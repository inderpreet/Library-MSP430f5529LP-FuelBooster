## THIS IS A GENERATED FILE -- DO NOT EDIT
.configuro: .libraries,e430X linker.cmd package/cfg/FuelTank_BoosterPack_pe430X.oe430X

linker.cmd: package/cfg/FuelTank_BoosterPack_pe430X.xdl
	$(SED) 's"^\"\(package/cfg/FuelTank_BoosterPack_pe430Xcfg.cmd\)\"$""\"E:/Inderpreet/Sandbox/MSP430f5529_USB_LAUNCHPAD/Design/CCS5/MSP430G2_FuelTank_BoostPack/.config/xconfig_FuelTank_BoosterPack/\1\""' package/cfg/FuelTank_BoosterPack_pe430X.xdl > $@
