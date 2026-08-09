/*
 * REFERENCE-ONLY GHIDRA PSEUDOCODE.
 * This is not the manufacturer's source and is not directly recompilable.
 * Types, names, control flow, volatile semantics, and timing may be wrong.
 */


/* ===== armcc_runtime_entry @ 0x28C0 ===== */

/* ARMCC reset-time runtime and scatter-loading entry reached after SystemInit. */

void __stdcall_softfp armcc_runtime_entry(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 *puVar2;
  int iVar3;
  
  armcc_scatterload_dispatcher();
  application_entry();
  iVar1 = DAT_000028fc;
  puVar2 = (undefined4 *)((int)&DAT_000028fc + DAT_000028fc);
  iVar3 = DAT_000028fc + 0x28fb;
  if (puVar2 == (undefined4 *)((int)&DAT_000028fc + DAT_00002900)) {
    application_entry();
  }
  UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x2908);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
    UNRECOVERED_JUMPTABLE = (code *)(iVar3 - (int)UNRECOVERED_JUMPTABLE);
  }
                    /* WARNING: Could not recover jumptable at 0x000028fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)
            (*puVar2,*(undefined4 *)((int)&DAT_00002900 + iVar1),*(undefined4 *)(iVar1 + 0x2904));
  return;
}



/* ===== armcc_scatterload_dispatcher @ 0x28C8 ===== */

/* ARMCC scatter-load dispatcher reached from the reset-time runtime entry. */

void __stdcall_softfp armcc_scatterload_dispatcher(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  undefined4 *puVar2;
  int iVar3;
  
  iVar1 = DAT_000028fc;
  puVar2 = (undefined4 *)((int)&DAT_000028fc + DAT_000028fc);
  iVar3 = DAT_000028fc + 0x28fb;
  if (puVar2 == (undefined4 *)((int)&DAT_000028fc + DAT_00002900)) {
    application_entry();
  }
  UNRECOVERED_JUMPTABLE = *(code **)(iVar1 + 0x2908);
  if (((uint)UNRECOVERED_JUMPTABLE & 1) != 0) {
    UNRECOVERED_JUMPTABLE = (code *)(iVar3 - (int)UNRECOVERED_JUMPTABLE);
  }
                    /* WARNING: Could not recover jumptable at 0x000028fa. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)
            (*puVar2,*(undefined4 *)((int)&DAT_00002900 + iVar1),*(undefined4 *)(iVar1 + 0x2904));
  return;
}



/* ===== FUN_00002920 @ 0x2920 ===== */

undefined8 __stdcall_softfp FUN_00002920(undefined4 param_1,undefined4 param_2)

{
  FUN_000029f4();
  return CONCAT44(param_2,param_1);
}



/* ===== FUN_00002928 @ 0x2928 ===== */

void __stdcall_softfp FUN_00002928(void)

{
  return;
}



/* ===== application_entry @ 0x292C ===== */

/* Application entry reached after scatter loading; initializes and enters the cooperative
   scheduler. */

void __stdcall_softfp application_entry(void)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 extraout_r2;
  uint *puVar4;
  int *piVar5;
  uint *puVar6;
  code *UNRECOVERED_JUMPTABLE;
  undefined8 uVar7;
  
  uVar2 = FUN_00003a9c();
  FUN_00002920(uVar2,extraout_r2);
  main_scheduler_loop();
  uVar7 = FUN_00003ada();
  FUN_00002928();
  UNRECOVERED_JUMPTABLE = (code *)0x294a;
  FUN_00003b8c((int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
  puVar1 = DAT_00002980;
  piVar5 = (int *)*DAT_00002980;
  puVar4 = (uint *)DAT_00002980[1];
  uVar3 = *puVar4 + *piVar5;
  *puVar4 = uVar3;
  puVar6 = (uint *)(piVar5 + 1);
  puVar4 = puVar4 + 1;
  if (puVar6 < puVar1) {
    if (puVar1 <= puVar4) {
      puVar4 = puVar1 + -0x37;
    }
  }
  else {
    puVar6 = puVar1 + -0x37;
  }
  *puVar1 = (uint)puVar6;
  puVar1[1] = (uint)puVar4;
                    /* WARNING: Could not recover jumptable at 0x00002972. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar3 & 0x7fffffff);
  return;
}



/* ===== FUN_0000293e @ 0x293E ===== */

void __stdcall_softfp FUN_0000293e(undefined4 param_1,undefined4 param_2)

{
  uint *puVar1;
  uint uVar2;
  uint *puVar3;
  int *piVar4;
  uint *puVar5;
  code *UNRECOVERED_JUMPTABLE;
  
  FUN_00002928();
  UNRECOVERED_JUMPTABLE = (code *)0x294a;
  FUN_00003b8c(param_1,param_2);
  puVar1 = DAT_00002980;
  piVar4 = (int *)*DAT_00002980;
  puVar3 = (uint *)DAT_00002980[1];
  uVar2 = *puVar3 + *piVar4;
  *puVar3 = uVar2;
  puVar5 = (uint *)(piVar4 + 1);
  puVar3 = puVar3 + 1;
  if (puVar5 < puVar1) {
    if (puVar1 <= puVar3) {
      puVar3 = puVar1 + -0x37;
    }
  }
  else {
    puVar5 = puVar1 + -0x37;
  }
  *puVar1 = (uint)puVar5;
  puVar1[1] = (uint)puVar3;
                    /* WARNING: Could not recover jumptable at 0x00002972. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar2 & 0x7fffffff);
  return;
}



/* ===== Reset_Handler @ 0x2984 ===== */

/* Reset entry from the vector table; LKS32 Cortex-M0 application startup. */

void __stdcall_softfp Reset_Handler(void)

{
  bool bVar1;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(DAT_000029ac);
  }
  (*DAT_000029b0)();
                    /* WARNING: Could not recover jumptable at 0x00002990. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_000029b4)();
  return;
}



/* ===== nmi_Handler @ 0x2992 ===== */

void __stdcall_softfp nmi_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== hard_fault_Handler @ 0x2994 ===== */

void __stdcall_softfp hard_fault_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== svc_Handler @ 0x2996 ===== */

void __stdcall_softfp svc_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== pend_sv_Handler @ 0x2998 ===== */

void __stdcall_softfp pend_sv_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== sys_tick_Handler @ 0x299A ===== */

void __stdcall_softfp sys_tick_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== timer0_irq_Handler @ 0x299C ===== */

void __stdcall_softfp timer0_irq_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_000029a0 @ 0x29A0 ===== */

undefined8 __stdcall_softfp FUN_000029a0(void)

{
  return CONCAT44(DAT_000029bc,DAT_000029b8);
}



/* ===== FUN_000029f4 @ 0x29F4 ===== */

void __stdcall_softfp FUN_000029f4(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = DAT_000029fc;
  iVar3 = DAT_000029f8;
  uVar2 = 1;
  iVar4 = DAT_000029f8 + -0x7c;
  *(int *)(DAT_000029f8 + 0x60) = DAT_000029f8;
  *(int *)(iVar3 + 100) = iVar4;
  iVar3 = 0x37;
  while (0 < iVar3) {
    *(uint *)(iVar4 + (iVar3 + -1) * 4) = (uVar2 >> 0x10) + uVar2;
    uVar2 = DAT_00002a00 * uVar2 + iVar1;
    iVar3 = iVar3 + -1;
  }
  return;
}



/* ===== FUN_00002a3c @ 0x2A3C ===== */

void __stdcall_softfp FUN_00002a3c(undefined4 *param_1,uint param_2)

{
  if (param_2 != 0) {
    if (((uint)param_1 & 1) != 0) {
      *(undefined1 *)param_1 = 0;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_2 = param_2 - 1;
    }
    if ((1 < param_2) && ((int)param_1 << 0x1e < 0)) {
      *(undefined2 *)param_1 = 0;
      param_1 = (undefined4 *)((int)param_1 + 2);
      param_2 = param_2 - 2;
    }
  }
  for (; 3 < param_2; param_2 = param_2 - 4) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  if ((int)(param_2 << 0x1e) < 0) {
    *(undefined2 *)param_1 = 0;
    param_1 = (undefined4 *)((int)param_1 + 2);
  }
  if ((param_2 & 1) != 0) {
    *(undefined1 *)param_1 = 0;
  }
  return;
}



/* ===== FUN_00002a40 @ 0x2A40 ===== */

void __stdcall_softfp FUN_00002a40(undefined4 *param_1,uint param_2)

{
  for (; 3 < param_2; param_2 = param_2 - 4) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  if ((int)(param_2 << 0x1e) < 0) {
    *(undefined2 *)param_1 = 0;
    param_1 = (undefined4 *)((int)param_1 + 2);
  }
  if ((param_2 & 1) != 0) {
    *(undefined1 *)param_1 = 0;
  }
  return;
}



/* ===== FUN_00002a44 @ 0x2A44 ===== */

longlong __stdcall_softfp FUN_00002a44(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  iVar5 = 0;
  if (param_2 <= param_1 >> 4) {
    if (param_2 <= param_1 >> 8) {
      if (param_1 >> 0xc < param_2) goto LAB_00002ad2;
      if (param_2 <= param_1 >> 0x10) {
        iVar5 = -0x1000000;
        uVar1 = param_2 << 8;
        if (param_2 << 8 <= param_1 >> 0x10) {
          iVar5 = -0x10000;
          uVar1 = param_2 << 0x10;
          if (param_2 << 0x10 == 0) {
            return (ulonglong)param_1 << 0x20;
          }
        }
        param_2 = uVar1;
        if (param_1 >> 0xc < param_2) goto LAB_00002ad2;
      }
      while( true ) {
        bVar6 = param_2 <= param_1 >> 0xf;
        uVar1 = param_1;
        if (bVar6) {
          uVar1 = param_1 + param_2 * -0x8000;
        }
        bVar10 = param_2 * 0x8000 <= param_1;
        bVar7 = param_2 <= uVar1 >> 0xe;
        uVar2 = uVar1;
        if (bVar7) {
          uVar2 = uVar1 + param_2 * -0x4000;
        }
        bVar8 = param_2 <= uVar2 >> 0xd;
        uVar3 = uVar2;
        if (bVar8) {
          uVar3 = uVar2 + param_2 * -0x2000;
        }
        bVar9 = param_2 <= uVar3 >> 0xc;
        param_1 = uVar3;
        if (bVar9) {
          param_1 = uVar3 + param_2 * -0x1000;
        }
        iVar5 = (((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 +
                 (uint)(bVar7 && param_2 * 0x4000 <= uVar1)) * 2 +
                (uint)(bVar8 && param_2 * 0x2000 <= uVar2)) * 2 +
                (uint)(bVar9 && param_2 * 0x1000 <= uVar3);
LAB_00002ad2:
        bVar6 = param_2 <= param_1 >> 0xb;
        uVar1 = param_1;
        if (bVar6) {
          uVar1 = param_1 + param_2 * -0x800;
        }
        bVar10 = param_2 <= uVar1 >> 10;
        uVar2 = uVar1;
        if (bVar10) {
          uVar2 = uVar1 + param_2 * -0x400;
        }
        bVar7 = param_2 <= uVar2 >> 9;
        uVar3 = uVar2;
        if (bVar7) {
          uVar3 = uVar2 + param_2 * -0x200;
        }
        uVar1 = ((iVar5 * 2 + (uint)(bVar6 && param_2 * 0x800 <= param_1)) * 2 +
                (uint)(bVar10 && param_2 * 0x400 <= uVar1)) * 2 +
                (uint)(bVar7 && param_2 * 0x200 <= uVar2);
        bVar6 = param_2 <= uVar3 >> 8;
        param_1 = uVar3;
        if (bVar6) {
          param_1 = uVar3 + param_2 * -0x100;
        }
        bVar6 = bVar6 && param_2 * 0x100 <= uVar3;
        iVar5 = uVar1 * 2 + (uint)bVar6;
        if (!CARRY4(uVar1,uVar1) && !CARRY4(uVar1 * 2,(uint)bVar6)) break;
        param_2 = param_2 >> 8;
      }
    }
    bVar6 = param_2 <= param_1 >> 7;
    uVar1 = param_1;
    if (bVar6) {
      uVar1 = param_1 + param_2 * -0x80;
    }
    bVar10 = param_2 * 0x80 <= param_1;
    bVar7 = param_2 <= uVar1 >> 6;
    uVar2 = uVar1;
    if (bVar7) {
      uVar2 = uVar1 + param_2 * -0x40;
    }
    bVar8 = param_2 <= uVar2 >> 5;
    uVar3 = uVar2;
    if (bVar8) {
      uVar3 = uVar2 + param_2 * -0x20;
    }
    bVar9 = param_2 <= uVar3 >> 4;
    param_1 = uVar3;
    if (bVar9) {
      param_1 = uVar3 + param_2 * -0x10;
    }
    iVar5 = (((iVar5 * 2 + (uint)(bVar6 && bVar10)) * 2 + (uint)(bVar7 && param_2 * 0x40 <= uVar1))
             * 2 + (uint)(bVar8 && param_2 * 0x20 <= uVar2)) * 2 +
            (uint)(bVar9 && param_2 * 0x10 <= uVar3);
  }
  bVar6 = param_2 <= param_1 >> 3;
  uVar1 = param_1;
  if (bVar6) {
    uVar1 = param_1 + param_2 * -8;
  }
  bVar10 = param_2 <= uVar1 >> 2;
  uVar2 = uVar1;
  if (bVar10) {
    uVar2 = uVar1 + param_2 * -4;
  }
  bVar7 = param_2 <= uVar2 >> 1;
  uVar3 = uVar2;
  if (bVar7) {
    uVar3 = uVar2 + param_2 * -2;
  }
  uVar4 = uVar3 - param_2;
  if (param_2 > uVar3) {
    uVar4 = uVar3;
  }
  return CONCAT44(uVar4,(((iVar5 * 2 + (uint)(bVar6 && param_2 * 8 <= param_1)) * 2 +
                         (uint)(bVar10 && param_2 * 4 <= uVar1)) * 2 +
                        (uint)(bVar7 && param_2 * 2 <= uVar2)) * 2 + (uint)(param_2 <= uVar3));
}



/* ===== FUN_00002a60 @ 0x2A60 ===== */

longlong __stdcall_softfp FUN_00002a60(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  
  if (-1 < (int)(param_1 | param_2)) {
    iVar6 = 0;
    if (param_2 <= param_1 >> 1) {
      if (param_2 <= param_1 >> 4) {
        if (param_2 <= param_1 >> 8) {
          if (param_1 >> 0xc < param_2) goto LAB_00002ad2;
          if (param_2 <= param_1 >> 0x10) {
            iVar6 = -0x1000000;
            uVar1 = param_2 << 8;
            if (param_2 << 8 <= param_1 >> 0x10) {
              iVar6 = -0x10000;
              uVar1 = param_2 << 0x10;
              if (param_2 << 0x10 == 0) goto LAB_00002c22;
            }
            param_2 = uVar1;
            if (param_1 >> 0xc < param_2) goto LAB_00002ad2;
          }
          while( true ) {
            bVar7 = param_2 <= param_1 >> 0xf;
            uVar1 = param_1;
            if (bVar7) {
              uVar1 = param_1 + param_2 * -0x8000;
            }
            bVar11 = param_2 * 0x8000 <= param_1;
            bVar8 = param_2 <= uVar1 >> 0xe;
            uVar2 = uVar1;
            if (bVar8) {
              uVar2 = uVar1 + param_2 * -0x4000;
            }
            bVar9 = param_2 <= uVar2 >> 0xd;
            uVar3 = uVar2;
            if (bVar9) {
              uVar3 = uVar2 + param_2 * -0x2000;
            }
            bVar10 = param_2 <= uVar3 >> 0xc;
            param_1 = uVar3;
            if (bVar10) {
              param_1 = uVar3 + param_2 * -0x1000;
            }
            iVar6 = (((iVar6 * 2 + (uint)(bVar7 && bVar11)) * 2 +
                     (uint)(bVar8 && param_2 * 0x4000 <= uVar1)) * 2 +
                    (uint)(bVar9 && param_2 * 0x2000 <= uVar2)) * 2 +
                    (uint)(bVar10 && param_2 * 0x1000 <= uVar3);
LAB_00002ad2:
            bVar7 = param_2 <= param_1 >> 0xb;
            uVar1 = param_1;
            if (bVar7) {
              uVar1 = param_1 + param_2 * -0x800;
            }
            bVar11 = param_2 <= uVar1 >> 10;
            uVar2 = uVar1;
            if (bVar11) {
              uVar2 = uVar1 + param_2 * -0x400;
            }
            bVar8 = param_2 <= uVar2 >> 9;
            uVar3 = uVar2;
            if (bVar8) {
              uVar3 = uVar2 + param_2 * -0x200;
            }
            uVar1 = ((iVar6 * 2 + (uint)(bVar7 && param_2 * 0x800 <= param_1)) * 2 +
                    (uint)(bVar11 && param_2 * 0x400 <= uVar1)) * 2 +
                    (uint)(bVar8 && param_2 * 0x200 <= uVar2);
            bVar7 = param_2 <= uVar3 >> 8;
            param_1 = uVar3;
            if (bVar7) {
              param_1 = uVar3 + param_2 * -0x100;
            }
            bVar7 = bVar7 && param_2 * 0x100 <= uVar3;
            iVar6 = uVar1 * 2 + (uint)bVar7;
            if (!CARRY4(uVar1,uVar1) && !CARRY4(uVar1 * 2,(uint)bVar7)) break;
            param_2 = param_2 >> 8;
          }
        }
        bVar7 = param_2 <= param_1 >> 7;
        uVar1 = param_1;
        if (bVar7) {
          uVar1 = param_1 + param_2 * -0x80;
        }
        bVar11 = param_2 * 0x80 <= param_1;
        bVar8 = param_2 <= uVar1 >> 6;
        uVar2 = uVar1;
        if (bVar8) {
          uVar2 = uVar1 + param_2 * -0x40;
        }
        bVar9 = param_2 <= uVar2 >> 5;
        uVar3 = uVar2;
        if (bVar9) {
          uVar3 = uVar2 + param_2 * -0x20;
        }
        bVar10 = param_2 <= uVar3 >> 4;
        param_1 = uVar3;
        if (bVar10) {
          param_1 = uVar3 + param_2 * -0x10;
        }
        iVar6 = (((iVar6 * 2 + (uint)(bVar7 && bVar11)) * 2 +
                 (uint)(bVar8 && param_2 * 0x40 <= uVar1)) * 2 +
                (uint)(bVar9 && param_2 * 0x20 <= uVar2)) * 2 +
                (uint)(bVar10 && param_2 * 0x10 <= uVar3);
      }
      bVar7 = param_2 <= param_1 >> 3;
      uVar1 = param_1;
      if (bVar7) {
        uVar1 = param_1 + param_2 * -8;
      }
      bVar11 = param_2 * 8 <= param_1;
      bVar8 = param_2 <= uVar1 >> 2;
      uVar2 = uVar1;
      if (bVar8) {
        uVar2 = uVar1 + param_2 * -4;
      }
      bVar9 = param_2 <= uVar2 >> 1;
      param_1 = uVar2;
      if (bVar9) {
        param_1 = uVar2 + param_2 * -2;
      }
      iVar6 = ((iVar6 * 2 + (uint)(bVar7 && bVar11)) * 2 + (uint)(bVar8 && param_2 * 4 <= uVar1)) *
              2 + (uint)(bVar9 && param_2 * 2 <= uVar2);
    }
    uVar1 = param_1 - param_2;
    if (param_2 > param_1) {
      uVar1 = param_1;
    }
    return CONCAT44(uVar1,iVar6 * 2 + (uint)(param_2 <= param_1));
  }
  iVar6 = (int)param_2 >> 0x1f;
  if (-iVar6 != 0) {
    param_2 = -param_2;
  }
  uVar1 = (int)param_1 >> 0x20;
  if (((int)param_1 >> 0x1f & 1U) != 0) {
    param_1 = -param_1;
  }
  uVar1 = uVar1 ^ -iVar6;
  iVar6 = 0;
  uVar2 = param_2;
  if (param_1 >> 4 < param_2) goto LAB_00002bda;
  if (param_2 <= param_1 >> 8) {
    uVar2 = param_2 << 6;
    iVar6 = -0x4000000;
    uVar3 = param_1 >> 8;
    if (uVar2 <= uVar3) {
      uVar2 = param_2 << 0xc;
      iVar6 = -0x100000;
      if (uVar2 <= uVar3) {
        uVar2 = param_2 << 0x12;
        iVar6 = -0x4000;
        if (uVar2 <= uVar3) {
          uVar2 = param_2 << 0x18;
          if (uVar2 == 0) {
            if ((uVar1 & 1) != 0) {
              param_1 = -param_1;
            }
LAB_00002c22:
            return (ulonglong)param_1 << 0x20;
          }
          iVar6 = -0x100;
        }
      }
    }
  }
  while( true ) {
    bVar7 = uVar2 <= param_1 >> 7;
    uVar3 = param_1;
    if (bVar7) {
      uVar3 = param_1 + uVar2 * -0x80;
    }
    bVar11 = uVar2 * 0x80 <= param_1;
    bVar8 = uVar2 <= uVar3 >> 6;
    uVar4 = uVar3;
    if (bVar8) {
      uVar4 = uVar3 + uVar2 * -0x40;
    }
    bVar9 = uVar2 <= uVar4 >> 5;
    uVar5 = uVar4;
    if (bVar9) {
      uVar5 = uVar4 + uVar2 * -0x20;
    }
    bVar10 = uVar2 <= uVar5 >> 4;
    param_1 = uVar5;
    if (bVar10) {
      param_1 = uVar5 + uVar2 * -0x10;
    }
    iVar6 = (((iVar6 * 2 + (uint)(bVar7 && bVar11)) * 2 + (uint)(bVar8 && uVar2 * 0x40 <= uVar3)) *
             2 + (uint)(bVar9 && uVar2 * 0x20 <= uVar4)) * 2 +
            (uint)(bVar10 && uVar2 * 0x10 <= uVar5);
LAB_00002bda:
    bVar7 = uVar2 <= param_1 >> 3;
    uVar3 = param_1;
    if (bVar7) {
      uVar3 = param_1 + uVar2 * -8;
    }
    uVar4 = iVar6 * 2 + (uint)(bVar7 && uVar2 * 8 <= param_1);
    bVar7 = uVar2 <= uVar3 >> 2;
    param_1 = uVar3;
    if (bVar7) {
      param_1 = uVar3 + uVar2 * -4;
    }
    bVar7 = bVar7 && uVar2 * 4 <= uVar3;
    iVar6 = uVar4 * 2 + (uint)bVar7;
    if (!CARRY4(uVar4,uVar4) && !CARRY4(uVar4 * 2,(uint)bVar7)) break;
    uVar2 = uVar2 >> 6;
  }
  bVar7 = uVar2 <= param_1 >> 1;
  uVar3 = param_1;
  if (bVar7) {
    uVar3 = param_1 + uVar2 * -2;
  }
  uVar4 = uVar3 - uVar2;
  if (uVar2 > uVar3) {
    uVar4 = uVar3;
  }
  iVar6 = (iVar6 * 2 + (uint)(bVar7 && uVar2 * 2 <= param_1)) * 2 + (uint)(uVar2 <= uVar3);
  if ((uVar1 & 1) != 0) {
    iVar6 = -iVar6;
  }
  if ((int)uVar1 >> 1 < 0) {
    uVar4 = -uVar4;
  }
  return CONCAT44(uVar4,iVar6);
}



/* ===== FUN_00002c34 @ 0x2C34 ===== */

longlong __stdcall_softfp FUN_00002c34(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  bool bVar8;
  
  uVar6 = param_1 - param_3;
  iVar2 = (param_2 - param_4) - (uint)(param_1 < param_3);
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    bVar8 = param_1 < uVar6;
    param_1 = param_1 - uVar6;
    param_2 = (param_2 - iVar2) - (uint)bVar8;
    bVar8 = CARRY4(param_3,uVar6);
    param_3 = param_3 + uVar6;
    param_4 = param_4 + iVar2 + (uint)bVar8;
  }
  uVar3 = param_2 >> 0x14;
  uVar6 = uVar3 - (param_4 >> 0x14);
  if ((DAT_00002f78 & ~uVar3) == 0) {
    uVar6 = param_2 * 2 + (uint)(param_1 != 0);
    uVar3 = param_4 * 2 + (uint)(param_3 != 0);
    if ((uVar6 <= DAT_00002f84) && (uVar3 <= DAT_00002f84)) {
      if (uVar6 == uVar3) {
        bVar8 = param_2 != param_4;
        param_3 = param_1;
        param_4 = param_2;
        if (bVar8) goto LAB_00002d50;
      }
      else if (uVar6 == 0xffe00000) goto LAB_00002cc0;
      return CONCAT44(param_4,param_3);
    }
LAB_00002d50:
    return (ulonglong)DAT_00002f88 << 0x20;
  }
  if ((param_4 >> 0x14 & 0x7ff) == 0) {
    if ((uVar3 & 0x7ff) != 0) goto LAB_00002cc0;
    param_2 = param_2 & 0x80000000;
  }
  else {
    uVar3 = uVar3 * 0x100000;
    param_2 = param_2 & ~uVar3;
    uVar4 = param_4 & 0x1fffff | 0x100000;
    uVar1 = 0x20 - uVar6;
    if ((int)uVar1 < 0) {
      param_3 = uVar4 * 2 + (uint)(param_3 != 0);
      uVar1 = 0x1f - (uVar6 - 0x20);
      if ((int)uVar1 < 0) {
        uVar1 = 0;
      }
      else {
        uVar4 = uVar4 >> (uVar6 - 0x20 & 0xff);
        bVar8 = CARRY4(uVar4,param_1);
        param_1 = uVar4 + param_1;
        param_2 = param_2 + bVar8;
      }
      if (param_2 >> 0x14 != 0) goto LAB_00002ce2;
LAB_00002c92:
      param_2 = param_2 + uVar3;
      param_3 = param_3 << (uVar1 & 0xff);
      if (-1 < (int)param_3) goto LAB_00002cc0;
      bVar8 = 0xfffffffe < param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + bVar8;
      if ((param_3 & 0x7fffffff) != 0) goto LAB_00002cc0;
LAB_00002ca2:
      param_1 = param_1 & 0xfffffffe;
    }
    else {
      uVar7 = param_3 >> (uVar6 & 0xff);
      bVar8 = CARRY4(uVar7,param_1);
      uVar7 = uVar7 + param_1;
      uVar5 = uVar4 << (uVar1 & 0xff);
      param_1 = uVar5 + uVar7;
      param_2 = param_2 + bVar8 + (uVar4 >> (uVar6 & 0xff)) + (uint)CARRY4(uVar5,uVar7);
      if (param_2 >> 0x14 == 0) goto LAB_00002c92;
LAB_00002ce2:
      uVar6 = param_1 & 1;
      param_1 = param_1 >> 1 | param_2 << 0x1f;
      param_2 = (param_2 + 0x100000 >> 1) + uVar3;
      if (uVar6 != 0) {
        bVar8 = 0xfffffffe < param_1;
        param_1 = param_1 + 1;
        param_2 = param_2 + bVar8;
        if (param_3 << (uVar1 & 0xff) != 0) goto LAB_00002ca6;
        goto LAB_00002ca2;
      }
    }
LAB_00002ca6:
    if (param_2 << 1 < 0xffe00000) goto LAB_00002cc0;
    iVar2 = param_2 + 0xa0000000;
    param_2 = DAT_00002f80;
    if (iVar2 < 0) {
      param_2 = DAT_00002f7c;
    }
  }
  param_1 = 0;
LAB_00002cc0:
  return CONCAT44(param_2,param_1);
}



/* ===== FUN_00002d56 @ 0x2D56 ===== */

undefined8 __stdcall_softfp FUN_00002d56(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  bool bVar13;
  
  uVar4 = param_1 - param_3;
  if (param_2 <= param_4 && (uint)(param_3 <= param_1) <= param_2 - param_4) {
    uVar11 = (param_2 - param_4) - (uint)(param_1 < param_3) ^ 0x80000000;
    bVar13 = param_1 < uVar4;
    param_1 = param_1 - uVar4;
    param_2 = (param_2 - uVar11) - (uint)bVar13;
    bVar13 = CARRY4(param_3,uVar4);
    param_3 = param_3 + uVar4;
    param_4 = param_4 + uVar11 + (uint)bVar13;
  }
  uVar4 = param_2 >> 0x14;
  uVar11 = uVar4 - (param_4 >> 0x14);
  if ((DAT_00002f78 & ~uVar4) == 0) {
    uVar4 = param_2 * 2 + (uint)(param_1 != 0);
    uVar11 = param_4 * 2 + (uint)(param_3 != 0);
    if ((uVar4 <= DAT_00002f84) && (uVar11 <= DAT_00002f84)) {
      if (uVar4 != uVar11) {
        if (uVar4 != 0xffe00000) {
          param_1 = param_3;
          param_2 = param_4 ^ 0x80000000;
        }
        goto LAB_00002e16;
      }
      if (param_2 != param_4) goto LAB_00002e16;
    }
    param_1 = 0;
    param_2 = DAT_00002f88;
    goto LAB_00002e16;
  }
  if ((param_4 >> 0x14 & 0x7ff) == 0) {
    if ((uVar4 & 0x7ff) != 0) goto LAB_00002e16;
    param_1 = 0;
LAB_00002edc:
    param_2 = 0;
    goto LAB_00002e16;
  }
  uVar8 = uVar4 * 0x100000;
  uVar7 = param_2 & ~uVar8;
  uVar3 = -param_3;
  iVar9 = (DAT_00002f7c - (param_4 & 0xfffff)) - (uint)(param_3 != 0);
  uVar5 = 0x20 - uVar11;
  if (uVar11 < 0x21) {
    uVar12 = uVar3 >> (uVar11 & 0xff);
    uVar1 = uVar12 + param_1;
    uVar10 = iVar9 << (uVar5 & 0xff);
    uVar2 = uVar10 + uVar1;
    iVar9 = uVar7 + CARRY4(uVar12,param_1) + (iVar9 >> (uVar11 & 0xff)) + (uint)CARRY4(uVar10,uVar1)
    ;
    if (-1 < iVar9) goto LAB_00002dc2;
LAB_00002df0:
    bVar13 = CARRY4(uVar2,uVar2);
    uVar2 = uVar2 * 2;
    iVar9 = iVar9 * 2 + (uint)bVar13;
    uVar11 = uVar5 + 1 & 0xff;
    uVar7 = uVar3 << uVar11;
    if (uVar11 == 0 && uVar5 == 0xffffffff || uVar11 != 0 && (uVar3 << uVar11 - 1 & 0x80000000) != 0
       ) {
      uVar2 = uVar2 + 1;
    }
    uVar11 = iVar9 + uVar4 * 0x200000;
    if ((uVar11 >> 0x14 & 1) == 0) {
      uVar11 = iVar9 + 0x200000;
      if ((uVar11 == 0) && (param_1 = 0, uVar2 == 0)) goto LAB_00002edc;
      uVar4 = uVar4 & 0xfffff7ff;
      iVar9 = uVar4 - 2;
      uVar3 = uVar2;
      if (uVar11 == 0) {
        if (uVar2 >> 0x10 == 0) {
          uVar3 = 0;
          iVar9 = uVar4 - 0x22;
          uVar11 = uVar2;
        }
        else {
          uVar3 = uVar2 << 0x10;
          iVar9 = uVar4 - 0x12;
          uVar11 = uVar2 >> 0x10;
        }
      }
      iVar6 = 0;
      uVar4 = uVar11;
      if (uVar11 >> 0xd == 0) {
        uVar4 = uVar11 << 8;
        iVar6 = 8;
        if ((uVar11 & 0xffffff) >> 5 == 0) {
          uVar4 = uVar11 << 0xd;
          iVar6 = 0xd;
        }
      }
      if (uVar4 >> 0x11 == 0) {
        uVar4 = uVar4 << 4;
        iVar6 = iVar6 + 4;
      }
      if (uVar4 >> 0x13 == 0) {
        uVar4 = uVar4 << 2;
        iVar6 = iVar6 + 2;
      }
      if (uVar4 >> 0x14 == 0) {
        uVar4 = uVar4 << 1;
        iVar6 = iVar6 + 1;
      }
      param_2 = (uVar3 >> (0x20U - iVar6 & 0xff) | uVar4) + (param_2 & 0x80000000) +
                (iVar9 - iVar6) * 0x100000;
      param_1 = uVar3 << iVar6;
      if (-1 < iVar9 - iVar6) goto LAB_00002e16;
      param_2 = param_2 + 0x60000000;
LAB_00002eca:
      param_1 = 0;
      param_2 = param_2 & 0x80000000;
      goto LAB_00002e16;
    }
    if (uVar11 >> 0x15 == 0) {
      param_1 = uVar2 >> 1 | (uint)bVar13 * -0x80000000;
      param_2 = (iVar9 >> 1) + uVar8;
      if (param_2 * 2 == 0) {
        if (param_1 == 0) goto LAB_00002edc;
      }
      else if (0x1fffff < param_2 * 2) goto LAB_00002e16;
      goto LAB_00002eca;
    }
    param_2 = iVar9 + uVar8;
    uVar4 = uVar7 >> 0x1f;
  }
  else {
    uVar3 = (iVar9 * 2 + (uint)CARRY4(uVar3,uVar3)) * 2;
    if (param_3 * -2 != 0) {
      uVar3 = uVar3 + 1;
    }
    uVar5 = 0x1e - (uVar11 - 0x20);
    if ((int)uVar5 < 1) {
      param_2 = uVar7 + uVar8;
      goto LAB_00002e16;
    }
    uVar11 = iVar9 >> (uVar11 - 0x20 & 0xff);
    uVar2 = uVar11 + param_1;
    iVar9 = ((int)uVar11 >> 0x1f) + uVar7 + (uint)CARRY4(uVar11,param_1);
    if (iVar9 < 0) goto LAB_00002df0;
LAB_00002dc2:
    param_2 = iVar9 + uVar8;
    uVar7 = uVar3 << (uVar5 & 0xff);
    param_1 = uVar2;
    if (-1 < (int)uVar7) goto LAB_00002e16;
    uVar4 = 1;
  }
  param_1 = uVar2 + uVar4;
  if (CARRY4(uVar2,uVar4)) {
    param_2 = param_2 + 1;
  }
  else if (uVar7 == 0x80000000) {
    param_1 = param_1 & 0xfffffffe;
  }
LAB_00002e16:
  return CONCAT44(param_2,param_1);
}



/* ===== FUN_00002f2c @ 0x2F2C ===== */

void __stdcall_softfp FUN_00002f2c(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  if ((int)(param_2 ^ param_4) < 0) {
    FUN_00002d56();
    return;
  }
  FUN_00002c34();
  return;
}



/* ===== FUN_00002f46 @ 0x2F46 ===== */

void __stdcall_softfp FUN_00002f46(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  if ((int)(param_2 ^ param_4) < 0) {
    FUN_00002c34();
    return;
  }
  FUN_00002d56();
  return;
}



/* ===== FUN_00002f5c @ 0x2F5C ===== */

void __stdcall_softfp FUN_00002f5c(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  if (-1 < (int)(param_2 ^ 0x80000000 ^ param_4)) {
    FUN_00002c34();
    return;
  }
  FUN_00002d56();
  return;
}



/* ===== FUN_00002f8c @ 0x2F8C ===== */

/* WARNING: Removing unreachable block (ram,0x00003030) */

undefined8 __stdcall_softfp FUN_00002f8c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  bool bVar24;
  bool bVar25;
  uint local_40;
  uint local_38;
  uint local_34;
  
  uVar5 = param_2 >> 4 & DAT_00003374;
  uVar17 = param_4 >> 4 & DAT_00003374;
  bVar24 = (DAT_00003374 & ~uVar5) == 0;
  uVar1 = DAT_00003374;
  do {
    if (bVar24) {
      uVar1 = param_2 * 2 + (uint)CARRY4(param_1,param_1);
      if ((DAT_00003380 <= uVar1 && (uint)((param_1 & 0x7fffffff) == 0) <= DAT_00003380 - uVar1) ||
         (uVar1 = param_4 * 2 + (uint)CARRY4(param_3,param_3),
         DAT_00003380 <= uVar1 && (uint)((param_3 & 0x7fffffff) == 0) <= DAT_00003380 - uVar1))
      goto LAB_00003360;
      if ((param_2 & 0x7fffffff) != 0x7ff00000) goto LAB_00003358;
      if ((param_4 & 0x7fffffff) == 0x7ff00000) goto LAB_00003360;
      if ((int)(param_4 ^ param_2) < 0) {
        param_2 = param_2 | 0x80000000;
      }
      else {
        param_2 = param_2 & 0x7fffffff;
      }
      goto LAB_00003318;
    }
    uVar10 = uVar1 & ~uVar17;
    bVar24 = true;
    uVar1 = 0;
  } while (uVar10 == 0);
  bVar24 = uVar17 == 0;
  while (!bVar24) {
    bVar24 = true;
    if (uVar5 != 0) goto code_r0x00002fac;
  }
  if ((param_2 & DAT_0000337c) != 0) {
    param_2 = (param_2 ^ param_4 | DAT_000033d0) ^ (int)DAT_000033d0 >> 0xb;
    goto LAB_00003392;
  }
  if ((param_4 & DAT_0000337c) != 0) goto LAB_00003358;
LAB_00003360:
  param_1 = 0;
  param_2 = DAT_00003384;
LAB_00003318:
  return CONCAT44(param_2,param_1);
LAB_00003358:
  param_2 = (param_2 ^ param_4) & 0x80000000;
LAB_00003392:
  param_1 = 0;
  goto LAB_00003318;
code_r0x00002fac:
  iVar6 = ((param_2 ^ param_4) >> 0x1f | uVar5) - uVar17;
  iVar7 = iVar6 + 0x3fc0000;
  uVar5 = param_2 << 0xb | param_1 >> 0x15 | 0x80000000;
  uVar8 = param_4 << 0xb | param_3 >> 0x15 | 0x80000000;
  uVar1 = uVar8 >> 0x10;
  uVar17 = (param_3 & 0x1fffff) >> 5;
  uVar4 = uVar8 & ~(uVar1 << 0x10);
  uVar3 = param_3 << 0xb & ~(uVar17 << 0x10);
  uVar10 = (uint)*(byte *)((int)&DAT_00002f78 + (uVar8 >> 0x18) + DAT_00003378);
  iVar2 = ((0x800000 - (uVar10 * uVar1 + uVar10)) * uVar10 >> 0x13) + 2;
  uVar10 = 0x20000000 - (iVar2 * (uVar8 >> 0xd) + iVar2);
  uVar8 = uVar10 >> 0x10;
  uVar10 = iVar2 * uVar8 + (iVar2 * (uVar10 & ~(uVar8 << 0x10)) >> 0x10) >> 6;
  uVar20 = (param_1 & 0x1fffff) << 10 | (param_1 >> 0x15) << 0x1f;
  uVar8 = (uVar5 >> 0x10) * uVar10 >> 0x10;
  uVar11 = uVar20 - uVar17 * uVar8;
  local_34 = uVar4 * uVar8 >> 0x10;
  uVar12 = uVar3 * uVar8;
  local_38 = uVar12 >> 0x10 | uVar4 * uVar8 * 0x10000;
  if ((uVar12 & 0xffff) != 0) {
    bVar24 = 0xfffffffe < local_38;
    local_38 = local_38 + 1;
    local_34 = local_34 + bVar24;
  }
  uVar13 = uVar11 - local_38;
  uVar11 = ((((uVar5 >> 1) - uVar1 * uVar8) - (uint)(uVar20 < uVar17 * uVar8)) - local_34) -
           (uint)(uVar11 < local_38);
  uVar5 = (uVar11 >> 2) * uVar10 >> 0x10;
  local_34 = uVar1 * uVar5 >> 0xd;
  uVar20 = uVar17 * uVar5;
  local_38 = uVar20 >> 0xd | uVar1 * uVar5 * 0x80000;
  uVar9 = uVar12 * -0x10000 + uVar20 * -0x80000;
  if (uVar12 * -0x10000 < uVar20 * 0x80000) {
    bVar24 = 0xfffffffe < local_38;
    local_38 = local_38 + 1;
    local_34 = local_34 + bVar24;
  }
  bVar24 = uVar13 < local_38;
  uVar13 = uVar13 - local_38;
  iVar2 = uVar11 - local_34;
  local_34 = uVar4 * uVar5 >> 0x1d;
  uVar11 = uVar3 * uVar5;
  local_38 = uVar11 >> 0x1d | uVar4 * uVar5 * 8;
  if (uVar9 < uVar11 * 8) {
    bVar25 = 0xfffffffe < local_38;
    local_38 = local_38 + 1;
    local_34 = local_34 + bVar25;
  }
  uVar12 = uVar13 - local_38;
  uVar21 = uVar12 * 0x4000000 | uVar9 + uVar11 * -8 >> 6;
  uVar11 = (((iVar2 - (uint)bVar24) - local_34) - (uint)(uVar13 < local_38)) * 0x4000000 |
           uVar12 >> 6;
  uVar12 = (uVar11 >> 0xf) * uVar10;
  uVar20 = uVar12 >> 0x10;
  uVar9 = uVar21 - uVar17 * uVar20;
  local_34 = uVar4 * uVar20 >> 0x10;
  uVar13 = uVar3 * uVar20;
  local_38 = uVar13 >> 0x10 | uVar4 * uVar20 * 0x10000;
  if ((uVar13 & 0xffff) != 0) {
    bVar24 = 0xfffffffe < local_38;
    local_38 = local_38 + 1;
    local_34 = local_34 + bVar24;
  }
  uVar14 = uVar9 - local_38;
  uVar9 = (((uVar11 - uVar1 * uVar20) - (uint)(uVar21 < uVar17 * uVar20)) - local_34) -
          (uint)(uVar9 < local_38);
  uVar11 = (uVar9 >> 2) * uVar10 >> 0x10;
  uVar10 = uVar1 * uVar11 >> 0xd;
  uVar15 = uVar17 * uVar11;
  uVar21 = uVar15 >> 0xd | uVar1 * uVar11 * 0x80000;
  uVar16 = uVar13 * -0x10000 + uVar15 * -0x80000;
  if (uVar13 * -0x10000 < uVar15 * 0x80000) {
    bVar24 = 0xfffffffe < uVar21;
    uVar21 = uVar21 + 1;
    uVar10 = uVar10 + bVar24;
  }
  uVar22 = uVar14 - uVar21;
  uVar18 = uVar4 * uVar11 >> 0x1d;
  uVar15 = uVar3 * uVar11;
  uVar13 = uVar15 >> 0x1d | uVar4 * uVar11 * 8;
  if (uVar16 < uVar15 * 8) {
    bVar24 = 0xfffffffe < uVar13;
    uVar13 = uVar13 + 1;
    uVar18 = uVar18 + bVar24;
  }
  uVar23 = uVar22 - uVar13;
  uVar19 = uVar11 * 0x200 + uVar20 * 0x400000;
  uVar15 = uVar23 * 0x4000000 | uVar16 + uVar15 * -8 >> 6;
  uVar4 = uVar1 << 0x10 | uVar4;
  uVar1 = uVar15 * 2;
  uVar3 = uVar17 << 0x10 | uVar3;
  uVar10 = (((((uVar9 - uVar10) - (uint)(uVar14 < uVar21)) - uVar18) - (uint)(uVar22 < uVar13)) *
            0x4000000 | uVar23 >> 6) * 2 + (uint)CARRY4(uVar15,uVar15);
  uVar9 = (uVar10 - uVar4) - (uint)(uVar1 < uVar3);
  uVar17 = uVar10;
  if (uVar9 < uVar10) {
    uVar17 = uVar9;
    uVar1 = uVar1 - uVar3;
  }
  local_40 = (uint)(uVar9 < uVar10);
  uVar10 = uVar1 * 2;
  uVar1 = uVar17 * 2 + (uint)CARRY4(uVar1,uVar1);
  iVar2 = local_40 * 2;
  uVar9 = (uVar1 - uVar4) - (uint)(uVar10 < uVar3);
  if (((int)uVar17 < 0) || (uVar9 < uVar1)) {
    iVar2 = iVar2 + 1;
    uVar1 = uVar9;
    uVar10 = uVar10 - uVar3;
  }
  uVar17 = uVar10 * 2;
  uVar10 = uVar1 * 2 + (uint)CARRY4(uVar10,uVar10);
  iVar2 = iVar2 * 2;
  uVar4 = (uVar10 - uVar4) - (uint)(uVar17 < uVar3);
  if (((int)uVar1 < 0) || (uVar4 < uVar10)) {
    iVar2 = iVar2 + 1;
    uVar10 = uVar4;
    uVar17 = uVar17 - uVar3;
  }
  if (uVar10 != 0 || uVar17 != 0) {
    uVar19 = uVar19 | 1;
  }
  uVar1 = iVar2 * 0x200 + uVar19;
  uVar5 = uVar8 * 0x10000 + uVar5 * 8 + (uVar12 >> 0x1a) +
          (uint)CARRY4(uVar11 * 0x200,uVar20 * 0x400000) + (uint)CARRY4(iVar2 * 0x200,uVar19);
  iVar2 = 2;
  if (-1 < (int)uVar5) {
    bVar24 = CARRY4(uVar1,uVar1);
    uVar1 = uVar1 * 2;
    iVar2 = 1;
    uVar5 = uVar5 * 2 + (uint)bVar24;
  }
  uVar17 = (uVar5 >> 0xb) + (iVar2 + (iVar7 >> 0x10)) * 0x100000;
  param_1 = uVar1 >> 0xb | uVar5 << 0x15;
  param_2 = iVar6 * -0x80000000 ^ uVar17;
  if ((uVar1 * 0x200000 != 0) && ((uVar1 * 0x200000 & 0x80000000) != 0)) {
    bVar24 = 0xfffffffe < param_1;
    param_1 = param_1 + 1;
    param_2 = param_2 + bVar24;
    if ((uVar1 & 0x3ff) == 0) {
      param_1 = param_1 & 0xfffffffe;
    }
  }
  if ((((int)uVar17 < 0) || ((uVar17 & DAT_0000337c) == 0)) || ((DAT_0000337c & ~uVar17) == 0)) {
    param_1 = 0;
    if (iVar7 < 0x4000001) {
      param_2 = param_2 + 0x60000000 & 0x80000000;
    }
    else {
      param_2 = (param_2 + 0xa0000000 | DAT_000033d0) ^ (int)DAT_000033d0 >> 0xb;
    }
  }
  goto LAB_00003318;
}



/* ===== FUN_000033bc @ 0x33BC ===== */

void __stdcall_softfp
FUN_000033bc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_00002f8c(param_3,param_4,param_1,param_2);
  return;
}



/* ===== FUN_000033d4 @ 0x33D4 ===== */

uint __stdcall_softfp FUN_000033d4(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_1 >> 0x15 | param_2 << 0xb;
  uVar3 = param_2 >> 0x14;
  if ((uVar3 == 0) || (uVar2 = uVar2 | DAT_0000343c, -1 < (int)uVar3)) {
    uVar3 = DAT_00003438 - uVar3;
    if (0 < (int)uVar3) {
      if (0xff < (int)uVar3) {
        return 0;
      }
      return uVar2 >> (uVar3 & 0xff);
    }
  }
  else {
    if ((uVar3 & 0x7ff) == 0) {
      uVar2 = uVar2 & 0x7fffffff;
    }
    uVar3 = DAT_00003438 - (uVar3 & 0x7ff);
    if (-1 < (int)uVar3) {
      uVar2 = uVar2 >> (uVar3 & 0xff);
      uVar1 = -uVar2;
      if (0xff < (int)uVar3) {
        return 0;
      }
      if (uVar2 == 0 || (int)uVar1 < 0) {
        return uVar1;
      }
    }
  }
  if (0xffe00000 < param_2 * 2 + (uint)(param_1 != 0)) {
    return 0;
  }
  return ~(param_2 >> 0x1f) ^ DAT_0000343c;
}



/* ===== FUN_000034ca @ 0x34CA ===== */

undefined8 __stdcall_softfp FUN_000034ca(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1 & 0x80000000;
  if (uVar1 != 0) {
    param_1 = -param_1;
  }
  iVar2 = 0x1f;
  if (param_1 >> 0x10 == 0) {
    iVar2 = 0xf;
    param_1 = param_1 << 0x10;
    if (param_1 == 0) {
      return 0;
    }
  }
  if (param_1 >> 0x18 == 0) {
    param_1 = param_1 << 8;
    iVar2 = iVar2 + -8;
  }
  if (param_1 >> 0x1c == 0) {
    param_1 = param_1 << 4;
    iVar2 = iVar2 + -4;
  }
  if (param_1 >> 0x1e == 0) {
    param_1 = param_1 << 2;
    iVar2 = iVar2 + -2;
  }
  if (-1 < (int)param_1) {
    param_1 = param_1 << 1;
    iVar2 = iVar2 + -1;
  }
  return CONCAT44(((int)param_1 >> 0xb) + iVar2 * 0x100000 + (uVar1 | 0x40000000),param_1 << 0x15);
}



/* ===== FUN_000034da @ 0x34DA ===== */

undefined8 __stdcall_softfp FUN_000034da(uint param_1)

{
  int iVar1;
  
  iVar1 = 0x1f;
  if (param_1 >> 0x10 == 0) {
    iVar1 = 0xf;
    param_1 = param_1 << 0x10;
    if (param_1 == 0) {
      return 0;
    }
  }
  if (param_1 >> 0x18 == 0) {
    param_1 = param_1 << 8;
    iVar1 = iVar1 + -8;
  }
  if (param_1 >> 0x1c == 0) {
    param_1 = param_1 << 4;
    iVar1 = iVar1 + -4;
  }
  if (param_1 >> 0x1e == 0) {
    param_1 = param_1 << 2;
    iVar1 = iVar1 + -2;
  }
  if (-1 < (int)param_1) {
    param_1 = param_1 << 1;
    iVar1 = iVar1 + -1;
  }
  return CONCAT44(((int)param_1 >> 0xb) + iVar1 * 0x100000 + 0x40000000,param_1 << 0x15);
}



/* ===== FUN_000034e0 @ 0x34E0 ===== */

undefined8 __stdcall_softfp FUN_000034e0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  bool bVar20;
  
  bVar20 = (DAT_00003710 & ~(param_2 >> 4)) == 0;
  do {
    if (bVar20) {
      uVar4 = param_2 * 2 + (uint)CARRY4(param_1,param_1);
      if ((((uVar4 < DAT_0000371c || DAT_0000371c - uVar4 < (uint)((param_1 & 0x7fffffff) == 0)) &&
           (uVar4 = param_4 * 2 + (uint)CARRY4(param_3,param_3),
           uVar4 < DAT_0000371c || DAT_0000371c - uVar4 < (uint)((param_3 & 0x7fffffff) == 0))) &&
          (0x1fffff < param_2 << 1)) && (0x1fffff < param_4 << 1)) {
        uVar6 = 0;
        uVar4 = (param_2 ^ param_4) & 0x80000000 | DAT_00003720;
      }
      else {
        uVar6 = 0;
        uVar4 = DAT_00003724;
      }
      goto LAB_000036c4;
    }
    bVar20 = true;
  } while ((DAT_00003710 & ~(param_4 >> 4)) == 0);
  uVar13 = (param_2 ^ param_4) >> 0x1f | param_2 >> 4 & DAT_00003710;
  uVar6 = param_4 >> 4 & DAT_00003710;
  bVar20 = uVar6 == 0;
  uVar4 = DAT_00003710;
  do {
    if (bVar20) {
      uVar6 = 0;
      uVar4 = uVar13 << 0x1f;
      goto LAB_000036c4;
    }
    uVar4 = uVar4 << 4;
    bVar20 = true;
  } while ((param_2 & uVar4) == 0);
  iVar7 = uVar6 + uVar13;
  iVar8 = iVar7 + -0x3fc0000;
  uVar2 = param_4 & 0x1fffff | 0x100000;
  uVar6 = param_2 & 0x1fffff | 0x100000;
  uVar4 = uVar6 >> 10;
  uVar6 = (uVar6 << 4 | param_1 >> 0x1c) & ~(uVar4 << 0xe);
  uVar13 = (param_1 & 0xfffffff) >> 0xe;
  uVar9 = param_1 & 0xfffffff & ~(uVar13 << 0xe);
  uVar3 = uVar2 >> 10;
  uVar14 = (uVar2 << 4 | param_3 >> 0x1c) & ~(uVar3 << 0xe);
  uVar2 = (param_3 & 0xfffffff) >> 0xe;
  uVar18 = param_3 & 0xfffffff & ~(uVar2 << 0xe);
  uVar19 = ((uVar2 + uVar18) * (uVar13 + uVar9) - uVar2 * uVar13) - uVar18 * uVar9;
  uVar15 = uVar18 * uVar9 * 0x10;
  iVar16 = (uVar19 >> 0xe) + uVar2 * uVar13;
  uVar19 = uVar19 * 0x40000;
  if (CARRY4(uVar15,uVar19)) {
    iVar16 = iVar16 + 1;
  }
  uVar5 = iVar16 << 1;
  if (uVar15 + uVar19 != 0) {
    uVar5 = uVar5 | 1;
  }
  uVar15 = uVar14 * uVar9 * 2 + uVar18 * uVar6 * 2 + uVar5;
  uVar19 = uVar3 * uVar13;
  uVar13 = ((uVar3 + uVar14) * (uVar13 + uVar9) - uVar14 * uVar9) - uVar19;
  uVar9 = uVar2 * uVar4;
  uVar2 = ((uVar4 + uVar6) * (uVar2 + uVar18) - uVar18 * uVar6) - uVar9;
  if ((uVar15 & 0x1f) == 0) {
    uVar15 = uVar15 >> 5;
  }
  else {
    uVar15 = uVar15 >> 5 | 1;
  }
  uVar18 = uVar19 * 0x1000000 + uVar15;
  uVar5 = uVar9 * 0x1000000 + uVar18;
  uVar10 = uVar13 * 0x400;
  uVar11 = uVar10 + uVar5;
  uVar1 = uVar2 * 0x400;
  uVar12 = uVar1 + uVar11;
  uVar2 = (uVar2 >> 0x16) +
          (uVar13 >> 0x16) +
          (uVar9 >> 8) + (uVar19 >> 8) + (uint)CARRY4(uVar19 * 0x1000000,uVar15) +
          (uint)CARRY4(uVar9 * 0x1000000,uVar18) + (uint)CARRY4(uVar10,uVar5) +
          (uint)CARRY4(uVar1,uVar11);
  uVar13 = uVar3 * uVar4;
  uVar9 = uVar14 * uVar6;
  uVar4 = ((uVar3 + uVar14) * (uVar4 + uVar6) - uVar13) - uVar9;
  uVar6 = uVar4 * 0x40;
  uVar3 = uVar6 + uVar2;
  uVar19 = uVar13 * 0x100000 + uVar3;
  uVar4 = (uVar13 >> 0xc) + (uVar4 >> 0x1a) + (uint)CARRY4(uVar6,uVar2) +
          (uint)CARRY4(uVar13 * 0x100000,uVar3);
  uVar2 = uVar9 * 0x1000000 + uVar12;
  uVar13 = (uVar9 >> 8) + uVar19 + (uint)CARRY4(uVar9 * 0x1000000,uVar12);
  if (uVar13 < uVar19) {
    uVar4 = uVar4 + 1;
  }
  if (uVar4 < 0x200) {
    iVar16 = 0x14;
    iVar17 = -4;
  }
  else {
    iVar16 = 0x15;
    iVar17 = -3;
  }
  uVar19 = 0x20 - iVar16;
  uVar3 = iVar17 + (iVar8 >> 0x10);
  uVar6 = uVar2 >> iVar16 | uVar13 << (uVar19 & 0xff);
  uVar4 = (uVar13 >> iVar16 | uVar4 << (uVar19 & 0xff)) + uVar3 * 0x100000 ^ iVar7 * -0x80000000;
  uVar2 = uVar2 << (uVar19 & 0xff);
  if ((uVar2 != 0) && ((uVar2 & 0x80000000) != 0)) {
    bVar20 = 0xfffffffe < uVar6;
    uVar6 = uVar6 + 1;
    uVar4 = uVar4 + bVar20;
    if ((uVar2 & 0x7fffffff) == 0) {
      uVar6 = uVar6 & 0xfffffffe;
    }
  }
  if (DAT_00003714 <= uVar3) {
    if (iVar8 < 0x4000000) {
      uVar4 = uVar4 + 0x60000000 & 0x80000000;
    }
    else {
      uVar4 = (uVar4 + 0xa0000000 | DAT_00003718) ^ (int)DAT_00003718 >> 0xb;
    }
    uVar6 = 0;
  }
LAB_000036c4:
  return CONCAT44(uVar4,uVar6);
}



/* ===== FUN_00003728 @ 0x3728 ===== */

longlong __stdcall_softfp FUN_00003728(uint param_1)

{
  int iVar1;
  int iVar2;
  
  if (param_1 * 2 + 0x1000000 >> 0x19 != 0) {
    iVar1 = (int)param_1 >> 3;
    iVar2 = iVar1 + 0x38000000;
    if (iVar1 < 0) {
      iVar2 = iVar1 + -0x38000000;
    }
    return CONCAT44(iVar2,param_1 << 0x1d);
  }
  if ((int)((param_1 + 0x800000) * 0x100) < 0) {
    if (param_1 * 2 != 0) {
      return (ulonglong)(param_1 & 0x80000000) << 0x20;
    }
  }
  else {
    if ((param_1 & 0x7fffff) != 0) {
      return (ulonglong)DAT_00003778 << 0x20;
    }
    param_1 = param_1 | 0x700000;
  }
  return (ulonglong)param_1 << 0x20;
}



/* ===== FUN_0000377c @ 0x377C ===== */

uint __stdcall_softfp FUN_0000377c(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  uVar8 = param_1 >> 7 & 0xff0000 | 0x100;
  uVar1 = param_1 ^ param_2;
  uVar2 = param_1 >> 7 & 0xff0000;
  uVar4 = param_2 >> 7 & 0xff0000;
  if ((((uVar2 != 0) && (uVar4 != 0)) && (uVar2 != 0xff0000)) && (uVar4 != 0xff0000)) {
    if ((int)uVar1 < 0) {
      uVar2 = uVar8;
    }
    uVar8 = param_2 & 0xffffff | 0x800000;
    uVar1 = param_1 & 0xffffff | 0x800000;
    uVar5 = (uint)*(byte *)(DAT_000038d4 + (0x384d - (uVar8 >> 0x11)));
    iVar3 = (uVar2 - uVar4) + 0x7d0000;
    iVar6 = uVar5 * 2;
    uVar2 = (iVar3 >> 0x10) + iVar3;
    if (uVar1 < uVar8) {
      uVar1 = uVar1 << 1;
    }
    else {
      uVar2 = uVar2 + 1;
    }
    uVar4 = -uVar8;
    iVar3 = (iVar6 * ((int)(iVar6 * uVar4) >> 4) >> 0x15) + uVar5 * 0x100;
    uVar5 = iVar3 * (uVar1 >> 8) >> 0x14;
    uVar1 = uVar5 * uVar4 + uVar1 * 0x800;
    uVar7 = iVar3 * (uVar1 >> 8) >> 0x13;
    iVar3 = uVar5 * 0x1000 + uVar7;
    uVar1 = uVar7 * uVar4 + uVar1 * 0x1000;
    if (uVar8 <= uVar1) {
      uVar1 = uVar1 + uVar4;
      iVar3 = iVar3 + 1;
    }
    uVar5 = uVar2 * 0x800000 + iVar3;
    if (((uVar1 != 0) && (CARRY4(uVar4,uVar1 * 2))) && (uVar5 = uVar5 + 1, uVar1 * 2 == uVar8)) {
      uVar5 = uVar5 & 0xfffffffe;
    }
    if (0xfbffff < uVar2) {
      if ((int)uVar2 < 1) {
        if ((uVar2 & 0xff) >> 4 != 0) {
          uVar5 = uVar5 + 0x60000000 & 0x80000000;
        }
      }
      else if (uVar5 * 2 + 0x1000000 < 0xfe000000) {
        if (-1 < (int)(uVar5 + 0xa0000000)) {
          return 0x7f800000;
        }
        return 0xff800000;
      }
    }
    return uVar5;
  }
  if ((int)uVar1 < 0) {
    uVar2 = uVar8;
  }
  if ((uVar2 < 0xff0000) && (uVar4 < 0xff0000)) {
    if (uVar4 == 0) {
      if (uVar2 >> 0x10 == 0) {
        return DAT_000038d8;
      }
      return (uVar2 | 0xff) << 0x17;
    }
    uVar1 = uVar1 & 0x80000000;
  }
  else {
    uVar1 = DAT_000038d8;
    if (((param_1 * 2 < 0xff000001) && (param_2 = param_2 * 2, param_2 < 0xff000001)) &&
       ((param_1 * 2 != 0xff000000 || (param_2 != 0xff000000)))) {
      if (param_2 == 0xff000000) {
        param_1 = 0;
      }
      else {
        param_1 = param_1 & 0x7fffffff;
      }
      return uVar2 << 0x17 | param_1;
    }
  }
  return uVar1;
}



/* ===== FUN_000038dc @ 0x38DC ===== */

uint __stdcall_softfp FUN_000038dc(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 << 8;
  uVar2 = (int)param_1 >> 0x17;
  if ((uVar2 == 0) || (uVar1 = uVar1 | 0x80000000, -1 < (int)uVar2)) {
    if ((int)(0x9e - uVar2) < 1) {
LAB_00003912:
      if (0xff000000 < param_1 * 2) {
        return 0;
      }
      return ~((int)param_1 >> 0x1f) ^ 0x80000000;
    }
    uVar1 = uVar1 >> (0x9e - uVar2 & 0xff);
  }
  else {
    if ((uVar2 & 0xff) == 0) {
      uVar1 = (param_1 & 0x7fffff) << 8;
    }
    uVar2 = 0x9e - (uVar2 & 0xff);
    if (((int)uVar2 < 0) ||
       (uVar2 = uVar1 >> (uVar2 & 0xff), uVar1 = -uVar2, uVar2 != 0 && -1 < (int)uVar1))
    goto LAB_00003912;
  }
  return uVar1;
}



/* ===== FUN_00003970 @ 0x3970 ===== */

uint __stdcall_softfp FUN_00003970(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1 & 0x80000000;
  if (uVar1 != 0) {
    param_1 = -param_1;
  }
  iVar2 = 0x1f;
  if (param_1 >> 0x10 == 0) {
    iVar2 = 0xf;
    param_1 = param_1 << 0x10;
    if (param_1 == 0) {
      return 0;
    }
  }
  if (param_1 >> 0x18 == 0) {
    param_1 = param_1 << 8;
    iVar2 = iVar2 + -8;
  }
  if (param_1 >> 0x1c == 0) {
    param_1 = param_1 << 4;
    iVar2 = iVar2 + -4;
  }
  if (param_1 >> 0x1e == 0) {
    param_1 = param_1 << 2;
    iVar2 = iVar2 + -2;
  }
  if (-1 < (int)param_1) {
    param_1 = param_1 << 1;
    iVar2 = iVar2 + -1;
  }
  uVar1 = ((int)param_1 >> 8) + iVar2 * 0x800000 + (uVar1 | 0x40000000);
  if (((param_1 & 0x80) != 0) && (uVar1 = uVar1 + 1, (param_1 & 0x7f) == 0)) {
    uVar1 = uVar1 & 0xfffffffe;
  }
  return uVar1;
}



/* ===== FUN_00003980 @ 0x3980 ===== */

uint __stdcall_softfp FUN_00003980(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0x1f;
  if (param_1 >> 0x10 == 0) {
    iVar2 = 0xf;
    param_1 = param_1 << 0x10;
    if (param_1 == 0) {
      return 0;
    }
  }
  if (param_1 >> 0x18 == 0) {
    param_1 = param_1 << 8;
    iVar2 = iVar2 + -8;
  }
  if (param_1 >> 0x1c == 0) {
    param_1 = param_1 << 4;
    iVar2 = iVar2 + -4;
  }
  if (param_1 >> 0x1e == 0) {
    param_1 = param_1 << 2;
    iVar2 = iVar2 + -2;
  }
  if (-1 < (int)param_1) {
    param_1 = param_1 << 1;
    iVar2 = iVar2 + -1;
  }
  uVar1 = ((int)param_1 >> 8) + iVar2 * 0x800000 + 0x40000000;
  if (((param_1 & 0x80) != 0) && (uVar1 = uVar1 + 1, (param_1 & 0x7f) == 0)) {
    uVar1 = uVar1 & 0xfffffffe;
  }
  return uVar1;
}



/* ===== FUN_00003990 @ 0x3990 ===== */

void __stdcall_softfp FUN_00003990(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_000039fc();
  *puVar1 = param_1;
  return;
}



/* ===== FUN_0000399c @ 0x399C ===== */

longlong __stdcall_softfp FUN_0000399c(int param_1,uint param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_2 & 0x7fffffff) >> 0x14;
  iVar1 = 0;
  uVar2 = DAT_000039f0;
  if ((((uVar3 == 0) || (uVar2 = DAT_000039f0 ^ uVar3, uVar2 == 0)) || ((int)uVar2 <= param_3)) ||
     (param_3 <= (int)-uVar3)) {
    if (uVar3 == 0) {
      return (ulonglong)(param_2 & 0x80000000) << 0x20;
    }
    if (uVar2 == 0) {
      if (param_1 != 0 || (param_2 & 0xfffff) != 0) {
        return (ulonglong)DAT_000039f8 << 0x20;
      }
      return CONCAT44(param_2,param_1);
    }
    param_2 = param_2 & 0x80000000;
    if (-1 < param_3) {
      return (ulonglong)(param_2 | DAT_000039f4) << 0x20;
    }
  }
  else {
    param_2 = param_2 + param_3 * 0x100000;
    iVar1 = param_1;
  }
  return CONCAT44(param_2,iVar1);
}



/* ===== FUN_000039fc @ 0x39FC ===== */

undefined4 __stdcall_softfp FUN_000039fc(void)

{
  return DAT_00003a00;
}



/* ===== FUN_00003a04 @ 0x3A04 ===== */

uint __stdcall_softfp FUN_00003a04(uint param_1,uint param_2,uint param_3,uint param_4,uint param_5)

{
  uint uVar1;
  bool bVar2;
  byte in_Q;
  
  uVar1 = param_2 * 2;
  if (((DAT_00003a90 <= uVar1 && uVar1 - DAT_00003a90 != 0) ||
      (((uVar1 - DAT_00003a90 == 0 && (param_1 != 0)) ||
       (uVar1 = param_4 * 2, DAT_00003a90 <= uVar1 && uVar1 - DAT_00003a90 != 0)))) ||
     ((uVar1 - DAT_00003a90 == 0 && (param_3 != 0)))) {
    if ((param_5 & 0xd0000) == 0) {
      uVar1 = FUN_00003b18();
      return uVar1;
    }
    uVar1 = FUN_00003aea(0,param_5,param_3,param_4,param_4);
    return uVar1;
  }
  if ((int)(param_2 | param_4) < 0) {
    if (param_4 == param_2) {
      if (param_1 <= param_3) {
        return ((byte)((param_3 == param_1) << 3 | 4U | in_Q) & 0xd) << 0x1b;
      }
      uVar1 = ((byte)((param_3 == param_1) << 3 | in_Q) & 0xd) << 0x1b;
    }
    else {
      uVar1 = ((byte)((param_2 <= param_4) << 2 | in_Q) & 0xd) << 0x1b;
      if (param_2 <= param_4) {
        return uVar1;
      }
    }
    return uVar1 | 0x80000000;
  }
  if (param_2 != param_4) {
    return (uint)(byte)(((int)(param_2 - param_4) < 0) << 4 | (param_4 <= param_2) << 2 |
                        SBORROW4(param_2,param_4) << 1 | in_Q) << 0x1b;
  }
  bVar2 = (int)(param_1 - param_3) < 0;
  if (param_1 == param_3) {
    return (uint)(byte)(bVar2 << 4 | 8U | (param_3 <= param_1) << 2 | SBORROW4(param_1,param_3) << 1
                       | in_Q) << 0x1b;
  }
  return (uint)(byte)(bVar2 << 4 | (param_3 <= param_1) << 2 | SBORROW4(param_1,param_3) << 1 | in_Q
                     ) << 0x1b;
}



/* ===== FUN_00003a94 @ 0x3A94 ===== */

undefined4 __stdcall_softfp FUN_00003a94(void)

{
  return DAT_00003a98;
}



/* ===== FUN_00003a9c @ 0x3A9C ===== */

void __stdcall_softfp FUN_00003a9c(void)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 in_lr;
  uint *puVar3;
  
  uVar1 = FUN_00003a94();
  *(undefined4 *)((uVar1 & 0xfffffff8) + 0x5c) = in_lr;
  puVar3 = (uint *)((uVar1 & 0xfffffff8) + 0x58);
  *puVar3 = uVar1;
  FUN_000029a0();
  puVar2 = (undefined4 *)*puVar3;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[3] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  puVar2[6] = 0;
  puVar2[7] = 0;
  puVar2[8] = 0;
  puVar2[9] = 0;
  puVar2[10] = 0;
  puVar2[0xb] = 0;
  puVar2[0xc] = 0;
  puVar2[0xd] = 0;
  puVar2[0xe] = 0;
  puVar2[0xf] = 0;
  return;
}



/* ===== FUN_00003ada @ 0x3ADA ===== */

void __stdcall_softfp FUN_00003ada(undefined4 param_1)

{
  FUN_0000293e(param_1);
  return;
}



/* ===== FUN_00003aea @ 0x3AEA ===== */

uint __stdcall_softfp FUN_00003aea(undefined4 param_1,uint param_2)

{
  byte in_Q;
  
  if (-1 < (int)(param_2 << 0xb)) {
    return 0;
  }
  if ((param_2 & 0x7ffff) >> 0x10 != 0) {
    return ~(param_2 << 0xf) << 1;
  }
  return (in_Q & 1) << 0x1b | 0x30000000;
}



/* ===== FUN_00003b18 @ 0x3B18 ===== */

void __stdcall_softfp FUN_00003b18(void)

{
  undefined4 in_stack_00000000;
  
  FUN_00003b2c(0,DAT_00003b28,in_stack_00000000);
  return;
}



/* ===== FUN_00003b2c @ 0x3B2C ===== */

undefined8 __stdcall_softfp FUN_00003b2c(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_3 & 0xf;
  if (uVar1 == 9) {
    uVar2 = FUN_00003aea(8,param_3);
    goto LAB_00003b5a;
  }
  uVar2 = param_1;
  if (uVar1 == 10) {
    if (-1 < (int)(param_3 << 0x19)) goto LAB_00003b5a;
  }
  else {
    if (uVar1 != 8) goto LAB_00003b5a;
    if (-1 < (int)(param_3 << 0x19)) {
      if ((int)(param_3 << 0x1b) < 0) {
        uVar2 = param_1 << 0x1d;
        param_2 = (param_1 & 0xfffffff) >> 3 | param_1 & 0xff000000;
      }
      else {
        uVar2 = param_1 >> 0x1d | (param_2 & 0xffffff) << 3 | param_2 & 0xff000000;
      }
      goto LAB_00003b5a;
    }
  }
  uVar2 = 0x80000000;
LAB_00003b5a:
  return CONCAT44(param_2,uVar2);
}



/* ===== FUN_00003b8c @ 0x3B8C ===== */

void __stdcall_softfp FUN_00003b8c(void)

{
  software_bkpt(0xab);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_00003bf0 @ 0x3BF0 ===== */

undefined4 __stdcall_softfp FUN_00003bf0(void)

{
  DAT_00020004 = 0x95000000;
  LKS_FLASH_registers =
       (LKS_FLASH_registers & DAT_00003c28) + (uint)(*DAT_00003c24 != 1) * 0x800 & DAT_00003c28;
  return DAT_0002000c;
}



/* ===== FUN_00003c2c @ 0x3C2C ===== */

void __stdcall_softfp FUN_00003c2c(int param_1,uint param_2,int param_3,int param_4)

{
  int iVar1;
  
  if (param_4 == 1) {
    *(uint *)(param_1 + 100) = *(uint *)(param_1 + 100) | 1 << (param_2 & 0xff);
  }
  iVar1 = (param_2 & 3) << 2;
  param_1 = (param_2 & 0xc) + param_1;
  *(uint *)(param_1 + 0x50) = param_3 << iVar1 | *(uint *)(param_1 + 0x50) & ~(0xf << iVar1);
  return;
}



/* ===== FUN_00003c56 @ 0x3C56 ===== */

void __stdcall_softfp FUN_00003c56(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x94) = param_2;
  return;
}



/* ===== FUN_00003c5c @ 0x3C5C ===== */

void __stdcall_softfp FUN_00003c5c(int param_1,ushort *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  FUN_00007a34(1);
  *(uint *)(param_1 + 0x90) = (uint)(*param_2 | param_2[1]);
  *(uint *)(param_1 + 0x60) = (uint)param_2[0xb] << 8 | (uint)param_2[10] << 4 | (uint)param_2[9];
  *(uint *)(param_1 + 0x78) = (uint)param_2[8];
  *(uint *)(param_1 + 0x74) =
       (uint)param_2[2] << 0xc | (uint)param_2[3] << 10 | (uint)param_2[4] << 8 |
       (uint)param_2[5] << 4 | (uint)param_2[6] << 3 | (uint)param_2[7];
  *(uint *)(param_1 + 0xc4) = (uint)param_2[0xd];
  *(uint *)(param_1 + 200) = (uint)param_2[0xe];
  *(uint *)(param_1 + 0xcc) = (uint)param_2[0xf];
  uVar2 = FUN_00003bf0(0x1420);
  puVar1 = DAT_00003d0c;
  *DAT_00003d0c = uVar2;
  uVar2 = FUN_00003bf0(DAT_00003d10);
  puVar1[1] = uVar2;
  uVar2 = FUN_00003bf0(DAT_00003d10 + 4);
  puVar1[2] = uVar2;
  uVar2 = FUN_00003bf0(DAT_00003d10 + 8);
  puVar1[3] = uVar2;
  uVar2 = FUN_00003bf0(DAT_00003d10 + 0xc);
  puVar1 = DAT_00003d14;
  *DAT_00003d14 = uVar2;
  uVar2 = FUN_00003bf0(DAT_00003d10 + 0x10);
  puVar1[1] = uVar2;
  uVar2 = FUN_00003bf0(DAT_00003d10 + 0x14);
  puVar1[2] = uVar2;
  uVar2 = FUN_00003bf0(DAT_00003d10 + 0x18);
  puVar1[3] = uVar2;
  return;
}



/* ===== FUN_00003d18 @ 0x3D18 ===== */

void __stdcall_softfp FUN_00003d18(undefined2 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[9] = 1;
  param_1[10] = 1;
  param_1[0xb] = 1;
  param_1[0xc] = 0;
  return;
}



/* ===== FUN_00003d38 @ 0x3D38 ===== */

void __stdcall_softfp FUN_00003d38(int param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 local_48 [16];
  undefined1 local_38 [20];
  int iStack_24;
  int iStack_20;
  int local_1c;
  undefined4 uStack_18;
  
  uVar4 = 0;
  do {
    uVar3 = 0;
    do {
      iVar1 = uVar4 * 4 + uVar3;
      iVar2 = uVar3 * 4;
      uVar3 = uVar3 + 1 & 0xff;
      local_48[uVar4 + iVar2] = *(undefined1 *)(param_1 + iVar1);
    } while (uVar3 < 4);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 4);
  uVar4 = 0;
  do {
    uVar3 = 0;
    do {
      iVar1 = uVar4 * 4 + uVar3;
      iVar2 = uVar3 * 4;
      uVar3 = uVar3 + 1 & 0xff;
      local_38[uVar4 + iVar2] = *(undefined1 *)(param_2 + iVar1);
    } while (uVar3 < 4);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 4);
  iStack_24 = param_1;
  iStack_20 = param_2;
  local_1c = param_3;
  uStack_18 = param_4;
  FUN_0000a04e(local_48,local_38,param_4);
  uVar4 = 0;
  do {
    uVar3 = 0;
    do {
      iVar1 = uVar3 * 4;
      iVar2 = uVar4 * 4 + uVar3;
      uVar3 = uVar3 + 1 & 0xff;
      *(undefined1 *)(local_1c + iVar2) = local_48[uVar4 + iVar1];
    } while (uVar3 < 4);
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 4);
  return;
}



/* ===== FUN_00003db8 @ 0x3DB8 ===== */

/* WARNING: Function: __ARM_common_switch8 replaced with injection: switch8_r3 */
/* WARNING (jumptable): Removing unreachable block (ram,0x00003e6a) */
/* WARNING: Removing unreachable block (ram,0x00003e6a) */

void __stdcall_softfp FUN_00003db8(void)

{
  byte *pbVar1;
  byte bVar2;
  undefined *puVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  byte local_48 [20];
  uint local_34;
  int local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  undefined4 local_1c;
  
  puVar3 = PTR_DAT_00004058;
  uVar6 = (uint)DAT_00004054[1];
  local_20 = (uint)DAT_00004054[4];
  uVar4 = 0;
  local_48[2] = DAT_00004054[2];
  bVar5 = *DAT_00004054;
  bVar2 = DAT_00004054[5];
  if (uVar6 == 0x40) {
    uVar7 = 0;
    do {
      pbVar1 = DAT_00004054 + uVar7;
      uVar7 = uVar7 + 1 & 0xff;
      uVar4 = *pbVar1 + uVar4 & 0xff;
    } while (uVar7 < 4);
    if (DAT_00004054[4] != uVar4) {
      return;
    }
  }
  else {
    uVar8 = (uint)(byte)(local_48[2] + 3);
    for (uVar7 = 0; uVar7 < uVar8; uVar7 = uVar7 + 1 & 0xff) {
      uVar4 = DAT_00004054[uVar7] + uVar4 & 0xff;
    }
    if (DAT_00004054[uVar8] != uVar4) {
      return;
    }
    bVar2 = DAT_00004054[uVar8 + 1];
  }
  if ((uint)bVar2 + (uint)bVar5 == 0xff) {
    *(undefined2 *)(PTR_DAT_00004058 + 0x16) = 0;
    puVar3[9] = 0;
    if (bVar5 == 0x74) {
      local_1c = 0;
      local_48[0] = 100;
      if (uVar6 == 0x47) {
        PTR_DAT_00004058[8] = 1;
      }
      else {
        if (uVar6 < 0x48) {
          local_24 = (uint)(ushort)((ushort)DAT_00004054[3] * 0x100 + (ushort)DAT_00004054[4]);
          local_28 = (uint)DAT_00004054[6];
          local_2c = (uint)DAT_00004054[5] * 0x100 + local_28;
          local_30 = (uint)DAT_00004054[7] * 0x100 + (uint)DAT_00004054[8];
          local_34 = (uint)DAT_00004054[10];
                    /* WARNING: Could not recover jumptable at 0x00003e6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          if (uVar6 - 0x41 < (uint)DAT_00003e6e) {
            pbVar1 = (byte *)(uVar6 + 0x3e2e);
          }
          else {
            pbVar1 = (byte *)(DAT_00003e6e + 0x3e6f);
          }
          (*(code *)((uint)*pbVar1 * 2 + 0x3e6f))(DAT_00004054[9]);
          return;
        }
        if (uVar6 == 0x4a) {
          local_48[1] = 0x2f;
          if ((int)((uint)DAT_00004054[3] << 0x18) < 0) {
            bVar5 = -(DAT_00004054[3] & 0x7f);
          }
          else {
            bVar5 = DAT_00004054[3];
          }
          *PTR_DAT_00004058 = bVar5;
        }
        else {
          if (uVar6 < 0x4b) {
            if (uVar6 == 0x48) {
              local_48[1] = 0x2c;
              local_48[2] = 4;
            }
            else {
              if (uVar6 != 0x49) {
                return;
              }
              local_48[1] = 0x2e;
              local_48[2] = 0x1a;
            }
          }
          else if (uVar6 == 0x60) {
            local_48[1] = 0x50;
            local_48[2] = 10;
          }
          else {
            if (uVar6 != 0x61) {
              return;
            }
            local_48[1] = 0x51;
            local_48[2] = 8;
          }
        }
        if (*DAT_00004060 == '\0') {
          for (uVar4 = 3; uVar4 < local_48[2] + 3; uVar4 = uVar4 + 1 & 0xff) {
            local_48[uVar4] = DAT_00004054[uVar4];
          }
          bVar5 = 0;
          for (uVar6 = 0; uVar6 < uVar4; uVar6 = uVar6 + 1 & 0xff) {
            bVar5 = local_48[uVar6] + bVar5;
          }
          local_48[uVar6] = bVar5;
          uVar4 = uVar6 + 1 & 0xff;
          local_48[uVar4] = -local_48[0] - 1;
          *DAT_00004060 = '\x01';
          FUN_00009098(local_48,uVar4 + 1 & 0xff);
        }
      }
    }
  }
  return;
}



/* ===== FUN_000042e8 @ 0x42E8 ===== */

void __stdcall_softfp FUN_000042e8(void)

{
  char *pcVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar3 = FUN_000086f0(DAT_00004350);
  puVar2 = DAT_0000435c;
  pcVar1 = DAT_00004358;
  if (iVar3 == 6) {
    if (*DAT_00004358 != '\x01') {
      return;
    }
    if (*DAT_00004354 != '\x01') {
      return;
    }
    *DAT_0000435c = 6;
    puVar2 = DAT_0000435c;
    DAT_0000435c[-0xd] = 1;
    puVar2[-0xc] = 0;
    uVar5 = 1;
    *pcVar1 = '\0';
    *DAT_00004360 = 0x10;
  }
  else {
    if (iVar3 != 7) {
      return;
    }
    if (*DAT_00004358 != '\x01') {
      return;
    }
    if (*DAT_00004354 != '\x01') {
      return;
    }
    uVar4 = 0;
    do {
      puVar2[uVar4] = 0x18;
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 3);
    uVar5 = 3;
    FUN_00004cac();
  }
  FUN_00009098(DAT_0000435c,uVar5);
  return;
}



/* ===== FUN_00004364 @ 0x4364 ===== */

void __stdcall_softfp FUN_00004364(void)

{
  char *pcVar1;
  int iVar2;
  char *pcVar3;
  byte bVar4;
  undefined4 in_r3;
  char local_10;
  undefined3 uStack_f;
  
  iVar2 = DAT_000043c8;
  pcVar1 = DAT_000043c4;
  _local_10 = CONCAT31((int3)((uint)in_r3 >> 8),*DAT_000043c0);
  if (*DAT_000043c4 != '\0') {
    if (*DAT_000043c0 == '\x18') {
      bVar4 = *(char *)(DAT_000043c8 + 0x15) + 1;
      *(byte *)(DAT_000043c8 + 0x15) = bVar4;
      if (3 < bVar4) {
        *(undefined1 *)(iVar2 + 0x15) = 0;
        FUN_00004cac();
      }
    }
    pcVar3 = DAT_000043cc;
    if (*DAT_000043cc == '\x01') {
      if (local_10 == '\x06') {
        *pcVar1 = '\0';
        pcVar1 = DAT_000043d0;
        if (*DAT_000043d0 != '\0') {
          *DAT_000043d4 = 1;
          *pcVar1 = '\0';
        }
      }
      *pcVar3 = '\0';
    }
    FUN_00009098(&local_10,1);
  }
  return;
}



/* ===== FUN_000043d8 @ 0x43D8 ===== */

void __stdcall_softfp FUN_000043d8(void)

{
  int iVar1;
  
  iVar1 = DAT_000043f8;
  *(undefined4 *)(DAT_000043f8 + 0x28) = DAT_000043f4;
  *(uint *)(iVar1 * 0x800000 + 0x1c) = *(uint *)(iVar1 * 0x800000 + 0x1c) | 8;
  iVar1 = DAT_000043fc;
  *(undefined4 *)(DAT_000043fc + 8) = 8;
  *(undefined4 *)(iVar1 + 0xc) = 2;
  return;
}



/* ===== FUN_00004400 @ 0x4400 ===== */

undefined4 __stdcall_softfp FUN_00004400(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = DAT_0000440c;
  *(undefined4 *)(DAT_0000440c + 0x20) = param_1;
  *(undefined4 *)(iVar1 + 0x24) = param_2;
  return *(undefined4 *)(iVar1 + 0x28);
}



/* ===== FUN_00004410 @ 0x4410 ===== */

void __stdcall_softfp FUN_00004410(byte *param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  byte bVar3;
  bool bVar4;
  
  uVar2 = 0;
  while (bVar4 = param_2 != 0, param_2 = param_2 + -1, bVar4) {
    uVar2 = uVar2 ^ (uint)*param_1 << 8;
    bVar3 = 0;
    param_1 = param_1 + 1;
    do {
      if ((int)(uVar2 << 0x10) < 0) {
        uVar1 = (ushort)(uVar2 << 1) ^ (ushort)DAT_00004440;
      }
      else {
        uVar1 = (ushort)(uVar2 << 1);
      }
      bVar3 = bVar3 + 1;
      uVar2 = (uint)uVar1;
    } while (bVar3 < 8);
  }
  return;
}



/* ===== FUN_000044ac @ 0x44AC ===== */

char __stdcall_softfp FUN_000044ac(uint param_1)

{
  char cVar1;
  
  if (param_1 < DAT_00004560) {
    return '\0';
  }
  if (param_1 < DAT_00004560 + 0x36) {
    cVar1 = FUN_00002a60((param_1 - DAT_00004560) * 10,0x36);
  }
  else if (param_1 < DAT_00004560 + 0x4b) {
    cVar1 = FUN_00002a60((param_1 + DAT_00004564) * 10,0x15);
    cVar1 = cVar1 + '\n';
  }
  else if (param_1 < 0x36c) {
    cVar1 = FUN_00002a60((param_1 + DAT_00004564 + -0x15) * 0x14,0x12);
    cVar1 = cVar1 + '\x14';
  }
  else if (param_1 < DAT_00004560 + 0x7c) {
    cVar1 = FUN_00002a60((param_1 - 0x36c) * 0x14,0x1f);
    cVar1 = cVar1 + '(';
  }
  else if (param_1 < DAT_00004560 + 0xa8) {
    cVar1 = FUN_00002a60((param_1 + DAT_00004564 + -0x46) * 0x14,0x2c);
    cVar1 = cVar1 + '<';
  }
  else {
    if (DAT_00004560 + 0xe0 <= param_1) {
      return 'd';
    }
    cVar1 = FUN_00002a60((param_1 + DAT_00004564 + -0x72) * 0x14,0x38);
    cVar1 = cVar1 + 'P';
  }
  return cVar1;
}



/* ===== FUN_00004568 @ 0x4568 ===== */

void __stdcall_softfp FUN_00004568(void)

{
  ushort *puVar1;
  short *psVar2;
  short sVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar5 = DAT_000045f0 * ((*DAT_000045ec * 2 - (int)*DAT_000045e4) - (int)*DAT_000045e8) >> 0xf;
  iVar5 = ((int)*DAT_000045e4 - (int)*DAT_000045e8) * ((int)*DAT_000045e4 - (int)*DAT_000045e8) +
          iVar5 * iVar5;
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  uVar4 = FUN_000086e0(iVar5);
  iVar5 = DAT_000045f4;
  *(undefined4 *)(DAT_000045f4 + 0x24) = uVar4;
  psVar2 = DAT_000045fc;
  puVar1 = DAT_000045f8;
  if ((*DAT_000045f8 < 0xb) || (*(int *)(iVar5 + 0x24) < 0xb)) {
    iVar5 = 0;
  }
  else {
    if ((int)(uint)*DAT_000045f8 < *(int *)(iVar5 + 0x24)) {
      *(uint *)(iVar5 + 0x24) = (uint)*DAT_000045f8;
    }
    sVar3 = FUN_00004400(*(int *)(iVar5 + 0x24) * 0x3ff,(int)(short)*puVar1);
    *psVar2 = sVar3;
    iVar5 = DAT_00004600;
    if (*psVar2 <= DAT_00004600) {
      return;
    }
  }
  *psVar2 = (short)iVar5;
  return;
}



/* ===== FUN_00004604 @ 0x4604 ===== */

undefined4 __stdcall_softfp FUN_00004604(uint *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if ((*param_1 & DAT_0000463c) == 0x20000000) {
    if (((*param_1 & 0xfffe0000) == (vector_00_initial_sp & 0xfffe0000)) &&
       (iVar1 = FUN_00004d00(), iVar1 == param_3)) {
      return 0;
    }
  }
  return 1;
}



/* ===== FUN_00004640 @ 0x4640 ===== */

void __stdcall_softfp FUN_00004640(void)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_0000464c;
  *(undefined4 *)(DAT_0000464c + 4) = 0;
  *puVar1 = 0xa7;
  return;
}



/* ===== FUN_00004650 @ 0x4650 ===== */

void __stdcall_softfp FUN_00004650(void)

{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  puVar4 = DAT_00004694;
  puVar3 = DAT_00004690;
  iVar2 = DAT_0000468c;
  piVar1 = DAT_00004688;
  if (*DAT_00004688 != DAT_0000468c) {
    *DAT_00004694 = *DAT_00004690;
    puVar4[1] = puVar3[1];
    puVar4[2] = puVar3[2];
    puVar4[3] = puVar3[3];
    puVar4 = DAT_0000469c;
    puVar3 = DAT_00004698;
    *DAT_0000469c = *DAT_00004698;
    puVar4[1] = puVar3[1];
    puVar4[2] = puVar3[2];
    *piVar1 = iVar2;
    FUN_00007c94();
  }
  return;
}



/* ===== FUN_000046a0 @ 0x46A0 ===== */

void __stdcall_softfp FUN_000046a0(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  
  iVar3 = DAT_000046d0;
  iVar2 = DAT_000046cc;
  piVar1 = DAT_000046c8;
  uVar4 = 0;
  cVar5 = -0x60;
  if (*DAT_000046c8 != DAT_000046cc) {
    do {
      *(char *)(iVar3 + uVar4) = cVar5;
      cVar5 = cVar5 + '\x01';
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 0x10);
    *piVar1 = iVar2;
    FUN_00007c94();
  }
  return;
}



/* ===== FUN_000046d4 @ 0x46D4 ===== */

void __stdcall_softfp FUN_000046d4(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  char cVar6;
  uint *puVar7;
  uint *puVar8;
  char cVar9;
  char cVar10;
  uint local_28;
  
  uVar3 = 0;
  cVar5 = '\0';
  do {
    if (*(char *)(DAT_0000485c + uVar3) != -1) {
      cVar5 = cVar5 + '\x01';
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 0x12);
  uVar3 = 0;
  cVar6 = '\0';
  do {
    if (*(char *)(DAT_00004860 + uVar3) != -1) {
      cVar6 = cVar6 + '\x01';
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 0x17);
  if ((cVar6 == '\0') || (cVar5 == '\0')) {
    disableIRQinterrupts();
    *DAT_00004868 = DAT_00004864;
    FUN_00004c0c(0x1f800,0);
    bVar2 = 0;
    do {
      puVar7 = (uint *)&DAT_0001f800;
      cVar10 = '\0';
      cVar9 = '\0';
      puVar8 = puVar7;
      if (cVar5 == '\0') {
        bVar1 = 0;
        do {
          FUN_00005efc(puVar8,0x30);
          puVar8 = puVar8 + 1;
          bVar1 = bVar1 + 1;
        } while (bVar1 < 0x12);
        bVar1 = 0;
        do {
          uVar3 = *puVar7;
          puVar7 = puVar7 + 1;
          if (uVar3 != 0x30) {
            cVar10 = cVar10 + '\x01';
          }
          bVar1 = bVar1 + 1;
        } while (bVar1 < 0x12);
      }
      else {
        local_28 = 0;
        do {
          FUN_00005efc(puVar8,*(undefined1 *)(DAT_0000485c + local_28));
          puVar8 = puVar8 + 1;
          local_28 = local_28 + 1 & 0xff;
        } while (local_28 < 0x12);
        uVar3 = 0;
        do {
          uVar4 = *puVar7;
          puVar7 = puVar7 + 1;
          if (*(byte *)(DAT_0000485c + uVar3) != uVar4) {
            cVar10 = cVar10 + '\x01';
          }
          uVar3 = uVar3 + 1 & 0xff;
        } while (uVar3 < 0x12);
      }
      puVar7 = DAT_0000486c;
      if (cVar6 == '\0') {
        local_28 = 0;
        do {
          FUN_00005efc(puVar8,*(undefined1 *)(DAT_00004870 + local_28));
          puVar8 = puVar8 + 1;
          local_28 = local_28 + 1 & 0xff;
        } while (local_28 < 0x17);
        uVar3 = 0;
        do {
          uVar4 = *puVar7;
          puVar7 = puVar7 + 1;
          if (*(byte *)(DAT_00004870 + uVar3) != uVar4) {
            cVar9 = cVar9 + '\x01';
          }
          uVar3 = uVar3 + 1 & 0xff;
        } while (uVar3 < 0x17);
      }
      else {
        local_28 = 0;
        do {
          FUN_00005efc(puVar8,*(undefined1 *)(DAT_00004860 + local_28));
          puVar8 = puVar8 + 1;
          local_28 = local_28 + 1 & 0xff;
        } while (local_28 < 0x17);
        uVar3 = 0;
        do {
          uVar4 = *puVar7;
          puVar7 = puVar7 + 1;
          if (*(byte *)(DAT_00004860 + uVar3) != uVar4) {
            cVar9 = cVar9 + '\x01';
          }
          uVar3 = uVar3 + 1 & 0xff;
        } while (uVar3 < 0x17);
      }
      if (cVar9 == '\0' && cVar10 == '\0') {
        bVar2 = 10;
      }
      bVar2 = bVar2 + 1;
    } while (bVar2 < 8);
    if (bVar2 == 8) {
      *DAT_00004868 = DAT_00004864;
      FUN_00004c0c(0x1f800,0);
    }
  }
  bVar2 = 0;
  do {
    bVar2 = bVar2 + 1;
  } while (bVar2 < 0x17);
  enableIRQinterrupts();
  return;
}



/* ===== FUN_00004874 @ 0x4874 ===== */

void __stdcall_softfp FUN_00004874(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_000048b0;
  uVar1 = DAT_000048ac;
  *(undefined4 *)(DAT_000048b0 + 0x28) = DAT_000048ac;
  *(undefined4 *)(iVar2 + 0x24) = DAT_000048b4;
  *(undefined4 *)(iVar2 + 0x24) = 0;
  iVar3 = DAT_000048b8 * 0x40000000;
  *(int *)(iVar3 + 0x24) = DAT_000048b8;
  FUN_00007ba0(1);
  FUN_000086bc(100);
  FUN_00007a54(1);
  *(undefined4 *)(iVar2 + 0x28) = uVar1;
  *(undefined4 *)(iVar2 + 0x18) = 0;
  *(undefined4 *)(iVar2 + 0x1c) = DAT_000048bc;
  *(undefined4 *)(iVar3 + 0x14) = 1;
  *(undefined4 *)(iVar2 + 0x28) = 0;
  return;
}



/* ===== FUN_000048c0 @ 0x48C0 ===== */

void __stdcall_softfp FUN_000048c0(void)

{
  int iVar1;
  
  iVar1 = DAT_000048d0;
  *(undefined4 *)(DAT_000048d0 + 4) = 1;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = DAT_000048d4;
  return;
}



/* ===== FUN_000048d8 @ 0x48D8 ===== */

uint __stdcall_softfp FUN_000048d8(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1 & 0xff) {
    uVar1 = (uint)*(byte *)(param_1 + uVar2) ^ (uVar1 >> 8 | (uVar1 & 0xff) << 8);
    uVar1 = (uVar1 & 0xff) >> 4 ^ uVar1;
    uVar1 = (uVar1 & 0xff) << 5 ^ (uVar1 & 0xf) << 0xc ^ uVar1;
  }
  return uVar1;
}



/* ===== FUN_0000490a @ 0x490A ===== */

void __stdcall_softfp FUN_0000490a(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x1000;
  }
  else {
    if (param_1 != 1) {
      return;
    }
    uVar1 = 0x200;
  }
  FUN_00007a34(uVar1);
  return;
}



/* ===== FUN_00004922 @ 0x4922 ===== */

void __stdcall_softfp FUN_00004922(void)

{
  undefined4 in_r3;
  undefined4 local_8 [2];
  
  local_8[0] = in_r3;
  FUN_00004a40(local_8);
  local_8[0] = 0;
  FUN_00004948(0,local_8);
  FUN_00004a24(0,0xcb);
  FUN_0000490a(0,1);
  return;
}



/* ===== FUN_00004948 @ 0x4948 ===== */

void __stdcall_softfp FUN_00004948(int param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  iVar1 = DAT_00004a18;
  *(undefined4 *)(DAT_00004a18 + 0x28) = DAT_00004a14;
  iVar7 = iVar1 * 0x800000;
  *(uint *)(iVar7 + 0x14) = *(uint *)(iVar7 + 0x14) & ~(1 << (param_1 + 6U & 0xff));
  *(uint *)(iVar7 + 0x14) = *(uint *)(iVar7 + 0x14) | (uint)*param_2 << (param_1 + 6U & 0xff);
  iVar2 = DAT_00004a18;
  if (param_1 == 0) {
    if (*(int *)(iVar7 + 0x14) << 0x19 < 0) {
      uVar3 = FUN_00003bf0(DAT_00004a1c);
      *(undefined4 *)(iVar2 + -0x14) = uVar3;
      iVar4 = DAT_00004a1c + -4;
LAB_000049a2:
      uVar3 = FUN_00003bf0(iVar4);
      *(undefined4 *)(iVar2 + -0x18) = uVar3;
    }
    else if ((*(uint *)(iVar7 + 0x14) >> 6 & 1) == 0) {
      uVar3 = FUN_00003bf0(DAT_00004a1c + -8);
      *(undefined4 *)(iVar2 + -0x14) = uVar3;
      iVar4 = DAT_00004a1c + -0xc;
      goto LAB_000049a2;
    }
    *(uint *)(iVar2 + -0x24) =
         *(uint *)(iVar2 + -0x24) | (uint)param_2[3] | (int)(char)param_2[2] << 4;
    uVar5 = *(uint *)(iVar7 + 0x1c);
    uVar6 = (uint)param_2[1] << 0xb;
  }
  else {
    if (param_1 != 1) goto LAB_00004a0e;
    if (*(int *)(iVar7 + 0x14) << 0x18 < 0) {
      uVar3 = FUN_00003bf0(DAT_00004a1c + 0x10);
      *(undefined4 *)(iVar2 + -0xc) = uVar3;
      iVar4 = DAT_00004a1c + 0xc;
LAB_000049ec:
      uVar3 = FUN_00003bf0(iVar4);
      *(undefined4 *)(iVar2 + -0x10) = uVar3;
    }
    else if ((*(uint *)(iVar7 + 0x14) >> 7 & 1) == 0) {
      uVar3 = FUN_00003bf0(DAT_00004a1c + 8);
      *(undefined4 *)(iVar2 + -0xc) = uVar3;
      iVar4 = 0x1460;
      goto LAB_000049ec;
    }
    *(uint *)(iVar2 + -0x24) =
         (int)(char)param_2[2] << 0xc | (uint)param_2[3] << 8 | *(uint *)(iVar2 + -0x24);
    uVar5 = *(uint *)(iVar7 + 0x1c);
    uVar6 = (uint)param_2[1] << 0xf;
  }
  *(uint *)(iVar7 + 0x1c) = uVar5 | uVar6;
LAB_00004a0e:
  *(undefined4 *)(iVar1 + 0x28) = DAT_00004a20;
  return;
}



/* ===== FUN_00004a24 @ 0x4A24 ===== */

void __stdcall_softfp FUN_00004a24(int param_1,uint param_2)

{
  if (param_1 != 0) {
    if (param_1 == 1) {
      *(uint *)(DAT_00004a3c + 0x24) = param_2 & 0xfff;
    }
    return;
  }
  *(uint *)(DAT_00004a3c + 0x20) = param_2 & 0xfff;
  return;
}



/* ===== FUN_00004a40 @ 0x4A40 ===== */

void __stdcall_softfp FUN_00004a40(undefined4 param_1)

{
  FUN_00002a3c(param_1,4);
  return;
}



/* ===== FUN_00004a4a @ 0x4A4A ===== */

void __stdcall_softfp FUN_00004a4a(void)

{
  FUN_00007b7c(0x20000);
  return;
}



/* ===== FUN_00004a58 @ 0x4A58 ===== */

void __stdcall_softfp FUN_00004a58(int param_1,int param_2,uint param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  for (uVar4 = 0; iVar3 = DAT_00004a94, pcVar2 = DAT_00004a90, uVar4 < param_3; uVar4 = uVar4 + 1) {
    uVar5 = *(uint *)(DAT_00004a90 + 4);
    cVar1 = ((*(byte *)(param_1 + uVar4) ^ *(byte *)(DAT_00004a94 + (uVar5 & 0xf))) - *DAT_00004a90)
            - (char)uVar5;
    *(char *)(param_2 + uVar4) = cVar1;
    *pcVar2 = cVar1 + *(char *)(iVar3 + 0x10 + (uVar5 & 0xf));
    *(uint *)(pcVar2 + 4) = uVar5 + 1;
  }
  return;
}



/* ===== FUN_00004a98 @ 0x4A98 ===== */

void __stdcall_softfp FUN_00004a98(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_00004ab4;
  *DAT_00004ab4 = DAT_00004ab0;
  DAT_00004ab4[-4] = DAT_00004ab4[-4] & DAT_00004ab8;
  *puVar1 = DAT_00004abc;
  return;
}



/* ===== FUN_00004ae8 @ 0x4AE8 ===== */

void __stdcall_softfp FUN_00004ae8(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar1 = DAT_00004b0c;
  *DAT_00004b0c = DAT_00004b08;
  puVar2 = DAT_00004b0c;
  DAT_00004b0c[-8] = DAT_00004b10;
  puVar2[-7] = DAT_00004b14;
  puVar2[-4] = puVar2[-4] | 0x40;
  *puVar1 = DAT_00004b18;
  return;
}



/* ===== FUN_00004b1c @ 0x4B1C ===== */

void __stdcall_softfp FUN_00004b1c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar1 = DAT_00004b40;
  *DAT_00004b40 = DAT_00004b3c;
  uVar3 = DAT_00004b44;
  puVar2 = DAT_00004b40;
  DAT_00004b40[-8] = DAT_00004b44;
  puVar2[-7] = uVar3;
  puVar2[-4] = puVar2[-4] | 0x40;
  *puVar1 = DAT_00004b48;
  return;
}



/* ===== FUN_00004b4c @ 0x4B4C ===== */

void __stdcall_softfp FUN_00004b4c(void)

{
  ushort *puVar1;
  undefined2 *puVar2;
  ushort uVar3;
  undefined2 uVar4;
  uint uVar5;
  byte bVar6;
  
  puVar1 = DAT_00004bf4;
  uVar5 = 0;
  bVar6 = *DAT_00004bec;
  if ((((*DAT_00004bf0 < 0x3c) || (*DAT_00004bf0 + -0x14 <= (int)(uint)*DAT_00004bf8)) ||
      (',' < *DAT_00004bfc)) || (*DAT_00004bfc < '\x01')) {
    uVar5 = (uint)*DAT_00004bf4;
  }
  else {
    if ((0x59 < *(byte *)(DAT_00004c00 + 1)) && (0x3c < bVar6)) {
      bVar6 = 0x3c;
    }
    if (*DAT_00004bf0 < 0x51) {
      if ((0x3c < *DAT_00004bf0) && (*DAT_00004bf4 != 0)) {
        uVar3 = FUN_00002a60((uint)*DAT_00004bf4 * 0x14,*DAT_00004bf0 + -0x3c);
        uVar5 = (uint)uVar3;
      }
    }
    else {
      if (bVar6 == 0x1e) {
        uVar3 = *(ushort *)(DAT_00004c04 + 4);
      }
      else if (bVar6 == 0x3c) {
        uVar3 = *(ushort *)(DAT_00004c04 + 6);
      }
      else if (bVar6 == 0x5a) {
        uVar3 = *(ushort *)(DAT_00004c04 + 8);
      }
      else {
        uVar3 = 0;
      }
      *DAT_00004bf4 = uVar3;
    }
  }
  puVar2 = DAT_00004c08;
  if (*puVar1 < uVar5) {
    uVar5 = (uint)*puVar1;
  }
  uVar4 = FUN_00009e50(*DAT_00004c08,*puVar1 - uVar5,5);
  *puVar2 = uVar4;
  return;
}



/* ===== FUN_00004c0c @ 0x4C0C ===== */

void __stdcall_softfp FUN_00004c0c(undefined4 param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  *(undefined4 *)(DAT_00004c84 + 0x28) = DAT_00004c80;
  *(undefined4 *)(DAT_00004c84 + 0x50) = DAT_00004c88;
  uVar3 = DAT_00004c94;
  uVar2 = DAT_00004c90;
  puVar1 = DAT_00004c8c;
  if (*DAT_00004c8c == DAT_00004c90) {
    puVar4 = (uint *)(*DAT_00004c8c ^ DAT_00004c98 ^ DAT_00004c9c);
    *puVar4 = *puVar4 & DAT_00004c94;
    DAT_00020004 = param_1;
    *puVar4 = *puVar4 | param_2 + 0x80000000U;
  }
  if (*puVar1 == uVar2) {
    *(undefined4 *)(*puVar1 ^ DAT_00004ca0 ^ DAT_00004ca4) = DAT_00004ca8;
    LKS_FLASH_registers = LKS_FLASH_registers & uVar3;
    *puVar1 = 0;
  }
  LKS_FLASH_registers = LKS_FLASH_registers & uVar3;
  *puVar1 = 0;
  *(undefined4 *)(DAT_00004c84 + 0x54) = 0;
  *(undefined4 *)(DAT_00004c84 + 0x28) = 0;
  return;
}



/* ===== FUN_00004cac @ 0x4CAC ===== */

void __stdcall_softfp FUN_00004cac(void)

{
  int iVar1;
  
  iVar1 = DAT_00004cd4;
  *(undefined1 *)(DAT_00004cd4 + 0x15) = 0;
  *(undefined1 *)(iVar1 + 2) = 0;
  *(undefined4 *)(iVar1 + 0x4c) = 0;
  *DAT_00004cd8 = 0;
  *DAT_00004cdc = 0;
  *(undefined1 *)(iVar1 + 0x11) = 0;
  *(undefined1 *)(iVar1 + 0x12) = 0;
  *(undefined1 *)(iVar1 + 0x13) = 0;
  *(undefined1 *)(iVar1 + 0x14) = 0;
  *(undefined2 *)(iVar1 + 0x34) = 0;
  *(undefined4 *)(iVar1 + 0x5c) = 0;
  *(undefined1 *)(iVar1 + 0x21) = 0;
  *(undefined1 *)(iVar1 + 0x22) = 0;
  return;
}



/* ===== FUN_00004ce0 @ 0x4CE0 ===== */

void __stdcall_softfp FUN_00004ce0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 auStack_90 [132];
  
  FUN_00004a58(param_2,auStack_90);
  FUN_00004eac(param_1,auStack_90,param_3);
  return;
}



/* ===== FUN_00004d00 @ 0x4D00 ===== */

undefined4 __stdcall_softfp
FUN_00004d00(int param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  undefined4 local_18;
  
  puVar1 = DAT_00004d38;
  DAT_00004d38[1] = 1;
  local_18 = param_4;
  for (uVar3 = 0; uVar3 < param_2; uVar3 = uVar3 + 4) {
    uVar2 = 0;
    do {
      if (uVar3 + uVar2 < param_2) {
        *(undefined1 *)((int)&local_18 + uVar2) = *(undefined1 *)(param_1 + uVar2);
      }
      else {
        *(undefined1 *)((int)&local_18 + uVar2) = 0xff;
      }
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 4);
    *puVar1 = local_18;
    param_1 = param_1 + 4;
  }
  return *puVar1;
}



/* ===== FUN_00004d3c @ 0x4D3C ===== */

void __stdcall_softfp FUN_00004d3c(undefined4 param_1)

{
  FUN_00007b7c(8,param_1);
  return;
}



/* ===== FUN_00004d48 @ 0x4D48 ===== */

void __stdcall_softfp FUN_00004d48(uint *param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_00004d7c;
  *DAT_00004d7c =
       param_1[1] & 0xffffff | (uint)*(byte *)((int)param_1 + 7) << 0x14 |
       (uint)(byte)param_1[2] << 0x18 | (uint)*(byte *)((int)param_1 + 9) << 0x1c |
       (uint)*(byte *)((int)param_1 + 10) << 0x1d | (uint)*(byte *)((int)param_1 + 0xb) << 0x1e;
  puVar1[3] = *param_1;
  puVar1[1] = 0;
  return;
}



/* ===== FUN_00004d80 @ 0x4D80 ===== */

void __stdcall_softfp
FUN_00004d80(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_10 = param_2;
  local_c = param_3;
  local_8 = param_4;
  FUN_00004db8(&local_10);
  local_c = 0x200;
  local_8 = 0x10101;
  local_10 = DAT_00004db4;
  FUN_00004d48(&local_10);
  FUN_00004d3c(1);
  return;
}



/* ===== FUN_00004db8 @ 0x4DB8 ===== */

void __stdcall_softfp FUN_00004db8(undefined4 *param_1)

{
  *(short *)(param_1 + 1) = (short)DAT_00004dd4;
  *(undefined1 *)((int)param_1 + 6) = 0;
  *(undefined1 *)((int)param_1 + 7) = 1;
  *(undefined1 *)(param_1 + 2) = 1;
  *(undefined1 *)((int)param_1 + 9) = 1;
  *(undefined1 *)((int)param_1 + 10) = 0;
  *param_1 = 1000;
  *(undefined1 *)((int)param_1 + 0xb) = 0;
  return;
}



/* ===== FUN_00004dd8 @ 0x4DD8 ===== */

bool __stdcall_softfp FUN_00004dd8(byte *param_1,uint param_2)

{
  *param_1 = (byte)(*(uint *)(DAT_00004df0 + 4) >> (param_2 & 0xff)) & 1;
  return *param_1 != 0;
}



/* ===== i2c0_irq_Handler @ 0x4DF4 ===== */

void __stdcall_softfp i2c0_irq_Handler(void)

{
  byte bVar1;
  char cVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  byte *pbVar8;
  
  puVar3 = DAT_00004ea4;
  iVar5 = *(int *)(DAT_00004ea4 + 0xc);
  if (*(int *)(iVar5 + 8) * 0x4000000 < 0) {
    *DAT_00004ea4 = 1;
  }
  if ((*(uint *)(iVar5 + 8) & 1) == 0) goto LAB_00004ea0;
  puVar3[1] = 1;
  pbVar8 = DAT_00004ea8;
  puVar4 = DAT_00004ea4;
  uVar6 = (uint)(byte)puVar3[3];
  uVar7 = (uint)(byte)puVar3[4];
  cVar2 = puVar3[3] - 1;
  if (uVar6 == uVar7) {
    puVar3[3] = cVar2;
    uVar6 = (uint)*pbVar8;
    goto LAB_00004e96;
  }
  if (uVar6 == uVar7 - 1) {
    DAT_00004ea4[3] = cVar2;
    *(uint *)(iVar5 + 0xc) = (uint)pbVar8[1];
    *(undefined4 *)(iVar5 + 0x10) = 2;
  }
  else if (uVar6 == uVar7 - 2) {
    DAT_00004ea4[3] = cVar2;
  }
  else {
    bVar1 = DAT_00004ea4[5];
    if (uVar6 < 2) {
      if (uVar6 == 1) {
        DAT_00004ea4[3] = 0;
        pbVar8[bVar1] = (byte)*(undefined4 *)(iVar5 + 0xc);
        puVar4[5] = bVar1 + 1;
LAB_00004ea0:
        *(undefined4 *)(iVar5 + 8) = 0;
        return;
      }
      cVar2 = DAT_00004ea4[6];
      pbVar8 = DAT_00004ea4 + 10;
      if (cVar2 == '\x03') {
        DAT_00004ea4[6] = 2;
        uVar6 = (uint)*pbVar8;
      }
      else {
        if (cVar2 != '\x02') {
          if (cVar2 == '\x01') {
            DAT_00004ea4[6] = 0;
          }
          goto LAB_00004ea0;
        }
        DAT_00004ea4[6] = 1;
        uVar6 = (uint)(byte)puVar4[0xb];
      }
LAB_00004e96:
      *(uint *)(iVar5 + 0xc) = uVar6;
      *(undefined4 *)(iVar5 + 8) = 4;
      return;
    }
    DAT_00004ea4[3] = cVar2;
    pbVar8[bVar1] = (byte)*(undefined4 *)(iVar5 + 0xc);
    puVar4[5] = bVar1 + 1;
  }
  *(undefined4 *)(iVar5 + 8) = 0x10;
  return;
}



/* ===== FUN_00004eac @ 0x4EAC ===== */

void __stdcall_softfp FUN_00004eac(uint param_1,byte *param_2,uint param_3,undefined4 param_4)

{
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint extraout_r3;
  uint uVar5;
  uint uVar6;
  
  puVar2 = DAT_00005014;
  uVar5 = DAT_00005010;
  uVar6 = 0;
  disableIRQinterrupts();
  *DAT_00005014 = DAT_00005010;
  *(undefined4 *)(DAT_0000501c + 0x28) = DAT_00005018;
  *(undefined4 *)(DAT_0000501c + 0x54) = DAT_00005020;
  if (*puVar2 == uVar5) {
    puVar2 = (uint *)(*DAT_00005014 ^ DAT_00005024 ^ DAT_00005028);
    *puVar2 = *puVar2 & DAT_0000502c;
    *puVar2 = *puVar2 | 0x8000000;
  }
  puVar4 = DAT_00005030;
  uVar3 = param_1;
  if ((param_1 & 3) == 0) goto LAB_00004fea;
  uVar3 = param_1 & 3;
  if (uVar3 == 1) {
    *(undefined1 *)DAT_00005030 = 0xff;
    *(byte *)((int)puVar4 + 1) = *param_2;
    *(byte *)((int)puVar4 + 2) = param_2[1];
    uVar6 = 3;
    param_1 = param_1 - 1;
    *(byte *)((int)puVar4 + 3) = param_2[2];
    param_2 = param_2 + 3;
    puVar4 = DAT_00005030;
  }
  else if (uVar3 == 2) {
    *(undefined1 *)DAT_00005030 = 0xff;
    *(undefined1 *)((int)puVar4 + 1) = 0xff;
    *(byte *)((int)puVar4 + 2) = *param_2;
    uVar6 = 2;
    param_1 = param_1 - 2;
    *(byte *)((int)puVar4 + 3) = param_2[1];
    param_2 = param_2 + 2;
    puVar4 = DAT_00005030;
  }
  else if (uVar3 == 3) {
    *(undefined1 *)DAT_00005030 = 0xff;
    *(undefined1 *)((int)puVar4 + 1) = 0xff;
    *(undefined1 *)((int)puVar4 + 2) = 0xff;
    uVar6 = 1;
    param_1 = param_1 - 3;
    *(byte *)((int)puVar4 + 3) = *param_2;
    param_2 = param_2 + 1;
    puVar4 = DAT_00005030;
  }
  while( true ) {
    DAT_00020008 = *puVar4;
    uVar3 = param_1 + 4;
    DAT_00020004 = param_1;
LAB_00004fea:
    param_1 = uVar3;
    if (param_3 <= uVar6) break;
    if ((param_1 & 0x1ff) == 0) {
      LKS_FLASH_registers = LKS_FLASH_registers & DAT_00005034;
      *DAT_00005014 = 0;
      *(undefined4 *)(DAT_0000501c + 0x54) = 0;
      *(undefined4 *)(DAT_0000501c + 0x28) = 0;
      *DAT_0000503c = DAT_00005038;
      FUN_00004c0c(param_1,0,0x20000,uVar5,param_4);
      uVar3 = DAT_00005010;
      *DAT_00005014 = DAT_00005010;
      *(undefined4 *)(DAT_0000501c + 0x28) = DAT_00005018;
      *(undefined4 *)(DAT_0000501c + 0x54) = DAT_00005020;
      uVar5 = extraout_r3;
      if (*DAT_00005014 == uVar3) {
        puVar2 = (uint *)(*DAT_00005014 ^ DAT_00005024 ^ DAT_00005028);
        *puVar2 = *puVar2 & DAT_0000502c;
        *puVar2 = *puVar2 | 0x8000000;
      }
    }
    puVar4 = DAT_00005030;
    uVar3 = 0;
    do {
      if (uVar6 < param_3) {
        bVar1 = *param_2;
        uVar5 = (uint)bVar1;
        param_2 = param_2 + 1;
        *(byte *)((int)puVar4 + uVar3) = bVar1;
        uVar6 = uVar6 + 1;
      }
      else {
        *(undefined1 *)((int)puVar4 + uVar3) = 0xff;
      }
      uVar3 = uVar3 + 1 & 0xff;
    } while (uVar3 < 4);
  }
  LKS_FLASH_registers = LKS_FLASH_registers & DAT_00005034;
  *DAT_00005014 = 0;
  *(undefined4 *)(DAT_0000501c + 0x54) = 0;
  *(undefined4 *)(DAT_0000501c + 0x28) = 0;
  enableIRQinterrupts();
  return;
}



/* ===== regional_or_hardware_init @ 0x5040 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Provisional behavior name; called by the main scheduler during initialization. */

void __stdcall_softfp regional_or_hardware_init(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  char *pcVar3;
  short *psVar4;
  ushort *puVar5;
  byte bVar6;
  uint uVar7;
  int iVar8;
  
  puVar1 = DAT_0000514c;
  *DAT_0000514c = 0;
  puVar2 = DAT_00005150;
  *DAT_00005150 = 0;
  pcVar3 = DAT_00005154;
  bVar6 = 0;
  do {
    do {
    } while (*pcVar3 == '\0');
    *pcVar3 = '\0';
    psVar4 = DAT_0000515c;
    bVar6 = bVar6 + 1;
  } while (bVar6 < 100);
  iVar8 = 0;
  uVar7 = 0;
  do {
    iVar8 = *(short *)(DAT_00005158 + uVar7 * 2) + iVar8;
    uVar7 = uVar7 + 1 & 0xff;
  } while (uVar7 < 4);
  *DAT_0000515c = (short)(iVar8 >> 6);
  if ((499 < *psVar4) || (*psVar4 < -499)) {
    *puVar2 = 8;
  }
  *DAT_00005160 = *psVar4;
  FUN_00006c60();
  *DAT_00005164 = 0;
  *DAT_00005168 = 0;
  *DAT_0000516c = 0;
  *DAT_00005170 = 0x1ed;
  puVar2 = DAT_00005174;
  *DAT_00005174 = 1;
  *DAT_00005178 = 0;
  *puVar1 = 1;
  FUN_0000750c();
  puVar5 = DAT_00005180;
  iVar8 = 0;
  uVar7 = 0;
  do {
    iVar8 = *(short *)(DAT_0000517c + uVar7 * 2) + iVar8;
    uVar7 = uVar7 + 1 & 0xff;
  } while (uVar7 < 4);
  iVar8 = iVar8 >> 6;
  if (iVar8 < 0) {
    iVar8 = 0;
  }
  *DAT_00005180 = (ushort)iVar8;
  FUN_0000762c();
  if (DAT_00005184 < *puVar5) {
    FUN_000046d4();
    FUN_00004650();
    FUN_000046a0();
  }
  FUN_0000762c();
  speed_variant_config_init();
  if (_DAT_0001fc0c == DAT_00005188) {
    *DAT_0000518c = 1;
    *DAT_00005194 = DAT_00005190;
    FUN_00004c0c(0x1fc00,0);
  }
  else {
    *DAT_0000518c = 0;
  }
  *(undefined1 *)(DAT_00005198 + 2) = 0;
  *(undefined1 *)(DAT_0000519c + 1) = 100;
  if (((*(int *)(puVar2 + 4) != DAT_000051a0) && (*(int *)(puVar2 + 4) != DAT_000051a8)) &&
     (*(int *)(puVar2 + 4) != DAT_000051a0 + -6)) {
    *DAT_000051a4 = 0;
    return;
  }
  *DAT_000051a4 = 1;
  return;
}



/* ===== controller_init_stage @ 0x51AC ===== */

/* Provisional initialization routine called by the scheduler. */

void __stdcall_softfp controller_init_stage(void)

{
  int iVar1;
  uint *puVar2;
  
  iVar1 = DAT_00005244;
  disableIRQinterrupts();
  *(undefined4 *)(DAT_00005244 + 0x28) = DAT_00005240;
  puVar2 = (uint *)(iVar1 >> 0xd);
  *puVar2 = *puVar2 | (int)puVar2 << 2;
  *(undefined4 *)(DAT_00005248 + 4) = 0x3c00;
  FUN_00005250();
  FUN_000086bc(200);
  FUN_00004a4a();
  FUN_0000533c();
  FUN_00004922();
  FUN_000043d8();
  FUN_00005a6c();
  FUN_00005f8c();
  FUN_00004d80();
  FUN_000048c0();
  FUN_00009080();
  FUN_00009148();
  *DAT_0000524c = 2;
  FUN_00008afc();
  FUN_0000549c();
  FUN_00009f08(0x10,1);
  FUN_00009ef0(0x10);
  FUN_00009f08(10,3);
  FUN_00009ef0(10);
  FUN_00009f08(0xb,3);
  FUN_00009ef0(0xb);
  FUN_00007c00(1);
  *(undefined4 *)(iVar1 + 0x28) = 0;
  enableIRQinterrupts();
  return;
}



/* ===== FUN_00005250 @ 0x5250 ===== */

void __stdcall_softfp FUN_00005250(void)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  puVar1 = DAT_00005304;
  *DAT_00005304 = *DAT_00005304 | 0x40;
  uVar3 = (int)puVar1 >> 0x14;
  puVar1[9] = puVar1[9] | uVar3;
  puVar1[1] = puVar1[1] | 0x80;
  puVar1[9] = puVar1[9] | uVar3 << 4;
  *puVar1 = *puVar1 | uVar3 << 5;
  puVar1[0xb] = puVar1[0xb] | uVar3 << 4;
  puVar1 = DAT_00005304;
  puVar2 = DAT_00005304 + 0x10;
  DAT_00005304[0x11] = DAT_00005304[0x11] | 1;
  puVar1[0x18] = puVar1[0x18] | 4;
  *puVar2 = 0xc00;
  puVar1[0x19] = puVar1[0x19] | DAT_00005308;
  puVar1[0x1a] = puVar1[0x1a] | DAT_0000530c;
  puVar1[0x11] = puVar1[0x11] | 0x3f0;
  puVar1 = DAT_00005304;
  puVar2 = DAT_00005304 + 0x20;
  *puVar2 = *puVar2 | 0x174;
  puVar1[0x21] = puVar1[0x21] | DAT_00005310;
  puVar1[0x23] = puVar1[0x23] & ~uVar3;
  puVar1[0x23] = puVar1[0x23] & ~((int)puVar2 >> 0x12);
  puVar1[0x23] = puVar1[0x23] & 0xfffffff7;
  puVar1[0x29] = puVar1[0x29] | DAT_00005314;
  puVar1 = DAT_00005304;
  puVar2 = DAT_00005304 + 0x30;
  DAT_00005304[0x31] = DAT_00005304[0x31] | 0x204;
  puVar1[0x33] = puVar1[0x33] | (int)puVar2 >> 0x15;
  return;
}



/* ===== FUN_00005318 @ 0x5318 ===== */

void __stdcall_softfp FUN_00005318(void)

{
  int iVar1;
  undefined2 uVar2;
  
  iVar1 = DAT_00005334;
  *(undefined2 *)(DAT_00005334 + 0x18) = 0;
  *(undefined2 *)(iVar1 + 0x1a) = 0;
  FUN_0000a170(DAT_00005338,0);
  uVar2 = FUN_000038dc();
  *(undefined2 *)(iVar1 + 6) = uVar2;
  return;
}



/* ===== FUN_0000533c @ 0x533C ===== */

void __stdcall_softfp FUN_0000533c(void)

{
  int iVar1;
  uint uVar2;
  undefined2 local_38;
  undefined2 local_36;
  undefined2 local_34;
  undefined2 local_32;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  undefined2 local_28;
  undefined2 local_26;
  undefined2 local_24;
  undefined2 local_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 local_1a;
  
  FUN_00003d18(&local_38);
  iVar1 = DAT_0000547c;
  local_38 = 0;
  local_36 = 0;
  local_34 = 0;
  local_32 = 0;
  local_30 = 0;
  local_2e = 0;
  local_2c = 0;
  local_2a = 0;
  local_28 = 4;
  local_26 = 7;
  local_24 = 0;
  local_22 = 0;
  local_20 = 0;
  local_1e = 0;
  local_1c = 0;
  local_1a = 0;
  FUN_00003c5c(DAT_0000547c,&local_38);
  FUN_00003c56(iVar1,0x7f);
  FUN_00003c2c(iVar1,0,1);
  FUN_00003c2c(iVar1,1,3,0);
  FUN_00003c2c(iVar1,2,2,0);
  FUN_00003c2c(iVar1,3,5,0);
  FUN_00003c2c(iVar1,4,8,1);
  FUN_00003c2c(iVar1,5,7,0);
  FUN_00003c2c(iVar1,6,4,1);
  FUN_00003d18(&local_38);
  iVar1 = DAT_00005480;
  local_38 = 0;
  local_36 = 0;
  local_34 = 0;
  local_32 = 0;
  local_30 = 0;
  local_2e = 0;
  local_2c = 0;
  local_2a = 0;
  local_28 = 4;
  local_26 = 7;
  local_24 = 0;
  local_22 = 0;
  local_20 = 0;
  local_1e = 0;
  local_1c = 0;
  local_1a = 0;
  FUN_00003c5c(DAT_00005480,&local_38);
  FUN_00003c56(iVar1,0x7f);
  FUN_00003c2c(iVar1,0,0);
  FUN_00003c2c(iVar1,1,10,0);
  FUN_00003c2c(iVar1,2,0xd,0);
  FUN_00003c2c(iVar1,3,0xc,0);
  FUN_00003c2c(iVar1,4,9,0);
  FUN_00003c2c(iVar1,5,0xe,0);
  FUN_00003c2c(iVar1,6,0xf,0);
  uVar2 = DAT_0000547c + 0x40 >> 0x13;
  *(uint *)(DAT_0000547c + 0x74) = *(uint *)(DAT_0000547c + 0x74) | uVar2;
  *(uint *)(DAT_00005480 + 0x74) = *(uint *)(DAT_00005480 + 0x74) | uVar2;
  return;
}



/* ===== FUN_0000549c @ 0x549C ===== */

void __stdcall_softfp FUN_0000549c(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_000054b4;
  *DAT_000054b4 = DAT_000054b0;
  puVar1[4] = 0x1f400;
  puVar1[1] = 1;
  return;
}



/* ===== FUN_000054b8 @ 0x54B8 ===== */

void __stdcall_softfp FUN_000054b8(void)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  byte bVar4;
  undefined1 uVar5;
  
  iVar3 = DAT_00005530;
  pcVar2 = DAT_0000552c;
  if (*DAT_0000552c == '\v') {
    bVar4 = *(char *)(DAT_00005530 + 0xb) + 1;
    *(byte *)(DAT_00005530 + 0xb) = bVar4;
    if (0x28 < bVar4) {
      *(undefined1 *)(iVar3 + 0xb) = 0;
      *(byte *)(iVar3 + 0xc) = *(byte *)(iVar3 + 0xc) ^ 1;
    }
  }
  else {
    *(undefined1 *)(DAT_00005530 + 0xb) = 0;
    *(undefined1 *)(iVar3 + 0xc) = 0;
  }
  if (*DAT_00005534 == 0) {
    uVar5 = 8;
    if (*pcVar2 == '\v') {
      if ((*DAT_00005540 != DAT_00005544) && (*DAT_00005540 != DAT_00005548)) {
        cVar1 = *(char *)(iVar3 + 0xc);
        goto LAB_0000551a;
      }
    }
    else if (*DAT_0000553c == '\0') {
      cVar1 = *(char *)(iVar3 + 2);
LAB_0000551a:
      if (cVar1 == '\0') {
        *DAT_00005538 = 0;
        goto LAB_00005524;
      }
    }
  }
  else {
    uVar5 = 0x14;
  }
  *DAT_00005538 = uVar5;
LAB_00005524:
  *(undefined1 *)(iVar3 + 6) = 0;
  *(undefined1 *)(iVar3 + 7) = 0;
  return;
}



/* ===== mcpwm0_irq_Handler @ 0x554C ===== */

void __stdcall_softfp mcpwm0_irq_Handler(void)

{
  char cVar1;
  short sVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  char *pcVar7;
  short *psVar8;
  short *psVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  uint uVar12;
  undefined2 *puVar13;
  undefined1 uVar14;
  short sVar15;
  int iVar16;
  int *piVar17;
  undefined4 in_r3;
  
  puVar3 = DAT_0000592c;
  if ((byte)DAT_0000592c[7] < 3) {
    DAT_0000592c[7] = DAT_0000592c[7] + 1;
  }
  else {
    *DAT_00005930 = 1;
    puVar3[7] = 0;
  }
  puVar5 = DAT_00005934;
  *(short *)(puVar3 + 0x1c) = (short)*DAT_00005934 >> 4;
  puVar6 = DAT_00005938;
  *(short *)(puVar3 + 0x1e) = (short)*DAT_00005938 >> 4;
  *(short *)(puVar3 + 0x20) = (short)puVar5[1] >> 4;
  puVar4 = DAT_0000592c;
  iVar16 = (uint)(byte)puVar3[7] * 2;
  *(short *)(DAT_0000592c + iVar16 + 0x34) = (short)puVar5[2];
  *(short *)(puVar4 + iVar16 + 100) = (short)puVar6[4];
  *(short *)(puVar4 + iVar16 + 0x3c) = (short)puVar5[3];
  *(short *)(puVar3 + 0x14) = (short)puVar6[1] >> 4;
  *(short *)(puVar3 + 0x16) = (short)puVar6[2] >> 4;
  *(short *)(puVar3 + 0x18) = (short)puVar6[3] >> 4;
  *(short *)(puVar4 + iVar16 + 0x6c) = (short)puVar5[4];
  *(short *)(puVar4 + iVar16 + 0x4c) = (short)puVar5[5];
  *(short *)(puVar4 + iVar16 + 0x44) = (short)puVar5[6];
  *(short *)(puVar4 + iVar16 + 0x5c) = (short)puVar6[5];
  *(short *)(puVar4 + iVar16 + 0x54) = (short)puVar6[6];
  DAT_00005938[0x25] = DAT_00005938[0x25] | 3;
  DAT_00005934[0x25] = DAT_00005934[0x25] | 3;
  pcVar7 = DAT_0000593c;
  *DAT_0000593c = '\0';
  psVar9 = DAT_00005944;
  psVar8 = DAT_00005940;
  cVar1 = puVar3[5];
  if (((cVar1 == '\x04') || (cVar1 == '\x06')) || (cVar1 == '\0')) {
    if ((((puVar3[0x10] != '\0') && (puVar3[0x11] != '\0')) &&
        ((*(short *)(puVar3 + 0x1c) < 0x708 &&
         ((*(short *)(puVar3 + 0x1e) < 0x708 && (-0x708 < *(short *)(puVar3 + 0x1c))))))) &&
       (-0x708 < *(short *)(puVar3 + 0x1e))) {
      *pcVar7 = '\x01';
      *psVar8 = *DAT_00005948 - *(short *)(puVar3 + 0x1c);
      sVar15 = *DAT_0000594c - *(short *)(puVar3 + 0x1e);
LAB_000056ec:
      *psVar9 = sVar15;
    }
  }
  else if ((cVar1 == '\x02') || (cVar1 == '\x03')) {
    if ((puVar3[0x11] != '\0') &&
       ((((puVar3[0x12] != '\0' && (*(short *)(puVar3 + 0x1e) < 0x708)) &&
         (*(short *)(puVar3 + 0x20) < 0x708)) &&
        ((-0x708 < *(short *)(puVar3 + 0x1e) && (-0x708 < *(short *)(puVar3 + 0x20))))))) {
      *pcVar7 = '\x01';
      sVar15 = *DAT_00005950;
      sVar2 = *(short *)(puVar3 + 0x20);
      *psVar9 = *DAT_0000594c - *(short *)(puVar3 + 0x1e);
      *psVar8 = -(*psVar9 + (sVar15 - sVar2));
    }
  }
  else if ((((cVar1 == '\x01') || (cVar1 == '\x05')) &&
           ((puVar3[0x10] != '\0' &&
            (((puVar3[0x12] != '\0' && (*(short *)(puVar3 + 0x1c) < 0x708)) &&
             (*(short *)(puVar3 + 0x20) < 0x708)))))) &&
          ((-0x708 < *(short *)(puVar3 + 0x1c) && (-0x708 < *(short *)(puVar3 + 0x20))))) {
    *pcVar7 = '\x01';
    *psVar8 = *DAT_00005948 - *(short *)(puVar3 + 0x1c);
    sVar15 = -(*psVar8 + (*DAT_00005950 - *(short *)(puVar3 + 0x20)));
    goto LAB_000056ec;
  }
  puVar4 = DAT_00005954;
  puVar3[0x10] = *DAT_00005954;
  puVar10 = DAT_00005958;
  puVar3[0x11] = *DAT_00005958;
  puVar11 = DAT_0000595c;
  puVar3[0x12] = *DAT_0000595c;
  uVar14 = *DAT_00005960;
  puVar3[5] = uVar14;
  *puVar4 = 0;
  *puVar10 = 0;
  *puVar11 = 0;
  if (*DAT_00005964 == '\0') goto LAB_0000576c;
  uVar14 = FUN_00004dd8(DAT_0000592c + 0x22,0,puVar11,uVar14,in_r3);
  puVar3[0xc] = uVar14;
  uVar14 = FUN_00004dd8(DAT_0000592c + 0x28,1);
  puVar3[0xd] = uVar14;
  uVar14 = FUN_00004dd8(DAT_0000592c + 0x2e,2);
  puVar3[0xe] = uVar14;
  puVar3[0xf] = puVar3[0xc] << 2 | puVar3[0xd] << 1 | puVar3[0xe];
  FUN_00007ec8(puVar3[0xf]);
  psVar8 = DAT_00005968;
  if (puVar3[9] == '\x02') {
    if (*DAT_00005974 == '\0') {
      if (*DAT_0000597c < *DAT_00005978) {
        sVar15 = *DAT_0000597c + 1;
      }
      else {
        if (*DAT_0000597c <= *DAT_00005978) goto LAB_000057c8;
        sVar15 = *DAT_0000597c + -1;
      }
      *DAT_0000597c = sVar15;
    }
    else {
      *DAT_0000597c = *DAT_00005978;
    }
LAB_000057c8:
    if ((byte)puVar3[8] < 2) {
      FUN_00005318();
    }
    else if (*pcVar7 != '\0') {
      FUN_00005e34();
      FUN_00005eb0();
      puVar13 = DAT_00005984;
      if (*DAT_00005980 != '\0') {
        *DAT_00005984 = 0;
      }
      if (*DAT_00005988 != '\0') {
        *puVar13 = 0;
      }
      FUN_00005fa8();
    }
    FUN_00005e58();
    FUN_000077a8();
    iVar16 = DAT_00005994;
    if (((*DAT_0000598c == '\0') && (*DAT_00005990 == '\0')) && ((byte)puVar3[8] < 10)) {
      if (puVar3[8] == 0) {
        *(uint *)(DAT_00005994 + 4) = *(uint *)(DAT_00005994 + 4) | 1;
        do {
        } while ((*(uint *)(iVar16 + 4) & 1) == 0);
        FUN_00004b1c();
      }
      puVar3[8] = puVar3[8] + '\x01';
    }
    if ((*DAT_00005998 != '\0') && (*DAT_0000599c != '\0')) {
      puVar3[0xb] = 0;
    }
    if (puVar3[0xb] != '\0') goto LAB_0000576c;
    FUN_00004a98();
    puVar3[9] = 1;
  }
  else {
    if (puVar3[9] != '\x01') {
      if (puVar3[9] != '\x03') {
        if (puVar3[9] != '\0') {
          puVar3[9] = 1;
        }
        goto LAB_0000576c;
      }
      if (puVar3[8] == '\x01') {
        FUN_00004ae8();
LAB_000058d2:
        if (2 < (byte)puVar3[8]) {
          FUN_00004568();
        }
      }
      else {
        if (*DAT_00005998 != '\0') {
          if (*DAT_00005968 < DAT_000059a8) {
            sVar15 = *DAT_00005968 + 2;
LAB_000058d0:
            *DAT_00005968 = sVar15;
          }
          goto LAB_000058d2;
        }
        if (*DAT_00005a54 != '\0') {
          if (1 < *DAT_00005968) {
            sVar15 = *DAT_00005968 + -2;
            goto LAB_000058d0;
          }
          *DAT_00005a54 = '\0';
          goto LAB_000058d2;
        }
        FUN_00004a98();
        puVar3[9] = 1;
        puVar3[8] = 0;
      }
      psVar9 = DAT_000059a0;
      *DAT_00005978 = *DAT_000059a0;
      *DAT_000059a4 = *psVar9;
      if ((byte)puVar3[8] < 10) {
        puVar3[8] = puVar3[8] + 1;
      }
      iVar16 = DAT_00005994;
      piVar17 = (int *)(DAT_00005994 + -0x80);
      *(int *)(DAT_00005994 + -0x70) = -(int)*psVar8;
      *(int *)(iVar16 + -0x6c) = (int)*psVar8;
      *(int *)(iVar16 + -0x78) = -(int)*psVar8;
      *(int *)(iVar16 + -0x74) = (int)*psVar8;
      *piVar17 = -(int)*psVar8;
      *(int *)(iVar16 + -0x7c) = (int)*psVar8;
      goto LAB_0000576c;
    }
    FUN_00004568();
    *DAT_0000597c = *DAT_000059a0;
    FUN_00005318();
    FUN_00005e58();
    FUN_000077a8();
    if ((puVar3[0xb] == '\0') ||
       (cVar1 = puVar3[8], puVar3[8] = cVar1 + 1U, (byte)(cVar1 + 1U) < 0x20)) goto LAB_0000576c;
    if (*DAT_00005998 == '\0') {
      uVar14 = 2;
    }
    else {
      *psVar8 = *DAT_000059a0 * 3;
      uVar14 = 3;
    }
    puVar3[9] = uVar14;
    psVar8 = DAT_000059a0;
    *DAT_00005978 = *DAT_000059a0;
    *DAT_000059a4 = *psVar8;
  }
  puVar3[8] = 0;
LAB_0000576c:
  puVar3[2] = puVar3[2] + '\x01';
  uVar12 = DAT_0000596c;
  sVar15 = *(short *)(puVar3 + 0x1a);
  *(ushort *)(puVar3 + 0x1a) = sVar15 + 1U;
  if (uVar12 <= (ushort)(sVar15 + 1U)) {
    *(undefined2 *)(puVar3 + 0x1a) = 0;
    puVar3[1] = 1;
  }
  if ((*DAT_00005970 == '\x02') && (puVar3[3] == '\0')) {
    if ((byte)puVar3[6] < 0x10) {
      puVar3[6] = puVar3[6] + 1;
    }
    else {
      puVar3[3] = 1;
    }
  }
  else {
    puVar3[6] = 0;
  }
  cVar1 = puVar3[4];
  puVar3[4] = cVar1 + 1U;
  if (0xf < (byte)(cVar1 + 1U)) {
    puVar3[4] = 0;
    puVar3[10] = 1;
    if (*DAT_00005a58 != '\0') {
      *DAT_00005a58 = *DAT_00005a58 + -1;
    }
    if (*DAT_00005a5c != '\0') {
      *DAT_00005a5c = *DAT_00005a5c + -1;
    }
    if (*DAT_00005a60 != '\0') {
      *DAT_00005a60 = *DAT_00005a60 + -1;
    }
    if (*DAT_00005a64 != '\0') {
      *DAT_00005a64 = *DAT_00005a64 + -1;
    }
  }
  FUN_00006bb4();
  iVar16 = DAT_00005a68;
  if (*(int *)(DAT_00005a68 + 0x14) << 0x1b < 0) {
    *(undefined4 *)(DAT_00005a68 + 0x14) = 0x10;
    *puVar3 = 1;
    puVar3[0xb] = 0;
    puVar3[9] = 1;
    FUN_00004a98();
  }
  *(uint *)(iVar16 + 4) = *(uint *)(iVar16 + 4) | 3;
  return;
}



/* ===== FUN_00005a6c @ 0x5A6C ===== */

void __stdcall_softfp FUN_00005a6c(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar1 = DAT_00005ac0;
  *DAT_00005ac0 = DAT_00005abc;
  puVar2 = DAT_00005ac0;
  puVar5 = DAT_00005ac0 + -0x20;
  DAT_00005ac0[-0x11] = 0x44;
  puVar2[-0x14] = 0;
  uVar3 = DAT_00005ac4;
  puVar2[-0x1c] = DAT_00005ac4;
  *puVar5 = 0xc00;
  DAT_00005ac0[-0x22] = DAT_00005ac8;
  uVar4 = DAT_00005acc;
  puVar5 = DAT_00005ac0;
  puVar6 = DAT_00005ac0 + -0x10;
  DAT_00005ac0[-8] = DAT_00005acc;
  puVar5[-7] = uVar4;
  puVar5[-4] = 0x110;
  puVar2[-0x13] = 0x10;
  puVar2[-0x18] = 0x4c;
  puVar2[-0x17] = 0x4c;
  puVar2[-0x16] = 0x4c;
  puVar2[-0x15] = 0x4c;
  puVar5[-0xb] = uVar3;
  *puVar6 = 2;
  *puVar1 = DAT_00005ad0;
  return;
}



/* ===== FUN_00005ad4 @ 0x5AD4 ===== */

void __stdcall_softfp FUN_00005ad4(void)

{
  char cVar1;
  int iVar2;
  short sVar3;
  uint uVar4;
  char cVar5;
  char local_28 [20];
  
  iVar2 = DAT_00005d50;
  cVar5 = '\0';
  if (*(char *)(DAT_00005d50 + 0x16) != '\0') {
    *(undefined1 *)(DAT_00005d50 + 0x16) = 0;
    return;
  }
  if (*(char *)(DAT_00005d50 + 0x2a) == '\0') {
    *(undefined1 *)(DAT_00005d50 + 0x2a) = 1;
  }
  else {
    *(undefined1 *)(DAT_00005d50 + 0x2a) = 0;
  }
  uVar4 = 0;
  do {
    local_28[uVar4] = '\0';
    uVar4 = uVar4 + 1 & 0xff;
  } while (uVar4 < 0x14);
  local_28[0] = 'a';
  cVar1 = *(char *)(iVar2 + 0x2a);
  local_28[1] = cVar1 + '0';
  if (cVar1 != '\0') {
    if (cVar1 == '\x01') {
      local_28[2] = 9;
      local_28[3] = *DAT_00005dc0;
      local_28[4] = *DAT_00005dc4;
      local_28[5] = (byte)((ushort)*(undefined2 *)(DAT_00005dc0 + 2) >> 8);
      local_28[6] = (char)*(undefined2 *)(DAT_00005dc0 + 2);
      local_28[7] = (char)((ushort)*(undefined2 *)(DAT_00005dc0 + 4) >> 8);
      local_28[8] = (char)*(undefined2 *)(DAT_00005dc0 + 4);
      local_28[9] = DAT_00005dc0[6];
      local_28[10] = DAT_00005dc0[8];
      local_28[0xb] = DAT_00005dc0[7];
    }
    goto LAB_00005d0e;
  }
  local_28[2] = 10;
  local_28[3] = *DAT_00005d54 << 4 | *DAT_00005d58;
  if (*DAT_00005d5c != '\0') {
    local_28[4] = local_28[4] | 1;
  }
  if (*(char *)(iVar2 + 0x19) != '\0') {
    local_28[4] = local_28[4] | 8;
  }
  if (*DAT_00005d60 != '\0') {
    local_28[4] = local_28[4] | 0x80;
  }
  if (*DAT_00005d64 == '\0') {
    local_28[5] = local_28[5] | 0x80;
  }
  if (*DAT_00005d68 != '\0') {
    local_28[5] = local_28[5] | 0x40;
  }
  if (*DAT_00005d6c != '\0') {
    local_28[5] = local_28[5] | 0x20;
  }
  if (*DAT_00005d70 != '\0') {
    local_28[5] = local_28[5] | 8;
  }
  if (*DAT_00005d74 != '\0') {
    local_28[5] = local_28[5] | 4;
  }
  sVar3 = FUN_00002a60((int)*DAT_00005d78,10);
  if (sVar3 < 0) {
    sVar3 = 0;
  }
  else if (0xff < sVar3) {
    sVar3 = 0xff;
  }
  local_28[6] = (char)sVar3;
  sVar3 = *DAT_00005d7c;
  if (sVar3 < 0) {
    sVar3 = 0;
  }
  else if (200 < sVar3) {
    sVar3 = 200;
  }
  local_28[7] = (char)sVar3;
  if (*(char *)(iVar2 + 3) == '\0') {
    if (*DAT_00005d80 != '\0') {
      local_28[8] = 0x11;
      goto LAB_00005c76;
    }
    if (*DAT_00005d84 != '\0') {
      local_28[8] = 0x12;
      goto LAB_00005c76;
    }
    if (*DAT_00005d88 != '\0') {
      local_28[8] = 0x18;
      goto LAB_00005c76;
    }
    if (*DAT_00005d8c != '\0') {
      local_28[8] = 0x21;
      goto LAB_00005c76;
    }
    if (*DAT_00005d90 != '\0') {
      local_28[8] = 0x24;
      goto LAB_00005c76;
    }
    if ((*DAT_00005d94 & 7) != 0) {
      local_28[8] = 0x28;
      goto LAB_00005c76;
    }
    if ((*DAT_00005d94 & 0x3f) >> 3 != 0) {
      local_28[8] = 0x29;
      goto LAB_00005c76;
    }
    if (*DAT_00005d98 != '\0') {
      local_28[8] = 0x40;
      goto LAB_00005c76;
    }
    if (*DAT_00005d9c != '\0') {
      local_28[8] = 0x45;
      goto LAB_00005c76;
    }
    if (*(char *)(iVar2 + 2) != '\0') {
      local_28[8] = 0x49;
      goto LAB_00005c76;
    }
    if (*DAT_00005da0 != '\0') {
      local_28[8] = 2;
      goto LAB_00005c76;
    }
    local_28[8] = 1;
  }
  else {
    local_28[8] = 0x10;
LAB_00005c76:
  }
  sVar3 = *(short *)((int)DAT_00005da4 + DAT_00005da8);
  if (*DAT_00005da4 < 0) {
    sVar3 = -sVar3;
  }
  local_28[9] = (byte)((ushort)sVar3 >> 8);
  local_28[10] = (byte)sVar3;
  if ((((*DAT_00005dac != '\0') || (*DAT_00005db0 != '\0')) || (*DAT_00005db4 != '\0')) ||
     (*DAT_00005db8 != '\0')) {
    local_28[0xb] = local_28[0xb] | 8;
  }
  if (*DAT_00005dbc != '\0') {
    local_28[0xc] = local_28[0xc] | 0x20;
  }
  local_28[0xc] = local_28[0xc] | *(byte *)(iVar2 + 8) & 0xf;
LAB_00005d0e:
  for (uVar4 = 0; uVar4 < (byte)local_28[2] + 3; uVar4 = uVar4 + 1 & 0xff) {
    cVar5 = local_28[uVar4] + cVar5;
  }
  local_28[uVar4] = cVar5;
  uVar4 = uVar4 + 1 & 0xff;
  local_28[uVar4] = -1 - local_28[0];
  FUN_00009098(local_28,uVar4 + 1 & 0xff);
  if (*(byte *)(iVar2 + 0x1c) < 10) {
    *(byte *)(iVar2 + 0x1c) = *(byte *)(iVar2 + 0x1c) + 1;
  }
  else {
    *(undefined1 *)(iVar2 + 3) = 1;
  }
  return;
}



/* ===== FUN_00005dc8 @ 0x5DC8 ===== */

void __stdcall_softfp FUN_00005dc8(void)

{
  short *psVar1;
  int iVar2;
  undefined2 uVar3;
  undefined4 uVar4;
  int iVar5;
  
  iVar2 = DAT_00005e24;
  psVar1 = DAT_00005e20;
  iVar5 = (int)(short)(*DAT_00005e20 - *(short *)(DAT_00005e24 + 0x14));
  if (iVar5 < 0) {
    iVar5 = 0;
  }
  else if (0x28 < iVar5) {
    iVar5 = 0x28;
  }
  uVar4 = FUN_00003970((int)*DAT_00005e20);
  FUN_0000a170(DAT_00005e28,uVar4);
  uVar3 = FUN_000038dc();
  *(undefined2 *)(iVar2 + 0x14) = uVar3;
  if (*DAT_00005e2c < 0) {
    *(short *)(iVar2 + 0x14) = *psVar1;
  }
  uVar4 = FUN_00003970(iVar5);
  FUN_0000a170(DAT_00005e30,uVar4);
  uVar3 = FUN_000038dc();
  *(undefined2 *)(iVar2 + 6) = uVar3;
  return;
}



/* ===== FUN_00005e34 @ 0x5E34 ===== */

void __stdcall_softfp FUN_00005e34(void)

{
  int iVar1;
  
  iVar1 = DAT_00005e50;
  *(undefined2 *)(DAT_00005e50 + 0x10) = *(undefined2 *)(DAT_00005e50 + 10);
  *(short *)(iVar1 + 0x12) =
       (short)(DAT_00005e54 * (*(short *)(iVar1 + 0xc) * 2 + (int)*(short *)(iVar1 + 10)) >> 0xf);
  return;
}



/* ===== FUN_00005e58 @ 0x5E58 ===== */

void __stdcall_softfp FUN_00005e58(void)

{
  int iVar1;
  short *psVar2;
  short *psVar3;
  
  FUN_0000a150((int)*DAT_00005ea0);
  psVar3 = DAT_00005eac;
  psVar2 = DAT_00005ea8;
  iVar1 = DAT_00005ea4;
  *(short *)(DAT_00005ea4 + 0x14) =
       (short)((int)*DAT_00005ea8 * (int)*(short *)(DAT_00005ea4 + 6) -
               (int)*DAT_00005eac * (int)*(short *)(DAT_00005ea4 + 4) >> 0xf);
  *(short *)(iVar1 + 0x16) =
       (short)((int)*psVar2 * (int)*(short *)(iVar1 + 4) + (int)*psVar3 * (int)*(short *)(iVar1 + 6)
              >> 0xf);
  return;
}



/* ===== FUN_00005eb0 @ 0x5EB0 ===== */

void __stdcall_softfp FUN_00005eb0(void)

{
  int iVar1;
  short *psVar2;
  short *psVar3;
  
  psVar3 = DAT_00005ef8;
  psVar2 = DAT_00005ef4;
  iVar1 = DAT_00005ef0;
  *(short *)(DAT_00005ef0 + 0x1a) =
       (short)((int)*DAT_00005ef4 * (int)*(short *)(DAT_00005ef0 + 0x12) -
               (int)*DAT_00005ef8 * (int)*(short *)(DAT_00005ef0 + 0x10) >> 0xf);
  *(short *)(iVar1 + 0x18) =
       (short)((int)*psVar2 * (int)*(short *)(iVar1 + 0x10) +
               (int)*psVar3 * (int)*(short *)(iVar1 + 0x12) >> 0xf);
  return;
}



/* ===== FUN_00005efc @ 0x5EFC ===== */

bool __stdcall_softfp FUN_00005efc(uint *param_1,uint param_2)

{
  uint uVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar2 = DAT_00005f6c;
  uVar1 = DAT_00005f68;
  *DAT_00005f6c = DAT_00005f68;
  *(undefined4 *)(DAT_00005f74 + 0x28) = DAT_00005f70;
  iVar3 = DAT_00005f74;
  iVar4 = DAT_00005f74 + 0x40;
  *(undefined4 *)(DAT_00005f74 + 0x54) = DAT_00005f78;
  puVar6 = (uint *)(iVar4 >> 0xd);
  if (*puVar2 == uVar1) {
    puVar5 = (uint *)(*puVar2 ^ DAT_00005f7c ^ DAT_00005f80);
    *puVar5 = *puVar5 & DAT_00005f84;
    puVar6[1] = (uint)param_1;
    *puVar5 = *puVar5 | (int)puVar6 << 10;
    *puVar2 = 0;
    puVar6[2] = param_2;
  }
  *puVar6 = *puVar6 & DAT_00005f88;
  *puVar2 = 0;
  *(undefined4 *)(iVar3 + 0x54) = 0;
  *(undefined4 *)(DAT_00005f74 + 0x28) = 0;
  return *param_1 == puVar6[3];
}



/* ===== FUN_00005f8c @ 0x5F8C ===== */

void __stdcall_softfp FUN_00005f8c(void)

{
  *(undefined4 *)(DAT_00005fa4 + 0x28) = DAT_00005fa0;
  DAT_40000010 = 0;
  DAT_40000018 = 0;
  return;
}



/* ===== FUN_00005fa8 @ 0x5FA8 ===== */

void __stdcall_softfp FUN_00005fa8(void)

{
  short *psVar1;
  short sVar2;
  int iVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  int iVar6;
  short sVar7;
  
  iVar3 = DAT_0000602c;
  psVar1 = (short *)(DAT_0000602c + 0x18);
  *(short *)(DAT_0000602c + 0x1e) = -*psVar1;
  sVar7 = -*psVar1 >> 3;
  *(short *)(iVar3 + 0x22) = sVar7;
  sVar2 = (*(short *)(iVar3 + 8) - *(short *)(iVar3 + 0x18)) * 3;
  *(short *)(iVar3 + 0x20) = sVar2;
  *(undefined2 *)(iVar3 + 8) = *(undefined2 *)(iVar3 + 0x18);
  *(short *)(iVar3 + 6) = sVar7 + sVar2 + *(short *)(iVar3 + 6);
  iVar6 = DAT_00006030;
  if (DAT_00006030 <= *(short *)(iVar3 + 6)) {
    iVar6 = -DAT_00006030;
    if (*(short *)(iVar3 + 6) <= iVar6) goto LAB_00005fe6;
  }
  *(short *)(iVar3 + 6) = (short)iVar6;
LAB_00005fe6:
  uVar5 = FUN_00003970((int)*(short *)(iVar3 + 6));
  FUN_0000a170(DAT_00006034,uVar5);
  uVar4 = FUN_000038dc();
  *(undefined2 *)(iVar3 + 6) = uVar4;
  if (DAT_00006038 - (int)*(short *)(iVar3 + 6) * (int)*(short *)(iVar3 + 6) < 1) {
    iVar6 = 0;
  }
  else {
    iVar6 = FUN_000086e0();
  }
  if ((iVar6 < *(short *)(iVar3 + 4)) || (iVar6 = -iVar6, *(short *)(iVar3 + 4) < iVar6)) {
    *(short *)(iVar3 + 4) = (short)iVar6;
  }
  return;
}



/* ===== power_down_irq_Handler @ 0x603C ===== */

void __stdcall_softfp power_down_irq_Handler(void)

{
  FUN_00007c2c();
  return;
}



/* ===== FUN_00006044 @ 0x6044 ===== */

void __stdcall_softfp FUN_00006044(void)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  short *psVar4;
  short *psVar5;
  ushort *puVar6;
  short sVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined4 in_r3;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  
  pcVar2 = DAT_000062d8;
  iVar10 = 0;
  uVar8 = 0;
  do {
    iVar10 = *(short *)(DAT_000062d4 + uVar8 * 2) + iVar10;
    uVar8 = uVar8 + 1 & 0xff;
  } while (uVar8 < 4);
  *(short *)(DAT_000062d8 + 4) = (short)(iVar10 >> 6) - *(short *)(DAT_000062d8 + 0x10);
  psVar5 = DAT_000062e0;
  psVar4 = DAT_000062dc;
  pcVar3 = DAT_000062d8;
  if (((int)(uint)*(ushort *)(pcVar2 + 0x12) < (int)*(short *)(pcVar2 + 4)) ||
     (DAT_000062e4 < *DAT_000062e0)) {
    *DAT_000062d8 = '\x01';
    if (*(short *)(pcVar3 + 4) < 0x2ac) {
      iVar10 = 4;
      iVar15 = 1;
      uVar12 = 10;
      uVar8 = 0x1e;
    }
    else {
      iVar10 = 2;
      iVar15 = 3;
      uVar12 = 0x1e;
      uVar8 = 0x3c;
    }
    if ((int)(uint)*(ushort *)(DAT_000062d8 + 0x12) < (int)*(short *)(DAT_000062d8 + 4)) {
      uVar9 = (int)((int)*(short *)(DAT_000062d8 + 4) - (uint)*(ushort *)(DAT_000062d8 + 0x12)) >>
              iVar10 & 0xffff;
    }
    else {
      uVar9 = 0;
    }
    iVar14 = (int)*(short *)((int)DAT_000062e0 + DAT_000062e8);
    iVar13 = DAT_000062e4;
    if (DAT_000062e4 < *DAT_000062e0) {
LAB_000060fc:
      iVar14 = iVar14 - iVar13;
LAB_000060fe:
      uVar9 = (iVar14 >> iVar10) + uVar9 & 0xffff;
    }
    else if (iVar14 < DAT_000062ec) {
      iVar14 = (int)*(short *)((int)DAT_000062e0 + DAT_000062e8);
      iVar13 = DAT_000062ec;
      if (DAT_000062ec - *DAT_000062e0 < 0) goto LAB_000060fc;
      iVar14 = DAT_000062ec - iVar14;
      goto LAB_000060fe;
    }
    if ((int)*(short *)(DAT_000062d8 + 10) < (int)*(short *)(DAT_000062d8 + 4)) {
      uVar11 = (uint)*(ushort *)(DAT_000062d8 + 4) - (int)*(short *)(DAT_000062d8 + 10) << iVar15 &
               0xffff;
      if (uVar12 < uVar11) {
        uVar11 = uVar12;
      }
    }
    else {
      uVar11 = 0;
    }
    uVar12 = uVar9 + uVar11 & 0xffff;
    if (uVar12 == 0) {
      uVar12 = 1;
    }
    else if (uVar8 < uVar12) {
      uVar12 = uVar8;
    }
    if ((int)*psVar4 < (int)-uVar12) {
      sVar7 = *psVar4 + (short)uVar12;
    }
    else {
      if ((int)*psVar4 <= (int)uVar12) {
        *psVar4 = 0;
        goto LAB_0000619e;
      }
      sVar7 = *psVar4 - (short)uVar12;
    }
LAB_00006154:
    *psVar4 = sVar7;
  }
  else {
    *DAT_000062d8 = '\0';
    if ((*DAT_000062f0 != '\0') &&
       (((*(short *)(pcVar3 + 4) < *(short *)(pcVar3 + 6) || (*psVar5 < *(short *)(pcVar3 + 8))) ||
        ((*(ushort *)(DAT_000062f4 + 0x1c) < *DAT_000062f8 &&
         ((*DAT_000062fc == '\0' && (*DAT_00006300 == '\0')))))))) {
      iVar10 = DAT_000062ec - *psVar5;
      if (iVar10 < 0) {
        uVar8 = *psVar5 - DAT_000062ec;
      }
      else {
        iVar10 = (int)*psVar5;
        uVar8 = DAT_000062ec - iVar10;
      }
      uVar8 = (uVar8 & 0x3ffff) >> 2;
      if (uVar8 == 0) {
        uVar8 = 1;
      }
      else if (0x14 < uVar8) {
        uVar8 = 0x14;
      }
      *pcVar3 = '\x01';
      sVar7 = FUN_00009e50((int)*psVar4,0,uVar8,iVar10,in_r3);
      goto LAB_00006154;
    }
  }
LAB_0000619e:
  pcVar3 = DAT_00006304;
  pcVar2 = DAT_000062d8;
  *(undefined2 *)(DAT_000062d8 + 10) = *(undefined2 *)(DAT_000062d8 + 4);
  if (*pcVar3 == '\0') {
    pcVar2[0xe] = '\0';
    pcVar2[0xf] = '\0';
  }
  else {
    sVar7 = *(short *)(pcVar2 + 0xe);
    if (sVar7 == 0) {
      pcVar2[0xc] = '\n';
      pcVar2[0xd] = '\0';
    }
    *(short *)(pcVar2 + 0xe) = sVar7 + 1;
    if (2000 < (ushort)(sVar7 + 1U)) {
      pcVar2[0xe] = -0x30;
      pcVar2[0xf] = '\a';
      cVar1 = pcVar2[1];
      pcVar2[1] = cVar1 + 1U;
      if (2 < (byte)(cVar1 + 1U)) {
        pcVar2[1] = '\0';
        if (*(short *)(pcVar2 + 0xc) < DAT_000062e4) {
          *(short *)(pcVar2 + 0xc) = *(short *)(pcVar2 + 0xc) + 1;
        }
      }
    }
  }
  if (*pcVar3 != '\0') {
    *pcVar2 = '\x01';
    if (*(short *)(pcVar2 + 0xc) < *DAT_000062e0) {
      if (*psVar4 < 1) goto LAB_00006260;
      sVar7 = *psVar4 + -1;
    }
    else {
      if ((-1 < *DAT_000062e0) || (DAT_00006308 <= *psVar4)) goto LAB_00006260;
      sVar7 = *psVar4 + 1;
    }
    *psVar4 = sVar7;
  }
LAB_00006260:
  if (*pcVar2 == '\0') {
    sVar7 = FUN_00009e50((int)*psVar4,(int)*(short *)(pcVar2 + 2),3);
    *psVar4 = sVar7;
  }
  else if (*DAT_000062f0 == '\0') {
    *(short *)(pcVar2 + 2) = *psVar4;
  }
  psVar4 = DAT_0000630c;
  sVar7 = FUN_00002a60((int)*DAT_000062e0 - (int)*DAT_0000630c,0x14);
  *psVar4 = sVar7 + *psVar4;
  puVar6 = DAT_000062f8;
  iVar10 = 0;
  uVar8 = 0;
  do {
    iVar10 = *(short *)(DAT_00006310 + uVar8 * 2) + iVar10;
    uVar8 = uVar8 + 1 & 0xff;
  } while (uVar8 < 4);
  *DAT_000062f8 = (ushort)(iVar10 >> 6);
  if (DAT_00006308 + 0x34U < (uint)*puVar6) {
    *DAT_00006314 = 1;
    *DAT_00006318 = 0;
    FUN_00004a98();
  }
  return;
}



/* ===== cruise_control_state_update @ 0x63B0 ===== */

/* Periodic cruise-control state machine; identity validated by scheduler cross-reference. */

void __stdcall_softfp cruise_control_state_update(void)

{
  byte bVar1;
  short sVar2;
  short sVar3;
  undefined2 uVar4;
  ushort *puVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  short *psVar9;
  char *pcVar10;
  uint uVar11;
  uint uVar12;
  ushort uVar13;
  uint uVar14;
  int iVar15;
  
  iVar7 = DAT_00006628;
  iVar6 = DAT_00006624;
  uVar11 = 0;
  uVar14 = 0;
  bVar1 = *(byte *)(DAT_00006624 + 0xe);
  *(ushort *)(DAT_00006628 + (uint)bVar1 * 2) = *DAT_00006620;
  uVar12 = bVar1 + 1;
  *(char *)(iVar6 + 0xe) = (char)uVar12;
  if (7 < (uVar12 & 0xff)) {
    *(undefined1 *)(iVar6 + 0xe) = 0;
  }
  do {
    piVar8 = DAT_0000662c;
    iVar15 = uVar11 * 2;
    uVar11 = uVar11 + 1 & 0xff;
    uVar14 = *(ushort *)(iVar7 + iVar15) + uVar14 & 0xffff;
  } while (uVar11 < 8);
  uVar14 = uVar14 >> 3;
  uVar4 = (undefined2)uVar14;
  *(undefined2 *)(iVar6 + 0x26) = uVar4;
  psVar9 = DAT_00006634;
  if ((*piVar8 == DAT_00006630) ||
     (((*(char *)(iVar6 + 9) == '\0' ||
       (((*DAT_00006638 < -5 && (*DAT_0000663c == '\0')) || (0x103 < *DAT_00006634)))) &&
      (*(char *)(iVar6 + 8) == '\0')))) {
    *(undefined1 *)(iVar6 + 8) = 0;
    *(undefined2 *)(iVar6 + 0x12) = 0;
    return;
  }
  if (((*(char *)(iVar6 + 8) == '\0') && (10 < uVar14)) && (0x14 < *DAT_00006634)) {
    *(short *)(iVar6 + 0x18) = (short)(uVar14 + 10);
    *(short *)(iVar6 + 0x1a) = (short)(uVar14 - 10);
    sVar2 = *psVar9;
    *(ushort *)(iVar6 + 0x1e) = sVar2 + 0x14U;
    sVar3 = *psVar9;
    *(ushort *)(iVar6 + 0x20) = sVar3 - 0x14U;
    if ((((uint)*(ushort *)(iVar6 + 0x1c) < uVar14 + 10) &&
        ((uVar14 - 10 & 0xffff) < (uint)*(ushort *)(iVar6 + 0x1c))) &&
       ((*(ushort *)(iVar6 + 0x22) < (ushort)(sVar2 + 0x14U) &&
        (((((ushort)(sVar3 - 0x14U) < *(ushort *)(iVar6 + 0x22) && (*DAT_00006640 == '\0')) &&
          (*DAT_00006644 == '\0')) && (*DAT_00006648 != '\0')))))) {
      if (*(ushort *)(iVar6 + 0x28) < 2) {
        *(undefined2 *)(iVar6 + 0x24) = uVar4;
      }
      else if ((*(ushort *)(iVar6 + 0x24) + 10 < uVar14) ||
              ((int)uVar14 < (int)(*(ushort *)(iVar6 + 0x24) - 10))) {
        *(undefined1 *)(iVar6 + 0x11) = 0;
        *(undefined2 *)(iVar6 + 0x28) = 0;
      }
      if (*(ushort *)(iVar6 + 0x2a) < 2) {
        *(short *)(iVar6 + 0x2c) = *psVar9;
      }
      else if (((int)(*(ushort *)(iVar6 + 0x2c) + 0x14) < (int)*psVar9) ||
              ((int)*psVar9 < (int)(*(ushort *)(iVar6 + 0x2c) - 0x14))) {
        *(undefined1 *)(iVar6 + 0x10) = 0;
        *(undefined2 *)(iVar6 + 0x2a) = 0;
      }
      uVar13 = *(short *)(iVar6 + 0x28) + 1;
      *(ushort *)(iVar6 + 0x28) = uVar13;
      if (500 < uVar13) {
        *(undefined1 *)(iVar6 + 0x11) = 1;
        *(undefined2 *)(iVar6 + 0x28) = 0;
      }
      uVar13 = *(short *)(iVar6 + 0x2a) + 1;
      *(ushort *)(iVar6 + 0x2a) = uVar13;
      if (uVar13 < 0x12d) {
        if (*(char *)(iVar6 + 0x10) != '\x01') goto LAB_00006532;
      }
      else {
        *(undefined1 *)(iVar6 + 0x10) = 1;
        *(undefined2 *)(iVar6 + 0x2a) = 0;
      }
      puVar5 = DAT_00006650;
      if (((*(char *)(iVar6 + 0x11) == '\x01') && (0x1c < *DAT_0000664c)) && (10 < *DAT_00006650)) {
        *(undefined1 *)(iVar6 + 0x10) = 0;
        *(undefined1 *)(iVar6 + 0x11) = 0;
        *(undefined1 *)(iVar6 + 8) = 1;
        *(undefined1 *)(iVar6 + 0xd) = 0;
        *(ushort *)(iVar6 + 0x12) = *puVar5;
      }
    }
    else {
      *(undefined2 *)(iVar6 + 0x28) = 0;
      *(undefined2 *)(iVar6 + 0x2a) = 0;
      *(undefined1 *)(iVar6 + 0x10) = 0;
      *(undefined1 *)(iVar6 + 0x11) = 0;
    }
  }
  else {
    *(undefined2 *)(iVar6 + 0x28) = 0;
  }
LAB_00006532:
  *(undefined2 *)(iVar6 + 0x1c) = uVar4;
  *(short *)(iVar6 + 0x22) = *psVar9;
  pcVar10 = DAT_00006654;
  puVar5 = DAT_00006620;
  if (*(char *)(iVar6 + 8) == '\0') goto LAB_00006618;
  if (*DAT_00006620 < 5) {
    *(undefined1 *)(iVar6 + 0xd) = 1;
LAB_00006552:
    if (0xf < *puVar5) {
      *(undefined1 *)(iVar6 + 0xd) = 0;
      *(undefined1 *)(iVar6 + 8) = 0;
      *(undefined2 *)(iVar6 + 0x12) = 0;
    }
  }
  else if (*(char *)(iVar6 + 0xd) != '\0') goto LAB_00006552;
  if (((int)(uint)*(ushort *)(iVar6 + 0x24) < (int)(*puVar5 - 10)) && (10 < *puVar5)) {
    *(undefined1 *)(iVar6 + 0xd) = 0;
    *(undefined1 *)(iVar6 + 8) = 0;
    *(undefined2 *)(iVar6 + 0x12) = 0;
  }
  if ((((((*DAT_00006658 != '\0') || (*DAT_0000665c != '\0')) ||
        ((*DAT_00006660 != '\0' ||
         (((*DAT_00006664 != '\0' || (*DAT_00006668 != '\0')) || (*DAT_0000666c != '\0')))))) ||
       ((*DAT_00006670 != '\0' || (*DAT_00006674 != '\0')))) || (*DAT_00006678 != '\0')) ||
     ((((*DAT_0000667c != '\0' || (*DAT_00006680 != '\0')) ||
       ((*DAT_00006684 != '\0' || (*DAT_00006688 != '\0')))) ||
      (((((((int)((uint)*(byte *)(DAT_0000668c + 7) << 0x1a) < 0 ||
           ((*(byte *)(DAT_0000668c + 7) & 7) >> 1 != 0)) && (*DAT_0000663c == '\0')) ||
         ((*DAT_00006690 != '\0' || (*DAT_00006644 != '\0')))) || (*DAT_00006640 != '\0')) ||
       (*(char *)(iVar6 + 0xf) != *pcVar10)))))) {
    *(undefined1 *)(iVar6 + 0xd) = 0;
    *(undefined1 *)(iVar6 + 8) = 0;
    *(undefined2 *)(iVar6 + 0x12) = 0;
  }
LAB_00006618:
  *(char *)(iVar6 + 0xf) = *pcVar10;
  return;
}



/* ===== ride_mode_and_speed_target_update @ 0x67AC ===== */

/* Periodic mode and target-speed update; modes 1 2 3 and 11 observed. */

void __stdcall_softfp
ride_mode_and_speed_target_update
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  char *pcVar2;
  undefined4 *puVar3;
  short *psVar4;
  char *pcVar5;
  undefined2 *puVar6;
  undefined2 uVar7;
  ushort uVar8;
  byte bVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  bVar9 = 0;
  if (*(ushort *)(DAT_00006a58 + 0xc) - 6 < 0x5f) {
    uVar7 = FUN_00002a60((uint)*(ushort *)(DAT_00006a58 + 0xc) * (uint)*DAT_00006a5c,100,param_3,
                         param_4,param_4);
    *DAT_00006a60 = uVar7;
LAB_00006992:
    if (DAT_00006a58[4] != '\0') goto LAB_0000699a;
LAB_000069ba:
    *DAT_00006a60 = 0;
    *DAT_00006a64 = '\0';
  }
  else {
    if (*DAT_00006a64 == '\0') {
      *DAT_00006a60 = 0;
    }
    else {
      *DAT_00006a60 = *DAT_00006a68;
    }
    if (DAT_00006a58[3] == '\0') {
      if ((((DAT_00006a70 < *DAT_00006a6c) &&
           ((int)*DAT_00006a74 + (int)*DAT_00006a78 + (int)*DAT_00006a7c < 0x3c)) &&
          (*DAT_00006a80 == '\0')) && (*DAT_00006a84 == '\0')) {
        *DAT_00006a88 = 0;
        *DAT_00006a8c = *DAT_00006a8c & 0xf8;
        puVar3 = DAT_00006a90;
        if ((byte)DAT_00006a58[2] < 0x32) {
          DAT_00006a58[2] = DAT_00006a58[2] + 1;
        }
        else {
          DAT_00006a90[4] = 0;
          puVar3[5] = 0;
          puVar3[2] = 0;
          puVar3[3] = 0;
          *puVar3 = 0;
          puVar3[1] = 0;
          FUN_00004b1c();
          pcVar2 = DAT_00006a94;
          do {
            do {
            } while (*pcVar2 == '\0');
            *pcVar2 = '\0';
            psVar4 = DAT_00006a98;
            bVar9 = bVar9 + 1;
          } while (bVar9 < 3);
          iVar12 = 0;
          iVar11 = 0;
          iVar10 = 0;
          bVar9 = 0;
          do {
            iVar12 = iVar12 + *psVar4;
            iVar11 = iVar11 + *DAT_00006a9c;
            iVar10 = iVar10 + *DAT_00006aa0;
            do {
            } while (*DAT_00006a94 == '\0');
            *DAT_00006a94 = '\0';
            bVar9 = bVar9 + 1;
          } while (bVar9 < 0x10);
          FUN_00004a98();
          *DAT_00006aa4 = (short)(iVar12 >> 4);
          *DAT_00006aa8 = (short)(iVar11 >> 4);
          *DAT_00006aac = (short)(iVar10 >> 4);
          DAT_00006a58[3] = '\x01';
        }
        if ((500 < *DAT_00006aa4) || (*DAT_00006aa4 < -500)) {
          *DAT_00006a8c = *DAT_00006a8c | 1;
        }
        if ((500 < *DAT_00006aa8) || (*DAT_00006aa8 < -500)) {
          *DAT_00006a8c = *DAT_00006a8c | 2;
        }
        if ((500 < *DAT_00006aac) || (*DAT_00006aac < -500)) {
          *DAT_00006a8c = *DAT_00006a8c | 4;
        }
        if (*DAT_00006a8c != 0) {
          FUN_00004a98();
        }
        *DAT_00006a88 = 1;
      }
      else {
        DAT_00006a58[2] = '\0';
      }
    }
    pcVar2 = DAT_00006a58;
    DAT_00006a58[4] = '\x01';
    if ((*DAT_00006a64 == '\0') && (*DAT_00006ab0 == '\0')) {
      *DAT_00006ab4 = 0;
      *DAT_00006ab8 = 0;
      if ((*DAT_00006abc != '\0') && (*DAT_00006abc != '\a')) {
        *DAT_00006ac0 = 0;
      }
      pcVar5 = DAT_00006ac4;
      if ((((*DAT_00006ac4 != '\0') && (*DAT_00006a84 == '\0')) && (*DAT_00006ac8 == 0)) &&
         (((*DAT_00006a80 == '\0' && (bVar9 = pcVar2[6], bVar9 < 8)) && (*DAT_00006acc == '\0')))) {
        pcVar2[6] = bVar9 + 1;
        FUN_00006c60();
        *pcVar5 = '\0';
        goto LAB_00006992;
      }
    }
LAB_0000699a:
    if (((*DAT_00006a58 == '\x01') || (*DAT_00006ad0 == '\0')) ||
       ((*DAT_00006ad4 == '\x01' || (*DAT_00006ad8 != '\0')))) goto LAB_000069ba;
  }
  puVar6 = DAT_00006ae0;
  pcVar2 = DAT_00006a58;
  if (DAT_00006a58[5] == DAT_00006a58[1]) {
    *DAT_00006ae4 = 0;
    goto LAB_00006a50;
  }
  cVar1 = DAT_00006a58[1];
  if (cVar1 == '\x01') {
LAB_000069e8:
    *DAT_00006adc = 0x112;
    pcVar2[0xe] = 'g';
    pcVar2[0xf] = '\0';
  }
  else {
    if (cVar1 == '\x02') {
      *DAT_00006adc = 0x148;
      uVar7 = *puVar6;
    }
    else if (cVar1 == '\x03') {
      *DAT_00006adc = 0x1ed;
      uVar7 = puVar6[1];
    }
    else {
      if (cVar1 != '\v') goto LAB_000069e8;
      *DAT_00006adc = 0x89;
      uVar7 = 0x3e;
    }
    *(undefined2 *)(pcVar2 + 0xe) = uVar7;
  }
  if ((byte)pcVar2[7] < 5) {
    pcVar2[7] = pcVar2[7] + 1;
  }
  else {
    pcVar2[7] = '\0';
    uVar8 = *(ushort *)(pcVar2 + 0xe);
    if (*DAT_00006a5c < uVar8) {
      uVar8 = *DAT_00006a5c + 1;
    }
    else if (uVar8 < *DAT_00006a5c) {
      uVar8 = *DAT_00006a5c - 1;
    }
    *DAT_00006a5c = uVar8;
  }
  if ((*DAT_00006a5c == *(ushort *)(pcVar2 + 0xe)) || (*(short *)(pcVar2 + 0xc) == 0)) {
    *DAT_00006a5c = *(ushort *)(pcVar2 + 0xe);
    pcVar2[5] = pcVar2[1];
  }
LAB_00006a50:
  *(undefined2 *)(pcVar2 + 8) = *(undefined2 *)(pcVar2 + 10);
  return;
}



/* ===== kick_start_state_update @ 0x6AE8 ===== */

/* Uses signed wheel speed and two hysteresis thresholds. */

void __stdcall_softfp kick_start_state_update(void)

{
  char *pcVar1;
  short *psVar2;
  
  psVar2 = DAT_00006b9c;
  pcVar1 = DAT_00006b98;
  if (DAT_00006b98[1] == '\0') {
LAB_00006b28:
    *DAT_00006b98 = '\x01';
  }
  else if (*DAT_00006b98 == '\0') {
    if (((0x32 < *DAT_00006b9c) && ((ushort)*(byte *)(DAT_00006ba0 + 0xd) == *DAT_00006ba4)) &&
       (*DAT_00006ba8 == 0)) goto LAB_00006b28;
  }
  else if (*DAT_00006b9c < 0x1e) {
    if (*(ushort *)(DAT_00006b98 + 0x16) < 0x14) {
      *(ushort *)(DAT_00006b98 + 0x16) = *(ushort *)(DAT_00006b98 + 0x16) + 1;
    }
    else {
      *DAT_00006b98 = '\0';
    }
  }
  else {
    pcVar1[0x16] = '\0';
    pcVar1[0x17] = '\0';
  }
  if (pcVar1[3] == '\0') {
    pcVar1[4] = '\0';
  }
  else if ((pcVar1[4] == '\0') && (*psVar2 < 0x14)) {
    pcVar1[4] = '\x01';
  }
  if (pcVar1[4] == '\0') {
    pcVar1[5] = '\0';
    pcVar1[0x14] = '\0';
    pcVar1[0x15] = '\0';
LAB_00006b72:
    pcVar1[0x2e] = '\0';
    pcVar1[0x2f] = '\0';
  }
  else {
    if (pcVar1[5] == '\0') {
      if ((2 < *(short *)(pcVar1 + 0x2e)) || (*(short *)(pcVar1 + 0x2e) < -2)) {
        pcVar1[5] = '\x01';
      }
    }
    else if (DAT_00006bb0 <= *DAT_00006bac) {
      if (*(ushort *)(pcVar1 + 0x14) < 300) {
        *(ushort *)(pcVar1 + 0x14) = *(ushort *)(pcVar1 + 0x14) + 1;
        goto LAB_00006b8a;
      }
      pcVar1[5] = '\0';
      goto LAB_00006b72;
    }
    pcVar1[0x14] = '\0';
    pcVar1[0x15] = '\0';
  }
LAB_00006b8a:
  FUN_000054b8();
  return;
}



/* ===== FUN_00006bb4 @ 0x6BB4 ===== */

void __stdcall_softfp FUN_00006bb4(void)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  
  iVar1 = DAT_00006bec;
  bVar2 = *(char *)(DAT_00006bec + 10) + 1;
  *(byte *)(DAT_00006bec + 10) = bVar2;
  if (0x13 < bVar2) {
    bVar2 = 0;
    *(undefined1 *)(iVar1 + 10) = 0;
  }
  if ((bVar2 < *DAT_00006bf0) && (*DAT_00006bf8 == '\0')) {
    uVar3 = *(uint *)(DAT_00006bf4 + 0xc) | 8;
  }
  else {
    uVar3 = *(uint *)(DAT_00006bf4 + 0xc) & 0xfffffff7;
  }
  *(uint *)(DAT_00006bf4 + 0xc) = uVar3;
  return;
}



/* ===== FUN_00006c60 @ 0x6C60 ===== */

void __stdcall_softfp FUN_00006c60(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  short sVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 *puVar8;
  bool bVar9;
  
  *DAT_00006d50 = 0;
  disableIRQinterrupts();
  *(undefined4 *)(DAT_00006d54 + 0x20) = 0x33;
  FUN_00004a98();
  DAT_00006d58[1] = 1;
  iVar2 = DAT_00006d5c;
  *(undefined4 *)(DAT_00006d5c + 0x14) = 0x10;
  uVar3 = DAT_00006d60;
  uVar7 = 0;
  puVar8 = (undefined4 *)(DAT_00006d5c + 0x40);
LAB_00006ca4:
  *puVar8 = uVar3;
  iVar5 = DAT_00006d64;
LAB_00006cc2:
  *(int *)(iVar2 + 0x20) = iVar5;
  uVar6 = 0xc;
LAB_00006cd8:
  do {
    *(undefined4 *)(iVar2 + 0x24) = uVar6;
    *puVar8 = DAT_00006d70;
    do {
      *puVar8 = uVar3;
      *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) | 0x40;
      *puVar8 = DAT_00006d70;
      sVar4 = 0x3c;
      do {
        bVar9 = sVar4 != 0;
        sVar4 = sVar4 + -1;
      } while (bVar9);
      FUN_00004a98();
      puVar1 = DAT_00006d58;
      if (((DAT_00006d58[1] & 1) != 0) || (*(int *)(iVar2 + 0x14) << 0x1b < 0)) {
        *DAT_00006d50 = (byte)(1 << uVar7) | *DAT_00006d50;
        puVar1[1] = 1;
        *(undefined4 *)(iVar2 + 0x14) = 0x10;
      }
      sVar4 = 0x44;
      do {
        bVar9 = sVar4 != 0;
        sVar4 = sVar4 + -1;
      } while (bVar9);
      uVar7 = uVar7 + 1 & 0xff;
      if (5 < uVar7) {
        *(undefined4 *)(DAT_00006d54 + 0x20) = 0xcb;
        *puVar8 = uVar3;
        uVar3 = DAT_00006d74;
        *(undefined4 *)(iVar2 + 0x20) = DAT_00006d74;
        *(undefined4 *)(iVar2 + 0x24) = uVar3;
        *puVar8 = DAT_00006d70;
        *DAT_00006d58 = 0;
        enableIRQinterrupts();
        return;
      }
      if (uVar7 == 0) goto LAB_00006ca4;
      if (uVar7 == 1) {
        *puVar8 = uVar3;
        iVar5 = DAT_00006d68;
        goto LAB_00006cc2;
      }
      if (uVar7 == 2) {
        *puVar8 = uVar3;
        *(int *)(iVar2 + 0x20) = DAT_00006d64 + -0x10;
        uVar6 = 0x1c;
        goto LAB_00006cd8;
      }
      if (uVar7 == 3) {
        *puVar8 = uVar3;
        iVar5 = DAT_00006d64 + 0x10;
        goto LAB_00006cc2;
      }
      if (uVar7 == 4) {
        *puVar8 = uVar3;
        iVar5 = DAT_00006d6c;
        goto LAB_00006cc2;
      }
    } while (uVar7 != 5);
    *puVar8 = uVar3;
    *(int *)(iVar2 + 0x20) = DAT_00006d64 + -0x10;
    uVar6 = 0x2c;
  } while( true );
}



/* ===== FUN_00006db0 @ 0x6DB0 ===== */

void __stdcall_softfp FUN_00006db0(void)

{
  char *pcVar1;
  char *pcVar2;
  undefined2 *puVar3;
  char *pcVar4;
  ushort *puVar5;
  ushort *puVar6;
  short *psVar7;
  char cVar8;
  undefined2 uVar9;
  short sVar10;
  ushort uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  undefined4 in_r3;
  
  pcVar1 = DAT_000071ac;
  if ((*DAT_000071a4 < DAT_000071a8) && (*DAT_000071a4 != 0)) {
    uVar9 = FUN_00002a44(DAT_000071b0,*DAT_000071a4,DAT_000071a8,in_r3,in_r3);
    *(undefined2 *)(pcVar1 + 0x24) = uVar9;
  }
  else {
    pcVar1[0x24] = '\0';
    pcVar1[0x25] = '\0';
  }
  *(undefined2 *)(pcVar1 + 0x22) = *(undefined2 *)(pcVar1 + 0x24);
  if ((ushort)*(byte *)(DAT_000071b4 + 0xd) == *DAT_000071b8) {
    uVar9 = FUN_00002a44(*(undefined2 *)(pcVar1 + 0x24),10);
  }
  else {
    uVar9 = FUN_00002a60(-(uint)*(ushort *)(pcVar1 + 0x24),10);
  }
  *(undefined2 *)(pcVar1 + 6) = uVar9;
  if (*(short *)(pcVar1 + 0xc) < *(short *)(pcVar1 + 6)) {
    cVar8 = '\x01';
  }
  else if (*(short *)(pcVar1 + 6) < *(short *)(pcVar1 + 0xc)) {
    cVar8 = -1;
  }
  else {
    cVar8 = '\0';
    pcVar1[4] = '\0';
  }
  cVar8 = pcVar1[4] + cVar8;
  pcVar1[4] = cVar8;
  if (cVar8 < '\x15') {
    if (cVar8 < -0x14) {
      pcVar1[4] = -0x14;
    }
  }
  else {
    pcVar1[4] = '\x14';
  }
  if (pcVar1[4] < '\x14') {
    if (pcVar1[4] < -0x13) {
      sVar10 = *(short *)(pcVar1 + 0xc) + -1;
      goto LAB_00006e54;
    }
  }
  else {
    sVar10 = *(short *)(pcVar1 + 0xc) + 1;
LAB_00006e54:
    *(short *)(pcVar1 + 0xc) = sVar10;
  }
  pcVar4 = DAT_000071cc;
  puVar3 = DAT_000071c4;
  pcVar2 = DAT_000071c0;
  if ((((((((*DAT_000071bc == '\0') && (*DAT_000071d0 == '\0')) && (*DAT_000071d4 == '\0')) &&
         ((*DAT_000071d8 == '\0' && (*pcVar1 == '\0')))) && (*DAT_000071dc == '\0')) &&
       (((*DAT_000071e0 == '\0' && (*DAT_000071c8 == '\0')) &&
        ((*DAT_000071e4 == '\0' &&
         (((*DAT_000071e8 == '\0' && (*DAT_000071ec == '\0')) && (*DAT_000071f0 == '\0')))))))) &&
      ((*DAT_000071f4 == '\0' && (*DAT_000071f8 == '\0')))) &&
     ((*DAT_000071fc == '\0' &&
      (((*DAT_00007200 != '\x01' && (*DAT_00007204 != '\x01')) &&
       ((-1 < (int)((uint)*(byte *)(DAT_00007208 + 7) << 0x1a) &&
        ((*(byte *)(DAT_00007208 + 7) & 7) >> 1 == 0)))))))) {
    if ((*DAT_0000720c == '\0') && (*DAT_000071cc == '\0')) {
      if (*DAT_000071c0 != '\0') {
        *(undefined2 *)(pcVar1 + 10) = *DAT_000071c4;
      }
      if ((int)(uint)*(ushort *)(pcVar1 + 10) < (int)*(short *)(pcVar1 + 6)) goto LAB_00006f40;
      if ((int)*DAT_00007214 < (int)(uint)*DAT_00007210) {
        *(short *)(pcVar1 + 0x26) =
             (short)(((uint)*DAT_00007210 - (int)*DAT_00007214 & 0x7ffff) >> 3);
      }
      uVar11 = FUN_00009e6e(*(undefined2 *)(pcVar1 + 0x26),1,0x28);
      puVar5 = DAT_00007218;
      *(ushort *)(pcVar1 + 0x26) = uVar11;
      if ((*puVar5 < DAT_0000721c) && (2 < uVar11)) {
        pcVar1[0x26] = '\x02';
        pcVar1[0x27] = '\0';
      }
      if ((int)*(short *)(pcVar1 + 6) < (int)(*(ushort *)(pcVar1 + 10) - 10)) {
        sVar10 = (short)((int)(((uint)*(ushort *)(pcVar1 + 10) - (int)*(short *)(pcVar1 + 6)) + -10)
                        >> 4);
      }
      else {
        sVar10 = 1;
      }
      *(short *)(pcVar1 + 0x28) = sVar10;
      uVar9 = FUN_00009e6e((int)sVar10,1,*(undefined2 *)(pcVar1 + 0x26));
    }
    else {
LAB_00006f40:
      uVar9 = 0xffe2;
    }
    *(undefined2 *)(pcVar1 + 0x28) = uVar9;
  }
  else {
    if (*pcVar1 == '\0') {
      if ((*DAT_000071c8 == '\0') || (*DAT_000071f4 != '\0')) {
        uVar9 = 0xffe2;
      }
      else {
        uVar9 = 0xfff4;
      }
    }
    else {
      uVar9 = 0xfffb;
    }
    *(undefined2 *)(pcVar1 + 0x28) = uVar9;
    *pcVar2 = '\0';
    *puVar3 = 0;
    pcVar1[10] = '\0';
    pcVar1[0xb] = '\0';
  }
  if ((byte)pcVar1[1] < (byte)pcVar1[2]) {
    pcVar1[1] = pcVar1[1] + 1;
  }
  else {
    pcVar1[1] = '\0';
    pcVar1[2] = pcVar1[3];
  }
  if (*(short *)(pcVar1 + 6) < 0x3d) {
    if (*(short *)(pcVar1 + 0x14) == 0) {
      pcVar1[0x14] = '\0';
      pcVar1[0x15] = '\0';
    }
    else {
      *(short *)(pcVar1 + 0x14) = *(short *)(pcVar1 + 0x14) + -1;
    }
  }
  else {
    FUN_00004b4c();
  }
  puVar6 = DAT_00007224;
  puVar5 = DAT_00007220;
  if (((*DAT_0000720c == '\0') && (*pcVar4 == '\0')) && (*DAT_000071f4 == '\0')) {
    if (*DAT_00007234 == '\0') {
      *DAT_00007224 = *(ushort *)(pcVar1 + 0xe);
      pcVar1[0x14] = '\0';
      pcVar1[0x15] = '\0';
    }
    else if (((int)*(short *)(pcVar1 + 6) < (int)(uint)*(ushort *)(pcVar1 + 10)) &&
            (*(short *)(pcVar1 + 10) != 0)) {
      if (*DAT_00007238 < 10) {
        *DAT_00007224 = *DAT_00007220;
        pcVar1[0x28] = '\x1e';
        pcVar1[0x29] = '\0';
      }
      psVar7 = DAT_0000723c;
      if (*(short *)(pcVar1 + 6) < 0) {
        uVar13 = 0;
      }
      else {
        uVar11 = *(ushort *)(pcVar1 + 6);
        if (0 < *DAT_0000723c) {
          uVar11 = uVar11 + *DAT_0000723c;
        }
        uVar13 = (uint)uVar11;
      }
      if ((int)(*(ushort *)(pcVar1 + 10) - 0x1c) < (int)uVar13) {
        if (uVar13 < *(ushort *)(pcVar1 + 10)) {
          uVar13 = (((uint)((int)(*(ushort *)(pcVar1 + 10) - uVar13) >> 0x1f) >> 0x1d) +
                    (*(ushort *)(pcVar1 + 10) - uVar13) & 0x7ffff) >> 3;
        }
        else {
          uVar13 = 0;
        }
      }
      else {
        uVar13 = (uint)*(ushort *)(pcVar1 + 0x28);
      }
      if ((int)uVar13 < (int)*(short *)(pcVar1 + 0x28)) {
        *(short *)(pcVar1 + 0x28) = (short)uVar13;
      }
      iVar12 = DAT_00007240;
      iVar14 = (int)*(short *)(pcVar1 + 0x28);
      if (((short)*puVar6 + iVar14 < DAT_00007240) && (0 < iVar14)) {
        uVar11 = *puVar6 + *(short *)(pcVar1 + 0x28);
        goto LAB_00007106;
      }
      pcVar1[3] = '\f';
      if (((pcVar1[1] == '\0') && (-1 < iVar14)) && (-1 < *psVar7)) {
        if ((int)*(short *)(pcVar1 + 6) + (int)*psVar7 < (int)(*(ushort *)(pcVar1 + 10) - 3)) {
          if (*(short *)((int)puVar6 + DAT_0000722c) < iVar12) {
            uVar11 = *puVar6 + 1;
LAB_00007106:
            *puVar6 = uVar11;
          }
        }
        else if ((0 < *(short *)((int)puVar6 + DAT_0000722c)) &&
                ((int)(uint)*(ushort *)(pcVar1 + 10) < *(short *)(pcVar1 + 6) + 1)) {
          uVar11 = *puVar6 - 1;
          goto LAB_00007106;
        }
      }
      pcVar1[0x12] = '\0';
      pcVar1[0x13] = '\0';
    }
    else {
      if ((*DAT_00007244 < 0x21c) && (0x1e < *(short *)(pcVar1 + 6))) {
        *(short *)(pcVar1 + 0x1a) =
             (short)((int)(((uint)((int)((int)*(short *)(pcVar1 + 6) -
                                        (uint)*(ushort *)(pcVar1 + 10)) >> 0x1f) >> 0x1d) +
                          ((int)*(short *)(pcVar1 + 6) - (uint)*(ushort *)(pcVar1 + 10))) >> 3);
      }
      else {
        pcVar1[0x1a] = '\0';
        pcVar1[0x1b] = '\0';
      }
      uVar9 = FUN_00009e6e((int)*(short *)(pcVar1 + 0x1a),0,10);
      *(undefined2 *)(pcVar1 + 0x1a) = uVar9;
      psVar7 = DAT_00007238;
      if (((int)-(uint)*(ushort *)(pcVar1 + 0x14) < (int)*DAT_00007238) &&
         (sVar10 = *(short *)(pcVar1 + 0x1a), 0 < sVar10)) {
LAB_0000715c:
        uVar11 = *puVar6 - sVar10;
LAB_00007174:
        *puVar6 = uVar11;
      }
      else {
        pcVar1[3] = '\x05';
        if (*psVar7 < -0x14) {
          uVar11 = *puVar6 + 1;
          goto LAB_00007174;
        }
        if ((2 < *psVar7) && (pcVar1[1] == '\0')) {
          if (*psVar7 < 0x15) {
            sVar10 = 1;
          }
          else {
            sVar10 = (short)(((int)*psVar7 & 0xfffffU) >> 4);
          }
          goto LAB_0000715c;
        }
      }
      *(undefined2 *)(pcVar1 + 8) = *(undefined2 *)(pcVar1 + 6);
    }
    if ((short)*puVar6 < 0) {
      *puVar6 = 0;
    }
  }
  else {
    if (*DAT_000071f4 != '\0') {
      iVar12 = (int)*(short *)((int)DAT_00007228 + DAT_0000722c);
      if (*DAT_00007228 < 0) {
        iVar12 = -iVar12;
      }
      if ((iVar12 < 0x14) || (*DAT_00007230 != '\0')) {
        *DAT_00007230 = '\x01';
        goto LAB_00007414;
      }
      if (*DAT_00007228 < 0x1f) {
        sVar10 = -0x1e;
        if (-0x1f < *DAT_00007228) {
          sVar10 = *DAT_00007228;
        }
      }
      else {
        sVar10 = 0x1e;
      }
      *(short *)(pcVar1 + 0x18) = sVar10;
      if ((-6 < sVar10) && (sVar10 < 2)) {
        pcVar1[0x18] = '\x02';
        pcVar1[0x19] = '\0';
      }
      uVar11 = *puVar6 - *(short *)(pcVar1 + 0x18);
      goto LAB_000073f4;
    }
    if ((*DAT_000074cc == '\x01') && (*pcVar4 == '\0')) {
      pcVar1[0x1e] = '\0';
      pcVar1[0x1f] = '\0';
      pcVar1[0x12] = '\0';
      pcVar1[0x13] = '\0';
      if ((short)*puVar5 < (short)*puVar6) {
        *puVar6 = *puVar5;
      }
      *pcVar4 = '\x01';
    }
    else if ((*DAT_000074cc == '\0') && (*pcVar4 == '\x01')) {
      if ((int)*DAT_000074d4 < (int)-(uint)*(ushort *)(pcVar1 + 0x14)) {
        if ((short)*DAT_00007224 < 1000) {
          uVar11 = *DAT_00007224 + 0x19;
LAB_000072f2:
          *puVar6 = uVar11;
        }
        else {
          *pcVar4 = '\0';
        }
      }
      else {
        *pcVar4 = '\0';
        if ((short)*puVar6 < 1) {
          uVar11 = 10;
          goto LAB_000072f2;
        }
      }
      if (*pcVar4 == '\0') {
        *(ushort *)(pcVar1 + 0x10) = *puVar6;
      }
    }
    else {
      if (*DAT_000074d0 < *(ushort *)(pcVar1 + 0x14)) {
        uVar11 = *(ushort *)(pcVar1 + 0x14);
      }
      else {
        uVar11 = *DAT_000074d0;
      }
      sVar10 = -uVar11;
      *(short *)(pcVar1 + 0x16) = sVar10;
      iVar12 = ((int)*(short *)(pcVar1 + 6) - (int)*(short *)(pcVar1 + 0x20)) * 0x32;
      *(int *)(pcVar1 + 0x2c) = iVar12;
      *(undefined2 *)(pcVar1 + 0x20) = *(undefined2 *)(pcVar1 + 6);
      if (*DAT_000074d8 == '\0') {
        pcVar1[0x1a] = '\0';
        pcVar1[0x1b] = '\0';
      }
      else {
        if (*(short *)(pcVar1 + 6) == 0) {
          iVar14 = (int)*(short *)((int)DAT_000074dc + DAT_000074e0);
          if (*DAT_000074dc < 0) {
            iVar14 = -iVar14;
          }
          if ((0x13 < iVar14) || (0x1d < *DAT_000074e4)) goto LAB_00007358;
          if (*(short *)(pcVar1 + 0x1e) < 200) {
            *(short *)(pcVar1 + 0x1e) = *(short *)(pcVar1 + 0x1e) + 1;
          }
          else {
            *DAT_000074e4 = 0;
          }
        }
        else {
LAB_00007358:
          pcVar1[0x1e] = '\0';
          pcVar1[0x1f] = '\0';
        }
        *(short *)(pcVar1 + 0x1a) = (short)iVar12 + *DAT_000074e4 * -5;
      }
      if (*(ushort *)(pcVar1 + 0x1a) == 0) {
        if ((ushort)*(byte *)(DAT_000074e8 + 0xd) == *DAT_000074ec) {
          if (*(short *)(pcVar1 + 6) < 0x15) {
            pcVar1[0x1c] = '\0';
            pcVar1[0x1d] = '\0';
            if ((short)*puVar6 < 1) {
              if ((short)*puVar6 < 0) {
                uVar11 = *puVar6 + 1;
                goto LAB_000073e6;
              }
            }
            else {
              uVar11 = *puVar6 - 1;
LAB_000073e6:
              *puVar6 = uVar11;
            }
          }
          else {
            if (*DAT_000074d4 < sVar10) {
              iVar12 = DAT_000074f0;
              if ((short)*puVar6 < DAT_000074f0) {
                iVar12 = *puVar6 + 0x28;
              }
LAB_000073bc:
              *puVar6 = (ushort)iVar12;
            }
            else if (sVar10 < *DAT_000074d4) {
              iVar12 = -DAT_000074f0;
              if (iVar12 < (short)*puVar6) {
                iVar12 = *puVar6 - 0x28;
              }
              goto LAB_000073bc;
            }
            *(short *)(pcVar1 + 0x1c) = *(short *)(pcVar1 + 6) * -0xc;
          }
          uVar11 = *(ushort *)(pcVar1 + 0x1c);
          if ((short)uVar11 <= (short)*puVar6) goto LAB_00007414;
        }
        else if ((short)*puVar6 < 1) {
          if (-1 < (short)*puVar6) goto LAB_00007414;
          uVar11 = *puVar6 + 1;
        }
        else {
          uVar11 = *puVar6 - 1;
        }
LAB_000073f4:
        *puVar6 = uVar11;
      }
      else {
        *puVar6 = *(ushort *)(pcVar1 + 0x1a);
      }
    }
  }
LAB_00007414:
  pcVar2 = DAT_00007508;
  if ((((*(short *)(pcVar1 + 10) == 0) && (*DAT_000074f4 == '\0')) &&
      (((*DAT_000074cc != '\x01' && (*pcVar4 != '\x01')) || (*(short *)(pcVar1 + 6) < 0xb)))) &&
     ((((*DAT_000074f8 == '\0' || (*DAT_000074fc == 0)) &&
       ((*DAT_000074d8 == '\0' || (*DAT_000074e4 == 0)))) &&
      ((*(short *)(pcVar1 + 0x14) == 0 || (*(short *)(pcVar1 + 6) < 0x3d)))))) {
    iVar12 = (int)*(short *)((int)DAT_00007500 + DAT_000074e0);
    if (*DAT_00007500 < 0) {
      iVar12 = -iVar12;
    }
    if (0x1b < iVar12) goto LAB_0000748e;
    iVar12 = (int)*(short *)((int)DAT_000074dc + DAT_000074e0);
    if (*DAT_000074dc < 0) {
      iVar12 = -iVar12;
    }
    if (0x12 < iVar12) goto LAB_0000748e;
  }
  else {
LAB_0000748e:
    if (*DAT_00007504 == '\0') {
      if (*DAT_00007508 == '\0') {
        *(undefined2 *)(pcVar1 + 0x10) = *(undefined2 *)(pcVar1 + 0xe);
        *puVar6 = *(ushort *)(pcVar1 + 0xe);
      }
      *pcVar2 = '\x01';
      goto LAB_0000749a;
    }
  }
  *DAT_00007508 = '\0';
LAB_0000749a:
  iVar12 = DAT_000074f0;
  if (((short)*puVar6 <= DAT_000074f0) && (iVar12 = -DAT_000074f0, iVar12 <= (short)*puVar6)) {
    iVar12 = (int)(short)*puVar6;
  }
  *puVar6 = (ushort)iVar12;
  return;
}



/* ===== FUN_0000750c @ 0x750C ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __stdcall_softfp FUN_0000750c(void)

{
  undefined2 uVar1;
  int *piVar2;
  undefined1 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined2 *puVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  iVar9 = DAT_000075fc;
  puVar5 = (undefined4 *)&DAT_0001fa00;
  iVar11 = DAT_000075fc + 100;
  if (_DAT_0001fa00 == DAT_000075f8) {
    uVar4 = 0;
    iVar10 = DAT_000075fc + -0x50;
    do {
      iVar12 = uVar4 * 4;
      uVar8 = *puVar5;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 + 1 & 0xff;
      *(undefined4 *)(iVar10 + iVar12) = uVar8;
    } while (uVar4 < 0x14);
    *DAT_00007600 = *(undefined4 *)(iVar9 + -0x4c);
    uVar4 = *(uint *)(iVar9 + -0x38);
    if ((uVar4 & 1) == 0) {
      *DAT_00007604 = 0;
    }
    else {
      *DAT_00007604 = 1;
    }
    if ((int)(uVar4 << 0x1d) < 0) {
      *DAT_00007608 = 1;
    }
    else {
      *DAT_00007608 = 0;
    }
    *DAT_0000760c = *(undefined4 *)(iVar9 + -0x34);
    piVar2 = DAT_00007610;
    *DAT_00007610 = *(int *)(iVar9 + -0x30);
    puVar3 = DAT_00007618;
    if (*piVar2 == DAT_00007614) {
      uVar8 = *(undefined4 *)(iVar9 + -0x2c);
      *DAT_00007618 = (char)uVar8;
      puVar3[1] = (char)((uint)uVar8 >> 8);
      puVar3[2] = (char)((uint)uVar8 >> 0x10);
      puVar3[3] = (char)((uint)uVar8 >> 0x18);
      puVar3 = DAT_0000761c;
      uVar8 = *(undefined4 *)(iVar9 + -0x28);
      *DAT_0000761c = (char)uVar8;
      puVar3[1] = (char)((uint)uVar8 >> 8);
      puVar3[2] = (char)((uint)uVar8 >> 0x10);
    }
    iVar12 = DAT_00007620;
    uVar4 = 0;
    do {
      iVar7 = uVar4 * 4;
      uVar8 = *(undefined4 *)(iVar7 + iVar10 + 0x2c);
      *(char *)(iVar12 + iVar7) = (char)uVar8;
      iVar7 = iVar7 + iVar12;
      *(char *)(iVar7 + 1) = (char)((uint)uVar8 >> 8);
      *(char *)(iVar7 + 2) = (char)((uint)uVar8 >> 0x10);
      *(char *)(iVar7 + 3) = (char)((uint)uVar8 >> 0x18);
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 4);
    *DAT_00007624 = *(undefined4 *)(iVar9 + -0x14);
    uVar4 = 0;
    puVar6 = DAT_00007628;
    do {
      iVar10 = uVar4 * 2;
      uVar1 = *puVar6;
      uVar4 = uVar4 + 1 & 0xff;
      puVar6 = puVar6 + 2;
      *(undefined2 *)(iVar9 + iVar10) = uVar1;
    } while (uVar4 < 0x32);
    puVar6 = DAT_00007628 + 100;
    uVar4 = 0;
    do {
      iVar9 = uVar4 * 2;
      uVar1 = *puVar6;
      uVar4 = uVar4 + 1 & 0xff;
      puVar6 = puVar6 + 2;
      *(undefined2 *)(iVar11 + iVar9) = uVar1;
    } while (uVar4 < 0x32);
    return;
  }
  *DAT_00007600 = 0;
  uVar4 = 0;
  do {
    iVar10 = uVar4 * 2;
    *(undefined2 *)(iVar9 + iVar10) = 0;
    uVar4 = uVar4 + 1 & 0xff;
    *(undefined2 *)(iVar11 + iVar10) = 0;
  } while (uVar4 < 0x32);
  return;
}



/* ===== FUN_0000762c @ 0x762C ===== */

void __stdcall_softfp FUN_0000762c(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  uint uVar4;
  
  iVar1 = DAT_00007658;
  puVar3 = &DAT_0001f800;
  uVar4 = 0;
  do {
    *(undefined1 *)(iVar1 + uVar4) = *puVar3;
    iVar2 = DAT_0000765c;
    uVar4 = uVar4 + 1 & 0xff;
    puVar3 = puVar3 + 4;
  } while (uVar4 < 0x12);
  uVar4 = 0;
  do {
    *(undefined1 *)(iVar2 + uVar4) = *puVar3;
    uVar4 = uVar4 + 1 & 0xff;
    puVar3 = puVar3 + 4;
  } while (uVar4 < 0x17);
  return;
}



/* ===== FUN_00007660 @ 0x7660 ===== */

void __stdcall_softfp FUN_00007660(void)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = DAT_000076a4;
  if (*(char *)(DAT_000076a4 + 0x1e) != '\0') {
    if (*(char *)(DAT_000076a4 + 0x1d) == '\0') {
      *(undefined1 *)(DAT_000076a4 + 0x1d) = 10;
      *(undefined1 *)(iVar1 + 0x40) = 0x43;
      FUN_00009098(DAT_000076a4 + 0x40,1);
      pcVar2 = (char *)(DAT_000076a4 + 0x20);
      if (*pcVar2 != '\0') {
        *pcVar2 = *pcVar2 + -1;
        return;
      }
      *(undefined1 *)(iVar1 + 0x1e) = 0;
      return;
    }
    *(char *)(DAT_000076a4 + 0x1d) = *(char *)(DAT_000076a4 + 0x1d) + -1;
  }
  return;
}



/* ===== FUN_000076a8 @ 0x76A8 ===== */

void __stdcall_softfp FUN_000076a8(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined8 uVar3;
  undefined8 uVar4;
  
  iVar2 = param_1 * 0x1c20 >> 0xb;
  if (iVar2 < DAT_0000772c) {
    FUN_00002a60(iVar2 * param_2,DAT_0000772c - iVar2);
    uVar1 = FUN_00003970();
  }
  else {
    uVar1 = FUN_00003980(param_2 * DAT_0000772c);
  }
  uVar1 = FUN_0000377c(uVar1,DAT_00007730);
  uVar3 = FUN_000034da(param_3);
  FUN_00003728(uVar1);
  uVar4 = FUN_0000a298();
  uVar3 = FUN_00002f8c((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),(int)uVar3,
                       (int)((ulonglong)uVar3 >> 0x20));
  uVar3 = FUN_00002f2c(0xe0000000,DAT_00007734,(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
  uVar3 = FUN_00002f8c(0,DAT_00007738,(int)uVar3,(int)((ulonglong)uVar3 >> 0x20));
  uVar3 = FUN_00002f46((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0x60000000,DAT_0000773c);
  FUN_00002f2c((int)uVar3,(int)((ulonglong)uVar3 >> 0x20),0,DAT_00007740);
  FUN_000033d4();
  return;
}



/* ===== FUN_000077a8 @ 0x77A8 ===== */

/* WARNING: Function: __ARM_common_switch8 replaced with injection: switch8_r3 */
/* WARNING (jumptable): Removing unreachable block (ram,0x00007802) */
/* WARNING: Removing unreachable block (ram,0x00007802) */

void __stdcall_softfp FUN_000077a8(void)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 in_r3;
  int iVar5;
  
  iVar3 = DAT_00007a2c * *(short *)(DAT_00007a28 + 0x14) >> 0xf;
  psVar1 = (short *)(DAT_00007a28 + 0x16);
  iVar5 = -(iVar3 + *(short *)(DAT_00007a28 + 0x16)) >> 1;
  uVar4 = (uint)(0 < *psVar1);
  if (0 < iVar3 - *(short *)(DAT_00007a28 + 0x16) >> 1) {
    uVar4 = uVar4 + 2;
  }
  if (0 < iVar5) {
    uVar4 = uVar4 + 4;
  }
  *DAT_00007a28 = (char)uVar4;
                    /* WARNING: Could not recover jumptable at 0x00007802. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar2 = uVar4;
  if (DAT_00007806 <= uVar4) {
    uVar2 = (uint)DAT_00007806;
  }
  iVar3 = (uint)*(byte *)(uVar2 + 0x7807) * 2;
  (*(code *)(iVar3 + 0x7807))(uVar4,*psVar1 * 0x600 >> 10,iVar5 * -0x600 >> 10,iVar3,in_r3);
  return;
}



/* ===== FUN_00007a34 @ 0x7A34 ===== */

void __stdcall_softfp FUN_00007a34(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = DAT_00007a50;
  *(undefined4 *)(DAT_00007a50 + 0x28) = DAT_00007a4c;
  uVar2 = *(uint *)(iVar1 * 0x800000 + 0x24);
  if (param_2 == 0) {
    uVar2 = uVar2 & ~param_1;
  }
  else {
    uVar2 = uVar2 | param_1;
  }
  *(uint *)(iVar1 * 0x800000 + 0x24) = uVar2;
  return;
}



/* ===== FUN_00007a54 @ 0x7A54 ===== */

void __stdcall_softfp FUN_00007a54(int param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  puVar1 = DAT_00007b50;
  uVar6 = 0;
  DAT_00007b50[10] = DAT_00007b4c;
  FUN_00003bf0(DAT_00007b54);
  *puVar1 = 0;
  puVar2 = DAT_00007b58;
  iVar3 = (int)puVar1 * 0x800000;
  uVar5 = iVar3 >> 0xf;
  if (param_1 == 5) {
    *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) | uVar5;
    *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) & ~uVar5;
LAB_00007b42:
    uVar6 = 0x101;
    uVar4 = DAT_00007b78;
  }
  else {
    if (param_1 < 6) {
      if (param_1 != 1) {
        if (param_1 == 2) {
          *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) | uVar5;
          *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) & ~uVar5;
LAB_00007b1a:
          uVar4 = DAT_00007b70;
          uVar6 = 0x155;
        }
        else if (param_1 == 3) {
          *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) | uVar5;
          *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) & ~uVar5;
LAB_00007b2e:
          uVar4 = DAT_00007b74;
          uVar6 = 0x111;
        }
        else {
          if (param_1 != 4) goto LAB_00007abc;
          *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) | uVar5;
          *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) & ~uVar5;
          uVar4 = DAT_00007b78;
          uVar6 = DAT_00007b64;
        }
        goto LAB_00007aba;
      }
      *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) | uVar5;
      uVar5 = *(uint *)(iVar3 + 0x28) & ~uVar5;
    }
    else {
      if (param_1 != 0x11) {
        if (param_1 == 0x12) {
          *puVar1 = *puVar1 & DAT_00007b5c;
          *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) | 0xc000;
          goto LAB_00007b1a;
        }
        if (param_1 == 0x13) {
          *puVar1 = *puVar1 & DAT_00007b5c;
          *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) | 0xc000;
          goto LAB_00007b2e;
        }
        if (param_1 != 0x14) goto LAB_00007abc;
        *puVar1 = *puVar1 & DAT_00007b5c;
        *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) | 0xc000;
        goto LAB_00007b42;
      }
      *puVar1 = *puVar1 & DAT_00007b5c;
      *(uint *)(iVar3 + 0x24) = *(uint *)(iVar3 + 0x24) | 0xc000;
      uVar5 = *(uint *)(iVar3 + 0x28) | uVar5;
    }
    *(uint *)(iVar3 + 0x28) = uVar5;
    uVar4 = DAT_00007b6c;
    uVar6 = DAT_00007b68;
  }
LAB_00007aba:
  *puVar2 = uVar4;
LAB_00007abc:
  FUN_000086ce(DAT_00007b60);
  *puVar1 = uVar6;
  puVar1[10] = 0;
  return;
}



/* ===== FUN_00007b7c @ 0x7B7C ===== */

void __stdcall_softfp FUN_00007b7c(uint param_1,int param_2)

{
  int iVar1;
  
  iVar1 = DAT_00007b9c;
  *(undefined4 *)(DAT_00007b9c + 0x28) = DAT_00007b98;
  if (param_2 == 1) {
    param_1 = *(uint *)(iVar1 + 0x1c) | param_1;
  }
  else {
    param_1 = *(uint *)(iVar1 + 0x1c) & ~param_1;
  }
  *(uint *)(iVar1 + 0x1c) = param_1;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  return;
}



/* ===== FUN_00007ba0 @ 0x7BA0 ===== */

void __stdcall_softfp FUN_00007ba0(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_00007bfc;
  if (param_1 == 1) {
    *(undefined4 *)(DAT_00007bfc + 0x28) = DAT_00007bf8;
    iVar2 = iVar1 * 0x800000;
    *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) & 0xfffffcff;
    FUN_000086ce(100);
    *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)(iVar2 + 0x28);
    FUN_000086ce(100);
    do {
    } while (*(int *)(iVar2 + 8) << 0x10 < 0);
    *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) & 0xfffffcff;
    FUN_000086ce(100);
    *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) | 0x200;
    FUN_000086ce(100);
    FUN_00009e98(0x17);
    *(undefined4 *)(iVar1 + 0x28) = 0;
  }
  return;
}



/* ===== FUN_00007c00 @ 0x7C00 ===== */

void __stdcall_softfp FUN_00007c00(int param_1)

{
  if (param_1 != 1) {
    FUN_00009ed0(0x17);
    return;
  }
  *DAT_00007c24 = *DAT_00007c24 & 0xffffff;
  *DAT_00007c28 = 0x800000;
  return;
}



/* ===== FUN_00007c2c @ 0x7C2C ===== */

void __stdcall_softfp FUN_00007c2c(void)

{
  undefined4 *puVar1;
  
  FUN_00009ed0(0x17);
  FUN_00009e98(0x17);
  DAT_00007c80[10] = DAT_00007c7c;
  *DAT_00007c80 = 0;
  *(uint *)((int)DAT_00007c80 * 0x800000 + 0x28) =
       *(uint *)((int)DAT_00007c80 * 0x800000 + 0x28) & 0xfffffcff;
  DAT_00007c80[10] = 0;
  puVar1 = DAT_00007c88;
  *DAT_00007c88 = DAT_00007c84;
  DAT_00007c88[-4] = DAT_00007c88[-4] & 0xffffffbf;
  DAT_00007c88[-3] = DAT_00007c88[-3] & 0xffffffbf;
  *puVar1 = 0;
  DataSynchronizationBarrier(0xf);
  *(undefined4 *)(DAT_00007c90 + 0xc) = DAT_00007c8c;
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_00007c94 @ 0x7C94 ===== */

void __stdcall_softfp FUN_00007c94(void)

{
  undefined2 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  undefined4 in_r3;
  undefined1 *puVar8;
  undefined4 *puVar9;
  
  puVar2 = DAT_00007dd0;
  *DAT_00007dd0 = DAT_00007dcc;
  puVar8 = &DAT_0001fa00;
  puVar2[1] = *DAT_00007dd4;
  puVar2[6] = 0;
  if (*DAT_00007dd8 != '\0') {
    puVar2[6] = 1;
  }
  if (*DAT_00007ddc != '\0') {
    puVar2[6] = puVar2[6] | 4;
  }
  puVar2[7] = *DAT_00007de0;
  puVar2[8] = *DAT_00007de4;
  puVar2[9] = (uint)*DAT_00007de8 + (uint)DAT_00007de8[1] * 0x100 +
              (uint)DAT_00007de8[2] * 0x10000 + (uint)DAT_00007de8[3] * 0x1000000;
  puVar2[10] = (uint)DAT_00007dec[1] * 0x100 + (uint)DAT_00007dec[2] * 0x10000 + (uint)*DAT_00007dec
  ;
  iVar7 = DAT_00007df0;
  uVar5 = 0;
  do {
    iVar6 = uVar5 * 4 + iVar7;
    uVar4 = uVar5 + 1 & 0xff;
    puVar2[uVar5 + 0xb] =
         (uint)*(byte *)(iVar7 + uVar5 * 4) + (uint)*(byte *)(iVar6 + 1) * 0x100 +
         (uint)*(byte *)(iVar6 + 2) * 0x10000 + (uint)*(byte *)(iVar6 + 3) * 0x1000000;
    uVar5 = uVar4;
  } while (uVar4 < 4);
  puVar2[0xf] = *DAT_00007df4;
  puVar3 = DAT_00007dd0;
  uVar5 = 0;
  do {
    iVar7 = 0x30 - uVar5;
    iVar6 = 0x31 - uVar5;
    uVar5 = uVar5 + 1 & 0xff;
    *(undefined2 *)((int)puVar3 + iVar6 * 2 + 0x50) =
         *(undefined2 *)((int)puVar3 + iVar7 * 2 + 0x50);
    puVar9 = DAT_00007dd0;
  } while (uVar5 < 0x31);
  *(undefined2 *)(DAT_00007dd0 + 0x14) = *DAT_00007df8;
  uVar5 = 0;
  puVar9 = puVar9 + 0x2d;
  do {
    iVar7 = (0x31 - uVar5) * 2;
    uVar1 = *(undefined2 *)((int)puVar9 + (0x30 - uVar5) * 2);
    uVar5 = uVar5 + 1 & 0xff;
    *(undefined2 *)((int)puVar9 + iVar7) = uVar1;
  } while (uVar5 < 0x31);
  *(undefined2 *)puVar9 = *DAT_00007dfc;
  disableIRQinterrupts();
  *DAT_00007e04 = DAT_00007e00;
  FUN_00004c0c(&DAT_0001fa00,0,uVar1,iVar7,in_r3);
  uVar5 = 0;
  do {
    FUN_00005efc(puVar8,puVar2[uVar5]);
    puVar3 = DAT_00007dd0;
    uVar5 = uVar5 + 1 & 0xff;
    puVar8 = puVar8 + 4;
  } while (uVar5 < 0x14);
  uVar5 = 0;
  do {
    FUN_00005efc(puVar8,*(undefined2 *)((int)puVar3 + uVar5 * 2 + 0x50));
    uVar5 = uVar5 + 1 & 0xff;
    puVar8 = puVar8 + 4;
  } while (uVar5 < 0x32);
  uVar5 = 0;
  do {
    FUN_00005efc(puVar8,*(undefined2 *)((int)puVar9 + uVar5 * 2));
    uVar5 = uVar5 + 1 & 0xff;
    puVar8 = puVar8 + 4;
  } while (uVar5 < 0x32);
  enableIRQinterrupts();
  return;
}



/* ===== FUN_00007e08 @ 0x7E08 ===== */

void __stdcall_softfp FUN_00007e08(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 in_r3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  char cVar7;
  uint uVar8;
  
  puVar1 = DAT_00007eb8;
  bVar6 = 0;
  iVar5 = 0x1f800;
  disableIRQinterrupts();
  *DAT_00007eb8 = DAT_00007eb4;
  FUN_00004c0c(0x1f800,0,puVar1,in_r3,in_r3);
  do {
    cVar7 = '\0';
    uVar4 = 0;
    uVar8 = 0;
    do {
      FUN_00005efc(iVar5,*(undefined1 *)(DAT_00007ebc + uVar4));
      uVar4 = uVar4 + 1 & 0xff;
      iVar5 = iVar5 + 4;
    } while (uVar4 < 0x12);
    puVar2 = (uint *)&DAT_0001f800;
    uVar4 = 0;
    do {
      uVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      if (*(byte *)(DAT_00007ebc + uVar4) != uVar3) {
        uVar8 = uVar8 + 1 & 0xff;
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 0x12);
    uVar4 = 0;
    do {
      FUN_00005efc(iVar5,*(undefined1 *)(DAT_00007ec0 + uVar4));
      uVar4 = uVar4 + 1 & 0xff;
      iVar5 = iVar5 + 4;
    } while (uVar4 < 0x17);
    uVar4 = 0;
    puVar2 = DAT_00007ec4;
    do {
      uVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      if (*(byte *)(DAT_00007ec0 + uVar4) != uVar3) {
        cVar7 = cVar7 + '\x01';
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 0x17);
    if (cVar7 == '\0' && uVar8 == 0) {
      bVar6 = 10;
    }
    bVar6 = bVar6 + 1;
  } while (bVar6 < 8);
  if (bVar6 == 8) {
    *DAT_00007eb8 = DAT_00007eb4;
    FUN_00004c0c(0x1f800,0);
  }
  enableIRQinterrupts();
  return;
}



/* ===== FUN_00007ec8 @ 0x7EC8 ===== */

/* WARNING: Function: __ARM_common_switch8 replaced with injection: switch8_r3 */
/* WARNING (jumptable): Removing unreachable block (ram,0x00008146) */
/* WARNING (jumptable): Removing unreachable block (ram,0x0000820e) */
/* WARNING: Removing unreachable block (ram,0x00008146) */
/* WARNING: Removing unreachable block (ram,0x0000820e) */

void __stdcall_softfp FUN_00007ec8(int param_1)

{
  short *psVar1;
  short *psVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  char *pcVar6;
  char *pcVar7;
  ushort *puVar8;
  undefined2 uVar9;
  short sVar10;
  ushort uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  short sVar16;
  
  uVar12 = DAT_000082b4;
  pcVar6 = DAT_000082b0;
  uVar11 = *(ushort *)(DAT_000082b0 + 0x10);
  sVar10 = 0;
  if (uVar11 < DAT_000082b4) {
    uVar11 = uVar11 + 1;
    *(ushort *)(DAT_000082b0 + 0x10) = uVar11;
  }
  uVar14 = (uint)uVar11;
  if ((uint)*(ushort *)(pcVar6 + 0xe) < uVar14 * 3) {
    *(short *)(pcVar6 + 0xe) = (short)(uVar14 * 3);
  }
  if (uVar12 <= uVar14) {
    *(short *)(pcVar6 + 0xe) = (short)DAT_000082b8;
    pcVar6[7] = '\0';
    pcVar6[8] = '\0';
    pcVar6[0xc] = '\0';
  }
  if ((DAT_000082b4 - 7 < (uint)*(ushort *)(pcVar6 + 0xe)) || (DAT_000082b4 - 7 <= uVar14 * 6)) {
    *(undefined2 *)(pcVar6 + 0x1c) = *(undefined2 *)(pcVar6 + 0x26);
  }
  pcVar6 = DAT_000082b0;
  uVar14 = (uint)*(ushort *)(DAT_000082b0 + 0x14);
  cVar3 = DAT_000082b0[9];
  uVar12 = (uint)*(ushort *)(DAT_000082b0 + 0x12);
  if (*(short *)(DAT_000082b0 + 0x18) == 0) {
    psVar1 = (short *)(DAT_000082b0 + 0x14);
    psVar2 = (short *)(DAT_000082b0 + 0x12);
    if (cVar3 == '\x01') {
      if (DAT_000082b0[10] != '\0') {
        if (*(short *)(DAT_000082b0 + 0x1c) != 0) goto LAB_00007fd2;
        uVar9 = (undefined2)DAT_000082bc;
LAB_00007ffc:
        *(undefined2 *)(DAT_000082b0 + 0x12) = uVar9;
        goto LAB_00007ffe;
      }
      if (*DAT_000082b0 == '\0') {
        if (uVar12 < uVar14) {
          DAT_000082b0[10] = '\x01';
        }
      }
      else if (uVar12 <= uVar14 + DAT_000082c4) {
        *(short *)(DAT_000082b0 + 0x12) = (short)DAT_000082c4;
        goto LAB_00007ffe;
      }
    }
    else if (DAT_000082b0[0xb] == '\0') {
LAB_00007fd2:
      if (uVar12 <= *(ushort *)(DAT_000082b0 + 0x1c) + uVar14) {
        uVar9 = *(undefined2 *)(DAT_000082b0 + 0x1c);
        goto LAB_00007ffc;
      }
    }
    else if (uVar12 < uVar14) {
      DAT_000082b0[0xb] = '\0';
    }
    *(short *)(pcVar6 + 0x12) = *psVar2 - *psVar1;
  }
  else {
    uVar15 = DAT_000082bc - *(ushort *)(DAT_000082b0 + 0x14);
    sVar16 = *(short *)(DAT_000082b0 + 0x12) + *(ushort *)(DAT_000082b0 + 0x14);
    if (cVar3 == '\x06') {
      if (DAT_000082b0[10] != '\0') {
        if (*(ushort *)(DAT_000082b0 + 0x1c) == DAT_000082bc) {
          pcVar6[0x12] = '\0';
          pcVar6[0x13] = '\0';
          goto LAB_00007ffe;
        }
        goto LAB_00007f4e;
      }
      if (*DAT_000082b0 == '\0') {
        if (uVar15 < uVar12) {
          DAT_000082b0[10] = '\x01';
        }
        goto LAB_00007f92;
      }
      if ((int)(DAT_000082c0 - uVar14) <= (int)uVar12) {
        *(short *)(DAT_000082b0 + 0x12) = (short)DAT_000082c0;
        goto LAB_00007ffe;
      }
LAB_00007f96:
      *(short *)(DAT_000082b0 + 0x12) = sVar16;
    }
    else if (DAT_000082b0[0xb] == '\0') {
LAB_00007f4e:
      if ((int)uVar12 < (int)(*(ushort *)(DAT_000082b0 + 0x1c) - uVar14)) goto LAB_00007f96;
      *(undefined2 *)(DAT_000082b0 + 0x12) = *(undefined2 *)(DAT_000082b0 + 0x1c);
    }
    else {
      if (uVar15 < uVar12) {
        DAT_000082b0[0xb] = '\0';
      }
LAB_00007f92:
      *(short *)(pcVar6 + 0x12) = sVar16;
    }
  }
LAB_00007ffe:
  pcVar6 = DAT_000082b0;
  DAT_000082b0[4] = (char)param_1;
  pcVar6[0xd] = (char)param_1;
  if ((param_1 == 0) || (param_1 == 7)) {
    if ((byte)pcVar6[6] < 10) {
      pcVar6[6] = pcVar6[6] + 1;
      pcVar6[4] = pcVar6[5];
    }
  }
  else {
    pcVar6[6] = '\0';
  }
  pcVar7 = DAT_000082b0;
  bVar4 = DAT_000082b0[4];
  uVar12 = (uint)bVar4;
  if (uVar12 != (byte)pcVar6[5]) {
    DAT_000082b0[0xb] = '\0';
    pcVar7[7] = '\x01';
    psVar1 = DAT_000082c8;
    cVar3 = pcVar7[uVar12 + 0x2a] - cVar3;
    pcVar7[3] = cVar3;
    psVar2 = DAT_000082cc;
    pcVar6 = DAT_000082b0;
    if ((cVar3 == '\x01') || (cVar3 == -5)) {
      pcVar6[0x18] = '\x01';
      pcVar6[0x19] = '\0';
      if (*DAT_000082d0 == '\0') {
        *psVar1 = 0;
      }
      else if (*psVar1 < 200) {
        *psVar1 = *psVar1 + 1;
      }
      if (*DAT_000082d4 == '\0') {
LAB_000080c6:
        *psVar2 = 0;
      }
      else if (*psVar2 < 200) {
        sVar16 = *psVar2 + 1;
LAB_000080c2:
        *psVar2 = sVar16;
      }
    }
    else if ((cVar3 == -1) || (cVar3 == '\x05')) {
      pcVar6[0x18] = '\0';
      pcVar6[0x19] = '\0';
      if (*DAT_000082d0 == '\0') {
        *psVar1 = 0;
      }
      else if (-200 < *psVar1) {
        *psVar1 = *psVar1 + -1;
      }
      if (*DAT_000082d4 == '\0') goto LAB_000080c6;
      if (-200 < *psVar2) {
        sVar16 = *psVar2 + -1;
        goto LAB_000080c2;
      }
    }
    pcVar6 = DAT_000082b0;
    if ((ushort)(byte)DAT_000082b0[2] != *(ushort *)(DAT_000082b0 + 0x18)) {
      *(short *)(DAT_000082b0 + 0xe) = (short)DAT_000082b8 + -1;
      pcVar6[7] = '\0';
      pcVar6[8] = '\0';
      pcVar6[0xc] = '\0';
    }
    pcVar6[2] = (char)*(undefined2 *)(pcVar6 + 0x18);
    iVar13 = DAT_000082d8;
    bVar5 = pcVar6[0xc];
    uVar14 = (uint)bVar5;
    *(ushort *)(DAT_000082d8 + uVar14 * 2) = uVar11;
    pcVar6[0x10] = '\0';
    pcVar6[0x11] = '\0';
    if (pcVar6[8] == '\0') {
      if (uVar14 != 5) goto LAB_00008104;
      pcVar6[8] = '\x01';
LAB_00008118:
      pcVar6[0xc] = '\0';
    }
    else {
      uVar15 = 0;
      do {
        sVar10 = *(short *)(iVar13 + uVar15 * 2) + sVar10;
        uVar15 = uVar15 + 1 & 0xff;
      } while (uVar15 < 6);
      *(short *)(pcVar6 + 0xe) = sVar10;
LAB_00008104:
      if (4 < uVar14) goto LAB_00008118;
      pcVar6[0xc] = bVar5 + 1;
    }
    if (*(ushort *)(pcVar6 + 0xe) < 0x2e) {
      pcVar6[0xe] = '.';
      pcVar6[0xf] = '\0';
    }
    bVar5 = DAT_000082b0[uVar12 + 0x2a];
    pcVar6[9] = bVar5;
    pcVar6[5] = bVar4;
    uVar12 = (uint)bVar5;
    if (uVar12 != 0) {
      if (*(short *)(pcVar6 + 0x18) == 0) {
                    /* WARNING: Could not recover jumptable at 0x0000820e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        uVar14 = uVar12;
        if (DAT_00008212 <= uVar12) {
          uVar14 = (uint)DAT_00008212;
        }
        (*(code *)((uint)*(byte *)(uVar14 + 0x8213) * 2 + 0x8213))(uVar12,DAT_000082dc,0x8000);
        return;
      }
                    /* WARNING: Could not recover jumptable at 0x00008146. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      if (DAT_0000814a <= uVar12) {
        uVar12 = (uint)DAT_0000814a;
      }
      (*(code *)((uint)*(byte *)(uVar12 + 0x814b) * 2 + 0x814b))();
      return;
    }
    pcVar6[1] = '\x01';
    FUN_00004a98();
    if (*(short *)(pcVar6 + 0xe) != 0) {
      uVar9 = FUN_00004400((uint)(*(ushort *)(pcVar6 + 0xe) >> 1) +
                           (*(short *)(pcVar6 + 0x16) - DAT_00008458),(int)*(short *)(pcVar6 + 0xe))
      ;
      *(undefined2 *)(pcVar6 + 0x14) = uVar9;
    }
    pcVar6[10] = '\0';
  }
  pcVar6 = DAT_00008460;
  *DAT_00008460 = DAT_00008460[7] == '\0';
  if (*pcVar6 != '\0') {
    *(undefined2 *)(pcVar6 + 0x12) = *(undefined2 *)(pcVar6 + 0x1e);
  }
  *(undefined2 *)(pcVar6 + 0x28) = *(undefined2 *)(pcVar6 + 0x12);
  if (*pcVar6 == '\0') {
    if (*(short *)(pcVar6 + 0x18) != 0) {
      sVar10 = *(short *)(pcVar6 + 0x28) + (short)DAT_00008468;
      goto LAB_0000841e;
    }
    sVar10 = *(short *)(pcVar6 + 0x28);
    sVar16 = (short)DAT_0000846c;
  }
  else {
    sVar10 = *(short *)(pcVar6 + 0x28);
    sVar16 = (short)DAT_00008464;
  }
  sVar10 = sVar10 + sVar16;
LAB_0000841e:
  *(short *)(pcVar6 + 0x28) = sVar10;
  puVar8 = DAT_00008470;
  if ((int)((uint)*(ushort *)(pcVar6 + 0xe) - (uint)*DAT_00008470) < 0) {
    sVar10 = -(*(short *)(pcVar6 + 0xe) + *DAT_00008470);
  }
  else {
    sVar10 = *(short *)(pcVar6 + 0xe) - *DAT_00008470;
  }
  iVar13 = (int)sVar10;
  if (iVar13 < 0x29) {
    if (iVar13 < 2) {
      iVar13 = 2;
    }
  }
  else {
    iVar13 = 0x28;
  }
  sVar10 = FUN_00002a60((uint)*(ushort *)(pcVar6 + 0xe) - (uint)*DAT_00008470,iVar13);
  *puVar8 = sVar10 + *puVar8;
  return;
}



/* ===== FUN_00008474 @ 0x8474 ===== */

void __stdcall_softfp FUN_00008474(void)

{
  byte bVar1;
  short sVar2;
  char cVar3;
  undefined1 *puVar4;
  char *pcVar5;
  char *pcVar6;
  undefined2 uVar7;
  ushort uVar8;
  ushort uVar9;
  uint uVar10;
  int iVar11;
  ushort uVar12;
  
  puVar4 = DAT_0000866c;
  uVar9 = *(ushort *)(DAT_0000866c + 0x12);
  if (uVar9 < *(ushort *)(DAT_0000866c + 6)) {
    sVar2 = 1;
LAB_0000848c:
    *(ushort *)(DAT_0000866c + 0x12) = uVar9 + sVar2;
  }
  else if (*(ushort *)(DAT_0000866c + 6) < uVar9) {
    sVar2 = -1;
    goto LAB_0000848c;
  }
  if ((((*DAT_00008670 == '\x02') && (*DAT_00008674 == '\0')) && (*DAT_00008678 == '\0')) &&
     (*DAT_0000867c < 4)) {
    if (*(ushort *)(puVar4 + 8) < 0xb4) {
      *(short *)(puVar4 + 8) = *(short *)(puVar4 + 8) + 1;
    }
    if (*(ushort *)(puVar4 + 8) < 0xb4) {
      if (*(ushort *)(puVar4 + 8) < 0x97) {
        if (*(ushort *)(puVar4 + 8) < 0x83) {
          if (*(ushort *)(puVar4 + 8) < 0x6f) goto LAB_000084f0;
          uVar10 = (uint)*(ushort *)(puVar4 + 0x12);
          iVar11 = 0x50;
        }
        else {
          uVar10 = (uint)*(ushort *)(puVar4 + 0x12);
          iVar11 = 0x32;
        }
      }
      else {
        uVar10 = (uint)*(ushort *)(puVar4 + 0x12);
        iVar11 = 0x14;
      }
      uVar7 = (undefined2)(iVar11 * uVar10 >> 7);
      goto LAB_000084f2;
    }
    *puVar4 = 1;
  }
  else {
    *(undefined2 *)(puVar4 + 8) = 0;
LAB_000084f0:
    uVar7 = *(undefined2 *)(puVar4 + 0x12);
LAB_000084f2:
    *(undefined2 *)(puVar4 + 0x10) = uVar7;
  }
  sVar2 = *(short *)(puVar4 + 10);
  if (sVar2 < 0x385) {
    puVar4[3] = 0;
  }
  else {
    puVar4[3] = 1;
    if (sVar2 < DAT_00008680) {
      iVar11 = (int)(short)((short)DAT_00008684 + sVar2 * -3);
      if (iVar11 < 0) {
        iVar11 = 0;
      }
    }
    else {
      iVar11 = 3;
    }
    if (iVar11 < (int)(uint)*(ushort *)(puVar4 + 0x10)) {
      *(short *)(puVar4 + 0x10) = (short)iVar11;
    }
  }
  pcVar5 = DAT_00008688;
  bVar1 = DAT_0000866c[4];
  if (*DAT_00008688 < 'E') {
    if (bVar1 != 0) {
      cVar3 = -1;
      goto LAB_0000854c;
    }
    puVar4[1] = 0;
  }
  else if (bVar1 < 4) {
    cVar3 = '\x01';
LAB_0000854c:
    puVar4[4] = bVar1 + cVar3;
  }
  else {
    puVar4[1] = 1;
  }
  pcVar6 = DAT_0000868c;
  uVar9 = *(ushort *)(puVar4 + 0x10);
  uVar12 = 0x112;
  if (0x112 < uVar9) {
    if ((*DAT_0000868c == '\0') || (puVar4[1] == '\0')) {
      uVar8 = uVar12;
      if ((*pcVar5 < '7') && (-5 < *pcVar5)) {
        if ((*pcVar5 < '\x02') && (-5 < *pcVar5)) {
          uVar8 = (2 - *pcVar5) * -0x1f + 0x1ed;
        }
        else {
          uVar8 = uVar9;
          if (('2' < *pcVar5) && (*pcVar5 < '7')) {
            uVar8 = (short)DAT_00008690 + *pcVar5 * -0x2c;
          }
        }
      }
      if (uVar8 < uVar9) {
        *(ushort *)(puVar4 + 0x10) = uVar8;
      }
    }
    if ((((*(byte *)(DAT_00008694 + 8) & 0x2c) != 0) || (*pcVar6 != '\0')) &&
       (0x112 < *(ushort *)(puVar4 + 0x10))) {
      *(undefined2 *)(puVar4 + 0x10) = 0x112;
    }
    uVar9 = (ushort)*DAT_00008698;
    if (uVar9 < 0x14) {
      if (10 < uVar9) {
        uVar12 = (0x14 - uVar9) * -0x16 + 0x1ed;
      }
      if (uVar12 < *(ushort *)(puVar4 + 0x10)) {
        *(ushort *)(puVar4 + 0x10) = uVar12;
      }
    }
  }
  if (*DAT_0000869c < *(ushort *)(puVar4 + 0x10)) {
    uVar9 = *DAT_0000869c + 1;
LAB_00008622:
    *DAT_0000869c = uVar9;
  }
  else if (*(ushort *)(puVar4 + 0x10) < *DAT_0000869c) {
    uVar9 = *DAT_0000869c - 1;
    goto LAB_00008622;
  }
  uVar9 = *(ushort *)(DAT_0000866c + 0x14);
  if (*DAT_000086a0 < -0x111) {
    if (7999 < uVar9) {
      uVar7 = 0xff40;
LAB_00008656:
      *DAT_000086a4 = uVar7;
      goto LAB_00008658;
    }
    sVar2 = 1;
  }
  else {
    if (uVar9 == 0) {
      uVar7 = (undefined2)DAT_000086a8;
      goto LAB_00008656;
    }
    sVar2 = -1;
  }
  *(ushort *)(puVar4 + 0x14) = uVar9 + sVar2;
LAB_00008658:
  if (*DAT_000086ac == '\0') {
    uVar7 = (undefined2)DAT_000086b8;
  }
  else {
    uVar7 = (undefined2)DAT_000086b4;
  }
  *DAT_000086b0 = uVar7;
  return;
}



/* ===== FUN_000086bc @ 0x86BC ===== */

void __stdcall_softfp FUN_000086bc(uint param_1)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_1; uVar1 = uVar1 + 1) {
  }
  return;
}



/* ===== FUN_000086ce @ 0x86CE ===== */

void __stdcall_softfp FUN_000086ce(uint param_1)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_1; uVar1 = uVar1 + 1) {
  }
  return;
}



/* ===== FUN_000086e0 @ 0x86E0 ===== */

uint __stdcall_softfp FUN_000086e0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = DAT_000086ec;
  *(undefined4 *)(DAT_000086ec + 0x30) = param_1;
  return *(uint *)(iVar1 + 0x34) & 0xffff;
}



/* ===== FUN_000086f0 @ 0x86F0 ===== */

/* WARNING: Function: __ARM_common_switch8 replaced with injection: switch8_r3 */
/* WARNING (jumptable): Removing unreachable block (ram,0x000086f8) */
/* WARNING: Removing unreachable block (ram,0x000086f8) */

void __stdcall_softfp FUN_000086f0(void)

{
                    /* WARNING: Could not recover jumptable at 0x000086f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&DAT_000086fd + (uint)DAT_000086fd * 2))();
  return;
}



/* ===== system_init_set_vtor @ 0x8780 ===== */

/* SystemInit stage that relocates SCB VTOR to the application vector table at 0x2800. */

void __stdcall_softfp system_init_set_vtor(void)

{
  *(dword **)(DAT_00008790 + 8) = &vector_00_initial_sp;
  FUN_00004874();
  return;
}



/* ===== speed_variant_config_init @ 0x8794 ===== */

/* Parses the five-digit product or variant identifier and builds the speed profile. */

void __stdcall_softfp speed_variant_config_init(void)

{
  int iVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = DAT_00008844;
  iVar3 = DAT_0000883c;
  if ((*DAT_00008840 != '0') && (*DAT_00008840 != -1)) {
    iVar3 = 0;
    uVar4 = 0;
    do {
      iVar3 = (uint)(byte)DAT_00008840[uVar4] + iVar3 + -0x30;
      if (uVar4 < 4) {
        iVar3 = iVar3 * 10;
      }
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 5);
  }
  *(int *)(DAT_00008844 + 4) = iVar3;
  puVar2 = DAT_0000884c;
  DAT_0000884c[0xe] = (short)DAT_00008848;
  puVar2[5] = 0x17c;
  *(undefined1 *)(puVar2 + 6) = 0;
  puVar2[2] = 100;
  puVar2[3] = 0x92;
  puVar2[4] = 0x112;
  *(undefined1 *)((int)puVar2 + 0xd) = 1;
  puVar2[10] = (short)DAT_00008850;
  puVar2[9] = (short)DAT_00008854;
  *puVar2 = 0xcb;
  puVar2[1] = 0xfd;
  *(undefined4 *)(puVar2 + 0xc) = DAT_00008858;
  *(undefined1 *)(puVar2 + 7) = 3;
  *(undefined1 *)(puVar2 + 0xf) = 0x14;
  *(undefined1 *)((int)puVar2 + 0x1f) = 0xf;
  if (((*(int *)(iVar1 + 4) == DAT_0000883c + -0xe) || (*(int *)(iVar1 + 4) == DAT_0000883c + -10))
     || (*(int *)(iVar1 + 4) == DAT_0000885c)) {
    *puVar2 = 0x99;
    puVar2[1] = 0xcb;
    *(undefined1 *)(puVar2 + 0xf) = 0xf;
    *(undefined1 *)((int)puVar2 + 0x1f) = 10;
    puVar2[0xe] = (short)DAT_00008848 + 0xc;
    *(undefined1 *)(puVar2 + 6) = 0;
    puVar2[5] = 500;
  }
  return;
}



/* ===== FUN_00008860 @ 0x8860 ===== */

void __stdcall_softfp FUN_00008860(void)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  byte bVar4;
  undefined2 uVar5;
  int iVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  ushort uVar10;
  byte *pbVar11;
  char *unaff_r6;
  int iVar12;
  bool bVar13;
  byte local_b0 [4];
  char local_ac;
  char local_ab [4];
  undefined1 local_a7;
  
  iVar12 = DAT_00008adc;
  uVar8 = (uint)(byte)(*(char *)(DAT_00008adc + 4) + 5);
  if (0x87 < uVar8) {
    return;
  }
  bVar1 = *(byte *)(DAT_00008adc + uVar8);
  bVar4 = *(byte *)(DAT_00008adc + uVar8 + 1);
  iVar6 = FUN_000048d8(DAT_00008adc);
  iVar2 = DAT_00008ae0;
  if ((uint)bVar1 * 0x100 + (uint)bVar4 != iVar6) {
    return;
  }
  local_b0[2] = *(byte *)(iVar12 + 2);
  local_b0[0] = 0x5a;
  local_b0[1] = 0xb1;
  cVar3 = '\x01';
  local_b0[3] = local_b0[2];
  if (local_b0[2] == 0xe0) {
    local_ac = '\x01';
    local_ab[0] = '\0';
    *(undefined1 *)(DAT_00008ae0 + 2) = 1;
    if (*(char *)(iVar2 + 0x30) == '\0') {
      *DAT_00008af0 = DAT_00008aec;
      FUN_00004c0c(0xf000,0);
      *(undefined1 *)(iVar2 + 0x30) = 1;
    }
    *(undefined1 *)(iVar2 + 0x31) = 0;
    *(undefined2 *)(iVar2 + 0x42) = 0;
    *(undefined4 *)(iVar2 + 0x7c) = 0;
    *(undefined4 *)(iVar2 + 0x78) = 0xf000;
    FUN_00004640();
    uVar5 = FUN_000048d8(local_b0,6);
    local_ab[1] = (char)((ushort)uVar5 >> 8);
    local_ab[2] = (char)uVar5;
    goto LAB_00008924;
  }
  if (local_b0[2] < 0xe1) {
    if (local_b0[2] == 0x11) {
      if ((*(char *)(DAT_00008ae0 + 0x32) == '\0') && (unaff_r6 = &DAT_00002600, DAT_00002600 == -1)
         ) {
        *(undefined1 *)(DAT_00008ae0 + 0x32) = 1;
      }
      local_ac = '\f';
      bVar4 = *(byte *)(iVar2 + 0x32);
      uVar8 = 0;
      do {
        if (bVar4 == 0) {
          local_ab[uVar8] = *unaff_r6;
          unaff_r6 = unaff_r6 + 1;
        }
        else {
          local_ab[uVar8] = *(char *)(DAT_00008ae8 + 0x1e + uVar8);
        }
        uVar8 = uVar8 + 1 & 0xff;
      } while (uVar8 < 0xc);
      *(byte *)(iVar2 + 0x32) = bVar4 ^ 1;
    }
    else {
      if (local_b0[2] != 0x1d) {
        return;
      }
      local_ac = '\x17';
      uVar8 = 0;
      do {
        local_ab[uVar8] = *(char *)(DAT_00008ae0 + 0x89 + uVar8);
        uVar8 = uVar8 + 1 & 0xff;
      } while (uVar8 < 0x17);
    }
    goto LAB_00008924;
  }
  if (local_b0[2] == 0xe1) {
    local_ac = '\x03';
    uVar10 = (ushort)*(byte *)(iVar12 + 5) * 0x100 + (ushort)*(byte *)(iVar12 + 6);
    uVar9 = *(uint *)(DAT_00008ae0 + 0x78);
    uVar8 = (uint)*(byte *)(iVar12 + 4);
    local_ab[0] = cVar3;
    if (((uVar9 + uVar8 < 0x1b800) && (0xefff < uVar9)) && (*(char *)(DAT_00008ae0 + 2) != '\0')) {
      if (*(ushort *)(DAT_00008ae0 + 0x42) + 1 == (uint)uVar10) {
        *(ushort *)(DAT_00008ae0 + 0x42) = uVar10;
        iVar6 = DAT_00008ae0;
        if (2 < uVar8) {
          uVar8 = uVar8 - 2 & 0xffff;
          FUN_00004ce0(uVar9,iVar12 + 7,uVar8);
          *(uint *)(iVar6 + 0x7c) = *(int *)(iVar6 + 0x7c) + uVar8;
          *(uint *)(iVar6 + 0x78) = *(int *)(iVar6 + 0x78) + uVar8;
        }
      }
      else if ((uint)*(ushort *)(DAT_00008ae0 + 0x42) != (uint)uVar10) goto LAB_00008a4a;
      local_ab[0] = '\0';
    }
LAB_00008a4a:
    local_ab[1] = (char)((ushort)*(undefined2 *)(iVar2 + 0x42) >> 8);
    local_ab[2] = (char)*(undefined2 *)(iVar2 + 0x42);
    uVar5 = FUN_000048d8(local_b0,8);
    local_ab[3] = (char)((ushort)uVar5 >> 8);
    local_a7 = (undefined1)uVar5;
  }
  else {
    if (local_b0[2] != 0xe2) {
      return;
    }
    local_ac = '\x01';
    uVar8 = *(uint *)(DAT_00008ae0 + 0x78);
    if (DAT_00008ae4 < uVar8) {
      pcVar7 = (char *)(uVar8 - 0xc);
      bVar13 = *pcVar7 == 'F';
LAB_000088ec:
      if (!bVar13) goto code_r0x000088ee;
      iVar12 = 0;
      bVar4 = 0;
      pbVar11 = (byte *)(uVar8 - 4);
      do {
        bVar4 = bVar4 + 1;
        iVar12 = (uint)*pbVar11 + iVar12 * 0x100;
        pbVar11 = pbVar11 + 1;
      } while (bVar4 < 4);
      if (*(uint *)(DAT_00008ae0 + 0x7c) < 5) {
        local_ab[0] = '\x01';
      }
      else {
        local_ab[0] = FUN_00004604(0xf000,*(uint *)(DAT_00008ae0 + 0x7c) - 4,iVar12);
      }
      if (local_ab[0] == '\0' && *(char *)(iVar2 + 0x31) == '\0') {
        *DAT_00008af0 = DAT_00008aec;
        FUN_00004c0c(0x1fc00,0);
        FUN_00005efc(0x1fc00,DAT_00008af4);
        FUN_00005efc(DAT_00008af8,*(int *)(iVar2 + 0x7c) + -4);
        FUN_00005efc(DAT_00008af8 + 4,iVar12);
        *(undefined1 *)(iVar2 + 0x31) = 1;
      }
      goto LAB_0000890c;
    }
LAB_00008908:
    local_ab[0] = '\x01';
LAB_0000890c:
    uVar5 = FUN_000048d8(local_b0,6);
    local_ab[1] = (char)((ushort)uVar5 >> 8);
    local_ab[2] = (char)uVar5;
    *(undefined1 *)(DAT_00008ae0 + 1) = 1;
  }
  *(undefined1 *)(iVar2 + 0x30) = 0;
LAB_00008924:
  uVar8 = (uint)(byte)(local_ac + 5);
  uVar5 = FUN_000048d8(local_b0,uVar8);
  local_b0[uVar8] = (byte)((ushort)uVar5 >> 8);
  uVar8 = uVar8 + 1 & 0xff;
  local_b0[uVar8] = (byte)uVar5;
  FUN_00009098(local_b0,uVar8 + 1 & 0xff);
  return;
code_r0x000088ee:
  uVar9 = 0;
  do {
    cVar3 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    if (cVar3 != *(char *)(DAT_00008ae8 + uVar9)) break;
    uVar9 = uVar9 + 1 & 0xff;
  } while (uVar9 < 7);
  bVar13 = uVar9 == 7;
  if (!bVar13) goto LAB_00008908;
  goto LAB_000088ec;
}



/* ===== FUN_00008afc @ 0x8AFC ===== */

void __stdcall_softfp FUN_00008afc(void)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  
  FUN_00007a34(0x2000);
  uVar2 = FUN_00003bf0(DAT_00008b1c);
  puVar1 = DAT_00008b20;
  *DAT_00008b20 = uVar2;
  uVar2 = FUN_00003bf0(DAT_00008b1c + 4);
  puVar1[1] = uVar2;
  return;
}



/* ===== uart0_irq_Handler @ 0x8C40 ===== */

void __stdcall_softfp uart0_irq_Handler(void)

{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  undefined1 uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  uint uVar10;
  int iVar11;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar1 = DAT_00008e78;
  iVar11 = 0;
  if (-1 < *(int *)(DAT_00008e78 + 0x20) * 0x40000000) goto LAB_00008e44;
  *(undefined4 *)(DAT_00008e78 + 0x20) = 2;
  iVar2 = DAT_00008e7c;
  uVar7 = *(uint *)(iVar1 + 0xc);
  uVar8 = uVar7 & 0xff;
  if (*(char *)(DAT_00008e7c + 0xc) == '\0') {
    *(undefined1 *)(DAT_00008e7c + 0x23) = 0;
  }
  *(undefined1 *)(iVar2 + 0xc) = 8;
  pcVar3 = DAT_00008e80;
  bVar6 = *(byte *)(iVar2 + 0x23);
  uVar10 = (uint)bVar6;
  cVar9 = (char)uVar7;
  if (uVar10 == 0) {
    *(undefined1 *)(iVar2 + 0x24) = 7;
    if (uVar8 - 0x51 < 4) {
      *pcVar3 = cVar9;
      *(undefined1 *)(iVar2 + 0x23) = 1;
      *(undefined1 *)(iVar2 + 0xe) = 1;
      goto LAB_00008e44;
    }
    if (uVar8 == 100) {
      *pcVar3 = cVar9;
      *(undefined1 *)(iVar2 + 0x23) = 1;
      *(undefined1 *)(iVar2 + 0xe) = 2;
      *(undefined1 *)(iVar2 + 0x24) = 0x1f;
      *(undefined1 *)(iVar2 + 0x25) = 0;
      goto LAB_00008e44;
    }
    if (uVar8 == 0x5a) {
      *pcVar3 = cVar9;
      *(undefined1 *)(iVar2 + 0x23) = 1;
      *(undefined1 *)(iVar2 + 0xe) = 4;
      *(undefined1 *)(iVar2 + 0xc) = 8;
      goto LAB_00008e44;
    }
    if ((*(char *)(iVar2 + 2) == '\0') || ((uVar8 != 1 && (uVar8 != 4)))) goto LAB_00008e44;
    *(undefined1 *)(iVar2 + 0xe) = 3;
    *pcVar3 = cVar9;
    *(undefined1 *)(iVar2 + 0x23) = 1;
    if (uVar8 != 1) {
      *(undefined1 *)(iVar2 + 0xb) = 3;
      *(undefined1 *)(iVar2 + 0x10) = 1;
      pcVar3 = DAT_00008e80;
      *(undefined1 *)(iVar2 + 0x23) = 0;
      pcVar3[0x96] = '\x04';
      goto LAB_00008e44;
    }
    uVar5 = 0x85;
LAB_00008dcc:
    *(undefined1 *)(iVar2 + 0x24) = uVar5;
    goto LAB_00008e44;
  }
  if (uVar10 < 0x96) {
    if (*(char *)(DAT_00008e7c + 0xe) == '\x02') {
      DAT_00008e80[uVar10] = cVar9;
      *(byte *)(iVar2 + 0x23) = bVar6 + 1;
      if (uVar8 == 0xd) {
        cVar9 = '\0';
        local_1c = DAT_00008e84;
        local_18 = DAT_00008e88;
        uVar7 = 1;
        do {
          if (pcVar3[uVar7] == *(char *)((int)&local_1c + uVar7)) {
            cVar9 = cVar9 + '\x01';
          }
          uVar7 = uVar7 + 1 & 0xff;
        } while (uVar7 < 5);
        if (cVar9 == '\x04') {
          *(undefined1 *)(iVar2 + 0x25) = 1;
          local_28 = DAT_00008e8c;
          uStack_24 = DAT_00008e90;
          uStack_20 = DAT_00008e94;
          uVar7 = FUN_000086f0(DAT_00008e80,DAT_00008e90,DAT_00008e94,&local_1c);
          if (uVar7 < 0xc) {
            *(undefined1 *)(iVar2 + 0x24) = *(undefined1 *)((int)&local_28 + uVar7);
          }
          else {
            *(undefined1 *)(iVar2 + 0x23) = 0;
            *(undefined1 *)(iVar2 + 0x25) = 0;
          }
        }
        else {
          *(undefined1 *)(iVar2 + 0x23) = 0;
        }
      }
      if ((*(byte *)(iVar2 + 0x24) <= *(byte *)(iVar2 + 0x23)) &&
         (*(char *)(iVar2 + 0x25) == '\x01')) {
        *(byte *)(DAT_00008e7c + 0xf) = *(byte *)(iVar2 + 0x23);
        iVar11 = 2;
      }
    }
    else {
      bVar6 = *(byte *)(DAT_00008e7c + 0x24);
      uVar8 = (uint)bVar6;
      if (*(char *)(DAT_00008e7c + 0xe) == '\x03') {
        DAT_00008e80[uVar10] = cVar9;
        *(char *)(iVar2 + 0x23) = (char)(uVar10 + 1);
        if (uVar8 <= (uVar10 + 1 & 0xff)) {
          *(undefined1 *)(DAT_00008e7c + 0x10) = 0x85;
          iVar11 = 3;
        }
      }
      else if (*(char *)(DAT_00008e7c + 0xe) == '\x01') {
        DAT_00008e80[uVar10] = cVar9;
        uVar7 = uVar10 + 1 & 0xff;
        *(char *)(iVar2 + 0x23) = (char)(uVar10 + 1);
        if (uVar7 == 3) {
          cVar9 = *pcVar3;
          if (cVar9 == 'S') {
            uVar5 = 4;
            goto LAB_00008dcc;
          }
          if (((cVar9 != 'Q') && (cVar9 != 'T')) && (cVar9 != 'R')) {
            *(undefined1 *)(iVar2 + 0x24) = 0;
            goto LAB_00008e42;
          }
          uVar7 = (byte)pcVar3[2] + 5;
          if (uVar7 < 0x96) goto LAB_00008dd8;
        }
        else if (uVar8 <= uVar7) {
          iVar11 = 1;
          *(byte *)(DAT_00008e7c + 0x10) = bVar6;
        }
      }
      else if (*(char *)(DAT_00008e7c + 0xe) == '\x04') {
        if (uVar10 == 1) {
          if (((uVar7 & 0x87) == 1) || ((uVar7 & 0x87) == 2)) {
            DAT_00008e80[1] = cVar9;
            *(undefined1 *)(iVar2 + 0x23) = 2;
          }
          else {
LAB_00008e26:
            *(undefined1 *)(iVar2 + 0x23) = 0;
          }
        }
        else {
          DAT_00008e80[uVar10] = cVar9;
          uVar7 = uVar10 + 1 & 0xff;
          *(char *)(iVar2 + 0x23) = (char)(uVar10 + 1);
          if (uVar7 == 5) {
            if (0x8e < (byte)pcVar3[4]) goto LAB_00008e26;
            uVar7 = (byte)pcVar3[4] + 7;
LAB_00008dd8:
            *(char *)(iVar2 + 0x24) = (char)uVar7;
          }
          else if (uVar8 <= uVar7) {
            iVar11 = 5;
          }
        }
      }
    }
    pcVar4 = DAT_00008e80;
    iVar1 = DAT_00008e7c;
    bVar6 = *(byte *)(iVar2 + 0x23);
    if (((uint)bVar6 < (uint)*(byte *)(iVar2 + 0x24)) || (iVar11 == 0)) goto LAB_00008e44;
    if (*(char *)(DAT_00008e7c + 0xb) == '\0') {
      for (uVar7 = 0; uVar7 < bVar6; uVar7 = uVar7 + 1 & 0xff) {
        pcVar4[uVar7 + 0x96] = pcVar3[uVar7];
      }
      *(undefined1 *)(iVar1 + 0xb) = *(undefined1 *)(iVar1 + 0xe);
    }
  }
LAB_00008e42:
  *(undefined1 *)(iVar2 + 0x23) = 0;
LAB_00008e44:
  iVar1 = DAT_00008e78;
  if ((*(uint *)(DAT_00008e78 + 0x20) & 1) != 0) {
    *(undefined4 *)(DAT_00008e78 + 0x20) = 1;
    iVar11 = DAT_00008e7c;
    bVar6 = *(byte *)(DAT_00008e7c + 9);
    if ((uint)bVar6 != (uint)*(byte *)(DAT_00008e7c + 10)) {
      *(uint *)(iVar1 + 0xc) = (uint)*(byte *)(DAT_00008e98 + (uint)bVar6);
      bVar6 = bVar6 + 1;
      *(byte *)(iVar11 + 9) = bVar6;
    }
    if (0x31 < bVar6) {
      *(undefined1 *)(iVar11 + 9) = 0;
    }
    *(undefined1 *)(iVar11 + 0xd) = 5;
  }
  *(undefined4 *)(iVar1 + 0x20) = 0x1c;
  return;
}



/* ===== FUN_00008e9c @ 0x8E9C ===== */

void __stdcall_softfp FUN_00008e9c(void)

{
  int iVar1;
  short sVar2;
  
  if ((*(char *)(DAT_00008ee8 + 3) == '\0') || (*(char *)(DAT_00008ee8 + 2) != '\0')) {
    sVar2 = 0;
  }
  else {
    if (0x1df < *(ushort *)(DAT_00008ee8 + 0x3e)) {
      FUN_00004a98();
      iVar1 = DAT_00008ee8;
      if (*(char *)(DAT_00008ee8 + 0x29) == '\0') {
        FUN_00007c94();
        *(undefined1 *)(iVar1 + 0x29) = 1;
      }
      *DAT_00008eec = 1;
      *(uint *)(DAT_00008ef0 + 0xc) = *(uint *)(DAT_00008ef0 + 0xc) & ~(DAT_00008ef0 >> 0x15);
      return;
    }
    sVar2 = *(ushort *)(DAT_00008ee8 + 0x3e) + 1;
  }
  *(short *)(DAT_00008ee8 + 0x3e) = sVar2;
  return;
}



/* ===== uart1_irq_Handler @ 0x8EF4 ===== */

void __stdcall_softfp uart1_irq_Handler(void)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  char cVar9;
  uint uVar10;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar2 = DAT_00009068;
  if (-1 < *(int *)(DAT_00009068 + 0x20) * 0x40000000) goto LAB_00008fbe;
  *(undefined4 *)(DAT_00009068 + 0x20) = 2;
  iVar3 = DAT_0000906c;
  uVar7 = *(uint *)(iVar2 + 0xc);
  uVar8 = uVar7 & 0xff;
  if (*(char *)(DAT_0000906c + 4) == '\0') {
    *(undefined1 *)(DAT_0000906c + 0xe) = 0;
  }
  *(undefined1 *)(iVar3 + 4) = 10;
  puVar4 = DAT_00009070;
  uVar10 = (uint)*(byte *)(iVar3 + 0xe);
  uVar1 = (undefined1)uVar7;
  if (uVar10 != 0) {
    if (uVar10 < 0x32) {
      if (*(char *)(iVar3 + 6) != '\0') {
        if (*(char *)(iVar3 + 6) == '\x01') {
          DAT_00009070[uVar10] = uVar1;
          uVar1 = (undefined1)(uVar10 + 1);
          *(undefined1 *)(DAT_0000906c + 0xe) = uVar1;
          iVar2 = DAT_0000906c;
          if (uVar8 == 0xd) {
            cVar9 = '\0';
            local_1c = DAT_00009078;
            local_18 = DAT_0000907c;
            uVar7 = 1;
            do {
              if (puVar4[uVar7] == *(char *)((int)&local_1c + uVar7)) {
                cVar9 = cVar9 + '\x01';
              }
              uVar7 = uVar7 + 1 & 0xff;
            } while (uVar7 < 5);
            if ((cVar9 == '\x04') &&
               (*(undefined1 *)(DAT_0000906c + 7) = uVar1, puVar5 = DAT_00009070,
               *(char *)(iVar2 + 3) == '\0')) {
              for (uVar7 = 0; uVar7 < (uVar10 + 1 & 0xff); uVar7 = uVar7 + 1 & 0xff) {
                puVar5[uVar7 - 0x32] = puVar4[uVar7];
              }
              *(undefined1 *)(iVar2 + 3) = 2;
            }
            *(undefined1 *)(DAT_0000906c + 0xe) = 0;
          }
        }
        goto LAB_00008fbe;
      }
      DAT_00009070[uVar10] = uVar1;
      uVar7 = uVar10 + 1 & 0xff;
      *(char *)(iVar3 + 0xe) = (char)(uVar10 + 1);
      if ((uVar7 == 2) && (puVar4[1] == '@')) {
        *(undefined1 *)(iVar3 + 0xf) = 6;
        *(undefined1 *)(iVar3 + 0xd) = 1;
        goto LAB_00008fbe;
      }
      if ((*(char *)(iVar3 + 0xd) == '\0') && (uVar7 == 3)) {
        if (0x31 < (byte)puVar4[2] + 5) {
          *(undefined1 *)(iVar3 + 0xf) = 7;
          goto LAB_00008fbc;
        }
        *(char *)(iVar3 + 0xf) = (char)((byte)puVar4[2] + 5);
      }
      puVar5 = DAT_00009070;
      bVar6 = *(byte *)(iVar3 + 0xf);
      if (uVar7 == bVar6) {
        if (*(char *)(iVar3 + 3) == '\0') {
          for (uVar7 = 0; uVar7 < bVar6; uVar7 = uVar7 + 1 & 0xff) {
            puVar5[uVar7 - 0x32] = puVar4[uVar7];
          }
          *(undefined1 *)(iVar3 + 3) = 1;
          *(byte *)(iVar3 + 7) = bVar6;
        }
        *(undefined1 *)(iVar3 + 0xe) = 0;
        *(undefined1 *)(iVar3 + 0xd) = 0;
      }
    }
    else {
LAB_00008fbc:
      *(undefined1 *)(iVar3 + 0xe) = 0;
    }
    goto LAB_00008fbe;
  }
  if (uVar8 == 0x74) {
    *(undefined1 *)(iVar3 + 6) = 0;
LAB_00008f60:
    *puVar4 = uVar1;
    *(undefined1 *)(iVar3 + 0xe) = 1;
  }
  else {
    if (uVar8 == 100) {
      *(undefined1 *)(iVar3 + 6) = 1;
      goto LAB_00008f60;
    }
    if ((*DAT_00009074 != '\0') &&
       ((((uVar8 == 6 || (uVar8 == 0x15)) || (uVar8 == 0x18)) || (uVar8 == 0x43)))) {
      *(undefined1 *)(iVar3 + 6) = 2;
      DAT_00009070[-0x32] = uVar1;
      *(undefined1 *)(iVar3 + 0xe) = 0;
      *(undefined1 *)(iVar3 + 7) = 1;
      *(undefined1 *)(iVar3 + 3) = 3;
    }
  }
  *(undefined1 *)(iVar3 + 0xf) = 7;
LAB_00008fbe:
  iVar2 = DAT_00009068;
  if ((*(uint *)(DAT_00009068 + 0x20) & 1) != 0) {
    *(undefined4 *)(DAT_00009068 + 0x20) = 1;
    iVar3 = DAT_0000906c;
    bVar6 = *(byte *)(DAT_0000906c + 1);
    if ((uint)bVar6 != (uint)*(byte *)(DAT_0000906c + 2)) {
      *(uint *)(iVar2 + 0xc) = (uint)(byte)DAT_00009070[bVar6 + 0x32];
      bVar6 = bVar6 + 1;
      *(byte *)(iVar3 + 1) = bVar6;
    }
    if (0x95 < bVar6) {
      *(undefined1 *)(iVar3 + 1) = 0;
    }
    *(undefined1 *)(iVar3 + 5) = 5;
  }
  *(undefined4 *)(iVar2 + 0x20) = 0x1c;
  return;
}



/* ===== FUN_00009080 @ 0x9080 ===== */

void __stdcall_softfp FUN_00009080(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_00009094;
  *DAT_00009094 = 0;
  puVar1[1] = 0x13;
  puVar1[2] = 0x87;
  puVar1[7] = 3;
  return;
}



/* ===== FUN_00009098 @ 0x9098 ===== */

void __stdcall_softfp FUN_00009098(int param_1,uint param_2)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar4 = DAT_00009120;
  iVar3 = DAT_00009118;
  do {
    if (*(int *)(DAT_0000911c + 0x14) << 0x1e < 0) break;
  } while (*(char *)(DAT_00009118 + 0xd) != '\0');
  cVar1 = *(char *)(DAT_00009118 + 10);
  for (uVar5 = 0; uVar5 < param_2; uVar5 = uVar5 + 1 & 0xff) {
    bVar2 = *(byte *)(iVar3 + 10);
    *(undefined1 *)(iVar4 + (uint)bVar2) = *(undefined1 *)(param_1 + uVar5);
    uVar6 = bVar2 + 1;
    *(char *)(iVar3 + 10) = (char)uVar6;
    if (0x31 < (uVar6 & 0xff)) {
      *(undefined1 *)(iVar3 + 10) = 0;
    }
  }
  *(undefined4 *)(DAT_0000911c + 0x20) = 0x1c;
  if ((*(char *)(iVar3 + 9) == cVar1) || (*(char *)(iVar3 + 0xd) == '\0')) {
    if (*(char *)(iVar3 + 9) != cVar1) {
      *(undefined1 *)(iVar3 + 10) = 0;
      *(undefined1 *)(iVar3 + 9) = 0;
      for (uVar5 = 0; uVar5 < param_2; uVar5 = uVar5 + 1 & 0xff) {
        bVar2 = *(byte *)(iVar3 + 10);
        *(undefined1 *)(iVar4 + (uint)bVar2) = *(undefined1 *)(param_1 + uVar5);
        *(byte *)(iVar3 + 10) = bVar2 + 1;
      }
    }
    bVar2 = *(byte *)(iVar3 + 9);
    *(uint *)(DAT_0000911c + 0xc) = (uint)*(byte *)(iVar4 + (uint)bVar2);
    uVar5 = bVar2 + 1;
    *(char *)(iVar3 + 9) = (char)uVar5;
    if (0x31 < (uVar5 & 0xff)) {
      *(undefined1 *)(iVar3 + 9) = 0;
    }
  }
  return;
}



/* ===== FUN_00009148 @ 0x9148 ===== */

void __stdcall_softfp FUN_00009148(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0000915c;
  *DAT_0000915c = 0;
  puVar1[1] = 0x13;
  puVar1[2] = 0x87;
  puVar1[7] = 3;
  return;
}



/* ===== FUN_00009160 @ 0x9160 ===== */

void __stdcall_softfp FUN_00009160(int param_1,uint param_2)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  iVar5 = DAT_000091c8;
  iVar4 = DAT_000091c4;
  iVar3 = DAT_000091c0;
  do {
    if (*(int *)(DAT_000091c0 + 0x14) << 0x1e < 0) break;
  } while (*(char *)(DAT_000091c4 + 5) != '\0');
  bVar1 = *(byte *)(DAT_000091c4 + 2);
  for (uVar6 = 0; uVar6 < param_2; uVar6 = uVar6 + 1 & 0xff) {
    bVar2 = *(byte *)(iVar4 + 2);
    *(undefined1 *)(iVar5 + (uint)bVar2) = *(undefined1 *)(param_1 + uVar6);
    uVar7 = bVar2 + 1;
    *(char *)(iVar4 + 2) = (char)uVar7;
    if (0x95 < (uVar7 & 0xff)) {
      *(undefined1 *)(iVar4 + 2) = 0;
    }
  }
  *(undefined4 *)(iVar3 + 0x20) = 0x1c;
  uVar6 = (uint)*(byte *)(iVar4 + 1);
  if ((uVar6 == bVar1) || (*(char *)(iVar4 + 5) == '\0')) {
    *(uint *)(iVar3 + 0xc) = (uint)*(byte *)(iVar5 + uVar6);
    *(char *)(iVar4 + 1) = (char)(uVar6 + 1);
    if (0x95 < (uVar6 + 1 & 0xff)) {
      *(undefined1 *)(iVar4 + 1) = 0;
    }
  }
  return;
}



/* ===== uart_command_parser @ 0x91CC ===== */

/* WARNING: Function: __ARM_common_switch8 replaced with injection: switch8_r3 */
/* WARNING (jumptable): Removing unreachable block (ram,0x000094be) */
/* WARNING (jumptable): Removing unreachable block (ram,0x000094dc) */
/* WARNING: Removing unreachable block (ram,0x000094be) */
/* WARNING: Removing unreachable block (ram,0x000094dc) */
/* Large UART packet parser handling command families 0x51 0x52 and 0x53. */

void __stdcall_softfp uart_command_parser(undefined4 param_1,undefined4 param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  bool bVar6;
  int iVar7;
  undefined1 *puVar8;
  char *pcVar9;
  undefined1 *puVar10;
  short *psVar11;
  undefined1 uVar12;
  undefined2 uVar13;
  uint uVar14;
  undefined4 uVar15;
  char cVar16;
  undefined2 *puVar17;
  uint uVar18;
  char *pcVar19;
  uint uVar20;
  uint uVar21;
  
  puVar8 = DAT_000095f8;
  iVar7 = DAT_000095b4;
  uVar21 = 0;
  bVar6 = false;
  bVar1 = DAT_000095b0[1];
  uVar14 = (uint)bVar1;
  uVar20 = (uint)*DAT_000095b0;
  bVar2 = DAT_000095b0[3];
  if ((uVar20 != 0x51) && (uVar20 != 0x52)) {
    if (uVar20 != 0x53) {
      return;
    }
    if ((uint)DAT_000095b0[2] != (uVar14 + 0x53 & 0xff)) {
      return;
    }
    if (bVar2 != 0xac) {
      return;
    }
LAB_00009202:
    uVar20 = 0;
    do {
      puVar8[uVar20] = 0;
      uVar20 = uVar20 + 1 & 0xff;
    } while (uVar20 < 0xe);
    *puVar8 = 100;
    puVar8[1] = bVar1;
    psVar11 = DAT_00009828;
    pcVar19 = DAT_000095c4;
    if (uVar14 == 0x2b) {
      uVar15 = FUN_00004d00(0,0xf000);
      iVar7 = DAT_00009810;
      *(undefined4 *)(DAT_00009810 + -0x3c) = uVar15;
      puVar8[2] = 4;
      puVar8[3] = (char)((uint)*(undefined4 *)(iVar7 + -0x3c) >> 0x18);
      puVar8[4] = (char)((uint)*(undefined4 *)(iVar7 + -0x3c) >> 0x10);
      puVar8[5] = (char)((uint)*(undefined4 *)(iVar7 + -0x3c) >> 8);
      puVar8[6] = (char)*(undefined4 *)(iVar7 + -0x3c);
    }
    else {
      if (uVar14 < 0x2c) {
                    /* WARNING: Could not recover jumptable at 0x000094be. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        if (uVar14 - 0x20 < (uint)DAT_000094c2) {
          pbVar5 = (byte *)(uVar14 + 0x94a3);
        }
        else {
          pbVar5 = (byte *)(DAT_000094c2 + 0x94c3);
        }
        (*(code *)((uint)*pbVar5 * 2 + 0x94c3))
                  (uVar14 - 0x20,iVar7,7,(uint)*pbVar5 * 2,uVar21,param_3);
        return;
      }
      if (uVar14 != 0x31) {
        if (uVar14 < 0x32) {
                    /* WARNING: Could not recover jumptable at 0x000094dc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          if (uVar14 - 0x2c < (uint)DAT_000094e0) {
            pbVar5 = (byte *)(uVar14 + 0x94b5);
          }
          else {
            pbVar5 = (byte *)(DAT_000094e0 + 0x94e1);
          }
          (*(code *)((uint)*pbVar5 * 2 + 0x94e1))();
          return;
        }
        if (uVar14 == 0x50) {
          *(undefined1 *)(iVar7 + 0xc) = 1;
        }
        else if (uVar14 == 0x51) {
          *(undefined1 *)(iVar7 + 0xd) = 1;
        }
        else if (uVar14 == 0x53) {
          *(undefined1 *)(iVar7 + 0xe) = 1;
        }
        else if (uVar14 == 0x80) {
          puVar8[2] = 2;
          puVar8[3] = (char)((ushort)*(undefined2 *)(pcVar19 + 0x3c) >> 8);
          uVar12 = (undefined1)*(undefined2 *)(pcVar19 + 0x3c);
          goto LAB_000097c2;
        }
        goto LAB_00009754;
      }
      puVar8[2] = 2;
      uVar13 = FUN_00002a60(*psVar11 * 1000,0x112);
      iVar7 = DAT_00009810;
      puVar17 = (undefined2 *)(DAT_00009810 + -0x5c);
      *puVar17 = uVar13;
      puVar8[3] = *(undefined1 *)(iVar7 + -0x5b);
      uVar12 = *(undefined1 *)puVar17;
LAB_000097c2:
      puVar8[4] = uVar12;
    }
    pcVar19 = PTR_DAT_00009814 + -100;
    cVar16 = '\0';
    for (uVar14 = 0; uVar14 < (byte)(PTR_DAT_00009814[-0x62] + 3); uVar14 = uVar14 + 1 & 0xff) {
      cVar16 = pcVar19[uVar14] + cVar16;
    }
    pcVar19[uVar14] = cVar16;
    uVar14 = uVar14 + 1 & 0xff;
    pcVar19[uVar14] = -1 - *pcVar19;
    uVar14 = uVar14 + 1 & 0xff;
    goto LAB_000097ee;
  }
  param_3 = DAT_000095b0[2] + 3 & 0xff;
  for (uVar18 = 0; uVar18 < param_3; uVar18 = uVar18 + 1 & 0xff) {
    uVar21 = DAT_000095b0[uVar18] + uVar21 & 0xff;
  }
  if (DAT_000095b0[param_3] != uVar21) {
    return;
  }
  if (DAT_000095b0[param_3 + 1] + uVar20 != 0xff) {
    return;
  }
  bVar3 = DAT_000095b0[5];
  uVar21 = (uint)bVar3;
  bVar4 = DAT_000095b0[4];
  uVar18 = (uint)bVar4;
  if (uVar20 == 0x51) {
    if (uVar14 == 0x10) {
      *DAT_000095b8 = bVar2 & 0xf;
      *DAT_000095bc = bVar2 >> 4;
      *DAT_000095c0 = bVar4 >> 7;
      pcVar19 = DAT_000095c4;
      DAT_000095c4[0x1a] = (char)((uVar18 & 0x7f) >> 6);
      pcVar19[0x1b] = (char)((uVar18 & 0x3f) >> 5);
      pcVar19[0x19] = (char)((uVar18 & 0xf) >> 3);
      *DAT_000095c8 = bVar4 & 1;
      pcVar9 = DAT_000095d4;
      puVar8 = DAT_000095cc;
      pcVar19 = DAT_000095c4;
      if ((int)(uVar21 * 0x1000000) < 0) {
        if (*DAT_000095d4 == '\0') {
          *DAT_000095cc = 1;
        }
        *pcVar9 = '\x01';
        *DAT_000095d0 = 0;
        *(uint *)(DAT_000095d8 + 0xc) = *(uint *)(DAT_000095d8 + 0xc) | DAT_000095d8 >> 0x15;
        pcVar19[0x26] = '\0';
      }
      else if ((byte)DAT_000095c4[0x26] < 2) {
        DAT_000095c4[0x26] = DAT_000095c4[0x26] + 1;
      }
      else {
        FUN_00004a98();
        *DAT_000095d0 = 1;
        pcVar9 = DAT_000095d4;
        if (*DAT_000095d4 == '\0') {
          *puVar8 = 0;
        }
        *pcVar9 = '\x01';
        if (pcVar19[0x27] == '\0') {
          FUN_00007c94();
          pcVar19[0x27] = '\x01';
        }
        *(uint *)(DAT_000095d8 + 0xc) = *(uint *)(DAT_000095d8 + 0xc) & ~(DAT_000095d8 >> 0x15);
      }
      pbVar5 = DAT_000095b0;
      bVar1 = DAT_000095b0[5];
      uVar14 = (uint)bVar1;
      bVar2 = pcVar19[0x28];
      if ((int)(uVar14 << 0x19) < 0) {
        if (bVar2 < 3) {
          cVar16 = '\x01';
LAB_0000930e:
          pcVar19[0x28] = bVar2 + cVar16;
        }
        else {
          *DAT_000095dc = 1;
        }
      }
      else {
        if (bVar2 != 0) {
          cVar16 = -1;
          goto LAB_0000930e;
        }
        *DAT_000095dc = 0;
      }
      *DAT_000095e0 = (char)((uVar14 & 0x3f) >> 5);
      *DAT_000095e4 = (char)((uVar14 & 0xf) >> 3);
      pcVar19 = DAT_000095c4;
      DAT_000095c4[0x17] = (char)((uVar14 & 7) >> 2);
      *DAT_000095e8 = (char)((uVar14 & 3) >> 1);
      *DAT_000095ec = bVar1 & 1;
      *DAT_000095f0 = (ushort)pbVar5[6];
      *DAT_000095f4 = (ushort)pbVar5[7];
      if (pbVar5[8] < 0x65) {
        pcVar19[0x18] = pbVar5[8];
      }
      bVar1 = pbVar5[9];
      pcVar19[4] = bVar1 >> 7;
      pcVar19[5] = (char)((bVar1 & 0x7f) >> 6);
      pcVar19[6] = (char)((bVar1 & 0x3f) >> 5);
      pcVar19[8] = bVar1 & 0xf;
      pcVar19[0x1c] = '\0';
      pcVar19[3] = '\0';
    }
  }
  else if (uVar20 == 0x52) {
    uVar21 = 0;
    do {
      puVar8[uVar21] = 0;
      uVar21 = uVar21 + 1 & 0xff;
    } while (uVar21 < 0xe);
    *puVar8 = 0x65;
    puVar8[1] = bVar1;
    puVar8[2] = 0x4f;
    pbVar5 = DAT_000095b0;
    puVar8[3] = 0x4b;
    psVar11 = DAT_000095fc;
    puVar10 = DAT_000095f8;
    pcVar19 = DAT_000095c4;
    if (uVar14 == 0x18) {
      if (bVar2 == 1) {
        if (*DAT_000095c4 == '\0') {
          *DAT_000095c4 = '\x01';
          FUN_00007c94();
        }
        uVar12 = 0x17;
        goto LAB_00009482;
      }
    }
    else {
      if (uVar14 < 0x19) {
        if (uVar14 != 0x14) {
          if (uVar14 == 0x15) {
            uVar14 = 0;
            do {
              pcVar19[uVar14 + 0xa0] = pbVar5[uVar14 + 3];
              uVar14 = uVar14 + 1 & 0xff;
            } while (uVar14 < 0x12);
            FUN_00007e08();
            uVar12 = 0x14;
          }
          else {
            if ((uVar14 != 0x16) || (*DAT_000095c4 != '\0')) goto LAB_00009754;
            uVar14 = 0;
            do {
              pcVar19[uVar14 + 0x89] = pbVar5[uVar14 + 3];
              uVar14 = uVar14 + 1 & 0xff;
            } while (uVar14 < 0x14);
            FUN_00007e08();
            uVar12 = 0x15;
          }
          puVar8[4] = uVar12;
          uVar12 = 0x9c;
          goto LAB_00009486;
        }
        *DAT_000095fc = (ushort)bVar2 * 0x100 + (ushort)bVar4;
        *(byte *)(psVar11 + 1) = bVar3 >> 4;
        *(byte *)((int)psVar11 + 3) = bVar3 & 0xf;
        *(byte *)(psVar11 + 2) = pbVar5[6];
        bVar1 = pbVar5[7];
        *(byte *)((int)psVar11 + 5) = bVar1 >> 7;
        *(char *)(psVar11 + 3) = (char)((bVar1 & 0x7f) >> 6);
        *(byte *)((int)psVar11 + 7) = bVar1 & 0x1f;
        *(byte *)(psVar11 + 4) = pbVar5[8];
        *(byte *)((int)psVar11 + 9) = pbVar5[9];
        puVar8[4] = 0x13;
        puVar8[5] = 0x9c;
        *(undefined1 *)(iVar7 + 7) = 1;
        *DAT_00009600 = 0;
      }
      else {
        if (uVar14 == 0x1a) {
          if (*DAT_000095c4 != '\0') goto LAB_00009754;
          uVar14 = 0;
          do {
            puVar10[uVar14 + 100] = pbVar5[uVar14 + 3];
            uVar14 = uVar14 + 1 & 0xff;
          } while (uVar14 < 0x10);
          FUN_00007c94();
          uVar12 = 0x19;
        }
        else if (uVar14 == 0x1b) {
          DAT_000095c4[7] = DAT_000095b0[3] & 1;
          uVar12 = 0x1a;
        }
        else {
          if (uVar14 != 0x53) goto LAB_00009754;
          *(byte *)(iVar7 + 0xe) = DAT_000095b0[3] & 1;
          uVar12 = 0x52;
        }
LAB_00009482:
        puVar8[4] = uVar12;
        uVar12 = 0x9a;
LAB_00009486:
        puVar8[5] = uVar12;
      }
      bVar6 = true;
    }
  }
  else if (uVar20 == 0x53) goto LAB_00009202;
LAB_00009754:
  if (!bVar6) {
    return;
  }
  uVar14 = 6;
LAB_000097ee:
  FUN_00009098(PTR_DAT_00009814 + -100,uVar14);
  *(undefined1 *)(DAT_00009810 + -0x8a) = 1;
  return;
}



/* ===== FUN_0000982c @ 0x982C ===== */

/* WARNING: Function: __ARM_common_switch8 replaced with injection: switch8_r3 */
/* WARNING (jumptable): Removing unreachable block (ram,0x00009844) */
/* WARNING: Removing unreachable block (ram,0x00009844) */

void __stdcall_softfp FUN_0000982c(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_r3;
  int iVar3;
  
  uVar2 = FUN_000086f0(DAT_00009b80);
                    /* WARNING: Could not recover jumptable at 0x00009844. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = uVar2;
  if (DAT_00009848 <= uVar2) {
    uVar1 = (uint)DAT_00009848;
  }
  iVar3 = (uint)*(byte *)(uVar1 + 0x9849) * 2;
  (*(code *)(iVar3 + 0x9849))(uVar2,DAT_00009b80,0,iVar3,in_r3);
  return;
}



/* ===== FUN_00009bb8 @ 0x9BB8 ===== */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __stdcall_softfp FUN_00009bb8(void)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *extraout_r3;
  int iVar7;
  bool bVar8;
  char local_9c [136];
  
  FUN_00002a40(local_9c,0x88);
  pcVar6 = DAT_00009df8;
  iVar3 = DAT_00009df4;
  iVar7 = 0;
  if (*DAT_00009df0 != '\x01') {
    if (*DAT_00009df0 == '\x04') {
      if (*DAT_00009df8 != '\0') {
        *DAT_00009dfc = '\x01';
        *pcVar6 = '\0';
      }
      local_9c[0] = '\x06';
      iVar7 = 1;
      *(undefined1 *)(iVar3 + 0xf) = 0;
    }
    goto LAB_00009db8;
  }
  if (*(char *)(DAT_00009df4 + -0xd) != '\0') {
    *(undefined1 *)(DAT_00009df4 + -0xd) = 0;
    *(undefined1 *)(iVar3 + -0xb) = 1;
  }
  bVar8 = (uint)(byte)DAT_00009df0[1] == 0xff - (byte)DAT_00009df0[2];
  pcVar6 = DAT_00009df0;
  do {
    if (!bVar8) {
      bVar2 = *(byte *)(iVar3 + 0xe);
      *(byte *)(iVar3 + 0xe) = bVar2 + 1;
      if (bVar2 < 0x11) goto LAB_00009d76;
      *(undefined1 *)(iVar3 + 0xe) = 0;
      goto LAB_00009d82;
    }
    bVar2 = pcVar6[0x83];
    bVar1 = pcVar6[0x84];
    uVar5 = FUN_00004410(pcVar6 + 3,0x80);
    iVar4 = DAT_00009df4;
    bVar8 = (ushort)((ushort)bVar2 * 0x100 + (ushort)bVar1) == uVar5;
    pcVar6 = extraout_r3;
  } while (!bVar8);
  *(undefined1 *)(DAT_00009df4 + -2) = 0;
  *(int *)(iVar4 + 0x34) = *(int *)(iVar4 + 0x34) + 1;
  *(undefined1 *)(iVar3 + 0xe) = 0;
  if (*(int *)(iVar4 + 0x2c) == 0) {
    *(undefined4 *)(iVar4 + 0x3c) = 0;
    *(undefined4 *)(iVar4 + 0x54) = 0xf000;
    *(undefined1 *)(iVar3 + 0xf) = 0;
    pcVar6 = DAT_00009df0;
    *(uint *)(iVar4 + 0x30) =
         (uint)(byte)DAT_00009df0[6] + (uint)(byte)DAT_00009df0[3] * 0x1000000 +
         (uint)(byte)DAT_00009df0[4] * 0x10000 + (uint)(byte)DAT_00009df0[5] * 0x100;
    *(ushort *)(iVar4 + 0x16) = (ushort)(byte)pcVar6[7] * 0x100 + (ushort)(byte)pcVar6[8];
    *(uint *)(iVar4 + 0x38) =
         (uint)(byte)pcVar6[0xc] + (uint)(byte)pcVar6[9] * 0x1000000 +
         (uint)(byte)pcVar6[10] * 0x10000 + (uint)(byte)pcVar6[0xb] * 0x100;
    *(ushort *)(iVar4 + 0x18) = (ushort)(byte)pcVar6[0xd] * 0x100 + (ushort)(byte)pcVar6[0xe];
    *(uint *)(iVar4 + 0x40) =
         (uint)(byte)pcVar6[0x12] + (uint)(byte)pcVar6[0xf] * 0x1000000 +
         (uint)(byte)pcVar6[0x10] * 0x10000 + (uint)(byte)pcVar6[0x11] * 0x100;
    *(ushort *)(iVar4 + 0x1a) = (ushort)(byte)pcVar6[0x13] * 0x100 + (ushort)(byte)pcVar6[0x14];
    *(char *)(iVar4 + 100) = pcVar6[0x15];
    *(char *)(iVar4 + 0x65) = pcVar6[0x16];
    *(char *)(iVar4 + 0x66) = pcVar6[0x17];
    *(char *)(iVar4 + 0x67) = pcVar6[0x18];
    *(char *)(iVar4 + 0x68) = pcVar6[0x19];
    if (*(int *)(iVar4 + 0x40) != 0) {
      *(undefined1 *)(iVar4 + -0xe) = 1;
      *(undefined1 *)(iVar4 + -0xb) = 1;
      *(int *)(iVar4 + 0x2c) = *(int *)(iVar4 + 0x2c) + 1;
    }
  }
  pcVar6 = DAT_00009df0;
  if (*(char *)(iVar4 + -0xb) != '\0') {
    *(short *)(iVar4 + 0x14) = *(short *)(iVar4 + 0x14) + 1;
    if (((0xf < *(ushort *)(iVar4 + 0x14)) && (DAT_00009df0[1] == '\x10')) &&
       (*(char *)(iVar4 + -0xf) == '\0')) {
      *(undefined1 *)(iVar4 + -0xf) = 1;
      *(undefined1 *)(iVar4 + -0xc) = 1;
    }
    goto LAB_00009db8;
  }
  if (0x1b800 < *(uint *)(iVar4 + 0x38)) {
LAB_00009d82:
    local_9c[0] = '\x18';
    local_9c[1] = 0x18;
    local_9c[2] = 0x18;
    iVar7 = 3;
    FUN_00004cac();
    goto LAB_00009db8;
  }
  if ((*DAT_00009df8 == '\x01') && (*DAT_00009dfc == '\0')) {
LAB_00009d52:
    local_9c[0] = '\x06';
  }
  else {
    bVar2 = DAT_00009df0[1];
    if (((uint)bVar2 == *(byte *)(iVar3 + 0xf) + 1) && (*(int *)(iVar4 + 0x3c) + 0x18U < 0xc801)) {
      *(byte *)(iVar3 + 0xf) = bVar2;
      if ((0xf < *(uint *)(iVar4 + 0x2c)) &&
         (*(uint *)(iVar4 + 0x2c) < (*(uint *)(iVar4 + 0x38) >> 7) + 0x10)) {
        FUN_00004eac(*(undefined4 *)(iVar4 + 0x54),pcVar6 + 3,0x80);
        if (*(int *)(iVar4 + 0x54) == 0xf000) {
          *(undefined4 *)(iVar4 + 0x3c) = _DAT_0000f000;
          *(int *)(iVar4 + 0x3c) = *(int *)(iVar4 + 0x3c) + 0x18;
        }
        *(int *)(iVar4 + 0x54) = *(int *)(iVar4 + 0x54) + 0x80;
      }
      *(int *)(iVar4 + 0x2c) = *(int *)(iVar4 + 0x2c) + 1;
      goto LAB_00009d52;
    }
    if ((uint)bVar2 == (uint)*(byte *)(iVar3 + 0xf)) goto LAB_00009d52;
    if (0xc800 < *(uint *)(iVar4 + 0x3c)) {
      *(undefined1 *)(iVar3 + 0xe) = 0;
      goto LAB_00009d82;
    }
    *(undefined1 *)(iVar3 + 0xe) = 1;
LAB_00009d76:
    local_9c[0] = '\x15';
  }
  iVar7 = 1;
LAB_00009db8:
  if (*(char *)(DAT_00009df4 + -0xb) == '\x01') {
    bVar2 = *(byte *)(DAT_00009df4 + -0x10);
    for (uVar5 = 0; uVar5 < bVar2; uVar5 = uVar5 + 1 & 0xffff) {
      local_9c[uVar5] = DAT_00009df0[uVar5];
    }
    FUN_00009160(local_9c);
  }
  else if (iVar7 != 0) {
    FUN_00009098(local_9c,iVar7);
  }
  return;
}



/* ===== FUN_00009e00 @ 0x9E00 ===== */

void __stdcall_softfp FUN_00009e00(void)

{
  int iVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = DAT_00009e48;
  iVar4 = 0;
  uVar3 = 0;
  do {
    iVar4 = *(short *)(DAT_00009e44 + uVar3 * 2) + iVar4;
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 4);
  iVar4 = iVar4 >> 6;
  if (iVar4 < 0) {
    iVar4 = 0;
  }
  *(short *)(DAT_00009e48 + 8) = (short)iVar4;
  if (DAT_00009e4c < *(ushort *)(iVar1 + 8)) {
    *(undefined1 *)(iVar1 + 4) = 0;
    *(undefined1 *)(iVar1 + 5) = 0;
  }
  else {
    bVar2 = *(char *)(iVar1 + 5) + 1;
    *(byte *)(iVar1 + 5) = bVar2;
    if (10 < bVar2) {
      *(undefined1 *)(iVar1 + 5) = 10;
      *(undefined1 *)(iVar1 + 4) = 1;
      return;
    }
  }
  return;
}



/* ===== FUN_00009e50 @ 0x9E50 ===== */

int __stdcall_softfp FUN_00009e50(int param_1,int param_2,int param_3)

{
  if (param_2 < param_1) {
    if (param_2 + param_3 < param_1) {
      return param_1 - param_3;
    }
  }
  else if ((param_1 < param_2) && (param_1 + param_3 < param_2)) {
    return param_1 + param_3;
  }
  return param_2;
}



/* ===== FUN_00009e6e @ 0x9E6E ===== */

int __stdcall_softfp FUN_00009e6e(int param_1,int param_2,int param_3)

{
  if (param_1 < param_2) {
    param_1 = param_2;
  }
  if (param_3 < param_1) {
    param_1 = param_3;
  }
  return param_1;
}



/* ===== __ARM_common_switch8 @ 0x9E7C ===== */

/* WARNING: This is an inlined function */

void __stdcall_softfp __ARM_common_switch8(void)

{
  uint in_r3;
  uint uVar1;
  int in_lr;
  
  uVar1 = (uint)*(byte *)(in_lr + -1);
  if (in_r3 < *(byte *)(in_lr + -1)) {
    uVar1 = in_r3;
  }
                    /* WARNING: Could not recover jumptable at 0x00009e94. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(in_lr + (uint)*(byte *)(in_lr + uVar1) * 2))();
  return;
}



/* ===== FUN_00009e98 @ 0x9E98 ===== */

void __stdcall_softfp FUN_00009e98(uint param_1)

{
  if (-1 < (int)param_1) {
    *DAT_00009eac = 1 << (param_1 & 0x1f);
  }
  return;
}



/* ===== FUN_00009ed0 @ 0x9ED0 ===== */

void __stdcall_softfp FUN_00009ed0(uint param_1)

{
  if (-1 < (int)param_1) {
    *DAT_00009eec = 1 << (param_1 & 0x1f);
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  return;
}



/* ===== FUN_00009ef0 @ 0x9EF0 ===== */

void __stdcall_softfp FUN_00009ef0(uint param_1)

{
  if (-1 < (int)param_1) {
    *DAT_00009f04 = 1 << (param_1 & 0x1f);
  }
  return;
}



/* ===== FUN_00009f08 @ 0x9F08 ===== */

void __stdcall_softfp FUN_00009f08(uint param_1,uint param_2)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = (param_1 & 3) << 3;
  uVar3 = 0xff << iVar4;
  uVar2 = ((param_2 & 3) << 6) << iVar4;
  if (-1 < (int)param_1) {
    puVar1 = (uint *)((param_1 & 0xfffffffc) + DAT_00009f44);
    *puVar1 = *puVar1 & ~uVar3 | uVar2;
    return;
  }
  iVar4 = ((param_1 & 0xf) - 8 & 0xfffffffc) + DAT_00009f48;
  *(uint *)(iVar4 + 0x1c) = *(uint *)(iVar4 + 0x1c) & ~uVar3 | uVar2;
  return;
}



/* ===== FUN_00009f4c @ 0x9F4C ===== */

void __stdcall_softfp
FUN_00009f4c(undefined4 *param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined8 uVar2;
  undefined4 uVar3;
  
  uVar2 = *(undefined8 *)(param_1 + param_2 * 2 + -2);
  uVar3 = param_4;
  while( true ) {
    uVar1 = (undefined4)((ulonglong)uVar2 >> 0x20);
    param_2 = param_2 - 1;
    if ((param_2 & 0xfffffff9) == 0) break;
    uVar2 = FUN_000034e0((int)uVar2,uVar1,param_3,param_4,uVar3);
    uVar2 = FUN_00002f2c((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),param_1[param_2 * 2 + -2],
                         (param_1 + param_2 * 2 + -2)[1]);
  }
  if (param_2 != 2) {
    if (param_2 != 4) {
      if (param_2 != 6) {
        return;
      }
      uVar2 = FUN_000034e0((int)uVar2,uVar1,param_3,param_4,uVar3);
      uVar2 = FUN_00002f2c((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),param_1[10],param_1[0xb]);
      uVar2 = FUN_000034e0((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),param_3,param_4);
      uVar2 = FUN_00002f2c((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),param_1[8],param_1[9]);
    }
    uVar2 = FUN_000034e0((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),param_3,param_4,uVar3);
    uVar2 = FUN_00002f2c((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),param_1[6],param_1[7]);
    uVar2 = FUN_000034e0((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),param_3,param_4);
    uVar2 = FUN_00002f2c((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),param_1[4],param_1[5]);
  }
  uVar2 = FUN_000034e0((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),param_3,param_4,uVar3);
  uVar2 = FUN_00002f2c((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),param_1[2],param_1[3]);
  uVar2 = FUN_000034e0((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),param_3,param_4);
  FUN_00002f2c((int)uVar2,(int)((ulonglong)uVar2 >> 0x20),*param_1,param_1[1]);
  return;
}



/* ===== FUN_00009ff8 @ 0x9FF8 ===== */

void __stdcall_softfp FUN_00009ff8(void)

{
  FUN_00002f8c(0,DAT_0000a008,0,0);
  return;
}



/* ===== FUN_0000a00c @ 0xA00C ===== */

void __stdcall_softfp FUN_0000a00c(undefined4 param_1,undefined4 param_2)

{
  FUN_0000399c(param_1,param_2,1);
  return;
}



/* ===== FUN_0000a016 @ 0xA016 ===== */

void __stdcall_softfp FUN_0000a016(void)

{
  FUN_00002f8c(0,0,0,0);
  return;
}



/* ===== FUN_0000a026 @ 0xA026 ===== */

void __stdcall_softfp FUN_0000a026(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  do {
    uVar1 = 0;
    iVar3 = uVar2 * 4 + param_1;
    do {
      *(byte *)(iVar3 + uVar1) = *(byte *)(iVar3 + uVar1) ^ *(byte *)(uVar1 * 4 + param_2 + uVar2);
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 4);
    uVar2 = uVar2 + 1 & 0xff;
  } while (uVar2 < 4);
  return;
}



/* ===== FUN_0000a04e @ 0xA04E ===== */

void __stdcall_softfp FUN_0000a04e(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_c8 [160];
  undefined1 auStack_28 [20];
  
  FUN_0000a1c4(param_2,auStack_c8);
  if (param_3 == 0) {
    FUN_0000a026(param_1,auStack_28);
    iVar1 = 9;
    do {
      FUN_0000a9a0(param_1,0);
      FUN_0000a9e8(param_1,0);
      FUN_0000a026(param_1,auStack_c8 + iVar1 * 0x10);
      if (iVar1 != 0) {
        FUN_0000a850(param_1,0);
      }
      iVar1 = iVar1 + -1;
    } while (-1 < iVar1);
  }
  else {
    FUN_0000a026(param_1,auStack_c8);
    iVar1 = 1;
    do {
      FUN_0000a9e8(param_1,param_3);
      FUN_0000a9a0(param_1,param_3);
      if (iVar1 != 10) {
        FUN_0000a850(param_1,param_3);
      }
      FUN_0000a026(param_1,auStack_c8 + iVar1 * 0x10);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0xb);
  }
  return;
}



/* ===== FUN_0000a0d8 @ 0xA0D8 ===== */

uint __stdcall_softfp FUN_0000a0d8(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  
  uVar2 = 0;
  if ((param_2 & 8) != 0) {
    bVar3 = 1;
    uVar2 = param_1;
    do {
      uVar2 = (uVar2 & 0x7fff) * 2;
      if (0xff < uVar2) {
        uVar2 = uVar2 ^ 0x11b;
      }
      bVar3 = bVar3 + 1;
    } while (bVar3 < 4);
    uVar2 = uVar2 & 0xff;
  }
  if ((param_2 & 4) != 0) {
    bVar3 = 1;
    uVar1 = param_1;
    do {
      uVar1 = (uVar1 & 0x7fff) * 2;
      if (0xff < uVar1) {
        uVar1 = uVar1 ^ 0x11b;
      }
      bVar3 = bVar3 + 1;
    } while (bVar3 < 3);
    uVar2 = uVar2 ^ uVar1 & 0xff;
  }
  if ((param_2 & 2) != 0) {
    uVar1 = param_1 * 2;
    if (0xff < uVar1) {
      uVar1 = uVar1 ^ 0x11b;
    }
    uVar2 = uVar2 ^ uVar1 & 0xff;
  }
  if ((param_2 & 1) != 0) {
    uVar2 = uVar2 ^ param_1;
  }
  return uVar2;
}



/* ===== FUN_0000a150 @ 0xA150 ===== */

void __stdcall_softfp FUN_0000a150(uint param_1)

{
  uint *puVar1;
  undefined2 *puVar2;
  
  puVar1 = DAT_0000a168;
  *DAT_0000a168 = *DAT_0000a168 | 4;
  puVar1[1] = param_1;
  puVar2 = DAT_0000a16c;
  *DAT_0000a16c = (short)puVar1[4];
  puVar2[1] = (short)puVar1[5];
  return;
}



/* ===== FUN_0000a170 @ 0xA170 ===== */

undefined8 __stdcall_softfp FUN_0000a170(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uStack_20;
  
  uVar1 = FUN_0000ab64(*param_1,param_1[4]);
  param_1[1] = uVar1;
  uVar2 = FUN_0000ab64(uVar1,param_1[5]);
  uVar2 = FUN_0000377c(uVar1,uVar2);
  param_1[3] = uVar2;
  uVar4 = param_1[2];
  uVar3 = FUN_0000aca0(param_2,uVar4);
  uVar3 = FUN_0000abf0(uVar3,uVar2);
  uVar3 = FUN_0000ab64(uVar3,uVar4);
  param_1[2] = uVar3;
  uVar2 = FUN_0000aca0(0x3f800000,uVar2);
  uVar1 = FUN_0000abf0(uVar2,uVar1);
  *param_1 = uVar1;
  return CONCAT44(uStack_20,uVar3);
}



/* ===== FUN_0000a1c4 @ 0xA1C4 ===== */

void __stdcall_softfp FUN_0000a1c4(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_18;
  
  uVar3 = 0;
  do {
    uVar2 = 0;
    do {
      *(undefined1 *)(uVar3 * 4 + param_2 + uVar2) = *(undefined1 *)(uVar2 * 4 + param_1 + uVar3);
      uVar2 = uVar2 + 1 & 0xff;
    } while (uVar2 < 4);
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 4);
  uVar3 = 1;
LAB_0000a1ea:
  iVar4 = uVar3 * 0x10 + param_2;
  uVar2 = 0;
  do {
    local_18 = CONCAT13(*(undefined1 *)(iVar4 + -4),*(undefined3 *)(iVar4 + -3));
    uVar1 = 0;
    do {
      *(undefined1 *)((int)&local_18 + uVar1) =
           *(undefined1 *)
            ((uint)(*(byte *)((int)&local_18 + uVar1) >> 4) * 0x10 + DAT_0000a290 +
            (*(byte *)((int)&local_18 + uVar1) & 0xf));
      if (uVar1 == 0) {
        local_18 = CONCAT31(local_18._1_3_,(byte)local_18 ^ *(byte *)(DAT_0000a294 + uVar3 + -1));
      }
      uVar1 = uVar1 + 1 & 0xff;
    } while (uVar1 < 4);
    while( true ) {
      uVar1 = 0;
      iVar5 = iVar4 + uVar2 * 4;
      do {
        *(byte *)(iVar5 + uVar1) =
             *(byte *)(iVar5 + uVar1 + -0x10) ^ *(byte *)((int)&local_18 + uVar1);
        uVar1 = uVar1 + 1 & 0xff;
      } while (uVar1 < 4);
      uVar2 = uVar2 + 1 & 0xff;
      if (3 < uVar2) {
        uVar3 = uVar3 + 1 & 0xff;
        if (10 < uVar3) {
          return;
        }
        goto LAB_0000a1ea;
      }
      if (uVar2 == 0) break;
      local_18 = *(undefined4 *)(iVar4 + uVar2 * 4 + -4);
    }
  } while( true );
}



/* ===== FUN_0000a298 @ 0xA298 ===== */

undefined4 __stdcall_softfp FUN_0000a298(int param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  undefined4 *puVar15;
  char cVar16;
  undefined8 uVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  
  uVar17 = CONCAT44(param_2,param_1);
  iVar13 = 0;
  if ((((int)DAT_0000a5b0 <= (int)param_2) || (DAT_0000a5b0 < (param_2 & 0x7fffffff))) ||
     (((param_2 & 0x7fffffff) == 0x7ff00000 && (param_1 != 0)))) {
    uVar1 = FUN_0000a00c();
    return uVar1;
  }
  if ((int)param_2 < 0x100000) {
    if ((param_2 & 0x7fffffff) == 0 && param_1 == 0) {
      FUN_00003990(2);
      uVar1 = FUN_00009ff8();
      return uVar1;
    }
    if ((int)param_2 < 0) {
      FUN_00003990(1);
      uVar1 = FUN_0000a016();
      return uVar1;
    }
    iVar13 = -0x36;
    uVar17 = FUN_0000399c(param_1,param_2,0x36);
  }
  uVar2 = (uint)((ulonglong)uVar17 >> 0x20);
  uVar12 = uVar2 & 0xfffff;
  uVar14 = uVar12 + DAT_0000a5b8 & 0x100000;
  iVar13 = ((int)uVar14 >> 0x14) + ((int)uVar2 >> 0x14) + iVar13 + DAT_0000a5b4;
  uVar17 = FUN_00002f46((int)uVar17,uVar14 ^ DAT_0000a5bc | uVar12,0);
  uVar6 = (undefined4)((ulonglong)uVar17 >> 0x20);
  uVar1 = (undefined4)uVar17;
  uVar2 = uVar12 + 2 & 0xfffff;
  puVar15 = (undefined4 *)(DAT_0000a5c0 + 0xa338);
  cVar16 = uVar2 == 3;
  if (uVar2 < 3) {
    FUN_0000ab00(uVar1,uVar6,*puVar15,*(undefined4 *)(DAT_0000a5c0 + 0xa33c));
    if (cVar16 != '\0') {
      if (iVar13 == 0) {
        return *puVar15;
      }
      uVar17 = FUN_000034ca();
      uVar1 = (undefined4)((ulonglong)uVar17 >> 0x20);
      uVar18 = FUN_000034e0((int)uVar17,uVar1,DAT_0000a5c4,DAT_0000a5c8);
      uVar17 = FUN_000034e0((int)uVar17,uVar1,DAT_0000a5cc,DAT_0000a5d0);
      uVar1 = FUN_00002f2c((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar18,
                           (int)((ulonglong)uVar18 >> 0x20));
      return uVar1;
    }
    uVar18 = FUN_000034e0(uVar1,uVar6,DAT_0000a5d4,DAT_0000a5d8);
    uVar18 = FUN_00002f5c((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),0,DAT_0000a5dc);
    uVar19 = FUN_000034e0(uVar1,uVar6);
    uVar18 = FUN_000034e0((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,
                          (int)((ulonglong)uVar18 >> 0x20));
    if (iVar13 != 0) {
      uVar17 = FUN_000034ca();
      uVar3 = (undefined4)((ulonglong)uVar17 >> 0x20);
      uVar19 = FUN_000034e0((int)uVar17,uVar3,DAT_0000a5c4,DAT_0000a5c8);
      uVar18 = FUN_00002f5c((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,
                            (int)((ulonglong)uVar18 >> 0x20));
      uVar18 = FUN_00002f46((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar1,uVar6);
      uVar17 = FUN_000034e0((int)uVar17,uVar3,DAT_0000a5cc,DAT_0000a5d0);
      uVar1 = FUN_00002f46((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar18,
                           (int)((ulonglong)uVar18 >> 0x20));
      return uVar1;
    }
  }
  else {
    uVar17 = FUN_00002f2c(uVar1,uVar6,0,0x40000000);
    uVar17 = FUN_00002f8c(uVar1,uVar6,(int)uVar17,(int)((ulonglong)uVar17 >> 0x20));
    uVar7 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar3 = (undefined4)uVar17;
    uVar17 = FUN_000034ca(iVar13);
    uVar8 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar4 = (undefined4)uVar17;
    uVar17 = FUN_000034e0(uVar3,uVar7);
    uVar9 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar2 = uVar12 + DAT_0000a5e0;
    uVar18 = FUN_000034e0((int)uVar17,uVar9);
    uVar10 = (undefined4)((ulonglong)uVar18 >> 0x20);
    uVar5 = (undefined4)uVar18;
    uVar12 = DAT_0000a5e4 - uVar12;
    uVar18 = FUN_00009f4c(DAT_0000a5e8 + 0xa45c,3,uVar5,uVar10);
    uVar18 = FUN_000034e0((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar5,uVar10);
    uVar19 = FUN_00009f4c(DAT_0000a5e8 + 0xa474,4,uVar5,uVar10);
    uVar17 = FUN_000034e0((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar17,uVar9);
    uVar17 = FUN_00002f2c((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar18,
                          (int)((ulonglong)uVar18 >> 0x20));
    uVar9 = (undefined4)((ulonglong)uVar17 >> 0x20);
    uVar5 = (undefined4)uVar17;
    if (0 < (int)(uVar2 | uVar12)) {
      uVar17 = FUN_0000399c(uVar1,uVar6,0xffffffff);
      uVar17 = FUN_000034e0((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar1,uVar6);
      uVar11 = (undefined4)((ulonglong)uVar17 >> 0x20);
      uVar10 = (undefined4)uVar17;
      if (iVar13 == 0) {
        uVar17 = FUN_00002f2c(uVar10,uVar11,uVar5,uVar9);
        uVar17 = FUN_000034e0((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar3,uVar7);
        uVar17 = FUN_00002f5c((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar10,uVar11);
        uVar1 = FUN_00002f5c((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar1,uVar6);
        return uVar1;
      }
      uVar17 = FUN_000034e0(uVar4,uVar8,DAT_0000a5c4,DAT_0000a5c8);
      uVar18 = FUN_00002f2c(uVar10,uVar11,uVar5,uVar9);
      uVar18 = FUN_000034e0((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar3,uVar7);
      uVar17 = FUN_00002f2c((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                            (int)((ulonglong)uVar17 >> 0x20));
      uVar17 = FUN_00002f5c((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar10,uVar11);
      uVar17 = FUN_00002f46((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar1,uVar6);
      uVar18 = FUN_000034e0(uVar4,uVar8,DAT_0000a5cc,DAT_0000a5d0);
      uVar1 = FUN_00002f46((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                           (int)((ulonglong)uVar17 >> 0x20));
      return uVar1;
    }
    if (iVar13 == 0) {
      uVar17 = FUN_00002f46(uVar1,uVar6,uVar5,uVar9);
      uVar17 = FUN_000034e0((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar3,uVar7);
      uVar1 = FUN_00002f5c((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar1,uVar6);
      return uVar1;
    }
    uVar17 = FUN_000034e0(uVar4,uVar8,DAT_0000a5c4,DAT_0000a5c8);
    uVar18 = FUN_00002f46(uVar1,uVar6,uVar5,uVar9);
    uVar18 = FUN_000034e0((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar3,uVar7);
    uVar17 = FUN_00002f46((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),(int)uVar17,
                          (int)((ulonglong)uVar17 >> 0x20));
    uVar18 = FUN_00002f46((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar1,uVar6);
    uVar17 = FUN_000034e0(uVar4,uVar8,DAT_0000a5cc,DAT_0000a5d0);
  }
  uVar1 = FUN_00002f46((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),(int)uVar18,
                       (int)((ulonglong)uVar18 >> 0x20));
  return uVar1;
}



/* ===== main_scheduler_loop @ 0xA5EC ===== */

/* WARNING: Function: __ARM_common_switch8 replaced with injection: switch8_r3 */
/* WARNING (jumptable): Removing unreachable block (ram,0x0000a6e4) */
/* WARNING: Removing unreachable block (ram,0x0000a6e4) */
/* Main cooperative scheduler with modulo 5 10 100 and 250 task counters. */

void __stdcall_softfp main_scheduler_loop(void)

{
  short sVar1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined *puVar4;
  uint uVar5;
  
  controller_init_stage();
  regional_or_hardware_init();
  puVar2 = DAT_0000a820;
  do {
    pcVar3 = DAT_0000a828;
    if (*DAT_0000a828 != '\0') {
      FUN_00006044();
      FUN_00009e00();
      *pcVar3 = '\0';
    }
    pcVar3 = DAT_0000a82c;
    if (*DAT_0000a82c == '\x01') {
      uart_command_parser();
LAB_0000a652:
      *pcVar3 = '\0';
    }
    else {
      if (*DAT_0000a82c != '\x02') {
        if (*DAT_0000a82c == '\x03') {
          *puVar2 = 0;
          FUN_00009bb8();
        }
        else {
          if (*DAT_0000a82c != '\x04') goto LAB_0000a654;
          *puVar2 = 0;
          FUN_00008860();
        }
        goto LAB_0000a652;
      }
      if (*DAT_0000a830 != '\0') {
        *puVar2 = 0;
        FUN_0000982c();
        *pcVar3 = '\0';
        *DAT_0000a830 = '\0';
      }
    }
LAB_0000a654:
    pcVar3 = DAT_0000a834;
    if (*DAT_0000a834 == '\x01') {
      FUN_00003db8();
LAB_0000a67a:
      *pcVar3 = '\0';
    }
    else {
      if (*DAT_0000a834 == '\x02') {
        FUN_000042e8();
        goto LAB_0000a67a;
      }
      if (*DAT_0000a834 == '\x03') {
        FUN_00004364();
        goto LAB_0000a67a;
      }
    }
    if (*DAT_0000a838 != '\0') {
      *DAT_0000a838 = '\0';
      puVar4 = PTR_DAT_0000a83c;
      sVar1 = *(short *)(PTR_DAT_0000a83c + 2);
      *(ushort *)(PTR_DAT_0000a83c + 2) = sVar1 + 1U;
      if (4 < (ushort)(sVar1 + 1U)) {
        *(undefined2 *)(puVar4 + 2) = 0;
      }
      sVar1 = *(short *)(puVar4 + 4);
      *(ushort *)(puVar4 + 4) = sVar1 + 1U;
      if (9 < (ushort)(sVar1 + 1U)) {
        *(undefined2 *)(puVar4 + 4) = 0;
      }
      sVar1 = *(short *)(puVar4 + 6);
      *(ushort *)(puVar4 + 6) = sVar1 + 1U;
      if (99 < (ushort)(sVar1 + 1U)) {
        *(undefined2 *)(puVar4 + 6) = 0;
      }
      sVar1 = *(short *)(puVar4 + 8);
      *(ushort *)(puVar4 + 8) = sVar1 + 1U;
      if (0xf9 < (ushort)(sVar1 + 1U)) {
        *(undefined2 *)(puVar4 + 8) = 0;
      }
      sVar1 = *(short *)(puVar4 + 2);
      if (sVar1 == 0) {
        FUN_00006db0();
      }
      else if (sVar1 == 1) {
        FUN_0000aa2c();
      }
      else if (sVar1 == 2) {
        ride_mode_and_speed_target_update();
      }
      uVar5 = (uint)*(ushort *)(puVar4 + 4);
                    /* WARNING: Could not recover jumptable at 0x0000a6e4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      if (DAT_0000a6e8 <= uVar5) {
        uVar5 = (uint)DAT_0000a6e8;
      }
      (*(code *)(&DAT_0000a6e9 + (uint)(byte)(&DAT_0000a6e9)[uVar5] * 2))();
      return;
    }
  } while( true );
}



/* ===== FUN_0000a850 @ 0xA850 ===== */

void __stdcall_softfp FUN_0000a850(int param_1,int param_2)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  undefined4 uVar8;
  uint uVar9;
  int iVar10;
  byte bVar11;
  
  uVar9 = 0;
  do {
    bVar6 = *(byte *)(param_1 + uVar9);
    iVar10 = param_1 + uVar9;
    bVar7 = *(byte *)(iVar10 + 4);
    bVar11 = *(byte *)(iVar10 + 8);
    bVar1 = *(byte *)(iVar10 + 0xc);
    if (param_2 == 0) {
      bVar2 = FUN_0000a0d8(bVar6,0xe);
      bVar3 = FUN_0000a0d8(bVar7,0xb);
      bVar4 = FUN_0000a0d8(bVar11,0xd);
      bVar5 = FUN_0000a0d8(bVar1,9);
      *(byte *)(param_1 + uVar9) = bVar2 ^ bVar3 ^ bVar4 ^ bVar5;
      bVar2 = FUN_0000a0d8(bVar6,9);
      bVar3 = FUN_0000a0d8(bVar7,0xe);
      bVar4 = FUN_0000a0d8(bVar11,0xb);
      bVar5 = FUN_0000a0d8(bVar1,0xd);
      *(byte *)(iVar10 + 4) = bVar2 ^ bVar3 ^ bVar4 ^ bVar5;
      bVar2 = FUN_0000a0d8(bVar6,0xd);
      bVar3 = FUN_0000a0d8(bVar7,9);
      bVar4 = FUN_0000a0d8(bVar11,0xe);
      bVar5 = FUN_0000a0d8(bVar1,0xb);
      *(byte *)(iVar10 + 8) = bVar2 ^ bVar3 ^ bVar4 ^ bVar5;
      bVar6 = FUN_0000a0d8(bVar6,0xb);
      bVar7 = FUN_0000a0d8(bVar7,0xd);
      bVar11 = FUN_0000a0d8(bVar11,9);
      bVar11 = bVar6 ^ bVar7 ^ bVar11;
      uVar8 = 0xe;
    }
    else {
      bVar2 = FUN_0000a0d8(bVar6,2);
      bVar3 = FUN_0000a0d8(bVar7,3);
      *(byte *)(param_1 + uVar9) = bVar2 ^ bVar3 ^ bVar11 ^ bVar1;
      bVar2 = FUN_0000a0d8(bVar7,2);
      bVar3 = FUN_0000a0d8(bVar11,2);
      *(byte *)(iVar10 + 4) = bVar2 ^ bVar6 ^ bVar3 ^ bVar11 ^ bVar1;
      bVar2 = FUN_0000a0d8(bVar11,2);
      bVar3 = FUN_0000a0d8(bVar1,2);
      *(byte *)(iVar10 + 8) = bVar2 ^ bVar6 ^ bVar7 ^ bVar3 ^ bVar1;
      bVar2 = FUN_0000a0d8(bVar6,2);
      bVar11 = bVar2 ^ bVar6 ^ bVar7 ^ bVar11;
      uVar8 = 2;
    }
    bVar7 = FUN_0000a0d8(bVar1,uVar8);
    uVar9 = uVar9 + 1 & 0xff;
    *(byte *)(iVar10 + 0xc) = bVar11 ^ bVar7;
  } while (uVar9 < 4);
  return;
}



/* ===== FUN_0000a9a0 @ 0xA9A0 ===== */

void __stdcall_softfp FUN_0000a9a0(int param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  uVar3 = 0;
  do {
    for (uVar4 = 0; uVar4 < uVar3; uVar4 = uVar4 + 1 & 0xff) {
      if (param_2 == 0) {
        iVar5 = uVar3 * 4;
        iVar2 = iVar5 + param_1;
        uVar1 = *(undefined1 *)(iVar2 + 3);
        *(undefined1 *)(iVar2 + 3) = *(undefined1 *)(iVar2 + 2);
        *(undefined1 *)(iVar2 + 2) = *(undefined1 *)(iVar2 + 1);
        *(undefined1 *)(iVar2 + 1) = *(undefined1 *)(param_1 + iVar5);
        *(undefined1 *)(param_1 + iVar5) = uVar1;
      }
      else {
        iVar5 = uVar3 * 4;
        iVar2 = iVar5 + param_1;
        uVar1 = *(undefined1 *)(param_1 + iVar5);
        *(undefined1 *)(param_1 + iVar5) = *(undefined1 *)(iVar2 + 1);
        *(undefined1 *)(iVar2 + 1) = *(undefined1 *)(iVar2 + 2);
        *(undefined1 *)(iVar2 + 2) = *(undefined1 *)(iVar2 + 3);
        *(undefined1 *)(iVar2 + 3) = uVar1;
      }
    }
    uVar3 = uVar3 + 1 & 0xff;
  } while (uVar3 < 4);
  return;
}



/* ===== FUN_0000a9e8 @ 0xA9E8 ===== */

void __stdcall_softfp FUN_0000a9e8(int param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  
  uVar6 = 0;
  do {
    iVar2 = DAT_0000aa28;
    iVar5 = uVar6 * 4 + param_1;
    uVar4 = 0;
    iVar3 = DAT_0000aa28 + 0x100;
    do {
      bVar1 = *(byte *)(iVar5 + uVar4);
      uVar7 = (uint)(bVar1 >> 4);
      if (param_2 == 0) {
        iVar8 = uVar7 * 0x10 + iVar3;
      }
      else {
        iVar8 = uVar7 * 0x10 + iVar2;
      }
      *(undefined1 *)(iVar5 + uVar4) = *(undefined1 *)(iVar8 + (bVar1 & 0xf));
      uVar4 = uVar4 + 1 & 0xff;
    } while (uVar4 < 4);
    uVar6 = uVar6 + 1 & 0xff;
  } while (uVar6 < 4);
  return;
}



/* ===== FUN_0000aa2c @ 0xAA2C ===== */

void __stdcall_softfp FUN_0000aa2c(void)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  short sVar3;
  ushort uVar4;
  
  puVar1 = DAT_0000aae0;
  *DAT_0000aae8 = (short)(DAT_0000aae4 * (uint)*(ushort *)(DAT_0000aae0 + 0xe) >> 0xe);
  if (*(ushort *)(puVar1 + 0xe) < DAT_0000aaec) {
    FUN_00004a98();
    *puVar1 = 1;
    puVar1[2] = 1;
    uVar4 = *(ushort *)(puVar1 + 0xc);
LAB_0000aa76:
    if (199 < uVar4) goto LAB_0000aa94;
    sVar3 = uVar4 + 1;
  }
  else {
    if (DAT_0000aaf0 < *(ushort *)(puVar1 + 0xe)) {
      puVar1[1] = 1;
      *(undefined2 *)(puVar1 + 0xc) = 0;
      goto LAB_0000aa94;
    }
    uVar4 = *(ushort *)(DAT_0000aae0 + 0xc);
    if ((uint)*(ushort *)(puVar1 + 0xe) < DAT_0000aaec + 0x8c) {
      puVar1[2] = 1;
      goto LAB_0000aa76;
    }
    if ((uint)*(ushort *)(puVar1 + 0xe) < DAT_0000aaf0 - 0x26) {
      puVar1[1] = 0;
    }
    puVar1[2] = 0;
    *puVar1 = 0;
    if (uVar4 == 0) goto LAB_0000aa94;
    sVar3 = uVar4 - 1;
  }
  *(short *)(puVar1 + 0xc) = sVar3;
LAB_0000aa94:
  if ((*DAT_0000aaf4 < 0x117) && (*(ushort *)(puVar1 + 0xe) < *(ushort *)(puVar1 + 6))) {
    if (*(ushort *)(puVar1 + 10) < 0x50) {
      *(ushort *)(puVar1 + 10) = *(ushort *)(puVar1 + 10) + 1;
    }
    else {
      *(undefined2 *)(puVar1 + 10) = 0;
      *(undefined2 *)(puVar1 + 6) = *(undefined2 *)(puVar1 + 0xe);
    }
  }
  else {
    *(undefined2 *)(puVar1 + 10) = 0;
  }
  if (*DAT_0000aaf8 == '\0') {
    puVar1[3] = *(undefined1 *)(DAT_0000aafc + 1);
    *(undefined2 *)(puVar1 + 6) = *(undefined2 *)(puVar1 + 0xe);
    return;
  }
  uVar2 = FUN_000044ac(*(undefined2 *)(puVar1 + 6));
  puVar1[3] = uVar2;
  return;
}



/* ===== FUN_0000ab00 @ 0xAB00 ===== */

void __stdcall_softfp FUN_0000ab00(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = param_2 | param_4;
  if ((int)uVar1 < 0) {
    if (-1 < (int)(uVar1 + 0x100000)) {
      if ((param_2 << 1 < 0xffe00000) && (param_4 << 1 < 0xffe00000)) {
        return;
      }
      goto LAB_0000ab52;
    }
    if ((int)(uVar1 - 0x100000) < 0) {
      if (param_4 != param_2) {
        return;
      }
      return;
    }
  }
  else {
    if ((int)(uVar1 + 0x100000) < 0) {
      if ((-1 < (int)(param_2 + 0x100000)) && (-1 < (int)(param_4 + 0x100000))) {
        return;
      }
LAB_0000ab52:
      FUN_00003a04();
      return;
    }
    if (-1 < (int)(uVar1 - 0x100000)) {
      if (param_2 != param_4) {
        return;
      }
      return;
    }
  }
  return;
}



/* ===== FUN_0000ab64 @ 0xAB64 ===== */

uint __stdcall_softfp FUN_0000ab64(uint param_1,uint param_2)

{
  uint uVar1;
  uint extraout_r1;
  uint uVar2;
  uint extraout_r2;
  uint uVar3;
  uint extraout_r3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint unaff_r6;
  
  uVar6 = 0x80000000;
  uVar4 = param_1 ^ param_2;
  if ((int)uVar4 < 0) {
    FUN_0000acac(param_1,param_2 ^ 0x80000000);
    param_2 = extraout_r1;
    uVar2 = extraout_r2;
    uVar3 = extraout_r3;
  }
  else {
    iVar5 = param_1 - param_2;
    if (param_1 < param_2) {
      param_1 = param_1 - iVar5;
      param_2 = param_2 + iVar5;
    }
    unaff_r6 = param_1 >> 0x17;
    uVar2 = unaff_r6 & 0xff;
    if (uVar2 == 0xff) {
      if ((param_1 & 0x7fffff) != 0) {
        param_1 = DAT_0000abec;
      }
      return param_1;
    }
    uVar3 = (param_2 & 0x7fffffff) >> 0x17;
    if (uVar3 == 0) {
      if (uVar2 != 0) {
        return param_1;
      }
      return param_1 & 0x80000000;
    }
    uVar3 = uVar2 - uVar3;
    uVar4 = (param_2 << 8 | 0x80000000) >> (uVar3 & 0xff);
    uVar1 = param_1 << 8 | 0x80000000;
    uVar6 = uVar1 + uVar4;
    if (!CARRY4(uVar1,uVar4)) goto LAB_0000ab96;
  }
  uVar6 = uVar6 >> 1 | (uVar6 | 1) << 0x1f;
  uVar2 = uVar2 + 1;
  unaff_r6 = unaff_r6 + 1;
LAB_0000ab96:
  uVar1 = uVar6 >> 8;
  if ((((uVar6 >> 7 & 1) != 0) && (uVar1 = uVar1 + 1, (uVar6 & 0x7f) == 0)) &&
     (((param_2 << 7 ^ (uVar4 >> 1) << (uVar3 & 0xff)) & 0x3fffffff) == 0)) {
    uVar1 = uVar1 & 0xfffffffe;
  }
  uVar1 = uVar1 + (unaff_r6 - 1) * 0x800000;
  if (0xfe < (int)uVar2) {
    return uVar1 & 0xff800000;
  }
  return uVar1;
}



/* ===== FUN_0000ab70 @ 0xAB70 ===== */

uint __stdcall_softfp FUN_0000ab70(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint unaff_r5;
  uint uVar6;
  uint uVar7;
  
  iVar4 = param_1 - param_2;
  if (param_1 < param_2) {
    param_1 = param_1 - iVar4;
    param_2 = param_2 + iVar4;
  }
  uVar7 = param_1 >> 0x17;
  uVar2 = uVar7 & 0xff;
  if (uVar2 == 0xff) {
    if ((param_1 & 0x7fffff) != 0) {
      param_1 = DAT_0000abec;
    }
  }
  else {
    uVar3 = (param_2 & 0x7fffffff) >> 0x17;
    if (uVar3 != 0) {
      uVar3 = uVar2 - uVar3;
      uVar5 = (param_2 << 8 | unaff_r5) >> (uVar3 & 0xff);
      uVar1 = param_1 << 8 | unaff_r5;
      uVar6 = uVar1 + uVar5;
      if (CARRY4(uVar1,uVar5)) {
        uVar6 = uVar6 >> 1 | (uVar6 | 1) << 0x1f;
        uVar2 = uVar2 + 1;
        uVar7 = uVar7 + 1;
      }
      uVar1 = uVar6 >> 8;
      if ((((uVar6 >> 7 & 1) != 0) && (uVar1 = uVar1 + 1, (uVar6 & 0x7f) == 0)) &&
         (((param_2 << 7 ^ (uVar5 >> 1) << (uVar3 & 0xff)) & 0x3fffffff) == 0)) {
        uVar1 = uVar1 & 0xfffffffe;
      }
      uVar1 = uVar1 + (uVar7 - 1) * 0x800000;
      if (uVar2 < 0xff) {
        return uVar1;
      }
      return uVar1 & 0xff800000;
    }
    if (uVar2 == 0) {
      return param_1 & 0x80000000;
    }
  }
  return param_1;
}



/* ===== FUN_0000abf0 @ 0xABF0 ===== */

int __stdcall_softfp FUN_0000abf0(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int unaff_r4;
  int iVar6;
  
  iVar6 = unaff_r4 * 2 + (uint)((param_1 & 0x80000000) != 0) + param_2 * 2 +
          (uint)((param_2 & 0x80000000) != 0);
  uVar2 = (param_1 & 0x7fffffff) >> 0x17;
  if (uVar2 == 0) {
    uVar4 = (param_2 & 0x7fffffff) >> 0x17;
LAB_0000ac74:
    if ((uVar2 != 0xff) && (uVar4 != 0xff)) {
      return iVar6 * -0x80000000;
    }
  }
  else {
    uVar4 = (param_2 & 0x7fffffff) >> 0x17;
    if (uVar4 == 0) goto LAB_0000ac74;
    if ((uVar2 != 0xff) && (uVar4 != 0xff)) {
      param_1 = param_1 & 0x7fffff;
      param_2 = param_2 & 0x7fffff;
      iVar1 = (param_2 >> 8) * (param_1 >> 8);
      uVar3 = (uVar2 + uVar4) - 0x7f;
      uVar5 = iVar1 + (param_1 + param_2) * 0x80 + (param_2 * param_1 + iVar1 * -0x10000 >> 0x10);
      if (uVar5 >> 0x1e != 0) {
        uVar5 = (uVar5 >> 1) + 0xe0000000;
        uVar3 = (uVar2 + uVar4) - 0x7e;
      }
      uVar2 = uVar5 >> 7;
      if ((((uVar5 >> 6 & 1) != 0) && (uVar2 = uVar2 + 1, (param_2 * param_1 & 0x1ffff) == 0)) &&
         ((uVar5 & 0x3f) == 0)) {
        uVar2 = uVar2 & 0xfffffffe;
      }
      if ((uVar3 < 0xff) && (uVar3 * 0x800000 != 0)) {
        return (uVar2 | iVar6 * -0x80000000) + uVar3 * 0x800000;
      }
      if ((int)uVar3 < 1) {
        return iVar6 * -0x80000000;
      }
      goto LAB_0000ac68;
    }
  }
  if (((0xff000000 < param_1 * 2) || (0xff000000 < param_2 * 2)) || (uVar2 + uVar4 == 0xff)) {
    return DAT_0000ac9c;
  }
LAB_0000ac68:
  return (iVar6 * 0x100 | 0xffU) << 0x17;
}



/* ===== FUN_0000aca0 @ 0xACA0 ===== */

uint __stdcall_softfp FUN_0000aca0(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint extraout_r3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined8 uVar7;
  
  uVar4 = param_1 ^ param_2;
  if ((int)uVar4 < 0) {
    uVar7 = FUN_0000ab70(param_1,param_2 ^ 0x80000000);
    uVar3 = extraout_r3;
  }
  else {
    if (param_1 < param_2) {
      uVar4 = param_1 - param_2 ^ 0x80000000;
      param_1 = param_1 - uVar4;
      param_2 = param_2 + uVar4;
    }
    uVar6 = param_1 >> 0x17;
    uVar2 = uVar6 & 0xff;
    if (uVar2 == 0xff) {
      if (((param_1 & 0x7fffff) != 0) || ((param_2 & 0x7fffffff) >> 0x17 == 0xff)) {
        param_1 = DAT_0000ad6c;
      }
      return param_1;
    }
    uVar3 = (param_2 & 0x7fffffff) >> 0x17;
    if (uVar3 == 0) {
      if (uVar2 == 0) {
        return 0;
      }
      return param_1;
    }
    uVar3 = uVar2 - uVar3;
    uVar4 = (param_2 << 8 | 0x80000000) >> (uVar3 & 0xff);
    uVar5 = (param_1 & 0x7fffff) * 0x100 - uVar4;
    if ((int)uVar5 < 0) {
      if ((uVar5 & 0x40000000) == 0) {
        uVar4 = (uVar5 & 0x3fffffff) << 1;
        if ((uVar5 & 0x3fffffff) == 0) {
          return 0;
        }
        iVar1 = 1;
        if ((uVar5 & 0x3fffffff) >> 0xf == 0) {
          uVar4 = uVar5 * 0x20000;
          iVar1 = 0x11;
        }
        if (uVar4 >> 0x18 == 0) {
          uVar4 = uVar4 << 8;
          iVar1 = iVar1 + 8;
        }
        if (uVar4 >> 0x1c == 0) {
          uVar4 = uVar4 << 4;
          iVar1 = iVar1 + 4;
        }
        if (uVar4 >> 0x1e == 0) {
          uVar4 = uVar4 << 2;
          iVar1 = iVar1 + 2;
        }
        if (-1 < (int)uVar4) {
          uVar4 = uVar4 << 1;
          iVar1 = iVar1 + 1;
        }
        uVar6 = uVar6 - iVar1;
        if (0 < (int)(uVar2 - iVar1)) {
          return ((uVar4 & 0x7fffffff) >> 8) + uVar6 * 0x800000;
        }
LAB_0000ad50:
        return (uVar6 + 0xc0 >> 8) << 0x1f;
      }
      uVar5 = (uVar5 & 0x3fffffff) << 1;
      uVar6 = uVar6 - 1;
      if (uVar2 == 1) goto LAB_0000ad50;
    }
    if ((uVar5 >> 7 & 1) == 0) {
      return (uVar5 >> 8) + uVar6 * 0x800000;
    }
    uVar2 = (uVar5 >> 8) + uVar6 * 0x800000 + 1;
    uVar7 = CONCAT44(param_2,uVar2);
    if ((uVar5 & 0x7f) != 0) {
      return uVar2;
    }
  }
  if ((((int)((ulonglong)uVar7 >> 0x20) << 8 ^ uVar4 << (uVar3 & 0xff)) & 0x7fffffff) == 0) {
    return (uint)uVar7 & 0xfffffffe;
  }
  return (uint)uVar7 - 1;
}



/* ===== FUN_0000acac @ 0xACAC ===== */

uint __stdcall_softfp FUN_0000acac(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint unaff_r5;
  uint uVar5;
  uint uVar6;
  
  if (param_1 < param_2) {
    uVar3 = param_1 - param_2 ^ unaff_r5;
    param_1 = param_1 - uVar3;
    param_2 = param_2 + uVar3;
  }
  uVar6 = param_1 >> 0x17;
  uVar3 = uVar6 & 0xff;
  if (uVar3 == 0xff) {
    if (((param_1 & 0x7fffff) != 0) || ((param_2 & 0x7fffffff) >> 0x17 == 0xff)) {
      param_1 = DAT_0000ad6c;
    }
    return param_1;
  }
  uVar2 = (param_2 & 0x7fffffff) >> 0x17;
  if (uVar2 == 0) {
    if (uVar3 == 0) {
      return 0;
    }
    return param_1;
  }
  uVar2 = uVar3 - uVar2;
  uVar4 = (param_2 << 8 | unaff_r5) >> (uVar2 & 0xff);
  uVar5 = (param_1 << 8 & ~unaff_r5) - uVar4;
  if (-1 < (int)uVar5) {
LAB_0000ace0:
    if ((uVar5 >> 7 & 1) == 0) {
      return (uVar5 >> 8) + uVar6 * 0x800000;
    }
    uVar3 = (uVar5 >> 8) + uVar6 * 0x800000;
    uVar6 = uVar3 + 1;
    if ((uVar5 & 0x7f) == 0) {
      if (((param_2 << 8 ^ uVar4 << (uVar2 & 0xff)) & 0x7fffffff) == 0) {
        return uVar6 & 0xfffffffe;
      }
      return uVar3;
    }
    return uVar6;
  }
  if ((uVar5 & 0x40000000) == 0) {
    uVar2 = (uVar5 & 0x3fffffff) << 1;
    if ((uVar5 & 0x3fffffff) == 0) {
      return 0;
    }
    iVar1 = 1;
    if ((uVar5 & 0x3fffffff) >> 0xf == 0) {
      uVar2 = uVar5 * 0x20000;
      iVar1 = 0x11;
    }
    if (uVar2 >> 0x18 == 0) {
      uVar2 = uVar2 << 8;
      iVar1 = iVar1 + 8;
    }
    if (uVar2 >> 0x1c == 0) {
      uVar2 = uVar2 << 4;
      iVar1 = iVar1 + 4;
    }
    if (uVar2 >> 0x1e == 0) {
      uVar2 = uVar2 << 2;
      iVar1 = iVar1 + 2;
    }
    if (-1 < (int)uVar2) {
      uVar2 = uVar2 << 1;
      iVar1 = iVar1 + 1;
    }
    uVar6 = uVar6 - iVar1;
    if (0 < (int)(uVar3 - iVar1)) {
      return ((uVar2 & 0x7fffffff) >> 8) + uVar6 * 0x800000;
    }
  }
  else {
    uVar5 = (uVar5 & 0x3fffffff) << 1;
    uVar6 = uVar6 - 1;
    if (uVar3 != 1) goto LAB_0000ace0;
  }
  return (uVar6 + 0xc0 >> 8) << 0x1f;
}


