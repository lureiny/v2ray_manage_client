CPPFLAGS += `pkg-config --cflags protobuf grpc`
CXXFLAGS += -c -I. -I./include --std=c++11 -g
LDFLAGS += -L/usr/local/lib `pkg-config --libs grpc++ grpc protobuf protobuf-lite `\
           -pthread -lgflags -lpthread -lhiredis_static\
           -Wl,--no-as-needed -lgrpc++_reflection -Wl,--as-needed\
           -ldl

PROTOS = proxy/vmess/account proxy/vless/account \
         common/serial/typed_message transport/config \
		 transport/internet/config app/proxyman/command/command \
		 common/protocol/headers common/protocol/user config \
		 app/stats/command/command redis local_stats
		 
OTHER_OBJS = src/main.o src/handler_service_client.o src/stats_service_client.o src/rpc.o src/cluster.o \
             src/redis_client.o src/common.o  src/callback.o src/file_io.o 

GRPC_CC = app/proxyman/command/command app/stats/command/command
OBJS_PATH = objs
OBJS = $(addprefix $(OBJS_PATH)/,$(addsuffix .pb.o,$(PROTOS)) $(addsuffix .grpc.pb.o,$(GRPC_CC)) ) $(addprefix $(OBJS_PATH)/,$(OTHER_OBJS)) 
DIRS = $(addprefix $(OBJS_PATH)/,$(dir $(PROTOS))) $(addprefix $(OBJS_PATH)/,$(dir $(OTHER_OBJS)))

MKDIR = mkdir -p

PROTO_DET = /root/grpc_proto/v2ray_man/build
PROTO_INCLUDE = -I=.
PROTO_SRC = /root/grpc_proto/v2ray_man/v2ray-core/
PROTO_PLUGIN = --plugin=protoc-gen-grpc=`which grpc_cpp_plugin`

EXEC = ./bin/demo

.PHONY: build
build: mkdir $(addsuffix .grpc.pb.cc,$(GRPC_CC)) $(addsuffix .pb.cc,$(PROTOS)) $(OBJS)
	$(CXX) -g -o $(EXEC) $(OBJS) $(LDFLAGS)

%.grpc.pb.cc: %.proto
	protoc $(PROTO_INCLUDE) --grpc_out=. $(PROTO_PLUGIN) $*.proto

%.pb.cc: %.proto
	protoc $(PROTO_INCLUDE) --cpp_out=. $(subst .pb.cc,.proto,$@)

$(OBJS_PATH)/%.o: %.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(patsubst $(OBJS_PATH)/%.o,%.cc,$@) -o $@

.PHONY: cp
cp:
	cd $(PROTO_SRC) && cp --parents $(addsuffix .proto,$(PROTOS)) /root/v2ray_manage_client

.PHONY: mkdir
mkdir:
	$(MKDIR) $(DIRS)

.IGNORE: test

.PHONY: test
test:

	@echo Add user test:
	$(EXEC) -operation=add_user -inbound_tag=intest -name=lureiny -protocol=vmess
	@echo 
	@echo
	@echo Query stats test:
	$(EXEC) -operation=query_stats -query_pattern="api"
	@echo 
	@echo
	@echo Get stats test:
	$(EXEC) -operation=get_stats -stats_name="inbound>>>api>>>traffic>>>downlink"
	@echo
	@echo
	@echo Get sys stats test:
	$(EXEC) -operation=get_sys_stats
	@echo 
	@echo
	@echo Remove user test:
	$(EXEC) -operation=remove_user -inbound_tag=intest -name=lureiny


.PHONY: clean
clean:
	rm -rf $(OBJS_PATH)/*
	rm -f $(EXEC)
