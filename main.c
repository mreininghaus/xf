/*
 *  xf - exchange filenames of two files
 *  Copyright (C) 2023 Maximilian Reininghaus

 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char const* const* argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <filename1> <filename2>\n", argv[0]);
    return EXIT_FAILURE;
  }

  int const dirfd = AT_FDCWD;
  int const r = renameat2(dirfd, argv[1], dirfd, argv[2], RENAME_EXCHANGE);
  if (r == -1) {
    int const errsv = errno;
    fprintf(stderr, "%s failed: %s\n", argv[0], strerror(errsv));
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}
