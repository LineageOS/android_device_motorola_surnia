# Copyright (C) 2016 The CyanogenMod Project
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

def IncrementalOTA_Assertions(info):
  AddAssertion(info)

def IncrementalOTA_VerifyBegin(info):
  # Workaround for apn list changes
  RestoreApnList(info)

def IncrementalOTA_InstallEnd(info):
  ReplaceApnList(info)

def FullOTA_Assertions(info):
  AddAssertion(info)

def FullOTA_InstallEnd(info):
  ReplaceApnList(info)


def AddAssertion(info):
  info.script.AppendExtra('if getprop("ro.boot.carrier") == "sprint" && getprop("ro.boot.fsg-id") == "" then')
  info.script.AppendExtra('ui_print("Sprint CDMA variant detected!");')
  info.script.AppendExtra('ui_print("Reboot into Bootloader Mode, connect your device to PC and from PC terminal type:");')
  info.script.AppendExtra('ui_print("fastboot oem config fsg-id boost    if you are a Boost Mobile user");')
  info.script.AppendExtra('ui_print("fastboot oem config fsg-id frdm     if you are a FreedomPop user");')
  info.script.AppendExtra('ui_print("fastboot oem config fsg-id rngplus  if you are a RingPlus user");')
  info.script.AppendExtra('ui_print("fastboot oem config fsg-id sprint   if you are a Sprint user or not listed");')
  info.script.AppendExtra('ui_print("fastboot oem config fsg-id virgin   if you are a Virgin Mobile user");')
  info.script.AppendExtra('ui_print("and then flash CyanogenMod again");')
  info.script.AppendExtra('abort("**********");')
  info.script.AppendExtra('endif;')

def ReplaceApnList(info):
  info.script.AppendExtra('if getprop("ro.boot.radio") == "0x3" then')
  info.script.Mount("/system")
  info.script.Mount("/data")
  info.script.AppendExtra('run_program("/sbin/sh", "-c", "mv /system/etc/apns-conf.xml /system/etc/apns-conf.xml.bak");')
  info.script.AppendExtra('if getprop("ro.boot.carrier") == "sprint" then')
  info.script.AppendExtra('if getprop("ro.boot.fsg-id") == "boost" then')
  info.script.AppendExtra('run_program("/sbin/sh", "-c", "mv /system/etc/cdma/apns-conf-boost.xml /system/etc/apns-conf.xml");');
  info.script.AppendExtra('run_program("/sbin/sh", "-c", "cp /system/etc/cdma/eri-boost.xml /data/eri.xml");');
  info.script.AppendExtra('endif;')
  info.script.AppendExtra('if getprop("ro.boot.fsg-id") == "frdm" then')
  info.script.AppendExtra('run_program("/sbin/sh", "-c", "mv /system/etc/cdma/apns-conf-frdm.xml /system/etc/apns-conf.xml");');
  info.script.AppendExtra('run_program("/sbin/sh", "-c", "cp /system/etc/cdma/eri-frdm.xml /data/eri.xml");');
  info.script.AppendExtra('endif;')
  info.script.AppendExtra('if getprop("ro.boot.fsg-id") == "rngplus" then')
  info.script.AppendExtra('run_program("/sbin/sh", "-c", "mv /system/etc/cdma/apns-conf-rngplus.xml /system/etc/apns-conf.xml");');
  info.script.AppendExtra('run_program("/sbin/sh", "-c", "cp /system/etc/cdma/eri-rngplus.xml /data/eri.xml");');
  info.script.AppendExtra('endif;')
  info.script.AppendExtra('if getprop("ro.boot.fsg-id") == "sprint" then')
  info.script.AppendExtra('run_program("/sbin/sh", "-c", "mv /system/etc/cdma/apns-conf-sprint.xml /system/etc/apns-conf.xml");');
  info.script.AppendExtra('endif;')
  info.script.AppendExtra('if getprop("ro.boot.fsg-id") == "virgin" then')
  info.script.AppendExtra('run_program("/sbin/sh", "-c", "mv /system/etc/cdma/apns-conf-virgin.xml /system/etc/apns-conf.xml");');
  info.script.AppendExtra('run_program("/sbin/sh", "-c", "cp /system/etc/cdma/eri-virgin.xml /data/eri.xml");');
  info.script.AppendExtra('endif;')
  info.script.AppendExtra('endif;')
  info.script.AppendExtra('ifelse(getprop("ro.boot.carrier") == "usc", run_program("/sbin/sh", "-c", "mv /system/etc/cdma/apns-conf-usc.xml /system/etc/apns-conf.xml"));')
  info.script.Unmount("/data")
  info.script.Unmount("/system")
  info.script.AppendExtra('endif;')

def RestoreApnList(info):
  info.script.AppendExtra('if getprop("ro.boot.radio") == "0x3" then')
  info.script.Mount("/system")
  info.script.AppendExtra('delete("/system/etc/apns-conf.xml");')
  info.script.AppendExtra('run_program("/sbin/sh", "-c", "mv /system/etc/apns-conf.xml.bak /system/etc/apns-conf.xml");')
  info.script.Unmount("/system")
  info.script.AppendExtra('endif;')
