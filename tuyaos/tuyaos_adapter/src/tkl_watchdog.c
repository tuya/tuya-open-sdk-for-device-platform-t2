/**
 * @file tkl_watchdog.c
 * @brief this file was auto-generated by tuyaos v&v tools, developer can add implements between BEGIN and END
 * 
 * @warning: changes between user 'BEGIN' and 'END' will be keeped when run tuyaos v&v tools
 *           changes in other place will be overwrited and lost
 *
 * @copyright Copyright 2020-2021 Tuya Inc. All Rights Reserved.
 * 
 */

// --- BEGIN: user defines and implements ---
#include "tkl_watchdog.h"
#include "tuya_error_code.h"
#include "drv_model_pub.h"
#include "wdt_pub.h"
#include "BkDriverWdg.h"
// --- END: user defines and implements ---

/**
 * @brief watchdog init
 * 
 * @param[in] cfg: watchdog config
 *
 * @return 0, init error; >0 : the actually watchdog interval 
 */
uint32_t tkl_watchdog_init(TUYA_WDOG_BASE_CFG_T *cfg)
{
    // --- BEGIN: user implements ---
    if (cfg->interval_ms > 60000) {
        cfg->interval_ms = 60000;
    }

    bk_wdg_initialize((uint32_t)cfg->interval_ms);
    return cfg->interval_ms;
    // --- END: user implements ---
}

/**
 * @brief watchdog deinit
 *
 * @param[in] none
 * 
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tkl_watchdog_deinit(void)
{
    // --- BEGIN: user implements ---
    bk_wdg_finalize();
    return OPRT_OK;
    // --- END: user implements ---
}

/**
 * @brief refresh watch dog
 * 
 * @param[in] none
 *
 * @return OPRT_OK on success. Others on error, please refer to tuya_error_code.h
 */
OPERATE_RET tkl_watchdog_refresh(void)
{
    // --- BEGIN: user implements ---
    bk_wdg_reload();
    return OPRT_OK;
    // --- END: user implements ---
}

