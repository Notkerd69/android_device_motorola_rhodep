/*
 * Copyright (C) 2021 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <libinit_dalvik_heap.h>
#include <libinit_variant.h>
#include <libinit_utils.h>

#include <sys/stat.h>

#include "vendor_init.h"

static const variant_info_t global_info = {
    .sku_value = "XT2225-1",

    .model = "moto g82 5G",
    .name = "rhodep_g",
    .build_fingerprint = "motorola/rhodep_g/rhodep:13/T1SUS33.1-124-6-3/1f802-e899d:user/release-keys",
    .build_description = "rhodep_g-user 13 T1SUS33.1-124-6-3 1f802-e899d release-keys",
};

static const std::vector<variant_info_t> variants = {
    global_info,
};

static void workaround_snet_properties() {
    chmod("/sys/fs/selinux/enforce", 0640);
    chmod("/sys/fs/selinux/policy", 0440);
}

void vendor_load_properties() {
    search_variant(variants);
    set_dalvik_heap();

    // Workaround SafetyNet
    workaround_snet_properties();
}
