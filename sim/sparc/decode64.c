/* Simulator instruction decoder for sparc64.

THIS FILE IS MACHINE GENERATED WITH CGEN.

Copyright (C) 1999 Cygnus Solutions, Inc.

This file is part of the Cygnus Simulators.


*/

#define WANT_CPU sparc64
#define WANT_CPU_SPARC64

#include "sim-main.h"
#include "sim-assert.h"

/* FIXME: Need to review choices for the following.  */

#if WITH_SEM_SWITCH_FULL
#define FULL(fn)
#else
#define FULL(fn) CONCAT3 (sparc64,_sem_,fn) ,
#endif

#if WITH_FAST
#if WITH_SEM_SWITCH_FAST
#define FAST(fn)
#else
#define FAST(fn) CONCAT3 (sparc64,_semf_,fn) , /* f for fast */
#endif
#else
#define FAST(fn)
#endif

/* The instruction descriptor array.
   This is computed at runtime.  Space for it is not malloc'd to save a
   teensy bit of cpu in the decoder.  Moving it to malloc space is trivial
   but won't be done until necessary (we don't currently support the runtime
   addition of instructions nor an SMP machine with different cpus).  */
static IDESC sparc64_insn_data[SPARC64_INSN_MAX];

/* The INSN_ prefix is not here and is instead part of the `insn' argument
   to avoid collisions with header files (e.g. `AND' in ansidecl.h).  */
#define IDX(insn) CONCAT2 (SPARC64_,insn)
#define TYPE(insn) CONCAT2 (SPARC_,insn)

/* Commas between elements are contained in the macros.
   Some of these are conditionally compiled out.  */

static const struct insn_sem sparc64_insn_sem[] =
{
  { VIRTUAL_INSN_X_INVALID, IDX (INSN_X_INVALID), FULL (x_invalid) FAST (x_invalid) },
  { VIRTUAL_INSN_X_AFTER, IDX (INSN_X_AFTER), FULL (x_after) FAST (x_after) },
  { VIRTUAL_INSN_X_BEFORE, IDX (INSN_X_BEFORE), FULL (x_before) FAST (x_before) },
  { VIRTUAL_INSN_X_CTI_CHAIN, IDX (INSN_X_CTI_CHAIN), FULL (x_cti_chain) FAST (x_cti_chain) },
  { VIRTUAL_INSN_X_CHAIN, IDX (INSN_X_CHAIN), FULL (x_chain) FAST (x_chain) },
  { VIRTUAL_INSN_X_BEGIN, IDX (INSN_X_BEGIN), FULL (x_begin) FAST (x_begin) },
  { TYPE (INSN_BEQZ), IDX (INSN_BEQZ), FULL (beqz) FAST (beqz) },
  { TYPE (INSN_BGEZ), IDX (INSN_BGEZ), FULL (bgez) FAST (bgez) },
  { TYPE (INSN_BGTZ), IDX (INSN_BGTZ), FULL (bgtz) FAST (bgtz) },
  { TYPE (INSN_BLEZ), IDX (INSN_BLEZ), FULL (blez) FAST (blez) },
  { TYPE (INSN_BLTZ), IDX (INSN_BLTZ), FULL (bltz) FAST (bltz) },
  { TYPE (INSN_BNEZ), IDX (INSN_BNEZ), FULL (bnez) FAST (bnez) },
  { TYPE (INSN_BPCC_BA), IDX (INSN_BPCC_BA), FULL (bpcc_ba) FAST (bpcc_ba) },
  { TYPE (INSN_BPCC_BN), IDX (INSN_BPCC_BN), FULL (bpcc_bn) FAST (bpcc_bn) },
  { TYPE (INSN_BPCC_BNE), IDX (INSN_BPCC_BNE), FULL (bpcc_bne) FAST (bpcc_bne) },
  { TYPE (INSN_BPCC_BE), IDX (INSN_BPCC_BE), FULL (bpcc_be) FAST (bpcc_be) },
  { TYPE (INSN_BPCC_BG), IDX (INSN_BPCC_BG), FULL (bpcc_bg) FAST (bpcc_bg) },
  { TYPE (INSN_BPCC_BLE), IDX (INSN_BPCC_BLE), FULL (bpcc_ble) FAST (bpcc_ble) },
  { TYPE (INSN_BPCC_BGE), IDX (INSN_BPCC_BGE), FULL (bpcc_bge) FAST (bpcc_bge) },
  { TYPE (INSN_BPCC_BL), IDX (INSN_BPCC_BL), FULL (bpcc_bl) FAST (bpcc_bl) },
  { TYPE (INSN_BPCC_BGU), IDX (INSN_BPCC_BGU), FULL (bpcc_bgu) FAST (bpcc_bgu) },
  { TYPE (INSN_BPCC_BLEU), IDX (INSN_BPCC_BLEU), FULL (bpcc_bleu) FAST (bpcc_bleu) },
  { TYPE (INSN_BPCC_BCC), IDX (INSN_BPCC_BCC), FULL (bpcc_bcc) FAST (bpcc_bcc) },
  { TYPE (INSN_BPCC_BCS), IDX (INSN_BPCC_BCS), FULL (bpcc_bcs) FAST (bpcc_bcs) },
  { TYPE (INSN_BPCC_BPOS), IDX (INSN_BPCC_BPOS), FULL (bpcc_bpos) FAST (bpcc_bpos) },
  { TYPE (INSN_BPCC_BNEG), IDX (INSN_BPCC_BNEG), FULL (bpcc_bneg) FAST (bpcc_bneg) },
  { TYPE (INSN_BPCC_BVC), IDX (INSN_BPCC_BVC), FULL (bpcc_bvc) FAST (bpcc_bvc) },
  { TYPE (INSN_BPCC_BVS), IDX (INSN_BPCC_BVS), FULL (bpcc_bvs) FAST (bpcc_bvs) },
  { TYPE (INSN_DONE), IDX (INSN_DONE), FULL (done) FAST (done) },
  { TYPE (INSN_RETRY), IDX (INSN_RETRY), FULL (retry) FAST (retry) },
  { TYPE (INSN_FLUSH), IDX (INSN_FLUSH), FULL (flush) FAST (flush) },
  { TYPE (INSN_FLUSH_IMM), IDX (INSN_FLUSH_IMM), FULL (flush_imm) FAST (flush_imm) },
  { TYPE (INSN_FLUSHW), IDX (INSN_FLUSHW), FULL (flushw) FAST (flushw) },
  { TYPE (INSN_IMPDEP1), IDX (INSN_IMPDEP1), FULL (impdep1) FAST (impdep1) },
  { TYPE (INSN_IMPDEP2), IDX (INSN_IMPDEP2), FULL (impdep2) FAST (impdep2) },
  { TYPE (INSN_MEMBAR), IDX (INSN_MEMBAR), FULL (membar) FAST (membar) },
  { TYPE (INSN_MOVA_ICC_ICC), IDX (INSN_MOVA_ICC_ICC), FULL (mova_icc_icc) FAST (mova_icc_icc) },
  { TYPE (INSN_MOVA_IMM_ICC_ICC), IDX (INSN_MOVA_IMM_ICC_ICC), FULL (mova_imm_icc_icc) FAST (mova_imm_icc_icc) },
  { TYPE (INSN_MOVA_XCC_XCC), IDX (INSN_MOVA_XCC_XCC), FULL (mova_xcc_xcc) FAST (mova_xcc_xcc) },
  { TYPE (INSN_MOVA_IMM_XCC_XCC), IDX (INSN_MOVA_IMM_XCC_XCC), FULL (mova_imm_xcc_xcc) FAST (mova_imm_xcc_xcc) },
  { TYPE (INSN_MOVN_ICC_ICC), IDX (INSN_MOVN_ICC_ICC), FULL (movn_icc_icc) FAST (movn_icc_icc) },
  { TYPE (INSN_MOVN_IMM_ICC_ICC), IDX (INSN_MOVN_IMM_ICC_ICC), FULL (movn_imm_icc_icc) FAST (movn_imm_icc_icc) },
  { TYPE (INSN_MOVN_XCC_XCC), IDX (INSN_MOVN_XCC_XCC), FULL (movn_xcc_xcc) FAST (movn_xcc_xcc) },
  { TYPE (INSN_MOVN_IMM_XCC_XCC), IDX (INSN_MOVN_IMM_XCC_XCC), FULL (movn_imm_xcc_xcc) FAST (movn_imm_xcc_xcc) },
  { TYPE (INSN_MOVNE_ICC_ICC), IDX (INSN_MOVNE_ICC_ICC), FULL (movne_icc_icc) FAST (movne_icc_icc) },
  { TYPE (INSN_MOVNE_IMM_ICC_ICC), IDX (INSN_MOVNE_IMM_ICC_ICC), FULL (movne_imm_icc_icc) FAST (movne_imm_icc_icc) },
  { TYPE (INSN_MOVNE_XCC_XCC), IDX (INSN_MOVNE_XCC_XCC), FULL (movne_xcc_xcc) FAST (movne_xcc_xcc) },
  { TYPE (INSN_MOVNE_IMM_XCC_XCC), IDX (INSN_MOVNE_IMM_XCC_XCC), FULL (movne_imm_xcc_xcc) FAST (movne_imm_xcc_xcc) },
  { TYPE (INSN_MOVE_ICC_ICC), IDX (INSN_MOVE_ICC_ICC), FULL (move_icc_icc) FAST (move_icc_icc) },
  { TYPE (INSN_MOVE_IMM_ICC_ICC), IDX (INSN_MOVE_IMM_ICC_ICC), FULL (move_imm_icc_icc) FAST (move_imm_icc_icc) },
  { TYPE (INSN_MOVE_XCC_XCC), IDX (INSN_MOVE_XCC_XCC), FULL (move_xcc_xcc) FAST (move_xcc_xcc) },
  { TYPE (INSN_MOVE_IMM_XCC_XCC), IDX (INSN_MOVE_IMM_XCC_XCC), FULL (move_imm_xcc_xcc) FAST (move_imm_xcc_xcc) },
  { TYPE (INSN_MOVG_ICC_ICC), IDX (INSN_MOVG_ICC_ICC), FULL (movg_icc_icc) FAST (movg_icc_icc) },
  { TYPE (INSN_MOVG_IMM_ICC_ICC), IDX (INSN_MOVG_IMM_ICC_ICC), FULL (movg_imm_icc_icc) FAST (movg_imm_icc_icc) },
  { TYPE (INSN_MOVG_XCC_XCC), IDX (INSN_MOVG_XCC_XCC), FULL (movg_xcc_xcc) FAST (movg_xcc_xcc) },
  { TYPE (INSN_MOVG_IMM_XCC_XCC), IDX (INSN_MOVG_IMM_XCC_XCC), FULL (movg_imm_xcc_xcc) FAST (movg_imm_xcc_xcc) },
  { TYPE (INSN_MOVLE_ICC_ICC), IDX (INSN_MOVLE_ICC_ICC), FULL (movle_icc_icc) FAST (movle_icc_icc) },
  { TYPE (INSN_MOVLE_IMM_ICC_ICC), IDX (INSN_MOVLE_IMM_ICC_ICC), FULL (movle_imm_icc_icc) FAST (movle_imm_icc_icc) },
  { TYPE (INSN_MOVLE_XCC_XCC), IDX (INSN_MOVLE_XCC_XCC), FULL (movle_xcc_xcc) FAST (movle_xcc_xcc) },
  { TYPE (INSN_MOVLE_IMM_XCC_XCC), IDX (INSN_MOVLE_IMM_XCC_XCC), FULL (movle_imm_xcc_xcc) FAST (movle_imm_xcc_xcc) },
  { TYPE (INSN_MOVGE_ICC_ICC), IDX (INSN_MOVGE_ICC_ICC), FULL (movge_icc_icc) FAST (movge_icc_icc) },
  { TYPE (INSN_MOVGE_IMM_ICC_ICC), IDX (INSN_MOVGE_IMM_ICC_ICC), FULL (movge_imm_icc_icc) FAST (movge_imm_icc_icc) },
  { TYPE (INSN_MOVGE_XCC_XCC), IDX (INSN_MOVGE_XCC_XCC), FULL (movge_xcc_xcc) FAST (movge_xcc_xcc) },
  { TYPE (INSN_MOVGE_IMM_XCC_XCC), IDX (INSN_MOVGE_IMM_XCC_XCC), FULL (movge_imm_xcc_xcc) FAST (movge_imm_xcc_xcc) },
  { TYPE (INSN_MOVL_ICC_ICC), IDX (INSN_MOVL_ICC_ICC), FULL (movl_icc_icc) FAST (movl_icc_icc) },
  { TYPE (INSN_MOVL_IMM_ICC_ICC), IDX (INSN_MOVL_IMM_ICC_ICC), FULL (movl_imm_icc_icc) FAST (movl_imm_icc_icc) },
  { TYPE (INSN_MOVL_XCC_XCC), IDX (INSN_MOVL_XCC_XCC), FULL (movl_xcc_xcc) FAST (movl_xcc_xcc) },
  { TYPE (INSN_MOVL_IMM_XCC_XCC), IDX (INSN_MOVL_IMM_XCC_XCC), FULL (movl_imm_xcc_xcc) FAST (movl_imm_xcc_xcc) },
  { TYPE (INSN_MOVGU_ICC_ICC), IDX (INSN_MOVGU_ICC_ICC), FULL (movgu_icc_icc) FAST (movgu_icc_icc) },
  { TYPE (INSN_MOVGU_IMM_ICC_ICC), IDX (INSN_MOVGU_IMM_ICC_ICC), FULL (movgu_imm_icc_icc) FAST (movgu_imm_icc_icc) },
  { TYPE (INSN_MOVGU_XCC_XCC), IDX (INSN_MOVGU_XCC_XCC), FULL (movgu_xcc_xcc) FAST (movgu_xcc_xcc) },
  { TYPE (INSN_MOVGU_IMM_XCC_XCC), IDX (INSN_MOVGU_IMM_XCC_XCC), FULL (movgu_imm_xcc_xcc) FAST (movgu_imm_xcc_xcc) },
  { TYPE (INSN_MOVLEU_ICC_ICC), IDX (INSN_MOVLEU_ICC_ICC), FULL (movleu_icc_icc) FAST (movleu_icc_icc) },
  { TYPE (INSN_MOVLEU_IMM_ICC_ICC), IDX (INSN_MOVLEU_IMM_ICC_ICC), FULL (movleu_imm_icc_icc) FAST (movleu_imm_icc_icc) },
  { TYPE (INSN_MOVLEU_XCC_XCC), IDX (INSN_MOVLEU_XCC_XCC), FULL (movleu_xcc_xcc) FAST (movleu_xcc_xcc) },
  { TYPE (INSN_MOVLEU_IMM_XCC_XCC), IDX (INSN_MOVLEU_IMM_XCC_XCC), FULL (movleu_imm_xcc_xcc) FAST (movleu_imm_xcc_xcc) },
  { TYPE (INSN_MOVCC_ICC_ICC), IDX (INSN_MOVCC_ICC_ICC), FULL (movcc_icc_icc) FAST (movcc_icc_icc) },
  { TYPE (INSN_MOVCC_IMM_ICC_ICC), IDX (INSN_MOVCC_IMM_ICC_ICC), FULL (movcc_imm_icc_icc) FAST (movcc_imm_icc_icc) },
  { TYPE (INSN_MOVCC_XCC_XCC), IDX (INSN_MOVCC_XCC_XCC), FULL (movcc_xcc_xcc) FAST (movcc_xcc_xcc) },
  { TYPE (INSN_MOVCC_IMM_XCC_XCC), IDX (INSN_MOVCC_IMM_XCC_XCC), FULL (movcc_imm_xcc_xcc) FAST (movcc_imm_xcc_xcc) },
  { TYPE (INSN_MOVCS_ICC_ICC), IDX (INSN_MOVCS_ICC_ICC), FULL (movcs_icc_icc) FAST (movcs_icc_icc) },
  { TYPE (INSN_MOVCS_IMM_ICC_ICC), IDX (INSN_MOVCS_IMM_ICC_ICC), FULL (movcs_imm_icc_icc) FAST (movcs_imm_icc_icc) },
  { TYPE (INSN_MOVCS_XCC_XCC), IDX (INSN_MOVCS_XCC_XCC), FULL (movcs_xcc_xcc) FAST (movcs_xcc_xcc) },
  { TYPE (INSN_MOVCS_IMM_XCC_XCC), IDX (INSN_MOVCS_IMM_XCC_XCC), FULL (movcs_imm_xcc_xcc) FAST (movcs_imm_xcc_xcc) },
  { TYPE (INSN_MOVPOS_ICC_ICC), IDX (INSN_MOVPOS_ICC_ICC), FULL (movpos_icc_icc) FAST (movpos_icc_icc) },
  { TYPE (INSN_MOVPOS_IMM_ICC_ICC), IDX (INSN_MOVPOS_IMM_ICC_ICC), FULL (movpos_imm_icc_icc) FAST (movpos_imm_icc_icc) },
  { TYPE (INSN_MOVPOS_XCC_XCC), IDX (INSN_MOVPOS_XCC_XCC), FULL (movpos_xcc_xcc) FAST (movpos_xcc_xcc) },
  { TYPE (INSN_MOVPOS_IMM_XCC_XCC), IDX (INSN_MOVPOS_IMM_XCC_XCC), FULL (movpos_imm_xcc_xcc) FAST (movpos_imm_xcc_xcc) },
  { TYPE (INSN_MOVNEG_ICC_ICC), IDX (INSN_MOVNEG_ICC_ICC), FULL (movneg_icc_icc) FAST (movneg_icc_icc) },
  { TYPE (INSN_MOVNEG_IMM_ICC_ICC), IDX (INSN_MOVNEG_IMM_ICC_ICC), FULL (movneg_imm_icc_icc) FAST (movneg_imm_icc_icc) },
  { TYPE (INSN_MOVNEG_XCC_XCC), IDX (INSN_MOVNEG_XCC_XCC), FULL (movneg_xcc_xcc) FAST (movneg_xcc_xcc) },
  { TYPE (INSN_MOVNEG_IMM_XCC_XCC), IDX (INSN_MOVNEG_IMM_XCC_XCC), FULL (movneg_imm_xcc_xcc) FAST (movneg_imm_xcc_xcc) },
  { TYPE (INSN_MOVVC_ICC_ICC), IDX (INSN_MOVVC_ICC_ICC), FULL (movvc_icc_icc) FAST (movvc_icc_icc) },
  { TYPE (INSN_MOVVC_IMM_ICC_ICC), IDX (INSN_MOVVC_IMM_ICC_ICC), FULL (movvc_imm_icc_icc) FAST (movvc_imm_icc_icc) },
  { TYPE (INSN_MOVVC_XCC_XCC), IDX (INSN_MOVVC_XCC_XCC), FULL (movvc_xcc_xcc) FAST (movvc_xcc_xcc) },
  { TYPE (INSN_MOVVC_IMM_XCC_XCC), IDX (INSN_MOVVC_IMM_XCC_XCC), FULL (movvc_imm_xcc_xcc) FAST (movvc_imm_xcc_xcc) },
  { TYPE (INSN_MOVVS_ICC_ICC), IDX (INSN_MOVVS_ICC_ICC), FULL (movvs_icc_icc) FAST (movvs_icc_icc) },
  { TYPE (INSN_MOVVS_IMM_ICC_ICC), IDX (INSN_MOVVS_IMM_ICC_ICC), FULL (movvs_imm_icc_icc) FAST (movvs_imm_icc_icc) },
  { TYPE (INSN_MOVVS_XCC_XCC), IDX (INSN_MOVVS_XCC_XCC), FULL (movvs_xcc_xcc) FAST (movvs_xcc_xcc) },
  { TYPE (INSN_MOVVS_IMM_XCC_XCC), IDX (INSN_MOVVS_IMM_XCC_XCC), FULL (movvs_imm_xcc_xcc) FAST (movvs_imm_xcc_xcc) },
  { TYPE (INSN_LDSB_REG_REG), IDX (INSN_LDSB_REG_REG), FULL (ldsb_reg_reg) FAST (ldsb_reg_reg) },
  { TYPE (INSN_LDSB_REG_IMM), IDX (INSN_LDSB_REG_IMM), FULL (ldsb_reg_imm) FAST (ldsb_reg_imm) },
  { TYPE (INSN_LDSB_REG_REG_ASI), IDX (INSN_LDSB_REG_REG_ASI), FULL (ldsb_reg_reg_asi) FAST (ldsb_reg_reg_asi) },
  { TYPE (INSN_LDUB_REG_REG), IDX (INSN_LDUB_REG_REG), FULL (ldub_reg_reg) FAST (ldub_reg_reg) },
  { TYPE (INSN_LDUB_REG_IMM), IDX (INSN_LDUB_REG_IMM), FULL (ldub_reg_imm) FAST (ldub_reg_imm) },
  { TYPE (INSN_LDUB_REG_REG_ASI), IDX (INSN_LDUB_REG_REG_ASI), FULL (ldub_reg_reg_asi) FAST (ldub_reg_reg_asi) },
  { TYPE (INSN_LDSH_REG_REG), IDX (INSN_LDSH_REG_REG), FULL (ldsh_reg_reg) FAST (ldsh_reg_reg) },
  { TYPE (INSN_LDSH_REG_IMM), IDX (INSN_LDSH_REG_IMM), FULL (ldsh_reg_imm) FAST (ldsh_reg_imm) },
  { TYPE (INSN_LDSH_REG_REG_ASI), IDX (INSN_LDSH_REG_REG_ASI), FULL (ldsh_reg_reg_asi) FAST (ldsh_reg_reg_asi) },
  { TYPE (INSN_LDUH_REG_REG), IDX (INSN_LDUH_REG_REG), FULL (lduh_reg_reg) FAST (lduh_reg_reg) },
  { TYPE (INSN_LDUH_REG_IMM), IDX (INSN_LDUH_REG_IMM), FULL (lduh_reg_imm) FAST (lduh_reg_imm) },
  { TYPE (INSN_LDUH_REG_REG_ASI), IDX (INSN_LDUH_REG_REG_ASI), FULL (lduh_reg_reg_asi) FAST (lduh_reg_reg_asi) },
  { TYPE (INSN_LDSW_REG_REG), IDX (INSN_LDSW_REG_REG), FULL (ldsw_reg_reg) FAST (ldsw_reg_reg) },
  { TYPE (INSN_LDSW_REG_IMM), IDX (INSN_LDSW_REG_IMM), FULL (ldsw_reg_imm) FAST (ldsw_reg_imm) },
  { TYPE (INSN_LDSW_REG_REG_ASI), IDX (INSN_LDSW_REG_REG_ASI), FULL (ldsw_reg_reg_asi) FAST (ldsw_reg_reg_asi) },
  { TYPE (INSN_LDUW_REG_REG), IDX (INSN_LDUW_REG_REG), FULL (lduw_reg_reg) FAST (lduw_reg_reg) },
  { TYPE (INSN_LDUW_REG_IMM), IDX (INSN_LDUW_REG_IMM), FULL (lduw_reg_imm) FAST (lduw_reg_imm) },
  { TYPE (INSN_LDUW_REG_REG_ASI), IDX (INSN_LDUW_REG_REG_ASI), FULL (lduw_reg_reg_asi) FAST (lduw_reg_reg_asi) },
  { TYPE (INSN_LDX_REG_REG), IDX (INSN_LDX_REG_REG), FULL (ldx_reg_reg) FAST (ldx_reg_reg) },
  { TYPE (INSN_LDX_REG_IMM), IDX (INSN_LDX_REG_IMM), FULL (ldx_reg_imm) FAST (ldx_reg_imm) },
  { TYPE (INSN_LDX_REG_REG_ASI), IDX (INSN_LDX_REG_REG_ASI), FULL (ldx_reg_reg_asi) FAST (ldx_reg_reg_asi) },
  { TYPE (INSN_LDD_REG_REG), IDX (INSN_LDD_REG_REG), FULL (ldd_reg_reg) FAST (ldd_reg_reg) },
  { TYPE (INSN_LDD_REG_IMM), IDX (INSN_LDD_REG_IMM), FULL (ldd_reg_imm) FAST (ldd_reg_imm) },
  { TYPE (INSN_LDD_REG_REG_ASI), IDX (INSN_LDD_REG_REG_ASI), FULL (ldd_reg_reg_asi) FAST (ldd_reg_reg_asi) },
  { TYPE (INSN_STB_REG_REG), IDX (INSN_STB_REG_REG), FULL (stb_reg_reg) FAST (stb_reg_reg) },
  { TYPE (INSN_STB_REG_IMM), IDX (INSN_STB_REG_IMM), FULL (stb_reg_imm) FAST (stb_reg_imm) },
  { TYPE (INSN_STB_REG_REG_ASI), IDX (INSN_STB_REG_REG_ASI), FULL (stb_reg_reg_asi) FAST (stb_reg_reg_asi) },
  { TYPE (INSN_STH_REG_REG), IDX (INSN_STH_REG_REG), FULL (sth_reg_reg) FAST (sth_reg_reg) },
  { TYPE (INSN_STH_REG_IMM), IDX (INSN_STH_REG_IMM), FULL (sth_reg_imm) FAST (sth_reg_imm) },
  { TYPE (INSN_STH_REG_REG_ASI), IDX (INSN_STH_REG_REG_ASI), FULL (sth_reg_reg_asi) FAST (sth_reg_reg_asi) },
  { TYPE (INSN_ST_REG_REG), IDX (INSN_ST_REG_REG), FULL (st_reg_reg) FAST (st_reg_reg) },
  { TYPE (INSN_ST_REG_IMM), IDX (INSN_ST_REG_IMM), FULL (st_reg_imm) FAST (st_reg_imm) },
  { TYPE (INSN_ST_REG_REG_ASI), IDX (INSN_ST_REG_REG_ASI), FULL (st_reg_reg_asi) FAST (st_reg_reg_asi) },
  { TYPE (INSN_STX_REG_REG), IDX (INSN_STX_REG_REG), FULL (stx_reg_reg) FAST (stx_reg_reg) },
  { TYPE (INSN_STX_REG_IMM), IDX (INSN_STX_REG_IMM), FULL (stx_reg_imm) FAST (stx_reg_imm) },
  { TYPE (INSN_STX_REG_REG_ASI), IDX (INSN_STX_REG_REG_ASI), FULL (stx_reg_reg_asi) FAST (stx_reg_reg_asi) },
  { TYPE (INSN_STD_REG_REG), IDX (INSN_STD_REG_REG), FULL (std_reg_reg) FAST (std_reg_reg) },
  { TYPE (INSN_STD_REG_IMM), IDX (INSN_STD_REG_IMM), FULL (std_reg_imm) FAST (std_reg_imm) },
  { TYPE (INSN_STD_REG_REG_ASI), IDX (INSN_STD_REG_REG_ASI), FULL (std_reg_reg_asi) FAST (std_reg_reg_asi) },
  { TYPE (INSN_FP_LD_REG_REG), IDX (INSN_FP_LD_REG_REG), FULL (fp_ld_reg_reg) FAST (fp_ld_reg_reg) },
  { TYPE (INSN_FP_LD_REG_IMM), IDX (INSN_FP_LD_REG_IMM), FULL (fp_ld_reg_imm) FAST (fp_ld_reg_imm) },
  { TYPE (INSN_FP_LD_REG_REG_ASI), IDX (INSN_FP_LD_REG_REG_ASI), FULL (fp_ld_reg_reg_asi) FAST (fp_ld_reg_reg_asi) },
  { TYPE (INSN_SETHI), IDX (INSN_SETHI), FULL (sethi) FAST (sethi) },
  { TYPE (INSN_ADD), IDX (INSN_ADD), FULL (add) FAST (add) },
  { TYPE (INSN_ADD_IMM), IDX (INSN_ADD_IMM), FULL (add_imm) FAST (add_imm) },
  { TYPE (INSN_SUB), IDX (INSN_SUB), FULL (sub) FAST (sub) },
  { TYPE (INSN_SUB_IMM), IDX (INSN_SUB_IMM), FULL (sub_imm) FAST (sub_imm) },
  { TYPE (INSN_ADDCC), IDX (INSN_ADDCC), FULL (addcc) FAST (addcc) },
  { TYPE (INSN_ADDCC_IMM), IDX (INSN_ADDCC_IMM), FULL (addcc_imm) FAST (addcc_imm) },
  { TYPE (INSN_SUBCC), IDX (INSN_SUBCC), FULL (subcc) FAST (subcc) },
  { TYPE (INSN_SUBCC_IMM), IDX (INSN_SUBCC_IMM), FULL (subcc_imm) FAST (subcc_imm) },
  { TYPE (INSN_ADDC), IDX (INSN_ADDC), FULL (addc) FAST (addc) },
  { TYPE (INSN_ADDC_IMM), IDX (INSN_ADDC_IMM), FULL (addc_imm) FAST (addc_imm) },
  { TYPE (INSN_SUBC), IDX (INSN_SUBC), FULL (subc) FAST (subc) },
  { TYPE (INSN_SUBC_IMM), IDX (INSN_SUBC_IMM), FULL (subc_imm) FAST (subc_imm) },
  { TYPE (INSN_ADDCCC), IDX (INSN_ADDCCC), FULL (addccc) FAST (addccc) },
  { TYPE (INSN_ADDCCC_IMM), IDX (INSN_ADDCCC_IMM), FULL (addccc_imm) FAST (addccc_imm) },
  { TYPE (INSN_SUBCCC), IDX (INSN_SUBCCC), FULL (subccc) FAST (subccc) },
  { TYPE (INSN_SUBCCC_IMM), IDX (INSN_SUBCCC_IMM), FULL (subccc_imm) FAST (subccc_imm) },
  { TYPE (INSN_AND), IDX (INSN_AND), FULL (and) FAST (and) },
  { TYPE (INSN_AND_IMM), IDX (INSN_AND_IMM), FULL (and_imm) FAST (and_imm) },
  { TYPE (INSN_ANDCC), IDX (INSN_ANDCC), FULL (andcc) FAST (andcc) },
  { TYPE (INSN_ANDCC_IMM), IDX (INSN_ANDCC_IMM), FULL (andcc_imm) FAST (andcc_imm) },
  { TYPE (INSN_OR), IDX (INSN_OR), FULL (or) FAST (or) },
  { TYPE (INSN_OR_IMM), IDX (INSN_OR_IMM), FULL (or_imm) FAST (or_imm) },
  { TYPE (INSN_ORCC), IDX (INSN_ORCC), FULL (orcc) FAST (orcc) },
  { TYPE (INSN_ORCC_IMM), IDX (INSN_ORCC_IMM), FULL (orcc_imm) FAST (orcc_imm) },
  { TYPE (INSN_XOR), IDX (INSN_XOR), FULL (xor) FAST (xor) },
  { TYPE (INSN_XOR_IMM), IDX (INSN_XOR_IMM), FULL (xor_imm) FAST (xor_imm) },
  { TYPE (INSN_XORCC), IDX (INSN_XORCC), FULL (xorcc) FAST (xorcc) },
  { TYPE (INSN_XORCC_IMM), IDX (INSN_XORCC_IMM), FULL (xorcc_imm) FAST (xorcc_imm) },
  { TYPE (INSN_ANDN), IDX (INSN_ANDN), FULL (andn) FAST (andn) },
  { TYPE (INSN_ANDN_IMM), IDX (INSN_ANDN_IMM), FULL (andn_imm) FAST (andn_imm) },
  { TYPE (INSN_ANDNCC), IDX (INSN_ANDNCC), FULL (andncc) FAST (andncc) },
  { TYPE (INSN_ANDNCC_IMM), IDX (INSN_ANDNCC_IMM), FULL (andncc_imm) FAST (andncc_imm) },
  { TYPE (INSN_ORN), IDX (INSN_ORN), FULL (orn) FAST (orn) },
  { TYPE (INSN_ORN_IMM), IDX (INSN_ORN_IMM), FULL (orn_imm) FAST (orn_imm) },
  { TYPE (INSN_ORNCC), IDX (INSN_ORNCC), FULL (orncc) FAST (orncc) },
  { TYPE (INSN_ORNCC_IMM), IDX (INSN_ORNCC_IMM), FULL (orncc_imm) FAST (orncc_imm) },
  { TYPE (INSN_XNOR), IDX (INSN_XNOR), FULL (xnor) FAST (xnor) },
  { TYPE (INSN_XNOR_IMM), IDX (INSN_XNOR_IMM), FULL (xnor_imm) FAST (xnor_imm) },
  { TYPE (INSN_XNORCC), IDX (INSN_XNORCC), FULL (xnorcc) FAST (xnorcc) },
  { TYPE (INSN_XNORCC_IMM), IDX (INSN_XNORCC_IMM), FULL (xnorcc_imm) FAST (xnorcc_imm) },
  { TYPE (INSN_SLL), IDX (INSN_SLL), FULL (sll) FAST (sll) },
  { TYPE (INSN_SLL_IMM), IDX (INSN_SLL_IMM), FULL (sll_imm) FAST (sll_imm) },
  { TYPE (INSN_SRL), IDX (INSN_SRL), FULL (srl) FAST (srl) },
  { TYPE (INSN_SRL_IMM), IDX (INSN_SRL_IMM), FULL (srl_imm) FAST (srl_imm) },
  { TYPE (INSN_SRA), IDX (INSN_SRA), FULL (sra) FAST (sra) },
  { TYPE (INSN_SRA_IMM), IDX (INSN_SRA_IMM), FULL (sra_imm) FAST (sra_imm) },
  { TYPE (INSN_SMUL), IDX (INSN_SMUL), FULL (smul) FAST (smul) },
  { TYPE (INSN_SMUL_IMM), IDX (INSN_SMUL_IMM), FULL (smul_imm) FAST (smul_imm) },
  { TYPE (INSN_SMUL_CC), IDX (INSN_SMUL_CC), FULL (smul_cc) FAST (smul_cc) },
  { TYPE (INSN_SMUL_CC_IMM), IDX (INSN_SMUL_CC_IMM), FULL (smul_cc_imm) FAST (smul_cc_imm) },
  { TYPE (INSN_UMUL), IDX (INSN_UMUL), FULL (umul) FAST (umul) },
  { TYPE (INSN_UMUL_IMM), IDX (INSN_UMUL_IMM), FULL (umul_imm) FAST (umul_imm) },
  { TYPE (INSN_UMUL_CC), IDX (INSN_UMUL_CC), FULL (umul_cc) FAST (umul_cc) },
  { TYPE (INSN_UMUL_CC_IMM), IDX (INSN_UMUL_CC_IMM), FULL (umul_cc_imm) FAST (umul_cc_imm) },
  { TYPE (INSN_MULSCC), IDX (INSN_MULSCC), FULL (mulscc) FAST (mulscc) },
  { TYPE (INSN_SAVE), IDX (INSN_SAVE), FULL (save) FAST (save) },
  { TYPE (INSN_SAVE_IMM), IDX (INSN_SAVE_IMM), FULL (save_imm) FAST (save_imm) },
  { TYPE (INSN_RESTORE), IDX (INSN_RESTORE), FULL (restore) FAST (restore) },
  { TYPE (INSN_RESTORE_IMM), IDX (INSN_RESTORE_IMM), FULL (restore_imm) FAST (restore_imm) },
  { TYPE (INSN_RETT), IDX (INSN_RETT), FULL (rett) FAST (rett) },
  { TYPE (INSN_RETT_IMM), IDX (INSN_RETT_IMM), FULL (rett_imm) FAST (rett_imm) },
  { TYPE (INSN_UNIMP), IDX (INSN_UNIMP), FULL (unimp) FAST (unimp) },
  { TYPE (INSN_CALL), IDX (INSN_CALL), FULL (call) FAST (call) },
  { TYPE (INSN_JMPL), IDX (INSN_JMPL), FULL (jmpl) FAST (jmpl) },
  { TYPE (INSN_JMPL_IMM), IDX (INSN_JMPL_IMM), FULL (jmpl_imm) FAST (jmpl_imm) },
  { TYPE (INSN_BA), IDX (INSN_BA), FULL (ba) FAST (ba) },
  { TYPE (INSN_TA), IDX (INSN_TA), FULL (ta) FAST (ta) },
  { TYPE (INSN_TA_IMM), IDX (INSN_TA_IMM), FULL (ta_imm) FAST (ta_imm) },
  { TYPE (INSN_BN), IDX (INSN_BN), FULL (bn) FAST (bn) },
  { TYPE (INSN_TN), IDX (INSN_TN), FULL (tn) FAST (tn) },
  { TYPE (INSN_TN_IMM), IDX (INSN_TN_IMM), FULL (tn_imm) FAST (tn_imm) },
  { TYPE (INSN_BNE), IDX (INSN_BNE), FULL (bne) FAST (bne) },
  { TYPE (INSN_TNE), IDX (INSN_TNE), FULL (tne) FAST (tne) },
  { TYPE (INSN_TNE_IMM), IDX (INSN_TNE_IMM), FULL (tne_imm) FAST (tne_imm) },
  { TYPE (INSN_BE), IDX (INSN_BE), FULL (be) FAST (be) },
  { TYPE (INSN_TE), IDX (INSN_TE), FULL (te) FAST (te) },
  { TYPE (INSN_TE_IMM), IDX (INSN_TE_IMM), FULL (te_imm) FAST (te_imm) },
  { TYPE (INSN_BG), IDX (INSN_BG), FULL (bg) FAST (bg) },
  { TYPE (INSN_TG), IDX (INSN_TG), FULL (tg) FAST (tg) },
  { TYPE (INSN_TG_IMM), IDX (INSN_TG_IMM), FULL (tg_imm) FAST (tg_imm) },
  { TYPE (INSN_BLE), IDX (INSN_BLE), FULL (ble) FAST (ble) },
  { TYPE (INSN_TLE), IDX (INSN_TLE), FULL (tle) FAST (tle) },
  { TYPE (INSN_TLE_IMM), IDX (INSN_TLE_IMM), FULL (tle_imm) FAST (tle_imm) },
  { TYPE (INSN_BGE), IDX (INSN_BGE), FULL (bge) FAST (bge) },
  { TYPE (INSN_TGE), IDX (INSN_TGE), FULL (tge) FAST (tge) },
  { TYPE (INSN_TGE_IMM), IDX (INSN_TGE_IMM), FULL (tge_imm) FAST (tge_imm) },
  { TYPE (INSN_BL), IDX (INSN_BL), FULL (bl) FAST (bl) },
  { TYPE (INSN_TL), IDX (INSN_TL), FULL (tl) FAST (tl) },
  { TYPE (INSN_TL_IMM), IDX (INSN_TL_IMM), FULL (tl_imm) FAST (tl_imm) },
  { TYPE (INSN_BGU), IDX (INSN_BGU), FULL (bgu) FAST (bgu) },
  { TYPE (INSN_TGU), IDX (INSN_TGU), FULL (tgu) FAST (tgu) },
  { TYPE (INSN_TGU_IMM), IDX (INSN_TGU_IMM), FULL (tgu_imm) FAST (tgu_imm) },
  { TYPE (INSN_BLEU), IDX (INSN_BLEU), FULL (bleu) FAST (bleu) },
  { TYPE (INSN_TLEU), IDX (INSN_TLEU), FULL (tleu) FAST (tleu) },
  { TYPE (INSN_TLEU_IMM), IDX (INSN_TLEU_IMM), FULL (tleu_imm) FAST (tleu_imm) },
  { TYPE (INSN_BCC), IDX (INSN_BCC), FULL (bcc) FAST (bcc) },
  { TYPE (INSN_TCC), IDX (INSN_TCC), FULL (tcc) FAST (tcc) },
  { TYPE (INSN_TCC_IMM), IDX (INSN_TCC_IMM), FULL (tcc_imm) FAST (tcc_imm) },
  { TYPE (INSN_BCS), IDX (INSN_BCS), FULL (bcs) FAST (bcs) },
  { TYPE (INSN_TCS), IDX (INSN_TCS), FULL (tcs) FAST (tcs) },
  { TYPE (INSN_TCS_IMM), IDX (INSN_TCS_IMM), FULL (tcs_imm) FAST (tcs_imm) },
  { TYPE (INSN_BPOS), IDX (INSN_BPOS), FULL (bpos) FAST (bpos) },
  { TYPE (INSN_TPOS), IDX (INSN_TPOS), FULL (tpos) FAST (tpos) },
  { TYPE (INSN_TPOS_IMM), IDX (INSN_TPOS_IMM), FULL (tpos_imm) FAST (tpos_imm) },
  { TYPE (INSN_BNEG), IDX (INSN_BNEG), FULL (bneg) FAST (bneg) },
  { TYPE (INSN_TNEG), IDX (INSN_TNEG), FULL (tneg) FAST (tneg) },
  { TYPE (INSN_TNEG_IMM), IDX (INSN_TNEG_IMM), FULL (tneg_imm) FAST (tneg_imm) },
  { TYPE (INSN_BVC), IDX (INSN_BVC), FULL (bvc) FAST (bvc) },
  { TYPE (INSN_TVC), IDX (INSN_TVC), FULL (tvc) FAST (tvc) },
  { TYPE (INSN_TVC_IMM), IDX (INSN_TVC_IMM), FULL (tvc_imm) FAST (tvc_imm) },
  { TYPE (INSN_BVS), IDX (INSN_BVS), FULL (bvs) FAST (bvs) },
  { TYPE (INSN_TVS), IDX (INSN_TVS), FULL (tvs) FAST (tvs) },
  { TYPE (INSN_TVS_IMM), IDX (INSN_TVS_IMM), FULL (tvs_imm) FAST (tvs_imm) },
  { TYPE (INSN_LDSTUB_REG_REG), IDX (INSN_LDSTUB_REG_REG), FULL (ldstub_reg_reg) FAST (ldstub_reg_reg) },
  { TYPE (INSN_LDSTUB_REG_IMM), IDX (INSN_LDSTUB_REG_IMM), FULL (ldstub_reg_imm) FAST (ldstub_reg_imm) },
  { TYPE (INSN_LDSTUB_REG_REG_ASI), IDX (INSN_LDSTUB_REG_REG_ASI), FULL (ldstub_reg_reg_asi) FAST (ldstub_reg_reg_asi) },
  { TYPE (INSN_SWAP_REG_REG), IDX (INSN_SWAP_REG_REG), FULL (swap_reg_reg) FAST (swap_reg_reg) },
  { TYPE (INSN_SWAP_REG_IMM), IDX (INSN_SWAP_REG_IMM), FULL (swap_reg_imm) FAST (swap_reg_imm) },
  { TYPE (INSN_SWAP_REG_REG_ASI), IDX (INSN_SWAP_REG_REG_ASI), FULL (swap_reg_reg_asi) FAST (swap_reg_reg_asi) },
};

static const struct insn_sem sparc64_insn_sem_invalid =
{
  VIRTUAL_INSN_X_INVALID, IDX (INSN_X_INVALID), FULL (x_invalid) FAST (x_invalid)
};

#undef IDX
#undef TYPE

/* Initialize an IDESC from the compile-time computable parts.  */

static INLINE void
init_idesc (SIM_CPU *cpu, IDESC *id, const struct insn_sem *t)
{
  const CGEN_INSN *insn_table = CGEN_CPU_INSN_TABLE (CPU_CPU_DESC (cpu))->init_entries;

  id->num = t->index;
  if ((int) t->type <= 0)
    id->idata = & cgen_virtual_insn_table[- (int) t->type];
  else
    id->idata = & insn_table[t->type];
  id->attrs = CGEN_INSN_ATTRS (id->idata);
  /* Oh my god, a magic number.  */
  id->length = CGEN_INSN_BITSIZE (id->idata) / 8;
#if ! WITH_SEM_SWITCH_FULL
  id->sem_full = t->sem_full;
#endif
#if WITH_FAST && ! WITH_SEM_SWITCH_FAST
  id->sem_fast = t->sem_fast;
#endif
#if WITH_PROFILE_MODEL_P
  id->timing = & MODEL_TIMING (CPU_MODEL (cpu)) [t->index];
  {
    SIM_DESC sd = CPU_STATE (cpu);
    SIM_ASSERT (t->index == id->timing->num);
  }
#endif
}

/* Initialize the instruction descriptor table.  */

void
sparc64_init_idesc_table (SIM_CPU *cpu)
{
  IDESC *id,*tabend;
  const struct insn_sem *t,*tend;
  int tabsize = SPARC64_INSN_MAX;
  IDESC *table = sparc64_insn_data;

  memset (table, 0, tabsize * sizeof (IDESC));

  /* First set all entries to the `invalid insn'.  */
  t = & sparc64_insn_sem_invalid;
  for (id = table, tabend = table + tabsize; id < tabend; ++id)
    init_idesc (cpu, id, t);

  /* Now fill in the values for the chosen cpu.  */
  for (t = sparc64_insn_sem, tend = t + sizeof (sparc64_insn_sem) / sizeof (*t);
       t != tend; ++t)
    {
      init_idesc (cpu, & table[t->index], t);
    }

  /* Link the IDESC table into the cpu.  */
  CPU_IDESC (cpu) = table;
}

#define GOTO_EXTRACT(id) goto extract

/* The decoder needs a slightly different computed goto switch control.  */
#ifdef __GNUC__
#define DECODE_SWITCH(N, X) goto *labels_##N[X];
#else
#define DECODE_SWITCH(N, X) switch (X)
#endif

/* Given an instruction, return a pointer to its IDESC entry.  */

const IDESC *
sparc64_decode (SIM_CPU *current_cpu, IADDR pc,
              CGEN_INSN_INT base_insn, CGEN_INSN_INT entire_insn,
              ARGBUF *abuf)
{
  /* Result.  */
  const IDESC *idecode;

  {
#define I(insn) & sparc64_insn_data[CONCAT2 (SPARC64_,insn)]
    CGEN_INSN_INT insn = base_insn;
    static const IDESC *idecode_invalid = I (INSN_X_INVALID);

    {
#ifdef __GNUC__
      static const void *labels_0[256] = {
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && case_0_12, && case_0_13, && default_0, && default_0, 
        && case_0_16, && case_0_17, && case_0_18, && case_0_19, 
        && case_0_20, && case_0_21, && case_0_22, && case_0_23, 
        && case_0_24, && case_0_25, && case_0_26, && case_0_27, 
        && case_0_28, && case_0_29, && case_0_30, && case_0_31, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && case_0_128, && case_0_129, && case_0_130, && case_0_131, 
        && case_0_132, && case_0_133, && case_0_134, && case_0_135, 
        && case_0_136, && default_0, && case_0_138, && case_0_139, 
        && case_0_140, && default_0, && default_0, && default_0, 
        && case_0_144, && case_0_145, && case_0_146, && case_0_147, 
        && case_0_148, && case_0_149, && case_0_150, && case_0_151, 
        && case_0_152, && default_0, && case_0_154, && case_0_155, 
        && case_0_156, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && case_0_165, && case_0_166, && case_0_167, 
        && default_0, && default_0, && default_0, && default_0, 
        && case_0_172, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && case_0_184, && case_0_185, && case_0_186, && case_0_187, 
        && case_0_188, && case_0_189, && case_0_190, && default_0, 
        && case_0_192, && case_0_193, && case_0_194, && case_0_195, 
        && case_0_196, && case_0_197, && case_0_198, && case_0_199, 
        && case_0_200, && case_0_201, && case_0_202, && case_0_203, 
        && default_0, && case_0_205, && case_0_206, && case_0_207, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && case_0_224, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
        && default_0, && default_0, && default_0, && default_0, 
      };
#endif
      static const IDESC * insns[256] = {
        I (INSN_UNIMP), I (INSN_UNIMP), 
        I (INSN_UNIMP), I (INSN_UNIMP), 
        I (INSN_UNIMP), I (INSN_UNIMP), 
        I (INSN_UNIMP), I (INSN_UNIMP), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        0, 0, 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        0, 0, 
        0, 0, 
        0, 0, 
        0, 0, 
        0, 0, 
        0, 0, 
        0, 0, 
        0, 0, 
        I (INSN_SETHI), I (INSN_SETHI), 
        I (INSN_SETHI), I (INSN_SETHI), 
        I (INSN_SETHI), I (INSN_SETHI), 
        I (INSN_SETHI), I (INSN_SETHI), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        I (INSN_CALL), I (INSN_CALL), 
        0, 0, 
        0, 0, 
        0, 0, 
        0, 0, 
        0, I (INSN_X_INVALID), 
        0, 0, 
        0, I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        0, 0, 
        0, 0, 
        0, 0, 
        0, 0, 
        0, I (INSN_X_INVALID), 
        0, 0, 
        0, I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_MULSCC), 0, 
        0, 0, 
        I (INSN_MEMBAR), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_FLUSHW), 
        0, I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_IMPDEP1), I (INSN_IMPDEP2), 
        0, 0, 
        0, 0, 
        0, 0, 
        0, I (INSN_X_INVALID), 
        0, 0, 
        0, 0, 
        0, 0, 
        0, 0, 
        0, 0, 
        0, 0, 
        I (INSN_X_INVALID), 0, 
        0, 0, 
        I (INSN_LDUW_REG_REG_ASI), I (INSN_LDUB_REG_REG_ASI), 
        I (INSN_LDUH_REG_REG_ASI), I (INSN_LDD_REG_REG_ASI), 
        I (INSN_ST_REG_REG_ASI), I (INSN_STB_REG_REG_ASI), 
        I (INSN_STH_REG_REG_ASI), I (INSN_STD_REG_REG_ASI), 
        I (INSN_LDSW_REG_REG_ASI), I (INSN_LDSB_REG_REG_ASI), 
        I (INSN_LDSH_REG_REG_ASI), I (INSN_LDX_REG_REG_ASI), 
        I (INSN_X_INVALID), I (INSN_LDSTUB_REG_REG_ASI), 
        I (INSN_STX_REG_REG_ASI), I (INSN_SWAP_REG_REG_ASI), 
        0, I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_FP_LD_REG_REG_ASI), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
        I (INSN_X_INVALID), I (INSN_X_INVALID), 
      };
      unsigned int val;
      val = (((insn >> 24) & (3 << 6)) | ((insn >> 19) & (63 << 0)));
      DECODE_SWITCH (0, val)
        {
        CASE (0, 12) : /* fall through */
        CASE (0, 13) :
          {
            static const IDESC * insns[16] = {
              I (INSN_BPCC_BN), I (INSN_BPCC_BE), 
              I (INSN_BPCC_BLE), I (INSN_BPCC_BL), 
              I (INSN_BPCC_BLEU), I (INSN_BPCC_BCS), 
              I (INSN_BPCC_BNEG), I (INSN_BPCC_BVS), 
              I (INSN_BPCC_BA), I (INSN_BPCC_BNE), 
              I (INSN_BPCC_BG), I (INSN_BPCC_BGE), 
              I (INSN_BPCC_BGU), I (INSN_BPCC_BCC), 
              I (INSN_BPCC_BPOS), I (INSN_BPCC_BVC), 
            };
            unsigned int val = (((insn >> 25) & (15 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 16) : /* fall through */
        CASE (0, 17) : /* fall through */
        CASE (0, 18) : /* fall through */
        CASE (0, 19) : /* fall through */
        CASE (0, 20) : /* fall through */
        CASE (0, 21) : /* fall through */
        CASE (0, 22) : /* fall through */
        CASE (0, 23) :
          {
            static const IDESC * insns[16] = {
              I (INSN_BN), I (INSN_BE), 
              I (INSN_BLE), I (INSN_BL), 
              I (INSN_BLEU), I (INSN_BCS), 
              I (INSN_BNEG), I (INSN_BVS), 
              I (INSN_BA), I (INSN_BNE), 
              I (INSN_BG), I (INSN_BGE), 
              I (INSN_BGU), I (INSN_BCC), 
              I (INSN_BPOS), I (INSN_BVC), 
            };
            unsigned int val = (((insn >> 25) & (15 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 24) : /* fall through */
        CASE (0, 25) : /* fall through */
        CASE (0, 26) : /* fall through */
        CASE (0, 27) : /* fall through */
        CASE (0, 28) : /* fall through */
        CASE (0, 29) : /* fall through */
        CASE (0, 30) : /* fall through */
        CASE (0, 31) :
          {
            static const IDESC * insns[8] = {
              I (INSN_X_INVALID), I (INSN_BEQZ), 
              I (INSN_BLEZ), I (INSN_BLTZ), 
              I (INSN_X_INVALID), I (INSN_BNEZ), 
              I (INSN_BGTZ), I (INSN_BGEZ), 
            };
            unsigned int val = (((insn >> 25) & (7 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 128) :
          {
            static const IDESC * insns[2] = {
              I (INSN_ADD), I (INSN_ADD_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 129) :
          {
            static const IDESC * insns[2] = {
              I (INSN_AND), I (INSN_AND_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 130) :
          {
            static const IDESC * insns[2] = {
              I (INSN_OR), I (INSN_OR_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 131) :
          {
            static const IDESC * insns[2] = {
              I (INSN_XOR), I (INSN_XOR_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 132) :
          {
            static const IDESC * insns[2] = {
              I (INSN_SUB), I (INSN_SUB_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 133) :
          {
            static const IDESC * insns[2] = {
              I (INSN_ANDN), I (INSN_ANDN_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 134) :
          {
            static const IDESC * insns[2] = {
              I (INSN_ORN), I (INSN_ORN_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 135) :
          {
            static const IDESC * insns[2] = {
              I (INSN_XNOR), I (INSN_XNOR_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 136) :
          {
            static const IDESC * insns[2] = {
              I (INSN_ADDC), I (INSN_ADDC_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 138) :
          {
            static const IDESC * insns[2] = {
              I (INSN_UMUL), I (INSN_UMUL_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 139) :
          {
            static const IDESC * insns[2] = {
              I (INSN_SMUL), I (INSN_SMUL_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 140) :
          {
            static const IDESC * insns[2] = {
              I (INSN_SUBC), I (INSN_SUBC_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 144) :
          {
            static const IDESC * insns[2] = {
              I (INSN_ADDCC), I (INSN_ADDCC_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 145) :
          {
            static const IDESC * insns[2] = {
              I (INSN_ANDCC), I (INSN_ANDCC_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 146) :
          {
            static const IDESC * insns[2] = {
              I (INSN_ORCC), I (INSN_ORCC_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 147) :
          {
            static const IDESC * insns[2] = {
              I (INSN_XORCC), I (INSN_XORCC_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 148) :
          {
            static const IDESC * insns[2] = {
              I (INSN_SUBCC), I (INSN_SUBCC_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 149) :
          {
            static const IDESC * insns[2] = {
              I (INSN_ANDNCC), I (INSN_ANDNCC_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 150) :
          {
            static const IDESC * insns[2] = {
              I (INSN_ORNCC), I (INSN_ORNCC_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 151) :
          {
            static const IDESC * insns[2] = {
              I (INSN_XNORCC), I (INSN_XNORCC_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 152) :
          {
            static const IDESC * insns[2] = {
              I (INSN_ADDCCC), I (INSN_ADDCCC_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 154) :
          {
            static const IDESC * insns[2] = {
              I (INSN_UMUL_CC), I (INSN_UMUL_CC_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 155) :
          {
            static const IDESC * insns[2] = {
              I (INSN_SMUL_CC), I (INSN_SMUL_CC_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 156) :
          {
            static const IDESC * insns[2] = {
              I (INSN_SUBCCC), I (INSN_SUBCCC_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 165) :
          {
            static const IDESC * insns[2] = {
              I (INSN_SLL), I (INSN_SLL_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 166) :
          {
            static const IDESC * insns[2] = {
              I (INSN_SRL), I (INSN_SRL_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 167) :
          {
            static const IDESC * insns[2] = {
              I (INSN_SRA), I (INSN_SRA_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 172) :
          {
#ifdef __GNUC__
            static const void *labels_0_172[16] = {
              && case_0_172_0, && case_0_172_1, && case_0_172_2, && case_0_172_3, 
              && case_0_172_4, && case_0_172_5, && case_0_172_6, && case_0_172_7, 
              && case_0_172_8, && case_0_172_9, && case_0_172_10, && case_0_172_11, 
              && case_0_172_12, && case_0_172_13, && case_0_172_14, && case_0_172_15, 
            };
#endif
            unsigned int val;
            val = (((insn >> 25) & (15 << 0)));
            DECODE_SWITCH (0_172, val)
              {
              CASE (0_172, 0) :
                {
                  static const IDESC * insns[16] = {
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_MOVN_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVN_XCC_XCC), I (INSN_X_INVALID), 
                    I (INSN_MOVN_IMM_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVN_IMM_XCC_XCC), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 15) & (1 << 3)) | ((insn >> 11) & (7 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_172, 1) :
                {
                  static const IDESC * insns[16] = {
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_MOVE_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVE_XCC_XCC), I (INSN_X_INVALID), 
                    I (INSN_MOVE_IMM_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVE_IMM_XCC_XCC), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 15) & (1 << 3)) | ((insn >> 11) & (7 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_172, 2) :
                {
                  static const IDESC * insns[16] = {
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_MOVLE_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVLE_XCC_XCC), I (INSN_X_INVALID), 
                    I (INSN_MOVLE_IMM_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVLE_IMM_XCC_XCC), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 15) & (1 << 3)) | ((insn >> 11) & (7 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_172, 3) :
                {
                  static const IDESC * insns[16] = {
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_MOVL_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVL_XCC_XCC), I (INSN_X_INVALID), 
                    I (INSN_MOVL_IMM_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVL_IMM_XCC_XCC), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 15) & (1 << 3)) | ((insn >> 11) & (7 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_172, 4) :
                {
                  static const IDESC * insns[16] = {
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_MOVLEU_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVLEU_XCC_XCC), I (INSN_X_INVALID), 
                    I (INSN_MOVLEU_IMM_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVLEU_IMM_XCC_XCC), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 15) & (1 << 3)) | ((insn >> 11) & (7 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_172, 5) :
                {
                  static const IDESC * insns[16] = {
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_MOVCS_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVCS_XCC_XCC), I (INSN_X_INVALID), 
                    I (INSN_MOVCS_IMM_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVCS_IMM_XCC_XCC), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 15) & (1 << 3)) | ((insn >> 11) & (7 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_172, 6) :
                {
                  static const IDESC * insns[16] = {
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_MOVNEG_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVNEG_XCC_XCC), I (INSN_X_INVALID), 
                    I (INSN_MOVNEG_IMM_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVNEG_IMM_XCC_XCC), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 15) & (1 << 3)) | ((insn >> 11) & (7 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_172, 7) :
                {
                  static const IDESC * insns[16] = {
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_MOVVS_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVVS_XCC_XCC), I (INSN_X_INVALID), 
                    I (INSN_MOVVS_IMM_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVVS_IMM_XCC_XCC), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 15) & (1 << 3)) | ((insn >> 11) & (7 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_172, 8) :
                {
                  static const IDESC * insns[16] = {
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_MOVA_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVA_XCC_XCC), I (INSN_X_INVALID), 
                    I (INSN_MOVA_IMM_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVA_IMM_XCC_XCC), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 15) & (1 << 3)) | ((insn >> 11) & (7 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_172, 9) :
                {
                  static const IDESC * insns[16] = {
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_MOVNE_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVNE_XCC_XCC), I (INSN_X_INVALID), 
                    I (INSN_MOVNE_IMM_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVNE_IMM_XCC_XCC), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 15) & (1 << 3)) | ((insn >> 11) & (7 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_172, 10) :
                {
                  static const IDESC * insns[16] = {
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_MOVG_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVG_XCC_XCC), I (INSN_X_INVALID), 
                    I (INSN_MOVG_IMM_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVG_IMM_XCC_XCC), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 15) & (1 << 3)) | ((insn >> 11) & (7 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_172, 11) :
                {
                  static const IDESC * insns[16] = {
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_MOVGE_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVGE_XCC_XCC), I (INSN_X_INVALID), 
                    I (INSN_MOVGE_IMM_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVGE_IMM_XCC_XCC), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 15) & (1 << 3)) | ((insn >> 11) & (7 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_172, 12) :
                {
                  static const IDESC * insns[16] = {
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_MOVGU_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVGU_XCC_XCC), I (INSN_X_INVALID), 
                    I (INSN_MOVGU_IMM_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVGU_IMM_XCC_XCC), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 15) & (1 << 3)) | ((insn >> 11) & (7 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_172, 13) :
                {
                  static const IDESC * insns[16] = {
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_MOVCC_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVCC_XCC_XCC), I (INSN_X_INVALID), 
                    I (INSN_MOVCC_IMM_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVCC_IMM_XCC_XCC), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 15) & (1 << 3)) | ((insn >> 11) & (7 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_172, 14) :
                {
                  static const IDESC * insns[16] = {
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_MOVPOS_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVPOS_XCC_XCC), I (INSN_X_INVALID), 
                    I (INSN_MOVPOS_IMM_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVPOS_IMM_XCC_XCC), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 15) & (1 << 3)) | ((insn >> 11) & (7 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_172, 15) :
                {
                  static const IDESC * insns[16] = {
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                    I (INSN_MOVVC_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVVC_XCC_XCC), I (INSN_X_INVALID), 
                    I (INSN_MOVVC_IMM_ICC_ICC), I (INSN_X_INVALID), 
                    I (INSN_MOVVC_IMM_XCC_XCC), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 15) & (1 << 3)) | ((insn >> 11) & (7 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              DEFAULT (0_172) :
                idecode = idecode_invalid;
                GOTO_EXTRACT (idecode);
              }
            ENDSWITCH (0_172)
          }
        CASE (0, 184) :
          {
            static const IDESC * insns[2] = {
              I (INSN_JMPL), I (INSN_JMPL_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 185) :
          {
#ifdef __GNUC__
            static const void *labels_0_185[16] = {
              && case_0_185_0, && default_0_185, && default_0_185, && default_0_185, 
              && default_0_185, && default_0_185, && default_0_185, && default_0_185, 
              && default_0_185, && default_0_185, && default_0_185, && default_0_185, 
              && default_0_185, && default_0_185, && default_0_185, && default_0_185, 
            };
#endif
            static const IDESC * insns[16] = {
              0, I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
            };
            unsigned int val;
            val = (((insn >> 26) & (15 << 0)));
            DECODE_SWITCH (0_185, val)
              {
              CASE (0_185, 0) :
                {
                  static const IDESC * insns[4] = {
                    I (INSN_RETT), I (INSN_RETT_IMM), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 24) & (1 << 1)) | ((insn >> 13) & (1 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              DEFAULT (0_185) :
                idecode = insns[val];
                GOTO_EXTRACT (idecode);
              }
            ENDSWITCH (0_185)
          }
        CASE (0, 186) :
          {
#ifdef __GNUC__
            static const void *labels_0_186[16] = {
              && case_0_186_0, && case_0_186_1, && case_0_186_2, && case_0_186_3, 
              && case_0_186_4, && case_0_186_5, && case_0_186_6, && case_0_186_7, 
              && default_0_186, && default_0_186, && default_0_186, && default_0_186, 
              && default_0_186, && default_0_186, && default_0_186, && default_0_186, 
            };
#endif
            static const IDESC * insns[16] = {
              0, 0, 
              0, 0, 
              0, 0, 
              0, 0, 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
            };
            unsigned int val;
            val = (((insn >> 26) & (15 << 0)));
            DECODE_SWITCH (0_186, val)
              {
              CASE (0_186, 0) :
                {
                  static const IDESC * insns[4] = {
                    I (INSN_TN), I (INSN_TN_IMM), 
                    I (INSN_TE), I (INSN_TE_IMM), 
                  };
                  unsigned int val = (((insn >> 24) & (1 << 1)) | ((insn >> 13) & (1 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_186, 1) :
                {
                  static const IDESC * insns[4] = {
                    I (INSN_TLE), I (INSN_TLE_IMM), 
                    I (INSN_TL), I (INSN_TL_IMM), 
                  };
                  unsigned int val = (((insn >> 24) & (1 << 1)) | ((insn >> 13) & (1 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_186, 2) :
                {
                  static const IDESC * insns[4] = {
                    I (INSN_TLEU), I (INSN_TLEU_IMM), 
                    I (INSN_TCS), I (INSN_TCS_IMM), 
                  };
                  unsigned int val = (((insn >> 24) & (1 << 1)) | ((insn >> 13) & (1 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_186, 3) :
                {
                  static const IDESC * insns[4] = {
                    I (INSN_TNEG), I (INSN_TNEG_IMM), 
                    I (INSN_TVS), I (INSN_TVS_IMM), 
                  };
                  unsigned int val = (((insn >> 24) & (1 << 1)) | ((insn >> 13) & (1 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_186, 4) :
                {
                  static const IDESC * insns[4] = {
                    I (INSN_TA), I (INSN_TA_IMM), 
                    I (INSN_TNE), I (INSN_TNE_IMM), 
                  };
                  unsigned int val = (((insn >> 24) & (1 << 1)) | ((insn >> 13) & (1 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_186, 5) :
                {
                  static const IDESC * insns[4] = {
                    I (INSN_TG), I (INSN_TG_IMM), 
                    I (INSN_TGE), I (INSN_TGE_IMM), 
                  };
                  unsigned int val = (((insn >> 24) & (1 << 1)) | ((insn >> 13) & (1 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_186, 6) :
                {
                  static const IDESC * insns[4] = {
                    I (INSN_TGU), I (INSN_TGU_IMM), 
                    I (INSN_TCC), I (INSN_TCC_IMM), 
                  };
                  unsigned int val = (((insn >> 24) & (1 << 1)) | ((insn >> 13) & (1 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              CASE (0_186, 7) :
                {
                  static const IDESC * insns[4] = {
                    I (INSN_TPOS), I (INSN_TPOS_IMM), 
                    I (INSN_TVC), I (INSN_TVC_IMM), 
                  };
                  unsigned int val = (((insn >> 24) & (1 << 1)) | ((insn >> 13) & (1 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              DEFAULT (0_186) :
                idecode = insns[val];
                GOTO_EXTRACT (idecode);
              }
            ENDSWITCH (0_186)
          }
        CASE (0, 187) :
          {
#ifdef __GNUC__
            static const void *labels_0_187[16] = {
              && case_0_187_0, && default_0_187, && default_0_187, && default_0_187, 
              && default_0_187, && default_0_187, && default_0_187, && default_0_187, 
              && default_0_187, && default_0_187, && default_0_187, && default_0_187, 
              && default_0_187, && default_0_187, && default_0_187, && default_0_187, 
            };
#endif
            static const IDESC * insns[16] = {
              0, I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
            };
            unsigned int val;
            val = (((insn >> 26) & (15 << 0)));
            DECODE_SWITCH (0_187, val)
              {
              CASE (0_187, 0) :
                {
                  static const IDESC * insns[4] = {
                    I (INSN_FLUSH), I (INSN_FLUSH_IMM), 
                    I (INSN_X_INVALID), I (INSN_X_INVALID), 
                  };
                  unsigned int val = (((insn >> 24) & (1 << 1)) | ((insn >> 13) & (1 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              DEFAULT (0_187) :
                idecode = insns[val];
                GOTO_EXTRACT (idecode);
              }
            ENDSWITCH (0_187)
          }
        CASE (0, 188) :
          {
            static const IDESC * insns[2] = {
              I (INSN_SAVE), I (INSN_SAVE_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 189) :
          {
            static const IDESC * insns[2] = {
              I (INSN_RESTORE), I (INSN_RESTORE_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 190) :
          {
#ifdef __GNUC__
            static const void *labels_0_190[16] = {
              && case_0_190_0, && default_0_190, && default_0_190, && default_0_190, 
              && default_0_190, && default_0_190, && default_0_190, && default_0_190, 
              && default_0_190, && default_0_190, && default_0_190, && default_0_190, 
              && default_0_190, && default_0_190, && default_0_190, && default_0_190, 
            };
#endif
            static const IDESC * insns[16] = {
              0, I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
              I (INSN_X_INVALID), I (INSN_X_INVALID), 
            };
            unsigned int val;
            val = (((insn >> 26) & (15 << 0)));
            DECODE_SWITCH (0_190, val)
              {
              CASE (0_190, 0) :
                {
                  static const IDESC * insns[2] = {
                    I (INSN_DONE), I (INSN_RETRY), 
                  };
                  unsigned int val = (((insn >> 25) & (1 << 0)));
                  idecode = insns[val];
                  GOTO_EXTRACT (idecode);
                }
              DEFAULT (0_190) :
                idecode = insns[val];
                GOTO_EXTRACT (idecode);
              }
            ENDSWITCH (0_190)
          }
        CASE (0, 192) :
          {
            static const IDESC * insns[2] = {
              I (INSN_LDUW_REG_REG), I (INSN_LDUW_REG_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 193) :
          {
            static const IDESC * insns[2] = {
              I (INSN_LDUB_REG_REG), I (INSN_LDUB_REG_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 194) :
          {
            static const IDESC * insns[2] = {
              I (INSN_LDUH_REG_REG), I (INSN_LDUH_REG_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 195) :
          {
            static const IDESC * insns[2] = {
              I (INSN_LDD_REG_REG), I (INSN_LDD_REG_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 196) :
          {
            static const IDESC * insns[2] = {
              I (INSN_ST_REG_REG), I (INSN_ST_REG_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 197) :
          {
            static const IDESC * insns[2] = {
              I (INSN_STB_REG_REG), I (INSN_STB_REG_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 198) :
          {
            static const IDESC * insns[2] = {
              I (INSN_STH_REG_REG), I (INSN_STH_REG_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 199) :
          {
            static const IDESC * insns[2] = {
              I (INSN_STD_REG_REG), I (INSN_STD_REG_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 200) :
          {
            static const IDESC * insns[2] = {
              I (INSN_LDSW_REG_REG), I (INSN_LDSW_REG_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 201) :
          {
            static const IDESC * insns[2] = {
              I (INSN_LDSB_REG_REG), I (INSN_LDSB_REG_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 202) :
          {
            static const IDESC * insns[2] = {
              I (INSN_LDSH_REG_REG), I (INSN_LDSH_REG_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 203) :
          {
            static const IDESC * insns[2] = {
              I (INSN_LDX_REG_REG), I (INSN_LDX_REG_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 205) :
          {
            static const IDESC * insns[2] = {
              I (INSN_LDSTUB_REG_REG), I (INSN_LDSTUB_REG_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 206) :
          {
            static const IDESC * insns[2] = {
              I (INSN_STX_REG_REG), I (INSN_STX_REG_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 207) :
          {
            static const IDESC * insns[2] = {
              I (INSN_SWAP_REG_REG), I (INSN_SWAP_REG_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        CASE (0, 224) :
          {
            static const IDESC * insns[2] = {
              I (INSN_FP_LD_REG_REG), I (INSN_FP_LD_REG_IMM), 
            };
            unsigned int val = (((insn >> 13) & (1 << 0)));
            idecode = insns[val];
            GOTO_EXTRACT (idecode);
          }
        DEFAULT (0) :
          idecode = insns[val];
          GOTO_EXTRACT (idecode);
        }
      ENDSWITCH (0)
    }
#undef I
#undef E
  }

  /* Extraction is defered until the semantic code.  */

 extract:
  return idecode;
}
