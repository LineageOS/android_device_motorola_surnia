#!/vendor/bin/sh

# Copyright (c) 2018 The LineageOS Project
#
# Device configuration for surnia variants
#
PATH=/sbin:/vendor/sbin:/vendor/bin:/vendor/xbin
export PATH

radio=`getprop ro.boot.radio`

set_config_props ()
{
    # 0x1: XT1527 GSM USA
    # 0x2: XT1529 CDMA Verizon
    # 0x3: XT1526 CDMA Sprint/Boost
    # 0x4: XT1524 GSM Europe
    # 0x6: XT1523 GSM Brazil w/TV (dual SIM)
    # 0x7: XT1521 GSM Asia (dual SIM)
    # 0x8: XT1514 GSM Brazil (dual SIM)
    case $radio in
        0x1|0x4 )
            setprop ro.device.cdma false
            setprop ro.device.dualsim false
        ;;
        0x2|0x3 )
            setprop ro.device.cdma true
            setprop ro.device.dualsim false
        ;;
        0x6|0x7|0x8 )
            setprop ro.device.cdma false
            setprop ro.device.dualsim true
        ;;
    esac
}

# Main
set_config_props

return 0
