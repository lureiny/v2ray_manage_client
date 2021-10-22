workspace(name = "v2m")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# grpc
git_repository(
    name = "com_github_grpc_grpc",
    branch = "v1.41.0",
    remote = "https://github.com/grpc/grpc",
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")

grpc_extra_deps()

load("//bazel_script:workspace.bzl", "v2m_workspace")

v2m_workspace()

load("@rules_cc//cc:repositories.bzl", "rules_cc_dependencies")

rules_cc_dependencies()

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

rules_proto_dependencies()

rules_proto_toolchains()
