workspace(name = "v2m")

load("//bazel_script:workspace.bzl", "v2m_workspace")

v2m_workspace()

load("@rules_proto_grpc//:repositories.bzl", "rules_proto_grpc_repos", "rules_proto_grpc_toolchains")

rules_proto_grpc_toolchains()

rules_proto_grpc_repos()

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

rules_proto_dependencies()

rules_proto_toolchains()

load("@rules_proto_grpc//cpp:repositories.bzl", "cpp_repos", rules_proto_grpc_cpp_repos = "cpp_repos")

cpp_repos()

rules_proto_grpc_toolchains()

rules_proto_grpc_repos()

rules_proto_dependencies()

rules_proto_toolchains()

rules_proto_grpc_cpp_repos()

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()
