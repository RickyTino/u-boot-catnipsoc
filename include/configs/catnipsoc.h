#ifndef __CATNIPSOC_CONFIG_H
#define __CATNIPSOC_CONFIG_H

/* BootROM + MIG is pretty smart. DDR and Cache initialized */
#define CONFIG_SKIP_LOWLEVEL_INIT

/*--------------------------------------------
 * CPU configuration
 */
/* CPU Timer rate */
#define CONFIG_SYS_MIPS_TIMER_FREQ	25000000  /* Freq(CP0_Count) = Freq(CPU) / 2 */

/*----------------------------------------------------------------------
 * Memory Layout
 */

/* SDRAM Configuration (for final code, data, stack, heap) */
#define CONFIG_SYS_SDRAM_BASE		0x80000000
#define CONFIG_SYS_SDRAM_SIZE		0x08000000	/* 128 Mbytes */
#define CONFIG_SYS_INIT_SP_ADDR		\
	(CONFIG_SYS_SDRAM_BASE + CONFIG_SYS_SDRAM_SIZE - 0x1000)

#define CONFIG_SYS_MALLOC_LEN		(256 << 10)
#define CONFIG_SYS_MONITOR_BASE		CONFIG_SYS_TEXT_BASE
#define CONFIG_SYS_LOAD_ADDR		0x80100000 /* default load address */

/*----------------------------------------------------------------------
 * Commands
 */

/*------------------------------------------------------------
 * Console Configuration
 */
#define CONFIG_SYS_CBSIZE		1024 /* Console I/O Buffer Size   */

/* -------------------------------------------------
 * Environment
 */
#define CONFIG_ENV_IS_NOWHERE      1
#define CONFIG_ENV_SECT_SIZE       0x10000
#define CONFIG_ENV_OFFSET          0
//#define CONFIG_ENV_SIZE            0x1000
#define CONFIG_EXTRA_ENV_SETTINGS \
    "serverip=192.168.11.1\0" \
    "ipaddr=192.168.11.2\0" \
    "netmask=255.255.255.0\0" \
    "load=tftpboot 0x80100000 uImage;iminfo\0" \
    "linux=tftpboot 0x80100000 uImage;bootm\0" \
    "u-boot=tftpboot 0x80200000 u-boot.bin;go 0x80200000\0"

/* ---------------------------------------------------------------------
 * Board boot configuration
 */
#define CONFIG_TIMESTAMP	/* Print image info with timestamp */
#define CONFIG_SYS_BOOTM_LEN    32*1024*1024

#endif	/* __CATNIPSOC_H */
