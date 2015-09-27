#!/system/bin/sh
PATH=/system/bin
TAG="scritch007"

product_model=`getprop ro.product.model`

if [ "XT1526" = $product_model ]; then
	log -t$TAG "Applying LTE fix"
	setprop ro.product.locale.region "US"
	setprop gsm.sim.operator.alpha "Boost Mobile"
	setprop gsm.sim.operator.numeric 311870
	setprop gsm.operator.alpha "Boost Mobile"
	setprop gsm.operator.numeric 311870
	setprop gsm.sim.operator.iso-country "US"
	cp /system/etc/boost/eri.xml /data/eri.xml
	chmod 644 /data/eri.xml
	cp /system/etc/boost/apns-conf.xml /system/etc/apns-conf.xml
	chmod 644 /system/etc/apns-conf.xml
fi

