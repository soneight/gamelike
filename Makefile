.PHONY: usage cmake ninja clean build allin
# commands
usage:
	@cat Makefile.usage.txt
cmake:
	@echo "configuring project"
	@cmake --preset default
ninja:
	@echo "generating project"
	@cmake --build --preset default
clean:
	@echo "cleaning build directory"
	@rm -rf build/
	@git restore build/.gitignore
build:
	@echo "configuring and generating project"
	@make cmake
	@make ninja
allin:
	@echo "cleaning build directory and then configuring and generating project"
	@make clean
	@make build

# GNU Affero General Public License v3.0 or later
# NO WARRANTY OF ANY KIND more details at <https://www.gnu.org/licenses/>
# SPDX-License-Identifier: AGPL-3.0-or-later
# app: `gamelike` Resemble Role Playing Games
# Ⓒ Copyright (C) 2026 Oleg'Ease'Kharchuk ᦒ
