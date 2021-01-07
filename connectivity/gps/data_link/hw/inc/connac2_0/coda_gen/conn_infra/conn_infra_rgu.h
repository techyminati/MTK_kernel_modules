/*
 * Copyright (C) 2019 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 */
#ifndef __CONN_INFRA_RGU_REGS_H__
#define __CONN_INFRA_RGU_REGS_H__

#define CONN_INFRA_RGU_BASE                                    0x18000000

#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_ADDR               (CONN_INFRA_RGU_BASE + 0x0000)
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ON_S_EN_ADDR           (CONN_INFRA_RGU_BASE + 0x0004)
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_ADDR               (CONN_INFRA_RGU_BASE + 0x0008)
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ON_S_EN_ADDR          (CONN_INFRA_RGU_BASE + 0x000C)
#define CONN_INFRA_RGU_WFSYS_CPU_SW_RST_B_ADDR                 (CONN_INFRA_RGU_BASE + 0x0010)
#define CONN_INFRA_RGU_BGFSYS_CPU_SW_RST_B_ADDR                (CONN_INFRA_RGU_BASE + 0x0014)
#define CONN_INFRA_RGU_WFSYS_SW_RST_B_ADDR                     (CONN_INFRA_RGU_BASE + 0x0018)
#define CONN_INFRA_RGU_BGFSYS_SW_RST_B_ADDR                    (CONN_INFRA_RGU_BASE + 0x001C)
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_ADDR         (CONN_INFRA_RGU_BASE + 0x0020)
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ON_S_EN_ADDR     (CONN_INFRA_RGU_BASE + 0x0024)
#define CONN_INFRA_RGU_SYSRAM_SHIFT_CHAIN_CTL_ADDR             (CONN_INFRA_RGU_BASE + 0x0034)
#define CONN_INFRA_RGU_SYSRAM_HWCTL_PDN_ADDR                   (CONN_INFRA_RGU_BASE + 0x0038)
#define CONN_INFRA_RGU_SYSRAM_HWCTL_SLP_ADDR                   (CONN_INFRA_RGU_BASE + 0x003C)
#define CONN_INFRA_RGU_SYSRAM_SWCTL_PDN_ADDR                   (CONN_INFRA_RGU_BASE + 0x0040)
#define CONN_INFRA_RGU_SYSRAM_SWCTL_SLP_ADDR                   (CONN_INFRA_RGU_BASE + 0x0044)
#define CONN_INFRA_RGU_SYSRAM_SWCTL_CKISO_ADDR                 (CONN_INFRA_RGU_BASE + 0x0048)
#define CONN_INFRA_RGU_SYSRAM_SWCTL_ISOINT_ADDR                (CONN_INFRA_RGU_BASE + 0x004C)
#define CONN_INFRA_RGU_CO_EXT_MEM_HWCTL_PDN_ADDR               (CONN_INFRA_RGU_BASE + 0x0050)
#define CONN_INFRA_RGU_CO_EXT_MEM_HWCTL_SLP_ADDR               (CONN_INFRA_RGU_BASE + 0x0054)
#define CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_PDN_ADDR               (CONN_INFRA_RGU_BASE + 0x0058)
#define CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_SLP_ADDR               (CONN_INFRA_RGU_BASE + 0x005C)
#define CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_CKISO_ADDR             (CONN_INFRA_RGU_BASE + 0x0060)
#define CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_ISOINT_ADDR            (CONN_INFRA_RGU_BASE + 0x0064)
#define CONN_INFRA_RGU_FM_CTRL_MEM_HWCTL_PDN_ADDR              (CONN_INFRA_RGU_BASE + 0x0068)
#define CONN_INFRA_RGU_FM_CTRL_MEM_HWCTL_SLP_ADDR              (CONN_INFRA_RGU_BASE + 0x006C)
#define CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_PDN_ADDR              (CONN_INFRA_RGU_BASE + 0x0070)
#define CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_SLP_ADDR              (CONN_INFRA_RGU_BASE + 0x0074)
#define CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_CKISO_ADDR            (CONN_INFRA_RGU_BASE + 0x0078)
#define CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_ISOINT_ADDR           (CONN_INFRA_RGU_BASE + 0x007C)
#define CONN_INFRA_RGU_RESERVED_ADDR                           (CONN_INFRA_RGU_BASE + 0x0080)
#define CONN_INFRA_RGU_DEBUG_SEL_ADDR                          (CONN_INFRA_RGU_BASE + 0x0090)
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ST_ADDR                (CONN_INFRA_RGU_BASE + 0x0100)
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ST_ADDR               (CONN_INFRA_RGU_BASE + 0x0104)
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ST_ADDR          (CONN_INFRA_RGU_BASE + 0x0108)
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ACK_ST_ADDR            (CONN_INFRA_RGU_BASE + 0x0110)
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ACK_ST_ADDR           (CONN_INFRA_RGU_BASE + 0x0114)
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ACK_ST_ADDR      (CONN_INFRA_RGU_BASE + 0x0118)
#define CONN_INFRA_RGU_WFSYS_OFF_TOP_PWR_ACK_ST_ADDR           (CONN_INFRA_RGU_BASE + 0x0120)
#define CONN_INFRA_RGU_BGFSYS_OFF_TOP_PWR_ACK_ST_ADDR          (CONN_INFRA_RGU_BASE + 0x0124)
#define CONN_INFRA_RGU_SYSRAM_PDN_ST_ADDR                      (CONN_INFRA_RGU_BASE + 0x0140)
#define CONN_INFRA_RGU_SYSRAM_SLP_ST_ADDR                      (CONN_INFRA_RGU_BASE + 0x0144)
#define CONN_INFRA_RGU_SYSRAM_CKISO_ST_ADDR                    (CONN_INFRA_RGU_BASE + 0x0148)
#define CONN_INFRA_RGU_SYSRAM_ISOINT_ST_ADDR                   (CONN_INFRA_RGU_BASE + 0x014C)
#define CONN_INFRA_RGU_CO_EXT_MEM_PDN_ST_ADDR                  (CONN_INFRA_RGU_BASE + 0x0150)
#define CONN_INFRA_RGU_CO_EXT_MEM_SLP_ST_ADDR                  (CONN_INFRA_RGU_BASE + 0x0154)
#define CONN_INFRA_RGU_CO_EXT_MEM_CKISO_ST_ADDR                (CONN_INFRA_RGU_BASE + 0x0158)
#define CONN_INFRA_RGU_CO_EXT_MEM_ISOINT_ST_ADDR               (CONN_INFRA_RGU_BASE + 0x015C)
#define CONN_INFRA_RGU_FM_CTRL_MEM_PDN_ST_ADDR                 (CONN_INFRA_RGU_BASE + 0x0160)
#define CONN_INFRA_RGU_FM_CTRL_MEM_SLP_ST_ADDR                 (CONN_INFRA_RGU_BASE + 0x0164)
#define CONN_INFRA_RGU_FM_CTRL_MEM_CKISO_ST_ADDR               (CONN_INFRA_RGU_BASE + 0x0168)
#define CONN_INFRA_RGU_FM_CTRL_MEM_ISOINT_ST_ADDR              (CONN_INFRA_RGU_BASE + 0x016C)


#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_WRITE_KEY_ADDR CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_WRITE_KEY_MASK 0xFFFF0000
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_WRITE_KEY_SHFT 16
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_PWR_ON_ADDR CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_PWR_ON_MASK 0x00000080
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_PWR_ON_SHFT 7
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_HWCTL_ADDR CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_HWCTL_MASK 0x00000010
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_HWCTL_SHFT 4
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_SW_PWR_ON_ADDR CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_SW_PWR_ON_MASK 0x00000008
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_SW_PWR_ON_SHFT 3
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_SW_PWR_ON_S_ADDR CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_SW_PWR_ON_S_MASK 0x00000004
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_SW_PWR_ON_S_SHFT 2
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_SW_ISO_EN_ADDR CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_SW_ISO_EN_MASK 0x00000002
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_SW_ISO_EN_SHFT 1
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_SW_RST_B_ADDR CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_SW_RST_B_MASK 0x00000001
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_CTL_WFSYS_ON_TOP_SW_RST_B_SHFT 0

#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ON_S_EN_WFSYS_ON_TOP_PWR_ON_S_EN_ADDR \
	CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ON_S_EN_ADDR
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ON_S_EN_WFSYS_ON_TOP_PWR_ON_S_EN_MASK 0x00FFFFFF
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ON_S_EN_WFSYS_ON_TOP_PWR_ON_S_EN_SHFT 0

#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_WRITE_KEY_ADDR CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_WRITE_KEY_MASK 0xFFFF0000
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_WRITE_KEY_SHFT 16
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_PWR_ON_ADDR CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_PWR_ON_MASK 0x00000080
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_PWR_ON_SHFT 7
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_HWCTL_ADDR CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_HWCTL_MASK 0x00000010
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_HWCTL_SHFT 4
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_SW_PWR_ON_ADDR CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_SW_PWR_ON_MASK 0x00000008
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_SW_PWR_ON_SHFT 3
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_SW_PWR_ON_S_ADDR CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_SW_PWR_ON_S_MASK 0x00000004
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_SW_PWR_ON_S_SHFT 2
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_SW_ISO_EN_ADDR CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_SW_ISO_EN_MASK 0x00000002
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_SW_ISO_EN_SHFT 1
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_SW_RST_B_ADDR CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_SW_RST_B_MASK 0x00000001
#define CONN_INFRA_RGU_BGFYS_ON_TOP_PWR_CTL_BGFSYS_ON_TOP_SW_RST_B_SHFT 0

#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ON_S_EN_BGFSYS_ON_TOP_PWR_ON_S_EN_ADDR \
	CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ON_S_EN_ADDR
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ON_S_EN_BGFSYS_ON_TOP_PWR_ON_S_EN_MASK 0x00000001
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ON_S_EN_BGFSYS_ON_TOP_PWR_ON_S_EN_SHFT 0

#define CONN_INFRA_RGU_WFSYS_CPU_SW_RST_B_WFSYS_CPU_SW_RST_B_ADDR CONN_INFRA_RGU_WFSYS_CPU_SW_RST_B_ADDR
#define CONN_INFRA_RGU_WFSYS_CPU_SW_RST_B_WFSYS_CPU_SW_RST_B_MASK 0x00000001
#define CONN_INFRA_RGU_WFSYS_CPU_SW_RST_B_WFSYS_CPU_SW_RST_B_SHFT 0

#define CONN_INFRA_RGU_BGFSYS_CPU_SW_RST_B_BGFSYS_CPU_SW_RST_B_ADDR CONN_INFRA_RGU_BGFSYS_CPU_SW_RST_B_ADDR
#define CONN_INFRA_RGU_BGFSYS_CPU_SW_RST_B_BGFSYS_CPU_SW_RST_B_MASK 0x00000001
#define CONN_INFRA_RGU_BGFSYS_CPU_SW_RST_B_BGFSYS_CPU_SW_RST_B_SHFT 0

#define CONN_INFRA_RGU_WFSYS_SW_RST_B_WFSYS_SW_RST_B_ADDR      CONN_INFRA_RGU_WFSYS_SW_RST_B_ADDR
#define CONN_INFRA_RGU_WFSYS_SW_RST_B_WFSYS_SW_RST_B_MASK      0x00000001
#define CONN_INFRA_RGU_WFSYS_SW_RST_B_WFSYS_SW_RST_B_SHFT      0

#define CONN_INFRA_RGU_BGFSYS_SW_RST_B_BGFSYS_SW_RST_B_ADDR    CONN_INFRA_RGU_BGFSYS_SW_RST_B_ADDR
#define CONN_INFRA_RGU_BGFSYS_SW_RST_B_BGFSYS_SW_RST_B_MASK    0x00000001
#define CONN_INFRA_RGU_BGFSYS_SW_RST_B_BGFSYS_SW_RST_B_SHFT    0

#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_WRITE_KEY_ADDR \
	CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_WRITE_KEY_MASK 0xFFFF0000
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_WRITE_KEY_SHFT 16
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_PWR_CHECK_WITH_MEM_PER_EN_ADDR \
	CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_PWR_CHECK_WITH_MEM_PER_EN_MASK 0x00000020
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_PWR_CHECK_WITH_MEM_PER_EN_SHFT 5
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_HWCTL_ADDR \
	CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_HWCTL_MASK 0x00000010
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_HWCTL_SHFT 4
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_SW_PWR_ON_ADDR \
	CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_SW_PWR_ON_MASK 0x00000008
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_SW_PWR_ON_SHFT 3
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_SW_PWR_ON_S_ADDR \
	CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_SW_PWR_ON_S_MASK 0x00000004
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_SW_PWR_ON_S_SHFT 2
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_SW_ISO_EN_ADDR \
	CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_SW_ISO_EN_MASK 0x00000002
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_SW_ISO_EN_SHFT 1
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_SW_RST_B_ADDR \
	CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_ADDR
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_SW_RST_B_MASK 0x00000001
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_CTL_CONN_INFRA_OFF_TOP_SW_RST_B_SHFT 0

#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ON_S_EN_CONN_INFRA_OFF_TOP_PWR_ON_S_EN_ADDR \
	CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ON_S_EN_ADDR
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ON_S_EN_CONN_INFRA_OFF_TOP_PWR_ON_S_EN_MASK 0x00FFFFFF
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ON_S_EN_CONN_INFRA_OFF_TOP_PWR_ON_S_EN_SHFT 0

#define CONN_INFRA_RGU_SYSRAM_SHIFT_CHAIN_CTL_PON_PRE_ADDR     CONN_INFRA_RGU_SYSRAM_SHIFT_CHAIN_CTL_ADDR
#define CONN_INFRA_RGU_SYSRAM_SHIFT_CHAIN_CTL_PON_PRE_MASK     0x00FF0000
#define CONN_INFRA_RGU_SYSRAM_SHIFT_CHAIN_CTL_PON_PRE_SHFT     16
#define CONN_INFRA_RGU_SYSRAM_SHIFT_CHAIN_CTL_PDN_PRE_ADDR     CONN_INFRA_RGU_SYSRAM_SHIFT_CHAIN_CTL_ADDR
#define CONN_INFRA_RGU_SYSRAM_SHIFT_CHAIN_CTL_PDN_PRE_MASK     0x0000FF00
#define CONN_INFRA_RGU_SYSRAM_SHIFT_CHAIN_CTL_PDN_PRE_SHFT     8
#define CONN_INFRA_RGU_SYSRAM_SHIFT_CHAIN_CTL_ISO_PRE_ADDR     CONN_INFRA_RGU_SYSRAM_SHIFT_CHAIN_CTL_ADDR
#define CONN_INFRA_RGU_SYSRAM_SHIFT_CHAIN_CTL_ISO_PRE_MASK     0x000000FF
#define CONN_INFRA_RGU_SYSRAM_SHIFT_CHAIN_CTL_ISO_PRE_SHFT     0

#define CONN_INFRA_RGU_SYSRAM_HWCTL_PDN_SYSRAM_HWCTL_PDN_ADDR  CONN_INFRA_RGU_SYSRAM_HWCTL_PDN_ADDR
#define CONN_INFRA_RGU_SYSRAM_HWCTL_PDN_SYSRAM_HWCTL_PDN_MASK  0x000000FF
#define CONN_INFRA_RGU_SYSRAM_HWCTL_PDN_SYSRAM_HWCTL_PDN_SHFT  0

#define CONN_INFRA_RGU_SYSRAM_HWCTL_SLP_SYSRAM_HWCTL_SLP_ADDR  CONN_INFRA_RGU_SYSRAM_HWCTL_SLP_ADDR
#define CONN_INFRA_RGU_SYSRAM_HWCTL_SLP_SYSRAM_HWCTL_SLP_MASK  0x000000FF
#define CONN_INFRA_RGU_SYSRAM_HWCTL_SLP_SYSRAM_HWCTL_SLP_SHFT  0

#define CONN_INFRA_RGU_SYSRAM_SWCTL_PDN_SYSRAM_SWCTL_PDN_ADDR  CONN_INFRA_RGU_SYSRAM_SWCTL_PDN_ADDR
#define CONN_INFRA_RGU_SYSRAM_SWCTL_PDN_SYSRAM_SWCTL_PDN_MASK  0x000000FF
#define CONN_INFRA_RGU_SYSRAM_SWCTL_PDN_SYSRAM_SWCTL_PDN_SHFT  0

#define CONN_INFRA_RGU_SYSRAM_SWCTL_SLP_SYSRAM_SWCTL_SLP_ADDR  CONN_INFRA_RGU_SYSRAM_SWCTL_SLP_ADDR
#define CONN_INFRA_RGU_SYSRAM_SWCTL_SLP_SYSRAM_SWCTL_SLP_MASK  0x000000FF
#define CONN_INFRA_RGU_SYSRAM_SWCTL_SLP_SYSRAM_SWCTL_SLP_SHFT  0

#define CONN_INFRA_RGU_SYSRAM_SWCTL_CKISO_SYSRAM_SWCTL_CKISO_ADDR CONN_INFRA_RGU_SYSRAM_SWCTL_CKISO_ADDR
#define CONN_INFRA_RGU_SYSRAM_SWCTL_CKISO_SYSRAM_SWCTL_CKISO_MASK 0x000000FF
#define CONN_INFRA_RGU_SYSRAM_SWCTL_CKISO_SYSRAM_SWCTL_CKISO_SHFT 0

#define CONN_INFRA_RGU_SYSRAM_SWCTL_ISOINT_SYSRAM_SWCTL_ISOINT_ADDR CONN_INFRA_RGU_SYSRAM_SWCTL_ISOINT_ADDR
#define CONN_INFRA_RGU_SYSRAM_SWCTL_ISOINT_SYSRAM_SWCTL_ISOINT_MASK 0x000000FF
#define CONN_INFRA_RGU_SYSRAM_SWCTL_ISOINT_SYSRAM_SWCTL_ISOINT_SHFT 0

#define CONN_INFRA_RGU_CO_EXT_MEM_HWCTL_PDN_CO_EXT_MEM_HWCTL_PDN_ADDR CONN_INFRA_RGU_CO_EXT_MEM_HWCTL_PDN_ADDR
#define CONN_INFRA_RGU_CO_EXT_MEM_HWCTL_PDN_CO_EXT_MEM_HWCTL_PDN_MASK 0x00000001
#define CONN_INFRA_RGU_CO_EXT_MEM_HWCTL_PDN_CO_EXT_MEM_HWCTL_PDN_SHFT 0

#define CONN_INFRA_RGU_CO_EXT_MEM_HWCTL_SLP_CO_EXT_MEM_HWCTL_SLP_ADDR CONN_INFRA_RGU_CO_EXT_MEM_HWCTL_SLP_ADDR
#define CONN_INFRA_RGU_CO_EXT_MEM_HWCTL_SLP_CO_EXT_MEM_HWCTL_SLP_MASK 0x00000001
#define CONN_INFRA_RGU_CO_EXT_MEM_HWCTL_SLP_CO_EXT_MEM_HWCTL_SLP_SHFT 0

#define CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_PDN_CO_EXT_MEM_SWCTL_PDN_ADDR CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_PDN_ADDR
#define CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_PDN_CO_EXT_MEM_SWCTL_PDN_MASK 0x00000001
#define CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_PDN_CO_EXT_MEM_SWCTL_PDN_SHFT 0

#define CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_SLP_CO_EXT_MEM_SWCTL_SLP_ADDR CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_SLP_ADDR
#define CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_SLP_CO_EXT_MEM_SWCTL_SLP_MASK 0x00000001
#define CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_SLP_CO_EXT_MEM_SWCTL_SLP_SHFT 0

#define CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_CKISO_CO_EXT_MEM_SWCTL_CKISO_ADDR CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_CKISO_ADDR
#define CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_CKISO_CO_EXT_MEM_SWCTL_CKISO_MASK 0x00000001
#define CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_CKISO_CO_EXT_MEM_SWCTL_CKISO_SHFT 0

#define CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_ISOINT_CO_EXT_MEM_SWCTL_ISOINT_ADDR CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_ISOINT_ADDR
#define CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_ISOINT_CO_EXT_MEM_SWCTL_ISOINT_MASK 0x00000001
#define CONN_INFRA_RGU_CO_EXT_MEM_SWCTL_ISOINT_CO_EXT_MEM_SWCTL_ISOINT_SHFT 0

#define CONN_INFRA_RGU_FM_CTRL_MEM_HWCTL_PDN_FM_CTRL_MEM_HWCTL_PDN_ADDR CONN_INFRA_RGU_FM_CTRL_MEM_HWCTL_PDN_ADDR
#define CONN_INFRA_RGU_FM_CTRL_MEM_HWCTL_PDN_FM_CTRL_MEM_HWCTL_PDN_MASK 0x00000001
#define CONN_INFRA_RGU_FM_CTRL_MEM_HWCTL_PDN_FM_CTRL_MEM_HWCTL_PDN_SHFT 0

#define CONN_INFRA_RGU_FM_CTRL_MEM_HWCTL_SLP_FM_CTRL_MEM_HWCTL_SLP_ADDR CONN_INFRA_RGU_FM_CTRL_MEM_HWCTL_SLP_ADDR
#define CONN_INFRA_RGU_FM_CTRL_MEM_HWCTL_SLP_FM_CTRL_MEM_HWCTL_SLP_MASK 0x00000001
#define CONN_INFRA_RGU_FM_CTRL_MEM_HWCTL_SLP_FM_CTRL_MEM_HWCTL_SLP_SHFT 0

#define CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_PDN_FM_CTRL_MEM_SWCTL_PDN_ADDR CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_PDN_ADDR
#define CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_PDN_FM_CTRL_MEM_SWCTL_PDN_MASK 0x00000001
#define CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_PDN_FM_CTRL_MEM_SWCTL_PDN_SHFT 0

#define CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_SLP_FM_CTRL_MEM_SWCTL_SLP_ADDR CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_SLP_ADDR
#define CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_SLP_FM_CTRL_MEM_SWCTL_SLP_MASK 0x00000001
#define CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_SLP_FM_CTRL_MEM_SWCTL_SLP_SHFT 0

#define CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_CKISO_FM_CTRL_MEM_SWCTL_CKISO_ADDR CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_CKISO_ADDR
#define CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_CKISO_FM_CTRL_MEM_SWCTL_CKISO_MASK 0x00000001
#define CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_CKISO_FM_CTRL_MEM_SWCTL_CKISO_SHFT 0

#define CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_ISOINT_FM_CTRL_MEM_SWCTL_ISOINT_ADDR \
	CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_ISOINT_ADDR
#define CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_ISOINT_FM_CTRL_MEM_SWCTL_ISOINT_MASK 0x00000001
#define CONN_INFRA_RGU_FM_CTRL_MEM_SWCTL_ISOINT_FM_CTRL_MEM_SWCTL_ISOINT_SHFT 0

#define CONN_INFRA_RGU_RESERVED_RESERVED_ADDR                  CONN_INFRA_RGU_RESERVED_ADDR
#define CONN_INFRA_RGU_RESERVED_RESERVED_MASK                  0xFFFFFFFF
#define CONN_INFRA_RGU_RESERVED_RESERVED_SHFT                  0

#define CONN_INFRA_RGU_DEBUG_SEL_DEBUG_SEL_ADDR                CONN_INFRA_RGU_DEBUG_SEL_ADDR
#define CONN_INFRA_RGU_DEBUG_SEL_DEBUG_SEL_MASK                0x0000000F
#define CONN_INFRA_RGU_DEBUG_SEL_DEBUG_SEL_SHFT                0

#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ST_WFSYS_ON_TOP_MTCMOS_PWR_FSM_ADDR CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ST_ADDR
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ST_WFSYS_ON_TOP_MTCMOS_PWR_FSM_MASK 0x0000001C
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ST_WFSYS_ON_TOP_MTCMOS_PWR_FSM_SHFT 2
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ST_WFSYS_ON_TOP_MTCMOS_PWR_FSM_OFF_ST_ADDR \
	CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ST_ADDR
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ST_WFSYS_ON_TOP_MTCMOS_PWR_FSM_OFF_ST_MASK 0x00000002
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ST_WFSYS_ON_TOP_MTCMOS_PWR_FSM_OFF_ST_SHFT 1
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ST_WFSYS_ON_TOP_MTCMOS_PWR_FSM_ON_ST_ADDR \
	CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ST_ADDR
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ST_WFSYS_ON_TOP_MTCMOS_PWR_FSM_ON_ST_MASK 0x00000001
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ST_WFSYS_ON_TOP_MTCMOS_PWR_FSM_ON_ST_SHFT 0

#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ST_BGFSYS_ON_TOP_MTCMOS_PWR_FSM_ADDR CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ST_ADDR
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ST_BGFSYS_ON_TOP_MTCMOS_PWR_FSM_MASK 0x0000001C
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ST_BGFSYS_ON_TOP_MTCMOS_PWR_FSM_SHFT 2
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ST_BGFSYS_ON_TOP_MTCMOS_PWR_FSM_OFF_ST_ADDR \
	CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ST_ADDR
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ST_BGFSYS_ON_TOP_MTCMOS_PWR_FSM_OFF_ST_MASK 0x00000002
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ST_BGFSYS_ON_TOP_MTCMOS_PWR_FSM_OFF_ST_SHFT 1
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ST_BGFSYS_ON_TOP_MTCMOS_PWR_FSM_ON_ST_ADDR \
	CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ST_ADDR
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ST_BGFSYS_ON_TOP_MTCMOS_PWR_FSM_ON_ST_MASK 0x00000001
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ST_BGFSYS_ON_TOP_MTCMOS_PWR_FSM_ON_ST_SHFT 0

#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ST_CONN_INFRA_OFF_TOP_MTCMOS_PWR_FSM_ADDR \
	CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ST_ADDR
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ST_CONN_INFRA_OFF_TOP_MTCMOS_PWR_FSM_MASK 0x0000001C
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ST_CONN_INFRA_OFF_TOP_MTCMOS_PWR_FSM_SHFT 2
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ST_CONN_INFRA_OFF_TOP_MTCMOS_PWR_FSM_OFF_ST_ADDR \
	CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ST_ADDR
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ST_CONN_INFRA_OFF_TOP_MTCMOS_PWR_FSM_OFF_ST_MASK 0x00000002
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ST_CONN_INFRA_OFF_TOP_MTCMOS_PWR_FSM_OFF_ST_SHFT 1
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ST_CONN_INFRA_OFF_TOP_MTCMOS_PWR_FSM_ON_ST_ADDR \
	CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ST_ADDR
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ST_CONN_INFRA_OFF_TOP_MTCMOS_PWR_FSM_ON_ST_MASK 0x00000001
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ST_CONN_INFRA_OFF_TOP_MTCMOS_PWR_FSM_ON_ST_SHFT 0

#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ACK_ST_AN_WFSYS_ON_TOP_PWR_ACK_S_ADDR \
	CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ACK_ST_ADDR
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ACK_ST_AN_WFSYS_ON_TOP_PWR_ACK_S_MASK 0x02000000
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ACK_ST_AN_WFSYS_ON_TOP_PWR_ACK_S_SHFT 25
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ACK_ST_WFSYS_ON_TOP_PWR_ACK_ADDR CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ACK_ST_ADDR
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ACK_ST_WFSYS_ON_TOP_PWR_ACK_MASK 0x01000000
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ACK_ST_WFSYS_ON_TOP_PWR_ACK_SHFT 24
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ACK_ST_WFSYS_ON_TOP_PWR_ACK_S_ADDR CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ACK_ST_ADDR
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ACK_ST_WFSYS_ON_TOP_PWR_ACK_S_MASK 0x00FFFFFF
#define CONN_INFRA_RGU_WFSYS_ON_TOP_PWR_ACK_ST_WFSYS_ON_TOP_PWR_ACK_S_SHFT 0

#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ACK_ST_AN_BGFSYS_ON_TOP_PWR_ACK_S_ADDR \
	CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ACK_ST_ADDR
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ACK_ST_AN_BGFSYS_ON_TOP_PWR_ACK_S_MASK 0x02000000
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ACK_ST_AN_BGFSYS_ON_TOP_PWR_ACK_S_SHFT 25
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ACK_ST_BGFSYS_ON_TOP_PWR_ACK_ADDR CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ACK_ST_ADDR
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ACK_ST_BGFSYS_ON_TOP_PWR_ACK_MASK 0x01000000
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ACK_ST_BGFSYS_ON_TOP_PWR_ACK_SHFT 24
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ACK_ST_BGFSYS_ON_TOP_PWR_ACK_S_ADDR \
	CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ACK_ST_ADDR
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ACK_ST_BGFSYS_ON_TOP_PWR_ACK_S_MASK 0x00000001
#define CONN_INFRA_RGU_BGFSYS_ON_TOP_PWR_ACK_ST_BGFSYS_ON_TOP_PWR_ACK_S_SHFT 0

#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ACK_ST_AN_CONN_INFRA_OFF_TOP_PWR_ACK_S_ADDR \
	CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ACK_ST_ADDR
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ACK_ST_AN_CONN_INFRA_OFF_TOP_PWR_ACK_S_MASK 0x02000000
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ACK_ST_AN_CONN_INFRA_OFF_TOP_PWR_ACK_S_SHFT 25
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ACK_ST_CONN_INFRA_OFF_TOP_PWR_ACK_ADDR \
	CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ACK_ST_ADDR
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ACK_ST_CONN_INFRA_OFF_TOP_PWR_ACK_MASK 0x01000000
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ACK_ST_CONN_INFRA_OFF_TOP_PWR_ACK_SHFT 24
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ACK_ST_CONN_INFRA_OFF_TOP_PWR_ACK_S_ADDR \
	CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ACK_ST_ADDR
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ACK_ST_CONN_INFRA_OFF_TOP_PWR_ACK_S_MASK 0x00000001
#define CONN_INFRA_RGU_CONN_INFRA_OFF_TOP_PWR_ACK_ST_CONN_INFRA_OFF_TOP_PWR_ACK_S_SHFT 0

#define CONN_INFRA_RGU_WFSYS_OFF_TOP_PWR_ACK_ST_WFSYS_OFF_TOP_PWR_ACK_ADDR CONN_INFRA_RGU_WFSYS_OFF_TOP_PWR_ACK_ST_ADDR
#define CONN_INFRA_RGU_WFSYS_OFF_TOP_PWR_ACK_ST_WFSYS_OFF_TOP_PWR_ACK_MASK 0x01000000
#define CONN_INFRA_RGU_WFSYS_OFF_TOP_PWR_ACK_ST_WFSYS_OFF_TOP_PWR_ACK_SHFT 24
#define CONN_INFRA_RGU_WFSYS_OFF_TOP_PWR_ACK_ST_WFSYS_OFF_TOP_PWR_ACK_S_ADDR \
	CONN_INFRA_RGU_WFSYS_OFF_TOP_PWR_ACK_ST_ADDR
#define CONN_INFRA_RGU_WFSYS_OFF_TOP_PWR_ACK_ST_WFSYS_OFF_TOP_PWR_ACK_S_MASK 0x00FFFFFF
#define CONN_INFRA_RGU_WFSYS_OFF_TOP_PWR_ACK_ST_WFSYS_OFF_TOP_PWR_ACK_S_SHFT 0

#define CONN_INFRA_RGU_BGFSYS_OFF_TOP_PWR_ACK_ST_BGFSYS_OFF_TOP_PWR_ACK_ADDR \
	CONN_INFRA_RGU_BGFSYS_OFF_TOP_PWR_ACK_ST_ADDR
#define CONN_INFRA_RGU_BGFSYS_OFF_TOP_PWR_ACK_ST_BGFSYS_OFF_TOP_PWR_ACK_MASK 0x01000000
#define CONN_INFRA_RGU_BGFSYS_OFF_TOP_PWR_ACK_ST_BGFSYS_OFF_TOP_PWR_ACK_SHFT 24
#define CONN_INFRA_RGU_BGFSYS_OFF_TOP_PWR_ACK_ST_BGFSYS_OFF_TOP_PWR_ACK_S_ADDR \
	CONN_INFRA_RGU_BGFSYS_OFF_TOP_PWR_ACK_ST_ADDR
#define CONN_INFRA_RGU_BGFSYS_OFF_TOP_PWR_ACK_ST_BGFSYS_OFF_TOP_PWR_ACK_S_MASK 0x00000003
#define CONN_INFRA_RGU_BGFSYS_OFF_TOP_PWR_ACK_ST_BGFSYS_OFF_TOP_PWR_ACK_S_SHFT 0

#define CONN_INFRA_RGU_SYSRAM_PDN_ST_SYSRAM_PDN_ST_ADDR        CONN_INFRA_RGU_SYSRAM_PDN_ST_ADDR
#define CONN_INFRA_RGU_SYSRAM_PDN_ST_SYSRAM_PDN_ST_MASK        0x000000FF
#define CONN_INFRA_RGU_SYSRAM_PDN_ST_SYSRAM_PDN_ST_SHFT        0

#define CONN_INFRA_RGU_SYSRAM_SLP_ST_SYSRAM_SLP_ST_ADDR        CONN_INFRA_RGU_SYSRAM_SLP_ST_ADDR
#define CONN_INFRA_RGU_SYSRAM_SLP_ST_SYSRAM_SLP_ST_MASK        0x000000FF
#define CONN_INFRA_RGU_SYSRAM_SLP_ST_SYSRAM_SLP_ST_SHFT        0

#define CONN_INFRA_RGU_SYSRAM_CKISO_ST_SYSRAM_CKISO_ST_ADDR    CONN_INFRA_RGU_SYSRAM_CKISO_ST_ADDR
#define CONN_INFRA_RGU_SYSRAM_CKISO_ST_SYSRAM_CKISO_ST_MASK    0x000000FF
#define CONN_INFRA_RGU_SYSRAM_CKISO_ST_SYSRAM_CKISO_ST_SHFT    0

#define CONN_INFRA_RGU_SYSRAM_ISOINT_ST_SYSRAM_ISOINT_ST_ADDR  CONN_INFRA_RGU_SYSRAM_ISOINT_ST_ADDR
#define CONN_INFRA_RGU_SYSRAM_ISOINT_ST_SYSRAM_ISOINT_ST_MASK  0x000000FF
#define CONN_INFRA_RGU_SYSRAM_ISOINT_ST_SYSRAM_ISOINT_ST_SHFT  0

#define CONN_INFRA_RGU_CO_EXT_MEM_PDN_ST_CO_EXT_MEM_PDN_ST_ADDR CONN_INFRA_RGU_CO_EXT_MEM_PDN_ST_ADDR
#define CONN_INFRA_RGU_CO_EXT_MEM_PDN_ST_CO_EXT_MEM_PDN_ST_MASK 0x00000001
#define CONN_INFRA_RGU_CO_EXT_MEM_PDN_ST_CO_EXT_MEM_PDN_ST_SHFT 0

#define CONN_INFRA_RGU_CO_EXT_MEM_SLP_ST_CO_EXT_MEM_SLP_ST_ADDR CONN_INFRA_RGU_CO_EXT_MEM_SLP_ST_ADDR
#define CONN_INFRA_RGU_CO_EXT_MEM_SLP_ST_CO_EXT_MEM_SLP_ST_MASK 0x00000001
#define CONN_INFRA_RGU_CO_EXT_MEM_SLP_ST_CO_EXT_MEM_SLP_ST_SHFT 0

#define CONN_INFRA_RGU_CO_EXT_MEM_CKISO_ST_CO_EXT_MEM_CKISO_ST_ADDR CONN_INFRA_RGU_CO_EXT_MEM_CKISO_ST_ADDR
#define CONN_INFRA_RGU_CO_EXT_MEM_CKISO_ST_CO_EXT_MEM_CKISO_ST_MASK 0x00000001
#define CONN_INFRA_RGU_CO_EXT_MEM_CKISO_ST_CO_EXT_MEM_CKISO_ST_SHFT 0

#define CONN_INFRA_RGU_CO_EXT_MEM_ISOINT_ST_CO_EXT_MEM_ISOINT_ST_ADDR CONN_INFRA_RGU_CO_EXT_MEM_ISOINT_ST_ADDR
#define CONN_INFRA_RGU_CO_EXT_MEM_ISOINT_ST_CO_EXT_MEM_ISOINT_ST_MASK 0x00000001
#define CONN_INFRA_RGU_CO_EXT_MEM_ISOINT_ST_CO_EXT_MEM_ISOINT_ST_SHFT 0

#define CONN_INFRA_RGU_FM_CTRL_MEM_PDN_ST_FM_CTRL_MEM_PDN_ST_ADDR CONN_INFRA_RGU_FM_CTRL_MEM_PDN_ST_ADDR
#define CONN_INFRA_RGU_FM_CTRL_MEM_PDN_ST_FM_CTRL_MEM_PDN_ST_MASK 0x00000001
#define CONN_INFRA_RGU_FM_CTRL_MEM_PDN_ST_FM_CTRL_MEM_PDN_ST_SHFT 0

#define CONN_INFRA_RGU_FM_CTRL_MEM_SLP_ST_FM_CTRL_MEM_SLP_ST_ADDR CONN_INFRA_RGU_FM_CTRL_MEM_SLP_ST_ADDR
#define CONN_INFRA_RGU_FM_CTRL_MEM_SLP_ST_FM_CTRL_MEM_SLP_ST_MASK 0x00000001
#define CONN_INFRA_RGU_FM_CTRL_MEM_SLP_ST_FM_CTRL_MEM_SLP_ST_SHFT 0

#define CONN_INFRA_RGU_FM_CTRL_MEM_CKISO_ST_FM_CTRL_MEM_CKISO_ST_ADDR CONN_INFRA_RGU_FM_CTRL_MEM_CKISO_ST_ADDR
#define CONN_INFRA_RGU_FM_CTRL_MEM_CKISO_ST_FM_CTRL_MEM_CKISO_ST_MASK 0x00000001
#define CONN_INFRA_RGU_FM_CTRL_MEM_CKISO_ST_FM_CTRL_MEM_CKISO_ST_SHFT 0

#define CONN_INFRA_RGU_FM_CTRL_MEM_ISOINT_ST_FM_CTRL_MEM_ISOINT_ST_ADDR CONN_INFRA_RGU_FM_CTRL_MEM_ISOINT_ST_ADDR
#define CONN_INFRA_RGU_FM_CTRL_MEM_ISOINT_ST_FM_CTRL_MEM_ISOINT_ST_MASK 0x00000001
#define CONN_INFRA_RGU_FM_CTRL_MEM_ISOINT_ST_FM_CTRL_MEM_ISOINT_ST_SHFT 0

#endif /* __CONN_INFRA_RGU_REGS_H__ */
