# CONTRIBUTING
> all source code files must end with license and copyright notices to ensure compliance with the GNU Affero General Public License v3.0 or later

## Ignore

### Engine
> files inside `source/engine` directory

Some the parts of engine related code could be changed to other license, so direct contributions to source code under `source/engine` subdirectory via pull request would be ignored, just suggest possible solution using issues or consider doing workaround for a specific application outside of engine realm.

## Contributor
> anyone who submits source code changes for inclusion by the Licensor

### Modification
> changing existing files

- purely cosmetic: nothing needs to be done

- small changes andor additions: add modification notices near such changes

- significant changes: add your copyright notice on a new line at the end of other copyright notices

### Creation
> adding new files

add similar comment matching the Licensor template, but include an additional empty line between the `app:` line and your `copyright` notice (`DO NOT USE LICENSOR COPYRIGHT NOTICE`), like so:

```md
GNU Affero General Public License v3.0 or later
NO WARRANTY OF ANY KIND more details at <https://www.gnu.org/licenses/>
SPDX-License-Identifier: AGPL-3.0-or-later
app: `gamelike` Resemble Role Playing Games

[CONTRIBUTOR COPYRIGHT NOTICE]
```

## Licensor
> project owner

source code files should end with comment about `license` name, `warranty` details, `SPDX` identifier, `application` legend and `copyright` notice

```md
GNU Affero General Public License v3.0 or later
NO WARRANTY OF ANY KIND more details at <https://www.gnu.org/licenses/>
SPDX-License-Identifier: AGPL-3.0-or-later
app: `gamelike` Resemble Role Playing Games
Ⓒ Copyright (C) 2026 Oleg'Ease'Kharchuk ᦒ
```
