#include "dma.h"

void configurarDMA() {
    GPDMA_Channel_CFG_Type DMAConfig;

    DMAConfig.ChannelNum = 0;
    DMAConfig.SrcMemAddr = (uint32_t)&(LPC_ADC->ADDR0);
    DMAConfig.DstMemAddr = (uint32_t)dmaBuffer;
    DMAConfig.TransferSize = BUFFER_SIZE;
    DMAConfig.TransferType = GPDMA_TRANSFERTYPE_P2M_CONTROLLER_DMA;
    DMAConfig.SrcConn = GPDMA_CONN_ADC;
    DMAConfig.DstConn = 0;
    DMAConfig.DMALLI = 0;

    GPDMA_Init();
    GPDMA_Setup(&DMAConfig);

    GPDMA_ChannelCmd(0, ENABLE);
}
