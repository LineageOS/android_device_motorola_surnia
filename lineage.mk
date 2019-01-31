# Copyright (C) 2014-2016 The CyanogenMod Project
#               2017-2018 The LineageOS Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

$(call inherit-product, device/motorola/surnia/full_surnia.mk)

# Boot animation
TARGET_SCREEN_WIDTH := 540
TARGET_SCREEN_HEIGHT := 960

## Device identifier. This must come after all inclusions
PRODUCT_DEVICE := surnia
PRODUCT_NAME := lineage_surnia
PRODUCT_MODEL := Moto E LTE
PRODUCT_BRAND := Motorola
PRODUCT_MANUFACTURER := Motorola
PRODUCT_RELEASE_NAME := surnia

PRODUCT_BUILD_PROP_OVERRIDES += \
    PRIVATE_BUILD_DESC="surnia_retus-user 5.0.2 LXI22.50-24.1 1 release-keys"

BUILD_FINGERPRINT := "motorola/surnia_retus/surnia_umts:5.0.2/LXI22.50-24.1/1:user/release-keys"
