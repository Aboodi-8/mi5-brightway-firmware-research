/*
 * REFERENCE-ONLY GHIDRA PSEUDOCODE.
 * This is not the manufacturer's source and is not directly recompilable.
 * Types, names, control flow, volatile semantics, and timing may be wrong.
 */


/* ===== armcc_runtime_entry @ 0x8003148 ===== */

/* ARMCC reset-time runtime entry; sets the stack and starts scatter loading before the application
   entry. */

void armcc_runtime_entry(void)

{
  armcc_scatterload_dispatcher();
  (*DAT_08003154)();
  return;
}



/* ===== application_entry_thunk @ 0x8003150 ===== */

/* Four-byte veneer that branches through a literal to the application entry at 0x0801907A. */

void application_entry_thunk(void)

{
  (*DAT_08003154)();
  return;
}



/* ===== Reset_Handler @ 0x800315C ===== */

/* Reset entry from the vector table; ARMCC-style startup. */

void Reset_Handler(void)

{
  (*DAT_08003178)();
                    /* WARNING: Could not recover jumptable at 0x08003162. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_0800317c)();
  return;
}



/* ===== pend_sv_Handler @ 0x8003172 ===== */

void pend_sv_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== irq_00_Handler @ 0x8003176 ===== */

void irq_00_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_08003180 @ 0x8003180 ===== */

uint FUN_08003180(void)

{
  uint uVar1;
  
  uVar1 = DAT_080031a0 * *DAT_0800319c + 0x3039;
  *DAT_0800319c = uVar1;
  return uVar1 >> 1;
}



/* ===== FUN_080031a4 @ 0x80031A4 ===== */

void FUN_080031a4(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  bool bVar2;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    for (; 3 < param_3; param_3 = param_3 - 4) {
      uVar1 = *param_2;
      param_2 = param_2 + 1;
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    }
  }
  while (bVar2 = param_3 != 0, param_3 = param_3 - 1, bVar2) {
    *(undefined1 *)param_1 = *(undefined1 *)param_2;
    param_1 = (undefined4 *)((int)param_1 + 1);
    param_2 = (undefined4 *)((int)param_2 + 1);
  }
  return;
}



/* ===== FUN_080031c8 @ 0x80031C8 ===== */

void FUN_080031c8(undefined1 *param_1,int param_2,undefined1 param_3)

{
  bool bVar1;
  
  while (bVar1 = param_2 != 0, param_2 = param_2 + -1, bVar1) {
    *param_1 = param_3;
    param_1 = param_1 + 1;
  }
  return;
}



/* ===== FUN_080031d6 @ 0x80031D6 ===== */

void FUN_080031d6(undefined4 param_1,undefined4 param_2)

{
  FUN_080031c8(param_1,param_2,0);
  return;
}



/* ===== armcc_memset_wrapper @ 0x80031DA ===== */

/* Exact byte match against the symbol-rich official Linko ARMCC reference image. */

undefined4 armcc_memset_wrapper(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_080031c8(param_1,param_3,param_2);
  return param_1;
}



/* ===== FUN_080031ec @ 0x80031EC ===== */

int FUN_080031ec(char *param_1)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  
  pcVar3 = param_1;
  do {
    pcVar2 = pcVar3 + 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar2;
  } while (cVar1 != '\0');
  return (int)pcVar2 - (int)(param_1 + 1);
}



/* ===== FUN_080031fa @ 0x80031FA ===== */

void FUN_080031fa(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0;
      ((uVar1 < param_3 && (*(char *)(param_1 + uVar1) == *(char *)(param_2 + uVar1))) &&
      (*(char *)(param_1 + uVar1) != '\0')); uVar1 = uVar1 + 1) {
  }
  return;
}



/* ===== FUN_08003218 @ 0x8003218 ===== */

void FUN_08003218(uint param_1)

{
  uint uVar1;
  
  uVar1 = (int)param_1 >> 0x1f;
  FUN_080032aa((param_1 ^ uVar1) - uVar1,0,0,0,0,uVar1 * -0x80000000,0x433);
  return;
}



/* ===== FUN_0800323a @ 0x800323A ===== */

int FUN_0800323a(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (param_2 & 0x7fffffff) >> 0x14;
  if (uVar2 < 0x3ff) {
    return 0;
  }
  if (uVar2 < 0x434) {
    iVar1 = FUN_0800326c(param_1,param_2 & 0xfffff | 0x100000,-(uVar2 - 0x433));
    return iVar1;
  }
  return param_1 << (uVar2 - 0x433 & 0xff);
}



/* ===== FUN_0800326c @ 0x800326C ===== */

ulonglong FUN_0800326c(uint param_1,uint param_2,uint param_3)

{
  if (0x1f < (int)param_3) {
    return (ulonglong)(param_2 >> (param_3 - 0x20 & 0xff));
  }
  return CONCAT44(param_2 >> (param_3 & 0xff),
                  param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff));
}



/* ===== FUN_080032aa @ 0x80032AA ===== */

ulonglong FUN_080032aa(undefined4 param_1,int param_2,int param_3,int param_4,uint param_5,
                      int param_6,int param_7)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  ulonglong uVar5;
  undefined8 uVar6;
  longlong lVar7;
  
  if (param_2 == 0) {
    iVar2 = LZCOUNT(param_1) + 0x20;
  }
  else {
    iVar2 = LZCOUNT(param_2);
  }
  uVar5 = FUN_080034e8();
  uVar3 = (uint)(uVar5 >> 0x20);
  if (((uint)uVar5 != 0 || param_3 != 0) || (uVar3 != 0 || param_4 != 0)) {
    if (param_3 != 0 || param_4 != 0) {
      uVar6 = FUN_0800326c(param_3,param_4,0x40 - iVar2);
      lVar7 = FUN_080034e8(param_3,param_4,iVar2);
      uVar5 = CONCAT44(uVar3 | (uint)((ulonglong)uVar6 >> 0x20),
                       (uint)uVar5 | (uint)uVar6 | (uint)(lVar7 != 0));
    }
    uVar3 = (uint)(uVar5 >> 0xb);
    iVar2 = (param_7 - iVar2) + 10;
    if (-1 < iVar2) {
      uVar1 = uVar3 + param_5;
      iVar2 = iVar2 * 0x100000 + (int)((uVar5 >> 0xb) >> 0x20) + param_6 +
              (uint)CARRY4(uVar3,param_5);
      if ((int)uVar5 * 0x200000 < 0) {
        bVar4 = 0xfffffffe < uVar1;
        uVar1 = uVar1 + 1;
        iVar2 = iVar2 + (uint)bVar4;
        if ((uVar5 & 0x3ff) == 0) {
          uVar1 = uVar1 & 0xfffffffe;
        }
      }
      return CONCAT44(iVar2,uVar1);
    }
    uVar5 = 0;
  }
  return uVar5;
}



/* ===== FUN_08003346 @ 0x8003346 ===== */

uint FUN_08003346(uint param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  ulonglong uVar11;
  longlong lVar12;
  
  iVar1 = (int)(param_2 ^ param_4) >> 0x1f;
  iVar2 = -iVar1;
  uVar7 = param_3;
  uVar9 = param_4;
  if ((param_2 & 0x7fffffff) <= (param_4 & 0x7fffffff) &&
      (uint)(param_3 <= param_1) <= (param_2 & 0x7fffffff) - (param_4 & 0x7fffffff)) {
    uVar7 = param_1;
    uVar9 = param_2;
    param_2 = param_4;
    param_1 = param_3;
  }
  if ((uVar9 & 0x7fffffff) != 0 || uVar7 != 0) {
    uVar8 = param_2 >> 0x14;
    uVar3 = uVar8 & 0x7ff;
    iVar4 = uVar3 - ((uVar9 & 0x7fffffff) >> 0x14);
    if (iVar4 < 0x40) {
      uVar9 = uVar9 & 0xfffff | 0x100000;
      if (iVar2 != 0) {
        bVar10 = uVar7 != 0;
        uVar7 = -uVar7;
        uVar9 = -(uint)bVar10 - uVar9;
      }
      uVar11 = FUN_080034e8(uVar7,uVar9,0x40 - iVar4);
      uVar6 = (uint)(uVar11 >> 0x20);
      uVar5 = (uint)uVar11;
      lVar12 = FUN_08003506(uVar7,uVar9,iVar4);
      lVar12 = lVar12 + CONCAT44(param_2,param_1);
      param_1 = (uint)lVar12;
      uVar7 = (uint)((ulonglong)lVar12 >> 0x20);
      if ((param_2 ^ uVar7) >> 0x14 != 0) {
        if (iVar2 == 0) {
          uVar11 = CONCAT44(uVar6 >> 1 | param_1 * -0x80000000,
                            (uint)((uVar11 & 0x100000000) != 0) << 0x1f | uVar5 >> 1);
          param_1 = (uint)((uVar7 + 0x100000 & 1) != 0) << 0x1f | param_1 >> 1;
        }
        else {
          if (iVar4 < 2) {
            uVar7 = FUN_080032aa(param_1,uVar7 + uVar8 * -0x100000 + 0x100000,uVar5,uVar6,0,
                                 (uVar8 & 0x800) << 0x14,uVar3);
            return uVar7;
          }
          param_1 = param_1 * 2 | uVar6 >> 0x1f;
          uVar11 = CONCAT44(uVar6 * 2 + (uint)CARRY4(uVar5,uVar5),uVar5 * 2);
        }
      }
    }
    else {
      uVar11 = CONCAT44(-(uint)(1 < (uint)(iVar1 * -2)),iVar1 * 2 + 1);
      param_1 = param_1 + iVar1;
    }
    if (((longlong)uVar11 < 0) &&
       (param_1 = param_1 + 1,
       (uVar11 & 0x7fffffff) == 0 &&
       (int)(uVar11 >> 0x20) * 2 + (uint)CARRY4((uint)uVar11,(uint)uVar11) == 0)) {
      param_1 = param_1 & 0xfffffffe;
    }
    return param_1;
  }
  return param_1;
}



/* ===== FUN_0800348e @ 0x800348E ===== */

void FUN_0800348e(undefined4 param_1,uint param_2)

{
  FUN_08003346(param_1,param_2 ^ 0x80000000);
  return;
}



/* ===== FUN_08003494 @ 0x8003494 ===== */

int FUN_08003494(int param_1,int param_2)

{
  if (-1 < param_2) {
    param_1 = -param_1;
  }
  return param_1;
}



/* ===== armcc_scatterload_dispatcher @ 0x80034C4 ===== */

/* ARMCC scatter-load dispatcher reached by the runtime entry and backed by records near 0x0801AD28.
    */

longlong armcc_scatterload_dispatcher(void)

{
  uint uVar1;
  uint extraout_r2;
  undefined4 *puVar2;
  
  for (puVar2 = &DAT_0801ad28; puVar2 < &DAT_0801ad48; puVar2 = puVar2 + 4) {
    (*(code *)puVar2[3])(*puVar2,puVar2[1],puVar2[2]);
  }
  uVar1 = application_entry_thunk();
  if (0x1f < (int)extraout_r2) {
    return (ulonglong)(uVar1 << (extraout_r2 - 0x20 & 0xff)) << 0x20;
  }
  return CONCAT44(0 << (extraout_r2 & 0xff) | uVar1 >> (0x20 - extraout_r2 & 0xff),
                  uVar1 << (extraout_r2 & 0xff));
}



/* ===== FUN_080034e8 @ 0x80034E8 ===== */

longlong FUN_080034e8(uint param_1,int param_2,uint param_3)

{
  if (0x1f < (int)param_3) {
    return (ulonglong)(param_1 << (param_3 - 0x20 & 0xff)) << 0x20;
  }
  return CONCAT44(param_2 << (param_3 & 0xff) | param_1 >> (0x20 - param_3 & 0xff),
                  param_1 << (param_3 & 0xff));
}



/* ===== FUN_08003506 @ 0x8003506 ===== */

undefined8 FUN_08003506(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  if ((int)param_3 < 0x20) {
    iVar2 = (int)param_2 >> (param_3 & 0xff);
    uVar1 = param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff);
  }
  else {
    uVar1 = (int)param_2 >> (param_3 - 0x20 & 0xff);
    iVar2 = (int)(param_2 | uVar1) >> 0x1f;
  }
  return CONCAT44(iVar2,uVar1);
}



/* ===== FUN_0800352a @ 0x800352A ===== */

undefined4 FUN_0800352a(byte *param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  
  pbVar5 = param_2 + param_3;
  do {
    uVar6 = (uint)*param_1;
    uVar4 = uVar6 & 7;
    pbVar1 = param_1 + 1;
    if ((*param_1 & 7) == 0) {
      pbVar1 = param_1 + 2;
      uVar4 = (uint)param_1[1];
    }
    uVar2 = (int)uVar6 >> 4;
    if (uVar2 == 0) {
      uVar2 = (uint)*pbVar1;
      pbVar1 = pbVar1 + 1;
    }
    while (uVar4 = uVar4 - 1, uVar4 != 0) {
      *param_2 = *pbVar1;
      pbVar1 = pbVar1 + 1;
      param_2 = param_2 + 1;
    }
    if ((int)(uVar6 << 0x1c) < 0) {
      param_1 = pbVar1 + 1;
      iVar3 = uVar2 + 2;
      pbVar1 = param_2 + -(uint)*pbVar1;
      while (iVar3 = iVar3 + -1, -1 < iVar3) {
        *param_2 = *pbVar1;
        param_2 = param_2 + 1;
        pbVar1 = pbVar1 + 1;
      }
    }
    else {
      while (uVar2 = uVar2 - 1, param_1 = pbVar1, -1 < (int)uVar2) {
        *param_2 = 0;
        param_2 = param_2 + 1;
      }
    }
  } while (param_2 < pbVar5);
  return 0;
}



/* ===== FUN_08003580 @ 0x8003580 ===== */

void FUN_08003580(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    FUN_0800e490(0x100,0);
    FUN_0800e478(param_2);
  }
  else {
    FUN_0800e490(param_2,1);
    FUN_0800e478(0);
  }
  return;
}



/* ===== FUN_080035aa @ 0x80035AA ===== */

void FUN_080035aa(int param_1,int param_2,int param_3,uint param_4)

{
  if (param_2 == 0x12) {
    *(uint *)(param_1 + 0x5c) = *(uint *)(param_1 + 0x5c) & 0xfffffff8 | param_4;
  }
  if (param_2 < 10) {
    *(uint *)(param_1 + 0x10) =
         *(uint *)(param_1 + 0x10) & ~(7 << (param_2 * 3 & 0xffU)) |
         param_4 << (param_2 * 3 & 0xffU);
  }
  else {
    *(uint *)(param_1 + 0xc) =
         *(uint *)(param_1 + 0xc) & ~(7 << ((param_2 + -10) * 3 & 0xffU)) |
         param_4 << ((param_2 + -10) * 3 & 0xffU);
  }
  if (param_3 < 7) {
    *(uint *)(param_1 + 0x34) =
         *(uint *)(param_1 + 0x34) & ~(0x1f << ((param_3 + -1) * 5 & 0xffU)) |
         param_2 << ((param_3 + -1) * 5 & 0xffU);
  }
  else if (param_3 < 0xd) {
    *(uint *)(param_1 + 0x30) =
         *(uint *)(param_1 + 0x30) & ~(0x1f << ((param_3 + -7) * 5 & 0xffU)) |
         param_2 << ((param_3 + -7) * 5 & 0xffU);
  }
  else {
    *(uint *)(param_1 + 0x2c) =
         *(uint *)(param_1 + 0x2c) & ~(0x1f << ((param_3 + -0xd) * 5 & 0xffU)) |
         param_2 << ((param_3 + -0xd) * 5 & 0xffU);
  }
  return;
}



/* ===== FUN_08003670 @ 0x8003670 ===== */

void FUN_08003670(void)

{
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  FUN_08006e50(DAT_080036c8);
  local_30 = DAT_080036cc;
  local_2c = DAT_080036d0;
  local_28 = 0;
  local_24 = 2;
  local_20 = 0;
  local_1c = 0x80;
  local_18 = 0x100;
  local_14 = 0x400;
  local_10 = 0x20;
  local_c = 0;
  local_8 = 0;
  FUN_08006f70(DAT_080036c8,&local_30);
  FUN_08006fac(0,DAT_080036c8 + -0x30,DAT_080036c8,1);
  FUN_08006f38(DAT_080036c8,1);
  return;
}



/* ===== FUN_080036d4 @ 0x80036D4 ===== */

undefined4 FUN_080036d4(void)

{
  byte bVar1;
  
  FUN_08003940();
  FUN_080037f4(DAT_08003700);
  for (bVar1 = 0; bVar1 < 2; bVar1 = bVar1 + 1) {
    FUN_08006e50(DAT_08003704);
  }
  *DAT_08003708 = 0;
  return 1;
}



/* ===== FUN_0800370c @ 0x800370C ===== */

undefined2 FUN_0800370c(int param_1)

{
  undefined2 *puVar1;
  undefined2 uVar2;
  uint uVar3;
  
  if (param_1 < 2) {
    for (uVar3 = 0; uVar3 < 7; uVar3 = uVar3 + 1 & 0xff) {
      *(undefined2 *)(DAT_08003758 + uVar3 * 2) = *(undefined2 *)(DAT_08003754 + param_1 * 2);
    }
    FUN_0800706a(DAT_08003758,5);
    uVar2 = FUN_08007044(DAT_08003758,2,3);
    puVar1 = DAT_08003750;
    *DAT_08003750 = uVar2;
    uVar2 = *puVar1;
  }
  else {
    uVar2 = *DAT_08003750;
  }
  return uVar2;
}



/* ===== FUN_0800375c @ 0x800375C ===== */

void FUN_0800375c(void)

{
  byte bVar1;
  
  FUN_08003940();
  for (bVar1 = 0; bVar1 < 2; bVar1 = bVar1 + 1) {
    FUN_08003858(bVar1);
    FUN_08003670();
    FUN_080038fc(bVar1);
  }
  *DAT_08003788 = 1;
  return;
}



/* ===== FUN_0800378c @ 0x800378C ===== */

undefined4 FUN_0800378c(void)

{
  ushort uVar1;
  int iVar2;
  
  uVar1 = 0;
  FUN_0800382a(DAT_080037f0,1);
  FUN_08003814(DAT_080037f0,1);
  do {
    iVar2 = FUN_0800389e(DAT_080037f0,0x20);
    if (iVar2 != 0) {
      FUN_08003974(DAT_080037f0);
      do {
        iVar2 = FUN_08003884(DAT_080037f0);
        if (iVar2 == 0) {
          FUN_08003840(DAT_080037f0,1);
          return 1;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < 0x3e9);
      return 0;
    }
    uVar1 = uVar1 + 1;
  } while (uVar1 < 0x1389);
  return 0;
}



/* ===== FUN_080037f4 @ 0x80037F4 ===== */

void FUN_080037f4(int param_1)

{
  if (param_1 == DAT_08003810) {
    FUN_0800e644(DAT_08003810 >> 0x12,1);
    FUN_0800e644(param_1 >> 0x12,0);
  }
  return;
}



/* ===== FUN_08003814 @ 0x8003814 ===== */

void FUN_08003814(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffffe;
  }
  else {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 1;
  }
  return;
}



/* ===== FUN_0800382a @ 0x800382A ===== */

void FUN_0800382a(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xfffffeff;
  }
  else {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x100;
  }
  return;
}



/* ===== FUN_08003840 @ 0x8003840 ===== */

void FUN_08003840(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) & 0xffafffff;
  }
  else {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 0x500000;
  }
  return;
}



/* ===== FUN_08003858 @ 0x8003858 ===== */

undefined8 FUN_08003858(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 local_18;
  undefined2 uStack_16;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_18 = (undefined2)param_1;
  uStack_16 = (undefined2)((uint)param_1 >> 0x10);
  uStack_14 = param_2;
  local_10 = param_3;
  uStack_c = param_4;
  FUN_0800a7b0(&local_18);
  local_18 = *(undefined2 *)(DAT_08003880 + param_1 * 8 + 4);
  local_10 = 3;
  FUN_0800a5c8(*(undefined4 *)(DAT_08003880 + param_1 * 8),&local_18);
  return CONCAT44(uStack_14,CONCAT22(uStack_16,local_18));
}



/* ===== FUN_08003884 @ 0x8003884 ===== */

bool FUN_08003884(int param_1)

{
  return *(int *)(param_1 + 0x54) == 0 && (*(uint *)(param_1 + 8) & 4) != 0;
}



/* ===== FUN_0800389e @ 0x800389E ===== */

bool FUN_0800389e(int param_1,uint param_2)

{
  return (*(uint *)(param_1 + 0x58) & param_2) != 0;
}



/* ===== FUN_080038b0 @ 0x80038B0 ===== */

void FUN_080038b0(int param_1,byte *param_2)

{
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & DAT_080038f4 | (uint)*param_2 << 8;
  *(uint *)(param_1 + 8) =
       *(uint *)(param_1 + 8) & DAT_080038f8 |
       *(uint *)(param_2 + 8) | *(uint *)(param_2 + 4) | (uint)param_2[1] << 1;
  *(uint *)(param_1 + 0x2c) =
       *(uint *)(param_1 + 0x2c) & 0xff0fffff | (param_2[0xc] - 1 & 0xff) << 0x14;
  return;
}



/* ===== FUN_080038fc @ 0x80038FC ===== */

undefined8 FUN_080038fc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 local_18;
  undefined1 local_17;
  undefined2 uStack_16;
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c;
  undefined3 uStack_b;
  
  uStack_16 = (undefined2)((uint)param_1 >> 0x10);
  local_18 = 1;
  local_17 = 1;
  local_14 = 0xe0000;
  local_10 = 0;
  _local_c = CONCAT31((int3)((uint)param_4 >> 8),2);
  FUN_080038b0(DAT_08003938,&local_18);
  FUN_080035aa(DAT_08003938,*(undefined1 *)(DAT_0800393c + param_1 * 8 + 6),param_1 + 1U & 0xff,7);
  return CONCAT44(local_14,CONCAT22(uStack_16,CONCAT11(local_17,local_18)));
}



/* ===== FUN_08003940 @ 0x8003940 ===== */

void FUN_08003940(void)

{
  FUN_0800e624(1);
  FUN_0800e6a4(4,1);
  FUN_0800e6a4(8,1);
  FUN_0800e6a4(1);
  FUN_0800e624(0x1000);
  FUN_08003580(0,2);
  return;
}



/* ===== FUN_08003974 @ 0x8003974 ===== */

void FUN_08003974(int param_1)

{
  if (*(int *)(param_1 + 0x54) == 0) {
    *(uint *)(param_1 + 8) = *(uint *)(param_1 + 8) | 4;
  }
  return;
}



/* ===== FUN_08003984 @ 0x8003984 ===== */

void FUN_08003984(void)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = FUN_0800a7ec();
  pbVar1 = DAT_080039ec;
  if (iVar2 == 0) {
    *DAT_080039ec = 0;
    *DAT_080039f0 = (*DAT_080039f0 & 0xf7) + 8;
  }
  else if ((int)((uint)*DAT_080039f0 << 0x1c) < 0) {
    *DAT_080039ec = *DAT_080039ec + 1;
    if (2 < *pbVar1) {
      *pbVar1 = 0;
      *DAT_080039f0 = *DAT_080039f0 & 0xf7;
    }
  }
  else {
    *DAT_080039ec = 0;
  }
  if (-1 < (int)((uint)*DAT_080039f0 << 0x1c)) {
    FUN_0800ab58();
    FUN_0800ab10();
  }
  return;
}



/* ===== FUN_080039f4 @ 0x80039F4 ===== */

void FUN_080039f4(void)

{
  byte *pbVar1;
  
  pbVar1 = DAT_08003a60;
  if ((int)((uint)*(byte *)(DAT_08003a58 + 0xc) << 0x1e) < 0) {
    if ((int)((uint)*(byte *)(DAT_08003a5c + 0x11) << 0x1d) < 0) {
      *DAT_08003a60 = 0;
    }
    else {
      *DAT_08003a60 = *DAT_08003a60 + 1;
      if (*(byte *)(DAT_08003a64 + 0xd) <= *pbVar1) {
        *(byte *)(DAT_08003a58 + 0xc) = *(byte *)(DAT_08003a58 + 0xc) & 0xfd;
        *DAT_08003a60 = 0;
      }
    }
  }
  if (((*(byte *)(DAT_08003a58 + 0x17) & 1) != 0) &&
     (-1 < (int)((uint)*(byte *)(DAT_08003a5c + 3) << 0x1c))) {
    *(byte *)(DAT_08003a58 + 0x17) = *(byte *)(DAT_08003a58 + 0x17) & 0xfe;
  }
  return;
}



/* ===== FUN_08003a68 @ 0x8003A68 ===== */

void FUN_08003a68(void)

{
  byte *pbVar1;
  
  pbVar1 = DAT_08003ab8;
  if ((int)((uint)*(byte *)(DAT_08003ab0 + 0xc) << 0x1b) < 0) {
    if (*(ushort *)(DAT_08003ab0 + 6) < *(ushort *)(DAT_08003ab4 + 0x18)) {
      *DAT_08003ab8 = 0;
    }
    else {
      *DAT_08003ab8 = *DAT_08003ab8 + 1;
      if (*(byte *)(DAT_08003ab4 + 0x1b) <= *pbVar1) {
        *(byte *)(DAT_08003ab0 + 0xc) = *(byte *)(DAT_08003ab0 + 0xc) & 0xef;
        *DAT_08003ab8 = 0;
      }
    }
  }
  return;
}



/* ===== FUN_08003abc @ 0x8003ABC ===== */

void FUN_08003abc(void)

{
  FUN_08003a68();
  FUN_080039f4();
  return;
}



/* ===== FUN_08003ac8 @ 0x8003AC8 ===== */

void FUN_08003ac8(undefined1 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = 0;
  uVar2 = FUN_08005b42(param_1,param_2,param_3,param_4,0);
  for (uVar3 = 0; (int)uVar3 < param_2; uVar3 = uVar3 + 1 & 0xff) {
    uVar4 = (byte)param_1[uVar3] + uVar4 & 0xffff;
  }
  uVar2 = uVar2 ^ uVar4;
  for (uVar3 = 0; (int)uVar3 < param_2; uVar3 = uVar3 + 1 & 0xff) {
    param_1[uVar3] = param_1[uVar3] ^ *(byte *)(DAT_08003bd4 + uVar3);
  }
  for (uVar3 = 0; (int)uVar3 < param_2; uVar3 = uVar3 + 1 & 0xff) {
    param_1[uVar3] =
         *(char *)(DAT_08003bd8 + (uVar2 & 3) * 0x10 + ((byte)param_1[uVar3] & 0xf)) +
         *(char *)(DAT_08003bd8 + (uVar2 & 0x30) + (uint)((byte)param_1[uVar3] >> 4)) * '\x10';
  }
  uVar3 = (int)uVar2 >> 8;
  for (uVar4 = uVar3 >> 6; uVar4 != 0; uVar4 = uVar4 - 1 & 0xff) {
    uVar1 = *param_1;
    *param_1 = param_1[1];
    param_1[1] = param_1[2];
    param_1[2] = param_1[3];
    param_1[3] = uVar1;
  }
  for (uVar4 = (uVar3 & 0x3f) >> 4; uVar4 != 0; uVar4 = uVar4 - 1 & 0xff) {
    uVar1 = param_1[4];
    param_1[4] = param_1[5];
    param_1[5] = param_1[6];
    param_1[6] = param_1[7];
    param_1[7] = uVar1;
  }
  for (uVar3 = (uVar3 & 0xf) >> 2; uVar3 != 0; uVar3 = uVar3 - 1 & 0xff) {
    uVar1 = param_1[8];
    param_1[8] = param_1[9];
    param_1[9] = param_1[10];
    param_1[10] = param_1[0xb];
    param_1[0xb] = uVar1;
  }
  for (uVar2 = (uVar2 & 0x3ff) >> 8; uVar2 != 0; uVar2 = uVar2 - 1 & 0xff) {
    uVar1 = param_1[0xc];
    param_1[0xc] = param_1[0xd];
    param_1[0xd] = param_1[0xe];
    param_1[0xe] = param_1[0xf];
    param_1[0xf] = uVar1;
  }
  return;
}



/* ===== FUN_08003bdc @ 0x8003BDC ===== */

undefined4 FUN_08003bdc(ushort param_1)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  uint local_c;
  
  local_c = (uint)param_1;
  iVar1 = FUN_08003e72(8,0x3e,1,&local_c,2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = 1000;
    do {
      bVar3 = iVar1 != 0;
      iVar1 = iVar1 + -1;
    } while (bVar3);
    uVar2 = 1;
  }
  return uVar2;
}



/* ===== FUN_08003c1c @ 0x8003C1C ===== */

undefined4 FUN_08003c1c(ushort param_1)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  uint local_c;
  
  local_c = (uint)param_1;
  iVar1 = FUN_0800b0a0(DAT_08003c5c,8,0x3e,&local_c,2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = 1000;
    do {
      bVar3 = iVar1 != 0;
      iVar1 = iVar1 + -1;
    } while (bVar3);
    uVar2 = 1;
  }
  return uVar2;
}



/* ===== FUN_08003c60 @ 0x8003C60 ===== */

void FUN_08003c60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_08003e52(param_1,param_2,1,param_3,param_4);
  return;
}



/* ===== FUN_08003c7a @ 0x8003C7A ===== */

undefined4 FUN_08003c7a(undefined4 param_1,ushort param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  uint local_1c;
  
  local_1c = (uint)param_2;
  iVar1 = FUN_08003e72(param_1,0x3e,1,&local_1c,2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = 1000;
    do {
      bVar3 = iVar1 != 0;
      iVar1 = iVar1 + -1;
    } while (bVar3);
    iVar1 = FUN_08003e52(param_1,0x40,1,param_3,param_4);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      iVar1 = 1000;
      do {
        bVar3 = iVar1 != 0;
        iVar1 = iVar1 + -1;
      } while (bVar3);
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* ===== FUN_08003cea @ 0x8003CEA ===== */

void FUN_08003cea(void)

{
  FUN_08003fe0();
  FUN_080040d8();
  return;
}



/* ===== FUN_08003cf6 @ 0x8003CF6 ===== */

void FUN_08003cf6(void)

{
  int iVar1;
  bool bVar2;
  undefined4 local_8;
  
  FUN_08013c5e();
  local_8 = 1000;
  do {
    bVar2 = local_8 != 0;
    local_8 = local_8 + -1;
  } while (bVar2);
  FUN_08005b20();
  local_8 = 10000;
  do {
    bVar2 = local_8 != 0;
    local_8 = local_8 + -1;
  } while (bVar2);
  iVar1 = FUN_0800e138();
  if (iVar1 == 0) {
    FUN_0800e200();
    local_8 = 10000;
    do {
      bVar2 = local_8 != 0;
      local_8 = local_8 + -1;
    } while (bVar2);
    FUN_0800e158();
    local_8 = 5000;
    do {
      bVar2 = local_8 != 0;
      local_8 = local_8 + -1;
    } while (bVar2);
    FUN_08007ee0();
    local_8 = 1000;
    do {
      bVar2 = local_8 != 0;
      local_8 = local_8 + -1;
    } while (bVar2);
    FUN_08003d78();
  }
  return;
}



/* ===== FUN_08003d78 @ 0x8003D78 ===== */

void FUN_08003d78(void)

{
  ushort *puVar1;
  byte bVar2;
  int iVar3;
  undefined4 local_10;
  
  local_10 = 0;
  iVar3 = FUN_08003c7a(8,5,&local_10,2);
  puVar1 = DAT_08003de8;
  if (iVar3 == 0) {
    for (bVar2 = 0; bVar2 < 3; bVar2 = bVar2 + 1) {
      iVar3 = FUN_08003c7a(8,5,&local_10,2);
      puVar1 = DAT_08003de8;
      if (iVar3 != 0) {
        *DAT_08003de8 = (ushort)local_10._1_1_ << 8;
        *DAT_08003de8 = (ushort)(byte)local_10 | *puVar1;
        return;
      }
      *DAT_08003de8 = 0;
    }
  }
  else {
    *DAT_08003de8 = (ushort)local_10._1_1_ << 8;
    *DAT_08003de8 = (ushort)(byte)local_10 | *puVar1;
  }
  return;
}



/* ===== FUN_08003dec @ 0x8003DEC ===== */

void FUN_08003dec(void)

{
  FUN_080049e8();
  return;
}



/* ===== FUN_08003df4 @ 0x8003DF4 ===== */

void FUN_08003df4(void)

{
  FUN_080071d8();
  FUN_08015c5c();
  FUN_0800a2b8();
  FUN_0801530c();
  FUN_08010ddc();
  FUN_0800e420();
  FUN_080163b0();
  FUN_0800f00c();
  FUN_0800e368();
  FUN_080159fc();
  FUN_08003cf6();
  FUN_08005b2a();
  FUN_0800bb08();
  FUN_08010f78();
  FUN_080128d8();
  return;
}



/* ===== FUN_08003e34 @ 0x8003E34 ===== */

char FUN_08003e34(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  
  cVar1 = '\0';
  for (iVar2 = 0; iVar2 < param_2; iVar2 = iVar2 + 1) {
    cVar1 = *(char *)(param_1 + iVar2) + cVar1;
  }
  return cVar1;
}



/* ===== FUN_08003e52 @ 0x8003E52 ===== */

void FUN_08003e52(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_0800414c(0,param_1,param_2,param_4,param_5);
  return;
}



/* ===== FUN_08003e72 @ 0x8003E72 ===== */

void FUN_08003e72(undefined4 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  FUN_08004730(0,param_1,param_2,param_4,param_5);
  return;
}



/* ===== FUN_08003e94 @ 0x8003E94 ===== */

uint * FUN_08003e94(void)

{
  uint *puVar1;
  undefined4 local_c;
  
  puVar1 = DAT_08003fdc;
  local_c = (uint)(*(char *)(DAT_08003fd8 + 2) < '\0');
  if ((int)((uint)*(byte *)(DAT_08003fd8 + 2) << 0x1a) < 0) {
    local_c = local_c | 2;
  }
  if ((int)((uint)*(byte *)(DAT_08003fd8 + 2) << 0x19) < 0) {
    local_c = local_c | 4;
  }
  if (*(char *)(DAT_08003fd8 + 7) < '\0') {
    local_c = (uint)CONCAT11(0x20,(undefined1)local_c);
  }
  if ((int)((uint)*(byte *)(DAT_08003fd8 + 2) << 0x1b) < 0) {
    local_c = local_c | 8;
  }
  if ((int)((uint)*(byte *)(DAT_08003fd8 + 2) << 0x1c) < 0) {
    local_c = local_c | 0x10;
  }
  if ((int)((uint)*(byte *)(DAT_08003fd8 + 2) << 0x1d) < 0) {
    local_c = local_c | 0x20;
  }
  if ((int)((uint)*(byte *)(DAT_08003fd8 + 4) << 0x1a) < 0) {
    local_c = local_c | 0x100;
  }
  if ((int)((uint)*(byte *)(DAT_08003fd8 + 4) << 0x1e) < 0) {
    local_c = local_c | 0x800;
  }
  if ((int)((uint)*(byte *)(DAT_08003fd8 + 4) << 0x1b) < 0) {
    local_c = local_c | 0x200;
  }
  if ((*(byte *)(DAT_08003fd8 + 4) & 1) != 0) {
    local_c = local_c | 0x1000;
  }
  if (*(char *)(DAT_08003fd8 + 4) < '\0') {
    local_c = local_c | 0x40;
  }
  *DAT_08003fdc = local_c;
  puVar1[1] = 0;
  return puVar1 + 2;
}



/* ===== FUN_08003fe0 @ 0x8003FE0 ===== */

void FUN_08003fe0(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  bool bVar4;
  int local_8;
  
  iVar3 = FUN_080049d4();
  pbVar2 = DAT_080040a8;
  if (iVar3 == 0) {
    *DAT_080040bc = 0;
    *DAT_080040b0 = '\0';
    *(byte *)(DAT_080040b4 + 3) = *(byte *)(DAT_080040b4 + 3) & 0xfb;
    *DAT_080040a8 = 0;
  }
  else {
    bVar1 = *DAT_080040a8;
    *DAT_080040a8 = bVar1 + 1;
    if ((byte)(bVar1 + 1) < 5) {
      if ((*DAT_080040b0 == '\x01') && (2 < *DAT_080040a8)) {
        *DAT_080040b8 = 2;
        local_8 = 500;
        do {
          bVar4 = local_8 != 0;
          local_8 = local_8 + -1;
        } while (bVar4);
        DAT_080040b8[4] = 2;
        if (*DAT_080040bc < 3) {
          FUN_08004a5c();
        }
        else if (3 < *DAT_080040bc) {
          *DAT_080040c0 = 1;
          *DAT_080040bc = 0;
        }
        *DAT_080040bc = *DAT_080040bc + 1;
      }
    }
    else {
      *pbVar2 = 0;
      FUN_0800cf94(DAT_080040ac);
      local_8 = 500;
      do {
        bVar4 = local_8 != 0;
        local_8 = local_8 + -1;
      } while (bVar4);
      *DAT_080040b0 = '\x01';
      *(byte *)(DAT_080040b4 + 3) = (*(byte *)(DAT_080040b4 + 3) & 0xfb) + 4;
    }
  }
  return;
}



/* ===== FUN_080040d8 @ 0x80040D8 ===== */

void FUN_080040d8(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  bool bVar4;
  undefined4 local_8;
  
  pbVar2 = DAT_08004130;
  if ((int)((uint)*DAT_0800412c << 0x1c) < 0) {
    bVar1 = *DAT_08004130;
    *DAT_08004130 = bVar1 + 1;
    if (4 < (byte)(bVar1 + 1)) {
      *pbVar2 = 0;
      FUN_0800cf94(DAT_08004134);
      local_8 = 500;
      do {
        bVar4 = local_8 != 0;
        local_8 = local_8 + -1;
      } while (bVar4);
      iVar3 = FUN_08004a5c();
      if (iVar3 != 0) {
        *DAT_0800412c = *DAT_0800412c & 0xf7;
      }
    }
  }
  else {
    *DAT_08004130 = 0;
  }
  return;
}



/* ===== FUN_0800414c @ 0x800414C ===== */

undefined4
FUN_0800414c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0800af7c(DAT_08004188,param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    iVar1 = FUN_0800af7c(DAT_08004188,param_2,param_3,param_4,param_5);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* ===== FUN_0800418c @ 0x800418C ===== */

undefined2 FUN_0800418c(void)

{
  uint uVar1;
  undefined4 in_r3;
  undefined4 local_10;
  
  local_10 = in_r3;
  uVar1 = FUN_08003c7a(8,0x83,&local_10,2);
  if ((uVar1 & 1) == 0) {
    local_10._0_2_ = 0;
  }
  else if (((char)local_10 == -1) || (local_10._1_1_ == -1)) {
    local_10._0_2_ = *DAT_080041d8;
  }
  else {
    *DAT_080041d8 = (undefined2)local_10;
  }
  return (undefined2)local_10;
}



/* ===== FUN_080041dc @ 0x80041DC ===== */

void FUN_080041dc(void)

{
  FUN_08003c60(8,0x12,DAT_080041ec,2);
  return;
}



/* ===== FUN_080042f4 @ 0x80042F4 ===== */

void FUN_080042f4(void)

{
  FUN_08003c60(8,0x3a,DAT_08004304,2);
  return;
}



/* ===== FUN_0800436c @ 0x800436C ===== */

void FUN_0800436c(void)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  
  iVar3 = FUN_080041dc();
  if (iVar3 == 0) {
    *DAT_080043bc = 0;
    pbVar2 = DAT_080043b8;
    bVar1 = *DAT_080043b8;
    *DAT_080043b8 = bVar1 + 1;
    if (3 < (byte)(bVar1 + 1)) {
      *pbVar2 = 0;
      *DAT_080043c0 = 0;
    }
  }
  else {
    *DAT_080043b8 = 0;
    pbVar2 = DAT_080043bc;
    bVar1 = *DAT_080043bc;
    *DAT_080043bc = bVar1 + 1;
    if (3 < (byte)(bVar1 + 1)) {
      *pbVar2 = 0;
      *DAT_080043c0 = 1;
    }
  }
  return;
}



/* ===== FUN_080043c4 @ 0x80043C4 ===== */

void FUN_080043c4(void)

{
  uint *puVar1;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = DAT_0800472c;
  local_8 = 0;
  local_c = (uint)(*(char *)(DAT_08004728 + 3) < '\0');
  if ((int)((uint)*(byte *)(DAT_08004728 + 3) << 0x1a) < 0) {
    local_c = local_c | 2;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 3) << 0x19) < 0) {
    local_c = local_c | 4;
  }
  if (*(char *)(DAT_08004728 + 7) < '\0') {
    local_c._0_2_ = CONCAT11(0x20,(undefined1)local_c);
    local_c = (uint)(ushort)local_c;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 3) << 0x1b) < 0) {
    local_c = local_c | 8;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 3) << 0x1c) < 0) {
    local_c = local_c | 0x10;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 3) << 0x1d) < 0) {
    local_c = local_c | 0x20;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 5) << 0x1a) < 0) {
    local_c = local_c | 0x100;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 5) << 0x1e) < 0) {
    local_c = local_c | 0x800;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 5) << 0x1b) < 0) {
    local_c = local_c | 0x200;
  }
  if ((*(byte *)(DAT_08004728 + 5) & 1) != 0) {
    local_c = local_c | 0x1000;
  }
  if (*(char *)(DAT_08004728 + 5) < '\0') {
    local_c = local_c | 0x40;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 5) << 0x19) < 0) {
    local_c = local_c | 0x80;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 5) << 0x1d) < 0) {
    local_c = local_c | 0x400;
  }
  if (*(char *)(DAT_08004728 + 0x11) < '\0') {
    local_8 = 0x200;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 0x11) << 0x1c) < 0) {
    local_8 = local_8 | 0x800;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 0x11) << 0x1d) < 0) {
    local_8 = local_8 | 0x1000;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 0x11) << 0x1b) < 0) {
    local_8 = local_8 | 0x400;
  }
  if (*(char *)(DAT_08004728 + 9) < '\0') {
    local_c._0_3_ = CONCAT12(8,(ushort)local_c);
    local_c = (uint)(uint3)local_c;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 9) << 0x19) < 0) {
    local_c = local_c | 0x100000;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 9) << 0x1b) < 0) {
    local_c = local_c | 0x200000;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 9) << 0x1c) < 0) {
    local_c = local_c | 0x400000;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 9) << 0x1d) < 0) {
    local_c = local_c | 0x800000;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 9) << 0x1e) < 0) {
    local_c = CONCAT13(1,(uint3)local_c);
  }
  if ((*(byte *)(DAT_08004728 + 9) & 1) != 0) {
    local_c = local_c | 0x2000000;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 0xb) << 0x1c) < 0) {
    local_c = local_c | 0x8000000;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 0xb) << 0x1b) < 0) {
    local_c = local_c | 0x10000000;
  }
  if ((*(byte *)(DAT_08004728 + 0xb) & 1) != 0) {
    local_c = local_c | 0x80000000;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 0xb) << 0x1e) < 0) {
    local_c = local_c | 0x40000000;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 0xb) << 0x1d) < 0) {
    local_c = local_c | 0x20000000;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 0xd) << 0x1a) < 0) {
    local_8 = CONCAT31(local_8._1_3_,4);
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 0xd) << 0x1c) < 0) {
    local_8 = local_8 | 0x10;
  }
  if ((int)((uint)*(byte *)(DAT_08004728 + 0xd) << 0x19) < 0) {
    local_8 = local_8 | 2;
  }
  *DAT_0800472c = local_c;
  puVar1[1] = local_8;
  return;
}



/* ===== FUN_08004730 @ 0x8004730 ===== */

undefined4
FUN_08004730(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0800b048(DAT_0800476c,param_2,param_3,param_4,param_5);
  if (iVar1 == 0) {
    iVar1 = FUN_0800b048(DAT_0800476c,param_2,param_3,param_4,param_5);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = 1;
  }
  return uVar2;
}



/* ===== FUN_08004770 @ 0x8004770 ===== */

undefined8
FUN_08004770(undefined4 param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,
            char param_5)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  local_24 = 0;
  local_20 = CONCAT13((char)((uint)param_4 >> 8),CONCAT12((char)param_4,param_3));
  local_28 = 4;
  iVar2 = FUN_0800b0a0(DAT_08004808,param_2,0x3e,&local_20);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    local_28 = 1000;
    do {
      bVar4 = local_28 != 0;
      local_28 = local_28 + -1;
    } while (bVar4);
    uVar1 = FUN_080068d8(&local_20,param_5 + '\x02');
    local_24._0_2_ = CONCAT11(param_5 + '\x04',uVar1);
    local_28 = 2;
    iVar2 = FUN_0800b0a0(DAT_08004808,param_2,0x60,&local_24);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      local_28 = 1000;
      do {
        bVar4 = local_28 != 0;
        local_28 = local_28 + -1;
      } while (bVar4);
      uVar3 = 1;
      local_28 = 0xffffffff;
    }
  }
  return CONCAT44(local_28,uVar3);
}



/* ===== FUN_0800480c @ 0x800480C ===== */

undefined4 FUN_0800480c(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  bool bVar6;
  undefined4 local_34;
  char local_30;
  undefined1 local_2f;
  undefined1 auStack_2e [18];
  
  FUN_080031d6(&local_30,0x14);
  local_34 = 0;
  cVar1 = (char)param_3;
  local_2f = (undefined1)((uint)param_3 >> 8);
  for (uVar5 = 0; uVar5 < 0xf; uVar5 = uVar5 + 1 & 0xff) {
    auStack_2e[uVar5] = *(undefined1 *)(param_4 + uVar5);
  }
  local_30 = cVar1;
  iVar3 = FUN_0800b048(DAT_080049d0,param_2,0x3e,&local_30,0x11);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    iVar3 = 30000;
    do {
      bVar6 = iVar3 != 0;
      iVar3 = iVar3 + -1;
    } while (bVar6);
    uVar2 = FUN_080068d8(&local_30,0x11);
    local_34._0_2_ = CONCAT11(0x13,uVar2);
    iVar3 = FUN_0800b048(DAT_080049d0,param_2,0x60,&local_34,2);
    if (iVar3 == 0) {
      uVar4 = 0;
    }
    else {
      iVar3 = 10000;
      do {
        bVar6 = iVar3 != 0;
        iVar3 = iVar3 + -1;
      } while (bVar6);
      local_30 = cVar1 + '\x0f';
      local_2f = (undefined1)((uint)(param_3 + 0xf) >> 8);
      for (uVar5 = 0; uVar5 < 0xf; uVar5 = uVar5 + 1 & 0xff) {
        auStack_2e[uVar5] = *(undefined1 *)(param_4 + uVar5 + 0xf);
      }
      iVar3 = FUN_0800b048(DAT_080049d0,param_2,0x3e,&local_30,0x11);
      if (iVar3 == 0) {
        uVar4 = 0;
      }
      else {
        iVar3 = 30000;
        do {
          bVar6 = iVar3 != 0;
          iVar3 = iVar3 + -1;
        } while (bVar6);
        uVar2 = FUN_080068d8(&local_30,0x11);
        local_34._0_2_ = CONCAT11(0x13,uVar2);
        iVar3 = FUN_0800b048(DAT_080049d0,param_2,0x60,&local_34,2);
        if (iVar3 == 0) {
          uVar4 = 0;
        }
        else {
          iVar3 = 10000;
          do {
            bVar6 = iVar3 != 0;
            iVar3 = iVar3 + -1;
          } while (bVar6);
          local_30 = cVar1 + '\x1e';
          local_2f = (undefined1)((uint)(param_3 + 0x1e) >> 8);
          for (uVar5 = 0; uVar5 < 2; uVar5 = uVar5 + 1 & 0xff) {
            auStack_2e[uVar5] = *(undefined1 *)(param_4 + uVar5 + 0x1e);
          }
          iVar3 = FUN_0800b048(DAT_080049d0,param_2,0x3e,&local_30,4);
          if (iVar3 == 0) {
            uVar4 = 0;
          }
          else {
            iVar3 = 10000;
            do {
              bVar6 = iVar3 != 0;
              iVar3 = iVar3 + -1;
            } while (bVar6);
            uVar2 = FUN_080068d8(&local_30,4);
            local_34._0_2_ = CONCAT11(6,uVar2);
            iVar3 = FUN_0800b048(DAT_080049d0,param_2,0x60,&local_34,2);
            if (iVar3 == 0) {
              uVar4 = 0;
            }
            else {
              iVar3 = 10000;
              do {
                bVar6 = iVar3 != 0;
                iVar3 = iVar3 + -1;
              } while (bVar6);
              uVar4 = 1;
            }
          }
        }
      }
    }
  }
  return uVar4;
}



/* ===== FUN_080049d4 @ 0x80049D4 ===== */

bool FUN_080049d4(void)

{
  return *DAT_080049e4 != 0;
}



/* ===== FUN_080049e8 @ 0x80049E8 ===== */

void FUN_080049e8(void)

{
  int iVar1;
  
  if (*(int *)(DAT_08004a50 + *DAT_08004a54 * 4) == 0) {
    *DAT_08004a54 = 0;
    FUN_080043c4();
    FUN_08003e94();
  }
  if (*(int *)(DAT_08004a50 + *DAT_08004a54 * 4) != 0) {
    iVar1 = (**(code **)(DAT_08004a50 + *DAT_08004a54 * 4))();
    if (iVar1 == 0) {
      *DAT_08004a58 = 1 << (sbyte)*DAT_08004a54 | *DAT_08004a58;
    }
    else {
      *DAT_08004a58 = *DAT_08004a58 & ~(1 << (sbyte)*DAT_08004a54);
    }
  }
  *DAT_08004a54 = *DAT_08004a54 + 1;
  return;
}



/* ===== FUN_08004a5c @ 0x8004A5C ===== */

uint FUN_08004a5c(void)

{
  uint uVar1;
  
  uVar1 = FUN_08003bdc(0x9a);
  return uVar1 & 1;
}



/* ===== FUN_08004a6c @ 0x8004A6C ===== */

void FUN_08004a6c(void)

{
  FUN_0801502c(*(undefined4 *)(DAT_08004a88 + 8));
  FUN_08006e50(*(undefined4 *)(DAT_08004a8c + 0x10));
  FUN_08006e50(*(undefined4 *)(DAT_08004a90 + 0x10));
  return;
}



/* ===== FUN_08004a94 @ 0x8004A94 ===== */

void FUN_08004a94(void)

{
  FUN_0800e624(1);
  FUN_0800a588(1,7);
  FUN_0800532c(DAT_08004b18,2);
  FUN_0800507c();
  FUN_08005278(*DAT_08004b20,DAT_08004b20[1],DAT_08004b20[2],DAT_08004b20[3],DAT_08004b20[4],
               DAT_08004b20[5],DAT_08004b20[6]);
  FUN_08005220(*DAT_08004b28,DAT_08004b28[1],DAT_08004b28[2],DAT_08004b28[3],DAT_08004b28[4],
               DAT_08004b28[5],DAT_08004b28[6],DAT_08004b24,0x96);
  FUN_080150e0(DAT_08004b20[2],0xc0,1);
  FUN_08014fe0(DAT_08004b20[2],0x424,1);
  FUN_08006f38(DAT_08004b28[4],1);
  FUN_080150c8(DAT_08004b20[2],1);
  return;
}



/* ===== FUN_08004b2c @ 0x8004B2C ===== */

void FUN_08004b2c(void)

{
  FUN_0800e624(1);
  FUN_0800532c(DAT_08004ba8,2);
  FUN_0800507c();
  FUN_08005278(*DAT_08004bb0,DAT_08004bb0[1],DAT_08004bb0[2],DAT_08004bb0[3],DAT_08004bb0[4],
               DAT_08004bb0[5],DAT_08004bb0[6]);
  FUN_08005220(*DAT_08004bb8,DAT_08004bb8[1],DAT_08004bb8[2],DAT_08004bb8[3],DAT_08004bb8[4],
               DAT_08004bb8[5],DAT_08004bb8[6],DAT_08004bb4,0x96);
  FUN_080150e0(DAT_08004bb0[2],0xc0,1);
  FUN_08014fe0(DAT_08004bb0[2],0x424,1);
  FUN_08006f38(DAT_08004bb8[4],1);
  FUN_080150c8(DAT_08004bb0[2],1);
  return;
}



/* ===== FUN_08004bbc @ 0x8004BBC ===== */

void FUN_08004bbc(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  if (param_1 == DAT_08004d04) {
    uVar2 = 0;
  }
  else if (param_1 == DAT_08004d08) {
    uVar2 = 1;
  }
  else if (param_1 == DAT_08004d0c) {
    uVar2 = 2;
  }
  else {
    if (param_1 != DAT_08004d10) {
      return;
    }
    uVar2 = 3;
  }
  if (param_2 == 0x100) {
    uVar1 = 8;
    *param_3 = 0x100;
    goto code_r0x08004cf8;
  }
  if (param_2 < 0x101) {
    if (param_2 == 0x10) {
      uVar1 = 4;
      *param_3 = 0x10;
      goto code_r0x08004cf8;
    }
    if (param_2 < 0x11) {
      if (param_2 == 1) {
        uVar1 = 0;
        *param_3 = 1;
        goto code_r0x08004cf8;
      }
      if (param_2 == 2) {
        uVar1 = 1;
        *param_3 = 2;
        goto code_r0x08004cf8;
      }
      if (param_2 == 4) {
        uVar1 = 2;
        *param_3 = 4;
        goto code_r0x08004cf8;
      }
      if (param_2 == 8) {
        uVar1 = 3;
        *param_3 = 8;
        goto code_r0x08004cf8;
      }
    }
    else {
      if (param_2 == 0x20) {
        uVar1 = 5;
        *param_3 = 0x20;
        goto code_r0x08004cf8;
      }
      if (param_2 == 0x40) {
        uVar1 = 6;
        *param_3 = 0x40;
        goto code_r0x08004cf8;
      }
      if (param_2 == 0x80) {
        uVar1 = 7;
        *param_3 = 0x80;
        goto code_r0x08004cf8;
      }
    }
  }
  else {
    if (param_2 == 0x1000) {
      uVar1 = 0xc;
      *param_3 = 0x1000;
      goto code_r0x08004cf8;
    }
    if (param_2 < 0x1001) {
      if (param_2 == 0x200) {
        uVar1 = 9;
        *param_3 = 0x200;
        goto code_r0x08004cf8;
      }
      if (param_2 == 0x400) {
        uVar1 = 10;
        *param_3 = 0x400;
        goto code_r0x08004cf8;
      }
      if (param_2 == 0x800) {
        uVar1 = 0xb;
        *param_3 = 0x800;
        goto code_r0x08004cf8;
      }
    }
    else {
      if (param_2 == 0x2000) {
        uVar1 = 0xd;
        *param_3 = 0x2000;
        goto code_r0x08004cf8;
      }
      if (param_2 == 0x4000) {
        uVar1 = 0xe;
        *param_3 = 0x4000;
        goto code_r0x08004cf8;
      }
      if (param_2 == 0x8000) {
        uVar1 = 0xf;
        *param_3 = 0x8000;
        goto code_r0x08004cf8;
      }
    }
  }
  uVar1 = 0;
  *param_3 = 1;
code_r0x08004cf8:
  FUN_0800a588(uVar2,uVar1);
  return;
}



/* ===== FUN_08004d14 @ 0x8004D14 ===== */

void FUN_08004d14(void)

{
  FUN_0800b678();
  return;
}



/* ===== FUN_08004d1c @ 0x8004D1C ===== */

void FUN_08004d1c(void)

{
  if (*DAT_08004d30 == 0) {
    disableIRQinterrupts();
  }
  *DAT_08004d30 = *DAT_08004d30 + 1;
  return;
}



/* ===== FUN_08004d34 @ 0x8004D34 ===== */

void FUN_08004d34(void)

{
  if ((*DAT_08004d58 == 1) || (*DAT_08004d58 == 0)) {
    enableIRQinterrupts();
    *DAT_08004d58 = 0;
  }
  else {
    *DAT_08004d58 = *DAT_08004d58 + -1;
  }
  return;
}



/* ===== FUN_08004d5c @ 0x8004D5C ===== */

void FUN_08004d5c(void)

{
  FUN_08005588();
  FUN_0800532c(DAT_08004d6c,0x1a);
  return;
}



/* ===== FUN_08004d70 @ 0x8004D70 ===== */

void FUN_08004d70(void)

{
  int iVar1;
  bool bVar2;
  int local_18;
  undefined4 local_14;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  
  local_10 = 0;
  local_e = 0xbfff;
  local_c = 0x30;
  local_a = 0x400;
  local_8 = 0x4000;
  local_14 = DAT_08004df4;
  FUN_0800b7f4(DAT_08004df8);
  FUN_0800532c(DAT_08004dfc,1);
  FUN_0800532c(DAT_08004e00,1);
  local_18 = 1000;
  do {
    bVar2 = local_18 != 0;
    local_18 = local_18 + -1;
  } while (bVar2);
  FUN_08004e0c(DAT_08004df8,&local_14);
  *DAT_08004e04 = (*DAT_08004e04 & 0xf) + 0x10;
  iVar1 = FUN_0800b874(DAT_08004df8,0x20000);
  if (iVar1 != 0) {
    *DAT_08004e08 = *DAT_08004e08 + '\x01';
  }
  return;
}



/* ===== FUN_08004e0c @ 0x8004E0C ===== */

undefined4 FUN_08004e0c(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int local_20;
  int *local_1c;
  int local_18;
  undefined4 local_14;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    uVar1 = 1;
  }
  else {
    local_20 = param_1;
    local_1c = param_2;
    local_18 = param_3;
    local_14 = param_4;
    if (param_1 == DAT_08004e7c) {
      FUN_0800e664(0x200000);
    }
    else {
      if (param_1 != DAT_08004e80) {
        return 1;
      }
      FUN_0800e664(0x400000);
    }
    FUN_0800b7f4(param_1);
    local_1c = (int *)param_2[1];
    local_18 = param_2[2];
    local_14 = CONCAT22(local_14._2_2_,(short)param_2[3]);
    local_20 = *param_2;
    FUN_0800b8c8(param_1,&local_20);
    FUN_0800b82c(param_1,1);
    uVar1 = 0;
  }
  return uVar1;
}



/* ===== FUN_08004e84 @ 0x8004E84 ===== */

undefined4
FUN_08004e84(int param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4,uint param_5)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = FUN_0800b874(param_1,0x20000,param_3,param_4,param_4);
  if (iVar2 != 0) {
    *DAT_08005024 = *DAT_08005024 + '\x01';
  }
  iVar2 = 0x1000;
  if (param_1 == 0) {
    return 1;
  }
  FUN_0800b7ca(param_1,1);
  while (iVar3 = FUN_0800b874(param_1,0x20000), iVar3 != 0) {
    bVar1 = iVar2 == 0;
    iVar2 = iVar2 + -1;
    if (bVar1) {
      return 2;
    }
  }
  FUN_0800b844(param_1,1);
  iVar2 = 0x1000;
  while (iVar3 = FUN_0800b794(param_1,DAT_08005028), iVar3 == 0) {
    bVar1 = iVar2 == 0;
    iVar2 = iVar2 + -1;
    if (bVar1) {
      FUN_0800b85c(param_1,1);
      return 3;
    }
  }
  FUN_0800b9bc(param_1,param_2,0);
  iVar2 = 0x1000;
  do {
    iVar3 = FUN_0800b794(param_1,DAT_08005030);
    if (iVar3 != 0) {
      FUN_0800b9ce(param_1,param_3);
      iVar2 = 0x1000;
      do {
        iVar3 = FUN_0800b794(param_1,DAT_08005030 + -2);
        if (iVar3 != 0) {
          do {
            uVar4 = param_5 - 1;
            if ((int)param_5 < 1) {
              FUN_0800b85c(param_1,1);
              return 0;
            }
            FUN_0800b9ce(param_1,*param_4);
            param_4 = param_4 + 1;
            iVar2 = 0x1000;
            while (iVar3 = FUN_0800b794(param_1,DAT_08005030 + 2), param_5 = uVar4 & 0xff,
                  iVar3 == 0) {
              iVar3 = FUN_0800b874(param_1,DAT_0800502c);
              if (iVar3 == 1) {
                FUN_0800b85c(param_1,1);
                FUN_0800b7be(param_1,DAT_0800502c);
                return 1;
              }
              bVar1 = iVar2 == 0;
              iVar2 = iVar2 + -1;
              if (bVar1) {
                FUN_0800b85c(param_1,1);
                return 3;
              }
            }
          } while( true );
        }
        iVar3 = FUN_0800b874(param_1,DAT_0800502c);
        if (iVar3 == 1) {
          FUN_0800b85c(param_1,1);
          FUN_0800b7be(param_1,DAT_0800502c);
          return 1;
        }
        bVar1 = iVar2 != 0;
        iVar2 = iVar2 + -1;
      } while (bVar1);
      FUN_0800b85c(param_1,1);
      return 3;
    }
    iVar3 = FUN_0800b874(param_1,DAT_0800502c);
    if (iVar3 == 1) {
      FUN_0800b85c(param_1,1);
      FUN_0800b7be(param_1,DAT_0800502c);
      return 1;
    }
    bVar1 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar1);
  FUN_0800b85c(param_1,1);
  return 3;
}



/* ===== FUN_08005034 @ 0x8005034 ===== */

void FUN_08005034(void)

{
  FUN_080050e0();
  FUN_08005600();
  FUN_0800eed0();
  FUN_08004d5c();
  FUN_0800cf94(DAT_08005074);
  FUN_08004a94();
  FUN_0800375c();
  FUN_0800378c();
  FUN_08009ed4();
  FUN_08012780();
  FUN_0800ba20(0xfff);
  *DAT_08005078 = 0xaaaa;
  return;
}



/* ===== FUN_0800507c @ 0x800507C ===== */

void FUN_0800507c(undefined4 param_1)

{
  undefined1 local_c;
  undefined1 local_b;
  undefined1 local_a;
  undefined1 local_9;
  undefined4 local_8;
  
  local_8._0_1_ = (undefined1)param_1;
  local_c = (undefined1)local_8;
  local_8._1_1_ = (undefined1)((uint)param_1 >> 8);
  local_b = local_8._1_1_;
  local_8._2_1_ = (undefined1)((uint)param_1 >> 0x10);
  local_a = local_8._2_1_;
  local_9 = 1;
  local_8 = param_1;
  FUN_0800e0b4(&local_c);
  return;
}



/* ===== FUN_080050a6 @ 0x80050A6 ===== */

void FUN_080050a6(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = param_3;
  local_c = param_4;
  FUN_0800e624(1);
  FUN_0800a588(1,0xb);
  FUN_08007970(0x800);
  local_10 = 0x800;
  local_c = CONCAT13((char)((uint)local_c >> 0x18),0x800);
  FUN_080079a4(&local_10);
  return;
}



/* ===== FUN_080050e0 @ 0x80050E0 ===== */

/* WARNING: Removing unreachable block (ram,0x080050e6) */
/* WARNING: Removing unreachable block (ram,0x080050ea) */

void FUN_080050e0(void)

{
  FUN_08012cdc();
  FUN_0800e664(0x10000000);
  FUN_0800e124(0x400);
  return;
}



/* ===== FUN_0800510c @ 0x800510C ===== */

void FUN_0800510c(void)

{
  int iVar1;
  
  FUN_0800e664(0x10000000);
  FUN_0800e6a4(1);
  FUN_0800e29c(1);
  FUN_0800e6fc(0);
  FUN_0800e6e4(1);
  do {
    iVar1 = FUN_0800e858(0x61);
  } while (iVar1 == 0);
  FUN_0800e5f0(0x200);
  FUN_0800e6fc(1);
  FUN_0800ee70();
  return;
}



/* ===== FUN_08005150 @ 0x8005150 ===== */

void FUN_08005150(void)

{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 0x7f;
  local_8 = 0x136;
  local_10 = 0;
  FUN_0800ed0c(&local_10);
  return;
}



/* ===== FUN_08005168 @ 0x8005168 ===== */

void FUN_08005168(void)

{
  ushort *puVar1;
  int iVar2;
  
  iVar2 = FUN_0800ec68(0x4000);
  if (iVar2 != 0) {
    FUN_0800e9dc(0x4000);
    FUN_08007970(0x100000);
    puVar1 = DAT_080051d0;
    if ((*DAT_080051c8 == '\x01') && (*DAT_080051cc == '\x01')) {
      *DAT_080051d0 = *DAT_080051d0 + (ushort)*DAT_080051d4;
      if (*puVar1 < 0x259) {
        *DAT_080051d8 = 1;
      }
      else {
        *DAT_080051d0 = 0;
        *DAT_080051d8 = 2;
      }
    }
    FUN_0800eb40(0);
  }
  return;
}



/* ===== FUN_080051dc @ 0x80051DC ===== */

void FUN_080051dc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0x18140802;
  local_10 = param_3;
  FUN_0800ed80(0,&local_c);
  local_10 = 0x4001010d;
  FUN_0800ea3c(0,&local_10);
  return;
}



/* ===== FUN_08005220 @ 0x8005220 ===== */

undefined4
FUN_08005220(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
            undefined4 param_9)

{
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  
  FUN_08006e50(param_5);
  local_44 = param_8;
  local_3c = param_9;
  local_38 = 0;
  local_34 = 0x80;
  local_30 = 0;
  local_2c = 0;
  local_20 = 0;
  local_48 = param_1;
  local_40 = param_2;
  local_28 = param_3;
  local_24 = param_4;
  FUN_08006f70(param_5,&local_48);
  FUN_08006fac(param_6,DAT_08005274,param_5,1);
  return 0;
}



/* ===== FUN_08005278 @ 0x8005278 ===== */

undefined4
FUN_08005278(undefined4 param_1,code *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  undefined4 local_28;
  code *pcStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  local_28 = param_1;
  pcStack_24 = param_2;
  uStack_20 = param_3;
  uStack_1c = param_4;
  (*param_2)(param_1,1);
  pcStack_24 = (code *)param_5;
  uStack_20 = param_6;
  uStack_1c = param_7;
  local_28 = param_4;
  FUN_08015148(param_3,&local_28);
  return 0;
}



/* ===== FUN_0800529e @ 0x800529E ===== */

void FUN_0800529e(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8,
                 undefined4 param_9)

{
  undefined1 uVar1;
  
  FUN_08005220(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
  uVar1 = (undefined1)((uint)param_9 >> 0x18);
  if ((char)param_7 == '\x01') {
    FUN_08006e3c(param_5,2,1);
    FUN_0800507c(CONCAT13(uVar1,(int3)((uint)param_7 >> 8)));
  }
  FUN_08006f38(param_5,1);
  return;
}



/* ===== FUN_080052f4 @ 0x80052F4 ===== */

void FUN_080052f4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = param_3;
  local_c = param_4;
  FUN_0800e624(1);
  FUN_0800a588(1,7);
  FUN_08007970(0x80);
  local_10 = 0x80;
  local_c = CONCAT13((char)((uint)local_c >> 0x18),0xc00);
  FUN_080079a4(&local_10);
  return;
}



/* ===== FUN_0800532c @ 0x800532C ===== */

void FUN_0800532c(int param_1,int param_2)

{
  uint uVar1;
  undefined4 local_30;
  undefined1 local_2c;
  undefined1 local_2b;
  undefined1 local_2a;
  undefined1 local_29;
  undefined4 local_28;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  undefined2 local_20;
  undefined1 local_1d;
  undefined1 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  local_30 = 1;
  for (uVar1 = 0; (int)uVar1 < param_2; uVar1 = uVar1 + 1 & 0xff) {
    FUN_080183b4(*(undefined4 *)(param_1 + uVar1 * 0x14));
    FUN_0800a7b0(&local_20);
    local_20 = *(undefined2 *)(param_1 + uVar1 * 0x14 + 4);
    if (((((*(int *)(param_1 + uVar1 * 0x14 + 7) == DAT_0800556c) ||
          (*(int *)(param_1 + uVar1 * 0x14 + 7) == DAT_08005570)) ||
         (*(int *)(param_1 + uVar1 * 0x14 + 7) == DAT_08005574)) ||
        ((*(int *)(param_1 + uVar1 * 0x14 + 7) == DAT_08005578 ||
         (*(int *)(param_1 + uVar1 * 0x14 + 7) == DAT_0800557c)))) ||
       (*(int *)(param_1 + uVar1 * 0x14 + 7) == DAT_08005580)) {
      if ((*(int *)(param_1 + uVar1 * 0x14) == DAT_08005584) &&
         (*(short *)(param_1 + uVar1 * 0x14 + 4) == 0x800)) {
        local_1c = *(undefined1 *)(param_1 + uVar1 * 0x14 + 6);
      }
      else {
        local_1c = 0;
      }
      local_18 = 0;
      FUN_0800a5c8(*(undefined4 *)(param_1 + uVar1 * 0x14),&local_20);
      FUN_08004bbc(*(undefined4 *)(param_1 + uVar1 * 0x14),local_20,&local_30);
      if ((*(int *)(param_1 + uVar1 * 0x14 + 7) == DAT_0800556c) ||
         (*(int *)(param_1 + uVar1 * 0x14 + 7) == DAT_08005578)) {
        local_23 = 8;
      }
      else if ((*(int *)(param_1 + uVar1 * 0x14 + 7) == DAT_08005570) ||
              (*(int *)(param_1 + uVar1 * 0x14 + 7) == DAT_0800557c)) {
        local_23 = 0xc;
      }
      else {
        local_23 = 0x10;
      }
      local_28 = local_30;
      local_24 = 0;
      local_22 = 1;
      FUN_080079a4(&local_28);
      local_29 = 1;
      local_2c = *(undefined1 *)(param_1 + uVar1 * 0x14 + 0x11);
      local_2b = *(undefined1 *)(param_1 + uVar1 * 0x14 + 0x12);
      local_2a = *(undefined1 *)(param_1 + uVar1 * 0x14 + 0x13);
      FUN_0800e0b4(&local_2c);
    }
    else {
      local_1d = *(undefined1 *)(param_1 + uVar1 * 0x14 + 0x10);
      local_1c = *(undefined1 *)(param_1 + uVar1 * 0x14 + 6);
      local_18 = *(undefined4 *)(param_1 + uVar1 * 0x14 + 7);
      local_14 = *(undefined4 *)(param_1 + uVar1 * 0x14 + 0xc);
      FUN_0800a5c8(*(undefined4 *)(param_1 + uVar1 * 0x14),&local_20);
    }
    if ((*(int *)(param_1 + uVar1 * 0x14 + 7) == 1) ||
       (*(int *)(param_1 + uVar1 * 0x14 + 7) == 0x11)) {
      FUN_0800a7e2(*(undefined4 *)(param_1 + uVar1 * 0x14),local_20,
                   *(undefined1 *)(param_1 + uVar1 * 0x14 + 0xb));
    }
  }
  return;
}



/* ===== FUN_08005588 @ 0x8005588 ===== */

undefined8 FUN_08005588(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 local_18;
  undefined1 local_16;
  undefined1 local_15;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = (undefined2)param_1;
  local_16 = (undefined1)((uint)param_1 >> 0x10);
  local_15 = (undefined1)((uint)param_1 >> 0x18);
  local_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  FUN_0800a7b0(&local_18);
  local_18 = 0xffff;
  local_14 = local_14 & 0xffffff00;
  local_10 = 3;
  local_15 = 1;
  local_c = 0xf;
  local_16 = 0;
  FUN_0800a5c8(DAT_080055dc,&local_18);
  FUN_0800a5c8(DAT_080055e0,&local_18);
  FUN_0800a5c8(DAT_080055e4,&local_18);
  local_18 = 0x9fff;
  FUN_0800a5c8(DAT_080055e8,&local_18);
  return CONCAT44(local_14,CONCAT13(local_15,CONCAT12(local_16,local_18)));
}



/* ===== FUN_080055ec @ 0x80055EC ===== */

void FUN_080055ec(void)

{
  DAT_e000e010 = DAT_e000e010 & 0xfffffffd;
  return;
}



/* ===== FUN_08005600 @ 0x8005600 ===== */

/* WARNING: Removing unreachable block (ram,0x08005634) */

void FUN_08005600(void)

{
  undefined1 auStack_24 [4];
  uint local_20;
  
  FUN_08013c84(4);
  FUN_0800e708(auStack_24);
  if (local_20 / 1000 - 1 < 0x1000000) {
    DAT_e000e014 = local_20 / 1000 - 1;
    *(undefined1 *)(DAT_08005664 + 0xb) = 0xf0;
    DAT_e000e018 = 0;
    DAT_e000e010 = 7;
  }
  return;
}



/* ===== FUN_08005668 @ 0x8005668 ===== */

void FUN_08005668(void)

{
  uint uVar1;
  
  FUN_0800aafc();
  if ((((*(char *)(DAT_080056e4 + 0xc) < '\0') || ((*(byte *)(DAT_080056e8 + 2) & 1) != 0)) ||
      ((int)((uint)*(byte *)(DAT_080056e8 + 2) << 0x1e) < 0)) ||
     (((int)((uint)*(byte *)(DAT_080056ec + 6) << 0x19) < 0 ||
      ((int)((uint)*(byte *)(DAT_080056ec + 9) << 0x1c) < 0)))) {
    if (*(int *)(DAT_080056e4 + 0xd) != 0) {
      FUN_080175ac(8,0x9335,0,1);
      *DAT_080056f0 = '\x01';
    }
  }
  else if ((*DAT_080056f0 == '\x01') && (uVar1 = FUN_080175ac(8,0x9335,3,1), (uVar1 & 1) != 0)) {
    *DAT_080056f0 = '\0';
  }
  return;
}



/* ===== FUN_080056f4 @ 0x80056F4 ===== */

void FUN_080056f4(void)

{
  FUN_08012900();
  FUN_08005b00();
  return;
}



/* ===== FUN_08005700 @ 0x8005700 ===== */

undefined4 FUN_08005700(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)FUN_08005994(*(undefined1 *)(param_1 + 2),DAT_08005738,param_3,param_4,param_4);
  if ((*DAT_08005738 == '\0') || (*(byte *)(*piVar1 + 8) < *(byte *)(param_1 + 3))) {
    uVar2 = 0;
  }
  else {
    FUN_08007dd8(1,*(undefined1 *)(param_1 + 1),param_1 + 3,param_1 + 4,piVar1);
    uVar2 = 1;
  }
  return uVar2;
}



/* ===== FUN_080058ec @ 0x80058EC ===== */

void FUN_080058ec(undefined1 *param_1,undefined1 *param_2,char *param_3)

{
  undefined2 uVar1;
  
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  param_2[2] = param_1[2];
  param_2[3] = param_1[3];
  FUN_080031a4(param_2 + 4,param_1 + 4,param_1[3]);
  uVar1 = FUN_08005c4c(param_2,param_1[3] + '\x04');
  param_2[(byte)param_1[3] + 4] = (char)((ushort)uVar1 >> 8);
  param_2[(byte)param_1[3] + 5] = (char)uVar1;
  *param_3 = param_1[3] + '\x06';
  return;
}



/* ===== FUN_08005940 @ 0x8005940 ===== */

void FUN_08005940(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_08005c04(0x8000000,0x3000,0);
  *DAT_08005958 = uVar1;
  return;
}



/* ===== FUN_08005994 @ 0x8005994 ===== */

int FUN_08005994(uint param_1,undefined1 *param_2)

{
  uint uVar1;
  
  *param_2 = 0;
  uVar1 = 0;
  while( true ) {
    if (0x39 < uVar1) {
      return 0;
    }
    if (*(byte *)(DAT_080059c8 + uVar1 * 8 + 4) == param_1) break;
    uVar1 = uVar1 + 1 & 0xffff;
  }
  *param_2 = 1;
  return DAT_080059c8 + uVar1 * 8;
}



/* ===== FUN_08005b00 @ 0x8005B00 ===== */

void FUN_08005b00(void)

{
  int iVar1;
  
  iVar1 = DAT_08005b1c;
  *(undefined2 *)(DAT_08005b1c + 2) = 0xfe;
  *(undefined2 *)(iVar1 + 4) = 0xfe;
  *(undefined2 *)(iVar1 + 0xe) = 2;
  *(undefined2 *)(iVar1 + 0xc) = 10;
  *(undefined2 *)(iVar1 + 8) = 0x102;
  *(undefined2 *)(iVar1 + 10) = 0x102;
  return;
}



/* ===== FUN_08005b20 @ 0x8005B20 ===== */

void FUN_08005b20(void)

{
  FUN_08003bdc(0x9a);
  return;
}



/* ===== FUN_08005b2a @ 0x8005B2A ===== */

void FUN_08005b2a(void)

{
  FUN_0800e304();
  FUN_08014aec();
  FUN_0800c788();
  FUN_08016924();
  return;
}



/* ===== bus_fault_Handler @ 0x8005B3E ===== */

void bus_fault_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_08005b40 @ 0x8005B40 ===== */

void FUN_08005b40(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_08005b42 @ 0x8005B42 ===== */

uint FUN_08005b42(byte *param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  bool bVar5;
  
  uVar3 = 0xffff;
  while (bVar5 = param_2 != 0, param_2 = param_2 - 1 & 0xffff, bVar5) {
    pbVar4 = param_1 + 1;
    uVar3 = uVar3 ^ *param_1;
    for (bVar1 = 0; param_1 = pbVar4, bVar1 < 8; bVar1 = bVar1 + 1) {
      uVar2 = uVar3 & 1;
      uVar3 = (int)uVar3 >> 1;
      if (uVar2 != 0) {
        uVar3 = uVar3 ^ 0xa001;
      }
    }
  }
  return ~uVar3 & 0xffff;
}



/* ===== FUN_08005b82 @ 0x8005B82 ===== */

void FUN_08005b82(byte *param_1,int param_2)

{
  uint uVar1;
  byte *pbVar2;
  int iVar3;
  bool bVar4;
  
  uVar1 = 0;
  while (bVar4 = param_2 != 0, param_2 = param_2 + -1, bVar4) {
    pbVar2 = param_1 + 1;
    uVar1 = uVar1 ^ (uint)*param_1 << 8;
    for (iVar3 = 0; param_1 = pbVar2, iVar3 < 8; iVar3 = iVar3 + 1) {
      if ((uVar1 & 0x8000) == 0) {
        uVar1 = uVar1 << 1;
      }
      else {
        uVar1 = uVar1 << 1 ^ 0x1021;
      }
      uVar1 = uVar1 & 0xffff;
    }
  }
  return;
}



/* ===== FUN_08005bc4 @ 0x8005BC4 ===== */

void FUN_08005bc4(uint param_1,byte *param_2,int param_3)

{
  byte *pbVar1;
  int iVar2;
  bool bVar3;
  
  while (bVar3 = param_3 != 0, param_3 = param_3 + -1, bVar3) {
    pbVar1 = param_2 + 1;
    param_1 = param_1 ^ (uint)*param_2 << 8;
    for (iVar2 = 0; param_2 = pbVar1, iVar2 < 8; iVar2 = iVar2 + 1) {
      if ((param_1 & 0x8000) == 0) {
        param_1 = param_1 << 1;
      }
      else {
        param_1 = param_1 << 1 ^ 0x1021;
      }
      param_1 = param_1 & 0xffff;
    }
  }
  return;
}



/* ===== FUN_08005c04 @ 0x8005C04 ===== */

uint FUN_08005c04(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if (param_3 == 0) {
    param_3 = 0xffffffff;
  }
  else {
    param_3 = ~param_3;
  }
  for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 1) {
    param_3 = param_3 ^ *(byte *)(param_1 + uVar1);
    for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
      if ((param_3 & 1) == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = 0xffffffff;
      }
      param_3 = uVar3 & DAT_08005c48 ^ param_3 >> 1;
    }
  }
  return ~param_3;
}



/* ===== FUN_08005c4c @ 0x8005C4C ===== */

void FUN_08005c4c(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  for (uVar1 = 0; (int)uVar1 < param_2; uVar1 = uVar1 + 1 & 0xff) {
  }
  return;
}



/* ===== FUN_08005c7c @ 0x8005C7C ===== */

void FUN_08005c7c(uint param_1,uint param_2)

{
  byte bVar1;
  
  param_2 = param_2 ^ param_1;
  for (bVar1 = 0; bVar1 < 8; bVar1 = bVar1 + 1) {
    if ((param_2 & 0x80) == 0) {
      param_2 = (param_2 & 0x7f) << 1;
    }
    else {
      param_2 = (param_2 & 0x7f) << 1 ^ 7;
    }
  }
  return;
}



/* ===== FUN_08005cac @ 0x8005CAC ===== */

void FUN_08005cac(void)

{
  if ((*DAT_08005d94 & 1) != 0) {
    *DAT_08005d94 = *DAT_08005d94 & 0xfffe;
    FUN_08013668(*DAT_08005d98);
  }
  if ((int)((uint)(byte)*DAT_08005d94 << 0x1e) < 0) {
    *DAT_08005d94 = *DAT_08005d94 & 0xfffd;
    FUN_08013674(DAT_08005d98[1]);
  }
  if ((int)((uint)(byte)*DAT_08005d94 << 0x1d) < 0) {
    *DAT_08005d94 = *DAT_08005d94 & 0xfffb;
    FUN_08013724(DAT_08005d98[2],*(undefined4 *)(DAT_08005d9c + 0xc));
  }
  if ((int)((uint)(byte)*DAT_08005d94 << 0x1c) < 0) {
    *DAT_08005d94 = *DAT_08005d94 & 0xfff7;
    FUN_08013724(*(undefined4 *)(DAT_08005d9c + 8),DAT_08005d98[3]);
  }
  if ((int)((uint)(byte)*DAT_08005d94 << 0x1b) < 0) {
    *DAT_08005d94 = *DAT_08005d94 & 0xffef;
    FUN_080137d4(*(undefined2 *)(DAT_08005d98 + 4),*(undefined1 *)(DAT_08005d9c + 0x12));
  }
  if ((int)((uint)(byte)*DAT_08005d94 << 0x1a) < 0) {
    *DAT_08005d94 = *DAT_08005d94 & 0xffdf;
    FUN_080137d4(*(undefined2 *)(DAT_08005d9c + 0x10),*(undefined1 *)((int)DAT_08005d98 + 0x12));
  }
  if ((int)((uint)(byte)*DAT_08005d94 << 0x19) < 0) {
    *DAT_08005d94 = *DAT_08005d94 & 0xffbf;
    FUN_08013888(*(undefined2 *)((int)DAT_08005d98 + 0x13));
  }
  return;
}



/* ===== FUN_08005de4 @ 0x8005DE4 ===== */

void FUN_08005de4(void)

{
  char cVar1;
  undefined1 *puVar2;
  
  if (*DAT_08005ee0 == '\0') {
    FUN_080031d6(DAT_08005ee4,0x1d);
    *DAT_08005ee8 = '\0';
    *DAT_08005eec = 0;
  }
  puVar2 = DAT_08005ee4;
  DAT_08005ee4[1] = *DAT_08005ef0;
  *puVar2 = *DAT_08005ef4;
  cVar1 = *DAT_08005ef0;
  if (cVar1 == '\0') {
    if (*DAT_08005ee0 == '\x01') {
      *DAT_08005ef0 = '\x01';
      *DAT_08005ee8 = '\0';
    }
  }
  else if (cVar1 == '\x01') {
    if (*DAT_08005ee0 == '\0') {
      *DAT_08005ef0 = '\0';
      *DAT_08005ee8 = '\0';
    }
    else {
      FUN_08005f00();
      if (*DAT_08005ee8 == '\x03') {
        *DAT_08005ef0 = '\x03';
      }
      else if (*DAT_08005ee8 == '\x01') {
        *DAT_08005ef0 = '\x02';
      }
      else if (*DAT_08005ee8 == '\x02') {
        FUN_0800532c(DAT_08005ef8,1);
        FUN_0800532c(DAT_08005efc,1);
        *DAT_08005ef0 = '\x01';
      }
    }
  }
  else if (cVar1 == '\x02') {
    if (*DAT_08005ee0 == '\0') {
      *DAT_08005ef0 = '\x01';
      *DAT_08005ee8 = '\0';
    }
  }
  else if (cVar1 == '\x03') {
    if ((*DAT_08005ee0 == '\0') || (*DAT_08005ee8 == '\x02')) {
      FUN_0800532c(DAT_08005ef8,1);
      FUN_0800532c(DAT_08005efc,1);
      *DAT_08005ef0 = '\x01';
      *DAT_08005ee8 = '\0';
    }
    else {
      FUN_08005f00();
    }
  }
  else {
    *DAT_08005ef0 = '\x01';
    *DAT_08005ee8 = '\0';
  }
  return;
}



/* ===== FUN_08005f00 @ 0x8005F00 ===== */

void FUN_08005f00(void)

{
  bool bVar1;
  int iVar2;
  byte *pbVar3;
  byte bVar4;
  undefined1 uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  undefined4 local_70;
  undefined1 local_6c;
  undefined2 local_6b;
  undefined1 local_69 [28];
  undefined2 local_4d;
  undefined1 local_48;
  byte local_47;
  undefined1 local_46;
  undefined1 auStack_45 [37];
  
  FUN_080031d6(&local_48,0x28);
  iVar7 = 0;
  bVar1 = false;
  uVar8 = 0;
  FUN_080031d6(&local_6c,0x24);
  *DAT_08006290 = *DAT_08006290 + 1;
  switch(*DAT_08006294) {
  case 0:
    *DAT_08006290 = 0;
    *DAT_08006298 = 0;
    if (*DAT_0800629c == '\x01') {
      FUN_080050a6();
      FUN_08004b2c();
      *DAT_08006294 = 1;
      *DAT_080062a0 = 0;
    }
    else {
      *DAT_080062a0 = 1;
    }
    break;
  case 1:
    if (*DAT_08006298 < 0xb) {
      if (0x14 < *DAT_08006290) {
        local_6b = 2;
        bVar1 = true;
        *DAT_08006290 = 0;
        *DAT_080062a0 = 0;
      }
    }
    else {
      *DAT_08006294 = 0;
      *DAT_080062a0 = 1;
      *DAT_08006298 = 0;
    }
    iVar7 = 0;
    break;
  case 2:
    if (*DAT_08006298 < 4) {
      if (0x14 < *DAT_08006290) {
        local_6b = 4;
        bVar1 = true;
        *DAT_08006290 = 0;
        *DAT_080062a0 = 0;
      }
    }
    else {
      *DAT_08006294 = 0;
      *DAT_080062a0 = 2;
      *DAT_08006298 = 0;
    }
    iVar7 = 0;
    break;
  case 3:
    if (*DAT_08006298 < 4) {
      if (0x14 < *DAT_08006290) {
        bVar4 = (local_6b._1_1_ & 0xf) + 0x40;
        local_6b = CONCAT11(bVar4,0x1c);
        iVar7 = (uint)(bVar4 >> 4) << 2;
        FUN_080031d6(DAT_080062a4,0x10);
        for (uVar8 = 0; uVar8 < 0x10; uVar8 = uVar8 + 1 & 0xff) {
          uVar5 = FUN_08003180();
          iVar2 = DAT_080062a4;
          *(undefined1 *)(DAT_080062a4 + uVar8) = uVar5;
          local_69[uVar8] = *(undefined1 *)(iVar2 + uVar8);
        }
        bVar1 = true;
        *DAT_08006290 = 0;
        *DAT_080062a0 = 0;
      }
    }
    else {
      *DAT_08006294 = 0;
      *DAT_080062a0 = 2;
      *DAT_08006298 = 0;
    }
    break;
  case 4:
    if (*DAT_08006298 < 4) {
      if (0x14 < *DAT_08006290) {
        local_6b = 6;
        bVar1 = true;
        *DAT_08006290 = 0;
        *DAT_080062a0 = 0;
      }
    }
    else {
      *DAT_08006294 = 0;
      *DAT_080062a0 = 2;
      *DAT_08006298 = 0;
    }
    iVar7 = 0;
    break;
  case 5:
    if (*DAT_08006298 < 4) {
      if (0x1e < *DAT_08006290) {
        bVar4 = (local_6b._1_1_ & 0xf) + 0x10;
        local_6b = CONCAT11(bVar4,8);
        iVar7 = (uint)(bVar4 >> 4) << 2;
        if (0x13f < (uint)*DAT_080062a8 * 100) {
          uVar8 = FUN_0800fd2c(((*(ushort *)(DAT_080062ac + 6) & 0xfff) >> 2) * 10,
                               ((*(ushort *)(DAT_080062ac + 5) & 0x3ff) >> 4) * 10,
                               *(ushort *)(DAT_080062ac + 4) & 0xfff,(uint)*DAT_080062a8 * 100);
        }
        uVar6 = FUN_0800fd2c((*(ushort *)(DAT_080062ac + 10) >> 4) * 10,
                             ((*(ushort *)(DAT_080062ac + 9) & 0xfff) >> 2) * 5,
                             *(ushort *)(DAT_080062ac + 8) & 0x3ff,0xd548);
        iVar2 = DAT_080062b0;
        local_70 = CONCAT22((short)(uVar8 / 10),(short)(uVar6 / 5)) & 0xfffffff;
        *(undefined2 *)(DAT_080062b0 + 0x18) = (undefined2)local_70;
        *(ushort *)(iVar2 + 0x1a) = (ushort)(((local_70 >> 0x10) << 0x14) >> 0x14);
        local_69[1] = (undefined1)(local_70 >> 0x10);
        local_69[2] = (undefined1)(local_70 >> 8);
        local_69[3] = (undefined1)local_70;
        bVar1 = true;
        *DAT_08006290 = 0;
        *DAT_080062a0 = 0;
        local_69[0] = local_70._3_1_;
      }
    }
    else {
      *DAT_08006294 = 0;
      *DAT_080062a0 = 2;
      *DAT_08006298 = 0;
    }
  }
  pbVar3 = DAT_080062b4;
  if (bVar1) {
    local_6c = 0xaa;
    local_47 = local_6b._1_1_ & 0xf0 | *DAT_080062b4 & 0xf;
    local_6b = CONCAT11(local_47,(undefined1)local_6b);
    *DAT_080062b4 = *DAT_080062b4 + 1;
    if (7 < *pbVar3) {
      *pbVar3 = 0;
    }
    local_48 = 0xaa;
    local_46 = (undefined1)local_6b;
    if (iVar7 != 0) {
      FUN_080031a4(auStack_45,local_69,iVar7);
    }
    local_4d = FUN_08005b42(&local_47,iVar7 + 2);
    auStack_45[iVar7] = (char)((ushort)local_4d >> 8);
    auStack_45[iVar7 + 1] = (undefined1)local_4d;
    FUN_08015284(2,&local_48,iVar7 + 5);
    *DAT_08006290 = 0;
    *DAT_08006298 = *DAT_08006298 + 1;
  }
  return;
}



/* ===== FUN_080062b8 @ 0x80062B8 ===== */

void FUN_080062b8(void)

{
  byte *pbVar1;
  ushort *puVar2;
  int iVar3;
  
  if (*DAT_08006330 == '\x01') {
    iVar3 = FUN_0800a7c8(DAT_08006334,0x800);
    pbVar1 = DAT_08006338;
    if (iVar3 == 0) {
      *DAT_08006338 = 0;
    }
    else {
      *DAT_08006338 = *DAT_08006338 + 1;
      if (5 < *pbVar1) {
        *pbVar1 = 0;
        *DAT_0800633c = 1;
        *DAT_08006330 = '\0';
      }
    }
    puVar2 = DAT_08006340;
    *DAT_08006340 = *DAT_08006340 + 1;
    if (1000 < *puVar2) {
      *puVar2 = 0;
      *DAT_0800633c = 0;
      *DAT_08006330 = '\0';
    }
  }
  else {
    *DAT_08006340 = 0;
    *DAT_08006338 = 0;
  }
  return;
}



/* ===== FUN_08006344 @ 0x8006344 ===== */

void FUN_08006344(void)

{
  uint *puVar1;
  byte *pbVar2;
  ushort *puVar3;
  int iVar4;
  
  puVar1 = DAT_0800648c;
  *DAT_0800648c = (uint)*(ushort *)(DAT_08006488 + 0x34) * 10;
  if (*DAT_08006490 == '\0') {
    if (((((int)((uint)*(byte *)(DAT_08006494 + 1) << 0x1d) < 0) || (0xe09b < *puVar1)) ||
        (*DAT_08006498 != '\x01')) ||
       (iVar4 = FUN_0800a7c8(DAT_0800649c,0x200), pbVar2 = DAT_080064a0, iVar4 != 0)) {
      *DAT_080064a0 = 0;
    }
    else {
      *DAT_080064a0 = *DAT_080064a0 + 1;
      if (0x3c < *pbVar2) {
        *pbVar2 = 0;
        *DAT_08006490 = '\x01';
      }
    }
    pbVar2 = DAT_080064a8;
    if ((((int)((uint)*(byte *)(DAT_08006494 + 1) << 0x1d) < 0) || (0xe09b < *DAT_0800648c)) ||
       (*DAT_0800648c + 0x5dc < *DAT_080064a4)) {
      *DAT_080064a8 = 0;
    }
    else {
      *DAT_080064a8 = *DAT_080064a8 + 1;
      if (0x96 < *pbVar2) {
        *pbVar2 = 0;
        *DAT_08006490 = '\x01';
      }
    }
    *DAT_080064ac = 0;
  }
  else {
    if ((*DAT_080064b0 == '\0') ||
       (((*DAT_08006498 != '\x01' || (iVar4 = FUN_0800a7c8(DAT_0800649c,0x200), iVar4 == 0)) &&
        ((*DAT_08006498 != '\0' || (*DAT_080064a4 <= *DAT_0800648c + 0x5dc)))))) {
      *DAT_080064ac = 0;
    }
    else {
      puVar3 = DAT_080064ac;
      *DAT_080064ac = *DAT_080064ac + 1;
      if (0x14 < *puVar3) {
        FUN_0800532c(DAT_080064b4,1);
        FUN_0800532c(DAT_080064b8,1);
        *DAT_08006498 = '\0';
        *DAT_080064bc = 1;
        *DAT_08006490 = '\0';
        *DAT_080064ac = 0;
      }
    }
    *DAT_080064a0 = 0;
    *DAT_080064a8 = 0;
  }
  return;
}



/* ===== FUN_080064c0 @ 0x80064C0 ===== */

undefined4 FUN_080064c0(void)

{
  undefined4 uVar1;
  
  if ((((*DAT_080064fc == '\0') || (*(ushort *)(DAT_08006500 + 6) < 0x7d1)) ||
      (0x1193 < *(ushort *)(DAT_08006500 + 8))) ||
     ((*(char *)(DAT_08006504 + 1) < -0x27 || ('c' < *(char *)(DAT_08006504 + 2))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* ===== FUN_08006508 @ 0x8006508 ===== */

void FUN_08006508(void)

{
  char cVar1;
  ushort *puVar2;
  byte *pbVar3;
  ushort *puVar4;
  
  puVar4 = DAT_0800662c;
  puVar2 = DAT_0800661c;
  cVar1 = *DAT_08006614;
  if (cVar1 == '\0') {
    if (*DAT_08006618 == '\x01') {
      *DAT_0800661c = *DAT_0800661c + 1;
      if (9 < *puVar2) {
        *puVar2 = 0;
        FUN_0800f670();
        *DAT_08006614 = '\x01';
      }
    }
    else {
      *DAT_0800661c = 0;
    }
    pbVar3 = DAT_08006624;
    if (*DAT_08006620 == '\x01') {
      *DAT_08006624 = *DAT_08006624 + 1;
      if (1 < *pbVar3) {
        *DAT_08006620 = '\0';
        *DAT_08006624 = 0;
        *DAT_08006628 = *DAT_08006614;
        *DAT_08006614 = '\x02';
      }
    }
    else {
      *DAT_08006624 = 0;
    }
  }
  else if (cVar1 == '\x01') {
    if (*DAT_08006618 == '\x01') {
      *DAT_0800662c = 0;
    }
    else {
      *DAT_0800662c = *DAT_0800662c + 1;
      if (9 < *puVar4) {
        *puVar4 = 0;
        FUN_0800f5d4();
        *DAT_08006614 = '\0';
      }
    }
    pbVar3 = DAT_08006624;
    if (*DAT_08006620 == '\x01') {
      *DAT_08006624 = *DAT_08006624 + 1;
      if (1 < *pbVar3) {
        *DAT_08006620 = '\0';
        *DAT_08006624 = 0;
        *DAT_08006628 = *DAT_08006614;
        *DAT_08006614 = '\x02';
      }
    }
    else {
      *DAT_08006624 = 0;
    }
  }
  else if (cVar1 == '\x02') {
    FUN_0800f534();
    *DAT_08006614 = *DAT_08006628;
  }
  else {
    *DAT_08006628 = '\0';
    *DAT_08006614 = '\0';
  }
  return;
}



/* ===== FUN_08006630 @ 0x8006630 ===== */

void FUN_08006630(void)

{
  int iVar1;
  
  *DAT_080066c4 = 1;
  if ((((*DAT_080066c8 == '\x02') || (*DAT_080066c8 == '\x03')) && (*DAT_080066cc == '\x01')) &&
     (iVar1 = FUN_0800ae14(), iVar1 == 0)) {
    *DAT_080066d0 = 1;
  }
  else {
    *DAT_080066d0 = 0;
  }
  if (((*DAT_080066d4 == '\x01') || (*DAT_080066d8 == '\x01')) ||
     ((*DAT_080066dc == '\0' || (iVar1 = FUN_0800c6a4(), iVar1 == 1)))) {
    *DAT_080066d0 = 0;
  }
  if (((*DAT_080066e0 == '\x01') || (*DAT_080066d8 == '\x01')) ||
     ((*DAT_080066dc == '\0' ||
      ((*DAT_080066e4 == '\x01' || (iVar1 = FUN_0800a7c8(DAT_080066e8,0x100), iVar1 == 0)))))) {
    *DAT_080066c4 = 0;
  }
  return;
}



/* ===== FUN_080066ec @ 0x80066EC ===== */

void FUN_080066ec(void)

{
  if (((((((((*(byte *)(DAT_080068b0 + 2) & 1) == 0 && (*(byte *)(DAT_080068b0 + 2) & 3) >> 1 == 0)
           && (*(byte *)(DAT_080068b0 + 2) & 7) >> 2 == 0) &&
          (*(byte *)(DAT_080068b0 + 2) & 0xf) >> 3 == 0) && -1 < *(char *)(DAT_080068b4 + 0xc)) &&
        (*(byte *)(DAT_080068b8 + 9) & 3) >> 1 == 0) &&
       (*(byte *)(DAT_080068b8 + 9) & 0xf) >> 3 == 0) &&
      -1 < (int)((uint)*(byte *)(DAT_080068b8 + 6) << 0x19)) &&
      -1 < (int)((uint)*(byte *)(DAT_080068b0 + 3) << 0x1d)) {
    *DAT_080068bc = '\0';
  }
  else {
    *DAT_080068bc = '\x01';
  }
  if (((int)((uint)*(byte *)(DAT_080068b4 + 0xc) << 0x1c |
             (uint)*(byte *)(DAT_080068b4 + 0xc) << 0x19 |
             (uint)*(byte *)(DAT_080068b4 + 0xc) << 0x1b | (uint)*(byte *)(DAT_080068c0 + 8) << 0x1c
             | (uint)*(byte *)(DAT_080068c0 + 8) << 0x1b | (uint)*(byte *)(DAT_080068c0 + 8) << 0x1a
            | (uint)*(byte *)(DAT_080068c0 + 8) << 0x19) < 0 ||
      (int)((uint)*(byte *)(DAT_080068b8 + 6) << 0x1c) < 0) ||
      (int)((uint)*(byte *)(DAT_080068b8 + 6) << 0x1a) < 0) {
    *DAT_080068c4 = '\x01';
  }
  else {
    *DAT_080068c4 = '\0';
  }
  if (((((((*(byte *)(DAT_080068b4 + 0xc) & 1) == 0 && (*(byte *)(DAT_080068b4 + 0x17) & 1) == 0) &&
         (*(byte *)(DAT_080068b4 + 0xc) & 3) >> 1 == 0) && (*(byte *)(DAT_080068c0 + 8) & 1) == 0)
       && (*(byte *)(DAT_080068c0 + 8) & 3) >> 1 == 0) && (*(byte *)(DAT_080068b8 + 6) & 1) == 0) &&
      -1 < (int)((uint)*(byte *)(DAT_080068b8 + 6) << 0x1e)) {
    *DAT_080068c8 = '\0';
  }
  else {
    *DAT_080068c8 = '\x01';
  }
  if ((*DAT_080068bc == '\0' && *DAT_080068c4 == '\0') && *DAT_080068c8 == '\0') {
    *DAT_080068cc = 0;
  }
  else {
    *DAT_080068cc = 1;
  }
  if ((((((((*(byte *)(DAT_080068b0 + 2) & 1) == 0 && (*(byte *)(DAT_080068b0 + 2) & 3) >> 1 == 0)
          && (*(byte *)(DAT_080068b0 + 2) & 7) >> 2 == 0) &&
         (*(byte *)(DAT_080068b0 + 2) & 0xf) >> 3 == 0) && -1 < *(char *)(DAT_080068b4 + 0xc)) &&
       (*(byte *)(DAT_080068b8 + 9) & 0xf) >> 3 == 0) &&
      -1 < (int)((uint)*(byte *)(DAT_080068b8 + 6) << 0x19)) &&
      -1 < (int)((uint)*(byte *)(DAT_080068b0 + 3) << 0x1d)) {
    *DAT_080068d0 = 0;
  }
  else {
    *DAT_080068d0 = 1;
  }
  if (((int)((uint)*(byte *)(DAT_080068b8 + 9) << 0x1e) < 0 || *DAT_080068c8 != '\0') ||
      *DAT_080068c4 != '\0') {
    *DAT_080068d4 = 1;
  }
  else {
    *DAT_080068d4 = 0;
  }
  return;
}



/* ===== FUN_080068d8 @ 0x80068D8 ===== */

byte FUN_080068d8(int param_1,int param_2)

{
  uint uVar1;
  byte bVar2;
  
  bVar2 = 0;
  for (uVar1 = 0; (int)uVar1 < param_2; uVar1 = uVar1 + 1 & 0xff) {
    bVar2 = *(char *)(param_1 + uVar1) + bVar2;
  }
  return ~bVar2;
}



/* ===== FUN_080068f8 @ 0x80068F8 ===== */

uint FUN_080068f8(void)

{
  int iVar1;
  uint uVar2;
  int in_r3;
  uint uVar3;
  bool bVar4;
  
  uVar3 = 1;
  if ((*DAT_08006988 == '\x01') && (-1 < (int)((uint)*(byte *)(DAT_0800698c + 1) << 0x1e))) {
    iVar1 = FUN_0800b400();
    if (iVar1 == 0) {
      uVar3 = FUN_0800df58(DAT_08006990,2,1);
      uVar3 = uVar3 & 1;
      iVar1 = 500;
      do {
        bVar4 = iVar1 != 0;
        iVar1 = iVar1 + -1;
      } while (bVar4);
      in_r3 = -1;
    }
  }
  else if ((*DAT_08006988 == '\0') && ((int)((uint)*(byte *)(DAT_0800698c + 1) << 0x1e) < 0)) {
    uVar3 = FUN_08003bdc(0x94);
    uVar3 = uVar3 & 1;
    iVar1 = 500;
    do {
      in_r3 = iVar1 + -1;
      bVar4 = iVar1 != 0;
      iVar1 = in_r3;
    } while (bVar4);
  }
  uVar2 = FUN_08003c60(8,0x7f,DAT_08006990,1,in_r3);
  *(byte *)(DAT_0800698c + 1) = *(byte *)(DAT_0800698c + 1) & 0xfd | (*DAT_08006990 & 1) << 1;
  return uVar3 & uVar2;
}



/* ===== FUN_08006994 @ 0x8006994 ===== */

void FUN_08006994(void)

{
  undefined1 *puVar1;
  
  FUN_080069ac();
  puVar1 = DAT_080069a8;
  DAT_080069a8[1] = 0;
  *puVar1 = 1;
  return;
}



/* ===== FUN_080069ac @ 0x80069AC ===== */

void FUN_080069ac(void)

{
  *DAT_080069b4 = 1;
  return;
}



/* ===== FUN_080069b8 @ 0x80069B8 ===== */

void FUN_080069b8(int param_1)

{
  bool bVar1;
  int local_10;
  
  if ((param_1 != 0) && ((param_1 == 1 || (param_1 == 2)))) {
    FUN_080036d4();
    FUN_0800a348();
    FUN_08012770();
    FUN_08004a6c();
    FUN_08006e08();
    local_10 = DAT_08006a00;
    do {
      bVar1 = local_10 != 0;
      local_10 = local_10 + -1;
    } while (bVar1);
    FUN_08003bdc(0x99);
  }
  return;
}



/* ===== FUN_08006a04 @ 0x8006A04 ===== */

void FUN_08006a04(void)

{
  *DAT_08006a1c = 0;
  *DAT_08006a20 = 0;
  *DAT_08006a24 = 0;
  *DAT_08006a28 = 0;
  *DAT_08006a2c = 0;
  return;
}



/* ===== FUN_08006a30 @ 0x8006A30 ===== */

void FUN_08006a30(void)

{
  int iVar1;
  undefined1 auStack_9c [152];
  
  FUN_08006a04();
  iVar1 = FUN_08014f44(auStack_9c);
  if (iVar1 != 0) {
    FUN_0800ff10(auStack_9c);
  }
  return;
}



/* ===== FUN_08006a4c @ 0x8006A4C ===== */

void FUN_08006a4c(undefined4 param_1,undefined1 *param_2)

{
  int iVar1;
  uint local_a8;
  undefined1 auStack_a4 [152];
  
  FUN_080031d6(auStack_a4,0x98);
  local_a8 = 0;
  FUN_08006a04();
  iVar1 = FUN_08017a60(param_2 + 2,*param_2);
  if (iVar1 == 1) {
    iVar1 = FUN_08017b84();
    if (iVar1 == 1) {
      FUN_08017c94(auStack_a4,&local_a8);
      FUN_080151fc(param_1,auStack_a4,local_a8 & 0xff);
      *DAT_08006aec = 1;
      *DAT_08006af0 = 0;
    }
  }
  else {
    iVar1 = FUN_0800c6b0(param_2);
    if (((iVar1 == 1) && (iVar1 = (*(code *)*DAT_08006af8)(param_2,*DAT_08006af4), iVar1 == 1)) &&
       (iVar1 = (*(code *)*DAT_08006afc)(*DAT_08006af4), iVar1 == 1)) {
      (*(code *)*DAT_08006b00)(*DAT_08006af4,auStack_a4,&local_a8);
      FUN_080151fc(param_1,auStack_a4,local_a8 & 0xff);
      *DAT_08006aec = 1;
      *DAT_08006af0 = 0;
    }
  }
  return;
}



/* ===== FUN_08006b04 @ 0x8006B04 ===== */

void FUN_08006b04(void)

{
  int iVar1;
  undefined1 auStack_9c [152];
  
  FUN_08006a04();
  iVar1 = FUN_08014d04(auStack_9c);
  if (iVar1 != 0) {
    FUN_08006a4c(0,auStack_9c);
  }
  return;
}



/* ===== FUN_08006b20 @ 0x8006B20 ===== */

void FUN_08006b20(void)

{
  uint *puVar1;
  int iVar2;
  bool bVar3;
  
  iVar2 = 10000;
  do {
    if ((DAT_08006bb8[4] & 2) == 2) break;
    bVar3 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar3);
  thunk_FUN_0800726e(100);
  puVar1 = DAT_08006bbc;
  *DAT_08006bbc = *DAT_08006bbc & 0xfdffffff;
  *puVar1 = *puVar1 | 0x2000000;
  puVar1 = DAT_08006bb8;
  *DAT_08006bb8 = *DAT_08006bb8 & 0xfffff9ff;
  *puVar1 = *puVar1 | 0x400;
  iVar2 = 10000;
  do {
    if ((DAT_08006bb8[4] & 2) == 0) break;
    bVar3 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar3);
  iVar2 = 10000;
  do {
    if ((DAT_08006bb8[4] & 2) == 2) {
      return;
    }
    bVar3 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar3);
  return;
}



/* ===== FUN_08006bc0 @ 0x8006BC0 ===== */

void FUN_08006bc0(int param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if (param_1 < 6) {
    FUN_08004d1c();
    iVar1 = DAT_08006be4 + param_1 * 0x10;
    *(undefined4 *)(iVar1 + 8) = param_2;
    *(undefined4 *)(iVar1 + 0xc) = param_3;
    FUN_08004d34();
  }
  return;
}



/* ===== FUN_08006be8 @ 0x8006BE8 ===== */

void FUN_08006be8(void)

{
  undefined1 *puVar1;
  byte bVar2;
  
  *DAT_08006c0c = 0;
  puVar1 = DAT_08006c10;
  for (bVar2 = 0; bVar2 < 6; bVar2 = bVar2 + 1) {
    *puVar1 = 0;
    *(undefined4 *)(puVar1 + 4) = 0xffffffff;
    puVar1[1] = 0;
    puVar1 = puVar1 + 0x10;
  }
  return;
}



/* ===== FUN_08006c14 @ 0x8006C14 ===== */

void FUN_08006c14(void)

{
  uint *puVar1;
  char *pcVar2;
  byte bVar3;
  
  puVar1 = DAT_08006c78;
  *DAT_08006c78 = *DAT_08006c78 + 1;
  if (DAT_08006c80 <= *puVar1) {
    pcVar2 = DAT_08006c7c;
    for (bVar3 = 0; bVar3 < 6; bVar3 = bVar3 + 1) {
      if (*(int *)(pcVar2 + 4) != -1) {
        *(uint *)(pcVar2 + 4) = *(int *)(pcVar2 + 4) - DAT_08006c80;
      }
      pcVar2 = pcVar2 + 0x10;
    }
    *DAT_08006c78 = *DAT_08006c78 - DAT_08006c80;
  }
  pcVar2 = DAT_08006c7c;
  for (bVar3 = 0; bVar3 < 6; bVar3 = bVar3 + 1) {
    if ((*pcVar2 == '\x01') && (*(uint *)(pcVar2 + 4) <= *DAT_08006c78)) {
      pcVar2[1] = '\x01';
    }
    pcVar2 = pcVar2 + 0x10;
  }
  return;
}



/* ===== FUN_08006c84 @ 0x8006C84 ===== */

void FUN_08006c84(int param_1,int param_2)

{
  undefined1 *puVar1;
  
  if (param_1 < 6) {
    puVar1 = (undefined1 *)(DAT_08006cb4 + param_1 * 0x10);
    FUN_08004d1c();
    *(int *)(puVar1 + 4) = *DAT_08006cb8 + param_2;
    *puVar1 = 1;
    if (param_2 == 0) {
      puVar1[1] = 1;
    }
    else {
      puVar1[1] = 0;
    }
    FUN_08004d34();
  }
  return;
}



/* ===== FUN_08006cbc @ 0x8006CBC ===== */

void FUN_08006cbc(void)

{
  byte bVar1;
  char *pcVar2;
  code *pcVar3;
  undefined4 uVar4;
  
  pcVar2 = DAT_08006d38;
  *DAT_08006d3c = *DAT_08006d3c + 1;
  FUN_08004d1c();
  bVar1 = 0;
  while( true ) {
    if (5 < bVar1) {
      FUN_08004d34();
      return;
    }
    if ((pcVar2[1] == '\x01') && (*pcVar2 == '\x01')) break;
    pcVar2 = pcVar2 + 0x10;
    bVar1 = bVar1 + 1;
  }
  if (*DAT_08006d44 < (uint)(*DAT_08006d40 - *(int *)(pcVar2 + 4))) {
    *DAT_08006d44 = *DAT_08006d40 - *(int *)(pcVar2 + 4);
  }
  pcVar3 = *(code **)(pcVar2 + 8);
  uVar4 = *(undefined4 *)(pcVar2 + 0xc);
  pcVar2[4] = -1;
  pcVar2[5] = -1;
  pcVar2[6] = -1;
  pcVar2[7] = -1;
  *pcVar2 = '\x02';
  pcVar2[1] = '\0';
  if (pcVar3 != (code *)0x0) {
    FUN_08004d34();
    (*pcVar3)(uVar4);
    FUN_08004d1c();
  }
  FUN_08004d34();
  return;
}



/* ===== FUN_08006d48 @ 0x8006D48 ===== */

int FUN_08006d48(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if (*DAT_08006dd4 < 10) {
    bVar1 = *DAT_08006dd4;
    *DAT_08006dd4 = *DAT_08006dd4 + 1;
    *(undefined4 *)(DAT_08006dd8 + (uint)bVar1 * 4) = param_1;
    for (uVar3 = 0; uVar3 < *DAT_08006dd4; uVar3 = uVar3 + 1 & 0xff) {
      iVar2 = iVar2 + *(int *)(DAT_08006dd8 + uVar3 * 4);
    }
    iVar2 = iVar2 / (int)(uint)*DAT_08006dd4;
  }
  else {
    bVar1 = *DAT_08006ddc;
    *DAT_08006ddc = *DAT_08006ddc + 1;
    *(undefined4 *)(DAT_08006dd8 + (uint)bVar1 * 4) = param_1;
    for (uVar3 = 0; uVar3 < *DAT_08006dd4; uVar3 = uVar3 + 1 & 0xff) {
      iVar2 = iVar2 + *(int *)(DAT_08006dd8 + uVar3 * 4);
    }
    iVar2 = iVar2 / (int)(uint)*DAT_08006dd4;
    if (*DAT_08006ddc == *DAT_08006dd4) {
      *DAT_08006ddc = 0;
    }
  }
  return iVar2;
}



/* ===== FUN_08006de0 @ 0x8006DE0 ===== */

void FUN_08006de0(void)

{
  bool bVar1;
  undefined4 local_10;
  
  FUN_08003bdc(0x93);
  FUN_08003bdc(0x94);
  local_10 = 500;
  do {
    bVar1 = local_10 != 0;
    local_10 = local_10 + -1;
  } while (bVar1);
  return;
}



/* ===== FUN_08006e08 @ 0x8006E08 ===== */

void FUN_08006e08(void)

{
  bool bVar1;
  undefined4 local_10;
  
  FUN_08003bdc(0x94);
  local_10 = 500;
  do {
    bVar1 = local_10 != 0;
    local_10 = local_10 + -1;
  } while (bVar1);
  return;
}



/* ===== irq_15_Handler @ 0x8006E28 ===== */

void irq_15_Handler(void)

{
  FUN_08007000();
  return;
}



/* ===== irq_17_Handler @ 0x8006E30 ===== */

void irq_17_Handler(void)

{
  FUN_08006fc0();
  return;
}



/* ===== FUN_08006e38 @ 0x8006E38 ===== */

void FUN_08006e38(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 4) = param_1;
  return;
}



/* ===== FUN_08006e3c @ 0x8006E3C ===== */

void FUN_08006e3c(uint *param_1,uint param_2,int param_3)

{
  if (param_3 == 0) {
    *param_1 = *param_1 & ~param_2;
  }
  else {
    *param_1 = *param_1 | param_2;
  }
  return;
}



/* ===== FUN_08006e50 @ 0x8006E50 ===== */

void FUN_08006e50(uint *param_1)

{
  *param_1 = *param_1 & 0xfffe;
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  if (param_1 == DAT_08006f34) {
    DAT_08006f34[-1] = DAT_08006f34[-1] | 0xf;
  }
  else if (param_1 == DAT_08006f34 + 5) {
    DAT_08006f34[-1] = DAT_08006f34[-1] | 0xf0;
  }
  else if (param_1 == DAT_08006f34 + 10) {
    DAT_08006f34[-1] = DAT_08006f34[-1] | 0xf00;
  }
  else if (param_1 == DAT_08006f34 + 0xf) {
    DAT_08006f34[-1] = DAT_08006f34[-1] | 0xf000;
  }
  else if (param_1 == DAT_08006f34 + 0x14) {
    DAT_08006f34[-1] = DAT_08006f34[-1] | 0xf0000;
  }
  else if (param_1 == DAT_08006f34 + 0x19) {
    DAT_08006f34[-1] = DAT_08006f34[-1] | 0xf00000;
  }
  else if (param_1 == DAT_08006f34 + 0x1e) {
    DAT_08006f34[-1] = DAT_08006f34[-1] | 0xf000000;
  }
  else if (param_1 == DAT_08006f34 + 0x23) {
    DAT_08006f34[-1] = DAT_08006f34[-1] | 0xf0000000;
  }
  return;
}



/* ===== FUN_08006f38 @ 0x8006F38 ===== */

void FUN_08006f38(uint *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = *param_1 & 0xfffe;
  }
  else {
    *param_1 = *param_1 | 1;
  }
  return;
}



/* ===== FUN_08006f50 @ 0x8006F50 ===== */

uint FUN_08006f50(int param_1)

{
  return *(uint *)(param_1 + 4) & 0xffff;
}



/* ===== FUN_08006f58 @ 0x8006F58 ===== */

bool FUN_08006f58(uint param_1,uint *param_2)

{
  return (*param_2 & param_1) != 0;
}



/* ===== FUN_08006f70 @ 0x8006F70 ===== */

void FUN_08006f70(uint *param_1,uint *param_2)

{
  *param_1 = *param_1 & 0xffff800f |
             param_2[2] | param_2[8] | param_2[4] | param_2[5] | param_2[6] | param_2[7] |
             param_2[9] | param_2[10];
  param_1[1] = param_2[3];
  param_1[2] = *param_2;
  param_1[3] = param_2[1];
  return;
}



/* ===== FUN_08006fac @ 0x8006FAC ===== */

void FUN_08006fac(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  if (param_4 == 0) {
    *(undefined4 *)(param_3 + 0x10) = 0;
  }
  else {
    *(undefined4 *)(param_3 + 0x10) = param_1;
  }
  return;
}



/* ===== FUN_08006fba @ 0x8006FBA ===== */

void FUN_08006fba(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}



/* ===== FUN_08006fc0 @ 0x8006FC0 ===== */

void FUN_08006fc0(void)

{
  int iVar1;
  
  iVar1 = FUN_08006f58(DAT_08006ff4 << 8);
  if (iVar1 != 0) {
    FUN_08006e38(DAT_08006ff4 << 8);
    *DAT_08006ff8 = *DAT_08006ff8 & ~(byte)(1 << DAT_08006ff8[1]);
    *DAT_08006ffc = *DAT_08006ffc & 0xfe;
  }
  return;
}



/* ===== FUN_08007000 @ 0x8007000 ===== */

void FUN_08007000(void)

{
  int iVar1;
  
  iVar1 = FUN_08006f58(0x20000,DAT_08007038);
  if (iVar1 != 0) {
    FUN_08006e38(0x20000,DAT_08007038);
    *DAT_0800703c = *DAT_0800703c & ~(byte)(1 << DAT_0800703c[1]);
    *DAT_08007040 = *DAT_08007040 & 0xfb;
  }
  return;
}



/* ===== FUN_08007044 @ 0x8007044 ===== */

uint FUN_08007044(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  for (uVar1 = param_2; (int)uVar1 < (int)(param_2 + param_3); uVar1 = uVar1 + 1 & 0xff) {
    uVar2 = uVar2 + *(ushort *)(param_1 + uVar1 * 2);
  }
  return uVar2 / param_3 & 0xffff;
}



/* ===== FUN_0800706a @ 0x800706A ===== */

int FUN_0800706a(int param_1,int param_2)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  for (iVar4 = 0; iVar4 < param_2; iVar4 = (int)(char)((char)iVar4 + '\x01')) {
    cVar2 = (char)param_2 - (char)iVar4;
    while( true ) {
      cVar2 = cVar2 + -1;
      iVar3 = (int)cVar2;
      if (iVar3 < 0) break;
      if (*(ushort *)(param_1 + (iVar3 + 1) * 2) < *(ushort *)(param_1 + iVar3 * 2)) {
        uVar1 = *(undefined2 *)(param_1 + (iVar3 + 1) * 2);
        *(undefined2 *)(param_1 + (iVar3 + 1) * 2) = *(undefined2 *)(param_1 + iVar3 * 2);
        *(undefined2 *)(param_1 + iVar3 * 2) = uVar1;
      }
    }
  }
  return iVar3;
}



/* ===== FUN_080070b0 @ 0x80070B0 ===== */

void FUN_080070b0(char *param_1,int param_2,undefined1 *param_3)

{
  uint uVar1;
  char cVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar4 = 0;
  cVar2 = *param_1;
  cVar3 = *param_1;
  uVar6 = 1;
  uVar5 = 1;
  for (uVar1 = 0; (int)uVar1 < param_2; uVar1 = uVar1 + 1 & 0xff) {
    if (cVar2 < param_1[uVar1]) {
      cVar2 = *(char *)(DAT_08007130 + uVar1);
      uVar6 = uVar1 + 1 & 0xff;
    }
    if (param_1[uVar1] < cVar3) {
      cVar3 = *(char *)(DAT_08007130 + uVar1);
      uVar5 = uVar1 + 1 & 0xff;
    }
    iVar4 = (int)(short)((short)*(char *)(DAT_08007130 + uVar1) + (short)iVar4);
  }
  *param_3 = (char)(iVar4 / param_2);
  param_3[1] = cVar3;
  param_3[2] = cVar2;
  param_3[3] = (char)uVar5;
  param_3[4] = (char)uVar6;
  return;
}



/* ===== FUN_08007134 @ 0x8007134 ===== */

void FUN_08007134(ushort *param_1,uint param_2,uint *param_3)

{
  uint uVar1;
  ushort uVar2;
  ushort uVar3;
  uint uVar4;
  uint uVar5;
  short local_48 [16];
  uint local_28;
  
  uVar4 = 0;
  FUN_080031a4(local_48,param_1,param_2 << 1);
  for (uVar1 = 0; (int)uVar1 < (int)param_2; uVar1 = uVar1 + 1 & 0xff) {
    if (local_48[uVar1] < 1) {
      param_1[uVar1] = 300;
    }
  }
  uVar2 = *param_1;
  uVar3 = *param_1;
  uVar5 = 1;
  local_28 = 1;
  for (uVar1 = 0; (int)uVar1 < (int)param_2; uVar1 = uVar1 + 1 & 0xff) {
    if (uVar2 < param_1[uVar1]) {
      uVar2 = param_1[uVar1];
      uVar5 = uVar1 + 1 & 0xff;
    }
    if (param_1[uVar1] < uVar3) {
      uVar3 = param_1[uVar1];
      local_28 = uVar1 + 1 & 0xff;
    }
    uVar4 = uVar4 + param_1[uVar1];
  }
  *param_3 = uVar4;
  *(short *)(param_3 + 1) = (short)(uVar4 / param_2);
  *(ushort *)((int)param_3 + 6) = uVar3;
  *(ushort *)(param_3 + 2) = uVar2;
  *(char *)((int)param_3 + 10) = (char)local_28;
  *(char *)((int)param_3 + 0xb) = (char)uVar5;
  return;
}



/* ===== debug_monitor_Handler @ 0x80071D6 ===== */

void debug_monitor_Handler(void)

{
  return;
}



/* ===== FUN_080071d8 @ 0x80071D8 ===== */

void FUN_080071d8(void)

{
  undefined4 *puVar1;
  uint uVar2;
  
  FUN_080031d6(DAT_08007244,0x25);
  FUN_080031d6(DAT_08007248,0x26);
  puVar1 = DAT_0800724c;
  *DAT_0800724c = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1 = DAT_08007250;
  *DAT_08007250 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  FUN_080031d6(DAT_08007254,0x54);
  FUN_080031d6(DAT_08007258,0x1d);
  for (uVar2 = 0; uVar2 < 0xd; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined2 *)(DAT_0800725c + uVar2 * 2) = 0xe10;
  }
  for (uVar2 = 0; uVar2 < 2; uVar2 = uVar2 + 1 & 0xff) {
    *(undefined1 *)(DAT_08007260 + uVar2) = 0x19;
  }
  FUN_0800baa4();
  *(undefined4 *)(DAT_08007264 + 4) = 10000;
  return;
}



/* ===== thunk_FUN_0800726e @ 0x8007268 ===== */

void thunk_FUN_0800726e(uint param_1)

{
  for (; 0 < (int)param_1; param_1 = param_1 - 1 & 0xffff) {
  }
  return;
}



/* ===== FUN_0800726e @ 0x800726E ===== */

void FUN_0800726e(uint param_1)

{
  for (; 0 < (int)param_1; param_1 = param_1 - 1 & 0xffff) {
  }
  return;
}



/* ===== FUN_08007274 @ 0x8007274 ===== */

void FUN_08007274(void)

{
  int iVar1;
  int in_r3;
  bool bVar2;
  
  if (*DAT_08007324 == '\x01') {
    if ((*(byte *)(DAT_08007328 + 1) & 1) == 0) {
      iVar1 = FUN_0800b438();
      if (iVar1 == 0) {
        FUN_0800df58(DAT_0800732c,0,1);
        iVar1 = 500;
        do {
          in_r3 = iVar1 + -1;
          bVar2 = iVar1 != 0;
          iVar1 = in_r3;
        } while (bVar2);
      }
      FUN_08003c60(8,0x7f,DAT_0800732c,1,in_r3);
      *(byte *)(DAT_08007328 + 1) = *(byte *)(DAT_08007328 + 1) & 0xfe | *DAT_0800732c >> 2 & 1;
    }
  }
  else if ((*(byte *)(DAT_08007328 + 1) & 1) != 0) {
    FUN_08003bdc(0x93);
    iVar1 = 500;
    do {
      bVar2 = iVar1 != 0;
      iVar1 = iVar1 + -1;
    } while (bVar2);
    FUN_08003c60(8,0x7f,DAT_0800732c,1);
    *(byte *)(DAT_08007328 + 1) = *(byte *)(DAT_08007328 + 1) & 0xfe | *DAT_0800732c >> 2 & 1;
  }
  return;
}



/* ===== FUN_08007330 @ 0x8007330 ===== */

void FUN_08007330(void)

{
  byte bVar1;
  int iVar2;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 local_28;
  undefined2 local_26;
  ushort local_24;
  undefined2 local_22;
  
  bVar1 = 0;
  FUN_080031d6(&local_38,0x30);
  if (*DAT_080073ec == 1) {
    while ((bVar1 < 3 && (iVar2 = FUN_0800cb0c(&local_38), iVar2 != 1))) {
      bVar1 = bVar1 + 1;
    }
    local_30 = *(undefined4 *)(DAT_080073f0 + 4);
    local_2c = *(undefined4 *)(DAT_080073f0 + 4);
    local_28 = 0;
    local_26 = *(undefined2 *)(DAT_080073f0 + 0x10);
    local_24 = (ushort)*(byte *)(DAT_080073f4 + 0x43);
    local_38 = *(undefined4 *)(DAT_080073f4 + 0x17);
    local_34 = *(undefined4 *)(DAT_080073f4 + 0x1b);
    local_22 = FUN_0800aa50(&local_38,0x16);
    for (bVar1 = 0; bVar1 < 3; bVar1 = bVar1 + 1) {
      FUN_080031a4(auStack_58,&local_28,0x20);
      iVar2 = FUN_0800cccc(local_38,local_34,local_30,local_2c);
      if ((iVar2 != 0) && (iVar2 = FUN_0800cb0c(&local_38), iVar2 != 0)) {
        *DAT_080073f8 = 1;
        FUN_08012f30(local_30);
        FUN_08012f24(local_26);
        *DAT_080073ec = 0;
        return;
      }
    }
  }
  return;
}



/* ===== FUN_080075c8 @ 0x80075C8 ===== */

void FUN_080075c8(void)

{
  int iVar1;
  
  if (*DAT_080076a4 == '\x01') {
    *DAT_080076a4 = '\0';
    iVar1 = DAT_080076a8;
    *(undefined4 *)(DAT_080076a8 + 4) = 0;
    *(undefined2 *)(iVar1 + 0x10) = 1000;
    *DAT_080076ac = 1;
    FUN_0800f534();
    *(byte *)(DAT_080076b0 + 2) = *(byte *)(DAT_080076b0 + 2) & 0xfd;
    FUN_080176ac();
    FUN_08016368();
    *(undefined2 *)(DAT_080076b4 + 0x15) = 0;
    *DAT_080076b8 = *DAT_080076b8 | 0x400;
    *(undefined4 *)(DAT_080076b0 + 9) = 0;
    *DAT_080076b8 = *DAT_080076b8 | 0x2000;
    *(undefined4 *)(DAT_080076b0 + 0xd) = 0;
    *DAT_080076b8 = *DAT_080076b8 | 0x4000;
    *(undefined4 *)(DAT_080076b0 + 0x11) = 0x78;
    *DAT_080076b8 = *DAT_080076b8 | 0x8000;
    *(undefined4 *)(DAT_080076b0 + 0x15) = 0;
    *DAT_080076b8 = *DAT_080076b8 | 0x10000;
    *(undefined4 *)(DAT_080076b0 + 0x1f) = 0;
    *DAT_080076b8 = *DAT_080076b8 | 0x20000;
    if (*(ushort *)(DAT_080076b0 + 0x23) < 60000) {
      *(short *)(DAT_080076b0 + 0x23) = *(short *)(DAT_080076b0 + 0x23) + 1;
    }
    *DAT_080076b8 = *DAT_080076b8 | 0x40000;
  }
  return;
}



/* ===== FUN_080076bc @ 0x80076BC ===== */

void FUN_080076bc(char *param_1,undefined1 *param_2,char *param_3)

{
  undefined1 uVar1;
  uint uVar2;
  
  *param_2 = 0x74;
  param_2[1] = param_1[2];
  if (*param_1 == '\x10') {
    if (param_1[2] == -0x7f) {
      param_2[2] = 0x1b;
      param_2[3] = *DAT_0800776c;
      param_2[4] = DAT_0800776c[1];
      FUN_080031a4(param_2 + 5,DAT_08007770,0x19);
      uVar2 = 0x1e;
    }
    else {
      param_2[2] = 0x4f;
      uVar2 = 4;
      param_2[3] = 0x4b;
    }
  }
  else {
    param_2[2] = param_1[4];
    FUN_080031a4(param_2 + 3,param_1 + 5,param_1[4]);
    uVar2 = (byte)param_1[4] + 3 & 0xff;
  }
  uVar1 = FUN_08003e34(param_2,uVar2);
  param_2[uVar2] = uVar1;
  param_2[uVar2 + 1 & 0xff] = 0x8b;
  *param_3 = (char)(uVar2 + 1) + '\x01';
  return;
}



/* ===== FUN_0800783c @ 0x800783C ===== */

int FUN_0800783c(uint param_1,undefined1 *param_2)

{
  uint uVar1;
  
  *param_2 = 0;
  uVar1 = 0;
  while( true ) {
    if (0x10 < uVar1) {
      return 0;
    }
    if (*(byte *)(DAT_08007870 + uVar1 * 8 + 4) == param_1) break;
    uVar1 = uVar1 + 1 & 0xffff;
  }
  *param_2 = 1;
  return DAT_08007870 + uVar1 * 8;
}



/* ===== irq_06_Handler @ 0x8007874 ===== */

void irq_06_Handler(void)

{
  int iVar1;
  
  iVar1 = FUN_0800797c(1);
  if (iVar1 != 0) {
    FUN_08007970(1);
  }
  return;
}



/* ===== irq_40_Handler @ 0x8007888 ===== */

void irq_40_Handler(void)

{
  int iVar1;
  
  iVar1 = FUN_0800797c(0x800);
  if ((iVar1 != 0) && (*DAT_080078ac == '\0')) {
    *DAT_080078ac = '\x01';
  }
  FUN_08007970(0x800);
  return;
}



/* ===== FUN_080078b0 @ 0x80078B0 ===== */

void FUN_080078b0(undefined1 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  local_18 = param_2;
  local_14 = param_3;
  local_10 = param_4;
  FUN_08007970(0x100000);
  local_14 = 0x100000;
  local_10 = CONCAT13((char)((uint)local_10 >> 0x18),0x10800);
  FUN_080079a4(&local_14);
  local_18 = CONCAT13(param_1,3);
  FUN_0800e0b4(&local_18);
  return;
}



/* ===== irq_10_Handler @ 0x80078F6 ===== */

void irq_10_Handler(void)

{
  int iVar1;
  
  iVar1 = FUN_0800797c(0x10);
  if (iVar1 != 0) {
    FUN_08007970(0x10);
  }
  return;
}



/* ===== irq_23_Handler @ 0x8007908 ===== */

void irq_23_Handler(void)

{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = FUN_0800797c(0x80);
  pbVar1 = DAT_08007964;
  if (iVar2 != 0) {
    *DAT_08007964 = *DAT_08007964 + 1;
    if (9 < *pbVar1) {
      *pbVar1 = 10;
      FUN_080052f4();
    }
  }
  iVar2 = FUN_0800797c(0x100);
  if (iVar2 != 0) {
    *DAT_08007968 = 1;
  }
  iVar2 = FUN_0800797c(0x200);
  if (iVar2 != 0) {
    *DAT_0800796c = 1;
  }
  FUN_08007970(0x80);
  FUN_08007970(0x100);
  FUN_08007970(0x200);
  return;
}



/* ===== FUN_08007970 @ 0x8007970 ===== */

void FUN_08007970(undefined4 param_1)

{
  *DAT_08007978 = param_1;
  return;
}



/* ===== FUN_0800797c @ 0x800797C ===== */

undefined4 FUN_0800797c(uint param_1)

{
  undefined4 uVar1;
  
  if (((DAT_080079a0[5] & param_1) == 0) || ((*DAT_080079a0 & param_1) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* ===== FUN_080079a4 @ 0x80079A4 ===== */

void FUN_080079a4(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  
  puVar2 = DAT_08007a34;
  if (*(char *)((int)param_1 + 6) == '\0') {
    puVar2 = (uint *)((int)DAT_08007a34 + (uint)(byte)param_1[1]);
    *puVar2 = *puVar2 & ~*param_1;
  }
  else {
    *DAT_08007a34 = *DAT_08007a34 & ~*param_1;
    puVar2[1] = puVar2[1] & ~*param_1;
    puVar2 = (uint *)((int)puVar2 + (uint)(byte)param_1[1]);
    *puVar2 = *puVar2 | *param_1;
    puVar2 = DAT_08007a34;
    DAT_08007a34[2] = DAT_08007a34[2] & ~*param_1;
    puVar1 = DAT_08007a34;
    DAT_08007a34[3] = puVar2[3] & ~*param_1;
    puVar2 = DAT_08007a34;
    if (*(char *)((int)param_1 + 5) == '\x10') {
      DAT_08007a34[2] = puVar1[2] | *param_1;
      DAT_08007a34[3] = puVar2[3] | *param_1;
    }
    else {
      puVar2 = (uint *)((int)DAT_08007a34 + (uint)*(byte *)((int)param_1 + 5));
      *puVar2 = *puVar2 | *param_1;
    }
  }
  return;
}



/* ===== FUN_08007a38 @ 0x8007A38 ===== */

void FUN_08007a38(void)

{
  FUN_08017588(DAT_08007a5c,*DAT_08007a58,100);
  FUN_08007134(DAT_08007a64,0xd,DAT_08007a60);
  FUN_080129c4();
  return;
}



/* ===== FUN_08007a68 @ 0x8007A68 ===== */

undefined4 FUN_08007a68(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  
  if (param_4 == param_3 * (param_4 / param_3)) {
    if (param_3 == 1) {
      FUN_080031a4(param_1,param_2,param_4);
      uVar1 = 1;
    }
    else if (param_3 == 2) {
      for (uVar2 = 0; (int)uVar2 < param_4; uVar2 = uVar2 + 2 & 0xff) {
        *(undefined1 *)(param_1 + uVar2) = *(undefined1 *)(param_2 + uVar2 + 1);
        *(undefined1 *)(param_1 + uVar2 + 1) = *(undefined1 *)(param_2 + uVar2);
      }
      uVar1 = 1;
    }
    else if (param_3 == 4) {
      for (uVar2 = 0; (int)uVar2 < param_4; uVar2 = uVar2 + 4 & 0xff) {
        *(undefined1 *)(param_1 + uVar2) = *(undefined1 *)(param_2 + uVar2 + 3);
        *(undefined1 *)(param_1 + uVar2 + 1) = *(undefined1 *)(param_2 + uVar2 + 2);
        *(undefined1 *)(param_1 + uVar2 + 2) = *(undefined1 *)(param_2 + uVar2 + 1);
        *(undefined1 *)(param_1 + uVar2 + 3) = *(undefined1 *)(param_2 + uVar2);
      }
      uVar1 = 1;
    }
    else if (param_3 == 8) {
      for (uVar2 = 0; (int)uVar2 < param_4; uVar2 = uVar2 + 8 & 0xff) {
        *(undefined1 *)(param_1 + uVar2) = *(undefined1 *)(param_2 + uVar2 + 7);
        *(undefined1 *)(param_1 + uVar2 + 1) = *(undefined1 *)(param_2 + uVar2 + 6);
        *(undefined1 *)(param_1 + uVar2 + 2) = *(undefined1 *)(param_2 + uVar2 + 5);
        *(undefined1 *)(param_1 + uVar2 + 3) = *(undefined1 *)(param_2 + uVar2 + 4);
        *(undefined1 *)(param_1 + uVar2 + 4) = *(undefined1 *)(param_2 + uVar2 + 3);
        *(undefined1 *)(param_1 + uVar2 + 5) = *(undefined1 *)(param_2 + uVar2 + 2);
        *(undefined1 *)(param_1 + uVar2 + 6) = *(undefined1 *)(param_2 + uVar2 + 1);
        *(undefined1 *)(param_1 + uVar2 + 7) = *(undefined1 *)(param_2 + uVar2);
      }
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* ===== FUN_08007b5a @ 0x8007B5A ===== */

undefined4 FUN_08007b5a(void)

{
  undefined4 uVar1;
  bool bVar2;
  undefined4 local_10;
  
  local_10 = 10000;
  do {
    bVar2 = local_10 != 0;
    local_10 = local_10 + -1;
  } while (bVar2);
  uVar1 = FUN_08003c1c(0x90);
  local_10 = 10000;
  do {
    bVar2 = local_10 != 0;
    local_10 = local_10 + -1;
  } while (bVar2);
  return uVar1;
}



/* ===== FUN_08007b8c @ 0x8007B8C ===== */

void FUN_08007b8c(void)

{
  FUN_08006de0();
  return;
}



/* ===== FUN_08007b98 @ 0x8007B98 ===== */

void FUN_08007b98(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_08007bb8;
  *DAT_08007bb8 = 0xaaaa;
  *DAT_08007bbc = (int)puVar1 >> 0xf;
  *DAT_08007bc0 = 4;
  FUN_0800e20c(3);
  return;
}



/* ===== FUN_08007bc4 @ 0x8007BC4 ===== */

void FUN_08007bc4(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    FUN_080069b8(2);
    FUN_0800532c(DAT_08007c90,0x10);
    iVar1 = FUN_0800a7c8(DAT_08007c94,0x4000);
    if (iVar1 != 0) {
      *(byte *)(DAT_08007c98 + 1) = *(byte *)(DAT_08007c98 + 1) & 0xfb;
      *(undefined4 *)(DAT_08007c94 + 0x28) = 0x4000;
    }
  }
  else if (param_1 == 1) {
    FUN_080069b8(2);
    FUN_0800532c(DAT_08007c90,0x10);
    iVar1 = FUN_0800a7c8(DAT_08007c94,0x4000);
    if (iVar1 != 0) {
      *(byte *)(DAT_08007c98 + 1) = *(byte *)(DAT_08007c98 + 1) & 0xfb;
      *(undefined4 *)(DAT_08007c94 + 0x28) = 0x4000;
    }
  }
  else if ((param_1 != 2) && (param_1 == 3)) {
    FUN_080069b8(1);
    FUN_0800532c(DAT_08007c90,0x10);
    iVar1 = FUN_0800a7c8(DAT_08007c94,0x4000);
    if (iVar1 != 0) {
      *(byte *)(DAT_08007c98 + 1) = *(byte *)(DAT_08007c98 + 1) & 0xfb;
      *(undefined4 *)(DAT_08007c94 + 0x28) = 0x4000;
    }
  }
  return;
}



/* ===== FUN_08007c9c @ 0x8007C9C ===== */

void FUN_08007c9c(void)

{
  *DAT_08007cb8 = 0xaaaa;
  FUN_0800532c(DAT_08007cbc,2);
  FUN_0800e20c(1);
  return;
}



/* ===== FUN_08007cc0 @ 0x8007CC0 ===== */

void FUN_08007cc0(void)

{
  *DAT_08007ccc = 0xaaaa;
  return;
}



/* ===== FUN_08007cd0 @ 0x8007CD0 ===== */

void FUN_08007cd0(int param_1)

{
  ushort uVar1;
  bool bVar2;
  undefined1 auStack_30 [32];
  int local_10;
  
  uVar1 = 0;
  FUN_0800e94c(param_1);
  FUN_080031a4(auStack_30,DAT_08007d94,0x24);
  FUN_0800ce98(*(undefined4 *)(DAT_08007d94 + -0x10),*(undefined4 *)(DAT_08007d94 + -0xc),
               *(undefined4 *)(DAT_08007d94 + -8),*(undefined4 *)(DAT_08007d94 + -4));
  *DAT_08007d98 = (char)param_1;
  *DAT_08007d9c = *DAT_08007d9c + param_1;
  *DAT_08007da0 = 0xaaaa;
  while( true ) {
    FUN_080055ec();
    uVar1 = uVar1 + 1;
    if (60000 < uVar1) break;
    FUN_0800e2a8(1,0x1000);
    local_10 = 0xa0;
    do {
      bVar2 = local_10 != 0;
      local_10 = local_10 + -1;
    } while (bVar2);
    local_10 = 0xffffffff;
    if ((((*DAT_08007da4 == '\x01') || (*DAT_08007da4 == '\x02')) || (*DAT_08007da8 != '\0')) ||
       ((*DAT_08007dac != '\0' || (*DAT_08007db0 != '\0')))) break;
  }
  *DAT_08007da0 = 0xaaaa;
  FUN_080050e0();
  FUN_0800532c(DAT_08007db4,1);
  FUN_0800532c(DAT_08007db8,1);
  FUN_0800cf94(DAT_08007d94 + -0x10);
  FUN_08005600();
  return;
}



/* ===== FUN_08007dbc @ 0x8007DBC ===== */

void FUN_08007dbc(void)

{
  *DAT_08007dd4 = 0xaaaa;
  FUN_08004d5c();
  FUN_0800e20c(4);
  return;
}



/* ===== FUN_08007dd8 @ 0x8007DD8 ===== */

void FUN_08007dd8(int param_1,int param_2,char *param_3,undefined1 *param_4,int *param_5)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  
  bVar2 = false;
  bVar3 = false;
  if (param_2 == 3) {
    cVar1 = *(char *)*param_5;
    if (cVar1 == '\0') {
      bVar2 = true;
    }
    else if ((cVar1 != '\x01') && (cVar1 == '\x02')) {
      bVar2 = true;
    }
  }
  else if (param_2 == 6) {
    cVar1 = *(char *)*param_5;
    if (cVar1 != '\0') {
      if (cVar1 == '\x01') {
        bVar3 = true;
      }
      else if (cVar1 == '\x02') {
        bVar3 = true;
      }
    }
  }
  else if ((param_2 == 0x10) && (cVar1 = *(char *)*param_5, cVar1 != '\0')) {
    if (cVar1 == '\x01') {
      bVar3 = true;
    }
    else if (cVar1 == '\x02') {
      bVar3 = true;
    }
  }
  if (bVar2) {
    if (*(int *)(*param_5 + 0x10) != 0) {
      (**(code **)(*param_5 + 0x10))();
    }
    *param_4 = 0;
    if (*param_3 != '\0') {
      if (param_1 == 1) {
        FUN_08007a68(param_4,*(undefined4 *)(*param_5 + 4),*(undefined1 *)(*param_5 + 1),*param_3);
      }
      else {
        FUN_080031a4(param_4,*(undefined4 *)(*param_5 + 4),*param_3);
      }
    }
  }
  if (bVar3) {
    if (*param_3 != '\0') {
      if (param_1 == 1) {
        FUN_08007a68(*(undefined4 *)(*param_5 + 4),param_4,*(undefined1 *)(*param_5 + 1),*param_3);
      }
      else {
        FUN_080031a4(*(undefined4 *)(*param_5 + 4),param_4,*param_3);
      }
    }
    if (*(int *)(*param_5 + 0xc) != 0) {
      (**(code **)(*param_5 + 0xc))();
    }
    *param_3 = '\0';
  }
  return;
}



/* ===== FUN_08007ee0 @ 0x8007EE0 ===== */

undefined8 FUN_08007ee0(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  bool bVar4;
  int local_18;
  uint local_14 [2];
  
  local_14[0] = 0;
  local_14[1] = 0;
  iVar3 = 0;
  FUN_08003bdc(0x90);
  local_18 = 30000;
  do {
    bVar4 = local_18 != 0;
    local_18 = local_18 + -1;
  } while (bVar4);
  iVar1 = FUN_08003bdc(0xa1);
  if (iVar1 != 0) {
    local_18 = 1000;
    do {
      bVar4 = local_18 != 0;
      local_18 = local_18 + -1;
    } while (bVar4);
    iVar3 = FUN_08003c60(8,0x3e,local_14,5);
    local_18 = 1000;
    do {
      bVar4 = local_18 != 0;
      local_18 = local_18 + -1;
    } while (bVar4);
  }
  if (iVar3 == 0) {
    FUN_08003bdc(0x92);
    local_18 = 10000;
    do {
      bVar4 = local_18 != 0;
      local_18 = local_18 + -1;
    } while (bVar4);
    uVar2 = 1;
  }
  else if ((local_14[0] & 0x800000) == 0) {
    FUN_08003bdc(0x92);
    local_18 = 10000;
    do {
      bVar4 = local_18 != 0;
      local_18 = local_18 + -1;
    } while (bVar4);
    uVar2 = 1;
  }
  else {
    FUN_08003bdc(0x92);
    local_18 = 10000;
    do {
      bVar4 = local_18 != 0;
      local_18 = local_18 + -1;
    } while (bVar4);
    *DAT_08007fb0 = 1;
    uVar2 = 0;
  }
  return CONCAT44(0xffffffff,uVar2);
}



/* ===== FUN_08007fb4 @ 0x8007FB4 ===== */

undefined4 FUN_08007fb4(void)

{
  undefined4 uVar1;
  bool bVar2;
  undefined4 local_10;
  
  uVar1 = FUN_08003c1c(0x92);
  local_10 = 10000;
  do {
    bVar2 = local_10 != 0;
    local_10 = local_10 + -1;
  } while (bVar2);
  return uVar1;
}



/* ===== FUN_08007fd4 @ 0x8007FD4 ===== */

void FUN_08007fd4(void)

{
  if (((*DAT_08008064 == '\x01') && (*DAT_08008068 == '\0')) &&
     (((',' < *(char *)(DAT_0800806c + 2) && (*(char *)(DAT_0800806c + 2) < 'd')) ||
      ((*(char *)(DAT_0800806c + 1) < '\x02' && (-0x1e < *(char *)(DAT_0800806c + 1))))))) {
    *DAT_08008070 = *DAT_08008070 + 1;
    *(int *)(DAT_08008074 + 0x15) = *(int *)(DAT_08008074 + 0x15) + 1;
    if (600 < *DAT_08008070) {
      *DAT_08008070 = *DAT_08008070 % 600;
      *DAT_08008078 = *DAT_08008078 | 0x10000;
    }
  }
  if (DAT_0800807c < *(uint *)(DAT_08008074 + 0x15)) {
    *(uint *)(DAT_08008074 + 0x15) = DAT_0800807c;
  }
  return;
}



/* ===== FUN_08008080 @ 0x8008080 ===== */

undefined8 FUN_08008080(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  ushort *puVar2;
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 local_c;
  
  if (((*DAT_080081b8 == '\x01') &&
      ((('@' < *(char *)(DAT_080081bc + 2) && (*(char *)(DAT_080081bc + 2) < 'd')) ||
       ((*(char *)(DAT_080081bc + 1) < -0x13 && (-0x1e < *(char *)(DAT_080081bc + 1))))))) ||
     ((*DAT_080081b8 == '\x02' &&
      (((';' < *(char *)(DAT_080081bc + 2) && (*(char *)(DAT_080081bc + 2) < 'd')) ||
       ((*(char *)(DAT_080081bc + 1) < -0x13 && (-0x1e < *(char *)(DAT_080081bc + 1))))))))) {
    if (*DAT_080081c0 == '\0') {
      *(int *)(DAT_080081c4 + 0x1f) = *(int *)(DAT_080081c4 + 0x1f) + 1;
      puVar2 = DAT_080081c8;
      *DAT_080081c8 = *DAT_080081c8 + 1;
      if (600 < *puVar2) {
        *puVar2 = 0;
        *DAT_080081cc = *DAT_080081cc | 0x20000;
      }
    }
    puVar2 = DAT_080081d0;
    if (*DAT_080081c0 == '\x01') {
      *DAT_080081d0 = *DAT_080081d0 + 1;
      if (5 < *puVar2) {
        *(int *)(DAT_080081c4 + 0x1f) = *(int *)(DAT_080081c4 + 0x1f) + 0x2d0;
        *DAT_080081d0 = 0;
        *DAT_080081cc = *DAT_080081cc | 0x20000;
      }
    }
    else {
      *DAT_080081d0 = 0;
    }
  }
  if (0xffffffe < *(uint *)(DAT_080081c4 + 0x1f)) {
    *(undefined4 *)(DAT_080081c4 + 0x1f) = 0xfffffff;
  }
  local_18 = param_1;
  uStack_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  FUN_08013bac(&local_18,*(undefined4 *)(DAT_080081c4 + 0x1f));
  iVar1 = DAT_080081c4;
  local_10._0_1_ = (undefined1)local_18;
  *(undefined1 *)(DAT_080081c4 + 0x19) = (undefined1)local_10;
  local_10._1_1_ = (undefined1)((uint)local_18 >> 8);
  *(undefined1 *)(iVar1 + 0x1a) = local_10._1_1_;
  local_10._2_1_ = (undefined1)((uint)local_18 >> 0x10);
  *(undefined1 *)(iVar1 + 0x1b) = local_10._2_1_;
  local_10._3_1_ = (undefined1)((uint)local_18 >> 0x18);
  *(undefined1 *)(iVar1 + 0x1c) = local_10._3_1_;
  local_c._0_1_ = (undefined1)uStack_14;
  *(undefined1 *)(iVar1 + 0x1d) = (undefined1)local_c;
  local_c._1_1_ = (undefined1)((uint)uStack_14 >> 8);
  *(undefined1 *)(iVar1 + 0x1e) = local_c._1_1_;
  return CONCAT44(uStack_14,local_18);
}



/* ===== FUN_080081d4 @ 0x80081D4 ===== */

void FUN_080081d4(uint param_1)

{
  *(uint *)(DAT_080081e0 + 0xc) = *(uint *)(DAT_080081e0 + 0xc) | param_1;
  return;
}



/* ===== FUN_080081e4 @ 0x80081E4 ===== */

undefined8 FUN_080081e4(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_8;
  
  iVar2 = 0;
  local_8 = 0;
  uVar1 = 0;
  if ((*DAT_0800822c & 2) == 0) {
    *DAT_0800822c = *DAT_0800822c | 1;
    do {
      local_8 = local_8 + 1;
      if ((int)(*DAT_0800822c << 0x1e) < 0) break;
    } while (local_8 != 0x500);
    iVar2 = -((int)(*DAT_0800822c << 0x1e) >> 0x1f);
    if (iVar2 == 0) {
      uVar1 = 1;
    }
  }
  return CONCAT44(iVar2,uVar1);
}



/* ===== FUN_08008230 @ 0x8008230 ===== */

int FUN_08008230(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  FUN_080081d4(0x7c);
  iVar2 = FUN_08008390(0xb0000);
  iVar1 = DAT_08008280;
  if (iVar2 == 6) {
    *(uint *)(DAT_08008280 + 0x10) = *(uint *)(DAT_08008280 + 0x10) | 2;
    *(undefined4 *)(iVar1 + 0x14) = param_1;
    *(uint *)(iVar1 + 0x10) = *(uint *)(iVar1 + 0x10) | 0x40;
    iVar2 = FUN_08008390(0xb0000);
    *(uint *)(DAT_08008280 + 0x10) = *(uint *)(DAT_08008280 + 0x10) & 0x3ffd;
  }
  return iVar2;
}



/* ===== FUN_08008284 @ 0x8008284 ===== */

undefined4 FUN_08008284(void)

{
  undefined4 uVar1;
  
  if ((*(uint *)(DAT_080082d0 + 0xc) & 1) == 0) {
    if ((*(uint *)(DAT_080082d0 + 0xc) & 4) == 0) {
      if ((*(uint *)(DAT_080082d0 + 0xc) & 8) == 0) {
        if ((*(uint *)(DAT_080082d0 + 0xc) & 0x10) == 0) {
          if ((*(uint *)(DAT_080082d0 + 0xc) & 0x40) == 0) {
            uVar1 = 6;
          }
          else {
            uVar1 = 7;
          }
        }
        else {
          uVar1 = 5;
        }
      }
      else {
        uVar1 = 4;
      }
    }
    else {
      uVar1 = 3;
    }
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* ===== FUN_080082d4 @ 0x80082D4 ===== */

void FUN_080082d4(void)

{
  *(uint *)(DAT_080082e4 + 0x10) = *(uint *)(DAT_080082e4 + 0x10) | 0x80;
  return;
}



/* ===== FUN_080082e8 @ 0x80082E8 ===== */

void FUN_080082e8(uint param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_08008300;
  *DAT_08008300 = *DAT_08008300 & 0xffffffef;
  *puVar1 = *puVar1 | param_1;
  return;
}



/* ===== FUN_08008304 @ 0x8008304 ===== */

int FUN_08008304(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  
  if (((uint)param_1 & 3) == 0) {
    FUN_080081d4(0x7c);
    iVar1 = FUN_08008390(0x2000);
    if (iVar1 == 6) {
      *(uint *)(DAT_0800835c + 0x10) = *(uint *)(DAT_0800835c + 0x10) | 1;
      *param_1 = param_2;
      iVar1 = FUN_08008390(0x2000);
      *(uint *)(DAT_0800835c + 0x10) = *(uint *)(DAT_0800835c + 0x10) & 0x3ffe;
    }
  }
  else {
    iVar1 = 9;
  }
  return iVar1;
}



/* ===== FUN_08008360 @ 0x8008360 ===== */

void FUN_08008360(uint param_1)

{
  *DAT_08008374 = *DAT_08008374 & 0xf8 | param_1;
  return;
}



/* ===== FUN_08008378 @ 0x8008378 ===== */

void FUN_08008378(void)

{
  int iVar1;
  
  iVar1 = DAT_08008388;
  *(undefined4 *)(DAT_08008388 + 4) = DAT_08008384;
  *(undefined4 *)(iVar1 + 4) = DAT_0800838c;
  return;
}



/* ===== FUN_08008390 @ 0x8008390 ===== */

int FUN_08008390(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int extraout_r2;
  int extraout_r2_00;
  int iVar2;
  
  iVar1 = FUN_08008284(param_1,param_2,param_1,6);
  iVar2 = extraout_r2;
  while ((iVar1 == 1 && (iVar2 != 0))) {
    iVar1 = FUN_08008284();
    iVar2 = extraout_r2_00 + -1;
  }
  if (iVar2 == 0) {
    iVar1 = 10;
  }
  return iVar1;
}



/* ===== FUN_080083b8 @ 0x80083B8 ===== */

void FUN_080083b8(undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  char cVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_20;
  int local_1c;
  int local_18;
  
  local_20 = param_2;
  local_1c = param_3;
  local_18 = param_4;
  FUN_08012fa4(1);
  if (*(char *)(DAT_08008608 + 0x6d) != '\0') {
    uVar3 = FUN_08018528();
    *(undefined4 *)(DAT_08008608 + 0x18) = uVar3;
  }
  local_18 = FUN_08018528();
  local_18 = local_18 - *(int *)(DAT_08008608 + 0x18);
  iVar4 = local_18;
  if (local_18 < 0) {
    iVar4 = -local_18;
  }
  if (0x31 < iVar4) {
    local_18 = 0;
  }
  local_18 = local_18 * (uint)*(byte *)(DAT_0800860c + 0x2d);
  if (*(byte *)(DAT_08008608 + 0x70) < 0x1f) {
    *(char *)(DAT_08008608 + 0x70) = *(char *)(DAT_08008608 + 0x70) + '\x01';
  }
  iVar4 = DAT_08008608;
  if (*(char *)(DAT_08008608 + 0x6e) == '\0') {
    *(undefined1 *)(DAT_08008608 + 0x6e) = 1;
    *(undefined1 *)(iVar4 + 0x6f) = 2;
    iVar4 = FUN_08018558();
    FUN_08012e5c(iVar4 * 10);
    uVar3 = FUN_0800ad90();
    iVar4 = DAT_0800860c;
    *(undefined4 *)(DAT_0800860c + 0x18) = uVar3;
    *(undefined1 *)(iVar4 + 0x2e) = 0;
    *(undefined2 *)(iVar4 + 0x28) = 0xfffe;
  }
  else {
    cVar1 = *(char *)(DAT_08008608 + 0x6f);
    if (cVar1 == '\x01') {
      iVar5 = FUN_0800ae14();
      iVar4 = DAT_08008608;
      if (iVar5 == 0) {
        *(undefined1 *)(DAT_08008608 + 0x6f) = 3;
        *(undefined4 *)(iVar4 + 0x44) = 0;
        iVar4 = DAT_0800860c;
        *(undefined1 *)(DAT_0800860c + 0x2e) = 0;
        *(undefined2 *)(iVar4 + 0x28) = 0xfffe;
        FUN_08010a64(&local_18);
      }
    }
    else if (cVar1 == '\x02') {
      *(undefined1 *)(DAT_08008608 + 0x6f) = 3;
      *(undefined4 *)(iVar4 + 0x44) = 0;
      iVar4 = DAT_0800860c;
      *(undefined1 *)(DAT_0800860c + 0x2e) = 0;
      *(undefined2 *)(iVar4 + 0x28) = 0xfffe;
      FUN_08010a64(&local_18);
    }
    else if (cVar1 == '\x03') {
      *(undefined1 *)(DAT_0800860c + 0x2e) = 0;
      iVar5 = FUN_0800ae14();
      iVar4 = DAT_08008608;
      if (iVar5 == 1) {
        *(undefined1 *)(DAT_08008608 + 0x6f) = 1;
        *(undefined4 *)(iVar4 + 0x44) = 0;
        FUN_08012e5c(DAT_08008610);
        uVar3 = FUN_0800ad90();
        *(undefined4 *)(DAT_0800860c + 0x18) = uVar3;
      }
      else if ((*(uint *)(DAT_08008608 + 0x44) < 36000) && (uVar6 = FUN_0800aeb4(), uVar6 < 0xe10))
      {
        FUN_08010a64(&local_18);
      }
      else {
        iVar4 = DAT_08008608;
        *(undefined1 *)(DAT_08008608 + 0x6f) = 4;
        *(undefined1 *)(iVar4 + 0x70) = 0;
        *(undefined4 *)(iVar4 + 0x44) = 0;
        uVar3 = FUN_0800aecc();
        FUN_080103ec(uVar3,&local_1c);
        iVar4 = (int)(short)local_1c;
        uVar3 = FUN_0800aee8();
        FUN_080103ec(uVar3,&local_1c);
        FUN_0801036c(iVar4,(int)(short)local_1c,&local_20);
        FUN_08012e5c((short)local_20 * 10);
        uVar3 = FUN_0800ad90();
        iVar4 = DAT_0800860c;
        *(undefined4 *)(DAT_0800860c + 0x18) = uVar3;
        *(undefined1 *)(iVar4 + 0x2e) = 1;
        uVar3 = FUN_0800af58();
        FUN_0801017c((int)(short)local_20,uVar3,&local_1c);
        if ((short)local_1c < 0) {
          local_1c = 0;
        }
        *(short *)(DAT_0800860c + 0x28) = (short)local_1c;
      }
    }
    else {
      *(undefined1 *)(DAT_0800860c + 0x2e) = 1;
      iVar4 = DAT_08008608;
      if (0x13 < *(byte *)(DAT_08008608 + 0x70)) {
        *(undefined1 *)(DAT_08008608 + 0x6f) = 3;
        *(undefined4 *)(iVar4 + 0x44) = 0;
        iVar4 = DAT_0800860c;
        *(undefined1 *)(DAT_0800860c + 0x2e) = 0;
        *(undefined2 *)(iVar4 + 0x28) = 0xfffe;
        FUN_08010a64(&local_18);
      }
    }
  }
  *(undefined1 *)(DAT_08008608 + 0x6d) = 0;
  uVar3 = FUN_08018528();
  *(undefined4 *)(DAT_08008608 + 0x18) = uVar3;
  FUN_08012fa4(0);
  sVar2 = FUN_08018222(*(undefined4 *)(DAT_0800860c + 0x18),10);
  local_1c = (int)sVar2;
  if (sVar2 < 0x2711) {
    if (sVar2 < DAT_08008614) {
      FUN_08012eac(DAT_08008614);
    }
    else {
      FUN_08012eac((int)sVar2);
    }
  }
  else {
    FUN_08012eac(10000);
  }
  FUN_08012f60(*(undefined1 *)(DAT_0800860c + 0x2e));
  return;
}



/* ===== FUN_08008618 @ 0x8008618 ===== */

void FUN_08008618(void)

{
  bool bVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  
  FUN_08012fb0(0);
  iVar3 = FUN_0800af24();
  if (iVar3 < 0) {
    iVar3 = FUN_0800af24();
    iVar3 = -iVar3;
  }
  else {
    iVar3 = FUN_0800af24();
  }
  if (iVar3 < DAT_08008828) {
    iVar3 = FUN_0800af24();
  }
  else {
    iVar3 = 0;
  }
  iVar5 = iVar3 * 10 + *(int *)(DAT_0800882c + 0xc);
  if ((DAT_08008830 < iVar5) && (iVar5 < -DAT_08008830)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (*(char *)(DAT_0800882c + 0x52) == '\0') {
    iVar7 = *(int *)(DAT_0800882c + 8);
  }
  else {
    iVar7 = 0;
  }
  if (bVar1) {
    iVar8 = iVar5 / -DAT_08008830;
  }
  else {
    iVar8 = 0;
  }
  iVar7 = iVar7 + iVar8;
  iVar8 = FUN_08018564();
  if (iVar8 < 0x2711) {
    iVar8 = FUN_08018564();
    if (iVar8 < 3000) {
      iVar8 = 3000;
    }
    else {
      iVar8 = FUN_08018564();
    }
  }
  else {
    iVar8 = 10000;
  }
  uVar4 = FUN_08018222(iVar8 * 0x262c,10000);
  FUN_080182ce(iVar7 * 10000,uVar4);
  FUN_0801305c();
  if (bVar1) {
    iVar8 = FUN_08018288(iVar5,-DAT_08008830);
    *(int *)(DAT_0800882c + 0xc) = iVar5 - -DAT_08008830 * iVar8;
  }
  else {
    *(int *)(DAT_0800882c + 0xc) = iVar5;
  }
  iVar5 = iVar3;
  if (iVar3 < 0) {
    iVar5 = 0;
  }
  iVar6 = iVar5 * 10 + *(int *)(DAT_0800882c + 0x10);
  iVar5 = -DAT_08008830;
  iVar8 = iVar3;
  if (-1 < iVar3) {
    iVar8 = 0;
  }
  iVar10 = iVar8 * -10 + *(int *)(DAT_0800882c + 0x14);
  iVar8 = -DAT_08008830;
  if (iVar6 < iVar5) {
    iVar9 = 0;
  }
  else {
    iVar9 = iVar6 / -DAT_08008830;
  }
  uVar11 = *(int *)(DAT_0800882c + 0x24) + iVar9;
  if (uVar11 < 0xfffffffd) {
    FUN_08013068(uVar11);
  }
  else {
    FUN_08013068(0);
  }
  if (iVar10 < iVar8) {
    iVar9 = 0;
  }
  else {
    iVar9 = iVar10 / -DAT_08008830;
  }
  uVar11 = *(int *)(DAT_0800882c + 0x28) + iVar9;
  if (uVar11 < 0xfffffffd) {
    FUN_08013074(uVar11);
  }
  else {
    FUN_08013074(0);
  }
  if (iVar6 < iVar5) {
    *(int *)(DAT_0800882c + 0x10) = iVar6;
  }
  else {
    iVar5 = FUN_08018288(iVar6,-DAT_08008830);
    *(int *)(DAT_0800882c + 0x10) = iVar6 - -DAT_08008830 * iVar5;
  }
  if (iVar10 < iVar8) {
    *(int *)(DAT_0800882c + 0x14) = iVar10;
  }
  else {
    iVar5 = FUN_08018288(iVar10,-DAT_08008830);
    *(int *)(DAT_0800882c + 0x14) = iVar10 - -DAT_08008830 * iVar5;
  }
  FUN_080182ce(iVar3,4);
  FUN_08013080();
  iVar3 = DAT_0800882c;
  if ((DAT_08008834 < iVar7) || (iVar7 < -DAT_08008834)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  *(undefined1 *)(DAT_0800882c + 0x52) = uVar2;
  *(int *)(iVar3 + 8) = iVar7;
  uVar4 = FUN_08018534();
  *(undefined4 *)(DAT_0800882c + 0x24) = uVar4;
  uVar4 = FUN_08018540();
  *(undefined4 *)(DAT_0800882c + 0x28) = uVar4;
  FUN_08012fb0(1);
  return;
}



/* ===== FUN_08008838 @ 0x8008838 ===== */

void FUN_08008838(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  FUN_08012fbc(1);
  if (*(char *)(DAT_08008970 + 0x6a) != '\0') {
    uVar3 = FUN_0801857c();
    *(undefined4 *)(DAT_08008970 + 4) = uVar3;
  }
  iVar4 = FUN_08018504();
  iVar2 = DAT_08008974;
  iVar1 = DAT_08008970;
  iVar4 = iVar4 - *(int *)(DAT_08008970 + 4);
  if (iVar4 < 0) {
    iVar4 = -iVar4;
  }
  if (499 < iVar4) {
    iVar4 = 0;
  }
  if (*(char *)(DAT_08008970 + 0x6b) == '\0') {
    *(undefined1 *)(DAT_08008970 + 0x6b) = 1;
    *(undefined1 *)(iVar1 + 0x6c) = 2;
    FUN_08012f30(*(undefined4 *)(DAT_08008974 + 0xc));
    FUN_0800adb4();
    FUN_08012e8c();
    *(undefined2 *)(DAT_08008974 + 0x26) = *(undefined2 *)(DAT_08008974 + 0x22);
  }
  else if (*(char *)(DAT_08008970 + 0x6c) == '\x01') {
    iVar4 = iVar4 + (uint)*(ushort *)(DAT_08008974 + 0x26);
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    else if (0xffff < iVar4) {
      iVar4 = 0xffff;
    }
    *(short *)(DAT_08008974 + 0x26) = (short)iVar4;
    if (19999 < *(ushort *)(iVar2 + 0x26)) {
      *(undefined2 *)(DAT_08008974 + 0x26) = 0;
      iVar4 = FUN_0800adb4();
      uVar6 = iVar4 + 1;
      uVar5 = FUN_0800adb4();
      if (uVar6 < uVar5) {
        uVar6 = 0xffffffff;
      }
      FUN_08012f30(uVar6);
    }
    FUN_0800adb4();
    FUN_08012e8c();
  }
  else {
    *(undefined1 *)(DAT_08008970 + 0x6c) = 1;
    iVar1 = DAT_08008974;
    iVar4 = iVar4 + (uint)*(ushort *)(DAT_08008974 + 0x26);
    if (iVar4 < 0) {
      iVar4 = 0;
    }
    else if (0xffff < iVar4) {
      iVar4 = 0xffff;
    }
    *(short *)(DAT_08008974 + 0x26) = (short)iVar4;
    if (19999 < *(ushort *)(iVar1 + 0x26)) {
      *(undefined2 *)(DAT_08008974 + 0x26) = 0;
      iVar4 = FUN_0800adb4();
      uVar6 = iVar4 + 1;
      uVar5 = FUN_0800adb4();
      if (uVar6 < uVar5) {
        uVar6 = 0xffffffff;
      }
      FUN_08012f30(uVar6);
    }
    FUN_0800adb4();
    FUN_08012e8c();
  }
  *(undefined1 *)(DAT_08008970 + 0x6a) = 0;
  uVar3 = FUN_08018504();
  *(undefined4 *)(DAT_08008970 + 4) = uVar3;
  FUN_08012fbc(0);
  FUN_08012ea0(*(undefined2 *)(DAT_08008974 + 0x26));
  return;
}



/* ===== FUN_08008978 @ 0x8008978 ===== */

void FUN_08008978(void)

{
  int iVar1;
  undefined2 uVar2;
  uint in_r3;
  uint local_8;
  
  local_8 = in_r3;
  FUN_08012fc8(1);
  iVar1 = DAT_080089e0;
  if (*(char *)(DAT_080089e0 + 0x68) == '\0') {
    *(undefined1 *)(DAT_080089e0 + 0x68) = 1;
    *(undefined1 *)(iVar1 + 0x69) = 2;
    uVar2 = FUN_08018504();
    *(undefined2 *)(DAT_080089e0 + 0x50) = uVar2;
    uVar2 = FUN_080184f8();
    *(undefined2 *)(DAT_080089e0 + 0x48) = uVar2;
    local_8 = 0;
  }
  else if (*(char *)(DAT_080089e0 + 0x69) == '\x01') {
    FUN_08010740(&local_8);
  }
  else {
    *(undefined1 *)(DAT_080089e0 + 0x69) = 1;
    FUN_08010740(&local_8);
  }
  FUN_08012fc8(0);
  FUN_08012f88(local_8 & 0xff);
  return;
}



/* ===== FUN_080089e4 @ 0x80089E4 ===== */

void FUN_080089e4(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  uint local_2c;
  uint local_28;
  
  FUN_08012fd4(1);
  iVar1 = FUN_0800aecc();
  iVar2 = FUN_0800aee8();
  if (iVar1 < iVar2) {
    iVar1 = FUN_0800aee8();
    uVar3 = FUN_0800aecc();
  }
  else {
    iVar1 = FUN_0800aecc();
    uVar3 = FUN_0800aee8();
  }
  if ((int)(iVar1 - uVar3) < 1000) {
    if ((int)uVar3 < 0xc80) {
      local_2c = uVar3 & 0xffff;
    }
    else {
      uVar4 = FUN_08019094(1000,uVar3 - 0xc80);
      iVar1 = FUN_08018328(uVar4,(1000 - iVar1) + uVar3);
      if (DAT_08008cb8 < iVar1) {
        local_2c = 0x7fffffff;
      }
      else {
        local_2c = iVar1 + 0xc80;
      }
      if ((int)local_2c < 0) {
        local_2c = 0;
      }
      else if (0xffff < (int)local_2c) {
        local_2c = 0xffff;
      }
      local_2c = local_2c & 0xffff;
    }
  }
  else {
    local_2c = 0xc80;
  }
  iVar1 = FUN_0801854c();
  if (iVar1 < 0) {
    iVar1 = FUN_0801854c();
    iVar1 = -iVar1;
  }
  else {
    iVar1 = FUN_0801854c();
  }
  uVar4 = FUN_0800af58();
  iVar5 = FUN_08018bd4(uVar4,iVar1,DAT_08008cbc + 0xbc,DAT_08008cbc + -0xac,DAT_08008cbc + 0x550,
                       DAT_08008cbc,5);
  iVar2 = DAT_08008cc0;
  if (*(char *)(DAT_08008cc0 + 0x65) == '\0') {
    *(undefined1 *)(DAT_08008cc0 + 0x65) = 1;
    *(undefined1 *)(iVar2 + 0x66) = 3;
    local_28 = 10;
    *(undefined2 *)(DAT_08008cc4 + 0x24) = (undefined2)local_2c;
  }
  else if (*(char *)(DAT_08008cc0 + 0x66) == '\x01') {
    iVar2 = FUN_0801854c();
    if (((iVar2 < 1) && ((int)(local_2c & 0xffff) <= iVar5)) &&
       ((iVar2 = FUN_0800af58(), -6 < iVar2 || (iVar2 = FUN_0801854c(), DAT_08008cc8 <= iVar2)))) {
      uVar4 = FUN_0800af58();
      uVar6 = FUN_0801854c();
      uVar7 = FUN_08018570();
      FUN_080102fc(uVar7,uVar6,uVar4,DAT_08008cc4 + 0x24);
      uVar4 = FUN_0800af58();
      FUN_080102cc(local_2c & 0xffff,*(undefined2 *)(DAT_08008cc4 + 0x24),uVar4,&local_28);
    }
    else {
      *(undefined1 *)(DAT_08008cc0 + 0x66) = 3;
      local_28 = 10;
      *(undefined2 *)(DAT_08008cc4 + 0x24) = (undefined2)local_2c;
    }
  }
  else if (*(char *)(DAT_08008cc0 + 0x66) == '\x02') {
    if (((local_2c & 0xffff) < 0xf6e) || (iVar2 = FUN_0801854c(), iVar2 < 0)) {
      *(undefined1 *)(DAT_08008cc0 + 0x66) = 3;
      local_28 = 10;
      *(undefined2 *)(DAT_08008cc4 + 0x24) = (undefined2)local_2c;
    }
    else {
      FUN_08010808(&local_28,&local_2c);
    }
  }
  else {
    iVar2 = FUN_0801854c();
    if ((iVar2 < 1) && ((int)(local_2c & 0xffff) <= iVar5)) {
      iVar2 = FUN_0800af58();
      if ((iVar2 < -5) && (iVar2 = FUN_0801854c(), iVar2 < DAT_08008cc8 + 0x32)) {
        *(undefined1 *)(DAT_08008cc0 + 0x66) = 3;
        local_28 = 10;
        *(undefined2 *)(DAT_08008cc4 + 0x24) = (undefined2)local_2c;
      }
      else {
        *(undefined1 *)(DAT_08008cc0 + 0x66) = 1;
        uVar4 = FUN_0800af58();
        uVar6 = FUN_0801854c();
        uVar7 = FUN_08018570();
        FUN_080102fc(uVar7,uVar6,uVar4,DAT_08008cc4 + 0x24);
        uVar4 = FUN_0800af58();
        FUN_080102cc(local_2c & 0xffff,*(undefined2 *)(DAT_08008cc4 + 0x24),uVar4,&local_28);
      }
    }
    else if (((local_2c & 0xffff) < 0xfa1) ||
            (iVar5 = FUN_0801854c(), iVar2 = DAT_08008cc0, iVar5 < 1)) {
      local_28 = 10;
      *(undefined2 *)(DAT_08008cc4 + 0x24) = (undefined2)local_2c;
    }
    else {
      *(undefined1 *)(DAT_08008cc0 + 0x66) = 2;
      *(undefined4 *)(iVar2 + 0x40) = 0;
      *(undefined2 *)(iVar2 + 0x4e) = 0;
      *(undefined2 *)(iVar2 + 0x4c) = (undefined2)local_2c;
      *(undefined1 *)(iVar2 + 0x67) = 0;
      *(undefined4 *)(iVar2 + 0x2c) = 0x105f;
      FUN_08010808(&local_28,&local_2c);
    }
  }
  iVar2 = FUN_0801854c();
  if (iVar2 < 1) {
    uVar4 = FUN_0800af58();
    iVar1 = FUN_08018f42(iVar1,uVar4,DAT_08008cbc + -0x30,DAT_08008cbc + 0xcc,DAT_08008cbc + 0x5bf,
                         DAT_08008cbc + -8,5);
  }
  else {
    iVar1 = 100;
  }
  if ((int)(local_28 & 0xff) < iVar1) {
    *(undefined1 *)(DAT_08008cc4 + 0x2d) = (undefined1)local_28;
  }
  else {
    *(char *)(DAT_08008cc4 + 0x2d) = (char)iVar1;
  }
  FUN_08012fd4(0);
  FUN_08013028(*(undefined2 *)(DAT_08008cc4 + 0x24));
  return;
}



/* ===== FUN_08008ccc @ 0x8008CCC ===== */

/* WARNING: Removing unreachable block (ram,0x08008d6a) */
/* WARNING: Removing unreachable block (ram,0x08008e04) */

void FUN_08008ccc(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  FUN_08012fe0(1);
  if (*(byte *)(DAT_08008e48 + 100) < 0x1f) {
    *(char *)(DAT_08008e48 + 100) = *(char *)(DAT_08008e48 + 100) + '\x01';
  }
  iVar1 = DAT_08008e48;
  if (*(char *)(DAT_08008e48 + 0x62) == '\0') {
    *(undefined1 *)(DAT_08008e48 + 0x62) = 1;
    *(undefined1 *)(iVar1 + 99) = 2;
    iVar1 = DAT_08008e4c;
    *(undefined1 *)(DAT_08008e4c + 0x2c) = 0;
    *(undefined4 *)(iVar1 + 0x14) = 0xfffffffe;
    *(undefined4 *)(DAT_08008e48 + 0x3c) = 0;
  }
  else if (*(char *)(DAT_08008e48 + 99) == '\x01') {
    if (0x13 < *(byte *)(DAT_08008e48 + 100)) {
      *(undefined1 *)(DAT_08008e48 + 99) = 2;
      iVar1 = DAT_08008e4c;
      *(undefined1 *)(DAT_08008e4c + 0x2c) = 0;
      *(undefined4 *)(iVar1 + 0x14) = 0xfffffffe;
      *(undefined4 *)(DAT_08008e48 + 0x3c) = 0;
    }
  }
  else if (*(char *)(DAT_08008e48 + 99) == '\x02') {
    iVar2 = FUN_0800ae14();
    iVar1 = DAT_08008e48;
    if (iVar2 == 1) {
      *(undefined1 *)(DAT_08008e48 + 99) = 3;
      *(undefined4 *)(iVar1 + 0x3c) = 0;
      *(undefined4 *)(DAT_08008e4c + 0x14) = 0xffffffe0;
      uVar3 = FUN_080184d4();
      *(undefined4 *)(DAT_08008e48 + 0x34) = uVar3;
      uVar3 = FUN_080184e0();
      *(undefined4 *)(DAT_08008e48 + 0x38) = uVar3;
    }
  }
  else {
    iVar2 = FUN_0800ae20();
    iVar1 = DAT_08008e48;
    if (iVar2 == 1) {
      *(undefined1 *)(DAT_08008e48 + 99) = 1;
      *(undefined1 *)(iVar1 + 100) = 0;
      uVar3 = FUN_080184e0();
      uVar4 = FUN_080184d4();
      FUN_08010200(*(undefined4 *)(DAT_08008e48 + 0x34),*(undefined4 *)(DAT_08008e48 + 0x38),uVar4,
                   uVar3,DAT_08008e4c + 0x14,DAT_08008e4c + 0x2c);
    }
    else if (*(uint *)(DAT_08008e48 + 0x3c) < 0xa8c0) {
      iVar2 = FUN_0800ae14();
      iVar1 = DAT_08008e48;
      if (iVar2 == 1) {
        *(undefined1 *)(DAT_08008e48 + 99) = 3;
        *(undefined4 *)(iVar1 + 0x3c) = 0;
        *(undefined4 *)(DAT_08008e4c + 0x14) = 0xffffffe0;
        uVar3 = FUN_080184d4();
        *(undefined4 *)(DAT_08008e48 + 0x34) = uVar3;
        uVar3 = FUN_080184e0();
        *(undefined4 *)(DAT_08008e48 + 0x38) = uVar3;
      }
      else {
        uVar5 = *(int *)(DAT_08008e48 + 0x3c) + 1;
        if (uVar5 < *(uint *)(DAT_08008e48 + 0x3c)) {
          uVar5 = 0xffffffff;
        }
        *(uint *)(DAT_08008e48 + 0x3c) = uVar5;
      }
    }
    else {
      *(undefined1 *)(DAT_08008e48 + 99) = 2;
      iVar1 = DAT_08008e4c;
      *(undefined1 *)(DAT_08008e4c + 0x2c) = 0;
      *(undefined4 *)(iVar1 + 0x14) = 0xfffffffe;
      *(undefined4 *)(DAT_08008e48 + 0x3c) = 0;
    }
  }
  FUN_08012fe0(0);
  FUN_08012f7c(*(undefined4 *)(DAT_08008e4c + 0x14));
  return;
}



/* ===== FUN_08008e50 @ 0x8008E50 ===== */

void FUN_08008e50(void)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  FUN_08012fec(1);
  iVar1 = FUN_08018534();
  uVar5 = iVar1 - *(int *)(DAT_08008fb8 + 0x1c);
  uVar2 = FUN_08018534();
  iVar1 = DAT_08008fb8;
  if (uVar2 < uVar5) {
    uVar5 = 0;
  }
  if (*(char *)(DAT_08008fb8 + 0x60) == '\0') {
    *(undefined1 *)(DAT_08008fb8 + 0x60) = 1;
    *(undefined1 *)(iVar1 + 0x61) = 1;
    FUN_08012f3c(*(undefined4 *)(DAT_08008fbc + 4));
    FUN_0800adc0();
    FUN_08012e74();
  }
  else if (*(char *)(DAT_08008fb8 + 0x61) == '\x01') {
    *(undefined1 *)(DAT_08008fb8 + 0x61) = 2;
    if (0x13 < uVar5) {
      uVar5 = 0;
    }
    iVar1 = FUN_0800adc0();
    uVar5 = iVar1 + uVar5;
    uVar2 = FUN_0800adc0();
    if (uVar5 < uVar2) {
      uVar5 = 0xffffffff;
    }
    FUN_08012f3c(uVar5);
    FUN_0800adc0();
    FUN_08012e74();
  }
  else {
    if (0x13 < uVar5) {
      uVar5 = 0;
    }
    iVar1 = FUN_0800adc0();
    uVar5 = iVar1 + uVar5;
    uVar2 = FUN_0800adc0();
    if (uVar5 < uVar2) {
      uVar5 = 0xffffffff;
    }
    FUN_08012f3c(uVar5);
    FUN_0800adc0();
    FUN_08012e74();
  }
  iVar3 = FUN_08018540();
  iVar1 = DAT_08008fb8;
  uVar2 = iVar3 - *(int *)(DAT_08008fb8 + 0x20);
  if (*(char *)(DAT_08008fb8 + 0x5e) == '\0') {
    *(undefined1 *)(DAT_08008fb8 + 0x5e) = 1;
    *(undefined1 *)(iVar1 + 0x5f) = 1;
    FUN_08012f48(*(undefined4 *)(DAT_08008fbc + 8));
    FUN_0800adcc();
    FUN_08012e80();
  }
  else if (*(char *)(DAT_08008fb8 + 0x5f) == '\x01') {
    *(undefined1 *)(DAT_08008fb8 + 0x5f) = 2;
    if (0x13 < uVar2) {
      uVar2 = 0;
    }
    iVar1 = FUN_0800adcc();
    uVar2 = iVar1 + uVar2;
    uVar5 = FUN_0800adcc();
    if (uVar2 < uVar5) {
      uVar2 = 0xffffffff;
    }
    FUN_08012f48(uVar2);
    FUN_0800adcc();
    FUN_08012e80();
  }
  else {
    if (0x13 < uVar2) {
      uVar2 = 0;
    }
    iVar1 = FUN_0800adcc();
    uVar2 = iVar1 + uVar2;
    uVar5 = FUN_0800adcc();
    if (uVar2 < uVar5) {
      uVar2 = 0xffffffff;
    }
    FUN_08012f48(uVar2);
    FUN_0800adcc();
    FUN_08012e80();
  }
  uVar4 = FUN_08018534();
  *(undefined4 *)(DAT_08008fb8 + 0x1c) = uVar4;
  uVar4 = FUN_08018540();
  *(undefined4 *)(DAT_08008fb8 + 0x20) = uVar4;
  FUN_08012fec(0);
  return;
}



/* ===== FUN_08008fc0 @ 0x8008FC0 ===== */

void FUN_08008fc0(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined1 uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_18;
  uint local_14;
  
  local_18 = param_3;
  local_14 = param_4;
  FUN_08012ff8(1);
  iVar3 = FUN_0800ae90();
  if (iVar3 == 0) {
    uVar4 = FUN_0800aecc();
    FUN_080103ec(uVar4,&local_14);
    iVar3 = (int)(short)local_14;
    uVar4 = FUN_0800aee8();
    FUN_080103ec(uVar4,&local_14);
    FUN_0801036c(iVar3,(int)(short)local_14,&local_18);
    FUN_08013098((int)(short)local_18);
    uVar4 = FUN_0800af58();
    FUN_0801017c((int)(short)local_18,uVar4,&local_14);
    if ((short)local_14 < 0x2711) {
      if ((short)local_14 < 0) {
        FUN_080130e4(0);
      }
      else {
        FUN_080130e4(local_14 & 0xffff);
      }
    }
    else {
      FUN_080130e4(10000);
    }
  }
  else {
    FUN_08013098(5000);
    FUN_080130e4(5000);
  }
  iVar5 = FUN_0800ae38();
  iVar3 = DAT_080090d4;
  if (iVar5 == 1) {
    *(undefined4 *)(DAT_080090d4 + 4) = 0;
    *(undefined4 *)(iVar3 + 8) = 0;
  }
  else {
    uVar4 = FUN_0800aba4();
    *(undefined4 *)(DAT_080090d4 + 4) = uVar4;
    uVar4 = FUN_0800abb0();
    *(undefined4 *)(DAT_080090d4 + 8) = uVar4;
  }
  iVar5 = FUN_0800ae2c();
  iVar3 = DAT_080090d4;
  if (iVar5 == 1) {
    *(undefined4 *)(DAT_080090d4 + 0xc) = 0;
    *(undefined2 *)(iVar3 + 0x22) = 0;
    *(undefined4 *)(iVar3 + 0x10) = 0;
  }
  else {
    uVar4 = FUN_0800abbc();
    *(undefined4 *)(DAT_080090d4 + 0xc) = uVar4;
    uVar2 = FUN_0800abc8();
    *(undefined2 *)(DAT_080090d4 + 0x22) = uVar2;
    uVar4 = FUN_0800ab98();
    *(undefined4 *)(DAT_080090d4 + 0x10) = uVar4;
  }
  iVar5 = FUN_0800ae44();
  iVar3 = DAT_080090d4;
  if (iVar5 == 1) {
    *(undefined2 *)(DAT_080090d4 + 0x20) = 1000;
    *(undefined1 *)(iVar3 + 0x2b) = 0;
  }
  else {
    uVar2 = FUN_0800abd4();
    *(undefined2 *)(DAT_080090d4 + 0x20) = uVar2;
    uVar1 = FUN_0800abe0();
    *(undefined1 *)(DAT_080090d4 + 0x2b) = uVar1;
  }
  FUN_08012ff8(0);
  return;
}



/* ===== FUN_080090d8 @ 0x80090D8 ===== */

/* WARNING: Removing unreachable block (ram,0x080091c6) */

void FUN_080090d8(void)

{
  bool bVar1;
  ushort uVar2;
  char cVar3;
  undefined1 uVar4;
  undefined2 uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  FUN_08013004(1);
  if (*(byte *)(DAT_08009488 + 0x59) < 0x1f) {
    *(char *)(DAT_08009488 + 0x59) = *(char *)(DAT_08009488 + 0x59) + '\x01';
  }
  iVar7 = DAT_08009488;
  if (*(char *)(DAT_08009488 + 0x57) == '\0') {
    *(undefined1 *)(DAT_08009488 + 0x57) = 1;
    *(undefined1 *)(iVar7 + 0x58) = 2;
    FUN_08012f24((short)DAT_0800948c[8]);
    uVar5 = FUN_0800ada8();
    *(undefined2 *)((int)DAT_0800948c + 0x1e) = uVar5;
    bVar1 = false;
  }
  else {
    cVar3 = *(char *)(DAT_08009488 + 0x58);
    if (cVar3 == '\x01') {
      if ((*(uint *)(DAT_08009488 + 0x30) < 0x515) && (299 < *(uint *)(DAT_08009488 + 0x30))) {
        *(undefined1 *)(DAT_08009488 + 0x58) = 3;
        *(undefined1 *)(iVar7 + 0x59) = 0;
        uVar5 = (undefined2)*(undefined4 *)(iVar7 + 0x30);
        if (0xffff < *(uint *)(iVar7 + 0x30)) {
          uVar5 = 0xffff;
        }
        FUN_08012f24(uVar5);
        uVar5 = FUN_0800ada8();
        *(undefined2 *)((int)DAT_0800948c + 0x1e) = uVar5;
        bVar1 = true;
      }
      else {
        *(undefined1 *)(DAT_08009488 + 0x58) = 4;
        bVar1 = false;
      }
    }
    else if (cVar3 == '\x02') {
      *(undefined1 *)(DAT_08009488 + 0x58) = 4;
      bVar1 = false;
    }
    else if (cVar3 == '\x03') {
      bVar1 = *(byte *)(DAT_08009488 + 0x59) < 0x14;
      if (!bVar1) {
        *(undefined1 *)(DAT_08009488 + 0x58) = 4;
      }
    }
    else {
      bVar1 = false;
      if ((char)DAT_0800948c[0xb] == '\x01') {
        *(undefined1 *)(DAT_08009488 + 0x58) = 1;
        uVar6 = FUN_0801851c();
        uVar9 = FUN_08019150(uVar6,1000);
        *(uint *)(DAT_08009488 + 0x30) = uVar9 / 0x262c;
      }
      else {
        uVar5 = FUN_0800ada8();
        *(undefined2 *)((int)DAT_0800948c + 0x1e) = uVar5;
      }
    }
  }
  iVar7 = DAT_08009488;
  if (*(char *)(DAT_08009488 + 0x5c) == '\0') {
    *(undefined1 *)(DAT_08009488 + 0x5c) = 1;
    *(undefined1 *)(iVar7 + 0x5d) = 2;
    *DAT_0800948c = DAT_0800948c[4];
  }
  else if (*(char *)(DAT_08009488 + 0x5d) == '\x01') {
    if ((bVar1) || (uVar9 = FUN_080184ec(), uVar9 < *DAT_0800948c)) {
      uVar9 = FUN_080184ec();
      *DAT_0800948c = uVar9;
    }
  }
  else {
    *(undefined1 *)(DAT_08009488 + 0x5d) = 1;
    if ((bVar1) || (uVar9 = FUN_080184ec(), uVar9 < *DAT_0800948c)) {
      uVar9 = FUN_080184ec();
      *DAT_0800948c = uVar9;
    }
  }
  iVar7 = FUN_080184ec();
  iVar8 = FUN_08018b22(iVar7 - *DAT_0800948c,DAT_08009490 + -0x554,DAT_08009490,9);
  iVar7 = DAT_08009488;
  if (699 < iVar8) {
    iVar8 = 700;
  }
  uVar9 = (uint)*(ushort *)((int)DAT_0800948c + 0x1e) - iVar8;
  uVar11 = uVar9 & 0xffff;
  uVar5 = (undefined2)uVar9;
  if (*(char *)(DAT_08009488 + 0x5a) == '\0') {
    *(undefined1 *)(DAT_08009488 + 0x5a) = 1;
    *(undefined1 *)(iVar7 + 0x5b) = 2;
    FUN_08012f54(*(undefined1 *)((int)DAT_0800948c + 0x2b));
    uVar4 = FUN_0800add8();
    *(undefined1 *)((int)DAT_0800948c + 0x2a) = uVar4;
    *(undefined2 *)(DAT_08009488 + 0x4a) = uVar5;
  }
  else if (*(char *)(DAT_08009488 + 0x5b) == '\x01') {
    if ((uVar11 < *(ushort *)(DAT_08009488 + 0x4a)) && (*(char *)((int)DAT_0800948c + 0x2a) != '\0')
       ) {
      uVar9 = *(byte *)((int)DAT_0800948c + 0x2a) - 1;
      if ((int)uVar9 < 0) {
        uVar9 = 0;
      }
      FUN_08012f54(uVar9 & 0xff);
    }
    *(undefined2 *)(DAT_08009488 + 0x4a) = uVar5;
    if (bVar1) {
      FUN_08012f54(10);
    }
    uVar4 = FUN_0800add8();
    *(undefined1 *)((int)DAT_0800948c + 0x2a) = uVar4;
  }
  else {
    *(undefined1 *)(DAT_08009488 + 0x5b) = 1;
    if ((uVar11 < *(ushort *)(iVar7 + 0x4a)) && (*(char *)((int)DAT_0800948c + 0x2a) != '\0')) {
      uVar9 = *(byte *)((int)DAT_0800948c + 0x2a) - 1;
      if ((int)uVar9 < 0) {
        uVar9 = 0;
      }
      FUN_08012f54(uVar9 & 0xff);
    }
    *(undefined2 *)(DAT_08009488 + 0x4a) = uVar5;
    if (bVar1) {
      FUN_08012f54(10);
    }
    uVar4 = FUN_0800add8();
    *(undefined1 *)((int)DAT_0800948c + 0x2a) = uVar4;
  }
  if (*(byte *)((int)DAT_0800948c + 0x2a) < 10) {
    uVar9 = (uint)*(byte *)((int)DAT_0800948c + 0x2a);
  }
  else {
    uVar9 = 10;
  }
  uVar2 = *(ushort *)((int)DAT_0800948c + 0x1e);
  if (*(byte *)((int)DAT_0800948c + 0x2a) < 10) {
    uVar10 = (uint)*(byte *)((int)DAT_0800948c + 0x2a);
  }
  else {
    uVar10 = 10;
  }
  iVar7 = FUN_0800ae9c();
  if (iVar7 < 0x3e9) {
    iVar7 = FUN_0800ae9c();
    if (iVar7 < 800) {
      iVar7 = 800;
    }
    else {
      iVar7 = FUN_0800ae9c();
    }
  }
  else {
    iVar7 = 1000;
  }
  FUN_08013004(0);
  FUN_08018266((uint)*(ushort *)((int)DAT_0800948c + 0x1e) * 0x262c,1000);
  FUN_08013034();
  FUN_08012e68(*DAT_0800948c);
  FUN_080130a4((uVar9 * uVar2 & 0xffff) + (10 - uVar9) * uVar11 & 0xffff);
  uVar11 = (1000 - iVar7) + uVar11;
  if (0xffff < uVar11) {
    uVar11 = 0xffff;
  }
  if (*(ushort *)((int)DAT_0800948c + 0x1e) < 0x3e9) {
    if (*(ushort *)((int)DAT_0800948c + 0x1e) < 300) {
      uVar9 = 300;
    }
    else {
      uVar9 = (uint)*(ushort *)((int)DAT_0800948c + 0x1e);
    }
  }
  else {
    uVar9 = 1000;
  }
  uVar9 = FUN_0801838a(uVar9 * 1000,iVar7);
  if (uVar9 < 0x3e9) {
    if (uVar9 < 300) {
      uVar9 = 300;
    }
  }
  else {
    uVar9 = 1000;
  }
  if ((uVar11 & 0xffff) < 0x3e9) {
    if ((uVar11 & 0xffff) < 300) {
      uVar11 = 300;
    }
    else {
      uVar11 = uVar11 & 0xffff;
    }
  }
  else {
    uVar11 = 1000;
  }
  FUN_080130b0(uVar9 * uVar10 + uVar11 * (10 - uVar10) & 0xffff);
  FUN_08012eb8(*(undefined2 *)((int)DAT_0800948c + 0x1e));
  FUN_08012ec4(*(undefined1 *)((int)DAT_0800948c + 0x2a));
  return;
}



/* ===== FUN_08009494 @ 0x8009494 ===== */

void FUN_08009494(void)

{
  short sVar1;
  int *piVar2;
  int *piVar3;
  byte bVar4;
  ushort uVar5;
  undefined2 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  ushort uVar11;
  char cVar12;
  short sVar13;
  uint local_2c;
  undefined4 local_28;
  int local_24;
  
  iVar7 = FUN_0800af04();
  if (iVar7 < 0x1389) {
    iVar7 = FUN_0800af04();
    if (iVar7 < 1000) {
      local_28 = 1000;
    }
    else {
      local_28 = FUN_0800af04();
    }
  }
  else {
    local_28 = 5000;
  }
  iVar7 = FUN_0800aecc();
  if (iVar7 < 0x1389) {
    iVar7 = FUN_0800aecc();
    if (iVar7 < 1000) {
      local_2c = 1000;
    }
    else {
      local_2c = FUN_0800aecc();
    }
  }
  else {
    local_2c = 5000;
  }
  iVar7 = FUN_0800aee8();
  if (iVar7 < 0x1389) {
    iVar7 = FUN_0800aee8();
    if (iVar7 < 1000) {
      uVar5 = 1000;
    }
    else {
      uVar5 = FUN_0800aee8();
    }
  }
  else {
    uVar5 = 5000;
  }
  piVar2 = DAT_08009924;
  uVar11 = uVar5;
  if ((short)(ushort)local_2c <= (short)uVar5) {
    uVar11 = (ushort)local_2c;
  }
  if ((short)uVar5 <= (short)(ushort)local_2c) {
    uVar5 = (ushort)local_2c;
  }
  *(ushort *)(DAT_08009924 + 2) = uVar5 - uVar11;
  *(short *)(piVar2 + 1) = 1000 - (short)piVar2[2];
  *(ushort *)((int)piVar2 + 10) = uVar11 - 0xc80;
  if ((short)piVar2[1] == 0) {
    if ((int)(short)piVar2[2] * (int)*(short *)((int)piVar2 + 10) < 0) {
      *DAT_08009924 = -0x80000000;
    }
    else {
      *DAT_08009924 = 0x7fffffff;
    }
  }
  else {
    *DAT_08009924 =
         ((int)(short)DAT_08009924[2] * (int)*(short *)((int)DAT_08009924 + 10)) /
         (int)(uint)*(ushort *)(DAT_08009924 + 1);
  }
  if (*DAT_08009924 < 0x8000) {
    if (*DAT_08009924 < -0x8000) {
      sVar13 = (short)DAT_08009928;
    }
    else {
      sVar13 = (short)*DAT_08009924;
    }
  }
  else {
    sVar13 = 0x7fff;
  }
  *(ushort *)(DAT_08009924 + 3) = sVar13 + uVar11;
  if ((0xc80 < (short)uVar11) && (uVar11 = uVar5, (short)uVar5 < 0x1068)) {
    uVar11 = *(ushort *)(DAT_08009924 + 3);
  }
  local_2c = (uint)uVar11;
  if ((int)((uint)*(byte *)(DAT_0800992c + 4) << 0x1c) < 0) {
    *(ushort *)(DAT_0800992c + 0x12) = uVar11;
  }
  iVar7 = FUN_0800af24();
  if (iVar7 < 500) {
    *(ushort *)(DAT_0800992c + 0x12) = uVar11;
  }
  else if (*(ushort *)(DAT_0800992c + 0x12) < uVar11) {
    *(ushort *)(DAT_0800992c + 0x12) = uVar11;
  }
  if ((int)((uint)*(byte *)(DAT_0800992c + 4) << 0x1b) < 0) {
    uVar6 = FUN_0800ae50();
    *(undefined2 *)(DAT_0800992c + 6) = uVar6;
  }
  if ((int)((uint)*(byte *)(DAT_0800992c + 4) << 0x1a) < 0) {
    uVar6 = FUN_0800ae50();
    *(undefined2 *)(DAT_0800992c + 8) = uVar6;
  }
  if ((int)((uint)*(byte *)(DAT_0800992c + 4) << 0x19) < 0) {
    uVar6 = FUN_0800ae50();
    *(undefined2 *)(DAT_0800992c + 10) = uVar6;
  }
  if (*(short *)(DAT_0800992c + 6) == *(short *)(DAT_0800992c + 8)) {
    sVar13 = *(short *)(DAT_0800992c + 8);
  }
  else {
    sVar13 = *(short *)(DAT_0800992c + 6);
    *(undefined2 *)(DAT_0800992c + 10) = *(undefined2 *)(DAT_0800992c + 8);
  }
  if ((short)(sVar13 - *(short *)(DAT_0800992c + 10)) < 0) {
    uVar8 = FUN_0800ae50();
    FUN_08011024(uVar8,(int)sVar13,DAT_0800992c + 6);
  }
  else {
    uVar8 = FUN_0800ae50();
    FUN_08011010(uVar8,(int)sVar13,DAT_0800992c + 6);
  }
  if (*(char *)(DAT_0800992c + 4) < '\0') {
    uVar6 = FUN_0800ae70();
    *(undefined2 *)(DAT_0800992c + 0xc) = uVar6;
  }
  if ((*(byte *)(DAT_0800992c + 5) & 1) != 0) {
    uVar6 = FUN_0800ae70();
    *(undefined2 *)(DAT_0800992c + 0xe) = uVar6;
  }
  if ((int)((uint)*(byte *)(DAT_0800992c + 5) << 0x1e) < 0) {
    uVar6 = FUN_0800ae70();
    *(undefined2 *)(DAT_0800992c + 0x10) = uVar6;
  }
  if (*(short *)(DAT_0800992c + 0xc) == *(short *)(DAT_0800992c + 0xe)) {
    sVar1 = *(short *)(DAT_0800992c + 0xe);
  }
  else {
    sVar1 = *(short *)(DAT_0800992c + 0xc);
    *(undefined2 *)(DAT_0800992c + 0x10) = *(undefined2 *)(DAT_0800992c + 0xe);
  }
  if ((short)(sVar1 - *(short *)(DAT_0800992c + 0x10)) < 0) {
    uVar8 = FUN_0800ae70();
    FUN_08011024(uVar8,(int)sVar1,DAT_0800992c + 0xc);
  }
  else {
    uVar8 = FUN_0800ae70();
    FUN_08011010(uVar8,(int)sVar1,DAT_0800992c + 0xc);
  }
  iVar7 = FUN_08018fde(*(undefined2 *)(DAT_0800992c + 0x12),(int)*(short *)(DAT_0800992c + 6),
                       DAT_08009930 + 0xe0,DAT_08009930 + 0xce,DAT_08009930 + 8,DAT_08009930,0xb);
  FUN_08018fde(*(undefined2 *)(DAT_0800992c + 0x12),(int)*(short *)(DAT_0800992c + 0xc),
               DAT_08009930 + 0xe0,DAT_08009930 + 0xce,DAT_08009930 + 8,DAT_08009930,0xb);
  FUN_0801308c();
  iVar9 = FUN_0800af18();
  if (iVar7 <= iVar9) {
    FUN_0801308c(iVar7);
  }
  iVar7 = FUN_0800af40();
  if (iVar7 < 0x2711) {
    iVar7 = FUN_0800af40();
    if (iVar7 < 5000) {
      iVar7 = 5000;
    }
    else {
      iVar7 = FUN_0800af40();
    }
  }
  else {
    iVar7 = 10000;
  }
  iVar10 = FUN_0800af18();
  iVar9 = DAT_0800992c;
  local_24 = (iVar7 * iVar10) / 100;
  if ((int)((uint)*(byte *)(DAT_0800992c + 5) << 0x1d) < 0) {
    bVar4 = *(byte *)(DAT_0800992c + 4) & 7;
    if (bVar4 == 1) {
      if (*(char *)(DAT_0800992c + 0x14) < '\n') {
        if ((uVar11 < (ushort)local_28) || ((ushort)local_28 < 0xc80)) {
          *(undefined1 *)(DAT_0800992c + 0x14) = 0;
        }
        else {
          *(char *)(DAT_0800992c + 0x14) = *(char *)(DAT_0800992c + 0x14) + '\x01';
        }
      }
      else {
        *(undefined1 *)(DAT_0800992c + 0x14) = 0;
        *(byte *)(iVar9 + 4) = (*(byte *)(iVar9 + 4) & 0xf8) + 3;
        iVar7 = FUN_0800af24();
        if (iVar7 <= local_24) {
          local_24 = FUN_0800af24();
        }
      }
    }
    else if (bVar4 == 2) {
      if (*(char *)(DAT_0800992c + 0x14) < '\n') {
        FUN_08010e48(&local_28,&local_2c,&local_24);
      }
      else {
        *(undefined1 *)(DAT_0800992c + 0x14) = 0;
        *(byte *)(iVar9 + 4) = (*(byte *)(iVar9 + 4) & 0xf8) + 1;
        if (((ushort)local_28 <= uVar11) && (0xc7f < (ushort)local_28)) {
          *(undefined1 *)(DAT_0800992c + 0x14) = 1;
        }
      }
    }
    else if (bVar4 == 3) {
      *(byte *)(DAT_0800992c + 4) = (*(byte *)(DAT_0800992c + 4) & 0xf8) + 2;
      FUN_08010e48(&local_28,&local_2c,&local_24);
    }
    else {
      *(byte *)(DAT_0800992c + 4) = (*(byte *)(DAT_0800992c + 4) & 0xf8) + 1;
      if ((uVar11 < (ushort)local_28) || ((ushort)local_28 < 0xc80)) {
        *(undefined1 *)(DAT_0800992c + 0x14) = 0;
      }
      else {
        cVar12 = *(char *)(DAT_0800992c + 0x14) + '\x01';
        if (0x7f < *(char *)(DAT_0800992c + 0x14) + 1) {
          cVar12 = '\x7f';
        }
        *(char *)(DAT_0800992c + 0x14) = cVar12;
      }
    }
  }
  else {
    *(byte *)(DAT_0800992c + 5) = (*(byte *)(DAT_0800992c + 5) & 0xfb) + 4;
    *(byte *)(iVar9 + 4) = (*(byte *)(iVar9 + 4) & 0xf8) + 4;
    *(undefined1 *)(iVar9 + 0x14) = 0;
  }
  iVar7 = local_24 / 100;
  if (iVar7 < 0x2711) {
    if (iVar7 < 0) {
      *(undefined2 *)((int)DAT_08009924 + 6) = 0;
    }
    else {
      *(short *)((int)DAT_08009924 + 6) = (short)iVar7;
    }
  }
  else {
    *(undefined2 *)((int)DAT_08009924 + 6) = 10000;
  }
  iVar7 = FUN_0800ade4();
  if (iVar7 == 0) {
    FUN_080130d8(*(undefined2 *)((int)DAT_08009924 + 6));
  }
  else {
    FUN_080130d8(0);
  }
  piVar2 = DAT_08009998;
  *(byte *)(DAT_08009998 + 1) = *(byte *)(DAT_08009998 + 1) & 0xf7;
  *(byte *)(piVar2 + 1) = *(byte *)(piVar2 + 1) & 0xef;
  *(byte *)(piVar2 + 1) = *(byte *)(piVar2 + 1) & 0xdf;
  *(short *)(piVar2 + 2) = sVar13;
  *(byte *)(piVar2 + 1) = *(byte *)(piVar2 + 1) & 0xbf;
  *(byte *)(piVar2 + 1) = *(byte *)(piVar2 + 1) & 0x7f;
  piVar3 = DAT_08009998;
  *(byte *)((int)DAT_08009998 + 5) = *(byte *)((int)piVar2 + 5) & 0xfe;
  *(short *)((int)piVar3 + 0xe) = sVar1;
  *(byte *)((int)DAT_08009998 + 5) = *(byte *)((int)piVar3 + 5) & 0xfd;
  *DAT_08009998 = local_24;
  return;
}



/* ===== FUN_0800999c @ 0x800999C ===== */

void FUN_0800999c(void)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int in_r3;
  int local_18;
  
  local_18 = in_r3;
  FUN_08013010(1);
  uVar2 = FUN_0800af58();
  FUN_08010160(uVar2,&local_18);
  FUN_08013010(0);
  iVar3 = FUN_08018222(0,10000);
  iVar3 = local_18 - iVar3;
  iVar4 = FUN_080184f8();
  iVar4 = FUN_08018222((10000 - iVar4) * 0x98b,10000);
  local_18 = FUN_080182ce((local_18 - iVar4) * 10000,iVar3);
  if (local_18 < 0x2711) {
    if (local_18 < DAT_08009a2c) {
      local_18 = DAT_08009a2c;
    }
  }
  else {
    local_18 = 10000;
  }
  sVar1 = FUN_08018222(local_18 * 10000,10000);
  FUN_080130cc((int)sVar1);
  return;
}



/* ===== FUN_08009a30 @ 0x8009A30 ===== */

void FUN_08009a30(void)

{
  bool bVar1;
  int *piVar2;
  undefined2 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  uint uVar9;
  
  FUN_0801301c(1);
  if (*(char *)((int)DAT_08009d64 + 0x53) != '\0') {
    iVar4 = FUN_08018528();
    *DAT_08009d64 = iVar4;
  }
  iVar5 = FUN_08018528();
  piVar2 = DAT_08009d64;
  iVar5 = iVar5 - *DAT_08009d64;
  iVar4 = iVar5;
  if (iVar5 < 0) {
    iVar4 = -iVar5;
  }
  if (iVar4 < 0x32) {
    iVar4 = (int)(short)iVar5;
  }
  else {
    iVar4 = 0;
  }
  if ((char)DAT_08009d64[0x15] == '\0') {
    *(undefined1 *)(DAT_08009d64 + 0x15) = 1;
    *(undefined1 *)((int)piVar2 + 0x55) = 4;
    FUN_0801857c();
    FUN_08012f18();
    uVar3 = FUN_0800ad9c();
    *(undefined2 *)(DAT_08009d68 + 0x1c) = uVar3;
  }
  else {
    bVar1 = false;
    switch(*(undefined1 *)((int)DAT_08009d64 + 0x55)) {
    default:
      iVar5 = FUN_08018510();
      if (iVar5 == 0) {
        *(undefined1 *)((int)DAT_08009d64 + 0x55) = 1;
        uVar6 = FUN_0801854c();
        uVar7 = FUN_08018570();
        uVar8 = FUN_0800ad9c();
        FUN_08010408(uVar8,uVar7,iVar4,uVar6,*(undefined1 *)(DAT_08009d68 + 0x2d),
                     DAT_08009d68 + 0x1c,(int)DAT_08009d64 + 0x71);
        FUN_08012f18(*(undefined2 *)(DAT_08009d68 + 0x1c));
        FUN_08010704();
      }
      break;
    case 1:
      iVar5 = FUN_0800ae20();
      if (iVar5 == 1) {
        *(undefined1 *)((int)DAT_08009d64 + 0x55) = 3;
        FUN_08012f18(0);
        uVar3 = FUN_0800ad9c();
        *(undefined2 *)(DAT_08009d68 + 0x1c) = uVar3;
      }
      else {
        iVar5 = FUN_08018510();
        if (iVar5 == 1) {
          iVar4 = FUN_0800ad9c();
          if ((((int)(*(ushort *)(DAT_08009d68 + 0x28) + 500) < iVar4) ||
              (iVar4 = FUN_0800ad9c(), iVar4 <= (int)(uint)*(ushort *)(DAT_08009d68 + 0x28))) &&
             ((iVar4 = FUN_0800ad9c(), iVar4 + 1000 < (int)(uint)*(ushort *)(DAT_08009d68 + 0x28) ||
              (iVar4 = FUN_0800ad9c(), (int)(uint)*(ushort *)(DAT_08009d68 + 0x28) <= iVar4)))) {
            bVar1 = true;
          }
          else {
            piVar2 = DAT_08009d64;
            uVar9 = *(byte *)((int)DAT_08009d64 + 0x56) + 1;
            if (0xff < uVar9) {
              uVar9 = 0xff;
            }
            *(char *)((int)DAT_08009d64 + 0x56) = (char)uVar9;
            if (*(byte *)((int)piVar2 + 0x56) < 0x78) {
              *(undefined1 *)((int)DAT_08009d64 + 0x55) = 6;
            }
            else {
              bVar1 = true;
            }
          }
        }
        else {
          iVar5 = FUN_0800ae14();
          if (iVar5 == 1) {
            *(undefined1 *)((int)DAT_08009d64 + 0x55) = 2;
            FUN_08012f18(10000);
            uVar3 = FUN_0800ad9c();
            *(undefined2 *)(DAT_08009d68 + 0x1c) = uVar3;
          }
          else {
            uVar6 = FUN_0801854c();
            uVar7 = FUN_08018570();
            uVar8 = FUN_0800ad9c();
            FUN_08010408(uVar8,uVar7,iVar4,uVar6,*(undefined1 *)(DAT_08009d68 + 0x2d),
                         DAT_08009d68 + 0x1c,(int)DAT_08009d64 + 0x71);
            FUN_08012f18(*(undefined2 *)(DAT_08009d68 + 0x1c));
            FUN_08010704();
          }
        }
      }
      break;
    case 2:
      iVar5 = FUN_0800ae14();
      if (iVar5 == 0) {
        *(undefined1 *)((int)DAT_08009d64 + 0x55) = 1;
        uVar6 = FUN_0801854c();
        uVar7 = FUN_08018570();
        uVar8 = FUN_0800ad9c();
        FUN_08010408(uVar8,uVar7,iVar4,uVar6,*(undefined1 *)(DAT_08009d68 + 0x2d),
                     DAT_08009d68 + 0x1c,(int)DAT_08009d64 + 0x71);
        FUN_08012f18(*(undefined2 *)(DAT_08009d68 + 0x1c));
        FUN_08010704();
      }
      break;
    case 3:
      iVar5 = FUN_0800ae20();
      if (iVar5 == 0) {
        *(undefined1 *)((int)DAT_08009d64 + 0x55) = 1;
        uVar6 = FUN_0801854c();
        uVar7 = FUN_08018570();
        uVar8 = FUN_0800ad9c();
        FUN_08010408(uVar8,uVar7,iVar4,uVar6,*(undefined1 *)(DAT_08009d68 + 0x2d),
                     DAT_08009d68 + 0x1c,(int)DAT_08009d64 + 0x71);
        FUN_08012f18(*(undefined2 *)(DAT_08009d68 + 0x1c));
        FUN_08010704();
      }
      break;
    case 4:
      *(undefined1 *)((int)DAT_08009d64 + 0x55) = 1;
      uVar6 = FUN_0801854c();
      uVar7 = FUN_08018570();
      uVar8 = FUN_0800ad9c();
      FUN_08010408(uVar8,uVar7,iVar4,uVar6,*(undefined1 *)(DAT_08009d68 + 0x2d),DAT_08009d68 + 0x1c,
                   (int)DAT_08009d64 + 0x71);
      FUN_08012f18(*(undefined2 *)(DAT_08009d68 + 0x1c));
      FUN_08010704();
      break;
    case 5:
      iVar5 = FUN_08018510();
      if (iVar5 == 0) {
        *(undefined1 *)((int)DAT_08009d64 + 0x55) = 1;
        uVar6 = FUN_0801854c();
        uVar7 = FUN_08018570();
        uVar8 = FUN_0800ad9c();
        FUN_08010408(uVar8,uVar7,iVar4,uVar6,*(undefined1 *)(DAT_08009d68 + 0x2d),
                     DAT_08009d68 + 0x1c,(int)DAT_08009d64 + 0x71);
        FUN_08012f18(*(undefined2 *)(DAT_08009d68 + 0x1c));
        FUN_08010704();
      }
    }
    piVar2 = DAT_08009d64;
    if (bVar1) {
      *(undefined1 *)((int)DAT_08009d64 + 0x55) = 5;
      *(undefined1 *)((int)piVar2 + 0x56) = 0;
      FUN_08012f18(*(undefined2 *)(DAT_08009d68 + 0x28));
      uVar3 = FUN_0800ad9c();
      *(undefined2 *)(DAT_08009d68 + 0x1c) = uVar3;
    }
  }
  *(undefined1 *)((int)DAT_08009d64 + 0x53) = 0;
  iVar4 = FUN_08018528();
  *DAT_08009d64 = iVar4;
  FUN_0801301c(0);
  FUN_08012ed0(*(undefined2 *)(DAT_08009d68 + 0x1c));
  return;
}



/* ===== vfp_control_routine_08009d6c @ 0x8009D6C ===== */

/* Reachable routine with VFP register save and hardware floating-point operations; exact behavior
   is not yet named. */

undefined4 vfp_control_routine_08009d6c(uint param_1,uint param_2,uint param_3)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined8 uVar7;
  undefined4 local_3c;
  
  local_3c = 0;
  if ((((param_3 == 0) || (0x800 < (int)param_3)) ||
      (param_3 != ((int)(param_3 + ((uint)((int)param_3 >> 0x1f) >> 0x1e)) >> 2) * 4)) ||
     ((DAT_08009e68 <= param_2 + param_3 || (param_2 < DAT_08009e6c)))) {
    local_3c = 0;
  }
  else if (param_1 == param_2) {
    local_3c = 1;
  }
  else {
    uVar7 = FUN_08003218((int)(param_3 + ((uint)((int)param_3 >> 0x1f) >> 0x15)) >> 0xb);
    uVar7 = FUN_08018040((int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
    uVar1 = FUN_0800323a((int)uVar7,(int)((ulonglong)uVar7 >> 0x20));
    iVar2 = FUN_08009e70(param_2,uVar1);
    if (iVar2 == 0) {
      local_3c = 0;
    }
    else {
      FUN_08008378();
      for (uVar6 = 0; uVar6 < param_3; uVar6 = uVar6 + 4) {
        iVar2 = FUN_08009fd4(param_1 + uVar6 + 3);
        iVar3 = FUN_08009fd4(param_1 + uVar6 + 2);
        iVar4 = FUN_08009fd4(param_1 + uVar6 + 1);
        iVar5 = FUN_08009fd4(param_1 + uVar6);
        iVar2 = FUN_08008304(param_2,iVar5 + (iVar4 + (iVar3 + iVar2 * 0x100) * 0x100) * 0x100);
        if (iVar2 != 6) {
          local_3c = 0;
          break;
        }
        param_2 = param_2 + 4;
        local_3c = 1;
      }
      FUN_080082d4();
    }
  }
  return local_3c;
}



/* ===== FUN_08009e70 @ 0x8009E70 ===== */

undefined4 FUN_08009e70(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (param_2 <= (int)uVar2) {
      return 1;
    }
    iVar1 = FUN_08009e98(param_1);
    if (iVar1 == 0) break;
    param_1 = param_1 + 0x800;
    uVar2 = uVar2 + 1 & 0xffff;
  }
  return 0;
}



/* ===== FUN_08009e98 @ 0x8009E98 ===== */

undefined4 FUN_08009e98(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  if ((((param_1 & 0x7ff) == 0) && (param_1 < DAT_08009ecc)) && (DAT_08009ed0 <= param_1)) {
    FUN_08008378();
    iVar2 = FUN_08008230(param_1);
    if (iVar2 == 6) {
      FUN_080082d4();
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* ===== FUN_08009ed4 @ 0x8009ED4 ===== */

bool FUN_08009ed4(void)

{
  int iVar1;
  
  iVar1 = FUN_080081e4();
  return iVar1 != 1;
}



/* ===== FUN_08009ee8 @ 0x8009EE8 ===== */

bool FUN_08009ee8(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  bool bVar2;
  undefined4 local_828;
  undefined1 auStack_824 [2046];
  ushort local_26;
  
  FUN_080031d6(auStack_824,0x800);
  if ((param_1 + param_3 < 0x801) && (param_2 != 0)) {
    if (param_4 == 1) {
      local_828 = DAT_08009fac;
    }
    else if (param_4 == 2) {
      local_828 = DAT_08009fb0;
    }
    else {
      local_828 = DAT_08009fac;
    }
    FUN_08009fb8(local_828,auStack_824,0x800);
    uVar1 = FUN_0800aa50(auStack_824,0x7fe);
    bVar2 = local_26 == uVar1;
    if (bVar2) {
      FUN_080031a4(param_2,auStack_824 + param_1,param_3);
      *DAT_08009fb4 = *DAT_08009fb4 & 0xfd;
    }
    else {
      *DAT_08009fb4 = (*DAT_08009fb4 & 0xfd) + 2;
    }
  }
  else {
    bVar2 = false;
  }
  return bVar2;
}



/* ===== FUN_08009fb8 @ 0x8009FB8 ===== */

undefined4 FUN_08009fb8(int param_1,int param_2,int param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; (int)uVar1 < param_3; uVar1 = uVar1 + 1 & 0xffff) {
    *(undefined1 *)(param_2 + uVar1) = *(undefined1 *)(param_1 + uVar1);
  }
  return 1;
}



/* ===== FUN_08009fd4 @ 0x8009FD4 ===== */

undefined1 FUN_08009fd4(undefined1 *param_1)

{
  return *param_1;
}



/* ===== FUN_08009fdc @ 0x8009FDC ===== */

int FUN_08009fdc(int param_1,int param_2,int param_3,int param_4)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_824 [2046];
  undefined1 local_26;
  undefined1 local_25;
  
  FUN_080031d6(auStack_824,0x800);
  if ((param_1 + param_3 < 0x801) && (param_2 != 0)) {
    uVar3 = DAT_0800a0a0;
    if ((param_4 != 1) && (param_4 == 2)) {
      uVar3 = DAT_0800a0a4;
    }
    FUN_08009fb8(uVar3,auStack_824,0x800);
    FUN_080031a4(auStack_824 + param_1,param_2,param_3);
    uVar1 = FUN_0800aa50(auStack_824,0x7fe);
    local_25 = (undefined1)((ushort)uVar1 >> 8);
    local_26 = (undefined1)uVar1;
    iVar2 = FUN_0800a0ac(uVar3,auStack_824,0x800);
    if (iVar2 == 1) {
      *DAT_0800a0a8 = *DAT_0800a0a8 & 0xfe;
    }
    else {
      *DAT_0800a0a8 = (*DAT_0800a0a8 & 0xfe) + 1;
    }
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}



/* ===== FUN_0800a0ac @ 0x800A0AC ===== */

undefined4 FUN_0800a0ac(uint param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (((((param_1 & 0x7ff) == 0) && (param_2 != 0)) && (param_3 != 0)) &&
     (((param_3 < 0x801 &&
       (param_3 == ((int)(param_3 + ((uint)(param_3 >> 0x1f) >> 0x1e)) >> 2) * 4)) &&
      ((param_1 + param_3 < DAT_0800a158 && (DAT_0800a15c <= param_1)))))) {
    iVar1 = FUN_08009e98(param_1);
    if (iVar1 == 0) {
      uVar3 = 0;
    }
    else {
      FUN_08008378();
      for (uVar2 = 0; (int)uVar2 < param_3; uVar2 = uVar2 + 4 & 0xffff) {
        iVar1 = FUN_08008304(param_1,(uint)*(byte *)(param_2 + uVar2) +
                                     ((uint)*(byte *)(param_2 + uVar2 + 1) +
                                     ((uint)*(byte *)(param_2 + uVar2 + 2) +
                                     (uint)*(byte *)(param_2 + uVar2 + 3) * 0x100) * 0x100) * 0x100)
        ;
        if (iVar1 != 6) {
          uVar3 = 0;
          break;
        }
        param_1 = param_1 + 4;
        uVar3 = 1;
      }
      FUN_080082d4();
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* ===== FUN_0800a160 @ 0x800A160 ===== */

void FUN_0800a160(void)

{
  byte *pbVar1;
  
  pbVar1 = DAT_0800a1b0;
  if ((*DAT_0800a1a4 == 'd') && (*DAT_0800a1a8 == '\x01')) {
    *DAT_0800a1ac = 1;
    *DAT_0800a1b0 = 0;
  }
  else if ((*DAT_0800a1a4 != 'd') && (*DAT_0800a1b0 = *DAT_0800a1b0 + 1, 5 < *pbVar1)) {
    *DAT_0800a1ac = 0;
    *DAT_0800a1b0 = 0;
  }
  return;
}



/* ===== FUN_0800a1b4 @ 0x800A1B4 ===== */

void FUN_0800a1b4(void)

{
  byte *pbVar1;
  ushort *puVar2;
  int iVar3;
  
  iVar3 = FUN_0800a7c8(DAT_0800a298,0x4000);
  puVar2 = DAT_0800a2b0;
  pbVar1 = DAT_0800a2ac;
  if (iVar3 == 0) {
    if (((*(ushort *)(DAT_0800a29c + 0x34) < 0x79f) || (0x157b < *(ushort *)(DAT_0800a29c + 0x34)))
       || ((*DAT_0800a2a0 != '\0' && ((*DAT_0800a2a4 != '\x01' || (*DAT_0800a2a8 != '\x01')))))) {
      *DAT_0800a2ac = 0;
    }
    else {
      *DAT_0800a2ac = *DAT_0800a2ac + 1;
      if (0x3c < *pbVar1) {
        *pbVar1 = 0;
        *DAT_0800a2a4 = '\0';
        *(undefined4 *)(DAT_0800a298 + 0x18) = 0x4000;
      }
    }
    *DAT_0800a2b0 = 0;
  }
  else {
    if (*DAT_0800a2a0 == '\0') {
      *DAT_0800a2b0 = 0;
    }
    else {
      *DAT_0800a2b0 = *DAT_0800a2b0 + 1;
      if (300 < *puVar2) {
        *puVar2 = 0;
        *(undefined4 *)(DAT_0800a298 + 0x28) = 0x4000;
      }
    }
    *DAT_0800a2ac = 0;
  }
  iVar3 = FUN_0800a7c8(DAT_0800a298,0x4000);
  if (iVar3 == 0) {
    *(byte *)(DAT_0800a2b4 + 1) = *(byte *)(DAT_0800a2b4 + 1) & 0xfb;
  }
  else {
    *(byte *)(DAT_0800a2b4 + 1) = (*(byte *)(DAT_0800a2b4 + 1) & 0xfb) + 4;
  }
  return;
}



/* ===== FUN_0800a2b8 @ 0x800A2B8 ===== */

void FUN_0800a2b8(void)

{
  int iVar1;
  
  *DAT_0800a2e4 = 0;
  FUN_0800a468();
  iVar1 = FUN_0800a3e4();
  if (((iVar1 != DAT_0800a2e8) && (iVar1 != DAT_0800a2e8 + -1)) && (iVar1 != DAT_0800a2ec)) {
    *DAT_0800a2e4 = 1;
  }
  return;
}



/* ===== FUN_0800a2f0 @ 0x800A2F0 ===== */

void FUN_0800a2f0(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_0800a33c();
  if (iVar1 == 0) {
    FUN_0800a4fc();
    FUN_0800a434();
    FUN_0800a7da(DAT_0800a338,0x10);
    FUN_08012870(0x20);
    FUN_08012870((param_1 & 0xffffff) >> 0x10);
    FUN_08012870((param_1 & 0xffff) >> 8);
    FUN_08012870(param_1 & 0xff);
    FUN_0800a7de(DAT_0800a338,0x10);
    FUN_0800a434();
  }
  return;
}



/* ===== FUN_0800a33c @ 0x800A33C ===== */

undefined1 FUN_0800a33c(void)

{
  return *DAT_0800a344;
}



/* ===== FUN_0800a348 @ 0x800A348 ===== */

void FUN_0800a348(void)

{
  int iVar1;
  bool bVar2;
  undefined4 local_8;
  
  iVar1 = FUN_0800a33c();
  if (iVar1 == 0) {
    FUN_0800a7da(DAT_0800a37c,0x10);
    FUN_08012870(0xb9);
    FUN_0800a7de(DAT_0800a37c,0x10);
    local_8 = 0x1e;
    do {
      bVar2 = local_8 != 0;
      local_8 = local_8 + -1;
    } while (bVar2);
  }
  return;
}



/* ===== FUN_0800a380 @ 0x800A380 ===== */

undefined4 FUN_0800a380(undefined1 *param_1,uint param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  
  iVar2 = FUN_0800a33c();
  if (iVar2 == 0) {
    FUN_0800a7da(DAT_0800a3e0,0x10);
    FUN_08012870(3);
    FUN_08012870((param_2 & 0xffffff) >> 0x10);
    FUN_08012870((param_2 & 0xffff) >> 8);
    FUN_08012870(param_2 & 0xff);
    while (bVar4 = param_3 != 0, param_3 = param_3 + -1, bVar4) {
      uVar1 = FUN_08012870(0xff);
      *param_1 = uVar1;
      param_1 = param_1 + 1;
    }
    FUN_0800a7de(DAT_0800a3e0,0x10);
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* ===== FUN_0800a3e4 @ 0x800A3E4 ===== */

uint FUN_0800a3e4(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  FUN_0800a7da(DAT_0800a430,0x10);
  FUN_08012870(0x9f);
  iVar1 = FUN_08012870(0xff);
  iVar2 = FUN_08012870(0xff);
  uVar3 = FUN_08012870(0xff);
  FUN_0800a7de(DAT_0800a430,0x10);
  return iVar1 << 0x10 | iVar2 << 8 | uVar3;
}



/* ===== FUN_0800a434 @ 0x800A434 ===== */

void FUN_0800a434(void)

{
  uint uVar1;
  
  FUN_0800a7da(DAT_0800a464,0x10);
  FUN_08012870(5);
  do {
    uVar1 = FUN_08012870(0xff);
  } while ((uVar1 & 1) != 0);
  FUN_0800a7de(DAT_0800a464,0x10);
  return;
}



/* ===== FUN_0800a468 @ 0x800A468 ===== */

void FUN_0800a468(void)

{
  int iVar1;
  bool bVar2;
  undefined4 local_8;
  
  iVar1 = FUN_0800a33c();
  if (iVar1 == 0) {
    FUN_0800a7da(DAT_0800a49c,0x10);
    FUN_08012870(0xab);
    FUN_0800a7de(DAT_0800a49c,0x10);
    local_8 = 0x32;
    do {
      bVar2 = local_8 != 0;
      local_8 = local_8 + -1;
    } while (bVar2);
  }
  return;
}



/* ===== FUN_0800a4a0 @ 0x800A4A0 ===== */

undefined4 FUN_0800a4a0(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  
  FUN_0800a33c();
  if (param_1 == 0) {
    uVar1 = 0;
  }
  else if ((int)param_3 < 0x801) {
    uVar2 = 0x100 - (param_2 & 0xff);
    if ((int)param_3 <= (int)uVar2) {
      uVar2 = param_3;
    }
    while (FUN_0800a51c(param_1,param_2,uVar2), param_3 != uVar2) {
      param_1 = param_1 + uVar2;
      param_2 = param_2 + uVar2;
      param_3 = param_3 - uVar2 & 0xffff;
      uVar2 = param_3;
      if (0x100 < param_3) {
        uVar2 = 0x100;
      }
    }
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* ===== FUN_0800a4fc @ 0x800A4FC ===== */

void FUN_0800a4fc(void)

{
  FUN_0800a7da(DAT_0800a518,0x10);
  FUN_08012870(6);
  FUN_0800a7de(DAT_0800a518,0x10);
  return;
}



/* ===== FUN_0800a51c @ 0x800A51C ===== */

void FUN_0800a51c(undefined1 *param_1,uint param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = FUN_0800a33c();
  if (iVar1 == 0) {
    FUN_0800a4fc();
    FUN_0800a434();
    FUN_0800a7da(DAT_0800a584,0x10);
    FUN_08012870(2);
    FUN_08012870((param_2 & 0xffffff) >> 0x10);
    FUN_08012870((param_2 & 0xffff) >> 8);
    FUN_08012870(param_2 & 0xff);
    while (bVar2 = param_3 != 0, param_3 = param_3 + -1, bVar2) {
      FUN_08012870(*param_1);
      param_1 = param_1 + 1;
    }
    FUN_0800a7de(DAT_0800a584,0x10);
    FUN_0800a434();
  }
  return;
}



/* ===== FUN_0800a588 @ 0x800A588 ===== */

void FUN_0800a588(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_0800a5c4;
  iVar2 = (int)param_2 >> 2;
  *(uint *)(DAT_0800a5c4 + iVar2 * 4) =
       *(uint *)(DAT_0800a5c4 + iVar2 * 4) & ~(3 << ((param_2 & 3) << 2));
  *(uint *)(DAT_0800a5c4 + iVar2 * 4) =
       param_1 << ((param_2 & 3) << 2) | *(uint *)(iVar1 + iVar2 * 4);
  return;
}



/* ===== FUN_0800a5c8 @ 0x800A5C8 ===== */

uint FUN_0800a5c8(uint *param_1,ushort *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0;
  for (uVar4 = 0; (int)(uint)*param_2 >> (uVar4 & 0xff) != 0; uVar4 = uVar4 + 1) {
    if (((uint)*param_2 & 1 << (uVar4 & 0xff)) != 0) {
      uVar3 = uVar4 << 1;
      if ((((*(int *)(param_2 + 4) == 2) || (*(int *)(param_2 + 4) == 0x12)) ||
          (*(int *)(param_2 + 4) == 0)) || (*(int *)(param_2 + 4) == 3)) {
        if ((uVar4 & 8) == 0) {
          param_1[8] = param_1[8] & ~(0xf << ((uVar4 & 7) << 2)) |
                       *(int *)(param_2 + 6) << ((uVar4 & 7) << 2);
        }
        else {
          param_1[9] = param_1[9] & ~(0xf << ((uVar4 & 7) << 2)) |
                       *(int *)(param_2 + 6) << ((uVar4 & 7) << 2);
        }
      }
      *param_1 = *param_1 & ~(3 << (uVar3 & 0xff)) | ((byte)param_2[4] & 0xf) << (uVar3 & 0xff);
      param_1[3] = param_1[3] & ~(3 << (uVar3 & 0xff)) | ((byte)param_2[2] & 3) << (uVar3 & 0xff);
      if (((param_2[4] & 3) != 0) && (*(int *)(param_2 + 4) != 3)) {
        param_1[0xb] = param_1[0xb] & ~(3 << (uVar3 & 0xff)) |
                       ((byte)param_2[1] & 3) << (uVar3 & 0xff);
      }
      uVar3 = param_1[2] & ~(1 << (uVar4 & 0xff)) |
              (*(byte *)((int)param_2 + 3) & 1) << (uVar4 & 0xff);
      param_1[2] = uVar3;
      if ((char)param_2[2] == '\x02') {
        param_1[10] = param_1[10] | 1 << (uVar4 & 0xff);
      }
      else if ((char)param_2[2] == '\x01') {
        param_1[6] = param_1[6] | 1 << (uVar4 & 0xff);
      }
      if (((*(int *)(param_2 + 4) == 1) || (*(int *)(param_2 + 4) == 2)) ||
         ((*(int *)(param_2 + 4) == 0x11 || (*(int *)(param_2 + 4) == 0x12)))) {
        uVar3 = param_1[1] & ~(1 << (uVar4 & 0xff)) |
                (((byte)param_2[4] & 0x1f) >> 4) << (uVar4 & 0xff);
        param_1[1] = uVar3;
      }
      puVar1 = DAT_0800a7ac;
      if ((*(uint *)(param_2 + 4) & 0x10000000) != 0) {
        uVar3 = *DAT_0800a7ac & ~(1 << (uVar4 & 0xff));
        if ((*(uint *)(param_2 + 4) & 0x10000) == 0x10000) {
          uVar3 = uVar3 | 1 << (uVar4 & 0xff);
        }
        *DAT_0800a7ac = uVar3;
        puVar2 = DAT_0800a7ac;
        uVar3 = puVar1[1] & ~(1 << (uVar4 & 0xff));
        if ((*(uint *)(param_2 + 4) & 0x20000) == 0x20000) {
          uVar3 = uVar3 | 1 << (uVar4 & 0xff);
        }
        DAT_0800a7ac[1] = uVar3;
        puVar1 = DAT_0800a7ac;
        uVar3 = puVar2[2] & ~(1 << (uVar4 & 0xff));
        if ((*(uint *)(param_2 + 4) & 0x100000) == 0x100000) {
          uVar3 = uVar3 | 1 << (uVar4 & 0xff);
        }
        DAT_0800a7ac[2] = uVar3;
        uVar3 = puVar1[3] & ~(1 << (uVar4 & 0xff));
        if ((*(uint *)(param_2 + 4) & 0x200000) == 0x200000) {
          uVar3 = uVar3 | 1 << (uVar4 & 0xff);
        }
        DAT_0800a7ac[3] = uVar3;
      }
    }
  }
  return uVar3;
}



/* ===== FUN_0800a7b0 @ 0x800A7B0 ===== */

void FUN_0800a7b0(undefined2 *param_1)

{
  *param_1 = 0xffff;
  *(undefined1 *)((int)param_1 + 3) = 0;
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 6) = 0xf;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}



/* ===== FUN_0800a7c8 @ 0x800A7C8 ===== */

bool FUN_0800a7c8(int param_1,uint param_2)

{
  return (*(uint *)(param_1 + 0x10) & param_2) != 0;
}



/* ===== FUN_0800a7da @ 0x800A7DA ===== */

void FUN_0800a7da(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x28) = param_2;
  return;
}



/* ===== FUN_0800a7de @ 0x800A7DE ===== */

void FUN_0800a7de(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  return;
}



/* ===== FUN_0800a7e2 @ 0x800A7E2 ===== */

void FUN_0800a7e2(int param_1,undefined4 param_2,int param_3)

{
  if (param_3 == 0) {
    *(undefined4 *)(param_1 + 0x28) = param_2;
  }
  else {
    *(undefined4 *)(param_1 + 0x18) = param_2;
  }
  return;
}



/* ===== FUN_0800a7ec @ 0x800A7EC ===== */

undefined1 FUN_0800a7ec(void)

{
  return *DAT_0800a7f4;
}



/* ===== FUN_0800a7f8 @ 0x800A7F8 ===== */

void FUN_0800a7f8(byte *param_1,uint param_2)

{
  byte *pbVar1;
  byte bVar2;
  char cVar3;
  bool bVar4;
  
  bVar2 = 0;
  while (bVar4 = param_2 != 0, param_2 = param_2 - 1 & 0xff, bVar4) {
    pbVar1 = param_1 + 1;
    bVar2 = bVar2 ^ *param_1;
    for (cVar3 = '\b'; param_1 = pbVar1, cVar3 != '\0'; cVar3 = cVar3 + -1) {
      if ((bVar2 & 0x80) == 0) {
        bVar2 = bVar2 << 1;
      }
      else {
        bVar2 = bVar2 << 1 ^ 0x2f;
      }
    }
  }
  return;
}



/* ===== FUN_0800a834 @ 0x800A834 ===== */

undefined4 FUN_0800a834(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((((*DAT_0800a868 == '\x01') && (*DAT_0800a86c == '\x01')) &&
      (iVar1 = FUN_0800c6a4(), iVar1 != 1)) &&
     ((*DAT_0800a870 != '\x01' && (*DAT_0800a874 != '\x01')))) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* ===== FUN_0800a878 @ 0x800A878 ===== */

undefined1 FUN_0800a878(void)

{
  return *DAT_0800a880;
}



/* ===== FUN_0800a884 @ 0x800A884 ===== */

void FUN_0800a884(void)

{
  int iVar1;
  byte local_804;
  byte local_803;
  undefined1 auStack_800 [2044];
  
  FUN_080031d6(&local_804,0x800);
  iVar1 = FUN_08009ee8(0,&local_804,0x800);
  if (iVar1 == 1) {
    FUN_080031a4(DAT_0800a92c,auStack_800,0x54);
    *DAT_0800a930 = (ushort)local_804 + (ushort)local_803 * 0x100;
    *DAT_0800a934 = *DAT_0800a934 & 0xfb;
  }
  else {
    iVar1 = FUN_08009ee8(0,&local_804,0x800);
    if (iVar1 == 1) {
      FUN_080031a4(DAT_0800a92c,auStack_800,0x54);
      *DAT_0800a930 = (ushort)local_804 + (ushort)local_803 * 0x100;
      FUN_08009fdc(0,&local_804,0x7fe,1);
      *DAT_0800a934 = *DAT_0800a934 & 0xfb;
    }
    else {
      *DAT_0800a934 = (*DAT_0800a934 & 0xfb) + 4;
      *DAT_0800a930 = 0;
    }
  }
  return;
}



/* ===== FUN_0800a938 @ 0x800A938 ===== */

int FUN_0800a938(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  undefined4 local_28;
  undefined4 local_24;
  
  iVar5 = 0;
  iVar6 = 0;
  local_28 = param_3;
  local_24 = param_4;
  FUN_0800aa90(&local_28);
  puVar1 = DAT_0800aa3c;
  *DAT_0800aa3c = local_28;
  *(undefined2 *)(puVar1 + 1) = (undefined2)local_24;
  *(undefined1 *)((int)puVar1 + 6) = local_24._2_1_;
  for (uVar4 = 2000; uVar4 < *(byte *)((int)puVar1 + 5) + 2000; uVar4 = uVar4 + 1 & 0xffff) {
    if ((uVar4 == ((int)uVar4 >> 2) * 4) &&
       ((uVar4 != (uVar4 / 100) * 100 || (uVar4 == (uVar4 / 400) * 400)))) {
      iVar5 = iVar5 + 0x2250;
    }
    else {
      iVar5 = iVar5 + 0x2238;
    }
  }
  for (uVar4 = 2000; uVar4 < *DAT_0800aa40; uVar4 = uVar4 + 1 & 0xffff) {
    if ((uVar4 == ((int)uVar4 >> 2) * 4) &&
       ((uVar4 != (uVar4 / 100) * 100 || (uVar4 == (uVar4 / 400) * 400)))) {
      iVar6 = iVar6 + 0x2250;
    }
    else {
      iVar6 = iVar6 + 0x2238;
    }
  }
  iVar2 = FUN_0801847c(*(byte *)((int)DAT_0800aa3c + 5) + 2000,*(undefined1 *)(DAT_0800aa3c + 1),
                       *(undefined1 *)((int)DAT_0800aa3c + 3),*(undefined1 *)((int)DAT_0800aa3c + 2)
                      );
  iVar3 = FUN_0801847c(*DAT_0800aa40,(char)DAT_0800aa40[1],*(undefined1 *)((int)DAT_0800aa40 + 3),
                       (char)DAT_0800aa40[2]);
  if ((uint)(iVar3 + iVar6) < (uint)(iVar2 + iVar5)) {
    iVar5 = (iVar2 + iVar5) - (iVar3 + iVar6);
  }
  else {
    iVar5 = 0;
  }
  return iVar5;
}



/* ===== FUN_0800aa44 @ 0x800AA44 ===== */

undefined4 FUN_0800aa44(void)

{
  return *(undefined4 *)(DAT_0800aa4c + 6);
}



/* ===== FUN_0800aa50 @ 0x800AA50 ===== */

uint FUN_0800aa50(byte *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = 0xff;
  uVar3 = 0xff;
  for (; param_2 != 0; param_2 = param_2 - 1 & 0xffff) {
    uVar2 = *param_1 ^ uVar1;
    uVar1 = *(byte *)(DAT_0800aa88 + uVar2) ^ uVar3;
    uVar3 = (uint)*(byte *)(DAT_0800aa8c + uVar2);
    param_1 = param_1 + 1;
  }
  return uVar1 << 8 | uVar3;
}



/* ===== FUN_0800aa90 @ 0x800AA90 ===== */

ulonglong FUN_0800aa90(undefined4 *param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = param_3;
  local_c = param_4;
  FUN_0800ec1c(0,&local_c,param_3,param_4,(char)param_1,param_2);
  FUN_0800ecbc(0,&local_10);
  *param_1 = CONCAT13(local_c._2_1_,
                      CONCAT12((undefined1)local_10,CONCAT11(local_10._1_1_,local_10._2_1_)));
  *(ushort *)(param_1 + 1) = CONCAT11(local_c._3_1_,local_c._1_1_);
  *(undefined1 *)((int)param_1 + 6) = (undefined1)local_c;
  return (ulonglong)
         CONCAT16((undefined1)local_c,
                  CONCAT15(local_c._3_1_,
                           CONCAT14(local_c._1_1_,
                                    CONCAT13(local_c._2_1_,
                                             CONCAT12((undefined1)local_10,
                                                      CONCAT11(local_10._1_1_,local_10._2_1_))))));
}



/* ===== FUN_0800aaf0 @ 0x800AAF0 ===== */

undefined1 FUN_0800aaf0(void)

{
  return *DAT_0800aaf8;
}



/* ===== FUN_0800aafc @ 0x800AAFC ===== */

void FUN_0800aafc(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0800418c();
  *(undefined4 *)(DAT_0800ab0c + 0xd) = uVar1;
  return;
}



/* ===== FUN_0800ab10 @ 0x800AB10 ===== */

void FUN_0800ab10(void)

{
  ushort *puVar1;
  char cVar2;
  ushort uVar3;
  
  uVar3 = FUN_0800370c(0);
  puVar1 = DAT_0800ab48;
  *DAT_0800ab48 = uVar3;
  cVar2 = FUN_08014804((uint)*puVar1 * 0xce4 >> 0xc);
  *(char *)(DAT_0800ab50 + 1) = cVar2 + *DAT_0800ab4c;
  *DAT_0800ab54 = 0;
  return;
}



/* ===== FUN_0800ab58 @ 0x800AB58 ===== */

void FUN_0800ab58(void)

{
  ushort *puVar1;
  char cVar2;
  ushort uVar3;
  
  uVar3 = FUN_0800370c(1);
  puVar1 = DAT_0800ab8c;
  *DAT_0800ab8c = uVar3;
  cVar2 = FUN_08014804((uint)*puVar1 * 0xce4 >> 0xc);
  *(char *)(DAT_0800ab94 + 8) = cVar2 + *DAT_0800ab90;
  return;
}



/* ===== FUN_0800ab98 @ 0x800AB98 ===== */

undefined4 FUN_0800ab98(void)

{
  return *(undefined4 *)(DAT_0800aba0 + 0x27);
}



/* ===== FUN_0800aba4 @ 0x800ABA4 ===== */

undefined4 FUN_0800aba4(void)

{
  return *(undefined4 *)(DAT_0800abac + 8);
}



/* ===== FUN_0800abb0 @ 0x800ABB0 ===== */

undefined4 FUN_0800abb0(void)

{
  return *(undefined4 *)(DAT_0800abb8 + 0xc);
}



/* ===== FUN_0800abbc @ 0x800ABBC ===== */

undefined4 FUN_0800abbc(void)

{
  return *(undefined4 *)(DAT_0800abc4 + 0x11);
}



/* ===== FUN_0800abc8 @ 0x800ABC8 ===== */

undefined2 FUN_0800abc8(void)

{
  return *(undefined2 *)(DAT_0800abd0 + 0x15);
}



/* ===== FUN_0800abd4 @ 0x800ABD4 ===== */

undefined2 FUN_0800abd4(void)

{
  return *(undefined2 *)(DAT_0800abdc + 0x18);
}



/* ===== FUN_0800abe0 @ 0x800ABE0 ===== */

undefined1 FUN_0800abe0(void)

{
  return *(undefined1 *)(DAT_0800abe8 + 0x1a);
}



/* ===== FUN_0800abec @ 0x800ABEC ===== */

void FUN_0800abec(void)

{
  short sVar1;
  undefined2 *puVar2;
  int iVar3;
  uint uVar4;
  
  if ((int)((uint)*(byte *)(DAT_0800ad70 + 3) << 0x1d) < 0) {
    *DAT_0800ad74 = (*DAT_0800ad74 & 0xfe) + 1;
    for (uVar4 = 0; uVar4 < 0xd; uVar4 = uVar4 + 1 & 0xff) {
      DAT_0800ad78[uVar4] = 0x9c4;
    }
  }
  else {
    iVar3 = FUN_0800aaf0();
    if (iVar3 != 0) {
      *DAT_0800ad74 = *DAT_0800ad74 & 0xfe;
      puVar2 = DAT_0800ad78;
      *DAT_0800ad78 = *(undefined2 *)(DAT_0800ad7c + 0x12);
      puVar2[1] = *(undefined2 *)(DAT_0800ad7c + 0x14);
      puVar2[2] = *(undefined2 *)(DAT_0800ad7c + 0x16);
      puVar2[3] = *(undefined2 *)(DAT_0800ad7c + 0x18);
      puVar2[4] = *(undefined2 *)(DAT_0800ad7c + 0x1a);
      puVar2[5] = *(undefined2 *)(DAT_0800ad7c + 0x1c);
      puVar2[6] = *(undefined2 *)(DAT_0800ad7c + 0x1e);
      puVar2[7] = *(undefined2 *)(DAT_0800ad7c + 0x20);
      puVar2[8] = *(undefined2 *)(DAT_0800ad7c + 0x22);
      puVar2[9] = *(undefined2 *)(DAT_0800ad7c + 0x24);
      puVar2[10] = *(undefined2 *)(DAT_0800ad7c + 0x26);
      puVar2[0xb] = *(undefined2 *)(DAT_0800ad7c + 0x28);
      puVar2[0xc] = *(undefined2 *)(DAT_0800ad7c + 0x2a);
    }
  }
  if ((int)((uint)*(byte *)(DAT_0800ad70 + 3) << 0x1d) < 0) {
    *DAT_0800ad74 = (*DAT_0800ad74 & 0xfd) + 2;
  }
  else {
    *DAT_0800ad74 = *DAT_0800ad74 & 0xfd;
    *DAT_0800ad80 = *(short *)(DAT_0800ad7c + 0x38) * 10;
  }
  if (*DAT_0800ad80 < 1) {
    iVar3 = -*DAT_0800ad80;
  }
  else {
    iVar3 = *DAT_0800ad80;
  }
  if (iVar3 < 0xb) {
    *DAT_0800ad80 = 0;
  }
  if (*DAT_0800ad80 < 0) {
    DAT_0800ad80[1] = -*DAT_0800ad80;
  }
  else {
    DAT_0800ad80[1] = *DAT_0800ad80;
  }
  if ((int)((uint)*(byte *)(DAT_0800ad70 + 3) << 0x1d) < 0) {
    *DAT_0800ad74 = (*DAT_0800ad74 & 0xfb) + 4;
    *DAT_0800ad84 = 0x19;
    *DAT_0800ad88 = 0xfa;
  }
  else {
    iVar3 = FUN_0800aaf0();
    if (iVar3 != 0) {
      *DAT_0800ad74 = *DAT_0800ad74 & 0xfb;
      sVar1 = *(short *)(DAT_0800ad7c + 0x48);
      *DAT_0800ad88 = *(short *)(DAT_0800ad7c + 0x48) + -0xaaf;
      *DAT_0800ad84 = (char)((sVar1 + -0xaaf) / 10);
    }
  }
  *DAT_0800ad8c = (char)((*(short *)(DAT_0800ad7c + 0x40) + -0xaaf) / 10);
  return;
}



/* ===== FUN_0800ad90 @ 0x800AD90 ===== */

undefined4 FUN_0800ad90(void)

{
  return *DAT_0800ad98;
}



/* ===== FUN_0800ad9c @ 0x800AD9C ===== */

undefined2 FUN_0800ad9c(void)

{
  return *(undefined2 *)(DAT_0800ada4 + 0x13);
}



/* ===== FUN_0800ada8 @ 0x800ADA8 ===== */

undefined2 FUN_0800ada8(void)

{
  return *(undefined2 *)(DAT_0800adb0 + 0x10);
}



/* ===== FUN_0800adb4 @ 0x800ADB4 ===== */

undefined4 FUN_0800adb4(void)

{
  return *(undefined4 *)(DAT_0800adbc + 4);
}



/* ===== FUN_0800adc0 @ 0x800ADC0 ===== */

undefined4 FUN_0800adc0(void)

{
  return *(undefined4 *)(DAT_0800adc8 + 8);
}



/* ===== FUN_0800adcc @ 0x800ADCC ===== */

undefined4 FUN_0800adcc(void)

{
  return *(undefined4 *)(DAT_0800add4 + 0xc);
}



/* ===== FUN_0800add8 @ 0x800ADD8 ===== */

undefined1 FUN_0800add8(void)

{
  return *(undefined1 *)(DAT_0800ade0 + 0x12);
}



/* ===== FUN_0800ade4 @ 0x800ADE4 ===== */

undefined1 FUN_0800ade4(void)

{
  if ((*DAT_0800ae08 == '\x01') || (*DAT_0800ae0c == '\x01')) {
    *(undefined1 *)(DAT_0800ae10 + 4) = 1;
  }
  else {
    *(undefined1 *)(DAT_0800ae10 + 4) = 0;
  }
  return *(undefined1 *)(DAT_0800ae10 + 4);
}



/* ===== FUN_0800ae14 @ 0x800AE14 ===== */

undefined1 FUN_0800ae14(void)

{
  return *(undefined1 *)(DAT_0800ae1c + 0x1f);
}



/* ===== FUN_0800ae20 @ 0x800AE20 ===== */

undefined1 FUN_0800ae20(void)

{
  return *(undefined1 *)(DAT_0800ae28 + 0x24);
}



/* ===== FUN_0800ae2c @ 0x800AE2C ===== */

undefined1 FUN_0800ae2c(void)

{
  return *(undefined1 *)(DAT_0800ae34 + 0x10);
}



/* ===== FUN_0800ae38 @ 0x800AE38 ===== */

undefined1 FUN_0800ae38(void)

{
  return *(undefined1 *)(DAT_0800ae40 + 7);
}



/* ===== FUN_0800ae44 @ 0x800AE44 ===== */

undefined1 FUN_0800ae44(void)

{
  return *(undefined1 *)(DAT_0800ae4c + 0x17);
}



/* ===== FUN_0800ae50 @ 0x800AE50 ===== */

int FUN_0800ae50(void)

{
  short *psVar1;
  
  psVar1 = DAT_0800ae6c;
  *DAT_0800ae6c = ((short)*(char *)(DAT_0800ae68 + 2) + *(char *)(DAT_0800ae68 + 2) * 4) * 2;
  return (int)*psVar1;
}



/* ===== FUN_0800ae70 @ 0x800AE70 ===== */

int FUN_0800ae70(void)

{
  int iVar1;
  
  iVar1 = DAT_0800ae8c;
  *(short *)(DAT_0800ae8c + 2) =
       ((short)*(char *)(DAT_0800ae88 + 1) + *(char *)(DAT_0800ae88 + 1) * 4) * 2;
  return (int)*(short *)(iVar1 + 2);
}



/* ===== FUN_0800ae90 @ 0x800AE90 ===== */

undefined1 FUN_0800ae90(void)

{
  return *DAT_0800ae98;
}



/* ===== FUN_0800ae9c @ 0x800AE9C ===== */

undefined2 FUN_0800ae9c(void)

{
  int iVar1;
  
  iVar1 = DAT_0800aeb0;
  *(undefined2 *)(DAT_0800aeb0 + 0x25) = 0x398;
  return *(undefined2 *)(iVar1 + 0x25);
}



/* ===== FUN_0800aeb4 @ 0x800AEB4 ===== */

undefined4 FUN_0800aeb4(void)

{
  int iVar1;
  
  iVar1 = DAT_0800aec8;
  *(undefined4 *)(DAT_0800aec8 + 0x20) = *DAT_0800aec4;
  return *(undefined4 *)(iVar1 + 0x20);
}



/* ===== FUN_0800aecc @ 0x800AECC ===== */

undefined2 FUN_0800aecc(void)

{
  int iVar1;
  
  iVar1 = DAT_0800aee4;
  *(undefined2 *)(DAT_0800aee4 + 1) = *(undefined2 *)(DAT_0800aee0 + 8);
  return *(undefined2 *)(iVar1 + 1);
}



/* ===== FUN_0800aee8 @ 0x800AEE8 ===== */

undefined2 FUN_0800aee8(void)

{
  int iVar1;
  
  iVar1 = DAT_0800af00;
  *(undefined2 *)(DAT_0800af00 + 3) = *(undefined2 *)(DAT_0800aefc + 6);
  return *(undefined2 *)(iVar1 + 3);
}



/* ===== FUN_0800af04 @ 0x800AF04 ===== */

undefined2 FUN_0800af04(void)

{
  int iVar1;
  
  iVar1 = DAT_0800af14;
  *(undefined2 *)(DAT_0800af14 + 0x10) = 0x1068;
  return *(undefined2 *)(iVar1 + 0x10);
}



/* ===== FUN_0800af18 @ 0x800AF18 ===== */

int FUN_0800af18(void)

{
  return (int)*DAT_0800af20;
}



/* ===== FUN_0800af24 @ 0x800AF24 ===== */

undefined4 FUN_0800af24(void)

{
  int iVar1;
  
  iVar1 = DAT_0800af3c;
  *(undefined4 *)(DAT_0800af3c + 0x1b) = *DAT_0800af38;
  return *(undefined4 *)(iVar1 + 0x1b);
}



/* ===== FUN_0800af40 @ 0x800AF40 ===== */

undefined2 FUN_0800af40(void)

{
  int iVar1;
  
  iVar1 = DAT_0800af54;
  *(undefined2 *)(DAT_0800af54 + 0xe) = *(undefined2 *)(DAT_0800af50 + 0x3f);
  return *(undefined2 *)(iVar1 + 0xe);
}



/* ===== FUN_0800af58 @ 0x800AF58 ===== */

int FUN_0800af58(void)

{
  int iVar1;
  
  iVar1 = DAT_0800af78;
  *(short *)(DAT_0800af78 + 5) = (short)*(char *)(DAT_0800af74 + 1);
  return (int)*(short *)(iVar1 + 5);
}



/* ===== FUN_0800af7c @ 0x800AF7C ===== */

undefined4 FUN_0800af7c(undefined4 param_1,char param_2,undefined4 param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  byte bVar5;
  uint uVar6;
  byte abStack_6d [73];
  
  FUN_080031d6(abStack_6d + 1,0x48);
  uVar6 = (param_5 & 0x7f) * 2;
  if (uVar6 < 0x47) {
    bVar5 = param_2 << 1;
    uVar1 = FUN_08005c7c(bVar5,0);
    uVar1 = FUN_08005c7c(param_3,uVar1);
    uVar1 = FUN_08005c7c(bVar5 | 1,uVar1);
    iVar2 = (**(code **)(DAT_0800b044 + 0x118))(bVar5,param_3,1,abStack_6d + 1,uVar6,DAT_0800b044);
    if (iVar2 == 0) {
      for (uVar4 = 0; uVar4 < uVar6; uVar4 = uVar4 + 1 & 0xff) {
        if (uVar4 == (uVar4 / 2) * 2) {
          *(byte *)(param_4 + uVar4 / 2) = abStack_6d[uVar4 + 1];
        }
        else {
          uVar3 = FUN_08005c7c(abStack_6d[uVar4],uVar1);
          if (abStack_6d[uVar4 + 1] != uVar3) {
            return 0;
          }
          uVar1 = 0;
        }
      }
      uVar1 = 1;
    }
    else {
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}



/* ===== FUN_0800b048 @ 0x800B048 ===== */

bool FUN_0800b048(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint param_5
                 )

{
  int iVar1;
  uint uVar2;
  undefined1 auStack_40 [40];
  
  FUN_080031d6(auStack_40,0x28);
  uVar2 = (param_2 & 0x7fff) << 1;
  FUN_08017640(uVar2,param_3,param_4,auStack_40,param_5);
  iVar1 = (**(code **)(DAT_0800b09c + 0x11c))
                    (uVar2 & 0xff,param_3,1,auStack_40,(param_5 & 0x7f) << 1,DAT_0800b09c);
  return iVar1 == 0;
}



/* ===== FUN_0800b0a0 @ 0x800B0A0 ===== */

undefined4
FUN_0800b0a0(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_1 == DAT_0800b128) {
    bVar1 = *DAT_0800b12c >> 4;
  }
  else {
    bVar1 = *DAT_0800b12c & 0xf;
  }
  if (bVar1 == 0) {
    FUN_08012a28(param_1,3,param_3,param_4,param_4);
    FUN_08004d1c();
    iVar3 = FUN_08004e84(param_1,(param_2 & 0x7f) << 1,param_3,param_4,param_5);
    FUN_08004d34();
    FUN_08012a28(param_1,1);
    if (iVar3 == 0) {
      FUN_0800b74c(param_1,0);
      uVar2 = 1;
    }
    else {
      FUN_0800b74c(param_1,1);
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}



/* ===== hard_fault_Handler @ 0x800B130 ===== */

void hard_fault_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_0800b132 @ 0x800B132 ===== */

void FUN_0800b132(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_0800b134 @ 0x800B134 ===== */

void FUN_0800b134(void)

{
  byte *pbVar1;
  
  if (((int)((uint)*(byte *)(DAT_0800b3e0 + 3) << 0x1d) < 0) &&
     (-1 < (int)((uint)*(byte *)(DAT_0800b3e4 + 0xc) << 0x1b))) {
    if ((-1 < (int)((uint)(ushort)*DAT_0800b3e8 << 0x15)) &&
       (-1 < (int)((uint)*(byte *)(DAT_0800b3e4 + 0xc) << 0x1b))) {
      *DAT_0800b3e8 = *DAT_0800b3e8 | 0x400;
      *(short *)(DAT_0800b3e4 + 0x15) = *(short *)(DAT_0800b3e4 + 0x15) + 1;
    }
    *(byte *)(DAT_0800b3e4 + 0xc) = (*(byte *)(DAT_0800b3e4 + 0xc) & 0xef) + 0x10;
    FUN_08003bdc(0x93);
  }
  if ((int)((uint)*(byte *)(DAT_0800b3e0 + 3) << 0x1c) < 0) {
    *(byte *)(DAT_0800b3e4 + 0x17) = (*(byte *)(DAT_0800b3e4 + 0x17) & 0xfe) + 1;
    FUN_08003bdc(0x94);
  }
  pbVar1 = DAT_0800b3ec;
  if (((int)((uint)*(byte *)(DAT_0800b3e0 + 0x11) << 0x1d) < 0) &&
     (-1 < (int)((uint)*(byte *)(DAT_0800b3e4 + 0xc) << 0x1e))) {
    *DAT_0800b3ec = *DAT_0800b3ec + 1;
    if (0x14 < *pbVar1) {
      *(byte *)(DAT_0800b3e4 + 0xc) = (*(byte *)(DAT_0800b3e4 + 0xc) & 0xfd) + 2;
      *DAT_0800b3ec = 0;
      FUN_08003bdc(0x94);
    }
  }
  else {
    *DAT_0800b3ec = 0;
  }
  if ((int)((uint)*(byte *)(DAT_0800b3e0 + 3) << 0x1b) < 0) {
    *DAT_0800b3f0 = (*DAT_0800b3f0 & 0xfb) + 4;
  }
  if (((int)((uint)*(byte *)(DAT_0800b3e0 + 3) << 0x19) < 0) &&
     (-1 < (int)((uint)*(byte *)(DAT_0800b3f4 + 8) << 0x1a))) {
    *(byte *)(DAT_0800b3f4 + 8) = (*(byte *)(DAT_0800b3f4 + 8) & 0xdf) + 0x20;
    FUN_08003bdc(0x93);
  }
  if (*(char *)(DAT_0800b3e0 + 7) < '\0') {
    *DAT_0800b3f0 = (*DAT_0800b3f0 & 0xf7) + 8;
  }
  else {
    *DAT_0800b3f0 = *DAT_0800b3f0 & 0xf7;
  }
  if ((*(char *)(DAT_0800b3e0 + 3) < '\0') &&
     (-1 < (int)((uint)*(byte *)(DAT_0800b3f4 + 8) << 0x19))) {
    *DAT_0800b3e8 = *DAT_0800b3e8 | 0x800;
    *(byte *)(DAT_0800b3f4 + 8) = (*(byte *)(DAT_0800b3f4 + 8) & 0xbf) + 0x40;
    FUN_08003bdc(0x93);
  }
  if ((((*(byte *)(DAT_0800b3e0 + 5) & 1) == 0) ||
      ((int)((uint)*(byte *)(DAT_0800b3f8 + 6) << 0x1e) < 0)) || (*DAT_0800b3fc != '\x01')) {
    if ((*(byte *)(DAT_0800b3e0 + 5) & 1) == 0) {
      *DAT_0800b3f0 = *DAT_0800b3f0 & 0xbf;
    }
  }
  else {
    *(byte *)(DAT_0800b3f8 + 6) = (*(byte *)(DAT_0800b3f8 + 6) & 0xfd) + 2;
    *DAT_0800b3f0 = (*DAT_0800b3f0 & 0xbf) + 0x40;
  }
  if (((int)((uint)*(byte *)(DAT_0800b3e0 + 5) << 0x1e) < 0) &&
     (-1 < (int)((uint)*(byte *)(DAT_0800b3f8 + 6) << 0x1a))) {
    *(byte *)(DAT_0800b3f8 + 6) = (*(byte *)(DAT_0800b3f8 + 6) & 0xdf) + 0x20;
    *DAT_0800b3f0 = (*DAT_0800b3f0 & 0x7f) + 0x80;
  }
  else if (-1 < (int)((uint)*(byte *)(DAT_0800b3e0 + 5) << 0x1e)) {
    *DAT_0800b3f0 = *DAT_0800b3f0 & 0x7f;
  }
  if ((((int)((uint)*(byte *)(DAT_0800b3e0 + 5) << 0x1b) < 0) &&
      ((*(byte *)(DAT_0800b3f8 + 6) & 1) == 0)) && (*DAT_0800b3fc == '\x01')) {
    *(byte *)(DAT_0800b3f8 + 6) = (*(byte *)(DAT_0800b3f8 + 6) & 0xfe) + 1;
    DAT_0800b3f0[1] = (DAT_0800b3f0[1] & 0xfe) + 1;
  }
  else if (-1 < (int)((uint)*(byte *)(DAT_0800b3e0 + 5) << 0x1b)) {
    DAT_0800b3f0[1] = DAT_0800b3f0[1] & 0xfe;
  }
  if (((int)((uint)*(byte *)(DAT_0800b3e0 + 5) << 0x1a) < 0) &&
     (-1 < (int)((uint)*(byte *)(DAT_0800b3f8 + 6) << 0x1c))) {
    *(byte *)(DAT_0800b3f8 + 6) = (*(byte *)(DAT_0800b3f8 + 6) & 0xf7) + 8;
    DAT_0800b3f0[1] = (DAT_0800b3f0[1] & 0xfd) + 2;
  }
  else if (-1 < (int)((uint)*(byte *)(DAT_0800b3e0 + 5) << 0x1a)) {
    DAT_0800b3f0[1] = DAT_0800b3f0[1] & 0xfd;
  }
  if (*(char *)(DAT_0800b3e0 + 5) < '\0') {
    DAT_0800b3f0[1] = (DAT_0800b3f0[1] & 0xfb) + 4;
  }
  else {
    DAT_0800b3f0[1] = DAT_0800b3f0[1] & 0xfb;
  }
  return;
}



/* ===== FUN_0800b400 @ 0x800B400 ===== */

bool FUN_0800b400(void)

{
  return ((int)((uint)*(byte *)(DAT_0800b434 + 3) << 0x1c |
               (uint)*(byte *)(DAT_0800b434 + 3) << 0x1b) < 0 ||
         (*(byte *)(DAT_0800b434 + 5) & 1) != 0) ||
         (int)((uint)*(byte *)(DAT_0800b434 + 5) << 0x1b) < 0;
}



/* ===== FUN_0800b438 @ 0x800B438 ===== */

bool FUN_0800b438(void)

{
  return ((((int)((uint)*(byte *)(DAT_0800b47c + 3) << 0x1d |
                 (uint)*(byte *)(DAT_0800b47c + 3) << 0x1a) < 0 ||
           *(char *)(DAT_0800b47c + 7) < '\0') || *(char *)(DAT_0800b47c + 3) < '\0') ||
         (int)((uint)*(byte *)(DAT_0800b47c + 5) << 0x1e) < 0) ||
         (int)((uint)*(byte *)(DAT_0800b47c + 5) << 0x1a) < 0;
}



/* ===== FUN_0800b480 @ 0x800B480 ===== */

void FUN_0800b480(void)

{
  return;
}



/* ===== FUN_0800b482 @ 0x800B482 ===== */

void FUN_0800b482(void)

{
  FUN_0800b134();
  FUN_0800b480();
  return;
}



/* ===== FUN_0800b490 @ 0x800B490 ===== */

void FUN_0800b490(void)

{
  uint *puVar1;
  
  if (((*DAT_0800b55c != '\0') && (*DAT_0800b55c = '\0', *(int *)(DAT_0800b560 + 0x11) != 0)) &&
     (*(uint *)(DAT_0800b564 + 0xd) < 10000)) {
    *(int *)(DAT_0800b564 + 0xd) = *(int *)(DAT_0800b560 + 0x11) * 10000;
    *DAT_0800b568 = *DAT_0800b568 | 0x4000;
  }
  puVar1 = DAT_0800b574;
  if (*DAT_0800b56c == '\x01') {
    *DAT_0800b574 = *(int *)(DAT_0800b570 + 4) + *DAT_0800b574;
    if (0xe10 < *puVar1) {
      *(uint *)(DAT_0800b564 + 0xd) = *puVar1 / 0xe10 + *(int *)(DAT_0800b564 + 0xd);
      *DAT_0800b578 = *DAT_0800b574 / 0xe10 + *DAT_0800b578;
      *DAT_0800b574 = *DAT_0800b574 % 0xe10;
      if (1000 < *DAT_0800b578) {
        *DAT_0800b578 = *DAT_0800b578 % 1000;
        *DAT_0800b568 = *DAT_0800b568 | 0x4000;
      }
    }
  }
  return;
}



/* ===== FUN_0800b57c @ 0x800B57C ===== */

void FUN_0800b57c(void)

{
  uint *puVar1;
  
  if (((*DAT_0800b650 != '\0') && (*DAT_0800b650 = '\0', *(int *)(DAT_0800b654 + 0x11) != 0)) &&
     (*(uint *)(DAT_0800b658 + 9) < 0x3ba)) {
    *(int *)(DAT_0800b658 + 9) = *(int *)(DAT_0800b654 + 0x11) * 0x3ba;
    *DAT_0800b65c = *DAT_0800b65c | 0x2000;
  }
  puVar1 = DAT_0800b66c;
  if (*DAT_0800b660 == '\x01') {
    *DAT_0800b66c = (uint)(*(int *)(DAT_0800b668 + 4) * *DAT_0800b664) / 1000 + *DAT_0800b66c;
    if (DAT_0800b670 < *puVar1) {
      *(uint *)(DAT_0800b658 + 9) = *DAT_0800b66c / DAT_0800b670 + *(int *)(DAT_0800b658 + 9);
      *DAT_0800b674 = *DAT_0800b66c / DAT_0800b670 + *DAT_0800b674;
      *DAT_0800b66c = *DAT_0800b66c - DAT_0800b670 * (*DAT_0800b66c / DAT_0800b670);
      if (0x28 < *DAT_0800b674) {
        *DAT_0800b674 = *DAT_0800b674 % 0x28;
        *DAT_0800b65c = *DAT_0800b65c | 0x2000;
      }
    }
  }
  return;
}



/* ===== FUN_0800b678 @ 0x800B678 ===== */

void FUN_0800b678(void)

{
  byte *pbVar1;
  
  pbVar1 = DAT_0800b6d4;
  if ((*DAT_0800b6d0 & 2) == 0) {
    *DAT_0800b6d4 = 0;
  }
  else {
    *DAT_0800b6d4 = *DAT_0800b6d4 + 1;
    if (2 < *pbVar1) {
      *pbVar1 = 0;
      *DAT_0800b6d0 = *DAT_0800b6d0 & 0xfd;
      *DAT_0800b6d8 = (*DAT_0800b6d8 & 0xf) + 0xa0;
    }
  }
  if (*DAT_0800b6d8 >> 4 == 10) {
    FUN_080193cc();
  }
  return;
}



/* ===== irq_34_Handler @ 0x800B6DC ===== */

void irq_34_Handler(void)

{
  undefined1 auStack_28 [36];
  
  if (DAT_0800b710[0x45] == 0) {
    FUN_080031a4(auStack_28,DAT_0800b710 + 4,0x24);
    FUN_0800ce98(*DAT_0800b710,DAT_0800b710[1],DAT_0800b710[2],DAT_0800b710[3]);
  }
  else {
    (*(code *)DAT_0800b710[0x45])();
  }
  return;
}



/* ===== irq_33_Handler @ 0x800B714 ===== */

void irq_33_Handler(void)

{
  undefined1 auStack_28 [36];
  
  if (DAT_0800b748[0x44] == 0) {
    FUN_080031a4(auStack_28,DAT_0800b748 + 4,0x24);
    FUN_0800ce98(*DAT_0800b748,DAT_0800b748[1],DAT_0800b748[2],DAT_0800b748[3]);
  }
  else {
    (*(code *)DAT_0800b748[0x44])();
  }
  return;
}



/* ===== FUN_0800b74c @ 0x800B74C ===== */

void FUN_0800b74c(int param_1,byte param_2)

{
  byte *pbVar1;
  
  pbVar1 = DAT_0800b78c;
  if (param_1 == DAT_0800b788) {
    *DAT_0800b78c = *DAT_0800b78c & 0xfe;
    *pbVar1 = *pbVar1 | param_2;
  }
  else if (param_1 == DAT_0800b790) {
    *DAT_0800b78c = *DAT_0800b78c & 0xfd;
    *pbVar1 = *pbVar1 | param_2 << 1;
  }
  return;
}



/* ===== FUN_0800b794 @ 0x800B794 ===== */

bool FUN_0800b794(int param_1,uint param_2)

{
  return (CONCAT22(*(undefined2 *)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x14)) & 0xffffff &
         param_2) == param_2;
}



/* ===== FUN_0800b7be @ 0x800B7BE ===== */

void FUN_0800b7be(int param_1,ushort param_2)

{
  *(ushort *)(param_1 + 0x14) = ~param_2;
  return;
}



/* ===== FUN_0800b7ca @ 0x800B7CA ===== */

void FUN_0800b7ca(ushort *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = *param_1 & 0xfbff;
  }
  else {
    *param_1 = *param_1 | 0x400;
  }
  return;
}



/* ===== FUN_0800b7e2 @ 0x800B7E2 ===== */

void FUN_0800b7e2(int param_1,ushort param_2,int param_3)

{
  if (param_3 == 0) {
    *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) & ~param_2;
  }
  else {
    *(ushort *)(param_1 + 4) = *(ushort *)(param_1 + 4) | param_2;
  }
  return;
}



/* ===== FUN_0800b7f4 @ 0x800B7F4 ===== */

void FUN_0800b7f4(int param_1)

{
  if (param_1 == DAT_0800b828) {
    FUN_0800e684(0x200000);
    FUN_0800e684(0x200000,0);
  }
  else {
    FUN_0800e684(0x400000);
    FUN_0800e684(0x400000,0);
  }
  return;
}



/* ===== FUN_0800b82c @ 0x800B82C ===== */

void FUN_0800b82c(ushort *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = *param_1 & 0xfffe;
  }
  else {
    *param_1 = *param_1 | 1;
  }
  return;
}



/* ===== FUN_0800b844 @ 0x800B844 ===== */

void FUN_0800b844(ushort *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = *param_1 & 0xfeff;
  }
  else {
    *param_1 = *param_1 | 0x100;
  }
  return;
}



/* ===== FUN_0800b85c @ 0x800B85C ===== */

void FUN_0800b85c(ushort *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = *param_1 & 0xfdff;
  }
  else {
    *param_1 = *param_1 | 0x200;
  }
  return;
}



/* ===== FUN_0800b874 @ 0x800B874 ===== */

bool FUN_0800b874(int param_1,uint param_2)

{
  uint uVar1;
  uint *local_c;
  
  uVar1 = param_2 & 0xffffff;
  if (param_2 >> 0x1c == 0) {
    uVar1 = uVar1 >> 0x10;
    local_c = (uint *)(param_1 + 0x18);
  }
  else {
    local_c = (uint *)(param_1 + 0x14);
  }
  return (*local_c & uVar1) != 0;
}



/* ===== FUN_0800b8ae @ 0x800B8AE ===== */

uint FUN_0800b8ae(int param_1)

{
  return CONCAT22(*(undefined2 *)(param_1 + 0x18),*(undefined2 *)(param_1 + 0x14)) & 0xffffff;
}



/* ===== FUN_0800b8c8 @ 0x800B8C8 ===== */

void FUN_0800b8c8(ushort *param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  ushort uVar3;
  uint uVar4;
  undefined1 auStack_34 [8];
  uint local_2c;
  
  uVar3 = param_1[2];
  FUN_0800e708(auStack_34);
  uVar2 = local_2c / DAT_0800b9ac;
  uVar1 = (ushort)uVar2;
  param_1[2] = uVar3 & 0xffc0 | uVar1;
  *param_1 = *param_1 & 0xfffe;
  if (DAT_0800b9b0 < *param_2) {
    if (*(short *)((int)param_2 + 6) == -0x4001) {
      uVar4 = local_2c / (*param_2 * 3) & 0xffff;
    }
    else {
      uVar4 = local_2c / (*param_2 * 0x19) & 0xffff | 0x4000;
    }
    uVar3 = (ushort)uVar4;
    if ((uVar4 & 0xfff) == 0) {
      uVar3 = uVar3 | 1;
    }
    uVar3 = uVar3 | 0x8000;
    param_1[0x10] = (short)(((uVar2 & 0xffff) * 300) / 1000) + 1;
  }
  else {
    local_2c = local_2c / (*param_2 << 1);
    uVar3 = (ushort)local_2c;
    if ((local_2c & 0xffff) < 4) {
      uVar3 = 4;
    }
    param_1[0x10] = uVar1 + 1;
  }
  param_1[0xe] = uVar3;
  *param_1 = *param_1 | 1;
  *param_1 = *param_1 & 0xfbf5 | (ushort)param_2[1] | *(ushort *)((int)param_2 + 10);
  param_1[4] = (ushort)param_2[3] | (ushort)param_2[2];
  return;
}



/* ===== FUN_0800b9b4 @ 0x800B9B4 ===== */

undefined1 FUN_0800b9b4(int param_1)

{
  return (char)*(undefined2 *)(param_1 + 0x10);
}



/* ===== FUN_0800b9bc @ 0x800B9BC ===== */

void FUN_0800b9bc(int param_1,ushort param_2,int param_3)

{
  if (param_3 == 0) {
    param_2 = param_2 & 0xfffe;
  }
  else {
    param_2 = param_2 | 1;
  }
  *(ushort *)(param_1 + 0x10) = param_2;
  return;
}



/* ===== FUN_0800b9ce @ 0x800B9CE ===== */

void FUN_0800b9ce(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0x10) = param_2;
  return;
}



/* ===== FUN_0800b9d4 @ 0x800B9D4 ===== */

void FUN_0800b9d4(undefined4 param_1)

{
  *(undefined4 *)(DAT_0800b9dc + 8) = param_1;
  return;
}



/* ===== FUN_0800b9e0 @ 0x800B9E0 ===== */

void FUN_0800b9e0(void)

{
  *DAT_0800b9ec = 0xcccc;
  return;
}



/* ===== FUN_0800b9f0 @ 0x800B9F0 ===== */

void FUN_0800b9f0(void)

{
  *DAT_0800b9fc = 0xaaaa;
  return;
}



/* ===== FUN_0800ba00 @ 0x800BA00 ===== */

void FUN_0800ba00(undefined4 param_1)

{
  *(undefined4 *)(DAT_0800ba08 + 4) = param_1;
  return;
}



/* ===== FUN_0800ba0c @ 0x800BA0C ===== */

void FUN_0800ba0c(undefined4 param_1)

{
  *DAT_0800ba14 = param_1;
  return;
}



/* ===== FUN_0800ba18 @ 0x800BA18 ===== */

void FUN_0800ba18(void)

{
  FUN_0800b9f0();
  return;
}



/* ===== FUN_0800ba20 @ 0x800BA20 ===== */

void FUN_0800ba20(undefined2 param_1)

{
  FUN_0800ba0c(0x5555);
  FUN_0800ba00(6);
  FUN_0800b9d4(param_1);
  FUN_0800b9f0();
  FUN_0800b9e0();
  return;
}



/* ===== FUN_0800ba44 @ 0x800BA44 ===== */

void FUN_0800ba44(void)

{
  FUN_08006be8();
  FUN_08006bc0(0,DAT_0800ba94);
  FUN_08006bc0(1,DAT_0800ba98,0);
  FUN_08006bc0(3,DAT_0800ba9c,0);
  FUN_08006bc0(4,DAT_0800baa0,0);
  FUN_08006c84(0,4);
  FUN_08006c84(1,4);
  FUN_08006c84(3,4);
  FUN_08006c84(4);
  return;
}



/* ===== FUN_0800baa4 @ 0x800BAA4 ===== */

void FUN_0800baa4(void)

{
  undefined4 *puVar1;
  undefined1 *puVar2;
  
  puVar1 = DAT_0800bafc;
  *DAT_0800bafc = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  *(undefined2 *)(puVar1 + 4) = 0;
  *(undefined1 *)((int)puVar1 + 0x12) = 0;
  *(undefined2 *)((int)puVar1 + 0x13) = 0;
  puVar2 = DAT_0800bb00;
  *DAT_0800bb00 = 0;
  *(undefined2 *)(puVar2 + 1) = 0;
  *(undefined2 *)(puVar2 + 3) = 0;
  *(undefined2 *)(puVar2 + 5) = 0;
  puVar2[7] = 0;
  *(undefined4 *)(puVar2 + 8) = 0;
  *(undefined4 *)(puVar2 + 0xc) = 0;
  puVar2[0x10] = 0;
  *(undefined4 *)(puVar2 + 0x11) = 0;
  *(undefined2 *)(puVar2 + 0x15) = 0;
  puVar2[0x17] = 0;
  *(undefined2 *)(puVar2 + 0x18) = 0;
  puVar2[0x1a] = 0;
  *(undefined4 *)(puVar2 + 0x1b) = 0;
  puVar2[0x1f] = 0;
  *(undefined4 *)(puVar2 + 0x20) = 0;
  puVar2[0x24] = 0;
  *(undefined2 *)(puVar2 + 0x25) = 0;
  FUN_080031d6(DAT_0800bb04,0x4a);
  return;
}



/* ===== FUN_0800bb08 @ 0x800BB08 ===== */

void FUN_0800bb08(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = 0;
  do {
    iVar2 = FUN_08004a5c();
    if (iVar2 != 0) {
      *DAT_0800bb40 = *DAT_0800bb40 & 0xf7;
      return;
    }
    *DAT_0800bb40 = (*DAT_0800bb40 & 0xf7) + 8;
    bVar1 = bVar1 + 1;
  } while (bVar1 < 2);
  return;
}



/* ===== FUN_0800bb44 @ 0x800BB44 ===== */

void FUN_0800bb44(void)

{
  FUN_0800bddc();
  FUN_0800bc18();
  FUN_0800bc64();
  FUN_0800bb5c();
  FUN_0800bdb4();
  return;
}



/* ===== FUN_0800bb5c @ 0x800BB5C ===== */

void FUN_0800bb5c(void)

{
  undefined2 *puVar1;
  
  puVar1 = DAT_0800bc14;
  *DAT_0800bc14 = 0x5dc;
  *(undefined1 *)(puVar1 + 1) = 2;
  *(undefined2 *)((int)puVar1 + 3) = 0x898;
  *(undefined1 *)((int)puVar1 + 5) = 5;
  puVar1[3] = 0x1194;
  *(undefined1 *)(puVar1 + 4) = 5;
  *(undefined2 *)((int)puVar1 + 9) = 500;
  *(undefined1 *)((int)puVar1 + 0xb) = 5;
  puVar1[6] = 10000;
  *(undefined1 *)(puVar1 + 7) = 5;
  *(undefined2 *)((int)puVar1 + 0xf) = 0x8300;
  *(undefined1 *)((int)puVar1 + 0x11) = 5;
  *(undefined1 *)(puVar1 + 9) = 0x41;
  *(undefined1 *)((int)puVar1 + 0x13) = 5;
  *(undefined1 *)(puVar1 + 10) = 0x55;
  *(undefined1 *)((int)puVar1 + 0x15) = 5;
  puVar1[0xb] = 0xdac;
  puVar1[0xc] = 10;
  puVar1[0xd] = 500;
  *(undefined1 *)(puVar1 + 0xe) = 5;
  *(undefined2 *)((int)puVar1 + 0x1d) = 100;
  *(undefined2 *)((int)puVar1 + 0x1f) = 0xe74;
  *(undefined2 *)((int)puVar1 + 0x21) = 0x32;
  *(undefined2 *)((int)puVar1 + 0x23) = 200;
  *(undefined1 *)((int)puVar1 + 0x25) = 5;
  puVar1[0x13] = 0x14;
  *(undefined1 *)(puVar1 + 0x14) = 5;
  *(undefined2 *)((int)puVar1 + 0x29) = 0xffec;
  *(undefined1 *)((int)puVar1 + 0x2b) = 5;
  puVar1[0x16] = 100;
  *(undefined1 *)(puVar1 + 0x17) = 5;
  *(undefined1 *)((int)puVar1 + 0x2f) = 5;
  *(undefined1 *)(puVar1 + 0x18) = 5;
  *(undefined1 *)((int)puVar1 + 0x31) = 5;
  return;
}



/* ===== FUN_0800bc18 @ 0x800BC18 ===== */

void FUN_0800bc18(void)

{
  undefined2 *puVar1;
  
  puVar1 = DAT_0800bc60;
  *DAT_0800bc60 = 0;
  puVar1[1] = 6000;
  *(undefined1 *)(puVar1 + 2) = 10;
  *(undefined1 *)((int)puVar1 + 5) = 0x55;
  *(undefined1 *)(puVar1 + 3) = 10;
  *(undefined1 *)((int)puVar1 + 7) = 0;
  *(undefined1 *)(puVar1 + 4) = 0;
  *(undefined1 *)((int)puVar1 + 9) = 0;
  *(undefined1 *)(puVar1 + 5) = 5;
  *(undefined2 *)((int)puVar1 + 0xb) = 0x14;
  *(undefined1 *)((int)puVar1 + 0xd) = 5;
  puVar1[7] = 500;
  *(undefined1 *)(puVar1 + 8) = 10;
  *(undefined2 *)((int)puVar1 + 0x11) = 30000;
  *(undefined2 *)((int)puVar1 + 0x13) = 100;
  return;
}



/* ===== FUN_0800bc64 @ 0x800BC64 ===== */

void FUN_0800bc64(void)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_0800bdb0;
  *DAT_0800bdb0 = 0x36;
  *(undefined2 *)(puVar1 + 1) = 0x12f;
  puVar1[3] = 0xb;
  puVar1[4] = 0x54;
  *(undefined2 *)(puVar1 + 5) = 0x25e;
  puVar1[7] = 3;
  puVar1[8] = 0;
  puVar1[9] = 10;
  puVar1[10] = 0xf;
  puVar1[0xb] = 4;
  puVar1[0xc] = 4;
  *(undefined2 *)(puVar1 + 0xd) = 0xff38;
  *(undefined2 *)(puVar1 + 0xf) = 2000;
  puVar1[0x11] = 8;
  puVar1[0x12] = 1;
  puVar1[0x13] = 0x1e;
  puVar1[0x14] = 0xf;
  puVar1[0x15] = 5;
  puVar1[0x16] = 0x1e;
  puVar1[0x17] = 6;
  *(undefined2 *)(puVar1 + 0x18) = 0xf060;
  puVar1[0x1a] = 2;
  *(undefined2 *)(puVar1 + 0x1b) = 0xff9c;
  puVar1[0x1d] = 0;
  puVar1[0x1e] = 10;
  puVar1[0x1f] = 0xf;
  *(undefined2 *)(puVar1 + 0x20) = 200;
  puVar1[0x22] = 0;
  puVar1[0x23] = 10;
  puVar1[0x24] = 0xf;
  *(undefined2 *)(puVar1 + 0x25) = 200;
  puVar1[0x27] = 0x2d;
  puVar1[0x28] = 3;
  puVar1[0x29] = 0x28;
  puVar1[0x2a] = 0x41;
  puVar1[0x2b] = 5;
  puVar1[0x2c] = 0x3c;
  puVar1[0x2d] = 0x50;
  puVar1[0x2e] = 2;
  puVar1[0x2f] = 0x41;
  puVar1[0x30] = 0x55;
  puVar1[0x31] = 2;
  puVar1[0x32] = 0x50;
  puVar1[0x33] = 2;
  puVar1[0x34] = 3;
  puVar1[0x35] = 5;
  puVar1[0x36] = 0xee;
  puVar1[0x37] = 5;
  puVar1[0x38] = 0xf0;
  puVar1[0x39] = 0xec;
  puVar1[0x3a] = 2;
  puVar1[0x3b] = 0xf1;
  puVar1[0x3c] = 2;
  *(undefined2 *)(puVar1 + 0x3d) = 700;
  puVar1[0x3f] = 0;
  puVar1[0x40] = 0;
  *(undefined2 *)(puVar1 + 0x41) = 0;
  *(undefined2 *)(puVar1 + 0x43) = 0xfa;
  *(undefined2 *)(puVar1 + 0x45) = 0x708;
  *(undefined2 *)(puVar1 + 0x47) = 1;
  return;
}



/* ===== FUN_0800bdb4 @ 0x800BDB4 ===== */

void FUN_0800bdb4(void)

{
  undefined1 *puVar1;
  
  puVar1 = DAT_0800bdd8;
  *DAT_0800bdd8 = 0;
  *(undefined2 *)(puVar1 + 1) = 0x414;
  *(undefined2 *)(puVar1 + 3) = 0x3672;
  *(undefined2 *)(puVar1 + 5) = 0xffff;
  *(undefined2 *)(puVar1 + 7) = 0xffff;
  return;
}



/* ===== FUN_0800bddc @ 0x800BDDC ===== */

void FUN_0800bddc(void)

{
  undefined2 *puVar1;
  
  puVar1 = DAT_0800bf60;
  *DAT_0800bf60 = 56000;
  *(undefined1 *)(puVar1 + 1) = 0x1e;
  *(undefined2 *)((int)puVar1 + 3) = 0x28a4;
  *(undefined1 *)((int)puVar1 + 5) = 0xd;
  *(undefined1 *)(puVar1 + 3) = 1;
  *(undefined1 *)((int)puVar1 + 7) = 0x24;
  *(undefined1 *)(puVar1 + 4) = 0x11;
  *(undefined1 *)((int)puVar1 + 9) = 0;
  *(undefined1 *)(puVar1 + 5) = 0;
  *(undefined1 *)((int)puVar1 + 0xb) = 0;
  *(undefined1 *)(puVar1 + 6) = 0;
  *(undefined1 *)((int)puVar1 + 0xd) = 0;
  *(undefined1 *)(puVar1 + 7) = 0xaa;
  *(undefined1 *)((int)puVar1 + 0xf) = 7;
  *(undefined1 *)(puVar1 + 8) = 0;
  *(undefined1 *)((int)puVar1 + 0x11) = 0;
  *(undefined1 *)(puVar1 + 9) = 0;
  *(undefined1 *)((int)puVar1 + 0x13) = 0;
  *(undefined1 *)(puVar1 + 10) = 0;
  *(undefined1 *)((int)puVar1 + 0x15) = 6;
  puVar1[0xb] = 0x8fff;
  *(undefined1 *)(puVar1 + 0xc) = 0x50;
  *(undefined2 *)((int)puVar1 + 0x19) = 0;
  *(undefined1 *)((int)puVar1 + 0x1b) = 0xcc;
  *(undefined1 *)(puVar1 + 0xe) = 0x33;
  *(undefined1 *)((int)puVar1 + 0x1d) = 2;
  *(undefined1 *)(puVar1 + 0xf) = 0x98;
  *(undefined1 *)((int)puVar1 + 0x1f) = 0x11;
  *(undefined1 *)(puVar1 + 0x10) = 2;
  *(undefined1 *)((int)puVar1 + 0x21) = 0xe4;
  *(undefined1 *)(puVar1 + 0x11) = 0x22;
  *(undefined1 *)((int)puVar1 + 0x23) = 2;
  puVar1[0x12] = 100;
  puVar1[0x13] = 1;
  *(undefined1 *)(puVar1 + 0x14) = 0;
  *(undefined1 *)((int)puVar1 + 0x29) = 0;
  *(undefined1 *)(puVar1 + 0x15) = 0;
  *(undefined1 *)((int)puVar1 + 0x2b) = 0;
  *(undefined1 *)(puVar1 + 0x16) = 0;
  *(undefined1 *)((int)puVar1 + 0x2d) = 0;
  *(undefined1 *)(puVar1 + 0x17) = 0;
  *(undefined1 *)((int)puVar1 + 0x2f) = 0;
  *(undefined1 *)(puVar1 + 0x18) = 0;
  *(undefined1 *)((int)puVar1 + 0x31) = 0xf;
  *(undefined1 *)(puVar1 + 0x19) = 0;
  *(undefined1 *)((int)puVar1 + 0x33) = 0x2e;
  *(undefined1 *)(puVar1 + 0x1a) = 1;
  *(undefined2 *)((int)puVar1 + 0x35) = 0;
  *(undefined2 *)((int)puVar1 + 0x37) = 0;
  *(undefined1 *)((int)puVar1 + 0x39) = 0;
  *(undefined1 *)(puVar1 + 0x1d) = 0;
  *(undefined2 *)((int)puVar1 + 0x3b) = 10;
  *(undefined2 *)((int)puVar1 + 0x3d) = 10;
  *(undefined1 *)((int)puVar1 + 0x3f) = 0x14;
  puVar1[0x20] = 0;
  puVar1[0x21] = 0;
  puVar1[0x22] = 0;
  puVar1[0x23] = 0;
  puVar1[0x24] = 0;
  puVar1[0x25] = 0;
  puVar1[0x26] = 0;
  puVar1[0x27] = 0;
  puVar1[0x28] = 0;
  puVar1[0x29] = 0;
  puVar1[0x2a] = 0;
  puVar1[0x2b] = 0;
  puVar1[0x2c] = 0;
  puVar1[0x2d] = 0;
  puVar1[0x2e] = 0;
  puVar1[0x2f] = 0;
  puVar1[0x30] = 0x50;
  *(undefined1 *)(puVar1 + 0x31) = 3;
  *(undefined1 *)((int)puVar1 + 99) = 0xec;
  *(undefined1 *)(puVar1 + 0x32) = 0x3c;
  *(undefined1 *)((int)puVar1 + 0x65) = 0x46;
  *(undefined1 *)(puVar1 + 0x33) = 0x14;
  *(undefined1 *)((int)puVar1 + 0x67) = 6;
  puVar1[0x34] = 0xed8;
  *(undefined1 *)(puVar1 + 0x35) = 0x32;
  *(undefined1 *)((int)puVar1 + 0x6b) = 0x14;
  puVar1[0x36] = 0xed8;
  *(undefined1 *)(puVar1 + 0x37) = 0x32;
  *(undefined1 *)((int)puVar1 + 0x6f) = 0x14;
  return;
}



/* ===== FUN_0800bf64 @ 0x800BF64 ===== */

void FUN_0800bf64(void)

{
  FUN_0800bb44();
  FUN_0800bf70();
  return;
}



/* ===== FUN_0800bf70 @ 0x800BF70 ===== */

void FUN_0800bf70(void)

{
  FUN_0800c39c();
  FUN_0800c0a0();
  FUN_0800c14c();
  FUN_0800bf8c();
  FUN_0800c368();
  FUN_0800c64c();
  return;
}



/* ===== FUN_0800bf8c @ 0x800BF8C ===== */

void FUN_0800bf8c(void)

{
  int iVar1;
  undefined2 *puVar2;
  
  iVar1 = DAT_0800c094;
  *(undefined2 *)(DAT_0800c094 + 0x17) = *DAT_0800c090;
  *(undefined1 *)(iVar1 + 0x19) = *(undefined1 *)(DAT_0800c090 + 1);
  *(undefined2 *)(iVar1 + 0x1a) = *(undefined2 *)((int)DAT_0800c090 + 3);
  *(undefined1 *)(iVar1 + 0x1c) = *(undefined1 *)((int)DAT_0800c090 + 5);
  *(undefined2 *)(iVar1 + 0x1d) = DAT_0800c090[3];
  *(undefined1 *)(iVar1 + 0x1f) = *(undefined1 *)(DAT_0800c090 + 4);
  puVar2 = DAT_0800c098;
  *DAT_0800c098 = *(undefined2 *)((int)DAT_0800c090 + 9);
  *(undefined1 *)(puVar2 + 1) = *(undefined1 *)((int)DAT_0800c090 + 0xb);
  *(undefined2 *)((int)puVar2 + 3) = DAT_0800c090[6];
  *(undefined1 *)((int)puVar2 + 5) = *(undefined1 *)(DAT_0800c090 + 7);
  puVar2[3] = *(undefined2 *)((int)DAT_0800c090 + 0xf);
  *(undefined1 *)(puVar2 + 4) = *(undefined1 *)((int)DAT_0800c090 + 0x11);
  *(undefined1 *)((int)puVar2 + 9) = *(undefined1 *)(DAT_0800c090 + 9);
  *(undefined1 *)(puVar2 + 5) = *(undefined1 *)((int)DAT_0800c090 + 0x13);
  *(undefined1 *)((int)puVar2 + 0xb) = *(undefined1 *)(DAT_0800c090 + 10);
  *(undefined1 *)(puVar2 + 6) = *(undefined1 *)((int)DAT_0800c090 + 0x15);
  *(undefined2 *)((int)puVar2 + 0xd) = DAT_0800c090[0xb];
  *(undefined2 *)((int)puVar2 + 0xf) = DAT_0800c090[0xc];
  *(undefined2 *)((int)puVar2 + 0x11) = DAT_0800c090[0xd];
  *(undefined1 *)((int)puVar2 + 0x13) = *(undefined1 *)(DAT_0800c090 + 0xe);
  puVar2[10] = *(undefined2 *)((int)DAT_0800c090 + 0x1d);
  puVar2[0xb] = *(undefined2 *)((int)DAT_0800c090 + 0x1f);
  puVar2[0xc] = *(undefined2 *)((int)DAT_0800c090 + 0x21);
  puVar2[0xd] = *(undefined2 *)((int)DAT_0800c090 + 0x23);
  *(undefined1 *)(puVar2 + 0xe) = *(undefined1 *)((int)DAT_0800c090 + 0x25);
  *(undefined2 *)((int)puVar2 + 0x1d) = DAT_0800c090[0x13];
  *(undefined1 *)((int)puVar2 + 0x1f) = *(undefined1 *)(DAT_0800c090 + 0x14);
  puVar2 = DAT_0800c09c;
  *DAT_0800c09c = *(undefined2 *)((int)DAT_0800c090 + 0x29);
  *(undefined1 *)(puVar2 + 1) = *(undefined1 *)((int)DAT_0800c090 + 0x2b);
  *(undefined2 *)((int)puVar2 + 3) = DAT_0800c090[0x16];
  *(undefined1 *)((int)puVar2 + 5) = *(undefined1 *)(DAT_0800c090 + 0x17);
  *(undefined1 *)(puVar2 + 3) = *(undefined1 *)((int)DAT_0800c090 + 0x2f);
  *(undefined1 *)((int)puVar2 + 7) = *(undefined1 *)(DAT_0800c090 + 0x18);
  *(undefined1 *)(puVar2 + 4) = *(undefined1 *)((int)DAT_0800c090 + 0x31);
  return;
}



/* ===== FUN_0800c0a0 @ 0x800C0A0 ===== */

void FUN_0800c0a0(void)

{
  undefined2 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  
  *(undefined2 *)(DAT_0800c144 + 0xe) = *DAT_0800c140;
  iVar2 = DAT_0800c144;
  *(ushort *)(DAT_0800c144 + 0x10) = (ushort)DAT_0800c140[1] / 10;
  *(undefined1 *)(iVar2 + 0x12) = *(undefined1 *)(DAT_0800c140 + 2);
  *(undefined1 *)(iVar2 + 0x13) = *(undefined1 *)((int)DAT_0800c140 + 5);
  *(undefined1 *)(iVar2 + 0x14) = *(undefined1 *)(DAT_0800c140 + 3);
  puVar1 = DAT_0800c140;
  *(char *)((int)DAT_0800c140 + 7) = *(char *)((int)DAT_0800c140 + 7) << 2;
  *(char *)(puVar1 + 4) = *(char *)(puVar1 + 4) << 2;
  puVar3 = DAT_0800c148;
  DAT_0800c148[3] = *(undefined1 *)((int)puVar1 + 9);
  puVar3[4] = *(undefined1 *)(DAT_0800c140 + 5);
  iVar2 = DAT_0800c144;
  *(undefined2 *)(DAT_0800c144 + 0x17) = *(undefined2 *)((int)DAT_0800c140 + 0xb);
  *(undefined1 *)(iVar2 + 0x19) = *(undefined1 *)((int)DAT_0800c140 + 0xd);
  *(undefined2 *)(iVar2 + 0x1a) = DAT_0800c140[7];
  *(undefined1 *)(iVar2 + 0x1c) = *(undefined1 *)(DAT_0800c140 + 8);
  *(ushort *)(DAT_0800c144 + 0x1d) = *(ushort *)((int)DAT_0800c140 + 0x11) / 10;
  *(char *)(DAT_0800c144 + 0x1f) = (char)(*(ushort *)((int)DAT_0800c140 + 0x13) / 10);
  *DAT_0800c148 = (char)(*(ushort *)((int)DAT_0800c140 + 0x13) / 10 >> 8);
  return;
}



/* ===== FUN_0800c14c @ 0x800C14C ===== */

void FUN_0800c14c(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = DAT_0800c35c;
  *(undefined1 *)(DAT_0800c35c + 4) = *DAT_0800c358;
  *(undefined2 *)(iVar1 + 5) = *(undefined2 *)(DAT_0800c358 + 1);
  *(undefined1 *)(iVar1 + 10) = DAT_0800c358[3];
  *(undefined1 *)(iVar1 + 7) = DAT_0800c358[4];
  *(undefined2 *)(iVar1 + 8) = *(undefined2 *)(DAT_0800c358 + 5);
  *(undefined1 *)(iVar1 + 0xb) = DAT_0800c358[7];
  *(undefined1 *)(iVar1 + 0xc) = DAT_0800c358[8];
  *(undefined1 *)(iVar1 + 0xd) = DAT_0800c358[9];
  *(undefined1 *)(iVar1 + 0xe) = DAT_0800c358[10];
  iVar1 = DAT_0800c35c;
  *(char *)(DAT_0800c35c + 0xf) = (char)((int)(uint)(byte)DAT_0800c358[0xb] >> 1);
  *(undefined1 *)(iVar1 + 0x10) = DAT_0800c358[0xc];
  *(undefined2 *)(iVar1 + 0x17) = *(undefined2 *)(DAT_0800c358 + 0xd);
  DAT_0800c360[0x1f] = (char)(*(ushort *)(DAT_0800c358 + 0xf) / 10);
  *DAT_0800c364 = (char)(*(ushort *)(DAT_0800c358 + 0xf) / 10 >> 8);
  *(char *)(iVar1 + 0x11) = (char)((int)(uint)(byte)DAT_0800c358[0x11] >> 1);
  *(undefined1 *)(iVar1 + 0x12) = DAT_0800c358[0x12];
  *(char *)(iVar1 + 0x13) = (char)((int)(uint)(byte)DAT_0800c358[0x13] >> 1);
  *(undefined1 *)(iVar1 + 0x14) = DAT_0800c358[0x14];
  *(undefined1 *)(iVar1 + 0x15) = DAT_0800c358[0x15];
  *(char *)(iVar1 + 0x16) = DAT_0800c358[0x16] + '\x01';
  DAT_0800c360[3] = DAT_0800c358[0x17];
  *(undefined2 *)(iVar1 + 0x19) = *(undefined2 *)(DAT_0800c358 + 0x18);
  *(undefined1 *)(iVar1 + 0x1b) = DAT_0800c358[0x1a];
  *(undefined2 *)(iVar1 + 0x1c) = *(undefined2 *)(DAT_0800c358 + 0x1b);
  *(undefined1 *)(iVar1 + 0x1e) = DAT_0800c358[0x1d];
  *(undefined1 *)(iVar1 + 0x1f) = DAT_0800c358[0x1e];
  puVar2 = DAT_0800c360;
  *DAT_0800c360 = DAT_0800c358[0x1f];
  *(undefined2 *)(puVar2 + 1) = *(undefined2 *)(DAT_0800c358 + 0x20);
  puVar2[4] = DAT_0800c358[0x22];
  puVar2[5] = DAT_0800c358[0x23];
  puVar2[6] = DAT_0800c358[0x24];
  *(undefined2 *)(puVar2 + 7) = *(undefined2 *)(DAT_0800c358 + 0x25);
  puVar2[9] = DAT_0800c358[0x27];
  puVar2[10] = DAT_0800c358[0x28];
  puVar2[0xb] = DAT_0800c358[0x29];
  puVar2[0xc] = DAT_0800c358[0x2a];
  puVar2[0xd] = DAT_0800c358[0x2b];
  puVar2[0xe] = DAT_0800c358[0x2c];
  puVar2[0xf] = DAT_0800c358[0x2d];
  puVar2[0x10] = DAT_0800c358[0x2e];
  puVar2[0x11] = DAT_0800c358[0x2f];
  puVar2[0x12] = DAT_0800c358[0x30];
  puVar2[0x13] = DAT_0800c358[0x31];
  puVar2[0x14] = DAT_0800c358[0x32];
  puVar2[0x15] = DAT_0800c358[0x33];
  puVar2[0x16] = DAT_0800c358[0x34];
  puVar2[0x17] = DAT_0800c358[0x35];
  puVar2[0x18] = DAT_0800c358[0x36];
  puVar2[0x19] = DAT_0800c358[0x37];
  puVar2[0x1a] = DAT_0800c358[0x38];
  puVar2[0x1b] = DAT_0800c358[0x39];
  puVar2[0x1c] = DAT_0800c358[0x3a];
  puVar2[0x1d] = DAT_0800c358[0x3b];
  puVar2[0x1e] = DAT_0800c358[0x3c];
  puVar2 = DAT_0800c364;
  *(undefined2 *)(DAT_0800c364 + 1) = *(undefined2 *)(DAT_0800c358 + 0x3d);
  puVar2[3] = DAT_0800c358[0x3f];
  puVar2[4] = DAT_0800c358[0x40];
  *(undefined2 *)(puVar2 + 5) = *(undefined2 *)(DAT_0800c358 + 0x41);
  *(undefined2 *)(puVar2 + 9) = *(undefined2 *)(DAT_0800c358 + 0x43);
  *(undefined2 *)(puVar2 + 0xb) = *(undefined2 *)(DAT_0800c358 + 0x45);
  *(undefined2 *)(puVar2 + 0xd) = *(undefined2 *)(DAT_0800c358 + 0x47);
  return;
}



/* ===== FUN_0800c368 @ 0x800C368 ===== */

void FUN_0800c368(void)

{
  int iVar1;
  
  iVar1 = DAT_0800c398;
  *(undefined1 *)(DAT_0800c398 + 5) = *DAT_0800c394;
  *(undefined2 *)(iVar1 + 6) = *(undefined2 *)(DAT_0800c394 + 1);
  *(undefined2 *)(iVar1 + 8) = *(undefined2 *)(DAT_0800c394 + 3);
  *(undefined2 *)(iVar1 + 10) = *(undefined2 *)(DAT_0800c394 + 5);
  *(undefined2 *)(iVar1 + 0xc) = *(undefined2 *)(DAT_0800c394 + 7);
  return;
}



/* ===== FUN_0800c39c @ 0x800C39C ===== */

void FUN_0800c39c(void)

{
  ushort *puVar1;
  int iVar2;
  undefined1 *puVar3;
  
  puVar1 = DAT_0800c630;
  *DAT_0800c630 = *DAT_0800c62c / 10;
  *(char *)(puVar1 + 1) = (char)DAT_0800c62c[1];
  *(undefined2 *)((int)puVar1 + 3) = *(undefined2 *)((int)DAT_0800c62c + 3);
  *(undefined1 *)((int)puVar1 + 5) = *(undefined1 *)((int)DAT_0800c62c + 5);
  *(char *)(puVar1 + 3) = (char)DAT_0800c62c[3];
  *(undefined1 *)((int)puVar1 + 7) = *(undefined1 *)((int)DAT_0800c62c + 7);
  *(char *)(puVar1 + 4) = (char)DAT_0800c62c[4];
  *(undefined1 *)((int)puVar1 + 9) = *(undefined1 *)((int)DAT_0800c62c + 9);
  *(char *)((int)puVar1 + 0xb) = (char)DAT_0800c62c[5];
  *(undefined1 *)(puVar1 + 6) = *(undefined1 *)((int)DAT_0800c62c + 0xb);
  iVar2 = DAT_0800c634;
  *(char *)(DAT_0800c634 + 9) = (char)DAT_0800c62c[6];
  *(undefined1 *)(iVar2 + 10) = *(undefined1 *)((int)DAT_0800c62c + 0xd);
  *(char *)(iVar2 + 0xb) = (char)DAT_0800c62c[7];
  *(undefined1 *)(iVar2 + 0xc) = *(undefined1 *)((int)DAT_0800c62c + 0xf);
  *(char *)(iVar2 + 0xd) = (char)DAT_0800c62c[8];
  *(undefined1 *)(iVar2 + 0xe) = *(undefined1 *)((int)DAT_0800c62c + 0x11);
  *(char *)(iVar2 + 0xf) = (char)DAT_0800c62c[9];
  *(undefined1 *)(iVar2 + 0x10) = *(undefined1 *)((int)DAT_0800c62c + 0x13);
  *(char *)(iVar2 + 0x11) = (char)DAT_0800c62c[10];
  *(undefined1 *)(iVar2 + 0x12) = *(undefined1 *)((int)DAT_0800c62c + 0x15);
  *(ushort *)(iVar2 + 0x13) = DAT_0800c62c[0xb];
  *(char *)(iVar2 + 0x16) = (char)DAT_0800c62c[0xc];
  iVar2 = DAT_0800c638;
  *(undefined2 *)(DAT_0800c638 + 0xe) = *(undefined2 *)((int)DAT_0800c62c + 0x19);
  *(undefined1 *)(iVar2 + 0x10) = *(undefined1 *)((int)DAT_0800c62c + 0x1b);
  *(char *)(iVar2 + 0x11) = (char)DAT_0800c62c[0xe];
  *(undefined1 *)(iVar2 + 0x12) = *(undefined1 *)((int)DAT_0800c62c + 0x1d);
  *(char *)(iVar2 + 0x14) = (char)DAT_0800c62c[0xf];
  *(undefined1 *)(iVar2 + 0x15) = *(undefined1 *)((int)DAT_0800c62c + 0x1f);
  *(char *)(iVar2 + 0x16) = (char)DAT_0800c62c[0x10];
  *(undefined1 *)(iVar2 + 0x18) = *(undefined1 *)((int)DAT_0800c62c + 0x21);
  *(char *)(iVar2 + 0x19) = (char)DAT_0800c62c[0x11];
  *(undefined1 *)(iVar2 + 0x1a) = *(undefined1 *)((int)DAT_0800c62c + 0x23);
  *(ushort *)(DAT_0800c63c + 2) = DAT_0800c62c[0x12];
  iVar2 = DAT_0800c638;
  *(ushort *)(DAT_0800c638 + 0x1c) = DAT_0800c62c[0x13];
  *(char *)(iVar2 + 0x1e) = (char)DAT_0800c62c[0x14];
  *(undefined1 *)(iVar2 + 0x1f) = *(undefined1 *)((int)DAT_0800c62c + 0x29);
  *DAT_0800c63c = (char)DAT_0800c62c[0x15];
  iVar2 = DAT_0800c640;
  *(undefined1 *)(DAT_0800c640 + 0x13) = *(undefined1 *)((int)DAT_0800c62c + 0x2b);
  *(char *)(iVar2 + 0x14) = (char)DAT_0800c62c[0x16];
  *(undefined1 *)(iVar2 + 0x15) = *(undefined1 *)((int)DAT_0800c62c + 0x2d);
  *(char *)(iVar2 + 0x16) = (char)DAT_0800c62c[0x17];
  *(undefined1 *)(iVar2 + 0xf) = *(undefined1 *)((int)DAT_0800c62c + 0x2f);
  *(char *)(iVar2 + 0x10) = (char)DAT_0800c62c[0x18];
  *(undefined1 *)(iVar2 + 0x11) = *(undefined1 *)((int)DAT_0800c62c + 0x31);
  *(char *)(iVar2 + 0x12) = (char)DAT_0800c62c[0x19];
  iVar2 = DAT_0800c634;
  *(undefined1 *)(DAT_0800c634 + 0x17) = *(undefined1 *)((int)DAT_0800c62c + 0x33);
  *(char *)(iVar2 + 0x18) = (char)DAT_0800c62c[0x1a];
  *(undefined2 *)(iVar2 + 0x19) = *(undefined2 *)((int)DAT_0800c62c + 0x35);
  *(undefined2 *)(iVar2 + 0x1b) = *(undefined2 *)((int)DAT_0800c62c + 0x37);
  *(undefined1 *)(iVar2 + 0x1d) = *(undefined1 *)((int)DAT_0800c62c + 0x39);
  *(char *)(iVar2 + 0x1e) = (char)DAT_0800c62c[0x1d];
  *(undefined1 *)(iVar2 + 0x1f) = *(undefined1 *)((int)DAT_0800c62c + 0x3b);
  puVar3 = DAT_0800c644;
  *DAT_0800c644 = (char)((ushort)*(undefined2 *)((int)DAT_0800c62c + 0x3b) >> 8);
  *(undefined2 *)(puVar3 + 1) = *(undefined2 *)((int)DAT_0800c62c + 0x3d);
  puVar3[3] = *(undefined1 *)((int)DAT_0800c62c + 0x3f);
  *(ushort *)(puVar3 + 4) = DAT_0800c62c[0x20];
  *(ushort *)(puVar3 + 6) = DAT_0800c62c[0x21];
  *(ushort *)(puVar3 + 8) = DAT_0800c62c[0x22];
  *(ushort *)(puVar3 + 10) = DAT_0800c62c[0x23];
  *(ushort *)(puVar3 + 0xc) = DAT_0800c62c[0x24];
  *(ushort *)(puVar3 + 0xe) = DAT_0800c62c[0x25];
  *(ushort *)(puVar3 + 0x10) = DAT_0800c62c[0x26];
  *(ushort *)(puVar3 + 0x12) = DAT_0800c62c[0x27];
  *(ushort *)(puVar3 + 0x14) = DAT_0800c62c[0x28];
  *(ushort *)(puVar3 + 0x16) = DAT_0800c62c[0x29];
  *(ushort *)(puVar3 + 0x18) = DAT_0800c62c[0x2a];
  *(ushort *)(puVar3 + 0x1a) = DAT_0800c62c[0x2b];
  *(ushort *)(puVar3 + 0x1c) = DAT_0800c62c[0x2c];
  *(ushort *)(puVar3 + 0x1e) = DAT_0800c62c[0x2d];
  puVar1 = DAT_0800c648;
  *DAT_0800c648 = DAT_0800c62c[0x2e];
  puVar1[1] = DAT_0800c62c[0x2f];
  puVar1[9] = DAT_0800c62c[0x30];
  *(char *)(puVar1 + 2) = (char)DAT_0800c62c[0x31];
  *(undefined1 *)((int)puVar1 + 5) = *(undefined1 *)((int)DAT_0800c62c + 99);
  *(char *)(puVar1 + 3) = (char)DAT_0800c62c[0x32];
  *(undefined1 *)((int)puVar1 + 7) = *(undefined1 *)((int)DAT_0800c62c + 0x65);
  *(char *)(puVar1 + 4) = (char)DAT_0800c62c[0x33];
  *(undefined1 *)((int)puVar1 + 9) = *(undefined1 *)((int)DAT_0800c62c + 0x67);
  puVar1[5] = DAT_0800c62c[0x34];
  *(char *)(puVar1 + 6) = (char)DAT_0800c62c[0x35];
  *(undefined1 *)((int)puVar1 + 0xd) = *(undefined1 *)((int)DAT_0800c62c + 0x6b);
  puVar1[7] = DAT_0800c62c[0x36];
  *(char *)(puVar1 + 8) = (char)DAT_0800c62c[0x37];
  *(undefined1 *)((int)puVar1 + 0x11) = *(undefined1 *)((int)DAT_0800c62c + 0x6f);
  return;
}



/* ===== FUN_0800c64c @ 0x800C64C ===== */

void FUN_0800c64c(void)

{
  int iVar1;
  
  iVar1 = DAT_0800c68c;
  *(undefined1 *)(DAT_0800c68c + 10) = 4;
  *(undefined1 *)(iVar1 + 0xd) = 1;
  *(undefined1 *)(iVar1 + 0x15) = 0x62;
  *(undefined1 *)(DAT_0800c68c + 0x16) = 2;
  iVar1 = DAT_0800c690;
  *(undefined1 *)(DAT_0800c690 + 0x13) = 0;
  *(undefined1 *)(iVar1 + 0x17) = 0;
  *(undefined1 *)(iVar1 + 0x1b) = 0;
  *(undefined1 *)(DAT_0800c694 + 1) = 0;
  *(undefined1 *)(DAT_0800c698 + 7) = 0x90;
  *(undefined1 *)(DAT_0800c698 + 8) = 1;
  *(undefined1 *)(DAT_0800c69c + 0x15) = 0;
  iVar1 = DAT_0800c6a0;
  *(undefined4 *)(DAT_0800c6a0 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  return;
}



/* ===== FUN_0800c6a4 @ 0x800C6A4 ===== */

undefined1 FUN_0800c6a4(void)

{
  return *DAT_0800c6ac;
}



/* ===== FUN_0800c6b0 @ 0x800C6B0 ===== */

undefined4 FUN_0800c6b0(int param_1)

{
  char cVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  puVar2 = DAT_0800c744;
  *DAT_0800c744 = *DAT_0800c744;
  cVar1 = *(char *)(param_1 + 2);
  if (cVar1 == 'c') {
    *DAT_0800c744 = 3;
    *DAT_0800c74c = DAT_0800c778;
    *DAT_0800c754 = DAT_0800c77c;
    *DAT_0800c75c = DAT_0800c780;
    *DAT_0800c764 = DAT_0800c784;
    uVar3 = 1;
  }
  else if (cVar1 == 'n') {
    *DAT_0800c744 = 1;
    *DAT_0800c74c = DAT_0800c768;
    *DAT_0800c754 = DAT_0800c76c;
    *DAT_0800c75c = DAT_0800c770;
    *DAT_0800c764 = DAT_0800c774;
    uVar3 = 1;
  }
  else if (cVar1 == -0x70) {
    *puVar2 = 0;
    *DAT_0800c74c = DAT_0800c748;
    *DAT_0800c754 = DAT_0800c750;
    *DAT_0800c75c = DAT_0800c758;
    *DAT_0800c764 = DAT_0800c760;
    uVar3 = 1;
  }
  else {
    *DAT_0800c744 = 4;
    *DAT_0800c74c = 0;
    uVar3 = 0;
  }
  return uVar3;
}



/* ===== FUN_0800c788 @ 0x800C788 ===== */

void FUN_0800c788(void)

{
  byte bVar1;
  int iVar2;
  undefined4 local_10;
  
  local_10 = 0;
  bVar1 = 0;
  do {
    if (2 < bVar1) {
      return;
    }
    iVar2 = FUN_0800eee0(8,0x91a4,&local_10,2);
    if (iVar2 != 0) {
      *(ushort *)(DAT_0800c7e8 + 0x1c) = (ushort)local_10;
      if ((31999 < (ushort)local_10) && ((ushort)local_10 < 0x8ca1)) {
        return;
      }
      local_10 = 34000;
      iVar2 = FUN_080175ac(8,0x91a4,34000,2);
      if (iVar2 != 0) {
        return;
      }
    }
    bVar1 = bVar1 + 1;
  } while( true );
}



/* ===== FUN_0800c7ec @ 0x800C7EC ===== */

void FUN_0800c7ec(void)

{
  byte *pbVar1;
  byte *pbVar2;
  
  *(undefined2 *)(DAT_0800c8a8 + 0x24) = *(undefined2 *)(DAT_0800c8a4 + 0x36);
  if ((*DAT_0800c8ac == '\0') && (2 < *DAT_0800c8b0)) {
    FUN_08003bdc(0x9e);
    pbVar2 = DAT_0800c8c0;
    pbVar1 = DAT_0800c8b8;
    if ((*(byte *)(DAT_0800c8b4 + 1) & 1) == 0) {
      if ((uint)*(ushort *)(DAT_0800c8a4 + 0x36) * 10 < 4000) {
        *DAT_0800c8b8 = *DAT_0800c8b8 + 1;
        if (10 < *pbVar1) {
          *pbVar1 = 0;
          *DAT_0800c8bc = 1;
        }
        *DAT_0800c8c0 = 0;
      }
      else {
        *DAT_0800c8c0 = *DAT_0800c8c0 + 1;
        if (10 < *pbVar2) {
          *pbVar2 = 0;
          *DAT_0800c8bc = 0;
        }
        *DAT_0800c8b8 = 0;
      }
    }
    else {
      *DAT_0800c8b8 = 0;
      *DAT_0800c8c0 = 0;
      *DAT_0800c8bc = 2;
    }
  }
  else {
    FUN_08003bdc(0x9f);
    *DAT_0800c8b8 = 0;
    *DAT_0800c8c0 = 0;
    *DAT_0800c8bc = 2;
  }
  return;
}



/* ===== FUN_0800c8c4 @ 0x800C8C4 ===== */

char FUN_0800c8c4(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  cVar1 = '\0';
  iVar4 = DAT_0800c908;
  if ((param_1 != 0) && (param_1 == 1)) {
    iVar4 = DAT_0800c90c;
  }
  uVar3 = 0;
  while ((uVar3 < 0x40 && (iVar2 = FUN_08009fd4(iVar4 + uVar3 * 0x20), iVar2 == 0xaa))) {
    cVar1 = cVar1 + '\x01';
    uVar3 = uVar3 + 1 & 0xff;
  }
  return cVar1;
}



/* ===== FUN_0800c910 @ 0x800C910 ===== */

char FUN_0800c910(int param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  cVar1 = '\0';
  iVar4 = DAT_0800c958;
  if ((param_1 != 0) && (param_1 == 1)) {
    iVar4 = DAT_0800c95c;
  }
  uVar3 = 0;
  while ((uVar3 < 0x24 && (iVar2 = FUN_08009fd4(iVar4 + uVar3 * 0x38), iVar2 == 0xaa))) {
    cVar1 = cVar1 + '\x01';
    uVar3 = uVar3 + 1 & 0xff;
  }
  return cVar1;
}



/* ===== FUN_0800c960 @ 0x800C960 ===== */

undefined4 FUN_0800c960(uint param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((((param_2 == 0) || (param_3 == 0)) || (0x800 < param_3)) ||
     ((param_3 != ((int)(param_3 + ((uint)(param_3 >> 0x1f) >> 0x1e)) >> 2) * 4 ||
      (((DAT_0800ca0c <= param_1 + param_3 || (param_1 < DAT_0800ca10)) &&
       ((DAT_0800ca14 <= param_1 + param_3 || (param_1 < DAT_0800ca0c + 1)))))))) {
    uVar3 = 0;
  }
  else {
    FUN_08008378();
    for (uVar2 = 0; (int)uVar2 < param_3; uVar2 = uVar2 + 4 & 0xff) {
      iVar1 = FUN_08008304(param_1,(uint)*(byte *)(param_2 + uVar2) +
                                   ((uint)*(byte *)(param_2 + uVar2 + 1) +
                                   ((uint)*(byte *)(param_2 + uVar2 + 2) +
                                   (uint)*(byte *)(param_2 + uVar2 + 3) * 0x100) * 0x100) * 0x100);
      if (iVar1 != 6) {
        uVar3 = 0;
        break;
      }
      param_1 = param_1 + 4;
      uVar3 = 1;
    }
    FUN_080082d4();
  }
  return uVar3;
}



/* ===== FUN_0800ca18 @ 0x800CA18 ===== */

undefined4 FUN_0800ca18(uint param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if ((((param_2 == 0) || (param_3 == 0)) || (0x800 < param_3)) ||
     ((param_3 != ((int)(param_3 + ((uint)(param_3 >> 0x1f) >> 0x1e)) >> 2) * 4 ||
      (((DAT_0800cac4 <= param_1 + param_3 || (param_1 < DAT_0800cac8)) &&
       ((DAT_0800cacc <= param_1 + param_3 || (param_1 < DAT_0800cac4 + 1)))))))) {
    uVar3 = 0;
  }
  else {
    FUN_08008378();
    for (uVar2 = 0; (int)uVar2 < param_3; uVar2 = uVar2 + 4 & 0xff) {
      iVar1 = FUN_08008304(param_1,(uint)*(byte *)(param_2 + uVar2) +
                                   ((uint)*(byte *)(param_2 + uVar2 + 1) +
                                   ((uint)*(byte *)(param_2 + uVar2 + 2) +
                                   (uint)*(byte *)(param_2 + uVar2 + 3) * 0x100) * 0x100) * 0x100);
      if (iVar1 != 6) {
        uVar3 = 0;
        break;
      }
      param_1 = param_1 + 4;
      uVar3 = 1;
    }
    FUN_080082d4();
  }
  return uVar3;
}



/* ===== FUN_0800cad0 @ 0x800CAD0 ===== */

uint FUN_0800cad0(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = 0;
  for (uVar2 = 0; uVar2 < param_2; uVar2 = uVar2 + 1) {
    uVar1 = ((int)uVar1 >> 8 | (uVar1 & 0xff) << 8) ^ (uint)*(byte *)(param_1 + uVar2);
    uVar1 = uVar1 ^ (uVar1 & 0xff) >> 4;
    uVar1 = uVar1 ^ (uVar1 & 0xf) << 0xc ^ (uVar1 & 0xff) << 5;
  }
  return uVar1;
}



/* ===== FUN_0800cb0c @ 0x800CB0C ===== */

bool FUN_0800cb0c(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  undefined1 auStack_4c [4];
  undefined1 auStack_48 [48];
  uint local_18;
  
  FUN_080031d6(auStack_4c,0x38);
  iVar1 = FUN_0800c910(0);
  iVar2 = FUN_0800c910(1);
  if (iVar1 == 0) {
    if (iVar2 == 0) {
      bVar4 = false;
    }
    else {
      vfp_control_routine_08009d6c(DAT_0800cbec,DAT_0800cbe8,0x800);
      FUN_08009fb8(DAT_0800cbec + iVar2 * 0x38,auStack_4c,0x38);
      uVar3 = FUN_0800cad0(auStack_4c,0x34);
      bVar4 = uVar3 == local_18 >> 0x10;
      if (bVar4) {
        FUN_080031a4(param_1,auStack_48,0x30);
      }
      else {
        FUN_08009e98(DAT_0800cbe8);
        FUN_08009e98(DAT_0800cbec);
      }
    }
  }
  else {
    if (iVar2 == 0) {
      vfp_control_routine_08009d6c(DAT_0800cbe8,DAT_0800cbec,0x800);
    }
    FUN_08009fb8(DAT_0800cbe8 + (iVar1 + -1) * 0x38,auStack_4c,0x38);
    uVar3 = FUN_0800cad0(auStack_4c,0x34);
    bVar4 = uVar3 == local_18 >> 0x10;
    if (bVar4) {
      FUN_080031a4(param_1,auStack_48,0x30);
    }
    else {
      FUN_08009e98(DAT_0800cbe8);
      FUN_08009e98(DAT_0800cbec);
    }
  }
  return bVar4;
}



/* ===== FUN_0800cbf0 @ 0x800CBF0 ===== */

bool FUN_0800cbf0(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [24];
  uint local_18;
  
  FUN_080031d6(auStack_34,0x20);
  iVar1 = FUN_0800c8c4(0);
  iVar2 = FUN_0800c8c4(1);
  if (iVar1 == 0) {
    if (iVar2 == 0) {
      bVar4 = false;
    }
    else {
      vfp_control_routine_08009d6c(DAT_0800ccc8,DAT_0800ccc4,0x800);
      FUN_08009fb8(DAT_0800ccc8 + iVar2 * 0x20,auStack_34,0x20);
      uVar3 = FUN_0800cad0(auStack_34,0x1c);
      bVar4 = uVar3 == local_18 >> 0x10;
      if (bVar4) {
        FUN_080031a4(param_1,auStack_30,0x18);
      }
      else {
        FUN_08009e98(DAT_0800ccc4);
        FUN_08009e98(DAT_0800ccc8);
      }
    }
  }
  else {
    if (iVar2 == 0) {
      vfp_control_routine_08009d6c(DAT_0800ccc4,DAT_0800ccc8,0x800);
    }
    FUN_08009fb8(DAT_0800ccc4 + (iVar1 + -1) * 0x20,auStack_34,0x20);
    uVar3 = FUN_0800cad0(auStack_34,0x1c);
    bVar4 = uVar3 == local_18 >> 0x10;
    if (bVar4) {
      FUN_080031a4(param_1,auStack_30,0x18);
    }
    else {
      FUN_08009e98(DAT_0800ccc4);
      FUN_08009e98(DAT_0800ccc8);
    }
  }
  return bVar4;
}



/* ===== FUN_0800cccc @ 0x800CCCC ===== */

int FUN_0800cccc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_5c;
  undefined1 auStack_58 [48];
  uint local_28;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  iVar2 = FUN_0800c910(0);
  iVar4 = DAT_0800cd90 + iVar2 * 0x38;
  iVar5 = DAT_0800cd94 + iVar2 * 0x38;
  FUN_080031d6(&local_5c,0x38);
  local_5c = 0xaa;
  FUN_080031a4(auStack_58,&uStack_10,0x30);
  iVar3 = FUN_0800cad0(&local_5c,0x34);
  local_28 = local_28 & 0xffff | iVar3 << 0x10;
  if (iVar2 == 0) {
    FUN_08009e98(DAT_0800cd90);
  }
  if (iVar4 + 0x38U < DAT_0800cd94 - 1U) {
    iVar2 = FUN_0800c960(iVar4,&local_5c,0x38);
    FUN_0800c960(iVar5,&local_5c,0x38);
  }
  else {
    iVar2 = FUN_0800a0ac(DAT_0800cd90,&local_5c,0x38);
    FUN_0800a0ac(DAT_0800cd94,&local_5c,0x38);
  }
  pbVar1 = DAT_0800cd98;
  if (iVar2 == 0) {
    *DAT_0800cd98 = *DAT_0800cd98 + 1;
    if (3 < *pbVar1) {
      FUN_08009e98(DAT_0800cd90);
      FUN_08009e98(DAT_0800cd94);
    }
  }
  else {
    *DAT_0800cd98 = 0;
  }
  return iVar2;
}



/* ===== FUN_0800cd9c @ 0x800CD9C ===== */

int FUN_0800cd9c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_44;
  undefined1 auStack_40 [24];
  uint local_28;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  iVar2 = FUN_0800c8c4(0);
  iVar4 = DAT_0800ce58 + iVar2 * 0x20;
  iVar5 = DAT_0800ce5c + iVar2 * 0x20;
  FUN_080031d6(&local_44,0x20);
  local_44 = 0xaa;
  FUN_080031a4(auStack_40,&uStack_10,0x18);
  iVar3 = FUN_0800cad0(&local_44,0x1c);
  local_28 = local_28 & 0xffff | iVar3 << 0x10;
  if (iVar2 == 0) {
    FUN_08009e98(DAT_0800ce58);
  }
  if (iVar4 + 0x20U < DAT_0800ce5c - 1U) {
    iVar2 = FUN_0800ca18(iVar4,&local_44,0x20);
    FUN_0800ca18(iVar5,&local_44,0x20);
  }
  else {
    iVar2 = FUN_0800a0ac(DAT_0800ce58,&local_44,0x20);
    FUN_0800a0ac(DAT_0800ce5c,&local_44,0x20);
  }
  pbVar1 = DAT_0800ce60;
  if (iVar2 == 0) {
    *DAT_0800ce60 = *DAT_0800ce60 + 1;
    if (3 < *pbVar1) {
      FUN_08009e98(DAT_0800ce58);
      FUN_08009e98(DAT_0800ce5c);
    }
  }
  else {
    *DAT_0800ce60 = 0;
  }
  return iVar2;
}



/* ===== FUN_0800ce64 @ 0x800CE64 ===== */

undefined4 FUN_0800ce64(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  FUN_0800b7ca(param_1,1);
  iVar2 = 0x10000;
  do {
    iVar1 = FUN_0800b874(param_1,0x20000);
    if (iVar1 == 0) {
      return 0;
    }
    bVar3 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar3);
  return 2;
}



/* ===== FUN_0800ce98 @ 0x800CE98 ===== */

void FUN_0800ce98(undefined4 param_1)

{
  undefined4 in_stack_00000000;
  char in_stack_00000008;
  undefined4 in_stack_0000000c;
  undefined4 in_stack_00000010;
  char in_stack_00000014;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  
  FUN_0800b7f4(param_1);
  if (in_stack_00000000._3_1_ != '\x01') {
    FUN_0800dc5c((int)in_stack_00000008,in_stack_0000000c,in_stack_00000010,0);
    FUN_0800dc5c((int)in_stack_00000014,in_stack_00000018,in_stack_0000001c,0);
  }
  return;
}



/* ===== FUN_0800cecc @ 0x800CECC ===== */

void FUN_0800cecc(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,uint param_5
                 )

{
  bool bVar1;
  int local_28;
  undefined2 local_24;
  undefined1 local_21;
  undefined1 local_20;
  undefined4 local_1c;
  uint local_18;
  undefined2 local_4;
  undefined2 local_2;
  
  FUN_0800a7b0(&local_24);
  local_4 = (undefined2)param_4;
  local_24 = local_4;
  local_20 = 0;
  local_1c = 1;
  local_21 = 0;
  FUN_0800a5c8(param_2,&local_24);
  local_2 = (undefined2)(param_4 >> 0x10);
  local_24 = local_2;
  local_20 = 0;
  local_1c = 1;
  local_21 = 0;
  FUN_0800a5c8(param_3,&local_24);
  FUN_0800a7e2(param_2,param_4 & 0xffff,0);
  FUN_0800a7e2(param_3,local_2,0);
  local_28 = 1000;
  do {
    bVar1 = local_28 != 0;
    local_28 = local_28 + -1;
  } while (bVar1);
  local_24 = local_4;
  local_21 = 0;
  local_1c = 0x12;
  local_18 = param_5 & 0xff;
  local_20 = 1;
  FUN_0800a5c8(param_2,&local_24);
  local_24 = local_2;
  local_21 = 0;
  local_1c = 0x12;
  local_18 = param_5 >> 8 & 0xff;
  local_20 = 1;
  FUN_0800a5c8(param_3,&local_24);
  return;
}



/* ===== FUN_0800cf94 @ 0x800CF94 ===== */

void FUN_0800cf94(int *param_1)

{
  undefined1 auStack_30 [36];
  
  FUN_080031a4(auStack_30,param_1 + 4,0x24);
  FUN_0800ce98(*param_1,param_1[1],param_1[2],param_1[3]);
  if (*(char *)((int)param_1 + 0x13) == '\x02') {
    FUN_080031d6(DAT_0800d090,0x848);
    FUN_0800e464(DAT_0800d094,DAT_0800d090,0x6a,0x14);
  }
  else {
    FUN_080031a4(auStack_30,param_1 + 4,0x24);
    FUN_0800d300(*param_1,param_1[1],param_1[2],param_1[3]);
  }
  FUN_080031a4(auStack_30,param_1 + 4,0x24);
  FUN_0800ce98(*param_1,param_1[1],param_1[2],param_1[3]);
  FUN_080031a4(auStack_30,param_1 + 4,0x24);
  FUN_0800d0f8(*param_1,param_1[1],param_1[2],param_1[3]);
  if (*(char *)((int)param_1 + 0x13) != '\x01') {
    FUN_0800dc5c((int)(char)param_1[6],param_1[7],param_1[8],1);
    FUN_0800dc5c((int)(char)param_1[9],param_1[10],param_1[0xb],1);
    FUN_0800b7e2(*param_1,0x700,1);
  }
  FUN_080031a4(auStack_30,param_1 + 4,0x24);
  FUN_0800cecc(*param_1,param_1[1],param_1[2],param_1[3]);
  FUN_080031a4(auStack_30,param_1 + 4,0x24);
  FUN_0800d098(*param_1,param_1[1],param_1[2],param_1[3]);
  if (((*(ushort *)(*param_1 + 4) & 0x700) == 0x700) && ((*(ushort *)*param_1 & 0x401) == 0x401)) {
    *(undefined1 *)(param_1 + 0x43) = 1;
  }
  else {
    *(undefined1 *)(param_1 + 0x43) = 0;
  }
  return;
}



/* ===== FUN_0800d098 @ 0x800D098 ===== */

undefined8
FUN_0800d098(ushort *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)

{
  ushort uVar1;
  undefined2 in_stack_00000020;
  undefined4 local_28;
  undefined2 local_24;
  undefined2 local_22;
  ushort local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined2 uStack_1a;
  
  if (param_5._3_1_ == '\x02') {
    uVar1 = (ushort)param_5._2_1_;
  }
  else {
    uVar1 = 0;
    *param_1 = *param_1 & 0xf7ff;
  }
  local_24 = 0;
  local_22 = 0xbfff;
  _local_20 = CONCAT22(0x400,uVar1);
  _local_1c = CONCAT22((short)((uint)param_4 >> 0x10),in_stack_00000020);
  local_28 = param_6;
  FUN_0800b8c8(param_1,&local_28);
  FUN_0800b82c(param_1,1);
  return CONCAT26(local_22,CONCAT24(local_24,local_28));
}



/* ===== FUN_0800d0f8 @ 0x800D0F8 ===== */

void FUN_0800d0f8(int param_1)

{
  if (param_1 == DAT_0800d134) {
    FUN_0800e6a4(8,1);
    FUN_0800e664(0x200000);
  }
  else {
    FUN_0800e6a4(4,1);
    FUN_0800e664(0x400000);
  }
  FUN_0800e6a4(1);
  return;
}



/* ===== FUN_0800d138 @ 0x800D138 ===== */

undefined4 FUN_0800d138(ushort *param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  bool bVar5;
  undefined1 *in_stack_00000024;
  uint in_stack_00000028;
  
  if (in_stack_00000028 == 1) {
    FUN_0800b7ca(param_1,0);
    FUN_0800b85c(param_1,1);
  }
  else if (in_stack_00000028 == 2) {
    *param_1 = *param_1 | 0x800;
    FUN_0800b7ca(param_1,0);
  }
  iVar4 = 0x10000;
  do {
    while( true ) {
      while( true ) {
        puVar3 = in_stack_00000024;
        if ((int)in_stack_00000028 < 1) {
          return 0;
        }
        if ((int)in_stack_00000028 < 4) break;
        while (iVar2 = FUN_0800b794(param_1,DAT_0800d2fc), iVar2 == 0) {
          bVar5 = iVar4 == 0;
          iVar4 = iVar4 + -1;
          if (bVar5) {
            FUN_0800b85c(param_1,1);
            return 3;
          }
        }
        uVar1 = FUN_0800b9b4(param_1);
        *puVar3 = uVar1;
        in_stack_00000028 = in_stack_00000028 - 1 & 0xff;
        iVar2 = FUN_0800b874(param_1,DAT_0800d2f8 + -0x3c);
        in_stack_00000024 = puVar3 + 1;
        if (iVar2 != 0) {
          uVar1 = FUN_0800b9b4(param_1);
          puVar3[1] = uVar1;
          in_stack_00000028 = in_stack_00000028 - 1 & 0xff;
          in_stack_00000024 = puVar3 + 2;
        }
      }
      if (in_stack_00000028 == 1) break;
      if (in_stack_00000028 == 2) {
        while (iVar2 = FUN_0800b874(param_1,DAT_0800d2f8 + -0x3c), iVar2 == 0) {
          bVar5 = iVar4 == 0;
          iVar4 = iVar4 + -1;
          if (bVar5) {
            FUN_0800b85c(param_1,1);
            return 3;
          }
        }
        FUN_0800b85c(param_1,1);
        uVar1 = FUN_0800b9b4(param_1);
        *puVar3 = uVar1;
        uVar1 = FUN_0800b9b4(param_1);
        puVar3[1] = uVar1;
        in_stack_00000028 = 0;
        in_stack_00000024 = puVar3 + 2;
      }
      else {
        while (iVar2 = FUN_0800b874(param_1,DAT_0800d2f8 + -0x3c), iVar2 == 0) {
          bVar5 = iVar4 == 0;
          iVar4 = iVar4 + -1;
          if (bVar5) {
            FUN_0800b85c(param_1,1);
            return 3;
          }
        }
        FUN_0800b7ca(param_1,0);
        uVar1 = FUN_0800b9b4(param_1);
        *puVar3 = uVar1;
        while (iVar2 = FUN_0800b874(param_1,DAT_0800d2f8 + -0x3c), iVar2 == 0) {
          bVar5 = iVar4 == 0;
          iVar4 = iVar4 + -1;
          if (bVar5) {
            FUN_0800b85c(param_1,1);
            return 3;
          }
        }
        FUN_0800b85c(param_1,1);
        uVar1 = FUN_0800b9b4(param_1);
        puVar3[1] = uVar1;
        uVar1 = FUN_0800b9b4(param_1);
        puVar3[2] = uVar1;
        in_stack_00000028 = ((in_stack_00000028 - 1 & 0xff) - 1 & 0xff) - 1 & 0xff;
        in_stack_00000024 = puVar3 + 3;
      }
    }
    while (iVar2 = FUN_0800b874(param_1,DAT_0800d2f8), iVar2 == 0) {
      bVar5 = iVar4 == 0;
      iVar4 = iVar4 + -1;
      if (bVar5) {
        FUN_0800b85c(param_1,1);
        return 3;
      }
    }
    uVar1 = FUN_0800b9b4(param_1);
    *puVar3 = uVar1;
    in_stack_00000028 = 0;
    in_stack_00000024 = puVar3 + 1;
  } while( true );
}



/* ===== FUN_0800d300 @ 0x800D300 ===== */

void FUN_0800d300(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4)

{
  byte bVar1;
  bool bVar2;
  int local_2c;
  undefined2 local_28 [4];
  undefined4 local_20;
  undefined4 local_1c;
  
  FUN_0800a7b0(local_28);
  local_20 = 1;
  local_1c = 0xf;
  local_28[0] = param_4;
  FUN_0800a5c8(param_2,local_28);
  local_2c = 1000;
  do {
    bVar2 = local_2c != 0;
    local_2c = local_2c + -1;
  } while (bVar2);
  for (bVar1 = 0; bVar1 < 9; bVar1 = bVar1 + 1) {
    FUN_0800a7e2(param_2,param_4,0);
    local_2c = 0x14;
    do {
      bVar2 = local_2c != 0;
      local_2c = local_2c + -1;
    } while (bVar2);
    FUN_0800a7e2(param_2,param_4,1);
    local_2c = 0x14;
    do {
      bVar2 = local_2c != 0;
      local_2c = local_2c + -1;
    } while (bVar2);
  }
  return;
}



/* ===== FUN_0800d384 @ 0x800D384 ===== */

void FUN_0800d384(int *param_1)

{
  undefined1 auStack_30 [40];
  
  if ((char)param_1[0x43] == '\0') {
    if (*(char *)((int)param_1 + 0x13) != '\x02') {
      FUN_0800b85c(*param_1,1);
    }
    FUN_0800b82c(*param_1,0);
    FUN_080031a4(auStack_30,param_1 + 4,0x24);
    FUN_0800dc84(*param_1,param_1[1],param_1[2],param_1[3]);
    if (*param_1 == DAT_0800d46c) {
      FUN_0800e684(0x400000);
      FUN_0800e684(0x400000,0);
      FUN_0800e664(0x400000,0);
      *(uint *)param_1[1] = *(uint *)param_1[1] | 0xf;
      FUN_0800e6a4(1,0);
      FUN_0800e6a4(4,0);
      FUN_0800e684(0x400000);
      FUN_0800e684(0x400000,0);
    }
    else if (*param_1 == DAT_0800d470) {
      FUN_0800e684(0x200000);
      FUN_0800e684(0x200000,0);
      FUN_0800e664(0x200000,0);
      *(uint *)param_1[1] = *(uint *)param_1[1] | 0xf;
      FUN_0800e6a4(1,0);
      FUN_0800e6a4(8,0);
      FUN_0800e684(0x200000);
      FUN_0800e684(0x200000,0);
    }
    FUN_0800cf94(param_1);
  }
  return;
}



/* ===== FUN_0800d474 @ 0x800D474 ===== */

undefined4 FUN_0800d474(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined1 *in_stack_00000024;
  uint in_stack_00000028;
  
  do {
    if ((int)in_stack_00000028 < 1) {
      return 0;
    }
    FUN_0800b9ce(param_1,*in_stack_00000024);
    in_stack_00000024 = in_stack_00000024 + 1;
    in_stack_00000028 = in_stack_00000028 - 1 & 0xff;
    iVar2 = 0x10000;
    while (iVar1 = FUN_0800b794(param_1,DAT_0800d4c8), iVar1 == 0) {
      bVar3 = iVar2 == 0;
      iVar2 = iVar2 + -1;
      if (bVar3) {
        FUN_0800b7ca(param_1,0);
        FUN_0800b85c(param_1,1);
        return 3;
      }
    }
  } while( true );
}



/* ===== FUN_0800d4cc @ 0x800D4CC ===== */

undefined4 FUN_0800d4cc(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined4 in_stack_00000024;
  int in_stack_00000028;
  
  uVar3 = DAT_0800d530;
  if ((in_stack_00000028 != 0) && (uVar3 = 0, in_stack_00000028 == 1)) {
    uVar3 = DAT_0800d534;
  }
  FUN_0800b9bc(param_1,in_stack_00000024,in_stack_00000028);
  iVar2 = 0x10000;
  do {
    iVar1 = FUN_0800b794(param_1,uVar3);
    if (iVar1 != 0) {
      return 0;
    }
    bVar4 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar4);
  FUN_0800b7ca(param_1,0);
  FUN_0800b85c(param_1,1);
  return 3;
}



/* ===== FUN_0800d538 @ 0x800D538 ===== */

undefined4 FUN_0800d538(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  FUN_0800b844(param_1,1);
  iVar2 = 0x10000;
  do {
    iVar1 = FUN_0800b794(param_1,DAT_0800d57c);
    if (iVar1 != 0) {
      return 0;
    }
    bVar3 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar3);
  FUN_0800b7ca(param_1,0);
  FUN_0800b85c(param_1,1);
  return 3;
}



/* ===== FUN_0800d580 @ 0x800D580 ===== */

undefined4 FUN_0800d580(undefined4 param_1)

{
  FUN_0800b7ca(param_1,0);
  FUN_0800b85c(param_1,1);
  return 0;
}



/* ===== FUN_0800d59c @ 0x800D59C ===== */

void FUN_0800d59c(undefined4 *param_1)

{
  byte *pbVar1;
  int iVar2;
  
  FUN_0800d8c8(param_1);
  iVar2 = FUN_0800d968(param_1);
  if (iVar2 == 0) {
    FUN_0800b7ca(*param_1,0);
    *(undefined1 *)(param_1 + 0x43) = 0;
    FUN_0800b7e2(*param_1,0x700,0);
  }
  else if (*(char *)((int)param_1 + 0x13) == '\0') {
    FUN_0800b8ae(*param_1);
    pbVar1 = DAT_0800d614;
    *DAT_0800d614 = *DAT_0800d614 + 1;
    if (99 < *pbVar1) {
      FUN_0800b85c(*param_1,1);
      *DAT_0800d614 = 0;
      FUN_0800b7ca(*param_1,0);
      *(undefined1 *)(param_1 + 0x43) = 0;
      FUN_0800b7e2(*param_1,0x700,0);
    }
  }
  return;
}



/* ===== FUN_0800d618 @ 0x800D618 ===== */

void FUN_0800d618(undefined4 *param_1)

{
  short sVar1;
  ushort uVar2;
  bool bVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  
  bVar3 = false;
  FUN_0800d8c8(param_1);
  iVar5 = FUN_0800d968(param_1);
  if (iVar5 == 0) {
    FUN_0800b7ca(*param_1,0);
    *(undefined1 *)(param_1 + 0x43) = 0;
    FUN_0800b7e2(*param_1,0x700,0);
  }
  else {
    uVar6 = FUN_0800b8ae(*param_1);
    if (*(char *)((int)param_1 + 0x13) == '\0') {
      *DAT_0800d834 = 0;
      if ((((DAT_0800d838 & uVar6) == 0) && ((uVar6 & 0x1000100) == 0)) &&
         ((DAT_0800d83c & uVar6) == 0)) {
        if ((DAT_0800d840 & uVar6) == 0) {
          if ((DAT_0800d840 + 0x7f & uVar6) == 0) {
            if ((DAT_0800d840 + 1 & uVar6) == 0) {
              if ((DAT_0800d840 + 0x3f & uVar6) == 0) {
                bVar3 = true;
              }
              else if (*(ushort *)((int)param_1 + 0x36) < 100) {
                uVar4 = FUN_0800b9b4(*param_1);
                uVar2 = *(ushort *)((int)param_1 + 0x36);
                *(ushort *)((int)param_1 + 0x36) = uVar2 + 1;
                *(undefined1 *)((int)param_1 + uVar2 + 0x39) = uVar4;
                if ((uint)*(ushort *)((int)param_1 + 0x36) == *(ushort *)(param_1 + 0xd) - 1) {
                  FUN_0800b7ca(*param_1,0);
                  if (*(char *)(param_1 + 0x43) == '\x01') {
                    *(undefined1 *)(param_1 + 0x43) = 2;
                    FUN_0800b85c(*param_1,1);
                  }
                }
                else if (*(short *)((int)param_1 + 0x36) == *(short *)(param_1 + 0xd)) {
                  *(undefined1 *)(param_1 + 0x43) = 3;
                }
              }
            }
            else {
              *(undefined1 *)(param_1 + 0x43) = 1;
              if (*DAT_0800d844 != '\0') {
                if (*(short *)(param_1 + 0xd) == 1) {
                  *(undefined1 *)(param_1 + 0x43) = 2;
                  FUN_0800b7ca(*param_1,0);
                  FUN_0800b85c(*param_1,1);
                }
                else if (*(short *)(param_1 + 0xd) == 2) {
                  *(ushort *)*param_1 = *(ushort *)*param_1 | 0x800;
                  FUN_0800b7ca(*param_1,0);
                }
              }
            }
          }
          else {
            if ((DAT_0800d840 + 1 & uVar6) != 0) {
              *(undefined1 *)(param_1 + 0x43) = 1;
            }
            if (*(ushort *)(param_1 + 0x28) < *(ushort *)((int)param_1 + 0x9e)) {
              uVar2 = *(ushort *)(param_1 + 0x28);
              *(ushort *)(param_1 + 0x28) = uVar2 + 1;
              FUN_0800b9ce(*param_1,*(undefined1 *)((int)param_1 + uVar2 + 0xa3));
            }
            else if (((*(short *)(param_1 + 0x28) == *(short *)((int)param_1 + 0x9e)) &&
                     ((DAT_0800d840 + 3 & uVar6) != 0)) && (*(char *)(param_1 + 0x43) == '\x01')) {
              if (*DAT_0800d84c == '\0') {
                FUN_0800b85c(*param_1,1);
              }
              else {
                *DAT_0800d844 = '\x01';
                FUN_0800b7ca(*param_1,1);
                FUN_0800b844(*param_1,1);
              }
              *(undefined1 *)(param_1 + 0x43) = 4;
            }
          }
        }
        else if (*DAT_0800d844 == '\0') {
          FUN_0800b9bc(*param_1,*DAT_0800d848,0);
        }
        else {
          FUN_0800b9bc(*param_1,*DAT_0800d848,1);
        }
      }
      else {
        FUN_0800b82c(*param_1,0);
        FUN_0800b82c(*param_1,1);
        bVar3 = true;
      }
      if (bVar3) {
        sVar1 = *DAT_0800d850;
        *DAT_0800d850 = *DAT_0800d850 + -1;
        if (sVar1 == 0) {
          FUN_0800b85c(*param_1,1);
          FUN_0800b7ca(*param_1,0);
          *(undefined1 *)(param_1 + 0x43) = 0;
          FUN_0800b7e2(*param_1,0x700,0);
        }
      }
      else {
        *DAT_0800d850 = 1000;
      }
    }
  }
  return;
}



/* ===== FUN_0800d854 @ 0x800D854 ===== */

void FUN_0800d854(int param_1)

{
  *(undefined4 *)(param_1 + 0x108) = 0x10000;
  return;
}



/* ===== FUN_0800d860 @ 0x800D860 ===== */

undefined4 FUN_0800d860(int param_1)

{
  int iVar1;
  
  *DAT_0800d8c0 = 0x10000;
  do {
    if (*(char *)(param_1 + 0x10c) == '\x03') {
      *DAT_0800d8c0 = 0x10000;
      do {
        iVar1 = FUN_0800b874(DAT_0800d8c4,0x20000);
        if (iVar1 == 0) {
          return 0;
        }
        iVar1 = *DAT_0800d8c0;
        *DAT_0800d8c0 = iVar1 + -1;
      } while ((iVar1 != 0) && (*(char *)(param_1 + 0x10c) != '\0'));
      return 3;
    }
    iVar1 = *DAT_0800d8c0;
    *DAT_0800d8c0 = iVar1 + -1;
  } while ((iVar1 != 0) && (*(char *)(param_1 + 0x10c) != '\0'));
  return 3;
}



/* ===== FUN_0800d8c8 @ 0x800D8C8 ===== */

void FUN_0800d8c8(int param_1)

{
  if (*(int *)(param_1 + 0x108) != 0) {
    *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + -1;
  }
  return;
}



/* ===== FUN_0800d8dc @ 0x800D8DC ===== */

undefined4 FUN_0800d8dc(undefined4 *param_1)

{
  int iVar1;
  
  *DAT_0800d95c = 0;
  if (*(char *)(param_1 + 0x43) == '\x01') {
    *(undefined1 *)(param_1 + 0x43) = 2;
    FUN_0800b844(*param_1,1);
  }
  *DAT_0800d960 = 0x10000;
  do {
    if (*(char *)(param_1 + 0x43) == '\x04') {
      if (*DAT_0800d964 == '\0') {
        *DAT_0800d960 = 0x10000;
        while (iVar1 = FUN_0800b874(*param_1,0x20000), iVar1 != 0) {
          iVar1 = *DAT_0800d960;
          *DAT_0800d960 = iVar1 + -1;
          if ((iVar1 == 0) || (*(char *)(param_1 + 0x43) == '\0')) {
            return 3;
          }
        }
      }
      return 0;
    }
    iVar1 = *DAT_0800d960;
    *DAT_0800d960 = iVar1 + -1;
  } while ((iVar1 != 0) && (*(char *)(param_1 + 0x43) != '\0'));
  return 3;
}



/* ===== FUN_0800d968 @ 0x800D968 ===== */

bool FUN_0800d968(int param_1)

{
  return *(int *)(param_1 + 0x108) != 0;
}



/* ===== FUN_0800d978 @ 0x800D978 ===== */

uint FUN_0800d978(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,int *param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined1 auStack_58 [36];
  undefined4 *local_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  
  uVar7 = 0;
  if (*param_6 == 0) {
    uVar7 = 1;
  }
  else {
    uStack_2c = param_1;
    uStack_28 = param_2;
    uStack_24 = param_3;
    uStack_20 = param_4;
    if (*(char *)((int)param_6 + 0x13) == '\0') {
      *DAT_0800db04 = 1;
      *(undefined2 *)((int)param_6 + 0x36) = 0;
      *(short *)(param_6 + 0xd) = (short)param_5;
      *(short *)((int)param_6 + 0x9e) = (short)param_3;
      *(undefined2 *)(param_6 + 0x28) = 0;
      FUN_080031a4((int)param_6 + 0xa3,&uStack_28,param_3);
      *DAT_0800db08 = (char)param_1;
      *DAT_0800db0c = *DAT_0800db0c & 0xf7ff;
      uVar7 = FUN_0800d8dc(param_6);
      if ((uVar7 == 0) || ((char)param_6[0x43] != '\0')) {
        *(undefined1 *)(param_6 + 0x43) = 1;
      }
      if ((uVar7 == 0) &&
         ((uVar7 = FUN_0800d860(param_6), uVar7 == 0 || ((char)param_6[0x43] != '\0')))) {
        *(undefined1 *)(param_6 + 0x43) = 1;
      }
      if (uVar7 == 0) {
        FUN_080031a4(param_4,(int)param_6 + 0x39,param_5);
      }
    }
    else if (*(char *)((int)param_6 + 0x13) == '\x01') {
      FUN_08004d1c();
      FUN_080031a4(auStack_58,param_6 + 4,0x24);
      uVar1 = FUN_0800ce64(*param_6,param_6[1],param_6[2],param_6[3]);
      *(ushort *)*param_6 = *(ushort *)*param_6 & 0xf7ff;
      FUN_080031a4(auStack_58,param_6 + 4,0x24);
      uVar2 = FUN_0800d538(*param_6,param_6[1],param_6[2],param_6[3]);
      uStack_30 = 0;
      local_34 = (undefined4 *)param_1;
      FUN_080031a4(auStack_58,param_6 + 4,0x24);
      uVar3 = FUN_0800d4cc(*param_6,param_6[1],param_6[2],param_6[3]);
      local_34 = &uStack_28;
      uStack_30 = param_3;
      FUN_080031a4(auStack_58,param_6 + 4,0x24);
      uVar4 = FUN_0800d474(*param_6,param_6[1],param_6[2],param_6[3]);
      FUN_080031a4(auStack_58,param_6 + 4,0x24);
      uVar5 = FUN_0800d538(*param_6,param_6[1],param_6[2],param_6[3]);
      uStack_30 = 1;
      local_34 = (undefined4 *)param_1;
      FUN_080031a4(auStack_58,param_6 + 4,0x24);
      uVar6 = FUN_0800d4cc(*param_6,param_6[1],param_6[2],param_6[3]);
      uStack_30 = param_5;
      local_34 = (undefined4 *)param_4;
      FUN_080031a4(auStack_58,param_6 + 4,0x24);
      uVar7 = FUN_0800d138(*param_6,param_6[1],param_6[2],param_6[3]);
      uVar7 = uVar1 | uVar2 | uVar3 | uVar4 | uVar5 | uVar6 | uVar7;
      FUN_08004d34();
    }
    if (uVar7 == 0) {
      *DAT_0800db10 = 0;
    }
    else {
      *DAT_0800db10 = *DAT_0800db10 + 1;
    }
    if (2 < *DAT_0800db10) {
      *(undefined1 *)(param_6 + 0x43) = 0;
      *DAT_0800db10 = 0;
    }
  }
  return uVar7;
}



/* ===== FUN_0800db14 @ 0x800DB14 ===== */

uint FUN_0800db14(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,
                 undefined4 param_5,int *param_6)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 auStack_58 [36];
  undefined4 *local_34;
  int iStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  int iStack_24;
  undefined4 uStack_20;
  
  uVar6 = 0;
  if (*param_6 == 0) {
    uVar6 = 1;
  }
  else {
    uStack_2c = param_1;
    uStack_28 = param_2;
    iStack_24 = param_3;
    uStack_20 = param_4;
    if (*(char *)((int)param_6 + 0x13) == '\0') {
      *DAT_0800dc50 = 0;
      *(short *)((int)param_6 + 0x9e) = (short)param_3 + (short)param_5;
      *(undefined2 *)(param_6 + 0x28) = 0;
      *DAT_0800dc54 = (char)param_1;
      FUN_080031a4((int)param_6 + 0xa3,&uStack_28,param_3);
      FUN_080031a4((int)param_6 + param_3 + 0xa3,param_4,param_5);
      uVar6 = FUN_0800d8dc(param_6);
      if ((uVar6 == 0) || ((char)param_6[0x43] != '\0')) {
        *(undefined1 *)(param_6 + 0x43) = 1;
      }
    }
    else if (*(char *)((int)param_6 + 0x13) == '\x01') {
      FUN_08004d1c();
      FUN_080031a4(auStack_58,param_6 + 4,0x24);
      uVar1 = FUN_0800ce64(*param_6,param_6[1],param_6[2],param_6[3]);
      FUN_080031a4(auStack_58,param_6 + 4,0x24);
      uVar2 = FUN_0800d538(*param_6,param_6[1],param_6[2],param_6[3]);
      iStack_30 = 0;
      local_34 = (undefined4 *)param_1;
      FUN_080031a4(auStack_58,param_6 + 4,0x24);
      uVar3 = FUN_0800d4cc(*param_6,param_6[1],param_6[2],param_6[3]);
      local_34 = &uStack_28;
      iStack_30 = param_3;
      FUN_080031a4(auStack_58,param_6 + 4,0x24);
      uVar4 = FUN_0800d474(*param_6,param_6[1],param_6[2],param_6[3]);
      iStack_30 = param_5;
      local_34 = (undefined4 *)param_4;
      FUN_080031a4(auStack_58,param_6 + 4,0x24);
      uVar5 = FUN_0800d474(*param_6,param_6[1],param_6[2],param_6[3]);
      FUN_080031a4(auStack_58,param_6 + 4,0x24);
      uVar6 = FUN_0800d580(*param_6,param_6[1],param_6[2],param_6[3]);
      uVar6 = uVar1 | uVar2 | uVar3 | uVar4 | uVar5 | uVar6;
      FUN_08004d34();
    }
    if (uVar6 == 0) {
      *DAT_0800dc58 = 0;
    }
    else {
      *DAT_0800dc58 = *DAT_0800dc58 + 1;
    }
    if (2 < *DAT_0800dc58) {
      *(undefined1 *)(param_6 + 0x43) = 0;
      *DAT_0800dc58 = 0;
    }
  }
  return uVar6;
}



/* ===== FUN_0800dc5c @ 0x800DC5C ===== */

void FUN_0800dc5c(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4)

{
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  undefined1 local_15;
  
  _local_18 = CONCAT13(param_4,CONCAT12(param_3,CONCAT11(param_2,param_1)));
  FUN_0800e0b4(&local_18);
  return;
}



/* ===== FUN_0800dc84 @ 0x800DC84 ===== */

undefined8 FUN_0800dc84(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  ushort local_28;
  undefined1 uStack_26;
  undefined1 local_25;
  uint local_24;
  undefined4 local_20;
  undefined4 uStack_1c;
  ushort local_4;
  ushort local_2;
  
  local_28 = (ushort)param_1;
  uStack_26 = (undefined1)((uint)param_1 >> 0x10);
  local_25 = (undefined1)((uint)param_1 >> 0x18);
  local_24 = param_2;
  local_20 = param_3;
  uStack_1c = param_4;
  FUN_0800a7b0(&local_28);
  local_4 = (ushort)param_4;
  local_2 = (ushort)((uint)param_4 >> 0x10);
  local_28 = local_4 | local_2;
  local_24 = local_24 & 0xffffff00;
  local_20 = 3;
  local_25 = 1;
  FUN_0800a5c8(param_2,&local_28);
  return CONCAT44(local_24,CONCAT13(local_25,CONCAT12(uStack_26,local_28)));
}



/* ===== memory_management_fault_Handler @ 0x800DCBA ===== */

void memory_management_fault_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_0800dcbc @ 0x800DCBC ===== */

void FUN_0800dcbc(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_0800dd50 @ 0x800DD50 ===== */

undefined4 FUN_0800dd50(ushort *param_1)

{
  char cVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  undefined4 uVar5;
  uint uVar6;
  
  pcVar3 = DAT_0800de68;
  *DAT_0800de68 = (char)param_1[1];
  pcVar3[1] = *(char *)((int)param_1 + 3);
  pcVar4 = DAT_0800de68;
  cVar1 = pcVar3[1];
  if (cVar1 == '\x03') {
    DAT_0800de68[2] = (char)param_1[2];
    pcVar4[3] = *(char *)((int)param_1 + 5);
    pcVar4[4] = (char)param_1[3];
    pcVar4[5] = *(char *)((int)param_1 + 7);
  }
  else if (cVar1 == '\x06') {
    DAT_0800de68[2] = (char)param_1[2];
    pcVar4[3] = *(char *)((int)param_1 + 5);
    pcVar4[7] = (char)param_1[3];
    DAT_0800de68[8] = *(char *)((int)param_1 + 7);
  }
  else if (cVar1 == '\x10') {
    DAT_0800de68[2] = (char)param_1[2];
    pcVar4[3] = *(char *)((int)param_1 + 5);
    pcVar4[4] = (char)param_1[3];
    pcVar4[5] = *(char *)((int)param_1 + 7);
    pcVar4[6] = (char)param_1[4];
    if ((byte)pcVar4[6] < 0x83) {
      FUN_080031a4(DAT_0800de68 + 7,(int)param_1 + 9,DAT_0800de68[6]);
    }
  }
  if ((*param_1 < 8) || (0x82 < *param_1)) {
    uVar5 = 0;
  }
  else {
    DAT_0800de68[0x9d] = *(char *)((int)param_1 + (uint)*param_1);
    pcVar3 = DAT_0800de68;
    DAT_0800de68[0x9e] = *(char *)((int)param_1 + *param_1 + 1);
    cVar1 = pcVar3[0x9d];
    cVar2 = pcVar3[0x9e];
    uVar6 = FUN_0800aa50(param_1 + 1,*param_1 - 2);
    if ((((uVar6 == CONCAT11(cVar1,cVar2)) && (*DAT_0800de68 == 'n')) &&
        ((DAT_0800de68[1] == '\x10' || ((DAT_0800de68[1] == '\x03' || (DAT_0800de68[1] == '\x06'))))
        )) && ((byte)DAT_0800de68[6] < 0x83)) {
      uVar5 = 1;
    }
    else {
      uVar5 = 0;
    }
  }
  return uVar5;
}



/* ===== FUN_0800de6c @ 0x800DE6C ===== */

void FUN_0800de6c(undefined1 *param_1,undefined1 *param_2,char *param_3)

{
  char cVar1;
  undefined2 uVar2;
  uint uVar3;
  
  *param_2 = *param_1;
  param_2[1] = param_1[1];
  cVar1 = param_1[1];
  if (cVar1 == '\x03') {
    param_2[2] = param_1[6];
    FUN_080031a4(param_2 + 3,param_1 + 7,param_1[6]);
    uVar3 = (uint)(byte)(param_1[6] + 3);
  }
  else if (cVar1 == '\x06') {
    param_2[2] = param_1[2];
    param_2[3] = param_1[3];
    param_2[4] = param_1[7];
    param_2[5] = param_1[8];
    uVar3 = 6;
  }
  else {
    if (cVar1 != '\x10') {
      return;
    }
    param_2[2] = param_1[2];
    param_2[3] = param_1[3];
    param_2[4] = param_1[4];
    param_2[5] = param_1[5];
    uVar3 = 6;
  }
  uVar2 = FUN_0800aa50(param_2,uVar3);
  param_2[uVar3] = (char)((ushort)uVar2 >> 8);
  param_2[uVar3 + 1] = (char)uVar2;
  *param_3 = (char)uVar3 + '\x02';
  return;
}



/* ===== FUN_0800defc @ 0x800DEFC ===== */

int FUN_0800defc(int param_1,undefined1 *param_2)

{
  uint uVar1;
  
  *param_2 = 0;
  uVar1 = 0;
  while( true ) {
    if (1 < uVar1) {
      return 0;
    }
    if (((int)(uint)*(byte *)(DAT_0800df48 + uVar1 * 8 + 4) <= param_1) &&
       (param_1 < (int)((uint)*(byte *)(DAT_0800df48 + uVar1 * 8 + 4) +
                       (uint)*(byte *)(*(int *)(DAT_0800df48 + uVar1 * 8) + 8)))) break;
    uVar1 = uVar1 + 1 & 0xffff;
  }
  *param_2 = 1;
  return DAT_0800df48 + uVar1 * 8;
}



/* ===== FUN_0800df58 @ 0x800DF58 ===== */

undefined4 FUN_0800df58(byte *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined4 uVar2;
  
  if (param_3 == 1) {
    uVar1 = ~(((*param_1 & 3) >> 1) << 3 | (*param_1 & 1) << 2 | ((*param_1 & 0xf) >> 3) << 1 |
             (*param_1 & 7) >> 2);
    if (param_2 == 3) {
      uVar1 = uVar1 & 0xf7;
    }
    else if (param_2 == 2) {
      uVar1 = uVar1 & 0xfb;
    }
    else if (param_2 == 1) {
      uVar1 = uVar1 & 0xfd;
    }
    else if (param_2 == 0) {
      uVar1 = uVar1 & 0xfe;
    }
    else {
      uVar1 = 0xff;
    }
  }
  else if (param_3 == 0) {
    uVar1 = ~(((*param_1 & 3) >> 1) << 3 | (*param_1 & 1) << 2 | ((*param_1 & 0xf) >> 3) << 1 |
             (*param_1 & 7) >> 2) & 0xff;
    if (param_2 == 3) {
      uVar1 = uVar1 | 8;
    }
    else if (param_2 == 2) {
      uVar1 = uVar1 | 4;
    }
    else if (param_2 == 1) {
      uVar1 = uVar1 | 2;
    }
    else if (param_2 == 0) {
      uVar1 = uVar1 | 1;
    }
    else {
      uVar1 = 0xff;
    }
  }
  else {
    uVar1 = 0xff;
  }
  uVar2 = FUN_080175ac(8,0x97,uVar1,1);
  return uVar2;
}



/* ===== FUN_0800e02c @ 0x800E02C ===== */

void FUN_0800e02c(void)

{
  ushort *puVar1;
  
  puVar1 = DAT_0800e094;
  if (((*(byte *)(DAT_0800e088 + 1) & 1) == *DAT_0800e08c) &&
     ((*(byte *)(DAT_0800e088 + 1) & 3) >> 1 == (uint)*DAT_0800e090)) {
    *DAT_0800e094 = 0;
    *(byte *)(DAT_0800e088 + 3) = *(byte *)(DAT_0800e088 + 3) & 0xf7;
  }
  else {
    *DAT_0800e094 = *DAT_0800e094 + 1;
    if (0x31 < *puVar1) {
      *(byte *)(DAT_0800e088 + 3) = (*(byte *)(DAT_0800e088 + 3) & 0xf7) + 8;
      *DAT_0800e094 = 0x32;
    }
  }
  return;
}



/* ===== FUN_0800e098 @ 0x800E098 ===== */

void FUN_0800e098(void)

{
  FUN_08006630();
  FUN_0800f33c();
  FUN_08007274();
  FUN_080068f8();
  FUN_0800e02c();
  return;
}



/* ===== nmi_Handler @ 0x800E0B0 ===== */

void nmi_Handler(void)

{
  return;
}



/* ===== FUN_0800e0b4 @ 0x800E0B4 ===== */

void FUN_0800e0b4(byte *param_1)

{
  uint uVar1;
  
  if (param_1[3] == 0) {
    *(int *)(DAT_0800e120 + ((int)(uint)*param_1 >> 5) * 4) = 1 << (*param_1 & 0x1f);
  }
  else {
    uVar1 = 0x700 - (*DAT_0800e118 & 0x700) >> 8;
    *(char *)(DAT_0800e11c + (uint)*param_1) =
         (char)(((uint)param_1[1] << (4 - uVar1 & 0xff) | (uint)param_1[2] & 0xfU >> (uVar1 & 0xff))
               << 4);
    *(int *)(&DAT_e000e100 + ((int)(uint)*param_1 >> 5) * 4) = 1 << (*param_1 & 0x1f);
  }
  return;
}



/* ===== FUN_0800e124 @ 0x800E124 ===== */

void FUN_0800e124(uint param_1)

{
  *DAT_0800e134 = DAT_0800e130 | param_1;
  return;
}



/* ===== FUN_0800e138 @ 0x800E138 ===== */

bool FUN_0800e138(void)

{
  FUN_08003d78();
  return *DAT_0800e154 == -0x14fc;
}



/* ===== FUN_0800e158 @ 0x800E158 ===== */

undefined4 FUN_0800e158(void)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  undefined1 auStack_2c [32];
  
  FUN_080031d6(auStack_2c,0x20);
  for (uVar2 = 0; uVar2 < 9; uVar2 = uVar2 + 1 & 0xff) {
    FUN_080031a4(auStack_2c,*(undefined4 *)(DAT_0800e1fc + uVar2 * 8 + 4),0x20);
    FUN_08003bdc(0x90);
    iVar1 = 1000;
    do {
      bVar3 = iVar1 != 0;
      iVar1 = iVar1 + -1;
    } while (bVar3);
    iVar1 = FUN_0800480c(0,8,*(undefined2 *)(DAT_0800e1fc + uVar2 * 8),auStack_2c,0x1e);
    if (iVar1 != 1) {
      iVar1 = 1000;
      do {
        bVar3 = iVar1 != 0;
        iVar1 = iVar1 + -1;
      } while (bVar3);
      FUN_0800480c(0,8,*(undefined2 *)(DAT_0800e1fc + uVar2 * 8),auStack_2c,0x1e);
    }
    FUN_08003bdc(0x92);
    iVar1 = 1000;
    do {
      bVar3 = iVar1 != 0;
      iVar1 = iVar1 + -1;
    } while (bVar3);
  }
  return 1;
}



/* ===== FUN_0800e200 @ 0x800E200 ===== */

undefined4 FUN_0800e200(void)

{
  undefined4 extraout_r3;
  
  FUN_0800bf64();
  return extraout_r3;
}



/* ===== FUN_0800e20c @ 0x800E20C ===== */

void FUN_0800e20c(undefined4 param_1)

{
  bool bVar1;
  int local_10;
  
  switch(param_1) {
  case 0:
  case 2:
    break;
  case 1:
    FUN_0800cf94(DAT_0800e294);
    FUN_08003bdc(0x9a);
    FUN_080036d4();
    local_10 = DAT_0800e298;
    do {
      bVar1 = local_10 != 0;
      local_10 = local_10 + -1;
    } while (bVar1);
    FUN_0800375c();
    FUN_0800378c();
    FUN_08012780();
    FUN_0800a468();
    break;
  case 3:
  case 4:
    FUN_0800cf94(DAT_0800e294);
    FUN_08003bdc(0x9a);
    FUN_080036d4();
    local_10 = DAT_0800e298;
    do {
      bVar1 = local_10 != 0;
      local_10 = local_10 + -1;
    } while (bVar1);
    FUN_0800375c();
    FUN_0800378c();
    FUN_08012780();
    FUN_08004a94();
    FUN_0800a468();
  }
  return;
}



/* ===== FUN_0800e29c @ 0x800E29C ===== */

void FUN_0800e29c(undefined4 param_1)

{
  *(undefined4 *)(DAT_0800e2a4 + 0x20) = param_1;
  return;
}



/* ===== FUN_0800e2a8 @ 0x800E2A8 ===== */

void FUN_0800e2a8(int param_1,uint param_2)

{
  uint *puVar1;
  
  puVar1 = DAT_0800e2fc;
  do {
  } while ((DAT_0800e2fc[4] & 2) != 2);
  DAT_0800e2fc[2] = DAT_0800e2fc[2] & 0xffffcfff | param_2;
  *puVar1 = *puVar1 & 0xfffffff8 | 2;
  *DAT_0800e300 = *DAT_0800e300 | 4;
  if (param_1 == 1) {
    WaitForInterrupt();
  }
  else {
    WaitForEvent();
    WaitForEvent();
  }
  *DAT_0800e300 = *DAT_0800e300 & 0xfffffffb;
  return;
}



/* ===== FUN_0800e304 @ 0x800E304 ===== */

void FUN_0800e304(void)

{
  byte bVar1;
  int iVar2;
  undefined4 local_10;
  
  local_10 = 0;
  bVar1 = 0;
  do {
    if (2 < bVar1) {
      return;
    }
    iVar2 = FUN_0800eee0(8,0x91a0,&local_10,2);
    if (iVar2 != 0) {
      *(ushort *)(DAT_0800e364 + 0x18) = (ushort)local_10;
      if ((31999 < (ushort)local_10) && ((ushort)local_10 < 0x8ca1)) {
        return;
      }
      local_10 = 34000;
      iVar2 = FUN_080175ac(8,0x91a0,34000,2);
      if (iVar2 != 0) {
        return;
      }
    }
    bVar1 = bVar1 + 1;
  } while( true );
}



/* ===== FUN_0800e368 @ 0x800E368 ===== */

void FUN_0800e368(void)

{
  int iVar1;
  
  if (*DAT_0800e414 == 0) {
    FUN_0800a884();
  }
  if (0x7f < *DAT_0800e418) {
    *DAT_0800e418 = 0;
  }
  if ((*DAT_0800e414 & 0x7f) != 0) {
    if ((int)((uint)*DAT_0800e414 << 0x1b) < 0) {
      iVar1 = FUN_08009fdc(4,DAT_0800e41c,0x54,1);
      if (iVar1 == 1) {
        iVar1 = FUN_08009fdc(4,DAT_0800e41c,0x54,2);
      }
      if (iVar1 == 1) {
        *DAT_0800e418 = *DAT_0800e418 | 0x10;
      }
      *DAT_0800e414 = *DAT_0800e414 & 0xef;
    }
    if (*DAT_0800e418 == 0x7f) {
      iVar1 = FUN_08009fdc(0,DAT_0800e418,2,1);
      if (iVar1 == 1) {
        FUN_08009fdc(0,DAT_0800e418,2);
        FUN_0800a884();
      }
    }
    else if (0x7f < *DAT_0800e418) {
      *DAT_0800e418 = 0;
    }
  }
  FUN_0800ba18();
  return;
}



/* ===== FUN_0800e420 @ 0x800E420 ===== */

void FUN_0800e420(void)

{
  int iVar1;
  bool bVar2;
  int local_10;
  
  iVar1 = FUN_0800f240();
  if (iVar1 == 0) {
    local_10 = 1000;
    do {
      bVar2 = local_10 != 0;
      local_10 = local_10 + -1;
    } while (bVar2);
    FUN_0800f240();
  }
  iVar1 = FUN_0800aa50(DAT_0800e45c,4);
  if (*(int *)(DAT_0800e45c + 4) == iVar1) {
    *DAT_0800e460 = *DAT_0800e45c;
  }
  return;
}



/* ===== FUN_0800e464 @ 0x800E464 ===== */

undefined4
FUN_0800e464(undefined4 *param_1,undefined4 param_2,undefined1 param_3,undefined1 param_4)

{
  *(undefined1 *)(param_1 + 1) = 0;
  *(undefined1 *)((int)param_1 + 5) = 0;
  *(undefined1 *)((int)param_1 + 6) = param_3;
  *(undefined1 *)((int)param_1 + 7) = param_4;
  *param_1 = param_2;
  return 1;
}



/* ===== FUN_0800e478 @ 0x800E478 ===== */

void FUN_0800e478(uint param_1)

{
  *(uint *)(DAT_0800e48c + 0x2c) = *(uint *)(DAT_0800e48c + 0x2c) & 0xfffffff0 | param_1;
  return;
}



/* ===== FUN_0800e490 @ 0x800E490 ===== */

void FUN_0800e490(uint param_1,int param_2)

{
  if (param_2 == 0) {
    param_1 = param_1 & 0xfffffeff;
  }
  *(uint *)(DAT_0800e4b0 + 0x2c) = *(uint *)(DAT_0800e4b0 + 0x2c) & 0xfffffe0f | param_1;
  return;
}



/* ===== FUN_0800e4b4 @ 0x800E4B4 ===== */

void FUN_0800e4b4(uint param_1)

{
  *(uint *)(DAT_0800e4c8 + 4) = *(uint *)(DAT_0800e4c8 + 4) & 0xffffff0f | param_1;
  return;
}



/* ===== FUN_0800e4cc @ 0x800E4CC ===== */

void FUN_0800e4cc(int param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_0800e514;
  *DAT_0800e514 = *DAT_0800e514 & 0xfffeffff;
  *puVar1 = *puVar1 & 0xfffbffff;
  if (param_1 == 0x10000) {
    *DAT_0800e514 = *DAT_0800e514 | 0x10000;
  }
  else if (param_1 == 0x40000) {
    *DAT_0800e514 = *DAT_0800e514 | 0x50000;
  }
  return;
}



/* ===== FUN_0800e518 @ 0x800E518 ===== */

void FUN_0800e518(int param_1)

{
  uint *puVar1;
  
  puVar1 = DAT_0800e53c;
  *DAT_0800e53c = *DAT_0800e53c & 0xfffffffe;
  if (param_1 == 1) {
    *puVar1 = *puVar1 | 1;
  }
  return;
}



/* ===== FUN_0800e540 @ 0x800E540 ===== */

void FUN_0800e540(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = DAT_0800e57c;
  *(uint *)(DAT_0800e57c + 0x24) = *(uint *)(DAT_0800e57c + 0x24) & 0xffffff8f;
  *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) | param_2;
  if (param_1 == 0) {
    *(uint *)(DAT_0800e57c + 0x24) = *(uint *)(DAT_0800e57c + 0x24) & 0xfffffffb;
  }
  else if (param_1 == 4) {
    *(uint *)(iVar1 + 0x24) = *(uint *)(iVar1 + 0x24) | 4;
  }
  return;
}



/* ===== FUN_0800e580 @ 0x800E580 ===== */

void FUN_0800e580(uint param_1)

{
  *(uint *)(DAT_0800e594 + 4) = *(uint *)(DAT_0800e594 + 4) & 0xfffff8ff | param_1;
  return;
}



/* ===== FUN_0800e598 @ 0x800E598 ===== */

void FUN_0800e598(int param_1)

{
  *(uint *)(DAT_0800e5ac + 4) = *(uint *)(DAT_0800e5ac + 4) & 0xffffc7ff | param_1 << 3;
  return;
}



/* ===== FUN_0800e5b0 @ 0x800E5B0 ===== */

void FUN_0800e5b0(uint param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  int iVar2;
  
  iVar2 = DAT_0800e5e8;
  puVar1 = (uint *)(DAT_0800e5e8 + 0x40);
  if ((param_1 == 0) || (param_1 == 1)) {
    param_3 = param_1 | param_3;
  }
  else {
    param_2 = param_1 | param_2;
  }
  *(uint *)(DAT_0800e5e8 + 4) = *(uint *)(DAT_0800e5e8 + 4) & DAT_0800e5ec | param_2;
  *(uint *)(iVar2 + 0x40) = *puVar1 & 0xfffffffc | param_3;
  return;
}



/* ===== FUN_0800e5f0 @ 0x800E5F0 ===== */

void FUN_0800e5f0(uint param_1)

{
  int iVar1;
  
  iVar1 = DAT_0800e608;
  *(uint *)(DAT_0800e608 + 0x20) = *(uint *)(DAT_0800e608 + 0x20) & 0xfffffcff;
  *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) | param_1;
  return;
}



/* ===== FUN_0800e60c @ 0x800E60C ===== */

void FUN_0800e60c(uint param_1)

{
  *(uint *)(DAT_0800e620 + 4) = *(uint *)(DAT_0800e620 + 4) & 0xfffffffc | param_1;
  return;
}



/* ===== FUN_0800e624 @ 0x800E624 ===== */

void FUN_0800e624(uint param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(DAT_0800e640 + 0x14) = *(uint *)(DAT_0800e640 + 0x14) & ~param_1;
  }
  else {
    *(uint *)(DAT_0800e640 + 0x14) = *(uint *)(DAT_0800e640 + 0x14) | param_1;
  }
  return;
}



/* ===== FUN_0800e644 @ 0x800E644 ===== */

void FUN_0800e644(uint param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(DAT_0800e660 + 0x28) = *(uint *)(DAT_0800e660 + 0x28) & ~param_1;
  }
  else {
    *(uint *)(DAT_0800e660 + 0x28) = *(uint *)(DAT_0800e660 + 0x28) | param_1;
  }
  return;
}



/* ===== FUN_0800e664 @ 0x800E664 ===== */

void FUN_0800e664(uint param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(DAT_0800e680 + 0x1c) = *(uint *)(DAT_0800e680 + 0x1c) & ~param_1;
  }
  else {
    *(uint *)(DAT_0800e680 + 0x1c) = *(uint *)(DAT_0800e680 + 0x1c) | param_1;
  }
  return;
}



/* ===== FUN_0800e684 @ 0x800E684 ===== */

void FUN_0800e684(uint param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(DAT_0800e6a0 + 0x10) = *(uint *)(DAT_0800e6a0 + 0x10) & ~param_1;
  }
  else {
    *(uint *)(DAT_0800e6a0 + 0x10) = *(uint *)(DAT_0800e6a0 + 0x10) | param_1;
  }
  return;
}



/* ===== FUN_0800e6a4 @ 0x800E6A4 ===== */

void FUN_0800e6a4(uint param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(DAT_0800e6c0 + 0x18) = *(uint *)(DAT_0800e6c0 + 0x18) & ~param_1;
  }
  else {
    *(uint *)(DAT_0800e6c0 + 0x18) = *(uint *)(DAT_0800e6c0 + 0x18) | param_1;
  }
  return;
}



/* ===== FUN_0800e6c4 @ 0x800E6C4 ===== */

void FUN_0800e6c4(uint param_1,int param_2)

{
  if (param_2 == 0) {
    *(uint *)(DAT_0800e6e0 + 0xc) = *(uint *)(DAT_0800e6e0 + 0xc) & ~param_1;
  }
  else {
    *(uint *)(DAT_0800e6e0 + 0xc) = *(uint *)(DAT_0800e6e0 + 0xc) | param_1;
  }
  return;
}



/* ===== FUN_0800e6e4 @ 0x800E6E4 ===== */

void FUN_0800e6e4(undefined4 param_1)

{
  *DAT_0800e6ec = param_1;
  return;
}



/* ===== FUN_0800e6f0 @ 0x800E6F0 ===== */

void FUN_0800e6f0(undefined4 param_1)

{
  *(undefined4 *)(DAT_0800e6f8 + 0x60) = param_1;
  return;
}



/* ===== FUN_0800e6fc @ 0x800E6FC ===== */

void FUN_0800e6fc(undefined4 param_1)

{
  *DAT_0800e704 = param_1;
  return;
}



/* ===== FUN_0800e708 @ 0x800E708 ===== */

void FUN_0800e708(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  uVar2 = *(uint *)(DAT_0800e838 + 4) & DAT_0800e83c;
  uVar4 = (*(uint *)(DAT_0800e838 + 0x24) & 0x7f) >> 4;
  if ((uVar2 & 0x8000000) == 0) {
    iVar3 = (uVar2 >> 0x12) + 2;
  }
  else {
    iVar3 = (uVar2 >> 0x12) - 0x1ef;
  }
  if ((*(uint *)(DAT_0800e838 + 4) & 0x10000) == 0) {
    if ((*(uint *)(DAT_0800e838 + 0x40) & 1) == 0) {
      uVar2 = iVar3 * DAT_0800e844;
    }
    else {
      uVar2 = iVar3 * DAT_0800e840;
    }
  }
  else if ((*(uint *)(DAT_0800e838 + 4) & 0x20000) == 0) {
    uVar2 = iVar3 * DAT_0800e844;
  }
  else {
    uVar2 = iVar3 * DAT_0800e840;
  }
  if ((*(uint *)(DAT_0800e838 + 0x40) & 2) != 0) {
    uVar2 = uVar2 >> 1;
  }
  uVar1 = *(uint *)(DAT_0800e838 + 4) & 0xc;
  if (uVar1 == 0) {
    *param_1 = *(uint *)(DAT_0800e848 + uVar4 * 4);
  }
  else if (uVar1 == 4) {
    *param_1 = DAT_0800e844;
  }
  else if (uVar1 == 8) {
    *param_1 = DAT_0800e844;
  }
  else if (uVar1 == 0xc) {
    *param_1 = uVar2;
  }
  else {
    *param_1 = *(uint *)(DAT_0800e848 + uVar4 * 4);
  }
  param_1[1] = *param_1 >> *(sbyte *)(DAT_0800e84c + ((*(uint *)(DAT_0800e838 + 4) & 0xf0) >> 4));
  param_1[2] = param_1[1] >> *(sbyte *)(DAT_0800e84c + ((*(uint *)(DAT_0800e838 + 4) & 0x700) >> 8))
  ;
  param_1[3] = param_1[1] >>
               *(sbyte *)(DAT_0800e84c + ((*(uint *)(DAT_0800e838 + 4) & 0x3800) >> 0xb));
  param_1[5] = param_1[1] / (uint)*(byte *)(DAT_0800e850 + (*(uint *)(DAT_0800e838 + 0x2c) & 0xf));
  param_1[4] = uVar2 / *(ushort *)
                        (DAT_0800e854 + ((*(uint *)(DAT_0800e838 + 0x2c) & 0x1f0) >> 4 & 0xf) * 2);
  return;
}



/* ===== FUN_0800e858 @ 0x800E858 ===== */

bool FUN_0800e858(uint param_1)

{
  uint uVar1;
  
  if ((int)param_1 >> 5 == 1) {
    uVar1 = *DAT_0800e890;
  }
  else if ((int)param_1 >> 5 == 2) {
    uVar1 = DAT_0800e890[8];
  }
  else {
    uVar1 = DAT_0800e890[9];
  }
  return (1 << (param_1 & 0x1f) & uVar1) != 0;
}



/* ===== FUN_0800e894 @ 0x800E894 ===== */

uint FUN_0800e894(void)

{
  return *(uint *)(DAT_0800e8a0 + 4) & 0xc;
}



/* ===== FUN_0800e8a4 @ 0x800E8A4 ===== */

bool FUN_0800e8a4(void)

{
  int iVar1;
  int local_10;
  
  local_10 = 0;
  do {
    iVar1 = FUN_0800e858(0x31);
    local_10 = local_10 + 1;
    if (local_10 == 0x2000) break;
  } while (iVar1 == 0);
  iVar1 = FUN_0800e858(0x31);
  return iVar1 != 0;
}



/* ===== FUN_0800e8dc @ 0x800E8DC ===== */

bool FUN_0800e8dc(void)

{
  int iVar1;
  int local_10;
  
  local_10 = 0;
  do {
    iVar1 = FUN_0800e858(0x21);
    local_10 = local_10 + 1;
    if (local_10 == 0x500) break;
  } while (iVar1 == 0);
  iVar1 = FUN_0800e858(0x21);
  return iVar1 != 0;
}



/* ===== FUN_0800e914 @ 0x800E914 ===== */

bool FUN_0800e914(void)

{
  int iVar1;
  int local_10;
  
  local_10 = 0;
  do {
    iVar1 = FUN_0800e858(99);
    local_10 = local_10 + 1;
    if (local_10 == 0x500) break;
  } while (iVar1 == 0);
  iVar1 = FUN_0800e858(99);
  return iVar1 != 0;
}



/* ===== FUN_0800e94c @ 0x800E94C ===== */

void FUN_0800e94c(undefined4 param_1)

{
  FUN_08016958(5);
  FUN_0800ee4c(param_1);
  FUN_080078b0(1);
  FUN_08007970(0x100000);
  FUN_0800e9fc(0x4000);
  FUN_0800e9dc(0x4000);
  FUN_0800eb40(1);
  return;
}



/* ===== FUN_0800e984 @ 0x800E984 ===== */

void FUN_0800e984(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = param_3;
  local_c = param_4;
  FUN_0800aa90(&local_10);
  puVar1 = DAT_0800e9a4;
  *DAT_0800e9a4 = local_10;
  *(undefined2 *)(puVar1 + 1) = (undefined2)local_c;
  *(undefined1 *)((int)puVar1 + 6) = local_c._2_1_;
  return;
}



/* ===== FUN_0800e9a8 @ 0x800E9A8 ===== */

uint FUN_0800e9a8(uint param_1)

{
  return (param_1 & 0xf) + (param_1 >> 4) * 10 & 0xff;
}



/* ===== FUN_0800e9be @ 0x800E9BE ===== */

uint FUN_0800e9be(uint param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  for (; 9 < (int)param_1; param_1 = param_1 - 10 & 0xff) {
    uVar1 = uVar1 + 1 & 0xff;
  }
  return param_1 | (uVar1 & 0xf) << 4;
}



/* ===== FUN_0800e9dc @ 0x800E9DC ===== */

void FUN_0800e9dc(uint param_1)

{
  *DAT_0800e9f8 = *DAT_0800e9f8 & 0x80 | ~(param_1 >> 4 & 0xffff | 0x80);
  return;
}



/* ===== FUN_0800e9fc @ 0x800E9FC ===== */

void FUN_0800e9fc(uint param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0800ea38;
  *DAT_0800ea38 = 0xca;
  *puVar1 = 0x53;
  if (param_2 == 0) {
    DAT_0800ea38[-7] = DAT_0800ea38[-7] & ~(param_1 & 0xfffffffb);
  }
  else {
    DAT_0800ea38[-7] = DAT_0800ea38[-7] | param_1 & 0xfffffffb;
  }
  *DAT_0800ea38 = 0xff;
  return;
}



/* ===== FUN_0800ea3c @ 0x800EA3C ===== */

undefined4 FUN_0800ea3c(int param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint *puVar4;
  uint uVar5;
  
  if (param_1 == 0) {
    if ((*DAT_0800eb08 & 0x40) == 0) {
      param_2[3] = 0;
    }
  }
  else if ((*DAT_0800eb08 & 0x40) == 0) {
    param_2[3] = 0;
  }
  else {
    FUN_0800e9a8(*param_2);
  }
  if (param_1 == 0) {
    iVar2 = FUN_0800e9be(*param_2);
    iVar1 = FUN_0800e9be(param_2[1]);
    uVar5 = FUN_0800e9be(param_2[2]);
    uVar5 = iVar2 << 0x10 | iVar1 << 8 | uVar5 | (uint)param_2[3] << 0x10;
  }
  else {
    uVar5 = (uint)*param_2 << 0x10 | (uint)param_2[1] << 8 | (uint)param_2[2] |
            (uint)param_2[3] << 0x10;
  }
  puVar4 = DAT_0800eb08 + 7;
  *puVar4 = 0xca;
  *puVar4 = 0x53;
  iVar2 = FUN_0800ebb8();
  if (iVar2 != 0) {
    DAT_0800eb08[-2] = DAT_0800eb0c & uVar5;
    FUN_0800ec08();
    if ((*DAT_0800eb08 & 0x20) == 0) {
      FUN_0800ee70();
    }
  }
  DAT_0800eb08[7] = 0xff;
  uVar3 = FUN_0800ee70();
  return uVar3;
}



/* ===== FUN_0800eb10 @ 0x800EB10 ===== */

void FUN_0800eb10(uint param_1)

{
  undefined4 *puVar1;
  uint *puVar2;
  
  puVar1 = DAT_0800eb3c;
  *DAT_0800eb3c = 0xca;
  *puVar1 = 0x53;
  puVar2 = DAT_0800eb3c + -7;
  *puVar2 = DAT_0800eb3c[-7] & 0xfffffff8;
  *puVar2 = *puVar2 | param_1;
  *DAT_0800eb3c = 0xff;
  return;
}



/* ===== FUN_0800eb40 @ 0x800EB40 ===== */

undefined4 FUN_0800eb40(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int local_c;
  
  puVar1 = DAT_0800ebb4;
  local_c = 0;
  *DAT_0800ebb4 = 0xca;
  *puVar1 = 0x53;
  if (param_1 == 0) {
    DAT_0800ebb4[-7] = DAT_0800ebb4[-7] & 0xfffffbff;
    do {
      local_c = local_c + 1;
      if (local_c == 0x2000) break;
    } while ((DAT_0800ebb4[-6] & 4) == 0);
    if ((DAT_0800ebb4[-6] & 4) == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
  }
  else {
    DAT_0800ebb4[-7] = DAT_0800ebb4[-7] | 0x400;
    uVar2 = 1;
  }
  *DAT_0800ebb4 = 0xff;
  return uVar2;
}



/* ===== FUN_0800ebb8 @ 0x800EBB8 ===== */

undefined8 FUN_0800ebb8(void)

{
  undefined4 uVar1;
  uint uVar2;
  undefined4 local_8;
  
  local_8 = 0;
  uVar2 = 0;
  if ((*DAT_0800ec04 & 0x40) == 0) {
    *DAT_0800ec04 = 0x80;
    do {
      uVar2 = *DAT_0800ec04 & 0x40;
      local_8 = local_8 + 1;
      if (local_8 == 0x2000) break;
    } while (uVar2 == 0);
    if ((*DAT_0800ec04 & 0x40) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 1;
  }
  return CONCAT44(uVar2,uVar1);
}



/* ===== FUN_0800ec08 @ 0x800EC08 ===== */

void FUN_0800ec08(void)

{
  *DAT_0800ec18 = *DAT_0800ec18 & 0xffffff7f;
  return;
}



/* ===== FUN_0800ec1c @ 0x800EC1C ===== */

void FUN_0800ec1c(int param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = *DAT_0800ec60 & DAT_0800ec64;
  param_2[3] = (byte)(uVar2 >> 0x10);
  param_2[1] = (byte)((uVar2 << 0x13) >> 0x1b);
  param_2[2] = (byte)uVar2 & 0x3f;
  *param_2 = (byte)(uVar2 >> 8) >> 5;
  if (param_1 == 0) {
    bVar1 = FUN_0800e9a8(param_2[3]);
    param_2[3] = bVar1;
    bVar1 = FUN_0800e9a8(param_2[1]);
    param_2[1] = bVar1;
    bVar1 = FUN_0800e9a8(param_2[2]);
    param_2[2] = bVar1;
  }
  return;
}



/* ===== FUN_0800ec68 @ 0x800EC68 ===== */

undefined4 FUN_0800ec68(uint param_1)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (((param_1 == 0x20000) || (param_1 == 0x40000)) || (param_1 == 0x80000)) {
    if ((*DAT_0800ecb8 & 0xffffff) >> 0x10 != 0) {
      uVar2 = 1;
    }
  }
  else {
    uVar2 = DAT_0800ecb8[-0xe] & param_1;
  }
  if ((uVar2 == 0) || ((DAT_0800ecb8[-0xd] & param_1 >> 4 & 0xffff) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* ===== FUN_0800ecbc @ 0x800ECBC ===== */

void FUN_0800ecbc(int param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = *DAT_0800ed04 & DAT_0800ed08;
  *param_2 = (byte)((uVar2 << 10) >> 0x1a);
  param_2[1] = (byte)((uVar2 << 0x11) >> 0x19);
  param_2[2] = (byte)uVar2 & 0x7f;
  param_2[3] = (byte)(uVar2 >> 0x10) & 0x40;
  if (param_1 == 0) {
    bVar1 = FUN_0800e9a8(*param_2);
    *param_2 = bVar1;
    bVar1 = FUN_0800e9a8(param_2[1]);
    param_2[1] = bVar1;
    bVar1 = FUN_0800e9a8(param_2[2]);
    param_2[2] = bVar1;
  }
  return;
}



/* ===== FUN_0800ed0c @ 0x800ED0C ===== */

bool FUN_0800ed0c(uint *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  
  puVar1 = DAT_0800ed7c;
  *DAT_0800ed7c = 0xca;
  *puVar1 = 0x53;
  iVar2 = FUN_0800ebb8();
  if (iVar2 != 0) {
    puVar3 = DAT_0800ed7c + -7;
    *puVar3 = DAT_0800ed7c[-7] & 0xffffffbf;
    DAT_0800ed7c[-7] = *puVar3 | *param_1;
    puVar3 = DAT_0800ed7c + -5;
    *puVar3 = param_1[2];
    DAT_0800ed7c[-5] = *puVar3 | (uint)(ushort)param_1[1] << 0x10;
    FUN_0800ec08();
  }
  *DAT_0800ed7c = 0xff;
  for (uVar4 = 0; uVar4 < 0x2ff; uVar4 = uVar4 + 1) {
  }
  return iVar2 != 0;
}



/* ===== FUN_0800ed80 @ 0x800ED80 ===== */

undefined4 FUN_0800ed80(int param_1,byte *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if ((param_1 == 0) && ((param_2[1] & 0x10) == 0x10)) {
    param_2[1] = (param_2[1] & 0xef) + 10;
  }
  if (param_1 == 0) {
    iVar3 = FUN_0800e9be(param_2[3]);
    iVar2 = FUN_0800e9be(param_2[1]);
    uVar5 = FUN_0800e9be(param_2[2]);
    uVar5 = iVar3 << 0x10 | iVar2 << 8 | uVar5 | (uint)*param_2 << 0xd;
  }
  else {
    FUN_0800e9a8(param_2[1]);
    FUN_0800e9a8(param_2[2]);
    uVar5 = (uint)param_2[3] << 0x10 | (uint)param_2[1] << 8 | (uint)param_2[2] |
            (uint)*param_2 << 0xd;
  }
  puVar1 = DAT_0800ee44;
  *DAT_0800ee44 = 0xca;
  *puVar1 = 0x53;
  iVar3 = FUN_0800ebb8();
  if (iVar3 != 0) {
    DAT_0800ee44[-8] = DAT_0800ee48 & uVar5;
    FUN_0800ec08();
    if ((DAT_0800ee44[-7] & 0x20) == 0) {
      FUN_0800ee70();
    }
  }
  *DAT_0800ee44 = 0xff;
  uVar4 = FUN_0800ee70();
  return uVar4;
}



/* ===== FUN_0800ee4c @ 0x800EE4C ===== */

void FUN_0800ee4c(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_0800ee64;
  *DAT_0800ee64 = 0xca;
  *puVar1 = 0x53;
  DAT_0800ee64[-4] = param_1;
  *puVar1 = 0xff;
  return;
}



/* ===== irq_03_Handler @ 0x800EE68 ===== */

void irq_03_Handler(void)

{
  FUN_08005168();
  return;
}



/* ===== FUN_0800ee70 @ 0x800EE70 ===== */

bool FUN_0800ee70(void)

{
  undefined4 *puVar1;
  uint *puVar2;
  int local_8;
  
  puVar1 = DAT_0800eecc;
  local_8 = 0;
  *DAT_0800eecc = 0xca;
  *puVar1 = 0x53;
  DAT_0800eecc[-6] = DAT_0800eecc[-6] & 0xffffffdf;
  do {
    local_8 = local_8 + 1;
    if (local_8 == 0x8000) break;
  } while ((DAT_0800eecc[-6] & 0x20) == 0);
  puVar2 = DAT_0800eecc + -6;
  *DAT_0800eecc = 0xff;
  return (*puVar2 & 0x20) != 0;
}



/* ===== FUN_0800eed0 @ 0x800EED0 ===== */

void FUN_0800eed0(void)

{
  FUN_0800510c();
  FUN_08005150();
  FUN_080051dc();
  return;
}



/* ===== FUN_0800eee0 @ 0x800EEE0 ===== */

undefined4
FUN_0800eee0(undefined4 param_1,undefined2 param_2,undefined2 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined4 local_1c;
  
  local_1c = CONCAT13((char)((ushort)*param_3 >> 8),CONCAT12((char)*param_3,param_2));
  iVar1 = FUN_08003e72(param_1,0x3e,1,&local_1c,2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = 4000;
    do {
      bVar3 = iVar1 != 0;
      iVar1 = iVar1 + -1;
    } while (bVar3);
    iVar1 = FUN_08003e52(param_1,0x40,1,param_3,param_4);
    if (iVar1 == 0) {
      uVar2 = 0;
    }
    else {
      iVar1 = 1000;
      do {
        bVar3 = iVar1 != 0;
        iVar1 = iVar1 + -1;
      } while (bVar3);
      uVar2 = 1;
    }
  }
  return uVar2;
}



/* ===== FUN_0800ef60 @ 0x800EF60 ===== */

bool FUN_0800ef60(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
  iVar1 = FUN_0800a380(DAT_0800efb4,param_1,0x28,param_4,param_4);
  if (iVar1 == 0) {
    iVar1 = 100;
    do {
      bVar3 = iVar1 != 0;
      iVar1 = iVar1 + -1;
    } while (bVar3);
    FUN_0800a380(DAT_0800efb4,param_1,0x28);
  }
  uVar2 = FUN_0800aa50(DAT_0800efb4,0x26);
  bVar3 = uVar2 != *(ushort *)(DAT_0800efb4 + 0x26);
  if (bVar3) {
    *(undefined2 *)(DAT_0800efb4 + 0x24) = 0;
  }
  else {
    *(undefined2 *)(DAT_0800efb4 + 0x24) = 1;
  }
  return bVar3;
}



/* ===== FUN_0800efb8 @ 0x800EFB8 ===== */

int FUN_0800efb8(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  bool bVar3;
  
  iVar1 = FUN_0800a380(DAT_0800f008,0x20000,0x10,in_r3,in_r3);
  if (iVar1 == 0) {
    iVar1 = 100;
    do {
      bVar3 = iVar1 != 0;
      iVar1 = iVar1 + -1;
    } while (bVar3);
    iVar1 = FUN_0800a380(DAT_0800f008,0x20000);
  }
  if ((iVar1 == 1) &&
     (iVar2 = FUN_0800aa50(DAT_0800f008,0xc), *(int *)(DAT_0800f008 + 0xc) != iVar2)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* ===== FUN_0800f00c @ 0x800F00C ===== */

void FUN_0800f00c(void)

{
  bool bVar1;
  undefined4 *puVar2;
  int iVar3;
  byte bVar4;
  undefined2 uVar5;
  uint uVar6;
  int unaff_r4;
  undefined4 local_80;
  undefined4 uStack_7c;
  undefined4 local_64;
  undefined2 local_60;
  undefined1 local_5e;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 auStack_34 [8];
  undefined4 local_2c;
  undefined1 local_28;
  undefined1 uStack_27;
  undefined2 uStack_26;
  undefined2 local_24;
  ushort uStack_22;
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined1 local_1a;
  ushort local_19;
  byte local_17;
  ushort local_16;
  
  bVar4 = 0;
  while ((bVar4 < 3 && (unaff_r4 = FUN_0800cb0c(&local_44), unaff_r4 != 1))) {
    bVar4 = bVar4 + 1;
  }
  *DAT_0800f224 = 0;
  uVar6 = FUN_0800aa50(&local_2c,10);
  puVar2 = DAT_0800f228;
  if ((uStack_22 == uVar6) && (unaff_r4 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    *DAT_0800f228 = local_2c;
    puVar2[1] = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
    puVar2[2] = CONCAT22(uStack_22,local_24);
  }
  else {
    FUN_0800aa90(&local_64);
    puVar2 = DAT_0800f22c;
    *DAT_0800f22c = local_64;
    *(undefined2 *)(puVar2 + 1) = local_60;
    *(undefined1 *)((int)puVar2 + 6) = local_5e;
    local_2c = CONCAT13(*(undefined1 *)((int)DAT_0800f22c + 3),
                        CONCAT12(*(undefined1 *)(DAT_0800f22c + 1),*(byte *)((int)puVar2 + 5) + 2000
                                ));
    local_28 = *(undefined1 *)((int)DAT_0800f22c + 2);
    uStack_26 = 0;
    local_24 = 0;
    uStack_22 = FUN_0800aa50(&local_2c,10);
    FUN_080031a4(&local_80,auStack_34,0x20);
    FUN_0800cccc(local_44,uStack_40,uStack_3c,uStack_38);
    puVar2 = DAT_0800f228;
    *DAT_0800f228 = local_2c;
    puVar2[1] = CONCAT22(uStack_26,CONCAT11(uStack_27,local_28));
    puVar2[2] = CONCAT22(uStack_22,local_24);
  }
  uVar6 = FUN_0800aa50(&local_20,7);
  if ((local_19 == uVar6) && (unaff_r4 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    *(undefined2 *)(DAT_0800f230 + 7) = local_20;
    *(undefined2 *)(DAT_0800f234 + 0x15) = local_1e;
    *(undefined2 *)(DAT_0800f238 + 9) = local_1c;
    *(undefined1 *)(DAT_0800f23c + 5) = local_1a;
  }
  else {
    local_20 = 0;
    local_1c = 0;
    local_1e = 0;
    local_1a = 0x19;
    local_19 = FUN_0800aa50(&local_20,7);
    FUN_080031a4(&local_80,auStack_34,0x20);
    FUN_0800cccc(local_44,uStack_40,uStack_3c,uStack_38);
  }
  uVar6 = FUN_0800aa50(&local_17,1);
  if ((local_16 == uVar6) && (unaff_r4 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    *(byte *)(DAT_0800f230 + 2) = *(byte *)(DAT_0800f230 + 2) & 0xfd | (local_17 & 1) << 1;
  }
  bVar4 = 0;
  while ((bVar4 < 3 && (unaff_r4 = FUN_0800cbf0(&local_5c), unaff_r4 != 1))) {
    bVar4 = bVar4 + 1;
  }
  uVar6 = FUN_0800aa50(&local_5c,0x16);
  iVar3 = DAT_0800f230;
  if ((local_48._2_2_ == uVar6) && (unaff_r4 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    *(undefined4 *)(DAT_0800f230 + 9) = local_5c;
    *(undefined4 *)(iVar3 + 0xd) = local_58;
    *(undefined4 *)(iVar3 + 0x11) = local_54;
    *(undefined4 *)(iVar3 + 0x15) = local_50;
    *(undefined4 *)(iVar3 + 0x1f) = local_4c;
    *(undefined2 *)(iVar3 + 0x23) = (undefined2)local_48;
  }
  else {
    local_5c = 0;
    local_58 = 0;
    local_54 = 0x78;
    local_50 = 0;
    local_4c = 0;
    local_48 = (uint)local_48._2_2_ << 0x10;
    uVar5 = FUN_0800aa50(&local_44,0x2e);
    local_48 = CONCAT22(uVar5,(undefined2)local_48);
    local_80 = local_4c;
    uStack_7c = local_48;
    FUN_0800cd9c(local_5c,local_58,local_54,local_50);
  }
  return;
}



/* ===== FUN_0800f240 @ 0x800F240 ===== */

int FUN_0800f240(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  bool bVar3;
  
  iVar1 = FUN_0800a380(DAT_0800f294,0x30000,8,in_r3,in_r3);
  if (iVar1 == 0) {
    iVar1 = 100;
    do {
      bVar3 = iVar1 != 0;
      iVar1 = iVar1 + -1;
    } while (bVar3);
    iVar1 = FUN_0800a380(DAT_0800f294,0x30000,8);
  }
  if ((iVar1 == 1) && (iVar2 = FUN_0800aa50(DAT_0800f294,4), *(int *)(DAT_0800f294 + 4) != iVar2)) {
    iVar1 = 0;
  }
  return iVar1;
}



/* ===== FUN_0800f33c @ 0x800F33C ===== */

void FUN_0800f33c(void)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = DAT_0800f390;
  *DAT_0800f390 = *DAT_0800f390 + 1;
  if (5 < *pbVar1) {
    iVar2 = FUN_08003c60(8,0x7f,DAT_0800f394,1);
    if (iVar2 != 0) {
      *(byte *)(DAT_0800f398 + 1) = *(byte *)(DAT_0800f398 + 1) & 0xfd | (*DAT_0800f394 & 1) << 1;
      *(byte *)(DAT_0800f398 + 1) = *(byte *)(DAT_0800f398 + 1) & 0xfe | *DAT_0800f394 >> 2 & 1;
    }
    *DAT_0800f390 = 0;
  }
  return;
}



/* ===== FUN_0800f39c @ 0x800F39C ===== */

undefined4 FUN_0800f39c(int param_1)

{
  byte bVar1;
  undefined2 uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  iVar5 = 0;
  bVar1 = 0;
  while ((bVar1 < 3 && (iVar5 = FUN_0800cbf0(&local_2c), iVar5 != 1))) {
    bVar1 = bVar1 + 1;
  }
  if (iVar5 == 1) {
    uVar3 = FUN_0800aa50(&local_2c,0x16);
    if (local_18._2_2_ != uVar3) {
      local_2c = 0;
      local_28 = 0;
      local_24 = 0x78;
      local_20 = 0;
      local_1c = 0;
      local_18 = (uint)local_18._2_2_ << 0x10;
    }
    if (param_1 == 0xd) {
      local_2c = *(undefined4 *)(DAT_0800f468 + 9);
    }
    else if (param_1 == 0xe) {
      local_28 = *(undefined4 *)(DAT_0800f468 + 0xd);
    }
    else if (param_1 == 0xf) {
      local_24 = *(undefined4 *)(DAT_0800f468 + 0x11);
    }
    else if (param_1 == 0x10) {
      local_20 = *(undefined4 *)(DAT_0800f468 + 0x15);
    }
    else if (param_1 == 0x11) {
      local_1c = *(undefined4 *)(DAT_0800f468 + 0x1f);
    }
    else if (param_1 == 0x12) {
      local_18 = CONCAT22(local_18._2_2_,*(undefined2 *)(DAT_0800f468 + 0x23));
    }
  }
  uVar2 = FUN_0800aa50(&local_2c,0x16);
  local_18 = CONCAT22(uVar2,(undefined2)local_18);
  uVar4 = FUN_0800cd9c(local_2c,local_28,local_24,local_20,local_1c,local_18);
  return uVar4;
}



/* ===== FUN_0800f46c @ 0x800F46C ===== */

undefined4 FUN_0800f46c(int param_1)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_68 [36];
  undefined4 local_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 auStack_34 [20];
  undefined2 local_20;
  undefined2 local_1e;
  undefined2 local_1c;
  undefined1 local_1a;
  ushort local_19;
  
  iVar4 = 0;
  bVar1 = 0;
  while ((bVar1 < 3 && (iVar4 = FUN_0800cb0c(&local_44), iVar4 != 1))) {
    bVar1 = bVar1 + 1;
  }
  if (iVar4 == 1) {
    uVar2 = FUN_0800aa50(&local_20,7);
    if (local_19 != uVar2) {
      local_20 = 0;
      local_1c = 0;
      local_1e = 0;
      local_1a = 0x19;
    }
    if (param_1 == 9) {
      local_20 = *(undefined2 *)(DAT_0800f524 + 7);
    }
    else if (param_1 == 10) {
      local_1e = *(undefined2 *)(DAT_0800f528 + 0x15);
    }
    else if (param_1 == 0xb) {
      local_1c = *(undefined2 *)(DAT_0800f52c + 9);
    }
    else if (param_1 == 0xc) {
      local_1a = *(undefined1 *)(DAT_0800f530 + 5);
    }
  }
  local_19 = FUN_0800aa50(&local_20,7);
  FUN_080031a4(auStack_68,auStack_34,0x20);
  uVar3 = FUN_0800cccc(local_44,uStack_40,uStack_3c,uStack_38);
  return uVar3;
}



/* ===== FUN_0800f534 @ 0x800F534 ===== */

void FUN_0800f534(void)

{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  undefined1 auStack_58 [24];
  undefined4 local_40;
  undefined2 local_3c;
  undefined1 local_3a;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [8];
  undefined4 local_20;
  undefined1 local_1c;
  undefined1 uStack_1b;
  undefined2 uStack_1a;
  undefined2 uStack_18;
  undefined2 uStack_16;
  
  FUN_080031d6(&local_38,0x30);
  bVar2 = 0;
  while ((bVar2 < 3 && (iVar3 = FUN_0800cb0c(&local_38), iVar3 != 1))) {
    bVar2 = bVar2 + 1;
  }
  FUN_0800aa90(&local_40);
  puVar1 = DAT_0800f5cc;
  *DAT_0800f5cc = local_40;
  *(undefined2 *)(puVar1 + 1) = local_3c;
  *(undefined1 *)((int)puVar1 + 6) = local_3a;
  local_20 = CONCAT13(*(undefined1 *)((int)DAT_0800f5cc + 3),
                      CONCAT12(*(undefined1 *)(DAT_0800f5cc + 1),*(byte *)((int)puVar1 + 5) + 2000))
  ;
  local_1c = *(undefined1 *)((int)DAT_0800f5cc + 2);
  uStack_1a = 0;
  uStack_18 = 0;
  uStack_16 = FUN_0800aa50(&local_20,10);
  FUN_080031a4(auStack_58,auStack_28,0x20);
  FUN_0800cccc(local_38,uStack_34,uStack_30,uStack_2c);
  puVar1 = DAT_0800f5d0;
  *DAT_0800f5d0 = local_20;
  puVar1[1] = CONCAT22(uStack_1a,CONCAT11(uStack_1b,local_1c));
  puVar1[2] = CONCAT22(uStack_16,uStack_18);
  return;
}



/* ===== FUN_0800f5d4 @ 0x800F5D4 ===== */

void FUN_0800f5d4(void)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined2 uVar3;
  int iVar4;
  undefined1 auStack_58 [24];
  undefined4 local_40;
  undefined2 local_3c;
  undefined1 local_3a;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [8];
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  FUN_080031d6(&local_38,0x30);
  for (bVar2 = 0; bVar2 < 3; bVar2 = bVar2 + 1) {
    iVar4 = FUN_0800cb0c(&local_38);
    if (iVar4 == 1) break;
  }
  FUN_0800aa90(&local_40);
  puVar1 = DAT_0800f668;
  *DAT_0800f668 = local_40;
  *(undefined2 *)(puVar1 + 1) = local_3c;
  *(undefined1 *)((int)puVar1 + 6) = local_3a;
  local_20 = CONCAT13(*(undefined1 *)((int)DAT_0800f668 + 3),
                      CONCAT12(*(undefined1 *)(DAT_0800f668 + 1),*(byte *)((int)puVar1 + 5) + 2000))
  ;
  local_1c = CONCAT31(local_1c._1_3_,*(undefined1 *)((int)DAT_0800f668 + 2));
  uVar3 = FUN_0800aa50(&local_20,10);
  local_18 = CONCAT22(uVar3,(undefined2)local_18);
  FUN_080031a4(auStack_58,auStack_28,0x20);
  FUN_0800cccc(local_38,uStack_34,uStack_30,uStack_2c);
  puVar1 = DAT_0800f66c;
  *DAT_0800f66c = local_20;
  puVar1[1] = local_1c;
  puVar1[2] = local_18;
  return;
}



/* ===== FUN_0800f670 @ 0x800F670 ===== */

void FUN_0800f670(void)

{
  undefined4 *puVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_60 [36];
  undefined4 local_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined1 auStack_2c [8];
  undefined4 local_24;
  undefined2 uStack_20;
  undefined2 local_1e;
  undefined2 uStack_1c;
  undefined2 local_1a;
  
  FUN_080031d6(&local_3c,0x30);
  bVar2 = 0;
  uVar3 = FUN_0800a938();
  if (*(uint *)((int)DAT_0800f6e0 + 6) < uVar3) {
    while ((bVar2 < 3 && (iVar4 = FUN_0800cb0c(&local_3c), iVar4 != 1))) {
      bVar2 = bVar2 + 1;
    }
    local_1e = (undefined2)uVar3;
    uStack_1c = (undefined2)(uVar3 >> 0x10);
    local_1a = FUN_0800aa50(&local_24,10);
    FUN_080031a4(auStack_60,auStack_2c,0x20);
    FUN_0800cccc(local_3c,uStack_38,uStack_34,uStack_30);
    puVar1 = DAT_0800f6e0;
    *DAT_0800f6e0 = local_24;
    puVar1[1] = CONCAT22(local_1e,uStack_20);
    puVar1[2] = CONCAT22(local_1a,uStack_1c);
  }
  return;
}



/* ===== FUN_0800f6e4 @ 0x800F6E4 ===== */

void FUN_0800f6e4(void)

{
  int iVar1;
  
  if (((int)((uint)(ushort)*DAT_0800f708 << 0x11) < 0) && (iVar1 = FUN_0800f39c(0xe), iVar1 == 1)) {
    *DAT_0800f708 = *DAT_0800f708 & 0xffffbfff;
  }
  return;
}



/* ===== FUN_0800f70c @ 0x800F70C ===== */

void FUN_0800f70c(void)

{
  int iVar1;
  
  if (((int)((uint)(ushort)*DAT_0800f730 << 0x16) < 0) && (iVar1 = FUN_0800f46c(9), iVar1 == 1)) {
    *DAT_0800f730 = *DAT_0800f730 & 0xfffffdff;
  }
  return;
}



/* ===== FUN_0800f734 @ 0x800F734 ===== */

void FUN_0800f734(void)

{
  int iVar1;
  
  if (((int)((uint)(ushort)*DAT_0800f758 << 0x12) < 0) && (iVar1 = FUN_0800f39c(0xd), iVar1 == 1)) {
    *DAT_0800f758 = *DAT_0800f758 & 0xffffdfff;
  }
  return;
}



/* ===== FUN_0800f75c @ 0x800F75C ===== */

void FUN_0800f75c(void)

{
  int iVar1;
  
  if (((int)(*DAT_0800f780 << 0xf) < 0) && (iVar1 = FUN_0800f39c(0x10), iVar1 == 1)) {
    *DAT_0800f780 = *DAT_0800f780 & 0xfffeffff;
  }
  return;
}



/* ===== FUN_0800f784 @ 0x800F784 ===== */

void FUN_0800f784(void)

{
  int iVar1;
  
  if (((int)(*DAT_0800f7a8 << 0xe) < 0) && (iVar1 = FUN_0800f39c(0x11), iVar1 == 1)) {
    *DAT_0800f7a8 = *DAT_0800f7a8 & 0xfffdffff;
  }
  return;
}



/* ===== FUN_0800f7ac @ 0x800F7AC ===== */

void FUN_0800f7ac(void)

{
  int iVar1;
  
  if (((int)((uint)(ushort)*DAT_0800f7d0 << 0x14) < 0) && (iVar1 = FUN_0800f46c(0xb), iVar1 == 1)) {
    *DAT_0800f7d0 = *DAT_0800f7d0 & 0xfffff7ff;
  }
  return;
}



/* ===== FUN_0800f7d4 @ 0x800F7D4 ===== */

void FUN_0800f7d4(void)

{
  int iVar1;
  
  if (((int)((uint)(ushort)*DAT_0800f7f8 << 0x10) < 0) && (iVar1 = FUN_0800f39c(0xf), iVar1 == 1)) {
    *DAT_0800f7f8 = *DAT_0800f7f8 & 0xffff7fff;
  }
  return;
}



/* ===== FUN_0800f7fc @ 0x800F7FC ===== */

void FUN_0800f7fc(void)

{
  int iVar1;
  
  if (((int)((uint)(ushort)*DAT_0800f820 << 0x13) < 0) && (iVar1 = FUN_0800f46c(0xc), iVar1 == 1)) {
    *DAT_0800f820 = *DAT_0800f820 & 0xffffefff;
  }
  return;
}



/* ===== FUN_0800f824 @ 0x800F824 ===== */

void FUN_0800f824(void)

{
  int iVar1;
  
  if (((int)((uint)(ushort)*DAT_0800f848 << 0x15) < 0) && (iVar1 = FUN_0800f46c(10), iVar1 == 1)) {
    *DAT_0800f848 = *DAT_0800f848 & 0xfffffbff;
  }
  return;
}



/* ===== FUN_0800f84c @ 0x800F84C ===== */

void FUN_0800f84c(void)

{
  return;
}



/* ===== FUN_0800f850 @ 0x800F850 ===== */

void FUN_0800f850(void)

{
  int iVar1;
  
  if (((int)(*DAT_0800f874 << 0xd) < 0) && (iVar1 = FUN_0800f39c(0x12), iVar1 == 1)) {
    *DAT_0800f874 = *DAT_0800f874 & 0xfffbffff;
  }
  return;
}



/* ===== FUN_0800f878 @ 0x800F878 ===== */

undefined8 FUN_0800f878(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 local_18;
  undefined2 local_14;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined4 local_10;
  undefined4 local_c;
  
  local_14 = (undefined2)param_2;
  uStack_12 = (undefined1)((uint)param_2 >> 0x10);
  uStack_11 = (undefined1)((uint)param_2 >> 0x18);
  local_18 = param_1;
  local_10 = param_3;
  local_c = param_4;
  FUN_0800aa90(&local_18);
  local_10 = local_18;
  local_c._0_3_ = CONCAT12(uStack_12,local_14);
  uVar1 = FUN_0800a7f8(&local_10,7);
  local_c = CONCAT13(uVar1,(undefined3)local_c);
  FUN_0800a2f0(0x50000);
  local_14 = 1000;
  uStack_12 = 0;
  uStack_11 = 0;
  do {
    iVar3 = CONCAT13(uStack_11,CONCAT12(uStack_12,local_14));
    iVar4 = iVar3 + -1;
    local_14 = (undefined2)iVar4;
    uStack_12 = (undefined1)((uint)iVar4 >> 0x10);
    uStack_11 = (undefined1)((uint)iVar4 >> 0x18);
  } while (iVar3 != 0);
  FUN_0800a2f0(0x51000);
  local_14 = 1000;
  uStack_12 = 0;
  uStack_11 = 0;
  do {
    iVar3 = CONCAT13(uStack_11,CONCAT12(uStack_12,local_14));
    iVar4 = iVar3 + -1;
    local_14 = (undefined2)iVar4;
    uStack_12 = (undefined1)((uint)iVar4 >> 0x10);
    uStack_11 = (undefined1)((uint)iVar4 >> 0x18);
  } while (iVar3 != 0);
  for (bVar2 = 0; bVar2 < 3; bVar2 = bVar2 + 1) {
    local_14 = 1000;
    uStack_12 = 0;
    uStack_11 = 0;
    do {
      iVar3 = CONCAT13(uStack_11,CONCAT12(uStack_12,local_14));
      iVar4 = iVar3 + -1;
      local_14 = (undefined2)iVar4;
      uStack_12 = (undefined1)((uint)iVar4 >> 0x10);
      uStack_11 = (undefined1)((uint)iVar4 >> 0x18);
    } while (iVar3 != 0);
    iVar3 = FUN_0800a4a0(&local_10,0x50000,8);
    if (iVar3 != 0) break;
  }
  for (bVar2 = 0; bVar2 < 3; bVar2 = bVar2 + 1) {
    local_14 = 1000;
    uStack_12 = 0;
    uStack_11 = 0;
    do {
      iVar3 = CONCAT13(uStack_11,CONCAT12(uStack_12,local_14));
      iVar4 = iVar3 + -1;
      local_14 = (undefined2)iVar4;
      uStack_12 = (undefined1)((uint)iVar4 >> 0x10);
      uStack_11 = (undefined1)((uint)iVar4 >> 0x18);
    } while (iVar3 != 0);
    iVar3 = FUN_0800a4a0(&local_10,0x51000,8);
    if (iVar3 != 0) break;
  }
  return CONCAT17(uStack_11,CONCAT16(uStack_12,CONCAT24(local_14,local_18)));
}



/* ===== FUN_0800f938 @ 0x800F938 ===== */

void FUN_0800f938(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 *puVar1;
  undefined4 *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = param_3;
  local_c = param_4;
  if (param_1 == 0) {
    FUN_080031a4(DAT_0800fd08,DAT_0800fd04,0x28);
  }
  else if ((param_1 == 8) || (param_1 == 9)) {
    *DAT_0800fd08 = (short)param_1;
    FUN_0800aa90(&local_10);
    puVar2 = DAT_0800fd0c;
    *DAT_0800fd0c = local_10;
    *(undefined2 *)(puVar2 + 1) = (undefined2)local_c;
    *(undefined1 *)((int)puVar2 + 6) = local_c._2_1_;
    *(undefined1 *)((int)DAT_0800fd08 + 7) = *(undefined1 *)((int)puVar2 + 5);
    *(undefined1 *)(DAT_0800fd08 + 3) = *(undefined1 *)(DAT_0800fd0c + 1);
    *(undefined1 *)((int)DAT_0800fd08 + 5) = *(undefined1 *)((int)DAT_0800fd0c + 3);
    *(undefined1 *)(DAT_0800fd08 + 2) = *(undefined1 *)((int)DAT_0800fd0c + 2);
    *(undefined1 *)((int)DAT_0800fd08 + 3) = *(undefined1 *)((int)DAT_0800fd0c + 1);
    puVar1 = DAT_0800fd08;
    *(undefined1 *)(DAT_0800fd08 + 1) = *(undefined1 *)DAT_0800fd0c;
    *(undefined4 *)(puVar1 + 4) = *(undefined4 *)(DAT_0800fd10 + 8);
    puVar1[6] = *(undefined2 *)(DAT_0800fd14 + 1);
    puVar1[7] = *(undefined2 *)(DAT_0800fd14 + 3);
    *(undefined4 *)(puVar1 + 8) = *(undefined4 *)(DAT_0800fd10 + 0xc);
    *(undefined1 *)(puVar1 + 10) = *(undefined1 *)(DAT_0800fd14 + 0x10);
    *(undefined1 *)((int)puVar1 + 0x15) = *(undefined1 *)(DAT_0800fd14 + 0x17);
    puVar1[0xb] = *(undefined2 *)(DAT_0800fd18 + 2);
    *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(DAT_0800fd18 + 0xc);
    *(undefined4 *)(puVar1 + 0xe) = *(undefined4 *)(DAT_0800fd18 + 8);
    puVar1 = DAT_0800fd08;
    if (((int)((uint)*(byte *)(DAT_0800fd28 + 6) << 0x19) < 0) ||
       ((int)((uint)*(byte *)(DAT_0800fd28 + 9) << 0x1c) < 0)) {
      iVar4 = 1;
    }
    else {
      iVar4 = 0;
    }
    *(uint *)(DAT_0800fd08 + 0x10) =
         *(byte *)(DAT_0800fd1c + 3) & 1 | *(byte *)(DAT_0800fd1c + 3) & 2 |
         (*(byte *)((int)DAT_0800fd1c + 0x17) & 1) << 2 | *(byte *)(DAT_0800fd1c + 3) & 8 |
         *(byte *)(DAT_0800fd1c + 3) & 0x10 | ((*(byte *)(DAT_0800fd1c + 3) & 0x7f) >> 6) << 5 |
         (*(byte *)(DAT_0800fd20 + 2) & 1) << 7 | (*(byte *)(DAT_0800fd24 + 2) & 1) << 8 |
         ((*(byte *)(DAT_0800fd24 + 2) & 3) >> 1) << 9 |
         ((*(byte *)(DAT_0800fd24 + 2) & 0xf) >> 3) << 10 |
         ((*(byte *)(DAT_0800fd24 + 2) & 0x1f) >> 4) << 0xb |
         ((*(byte *)(DAT_0800fd24 + 2) & 0x3f) >> 5) << 0xc |
         ((*(byte *)(DAT_0800fd24 + 2) & 0x7f) >> 6) << 0xe |
         (*(byte *)(DAT_0800fd28 + 6) & 1) << 0xf | ((*(byte *)(DAT_0800fd28 + 6) & 3) >> 1) << 0x11
         | ((*(byte *)(DAT_0800fd28 + 6) & 0xf) >> 3) << 0x13 |
         ((*(byte *)(DAT_0800fd28 + 6) & 0x3f) >> 5) << 0x15 |
         ((*(byte *)(DAT_0800fd28 + 9) & 3) >> 1) << 0x17 | iVar4 << 0x18 |
         (uint)(*(byte *)(DAT_0800fd1c + 3) >> 7) << 0x19 |
         ((*(byte *)(DAT_0800fd20 + 2) & 3) >> 1) << 0x1a |
         ((*(byte *)(DAT_0800fd20 + 2) & 7) >> 2) << 0x1b |
         ((*(byte *)(DAT_0800fd20 + 2) & 0xf) >> 3) << 0x1c |
         ((*(byte *)(DAT_0800fd20 + 3) & 0x1f) >> 4) << 0x1d |
         ((*(byte *)(DAT_0800fd20 + 3) & 7) >> 2) << 0x1e |
         (uint)(*(byte *)(DAT_0800fd20 + 3) >> 3) << 0x1f;
    puVar1[0x12] = 0;
    puVar1[0x13] = 0;
  }
  else {
    *DAT_0800fd08 = (short)param_1;
    FUN_0800aa90(&local_10);
    puVar2 = DAT_0800fd0c;
    *DAT_0800fd0c = local_10;
    *(undefined2 *)(puVar2 + 1) = (undefined2)local_c;
    *(undefined1 *)((int)puVar2 + 6) = local_c._2_1_;
    *(undefined1 *)((int)DAT_0800fd08 + 7) = *(undefined1 *)((int)puVar2 + 5);
    *(undefined1 *)(DAT_0800fd08 + 3) = *(undefined1 *)(DAT_0800fd0c + 1);
    *(undefined1 *)((int)DAT_0800fd08 + 5) = *(undefined1 *)((int)DAT_0800fd0c + 3);
    *(undefined1 *)(DAT_0800fd08 + 2) = *(undefined1 *)((int)DAT_0800fd0c + 2);
    *(undefined1 *)((int)DAT_0800fd08 + 3) = *(undefined1 *)((int)DAT_0800fd0c + 1);
    puVar1 = DAT_0800fd08;
    *(undefined1 *)(DAT_0800fd08 + 1) = *(undefined1 *)DAT_0800fd0c;
    *(undefined4 *)(puVar1 + 4) = *DAT_0800fd1c;
    puVar1[6] = *(undefined2 *)(DAT_0800fd1c + 2);
    puVar1[7] = *(undefined2 *)((int)DAT_0800fd1c + 6);
    *(undefined4 *)(puVar1 + 8) = *DAT_0800fd24;
    *(undefined1 *)(puVar1 + 10) = *(undefined1 *)(DAT_0800fd28 + 2);
    *(undefined1 *)((int)puVar1 + 0x15) = *(undefined1 *)(DAT_0800fd28 + 1);
    puVar1[0xb] = *(undefined2 *)(DAT_0800fd18 + 2);
    *(undefined4 *)(puVar1 + 0xc) = *(undefined4 *)(DAT_0800fd18 + 0xc);
    *(undefined4 *)(puVar1 + 0xe) = *(undefined4 *)(DAT_0800fd18 + 8);
    puVar1 = DAT_0800fd08;
    if (((int)((uint)*(byte *)(DAT_0800fd28 + 6) << 0x19) < 0) ||
       ((int)((uint)*(byte *)(DAT_0800fd28 + 9) << 0x1c) < 0)) {
      iVar4 = 1;
    }
    else {
      iVar4 = 0;
    }
    *(uint *)(DAT_0800fd08 + 0x10) =
         *(byte *)(DAT_0800fd1c + 3) & 1 | *(byte *)(DAT_0800fd1c + 3) & 2 |
         (*(byte *)((int)DAT_0800fd1c + 0x17) & 1) << 2 | *(byte *)(DAT_0800fd1c + 3) & 8 |
         *(byte *)(DAT_0800fd1c + 3) & 0x10 | ((*(byte *)(DAT_0800fd1c + 3) & 0x7f) >> 6) << 5 |
         (*(byte *)(DAT_0800fd20 + 2) & 1) << 7 | (*(byte *)(DAT_0800fd24 + 2) & 1) << 8 |
         ((*(byte *)(DAT_0800fd24 + 2) & 3) >> 1) << 9 |
         ((*(byte *)(DAT_0800fd24 + 2) & 0xf) >> 3) << 10 |
         ((*(byte *)(DAT_0800fd24 + 2) & 0x1f) >> 4) << 0xb |
         ((*(byte *)(DAT_0800fd24 + 2) & 0x3f) >> 5) << 0xc |
         ((*(byte *)(DAT_0800fd24 + 2) & 0x7f) >> 6) << 0xe |
         (*(byte *)(DAT_0800fd28 + 6) & 1) << 0xf | ((*(byte *)(DAT_0800fd28 + 6) & 3) >> 1) << 0x11
         | ((*(byte *)(DAT_0800fd28 + 6) & 0xf) >> 3) << 0x13 |
         ((*(byte *)(DAT_0800fd28 + 6) & 0x3f) >> 5) << 0x15 |
         ((*(byte *)(DAT_0800fd28 + 9) & 3) >> 1) << 0x17 | iVar4 << 0x18 |
         (uint)(*(byte *)(DAT_0800fd1c + 3) >> 7) << 0x19 |
         ((*(byte *)(DAT_0800fd20 + 2) & 3) >> 1) << 0x1a |
         ((*(byte *)(DAT_0800fd20 + 2) & 7) >> 2) << 0x1b |
         ((*(byte *)(DAT_0800fd20 + 2) & 0xf) >> 3) << 0x1c |
         ((*(byte *)(DAT_0800fd20 + 3) & 0x1f) >> 4) << 0x1d |
         ((*(byte *)(DAT_0800fd20 + 3) & 7) >> 2) << 0x1e |
         (uint)(*(byte *)(DAT_0800fd20 + 3) >> 3) << 0x1f;
    puVar1[0x12] = 0;
    puVar1[0x13] = 0;
  }
  uVar3 = FUN_0800aa50(DAT_0800fd08,0x26);
  DAT_0800fd08[0x13] = uVar3;
  FUN_080177e0();
  return;
}



/* ===== FUN_0800fd2c @ 0x800FD2C ===== */

uint FUN_0800fd2c(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2 * param_3 + param_1;
  uVar1 = param_1;
  if ((param_1 <= param_4) && (uVar1 = uVar2, param_4 <= uVar2)) {
    if (param_2 < ((param_4 - param_1) - param_2 * ((param_4 - param_1) / param_2)) * 2) {
      uVar1 = (param_4 - param_1) / param_2 + 1;
    }
    else {
      uVar1 = (param_4 - param_1) / param_2;
    }
    if (param_3 < uVar1) {
      uVar1 = param_3;
    }
    uVar1 = param_2 * uVar1 + param_1;
  }
  return uVar1;
}



/* ===== FUN_0800fd80 @ 0x800FD80 ===== */

void FUN_0800fd80(void)

{
  DataSynchronizationBarrier(0xf);
  *DAT_0800fdbc = (*DAT_0800fdbc & 0x700 | DAT_0800fdc0) + 4;
  DataSynchronizationBarrier(0xf);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_0800fdc4 @ 0x800FDC4 ===== */

void FUN_0800fdc4(void)

{
  if ((*(short *)(DAT_0800fe00 + 0x12) == 0xe0) && (*(short *)(DAT_0800fe00 + 0x14) == 0x5aa5)) {
    FUN_08009e98(DAT_0800fe04);
    FUN_0800fd80();
  }
  if ((*(short *)(DAT_0800fe00 + 0x12) == 0xe2) && (*(short *)(DAT_0800fe00 + 0x14) == 0x5aa5)) {
    FUN_0800fd80();
  }
  return;
}



/* ===== FUN_0800fe08 @ 0x800FE08 ===== */

undefined4 FUN_0800fe08(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  char local_30 [16];
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar3 = 0;
  local_30[0] = '\0';
  local_30[1] = '\0';
  local_30[2] = '\0';
  local_30[3] = '\0';
  local_30[4] = '\0';
  local_30[5] = '\0';
  local_30[6] = '\0';
  local_30[7] = '\0';
  local_30[8] = '\0';
  local_30[9] = '\0';
  local_30[10] = '\0';
  local_30[0xb] = '\0';
  local_30[0xc] = '\0';
  local_30[0xd] = '\0';
  local_30[0xe] = '\0';
  local_30[0xf] = '\0';
  uStack_10._1_1_ = (char)((uint)param_1 >> 8);
  cVar1 = uStack_10._1_1_;
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  FUN_080031a4(local_30,DAT_0800fe98,0x10);
  local_30[0xd] = (char)((uint)*DAT_0800fe9c >> 0x10);
  local_30[0xc] = (char)((uint)*DAT_0800fe9c >> 0x18);
  local_30[0xe] = (char)((ushort)*(undefined2 *)DAT_0800fe9c >> 8);
  local_30[0xf] = *(undefined1 *)DAT_0800fe9c;
  FUN_08003ac8(local_30,0x10);
  *(undefined1 *)(DAT_0800fea0 + 10) = 0;
  if (cVar1 == '\x1d') {
    for (uVar2 = 0; uVar2 < 0x10; uVar2 = uVar2 + 1 & 0xff) {
      if (local_30[uVar2] != *(char *)((int)&uStack_10 + uVar2 + 3)) {
        *(undefined1 *)(DAT_0800fea0 + 10) = 2;
        return 0;
      }
      uVar3 = 1;
      *(undefined1 *)(DAT_0800fea0 + 10) = 1;
    }
  }
  return uVar3;
}



/* ===== FUN_0800fea4 @ 0x800FEA4 ===== */

undefined4 FUN_0800fea4(undefined4 param_1)

{
  undefined4 uVar1;
  undefined1 local_f;
  
  uVar1 = 0;
  local_f = (char)((uint)param_1 >> 8);
  if ((local_f == '\t') || (local_f == '\v')) {
    uVar1 = 1;
    *DAT_0800fed0 = 3;
  }
  if (local_f == '\n') {
    uVar1 = 1;
    *DAT_0800fed0 = 3;
  }
  return uVar1;
}



/* ===== FUN_0800fed4 @ 0x800FED4 ===== */

bool FUN_0800fed4(uint param_1,uint param_2)

{
  undefined1 local_f;
  
  local_f = (char)(param_1 >> 8);
  if (local_f == '\x03') {
    *(uint *)(DAT_0800ff0c + 2) =
         (param_2 >> 0x10 & 0xff) +
         (param_1 & 0xff000000) + (param_2 & 0xff) * 0x10000 + (param_2 >> 8 & 0xff) * 0x100;
  }
  return local_f == '\x03';
}



/* ===== FUN_0800ff10 @ 0x800FF10 ===== */

void FUN_0800ff10(ushort *param_1)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  undefined1 auStack_50 [24];
  undefined4 local_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined1 auStack_28 [15];
  ushort local_19;
  
  bVar3 = false;
  local_38._0_3_ = CONCAT21(CONCAT11(*(byte *)((int)param_1 + 3),(char)param_1[2]),(char)param_1[1])
  ;
  uVar1 = (uint)(*(byte *)((int)param_1 + 3) >> 4);
  iVar2 = uVar1 * 4;
  if (((char)param_1[1] == -0x56) && (iVar2 + 5U <= (uint)*param_1)) {
    if (uVar1 != 0) {
      FUN_080031a4((int)&local_38 + 3,(int)param_1 + 5,iVar2);
    }
    local_19 = (ushort)(byte)param_1[uVar1 * 2 + 3] +
               (ushort)*(byte *)((int)param_1 + iVar2 + 5) * 0x100;
    uVar1 = FUN_08005b42((int)param_1 + 3,iVar2 + 2);
    if (local_19 == uVar1) {
      switch(*DAT_08010064) {
      case 1:
        FUN_080031a4(auStack_50,auStack_28,0x11);
        iVar2 = FUN_0800fed4(local_38,uStack_34,uStack_30,uStack_2c);
        bVar3 = iVar2 == 1;
        if (bVar3) {
          *DAT_08010064 = 2;
          *DAT_08010068 = 0;
        }
        break;
      case 2:
        FUN_080031a4(auStack_50,auStack_28,0x11);
        iVar2 = FUN_0801006c(local_38,uStack_34,uStack_30,uStack_2c);
        bVar3 = iVar2 == 1;
        if (bVar3) {
          *DAT_08010064 = 3;
          *DAT_08010068 = 0;
        }
        break;
      case 3:
        FUN_080031a4(auStack_50,auStack_28,0x11);
        iVar2 = FUN_0800fe08(local_38,uStack_34,uStack_30,uStack_2c);
        bVar3 = iVar2 != 0;
        if (bVar3) {
          *DAT_08010064 = 4;
          *DAT_08010068 = 0;
        }
        break;
      case 4:
        FUN_080031a4(auStack_50,auStack_28,0x11);
        iVar2 = FUN_080100b4(local_38,uStack_34,uStack_30,uStack_2c);
        bVar3 = iVar2 != 0;
        if (bVar3) {
          *DAT_08010064 = 5;
          *DAT_08010068 = 0;
        }
        break;
      case 5:
        FUN_080031a4(auStack_50,auStack_28,0x11);
        iVar2 = FUN_0800fea4(local_38,uStack_34,uStack_30,uStack_2c);
        bVar3 = iVar2 != 0;
        if (bVar3) {
          *DAT_08010064 = 5;
          *DAT_08010068 = 0;
        }
      }
      if (bVar3) {
        *DAT_08010068 = 0;
      }
    }
  }
  return;
}



/* ===== FUN_0801006c @ 0x801006C ===== */

bool FUN_0801006c(uint param_1,uint param_2)

{
  int *piVar1;
  undefined1 local_f;
  
  piVar1 = DAT_080100ac;
  local_f = (char)(param_1 >> 8);
  if (local_f == '\x05') {
    *DAT_080100ac =
         (param_2 >> 0x10 & 0xff) +
         (param_1 & 0xff000000) + (param_2 & 0xff) * 0x10000 + (param_2 >> 8 & 0xff) * 0x100;
    *(int *)(DAT_080100b0 + 6) = *piVar1;
  }
  return local_f == '\x05';
}



/* ===== FUN_080100b4 @ 0x80100B4 ===== */

undefined4 FUN_080100b4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  char local_f;
  byte local_d;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_4 = param_4;
  uStack_8 = param_3;
  uStack_c = param_2;
  uVar2 = 0;
  local_f = (char)((uint)param_1 >> 8);
  if (local_f == '\a') {
    for (uVar3 = 0; iVar1 = DAT_0801015c, uVar3 < 7; uVar3 = uVar3 + 1 & 0xff) {
      *(uint *)(DAT_08010158 + uVar3 * 2) =
           (uint)(&local_d)[uVar3 * 4] * 0x1000000 + (uint)*(byte *)(&uStack_c + uVar3) * 0x10000 +
           (uint)*(byte *)((int)&uStack_c + uVar3 * 4 + 1) * 0x100 +
           (uint)*(byte *)((int)&uStack_c + uVar3 * 4 + 2);
    }
    *(ushort *)(DAT_0801015c + 0xb) = (ushort)(((uint)*DAT_08010158 << 0x14) >> 0x14);
    *(ushort *)(iVar1 + 0xd) = (ushort)(((uint)DAT_08010158[3] << 0x14) >> 0x16);
    *(byte *)(iVar1 + 0xf) = (byte)(((uint)*(ushort *)((int)DAT_08010158 + 5) << 0x16) >> 0x1a);
    *(ushort *)(iVar1 + 0x10) = (ushort)(((uint)DAT_08010158[2] << 0x14) >> 0x14);
    *(ushort *)(iVar1 + 0x12) = DAT_08010158[5] >> 4;
    *(ushort *)(iVar1 + 0x14) = (ushort)(((uint)*(ushort *)((int)DAT_08010158 + 9) << 0x14) >> 0x16)
    ;
    *(ushort *)(iVar1 + 0x16) = (ushort)(((uint)DAT_08010158[4] << 0x16) >> 0x16);
    uVar2 = 1;
  }
  return uVar2;
}



/* ===== FUN_08010160 @ 0x8010160 ===== */

void FUN_08010160(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_08018880(param_1,DAT_08010178 + 0x140,DAT_08010178,6);
  *param_2 = uVar1;
  return;
}



/* ===== FUN_0801017c @ 0x801017C ===== */

void FUN_0801017c(int param_1,undefined4 param_2,undefined2 *param_3,int param_4)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int local_20;
  
  local_20 = param_4;
  FUN_08010160(param_2,&local_20);
  iVar2 = FUN_08018222(0,10000);
  iVar2 = local_20 - iVar2;
  iVar3 = FUN_08018222((10000 - param_1) * 0x98b,10000);
  local_20 = FUN_080182ce((local_20 - iVar3) * 10000,iVar2);
  if (local_20 < 0x2711) {
    if (local_20 < DAT_080101fc) {
      local_20 = DAT_080101fc;
    }
  }
  else {
    local_20 = 10000;
  }
  uVar1 = FUN_08018222(local_20 * 10000,10000);
  *param_3 = uVar1;
  return;
}



/* ===== FUN_08010200 @ 0x8010200 ===== */

void FUN_08010200(uint param_1,uint param_2,uint param_3,uint param_4,uint *param_5,
                 undefined1 *param_6)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_3 < param_1) || (param_4 <= param_2)) {
    *param_5 = 0xffffffea;
    if (*param_5 == 0xffffffff) {
      *param_5 = 0;
    }
    *param_6 = 0;
  }
  else {
    param_2 = param_4 - param_2;
    if (param_4 < param_2) {
      param_2 = 0;
    }
    param_1 = param_3 - param_1;
    if (param_3 < param_1) {
      param_1 = 0;
    }
    if ((param_1 < param_2) && (iVar1 = FUN_0800af58(), 0x1e < iVar1)) {
      param_1 = param_2 - param_1;
      if (param_2 < param_1) {
        param_1 = 0;
      }
      uVar2 = FUN_0800af58();
      uVar2 = FUN_08018938(uVar2,DAT_080102c8 + 0x70,DAT_080102c8,6,uVar2,param_3,param_4);
      uVar2 = FUN_08019150(uVar2,4);
      uVar3 = FUN_0801838a(param_1 * 0x262c,uVar2);
      *param_5 = 0x4c58;
      if (uVar3 <= *param_5) {
        uVar4 = FUN_08018266(0x262c,5);
        if (uVar3 < uVar4) {
          *param_5 = uVar4;
        }
        else {
          *param_5 = uVar3;
        }
      }
      *param_6 = 1;
    }
    else {
      *param_5 = 0xfffffff4;
      if (*param_5 == 0xffffffff) {
        *param_5 = 0;
      }
      *param_6 = 0;
    }
  }
  return;
}



/* ===== FUN_080102cc @ 0x80102CC ===== */

void FUN_080102cc(int param_1,int param_2,undefined4 param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  
  uVar1 = FUN_08018d8e(param_1 - param_2,param_3,DAT_080102f8 + -0x60,DAT_080102f8 + -0x30,
                       DAT_080102f8 + 0x59f,DAT_080102f8,0xc);
  *param_4 = uVar1;
  return;
}



/* ===== FUN_080102fc @ 0x80102FC ===== */

void FUN_080102fc(undefined4 param_1,int param_2,undefined4 param_3,undefined2 *param_4)

{
  undefined2 uVar1;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  local_28 = FUN_08019306(param_1,DAT_08010364,0x1a,&local_1c);
  local_34 = local_1c;
  if (param_2 < 0) {
    param_2 = -param_2;
  }
  local_24 = FUN_0801936a(param_2,DAT_08010368,3,&local_1c);
  local_30 = local_1c;
  local_20 = FUN_08019306(param_3,DAT_08010364 + 0x36,4,&local_1c);
  local_2c = local_1c;
  uVar1 = FUN_08018588(&local_28,&local_34,DAT_08010368 + 0x1ae);
  *param_4 = uVar1;
  return;
}



/* ===== FUN_0801036c @ 0x801036C ===== */

void FUN_0801036c(int param_1,int param_2,undefined2 *param_3)

{
  int iVar1;
  
  iVar1 = param_2;
  if (param_2 <= param_1) {
    iVar1 = param_1;
    param_1 = param_2;
  }
  if (iVar1 - param_1 < 10000) {
    if (iVar1 < 0x2711) {
      if (param_1 < 0) {
        *param_3 = (short)param_1;
      }
      else {
        iVar1 = FUN_08018328(param_1 * 10000,(10000 - iVar1) + param_1);
        if (iVar1 < 0x8000) {
          if (iVar1 < -0x8000) {
            iVar1 = DAT_080103e0;
          }
        }
        else {
          iVar1 = 0x7fff;
        }
        *param_3 = (short)iVar1;
      }
    }
    else {
      *param_3 = (short)iVar1;
    }
  }
  else {
    *param_3 = 0;
  }
  return;
}



/* ===== FUN_080103e4 @ 0x80103E4 ===== */

void FUN_080103e4(undefined2 *param_1)

{
  *param_1 = 0;
  return;
}



/* ===== FUN_080103ec @ 0x80103EC ===== */

void FUN_080103ec(undefined4 param_1,undefined2 *param_2)

{
  undefined2 uVar1;
  
  uVar1 = FUN_08018aa2(param_1,DAT_08010404 + 0x8a,DAT_08010404,0x15);
  *param_2 = uVar1;
  return;
}



/* ===== FUN_08010408 @ 0x8010408 ===== */

void FUN_08010408(int param_1,int param_2,int param_3,int param_4,uint param_5,ushort *param_6,
                 byte *param_7)

{
  short sVar1;
  ushort uVar2;
  short sVar3;
  byte bVar4;
  int iVar5;
  ushort uVar6;
  int iVar7;
  int local_28;
  
  uVar6 = (ushort)param_1;
  uVar2 = (ushort)param_2;
  if ((param_4 < 1) || (param_2 <= param_1)) {
    sVar3 = (short)param_3;
    if ((param_4 < 0) && (param_2 < param_1)) {
      sVar1 = uVar6 - uVar2;
      if (sVar1 < 0) {
        iVar7 = -(int)sVar1;
        if (0x7fff < iVar7) {
          iVar7 = 0x7fff;
        }
        sVar1 = (short)iVar7;
      }
      local_28 = (int)sVar1;
      if (param_4 < -0x13) {
        if (sVar1 < 9) {
          FUN_08010650(&local_28);
        }
        else if (sVar1 < 200) {
          FUN_0801064a(&local_28);
        }
        else if (sVar1 < 400) {
          local_28 = 3;
        }
        else {
          local_28 = 7;
        }
      }
      else {
        FUN_08010644(&local_28);
      }
      sVar1 = (short)(param_5 / 10);
      if ((short)(ushort)local_28 < sVar1) {
        local_28._0_2_ = sVar1;
      }
      uVar6 = sVar3 * (ushort)local_28 + uVar6;
      if ((short)uVar6 <= param_2) {
        uVar6 = uVar2;
      }
      if ((99 < param_1) && (uVar6 < 100)) {
        local_28._0_2_ = 100;
        uVar6 = (ushort)local_28;
      }
    }
    else {
      iVar7 = (int)(short)uVar6;
      local_28._0_2_ = sVar3;
      if (param_3 < 0) {
        local_28._0_2_ = -sVar3;
      }
      bVar4 = *param_7 + (0 < (short)(ushort)local_28);
      iVar5 = (uint)((uint)bVar4 % 3 == 0) * param_3 + iVar7;
      if (iVar5 < 0x8000) {
        if (iVar5 < -0x8000) {
          iVar5 = DAT_08010640;
        }
      }
      else {
        iVar5 = 0x7fff;
      }
      uVar2 = (ushort)iVar5;
      if ((iVar7 < 100) || (99 < (short)uVar2)) {
        if ((iVar7 < 0x26d5) && (0x26d4 < (short)uVar2)) {
          local_28._0_2_ = 0x26d4;
        }
        else {
          local_28._0_2_ = uVar6;
          if ((iVar7 < 0x26d5) && (local_28._0_2_ = uVar2, (short)uVar2 < 1)) {
            local_28._0_2_ = 0;
          }
        }
      }
      else {
        local_28._0_2_ = 100;
      }
      *param_7 = bVar4;
      uVar6 = (ushort)local_28;
    }
  }
  else {
    iVar7 = (int)(short)uVar6;
    local_28 = param_4;
    if (param_4 < 0x14) {
      FUN_08010650(&local_28);
    }
    else if ((short)(uVar2 - uVar6) < 9) {
      FUN_08010644(&local_28);
    }
    else if ((short)(uVar2 - uVar6) < 0x32) {
      FUN_0801064a(&local_28);
    }
    else {
      local_28 = 5;
    }
    param_3 = param_3 * (short)(ushort)local_28;
    if (param_3 < 0x8000) {
      if (param_3 < -0x8000) {
        param_3 = DAT_08010640;
      }
    }
    else {
      param_3 = 0x7fff;
    }
    param_3 = param_3 + iVar7;
    if (param_3 < 0x8000) {
      if (param_3 < -0x8000) {
        param_3 = DAT_08010640;
      }
    }
    else {
      param_3 = 0x7fff;
    }
    local_28 = (int)(short)param_3;
    if (param_2 <= (short)param_3) {
      local_28 = param_2;
    }
    if ((iVar7 < 0x26d5) && (0x26d4 < (short)(ushort)local_28)) {
      local_28._0_2_ = 0x26d4;
    }
    else if (0x26d4 < iVar7) goto LAB_0801060e;
    uVar6 = (ushort)local_28;
  }
LAB_0801060e:
  local_28._0_2_ = uVar6;
  if ((short)(ushort)local_28 < 0x2711) {
    if ((short)(ushort)local_28 < 0) {
      *param_6 = 0;
    }
    else {
      *param_6 = (ushort)local_28;
    }
  }
  else {
    *param_6 = 10000;
  }
  return;
}



/* ===== FUN_08010644 @ 0x8010644 ===== */

void FUN_08010644(undefined2 *param_1)

{
  *param_1 = 1;
  return;
}



/* ===== FUN_0801064a @ 0x801064A ===== */

void FUN_0801064a(undefined2 *param_1)

{
  *param_1 = 2;
  return;
}



/* ===== FUN_08010650 @ 0x8010650 ===== */

void FUN_08010650(undefined2 *param_1)

{
  *param_1 = 1;
  return;
}



/* ===== FUN_08010658 @ 0x8010658 ===== */

void FUN_08010658(void)

{
  byte *pbVar1;
  
  if ((((*DAT_080106e0 == '\0') || (*DAT_080106e0 == '\x01')) || (*DAT_080106e0 == '\x02')) &&
     (*DAT_080106e4 == '\x01')) {
    FUN_08008618();
    switch(*DAT_080106e8) {
    case 0:
      FUN_08008e50();
      break;
    case 1:
      FUN_080083b8();
      break;
    case 2:
      FUN_0800999c();
      break;
    case 3:
      FUN_08009a30();
      break;
    case 4:
      FUN_080089e4();
      break;
    case 5:
      FUN_08008838();
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      break;
    case 9:
      break;
    default:
      *DAT_080106e8 = 0;
    }
    pbVar1 = DAT_080106e8;
    *DAT_080106e8 = *DAT_080106e8 + 1;
    if (9 < *pbVar1) {
      *pbVar1 = 0;
    }
  }
  return;
}



/* ===== FUN_080106ec @ 0x80106EC ===== */

void FUN_080106ec(void)

{
  if (*(char *)(DAT_08010700 + 0x45) == '\x01') {
    FUN_0801114c();
  }
  return;
}



/* ===== FUN_08010704 @ 0x8010704 ===== */

void FUN_08010704(void)

{
  int iVar1;
  
  iVar1 = FUN_0801854c();
  if (iVar1 < 0) {
    iVar1 = FUN_0801854c();
    if (iVar1 < -0x7fffffff) {
      iVar1 = 0x7fffffff;
    }
    else {
      iVar1 = FUN_0801854c();
      iVar1 = -iVar1;
    }
  }
  else {
    iVar1 = FUN_0801854c();
  }
  if (200 < iVar1) {
    *(undefined1 *)(DAT_0801073c + 0x56) = 0;
  }
  return;
}



/* ===== FUN_08010740 @ 0x8010740 ===== */

void FUN_08010740(undefined1 *param_1)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  
  *param_1 = 0;
  iVar3 = FUN_08018504();
  if (iVar3 < (int)(uint)*(ushort *)(DAT_08010800 + 0x50)) {
    iVar3 = FUN_08018504();
    uVar4 = (uint)*(ushort *)(DAT_08010800 + 0x50) - iVar3;
    if ((int)uVar4 < 0) {
      uVar4 = 0;
    }
  }
  else {
    iVar3 = FUN_08018504();
    uVar4 = iVar3 - (uint)*(ushort *)(DAT_08010800 + 0x50);
    if ((int)uVar4 < 0) {
      uVar4 = 0;
    }
  }
  iVar3 = FUN_080184f8();
  if (iVar3 < *(short *)(DAT_08010800 + 0x48)) {
    iVar3 = FUN_080184f8();
    iVar3 = *(short *)(DAT_08010800 + 0x48) - iVar3;
    if (iVar3 < 0x8000) {
      if (iVar3 < -0x8000) {
        iVar3 = DAT_08010804;
      }
    }
    else {
      iVar3 = 0x7fff;
    }
    sVar1 = (short)iVar3;
  }
  else {
    iVar3 = FUN_080184f8();
    iVar3 = iVar3 - *(short *)(DAT_08010800 + 0x48);
    if (iVar3 < 0x8000) {
      if (iVar3 < -0x8000) {
        iVar3 = DAT_08010804;
      }
    }
    else {
      iVar3 = 0x7fff;
    }
    sVar1 = (short)iVar3;
  }
  if ((499 < (uVar4 & 0xffff)) || (500 < sVar1)) {
    *param_1 = 1;
    uVar2 = FUN_08018504();
    *(undefined2 *)(DAT_08010800 + 0x50) = uVar2;
    uVar2 = FUN_080184f8();
    *(undefined2 *)(DAT_08010800 + 0x48) = uVar2;
  }
  return;
}



/* ===== FUN_08010808 @ 0x8010808 ===== */

void FUN_08010808(char *param_1,ushort *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = DAT_08010a58;
  if (*(int *)(DAT_08010a58 + 0x40) == 500) {
    *(undefined4 *)(DAT_08010a58 + 0x40) = 0;
    uVar5 = (uint)*(ushort *)(iVar4 + 0x4c);
    *(ushort *)(iVar4 + 0x4c) = *param_2;
    if (((uVar5 < *(ushort *)(iVar4 + 0x4c)) || (1 < (int)(uVar5 - *(ushort *)(iVar4 + 0x4c)))) &&
       ((*(ushort *)(DAT_08010a58 + 0x4c) <= uVar5 ||
        (1 < (int)(*(ushort *)(DAT_08010a58 + 0x4c) - uVar5))))) {
      if (*(char *)(DAT_08010a58 + 0x67) != '\0') {
        iVar4 = *(byte *)(DAT_08010a58 + 0x67) - 1;
        if (iVar4 < 0) {
          iVar4 = 0;
        }
        *(char *)(DAT_08010a58 + 0x67) = (char)iVar4;
      }
    }
    else {
      if (*(byte *)(DAT_08010a58 + 0x67) < 0xc) {
        uVar5 = *(byte *)(DAT_08010a58 + 0x67) + 2;
        if (0xff < uVar5) {
          uVar5 = 0xff;
        }
        *(char *)(DAT_08010a58 + 0x67) = (char)uVar5;
      }
      if ((0xb < *(byte *)(DAT_08010a58 + 0x67)) &&
         (iVar2 = FUN_0801854c(), iVar4 = DAT_08010a58, iVar2 < 0xc9)) {
        *(undefined1 *)(DAT_08010a58 + 0x67) = 0;
        *(uint *)(iVar4 + 0x2c) = *(ushort *)(iVar4 + 0x4c) - 0xe;
      }
    }
  }
  else {
    uVar5 = *(int *)(DAT_08010a58 + 0x40) + 1;
    if (uVar5 < *(uint *)(DAT_08010a58 + 0x40)) {
      uVar5 = 0xffffffff;
    }
    *(uint *)(DAT_08010a58 + 0x40) = uVar5;
  }
  if (*(ushort *)(DAT_08010a58 + 0x4e) < 0xbb9) {
    uVar5 = *(ushort *)(DAT_08010a58 + 0x4e) + 1;
    if (0xffff < uVar5) {
      uVar5 = 0xffff;
    }
    *(short *)(DAT_08010a58 + 0x4e) = (short)uVar5;
  }
  uVar3 = FUN_0801854c();
  iVar4 = FUN_08019094(uVar3,0x32);
  iVar4 = (uint)*param_2 - iVar4 / 1000;
  if (*(int *)(DAT_08010a58 + 0x2c) < iVar4) {
    *(int *)(DAT_08010a58 + 0x2c) = iVar4;
  }
  if (0xf3c < iVar4) {
    if (*(int *)(DAT_08010a58 + 0x2c) < (int)DAT_08010a5c) {
      iVar2 = DAT_08010a5c << 0x1d;
    }
    else {
      iVar2 = *(int *)(DAT_08010a58 + 0x2c) + -0xf3c;
    }
    uVar3 = FUN_08019094(iVar4 + -0xf3c,0x123);
    iVar4 = FUN_08018328(uVar3,iVar2);
    if ((int)~DAT_08010a5c < iVar4) {
      iVar4 = 0x7fffffff;
    }
    else {
      iVar4 = iVar4 + 0xf3c;
    }
  }
  iVar2 = FUN_08018570();
  if ((iVar2 < 0x267a) &&
     (((0x1059 < iVar4 && (iVar2 = FUN_0801854c(), iVar2 < 0x65)) ||
      ((0x104a < iVar4 && (iVar2 = FUN_0801854c(), iVar2 < 0x3d)))))) {
    *param_1 = 'd';
  }
  else if (iVar4 < 0xf93) {
    *param_1 = '\n';
  }
  else {
    iVar4 = FUN_080189f0(iVar4,DAT_08010a60 + -0x5d6,DAT_08010a60,10,uVar3);
    if (0x7fff < iVar4) {
      iVar4 = 0x7fff;
    }
    iVar2 = FUN_08018570();
    iVar4 = iVar4 - iVar2;
    if (0x7fff < iVar4) {
      iVar4 = 0x7fff;
    }
    iVar4 = FUN_080187b6((int)(short)iVar4,DAT_08010a60 + -0x474,DAT_08010a60 + 0x52,2);
    if (iVar4 < 0xb) {
      *param_1 = (char)iVar4;
    }
    else {
      if (*(ushort *)(DAT_08010a58 + 0x4e) < 3000) {
        uVar5 = 5;
      }
      else {
        iVar2 = FUN_0801854c();
        if (iVar2 < 0xbb9) {
          iVar2 = FUN_0801854c();
          if (iVar2 < 500) {
            iVar2 = 500;
          }
          else {
            iVar2 = FUN_0801854c();
          }
        }
        else {
          iVar2 = 3000;
        }
        iVar2 = FUN_080181c6(iVar2 + -500,0x271);
        uVar5 = iVar2 + 1U & 0xff;
      }
      if (uVar5 == 0) {
        cVar1 = -1;
      }
      else {
        cVar1 = (char)((iVar4 - 10U) / uVar5);
      }
      *param_1 = cVar1 + '\n';
    }
  }
  return;
}



/* ===== FUN_08010a64 @ 0x8010A64 ===== */

void FUN_08010a64(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = FUN_0800ad90();
  if (iVar1 < 0) {
    iVar1 = FUN_0800ad90();
    if (-0x80000000 - iVar1 <= *param_1) goto LAB_08010a86;
    iVar1 = -0x80000000;
  }
  else {
LAB_08010a86:
    iVar1 = FUN_0800ad90();
    if (0 < iVar1) {
      iVar1 = FUN_0800ad90();
      if (0x7fffffff - iVar1 < *param_1) {
        iVar1 = 0x7fffffff;
        goto LAB_08010aac;
      }
    }
    iVar1 = FUN_0800ad90();
    iVar1 = iVar1 + *param_1;
  }
LAB_08010aac:
  iVar2 = FUN_0800ad90();
  if ((iVar2 <= DAT_08010c5c) && (DAT_08010c5c < iVar1)) {
    FUN_08012e5c();
    uVar3 = FUN_0800ad90();
    *(undefined4 *)(DAT_08010c60 + 0x18) = uVar3;
    goto LAB_08010bce;
  }
  iVar1 = FUN_0800ad90();
  if (iVar1 < 0) {
    iVar1 = FUN_0800ad90();
    if (-0x80000000 - iVar1 <= *param_1) goto LAB_08010ae6;
    iVar1 = -0x80000000;
  }
  else {
LAB_08010ae6:
    iVar1 = FUN_0800ad90();
    if (0 < iVar1) {
      iVar1 = FUN_0800ad90();
      if (0x7fffffff - iVar1 < *param_1) {
        iVar1 = 0x7fffffff;
        goto LAB_08010b0c;
      }
    }
    iVar1 = FUN_0800ad90();
    iVar1 = iVar1 + *param_1;
  }
LAB_08010b0c:
  if (iVar1 < DAT_08010c64) {
    FUN_08012e5c();
    uVar3 = FUN_0800ad90();
    *(undefined4 *)(DAT_08010c60 + 0x18) = uVar3;
    goto LAB_08010bce;
  }
  iVar1 = FUN_0800ad90();
  if (iVar1 < 0) {
    iVar1 = FUN_0800ad90();
    if (-0x80000000 - iVar1 <= *param_1) goto LAB_08010b3c;
    iVar1 = -0x80000000;
  }
  else {
LAB_08010b3c:
    iVar1 = FUN_0800ad90();
    if (0 < iVar1) {
      iVar1 = FUN_0800ad90();
      if (0x7fffffff - iVar1 < *param_1) {
        iVar1 = 0x7fffffff;
        goto LAB_08010b62;
      }
    }
    iVar1 = FUN_0800ad90();
    iVar1 = iVar1 + *param_1;
  }
LAB_08010b62:
  if (DAT_08010c68 <= iVar1) {
    FUN_08012e5c();
    uVar3 = FUN_0800ad90();
    *(undefined4 *)(DAT_08010c60 + 0x18) = uVar3;
    goto LAB_08010bce;
  }
  iVar1 = FUN_0800ad90();
  if (iVar1 < 0) {
    iVar1 = FUN_0800ad90();
    if (-0x80000000 - iVar1 <= *param_1) goto LAB_08010b96;
    FUN_08012e5c(0x80000000);
  }
  else {
LAB_08010b96:
    iVar1 = FUN_0800ad90();
    if (0 < iVar1) {
      iVar1 = FUN_0800ad90();
      if (0x7fffffff - iVar1 < *param_1) {
        FUN_08012e5c(0x7fffffff);
        goto LAB_08010bc6;
      }
    }
    iVar1 = FUN_0800ad90();
    FUN_08012e5c(iVar1 + *param_1);
  }
LAB_08010bc6:
  uVar3 = FUN_0800ad90();
  *(undefined4 *)(DAT_08010c60 + 0x18) = uVar3;
LAB_08010bce:
  iVar1 = FUN_0801854c();
  if (iVar1 < 0) {
    iVar1 = FUN_0801854c();
    if (iVar1 < -0x7fffffff) {
      iVar1 = 0x7fffffff;
    }
    else {
      iVar1 = FUN_0801854c();
      iVar1 = -iVar1;
    }
  }
  else {
    iVar1 = FUN_0801854c();
  }
  if (iVar1 < 100) {
    uVar4 = *(int *)(DAT_08010c6c + 0x44) + 1;
    if (uVar4 < *(uint *)(DAT_08010c6c + 0x44)) {
      uVar4 = 0xffffffff;
    }
    *(uint *)(DAT_08010c6c + 0x44) = uVar4;
  }
  else {
    iVar1 = FUN_0801854c();
    if (iVar1 < 0) {
      iVar1 = FUN_0801854c();
      if (iVar1 < -0x7fffffff) {
        iVar1 = 0x7fffffff;
      }
      else {
        iVar1 = FUN_0801854c();
        iVar1 = -iVar1;
      }
    }
    else {
      iVar1 = FUN_0801854c();
    }
    if (iVar1 < 200) {
      uVar4 = *(int *)(DAT_08010c6c + 0x44) - 100;
      if (*(uint *)(DAT_08010c6c + 0x44) < uVar4) {
        uVar4 = 0;
      }
      *(uint *)(DAT_08010c6c + 0x44) = uVar4;
    }
    else {
      *(undefined4 *)(DAT_08010c6c + 0x44) = 0;
    }
  }
  return;
}



/* ===== FUN_08010c70 @ 0x8010C70 ===== */

void FUN_08010c70(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 in_r3;
  undefined4 uStack_8;
  
  *(undefined4 *)*DAT_08010dd0 = 0;
  uStack_8 = in_r3;
  FUN_080031d6(DAT_08010dd4,0x2f);
  FUN_080031d6(DAT_08010dd8,0x8a);
  FUN_08012ff8(0);
  FUN_080103e4(&uStack_8);
  puVar1 = DAT_08010dd4;
  DAT_08010dd4[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  *(undefined2 *)((int)puVar1 + 0x22) = 0;
  puVar1[4] = 0;
  *(undefined1 *)((int)puVar1 + 0x2b) = 0;
  *(undefined2 *)(puVar1 + 8) = 0;
  FUN_08012fb0();
  FUN_08012fec(0);
  iVar2 = DAT_08010dd8;
  *(undefined1 *)(DAT_08010dd8 + 0x60) = 0;
  *(undefined1 *)(iVar2 + 0x61) = 0;
  *(undefined1 *)(iVar2 + 0x5e) = 0;
  *(undefined1 *)(iVar2 + 0x5f) = 0;
  FUN_08012fa4();
  iVar2 = DAT_08010dd8;
  *(undefined1 *)(DAT_08010dd8 + 0x6d) = 1;
  *(undefined1 *)(iVar2 + 0x70) = 0;
  *(undefined1 *)(iVar2 + 0x6e) = 0;
  *(undefined1 *)(iVar2 + 0x6f) = 0;
  *(undefined4 *)(iVar2 + 0x44) = 0;
  puVar1 = DAT_08010dd4;
  DAT_08010dd4[6] = 0;
  *(undefined1 *)((int)puVar1 + 0x2e) = 0;
  *(undefined2 *)(puVar1 + 10) = 0;
  FUN_080103e4(&uStack_8);
  FUN_08013010(0);
  FUN_0801301c(0);
  iVar2 = DAT_08010dd8;
  *(undefined1 *)(DAT_08010dd8 + 0x53) = 1;
  *(undefined1 *)(iVar2 + 0x54) = 0;
  *(undefined1 *)(iVar2 + 0x55) = 0;
  *(undefined1 *)(iVar2 + 0x56) = 0;
  *(undefined2 *)(DAT_08010dd4 + 7) = 0;
  FUN_08012fd4();
  iVar2 = DAT_08010dd8;
  *(undefined1 *)(DAT_08010dd8 + 0x65) = 0;
  *(undefined1 *)(iVar2 + 0x66) = 0;
  *(undefined4 *)(iVar2 + 0x40) = 0;
  *(undefined2 *)(iVar2 + 0x4c) = 0;
  *(undefined1 *)(iVar2 + 0x67) = 0;
  *(undefined4 *)(iVar2 + 0x2c) = 0;
  *(undefined2 *)(iVar2 + 0x4e) = 0;
  *(undefined2 *)(DAT_08010dd4 + 9) = 0;
  FUN_08012fbc();
  iVar2 = DAT_08010dd8;
  *(undefined1 *)(DAT_08010dd8 + 0x6a) = 1;
  *(undefined1 *)(iVar2 + 0x6b) = 0;
  *(undefined1 *)(iVar2 + 0x6c) = 0;
  *(undefined2 *)((int)DAT_08010dd4 + 0x26) = 0;
  FUN_08012fe0();
  iVar2 = DAT_08010dd8;
  *(undefined1 *)(DAT_08010dd8 + 100) = 0;
  *(undefined1 *)(iVar2 + 0x62) = 0;
  *(undefined1 *)(iVar2 + 99) = 0;
  *(undefined4 *)(iVar2 + 0x34) = 0;
  *(undefined4 *)(iVar2 + 0x38) = 0;
  *(undefined4 *)(iVar2 + 0x3c) = 0;
  puVar1 = DAT_08010dd4;
  *(undefined1 *)(DAT_08010dd4 + 0xb) = 0;
  puVar1[5] = 0;
  FUN_08013004();
  iVar2 = DAT_08010dd8;
  *(undefined1 *)(DAT_08010dd8 + 0x59) = 0;
  *(undefined1 *)(iVar2 + 0x57) = 0;
  *(undefined1 *)(iVar2 + 0x58) = 0;
  *(undefined4 *)(iVar2 + 0x30) = 0;
  *(undefined2 *)((int)DAT_08010dd4 + 0x1e) = 0;
  iVar2 = DAT_08010dd8;
  *(undefined1 *)(DAT_08010dd8 + 0x5c) = 0;
  *(undefined1 *)(iVar2 + 0x5d) = 0;
  *DAT_08010dd4 = 0;
  iVar2 = DAT_08010dd8;
  *(undefined1 *)(DAT_08010dd8 + 0x5a) = 0;
  *(undefined1 *)(iVar2 + 0x5b) = 0;
  *(undefined2 *)(iVar2 + 0x4a) = 0;
  *(undefined1 *)((int)DAT_08010dd4 + 0x2a) = 0;
  FUN_08012fc8();
  iVar2 = DAT_08010dd8;
  *(undefined1 *)(DAT_08010dd8 + 0x68) = 0;
  *(undefined1 *)(iVar2 + 0x69) = 0;
  *(undefined2 *)(iVar2 + 0x50) = 0;
  *(undefined2 *)(iVar2 + 0x48) = 0;
  return;
}



/* ===== FUN_08010ddc @ 0x8010DDC ===== */

void FUN_08010ddc(void)

{
  uint *puVar1;
  int iVar2;
  bool bVar3;
  int local_8;
  
  iVar2 = FUN_0800efb8();
  if (iVar2 == 0) {
    local_8 = 1000;
    do {
      bVar3 = local_8 != 0;
      local_8 = local_8 + -1;
    } while (bVar3);
    FUN_0800efb8();
  }
  puVar1 = DAT_08010e40;
  if ((((500 < *DAT_08010e40) || (DAT_08010e40[1] < 0x21000)) || (DAT_08010e44 < DAT_08010e40[1]))
     || ((DAT_08010e40[2] < 0x21000 || (DAT_08010e44 < DAT_08010e40[2])))) {
    *DAT_08010e40 = 0;
    puVar1[1] = 0x21000;
    puVar1[2] = 0x21000;
    FUN_0801770c();
  }
  return;
}



/* ===== FUN_08010e48 @ 0x8010E48 ===== */

void FUN_08010e48(ushort *param_1,ushort *param_2,int *param_3)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = *param_1 - 0xf;
  if ((uint)*param_1 < *param_1 - 0xf) {
    iVar2 = 0;
  }
  if ((int)(uint)*param_2 < iVar2) {
    cVar1 = (char)DAT_08010f74[5] + '\x01';
    if (0x7f < (char)DAT_08010f74[5] + 1) {
      cVar1 = '\x7f';
    }
    *(char *)(DAT_08010f74 + 5) = cVar1;
  }
  else {
    *(undefined1 *)(DAT_08010f74 + 5) = 0;
  }
  uVar3 = *param_1 + 1;
  if (0xffff < *param_1 + 1) {
    uVar3 = 0xffff;
  }
  if (*param_2 < uVar3) {
    iVar2 = 0;
  }
  else {
    if ((int)*DAT_08010f74 < 0) {
      if (*DAT_08010f74 == 0x80000000) {
        uVar3 = 0x80000000;
      }
      else {
        uVar3 = -*DAT_08010f74;
      }
    }
    else {
      uVar3 = *DAT_08010f74;
    }
    uVar4 = uVar3 / 1000;
    if (499 < uVar3 % 1000) {
      uVar4 = uVar4 + 1;
    }
    if ((int)*DAT_08010f74 < 0) {
      uVar4 = -uVar4;
    }
    uVar3 = (uint)*param_2 - (uint)*param_1;
    if (*param_2 < uVar3) {
      uVar3 = 0;
    }
    if ((int)uVar4 < 8) {
      uVar4 = 8;
    }
    iVar2 = FUN_080190e0(uVar4,uVar3);
  }
  if (iVar2 < (int)*DAT_08010f74) {
    if (((int)*DAT_08010f74 < 0) || ((int)(*DAT_08010f74 + 0x80000001) <= iVar2)) {
      if (((int)*DAT_08010f74 < 0) && ((int)(*DAT_08010f74 + 0x80000000) < iVar2)) {
        *param_3 = -0x80000000;
      }
      else {
        *param_3 = *DAT_08010f74 - iVar2;
      }
    }
    else {
      *param_3 = 0x7fffffff;
    }
  }
  else {
    *param_3 = 0;
  }
  return;
}



/* ===== FUN_08010f78 @ 0x8010F78 ===== */

void FUN_08010f78(void)

{
  int iVar1;
  int iVar2;
  
  *(undefined4 *)*DAT_08011004 = 0;
  FUN_080031d6(DAT_08011008,0xe);
  FUN_080031d6(DAT_0801100c,0x15);
  iVar1 = DAT_0801100c;
  *(byte *)(DAT_0801100c + 4) = (*(byte *)(DAT_0801100c + 4) & 0xf7) + 8;
  *(byte *)(iVar1 + 4) = (*(byte *)(iVar1 + 4) & 0xef) + 0x10;
  *(byte *)(iVar1 + 4) = (*(byte *)(iVar1 + 4) & 0xdf) + 0x20;
  *(byte *)(iVar1 + 4) = (*(byte *)(iVar1 + 4) & 0xbf) + 0x40;
  *(byte *)(iVar1 + 4) = (*(byte *)(iVar1 + 4) & 0x7f) + 0x80;
  *(byte *)(iVar1 + 5) = (*(byte *)(iVar1 + 5) & 0xfe) + 1;
  *(byte *)(iVar1 + 5) = (*(byte *)(iVar1 + 5) & 0xfd) + 2;
  iVar2 = DAT_0801100c;
  *(byte *)(DAT_0801100c + 5) = *(byte *)(iVar1 + 5) & 0xfb;
  iVar1 = DAT_0801100c;
  *(byte *)(DAT_0801100c + 4) = *(byte *)(iVar2 + 4) & 0xf8;
  *(undefined1 *)(iVar1 + 0x14) = 0;
  return;
}



/* ===== FUN_08011010 @ 0x8011010 ===== */

void FUN_08011010(int param_1,int param_2,undefined2 *param_3)

{
  if ((param_1 < param_2) && (param_2 < param_1 + 8)) {
    *param_3 = (short)param_2;
  }
  else {
    *param_3 = (short)param_1;
  }
  return;
}



/* ===== FUN_08011024 @ 0x8011024 ===== */

void FUN_08011024(int param_1,int param_2,undefined2 *param_3)

{
  if ((param_2 < param_1) && (param_1 < param_2 + 8)) {
    *param_3 = (short)param_2;
  }
  else {
    *param_3 = (short)param_1;
  }
  return;
}



/* ===== FUN_08011038 @ 0x8011038 ===== */

undefined4 FUN_08011038(void)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_3c;
  undefined4 local_38;
  uint local_34;
  undefined4 local_30;
  undefined2 local_2c;
  ushort local_2a;
  undefined1 local_28;
  ushort local_26;
  
  FUN_080031d6(&local_3c,0x30);
  iVar4 = 0;
  for (bVar1 = 0; bVar1 < 3; bVar1 = bVar1 + 1) {
    iVar4 = FUN_0800cb0c(&local_3c);
    if (iVar4 == 1) break;
  }
  if ((iVar4 == 1) &&
     (uVar2 = FUN_0800aa50(&local_3c,0x16), iVar4 = DAT_08011140, uVar2 == local_26)) {
    *(undefined4 *)(DAT_08011140 + 8) = local_3c;
    *(undefined4 *)(iVar4 + 0xc) = local_38;
    *(undefined1 *)(iVar4 + 7) = 0;
    if (local_34 < 60000) {
      *(uint *)(DAT_08011140 + 0x11) = local_34;
      *(uint *)(DAT_08011140 + 0x11) = local_34;
    }
    else {
      *(undefined4 *)(DAT_08011140 + 0x11) = 0;
      *(undefined4 *)(DAT_08011140 + 0x11) = 0;
    }
    iVar4 = DAT_08011140;
    *(undefined4 *)(DAT_08011140 + 0x27) = local_30;
    *(undefined2 *)(iVar4 + 0x15) = local_2c;
    *(undefined1 *)(iVar4 + 0x10) = 0;
    iVar4 = DAT_08011140;
    if ((local_2a < 0x3e9) && (299 < local_2a)) {
      *(ushort *)(DAT_08011140 + 0x18) = local_2a;
      *(undefined1 *)(iVar4 + 0x17) = 0;
    }
    else {
      *(undefined2 *)(DAT_08011140 + 0x18) = 1000;
      *(undefined1 *)(iVar4 + 0x17) = 1;
    }
    *(undefined1 *)(DAT_08011140 + 0x1a) = local_28;
    uVar3 = 1;
    *DAT_08011144 = 1;
    *DAT_08011148 = 1;
  }
  else {
    iVar4 = DAT_08011140;
    *(undefined4 *)(DAT_08011140 + 8) = 0;
    *(undefined4 *)(iVar4 + 0xc) = 0;
    *(undefined1 *)(iVar4 + 7) = 1;
    *(undefined4 *)(iVar4 + 0x11) = 0;
    *(undefined2 *)(iVar4 + 0x15) = 0;
    *(undefined1 *)(iVar4 + 0x10) = 1;
    *(undefined2 *)(iVar4 + 0x18) = 0;
    *(undefined1 *)(iVar4 + 0x1a) = 0;
    *(undefined1 *)(iVar4 + 0x17) = 1;
    uVar3 = 0;
  }
  return uVar3;
}



/* ===== FUN_0801114c @ 0x801114C ===== */

undefined4 FUN_0801114c(void)

{
  byte bVar1;
  int iVar2;
  undefined1 auStack_58 [32];
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined2 local_28;
  undefined2 local_26;
  ushort local_24;
  undefined2 local_22;
  
  bVar1 = 0;
  FUN_080031d6(&local_38,0x30);
  while ((bVar1 < 3 && (iVar2 = FUN_0800cb0c(&local_38), iVar2 != 1))) {
    bVar1 = bVar1 + 1;
  }
  local_30 = *(undefined4 *)(DAT_080111e8 + 0x2f);
  local_38 = *(undefined4 *)(DAT_080111e8 + 0x17);
  local_34 = *(undefined4 *)(DAT_080111e8 + 0x1b);
  local_2c = *(undefined4 *)(DAT_080111e8 + 0x46);
  local_28 = *(undefined2 *)(DAT_080111e8 + 0x2d);
  local_26 = *(undefined2 *)(DAT_080111e8 + 0x41);
  local_24 = (ushort)*(byte *)(DAT_080111e8 + 0x43);
  local_22 = FUN_0800aa50(&local_38,0x16);
  bVar1 = 0;
  while( true ) {
    if (2 < bVar1) {
      return 0;
    }
    FUN_080031a4(auStack_58,&local_28,0x20);
    iVar2 = FUN_0800cccc(local_38,local_34,local_30,local_2c);
    if (iVar2 != 0) break;
    bVar1 = bVar1 + 1;
  }
  return 1;
}



/* ===== FUN_080111ec @ 0x80111EC ===== */

void FUN_080111ec(void)

{
  ushort *puVar1;
  ushort *puVar2;
  
  puVar2 = DAT_0801128c;
  puVar1 = DAT_08011288;
  if ((int)((uint)*(byte *)(DAT_0801127c + 2) << 0x1e) < 0) {
    if (*(ushort *)(DAT_08011280 + 6) < *(ushort *)(DAT_08011284 + 0xc)) {
      *DAT_0801128c = 0;
    }
    else {
      *DAT_0801128c = *DAT_0801128c + 1;
      if (*(ushort *)(DAT_08011284 + 0x10) <= *puVar2) {
        *(byte *)(DAT_0801127c + 2) = *(byte *)(DAT_0801127c + 2) & 0xfd;
        *DAT_0801128c = 0;
        FUN_080176ac();
      }
    }
  }
  else if (*(ushort *)(DAT_08011284 + 10) < *(ushort *)(DAT_08011280 + 6)) {
    *DAT_08011288 = 0;
  }
  else {
    *DAT_08011288 = *DAT_08011288 + 1;
    if (*(ushort *)(DAT_08011284 + 0xe) <= *puVar1) {
      *(byte *)(DAT_0801127c + 2) = (*(byte *)(DAT_0801127c + 2) & 0xfd) + 2;
      *DAT_08011288 = 0;
      FUN_080176ac();
    }
  }
  return;
}



/* ===== FUN_08011290 @ 0x8011290 ===== */

void FUN_08011290(void)

{
  ushort *puVar1;
  
  puVar1 = DAT_08011300;
  if (-1 < (int)((uint)*(byte *)(DAT_080112f0 + 2) << 0x1d)) {
    if (((((int)((uint)*(byte *)(DAT_080112f0 + 1) << 0x1e) < 0) || (*DAT_080112f4 != '\0')) ||
        (*(uint *)(DAT_080112f8 + 4) < 1000)) || (*DAT_080112fc != '\x01')) {
      *DAT_08011300 = 0;
    }
    else {
      *DAT_08011300 = *DAT_08011300 + 1;
      if (299 < *puVar1) {
        *(byte *)(DAT_080112f0 + 2) = (*(byte *)(DAT_080112f0 + 2) & 0xfb) + 4;
        *DAT_08011300 = 0;
      }
    }
  }
  return;
}



/* ===== FUN_08011304 @ 0x8011304 ===== */

void FUN_08011304(void)

{
  ushort *puVar1;
  
  puVar1 = DAT_08011368;
  if (-1 < (int)((uint)*(byte *)(DAT_0801135c + 2) << 0x1c)) {
    if ((((*(byte *)(DAT_0801135c + 1) & 1) == 0) && (*DAT_08011360 == '\x01')) &&
       (999 < *(uint *)(DAT_08011364 + 4))) {
      *DAT_08011368 = *DAT_08011368 + 1;
      if (299 < *puVar1) {
        *(byte *)(DAT_0801135c + 2) = (*(byte *)(DAT_0801135c + 2) & 0xf7) + 8;
        *DAT_08011368 = 0;
      }
    }
    else {
      *DAT_08011368 = 0;
    }
  }
  return;
}



/* ===== FUN_0801136c @ 0x801136C ===== */

void FUN_0801136c(void)

{
  ushort *puVar1;
  ushort *puVar2;
  
  puVar2 = DAT_08011408;
  puVar1 = DAT_08011404;
  if ((int)((uint)*(byte *)(DAT_08011400 + 9) << 0x1c) < 0) {
    if ((*(char *)(DAT_08011400 + 8) < -0x1e) || ('d' < *(char *)(DAT_08011400 + 8))) {
      *DAT_08011408 = 0;
    }
    else {
      *DAT_08011408 = *DAT_08011408 + 1;
      if (0x31 < *puVar2) {
        *(byte *)(DAT_08011400 + 9) = *(byte *)(DAT_08011400 + 9) & 0xf7;
        *DAT_08011408 = 0;
      }
    }
  }
  else if ((*(char *)(DAT_08011400 + 8) < -0x1e) || ('d' < *(char *)(DAT_08011400 + 8))) {
    *DAT_08011404 = *DAT_08011404 + 1;
    if (0x31 < *puVar1) {
      *(byte *)(DAT_08011400 + 9) = (*(byte *)(DAT_08011400 + 9) & 0xf7) + 8;
      *DAT_08011404 = 0;
    }
  }
  else {
    *DAT_08011404 = 0;
  }
  return;
}



/* ===== FUN_0801140c @ 0x801140C ===== */

void FUN_0801140c(void)

{
  ushort *puVar1;
  ushort *puVar2;
  int iVar3;
  
  puVar2 = DAT_080115b8;
  puVar1 = DAT_080115b4;
  if ((int)((uint)*(byte *)(DAT_080115a8 + 2) << 0x1b) < 0) {
    if (*(ushort *)(DAT_080115ac + 6) < *(ushort *)(DAT_080115ac + 8)) {
      iVar3 = (uint)*(ushort *)(DAT_080115ac + 8) - (uint)*(ushort *)(DAT_080115ac + 6);
    }
    else {
      iVar3 = (uint)*(ushort *)(DAT_080115ac + 6) - (uint)*(ushort *)(DAT_080115ac + 8);
    }
    if ((int)(uint)*(ushort *)(DAT_080115b0 + 0x14) < iVar3) {
      *DAT_080115b8 = 0;
    }
    else {
      *DAT_080115b8 = *DAT_080115b8 + 1;
      if (*(ushort *)(DAT_080115b0 + 0x18) <= *puVar2) {
        *(byte *)(DAT_080115a8 + 2) = *(byte *)(DAT_080115a8 + 2) & 0xef;
        *DAT_080115b8 = 0;
      }
    }
  }
  else {
    if (*(ushort *)(DAT_080115ac + 6) < *(ushort *)(DAT_080115ac + 8)) {
      iVar3 = (uint)*(ushort *)(DAT_080115ac + 8) - (uint)*(ushort *)(DAT_080115ac + 6);
    }
    else {
      iVar3 = (uint)*(ushort *)(DAT_080115ac + 6) - (uint)*(ushort *)(DAT_080115ac + 8);
    }
    if ((iVar3 < (int)(uint)*(ushort *)(DAT_080115b0 + 0x12)) ||
       (*(ushort *)(DAT_080115ac + 6) < 0xc1d)) {
      *DAT_080115b4 = 0;
    }
    else {
      *DAT_080115b4 = *DAT_080115b4 + 1;
      if (*(ushort *)(DAT_080115b0 + 0x16) <= *puVar1) {
        *(byte *)(DAT_080115a8 + 2) = (*(byte *)(DAT_080115a8 + 2) & 0xef) + 0x10;
        *DAT_080115b4 = 0;
      }
    }
  }
  puVar2 = DAT_080115c0;
  puVar1 = DAT_080115bc;
  if ((*(byte *)(DAT_080115a8 + 2) & 1) == 0) {
    if (*(ushort *)(DAT_080115ac + 6) < *(ushort *)(DAT_080115ac + 8)) {
      iVar3 = (uint)*(ushort *)(DAT_080115ac + 8) - (uint)*(ushort *)(DAT_080115ac + 6);
    }
    else {
      iVar3 = (uint)*(ushort *)(DAT_080115ac + 6) - (uint)*(ushort *)(DAT_080115ac + 8);
    }
    if ((iVar3 < (int)(uint)*(ushort *)(DAT_080115b0 + 2)) ||
       (*(ushort *)(DAT_080115ac + 6) < 0xc1d)) {
      *DAT_080115bc = 0;
    }
    else {
      *DAT_080115bc = *DAT_080115bc + 1;
      if (*(ushort *)(DAT_080115b0 + 6) <= *puVar1) {
        *(byte *)(DAT_080115a8 + 2) = (*(byte *)(DAT_080115a8 + 2) & 0xfe) + 1;
        *DAT_080115bc = 0;
      }
    }
  }
  else {
    if (*(ushort *)(DAT_080115ac + 6) < *(ushort *)(DAT_080115ac + 8)) {
      iVar3 = (uint)*(ushort *)(DAT_080115ac + 8) - (uint)*(ushort *)(DAT_080115ac + 6);
    }
    else {
      iVar3 = (uint)*(ushort *)(DAT_080115ac + 6) - (uint)*(ushort *)(DAT_080115ac + 8);
    }
    if ((int)(uint)*(ushort *)(DAT_080115b0 + 4) < iVar3) {
      *DAT_080115c0 = 0;
    }
    else {
      *DAT_080115c0 = *DAT_080115c0 + 1;
      if (*(ushort *)(DAT_080115b0 + 8) <= *puVar2) {
        *(byte *)(DAT_080115a8 + 2) = *(byte *)(DAT_080115a8 + 2) & 0xfe;
        *DAT_080115c0 = 0;
      }
    }
  }
  return;
}



/* ===== FUN_080115c4 @ 0x80115C4 ===== */

void FUN_080115c4(void)

{
  ushort *puVar1;
  ushort *puVar2;
  
  puVar2 = DAT_08011690;
  puVar1 = DAT_0801168c;
  if ((int)((uint)*(byte *)(DAT_08011684 + 6) << 0x19) < 0) {
    if ((((*DAT_08011688 < -0x1e) || ('d' < *DAT_08011688)) || (DAT_08011688[1] < -0x1e)) ||
       ('d' < DAT_08011688[1])) {
      *DAT_08011690 = 0;
    }
    else {
      *DAT_08011690 = *DAT_08011690 + 1;
      if (0x31 < *puVar2) {
        *(byte *)(DAT_08011684 + 6) = *(byte *)(DAT_08011684 + 6) & 0xbf;
        *DAT_08011690 = 0;
      }
    }
  }
  else if (((*DAT_08011688 < -0x1e) || ('d' < *DAT_08011688)) ||
          ((DAT_08011688[1] < -0x1e || ('d' < DAT_08011688[1])))) {
    *DAT_0801168c = *DAT_0801168c + 1;
    if (0x31 < *puVar1) {
      *(byte *)(DAT_08011684 + 6) = (*(byte *)(DAT_08011684 + 6) & 0xbf) + 0x40;
      *DAT_0801168c = 0;
    }
  }
  else {
    *DAT_0801168c = 0;
  }
  return;
}



/* ===== FUN_08011694 @ 0x8011694 ===== */

void FUN_08011694(void)

{
  int iVar1;
  uint uVar2;
  
  for (uVar2 = 0; uVar2 < 0xc; uVar2 = uVar2 + 1 & 0xff) {
    if (((uVar2 < 0xb) &&
        ((int)(uint)DAT_08011980[uVar2] < (int)(*(ushort *)(DAT_08011984 + 4) - 800))) &&
       (*(ushort *)(DAT_08011984 + 4) + 700 < (uint)DAT_08011980[uVar2 + 2])) {
      DAT_08011988[uVar2] = DAT_08011988[uVar2] + 1;
      DAT_0801198c[uVar2] = 0;
      iVar1 = DAT_08011984;
      if (99 < DAT_08011988[uVar2]) {
        *(uint *)(DAT_08011984 + 0x11) = *(uint *)(DAT_08011984 + 0x11) | 1 << uVar2;
        *(uint *)(DAT_08011984 + 0x11) = *(uint *)(iVar1 + 0x11) | 1 << (uVar2 + 1 & 0xff);
        DAT_08011988[uVar2] = 0;
      }
    }
    else if (((int)(uint)DAT_08011980[uVar2] < (int)(*(ushort *)(DAT_08011984 + 4) - 800)) &&
            (*(ushort *)(DAT_08011984 + 4) + 700 < (uint)DAT_08011980[uVar2 + 1])) {
      DAT_08011988[uVar2] = DAT_08011988[uVar2] + 1;
      DAT_0801198c[uVar2] = 0;
      if (99 < DAT_08011988[uVar2]) {
        *(uint *)(DAT_08011984 + 0x11) = *(uint *)(DAT_08011984 + 0x11) | 1 << uVar2;
        DAT_08011988[uVar2] = 0;
      }
    }
    else if (((int)(uint)DAT_08011980[uVar2] < (int)(*(ushort *)(DAT_08011984 + 4) - 800)) &&
            ((int)(uint)DAT_08011980[uVar2 + 1] < (int)(*(ushort *)(DAT_08011984 + 4) - 800))) {
      DAT_08011988[uVar2] = DAT_08011988[uVar2] + 1;
      DAT_0801198c[uVar2] = 0;
      if (99 < DAT_08011988[uVar2]) {
        *(uint *)(DAT_08011984 + 0x11) = *(uint *)(DAT_08011984 + 0x11) | 1 << uVar2;
        DAT_08011988[uVar2] = 0;
      }
    }
    else if (((((int)(*(ushort *)(DAT_08011984 + 4) - 300) < (int)(uint)DAT_08011980[uVar2]) &&
              ((uint)DAT_08011980[uVar2] < *(ushort *)(DAT_08011984 + 4) + 300)) &&
             ((int)(*(ushort *)(DAT_08011984 + 4) - 300) < (int)(uint)DAT_08011980[uVar2 + 1])) &&
            ((uint)DAT_08011980[uVar2 + 1] < *(ushort *)(DAT_08011984 + 4) + 300)) {
      DAT_0801198c[uVar2] = DAT_0801198c[uVar2] + 1;
      DAT_08011988[uVar2] = 0;
      if (0x31 < DAT_0801198c[uVar2]) {
        *(uint *)(DAT_08011984 + 0x11) = *(uint *)(DAT_08011984 + 0x11) & ~(1 << uVar2);
        DAT_0801198c[uVar2] = 0;
      }
    }
    else {
      DAT_0801198c[uVar2] = 0;
    }
    if (uVar2 == 0) {
      if (*DAT_08011980 < 1000) {
        *DAT_08011988 = *DAT_08011988 + 1;
        *DAT_0801198c = 0;
        if (99 < *DAT_08011988) {
          *(uint *)(DAT_08011984 + 0x11) = *(uint *)(DAT_08011984 + 0x11) | 1;
          *DAT_08011988 = 0;
        }
      }
      else {
        *DAT_0801198c = *DAT_0801198c + 1;
        *DAT_08011988 = 0;
        if (0x31 < *DAT_0801198c) {
          *(uint *)(DAT_08011984 + 0x11) = *(uint *)(DAT_08011984 + 0x11) & 0xfffffffe;
          *DAT_0801198c = 0;
        }
      }
    }
    iVar1 = DAT_08011990;
    if (DAT_08011988[uVar2] == 0) {
      *(undefined1 *)(DAT_08011990 + uVar2) = 0;
    }
    else {
      *(char *)(DAT_08011990 + uVar2) = *(char *)(DAT_08011990 + uVar2) + '\x01';
      if (0x1d < *(byte *)(iVar1 + uVar2)) {
        *(undefined1 *)(iVar1 + uVar2) = 0;
        DAT_08011988[uVar2] = DAT_08011988[uVar2] - 1;
      }
    }
  }
  if (uVar2 == 0xc) {
    if (DAT_08011980[0xc] < 1000) {
      DAT_08011988[0xc] = DAT_08011988[0xc] + 1;
      DAT_0801198c[0xc] = 0;
      if (99 < DAT_08011988[0xc]) {
        *(uint *)(DAT_08011984 + 0x11) = *(uint *)(DAT_08011984 + 0x11) | 0x1000;
        DAT_08011988[0xc] = 0;
      }
    }
    else {
      DAT_0801198c[0xc] = DAT_0801198c[0xc] + 1;
      DAT_08011988[0xc] = 0;
      if (0x31 < DAT_0801198c[0xc]) {
        *(uint *)(DAT_08011984 + 0x11) = *(uint *)(DAT_08011984 + 0x11) & 0xffffefff;
        DAT_0801198c[0xc] = 0;
      }
    }
  }
  if (*(int *)(DAT_08011984 + 0x11) == 0) {
    *(byte *)(DAT_08011984 + 0xc) = *(byte *)(DAT_08011984 + 0xc) & 0x7f;
  }
  else {
    *(byte *)(DAT_08011984 + 0xc) = (*(byte *)(DAT_08011984 + 0xc) & 0x7f) + 0x80;
  }
  return;
}



/* ===== FUN_08011994 @ 0x8011994 ===== */

void FUN_08011994(void)

{
  int iVar1;
  ushort *puVar2;
  ushort *puVar3;
  
  puVar2 = DAT_08011bd4;
  if (*DAT_08011bc8 == '\0') {
    if ((*(byte *)(DAT_08011bcc + 8) & 1) == 0) {
      if (*(uint *)(DAT_08011bcc + 4) < *DAT_08011bd0) {
        *DAT_08011bd4 = 0;
      }
      else {
        *DAT_08011bd4 = *DAT_08011bd4 + 1;
        if ((ushort)DAT_08011bd0[1] <= *puVar2) {
          *(byte *)(DAT_08011bcc + 8) = (*(byte *)(DAT_08011bcc + 8) & 0xfe) + 1;
          *DAT_08011bd4 = 0;
        }
      }
    }
    puVar2 = DAT_08011bd8;
    if (-1 < (int)((uint)*(byte *)(DAT_08011bcc + 8) << 0x1e)) {
      if (*(uint *)(DAT_08011bcc + 4) < DAT_08011bd0[0xc]) {
        *DAT_08011bd8 = 0;
      }
      else {
        *DAT_08011bd8 = *DAT_08011bd8 + 1;
        if ((ushort)DAT_08011bd0[0xd] <= *puVar2) {
          *(byte *)(DAT_08011bcc + 8) = (*(byte *)(DAT_08011bcc + 8) & 0xfd) + 2;
          *DAT_08011bd8 = 0;
        }
      }
    }
  }
  else {
    *DAT_08011bd4 = 0;
    *DAT_08011bd8 = 0;
  }
  puVar3 = DAT_08011bf4;
  puVar2 = DAT_08011bdc;
  if (((*(byte *)(DAT_08011bcc + 8) & 1) == 0) &&
     (-1 < (int)((uint)*(byte *)(DAT_08011bcc + 8) << 0x1e))) {
    *DAT_08011bf4 = *DAT_08011bf4 + 1;
    if (699 < *puVar3) {
      *DAT_08011be0 = 0;
      *DAT_08011bf4 = 0;
    }
  }
  else {
    if ((*(byte *)(DAT_08011bcc + 8) & 1) != 0) {
      *DAT_08011bdc = *DAT_08011bdc + 1;
      if (((*DAT_08011bc8 != '\0') && (*(ushort *)((int)DAT_08011bd0 + 6) <= *puVar2)) &&
         ((*DAT_08011be0 < 3 ||
          ((((int)((uint)*(byte *)(DAT_08011be4 + 0xc) << 0x1c) < 0 ||
            ((int)((uint)*(byte *)(DAT_08011be4 + 0xc) << 0x1b) < 0)) ||
           ((int)((uint)*(byte *)(DAT_08011be4 + 0xc) << 0x19) < 0)))))) {
        *(byte *)(DAT_08011bcc + 8) = *(byte *)(DAT_08011bcc + 8) & 0xfe;
        *DAT_08011be0 = *DAT_08011be0 + 1;
        *DAT_08011bdc = 0;
      }
    }
    puVar2 = DAT_08011be8;
    if ((int)((uint)*(byte *)(DAT_08011bcc + 8) << 0x1e) < 0) {
      *DAT_08011be8 = *DAT_08011be8 + 1;
      if (((*DAT_08011bc8 != '\0') && (*(ushort *)((int)DAT_08011bd0 + 0x36) <= *puVar2)) &&
         (((*DAT_08011be0 < 3 ||
           (((int)((uint)*(byte *)(DAT_08011be4 + 0xc) << 0x1c) < 0 ||
            ((int)((uint)*(byte *)(DAT_08011be4 + 0xc) << 0x1b) < 0)))) ||
          ((int)((uint)*(byte *)(DAT_08011be4 + 0xc) << 0x19) < 0)))) {
        *(byte *)(DAT_08011bcc + 8) = *(byte *)(DAT_08011bcc + 8) & 0xfd;
        *DAT_08011be0 = *DAT_08011be0 + 1;
        *DAT_08011be8 = 0;
      }
    }
    puVar2 = DAT_08011bec;
    if (((*DAT_08011bc8 == '\x01') && (99 < *(uint *)(DAT_08011bcc + 4))) && (2 < *DAT_08011be0)) {
      *DAT_08011bec = *DAT_08011bec + 1;
      iVar1 = DAT_08011bcc;
      if (0x1d < *puVar2) {
        *(byte *)(DAT_08011bcc + 8) = *(byte *)(DAT_08011bcc + 8) & 0xfe;
        *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & 0xfd;
        *DAT_08011be0 = 0;
        *DAT_08011bec = 0;
      }
    }
    else {
      *DAT_08011bec = 0;
    }
    if ((*DAT_08011bf0 == '\0') && (2 < *DAT_08011be0)) {
      *DAT_08011bdc = 0;
      *DAT_08011be8 = 0;
      iVar1 = DAT_08011bcc;
      *(byte *)(DAT_08011bcc + 8) = *(byte *)(DAT_08011bcc + 8) & 0xfe;
      *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & 0xfd;
      *DAT_08011be0 = 0;
    }
    *DAT_08011bf4 = 0;
  }
  return;
}



/* ===== FUN_08011bf8 @ 0x8011BF8 ===== */

void FUN_08011bf8(void)

{
  ushort *puVar1;
  
  puVar1 = DAT_08011cc4;
  if (((*DAT_08011cb8 == '\0') || (*DAT_08011cb8 == '\x02')) &&
     ((*(byte *)(DAT_08011cbc + 0xc) & 1) == 0)) {
    if (*(ushort *)(DAT_08011cbc + 8) < *DAT_08011cc0) {
      *DAT_08011cc4 = 0;
    }
    else {
      *DAT_08011cc4 = *DAT_08011cc4 + 1;
      if (DAT_08011cc0[2] <= *puVar1) {
        *(byte *)(DAT_08011cbc + 0xc) = (*(byte *)(DAT_08011cbc + 0xc) & 0xfe) + 1;
        *DAT_08011cc4 = 0;
      }
    }
  }
  puVar1 = DAT_08011ccc;
  if ((*(byte *)(DAT_08011cbc + 0xc) & 1) != 0) {
    if ((*DAT_08011cb8 == '\x01') && (99 < *(uint *)(DAT_08011cc8 + 4))) {
      *(byte *)(DAT_08011cbc + 0xc) = *(byte *)(DAT_08011cbc + 0xc) & 0xfe;
      *DAT_08011ccc = 0;
    }
    else if (DAT_08011cc0[1] < *(ushort *)(DAT_08011cbc + 8)) {
      *DAT_08011ccc = 0;
    }
    else {
      *DAT_08011ccc = *DAT_08011ccc + 1;
      if (DAT_08011cc0[3] <= *puVar1) {
        *(byte *)(DAT_08011cbc + 0xc) = *(byte *)(DAT_08011cbc + 0xc) & 0xfe;
        *DAT_08011ccc = 0;
      }
    }
  }
  return;
}



/* ===== FUN_08011cd0 @ 0x8011CD0 ===== */

void FUN_08011cd0(void)

{
  ushort *puVar1;
  
  puVar1 = DAT_08011da0;
  if (((*DAT_08011d94 == '\x01') || (*DAT_08011d94 == '\x02')) &&
     (-1 < (int)((uint)*(byte *)(DAT_08011d98 + 0xc) << 0x1c))) {
    if (*(ushort *)(DAT_08011d9c + 0xe) < *(ushort *)(DAT_08011d98 + 6)) {
      *DAT_08011da0 = 0;
    }
    else {
      *DAT_08011da0 = *DAT_08011da0 + 1;
      if (*(ushort *)(DAT_08011d9c + 0x12) <= *puVar1) {
        *(byte *)(DAT_08011d98 + 0xc) = (*(byte *)(DAT_08011d98 + 0xc) & 0xf7) + 8;
        *DAT_08011da0 = 0;
        *DAT_08011da4 = 0;
      }
    }
  }
  puVar1 = DAT_08011da4;
  if ((int)((uint)*(byte *)(DAT_08011d98 + 0xc) << 0x1c) < 0) {
    if ((*DAT_08011d94 == '\0') && (99 < *(uint *)(DAT_08011da8 + 4))) {
      *(byte *)(DAT_08011d98 + 0xc) = *(byte *)(DAT_08011d98 + 0xc) & 0xf7;
      *DAT_08011da4 = 0;
    }
    else if (*(ushort *)(DAT_08011d98 + 6) < *(ushort *)(DAT_08011d9c + 0x10)) {
      *DAT_08011da4 = 0;
    }
    else {
      *DAT_08011da4 = *DAT_08011da4 + 1;
      if (*(ushort *)(DAT_08011d9c + 0x14) <= *puVar1) {
        *(byte *)(DAT_08011d98 + 0xc) = *(byte *)(DAT_08011d98 + 0xc) & 0xf7;
        *DAT_08011da4 = 0;
      }
    }
  }
  return;
}



/* ===== FUN_08011dac @ 0x8011DAC ===== */

void FUN_08011dac(void)

{
  ushort *puVar1;
  
  puVar1 = DAT_08011e68;
  if ((*DAT_08011e5c == '\0') && ((*(byte *)(DAT_08011e60 + 6) & 1) == 0)) {
    if (*(char *)(DAT_08011e60 + 2) < *DAT_08011e64) {
      *DAT_08011e68 = 0;
    }
    else {
      *DAT_08011e68 = *DAT_08011e68 + 1;
      if (*(ushort *)(DAT_08011e64 + 1) <= *puVar1) {
        *DAT_08011e6c = 0x8000;
        *(byte *)(DAT_08011e60 + 6) = (*(byte *)(DAT_08011e60 + 6) & 0xfe) + 1;
        *DAT_08011e68 = 0;
      }
    }
  }
  puVar1 = DAT_08011e70;
  if ((*(byte *)(DAT_08011e60 + 6) & 1) != 0) {
    if (DAT_08011e64[3] < *(char *)(DAT_08011e60 + 2)) {
      *DAT_08011e70 = 0;
    }
    else {
      *DAT_08011e70 = *DAT_08011e70 + 1;
      if (*(ushort *)(DAT_08011e64 + 4) <= *puVar1) {
        DAT_08011e6c[4] = 0x8000;
        *(byte *)(DAT_08011e60 + 6) = *(byte *)(DAT_08011e60 + 6) & 0xfe;
        *DAT_08011e70 = 0;
      }
    }
  }
  return;
}



/* ===== FUN_08011e74 @ 0x8011E74 ===== */

void FUN_08011e74(void)

{
  ushort *puVar1;
  
  puVar1 = DAT_08011f30;
  if ((*DAT_08011f24 == '\0') && (-1 < (int)((uint)*(byte *)(DAT_08011f28 + 6) << 0x1e))) {
    if (*(char *)(DAT_08011f2c + 6) < *(char *)(DAT_08011f28 + 1)) {
      *DAT_08011f30 = 0;
    }
    else {
      *DAT_08011f30 = *DAT_08011f30 + 1;
      if (*(ushort *)(DAT_08011f2c + 7) <= *puVar1) {
        *DAT_08011f34 = 0x8000;
        *(byte *)(DAT_08011f28 + 6) = (*(byte *)(DAT_08011f28 + 6) & 0xfd) + 2;
        *DAT_08011f30 = 0;
      }
    }
  }
  puVar1 = DAT_08011f38;
  if ((int)((uint)*(byte *)(DAT_08011f28 + 6) << 0x1e) < 0) {
    if (*(char *)(DAT_08011f28 + 1) < *(char *)(DAT_08011f2c + 9)) {
      *DAT_08011f38 = 0;
    }
    else {
      *DAT_08011f38 = *DAT_08011f38 + 1;
      if (*(ushort *)(DAT_08011f2c + 10) <= *puVar1) {
        DAT_08011f34[4] = 0x8000;
        *(byte *)(DAT_08011f28 + 6) = *(byte *)(DAT_08011f28 + 6) & 0xfd;
        *DAT_08011f38 = 0;
      }
    }
  }
  return;
}



/* ===== FUN_08011f3c @ 0x8011F3C ===== */

void FUN_08011f3c(void)

{
  int iVar1;
  ushort *puVar2;
  ushort *puVar3;
  
  puVar2 = DAT_08012344;
  if (*DAT_08012338 == '\x01') {
    if (-1 < (int)((uint)*(byte *)(DAT_0801233c + 8) << 0x1c)) {
      if (*(uint *)(DAT_0801233c + 4) < *(uint *)(DAT_08012340 + 8)) {
        *DAT_08012344 = 0;
      }
      else {
        *DAT_08012344 = *DAT_08012344 + 1;
        if (*(ushort *)(DAT_08012340 + 0xc) <= *puVar2) {
          *(byte *)(DAT_0801233c + 8) = (*(byte *)(DAT_0801233c + 8) & 0xf7) + 8;
          *DAT_08012344 = 0;
        }
      }
    }
    puVar2 = DAT_08012348;
    if (-1 < (int)((uint)*(byte *)(DAT_0801233c + 8) << 0x1b)) {
      if (*(uint *)(DAT_0801233c + 4) < *(uint *)(DAT_08012340 + 0x10)) {
        *DAT_08012348 = 0;
      }
      else {
        *DAT_08012348 = *DAT_08012348 + 1;
        if (*(ushort *)(DAT_08012340 + 0x14) <= *puVar2) {
          *(byte *)(DAT_0801233c + 8) = (*(byte *)(DAT_0801233c + 8) & 0xef) + 0x10;
          *DAT_08012348 = 0;
        }
      }
    }
  }
  else {
    *DAT_08012344 = 0;
    *DAT_08012348 = 0;
  }
  puVar3 = DAT_08012374;
  puVar2 = DAT_0801234c;
  if (((((int)((uint)*(byte *)(DAT_0801233c + 8) << 0x1c) < 0) ||
       ((int)((uint)*(byte *)(DAT_0801233c + 8) << 0x1b) < 0)) ||
      ((int)((uint)*(byte *)(DAT_0801233c + 8) << 0x1a) < 0)) ||
     ((int)((uint)*(byte *)(DAT_0801233c + 8) << 0x19) < 0)) {
    if (((((int)((uint)*(byte *)(DAT_0801233c + 8) << 0x1c) < 0) &&
         (*DAT_0801234c = *DAT_0801234c + 1, *DAT_08012338 != '\x01')) &&
        (*(ushort *)(DAT_08012340 + 0xe) <= *puVar2)) &&
       (((*DAT_08012350 < 3 || ((*(byte *)(DAT_08012354 + 0xc) & 1) != 0)) ||
        (((int)((uint)*(byte *)(DAT_08012354 + 0xc) << 0x1e) < 0 ||
         ((*(byte *)(DAT_08012354 + 0x17) & 1) != 0)))))) {
      *(byte *)(DAT_0801233c + 8) = *(byte *)(DAT_0801233c + 8) & 0xf7;
      *DAT_08012350 = *DAT_08012350 + 1;
      *DAT_0801234c = 0;
    }
    puVar2 = DAT_08012358;
    if (((((int)((uint)*(byte *)(DAT_0801233c + 8) << 0x1b) < 0) &&
         (*DAT_08012358 = *DAT_08012358 + 1, *DAT_08012338 != '\x01')) &&
        (*(ushort *)(DAT_08012340 + 0x16) <= *puVar2)) &&
       (((*DAT_08012350 < 3 || ((*(byte *)(DAT_08012354 + 0xc) & 1) != 0)) ||
        (((int)((uint)*(byte *)(DAT_08012354 + 0xc) << 0x1e) < 0 ||
         ((*(byte *)(DAT_08012354 + 0x17) & 1) != 0)))))) {
      *(byte *)(DAT_0801233c + 8) = *(byte *)(DAT_0801233c + 8) & 0xef;
      *DAT_08012350 = *DAT_08012350 + 1;
      *DAT_08012358 = 0;
    }
    puVar2 = DAT_0801235c;
    if (((((int)((uint)*(byte *)(DAT_0801233c + 8) << 0x1a) < 0) &&
         (*DAT_0801235c = *DAT_0801235c + 1, *DAT_08012338 != '\x01')) &&
        (*(ushort *)(DAT_08012340 + 0x1e) <= *puVar2)) &&
       ((((*DAT_08012350 < 3 || ((*(byte *)(DAT_08012354 + 0xc) & 1) != 0)) ||
         ((int)((uint)*(byte *)(DAT_08012354 + 0xc) << 0x1e) < 0)) ||
        ((*(byte *)(DAT_08012354 + 0x17) & 1) != 0)))) {
      *(byte *)(DAT_0801233c + 8) = *(byte *)(DAT_0801233c + 8) & 0xdf;
      *DAT_08012350 = *DAT_08012350 + 1;
      *DAT_0801235c = 0;
    }
    if ((int)((uint)*(byte *)(DAT_0801233c + 8) << 0x19) < 0) {
      *DAT_08012360 = *DAT_08012360 + 1;
      puVar2 = DAT_08012368;
      if ((*DAT_08012364 == '\0') && (*DAT_08012350 < 3)) {
        *DAT_08012368 = *DAT_08012368 + 1;
        if (99 < *puVar2) {
          *puVar2 = 0;
          *DAT_08012350 = *DAT_08012350 + 1;
          *(byte *)(DAT_0801233c + 8) = *(byte *)(DAT_0801233c + 8) & 0xbf;
        }
      }
      else {
        *DAT_08012368 = 0;
      }
      if (((*DAT_08012338 != '\x01') && (*(ushort *)(DAT_08012340 + 0x24) <= *DAT_08012360)) &&
         ((*DAT_08012350 < 3 ||
          ((((*(byte *)(DAT_08012354 + 0xc) & 1) != 0 ||
            ((int)((uint)*(byte *)(DAT_08012354 + 0xc) << 0x1e) < 0)) ||
           ((*(byte *)(DAT_08012354 + 0x17) & 1) != 0)))))) {
        *(byte *)(DAT_0801233c + 8) = *(byte *)(DAT_0801233c + 8) & 0xbf;
        *DAT_08012350 = *DAT_08012350 + 1;
        *DAT_08012360 = 0;
      }
    }
    puVar2 = DAT_0801236c;
    if ((*DAT_08012350 < 3) || (*DAT_08012364 != '\0')) {
      *DAT_0801236c = 0;
    }
    else {
      *DAT_0801236c = *DAT_0801236c + 1;
      iVar1 = DAT_0801233c;
      if (100 < *puVar2) {
        *(byte *)(DAT_0801233c + 8) = *(byte *)(DAT_0801233c + 8) & 0xfb;
        *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & 0xf7;
        *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & 0xef;
        *DAT_08012350 = 0;
        *DAT_0801236c = 0;
        if ((int)((uint)*(byte *)(DAT_0801233c + 8) << 0x1a) < 0) {
          *(byte *)(DAT_0801233c + 8) = *(byte *)(DAT_0801233c + 8) & 0xdf;
        }
        if ((int)((uint)*(byte *)(DAT_0801233c + 8) << 0x19) < 0) {
          *(byte *)(DAT_0801233c + 8) = *(byte *)(DAT_0801233c + 8) & 0xbf;
        }
      }
    }
    puVar2 = DAT_08012370;
    if (((*DAT_08012338 == '\0') && (2 < *DAT_08012350)) &&
       (*DAT_08012370 = *DAT_08012370 + 1, iVar1 = DAT_0801233c, 100 < *puVar2)) {
      *(byte *)(DAT_0801233c + 8) = *(byte *)(DAT_0801233c + 8) & 0xfb;
      *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & 0xf7;
      *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & 0xef;
      *DAT_08012350 = 0;
      *DAT_0801236c = 0;
      if ((int)((uint)*(byte *)(DAT_0801233c + 8) << 0x1a) < 0) {
        *(byte *)(DAT_0801233c + 8) = *(byte *)(DAT_0801233c + 8) & 0xdf;
      }
      if ((int)((uint)*(byte *)(DAT_0801233c + 8) << 0x19) < 0) {
        *(byte *)(DAT_0801233c + 8) = *(byte *)(DAT_0801233c + 8) & 0xbf;
      }
    }
    *DAT_08012374 = 0;
  }
  else {
    *DAT_08012374 = *DAT_08012374 + 1;
    if (699 < *puVar3) {
      *DAT_08012350 = 0;
      *DAT_08012374 = 0;
    }
    *DAT_0801234c = 0;
    *DAT_08012358 = 0;
    *DAT_0801235c = 0;
    *DAT_08012360 = 0;
  }
  if (*DAT_08012378 == '\x01') {
    *DAT_08012350 = 0;
    iVar1 = DAT_080123b0;
    *(byte *)(DAT_080123b0 + 8) = *(byte *)(DAT_0801233c + 8) & 0xf7;
    *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & 0xef;
    *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & 0xdf;
    *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & 0xbf;
    *(byte *)(iVar1 + 8) = *(byte *)(iVar1 + 8) & 0xfb;
    *DAT_080123b4 = 0;
  }
  return;
}



/* ===== FUN_080123b8 @ 0x80123B8 ===== */

void FUN_080123b8(void)

{
  ushort *puVar1;
  
  puVar1 = DAT_08012460;
  if ((int)((uint)*(byte *)(DAT_08012458 + 6) << 0x1c) < 0) {
    *DAT_08012460 = 0;
  }
  else if (*(char *)(DAT_08012458 + 2) < *(char *)(DAT_0801245c + 0x18)) {
    *DAT_08012460 = 0;
  }
  else {
    *DAT_08012460 = *DAT_08012460 + 1;
    if (*(ushort *)(DAT_0801245c + 0x19) <= *puVar1) {
      *(byte *)(DAT_08012458 + 6) = (*(byte *)(DAT_08012458 + 6) & 0xf7) + 8;
      *DAT_08012460 = 0;
    }
  }
  puVar1 = DAT_08012464;
  if ((int)((uint)*(byte *)(DAT_08012458 + 6) << 0x1c) < 0) {
    if (*(char *)(DAT_0801245c + 0x1b) < *(char *)(DAT_08012458 + 2)) {
      *DAT_08012464 = 0;
    }
    else {
      *DAT_08012464 = *DAT_08012464 + 1;
      if (*(ushort *)(DAT_0801245c + 0x1c) <= *puVar1) {
        *(byte *)(DAT_08012458 + 6) = *(byte *)(DAT_08012458 + 6) & 0xf7;
        *DAT_08012464 = 0;
      }
    }
  }
  return;
}



/* ===== FUN_08012468 @ 0x8012468 ===== */

void FUN_08012468(void)

{
  ushort *puVar1;
  
  puVar1 = DAT_0801251c;
  if (((*DAT_08012510 == '\x01') || (*DAT_08012510 == '\x02')) &&
     (-1 < (int)((uint)*(byte *)(DAT_08012514 + 6) << 0x1a))) {
    if (*(char *)(DAT_08012518 + 0x1e) < *(char *)(DAT_08012514 + 1)) {
      *DAT_0801251c = 0;
    }
    else {
      *DAT_0801251c = *DAT_0801251c + 1;
      if (*(ushort *)(DAT_08012518 + 0x1f) <= *puVar1) {
        *(byte *)(DAT_08012514 + 6) = (*(byte *)(DAT_08012514 + 6) & 0xdf) + 0x20;
        *DAT_0801251c = 0;
      }
    }
  }
  puVar1 = DAT_08012520;
  if ((int)((uint)*(byte *)(DAT_08012514 + 6) << 0x1a) < 0) {
    if (*(char *)(DAT_08012514 + 1) < *(char *)(DAT_08012518 + 0x21)) {
      *DAT_08012520 = 0;
    }
    else {
      *DAT_08012520 = *DAT_08012520 + 1;
      if (*(ushort *)(DAT_08012518 + 0x22) <= *puVar1) {
        *(byte *)(DAT_08012514 + 6) = *(byte *)(DAT_08012514 + 6) & 0xdf;
        *DAT_08012520 = 0;
      }
    }
  }
  return;
}



/* ===== FUN_08012524 @ 0x8012524 ===== */

void FUN_08012524(void)

{
  ushort *puVar1;
  ushort *puVar2;
  
  puVar2 = DAT_080125c0;
  puVar1 = DAT_080125bc;
  if ((int)((uint)*(byte *)(DAT_080125b4 + 9) << 0x1e) < 0) {
    if (*(char *)(DAT_080125b8 + 0x33) < *(char *)(DAT_080125b4 + 8)) {
      *DAT_080125c0 = 0;
    }
    else {
      *DAT_080125c0 = *DAT_080125c0 + 1;
      if (*(ushort *)(DAT_080125b8 + 0x34) <= *puVar2) {
        *(byte *)(DAT_080125b4 + 9) = *(byte *)(DAT_080125b4 + 9) & 0xfd;
        *DAT_080125c0 = 0;
      }
    }
  }
  else if (*(char *)(DAT_080125b4 + 8) < *(char *)(DAT_080125b8 + 0x30)) {
    *DAT_080125bc = 0;
  }
  else {
    *DAT_080125bc = *DAT_080125bc + 1;
    if (*(ushort *)(DAT_080125b8 + 0x31) <= *puVar1) {
      *(byte *)(DAT_080125b4 + 9) = (*(byte *)(DAT_080125b4 + 9) & 0xfd) + 2;
      *DAT_080125bc = 0;
    }
  }
  return;
}



/* ===== FUN_080125c4 @ 0x80125C4 ===== */

void FUN_080125c4(void)

{
  ushort *puVar1;
  
  puVar1 = DAT_08012694;
  if (((*DAT_08012688 == '\x01') || (*DAT_08012688 == '\x02')) &&
     (-1 < (int)((uint)*(byte *)(DAT_0801268c + 0xc) << 0x19))) {
    if (*(ushort *)(DAT_08012690 + 0x32) < *(ushort *)(DAT_0801268c + 4)) {
      *DAT_08012694 = 0;
    }
    else {
      *DAT_08012694 = *DAT_08012694 + 1;
      if (*(ushort *)(DAT_08012690 + 0x36) <= *puVar1) {
        *(byte *)(DAT_0801268c + 0xc) = (*(byte *)(DAT_0801268c + 0xc) & 0xbf) + 0x40;
        *DAT_08012694 = 0;
        *DAT_08012698 = 0;
      }
    }
  }
  puVar1 = DAT_08012698;
  if ((int)((uint)*(byte *)(DAT_0801268c + 0xc) << 0x19) < 0) {
    if ((*DAT_08012688 == '\0') && (99 < *(uint *)(DAT_0801269c + 4))) {
      *(byte *)(DAT_0801268c + 0xc) = *(byte *)(DAT_0801268c + 0xc) & 0xbf;
      *DAT_08012698 = 0;
    }
    else if (*(ushort *)(DAT_0801268c + 4) < *(ushort *)(DAT_08012690 + 0x34)) {
      *DAT_08012698 = 0;
    }
    else {
      *DAT_08012698 = *DAT_08012698 + 1;
      if (*(ushort *)(DAT_08012690 + 0x38) <= *puVar1) {
        *(byte *)(DAT_0801268c + 0xc) = *(byte *)(DAT_0801268c + 0xc) & 0xbf;
        *DAT_08012698 = 0;
      }
    }
  }
  return;
}



/* ===== FUN_080126a0 @ 0x80126A0 ===== */

void FUN_080126a0(ushort *param_1,int param_2)

{
  if (param_2 == 0) {
    *param_1 = *param_1 & 0xffbf;
  }
  else {
    *param_1 = *param_1 | 0x40;
  }
  return;
}



/* ===== FUN_080126b8 @ 0x80126B8 ===== */

void FUN_080126b8(void)

{
  FUN_080126a0(DAT_080126d4,0);
  FUN_080126d8(DAT_080126d4);
  FUN_0800e6a4(0x1000,0);
  return;
}



/* ===== FUN_080126d8 @ 0x80126D8 ===== */

void FUN_080126d8(int param_1)

{
  if (param_1 == DAT_08012710) {
    FUN_0800e6c4(DAT_08012710 >> 0x12,1);
    FUN_0800e6c4(param_1 >> 0x12,0);
  }
  else if (param_1 == DAT_08012714) {
    FUN_0800e6c4(0x80000);
    FUN_0800e6c4(0x80000,0);
  }
  return;
}



/* ===== FUN_08012718 @ 0x8012718 ===== */

bool FUN_08012718(int param_1,ushort param_2)

{
  return (*(ushort *)(param_1 + 8) & param_2) != 0;
}



/* ===== FUN_0801272a @ 0x801272A ===== */

undefined2 FUN_0801272a(int param_1)

{
  return *(undefined2 *)(param_1 + 0xc);
}



/* ===== FUN_08012730 @ 0x8012730 ===== */

void FUN_08012730(int param_1,undefined2 param_2)

{
  *(undefined2 *)(param_1 + 0xc) = param_2;
  return;
}



/* ===== FUN_08012734 @ 0x8012734 ===== */

void FUN_08012734(ushort *param_1,ushort *param_2)

{
  *param_1 = *param_1 & 0x3040 |
             *param_2 | param_2[1] | param_2[2] | param_2[3] | param_2[4] | param_2[5] | param_2[6]
             | param_2[7];
  param_1[0xe] = param_1[0xe] & 0xf7ff;
  param_1[8] = param_2[8];
  return;
}



/* ===== FUN_08012770 @ 0x8012770 ===== */

void FUN_08012770(void)

{
  FUN_0800e624(1);
  FUN_080126b8();
  return;
}



/* ===== FUN_08012780 @ 0x8012780 ===== */

void FUN_08012780(void)

{
  FUN_08012788();
  return;
}



/* ===== FUN_08012788 @ 0x8012788 ===== */

void FUN_08012788(void)

{
  undefined2 local_18;
  undefined2 local_16;
  undefined2 local_14;
  undefined2 local_12;
  undefined2 local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 local_a;
  undefined2 local_8;
  
  FUN_080127ec();
  FUN_0800a7de(DAT_080127e4,0x10);
  local_18 = 0;
  local_16 = 0x104;
  local_14 = 0;
  local_12 = 2;
  local_10 = 1;
  local_e = 0x200;
  local_c = 8;
  local_a = 0;
  local_8 = 7;
  FUN_08012734(DAT_080127e8,&local_18);
  FUN_080126a0(DAT_080127e8,1);
  return;
}



/* ===== FUN_080127ec @ 0x80127EC ===== */

undefined8 FUN_080127ec(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined2 local_18;
  undefined1 uStack_16;
  undefined1 local_15;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 local_c;
  
  local_18 = (undefined2)param_1;
  uStack_16 = (undefined1)((uint)param_1 >> 0x10);
  local_15 = (undefined1)((uint)param_1 >> 0x18);
  uStack_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  FUN_0800a7b0(&local_18);
  FUN_0800e6a4(4,1);
  FUN_0800e6a4(0x1001,1);
  local_18 = 0x20;
  local_15 = 0;
  local_10 = 2;
  local_c = 0;
  FUN_0800a5c8(DAT_0801286c,&local_18);
  local_18 = 0x80;
  local_15 = 0;
  local_10 = 2;
  FUN_0800a5c8(DAT_0801286c,&local_18);
  local_18 = 0x40;
  local_15 = 0;
  local_10 = 0;
  FUN_0800a5c8(DAT_0801286c,&local_18);
  local_18 = 0x10;
  local_15 = 0;
  local_10 = 1;
  FUN_0800a5c8(DAT_0801286c,&local_18);
  return CONCAT44(uStack_14,CONCAT13(local_15,CONCAT12(uStack_16,local_18)));
}



/* ===== FUN_08012870 @ 0x8012870 ===== */

undefined1 FUN_08012870(undefined4 param_1)

{
  undefined1 uVar1;
  ushort uVar2;
  int iVar3;
  bool bVar4;
  undefined4 local_10;
  
  uVar2 = 0;
  do {
    iVar3 = FUN_08012718(DAT_080128d4,2);
    if (iVar3 != 0) break;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x8001);
  FUN_08012730(DAT_080128d4,param_1);
  local_10 = 10;
  do {
    bVar4 = local_10 != 0;
    local_10 = local_10 + -1;
  } while (bVar4);
  uVar2 = 0;
  do {
    iVar3 = FUN_08012718(DAT_080128d4,1);
    if (iVar3 != 0) break;
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x8001);
  uVar1 = FUN_0801272a(DAT_080128d4);
  return uVar1;
}



/* ===== FUN_080128d8 @ 0x80128D8 ===== */

void FUN_080128d8(void)

{
  if (*(uint *)(DAT_080128f4 + 0x24) >> 0x18 == 0) {
    *DAT_080128f8 = 1;
  }
  else {
    *DAT_080128f8 = 0;
  }
  return;
}



/* ===== svc_Handler @ 0x80128FC ===== */

void svc_Handler(void)

{
  return;
}



/* ===== FUN_08012900 @ 0x8012900 ===== */

void FUN_08012900(void)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = DAT_08012934;
  *DAT_08012934 = *DAT_08012934 & 0xfe;
  *pbVar1 = *pbVar1 & 0xfd;
  *pbVar1 = *pbVar1 & 0xfb;
  *pbVar1 = *pbVar1 & 0xf7;
  iVar2 = DAT_08012938;
  *(undefined1 *)(DAT_08012938 + 7) = 0x19;
  *(undefined1 *)(iVar2 + 8) = 0x19;
  return;
}



/* ===== FUN_0801293c @ 0x801293C ===== */

void FUN_0801293c(void)

{
  undefined1 *puVar1;
  byte *pbVar2;
  
  puVar1 = DAT_080129b8;
  *DAT_080129b8 = *DAT_080129b4;
  puVar1[1] = DAT_080129b4[1];
  puVar1[2] = DAT_080129b4[2];
  puVar1[3] = DAT_080129b4[3];
  puVar1[4] = DAT_080129b4[4];
  pbVar2 = DAT_080129bc;
  if ((int)((uint)(byte)puVar1[6] << 0x19) < 0) {
    *DAT_080129bc = 0;
  }
  else if ((char)puVar1[5] < (char)puVar1[2]) {
    *DAT_080129bc = *DAT_080129bc + 1;
    if (10 < *pbVar2) {
      DAT_080129b8[5] = DAT_080129b8[2];
      *DAT_080129c0 = *DAT_080129c0 | 0x1000;
      *DAT_080129bc = 0;
    }
  }
  else {
    *DAT_080129bc = 0;
  }
  return;
}



/* ===== FUN_080129c4 @ 0x80129C4 ===== */

void FUN_080129c4(void)

{
  undefined4 *puVar1;
  
  puVar1 = DAT_080129f0;
  *DAT_080129f0 = *DAT_080129ec;
  *(undefined2 *)(puVar1 + 1) = *(undefined2 *)(DAT_080129ec + 1);
  *(undefined2 *)((int)puVar1 + 6) = *(undefined2 *)((int)DAT_080129ec + 6);
  *(undefined2 *)(puVar1 + 2) = *(undefined2 *)(DAT_080129ec + 2);
  *(undefined1 *)((int)puVar1 + 10) = *(undefined1 *)((int)DAT_080129ec + 10);
  *(undefined1 *)((int)puVar1 + 0xb) = *(undefined1 *)((int)DAT_080129ec + 0xb);
  return;
}



/* ===== FUN_080129f4 @ 0x80129F4 ===== */

void FUN_080129f4(void)

{
  if (*DAT_08012a18 != '\0') {
    if (*DAT_08012a1c < 10) {
      *DAT_08012a1c = *DAT_08012a1c + 1;
    }
    else {
      *DAT_08012a18 = '\0';
    }
  }
  return;
}



/* ===== FUN_08012a20 @ 0x8012A20 ===== */

void FUN_08012a20(void)

{
  FUN_080132bc();
  return;
}



/* ===== FUN_08012a28 @ 0x8012A28 ===== */

void FUN_08012a28(int param_1,byte param_2)

{
  if (param_1 == DAT_08012a50) {
    *DAT_08012a54 = *DAT_08012a54 & 0xf0 | param_2 & 0xf;
  }
  else if (param_1 == DAT_08012a58) {
    *DAT_08012a54 = *DAT_08012a54 & 0xf | param_2 << 4;
  }
  return;
}



/* ===== FUN_08012a5c @ 0x8012A5C ===== */

void FUN_08012a5c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  undefined1 local_11;
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  undefined1 local_d;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8._2_1_ = (undefined1)((uint)param_2 >> 0x10);
  local_14 = local_8._2_1_;
  local_8._0_1_ = (undefined1)param_2;
  local_13 = (undefined1)local_8;
  local_c._3_1_ = (undefined1)((uint)param_1 >> 0x18);
  local_12 = local_c._3_1_;
  local_8._1_1_ = (undefined1)((uint)param_2 >> 8);
  local_11 = local_8._1_1_;
  local_c = param_1;
  local_8 = param_2;
  iVar1 = FUN_0800ed80(0,&local_14);
  if (iVar1 != 0) {
    local_10 = local_c._2_1_;
    local_f = local_c._1_1_;
    local_e = (undefined1)local_c;
    local_d = 0x40;
    FUN_0800ea3c(0,&local_10);
  }
  return;
}



/* ===== FUN_08012abc @ 0x8012ABC ===== */

void FUN_08012abc(void)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  
  iVar3 = 0;
  *DAT_08012b8c = *DAT_08012b8c | 1;
  do {
    iVar3 = iVar3 + 1;
    if ((int)(*DAT_08012b8c << 0x1e) < 0) break;
  } while (iVar3 != 0x500);
  if ((int)(*DAT_08012b8c << 0x1e) < 0) {
    FUN_08006b20();
    puVar1 = DAT_08012b98;
    *DAT_08012b98 = *DAT_08012b98 & 0xfffffffc;
    *puVar1 = *puVar1;
    puVar1 = DAT_08012b8c;
    DAT_08012b8c[1] = DAT_08012b8c[1];
    puVar1[1] = puVar1[1];
    puVar1[1] = puVar1[1];
    puVar2 = DAT_08012b8c;
    DAT_08012b8c[1] = puVar1[1] & DAT_08012b9c;
    puVar2[0x10] = puVar2[0x10] & 0xfffffffc;
    puVar2[1] = puVar2[1];
    puVar2[0x10] = puVar2[0x10] | 1;
    *puVar2 = *puVar2 | 0x1000000;
    puVar1 = DAT_08012b8c;
    do {
    } while ((*DAT_08012b8c & 0x2000000) == 0);
    DAT_08012b8c[1] = DAT_08012b8c[1] & 0xfffffffc;
    puVar1[1] = puVar1[1] | 3;
    do {
    } while ((DAT_08012b8c[1] & 0xc) != 0xc);
  }
  else {
    *DAT_08012b94 = DAT_08012b90;
  }
  return;
}



/* ===== FUN_08012ba0 @ 0x8012BA0 ===== */

/* WARNING: Removing unreachable block (ram,0x08012bd8) */
/* WARNING: Removing unreachable block (ram,0x08012bd0) */
/* WARNING: Removing unreachable block (ram,0x08012bd4) */
/* WARNING: Removing unreachable block (ram,0x08012be6) */
/* WARNING: Removing unreachable block (ram,0x08012bda) */

void FUN_08012ba0(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_28;
  
  uVar2 = DAT_08012cd4;
  bVar1 = false;
  FUN_0800e4cc(0x10000);
  iVar3 = FUN_0800e8a4();
  if (iVar3 == 1) {
    if (DAT_08012cd4 < uVar2) {
      uVar5 = 0x30000;
      iVar3 = 0;
      local_28 = 2;
    }
    else if (uVar2 == DAT_08012cd4) {
      uVar5 = 0x30000;
      iVar3 = 0;
      local_28 = 0;
    }
    else if (DAT_08012cd4 == uVar2 * (DAT_08012cd4 / uVar2)) {
      uVar5 = 0x10000;
      iVar3 = (DAT_08012cd4 / uVar2 - 2) * 0x40000;
      local_28 = 0;
    }
    else {
      uVar5 = 0x30000;
      iVar3 = (DAT_08012cd8 / uVar2 - 2) * 0x40000;
      local_28 = 0;
    }
    iVar4 = FUN_0800e858(99);
    if (iVar4 == 0) {
      FUN_0800e540(4,0x60);
      do {
        iVar4 = FUN_0800e914();
      } while (iVar4 != 1);
      bVar1 = true;
    }
    FUN_0800e60c(0);
    FUN_08008360(0);
    FUN_0800e4b4(0);
    FUN_0800e598(0);
    FUN_0800e580(0);
    FUN_0800e6f0(0);
    FUN_0800e5b0(uVar5,iVar3,local_28);
    FUN_0800e6f0(1);
    do {
      iVar3 = FUN_0800e858(0x39);
    } while (iVar3 == 0);
    FUN_0800e60c(3);
    do {
      iVar3 = FUN_0800e894();
    } while (iVar3 != 0xc);
    if (bVar1) {
      FUN_0800e540(0,0x60);
    }
  }
  else {
    FUN_08012e10();
  }
  return;
}



/* ===== FUN_08012cdc @ 0x8012CDC ===== */

/* WARNING: Removing unreachable block (ram,0x08012d12) */
/* WARNING: Removing unreachable block (ram,0x08012d0a) */
/* WARNING: Removing unreachable block (ram,0x08012d0e) */
/* WARNING: Removing unreachable block (ram,0x08012d20) */
/* WARNING: Removing unreachable block (ram,0x08012d14) */

void FUN_08012cdc(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_28;
  
  uVar2 = DAT_08012e08;
  bVar1 = false;
  FUN_0800e518(1);
  iVar3 = FUN_0800e8dc();
  if (iVar3 == 1) {
    if (DAT_08012e08 < uVar2) {
      uVar5 = 1;
      iVar3 = 0;
      local_28 = 2;
    }
    else if (uVar2 == DAT_08012e08) {
      uVar5 = 1;
      iVar3 = 0;
      local_28 = 0;
    }
    else if (DAT_08012e08 == uVar2 * (DAT_08012e08 / uVar2)) {
      uVar5 = 0;
      iVar3 = (DAT_08012e08 / uVar2 - 2) * 0x40000;
      local_28 = 0;
    }
    else {
      uVar5 = 1;
      iVar3 = (DAT_08012e0c / uVar2 - 2) * 0x40000;
      local_28 = 0;
    }
    iVar4 = FUN_0800e858(99);
    if (iVar4 == 0) {
      FUN_0800e540(4,0x60);
      do {
        iVar4 = FUN_0800e914();
      } while (iVar4 != 1);
      bVar1 = true;
    }
    FUN_0800e60c(0);
    FUN_08008360(0);
    FUN_0800e4b4(0);
    FUN_0800e598(0);
    FUN_0800e580(0);
    FUN_0800e6f0(0);
    FUN_0800e5b0(uVar5,iVar3,local_28);
    FUN_0800e6f0(1);
    do {
      iVar3 = FUN_0800e858(0x39);
    } while (iVar3 == 0);
    FUN_0800e60c(3);
    do {
      iVar3 = FUN_0800e894();
    } while (iVar3 != 0xc);
    if (bVar1) {
      FUN_0800e540(0,0x60);
    }
  }
  else {
    FUN_08012e10();
  }
  return;
}



/* ===== FUN_08012e10 @ 0x8012E10 ===== */

void FUN_08012e10(void)

{
  int iVar1;
  
  iVar1 = FUN_0800e858(99);
  if (iVar1 == 0) {
    FUN_0800e540(4,0x60);
    do {
      iVar1 = FUN_0800e914();
    } while (iVar1 != 1);
  }
  FUN_080082e8(0x10);
  FUN_0800e60c(0);
  do {
    iVar1 = FUN_0800e894();
  } while (iVar1 != 0);
  FUN_08008360();
  FUN_0800e4b4(0);
  FUN_0800e598(0);
  FUN_0800e580(0);
  return;
}



/* ===== FUN_08012e5c @ 0x8012E5C ===== */

void FUN_08012e5c(undefined4 param_1)

{
  *DAT_08012e64 = param_1;
  return;
}



/* ===== FUN_08012e68 @ 0x8012E68 ===== */

void FUN_08012e68(undefined4 param_1)

{
  *(undefined4 *)(DAT_08012e70 + 0x46) = param_1;
  return;
}



/* ===== FUN_08012e74 @ 0x8012E74 ===== */

void FUN_08012e74(undefined4 param_1)

{
  *(undefined4 *)(DAT_08012e7c + 0x17) = param_1;
  return;
}



/* ===== FUN_08012e80 @ 0x8012E80 ===== */

void FUN_08012e80(undefined4 param_1)

{
  *(undefined4 *)(DAT_08012e88 + 0x1b) = param_1;
  return;
}



/* ===== FUN_08012e8c @ 0x8012E8C ===== */

void FUN_08012e8c(undefined4 param_1)

{
  *(short *)(DAT_08012e98 + 2) = (short)param_1;
  *(undefined4 *)(DAT_08012e9c + 0x2f) = param_1;
  return;
}



/* ===== FUN_08012ea0 @ 0x8012EA0 ===== */

void FUN_08012ea0(undefined2 param_1)

{
  *(undefined2 *)(DAT_08012ea8 + 0x2d) = param_1;
  return;
}



/* ===== FUN_08012eac @ 0x8012EAC ===== */

void FUN_08012eac(undefined2 param_1)

{
  *(undefined2 *)(DAT_08012eb4 + 0x20) = param_1;
  return;
}



/* ===== FUN_08012eb8 @ 0x8012EB8 ===== */

void FUN_08012eb8(undefined2 param_1)

{
  *(undefined2 *)(DAT_08012ec0 + 0x41) = param_1;
  return;
}



/* ===== FUN_08012ec4 @ 0x8012EC4 ===== */

void FUN_08012ec4(undefined1 param_1)

{
  *(undefined1 *)(DAT_08012ecc + 0x43) = param_1;
  return;
}



/* ===== FUN_08012ed0 @ 0x8012ED0 ===== */

void FUN_08012ed0(int param_1)

{
  byte *pbVar1;
  
  pbVar1 = DAT_08012f10;
  *DAT_08012f10 = (char)(param_1 / 100) + (0x32 < param_1 % 100);
  *(uint *)(DAT_08012f10 + 0xc) = (uint)*DAT_08012f10 * (*(uint *)(pbVar1 + 8) / 100);
  *(short *)(DAT_08012f14 + 0x27) = (short)param_1;
  return;
}



/* ===== FUN_08012f18 @ 0x8012F18 ===== */

void FUN_08012f18(undefined2 param_1)

{
  *(undefined2 *)(DAT_08012f20 + 0x13) = param_1;
  return;
}



/* ===== FUN_08012f24 @ 0x8012F24 ===== */

void FUN_08012f24(undefined2 param_1)

{
  *(undefined2 *)(DAT_08012f2c + 0x10) = param_1;
  return;
}



/* ===== FUN_08012f30 @ 0x8012F30 ===== */

void FUN_08012f30(undefined4 param_1)

{
  *(undefined4 *)(DAT_08012f38 + 4) = param_1;
  return;
}



/* ===== FUN_08012f3c @ 0x8012F3C ===== */

void FUN_08012f3c(undefined4 param_1)

{
  *(undefined4 *)(DAT_08012f44 + 8) = param_1;
  return;
}



/* ===== FUN_08012f48 @ 0x8012F48 ===== */

void FUN_08012f48(undefined4 param_1)

{
  *(undefined4 *)(DAT_08012f50 + 0xc) = param_1;
  return;
}



/* ===== FUN_08012f54 @ 0x8012F54 ===== */

void FUN_08012f54(undefined1 param_1)

{
  *(undefined1 *)(DAT_08012f5c + 0x12) = param_1;
  return;
}



/* ===== FUN_08012f60 @ 0x8012F60 ===== */

void FUN_08012f60(int param_1)

{
  *(char *)(DAT_08012f74 + 0x22) = (char)param_1;
  if (param_1 == 1) {
    *DAT_08012f78 = 0;
  }
  return;
}



/* ===== FUN_08012f7c @ 0x8012F7C ===== */

void FUN_08012f7c(undefined4 param_1)

{
  *(undefined4 *)(DAT_08012f84 + 0x34) = param_1;
  return;
}



/* ===== FUN_08012f88 @ 0x8012F88 ===== */

void FUN_08012f88(undefined1 param_1)

{
  int iVar1;
  
  iVar1 = DAT_08012f9c;
  *(undefined1 *)(DAT_08012f9c + 0x45) = param_1;
  if (*(char *)(iVar1 + 0x45) == '\x01') {
    *DAT_08012fa0 = 1;
  }
  return;
}



/* ===== FUN_08012fa4 @ 0x8012FA4 ===== */

void FUN_08012fa4(undefined1 param_1)

{
  *(undefined1 *)(DAT_08012fac + 0x1f) = param_1;
  return;
}



/* ===== FUN_08012fb0 @ 0x8012FB0 ===== */

void FUN_08012fb0(undefined1 param_1)

{
  *(undefined1 *)(DAT_08012fb8 + 5) = param_1;
  return;
}



/* ===== FUN_08012fbc @ 0x8012FBC ===== */

void FUN_08012fbc(undefined1 param_1)

{
  *(undefined1 *)(DAT_08012fc4 + 0x2c) = param_1;
  return;
}



/* ===== FUN_08012fc8 @ 0x8012FC8 ===== */

void FUN_08012fc8(undefined1 param_1)

{
  *(undefined1 *)(DAT_08012fd0 + 0x44) = param_1;
  return;
}



/* ===== FUN_08012fd4 @ 0x8012FD4 ===== */

void FUN_08012fd4(undefined1 param_1)

{
  *(undefined1 *)(DAT_08012fdc + 0x29) = param_1;
  return;
}



/* ===== FUN_08012fe0 @ 0x8012FE0 ===== */

void FUN_08012fe0(undefined1 param_1)

{
  *(undefined1 *)(DAT_08012fe8 + 0x33) = param_1;
  return;
}



/* ===== FUN_08012fec @ 0x8012FEC ===== */

void FUN_08012fec(undefined1 param_1)

{
  *(undefined1 *)(DAT_08012ff4 + 0x16) = param_1;
  return;
}



/* ===== FUN_08012ff8 @ 0x8012FF8 ===== */

void FUN_08012ff8(undefined1 param_1)

{
  *DAT_08013000 = param_1;
  return;
}



/* ===== FUN_08013004 @ 0x8013004 ===== */

void FUN_08013004(undefined1 param_1)

{
  *(undefined1 *)(DAT_0801300c + 0x38) = param_1;
  return;
}



/* ===== FUN_08013010 @ 0x8013010 ===== */

void FUN_08013010(undefined1 param_1)

{
  *(undefined1 *)(DAT_08013018 + 0x23) = param_1;
  return;
}



/* ===== FUN_0801301c @ 0x801301C ===== */

void FUN_0801301c(undefined1 param_1)

{
  *(undefined1 *)(DAT_08013024 + 0x26) = param_1;
  return;
}



/* ===== FUN_08013028 @ 0x8013028 ===== */

void FUN_08013028(undefined2 param_1)

{
  *(undefined2 *)(DAT_08013030 + 0x2a) = param_1;
  return;
}



/* ===== FUN_08013034 @ 0x8013034 ===== */

void FUN_08013034(undefined4 param_1)

{
  byte *pbVar1;
  
  pbVar1 = DAT_08013054;
  *(undefined4 *)(DAT_08013054 + 8) = param_1;
  *(uint *)(DAT_08013054 + 0xc) = (uint)*DAT_08013054 * (*(uint *)(pbVar1 + 8) / 100);
  *(undefined4 *)(DAT_08013058 + 0x39) = param_1;
  return;
}



/* ===== FUN_0801305c @ 0x801305C ===== */

void FUN_0801305c(undefined4 param_1)

{
  *(undefined4 *)(DAT_08013064 + 0x12) = param_1;
  return;
}



/* ===== FUN_08013068 @ 0x8013068 ===== */

void FUN_08013068(undefined4 param_1)

{
  *(undefined4 *)(DAT_08013070 + 10) = param_1;
  return;
}



/* ===== FUN_08013074 @ 0x8013074 ===== */

void FUN_08013074(undefined4 param_1)

{
  *(undefined4 *)(DAT_0801307c + 0xe) = param_1;
  return;
}



/* ===== FUN_08013080 @ 0x8013080 ===== */

void FUN_08013080(undefined4 param_1)

{
  *(undefined4 *)(DAT_08013088 + 6) = param_1;
  return;
}



/* ===== FUN_0801308c @ 0x801308C ===== */

void FUN_0801308c(undefined2 param_1)

{
  *DAT_08013094 = param_1;
  return;
}



/* ===== FUN_08013098 @ 0x8013098 ===== */

void FUN_08013098(undefined2 param_1)

{
  *(undefined2 *)(DAT_080130a0 + 1) = param_1;
  return;
}



/* ===== FUN_080130a4 @ 0x80130A4 ===== */

void FUN_080130a4(undefined2 param_1)

{
  *(undefined2 *)(DAT_080130ac + 0x3d) = param_1;
  return;
}



/* ===== FUN_080130b0 @ 0x80130B0 ===== */

void FUN_080130b0(int param_1)

{
  *(char *)(DAT_080130c4 + 1) = (char)(param_1 / 100);
  *(short *)(DAT_080130c8 + 0x3f) = (short)param_1;
  return;
}



/* ===== FUN_080130cc @ 0x80130CC ===== */

void FUN_080130cc(undefined2 param_1)

{
  *(undefined2 *)(DAT_080130d4 + 0x24) = param_1;
  return;
}



/* ===== FUN_080130d8 @ 0x80130D8 ===== */

void FUN_080130d8(undefined2 param_1)

{
  *DAT_080130e0 = param_1;
  return;
}



/* ===== FUN_080130e4 @ 0x80130E4 ===== */

void FUN_080130e4(undefined2 param_1)

{
  *(undefined2 *)(DAT_080130ec + 3) = param_1;
  return;
}



/* ===== FUN_080130f0 @ 0x80130F0 ===== */

void FUN_080130f0(void)

{
  FUN_08007b8c(0);
  return;
}



/* ===== FUN_080130fc @ 0x80130FC ===== */

void FUN_080130fc(void)

{
  char cVar1;
  ushort *puVar2;
  byte *pbVar3;
  
  cVar1 = *DAT_0801328c;
  if (cVar1 == '\0') {
    *DAT_08013290 = 0;
    *DAT_08013294 = 3;
    FUN_08007bc4(0);
    *DAT_0801328c = '\x01';
    FUN_08007cd0(5);
  }
  else if (cVar1 == '\x01') {
    *DAT_08013294 = 3;
    puVar2 = DAT_080132a4;
    if (*DAT_08013298 == '\x02') {
      *DAT_08013298 = '\0';
      FUN_08007c9c();
      *DAT_0801329c = *DAT_0801329c + 1;
      *DAT_080132a0 = *DAT_080132a0 + 1;
      *DAT_0801328c = '\x03';
      *DAT_080132a4 = 0;
    }
    else if (*DAT_08013298 == '\x01') {
      *DAT_08013298 = '\0';
      FUN_08007cc0();
      *DAT_0801328c = '\x02';
      *DAT_080132a4 = 0;
    }
    else {
      *DAT_080132a4 = *DAT_080132a4 + 1;
      if (5999 < *puVar2) {
        *DAT_080132a4 = 0;
        FUN_0800e94c(1);
        FUN_0800f938(6);
        DataSynchronizationBarrier(0xf);
        *DAT_080132a8 = (*DAT_080132a8 & 0x700 | DAT_080132ac) + 4;
        DataSynchronizationBarrier(0xf);
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
    }
  }
  else if (cVar1 == '\x02') {
    *DAT_08013294 = 2;
    pbVar3 = DAT_080132b0;
    *DAT_080132b0 = *DAT_080132b0 + 1;
    if (5 < *pbVar3) {
      *DAT_080132b4 = '\x02';
      *DAT_080132b0 = 0;
      *DAT_08013294 = 3;
      FUN_08007bc4(2);
      *DAT_0801328c = '\x01';
      FUN_08007cd0(5);
    }
    if (*DAT_080132b4 == '\0') {
      FUN_080042f4();
      FUN_0800abec();
    }
    *DAT_080132b4 = *DAT_080132b4 + -1;
  }
  else if (cVar1 == '\x03') {
    *DAT_08013294 = 1;
    puVar2 = DAT_080132b8;
    *DAT_080132b8 = *DAT_080132b8 + 1;
    if (699 < *puVar2) {
      *DAT_08013294 = 3;
      *DAT_080132b8 = 0;
      FUN_08007bc4(3);
      *DAT_0801328c = '\x01';
      FUN_08007cd0(5);
    }
  }
  return;
}



/* ===== FUN_080132bc @ 0x80132BC ===== */

int FUN_080132bc(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0x86f < *DAT_0801333c) {
    *DAT_0801333c = 0;
    iVar1 = DAT_08013348;
    if (*DAT_08013340 < *DAT_08013344) {
      iVar2 = *DAT_08013344 - *DAT_08013340;
      *(uint *)(DAT_08013348 + 0x11) = (uint)(iVar2 * 10000) / 0x4718;
      if (*(uint *)(iVar1 + 0x11) < 0x28) {
        *(undefined4 *)(iVar1 + 0x11) = 0x28;
      }
      if (10000 < *(uint *)(DAT_08013348 + 0x11)) {
        *(undefined4 *)(DAT_08013348 + 0x11) = 10000;
      }
      *DAT_0801334c = *DAT_0801334c | 0x8000;
    }
    else {
      *DAT_08013344 = *DAT_08013340;
    }
  }
  return iVar2;
}



/* ===== FUN_08013350 @ 0x8013350 ===== */

void FUN_08013350(void)

{
  byte *pbVar1;
  
  pbVar1 = DAT_080135cc;
  if (*(char *)(DAT_080135b0 + 0xc) < '\0') {
    *DAT_080135b4 = 0;
    *DAT_080135b8 = 0;
    *DAT_080135bc = 0;
    *DAT_080135c0 = 0;
  }
  else {
    if (((*DAT_080135c4 == '\x02') || (*DAT_080135c4 == '\x01')) &&
       (*(ushort *)(DAT_080135b0 + 8) < 0x109a)) {
      if ((((int)((uint)*(byte *)(DAT_080135b0 + 0xc) << 0x1c) < 0 ||
           (int)((uint)*(byte *)(DAT_080135b0 + 0xc) << 0x1b) < 0) ||
           (int)((uint)*(byte *)(DAT_080135b0 + 0xc) << 0x19) < 0) &&
         (*(char *)(DAT_080135c8 + 3) == '\0')) {
        *DAT_080135cc = *DAT_080135cc + 1;
        if (*(ushort *)(DAT_080135d0 + 0x12) < (ushort)*pbVar1) {
          *DAT_080135b4 = 0;
          *DAT_080135cc = 0;
          *(undefined1 *)(DAT_080135d4 + 0x24) = 1;
        }
      }
      else if (((*(ushort *)(DAT_080135d0 + 0xe) < *(ushort *)(DAT_080135b0 + 6)) &&
               (*(ushort *)(DAT_080135d0 + 0x10) < *(ushort *)(DAT_080135b0 + 4))) ||
              (*(char *)(DAT_080135c8 + 3) != '\0')) {
        *DAT_080135cc = 0;
        *DAT_080135b4 = 0;
      }
      else {
        *DAT_080135cc = 0;
        pbVar1 = DAT_080135b4;
        *DAT_080135b4 = *DAT_080135b4 + 1;
        if (*(ushort *)(DAT_080135d0 + 0x12) <= (ushort)*pbVar1) {
          *DAT_080135b4 = 0;
          *(undefined1 *)(DAT_080135d4 + 0x24) = 1;
        }
      }
    }
    else {
      *DAT_080135cc = 0;
      *DAT_080135b4 = 0;
    }
    pbVar1 = DAT_080135d8;
    if (((*DAT_080135c4 == '\x02') || (*DAT_080135c4 == '\0')) &&
       ((0xe0f < *(ushort *)(DAT_080135b0 + 6) && (3999 < *(ushort *)(DAT_080135b0 + 4))))) {
      if (((*(byte *)(DAT_080135b0 + 0xc) & 1) == 0 &&
          -1 < (int)((uint)*(byte *)(DAT_080135b0 + 0xc) << 0x1e)) &&
          (*(byte *)(DAT_080135b0 + 0x17) & 1) == 0) {
        if (((*(ushort *)(DAT_080135b0 + 8) < *(ushort *)(DAT_080135d0 + 8)) ||
            ((uint)(int)*(short *)(DAT_080135d0 + 10) < *(uint *)(DAT_080135dc + 4))) ||
           (*DAT_080135c4 != '\0')) {
          *DAT_080135d8 = 0;
          *DAT_080135b8 = 0;
        }
        else {
          *DAT_080135b8 = *DAT_080135b8 + 1;
          *DAT_080135d8 = 0;
          if (*(ushort *)(DAT_080135d0 + 0xc) <= *DAT_080135b8) {
            *DAT_080135b8 = 0;
            *(undefined1 *)(DAT_080135d4 + 0x1f) = 1;
          }
        }
      }
      else {
        *DAT_080135d8 = *DAT_080135d8 + 1;
        if (10 < *pbVar1) {
          *pbVar1 = 0;
          *DAT_080135b8 = 0;
          *(undefined1 *)(DAT_080135d4 + 0x1f) = 1;
        }
      }
    }
    else {
      *DAT_080135d8 = 0;
      *DAT_080135b8 = 0;
    }
    pbVar1 = DAT_080135c0;
    if (*(char *)(DAT_080135d4 + 0x24) == '\x01') {
      *DAT_080135c0 = *DAT_080135c0 + 1;
      if (0x13 < *pbVar1) {
        *(undefined1 *)(DAT_080135d4 + 0x24) = 0;
      }
    }
    else {
      *DAT_080135c0 = 0;
    }
    pbVar1 = DAT_080135bc;
    if (*(char *)(DAT_080135d4 + 0x1f) == '\x01') {
      *DAT_080135bc = *DAT_080135bc + 1;
      if (0x13 < *pbVar1) {
        *(undefined1 *)(DAT_080135d4 + 0x1f) = 0;
      }
    }
    else {
      *DAT_080135bc = 0;
    }
    if (*(ushort *)(DAT_080135e0 + 0x13) < 0x251d) {
      *DAT_080135e4 = 1;
    }
    if (499 < *(ushort *)(DAT_080135e0 + 0x13)) {
      *DAT_080135e8 = 1;
    }
    if ((*DAT_080135e4 == 1) && (*(char *)(DAT_080135d4 + 0x1f) == '\x01')) {
      *DAT_080135e4 = 0;
      FUN_0800f938(8);
    }
    if ((*DAT_080135e8 == 1) && (*(char *)(DAT_080135d4 + 0x24) == '\x01')) {
      *DAT_080135e8 = 0;
      FUN_0800f938(9);
    }
  }
  return;
}



/* ===== FUN_080135ec @ 0x80135EC ===== */

void FUN_080135ec(void)

{
  if (*DAT_08013658 == '\0') {
    *DAT_0801365c = *DAT_0801365c + 1;
    *DAT_08013660 = 0;
    if (5 < *DAT_0801365c) {
      *DAT_0801365c = 0;
      *DAT_08013664 = 0;
    }
  }
  else if (*DAT_08013658 == '\x01') {
    *DAT_08013660 = *DAT_08013660 + 1;
    *DAT_0801365c = 0;
    if (5 < *DAT_08013660) {
      *DAT_08013660 = 0;
      *DAT_08013664 = 0;
    }
  }
  else {
    *DAT_0801365c = 0;
    *DAT_08013660 = 0;
    *DAT_08013664 = *DAT_08013664 + 1;
  }
  return;
}



/* ===== FUN_08013668 @ 0x8013668 ===== */

void FUN_08013668(undefined4 param_1)

{
  FUN_08012e5c(param_1);
  return;
}



/* ===== FUN_08013674 @ 0x8013674 ===== */

undefined4 FUN_08013674(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  undefined1 auStack_60 [36];
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 uStack_30;
  undefined2 local_2c;
  undefined2 local_2a;
  ushort local_28;
  undefined2 local_26;
  
  bVar1 = 0;
  FUN_080031d6(&local_3c,0x30);
  while ((bVar1 < 3 && (iVar2 = FUN_0800cb0c(&local_3c), iVar2 != 1))) {
    bVar1 = bVar1 + 1;
  }
  local_3c = *(undefined4 *)(DAT_0801371c + 0x17);
  local_38 = *(undefined4 *)(DAT_0801371c + 0x1b);
  local_2c = 0;
  local_2a = *(undefined2 *)(DAT_0801371c + 0x41);
  local_28 = (ushort)*(byte *)(DAT_0801371c + 0x43);
  local_34 = param_1;
  local_26 = FUN_0800aa50(&local_3c,0x16);
  bVar1 = 0;
  while( true ) {
    if (2 < bVar1) {
      return 0;
    }
    FUN_080031a4(auStack_60,&local_2c,0x20);
    iVar2 = FUN_0800cccc(local_3c,local_38,local_34,uStack_30);
    if ((iVar2 != 0) && (iVar2 = FUN_0800cb0c(&local_3c), iVar2 != 0)) break;
    bVar1 = bVar1 + 1;
  }
  *DAT_08013720 = 1;
  FUN_08012f30(local_34);
  FUN_08012f30(local_34);
  return 1;
}



/* ===== FUN_08013724 @ 0x8013724 ===== */

undefined4 FUN_08013724(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  undefined1 auStack_60 [32];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined2 local_30;
  undefined2 local_2e;
  ushort local_2c;
  undefined2 local_2a;
  
  bVar1 = 0;
  FUN_080031d6(&local_40,0x30);
  while ((bVar1 < 3 && (iVar2 = FUN_0800cb0c(&local_40), iVar2 != 1))) {
    bVar1 = bVar1 + 1;
  }
  local_38 = *(undefined4 *)(DAT_080137cc + 0x2f);
  local_30 = *(undefined2 *)(DAT_080137cc + 0x2d);
  local_2e = *(undefined2 *)(DAT_080137cc + 0x41);
  local_2c = (ushort)*(byte *)(DAT_080137cc + 0x43);
  local_40 = param_1;
  local_3c = param_2;
  local_2a = FUN_0800aa50(&local_40,0x16);
  bVar1 = 0;
  while( true ) {
    if (2 < bVar1) {
      return 0;
    }
    FUN_080031a4(auStack_60,&local_30,0x20);
    iVar2 = FUN_0800cccc(local_40,local_3c,local_38,uStack_34);
    if ((iVar2 != 0) && (iVar2 = FUN_0800cb0c(&local_40), iVar2 != 0)) break;
    bVar1 = bVar1 + 1;
  }
  *DAT_080137d0 = 1;
  FUN_08012f3c(local_40);
  FUN_08012f48(local_3c);
  return 1;
}



/* ===== FUN_080137d4 @ 0x80137D4 ===== */

undefined4 FUN_080137d4(undefined2 param_1,undefined2 param_2)

{
  byte bVar1;
  int iVar2;
  undefined1 auStack_60 [32];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 uStack_34;
  undefined2 local_30;
  undefined2 local_2e;
  undefined2 local_2c;
  undefined2 local_2a;
  
  bVar1 = 0;
  FUN_080031d6(&local_40,0x30);
  while ((bVar1 < 3 && (iVar2 = FUN_0800cb0c(&local_40), iVar2 != 1))) {
    bVar1 = bVar1 + 1;
  }
  local_40 = *(undefined4 *)(DAT_08013880 + 0x17);
  local_3c = *(undefined4 *)(DAT_08013880 + 0x1b);
  local_38 = *(undefined4 *)(DAT_08013880 + 0x2f);
  local_30 = *(undefined2 *)(DAT_08013880 + 0x2d);
  local_2e = param_1;
  local_2c = param_2;
  local_2a = FUN_0800aa50(&local_40,0x16);
  bVar1 = 0;
  while( true ) {
    if (2 < bVar1) {
      return 0;
    }
    FUN_080031a4(auStack_60,&local_30,0x20);
    iVar2 = FUN_0800cccc(local_40,local_3c,local_38,uStack_34);
    if ((iVar2 != 0) && (iVar2 = FUN_0800cb0c(&local_40), iVar2 != 0)) break;
    bVar1 = bVar1 + 1;
  }
  *DAT_08013884 = 1;
  FUN_08012f24(local_2e);
  FUN_08012f54((char)local_2c);
  return 1;
}



/* ===== FUN_08013888 @ 0x8013888 ===== */

void FUN_08013888(undefined4 param_1)

{
  FUN_08012f18(param_1);
  return;
}



/* ===== FUN_08013894 @ 0x8013894 ===== */

void FUN_08013894(void)

{
  ushort *puVar1;
  byte *pbVar2;
  int iVar3;
  
  if (*DAT_08013960 == '\x01') {
    *DAT_08013960 = '\0';
    *DAT_08013964 = 0;
    *DAT_08013968 = 0;
  }
  puVar1 = DAT_0801396c;
  switch(*DAT_08013964) {
  case 0:
    FUN_08010c70();
    FUN_08011038();
    *DAT_08013964 = 1;
    break;
  case 1:
    *DAT_0801396c = *DAT_0801396c + 1;
    if (0x32 < *puVar1) {
      *puVar1 = 0;
      iVar3 = FUN_080064c0();
      pbVar2 = DAT_08013970;
      if (iVar3 == 1) {
        *DAT_08013970 = 0;
        *DAT_08013974 = 0;
        *DAT_08013964 = 2;
      }
      else {
        *DAT_08013970 = *DAT_08013970 + 1;
        if (9 < *pbVar2) {
          *pbVar2 = 0;
          *DAT_08013974 = 1;
          *DAT_08013964 = 3;
        }
      }
    }
    break;
  case 2:
    *DAT_0801396c = *DAT_0801396c + 1;
    if (100 < *puVar1) {
      *puVar1 = 0;
      *DAT_08013964 = 3;
    }
    break;
  case 3:
    FUN_08008fc0();
    *DAT_08013964 = 4;
    break;
  case 4:
    *DAT_08013968 = 1;
    break;
  default:
    *DAT_08013964 = 0;
  }
  return;
}



/* ===== FUN_08013978 @ 0x8013978 ===== */

void FUN_08013978(void)

{
  FUN_080111ec();
  FUN_0801140c();
  FUN_08011290();
  FUN_08011304();
  FUN_08011694();
  FUN_080115c4();
  FUN_0801136c();
  return;
}



/* ===== FUN_08013998 @ 0x8013998 ===== */

void FUN_08013998(void)

{
  FUN_08011bf8();
  FUN_08011cd0();
  FUN_080125c4();
  FUN_08011dac();
  FUN_08011e74();
  FUN_08012468();
  FUN_080123b8();
  FUN_08012524();
  FUN_08011994();
  FUN_08011f3c();
  return;
}



/* ===== FUN_080139c4 @ 0x80139C4 ===== */

void FUN_080139c4(void)

{
  FUN_08016a54();
  FUN_08016df8();
  FUN_08016b2c();
  FUN_08016bec();
  FUN_08016cac();
  FUN_08016d58();
  FUN_080169a4();
  return;
}



/* ===== FUN_080139e4 @ 0x80139E4 ===== */

undefined4 FUN_080139e4(uint param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  int local_20;
  
  if ((((0x800 < *(int *)(DAT_08013b98 + 0x800) + param_3) ||
       (*(uint *)(DAT_08013b98 + 0x804) < param_3)) || (param_3 == 0)) ||
     ((param_4 != 1 && (param_3 * (0x800 / param_3) != 0x800)))) {
    return 0;
  }
  if ((param_1 & 0x7ff) == 0) {
    *(uint *)(DAT_08013b98 + 0x808) = param_1;
  }
  for (uVar4 = 0; iVar1 = DAT_08013b98, uVar4 < param_3; uVar4 = uVar4 + 1) {
    *(undefined1 *)(DAT_08013b98 + *(int *)(DAT_08013b98 + 0x800) + uVar4) =
         *(undefined1 *)(param_2 + uVar4);
  }
  if ((param_4 == 1) || (*(int *)(DAT_08013b98 + 0x800) + param_3 == 0x800)) {
    if ((*(ushort *)(DAT_08013b98 + 0x808) & 0xfff) == 0) {
      FUN_0800a2f0(*(undefined4 *)(DAT_08013b98 + 0x808));
      local_20 = 100;
      do {
        bVar5 = local_20 != 0;
        local_20 = local_20 + -1;
      } while (bVar5);
    }
    uVar2 = FUN_08005b82(DAT_08013b98,0x800);
    *(undefined2 *)(DAT_08013ba0 + (*(ushort *)(DAT_08013b9c + 0xc) - 3) * 2) = uVar2;
    iVar3 = FUN_0800a4a0(DAT_08013b98,*(undefined4 *)(DAT_08013b98 + 0x808),
                         *(ushort *)(DAT_08013b98 + 0x800) + param_3 & 0xffff);
    FUN_0800a380(DAT_08013ba4,*(undefined4 *)(DAT_08013b98 + 0x808),
                 *(ushort *)(DAT_08013b98 + 0x800) + param_3 & 0xffff);
    uVar2 = FUN_08005b82(DAT_08013ba4,0x800);
    iVar1 = DAT_08013ba8;
    *(undefined2 *)(DAT_08013ba8 + (*(ushort *)(DAT_08013b9c + 0xc) - 3) * 2) = uVar2;
    if ((iVar3 != 1) ||
       (*(short *)(DAT_08013ba0 + (*(ushort *)(DAT_08013b9c + 0xc) - 3) * 2) !=
        *(short *)(iVar1 + (*(ushort *)(DAT_08013b9c + 0xc) - 3) * 2))) {
      iVar3 = FUN_0800a4a0(DAT_08013b98,*(undefined4 *)(DAT_08013b98 + 0x808),
                           *(ushort *)(DAT_08013b98 + 0x800) + param_3 & 0xffff);
      FUN_0800a380(DAT_08013ba4,*(undefined4 *)(DAT_08013b98 + 0x808),
                   *(ushort *)(DAT_08013b98 + 0x800) + param_3 & 0xffff);
      uVar2 = FUN_08005b82(DAT_08013ba4,0x800);
      iVar1 = DAT_08013ba8;
      *(undefined2 *)(DAT_08013ba8 + (*(ushort *)(DAT_08013b9c + 0xc) - 3) * 2) = uVar2;
      if ((iVar3 == 1) &&
         (*(short *)(DAT_08013ba0 + (*(ushort *)(DAT_08013b9c + 0xc) - 3) * 2) ==
          *(short *)(iVar1 + (*(ushort *)(DAT_08013b9c + 0xc) - 3) * 2))) {
        FUN_08017758();
        return 1;
      }
      return 0;
    }
    FUN_08017758();
  }
  else {
    *(uint *)(DAT_08013b98 + 0x800) = *(int *)(DAT_08013b98 + 0x800) + param_3;
    *(int *)(iVar1 + 0x804) = 0x800 - *(int *)(iVar1 + 0x800);
  }
  return 1;
}



/* ===== FUN_08013bac @ 0x8013BAC ===== */

void FUN_08013bac(undefined4 *param_1,uint param_2)

{
  undefined2 local_8;
  
  local_8 = CONCAT11((char)param_2 + (char)(param_2 / 0x3c) * -0x3c,(char)((param_2 % 0xe10) / 0x3c)
                    );
  *param_1 = CONCAT13((char)((param_2 - DAT_08013c38 * (param_2 / DAT_08013c38)) / 0xe10),
                      CONCAT12((char)((param_2 - DAT_08013c34 * (param_2 / DAT_08013c34)) /
                                     DAT_08013c38),
                               CONCAT11((char)((param_2 - DAT_08013c30 * (param_2 / DAT_08013c30)) /
                                              DAT_08013c34),(char)(param_2 / DAT_08013c30))));
  *(undefined2 *)(param_1 + 1) = local_8;
  return;
}



/* ===== FUN_08013c3c @ 0x8013C3C ===== */

undefined4 FUN_08013c3c(void)

{
  undefined4 uVar1;
  bool bVar2;
  undefined4 local_10;
  
  uVar1 = FUN_08003c1c(0x29bc);
  local_10 = 10000;
  do {
    bVar2 = local_10 != 0;
    local_10 = local_10 + -1;
  } while (bVar2);
  return uVar1;
}



/* ===== FUN_08013c5e @ 0x8013C5E ===== */

void FUN_08013c5e(void)

{
  FUN_08007b5a();
  FUN_08004770(0,8,0x9239,0x11,2);
  FUN_08013c3c();
  FUN_08007fb4();
  return;
}



/* ===== FUN_08013c84 @ 0x8013C84 ===== */

void FUN_08013c84(int param_1)

{
  if (param_1 == 4) {
    DAT_e000e010 = DAT_e000e010 | 4;
  }
  else {
    DAT_e000e010 = DAT_e000e010 & 0xfffffffb;
  }
  return;
}



/* ===== sys_tick_Handler @ 0x8013CAC ===== */

void sys_tick_Handler(void)

{
  FUN_08006c14();
  return;
}



/* ===== system_init_enable_fpu @ 0x8013CB4 ===== */

/* Reached from reset and enables CP10 and CP11 through SCB CPACR at 0xE000ED88. */

void system_init_enable_fpu(void)

{
  uint *puVar1;
  uint *puVar2;
  
  *DAT_08013d70 = *DAT_08013d70 | 0xf00000;
  puVar1 = DAT_08013d74;
  DAT_08013d74[9] = DAT_08013d74[9] | 4;
  puVar2 = DAT_08013d74;
  DAT_08013d74[1] = puVar1[1] & DAT_08013d78;
  puVar1 = DAT_08013d74;
  *DAT_08013d74 = *puVar2 & DAT_08013d7c;
  *puVar1 = *puVar1 & 0xfffbffff;
  puVar2 = DAT_08013d74;
  DAT_08013d74[1] = puVar1[1] & DAT_08013d80;
  puVar2[0xb] = 0;
  puVar2[0xc] = 0x3800;
  puVar2[0xd] = 0;
  puVar2[0x10] = 0;
  puVar2[2] = DAT_08013d84;
  puVar2[7] = puVar2[7] | 0x10000000;
  puVar1 = DAT_08013d8c;
  if ((*DAT_08013d88 & 0x400) == 0x400) {
    *DAT_08013d8c = *DAT_08013d8c & 0xfdffffff;
    *puVar1 = *puVar1 | 0x2000000;
  }
  puVar1 = DAT_08013d90;
  *DAT_08013d90 = *DAT_08013d90 | 0x90;
  if ((*puVar1 & 0x100) != 0) {
    *puVar1 = *puVar1 & 0xfffffdff;
  }
  FUN_08012abc();
  DAT_08013d70[-0x20] = DAT_08013d94;
  return;
}



/* ===== FUN_08013d98 @ 0x8013D98 ===== */

void FUN_08013d98(void)

{
  int iVar1;
  
  if (((*DAT_08013dd4 == '\0') || (*DAT_08013dd4 == '\x04')) || (*DAT_08013dd4 == '\x01')) {
    *DAT_08013dd8 = 1;
    FUN_08016ed0();
  }
  else {
    *DAT_08013dd8 = 0;
  }
  iVar1 = DAT_08013de0;
  *(undefined1 *)(DAT_08013de0 + 6) = *DAT_08013ddc;
  *(undefined1 *)(iVar1 + 5) = *DAT_08013de4;
  return;
}



/* ===== FUN_08013de8 @ 0x8013DE8 ===== */

void FUN_08013de8(void)

{
  ushort *puVar1;
  uint *puVar2;
  ushort *puVar3;
  int iVar4;
  bool bVar5;
  int local_8;
  
  switch(*DAT_080141e4) {
  case 0:
    *DAT_080141e8 = 0;
    FUN_080194fc();
    iVar4 = FUN_08017c7c();
    if (iVar4 == 0) {
      if ((*DAT_080141ec == '\x01') &&
         (iVar4 = FUN_0800a7c8(DAT_080141f0,0x100), puVar1 = DAT_080141f4, iVar4 != 0)) {
        *DAT_080141f4 = *DAT_080141f4 + 1;
        if (4 < *puVar1) {
          *DAT_080141ec = '\0';
        }
      }
      else {
        *DAT_080141f4 = 0;
      }
      puVar3 = DAT_08014208;
      puVar1 = DAT_08014204;
      if (((*DAT_080141f8 == '\0') || (DAT_080141fc[1] != '\0')) || (*DAT_080141fc != '\0')) {
        if (((*DAT_08014214 == '\x01') || (*DAT_08014218 == '\x01')) ||
           ((*DAT_0801421c == '\0' &&
            ((*DAT_080141f8 == '\x02' && ((int)((uint)*(byte *)(DAT_08014220 + 0xc) << 0x1b) < 0))))
           )) {
          *DAT_08014208 = *DAT_08014208 + 1;
          if ((2999 < *puVar3) || ((*DAT_08014214 == '\x01' || (*DAT_08014218 == '\x01')))) {
            *DAT_08014200 = 0;
            *DAT_08014204 = 0;
            *DAT_08014208 = 0;
            *DAT_08014214 = '\0';
            *DAT_08014218 = '\0';
            FUN_080159ac();
            FUN_0800f878();
            *DAT_080141e4 = 3;
            *DAT_08014224 = 0;
          }
        }
        else if (((((int)((uint)*(byte *)(DAT_08014220 + 0xc) << 0x1c) < 0) ||
                  ((int)((uint)*(byte *)(DAT_08014220 + 0xc) << 0x19) < 0)) &&
                 (*DAT_0801421c == '\0')) && (*DAT_080141f8 == '\x02')) {
          *DAT_08014204 = *DAT_08014204 + 1;
          if (11999 < *puVar1) {
            *DAT_08014200 = 0;
            *DAT_08014204 = 0;
            *DAT_08014208 = 0;
            *DAT_080141e4 = 1;
            *DAT_0801420c = 0;
          }
        }
        else {
          iVar4 = FUN_0800a878();
          puVar2 = DAT_08014200;
          if (((iVar4 == 0) && (DAT_080141fc[1] == '\0')) &&
             ((*DAT_0801421c == '\0' && (*DAT_080141f8 == '\x02')))) {
            *DAT_08014200 = *DAT_08014200 + 1;
            if (2999 < *puVar2) {
              *DAT_08014200 = 0;
              *DAT_08014204 = 0;
              *DAT_08014208 = 0;
              *DAT_080141e4 = 1;
              *DAT_0801420c = 0;
            }
          }
          else {
            *DAT_080141fc = '\x01';
            *DAT_0801421c = '\0';
            *DAT_08014210 = '\0';
            *DAT_08014208 = 0;
            *DAT_08014200 = 0;
            *DAT_08014204 = 0;
          }
        }
      }
      else {
        *DAT_080141fc = '\x01';
        *DAT_08014200 = 0;
        *DAT_08014204 = 0;
        *DAT_08014208 = 0;
        *DAT_080141e4 = 1;
        *DAT_0801420c = 0;
        *DAT_08014210 = '\0';
      }
    }
    else {
      *DAT_080141e4 = 4;
    }
    break;
  case 1:
    FUN_08006994();
    iVar4 = FUN_0800a834();
    if (((iVar4 == 1) || (*DAT_0801421c == '\x01')) ||
       ((*DAT_08014210 == '\x01' || ((2 < *DAT_08014228 || (200 < *(uint *)(DAT_0801422c + 4)))))))
    {
      *DAT_08014230 = 0;
      *DAT_080141e4 = 2;
      FUN_080052f4();
    }
    else {
      if (((int)((uint)*(byte *)(DAT_08014220 + 0xc) << 0x1b) < 0) ||
         (iVar4 = FUN_08019524(), iVar4 == 1)) {
        puVar1 = DAT_08014230;
        *DAT_08014230 = *DAT_08014230 + 1;
        if ((499 < *puVar1) || (iVar4 = FUN_08019524(), iVar4 == 1)) {
          FUN_08007b98();
          *DAT_08014230 = 0;
          FUN_080159ac();
          FUN_0800f878();
          *DAT_080141e4 = 3;
          *DAT_08014224 = 0;
        }
      }
      else {
        *DAT_08014230 = 0;
      }
      *DAT_08014228 = 0;
      FUN_080130fc();
    }
    break;
  case 2:
    *DAT_080141e8 = 2;
    puVar1 = DAT_08014234;
    *DAT_08014234 = *DAT_08014234 + 1;
    puVar3 = DAT_08014238;
    if (*puVar1 < 500) {
      if (((*DAT_08014210 == '\x01') || (2 < *DAT_08014228)) || (200 < *(uint *)(DAT_0801422c + 4)))
      {
        *DAT_08014238 = *DAT_08014238 + 1;
        if (3 < *puVar3) {
          *DAT_080141ec = '\0';
          *DAT_08014234 = 0;
          *DAT_08014238 = 0;
          *DAT_0801423c = 0;
          FUN_08007dbc();
          *DAT_08014210 = '\0';
          *DAT_0801421c = '\0';
          *DAT_08014228 = 0;
          *DAT_080141e4 = 0;
        }
      }
      else {
        *DAT_08014238 = 0;
      }
      iVar4 = FUN_0800a7c8(DAT_08014240,0x200);
      puVar1 = DAT_0801423c;
      if ((iVar4 == 0) || (*DAT_08014244 == '\x01')) {
        *DAT_0801423c = *DAT_0801423c + 1;
        if (4 < *puVar1) {
          *DAT_08014248 = 1;
          *DAT_080141ec = '\x01';
          *DAT_08014234 = 0;
          *DAT_08014238 = 0;
          *DAT_0801423c = 0;
          FUN_08007dbc();
          *DAT_08014210 = '\0';
          *DAT_0801421c = '\0';
          *DAT_08014228 = 0;
          *DAT_080141e4 = 0;
        }
      }
      else {
        *DAT_0801423c = 0;
      }
    }
    else {
      *puVar1 = 0;
      *DAT_08014238 = 0;
      *DAT_0801423c = 0;
      *DAT_080141e4 = 1;
      *DAT_0801420c = 0;
      *DAT_0801421c = '\0';
      *DAT_08014228 = 0;
    }
    break;
  case 3:
    *DAT_080141e8 = 5;
    FUN_080130f0();
    *DAT_0801424c = 0xaaaa;
    FUN_0800532c(DAT_08014250,2);
    FUN_08003bdc(0x9f);
    local_8 = 10000;
    do {
      bVar5 = local_8 != 0;
      local_8 = local_8 + -1;
    } while (bVar5);
    FUN_08003c60(8,0x38,DAT_08014254,2);
    puVar1 = DAT_08014258;
    local_8 = 10000;
    do {
      bVar5 = local_8 != 0;
      local_8 = local_8 + -1;
    } while (bVar5);
    if (*DAT_08014254 < 0x28) {
      *DAT_08014258 = *DAT_08014258 + 1;
      if (500 < *puVar1) {
        *puVar1 = 0;
        *(undefined4 *)(DAT_08014240 + 0x18) = 2;
        local_8 = DAT_0801436c;
        do {
          bVar5 = local_8 != 0;
          local_8 = local_8 + -1;
        } while (bVar5);
        FUN_08003bdc(0x10);
        local_8 = 10000;
        do {
          bVar5 = local_8 != 0;
          local_8 = local_8 + -1;
        } while (bVar5);
        FUN_08003bdc(0x10);
      }
    }
    else {
      *DAT_08014370 = 0;
    }
    puVar1 = DAT_08014378;
    if (*DAT_08014374 == '\x01') {
      *DAT_08014378 = *DAT_08014378 + 1;
      if (500 < *puVar1) {
        *puVar1 = 0;
        *DAT_08014374 = '\0';
      }
      iVar4 = FUN_0800a7c8(DAT_0801437c,0x200);
      puVar1 = DAT_08014380;
      if (iVar4 == 0) {
        *DAT_08014380 = *DAT_08014380 + 1;
        if (4 < *puVar1) {
          *puVar1 = 0;
          *DAT_08014374 = '\0';
          FUN_08007dbc();
          *DAT_08014384 = 0;
          *(undefined4 *)(DAT_0801437c + 0x18) = 2;
          local_8 = 10000;
          do {
            bVar5 = local_8 != 0;
            local_8 = local_8 + -1;
          } while (bVar5);
          *(undefined4 *)(DAT_0801437c + 0x28) = 2;
          FUN_08003bdc(0x12);
          local_8 = 10000;
          do {
            bVar5 = local_8 != 0;
            local_8 = local_8 + -1;
          } while (bVar5);
          FUN_08003bdc(0x12);
        }
      }
      else {
        *DAT_08014380 = 0;
      }
    }
    else {
      *DAT_08014378 = 0;
      *DAT_08014380 = 0;
    }
    break;
  case 4:
    *DAT_08014388 = 4;
    iVar4 = FUN_08017c7c();
    if (iVar4 == 0) {
      *DAT_08014384 = 0;
    }
    break;
  default:
    *DAT_08014384 = 0;
  }
  return;
}



/* ===== FUN_0801438c @ 0x801438C ===== */

void FUN_0801438c(void)

{
  if (((*DAT_080143bc == '\0') || (*DAT_080143bc == '\x01')) || (*DAT_080143bc == '\x02')) {
    FUN_0800c7ec();
  }
  if ((*DAT_080143bc == '\0') || (*DAT_080143bc == '\x01')) {
    FUN_0800e098();
  }
  return;
}



/* ===== FUN_080143c0 @ 0x80143C0 ===== */

void FUN_080143c0(void)

{
  FUN_0800d854(DAT_080143cc);
  return;
}



/* ===== FUN_080143d0 @ 0x80143D0 ===== */

void FUN_080143d0(void)

{
  return;
}



/* ===== FUN_080143d4 @ 0x80143D4 ===== */

void FUN_080143d4(void)

{
  if ((*DAT_08014420 == '\0') || (*DAT_08014420 == '\x01')) {
    FUN_0800b482();
    FUN_08003abc();
    FUN_080139c4();
    FUN_08013998();
    FUN_08013978();
  }
  if ((((*DAT_08014420 == '\0') || (*DAT_08014420 == '\x02')) || (*DAT_08014420 == '\x04')) ||
     (*DAT_08014420 == '\x01')) {
    *DAT_08014424 = 0xaaaa;
  }
  return;
}



/* ===== FUN_08014428 @ 0x8014428 ===== */

void FUN_08014428(void)

{
  if ((*DAT_08014440 == '\0') || (*DAT_08014440 == '\x01')) {
    FUN_08009494();
  }
  return;
}



/* ===== FUN_08014444 @ 0x8014444 ===== */

void FUN_08014444(void)

{
  if ((*DAT_08014460 == '\0') || (*DAT_08014460 == '\x01')) {
    FUN_0801537c();
    FUN_08007fd4();
  }
  return;
}



/* ===== FUN_08014464 @ 0x8014464 ===== */

void FUN_08014464(void)

{
  return;
}



/* ===== FUN_08014466 @ 0x8014466 ===== */

void FUN_08014466(void)

{
  return;
}



/* ===== FUN_08014468 @ 0x8014468 ===== */

void FUN_08014468(void)

{
  return;
}



/* ===== FUN_0801446a @ 0x801446A ===== */

void FUN_0801446a(void)

{
  return;
}



/* ===== FUN_0801446c @ 0x801446C ===== */

void FUN_0801446c(void)

{
  return;
}



/* ===== FUN_08014470 @ 0x8014470 ===== */

void FUN_08014470(void)

{
  FUN_08013de8();
  FUN_08013d98();
  FUN_08010658();
  if ((*DAT_080144bc == '\0') || (*DAT_080144bc == '\x01')) {
    FUN_08013894();
    FUN_080066ec();
    FUN_0800a1b4();
    FUN_08003dec();
    FUN_08005de4();
  }
  if (((*DAT_080144bc == '\0') || (*DAT_080144bc == '\x01')) || (*DAT_080144bc == '\x02')) {
    FUN_08006344();
  }
  return;
}



/* ===== FUN_080144c0 @ 0x80144C0 ===== */

void FUN_080144c0(void)

{
  if (((*DAT_080144fc == '\0') || (*DAT_080144fc == '\x02')) || (*DAT_080144fc == '\x04')) {
    FUN_08014c24();
    FUN_08014e64();
    FUN_08006b04();
    FUN_08006a30();
  }
  if ((*DAT_080144fc == '\0') || (*DAT_080144fc == '\x01')) {
    FUN_080062b8();
  }
  return;
}



/* ===== FUN_08014500 @ 0x8014500 ===== */

void FUN_08014500(void)

{
  if (*DAT_08014528 == '\0') {
    FUN_08005668();
  }
  if (((*DAT_08014528 == '\0') || (*DAT_08014528 == '\x01')) || (*DAT_08014528 == '\x02')) {
    FUN_080135ec();
  }
  return;
}



/* ===== FUN_0801452c @ 0x801452C ===== */

void FUN_0801452c(void)

{
  return;
}



/* ===== FUN_08014530 @ 0x8014530 ===== */

void FUN_08014530(void)

{
  if ((*DAT_08014558 == '\0') || (*DAT_08014558 == '\x01')) {
    FUN_0800a160();
    FUN_0800b57c();
    FUN_0800b490();
    FUN_08012a20();
    FUN_08008080();
  }
  return;
}



/* ===== FUN_0801455c @ 0x801455C ===== */

void FUN_0801455c(void)

{
  if ((*DAT_08014574 == '\0') || (*DAT_08014574 == '\x01')) {
    FUN_080148c8();
  }
  return;
}



/* ===== FUN_08014578 @ 0x8014578 ===== */

void FUN_08014578(void)

{
  if ((*DAT_08014594 == '\0') || (*DAT_08014594 == '\x04')) {
    FUN_08017c88();
  }
  return;
}



/* ===== FUN_08014598 @ 0x8014598 ===== */

void FUN_08014598(void)

{
  if ((((*DAT_080145c0 == '\0') || (*DAT_080145c0 == '\x01')) || (*DAT_080145c0 == '\x02')) &&
     (*DAT_080145c4 == '\x01')) {
    FUN_08008ccc();
  }
  return;
}



/* ===== FUN_080145c8 @ 0x80145C8 ===== */

void FUN_080145c8(void)

{
  if (((*DAT_080145f4 == '\0') || (*DAT_080145f4 == '\x01')) || (*DAT_080145f4 == '\x02')) {
    FUN_08016f50();
    if (*DAT_080145f8 == '\x01') {
      FUN_080090d8();
    }
  }
  return;
}



/* ===== FUN_080145fc @ 0x80145FC ===== */

void FUN_080145fc(void)

{
  if (((*DAT_08014628 == '\0') || (*DAT_08014628 == '\x01')) || (*DAT_08014628 == '\x02')) {
    FUN_08016424();
    if (*DAT_0801462c == '\x01') {
      FUN_08013350();
    }
  }
  return;
}



/* ===== FUN_08014630 @ 0x8014630 ===== */

void FUN_08014630(void)

{
  if ((*DAT_0801464c == '\0') || (*DAT_0801464c == '\x01')) {
    FUN_08003cea();
    FUN_0800e984(0);
  }
  return;
}



/* ===== FUN_08014650 @ 0x8014650 ===== */

void FUN_08014650(void)

{
  if ((((*DAT_08014678 == '\0') || (*DAT_08014678 == '\x01')) || (*DAT_08014678 == '\x02')) &&
     (*DAT_0801467c == '\x01')) {
    FUN_08008978();
  }
  return;
}



/* ===== FUN_08014680 @ 0x8014680 ===== */

void FUN_08014680(void)

{
  if ((*DAT_08014698 == '\0') || (*DAT_08014698 == '\x01')) {
    FUN_08004d14();
  }
  return;
}



/* ===== FUN_0801469c @ 0x801469C ===== */

void FUN_0801469c(void)

{
  char cVar1;
  int iVar2;
  
  if (*DAT_080146d4 == '\0') {
    FUN_08006508();
  }
  if ((*DAT_080146d4 == '\0') || (*DAT_080146d4 == '\x04')) {
    FUN_08017ffc(0);
    iVar2 = FUN_08017c7c();
    if (iVar2 == 1) {
      cVar1 = '\x04';
    }
    else {
      cVar1 = '\0';
    }
    *DAT_080146d4 = cVar1;
    FUN_08017ce0();
  }
  return;
}



/* ===== FUN_080146d8 @ 0x80146D8 ===== */

void FUN_080146d8(void)

{
  if (*DAT_0801470c == '\0') {
    FUN_0800f70c();
    FUN_0800f824();
    FUN_0800f7ac();
    FUN_0800f7fc();
    FUN_0800f734();
    FUN_0800f6e4();
    FUN_0800f7d4();
    FUN_0800f75c();
    FUN_0800f784();
    FUN_0800f850();
  }
  return;
}



/* ===== FUN_08014710 @ 0x8014710 ===== */

void FUN_08014710(void)

{
  if ((*DAT_08014730 == '\0') && ((*DAT_08014734 == -1 || (*DAT_08014734 == 0)))) {
    FUN_08003d78();
  }
  return;
}



/* ===== FUN_08014738 @ 0x8014738 ===== */

void FUN_08014738(void)

{
  return;
}



/* ===== FUN_0801473a @ 0x801473A ===== */

void FUN_0801473a(void)

{
  return;
}



/* ===== FUN_0801473c @ 0x801473C ===== */

char FUN_0801473c(void)

{
  char cVar1;
  
  cVar1 = '\0';
  if (*DAT_08014748 != '\0') {
    cVar1 = *DAT_08014748;
  }
  return cVar1;
}



/* ===== FUN_0801474c @ 0x801474C ===== */

void FUN_0801474c(void)

{
  if (((*DAT_08014770 == '\0') || (*DAT_08014770 == '\x01')) || (*DAT_08014770 == '\x05')) {
    FUN_0800d384(DAT_08014774);
    FUN_0800436c();
  }
  return;
}



/* ===== FUN_08014778 @ 0x8014778 ===== */

void FUN_08014778(void)

{
  return;
}



/* ===== FUN_0801477a @ 0x801477A ===== */

void FUN_0801477a(void)

{
  return;
}



/* ===== FUN_0801477c @ 0x801477C ===== */

void FUN_0801477c(void)

{
  FUN_08003984();
  return;
}



/* ===== FUN_08014784 @ 0x8014784 ===== */

void FUN_08014784(void)

{
  if (*DAT_08014794 != '\0') {
    FUN_0800e368();
  }
  return;
}



/* ===== FUN_08014798 @ 0x8014798 ===== */

void FUN_08014798(void)

{
  if ((*DAT_080147c8 == '\0') || (*DAT_080147c8 == '\x01')) {
    FUN_08005cac();
    FUN_08007330();
    FUN_080129f4();
    if (*DAT_080147cc == '\x01') {
      *DAT_080147cc = '\0';
      FUN_080106ec();
    }
  }
  return;
}



/* ===== FUN_080147d0 @ 0x80147D0 ===== */

char FUN_080147d0(void)

{
  char cVar1;
  
  cVar1 = '\0';
  if (*DAT_080147dc != '\0') {
    cVar1 = *DAT_080147dc;
  }
  return cVar1;
}



/* ===== FUN_080147e0 @ 0x80147E0 ===== */

void FUN_080147e0(void)

{
  return;
}



/* ===== FUN_080147e4 @ 0x80147E4 ===== */

void FUN_080147e4(void)

{
  if ((*DAT_08014800 == '\0') || (*DAT_08014800 == '\x01')) {
    FUN_0800abec();
    FUN_08007a38();
  }
  return;
}



/* ===== FUN_08014804 @ 0x8014804 ===== */

undefined8 FUN_08014804(uint param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar3 = 0;
  uVar4 = 0;
  uVar5 = 0x82;
  if ((int)(uint)*DAT_080148c4 < (int)param_1) {
    iVar2 = -0x1f;
  }
  else if ((int)param_1 < (int)(uint)DAT_080148c4[0x82]) {
    iVar2 = 0x65;
  }
  else {
    while (uVar4 < uVar5) {
      uVar3 = (int)(uVar4 + uVar5) >> 1;
      if (DAT_080148c4[uVar3] == param_1) {
        iVar2 = (int)(char)((char)uVar3 + -0x1e);
        goto LAB_0801481a;
      }
      if ((int)param_1 < (int)(uint)DAT_080148c4[uVar3]) {
        uVar4 = uVar3 + 1 & 0xff;
      }
      else if (uVar3 < 2) {
        uVar5 = 0;
      }
      else {
        uVar5 = uVar3 - 1 & 0xff;
      }
    }
    uVar3 = (int)(uVar4 + uVar5) >> 1;
    cVar1 = (char)uVar3;
    if ((int)(uint)DAT_080148c4[uVar3] < (int)param_1) {
      if ((int)(((uint)DAT_080148c4[uVar3] + (uint)DAT_080148c4[uVar3 - 1]) / 2) < (int)param_1) {
        iVar2 = (int)(char)(cVar1 + -0x1f);
      }
      else {
        iVar2 = (int)(char)(cVar1 + -0x1e);
      }
    }
    else if ((int)(((uint)DAT_080148c4[uVar3 + 1] + (uint)DAT_080148c4[uVar3]) / 2) < (int)param_1)
    {
      iVar2 = (int)(char)(cVar1 + -0x1e);
    }
    else {
      iVar2 = (int)(char)(cVar1 + -0x1d);
    }
  }
LAB_0801481a:
  return CONCAT44(uVar3,iVar2);
}



/* ===== FUN_080148c8 @ 0x80148C8 ===== */

void FUN_080148c8(void)

{
  FUN_080070b0(DAT_080148e0,2,DAT_080148dc);
  FUN_0801293c();
  return;
}



/* ===== FUN_080148e4 @ 0x80148E4 ===== */

void FUN_080148e4(void)

{
  byte bVar1;
  byte *pbVar2;
  
  FUN_08006c84(3,100);
  FUN_0801438c();
  bVar1 = *DAT_080149ac;
  if (bVar1 == 0) {
    FUN_0801474c();
  }
  else if (bVar1 == 1) {
    FUN_08014778();
  }
  else if (bVar1 == 2) {
    FUN_0801477a();
  }
  else if (bVar1 == 3) {
    FUN_0801477c();
  }
  pbVar2 = DAT_080149ac;
  *DAT_080149ac = *DAT_080149ac + 1;
  if (4 < *pbVar2) {
    *pbVar2 = 0;
  }
  switch(*DAT_080149b0) {
  case 0:
    FUN_08014500();
    break;
  case 1:
    FUN_08014530();
    break;
  case 2:
    FUN_0801455c();
    break;
  case 3:
    FUN_08014578();
    break;
  case 4:
    FUN_08014598();
    break;
  case 5:
    FUN_080145c8();
    break;
  case 6:
    FUN_080145fc();
    break;
  case 7:
    FUN_08014630();
    break;
  case 8:
    FUN_08014650();
    break;
  case 9:
    FUN_0801452c();
    break;
  default:
    *DAT_080149b0 = 0;
  }
  pbVar2 = DAT_080149b0;
  *DAT_080149b0 = *DAT_080149b0 + 1;
  if (9 < *pbVar2) {
    *pbVar2 = 0;
  }
  return;
}



/* ===== FUN_080149b4 @ 0x80149B4 ===== */

void FUN_080149b4(void)

{
  byte *pbVar1;
  
  FUN_08006c84(1,10);
  FUN_08014470();
  switch(*DAT_08014a60) {
  case 0:
    FUN_08014784();
    FUN_080143c0();
    break;
  case 1:
    FUN_08014798();
    FUN_080143d4();
    break;
  case 2:
    FUN_080147d0();
    FUN_08014428();
    break;
  case 3:
    FUN_080147e0();
    FUN_08014444();
    break;
  case 4:
    FUN_080147e4();
    FUN_08014464();
    break;
  case 5:
    FUN_08014784();
    FUN_08014466();
    break;
  case 6:
    FUN_08014798();
    FUN_08014468();
    break;
  case 7:
    FUN_080147d0();
    FUN_0801446a();
    break;
  case 8:
    FUN_080147e0();
    FUN_0801446c();
    break;
  case 9:
    FUN_080147e4();
    FUN_080143d0();
    break;
  default:
    *DAT_08014a60 = 0;
  }
  pbVar1 = DAT_08014a60;
  *DAT_08014a60 = *DAT_08014a60 + 1;
  if (9 < *pbVar1) {
    *pbVar1 = 0;
  }
  return;
}



/* ===== FUN_08014a64 @ 0x8014A64 ===== */

void FUN_08014a64(void)

{
  FUN_08006c84(0,1);
  FUN_080144c0();
  return;
}



/* ===== FUN_08014a78 @ 0x8014A78 ===== */

void FUN_08014a78(void)

{
  byte bVar1;
  byte *pbVar2;
  
  FUN_08006c84(4,500);
  FUN_0801473c();
  bVar1 = *DAT_08014ae8;
  if (bVar1 == 0) {
    FUN_08014680();
    FUN_080146d8();
  }
  else if (bVar1 == 1) {
    FUN_0801469c();
    FUN_08014710();
  }
  else if (bVar1 == 2) {
    FUN_08014680();
    FUN_08014738();
  }
  else if (bVar1 == 3) {
    FUN_0801469c();
    FUN_0801473a();
  }
  else {
    *DAT_08014ae8 = 0;
  }
  pbVar2 = DAT_08014ae8;
  *DAT_08014ae8 = *DAT_08014ae8 + 1;
  if (3 < *pbVar2) {
    *pbVar2 = 0;
  }
  return;
}



/* ===== FUN_08014aec @ 0x8014AEC ===== */

void FUN_08014aec(void)

{
  byte bVar1;
  int iVar2;
  undefined4 local_10;
  
  local_10 = 0;
  bVar1 = 0;
  do {
    if (2 < bVar1) {
      return;
    }
    iVar2 = FUN_0800eee0(8,0x91a2,&local_10,2);
    if (iVar2 != 0) {
      *(ushort *)(DAT_08014b4c + 0x1a) = (ushort)local_10;
      if ((31999 < (ushort)local_10) && ((ushort)local_10 < 0x8ca1)) {
        return;
      }
      local_10 = 34000;
      iVar2 = FUN_080175ac(8,0x91a2,34000,2);
      if (iVar2 != 0) {
        return;
      }
    }
    bVar1 = bVar1 + 1;
  } while( true );
}



/* ===== FUN_08014b50 @ 0x8014B50 ===== */

void FUN_08014b50(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_080150f2(DAT_08014c10,0x424);
  if (iVar2 != 0) {
    FUN_08006f38(*(undefined4 *)(DAT_08014c14 + 0x10),0);
    sVar1 = FUN_08006f50(*(undefined4 *)(DAT_08014c14 + 0x10));
    sVar1 = 0x96 - sVar1;
    if ((sVar1 != 0) && ((*DAT_08014c18 & 7) < 7)) {
      uVar3 = (uint)DAT_08014c18[1];
      do {
        uVar3 = uVar3 + 1 & 0xff;
        if (2 < uVar3) {
          uVar3 = 0;
        }
      } while (((uint)*DAT_08014c18 & 1 << uVar3) != 0);
      *DAT_08014c18 = *DAT_08014c18 | (byte)(1 << uVar3);
      FUN_080031a4(DAT_08014c18 + uVar3 * 0x98 + 4,DAT_08014c1c,sVar1);
      *(short *)(DAT_08014c18 + uVar3 * 0x98 + 2) = sVar1;
    }
    FUN_08006fba(*(undefined4 *)(DAT_08014c14 + 0x10),0x96);
    FUN_08006f38(*(undefined4 *)(DAT_08014c14 + 0x10),1);
    *DAT_08014c20 = 0;
  }
  return;
}



/* ===== FUN_08014c24 @ 0x8014C24 ===== */

void FUN_08014c24(void)

{
  ushort *puVar1;
  uint uVar2;
  
  puVar1 = DAT_08014cf8;
  if ((*DAT_08014cf4 & 1) == 0) {
    *DAT_08014cf8 = 0;
    if ((*DAT_08014cfc & 7) != 0) {
      uVar2 = (uint)DAT_08014cfc[1];
      do {
        uVar2 = uVar2 + 1 & 0xff;
        if (2 < uVar2) {
          uVar2 = 0;
        }
      } while (((uint)*DAT_08014cfc & 1 << uVar2) == 0);
      DAT_08014cfc[1] = (byte)uVar2;
      if (*(short *)(DAT_08014cfc + uVar2 * 0x98 + 2) != 0) {
        *DAT_08014cf4 = (*DAT_08014cf4 & 0xfe) + 1;
        FUN_0800529e(*DAT_08014d00,DAT_08014d00[1],DAT_08014d00[2],DAT_08014d00[3],DAT_08014d00[4],
                     DAT_08014d00[5],DAT_08014d00[6],DAT_08014cfc + uVar2 * 0x98 + 4,
                     *(undefined2 *)(DAT_08014cfc + uVar2 * 0x98 + 2));
      }
    }
  }
  else {
    *DAT_08014cf8 = *DAT_08014cf8 + 1;
    if (200 < *puVar1) {
      *DAT_08014cf4 = *DAT_08014cf4 & 0xfe;
      *DAT_08014cf8 = 0;
    }
  }
  return;
}



/* ===== FUN_08014d04 @ 0x8014D04 ===== */

undefined4 FUN_08014d04(undefined2 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((*DAT_08014d8c & 7) != 0) {
    uVar1 = (uint)DAT_08014d8c[1];
    do {
      uVar1 = uVar1 + 1 & 0xff;
      if (2 < uVar1) {
        uVar1 = 0;
      }
    } while (((uint)*DAT_08014d8c & 1 << uVar1) == 0);
    DAT_08014d8c[1] = (byte)uVar1;
    *param_1 = *(undefined2 *)(DAT_08014d8c + uVar1 * 0x98 + 2);
    FUN_080031a4(param_1 + 1,DAT_08014d8c + uVar1 * 0x98 + 4,
                 *(undefined2 *)(DAT_08014d8c + uVar1 * 0x98 + 2));
    *DAT_08014d8c = *DAT_08014d8c & ~(byte)(1 << uVar1);
    uVar2 = 1;
  }
  return uVar2;
}



/* ===== FUN_08014d90 @ 0x8014D90 ===== */

void FUN_08014d90(void)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = FUN_080150f2(DAT_08014e50,0x424);
  if (iVar2 != 0) {
    FUN_08006f38(*(undefined4 *)(DAT_08014e54 + 0x10),0);
    sVar1 = FUN_08006f50(*(undefined4 *)(DAT_08014e54 + 0x10));
    sVar1 = 0x96 - sVar1;
    if ((sVar1 != 0) && ((*DAT_08014e58 & 7) < 7)) {
      uVar3 = (uint)DAT_08014e58[1];
      do {
        uVar3 = uVar3 + 1 & 0xff;
        if (2 < uVar3) {
          uVar3 = 0;
        }
      } while (((uint)*DAT_08014e58 & 1 << uVar3) != 0);
      *DAT_08014e58 = *DAT_08014e58 | (byte)(1 << uVar3);
      FUN_080031a4(DAT_08014e58 + uVar3 * 0x98 + 4,DAT_08014e5c,sVar1);
      *(short *)(DAT_08014e58 + uVar3 * 0x98 + 2) = sVar1;
    }
    FUN_08006fba(*(undefined4 *)(DAT_08014e54 + 0x10),0x96);
    FUN_08006f38(*(undefined4 *)(DAT_08014e54 + 0x10),1);
    *DAT_08014e60 = 0;
  }
  return;
}



/* ===== FUN_08014e64 @ 0x8014E64 ===== */

void FUN_08014e64(void)

{
  ushort *puVar1;
  uint uVar2;
  
  puVar1 = DAT_08014f38;
  if ((int)((uint)*DAT_08014f34 << 0x1d) < 0) {
    *DAT_08014f38 = *DAT_08014f38 + 1;
    if (200 < *puVar1) {
      *DAT_08014f34 = *DAT_08014f34 & 0xfb;
      *DAT_08014f38 = 0;
    }
  }
  else {
    *DAT_08014f38 = 0;
    if ((*DAT_08014f3c & 7) != 0) {
      uVar2 = (uint)DAT_08014f3c[1];
      do {
        uVar2 = uVar2 + 1 & 0xff;
        if (2 < uVar2) {
          uVar2 = 0;
        }
      } while (((uint)*DAT_08014f3c & 1 << uVar2) == 0);
      DAT_08014f3c[1] = (byte)uVar2;
      if (*(short *)(DAT_08014f3c + uVar2 * 0x98 + 2) != 0) {
        *DAT_08014f34 = (*DAT_08014f34 & 0xfb) + 4;
        FUN_0800529e(*DAT_08014f40,DAT_08014f40[1],DAT_08014f40[2],DAT_08014f40[3],DAT_08014f40[4],
                     DAT_08014f40[5],DAT_08014f40[6],DAT_08014f3c + uVar2 * 0x98 + 4,
                     *(undefined2 *)(DAT_08014f3c + uVar2 * 0x98 + 2));
      }
    }
  }
  return;
}



/* ===== FUN_08014f44 @ 0x8014F44 ===== */

undefined4 FUN_08014f44(undefined2 *param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((*DAT_08014fcc & 7) != 0) {
    uVar1 = (uint)DAT_08014fcc[1];
    do {
      uVar1 = uVar1 + 1 & 0xff;
      if (2 < uVar1) {
        uVar1 = 0;
      }
    } while (((uint)*DAT_08014fcc & 1 << uVar1) == 0);
    DAT_08014fcc[1] = (byte)uVar1;
    *param_1 = *(undefined2 *)(DAT_08014fcc + uVar1 * 0x98 + 2);
    FUN_080031a4(param_1 + 1,DAT_08014fcc + uVar1 * 0x98 + 4,
                 *(undefined2 *)(DAT_08014fcc + uVar1 * 0x98 + 2));
    *DAT_08014fcc = *DAT_08014fcc & ~(byte)(1 << uVar1);
    uVar2 = 1;
  }
  return uVar2;
}



/* ===== irq_37_Handler @ 0x8014FD0 ===== */

void irq_37_Handler(void)

{
  FUN_08014b50();
  return;
}



/* ===== irq_39_Handler @ 0x8014FD8 ===== */

void irq_39_Handler(void)

{
  FUN_08014d90();
  return;
}



/* ===== FUN_08014fe0 @ 0x8014FE0 ===== */

void FUN_08014fe0(int param_1,uint param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (param_2 & 0xff) >> 5;
  uVar3 = 1 << (param_2 & 0x1f);
  if (uVar2 == 1) {
    puVar1 = (uint *)(param_1 + 0xc);
  }
  else if (uVar2 == 2) {
    puVar1 = (uint *)(param_1 + 0x10);
  }
  else {
    puVar1 = (uint *)(param_1 + 0x14);
  }
  if (param_3 == 0) {
    *puVar1 = *puVar1 & ~uVar3;
  }
  else {
    *puVar1 = *puVar1 | uVar3;
  }
  return;
}



/* ===== FUN_0801502c @ 0x801502C ===== */

void FUN_0801502c(int param_1)

{
  if (param_1 == DAT_080150b4) {
    FUN_0800e6c4(0x4000);
    FUN_0800e6c4(0x4000,0);
  }
  else if (param_1 == DAT_080150b8) {
    FUN_0800e684(0x20000);
    FUN_0800e684(0x20000,0);
  }
  else if (param_1 == DAT_080150bc) {
    FUN_0800e684(0x40000);
    FUN_0800e684(0x40000,0);
  }
  else if (param_1 == DAT_080150c0) {
    FUN_0800e6c4(0x20000);
    FUN_0800e6c4(0x20000,0);
  }
  else if (param_1 == DAT_080150c4) {
    FUN_0800e6c4(0x40000);
    FUN_0800e6c4(0x40000,0);
  }
  return;
}



/* ===== FUN_080150c8 @ 0x80150C8 ===== */

void FUN_080150c8(int param_1,int param_2)

{
  if (param_2 == 0) {
    *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) & 0xdfff;
  }
  else {
    *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) | 0x2000;
  }
  return;
}



/* ===== FUN_080150e0 @ 0x80150E0 ===== */

void FUN_080150e0(int param_1,ushort param_2,int param_3)

{
  if (param_3 == 0) {
    *(ushort *)(param_1 + 0x14) = *(ushort *)(param_1 + 0x14) & ~param_2;
  }
  else {
    *(ushort *)(param_1 + 0x14) = *(ushort *)(param_1 + 0x14) | param_2;
  }
  return;
}



/* ===== FUN_080150f2 @ 0x80150F2 ===== */

undefined4 FUN_080150f2(ushort *param_1,uint param_2)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (param_2 & 0xff) >> 5;
  uVar2 = 1 << (param_2 & 0x1f);
  if (uVar3 == 1) {
    uVar2 = uVar2 & param_1[6];
  }
  else if (uVar3 == 2) {
    uVar2 = uVar2 & param_1[8];
  }
  else {
    uVar2 = uVar2 & param_1[10];
  }
  if ((uVar2 == 0) || ((1 << ((int)param_2 >> 8 & 0xffU) & (uint)*param_1) == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}



/* ===== FUN_08015148 @ 0x8015148 ===== */

void FUN_08015148(int param_1,int *param_2)

{
  uint uVar1;
  undefined1 auStack_38 [8];
  int local_30;
  int local_2c;
  
  *(ushort *)(param_1 + 0x10) = *(ushort *)(param_1 + 0x10) & 0xcfff | *(ushort *)((int)param_2 + 6)
  ;
  *(ushort *)(param_1 + 0xc) =
       *(ushort *)(param_1 + 0xc) & 0xe9f3 |
       *(ushort *)(param_2 + 1) | *(ushort *)(param_2 + 2) | *(ushort *)((int)param_2 + 10);
  *(ushort *)(param_1 + 0x14) = *(ushort *)(param_1 + 0x14) & 0xfcff | *(ushort *)(param_2 + 3);
  FUN_0800e708(auStack_38);
  if (((param_1 != DAT_080151f0) && (param_1 != DAT_080151f4)) && (param_1 != DAT_080151f8)) {
    local_2c = local_30;
  }
  uVar1 = (uint)(local_2c * 0x19) / (uint)(*param_2 << 2);
  *(ushort *)(param_1 + 8) =
       (ushort)(uVar1 / 100 << 4) | (ushort)(((uVar1 % 100) * 0x10 + 0x32) / 100) & 0xf;
  return;
}



/* ===== FUN_080151fc @ 0x80151FC ===== */

void FUN_080151fc(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  
  if ((param_3 < 0x97) && ((*DAT_08015280 & 7) != 7)) {
    uVar1 = (uint)DAT_08015280[1];
    do {
      uVar1 = uVar1 + 1 & 0xff;
      if (2 < uVar1) {
        uVar1 = 0;
      }
    } while (((uint)*DAT_08015280 & 1 << uVar1) != 0);
    *DAT_08015280 = *DAT_08015280 | (byte)(1 << uVar1);
    *(short *)(DAT_08015280 + uVar1 * 0x98 + 2) = (short)param_3;
    FUN_080031a4(DAT_08015280 + uVar1 * 0x98 + 4,param_2,param_3);
    FUN_08014c24();
  }
  return;
}



/* ===== FUN_08015284 @ 0x8015284 ===== */

void FUN_08015284(undefined4 param_1,undefined4 param_2,int param_3)

{
  uint uVar1;
  
  if ((param_3 < 0x97) && ((*DAT_08015308 & 7) != 7)) {
    uVar1 = (uint)DAT_08015308[1];
    do {
      uVar1 = uVar1 + 1 & 0xff;
      if (2 < uVar1) {
        uVar1 = 0;
      }
    } while (((uint)*DAT_08015308 & 1 << uVar1) != 0);
    *DAT_08015308 = *DAT_08015308 | (byte)(1 << uVar1);
    *(short *)(DAT_08015308 + uVar1 * 0x98 + 2) = (short)param_3;
    FUN_080031a4(DAT_08015308 + uVar1 * 0x98 + 4,param_2,param_3);
    FUN_08014e64();
  }
  return;
}



/* ===== FUN_0801530c @ 0x801530C ===== */

void FUN_0801530c(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  bool bVar4;
  undefined4 local_14;
  uint uStack_10;
  
  bVar1 = false;
  local_14 = param_3;
  uStack_10 = param_4;
  iVar2 = FUN_0800a380(&local_14,0x50000,8,param_4,param_2);
  if ((iVar2 != 0) && (uVar3 = FUN_0800a7f8(&local_14,7), uStack_10 >> 0x18 == uVar3)) {
    bVar1 = true;
  }
  if (!bVar1) {
    iVar2 = 100;
    do {
      bVar4 = iVar2 != 0;
      iVar2 = iVar2 + -1;
    } while (bVar4);
    iVar2 = FUN_0800a380(&local_14,0x51000,8);
    if ((iVar2 != 0) && (uVar3 = FUN_0800a7f8(&local_14,7), uStack_10 >> 0x18 == uVar3)) {
      bVar1 = true;
    }
  }
  if (bVar1) {
    FUN_08012a5c(local_14,uStack_10);
  }
  return;
}



/* ===== usage_fault_Handler @ 0x8015376 ===== */

void usage_fault_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_08015378 @ 0x8015378 ===== */

void FUN_08015378(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}



/* ===== FUN_0801537c @ 0x801537C ===== */

void FUN_0801537c(void)

{
  uint *puVar1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  int iVar6;
  short sVar7;
  ushort uVar8;
  uint uVar9;
  byte local_2c;
  
  puVar1 = DAT_08015788;
  sVar7 = 0;
  if (*(char *)(DAT_08015784 + 3) == '\0') {
    *DAT_08015788 = 0;
    sVar7 = 0;
  }
  else {
    *DAT_08015788 = *DAT_08015788 + 1;
    if (0x31 < *puVar1) {
      *puVar1 = 0x32;
      sVar7 = 1;
    }
  }
  if (*DAT_0801578c == '\x01') {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_0800a938();
  }
  uVar5 = FUN_0800aa44();
  iVar6 = FUN_08006d48(*(short *)(DAT_08015790 + 0x38) * 10);
  if (iVar6 < 0) {
    uVar8 = -(short)(iVar6 / 10) | 0x8000;
  }
  else {
    uVar8 = (ushort)(iVar6 / 10);
  }
  if ((int)((uint)(byte)DAT_08015794[6] << 0x1e) < 0 ||
      (int)((uint)(byte)DAT_08015794[6] << 0x1b) < 0) {
    uVar9 = (uint)DAT_08015794[1];
  }
  else if ((DAT_08015794[6] & 1U) == 0 && -1 < (int)((uint)(byte)DAT_08015794[6] << 0x1d)) {
    uVar9 = (uint)*DAT_08015794;
  }
  else {
    uVar9 = (uint)DAT_08015794[2];
  }
  if ((int)uVar9 < 0) {
    uVar9 = -uVar9 | 0x80;
  }
  if ((char)DAT_08015798[4] < '\0') {
    local_2c = DAT_0801579c[2];
    DAT_08015798[4] = DAT_08015798[4] & 0xbf;
  }
  else {
    if ((byte)DAT_0801579c[2] < 0xd) {
      local_2c = DAT_0801579c[2];
    }
    else {
      local_2c = DAT_0801579c[2] - 0xc;
    }
    DAT_08015798[4] = DAT_08015798[4] & 0xbf | (0xc < (byte)DAT_0801579c[2]) << 6;
  }
  puVar2 = DAT_080157a4;
  *DAT_080157a4 = *DAT_080157a0;
  puVar2[1] = DAT_080157a0[1];
  *(undefined2 *)(puVar2 + 2) = uVar4;
  *(undefined2 *)(puVar2 + 4) = uVar5;
  puVar2[6] = *DAT_080157a8;
  puVar2[7] = *DAT_080157ac;
  puVar2 = DAT_08015798;
  *DAT_08015798 = (char)((byte)DAT_0801579c[5] + 2000 >> 8);
  puVar2[1] = DAT_0801579c[5] + -0x30;
  DAT_08015798[2] = DAT_08015798[2] & 0xf0 | DAT_0801579c[4] & 0xf;
  puVar2 = DAT_08015798;
  DAT_08015798[2] = DAT_08015798[2] & 0xf | DAT_0801579c[6] << 4;
  puVar2[3] = DAT_0801579c[3];
  DAT_08015798[4] = puVar2[4] & 0xc0 | local_2c & 0x3f;
  puVar2 = DAT_08015798;
  DAT_08015798[5] = DAT_0801579c[1];
  puVar2[6] = *DAT_0801579c;
  pcVar3 = DAT_080157b4;
  *DAT_080157b4 = (char)(*(ushort *)(DAT_080157b0 + 8) / 10) + '\x06';
  pcVar3[1] = *DAT_080157b8;
  pcVar3[2] = (char)((ushort)*(undefined2 *)DAT_080157b0 >> 8);
  pcVar3[3] = *DAT_080157b0;
  pcVar3[4] = (char)(uVar8 >> 8);
  pcVar3[5] = (char)uVar8;
  pcVar3[6] = (char)uVar9;
  *(ushort *)(DAT_080157b4 + 7) =
       *(ushort *)(DAT_080157b4 + 7) & 0xff7f |
       ((byte)((byte)DAT_080157b0[0xc] >> 2 | (byte)DAT_080157b0[0xc] >> 5) & 1) << 7;
  *(ushort *)(DAT_080157b4 + 7) =
       *(ushort *)(DAT_080157b4 + 7) & 0xffbf |
       ((byte)(DAT_080157b0[0xc] | (byte)DAT_080157b0[0xc] >> 1 | DAT_080157b0[0x17]) & 1) << 6;
  *(ushort *)(DAT_080157b4 + 7) =
       *(ushort *)(DAT_080157b4 + 7) & 0xffdf | (*(byte *)(DAT_080157bc + 8) >> 2 & 1) << 5;
  *(ushort *)(DAT_080157b4 + 7) =
       *(ushort *)(DAT_080157b4 + 7) & 0xffef |
       ((byte)(*(byte *)(DAT_080157bc + 8) | *(byte *)(DAT_080157bc + 8) >> 1) & 1) << 4;
  *(ushort *)(DAT_080157b4 + 7) =
       *(ushort *)(DAT_080157b4 + 7) & 0xfff7 | ((byte)DAT_08015794[6] >> 4 & 1) << 3;
  *(ushort *)(DAT_080157b4 + 7) =
       *(ushort *)(DAT_080157b4 + 7) & 0xfffb | ((byte)DAT_08015794[6] >> 2 & 1) << 2;
  pcVar3 = DAT_080157b4;
  *(ushort *)(DAT_080157b4 + 7) =
       *(ushort *)(DAT_080157b4 + 7) & 0xfffd | ((byte)DAT_08015794[6] >> 1 & 1) << 1;
  *(ushort *)(DAT_080157b4 + 7) = *(ushort *)(pcVar3 + 7) & 0xfffe | (byte)DAT_08015794[6] & 1;
  *(ushort *)(DAT_080157b4 + 7) =
       *(ushort *)(DAT_080157b4 + 7) & 0x7fff | (ushort)(*DAT_080157c0 == '\0') << 0xf;
  *(ushort *)(DAT_080157b4 + 7) =
       *(ushort *)(DAT_080157b4 + 7) & 0xbfff | (ushort)(*DAT_080157c0 == '\x01') << 0xe;
  *(ushort *)(DAT_080157b4 + 7) =
       *(ushort *)(DAT_080157b4 + 7) & 0xdfff | (*DAT_080157c4 & 1) << 0xd;
  uVar8 = FUN_0800c6a4();
  *(ushort *)(DAT_080157b4 + 7) = *(ushort *)(DAT_080157b4 + 7) & 0xefff | (uVar8 & 1) << 0xc;
  pcVar3 = DAT_080157b4;
  *(ushort *)(DAT_080157b4 + 7) =
       *(ushort *)(DAT_080157b4 + 7) & 0xf7ff | (*(byte *)(DAT_08015784 + 2) >> 4 & 1) << 0xb;
  *(ushort *)(DAT_080157b4 + 7) = *(ushort *)(pcVar3 + 7) & 0xfbff | sVar7 << 10;
  *(ushort *)(DAT_080157b4 + 7) =
       *(ushort *)(DAT_080157b4 + 7) & 0xfdff |
       ((byte)((byte)DAT_08015794[9] >> 3 | (byte)DAT_08015794[6] >> 6) & 1) << 9;
  *(ushort *)(DAT_080157b4 + 7) =
       *(ushort *)(DAT_080157b4 + 7) & 0xfeff | ((byte)DAT_08015794[9] >> 2 & 1) << 8;
  puVar2 = DAT_080157c8;
  *DAT_080157c8 = (char)((ushort)*(undefined2 *)(DAT_080157b8 + 2) >> 8);
  puVar2[1] = DAT_080157b8[2];
  DAT_080157c8[2] = (char)(*(uint *)(DAT_080157b8 + 0xc) / 10 >> 8);
  DAT_080157c8[3] = (char)(*(uint *)(DAT_080157b8 + 0xc) / 10);
  DAT_080157c8[4] = (char)(*(uint *)(DAT_080157b8 + 8) / 10 >> 8);
  puVar2 = DAT_080157c8;
  DAT_080157c8[5] = (char)(*(uint *)(DAT_080157b8 + 8) / 10);
  puVar2[10] = (char)((ushort)*DAT_080157cc >> 8);
  puVar2[0xb] = *(undefined1 *)DAT_080157cc;
  puVar2[6] = (char)((ushort)uVar4 >> 8);
  puVar2[7] = (char)uVar4;
  puVar2[8] = (char)((ushort)uVar5 >> 8);
  puVar2[9] = (char)uVar5;
  puVar2[0xc] = DAT_080157b8[1];
  for (uVar9 = 0; uVar9 < 0xd; uVar9 = uVar9 + 1 & 0xff) {
    *(ushort *)(DAT_080157d4 + uVar9 * 2) =
         *(ushort *)(DAT_080157d0 + uVar9 * 2) >> 8 |
         (ushort)*(byte *)(DAT_080157d0 + uVar9 * 2) << 8;
  }
  if (*DAT_080157d8 < '\0') {
    *DAT_08015940 = -0x80 - *DAT_0801593c;
  }
  else {
    *DAT_080157dc = *DAT_080157d8;
  }
  if (DAT_0801593c[1] < '\0') {
    DAT_08015940[1] = -0x80 - DAT_0801593c[1];
  }
  else {
    DAT_08015940[1] = DAT_0801593c[1];
  }
  puVar2 = DAT_08015948;
  if ((*(byte *)(DAT_08015944 + 9) & 1) == 0) {
    uVar9 = *(uint *)(DAT_08015944 + 9) >> 1;
  }
  else {
    uVar9 = (*(uint *)(DAT_08015944 + 9) >> 1) + 1;
  }
  *DAT_08015948 = (char)(uVar9 >> 0x10);
  puVar2[1] = (char)(uVar9 >> 8);
  puVar2[2] = (char)uVar9;
  puVar2 = DAT_08015948;
  if (*(uint *)(DAT_08015944 + 0xd) % 1000 < 500) {
    sVar7 = (short)(*(uint *)(DAT_08015944 + 0xd) / 1000);
  }
  else {
    sVar7 = (short)(*(uint *)(DAT_08015944 + 0xd) / 1000) + 1;
  }
  DAT_08015948[3] = (char)((ushort)sVar7 >> 8);
  puVar2[4] = (char)sVar7;
  puVar2[5] = (char)((ushort)*(undefined2 *)(DAT_0801594c + 0x15) >> 8);
  puVar2[6] = *(undefined1 *)(DAT_0801594c + 0x15);
  if (9999 < *(uint *)(DAT_08015944 + 0x11)) {
    *(undefined4 *)(DAT_08015944 + 0x11) = 10000;
  }
  if (*(uint *)(DAT_08015944 + 0x11) < 0x78) {
    *(undefined4 *)(DAT_08015944 + 0x11) = 0x78;
  }
  DAT_08015948[7] = *(byte *)(DAT_08015944 + 0x11) / 0x28;
  DAT_08015948[8] = (char)(*(uint *)(DAT_08015950 + 4) / 10 >> 8);
  DAT_08015948[9] = (char)(*(uint *)(DAT_08015950 + 4) / 10);
  puVar2 = DAT_08015954;
  *DAT_08015954 = *(undefined1 *)(DAT_08015944 + 0x19);
  puVar2[1] = *(undefined1 *)(DAT_08015944 + 0x1a);
  puVar2[2] = *(undefined1 *)(DAT_08015944 + 0x1b);
  puVar2[3] = *(undefined1 *)(DAT_08015944 + 0x1c);
  puVar2[4] = *(undefined1 *)(DAT_08015944 + 0x1d);
  puVar2[5] = *(undefined1 *)(DAT_08015944 + 0x1e);
  if (DAT_08015958 <= *(uint *)(DAT_08015944 + 0x15)) {
    *(uint *)(DAT_08015944 + 0x15) = DAT_08015958;
  }
  DAT_08015954[6] = (char)(*(uint *)(DAT_08015944 + 0x15) / 10 >> 8);
  DAT_08015954[7] = (char)(*(uint *)(DAT_08015944 + 0x15) / 10);
  return;
}



/* ===== FUN_0801595c @ 0x801595C ===== */

void FUN_0801595c(void)

{
  byte *pbVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = 0;
  if (*DAT_080159a4 != '\0') {
    iVar2 = FUN_0800aaf0();
    pbVar1 = DAT_080159a8;
    if (iVar2 == 0) {
      *DAT_080159a8 = *DAT_080159a8 + 1;
      if (5 < *pbVar1) {
        *pbVar1 = 0;
        *DAT_080159a4 = '\0';
        FUN_08015c78(&local_8);
      }
    }
    else {
      *DAT_080159a8 = 0;
      *DAT_080159a4 = '\0';
      FUN_08015c78(&local_8);
    }
  }
  return;
}



/* ===== FUN_080159ac @ 0x80159AC ===== */

void FUN_080159ac(void)

{
  undefined4 local_8;
  
  local_8 = 3;
  FUN_08015c78(&local_8);
  return;
}



/* ===== FUN_080159fc @ 0x80159FC ===== */

void FUN_080159fc(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 local_10;
  undefined4 local_c;
  
  puVar1 = DAT_08015ae0;
  DAT_08015ae0[1] = 0;
  *puVar1 = 1;
  local_10 = param_3;
  local_c = param_4;
  FUN_0800aa90(&local_10);
  puVar2 = DAT_08015ae4;
  *DAT_08015ae4 = local_10;
  *(undefined2 *)(puVar2 + 1) = (undefined2)local_c;
  *(undefined1 *)((int)puVar2 + 6) = local_c._2_1_;
  puVar1 = DAT_08015ae8;
  *DAT_08015ae8 = (char)(*(byte *)((int)puVar2 + 5) + 2000 >> 8);
  puVar1[1] = *(char *)((int)DAT_08015ae4 + 5) + -0x30;
  DAT_08015ae8[2] = DAT_08015ae8[2] & 0xf0 | *(byte *)(DAT_08015ae4 + 1) & 0xf;
  puVar1 = DAT_08015ae8;
  DAT_08015ae8[2] = DAT_08015ae8[2] & 0xf | *(char *)((int)DAT_08015ae4 + 6) << 4;
  puVar1[3] = *(undefined1 *)((int)DAT_08015ae4 + 3);
  puVar1[4] = (puVar1[4] & 0x7f) + 0x80;
  puVar1[4] = puVar1[4] & 0xbf;
  puVar1 = DAT_08015ae8;
  DAT_08015ae8[4] = DAT_08015ae8[4] & 0xc0 | *(byte *)((int)DAT_08015ae4 + 2) & 0x3f;
  puVar1[5] = *(undefined1 *)((int)DAT_08015ae4 + 1);
  puVar1[6] = *(undefined1 *)DAT_08015ae4;
  puVar3 = DAT_08015af0;
  puVar2 = DAT_08015aec;
  *DAT_08015aec = *DAT_08015af0;
  *(undefined2 *)(puVar2 + 1) = *(undefined2 *)(puVar3 + 1);
  *(undefined1 *)((int)puVar2 + 6) = *(undefined1 *)((int)puVar3 + 6);
  puVar3 = DAT_08015af8;
  puVar2 = DAT_08015af4;
  *DAT_08015af4 = *DAT_08015af8;
  *(undefined2 *)(puVar2 + 1) = *(undefined2 *)(puVar3 + 1);
  *(undefined1 *)((int)puVar2 + 6) = *(undefined1 *)((int)puVar3 + 6);
  puVar2 = DAT_08015afc;
  *DAT_08015afc = 0;
  puVar2[1] = 0;
  *(undefined1 *)(puVar2 + 2) = 0;
  FUN_080031d6(DAT_08015b00,0xd);
  *DAT_08015b04 = 0;
  puVar2 = DAT_08015b08;
  *DAT_08015b08 = 0;
  puVar2[1] = 0;
  *(undefined2 *)(puVar2 + 2) = 0;
  puVar2 = DAT_08015b0c;
  *DAT_08015b0c = 0;
  puVar2[1] = 0;
  *DAT_08015b10 = 0;
  return;
}



/* ===== FUN_08015b60 @ 0x8015B60 ===== */

int FUN_08015b60(void)

{
  int iVar1;
  int iVar2;
  undefined4 in_r3;
  bool bVar3;
  
  iVar1 = FUN_0800a380(DAT_08015bb4,0x40000,0xe,in_r3,in_r3);
  if (iVar1 == 0) {
    iVar1 = 100;
    do {
      bVar3 = iVar1 != 0;
      iVar1 = iVar1 + -1;
    } while (bVar3);
    iVar1 = FUN_0800a380(DAT_08015bb4,0x40000,0xe);
  }
  if ((iVar1 == 1) && (iVar2 = FUN_0800aa50(DAT_08015bb4,10), *(int *)(DAT_08015bb4 + 10) != iVar2))
  {
    iVar1 = 0;
  }
  return iVar1;
}



/* ===== FUN_08015c5c @ 0x8015C5C ===== */

void FUN_08015c5c(void)

{
  FUN_080031d6(DAT_08015c70,0x4b);
  *DAT_08015c74 = 1;
  return;
}



/* ===== FUN_08015c78 @ 0x8015C78 ===== */

void FUN_08015c78(char *param_1)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined1 uVar3;
  ushort uVar4;
  int iVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  int iVar11;
  undefined4 local_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 local_14;
  undefined2 local_10;
  undefined1 local_e;
  
  FUN_0800aa90(&local_14);
  puVar1 = DAT_08016080;
  *DAT_08016080 = local_14;
  *(undefined2 *)(puVar1 + 1) = local_10;
  *(undefined1 *)((int)puVar1 + 6) = local_e;
  FUN_080031a4(DAT_08016084 + 0x19,DAT_08016084,0x19);
  FUN_080031a4(DAT_08016084,DAT_08016084 + -0x19,0x19);
  iVar5 = DAT_08016084;
  *(undefined1 *)(DAT_08016084 + -0x19) = *(undefined1 *)((int)DAT_08016080 + 5);
  *(undefined1 *)(iVar5 + -0x18) = *(undefined1 *)(DAT_08016080 + 1);
  *(undefined1 *)(iVar5 + -0x17) = *(undefined1 *)((int)DAT_08016080 + 3);
  *(undefined1 *)(iVar5 + -0x16) = *(undefined1 *)((int)DAT_08016080 + 2);
  *(undefined1 *)(iVar5 + -0x15) = *(undefined1 *)((int)DAT_08016080 + 1);
  *(undefined1 *)(iVar5 + -0x14) = *(undefined1 *)DAT_08016080;
  *(undefined1 *)(iVar5 + -0x13) = 0;
  *(undefined1 *)(iVar5 + -0x12) = 0;
  *(undefined1 *)(iVar5 + -0x11) = *(undefined1 *)(DAT_08016088 + 0xb);
  *(char *)(iVar5 + -0x10) = (char)((ushort)*(undefined2 *)(DAT_08016088 + 8) >> 8);
  *(undefined1 *)(iVar5 + -0xf) = *(undefined1 *)(DAT_08016088 + 8);
  *(undefined1 *)(iVar5 + -0xe) = *(undefined1 *)(DAT_08016088 + 10);
  *(char *)(iVar5 + -0xd) = (char)((ushort)*(undefined2 *)(DAT_08016088 + 6) >> 8);
  *(undefined1 *)(iVar5 + -0xc) = *(undefined1 *)(DAT_08016088 + 6);
  if ((char)*DAT_0801608c < '\0') {
    bVar2 = -*DAT_0801608c | 0x80;
  }
  else {
    bVar2 = *DAT_0801608c;
  }
  *(byte *)(DAT_08016084 + -0xb) = bVar2;
  if ((char)DAT_0801608c[1] < '\0') {
    bVar2 = -DAT_0801608c[1] | 0x80;
  }
  else {
    bVar2 = DAT_0801608c[1];
  }
  *(byte *)(DAT_08016084 + -10) = bVar2;
  if (*(char *)(DAT_08016090 + 8) < '\0') {
    bVar2 = -*(char *)(DAT_08016090 + 8) | 0x80;
  }
  else {
    bVar2 = *(byte *)(DAT_08016090 + 8);
  }
  *(byte *)(DAT_08016084 + -9) = bVar2;
  iVar5 = DAT_08016084;
  if (*DAT_08016094 / 10 < 0) {
    uVar4 = (ushort)(-*DAT_08016094 / 10) | 0x8000;
  }
  else {
    uVar4 = (ushort)(*DAT_08016094 / 10);
  }
  *(char *)(DAT_08016084 + -8) = (char)(uVar4 >> 8);
  *(char *)(iVar5 + -7) = (char)uVar4;
  *(undefined1 *)(iVar5 + -6) = *DAT_08016098;
  iVar11 = ((uint)*(ushort *)(DAT_0801609c + 0x34) * 5 & 0x7fff) << 1;
  *(char *)(iVar5 + -5) = (char)((uint)iVar11 >> 8);
  *(char *)(iVar5 + -4) = (char)iVar11;
  *(undefined1 *)(iVar5 + -3) = *(undefined1 *)(DAT_080160a0 + 2);
  *(undefined1 *)(DAT_08016084 + -2) = *(undefined1 *)(DAT_080160a0 + 3);
  cVar6 = *param_1;
  if (cVar6 == '\0') {
    *DAT_080160a4 = 1;
    iVar5 = DAT_08016084;
    *(undefined1 *)(DAT_08016084 + -0x13) = 2;
    *(undefined1 *)(iVar5 + -0x12) = 0;
  }
  else if (cVar6 == '\x01') {
    *DAT_080160a4 = 3;
    if ((((*(byte *)(DAT_08016088 + 0xc) & 1) == 0) &&
        (-1 < (int)((uint)*(byte *)(DAT_08016088 + 0xc) << 0x1c))) &&
       (-1 < (int)((uint)*(byte *)(DAT_080160a8 + 2) << 0x1b))) {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    *(byte *)(DAT_08016084 + -0x13) =
         *(byte *)(DAT_080160a8 + 2) & 8 | (byte)(((*(byte *)(DAT_080160a8 + 2) & 7) >> 2) << 4) |
         (byte)(((*(byte *)(DAT_08016088 + 0xc) & 0x7f) >> 6) << 5) |
         (byte)(((*(byte *)(DAT_08016088 + 0xc) & 0x1f) >> 4) << 6) | cVar6 << 7;
    if ((((((*(byte *)(DAT_08016090 + 6) & 1) == 0) &&
          (-1 < (int)((uint)*(byte *)(DAT_08016090 + 6) << 0x1e))) &&
         ((-1 < (int)((uint)*(byte *)(DAT_08016090 + 6) << 0x1c) &&
          ((-1 < (int)((uint)*(byte *)(DAT_08016090 + 6) << 0x1a) &&
           (-1 < (int)((uint)*(byte *)(DAT_08016090 + 9) << 0x1e))))))) &&
        (-1 < (int)((uint)*(byte *)(DAT_08016090 + 9) << 0x1d))) &&
       ((-1 < (int)((uint)*(byte *)(DAT_08016090 + 9) << 0x1c) &&
        (-1 < (int)((uint)*(byte *)(DAT_08016090 + 6) << 0x19))))) {
      iVar5 = 0;
    }
    else {
      iVar5 = 1;
    }
    if (((*(byte *)(DAT_08016094 + 2) & 1) == 0) &&
       (-1 < (int)((uint)*(byte *)(DAT_08016094 + 2) << 0x1e))) {
      iVar11 = 0;
    }
    else {
      iVar11 = 1;
    }
    if (((int)((uint)*(byte *)(DAT_08016094 + 2) << 0x1c) < 0) ||
       ((int)((uint)*(byte *)(DAT_08016094 + 2) << 0x1b) < 0)) {
      iVar7 = 1;
    }
    else {
      iVar7 = 0;
    }
    *(byte *)(DAT_08016084 + -0x12) =
         (byte)((((*(byte *)(DAT_080160a8 + 3) & 7) >> 2) << 10) >> 8) |
         (byte)((uint)(iVar5 << 0xb) >> 8) | (byte)((uint)(iVar11 << 0xc) >> 8) |
         (byte)((((*(byte *)(DAT_08016094 + 2) & 0x7f) >> 6) << 0xd) >> 8) |
         (byte)((((*(byte *)(DAT_08016094 + 2) & 0x3f) >> 5) << 0xe) >> 8) |
         (byte)((uint)(iVar7 << 0xf) >> 8);
  }
  else if (cVar6 == '\x02') {
    *DAT_080160a4 = 1;
    if ((((*(byte *)(DAT_08016088 + 0xc) & 1) == 0) &&
        (-1 < (int)((uint)*(byte *)(DAT_08016088 + 0xc) << 0x1c))) &&
       (-1 < (int)((uint)*(byte *)(DAT_0801634c + 2) << 0x1b))) {
      cVar6 = '\0';
    }
    else {
      cVar6 = '\x01';
    }
    *(byte *)(DAT_08016358 + 6) =
         *(byte *)(DAT_080160a8 + 2) & 8 | (byte)(((*(byte *)(DAT_080160a8 + 2) & 7) >> 2) << 4) |
         (byte)(((*(byte *)(DAT_08016088 + 0xc) & 0x7f) >> 6) << 5) |
         (byte)(((*(byte *)(DAT_08016088 + 0xc) & 0x1f) >> 4) << 6) | cVar6 << 7;
    iVar5 = DAT_08016358;
    if (((((*(byte *)(DAT_08016350 + 6) & 1) == 0) &&
         (-1 < (int)((uint)*(byte *)(DAT_08016350 + 6) << 0x1e))) &&
        ((-1 < (int)((uint)*(byte *)(DAT_08016350 + 6) << 0x1c) &&
         ((-1 < (int)((uint)*(byte *)(DAT_08016350 + 6) << 0x1a) &&
          (-1 < (int)((uint)*(byte *)(DAT_08016350 + 9) << 0x1e))))))) &&
       ((-1 < (int)((uint)*(byte *)(DAT_08016350 + 9) << 0x1d) &&
        ((-1 < (int)((uint)*(byte *)(DAT_08016350 + 9) << 0x1c) &&
         (-1 < (int)((uint)*(byte *)(DAT_08016350 + 6) << 0x19))))))) {
      iVar11 = 0;
    }
    else {
      iVar11 = 1;
    }
    if (((*(byte *)(DAT_08016354 + 8) & 1) == 0) &&
       (-1 < (int)((uint)*(byte *)(DAT_08016354 + 8) << 0x1e))) {
      iVar7 = 0;
    }
    else {
      iVar7 = 1;
    }
    if (((int)((uint)*(byte *)(DAT_08016354 + 8) << 0x1c) < 0) ||
       ((int)((uint)*(byte *)(DAT_08016354 + 8) << 0x1b) < 0)) {
      iVar8 = 1;
    }
    else {
      iVar8 = 0;
    }
    *(byte *)(DAT_08016358 + 7) =
         (byte)((((*(byte *)(DAT_0801634c + 3) & 7) >> 2) << 10) >> 8) |
         (byte)((uint)(iVar11 << 0xb) >> 8) | (byte)((uint)(iVar7 << 0xc) >> 8) |
         (byte)((((*(byte *)(DAT_08016354 + 8) & 0x7f) >> 6) << 0xd) >> 8) |
         (byte)((((*(byte *)(DAT_08016354 + 8) & 0x3f) >> 5) << 0xe) >> 8) |
         (byte)((uint)(iVar8 << 0xf) >> 8);
    *(byte *)(iVar5 + 7) = *(byte *)(iVar5 + 7) | 2;
  }
  else if (cVar6 == '\x03') {
    *DAT_08016360 = 1;
    iVar5 = DAT_08016358;
    *(undefined1 *)(DAT_08016358 + 6) = 4;
    *(undefined1 *)(iVar5 + 7) = 0;
  }
  else {
    *DAT_08016364 = 0;
    *DAT_08016360 = 0;
    *param_1 = -1;
  }
  uVar3 = FUN_0800a7f8(DAT_08016358,0x18);
  *(undefined1 *)(DAT_08016358 + 0x18) = uVar3;
  if (*DAT_08016364 < *DAT_08016360) {
    *DAT_08016364 = *DAT_08016364 + 1;
  }
  else {
    *DAT_08016364 = 0;
    *DAT_08016360 = 0;
    *param_1 = -1;
  }
  if (*param_1 != -1) {
    iVar5 = (*DAT_08016360 - 1) * 0x19 + DAT_08016358;
    uVar9 = *(undefined4 *)(iVar5 + 0x10);
    uVar10 = *(undefined4 *)(iVar5 + 0x14);
    uVar3 = *(undefined1 *)(iVar5 + 0x18);
    FUN_080031a4(&local_28,(*DAT_08016360 - 1) * 0x19 + DAT_08016358,0x19);
    FUN_08016800(local_28,uStack_24,uStack_20,uStack_1c,uVar9,uVar10,uVar3);
  }
  return;
}



/* ===== FUN_08016368 @ 0x8016368 ===== */

void FUN_08016368(void)

{
  undefined2 *puVar1;
  int iVar2;
  undefined4 in_r3;
  bool bVar3;
  
  puVar1 = DAT_080163ac;
  *(undefined4 *)(DAT_080163ac + 1) = 0x41000;
  *(undefined4 *)(puVar1 + 3) = 0x41000;
  *puVar1 = 0;
  iVar2 = FUN_0800a4a0(DAT_080163ac,0x40000,0xe,in_r3,in_r3);
  if (iVar2 == 0) {
    iVar2 = 1000;
    do {
      bVar3 = iVar2 != 0;
      iVar2 = iVar2 + -1;
    } while (bVar3);
    FUN_0800a4a0(DAT_080163ac,0x40000,0xe);
  }
  return;
}



/* ===== FUN_080163b0 @ 0x80163B0 ===== */

void FUN_080163b0(void)

{
  ushort *puVar1;
  int iVar2;
  bool bVar3;
  int local_8;
  
  iVar2 = FUN_08015b60();
  if (iVar2 == 0) {
    local_8 = 1000;
    do {
      bVar3 = local_8 != 0;
      local_8 = local_8 + -1;
    } while (bVar3);
    FUN_08015b60();
  }
  puVar1 = DAT_08016420;
  if ((((0x200 < *DAT_08016420) || (*(uint *)(DAT_08016420 + 1) < 0x41000)) ||
      (0x45000 < *(uint *)(DAT_08016420 + 1))) ||
     ((*(uint *)(DAT_08016420 + 3) < 0x41000 || (0x45000 < *(uint *)(DAT_08016420 + 3))))) {
    *DAT_08016420 = 0;
    puVar1[1] = 0x1000;
    puVar1[2] = 4;
    puVar1[3] = 0x1000;
    puVar1[4] = 4;
    FUN_080167ac();
  }
  return;
}



/* ===== FUN_08016424 @ 0x8016424 ===== */

void FUN_08016424(void)

{
  short sVar1;
  short sVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  if ((((*(byte *)(DAT_08016798 + 0xc) & 1) == 0) &&
      (-1 < (int)((uint)*(byte *)(DAT_08016798 + 0xc) << 0x1c))) &&
     (-1 < (int)((uint)*(byte *)(DAT_08016794 + 2) << 0x1b))) {
    iVar5 = 0;
  }
  else {
    iVar5 = 1;
  }
  if ((((((*(byte *)(DAT_0801679c + 6) & 1) == 0) &&
        (-1 < (int)((uint)*(byte *)(DAT_0801679c + 6) << 0x1e))) &&
       ((-1 < (int)((uint)*(byte *)(DAT_0801679c + 6) << 0x1c) &&
        ((-1 < (int)((uint)*(byte *)(DAT_0801679c + 6) << 0x1a) &&
         (-1 < (int)((uint)*(byte *)(DAT_0801679c + 9) << 0x1e))))))) &&
      (-1 < (int)((uint)*(byte *)(DAT_0801679c + 9) << 0x1d))) &&
     ((-1 < (int)((uint)*(byte *)(DAT_0801679c + 9) << 0x1c) &&
      (-1 < (int)((uint)*(byte *)(DAT_0801679c + 6) << 0x19))))) {
    iVar6 = 0;
  }
  else {
    iVar6 = 1;
  }
  if (((*(byte *)(DAT_080167a0 + 8) & 1) == 0) &&
     (-1 < (int)((uint)*(byte *)(DAT_080167a0 + 8) << 0x1e))) {
    iVar7 = 0;
  }
  else {
    iVar7 = 1;
  }
  if (((int)((uint)*(byte *)(DAT_080167a0 + 8) << 0x1c) < 0) ||
     ((int)((uint)*(byte *)(DAT_080167a0 + 8) << 0x1b) < 0)) {
    iVar8 = 1;
  }
  else {
    iVar8 = 0;
  }
  if ((uint)*DAT_080167a4 <
      (*(byte *)(DAT_08016794 + 2) & 8 | ((*(byte *)(DAT_08016794 + 2) & 7) >> 2) << 4 |
       ((*(byte *)(DAT_08016798 + 0xc) & 0x7f) >> 6) << 5 |
       ((*(byte *)(DAT_08016798 + 0xc) & 0x1f) >> 4) << 6 | iVar5 << 7 |
       ((*(byte *)(DAT_08016794 + 3) & 7) >> 2) << 10 | iVar6 << 0xb | iVar7 << 0xc |
       ((*(byte *)(DAT_080167a0 + 8) & 0x7f) >> 6) << 0xd |
       ((*(byte *)(DAT_080167a0 + 8) & 0x3f) >> 5) << 0xe | iVar8 << 0xf)) {
    *DAT_080167a8 = 1;
  }
  else {
    if ((((*(byte *)(DAT_08016798 + 0xc) & 1) == 0) &&
        (-1 < (int)((uint)*(byte *)(DAT_08016798 + 0xc) << 0x1c))) &&
       (-1 < (int)((uint)*(byte *)(DAT_08016794 + 2) << 0x1b))) {
      iVar5 = 0;
    }
    else {
      iVar5 = 1;
    }
    if (((((*(byte *)(DAT_0801679c + 6) & 1) == 0) &&
         (-1 < (int)((uint)*(byte *)(DAT_0801679c + 6) << 0x1e))) &&
        ((-1 < (int)((uint)*(byte *)(DAT_0801679c + 6) << 0x1c) &&
         ((-1 < (int)((uint)*(byte *)(DAT_0801679c + 6) << 0x1a) &&
          (-1 < (int)((uint)*(byte *)(DAT_0801679c + 9) << 0x1e))))))) &&
       ((-1 < (int)((uint)*(byte *)(DAT_0801679c + 9) << 0x1d) &&
        ((-1 < (int)((uint)*(byte *)(DAT_0801679c + 9) << 0x1c) &&
         (-1 < (int)((uint)*(byte *)(DAT_0801679c + 6) << 0x19))))))) {
      iVar6 = 0;
    }
    else {
      iVar6 = 1;
    }
    if (((*(byte *)(DAT_080167a0 + 8) & 1) == 0) &&
       (-1 < (int)((uint)*(byte *)(DAT_080167a0 + 8) << 0x1e))) {
      iVar7 = 0;
    }
    else {
      iVar7 = 1;
    }
    if (((int)((uint)*(byte *)(DAT_080167a0 + 8) << 0x1c) < 0) ||
       ((int)((uint)*(byte *)(DAT_080167a0 + 8) << 0x1b) < 0)) {
      iVar8 = 1;
    }
    else {
      iVar8 = 0;
    }
    if ((*(byte *)(DAT_08016794 + 2) & 8 | ((*(byte *)(DAT_08016794 + 2) & 7) >> 2) << 4 |
         ((*(byte *)(DAT_08016798 + 0xc) & 0x7f) >> 6) << 5 |
         ((*(byte *)(DAT_08016798 + 0xc) & 0x1f) >> 4) << 6 | iVar5 << 7 |
         ((*(byte *)(DAT_08016794 + 3) & 7) >> 2) << 10 | iVar6 << 0xb | iVar7 << 0xc |
         ((*(byte *)(DAT_080167a0 + 8) & 0x7f) >> 6) << 0xd |
         ((*(byte *)(DAT_080167a0 + 8) & 0x3f) >> 5) << 0xe | iVar8 << 0xf) < (uint)*DAT_080167a4) {
      *DAT_080167a8 = 2;
    }
  }
  if ((((*(byte *)(DAT_08016798 + 0xc) & 1) == 0) &&
      (-1 < (int)((uint)*(byte *)(DAT_08016798 + 0xc) << 0x1c))) &&
     (-1 < (int)((uint)*(byte *)(DAT_08016794 + 2) << 0x1b))) {
    sVar1 = 0;
  }
  else {
    sVar1 = 1;
  }
  if (((((*(byte *)(DAT_0801679c + 6) & 1) == 0) &&
       (-1 < (int)((uint)*(byte *)(DAT_0801679c + 6) << 0x1e))) &&
      ((-1 < (int)((uint)*(byte *)(DAT_0801679c + 6) << 0x1c) &&
       ((-1 < (int)((uint)*(byte *)(DAT_0801679c + 6) << 0x1a) &&
        (-1 < (int)((uint)*(byte *)(DAT_0801679c + 9) << 0x1e))))))) &&
     ((-1 < (int)((uint)*(byte *)(DAT_0801679c + 9) << 0x1d) &&
      ((-1 < (int)((uint)*(byte *)(DAT_0801679c + 9) << 0x1c) &&
       (-1 < (int)((uint)*(byte *)(DAT_0801679c + 6) << 0x19))))))) {
    sVar2 = 0;
  }
  else {
    sVar2 = 1;
  }
  if (((*(byte *)(DAT_080167a0 + 8) & 1) == 0) &&
     (-1 < (int)((uint)*(byte *)(DAT_080167a0 + 8) << 0x1e))) {
    sVar3 = 0;
  }
  else {
    sVar3 = 1;
  }
  if (((int)((uint)*(byte *)(DAT_080167a0 + 8) << 0x1c) < 0) ||
     ((int)((uint)*(byte *)(DAT_080167a0 + 8) << 0x1b) < 0)) {
    sVar4 = 1;
  }
  else {
    sVar4 = 0;
  }
  *DAT_080167a4 =
       *(byte *)(DAT_08016794 + 2) & 8 | (ushort)(((*(byte *)(DAT_08016794 + 2) & 7) >> 2) << 4) |
       (ushort)(((*(byte *)(DAT_08016798 + 0xc) & 0x7f) >> 6) << 5) |
       (ushort)(((*(byte *)(DAT_08016798 + 0xc) & 0x1f) >> 4) << 6) | sVar1 << 7 |
       (ushort)(((*(byte *)(DAT_08016794 + 3) & 7) >> 2) << 10) | sVar2 << 0xb | sVar3 << 0xc |
       (ushort)(((*(byte *)(DAT_080167a0 + 8) & 0x7f) >> 6) << 0xd) |
       (ushort)(((*(byte *)(DAT_080167a0 + 8) & 0x3f) >> 5) << 0xe) | sVar4 << 0xf;
  FUN_0801595c();
  FUN_08015c78(DAT_080167a8);
  return;
}



/* ===== FUN_080167ac @ 0x80167AC ===== */

int FUN_080167ac(void)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_10;
  
  FUN_0800a2f0(0x40000);
  uVar1 = FUN_0800aa50(DAT_080167fc,10);
  *(undefined4 *)(DAT_080167fc + 10) = uVar1;
  iVar2 = FUN_0800a4a0(DAT_080167fc,0x40000,0xe);
  if (iVar2 == 0) {
    local_10 = 1000;
    do {
      bVar3 = local_10 != 0;
      local_10 = local_10 + -1;
    } while (bVar3);
    iVar2 = FUN_0800a4a0(DAT_080167fc,0x40000,0xe);
  }
  return iVar2;
}



/* ===== FUN_08016800 @ 0x8016800 ===== */

undefined4 FUN_08016800(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort *puVar1;
  int iVar2;
  char cVar3;
  bool bVar4;
  int local_20;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  puVar1 = DAT_08016920;
  cVar3 = '\x03';
  if ((((*(uint *)(DAT_08016920 + 1) < 0x41000) || (0x45000 < *(uint *)(DAT_08016920 + 1))) ||
      (*(uint *)(DAT_08016920 + 3) < 0x41000)) || (0x45000 < *(uint *)(DAT_08016920 + 3))) {
    *DAT_08016920 = 0;
    puVar1[1] = 0x1000;
    puVar1[2] = 4;
    puVar1[3] = 0x1000;
    puVar1[4] = 4;
  }
  uStack_10 = param_1;
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  if ((DAT_08016920[3] & 0xfff) == 0) {
    FUN_0800a2f0(*(undefined4 *)(DAT_08016920 + 3));
    local_20 = 1000;
    do {
      bVar4 = local_20 != 0;
      local_20 = local_20 + -1;
    } while (bVar4);
  }
  do {
    bVar4 = cVar3 == '\0';
    cVar3 = cVar3 + -1;
    if ((bVar4) ||
       (iVar2 = FUN_0800a4a0(&uStack_10,*(undefined4 *)(DAT_08016920 + 3),0x20), iVar2 == 1)) {
      puVar1 = DAT_08016920;
      *DAT_08016920 = *DAT_08016920 + 1;
      if (0x200 < *puVar1) {
        FUN_0800a2f0(*(undefined4 *)(puVar1 + 1));
        puVar1 = DAT_08016920;
        *DAT_08016920 = *DAT_08016920 - 0x80;
        *(int *)(puVar1 + 1) = *(int *)(puVar1 + 1) + 0x1000;
        if (0x44fff < *(uint *)(puVar1 + 1)) {
          puVar1[1] = 0x1000;
          puVar1[2] = 4;
        }
      }
      puVar1 = DAT_08016920;
      *(int *)(DAT_08016920 + 3) = *(int *)(DAT_08016920 + 3) + 0x20;
      if (0x44fff < *(uint *)(puVar1 + 3)) {
        puVar1[3] = 0x1000;
        puVar1[4] = 4;
      }
      FUN_080167ac();
      return 1;
    }
    local_20 = 500;
    do {
      bVar4 = local_20 != 0;
      local_20 = local_20 + -1;
    } while (bVar4);
  } while (cVar3 != '\0');
  return 0;
}



/* ===== FUN_08016924 @ 0x8016924 ===== */

void FUN_08016924(void)

{
  byte bVar1;
  int iVar2;
  undefined4 local_10;
  
  local_10 = 0;
  bVar1 = 0;
  while( true ) {
    if (2 < bVar1) {
      return;
    }
    iVar2 = FUN_0800eee0(8,0x91b2,&local_10,2);
    if (iVar2 != 0) break;
    bVar1 = bVar1 + 1;
  }
  *(undefined2 *)(DAT_08016954 + 0x1e) = (undefined2)local_10;
  return;
}



/* ===== FUN_08016958 @ 0x8016958 ===== */

void FUN_08016958(int param_1)

{
  if (param_1 == 1) {
    FUN_0800eb10(0);
  }
  else if (param_1 == 2) {
    FUN_0800eb10(1);
  }
  else if (param_1 == 3) {
    FUN_0800eb10(2);
  }
  else if (param_1 == 4) {
    FUN_0800eb10(3);
  }
  else if (param_1 == 5) {
    FUN_0800eb10(4);
  }
  else if (param_1 == 6) {
    FUN_0800eb10(6);
  }
  return;
}



/* ===== FUN_080169a4 @ 0x80169A4 ===== */

void FUN_080169a4(void)

{
  ushort *puVar1;
  ushort *puVar2;
  
  puVar2 = DAT_08016a50;
  puVar1 = DAT_08016a4c;
  if ((int)((uint)*(byte *)(DAT_08016a44 + 9) << 0x1d) < 0) {
    if ((int)*(char *)(DAT_08016a48 + 0x3f) <
        (int)*(char *)(DAT_08016a44 + 2) - (int)*(char *)(DAT_08016a44 + 1)) {
      *DAT_08016a50 = 0;
    }
    else {
      *DAT_08016a50 = *DAT_08016a50 + 1;
      if (*(ushort *)(DAT_08016a48 + 0x40) <= *puVar2) {
        *(byte *)(DAT_08016a44 + 9) = *(byte *)(DAT_08016a44 + 9) & 0xfb;
        *DAT_08016a50 = 0;
      }
    }
  }
  else if ((int)*(char *)(DAT_08016a44 + 2) - (int)*(char *)(DAT_08016a44 + 1) <
           (int)*(char *)(DAT_08016a48 + 0x3c)) {
    *DAT_08016a4c = 0;
  }
  else {
    *DAT_08016a4c = *DAT_08016a4c + 1;
    if (*(ushort *)(DAT_08016a48 + 0x3d) <= *puVar1) {
      *(byte *)(DAT_08016a44 + 9) = (*(byte *)(DAT_08016a44 + 9) & 0xfb) + 4;
      *DAT_08016a4c = 0;
    }
  }
  return;
}



/* ===== FUN_08016a54 @ 0x8016A54 ===== */

void FUN_08016a54(void)

{
  ushort *puVar1;
  
  puVar1 = DAT_08016b20;
  if (((*DAT_08016b14 == '\x01') || (*DAT_08016b14 == '\x02')) &&
     (-1 < (int)((uint)*(byte *)(DAT_08016b18 + 0xc) << 0x1d))) {
    if (*(ushort *)(DAT_08016b1c + 0x2a) < *(ushort *)(DAT_08016b18 + 6)) {
      *DAT_08016b20 = 0;
    }
    else {
      *DAT_08016b20 = *DAT_08016b20 + 1;
      if (*(ushort *)(DAT_08016b1c + 0x2e) <= *puVar1) {
        *(byte *)(DAT_08016b18 + 0xc) = (*(byte *)(DAT_08016b18 + 0xc) & 0xfb) + 4;
        *DAT_08016b20 = 0;
      }
    }
  }
  puVar1 = DAT_08016b28;
  if ((int)((uint)*(byte *)(DAT_08016b18 + 0xc) << 0x1d) < 0) {
    if ((*DAT_08016b14 == '\0') && (99 < *(uint *)(DAT_08016b24 + 4))) {
      *(byte *)(DAT_08016b18 + 0xc) = *(byte *)(DAT_08016b18 + 0xc) & 0xfb;
      *DAT_08016b28 = 0;
    }
    else if (*(ushort *)(DAT_08016b18 + 6) < *(ushort *)(DAT_08016b1c + 0x2c)) {
      *DAT_08016b28 = 0;
    }
    else {
      *DAT_08016b28 = *DAT_08016b28 + 1;
      if (*(ushort *)(DAT_08016b1c + 0x30) <= *puVar1) {
        *(byte *)(DAT_08016b18 + 0xc) = *(byte *)(DAT_08016b18 + 0xc) & 0xfb;
        *DAT_08016b28 = 0;
      }
    }
  }
  return;
}



/* ===== FUN_08016b2c @ 0x8016B2C ===== */

void FUN_08016b2c(void)

{
  ushort *puVar1;
  
  puVar1 = DAT_08016be4;
  if (((*DAT_08016bd4 == '\x01') && (99 < *(uint *)(DAT_08016bd8 + 4))) &&
     (-1 < (int)((uint)*(byte *)(DAT_08016bdc + 6) << 0x1d))) {
    if (*(char *)(DAT_08016bdc + 2) < *(char *)(DAT_08016be0 + 0x24)) {
      *DAT_08016be4 = 0;
    }
    else {
      *DAT_08016be4 = *DAT_08016be4 + 1;
      if (*(ushort *)(DAT_08016be0 + 0x25) <= *puVar1) {
        *(byte *)(DAT_08016bdc + 6) = (*(byte *)(DAT_08016bdc + 6) & 0xfb) + 4;
        *DAT_08016be4 = 0;
      }
    }
  }
  puVar1 = DAT_08016be8;
  if ((int)((uint)*(byte *)(DAT_08016bdc + 6) << 0x1d) < 0) {
    if (*(char *)(DAT_08016be0 + 0x27) < *(char *)(DAT_08016bdc + 2)) {
      *DAT_08016be8 = 0;
    }
    else {
      *DAT_08016be8 = *DAT_08016be8 + 1;
      if (*(ushort *)(DAT_08016be0 + 0x28) <= *puVar1) {
        *(byte *)(DAT_08016bdc + 6) = *(byte *)(DAT_08016bdc + 6) & 0xfb;
        *DAT_08016be8 = 0;
      }
    }
  }
  return;
}



/* ===== FUN_08016bec @ 0x8016BEC ===== */

void FUN_08016bec(void)

{
  ushort *puVar1;
  
  puVar1 = DAT_08016ca4;
  if (((*DAT_08016c94 == '\x01') && (99 < *(uint *)(DAT_08016c98 + 4))) &&
     (-1 < (int)((uint)*(byte *)(DAT_08016c9c + 6) << 0x1b))) {
    if (*(char *)(DAT_08016ca0 + 0x2a) < *(char *)(DAT_08016c9c + 1)) {
      *DAT_08016ca4 = 0;
    }
    else {
      *DAT_08016ca4 = *DAT_08016ca4 + 1;
      if (*(ushort *)(DAT_08016ca0 + 0x2b) <= *puVar1) {
        *(byte *)(DAT_08016c9c + 6) = (*(byte *)(DAT_08016c9c + 6) & 0xef) + 0x10;
        *DAT_08016ca4 = 0;
      }
    }
  }
  puVar1 = DAT_08016ca8;
  if ((int)((uint)*(byte *)(DAT_08016c9c + 6) << 0x1b) < 0) {
    if (*(char *)(DAT_08016c9c + 1) < *(char *)(DAT_08016ca0 + 0x2d)) {
      *DAT_08016ca8 = 0;
    }
    else {
      *DAT_08016ca8 = *DAT_08016ca8 + 1;
      if (*(ushort *)(DAT_08016ca0 + 0x2e) <= *puVar1) {
        *(byte *)(DAT_08016c9c + 6) = *(byte *)(DAT_08016c9c + 6) & 0xef;
        *DAT_08016ca8 = 0;
      }
    }
  }
  return;
}



/* ===== FUN_08016cac @ 0x8016CAC ===== */

void FUN_08016cac(void)

{
  ushort *puVar1;
  
  puVar1 = DAT_08016d50;
  if (*DAT_08016d44 == '\x01') {
    if (-1 < (int)((uint)*(byte *)(DAT_08016d48 + 8) << 0x1d)) {
      if (*(uint *)(DAT_08016d48 + 4) < *(uint *)(DAT_08016d4c + 0x26)) {
        *DAT_08016d50 = 0;
      }
      else {
        *DAT_08016d50 = *DAT_08016d50 + 1;
        if (*(ushort *)(DAT_08016d4c + 0x2a) <= *puVar1) {
          *(byte *)(DAT_08016d48 + 8) = (*(byte *)(DAT_08016d48 + 8) & 0xfb) + 4;
          *DAT_08016d50 = 0;
        }
      }
    }
  }
  else {
    *DAT_08016d50 = 0;
  }
  if ((((int)((uint)*(byte *)(DAT_08016d48 + 8) << 0x1d) < 0) &&
      (*DAT_08016d54 = *DAT_08016d54 + 1,
      *(uint *)(DAT_08016d48 + 4) <= (uint)*(ushort *)(DAT_08016d4c + 0x2c))) &&
     (*(ushort *)(DAT_08016d4c + 0x2e) <= *DAT_08016d54)) {
    *DAT_08016d54 = 0;
    *(byte *)(DAT_08016d48 + 8) = *(byte *)(DAT_08016d48 + 8) & 0xfb;
  }
  return;
}



/* ===== FUN_08016d58 @ 0x8016D58 ===== */

void FUN_08016d58(void)

{
  ushort *puVar1;
  ushort *puVar2;
  
  puVar2 = DAT_08016df4;
  puVar1 = DAT_08016df0;
  if ((*(byte *)(DAT_08016de8 + 9) & 1) == 0) {
    if (*(char *)(DAT_08016de8 + 8) < *(char *)(DAT_08016dec + 0x36)) {
      *DAT_08016df0 = 0;
    }
    else {
      *DAT_08016df0 = *DAT_08016df0 + 1;
      if (*(ushort *)(DAT_08016dec + 0x37) <= *puVar1) {
        *(byte *)(DAT_08016de8 + 9) = (*(byte *)(DAT_08016de8 + 9) & 0xfe) + 1;
        *DAT_08016df0 = 0;
      }
    }
  }
  else if (*(char *)(DAT_08016dec + 0x39) < *(char *)(DAT_08016de8 + 8)) {
    *DAT_08016df4 = 0;
  }
  else {
    *DAT_08016df4 = *DAT_08016df4 + 1;
    if (*(ushort *)(DAT_08016dec + 0x3a) <= *puVar2) {
      *(byte *)(DAT_08016de8 + 9) = *(byte *)(DAT_08016de8 + 9) & 0xfe;
      *DAT_08016df4 = 0;
    }
  }
  return;
}



/* ===== FUN_08016df8 @ 0x8016DF8 ===== */

void FUN_08016df8(void)

{
  ushort *puVar1;
  
  puVar1 = DAT_08016ec4;
  if (((*DAT_08016eb8 == '\x01') || (*DAT_08016eb8 == '\x02')) &&
     (-1 < (int)((uint)*(byte *)(DAT_08016ebc + 0xc) << 0x1a))) {
    if (*(ushort *)(DAT_08016ec0 + 0x1c) < *(ushort *)(DAT_08016ebc + 4)) {
      *DAT_08016ec4 = 0;
    }
    else {
      *DAT_08016ec4 = *DAT_08016ec4 + 1;
      if (*(ushort *)(DAT_08016ec0 + 0x20) <= *puVar1) {
        *(byte *)(DAT_08016ebc + 0xc) = (*(byte *)(DAT_08016ebc + 0xc) & 0xdf) + 0x20;
        *DAT_08016ec4 = 0;
      }
    }
  }
  puVar1 = DAT_08016ecc;
  if ((int)((uint)*(byte *)(DAT_08016ebc + 0xc) << 0x1a) < 0) {
    if ((*DAT_08016eb8 == '\0') && (99 < *(uint *)(DAT_08016ec8 + 4))) {
      *(byte *)(DAT_08016ebc + 0xc) = *(byte *)(DAT_08016ebc + 0xc) & 0xdf;
      *DAT_08016ecc = 0;
    }
    else if (*(ushort *)(DAT_08016ebc + 4) < *(ushort *)(DAT_08016ec0 + 0x1e)) {
      *DAT_08016ecc = 0;
    }
    else {
      *DAT_08016ecc = *DAT_08016ecc + 1;
      if (*(ushort *)(DAT_08016ec0 + 0x22) <= *puVar1) {
        *(byte *)(DAT_08016ebc + 0xc) = *(byte *)(DAT_08016ebc + 0xc) & 0xdf;
        *DAT_08016ecc = 0;
      }
    }
  }
  return;
}



/* ===== FUN_08016ed0 @ 0x8016ED0 ===== */

void FUN_08016ed0(void)

{
  byte *pbVar1;
  int iVar2;
  
  if (*DAT_08016f40 == '\0') {
    if ((*DAT_08016f44 == '\x01') && (*DAT_08016f48 == '\0')) {
      *DAT_08016f40 = '\x01';
    }
  }
  else if (*DAT_08016f40 == '\x01') {
    iVar2 = FUN_0800ae14();
    pbVar1 = DAT_08016f4c;
    if (iVar2 == 1) {
      *DAT_08016f40 = '\0';
      *DAT_08016f4c = 0;
    }
    else if (*DAT_08016f48 == '\0') {
      *DAT_08016f4c = 0;
    }
    else {
      *DAT_08016f4c = *DAT_08016f4c + 1;
      if (0x32 < *pbVar1) {
        *pbVar1 = 0;
        *DAT_08016f40 = '\0';
      }
    }
  }
  else {
    *DAT_08016f40 = '\0';
  }
  return;
}



/* ===== FUN_08016f50 @ 0x8016F50 ===== */

void FUN_08016f50(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  bool bVar2;
  ushort *puVar3;
  byte *pbVar4;
  undefined2 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 local_18;
  undefined4 local_14;
  
  bVar2 = false;
  cVar1 = *DAT_08017350;
  local_18 = param_3;
  local_14 = param_4;
  if (cVar1 == '\0') {
    *DAT_0801735c = 0;
    puVar3 = DAT_08017354;
    if ((*DAT_08017358 & 1) != 0) {
      *DAT_08017354 = *DAT_08017354 + 1;
      if ((((int)((uint)(byte)*DAT_08017358 << 0x18) < 0) && (100 < (uint)DAT_08017368[1])) &&
         (9 < *puVar3)) {
        *DAT_0801736c = 0;
        FUN_0800aa90(&local_18);
        puVar6 = DAT_08017370;
        *DAT_08017370 = local_18;
        *(undefined2 *)(puVar6 + 1) = (undefined2)local_14;
        *(undefined1 *)((int)puVar6 + 6) = local_14._2_1_;
        *(undefined1 *)((int)DAT_0801736c + 7) = *(undefined1 *)((int)puVar6 + 5);
        *(undefined1 *)(DAT_0801736c + 3) = *(undefined1 *)(DAT_08017370 + 1);
        *(undefined1 *)((int)DAT_0801736c + 5) = *(undefined1 *)((int)DAT_08017370 + 3);
        *(undefined1 *)(DAT_0801736c + 2) = *(undefined1 *)((int)DAT_08017370 + 2);
        *(undefined1 *)((int)DAT_0801736c + 3) = *(undefined1 *)((int)DAT_08017370 + 1);
        *(undefined1 *)(DAT_0801736c + 1) = *(undefined1 *)DAT_08017370;
        FUN_0800f84c();
        puVar5 = DAT_0801736c;
        *(undefined4 *)(DAT_0801736c + 4) = *DAT_08017374;
        puVar5[6] = *(undefined2 *)(DAT_08017374 + 2);
        puVar5[7] = *(undefined2 *)((int)DAT_08017374 + 6);
        *(undefined4 *)(puVar5 + 8) = *DAT_08017368;
        *(undefined1 *)(puVar5 + 10) = *(undefined1 *)(DAT_08017378 + 2);
        *(undefined1 *)((int)puVar5 + 0x15) = *(undefined1 *)(DAT_08017378 + 1);
        puVar5[0xb] = *(undefined2 *)(DAT_08017360 + 2);
        *(undefined4 *)(puVar5 + 0xc) = *(undefined4 *)(DAT_08017360 + 0xc);
        *(undefined4 *)(puVar5 + 0xe) = *(undefined4 *)(DAT_08017360 + 8);
        puVar5 = DAT_0801736c;
        if (((int)((uint)*(byte *)(DAT_08017378 + 6) << 0x19) < 0) ||
           ((int)((uint)*(byte *)(DAT_08017378 + 9) << 0x1c) < 0)) {
          iVar7 = 1;
        }
        else {
          iVar7 = 0;
        }
        *(uint *)(DAT_0801736c + 0x10) =
             *(byte *)(DAT_08017374 + 3) & 1 | *(byte *)(DAT_08017374 + 3) & 2 |
             (*(byte *)((int)DAT_08017374 + 0x17) & 1) << 2 | *(byte *)(DAT_08017374 + 3) & 8 |
             *(byte *)(DAT_08017374 + 3) & 0x10 | ((*(byte *)(DAT_08017374 + 3) & 0x7f) >> 6) << 5 |
             (*(byte *)(DAT_0801737c + 2) & 1) << 7 | (*(byte *)(DAT_08017368 + 2) & 1) << 8 |
             ((*(byte *)(DAT_08017368 + 2) & 3) >> 1) << 9 |
             ((*(byte *)(DAT_08017368 + 2) & 0xf) >> 3) << 10 |
             ((*(byte *)(DAT_08017368 + 2) & 0x1f) >> 4) << 0xb |
             ((*(byte *)(DAT_08017368 + 2) & 0x3f) >> 5) << 0xc |
             ((*(byte *)(DAT_08017368 + 2) & 0x7f) >> 6) << 0xe |
             (*(byte *)(DAT_08017378 + 6) & 1) << 0xf |
             ((*(byte *)(DAT_08017378 + 6) & 3) >> 1) << 0x11 |
             ((*(byte *)(DAT_08017378 + 6) & 0xf) >> 3) << 0x13 |
             ((*(byte *)(DAT_08017378 + 6) & 0x3f) >> 5) << 0x15 |
             ((*(byte *)(DAT_08017378 + 9) & 3) >> 1) << 0x17 | iVar7 << 0x18 |
             (uint)(*(byte *)(DAT_08017374 + 3) >> 7) << 0x19 |
             ((*(byte *)(DAT_0801737c + 2) & 3) >> 1) << 0x1a |
             ((*(byte *)(DAT_0801737c + 2) & 7) >> 2) << 0x1b |
             ((*(byte *)(DAT_0801737c + 2) & 0xf) >> 3) << 0x1c |
             ((*(byte *)(DAT_0801737c + 3) & 0x1f) >> 4) << 0x1d |
             ((*(byte *)(DAT_0801737c + 3) & 7) >> 2) << 0x1e |
             (uint)(*(byte *)(DAT_0801737c + 3) >> 3) << 0x1f;
        puVar5[0x12] = 0;
        puVar5[0x13] = 0;
        *DAT_08017358 = *DAT_08017358 & 0xff7f;
      }
      puVar3 = DAT_08017358;
      if (0x707 < *DAT_08017354) {
        *DAT_08017358 = *DAT_08017358 & 0xfffe;
        *puVar3 = *puVar3 | 2;
        *DAT_08017380 = *DAT_08017380 | 0x200;
        *(short *)(DAT_0801737c + 7) = *(short *)(DAT_0801737c + 7) + 1;
        FUN_0800f938(0);
        *DAT_08017354 = 0;
      }
    }
  }
  else if ((cVar1 == '\x01') || (cVar1 == '\x02')) {
    *DAT_08017354 = 0;
    puVar3 = DAT_08017358;
    *DAT_08017358 = *DAT_08017358 | 0x80;
    pbVar4 = DAT_0801735c;
    if (((int)((uint)(byte)*puVar3 << 0x1e) < 0) && (*DAT_0801735c = *DAT_0801735c + 1, 4 < *pbVar4)
       ) {
      *pbVar4 = 0;
      puVar3 = DAT_08017358;
      *DAT_08017358 = *DAT_08017358 & 0xfffd;
      *puVar3 = *puVar3 | 1;
      *puVar3 = *puVar3 | 4;
      FUN_0800f938(1);
      bVar2 = true;
      if (-1 < (int)((uint)(byte)*DAT_08017358 << 0x1c)) {
        *DAT_08017358 = *DAT_08017358 | 8;
      }
    }
    pbVar4 = DAT_08017364;
    if ((int)((uint)(byte)*DAT_08017358 << 0x1c) < 0) {
      if (*DAT_08017360 < 0x1f) {
        *DAT_08017364 = *DAT_08017364 + 1;
        puVar3 = DAT_08017358;
        if ((10 < *pbVar4) && (!bVar2)) {
          *DAT_08017358 = *DAT_08017358 & 0xfff7;
          *puVar3 = *puVar3 | 1;
          *puVar3 = *puVar3 | 4;
          FUN_0800f938(3);
          *DAT_08017364 = 0;
          bVar2 = true;
        }
      }
      else {
        *DAT_08017364 = 0;
      }
    }
  }
  else {
    *DAT_08017354 = 0;
    *DAT_0801735c = 0;
  }
  if (((int)((uint)*(byte *)(DAT_08017574 + 6) << 0x19) < 0) ||
     ((int)((uint)*(byte *)(DAT_08017574 + 9) << 0x1c) < 0)) {
    iVar7 = 1;
  }
  else {
    iVar7 = 0;
  }
  if ((*DAT_08017580 <
       (*(byte *)(DAT_08017374 + 3) & 1 | *(byte *)(DAT_08017374 + 3) & 2 |
        (*(byte *)((int)DAT_08017374 + 0x17) & 1) << 2 | *(byte *)(DAT_08017374 + 3) & 8 |
        *(byte *)(DAT_08017374 + 3) & 0x10 | ((*(byte *)(DAT_08017374 + 3) & 0x7f) >> 6) << 5 |
        (*(byte *)(DAT_0801737c + 2) & 1) << 7 | (*(byte *)(DAT_08017368 + 2) & 1) << 8 |
        ((*(byte *)(DAT_08017368 + 2) & 3) >> 1) << 9 |
        ((*(byte *)(DAT_08017368 + 2) & 0xf) >> 3) << 10 |
        ((*(byte *)(DAT_08017368 + 2) & 0x1f) >> 4) << 0xb |
        ((*(byte *)(DAT_08017368 + 2) & 0x3f) >> 5) << 0xc |
        ((*(byte *)(DAT_08017368 + 2) & 0x7f) >> 6) << 0xe |
        (*(byte *)(DAT_08017378 + 6) & 1) << 0xf | ((*(byte *)(DAT_08017378 + 6) & 3) >> 1) << 0x11
        | ((*(byte *)(DAT_08017574 + 6) & 0xf) >> 3) << 0x13 |
        ((*(byte *)(DAT_08017574 + 6) & 0x3f) >> 5) << 0x15 |
        ((*(byte *)(DAT_08017574 + 9) & 3) >> 1) << 0x17 | iVar7 << 0x18 |
        (uint)(*(byte *)(DAT_08017578 + 0xc) >> 7) << 0x19 |
        ((*(byte *)(DAT_0801757c + 2) & 3) >> 1) << 0x1a |
        ((*(byte *)(DAT_0801757c + 2) & 7) >> 2) << 0x1b |
        ((*(byte *)(DAT_0801757c + 2) & 0xf) >> 3) << 0x1c |
        ((*(byte *)(DAT_0801757c + 3) & 0x1f) >> 4) << 0x1d |
        ((*(byte *)(DAT_0801757c + 3) & 7) >> 2) << 0x1e |
       (uint)(*(byte *)(DAT_0801757c + 3) >> 3) << 0x1f)) && (!bVar2)) {
    FUN_0800f938(4);
  }
  if (((int)((uint)*(byte *)(DAT_08017574 + 6) << 0x19) < 0) ||
     ((int)((uint)*(byte *)(DAT_08017574 + 9) << 0x1c) < 0)) {
    iVar7 = 1;
  }
  else {
    iVar7 = 0;
  }
  *DAT_08017580 =
       *(byte *)(DAT_08017578 + 0xc) & 1 | *(byte *)(DAT_08017578 + 0xc) & 2 |
       (*(byte *)(DAT_08017578 + 0x17) & 1) << 2 | *(byte *)(DAT_08017578 + 0xc) & 8 |
       *(byte *)(DAT_08017578 + 0xc) & 0x10 | ((*(byte *)(DAT_08017578 + 0xc) & 0x7f) >> 6) << 5 |
       (*(byte *)(DAT_0801757c + 2) & 1) << 7 | (*(byte *)(DAT_08017584 + 8) & 1) << 8 |
       ((*(byte *)(DAT_08017584 + 8) & 3) >> 1) << 9 |
       ((*(byte *)(DAT_08017584 + 8) & 0xf) >> 3) << 10 |
       ((*(byte *)(DAT_08017584 + 8) & 0x1f) >> 4) << 0xb |
       ((*(byte *)(DAT_08017584 + 8) & 0x3f) >> 5) << 0xc |
       ((*(byte *)(DAT_08017584 + 8) & 0x7f) >> 6) << 0xe | (*(byte *)(DAT_08017574 + 6) & 1) << 0xf
       | ((*(byte *)(DAT_08017574 + 6) & 3) >> 1) << 0x11 |
       ((*(byte *)(DAT_08017574 + 6) & 0xf) >> 3) << 0x13 |
       ((*(byte *)(DAT_08017574 + 6) & 0x3f) >> 5) << 0x15 |
       ((*(byte *)(DAT_08017574 + 9) & 3) >> 1) << 0x17 | iVar7 << 0x18 |
       (uint)(*(byte *)(DAT_08017578 + 0xc) >> 7) << 0x19 |
       ((*(byte *)(DAT_0801757c + 2) & 3) >> 1) << 0x1a |
       ((*(byte *)(DAT_0801757c + 2) & 7) >> 2) << 0x1b |
       ((*(byte *)(DAT_0801757c + 2) & 0xf) >> 3) << 0x1c |
       ((*(byte *)(DAT_0801757c + 3) & 0x1f) >> 4) << 0x1d |
       ((*(byte *)(DAT_0801757c + 3) & 7) >> 2) << 0x1e |
       (uint)(*(byte *)(DAT_0801757c + 3) >> 3) << 0x1f;
  return;
}



/* ===== FUN_08017588 @ 0x8017588 ===== */

void FUN_08017588(undefined1 *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_2;
  if (param_2 < 1) {
    iVar1 = -param_2;
  }
  if (iVar1 < param_3) {
    *param_1 = 2;
  }
  else if (param_2 < 1) {
    *param_1 = 1;
  }
  else {
    *param_1 = 0;
  }
  return;
}



/* ===== FUN_080175ac @ 0x80175AC ===== */

undefined8 FUN_080175ac(undefined4 param_1,undefined2 param_2,undefined4 param_3,char param_4)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  bool bVar4;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  
  local_1c = 0;
  local_18 = CONCAT13((char)((uint)param_3 >> 8),CONCAT12((char)param_3,param_2));
  local_20 = (uint)(byte)(param_4 + 2);
  iVar2 = FUN_08003e72(param_1,0x3e,1,&local_18);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    local_20 = 1000;
    do {
      bVar4 = local_20 != 0;
      local_20 = local_20 + -1;
    } while (bVar4);
    uVar1 = FUN_080068d8(&local_18,param_4 + '\x02');
    local_1c._0_2_ = CONCAT11(param_4 + '\x04',uVar1);
    local_20 = 2;
    iVar2 = FUN_08003e72(param_1,0x60,1,&local_1c);
    if (iVar2 == 0) {
      uVar3 = 0;
    }
    else {
      local_20 = 1000;
      do {
        bVar4 = local_20 != 0;
        local_20 = local_20 + -1;
      } while (bVar4);
      uVar3 = 1;
      local_20 = 0xffffffff;
    }
  }
  return CONCAT44(local_20,uVar3);
}



/* ===== FUN_08017640 @ 0x8017640 ===== */

void FUN_08017640(undefined1 param_1,undefined1 param_2,undefined1 *param_3,undefined1 *param_4,
                 int param_5)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = FUN_08005c7c(param_1,0);
  uVar1 = FUN_08005c7c(param_2,uVar1);
  for (uVar2 = 0; (int)uVar2 < param_5; uVar2 = uVar2 + 1 & 0xff) {
    if (uVar2 == 0) {
      *param_4 = *param_3;
      uVar1 = FUN_08005c7c(*param_3,uVar1);
      param_4[1] = (char)uVar1;
    }
    else {
      param_4[uVar2 * 2] = param_3[uVar2];
      uVar1 = FUN_08005c7c(param_3[uVar2],0);
      param_4[uVar2 * 2 + 1] = (char)uVar1;
    }
  }
  return;
}



/* ===== FUN_080176ac @ 0x80176AC ===== */

undefined4 FUN_080176ac(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_60 [32];
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined1 auStack_30 [29];
  byte local_13;
  undefined2 local_12;
  
  bVar1 = 0;
  while ((bVar1 < 3 && (iVar2 = FUN_0800cb0c(&local_40), iVar2 != 1))) {
    bVar1 = bVar1 + 1;
  }
  local_13 = (byte)(((uint)*(byte *)(DAT_08017708 + 2) << 0x1e) >> 0x1f);
  local_12 = FUN_0800aa50(&local_13,1);
  FUN_080031a4(auStack_60,auStack_30,0x20);
  uVar3 = FUN_0800cccc(local_40,uStack_3c,uStack_38,uStack_34);
  return uVar3;
}



/* ===== FUN_0801770c @ 0x801770C ===== */

int FUN_0801770c(void)

{
  undefined4 uVar1;
  int iVar2;
  bool bVar3;
  undefined4 local_10;
  
  FUN_0800a2f0(0x20000);
  uVar1 = FUN_0800aa50(DAT_08017754,0xc);
  *(undefined4 *)(DAT_08017754 + 0xc) = uVar1;
  iVar2 = FUN_0800a4a0(DAT_08017754,0x20000);
  if (iVar2 == 0) {
    local_10 = 1000;
    do {
      bVar3 = local_10 != 0;
      local_10 = local_10 + -1;
    } while (bVar3);
    iVar2 = FUN_0800a4a0(DAT_08017754,0x20000);
  }
  return iVar2;
}



/* ===== FUN_08017758 @ 0x8017758 ===== */

void FUN_08017758(void)

{
  FUN_080031d6(DAT_08017788,0x80c);
  FUN_080031c8(DAT_0801778c,0x800,0xff);
  FUN_080031c8(DAT_08017788,0x800,0xff);
  *(undefined4 *)(DAT_08017788 + 0x804) = 0x800;
  return;
}



/* ===== FUN_080177e0 @ 0x80177E0 ===== */

undefined4 FUN_080177e0(void)

{
  uint *puVar1;
  int iVar2;
  char cVar3;
  uint uVar4;
  bool bVar5;
  int local_18;
  
  puVar1 = DAT_080178ec;
  cVar3 = '\x03';
  if ((((DAT_080178ec[1] < 0x21000) || (DAT_080178f0 < DAT_080178ec[1])) ||
      (DAT_080178ec[2] < 0x21000)) || (DAT_080178f0 < DAT_080178ec[2])) {
    *DAT_080178ec = 0;
    puVar1[1] = 0x21000;
    puVar1[2] = 0x21000;
  }
  if ((DAT_080178ec[2] & 0xfff) == 0) {
    FUN_0800a2f0(DAT_080178ec[2]);
    local_18 = 1000;
    do {
      bVar5 = local_18 != 0;
      local_18 = local_18 + -1;
    } while (bVar5);
  }
  do {
    bVar5 = cVar3 == '\0';
    cVar3 = cVar3 + -1;
    if ((bVar5) || (iVar2 = FUN_0800a4a0(DAT_080178f4,DAT_080178ec[2],0x28), iVar2 == 1)) {
      puVar1 = DAT_080178ec;
      *DAT_080178ec = *DAT_080178ec + 1;
      if (500 < *puVar1) {
        *puVar1 = 0;
        puVar1[1] = puVar1[1] + 0x28;
        if (DAT_080178f0 <= puVar1[1]) {
          DAT_080178ec[1] = 0x21000;
        }
        for (uVar4 = 0; uVar4 < 0x26; uVar4 = uVar4 + 1 & 0xffff) {
          FUN_0800a2f0(uVar4 * 0x1000 + 0x21000);
        }
      }
      puVar1 = DAT_080178ec;
      DAT_080178ec[2] = DAT_080178ec[2] + 0x28;
      if (DAT_080178f0 <= puVar1[2]) {
        DAT_080178ec[2] = 0x21000;
      }
      FUN_0801770c();
      return 1;
    }
    local_18 = 500;
    do {
      bVar5 = local_18 != 0;
      local_18 = local_18 + -1;
    } while (bVar5);
  } while (cVar3 != '\0');
  return 0;
}



/* ===== FUN_080178f8 @ 0x80178F8 ===== */

void FUN_080178f8(void)

{
  *DAT_08017910 = 1;
  FUN_08017ffc(10);
  *(undefined1 *)(DAT_08017914 + 3) = 1;
  return;
}



/* ===== FUN_08017918 @ 0x8017918 ===== */

void FUN_08017918(void)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  undefined4 local_18 [2];
  
  local_18[0] = DAT_08017a0c;
  local_18[1] = DAT_08017a10;
  uVar4 = 0;
  uVar1 = FUN_08005bc4(*(undefined2 *)(DAT_08017a18 + 4),DAT_08017a14 + 3,
                       *(undefined1 *)(DAT_08017a14 + 0x99));
  iVar2 = DAT_08017a18;
  *(undefined2 *)(DAT_08017a18 + 4) = uVar1;
  if (*(char *)(DAT_08017a14 + 1) == '\x01') {
    for (uVar5 = 0; uVar3 = FUN_080031ec(local_18), uVar5 < uVar3; uVar5 = uVar5 + 1 & 0xff) {
      if (*(char *)((int)local_18 + uVar5) != *(char *)(DAT_08017a14 + 3 + uVar4)) {
        iVar2 = FUN_080031ec(local_18);
        if (iVar2 - 1U == uVar5) {
          *(undefined1 *)(DAT_08017a18 + 3) = 7;
          return;
        }
        *(undefined1 *)(DAT_08017a18 + 3) = 6;
        return;
      }
      uVar4 = uVar4 + 1 & 0xffff;
    }
    *(uint *)(DAT_08017a18 + 0x18) =
         (uint)*(byte *)(DAT_08017a14 + 3 + uVar4) << 0x18 |
         (uint)*(byte *)(DAT_08017a14 + uVar4 + 4) << 0x10 |
         (uint)*(byte *)(DAT_08017a14 + uVar4 + 5) << 8 | (uint)*(byte *)(DAT_08017a14 + uVar4 + 6);
    uVar4 = uVar4 + 4 & 0xffff;
    *(ushort *)(DAT_08017a18 + 0x1c) =
         CONCAT11(*(undefined1 *)(DAT_08017a14 + 3 + uVar4),
                  *(undefined1 *)(DAT_08017a14 + uVar4 + 4));
    if ((*(ushort *)(DAT_08017a18 + 0x18) & 0x7ff) == 0) {
      *(undefined1 *)(DAT_08017a18 + 3) = 2;
    }
    else {
      *(undefined1 *)(DAT_08017a18 + 3) = 6;
    }
  }
  else {
    *(undefined1 *)(iVar2 + 3) = 2;
  }
  return;
}



/* ===== FUN_08017a1c @ 0x8017A1C ===== */

void FUN_08017a1c(void)

{
  int iVar1;
  
  iVar1 = DAT_08017a58;
  *(undefined1 *)(DAT_08017a58 + 3) = 0;
  *(undefined2 *)(iVar1 + 6) = 0;
  *(undefined2 *)(iVar1 + 8) = 0;
  *(undefined2 *)(iVar1 + 10) = 0xff;
  *(undefined2 *)(iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined2 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined2 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x1e) = 0;
  *(undefined4 *)(iVar1 + 0x22) = 0;
  *(undefined2 *)(iVar1 + 0x26) = 0;
  iVar1 = DAT_08017a58;
  *(undefined2 *)(DAT_08017a58 + 0xc) = 0;
  *(undefined2 *)(iVar1 + 0xe) = 0;
  *DAT_08017a5c = 0;
  FUN_08017758();
  return;
}



/* ===== FUN_08017a60 @ 0x8017A60 ===== */

undefined4 FUN_08017a60(char *param_1,int param_2)

{
  int iVar1;
  char *pcVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  if (param_2 < 0x100) {
    if (param_2 < 0x33) {
      for (uVar5 = 0; uVar5 < 7; uVar5 = uVar5 + 1 & 0xff) {
        uVar3 = FUN_080031ec(DAT_08017b78 + uVar5 * 0x32);
        iVar4 = FUN_080031fa(param_1,DAT_08017b78 + uVar5 * 0x32,uVar3);
        iVar1 = DAT_08017b7c;
        if (iVar4 == 0) {
          *(undefined1 *)(DAT_08017b7c + 1) = 0;
          *(char *)(iVar1 + 2) = (char)uVar5;
          return 1;
        }
      }
    }
    FUN_080031d6(DAT_08017b80,0x9c);
    pcVar2 = DAT_08017b80;
    *DAT_08017b80 = *param_1;
    if (*pcVar2 == '\x01') {
      DAT_08017b80[1] = param_1[1];
      DAT_08017b80[2] = param_1[2];
      pcVar2 = DAT_08017b80;
      *(ushort *)(DAT_08017b80 + 0x9a) = CONCAT11(param_1[param_2 + -2],param_1[param_2 + -1]);
      pcVar2[0x99] = (char)param_2 + -5;
      if ((byte)pcVar2[0x99] < 0x96) {
        FUN_080031a4(DAT_08017b80 + 3,param_1 + 3,DAT_08017b80[0x99]);
        uVar5 = FUN_08005b82(DAT_08017b80 + 3,DAT_08017b80[0x99]);
        if ((DAT_08017b80[1] == ~DAT_08017b80[2]) && (*(ushort *)(DAT_08017b80 + 0x9a) == uVar5)) {
          uVar3 = 1;
          *(undefined1 *)(DAT_08017b7c + 1) = 1;
        }
        else {
          uVar3 = 0;
        }
      }
      else {
        uVar3 = 0;
      }
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}



/* ===== FUN_08017b84 @ 0x8017B84 ===== */

undefined4 FUN_08017b84(void)

{
  char cVar1;
  int iVar2;
  
  FUN_080178f8();
  if (DAT_08017c70[1] == '\0') {
    if (DAT_08017c70[2] == '\0') {
      DAT_08017c70[3] = '\x04';
    }
    else if (DAT_08017c70[2] == '\x02') {
      DAT_08017c70[3] = '\0';
    }
    else if (DAT_08017c70[2] == '\x01') {
      DAT_08017c70[3] = '\x05';
    }
    else if (DAT_08017c70[2] == '\x03') {
      DAT_08017c70[3] = '\0';
      *DAT_08017c74 = 1;
    }
    else if (DAT_08017c70[2] == '\x04') {
      DAT_08017c70[3] = '\0';
    }
    else if (DAT_08017c70[2] == '\x05') {
      DAT_08017c70[3] = '\0';
    }
    else if (DAT_08017c70[2] == '\x06') {
      DAT_08017c70[3] = '\x02';
    }
    else {
      DAT_08017c70[3] = '\x06';
    }
  }
  else if (DAT_08017c70[1] == '\x01') {
    *DAT_08017c74 = 0;
    iVar2 = FUN_08017f00();
    if (iVar2 == 0) {
      return 1;
    }
    cVar1 = *DAT_08017c70;
    if (cVar1 == '\x01') {
      FUN_08017d14();
    }
    else if (cVar1 == '\x02') {
      FUN_08017918();
    }
    else if (cVar1 == '\x03') {
      FUN_08017df4();
      if (*DAT_08017c78 == '\x01') {
        return 0;
      }
    }
    else {
      *DAT_08017c70 = '\0';
    }
    FUN_08017fc8();
  }
  else {
    DAT_08017c70[3] = '\x03';
  }
  return 1;
}



/* ===== FUN_08017c7c @ 0x8017C7C ===== */

undefined1 FUN_08017c7c(void)

{
  return *DAT_08017c84;
}



/* ===== FUN_08017c88 @ 0x8017C88 ===== */

undefined1 FUN_08017c88(void)

{
  return *DAT_08017c90;
}



/* ===== FUN_08017c94 @ 0x8017C94 ===== */

void FUN_08017c94(int param_1,undefined1 *param_2)

{
  uint uVar1;
  uint uVar2;
  
  for (uVar2 = 0; uVar1 = FUN_080031ec(DAT_08017cdc + (uint)*(byte *)(DAT_08017cd8 + 3) * 0x32),
      uVar2 < uVar1; uVar2 = uVar2 + 1) {
    *(undefined1 *)(param_1 + uVar2) =
         *(undefined1 *)(DAT_08017cdc + (uint)*(byte *)(DAT_08017cd8 + 3) * 0x32 + uVar2);
  }
  *param_2 = (char)uVar2;
  return;
}



/* ===== FUN_08017ce0 @ 0x8017CE0 ===== */

void FUN_08017ce0(void)

{
  byte *pbVar1;
  
  pbVar1 = DAT_08017d10;
  if (*DAT_08017d0c == '\0') {
    *DAT_08017d10 = 0;
  }
  else {
    *DAT_08017d10 = *DAT_08017d10 + 1;
    if (2 < *pbVar1) {
      FUN_0800f878();
      FUN_0800fd80();
    }
  }
  return;
}



/* ===== FUN_08017d14 @ 0x8017D14 ===== */

void FUN_08017d14(void)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  iVar1 = DAT_08017df0;
  if (*(char *)(DAT_08017dec + 1) == '\x01') {
    *(uint *)(DAT_08017df0 + 0x10) =
         (uint)*(byte *)(DAT_08017dec + 0xf) << 0x18 | (uint)*(byte *)(DAT_08017dec + 0x10) << 0x10
         | (uint)*(byte *)(DAT_08017dec + 0x11) << 8 | (uint)*(byte *)(DAT_08017dec + 0x12);
    *(short *)(iVar1 + 10) = (short)((uint)(*(int *)(iVar1 + 0x10) << 5) >> 0x10);
    *(ushort *)(DAT_08017df0 + 0x14) =
         CONCAT11(*(undefined1 *)(DAT_08017dec + 0x13),*(undefined1 *)(DAT_08017dec + 0x14));
    uVar2 = 0x12;
    for (uVar3 = 0; uVar3 < 10; uVar3 = uVar3 + 1 & 0xff) {
      if (*(char *)(DAT_08017dec + 3 + uVar2) == -1) {
        *(undefined1 *)(DAT_08017df0 + 0x1e + uVar3) = 0;
        break;
      }
      *(undefined1 *)(DAT_08017df0 + 0x1e + uVar3) = *(undefined1 *)(DAT_08017dec + 3 + uVar2);
      uVar2 = uVar2 + 1 & 0xffff;
    }
    if ((*(short *)(DAT_08017df0 + 10) == 0) && (0x66 < *(ushort *)(DAT_08017df0 + 10))) {
      *(undefined1 *)(DAT_08017df0 + 3) = 6;
    }
    else {
      *(undefined1 *)(DAT_08017df0 + 3) = 2;
    }
  }
  else {
    *(undefined1 *)(DAT_08017df0 + 3) = 2;
  }
  return;
}



/* ===== FUN_08017df4 @ 0x8017DF4 ===== */

void FUN_08017df4(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  undefined2 local_24 [2];
  undefined2 local_20;
  undefined4 local_18;
  uint local_14;
  
  iVar2 = DAT_08017ee8;
  *(undefined1 *)(DAT_08017ee8 + 3) = 3;
  iVar2 = FUN_080139e4((*(ushort *)(iVar2 + 0xc) - 2) * 0x800 +
                       (*(ushort *)(DAT_08017ee8 + 6) - 1) * 0x80,DAT_08017eec + 3,
                       *(undefined1 *)(DAT_08017eec + 0x99),0);
  if (iVar2 == 1) {
    *(undefined1 *)(DAT_08017ee8 + 3) = 2;
    uVar1 = FUN_08005bc4(*(undefined2 *)(DAT_08017ee8 + 4),DAT_08017eec + 3,
                         *(undefined1 *)(DAT_08017eec + 0x99));
    iVar2 = DAT_08017ee8;
    *(undefined2 *)(DAT_08017ee8 + 4) = uVar1;
    if (((uint)*(ushort *)(iVar2 + 0xc) == *(ushort *)(iVar2 + 10) + 1) &&
       (*(short *)(DAT_08017ee8 + 6) == 0x10)) {
      iVar2 = FUN_08005b82(DAT_08017ef0,(*(ushort *)(DAT_08017ee8 + 0xc) - 2) * 2);
      iVar3 = FUN_08005b82(DAT_08017ef4,(*(ushort *)(DAT_08017ee8 + 0xc) - 2) * 2);
      if ((*(short *)(DAT_08017ee8 + 4) == *(short *)(DAT_08017ee8 + 0x14)) && (iVar2 == iVar3)) {
        FUN_08009fb8(DAT_08017ef8,local_24,0x14);
        local_20 = (undefined2)iVar2;
        local_18 = *(undefined4 *)(DAT_08017ee8 + 0x18);
        local_24[0] = 1;
        iVar2 = FUN_08005b82(local_24,0x12);
        local_14 = local_14 & 0xffff | iVar2 << 0x10;
        iVar2 = FUN_0800a0ac(DAT_08017ef8,local_24,0x14);
        if (iVar2 == 0) {
          *(undefined1 *)(DAT_08017ee8 + 3) = 1;
        }
        else {
          *DAT_08017efc = 1;
          *(undefined1 *)(DAT_08017ee8 + 3) = 7;
        }
      }
      else {
        *(undefined1 *)(DAT_08017ee8 + 3) = 1;
      }
    }
  }
  return;
}



/* ===== FUN_08017f00 @ 0x8017F00 ===== */

undefined4 FUN_08017f00(void)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  
  if ((*(char *)(DAT_08017fbc + 1) == '\x01') && (*(short *)(DAT_08017fc0 + 0xc) == 0)) {
    FUN_08017a1c();
  }
  puVar1 = DAT_08017fc0;
  if (*DAT_08017fc4 == '\x01') {
    DAT_08017fc0[3] = 7;
    uVar2 = 0;
  }
  else if ((ushort)*(byte *)(DAT_08017fbc + 1) == *(ushort *)(DAT_08017fc0 + 8)) {
    DAT_08017fc0[3] = 2;
    uVar2 = 0;
  }
  else if ((uint)*(byte *)(DAT_08017fbc + 1) ==
           (uint)*(ushort *)(DAT_08017fc0 + 6) +
           ((int)(uint)*(ushort *)(DAT_08017fc0 + 6) >> 4) * -0x10 + 1) {
    *(ushort *)(DAT_08017fc0 + 6) = (ushort)*(byte *)(DAT_08017fbc + 1);
    if (*(short *)(puVar1 + 0xc) == 0) {
      *puVar1 = 1;
    }
    else if (*(short *)(DAT_08017fc0 + 0xc) == 1) {
      *DAT_08017fc0 = 2;
    }
    else if ((*(ushort *)(DAT_08017fc0 + 0xc) < 2) ||
            (*(ushort *)(DAT_08017fc0 + 10) < *(ushort *)(DAT_08017fc0 + 0xc))) {
      *DAT_08017fc0 = 0;
    }
    else {
      *DAT_08017fc0 = 3;
    }
    if (0xf < *(ushort *)(DAT_08017fc0 + 6)) {
      *(short *)(DAT_08017fc0 + 0xc) = *(short *)(DAT_08017fc0 + 0xc) + 1;
    }
    uVar2 = 1;
  }
  else {
    DAT_08017fc0[3] = 3;
    uVar2 = 0;
  }
  return uVar2;
}



/* ===== FUN_08017fc8 @ 0x8017FC8 ===== */

void FUN_08017fc8(void)

{
  char *pcVar1;
  
  pcVar1 = DAT_08017ff8;
  if ((DAT_08017ff8[3] == '\x02') &&
     (((*DAT_08017ff8 == '\x01' || (*DAT_08017ff8 == '\x02')) || (*DAT_08017ff8 == '\x03')))) {
    *(undefined2 *)(DAT_08017ff8 + 8) = *(undefined2 *)(DAT_08017ff8 + 6);
    *(undefined2 *)(pcVar1 + 0xe) = *(undefined2 *)(pcVar1 + 0xc);
  }
  return;
}



/* ===== FUN_08017ffc @ 0x8017FFC ===== */

void FUN_08017ffc(int param_1)

{
  if (param_1 != 0) {
    *DAT_08018034 = param_1;
  }
  if (*DAT_08018038 == '\x01') {
    if (*DAT_08018034 == 0) {
      *DAT_08018038 = '\0';
      FUN_08017a1c();
    }
    else {
      *DAT_08018034 = *DAT_08018034 + -1;
    }
  }
  else {
    *DAT_0801803c = 0;
  }
  return;
}



/* ===== FUN_08018040 @ 0x8018040 ===== */

uint FUN_08018040(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar4;
  char cVar5;
  undefined4 uVar6;
  longlong in_d0;
  undefined4 uVar7;
  undefined8 uVar8;
  uint local_20;
  uint uStack_1c;
  undefined4 uVar3;
  
  local_20 = (uint)in_d0;
  uStack_1c = (uint)((ulonglong)in_d0 >> 0x20);
  uVar1 = (uStack_1c & 0x7fffffff) >> 0x14;
  uVar4 = uVar1 - 0x3ff;
  uVar6 = (undefined4)DAT_08018140;
  uVar2 = (undefined4)((ulonglong)DAT_08018140 >> 0x20);
  uVar7 = (undefined4)DAT_08018148;
  uVar3 = (undefined4)((ulonglong)DAT_08018148 >> 0x20);
  if (0x13 < (int)uVar4) {
    cVar5 = 0x32 < uVar4;
    if (0x33 < (int)uVar4) {
      return local_20;
    }
    uVar1 = 0xffffffff >> (uVar1 - 0x413 & 0xff);
    if ((local_20 & uVar1) == 0) {
      return local_20;
    }
    uVar8 = FUN_0800348e(local_20,uStack_1c,uVar6,uVar2);
    FUN_08003494((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar7,uVar3);
    if (cVar5 != '\0') {
      return local_20;
    }
    if ((0 < (int)uStack_1c) && (uVar4 != 0x14)) {
      local_20 = (1 << (0x34 - uVar4 & 0xff)) + local_20;
    }
    return local_20 & ~uVar1;
  }
  cVar5 = '\x01';
  if ((int)uVar4 < 0) {
    uVar8 = FUN_08003346(local_20,uStack_1c,uVar6,uVar2);
    FUN_08003494((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar7,uVar3);
    if (cVar5 != '\0') {
      return local_20;
    }
    if (in_d0 < 0) {
      return 0;
    }
    if (uStack_1c == 0 && local_20 == 0) {
      return local_20;
    }
  }
  else {
    if ((uStack_1c & DAT_08018154 >> (uVar4 & 0xff)) == 0 && local_20 == 0) {
      return local_20;
    }
    uVar8 = FUN_08003346(local_20,uStack_1c,uVar6,uVar2);
    FUN_08003494((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),uVar7,uVar3);
    if (cVar5 != '\0') {
      return local_20;
    }
  }
  return 0;
}



/* ===== thunk_FUN_08018160 @ 0x8018158 ===== */

/* ARMCC scatter-loader copy routine identified by exact-byte reference matching. */

void thunk_FUN_08018160(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  for (; param_3 != 0; param_3 = param_3 + -4) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}



/* ===== FUN_08018160 @ 0x8018160 ===== */

void FUN_08018160(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  
  for (; param_3 != 0; param_3 = param_3 + -4) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    *param_2 = uVar1;
    param_2 = param_2 + 1;
  }
  return;
}



/* ===== armcc_scatterload_zeroinit @ 0x8018168 ===== */

/* ARMCC scatter-loader zero-init routine identified by exact-byte reference matching. */

void armcc_scatterload_zeroinit(undefined4 param_1,undefined4 *param_2,int param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -4) {
    *param_2 = 0;
    param_2 = param_2 + 1;
  }
  return;
}



/* ===== FUN_08018176 @ 0x8018176 ===== */

void FUN_08018176(int param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  while (1 < param_4 - uVar2) {
    uVar1 = param_3;
    if (param_1 < *(short *)(param_2 + param_3 * 2)) {
      uVar1 = uVar2;
      param_4 = param_3;
    }
    param_3 = param_4 + uVar1 >> 1;
    uVar2 = uVar1;
  }
  return;
}



/* ===== FUN_0801819e @ 0x801819E ===== */

void FUN_0801819e(int param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 0;
  while (1 < param_4 - uVar2) {
    uVar1 = param_3;
    if (param_1 < *(int *)(param_2 + param_3 * 4)) {
      uVar1 = uVar2;
      param_4 = param_3;
    }
    param_3 = param_4 + uVar1 >> 1;
    uVar2 = uVar1;
  }
  return;
}



/* ===== FUN_080181c6 @ 0x80181C6 ===== */

int FUN_080181c6(int param_1,int param_2)

{
  int iVar1;
  
  if ((-(param_1 >> 0x1f) == -(param_2 >> 0x1f)) || (param_1 == param_2 * (param_1 / param_2))) {
    iVar1 = 0;
  }
  else {
    iVar1 = -1;
  }
  return iVar1 + param_1 / param_2;
}



/* ===== FUN_080181ea @ 0x80181EA ===== */

uint FUN_080181ea(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  
  uVar1 = param_1 / param_2;
  param_1 = param_1 - param_2 * (param_1 / param_2);
  for (uVar2 = 0; uVar2 < param_3; uVar2 = uVar2 + 1) {
    bVar3 = 0x7fffffff < param_1;
    param_1 = param_1 * 2;
    uVar1 = uVar1 * 2;
    if ((bVar3) || (param_2 <= param_1)) {
      uVar1 = uVar1 + 1;
      param_1 = param_1 - param_2;
    }
  }
  return uVar1;
}



/* ===== FUN_08018222 @ 0x8018222 ===== */

uint FUN_08018222(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = param_1;
  if ((int)param_1 < 0) {
    uVar1 = ~param_1 + 1;
  }
  uVar2 = param_2;
  if ((int)param_2 < 0) {
    uVar2 = ~param_2 + 1;
  }
  uVar3 = uVar1 / uVar2;
  if (uVar2 <= (uVar1 - uVar2 * (uVar1 / uVar2)) * 2) {
    uVar3 = uVar3 + 1;
  }
  if (-((int)param_1 >> 0x1f) != -((int)param_2 >> 0x1f)) {
    uVar3 = -uVar3;
  }
  return uVar3;
}



/* ===== FUN_08018266 @ 0x8018266 ===== */

uint FUN_08018266(uint param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_1 / param_2;
  param_1 = param_1 - param_2 * (param_1 / param_2);
  if (param_1 < 0x80000000) {
    if (param_2 <= param_1 * 2) {
      uVar1 = uVar1 + 1;
    }
  }
  else {
    uVar1 = uVar1 + 1;
  }
  return uVar1;
}



/* ===== FUN_08018288 @ 0x8018288 ===== */

uint FUN_08018288(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_2 == 0) {
    if ((int)param_1 < 0) {
      uVar1 = 0x80000000;
    }
    else {
      uVar1 = 0x7fffffff;
    }
  }
  else {
    uVar1 = param_1;
    if ((int)param_1 < 0) {
      uVar1 = ~param_1 + 1;
    }
    uVar2 = param_2;
    if ((int)param_2 < 0) {
      uVar2 = ~param_2 + 1;
    }
    uVar1 = uVar1 / uVar2;
    if (-((int)param_1 >> 0x1f) != -((int)param_2 >> 0x1f)) {
      uVar1 = -uVar1;
    }
  }
  return uVar1;
}



/* ===== FUN_080182ce @ 0x80182CE ===== */

uint FUN_080182ce(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (param_2 == 0) {
    if ((int)param_1 < 0) {
      uVar1 = 0x80000000;
    }
    else {
      uVar1 = 0x7fffffff;
    }
  }
  else {
    uVar2 = param_1;
    if ((int)param_1 < 0) {
      uVar2 = ~param_1 + 1;
    }
    uVar3 = param_2;
    if ((int)param_2 < 0) {
      uVar3 = ~param_2 + 1;
    }
    uVar1 = uVar2 / uVar3;
    if (uVar3 <= (uVar2 - uVar3 * (uVar2 / uVar3)) * 2) {
      uVar1 = uVar1 + 1;
    }
    if (-((int)param_1 >> 0x1f) != -((int)param_2 >> 0x1f)) {
      uVar1 = -uVar1;
    }
  }
  return uVar1;
}



/* ===== FUN_08018328 @ 0x8018328 ===== */

uint FUN_08018328(uint param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    if ((int)param_1 < 0) {
      param_1 = 0x80000000;
    }
    else {
      param_1 = 0x7fffffff;
    }
  }
  else {
    uVar1 = param_1 ^ param_2;
    if ((int)param_1 < 0) {
      param_1 = ~param_1 + 1;
    }
    if ((int)param_2 < 0) {
      param_2 = ~param_2 + 1;
    }
    param_1 = param_1 / param_2;
    if (((int)uVar1 < 0) || (param_1 < 0x7fffffff)) {
      if (((int)uVar1 < 0) && (0x7fffffff < param_1)) {
        param_1 = 0x80000000;
      }
      else if ((int)uVar1 < 0) {
        param_1 = -param_1;
      }
    }
    else {
      param_1 = 0x7fffffff;
    }
  }
  return param_1;
}



/* ===== FUN_0801838a @ 0x801838A ===== */

uint FUN_0801838a(uint param_1,uint param_2)

{
  uint uVar1;
  
  if (param_2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = param_1 / param_2;
    param_1 = param_1 - param_2 * (param_1 / param_2);
    if (param_1 < 0x80000000) {
      if (param_2 <= param_1 * 2) {
        uVar1 = uVar1 + 1;
      }
    }
    else {
      uVar1 = uVar1 + 1;
    }
  }
  return uVar1;
}



/* ===== FUN_080183b4 @ 0x80183B4 ===== */

void FUN_080183b4(int param_1)

{
  if (param_1 == DAT_08018400) {
    FUN_0800e6a4(4,1);
  }
  else if (param_1 == DAT_08018404) {
    FUN_0800e6a4(8,1);
  }
  else if (param_1 == DAT_08018408) {
    FUN_0800e6a4(0x10,1);
  }
  else if (param_1 == DAT_0801840c) {
    FUN_0800e6a4(0x20,1);
  }
  FUN_0800e6a4(1);
  return;
}



/* ===== FUN_08018410 @ 0x8018410 ===== */

undefined8 FUN_08018410(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  
  local_20 = DAT_08018470;
  uStack_1c = DAT_08018474;
  uStack_18 = DAT_08018478;
  iVar1 = 0;
  for (uVar2 = 0; (int)uVar2 < param_2 + -1; uVar2 = uVar2 + 1 & 0xff) {
    iVar1 = iVar1 + (uint)*(byte *)((int)&local_20 + uVar2);
  }
  iVar1 = iVar1 + param_3;
  if (2 < param_2) {
    if ((param_1 == ((int)(param_1 + ((uint)(param_1 >> 0x1f) >> 0x1e)) >> 2) * 4) &&
       ((param_1 != (param_1 / 100) * 100 || (param_1 == (param_1 / 400) * 400)))) {
      iVar3 = 1;
    }
    else {
      iVar3 = 0;
    }
    iVar1 = iVar1 + iVar3;
  }
  return CONCAT44(DAT_08018470,iVar1);
}



/* ===== FUN_0801847c @ 0x801847C ===== */

int FUN_0801847c(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  
  if ((((param_1 < 2000) && (2999 < param_1)) || (param_2 < 1)) ||
     (((0xc < param_2 || (param_3 < 1)) || ((0x1f < param_3 || (0x17 < param_4)))))) {
    param_4 = 0;
  }
  else {
    iVar1 = FUN_08018410(param_1,param_2,param_3);
    param_4 = param_4 + (iVar1 + -1) * 0x18;
  }
  return param_4;
}



/* ===== FUN_080184d4 @ 0x80184D4 ===== */

undefined4 FUN_080184d4(void)

{
  return *(undefined4 *)(DAT_080184dc + 0x17);
}



/* ===== FUN_080184e0 @ 0x80184E0 ===== */

undefined4 FUN_080184e0(void)

{
  return *(undefined4 *)(DAT_080184e8 + 0x1b);
}



/* ===== FUN_080184ec @ 0x80184EC ===== */

undefined4 FUN_080184ec(void)

{
  return *(undefined4 *)(DAT_080184f4 + 0x2f);
}



/* ===== FUN_080184f8 @ 0x80184F8 ===== */

int FUN_080184f8(void)

{
  return (int)*(short *)(DAT_08018500 + 0x20);
}



/* ===== FUN_08018504 @ 0x8018504 ===== */

undefined2 FUN_08018504(void)

{
  return *(undefined2 *)(DAT_0801850c + 0x27);
}



/* ===== FUN_08018510 @ 0x8018510 ===== */

undefined1 FUN_08018510(void)

{
  return *(undefined1 *)(DAT_08018518 + 0x22);
}



/* ===== FUN_0801851c @ 0x801851C ===== */

undefined4 FUN_0801851c(void)

{
  return *(undefined4 *)(DAT_08018524 + 0x34);
}



/* ===== FUN_08018528 @ 0x8018528 ===== */

undefined4 FUN_08018528(void)

{
  return *(undefined4 *)(DAT_08018530 + 0x12);
}



/* ===== FUN_08018534 @ 0x8018534 ===== */

undefined4 FUN_08018534(void)

{
  return *(undefined4 *)(DAT_0801853c + 10);
}



/* ===== FUN_08018540 @ 0x8018540 ===== */

undefined4 FUN_08018540(void)

{
  return *(undefined4 *)(DAT_08018548 + 0xe);
}



/* ===== FUN_0801854c @ 0x801854C ===== */

undefined4 FUN_0801854c(void)

{
  return *(undefined4 *)(DAT_08018554 + 6);
}



/* ===== FUN_08018558 @ 0x8018558 ===== */

int FUN_08018558(void)

{
  return (int)*(short *)(DAT_08018560 + 1);
}



/* ===== FUN_08018564 @ 0x8018564 ===== */

undefined2 FUN_08018564(void)

{
  return *(undefined2 *)(DAT_0801856c + 0x3d);
}



/* ===== FUN_08018570 @ 0x8018570 ===== */

int FUN_08018570(void)

{
  return (int)*(short *)(DAT_08018578 + 0x24);
}



/* ===== FUN_0801857c @ 0x801857C ===== */

undefined2 FUN_0801857c(void)

{
  return *(undefined2 *)(DAT_08018584 + 3);
}



/* ===== FUN_08018588 @ 0x8018588 ===== */

uint FUN_08018588(int *param_1,int *param_2,int param_3,int param_4)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar2 = param_1[1] * *(int *)(param_4 + 4) + param_1[2] * *(int *)(param_4 + 8) + *param_1;
  uVar1 = *(ushort *)(param_3 + (iVar2 + 1) * 2);
  if (uVar1 < *(ushort *)(param_3 + iVar2 * 2)) {
    uVar4 = (uint)*(ushort *)(param_3 + iVar2 * 2) -
            ((uint)(ushort)(*(short *)(param_3 + iVar2 * 2) - uVar1) * *param_2 >> 0x10);
  }
  else {
    uVar4 = (uint)*(ushort *)(param_3 + iVar2 * 2) +
            ((uint)(ushort)(uVar1 - *(short *)(param_3 + iVar2 * 2)) * *param_2 >> 0x10);
  }
  uVar4 = uVar4 & 0xffff;
  iVar3 = *(int *)(param_4 + 4) + iVar2;
  uVar1 = *(ushort *)(param_3 + (iVar3 + 1) * 2);
  if (uVar1 < *(ushort *)(param_3 + iVar3 * 2)) {
    uVar5 = (uint)*(ushort *)(param_3 + iVar3 * 2) -
            ((uint)(ushort)(*(short *)(param_3 + iVar3 * 2) - uVar1) * *param_2 >> 0x10);
  }
  else {
    uVar5 = (uint)*(ushort *)(param_3 + iVar3 * 2) +
            ((uint)(ushort)(uVar1 - *(short *)(param_3 + iVar3 * 2)) * *param_2 >> 0x10);
  }
  uVar5 = uVar5 & 0xffff;
  if (uVar5 < uVar4) {
    uVar5 = -((uVar4 - uVar5 & 0xffff) * param_2[1] >> 0x10);
  }
  else {
    uVar5 = (uVar5 - uVar4 & 0xffff) * param_2[1] >> 0x10;
  }
  uVar4 = uVar4 + uVar5 & 0xffff;
  iVar2 = iVar2 + *(int *)(param_4 + 8);
  uVar1 = *(ushort *)(param_3 + (iVar2 + 1) * 2);
  if (uVar1 < *(ushort *)(param_3 + iVar2 * 2)) {
    uVar5 = (uint)*(ushort *)(param_3 + iVar2 * 2) -
            ((uint)(ushort)(*(short *)(param_3 + iVar2 * 2) - uVar1) * *param_2 >> 0x10);
  }
  else {
    uVar5 = (uint)*(ushort *)(param_3 + iVar2 * 2) +
            ((uint)(ushort)(uVar1 - *(short *)(param_3 + iVar2 * 2)) * *param_2 >> 0x10);
  }
  uVar5 = uVar5 & 0xffff;
  iVar2 = *(int *)(param_4 + 4) + iVar2;
  uVar1 = *(ushort *)(param_3 + (iVar2 + 1) * 2);
  if (uVar1 < *(ushort *)(param_3 + iVar2 * 2)) {
    uVar6 = (uint)*(ushort *)(param_3 + iVar2 * 2) -
            ((uint)(ushort)(*(short *)(param_3 + iVar2 * 2) - uVar1) * *param_2 >> 0x10);
  }
  else {
    uVar6 = (uint)*(ushort *)(param_3 + iVar2 * 2) +
            ((uint)(ushort)(uVar1 - *(short *)(param_3 + iVar2 * 2)) * *param_2 >> 0x10);
  }
  uVar6 = uVar6 & 0xffff;
  if (uVar6 < uVar5) {
    uVar6 = -((uVar5 - uVar6 & 0xffff) * param_2[1] >> 0x10);
  }
  else {
    uVar6 = (uVar6 - uVar5 & 0xffff) * param_2[1] >> 0x10;
  }
  uVar5 = uVar5 + uVar6 & 0xffff;
  if (uVar5 < uVar4) {
    uVar5 = -((uVar4 - uVar5 & 0xffff) * param_2[2] >> 0x10);
  }
  else {
    uVar5 = (uVar5 - uVar4 & 0xffff) * param_2[2] >> 0x10;
  }
  return uVar4 + uVar5 & 0xffff;
}



/* ===== FUN_080187b6 @ 0x80187B6 ===== */

uint FUN_080187b6(int param_1,short *param_2,int param_3,uint param_4)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (*param_2 < param_1) {
    if (param_1 < param_2[param_4]) {
      uVar2 = 0;
      uVar4 = param_4;
      while (uVar4 = uVar4 >> 1, 1 < param_4 - uVar2) {
        uVar3 = uVar4;
        if (param_1 < param_2[uVar4]) {
          uVar3 = uVar2;
          param_4 = uVar4;
        }
        uVar4 = param_4 + uVar3;
        uVar2 = uVar3;
      }
      uVar4 = ((param_1 - (uint)(ushort)param_2[uVar2] & 0xffff) << 8) /
              ((uint)(ushort)param_2[uVar2 + 1] - (uint)(ushort)param_2[uVar2] & 0xffff) & 0xffff;
    }
    else {
      uVar2 = param_4 - 1;
      uVar4 = 0x100;
    }
  }
  else {
    uVar2 = 0;
    uVar4 = 0;
  }
  bVar1 = *(byte *)(param_3 + uVar2 + 1);
  if (bVar1 < *(byte *)(param_3 + uVar2)) {
    uVar2 = (uint)*(byte *)(param_3 + uVar2) -
            ((byte)(*(char *)(param_3 + uVar2) - bVar1) * uVar4 >> 8);
  }
  else {
    uVar2 = (uint)*(byte *)(param_3 + uVar2) +
            ((byte)(bVar1 - *(char *)(param_3 + uVar2)) * uVar4 >> 8);
  }
  return uVar2 & 0xff;
}



/* ===== FUN_08018880 @ 0x8018880 ===== */

int FUN_08018880(int param_1,short *param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  if (*param_2 < param_1) {
    if (param_1 < param_2[param_4]) {
      uVar1 = 0;
      uVar6 = param_4;
      uVar4 = param_4;
      while (uVar4 = uVar4 >> 1, 1 < uVar6 - uVar1) {
        uVar2 = uVar4;
        if (param_1 < param_2[uVar4]) {
          uVar2 = uVar1;
          uVar6 = uVar4;
        }
        uVar4 = uVar6 + uVar2;
        uVar1 = uVar2;
      }
      uVar3 = FUN_080181ea((param_1 - (uint)(ushort)param_2[uVar1]) * 0x10000,
                           param_2[uVar1 + 1] - param_2[uVar1],0xf,param_2[uVar1],param_4);
    }
    else {
      uVar1 = param_4 - 1;
      uVar3 = 0x80000000;
    }
  }
  else {
    uVar1 = 0;
    uVar3 = 0;
  }
  iVar5 = *(int *)(param_3 + (uVar1 + 1) * 4);
  if (iVar5 < *(int *)(param_3 + uVar1 * 4)) {
    iVar5 = FUN_0801912c(uVar3,*(int *)(param_3 + uVar1 * 4) - iVar5,0x1f);
    iVar5 = *(int *)(param_3 + uVar1 * 4) - iVar5;
  }
  else {
    iVar5 = FUN_0801912c(uVar3,iVar5 - *(int *)(param_3 + uVar1 * 4),0x1f);
    iVar5 = iVar5 + *(int *)(param_3 + uVar1 * 4);
  }
  return iVar5;
}



/* ===== FUN_08018938 @ 0x8018938 ===== */

int FUN_08018938(int param_1,short *param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  
  if (*param_2 < param_1) {
    if (param_1 < param_2[param_4]) {
      uVar2 = 0;
      uVar5 = param_4;
      while (uVar5 = uVar5 >> 1, 1 < param_4 - uVar2) {
        uVar3 = uVar5;
        if (param_1 < param_2[uVar5]) {
          uVar3 = uVar2;
          param_4 = uVar5;
        }
        uVar5 = param_4 + uVar3;
        uVar2 = uVar3;
      }
      uVar4 = FUN_080181ea((param_1 - (uint)(ushort)param_2[uVar2]) * 0x10000,
                           param_2[uVar2 + 1] - param_2[uVar2],0xf);
    }
    else {
      uVar2 = param_4 - 1;
      uVar4 = 0x80000000;
    }
  }
  else {
    uVar2 = 0;
    uVar4 = 0;
  }
  uVar5 = *(uint *)(param_3 + (uVar2 + 1) * 4);
  if (uVar5 < *(uint *)(param_3 + uVar2 * 4)) {
    iVar1 = FUN_0801912c(uVar4,*(int *)(param_3 + uVar2 * 4) - uVar5,0x1f);
    iVar1 = *(int *)(param_3 + uVar2 * 4) - iVar1;
  }
  else {
    iVar1 = FUN_0801912c(uVar4,uVar5 - *(int *)(param_3 + uVar2 * 4),0x1f);
    iVar1 = iVar1 + *(int *)(param_3 + uVar2 * 4);
  }
  return iVar1;
}



/* ===== FUN_080189f0 @ 0x80189F0 ===== */

uint FUN_080189f0(int param_1,int *param_2,int param_3,uint param_4)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (*param_2 < param_1) {
    if (param_1 < param_2[param_4]) {
      uVar2 = 0;
      uVar6 = param_4;
      uVar5 = param_4;
      while (uVar5 = uVar5 >> 1, 1 < uVar6 - uVar2) {
        uVar3 = uVar5;
        if (param_1 < param_2[uVar5]) {
          uVar3 = uVar2;
          uVar6 = uVar5;
        }
        uVar5 = uVar6 + uVar3;
        uVar2 = uVar3;
      }
      iVar4 = FUN_080181ea(param_1 - param_2[uVar2],param_2[uVar2 + 1] - param_2[uVar2],0x10,
                           param_2[uVar2],param_4);
    }
    else {
      uVar2 = param_4 - 1;
      iVar4 = 0x10000;
    }
  }
  else {
    uVar2 = 0;
    iVar4 = 0;
  }
  uVar1 = *(ushort *)(param_3 + (uVar2 + 1) * 2);
  if (uVar1 < *(ushort *)(param_3 + uVar2 * 2)) {
    uVar2 = (uint)*(ushort *)(param_3 + uVar2 * 2) -
            (iVar4 * (uint)(ushort)(*(short *)(param_3 + uVar2 * 2) - uVar1) >> 0x10);
  }
  else {
    uVar2 = (uint)*(ushort *)(param_3 + uVar2 * 2) +
            (iVar4 * (uint)(ushort)(uVar1 - *(short *)(param_3 + uVar2 * 2)) >> 0x10);
  }
  return uVar2 & 0xffff;
}



/* ===== FUN_08018aa2 @ 0x8018AA2 ===== */

int FUN_08018aa2(int param_1,ushort *param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((int)(uint)*param_2 < param_1) {
    if (param_1 < (int)(uint)param_2[param_4]) {
      uVar1 = 0;
      uVar3 = param_4;
      while (uVar3 = uVar3 >> 1, 1 < param_4 - uVar1) {
        uVar2 = uVar3;
        if (param_1 < (int)(uint)param_2[uVar3]) {
          uVar2 = uVar1;
          param_4 = uVar3;
        }
        uVar3 = param_4 + uVar2;
        uVar1 = uVar2;
      }
      uVar3 = ((param_1 - (uint)param_2[uVar1]) * 0x10000) /
              ((uint)param_2[uVar1 + 1] - (uint)param_2[uVar1] & 0xffff);
    }
    else {
      uVar1 = param_4 - 1;
      uVar3 = 0x10000;
    }
  }
  else {
    uVar1 = 0;
    uVar3 = 0;
  }
  return (int)(short)(*(short *)(param_3 + uVar1 * 2) +
                     (short)(uVar3 * ((int)*(short *)(param_3 + (uVar1 + 1) * 2) -
                                     (int)*(short *)(param_3 + uVar1 * 2)) >> 0x10));
}



/* ===== FUN_08018b22 @ 0x8018B22 ===== */

uint FUN_08018b22(uint param_1,uint *param_2,int param_3,uint param_4)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  if (*param_2 < param_1) {
    if (param_1 < param_2[param_4]) {
      uVar2 = 0;
      uVar6 = param_4;
      uVar5 = param_4;
      while (uVar5 = uVar5 >> 1, 1 < uVar6 - uVar2) {
        uVar3 = uVar5;
        if (param_1 < param_2[uVar5]) {
          uVar3 = uVar2;
          uVar6 = uVar5;
        }
        uVar5 = uVar6 + uVar3;
        uVar2 = uVar3;
      }
      iVar4 = FUN_080181ea(param_1 - param_2[uVar2],param_2[uVar2 + 1] - param_2[uVar2],0x10,
                           param_2[uVar2],param_4);
    }
    else {
      uVar2 = param_4 - 1;
      iVar4 = 0x10000;
    }
  }
  else {
    uVar2 = 0;
    iVar4 = 0;
  }
  uVar1 = *(ushort *)(param_3 + (uVar2 + 1) * 2);
  if (uVar1 < *(ushort *)(param_3 + uVar2 * 2)) {
    uVar2 = (uint)*(ushort *)(param_3 + uVar2 * 2) -
            (iVar4 * (uint)(ushort)(*(short *)(param_3 + uVar2 * 2) - uVar1) >> 0x10);
  }
  else {
    uVar2 = (uint)*(ushort *)(param_3 + uVar2 * 2) +
            (iVar4 * (uint)(ushort)(uVar1 - *(short *)(param_3 + uVar2 * 2)) >> 0x10);
  }
  return uVar2 & 0xffff;
}



/* ===== FUN_08018bd4 @ 0x8018BD4 ===== */

uint FUN_08018bd4(int param_1,int param_2,short *param_3,int *param_4,int param_5,uint *param_6,
                 int param_7)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint local_4c;
  uint local_38;
  
  if (*param_3 < param_1) {
    if (param_1 < param_3[*param_6]) {
      uVar5 = *param_6;
      uVar7 = *param_6;
      uVar4 = 0;
      while (uVar5 = uVar5 >> 1, 1 < uVar7 - uVar4) {
        uVar9 = uVar5;
        if (param_1 < param_3[uVar5]) {
          uVar9 = uVar4;
          uVar7 = uVar5;
        }
        uVar5 = uVar7 + uVar9;
        uVar4 = uVar9;
      }
      uVar7 = ((param_1 - (uint)(ushort)param_3[uVar4]) * 0x10000) /
              ((uint)(ushort)param_3[uVar4 + 1] - (uint)(ushort)param_3[uVar4] & 0xffff);
    }
    else {
      uVar4 = *param_6 - 1;
      uVar7 = 0x10000;
    }
  }
  else {
    uVar4 = 0;
    uVar7 = 0;
  }
  if (*param_4 < param_2) {
    if (param_2 < param_4[param_6[1]]) {
      uVar2 = param_6[1];
      uVar9 = param_6[1];
      uVar5 = 0;
      while (uVar2 = uVar2 >> 1, 1 < uVar9 - uVar5) {
        uVar6 = uVar2;
        if (param_2 < param_4[uVar2]) {
          uVar6 = uVar5;
          uVar9 = uVar2;
        }
        uVar2 = uVar9 + uVar6;
        uVar5 = uVar6;
      }
      iVar8 = FUN_080181ea(param_2 - param_4[uVar5],param_4[uVar5 + 1] - param_4[uVar5],0x10);
    }
    else {
      uVar5 = param_6[1] - 1;
      iVar8 = 0x10000;
    }
  }
  else {
    uVar5 = 0;
    iVar8 = 0;
  }
  iVar3 = uVar5 * param_7 + uVar4;
  uVar1 = *(ushort *)(param_5 + (iVar3 + 1) * 2);
  if (uVar1 < *(ushort *)(param_5 + iVar3 * 2)) {
    local_4c = (uint)*(ushort *)(param_5 + iVar3 * 2) -
               (uVar7 * (ushort)(*(short *)(param_5 + iVar3 * 2) - uVar1) >> 0x10);
  }
  else {
    local_4c = (uint)*(ushort *)(param_5 + iVar3 * 2) +
               (uVar7 * (ushort)(uVar1 - *(short *)(param_5 + iVar3 * 2)) >> 0x10);
  }
  local_4c = local_4c & 0xffff;
  iVar3 = iVar3 + param_7;
  uVar1 = *(ushort *)(param_5 + (iVar3 + 1) * 2);
  if (uVar1 < *(ushort *)(param_5 + iVar3 * 2)) {
    uVar4 = (uint)*(ushort *)(param_5 + iVar3 * 2) -
            (uVar7 * (ushort)(*(short *)(param_5 + iVar3 * 2) - uVar1) >> 0x10);
  }
  else {
    uVar4 = (uint)*(ushort *)(param_5 + iVar3 * 2) +
            (uVar7 * (ushort)(uVar1 - *(short *)(param_5 + iVar3 * 2)) >> 0x10);
  }
  uVar4 = uVar4 & 0xffff;
  if (uVar4 < local_4c) {
    uVar4 = -(iVar8 * (local_4c - uVar4 & 0xffff) >> 0x10);
  }
  else {
    uVar4 = iVar8 * (uVar4 - local_4c & 0xffff) >> 0x10;
  }
  local_38 = local_4c + uVar4 & 0xffff;
  return local_38;
}



/* ===== FUN_08018d8e @ 0x8018D8E ===== */

uint FUN_08018d8e(int param_1,int param_2,int *param_3,int *param_4,int param_5,uint *param_6,
                 int param_7)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint local_4c;
  uint local_3c;
  uint local_38;
  
  if (*param_3 < param_1) {
    if (param_1 < param_3[*param_6]) {
      uVar4 = *param_6;
      local_4c = *param_6;
      uVar6 = 0;
      while (uVar4 = uVar4 >> 1, 1 < local_4c - uVar6) {
        uVar7 = uVar4;
        if (param_1 < param_3[uVar4]) {
          uVar7 = uVar6;
          local_4c = uVar4;
        }
        uVar4 = local_4c + uVar7;
        uVar6 = uVar7;
      }
      uVar2 = FUN_080181ea(param_1 - param_3[uVar6],param_3[uVar6 + 1] - param_3[uVar6],8);
      local_3c = (uint)uVar2;
    }
    else {
      uVar6 = *param_6 - 1;
      local_3c = 0x100;
    }
  }
  else {
    uVar6 = 0;
    local_3c = 0;
  }
  uVar4 = local_3c;
  if (*param_4 < param_2) {
    if (param_2 < param_4[param_6[1]]) {
      uVar3 = param_6[1];
      local_4c = param_6[1];
      uVar7 = 0;
      while (uVar3 = uVar3 >> 1, 1 < local_4c - uVar7) {
        uVar8 = uVar3;
        if (param_2 < param_4[uVar3]) {
          uVar8 = uVar7;
          local_4c = uVar3;
        }
        uVar3 = local_4c + uVar8;
        uVar7 = uVar8;
      }
      uVar2 = FUN_080181ea(param_2 - param_4[uVar7],param_4[uVar7 + 1] - param_4[uVar7],8);
      local_3c = (uint)uVar2;
    }
    else {
      uVar7 = param_6[1] - 1;
      local_3c = 0x100;
    }
  }
  else {
    uVar7 = 0;
    local_3c = 0;
  }
  iVar5 = uVar7 * param_7 + uVar6;
  bVar1 = *(byte *)(param_5 + iVar5 + 1);
  if (bVar1 < *(byte *)(param_5 + iVar5)) {
    uVar6 = (uint)*(byte *)(param_5 + iVar5) -
            (uVar4 * (byte)(*(char *)(param_5 + iVar5) - bVar1) >> 8);
  }
  else {
    uVar6 = (uint)*(byte *)(param_5 + iVar5) +
            (uVar4 * (byte)(bVar1 - *(char *)(param_5 + iVar5)) >> 8);
  }
  uVar6 = uVar6 & 0xff;
  iVar5 = iVar5 + param_7;
  bVar1 = *(byte *)(param_5 + iVar5 + 1);
  if (bVar1 < *(byte *)(param_5 + iVar5)) {
    uVar4 = (uint)*(byte *)(param_5 + iVar5) -
            (uVar4 * (byte)(*(char *)(param_5 + iVar5) - bVar1) >> 8);
  }
  else {
    uVar4 = (uint)*(byte *)(param_5 + iVar5) +
            (uVar4 * (byte)(bVar1 - *(char *)(param_5 + iVar5)) >> 8);
  }
  uVar4 = uVar4 & 0xff;
  if (uVar4 < uVar6) {
    uVar4 = -(local_3c * (uVar6 - uVar4 & 0xff) >> 8);
  }
  else {
    uVar4 = local_3c * (uVar4 - uVar6 & 0xff) >> 8;
  }
  local_38 = uVar6 + uVar4 & 0xff;
  return local_38;
}



/* ===== FUN_08018f42 @ 0x8018F42 ===== */

undefined1
FUN_08018f42(int param_1,int param_2,int *param_3,short *param_4,int param_5,uint *param_6,
            int param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (*param_3 < param_1) {
    if (param_1 < param_3[*param_6]) {
      uVar5 = *param_6;
      uVar3 = *param_6;
      uVar2 = 0;
      while (uVar5 = uVar5 >> 1, 1 < uVar3 - uVar2) {
        uVar1 = uVar5;
        if (param_1 < param_3[uVar5]) {
          uVar1 = uVar2;
          uVar3 = uVar5;
        }
        uVar5 = uVar3 + uVar1;
        uVar2 = uVar1;
      }
    }
    else {
      uVar2 = *param_6;
    }
  }
  else {
    uVar2 = 0;
  }
  if (*param_4 < param_2) {
    if (param_2 < param_4[param_6[1]]) {
      uVar1 = param_6[1];
      uVar5 = param_6[1];
      uVar3 = 0;
      while (uVar1 = uVar1 >> 1, 1 < uVar5 - uVar3) {
        uVar4 = uVar1;
        if (param_2 < param_4[uVar1]) {
          uVar4 = uVar3;
          uVar5 = uVar1;
        }
        uVar1 = uVar5 + uVar4;
        uVar3 = uVar4;
      }
    }
    else {
      uVar3 = param_6[1];
    }
  }
  else {
    uVar3 = 0;
  }
  return *(undefined1 *)(param_5 + uVar3 * param_7 + uVar2);
}



/* ===== FUN_08018fde @ 0x8018FDE ===== */

int FUN_08018fde(int param_1,int param_2,ushort *param_3,short *param_4,int param_5,uint *param_6,
                int param_7)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if ((int)(uint)*param_3 < param_1) {
    if (param_1 < (int)(uint)param_3[*param_6]) {
      uVar5 = *param_6;
      uVar3 = *param_6;
      uVar2 = 0;
      while (uVar5 = uVar5 >> 1, 1 < uVar3 - uVar2) {
        uVar1 = uVar5;
        if (param_1 < (int)(uint)param_3[uVar5]) {
          uVar1 = uVar2;
          uVar3 = uVar5;
        }
        uVar5 = uVar3 + uVar1;
        uVar2 = uVar1;
      }
    }
    else {
      uVar2 = *param_6;
    }
  }
  else {
    uVar2 = 0;
  }
  if (*param_4 < param_2) {
    if (param_2 < param_4[param_6[1]]) {
      uVar1 = param_6[1];
      uVar5 = param_6[1];
      uVar3 = 0;
      while (uVar1 = uVar1 >> 1, 1 < uVar5 - uVar3) {
        uVar4 = uVar1;
        if (param_2 < param_4[uVar1]) {
          uVar4 = uVar3;
          uVar5 = uVar1;
        }
        uVar1 = uVar5 + uVar4;
        uVar3 = uVar4;
      }
    }
    else {
      uVar3 = param_6[1];
    }
  }
  else {
    uVar3 = 0;
  }
  return (int)*(short *)(param_5 + (uVar3 * param_7 + uVar2) * 2);
}



/* ===== application_entry @ 0x801907A ===== */

/* Application entry reached by the ARMCC runtime startup after scatter loading. */

void application_entry(void)

{
  FUN_0800ba44();
  FUN_080056f4();
  FUN_08005034();
  FUN_08003df4();
  do {
    FUN_08006cbc(0);
  } while( true );
}



/* ===== FUN_08019094 @ 0x8019094 ===== */

uint FUN_08019094(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint local_18;
  int local_14;
  
  local_18 = param_3;
  local_14 = param_4;
  FUN_08019170(param_1,param_2,&local_14,&local_18);
  if ((local_14 < 1) && ((local_14 != 0 || (local_18 < 0x80000000)))) {
    if ((local_14 < -1) || ((local_14 == -1 && (local_18 < 0x80000000)))) {
      local_18 = 0x80000000;
    }
  }
  else {
    local_18 = 0x7fffffff;
  }
  return local_18;
}



/* ===== FUN_080190e0 @ 0x80190E0 ===== */

uint FUN_080190e0(undefined4 param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint local_18;
  int local_14;
  
  local_18 = param_3;
  local_14 = param_4;
  FUN_08019214(param_1,param_2,&local_14,&local_18);
  if ((local_14 < 1) && ((local_14 != 0 || (local_18 < 0x80000000)))) {
    if ((local_14 < -1) || ((local_14 == -1 && (local_18 < 0x80000000)))) {
      local_18 = 0x80000000;
    }
  }
  else {
    local_18 = 0x7fffffff;
  }
  return local_18;
}



/* ===== FUN_0801912c @ 0x801912C ===== */

uint FUN_0801912c(undefined4 param_1,undefined4 param_2,uint param_3,uint param_4)

{
  uint local_18;
  uint local_14;
  
  local_18 = param_3;
  local_14 = param_4;
  FUN_080192b8(param_1,param_2,&local_18,&local_14);
  return local_18 << (0x20 - param_3 & 0xff) | local_14 >> (param_3 & 0xff);
}



/* ===== FUN_08019150 @ 0x8019150 ===== */

undefined4 FUN_08019150(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  int local_18;
  undefined4 local_14;
  
  local_18 = param_3;
  local_14 = param_4;
  FUN_080192b8(param_1,param_2,&local_18,&local_14);
  if (local_18 != 0) {
    local_14 = 0xffffffff;
  }
  return local_14;
}



/* ===== FUN_08019170 @ 0x8019170 ===== */

void FUN_08019170(uint param_1,uint param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar5 = param_1;
  if ((int)param_1 < 0) {
    uVar5 = ~param_1 + 1;
  }
  uVar6 = param_2;
  if ((int)param_2 < 0) {
    uVar6 = ~param_2 + 1;
  }
  uVar4 = (uVar5 >> 0x10) * (uVar6 & 0xffff);
  uVar7 = (uVar5 & 0xffff) * (uVar6 >> 0x10);
  uVar1 = (uVar5 & 0xffff) * (uVar6 & 0xffff);
  uVar2 = uVar1 + uVar7 * 0x10000;
  uVar1 = (uint)(uVar2 < uVar1);
  uVar3 = uVar2 + uVar4 * 0x10000;
  if (uVar3 < uVar2) {
    uVar1 = uVar1 + 1;
  }
  uVar1 = (uVar5 >> 0x10) * (uVar6 >> 0x10) + (uVar7 >> 0x10) + (uVar4 >> 0x10) + uVar1;
  if (((param_1 != 0) && (param_2 != 0)) && (0 < (int)param_1 != 0 < (int)param_2)) {
    uVar1 = ~uVar1;
    uVar3 = ~uVar3 + 1;
    if (uVar3 == 0) {
      uVar1 = uVar1 + 1;
    }
  }
  *param_3 = uVar1;
  *param_4 = uVar3;
  return;
}



/* ===== FUN_08019214 @ 0x8019214 ===== */

void FUN_08019214(uint param_1,uint param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar5 = param_1;
  if ((int)param_1 < 0) {
    uVar5 = ~param_1 + 1;
  }
  uVar6 = param_2;
  if ((int)param_2 < 0) {
    uVar6 = ~param_2 + 1;
  }
  uVar4 = (uVar5 >> 0x10) * (uVar6 & 0xffff);
  uVar7 = (uVar5 & 0xffff) * (uVar6 >> 0x10);
  uVar1 = (uVar5 & 0xffff) * (uVar6 & 0xffff);
  uVar2 = uVar1 + uVar7 * 0x10000;
  uVar1 = (uint)(uVar2 < uVar1);
  uVar3 = uVar2 + uVar4 * 0x10000;
  if (uVar3 < uVar2) {
    uVar1 = uVar1 + 1;
  }
  uVar1 = (uVar5 >> 0x10) * (uVar6 >> 0x10) + (uVar7 >> 0x10) + (uVar4 >> 0x10) + uVar1;
  if (((param_1 != 0) && (param_2 != 0)) && (0 < (int)param_1 != 0 < (int)param_2)) {
    uVar1 = ~uVar1;
    uVar3 = ~uVar3 + 1;
    if (uVar3 == 0) {
      uVar1 = uVar1 + 1;
    }
  }
  *param_3 = uVar1;
  *param_4 = uVar3;
  return;
}



/* ===== FUN_080192b8 @ 0x80192B8 ===== */

void FUN_080192b8(uint param_1,uint param_2,int *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = (param_1 >> 0x10) * (param_2 & 0xffff);
  uVar4 = (param_1 & 0xffff) * (param_2 >> 0x10);
  uVar1 = (param_2 & 0xffff) * (param_1 & 0xffff);
  uVar2 = uVar1 + uVar4 * 0x10000;
  uVar3 = (uint)(uVar2 < uVar1);
  uVar1 = uVar2 + uVar5 * 0x10000;
  if (uVar1 < uVar2) {
    uVar3 = uVar3 + 1;
  }
  *param_3 = (param_1 >> 0x10) * (param_2 >> 0x10) + (uVar4 >> 0x10) + (uVar5 >> 0x10) + uVar3;
  *param_4 = uVar1;
  return;
}



/* ===== FUN_08019306 @ 0x8019306 ===== */

int FUN_08019306(int param_1,short *param_2,uint param_3,uint *param_4)

{
  int iVar1;
  
  if (*param_2 < param_1) {
    if (param_1 < param_2[param_3]) {
      iVar1 = FUN_08018176(param_1,param_2,param_3 >> 1,param_3);
      *param_4 = ((param_1 - (uint)(ushort)param_2[iVar1]) * 0x10000) /
                 ((uint)(ushort)param_2[iVar1 + 1] - (uint)(ushort)param_2[iVar1] & 0xffff);
    }
    else {
      iVar1 = param_3 - 1;
      *param_4 = 0x10000;
    }
  }
  else {
    iVar1 = 0;
    *param_4 = 0;
  }
  return iVar1;
}



/* ===== FUN_0801936a @ 0x801936A ===== */

int FUN_0801936a(int param_1,int *param_2,uint param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*param_2 < param_1) {
    if (param_1 < param_2[param_3]) {
      iVar2 = FUN_0801819e(param_1,param_2,param_3 >> 1,param_3);
      uVar1 = FUN_080181ea(param_1 - param_2[iVar2],param_2[iVar2 + 1] - param_2[iVar2],0x10);
      *param_4 = uVar1;
    }
    else {
      iVar2 = param_3 - 1;
      *param_4 = 0x10000;
    }
  }
  else {
    iVar2 = 0;
    *param_4 = 0;
  }
  return iVar2;
}



/* ===== FUN_080193cc @ 0x80193CC ===== */

undefined8 FUN_080193cc(void)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  ushort local_20;
  undefined1 uStack_1e;
  undefined1 uStack_1d;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
  uStack_1e = 0;
  local_14 = 0;
  bVar1 = 0;
  uStack_1d = 1;
  local_18 = 0;
  local_1c = 0;
  local_20 = *(ushort *)(DAT_080194f4 + 1) | *(ushort *)(DAT_080194f8 + 1);
  FUN_0800a5c8(*DAT_080194f4,&local_20);
  local_18 = 0x11;
  local_20 = *(ushort *)(DAT_080194f8 + 1);
  FUN_0800a5c8(*DAT_080194f8,&local_20);
  FUN_0800a7e2(*DAT_080194f8,*(undefined2 *)(DAT_080194f8 + 1),0);
  iVar3 = FUN_0800a7c8(*DAT_080194f4,*(undefined2 *)(DAT_080194f4 + 1));
  if (iVar3 == 0) {
    for (; bVar1 < 9; bVar1 = bVar1 + 1) {
      FUN_0800a7e2(*DAT_080194f8,*(undefined2 *)(DAT_080194f8 + 1),0);
      for (uVar2 = 0; uVar2 < 400; uVar2 = uVar2 + 1) {
      }
      iVar3 = FUN_0800a7c8(*DAT_080194f4,*(undefined2 *)(DAT_080194f4 + 1));
      if (iVar3 != 0) break;
      FUN_0800a7e2(*DAT_080194f8,*(undefined2 *)(DAT_080194f8 + 1),1);
      for (uVar2 = 0; uVar2 < 400; uVar2 = uVar2 + 1) {
      }
    }
  }
  iVar3 = FUN_0800a7c8(*DAT_080194f4,*(undefined2 *)(DAT_080194f4 + 1));
  if (iVar3 == 1) {
    local_20 = *(ushort *)(DAT_080194f4 + 1);
    FUN_0800a5c8(*DAT_080194f4,&local_20);
    FUN_0800a7e2(*DAT_080194f4,*(undefined2 *)(DAT_080194f4 + 1),0);
    for (uVar2 = 0; uVar2 < 200; uVar2 = uVar2 + 1) {
    }
    FUN_0800a7e2(*DAT_080194f8,*(undefined2 *)(DAT_080194f8 + 1),1);
    for (uVar2 = 0; uVar2 < 200; uVar2 = uVar2 + 1) {
    }
    FUN_0800a7e2(*DAT_080194f4,*(undefined2 *)(DAT_080194f4 + 1),1);
    for (uVar2 = 0; uVar2 < 200; uVar2 = uVar2 + 1) {
    }
  }
  FUN_08004d70();
  return CONCAT44(local_1c,CONCAT13(uStack_1d,CONCAT12(uStack_1e,local_20)));
}



/* ===== FUN_080194fc @ 0x80194FC ===== */

void FUN_080194fc(void)

{
  *DAT_08019514 = 0;
  *DAT_0801951c = *DAT_08019518;
  *DAT_08019520 = 0;
  return;
}



/* ===== FUN_08019524 @ 0x8019524 ===== */

undefined4 FUN_08019524(void)

{
  if (*DAT_0801954c < 0x1f) {
    if (0x10df < *DAT_08019550) {
      *DAT_08019550 = 0x10e0;
      return 1;
    }
  }
  else {
    *DAT_08019550 = 0;
  }
  return 0;
}


