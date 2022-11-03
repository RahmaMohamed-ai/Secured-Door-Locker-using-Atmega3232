#include "GIE_interface.h"
#include "../../../COTS/LIB/BIT_MATH.h"
#include "../../../COTS/LIB/STD_TYPES.h"
#include "../../../COTS/MCAL/GIE/GIE_config.h"
#include "../../../COTS/MCAL/GIE/GIE_interface.h"
#include "../../../COTS/MCAL/GIE/GIE_private.h"

void GIE_vEnable(void)
{
	SET_BIT(SREG , G_INTERRUPT_CTRL_BIT);
}

void GIE_vDisable(void)
{
	CLR_BIT(SREG , G_INTERRUPT_CTRL_BIT);
}
