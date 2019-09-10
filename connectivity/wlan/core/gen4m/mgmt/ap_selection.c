/******************************************************************************
 *
 * This file is provided under a dual license.  When you use or
 * distribute this software, you may choose to be licensed under
 * version 2 of the GNU General Public License ("GPLv2 License")
 * or BSD License.
 *
 * GPLv2 License
 *
 * Copyright(C) 2016 MediaTek Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of version 2 of the GNU General Public License as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See http://www.gnu.org/licenses/gpl-2.0.html for more details.
 *
 * BSD LICENSE
 *
 * Copyright(C) 2016 MediaTek Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *  * Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *****************************************************************************/

#include "precomp.h"

/*
 * definition for AP selection algrithm
 */
#define BSS_FULL_SCORE                          (100)
#define CHNL_BSS_NUM_THRESOLD                   100
#define BSS_STA_CNT_THRESOLD                    30
#define SCORE_PER_AP                            1
#define ROAMING_NO_SWING_SCORE_STEP             100
/* MCS9 at BW 160 requires rssi at least -48dbm */
#define BEST_RSSI                               -48
/* MCS7 at 20BW, MCS5 at 40BW, MCS4 at 80BW, MCS3 at 160BW */
#define GOOD_RSSI_FOR_HT_VHT                    -64
/* Link speed 1Mbps need at least rssi -94dbm for 2.4G */
#define MINIMUM_RSSI_2G4                        -94
/* Link speed 6Mbps need at least rssi -86dbm for 5G */
#define MINIMUM_RSSI_5G                         -86

/* level of rssi range on StatusBar */
#define RSSI_MAX_LEVEL                          -55
#define RSSI_SECOND_LEVEL                       -66

#define RCPI_FOR_DONT_ROAM                      60 /*-80dbm*/

/* Real Rssi of a Bss may range in current_rssi - 5 dbm
 *to current_rssi + 5 dbm
 */
#define RSSI_DIFF_BETWEEN_BSS                   10 /* dbm */
#define LOW_RSSI_FOR_5G_BAND                    -70 /* dbm */
#define HIGH_RSSI_FOR_5G_BAND                   -60 /* dbm */

#define WEIGHT_IDX_CHNL_UTIL                    0
#define WEIGHT_IDX_RSSI                         2
#define WEIGHT_IDX_SCN_MISS_CNT                 2
#define WEIGHT_IDX_PROBE_RSP                    1
#define WEIGHT_IDX_CLIENT_CNT                   0
#define WEIGHT_IDX_AP_NUM                       0
#define WEIGHT_IDX_5G_BAND                      2
#define WEIGHT_IDX_BAND_WIDTH                   1
#define WEIGHT_IDX_STBC                         1
#define WEIGHT_IDX_DEAUTH_LAST                  1
#define WEIGHT_IDX_BLACK_LIST                   2
#define WEIGHT_IDX_SAA                          0
#define WEIGHT_IDX_CHNL_IDLE                    0
#define WEIGHT_IDX_OPCHNL                       0

#define WEIGHT_IDX_CHNL_UTIL_PER                0
#define WEIGHT_IDX_RSSI_PER                     4
#define WEIGHT_IDX_SCN_MISS_CNT_PER             4
#define WEIGHT_IDX_PROBE_RSP_PER                1
#define WEIGHT_IDX_CLIENT_CNT_PER               1
#define WEIGHT_IDX_AP_NUM_PER                   6
#define WEIGHT_IDX_5G_BAND_PER                  4
#define WEIGHT_IDX_BAND_WIDTH_PER               1
#define WEIGHT_IDX_STBC_PER                     1
#define WEIGHT_IDX_DEAUTH_LAST_PER              1
#define WEIGHT_IDX_BLACK_LIST_PER               4
#define WEIGHT_IDX_SAA_PER                      1
#define WEIGHT_IDX_CHNL_IDLE_PER                6
#define WEIGHT_IDX_OPCHNL_PER                   6

struct weight_config mtk_weight_config[ROAM_TYPE_NUM] = {
	[ROAM_TYPE_RCPI] = {
		.chnl_util_weight = WEIGHT_IDX_CHNL_UTIL,
		.rssi_weight = WEIGHT_IDX_RSSI,
		.scan_miss_cnt_weight = WEIGHT_IDX_SCN_MISS_CNT,
		.probe_resp_weight = WEIGHT_IDX_PROBE_RSP,
		.client_cnt_weight = WEIGHT_IDX_CLIENT_CNT,
		.ap_num_weight = WEIGHT_IDX_AP_NUM,
		.band_weight = WEIGHT_IDX_5G_BAND,
		.band_width_weight = WEIGHT_IDX_BAND_WIDTH,
		.stbc_weight = WEIGHT_IDX_STBC,
		.last_deauth_weight = WEIGHT_IDX_DEAUTH_LAST,
		.black_list_weight = WEIGHT_IDX_BLACK_LIST,
		.saa_weight = WEIGHT_IDX_SAA,
		.chnl_idle_weight = WEIGHT_IDX_CHNL_IDLE,
		.opchnl_weight = WEIGHT_IDX_OPCHNL
	},
	[ROAM_TYPE_PER] = {
		.chnl_util_weight = WEIGHT_IDX_CHNL_UTIL_PER,
		.rssi_weight = WEIGHT_IDX_RSSI_PER,
		.scan_miss_cnt_weight = WEIGHT_IDX_SCN_MISS_CNT_PER,
		.probe_resp_weight = WEIGHT_IDX_PROBE_RSP_PER,
		.client_cnt_weight = WEIGHT_IDX_CLIENT_CNT_PER,
		.ap_num_weight = WEIGHT_IDX_AP_NUM_PER,
		.band_weight = WEIGHT_IDX_5G_BAND_PER,
		.band_width_weight = WEIGHT_IDX_BAND_WIDTH_PER,
		.stbc_weight = WEIGHT_IDX_STBC_PER,
		.last_deauth_weight = WEIGHT_IDX_DEAUTH_LAST_PER,
		.black_list_weight = WEIGHT_IDX_BLACK_LIST_PER,
		.saa_weight = WEIGHT_IDX_SAA_PER,
		.chnl_idle_weight = WEIGHT_IDX_CHNL_IDLE_PER,
		.opchnl_weight = WEIGHT_IDX_OPCHNL_PER
	}
};

#define CALCULATE_SCORE_BY_PROBE_RSP(prBssDesc, eRoamType) \
	(mtk_weight_config[eRoamType].probe_resp_weight * \
	(prBssDesc->fgSeenProbeResp ? BSS_FULL_SCORE : 0))

#define CALCULATE_SCORE_BY_MISS_CNT(prAdapter, prBssDesc, eRoamType) \
	(mtk_weight_config[eRoamType].scan_miss_cnt_weight * \
	(prAdapter->rWifiVar.rScanInfo.u4ScanUpdateIdx - \
	prBssDesc->u4UpdateIdx > 3 ? 0 : \
	(BSS_FULL_SCORE - (prAdapter->rWifiVar.rScanInfo.u4ScanUpdateIdx - \
	prBssDesc->u4UpdateIdx) * 25)))

#define CALCULATE_SCORE_BY_BAND(prAdapter, prBssDesc, cRssi, eRoamType) \
	(mtk_weight_config[eRoamType].band_weight * \
	((prBssDesc->eBand == BAND_5G && prAdapter->fgEnable5GBand && \
	cRssi > -70) ? BSS_FULL_SCORE : 0))

#define CALCULATE_SCORE_BY_STBC(prAdapter, prBssDesc, eRoamType) \
	(mtk_weight_config[eRoamType].stbc_weight * \
	(prBssDesc->fgMultiAnttenaAndSTBC ? BSS_FULL_SCORE:0))

#define CALCULATE_SCORE_BY_DEAUTH(prBssDesc, eRoamType) \
	(mtk_weight_config[eRoamType].last_deauth_weight * \
	(prBssDesc->fgDeauthLastTime ? 0:BSS_FULL_SCORE))

#if CFG_SUPPORT_RSN_SCORE
#define CALCULATE_SCORE_BY_RSN(prBssDesc) \
	(WEIGHT_IDX_RSN * (prBssDesc->fgIsRSNSuitableBss ? BSS_FULL_SCORE:0))
#endif

#if 0
static uint16_t scanCaculateScoreBySTBC(struct ADAPTER *prAdapter,
	struct BSS_DESC *prBssDesc, enum ROAM_TYPE eRoamType)
{
	uint16_t u2Score = 0;
	uint8_t ucSpatial = 0;

	ucSpatial = prBssDesc->ucSpatial;

	if (prBssDesc->fgMultiAnttenaAndSTBC) {
		ucSpatial = (ucSpatial >= 4)?4:ucSpatial;
		u2Score = (BSS_FULL_SCORE-50)*ucSpatial;
	} else {
		u2Score = 0;
	}
	return u2Score*mtk_weight_config[eRoamType].stbc_weight;
}
#endif

/* Channel Utilization: weight index will be */
static uint16_t scanCalculateScoreByChnlInfo(
	struct AIS_SPECIFIC_BSS_INFO *prAisSpecificBssInfo, uint8_t ucChannel,
	enum ROAM_TYPE eRoamType)
{
	struct ESS_CHNL_INFO *prEssChnlInfo = &prAisSpecificBssInfo->
		arCurEssChnlInfo[0];
	uint8_t i = 0;
	uint16_t u2Score = 0;
	uint8_t weight = mtk_weight_config[eRoamType].ap_num_weight;

	for (; i < prAisSpecificBssInfo->ucCurEssChnlInfoNum; i++) {
		if (ucChannel == prEssChnlInfo[i].ucChannel) {
#if 0	/* currently, we don't take channel utilization into account */
			/* the channel utilization max value is 255.
			 *great utilization means little weight value.
			 * the step of weight value is 2.6
			 */
			u2Score = mtk_weight_config[eRoamType].
				chnl_util_weight * (BSS_FULL_SCORE -
				(prEssChnlInfo[i].ucUtilization * 10 / 26));
#endif
			/* if AP num on this channel is greater than 100,
			 * the weight will be 0.
			 * otherwise, the weight value decrease 1
			 * if AP number increase 1
			 */
			if (prEssChnlInfo[i].ucApNum <= CHNL_BSS_NUM_THRESOLD)
				u2Score += weight *
				(BSS_FULL_SCORE - prEssChnlInfo[i].ucApNum *
					SCORE_PER_AP);
			log_dbg(SCN, TRACE, "channel %d, AP num %d\n",
				ucChannel, prEssChnlInfo[i].ucApNum);
			break;
		}
	}
	return u2Score;
}

static uint16_t scanCalculateScoreByBandwidth(struct ADAPTER *prAdapter,
	struct BSS_DESC *prBssDesc, enum ROAM_TYPE eRoamType)
{
	uint16_t u2Score = 0;
	enum ENUM_CHANNEL_WIDTH eChannelWidth = prBssDesc->eChannelWidth;
	uint8_t ucSta5GBW = prAdapter->rWifiVar.ucSta5gBandwidth;
	uint8_t ucSta2GBW = prAdapter->rWifiVar.ucSta2gBandwidth;
	uint8_t ucStaBW = prAdapter->rWifiVar.ucStaBandwidth;

	if (prBssDesc->fgIsVHTPresent && prAdapter->fgEnable5GBand) {
		if (ucSta5GBW > ucStaBW)
			ucSta5GBW = ucStaBW;
		switch (ucSta5GBW) {
		case MAX_BW_20MHZ:
		case MAX_BW_40MHZ:
			eChannelWidth = CW_20_40MHZ;
			break;
		case MAX_BW_80MHZ:
			eChannelWidth = CW_80MHZ;
			break;
		}
		switch (eChannelWidth) {
		case CW_20_40MHZ:
			u2Score = 60;
			break;
		case CW_80MHZ:
			u2Score = 80;
			break;
		case CW_160MHZ:
		case CW_80P80MHZ:
			u2Score = BSS_FULL_SCORE;
			break;
		}
	} else if (prBssDesc->fgIsHTPresent) {
		if (prBssDesc->eBand == BAND_2G4) {
			if (ucSta2GBW > ucStaBW)
				ucSta2GBW = ucStaBW;
			u2Score = (prBssDesc->eSco == 0 ||
					ucSta2GBW == MAX_BW_20MHZ) ? 40:60;
		} else if (prBssDesc->eBand == BAND_5G) {
			if (ucSta5GBW > ucStaBW)
				ucSta5GBW = ucStaBW;
			u2Score = (prBssDesc->eSco == 0 ||
					ucSta5GBW == MAX_BW_20MHZ) ? 40:60;
		}
	} else if (prBssDesc->u2BSSBasicRateSet & RATE_SET_OFDM)
		u2Score = 20;
	else
		u2Score = 10;

	return u2Score * mtk_weight_config[eRoamType].band_width_weight;
}

static uint16_t scanCalculateScoreByClientCnt(struct BSS_DESC *prBssDesc,
			enum ROAM_TYPE eRoamType)
{
	uint16_t u2Score = 0;
	uint16_t u2StaCnt = 0;
#define BSS_STA_CNT_NORMAL_SCORE 50
#define BSS_STA_CNT_GOOD_THRESOLD 10

	log_dbg(SCN, TRACE, "Exist bss load %d, sta cnt %d\n",
			prBssDesc->fgExsitBssLoadIE, prBssDesc->u2StaCnt);

	if (!prBssDesc->fgExsitBssLoadIE) {
		u2Score = BSS_STA_CNT_NORMAL_SCORE;
		return u2Score * mtk_weight_config[eRoamType].client_cnt_weight;
	}

	u2StaCnt = prBssDesc->u2StaCnt;
	if (u2StaCnt > BSS_STA_CNT_THRESOLD)
		u2Score = 0;
	else if (u2StaCnt < BSS_STA_CNT_GOOD_THRESOLD)
		u2Score = BSS_FULL_SCORE - u2StaCnt;
	else
		u2Score = BSS_STA_CNT_NORMAL_SCORE;

	return u2Score * mtk_weight_config[eRoamType].client_cnt_weight;
}

#if CFG_SUPPORT_802_11V_BSS_TRANSITION_MGT
struct NEIGHBOR_AP_T *scanGetNeighborAPEntry(struct LINK *prNeighborApLink,
					     uint8_t *pucBssid)
{
	struct NEIGHBOR_AP_T *prNeighborAP = NULL;

	LINK_FOR_EACH_ENTRY(prNeighborAP, prNeighborApLink, rLinkEntry,
			    struct NEIGHBOR_AP_T)
	{
		if (EQUAL_MAC_ADDR(prNeighborAP->aucBssid, pucBssid))
			return prNeighborAP;
	}
	return NULL;
}

u_int8_t scanPreferenceIsZero(struct ADAPTER *prAdapter, uint8_t *pucBssid,
	uint8_t ucBssIndex)
{
	struct LINK *prNeighborAPLink =
		&aisGetAisSpecBssInfo(prAdapter, ucBssIndex)
		->rNeighborApList.rUsingLink;
	struct NEIGHBOR_AP_T *prNeighborAP = NULL;

	if (prNeighborAPLink->u4NumElem == 0)
		return FALSE;

	prNeighborAP = scanGetNeighborAPEntry(prNeighborAPLink, pucBssid);

	if (prNeighborAP == NULL)
		return FALSE;
	if (!prNeighborAP->fgPrefPresence)
		return FALSE;
	if (prNeighborAP->ucPreference > 0)
		return FALSE;

	return TRUE;
}
#endif

static u_int8_t scanNeedReplaceCandidate(struct ADAPTER *prAdapter,
	struct BSS_DESC *prCandBss, struct BSS_DESC *prCurrBss,
	uint16_t u2CandScore, uint16_t u2CurrScore,
	enum ROAM_TYPE eRoamType, uint8_t ucBssIndex)
{
	int8_t cCandRssi = RCPI_TO_dBm(prCandBss->ucRCPI);
	int8_t cCurrRssi = RCPI_TO_dBm(prCurrBss->ucRCPI);
	uint32_t u4UpdateIdx = prAdapter->rWifiVar.rScanInfo.u4ScanUpdateIdx;
	uint16_t u2CandMiss = u4UpdateIdx - prCandBss->u4UpdateIdx;
	uint16_t u2CurrMiss = u4UpdateIdx - prCurrBss->u4UpdateIdx;
	struct BSS_DESC *prBssDesc = NULL;
	int8_t ucOpChannelNum = 0;

	prBssDesc
		= aisGetTargetBssDesc(prAdapter, ucBssIndex);
	if (prBssDesc)
		ucOpChannelNum = prBssDesc->ucChannelNum;

	/* 1. No need check score case
	 * 1.1 Scan missing count of CurrBss is too more,
	 * but Candidate is suitable, don't replace
	 */
	if (u2CurrMiss > 2 && u2CurrMiss > u2CandMiss) {
		log_dbg(SCN, INFO, "Scan Miss count of CurrBss > 2, and Candidate <= 2\n");
		return FALSE;
	}
	/* 1.2 Scan missing count of Candidate is too more,
	 * but CurrBss is suitable, replace
	 */
	if (u2CandMiss > 2 && u2CandMiss > u2CurrMiss) {
		log_dbg(SCN, INFO, "Scan Miss count of Candidate > 2, and CurrBss <= 2\n");
		return TRUE;
	}
	/* 1.3 Hard connecting RSSI check */
	if ((prCurrBss->eBand == BAND_5G && cCurrRssi < MINIMUM_RSSI_5G) ||
		(prCurrBss->eBand == BAND_2G4 && cCurrRssi < MINIMUM_RSSI_2G4))
		return FALSE;
	else if ((prCandBss->eBand == BAND_5G && cCandRssi < MINIMUM_RSSI_5G) ||
		(prCandBss->eBand == BAND_2G4 && cCandRssi < MINIMUM_RSSI_2G4))
		return TRUE;

	/* 1.4 prefer to select 5G Bss if Rssi of a 5G band BSS is good */
	if (eRoamType != ROAM_TYPE_PER) {
		if (prCandBss->eBand != prCurrBss->eBand) {
			if (prCandBss->eBand == BAND_5G) {
				/* Candidate AP is 5G, don't replace it
				 * if it's good enough.
				 */
				if (cCandRssi >= GOOD_RSSI_FOR_HT_VHT)
					return FALSE;
				if (cCandRssi < LOW_RSSI_FOR_5G_BAND &&
					(cCurrRssi > cCandRssi + 5))
					return TRUE;
			} else {
				/* Current AP is 5G, replace candidate
				 * AP if current AP is good.
				 */
				if (cCurrRssi >= GOOD_RSSI_FOR_HT_VHT)
					return TRUE;
				if (cCurrRssi < LOW_RSSI_FOR_5G_BAND &&
					(cCandRssi > cCurrRssi + 5))
					return FALSE;
			}
		}
	}

	/* 1.5 RSSI of Current Bss is lower than Candidate, don't replace
	 * If the lower Rssi is greater than -59dbm,
	 * then no need check the difference
	 * Otherwise, if difference is greater than 10dbm, select the good RSSI
	 */
	 do {
		if ((eRoamType == ROAM_TYPE_PER) &&
			cCandRssi >= RSSI_SECOND_LEVEL &&
			cCurrRssi >= RSSI_SECOND_LEVEL)
			break;
		if (cCandRssi - cCurrRssi >= RSSI_DIFF_BETWEEN_BSS)
			return FALSE;
		if (cCurrRssi - cCandRssi >= RSSI_DIFF_BETWEEN_BSS)
			return TRUE;
	} while (FALSE);

#if CFG_SUPPORT_802_11V_BSS_TRANSITION_MGT
	if (scanPreferenceIsZero(prAdapter, prCurrBss->aucBSSID,
		ucBssIndex)) {
		log_dbg(SCN, INFO,
			"BTM: %s[" MACSTR "] preference value is 0, skip it\n",
			prCurrBss->aucSSID, MAC2STR(prCurrBss->aucBSSID));
		return FALSE;
	}
#endif
	if (eRoamType == ROAM_TYPE_PER) {
		if (prCandBss->ucChannelNum == ucOpChannelNum) {
			log_dbg(SCN, INFO, "CandBss in opchnl,add CurBss Score\n");
			u2CurrScore += BSS_FULL_SCORE *
				mtk_weight_config[eRoamType].opchnl_weight;
		}
		if (prCurrBss->ucChannelNum == ucOpChannelNum) {
			log_dbg(SCN, INFO, "CurrBss in opchnl,add CandBss Score\n");
			u2CandScore += BSS_FULL_SCORE *
				mtk_weight_config[eRoamType].opchnl_weight;
		}
	}

	/* 2. Check Score */
	/* 2.1 Cases that no need to replace candidate */
	if (prCandBss->fgIsConnected) {
		if ((u2CandScore + ROAMING_NO_SWING_SCORE_STEP) >= u2CurrScore)
			return FALSE;
	} else if (prCurrBss->fgIsConnected) {
		if (u2CandScore >= (u2CurrScore + ROAMING_NO_SWING_SCORE_STEP))
			return FALSE;
	} else if (u2CandScore >= u2CurrScore)
		return FALSE;
	/* 2.2 other cases, replace candidate */
	return TRUE;
}

static u_int8_t scanSanityCheckBssDesc(struct ADAPTER *prAdapter,
	struct BSS_DESC *prBssDesc, enum ENUM_BAND eBand, uint8_t ucChannel,
		u_int8_t fgIsFixedChannel, uint8_t ucBssIndex)
{
	prBssDesc->prBlack = aisQueryBlackList(prAdapter, prBssDesc);
	if (prBssDesc->prBlack &&
		prBssDesc->prBlack->fgIsInFWKBlacklist == TRUE) {
		log_dbg(SCN, WARN, MACSTR" in FW blacklist\n",
			MAC2STR(prBssDesc->aucBSSID));
		return FALSE;
	}

	if (prBssDesc->fgIsConnected) {
		struct BSS_DESC *target =
			aisGetTargetBssDesc(prAdapter, ucBssIndex);

		if (!target || (target && !EQUAL_MAC_ADDR(prBssDesc->aucBSSID,
			target->aucBSSID))) {
			log_dbg(SCN, WARN, MACSTR" used by others\n",
				MAC2STR(prBssDesc->aucBSSID));
					return FALSE;
		}
	}

	if (!(prBssDesc->ucPhyTypeSet &
		(prAdapter->rWifiVar.ucAvailablePhyTypeSet))) {
		log_dbg(SCN, WARN,
			MACSTR" ignore unsupported ucPhyTypeSet = %x\n",
			MAC2STR(prBssDesc->aucBSSID),
			prBssDesc->ucPhyTypeSet);
		return FALSE;
	}
	if (prBssDesc->fgIsUnknownBssBasicRate) {
		log_dbg(SCN, WARN, MACSTR" unknown bss basic rate\n",
			MAC2STR(prBssDesc->aucBSSID));
		return FALSE;
	}
	if (fgIsFixedChannel &&	(eBand != prBssDesc->eBand || ucChannel !=
		prBssDesc->ucChannelNum)) {
		log_dbg(SCN, WARN,
			MACSTR" fix channel required band %d, channel %d\n",
			MAC2STR(prBssDesc->aucBSSID), eBand, ucChannel);
		return FALSE;
	}
	if (!rlmDomainIsLegalChannel(prAdapter, prBssDesc->eBand,
		prBssDesc->ucChannelNum)) {
		log_dbg(SCN, WARN, MACSTR" band %d channel %d is not legal\n",
			MAC2STR(prBssDesc->aucBSSID), prBssDesc->eBand,
			prBssDesc->ucChannelNum);
		return FALSE;
	}

	if (CHECK_FOR_TIMEOUT(kalGetTimeTick(), prBssDesc->rUpdateTime,
		SEC_TO_SYSTIME(SCN_BSS_DESC_STALE_SEC))) {
		log_dbg(SCN, WARN, MACSTR " description is too old.\n",
			MAC2STR(prBssDesc->aucBSSID));
		return FALSE;
	}

#if CFG_SUPPORT_WAPI
	if (aisGetWapiMode(prAdapter, ucBssIndex)) {
		if (!wapiPerformPolicySelection(prAdapter, prBssDesc,
			ucBssIndex)) {
			log_dbg(SCN, WARN, MACSTR " wapi policy select fail.\n",
				MAC2STR(prBssDesc->aucBSSID));
			return FALSE;
		}
	} else
#endif
	if (!rsnPerformPolicySelection(prAdapter, prBssDesc,
		ucBssIndex)) {
		log_dbg(SCN, WARN, MACSTR " rsn policy select fail.\n",
			MAC2STR(prBssDesc->aucBSSID));
		return FALSE;
	}
	if (aisGetAisSpecBssInfo(prAdapter,
		ucBssIndex)->fgCounterMeasure) {
		log_dbg(SCN, WARN, MACSTR " Skip in counter measure period.\n",
			MAC2STR(prBssDesc->aucBSSID));
		return FALSE;
	}
	return TRUE;
}

static uint16_t scanCalculateScoreByRssi(struct BSS_DESC *prBssDesc,
	enum ROAM_TYPE eRoamType)
{
	uint16_t u2Score = 0;
	int8_t cRssi = RCPI_TO_dBm(prBssDesc->ucRCPI);

	if (cRssi >= BEST_RSSI)
		u2Score = 100;
	else if (cRssi <= -98)
		u2Score = 0;
	else
		u2Score = (cRssi + 98) * 2;
	u2Score *= mtk_weight_config[eRoamType].rssi_weight;

	return u2Score;
}

static uint16_t scanCalculateScoreBySaa(struct ADAPTER *prAdapter,
	struct BSS_DESC *prBssDesc, enum ROAM_TYPE eRoamType)
{
	uint16_t u2Score = 0;
	struct STA_RECORD *prStaRec = (struct STA_RECORD *) NULL;

	prStaRec = cnmGetStaRecByAddress(prAdapter, NETWORK_TYPE_AIS,
		prBssDesc->aucSrcAddr);
	if (prStaRec)
		u2Score = mtk_weight_config[eRoamType].saa_weight *
		(prStaRec->ucTxAuthAssocRetryCount ? 0 : BSS_FULL_SCORE);
	else
		u2Score = mtk_weight_config[eRoamType].saa_weight *
		BSS_FULL_SCORE;

	return u2Score;
}

static uint16_t scanCalculateScoreByIdleTime(struct ADAPTER *prAdapter,
	uint8_t ucChannel, enum ROAM_TYPE eRoamType, uint8_t ucBssIndex)
{
	uint8_t u4ChCnt = 0;
	uint16_t u2Score = 0;
	uint16_t u2ChIdleSlot;
	uint16_t u2ChIdleTime;
	uint16_t u2ChIdleUtil;
	uint16_t u2ChDwellTime;
	struct SCAN_INFO *prScanInfo;
	struct SCAN_PARAM *prScanParam;
	struct BSS_INFO *prAisBssInfo;
#define CHNL_DWELL_TIME_DEFAULT  100
#define CHNL_DWELL_TIME_ONLINE   50

	prAisBssInfo = aisGetAisBssInfo(prAdapter, ucBssIndex);
	prScanInfo = &(prAdapter->rWifiVar.rScanInfo);
	prScanParam = &(prScanInfo->rScanParam);

	if (prScanParam->u2ChannelDwellTime > 0)
		u2ChDwellTime = prScanParam->u2ChannelDwellTime;
	else if (prAisBssInfo->eConnectionState == PARAM_MEDIA_STATE_CONNECTED)
		u2ChDwellTime = CHNL_DWELL_TIME_ONLINE;
	else
		u2ChDwellTime = CHNL_DWELL_TIME_DEFAULT;

	for (u4ChCnt = 0; u4ChCnt < prScanInfo
		->ucSparseChannelArrayValidNum; u4ChCnt++) {
		if (ucChannel == prScanInfo->aucChannelNum[u4ChCnt]) {
			u2ChIdleSlot =
				prScanInfo->au2ChannelIdleTime[u4ChCnt];
			u2ChIdleTime = u2ChIdleSlot * 9;
			u2ChIdleUtil =
				(u2ChIdleTime * 100) / (u2ChDwellTime * 1000);
			if (u2ChIdleUtil > BSS_FULL_SCORE)
				u2ChIdleUtil = BSS_FULL_SCORE;
			u2Score = u2ChIdleUtil *
				mtk_weight_config[eRoamType].chnl_idle_weight;
			break;
		}
	}

	return u2Score;
}

u_int8_t scanApOverload(uint16_t status, uint16_t reason)
{
	switch (status) {
	case STATUS_CODE_ASSOC_DENIED_AP_OVERLOAD:
	case STATUS_CODE_ASSOC_DENIED_BANDWIDTH:
	case STATUS_CODE_ASSOC_DENIED_OUTSIDE_STANDARD:
		return TRUE;
	}
	switch (reason) {
	case REASON_CODE_DISASSOC_LACK_OF_BANDWIDTH:
	case REASON_CODE_DISASSOC_AP_OVERLOAD:
		return TRUE;
	}
	return FALSE;
}

uint16_t scanCalculateScoreByBlackList(struct ADAPTER *prAdapter,
	    struct BSS_DESC *prBssDesc, enum ROAM_TYPE eRoamType)
{
	uint16_t u2Score = 0;

	if (!prBssDesc->prBlack)
		u2Score = 100;
	else if (scanApOverload(prBssDesc->prBlack->u2AuthStatus,
		prBssDesc->prBlack->u2DeauthReason) ||
		 prBssDesc->prBlack->ucCount >= 10)
		u2Score = 0;
	else
		u2Score = 100 - prBssDesc->prBlack->ucCount * 10;

	return u2Score * mtk_weight_config[eRoamType].black_list_weight;
}

uint16_t scanCalculateTotalScore(struct ADAPTER *prAdapter,
	struct BSS_DESC *prBssDesc, enum ROAM_TYPE eRoamType,
	uint8_t ucBssIndex)
{
	struct AIS_SPECIFIC_BSS_INFO *prAisSpecificBssInfo = NULL;
	uint16_t u2ScoreStaCnt = 0;
	uint16_t u2ScoreBandwidth = 0;
	uint16_t u2ScoreSTBC = 0;
	uint16_t u2ScoreChnlInfo = 0;
	uint16_t u2ScoreSnrRssi = 0;
	uint16_t u2ScoreDeauth = 0;
	uint16_t u2ScoreProbeRsp = 0;
	uint16_t u2ScoreScanMiss = 0;
	uint16_t u2ScoreBand = 0;
	uint16_t u2ScoreSaa = 0;
	uint16_t u2ScoreIdleTime = 0;
	uint16_t u2ScoreTotal = 0;
	uint16_t u2BlackListScore = 0;
	int8_t cRssi = -128;

	prAisSpecificBssInfo =
		aisGetAisSpecBssInfo(prAdapter, ucBssIndex);
	cRssi = RCPI_TO_dBm(prBssDesc->ucRCPI);

	u2ScoreBandwidth =
		scanCalculateScoreByBandwidth(prAdapter, prBssDesc, eRoamType);
	u2ScoreStaCnt = scanCalculateScoreByClientCnt(prBssDesc, eRoamType);
	u2ScoreSTBC = CALCULATE_SCORE_BY_STBC(prAdapter, prBssDesc, eRoamType);
	u2ScoreChnlInfo =
		scanCalculateScoreByChnlInfo(prAisSpecificBssInfo,
		prBssDesc->ucChannelNum, eRoamType);
	u2ScoreSnrRssi = scanCalculateScoreByRssi(prBssDesc, eRoamType);
	u2ScoreDeauth = CALCULATE_SCORE_BY_DEAUTH(prBssDesc, eRoamType);
	u2ScoreProbeRsp = CALCULATE_SCORE_BY_PROBE_RSP(prBssDesc, eRoamType);
	u2ScoreScanMiss = CALCULATE_SCORE_BY_MISS_CNT(prAdapter,
		prBssDesc, eRoamType);
	u2ScoreBand = CALCULATE_SCORE_BY_BAND(prAdapter, prBssDesc,
		cRssi, eRoamType);
	u2ScoreSaa = scanCalculateScoreBySaa(prAdapter, prBssDesc, eRoamType);
	u2ScoreIdleTime = scanCalculateScoreByIdleTime(prAdapter,
		prBssDesc->ucChannelNum, eRoamType, ucBssIndex);
	u2BlackListScore =
	       scanCalculateScoreByBlackList(prAdapter, prBssDesc, eRoamType);

	u2ScoreTotal = u2ScoreBandwidth + u2ScoreChnlInfo +
		u2ScoreDeauth + u2ScoreProbeRsp + u2ScoreScanMiss +
		u2ScoreSnrRssi + u2ScoreStaCnt + u2ScoreSTBC +
		u2ScoreBand + u2BlackListScore + u2ScoreSaa +
		u2ScoreIdleTime;

	log_dbg(SCN, INFO,
		MACSTR
		" cRSSI[%d] 5G[%d] Score,Total %d,DE[%d],PR[%d],SM[%d],RSSI[%d],BD[%d],BL[%d],SAA[%d],BW[%d],SC[%d],ST[%d],CI[%d],IT[%d]\n",
		MAC2STR(prBssDesc->aucBSSID), cRssi,
		(prBssDesc->eBand == BAND_5G ? 1 : 0), u2ScoreTotal,
		u2ScoreDeauth, u2ScoreProbeRsp, u2ScoreScanMiss,
		u2ScoreSnrRssi, u2ScoreBand, u2BlackListScore,
		u2ScoreSaa, u2ScoreBandwidth, u2ScoreStaCnt,
		u2ScoreSTBC, u2ScoreChnlInfo, u2ScoreIdleTime);

	return u2ScoreTotal;
}
/*
 * Bss Characteristics to be taken into account when calculate Score:
 * Channel Loading Group:
 * 1. Client Count (in BSS Load IE).
 * 2. AP number on the Channel.
 *
 * RF Group:
 * 1. Channel utilization.
 * 2. SNR.
 * 3. RSSI.
 *
 * Misc Group:
 * 1. Deauth Last time.
 * 2. Scan Missing Count.
 * 3. Has probe response in scan result.
 *
 * Capability Group:
 * 1. Prefer 5G band.
 * 2. Bandwidth.
 * 3. STBC and Multi Anttena.
 */
struct BSS_DESC *scanSearchBssDescByScoreForAis(struct ADAPTER *prAdapter,
	uint8_t ucBssIndex)
{
	struct AIS_SPECIFIC_BSS_INFO *prAisSpecificBssInfo = NULL;
	struct ROAMING_INFO *prRoamingFsmInfo = NULL;
	struct BSS_INFO *prAisBssInfo = NULL;
	struct LINK *prEssLink = NULL;
	struct CONNECTION_SETTINGS *prConnSettings = NULL;
	struct BSS_DESC *prBssDesc = NULL;
	struct BSS_DESC *prCandBssDesc = NULL;
	struct BSS_DESC *prCandBssDescForLowRssi = NULL;
	uint16_t u2ScoreTotal = 0;
	uint16_t u2CandBssScore = 0;
	uint16_t u2CandBssScoreForLowRssi = 0;
	u_int8_t fgSearchBlackList = FALSE;
	u_int8_t fgIsFixedChannel = FALSE;
	enum ENUM_BAND eBand = BAND_2G4;
	uint8_t ucChannel = 0;
	enum ROAM_TYPE eRoamType = ROAM_TYPE_RCPI;
	enum ENUM_PARAM_CONNECTION_POLICY policy;

	if (!prAdapter) {
		log_dbg(SCN, ERROR, "prAdapter is NULL!\n");
		return NULL;
	}
	prAisSpecificBssInfo =
		aisGetAisSpecBssInfo(prAdapter, ucBssIndex);
	prConnSettings =
		aisGetConnSettings(prAdapter, ucBssIndex);
	prEssLink = &prAisSpecificBssInfo->rCurEssLink;
	prRoamingFsmInfo =
		aisGetRoamingInfo(prAdapter, ucBssIndex);
	prAisBssInfo = aisGetAisBssInfo(prAdapter, ucBssIndex);
	if (prAisBssInfo->eConnectionState == PARAM_MEDIA_STATE_CONNECTED &&
	    prRoamingFsmInfo->eReason == ROAMING_REASON_TX_ERR) {
		eRoamType = ROAM_TYPE_PER;
	}
#if CFG_SUPPORT_CHNL_CONFLICT_REVISE
	fgIsFixedChannel = cnmAisDetectP2PChannel
		(prAdapter, &eBand, &ucChannel);
#else
	fgIsFixedChannel =
		cnmAisInfraChannelFixed(prAdapter, &eBand, &ucChannel);
#endif
	aisRemoveTimeoutBlacklist(prAdapter);
	log_dbg(SCN, INFO, "%s: ConnectionPolicy = %d\n",
		__func__,
		prConnSettings->eConnectionPolicy);
	policy = prConnSettings->eConnectionPolicy;

try_again:
	LINK_FOR_EACH_ENTRY(prBssDesc, prEssLink, rLinkEntryEss[ucBssIndex],
		struct BSS_DESC) {
		/*
		 * Skip if
		 * 1. sanity check fail or
		 * 2. bssid is in driver's blacklist in the first round
		 */
		if (!scanSanityCheckBssDesc(prAdapter, prBssDesc, eBand,
			ucChannel, fgIsFixedChannel, ucBssIndex) ||
		    (!fgSearchBlackList && prBssDesc->prBlack))
			continue;

		/* pick by bssid first */
		if (policy == CONNECT_BY_BSSID) {
			if (EQUAL_MAC_ADDR(prBssDesc->aucBSSID,
					prConnSettings->aucBSSID)) {
				log_dbg(SCN, INFO, MACSTR" match bssid\n",
					MAC2STR(prBssDesc->aucBSSID));
				prCandBssDesc = prBssDesc;
				break;
			}
			/* skip when bssid unmatched if conn by bssid */
			log_dbg(SCN, INFO, MACSTR" unmatch bssid\n",
				MAC2STR(prBssDesc->aucBSSID));
			continue;
		} else if (policy == CONNECT_BY_BSSID_HINT) {
			if (EQUAL_MAC_ADDR(prBssDesc->aucBSSID,
					prConnSettings->aucBSSIDHint)) {
				log_dbg(SCN, INFO, MACSTR" match bssid_hint\n",
					MAC2STR(prBssDesc->aucBSSID));
				prCandBssDesc = prBssDesc;
				break;
			}
		}

		u2ScoreTotal = scanCalculateTotalScore(prAdapter, prBssDesc,
			eRoamType, ucBssIndex);
		if (!prCandBssDesc ||
			scanNeedReplaceCandidate(prAdapter, prCandBssDesc,
			prBssDesc, u2CandBssScore, u2ScoreTotal, eRoamType,
			ucBssIndex)) {
			prCandBssDesc = prBssDesc;
			u2CandBssScore = u2ScoreTotal;
		}
	}

	if (prCandBssDesc) {
		if (prCandBssDesc->fgIsConnected && !fgSearchBlackList &&
			prEssLink->u4NumElem > 0) {
			fgSearchBlackList = TRUE;
			log_dbg(SCN, INFO, "Can't roam out, try blacklist\n");
			goto try_again;
		}
		if (prAisBssInfo->eConnectionState ==
			PARAM_MEDIA_STATE_CONNECTED &&
			prCandBssDesc->ucRCPI < RCPI_FOR_DONT_ROAM) {
			log_dbg(SCN, INFO,
				"Don't roam " MACSTR " because rssi too low\n",
				MAC2STR(prCandBssDesc->aucBSSID));
			return NULL;
		}
		if (prConnSettings->eConnectionPolicy == CONNECT_BY_BSSID)
			log_dbg(SCN, INFO, "Selected "
				MACSTR
				" %d base on ssid,when find %s, "
				MACSTR
				" in %d bssid,fix channel %d.\n",
				MAC2STR(prCandBssDesc->aucBSSID),
				RCPI_TO_dBm(prCandBssDesc->ucRCPI),
				prConnSettings->aucSSID,
				MAC2STR(prConnSettings->aucBSSID),
				prEssLink->u4NumElem, ucChannel);
		else
			log_dbg(SCN, INFO,
				"Selected "
				MACSTR
				", cRSSI[%d] 5G[%d] Score %d when find %s, "
				MACSTR
				" in %d BSSes, fix channel %d.\n",
				MAC2STR(prCandBssDesc->aucBSSID),
				RCPI_TO_dBm(prCandBssDesc->ucRCPI),
				(prCandBssDesc->eBand == BAND_5G ? 1 : 0),
				u2CandBssScore, prConnSettings->aucSSID,
				MAC2STR(prConnSettings->aucBSSID),
				prEssLink->u4NumElem, ucChannel);

		return prCandBssDesc;
	} else if (prCandBssDescForLowRssi) {
		log_dbg(SCN, INFO, "Selected " MACSTR
			", Score %d when find %s, " MACSTR
			" in %d BSSes, fix channel %d.\n",
			MAC2STR(prCandBssDescForLowRssi->aucBSSID),
			u2CandBssScoreForLowRssi, prConnSettings->aucSSID,
			MAC2STR(prConnSettings->aucBSSID), prEssLink->u4NumElem,
			ucChannel);
		return prCandBssDescForLowRssi;
	}

	/* if No Candidate BSS is found, try BSSes which are in blacklist */
	if (!fgSearchBlackList && prEssLink->u4NumElem > 0) {
		fgSearchBlackList = TRUE;
		log_dbg(SCN, INFO, "No Bss is found, Try blacklist\n");
		goto try_again;
	}
	log_dbg(SCN, INFO, "Selected None when find %s, " MACSTR
		" in %d BSSes, fix channel %d.\n",
		prConnSettings->aucSSID, MAC2STR(prConnSettings->aucBSSID),
		prEssLink->u4NumElem, ucChannel);
	return NULL;
}

void scanGetCurrentEssChnlList(struct ADAPTER *prAdapter,
	uint8_t ucBssIndex)
{
	struct BSS_DESC *prBssDesc = NULL;
	struct LINK *prBSSDescList =
		&prAdapter->rWifiVar.rScanInfo.rBSSDescList;
	struct CONNECTION_SETTINGS *prConnSettings =
		aisGetConnSettings(prAdapter, ucBssIndex);
	struct ESS_CHNL_INFO *prEssChnlInfo;
	struct LINK *prCurEssLink;
	struct AIS_SPECIFIC_BSS_INFO *prAisSpecBssInfo;
	uint8_t aucChnlBitMap[30] = {0,};
	uint8_t aucChnlApNum[215] = {0,};
	uint8_t aucChnlUtil[215] = {0,};
	uint8_t ucByteNum = 0;
	uint8_t ucBitNum = 0;
	uint8_t ucChnlCount = 0;
	uint8_t j = 0;

	if (!prConnSettings)  {
		log_dbg(SCN, INFO, "No prConnSettings\n");
		return;
	}

	if (prConnSettings->ucSSIDLen == 0) {
		log_dbg(SCN, INFO, "No Ess are expected to connect\n");
		return;
	}

	prAisSpecBssInfo =
		aisGetAisSpecBssInfo(prAdapter, ucBssIndex);
	if (!prAisSpecBssInfo) {
		log_dbg(SCN, INFO, "No prAisSpecBssInfo\n");
		return;
	}
	prEssChnlInfo =
		&prAisSpecBssInfo->arCurEssChnlInfo[0];
	if (!prEssChnlInfo) {
		log_dbg(SCN, INFO, "No prEssChnlInfo\n");
		return;
	}
	prCurEssLink =
		&prAisSpecBssInfo->rCurEssLink;
	if (!prCurEssLink) {
		log_dbg(SCN, INFO, "No prCurEssLink\n");
		return;
	}

	kalMemZero(prEssChnlInfo, CFG_MAX_NUM_OF_CHNL_INFO *
		sizeof(struct ESS_CHNL_INFO));

	while (!LINK_IS_EMPTY(prCurEssLink)) {
		prBssDesc = LINK_PEEK_HEAD(prCurEssLink,
			struct BSS_DESC, rLinkEntryEss[ucBssIndex]);
		LINK_REMOVE_KNOWN_ENTRY(prCurEssLink,
			&prBssDesc->rLinkEntryEss[ucBssIndex]);
	}
	LINK_FOR_EACH_ENTRY(prBssDesc, prBSSDescList, rLinkEntry,
		struct BSS_DESC) {
		if (prBssDesc->ucChannelNum > 214)
			continue;
		/* Statistic AP num for each channel */
		if (aucChnlApNum[prBssDesc->ucChannelNum] < 255)
			aucChnlApNum[prBssDesc->ucChannelNum]++;
		if (aucChnlUtil[prBssDesc->ucChannelNum] <
			prBssDesc->ucChnlUtilization)
			aucChnlUtil[prBssDesc->ucChannelNum] =
				prBssDesc->ucChnlUtilization;
		if (!EQUAL_SSID(prConnSettings->aucSSID,
			prConnSettings->ucSSIDLen,
			prBssDesc->aucSSID, prBssDesc->ucSSIDLen))
			continue;
		/* Record same BSS list */
		LINK_INSERT_HEAD(prCurEssLink,
			&prBssDesc->rLinkEntryEss[ucBssIndex]);
		ucByteNum = prBssDesc->ucChannelNum / 8;
		ucBitNum = prBssDesc->ucChannelNum % 8;
		if (aucChnlBitMap[ucByteNum] & BIT(ucBitNum))
			continue;
		aucChnlBitMap[ucByteNum] |= BIT(ucBitNum);
		prEssChnlInfo[ucChnlCount].ucChannel = prBssDesc->ucChannelNum;
		ucChnlCount++;
		if (ucChnlCount >= CFG_MAX_NUM_OF_CHNL_INFO)
			break;
	}
	prAisSpecBssInfo->ucCurEssChnlInfoNum =
		ucChnlCount;
	for (j = 0; j < ucChnlCount; j++) {
		uint8_t ucChnl = prEssChnlInfo[j].ucChannel;

		prEssChnlInfo[j].ucApNum = aucChnlApNum[ucChnl];
		prEssChnlInfo[j].ucUtilization = aucChnlUtil[ucChnl];
	}
#if 0
	/* Sort according to AP number */
	for (j = 0; j < ucChnlCount; j++) {
		for (i = j + 1; i < ucChnlCount; i++)
			if (prEssChnlInfo[j].ucApNum >
				prEssChnlInfo[i].ucApNum) {
				struct ESS_CHNL_INFO rTemp = prEssChnlInfo[j];

				prEssChnlInfo[j] = prEssChnlInfo[i];
				prEssChnlInfo[i] = rTemp;
			}
	}
#endif
	log_dbg(SCN, INFO, "Find %s in %d BSSes, result %d\n",
		prConnSettings->aucSSID, prBSSDescList->u4NumElem,
		prCurEssLink->u4NumElem);
}

/*!
* \brief    This function is to decide if we can roam out by this beacon time
*
* \param[in] prAdapter  Pointer of ADAPTER_T
*
* \return true	if we can roam out
*         false	others
*/
/*----------------------------------------------------------------------------*/
uint8_t scanBeaconTimeoutFilterPolicyForAis(struct ADAPTER *prAdapter,
	uint8_t ucBssIndex)
{
	struct ROAMING_INFO *roam;
	int8_t cRssi;
	enum ENUM_ROAMING_REASON reason;

	roam = aisGetRoamingInfo(prAdapter, ucBssIndex);
	reason = roam->eReason;
	cRssi = prAdapter->rLinkQuality.rLq[ucBssIndex].cRssi;

	if (IS_BSS_INDEX_AIS(prAdapter, ucBssIndex) &&
		roam->fgIsEnableRoaming && cRssi > GOOD_RSSI_FOR_HT_VHT - 5) {
		struct BSS_DESC *target;
		struct BSS_DESC *bss;

		/* Good rssi but beacon timeout happened => PER */
		roam->eReason = ROAMING_REASON_TX_ERR;
		target = aisGetTargetBssDesc(prAdapter, ucBssIndex);
		bss = scanSearchBssDescByScoreForAis(prAdapter, ucBssIndex);
		if (bss && !EQUAL_MAC_ADDR(bss->aucBSSID, target->aucBSSID)) {
			log_dbg(SCN, INFO, "Better AP for beacon timeout");
			return TRUE;
		}
	}

	roam->eReason = reason;
	return FALSE;
}