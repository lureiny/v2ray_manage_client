# v2ray管理客户端

## 功能lie表
- [x] 添加用户（v2ray.core.app.proxyman.command.AddUserOperation）
    - [x] VMESS
    - [x] VLESS
    - [ ] Trojan
- [x] 删除用户（v2ray.core.app.proxyman.command.RemoveUserOperation）
    - [x] VMESS
    - [x] VLESS
    - [ ] Trojan
- [x] 流量查询（v2ray.core.app.stats.command.QueryStats, v2ray.core.app.stats.command.GetStats）
    - [x] 系统统计信息
    - [x] user统计信息
    - [x] inbound统计信息
- [x] 系统统计查询（v2ray.core.app.stats.command.GetSysStats）
- [x] 持久化配置
- [x] 集群模式（管理、查看）
    - [x] 上报当前统计信息
    - [x] 上报历史统计信息
    - [x] 通过队列实现远程操作管理
- [x] 断电统计（历史记录）

## 项目依赖

- [rapidjson][rapidjson]: A fast JSON parser/generator for C++ with both SAX/DOM style API
- [hiredis][hiredis]: Hiredis is a minimalistic C client library for the Redis database.
- [grpc][grpc]: gRPC is a modern, open source, high-performance remote procedure call (RPC) framework that can run anywhere. gRPC enables client and server applications to communicate transparently, and simplifies the building of connected systems.
- [protobuf][protobuf]: Protocol Buffers (a.k.a., protobuf) are Google's language-neutral, platform-neutral, extensible mechanism for serializing structured data. You can find protobuf's documentation on the Google Developers site.



[rapidjson]: https://github.com/Tencent/rapidjson
[hiredis]: https://github.com/redis/hiredis
[grpc]: https://github.com/grpc/grpc
[protobuf]: https://github.com/protocolbuffers/protobuf