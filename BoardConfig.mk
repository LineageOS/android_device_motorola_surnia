#
# Copyright (C) 2015 The Android Open-Source Project
# Copyright (C) 2017-2018 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

include device/motorola/msm8916-common/BoardConfigCommon.mk

-include vendor/motorola/surnia/BoardConfigVendor.mk

DEVICE_PATH := device/motorola/surnia

TARGET_KERNEL_CONFIG := surnia_defconfig

# Asserts
TARGET_OTA_ASSERT_DEVICE := XT1514,XT1521,XT1524,XT1526,XT1527,XT1523,surnia_uds,surnia_umts,surnia,surnia_udstv
TARGET_RELEASETOOLS_EXTENSIONS := # Not a typo, surnia doesn't need fw extraction script

# Camera
BOARD_GLOBAL_CFLAGS += -DCONFIG_MSM_USES_M_STACK
TARGET_HAS_LEGACY_CAMERA_HAL1 := true
TARGET_PROCESS_SDK_VERSION_OVERRIDE := \
    /system/bin/cameraserver=23 \
    /system/bin/mediaserver=23 \
    /system/bin/mm-qcamera-daemon=23

# Partitions
BOARD_BOOTIMAGE_PARTITION_SIZE := 33554432 #65536 * 512 mmcblk0p33
BOARD_RECOVERYIMAGE_PARTITION_SIZE := 33538048 #65504 * 512 mmcblk0p34
BOARD_SYSTEMIMAGE_PARTITION_SIZE := 1895825408 #3702784 * 512 mmcblk0p42
BOARD_PERSISTIMAGE_PARTITION_SIZE := 8388608 #16384 * 512 mmcblk0p31
BOARD_USERDATAIMAGE_PARTITION_SIZE := 5368578048 #(10518495 * 512) - 16891392 mmcblk0p44
BOARD_CACHEIMAGE_PARTITION_SIZE     := 268435456 #524288 * 512 mmcblk0p43

# Sensors
BOARD_USES_STML0XX_SENSOR_HUB := true
