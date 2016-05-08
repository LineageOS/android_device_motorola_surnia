/*
   Copyright (c) 2014, The Linux Foundation. All rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the following
      disclaimer in the documentation and/or other materials provided
      with the distribution.
    * Neither the name of The Linux Foundation nor the names of its
      contributors may be used to endorse or promote products derived
      from this software without specific prior written permission.

   THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESS OR IMPLIED
   WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
   MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT
   ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS
   BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
   CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
   SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR
   BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
   WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
   OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN
   IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <stdlib.h>
#include <stdio.h>

#include "vendor_init.h"
#include "property_service.h"
#include "log.h"
#include "util.h"

#define ISMATCH(a,b)    (!strncmp(a,b,PROP_VALUE_MAX))

void gsm_properties(bool msim);
void cdma_properties();

void vendor_load_properties()
{
    char carrier[PROP_VALUE_MAX];
    char device[PROP_VALUE_MAX];
    char devicename[PROP_VALUE_MAX];
    char fsg[PROP_VALUE_MAX];
    char platform[PROP_VALUE_MAX];
    char radio[PROP_VALUE_MAX];
    int rc;

    rc = property_get("ro.board.platform", platform);
    if (!rc || !ISMATCH(platform, ANDROID_TARGET))
        return;

    property_get("ro.boot.radio", radio);
    property_get("ro.boot.carrier", carrier);
    property_get("ro.boot.fsg-id", fsg);

    if (ISMATCH(radio, "0x2")) {
        /* XT1529 */
        cdma_properties();
        property_set("ro.product.model", "XT1529");
        property_set("ro.product.device", "surnia_cdma");
        property_set("ro.build.product", "surnia_cdma");
        property_set("ro.build.description", "surnia_verizon-user 5.1 LPI23.29-17.5 5 release-keys");
        property_set("ro.build.fingerprint", "motorola/surnia_verizon/surnia_cdma:5.1/LPI23.29-17.5/5:user/release-keys");
        property_set("ro.mot.build.customerid", "verizon");
        property_set("ro.ril.force_eri_from_xml", "true");
        property_set("ro.telephony.get_imsi_from_sim", "true");
        property_set("ro.com.google.clientidbase.am", "android-verizon");
        property_set("ro.com.google.clientidbase.ms", "android-verizon");
        property_set("ro.com.google.clientidbase.yt", "android-verizon");
        property_set("ro.cdma.data_retry_config", "max_retries=infinite,0,0,10000,10000,100000,10000,10000,10000,10000,140000,540000,960000");
    } else if (ISMATCH(radio, "0x1")) {
        /* XT1527 */
        gsm_properties(false);
        property_set("ro.product.model", "XT1527");
        property_set("ro.product.device", "surnia_umts");
        property_set("ro.build.product", "surnia_umts");
        property_set("ro.build.description", "surnia_retus-user 5.0.2 LXI22.50-24.1 1 release-keys");
        property_set("ro.build.fingerprint", "motorola/surnia_retus/surnia_umts:5.0.2/LXI22.50-24.1/1:user/release-keys");
        property_set("ro.mot.build.customerid", "retus");
    } else if (ISMATCH(radio, "0x3")) {
        /* XT1526 */
        cdma_properties();
        if (ISMATCH(carrier, "sprint")) {
            if (ISMATCH(fsg, "boost")) {
                property_set("ro.build.description", "surnia_boost-user 5.0.2 LXI22.50-14.8 30 release-keys");
                property_set("ro.build.fingerprint", "motorola/surnia_boost/surnia_cdma:5.0.2/LXI22.50-14.8/30:user/release-keys");
	        property_set("ro.cdma.home.operator.numeric", "311870");
	        property_set("ro.cdma.home.operator.alpha", "Boost Mobile");
            } else {
                property_set("ro.build.description", "surnia_sprint-user 5.0.2 LXI22.50-14.8 30 release-keys");
                property_set("ro.build.fingerprint", "motorola/surnia_sprint/surnia_cdma:5.0.2/LXI22.50-14.8/30:user/release-keys");
            }
            property_set("ro.fsg-id", "sprint");
            property_set("ro.carrier", "sprint");
            property_set("ro.mot.build.customerid ","sprint");
        } else {
            property_set("ro.build.description", "surnia_usc-user 5.0.2 LXI22.50-14.8 30 release-keys");
            property_set("ro.build.fingerprint", "motorola/surnia_usc/surnia_cdma:5.0.2/LXI22.50-14.8/30:user/release-keys");
            property_set("ro.mot.build.customerid", "usc");
            property_set("ro.cdma.home.operator.alpha", "U.S. Cellular");
            property_set("ro.cdma.home.operator.numeric", "311580");
            property_set("ro.fsg-id", "usc");
        }
        property_set("ro.product.model", "XT1526");
        property_set("ro.product.device", "surnia_cdma");
        property_set("ro.build.product", "surnia_cdma");
        property_set("persist.radio.0x9e_not_callname","1");
        property_set("persist.radio.lifecalls", "0");
        property_set("persist.radio.lifetimer", "0");
        property_set("persist.radio.multisim.config", "");
        property_set("ro.cdma.international.eri", "2,74,124,125,126,157,158,159,193,194,195,196,197,198,228,229,230,231,232,233,234,235");
        property_set("ro.com.android.dataroaming","false");
	property_set("ro.ril.force_eri_from_xml", "true");
    } else if (ISMATCH(radio, "0x4")) {
        /* XT1524 */
        gsm_properties(false);
        property_set("ro.product.model", "XT1524");
        property_set("ro.product.device", "surnia_umts");
        property_set("ro.build.product", "surnia_umts");
        property_set("ro.build.description", "surnia_reteu-user 5.0.2 LXI22.50-24.1 2 release-keys");
        property_set("ro.build.fingerprint", "motorola/surnia_reteu/surnia_umts:5.0.2/LXI22.50-24.1/2:user/release-keys");
        property_set("ro.mot.build.customerid", "reteuall");
    } else if (ISMATCH(radio, "0x6")) {
        /* XT1523 */
        gsm_properties(true);
        property_set("ro.product.model", "XT1523");
        property_set("ro.product.device", "surnia_udstv");
        property_set("ro.build.product", "surnia_udstv");
        property_set("ro.build.description", "surnia_retbr_dstv-user 5.0.2 LXI22.50-24.1 3 release-keys");
        property_set("ro.build.fingerprint", "motorola/surnia_retbr_dstv/surnia_udstv:5.0.2/LXI22.50-24.1/3:user/release-keys");
        property_set("ro.mot.build.customerid", "retbr");
    } else if (ISMATCH(radio, "0x7")) {
        /* XT1521 */
        gsm_properties(true);
        property_set("ro.product.model", "XT1521");
        property_set("ro.product.device", "surnia_uds");
        property_set("ro.build.product", "surnia_uds");
        property_set("ro.build.description", "surnia_reteu-user 5.0.2 LXI22.50-53.1 1 release-keys");
        property_set("ro.build.fingerprint", "motorola/surnia_reteu/surnia_umts:5.0.2/LXI22.50-53.1/1:user/release-keys");
        property_set("ro.mot.build.customerid", "retasiaall");
    } else if (ISMATCH(radio, "0x8")) {
        /* XT1514 */
        gsm_properties(true);
        property_set("ro.product.model", "XT1514");
        property_set("ro.product.device", "surnia_uds");
        property_set("ro.build.product", "surnia_uds");
        property_set("ro.build.description", "surnia_retbr_ds-user 5.0.2 LXI22.50-24.1 1 release-keys");
        property_set("ro.build.fingerprint", "motorola/surnia_retbr_ds/surnia_uds:5.0.2/LXI22.50-24.1/1:user/release-keys");
        property_set("ro.mot.build.customerid", "retbr");
    }
    property_get("ro.product.device", device);
    strlcpy(devicename, device, sizeof(devicename));
    INFO("Found radio id: %s setting build properties for %s device\n", radio, devicename);
}

void cdma_properties()
{
    property_set("DEVICE_PROVISIONED","1");
    property_set("gsm.sim.operator.iso-country", "US");
    property_set("gsm.operator.iso-country", "US");
    property_set("ril.subscription.types","NV,RUIM");
    property_set("ro.telephony.default_cdma_sub", "0");
    property_set("ro.product.locale.region", "US");
    property_set("ro.telephony.default_network", "8");
    property_set("telephony.lteOnCdmaDevice", "1");
}

void gsm_properties(bool msim)
{
    property_set("telephony.lteOnGsmDevice", "1");
    property_set("ro.telephony.default_network", "9");
    if (msim) {
        property_set("persist.radio.dont_use_dsd", "true");
        property_set("persist.radio.multisim.config", "dsds");
        property_set("persist.radio.plmn_name_cmp", "1");
        property_set("ro.telephony.ril.config", "simactivation");
    } else {
        property_set("persist.radio.multisim.config", "");
    }
}
