#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<stdlib.h>

#define AVAGO_SERDES_LINKSPD_11G      (11.19744)   /* 11.19744 Gbps */
#define AVAGO_SERDES_LINKSPD_15G      (15.0)       /* 15 Gbps */
#define AVAGO_SERDES_LINKSPD_21G      (21.875)     /* 21.875 Gbps */
    #define AVAGO_SERDES_LINKSPD_25_66G   (25.66080)   /* 25.66080 Gbps */
    #define AVAGO_SERDES_LINKSPD_25_78G   (25.78125)   /* 25.78125 Gbps */
    
    #define AVAGO_SERDES_REFCLK_125MHZ    (125.0)      /* 125.0 MHz */
    #define AVAGO_SERDES_REFCLK_155MHZ    (155.52)     /* 155.52 MHz */
    #define AVAGO_SERDES_REFCLK_156MHZ    (156.25)     /* 156.25 MHz */
#define AVAGO_SERDES_WIDTH_MODE_40 1
#define AVAGO_SERDES28NM_RXTERM_DC 2
#define AVAGO_SERDES28NM_FULL_RATE 1
#define AV8801_COEF_TX(PRE, POST)                     \
{ \
    .link_speed = AVAGO_SERDES_LINKSPD_11G,          \
    .refclk = AVAGO_SERDES_REFCLK_155MHZ,             \
    .tx_rate = AVAGO_SERDES28NM_FULL_RATE,            \
    .tx_data_width = AVAGO_SERDES_WIDTH_MODE_40,      \
    .eq_pre = 9,                                      \
    .eq_post = 0,                                     \
    .output_attenuation = 0,                          \
    .tx_polarity_invert = 0 }                         

#define AV8801_COEF_RX(PARAM1) { \
        .link_speed = AVAGO_SERDES_LINKSPD_11G, \
        .refclk = AVAGO_SERDES_REFCLK_155MHZ, \
        .rx_rate = AVAGO_SERDES28NM_FULL_RATE, \
        .rx_data_width = AVAGO_SERDES_WIDTH_MODE_40, \
        .rx_polarity_invert = 0, \
       .rx_termination = AVAGO_SERDES28NM_RXTERM_DC}
typedef struct _avago_retimer_tx_coef_ {
    /* bitrate to refclk ratio (2 to 165) is derived from link_speed & refclk */
    float     link_speed;              /**< speed of the link - in Gbps */
    float     refclk;                  /**< reference clock - in MHz */
    u_int16_t tx_rate;                 /**< full, half, quarter, eighth, 16th
                                         - Set by Intr 0x05, 
                                         field data[10:8] */
    u_int16_t tx_data_width;           /**< 10, 20, 40 
                                         - Set by Intr 20, 
                                         field data[1:0] */
    u_int32_t eq_pre;                  /**< Set by Intr 0x15, field data[4:0] */
    u_int32_t eq_post;                 /**< Set by Intr 0x15, field data[4:0] */
    u_int32_t output_attenuation;      /**< Set by Intr 0x15, field data[4:0] */
    u_int8_t  tx_polarity_invert;      /**< 1 to invert */
} avago_retimer_tx_coef_t;

typedef struct _avago_retimer_rx_coef_ {
    /* bitrate to refclk ratio (2 to 165) is derived from link_speed & refclk */
    float     link_speed;              /**< speed of the link - in Gbps */
    float     refclk;                  /**< reference clock - in MHz */
    u_int16_t rx_rate;                /**< full, half, quarter, eigth, 16th
                                        - Set by Intr 0x06,field data[10:8]*/
    u_int16_t rx_data_width;          /**< 10, 20, 40 - Set by Intr 20, 
                                        field data[5:4] */
    u_int8_t  rx_polarity_invert;     /**< 1 to invert */
    u_int8_t  rx_termination;         /**< 1 for DC-coupled, 0 for AC-coupled */
} avago_retimer_rx_coef_t;

typedef struct _avago_retimer_coef_ {
    avago_retimer_tx_coef_t    avago_rtmr_tx_link;
    avago_retimer_rx_coef_t    avago_rtmr_rx_link;
} avago_retimer_coef_t;

typedef struct cmty_sfb_retimer_reg_ {
    u_int16_t i2c_addr;
    u_int16_t channel;
    u_int16_t reg[7];
    u_int32_t rtmr_idx;
    avago_retimer_coef_t avago_retimer_coef;
} cmty_sfb_retimer_reg_t;

typedef struct cmty_sfb_retimer_reg_map_ {
    cmty_sfb_retimer_reg_t tx_retimer_to_asic;
    cmty_sfb_retimer_reg_t tx_retimer_to_backplane;
} cmty_sfb_retimer_reg_map_t;

cmty_sfb_retimer_reg_map_t var = 
{ 
    .tx_retimer_to_asic = {
        .i2c_addr = 0x40,
        .channel =  4,
        .rtmr_idx = 0X8001,
        .avago_retimer_coef = {
            .avago_rtmr_tx_link = AV8801_COEF_TX(0,0),
            .avago_rtmr_rx_link = AV8801_COEF_RX(0)
        }
    },
    .tx_retimer_to_backplane = {
        .i2c_addr = 0x40,
        .channel =  3,
        .rtmr_idx = 0X8001,
        .avago_retimer_coef = {
            .avago_rtmr_tx_link = AV8801_COEF_TX(0,0),
            .avago_rtmr_rx_link = AV8801_COEF_RX(0)
        }
    }
};


int main()
{
    printf("%d", var.tx_retimer_to_asic.avago_retimer_coef.avago_rtmr_tx_link.eq_pre);
}

