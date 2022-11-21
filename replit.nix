{ pkgs }: {
	deps = [
		pkgs.banner
  pkgs.clang_12
		pkgs.ccls
		pkgs.gdb
		pkgs.gnumake
	];
}