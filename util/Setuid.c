/* vim: set expandtab ts=4 sw=4: */
/*
 * You may redistribute this program and/or modify it under the terms of
 * the GNU General Public License as published by the Free Software Foundation,
 * either version 3 of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */
#include "util/Setuid.h"
#include "util/Js.h"

Js({
    const done = js.async();
    const impl = "util/Setuid_" + builder.config.systemName + ".c";
    require("fs").exists(impl, function (exists) {
        var out = "";
        if (!exists) {
            console.log("No setuid keepNetAdmin");
            js.linkerDependency("util/Setuid_dummy.c");
        } else {
            js.linkerDependency(impl);
            console.log("Has setuid keepNetAdmin");
        }
        done();
    });
})

