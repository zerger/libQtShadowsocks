Client
------

`shadowsocks-libqss` is a CLI client utilising `libQtShadowsocks`.

Note: This subproject is also a part of project `libQtShadowsocks`.

You can build this Qt project and use it to test functionality of `libQtShadowsocks`, or simply use it as your shadowsocks client on either (or both) local-side and server-side.

Usage
-----

```
Usage: ./shadowsocks-libqss [options]

Options:
  -h, --help                       Displays this help.
  -v, --version                    Displays version information.
  -c, --config-file <config.json>  specify config.json file.
  -s, --server-mode                run as shadowsocks server.
```

By default, it runs as local client. You have to pass `-s` if you want it run in server mode.

There is a `config.json` example for reference.

License
-------

Copyright (C) 2014 Symeon Huang

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
