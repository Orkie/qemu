#include "qemu/osdep.h"
#include "qapi/error.h"
#include "cpu.h"
#include "hw/sysbus.h"
#include "migration/vmstate.h"
#include "hw/arm/boot.h"
#include "hw/net/smc91c111.h"
#include "net/net.h"
#include "sysemu/sysemu.h"
#include "hw/pci/pci.h"
#include "hw/i2c/i2c.h"
#include "hw/i2c/arm_sbcon_i2c.h"
#include "hw/irq.h"
#include "hw/boards.h"
#include "exec/address-spaces.h"
#include "hw/block/flash.h"
#include "qemu/error-report.h"
#include "hw/char/pl011.h"
#include "hw/sd/sd.h"
#include "qom/object.h"

static void gp2x_init(MachineState *machine) {
}

static void gp2x_class_init(ObjectClass *oc, void *data)
{
    MachineClass *mc = MACHINE_CLASS(oc);

    mc->desc = "GP2X (MMSP2/MP2520F)";
    mc->init = gp2x_init;
    mc->ignore_memory_transaction_failures = true;
    mc->default_cpu_type = ARM_CPU_TYPE_NAME("arm920");
    mc->default_ram_id = "gp2x.ram";
}

static const TypeInfo gp2x_type = {
    .name = MACHINE_TYPE_NAME("gp2x"),
    .parent = TYPE_MACHINE,
    .class_init = gp2x_class_init,
};

static void gp2x_machine_init(void)
{
    type_register_static(&gp2x_type);
}

type_init(gp2x_machine_init)
