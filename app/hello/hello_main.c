/****************************************************************************
 * apps/examples/hello/hello_main.c
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed to the Apache Software Foundation (ASF) under one or more
 * contributor license agreements.  See the NOTICE file distributed with
 * this work for additional information regarding copyright ownership.  The
 * ASF licenses this file to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance with the
 * License.  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
 * License for the specific language governing permissions and limitations
 * under the License.
 *
 ****************************************************************************/

/****************************************************************************
 * Included Files
 ****************************************************************************/

#include <nuttx/config.h>
#include <stdio.h>
#include <sys/mount.h>
#include <errno.h>
#include <dlfcn.h>

/****************************************************************************
 * Public Functions
 ****************************************************************************/

/****************************************************************************
 * hello_main
 ****************************************************************************/

int main(int argc, FAR char *argv[])
{
  int ret;

  ret = mount("/dev/mmcsd0",
              "/mnt/elf",
              "vfat",
              MS_RDONLY,
              NULL);

  if (ret < 0)
    {
      fprintf(stderr, "ERROR: mount failed: %d (errno=%d)\n", ret, errno);
      return -1;
    }

  void *handle = dlopen("/mnt/elf/shrlib.so", RTLD_NOW);
  if (!handle)
    {
      fprintf(stderr, "dlopen failed: %s\n", dlerror());
      return -1;
    }
  
  int (*multiplication)(void) = dlsym(handle, "shrlib_mult");
  if (!multiplication)
    {
      dlclose(handle);
      return -1;
    }
 
  printf("Result is = %d\n", multiplication());
  dlclose(handle);
  return 0;
}
