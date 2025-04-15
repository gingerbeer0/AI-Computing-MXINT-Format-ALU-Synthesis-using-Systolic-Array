// file = 0; split type = patterns; threshold = 100000; total count = 0.
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include "rmapats.h"

void  schedNewEvent (struct dummyq_struct * I1460, EBLK  * I1455, U  I627);
void  schedNewEvent (struct dummyq_struct * I1460, EBLK  * I1455, U  I627)
{
    U  I1744;
    U  I1745;
    U  I1746;
    struct futq * I1747;
    struct dummyq_struct * pQ = I1460;
    I1744 = ((U )vcs_clocks) + I627;
    I1746 = I1744 & ((1 << fHashTableSize) - 1);
    I1455->I673 = (EBLK  *)(-1);
    I1455->I674 = I1744;
    if (0 && rmaProfEvtProp) {
        vcs_simpSetEBlkEvtID(I1455);
    }
    if (I1744 < (U )vcs_clocks) {
        I1745 = ((U  *)&vcs_clocks)[1];
        sched_millenium(pQ, I1455, I1745 + 1, I1744);
    }
    else if ((peblkFutQ1Head != ((void *)0)) && (I627 == 1)) {
        I1455->I676 = (struct eblk *)peblkFutQ1Tail;
        peblkFutQ1Tail->I673 = I1455;
        peblkFutQ1Tail = I1455;
    }
    else if ((I1747 = pQ->I1361[I1746].I696)) {
        I1455->I676 = (struct eblk *)I1747->I694;
        I1747->I694->I673 = (RP )I1455;
        I1747->I694 = (RmaEblk  *)I1455;
    }
    else {
        sched_hsopt(pQ, I1455, I1744);
    }
}
void  rmaPropagate3 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    scalar  I1606;
    scalar  I1607;
    scalar  I1184;
    scalar  I1608;
    scalar  * I1609;
    UB  * I1610;
    U  I1611 = 0;
    U  I1612;
    U  I1613 = 0;
    scalar  I1614;
    US  * I1615;
    US  I1616 = 0;
    UB  * I1129;
    UB  * I1617;
    RP  I1618 = 0;
    I1612 = (U )*(pcode + 24 + 3);
    *(pcode + 24 + 3) = 0;
    I1617 = pcode + 24;
    if (I1612) {
        *I1617 = val;
    }
    else {
        I1607 = *(pcode + 24 + 2);
        I1606 = val;
        if (I1606 != I1607) {
            I1611 = 1;
        }
        if (I1607 == 0xff) {
            I1607 = 0;
            I1613 = 1;
        }
        I1129 = pcode + 24 + 1U;
        *I1129 = I1606;
        if (!I1611) {
            return  ;
        }
        *(pcode + 24 + 2) = I1606;
    }
    if (!I1612) {
        I1609 = *(scalar  **)((*(RP  **)(pcode + 32)));
        I1184 = *(I1609 + I1606);
        *I1617 = I1184;
        val = I1184;
        I1608 = *(I1609 + I1607);
        I1614 = *(I1609 + (28));
        I1610 = (UB  *)(*((*(RP  **)(pcode + 32)) + 1));
        I1615 = edgeActionT + (9 * ((I1607 << 7U) + (I1606 << 2U) + I1614));
        I1616 = I1615[0];
    }
    if (I1611) {
        rmaScheduleGatedClockEdgeLoadNew(pcode + 40, I1615, 1U, I1610, I1610, I1606, I1607);
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 104);
        {
            RP  I1569 = 1;
            if (I1569 && I1611) {
                startBit = *(U  *)(pcode + 96);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(31U << startBit);
                state |= I1606 << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode += 112;
        pcode1 = *(UB  **)(pcode + 8);
        {
            RP  I1569 = 1;
            if (I1569 && I1611) {
                startBit = *(U  *)(pcode + 0);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(31U << startBit);
                state |= I1606 << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    if (!I1612 && !(I1616 & ~33825) && !I1613) {
        return  ;
    }
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 16);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    pcode += 24;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate3_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 24 + 1U);
    *(pcode + 24 + 1U) = 24;
    rmaPropagate3(pcode, val);
}
void  rmaPropagate8 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        unsigned long long * I1878 = derivedClk + (4U * X4val[val]);
        memcpy(pcode + 2 + 4, I1878, 25U);
    }
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 32);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        I1184 = X4val[val];
        I1627 = *(pcode + 40);
        *(pcode + 40) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 8718) {
            *(RmaTimeStamp  *)(pcode + 48) = (RmaTimeStamp )vcs_clocks;
        }
    }
    pcode += 56;
    {
        EBLK  * I1455;
        *((*(UB  **)(pcode + 8)) + 1) = X4val[val];
        I1455 = (EBLK  *)(pcode + 0);
        if (I1455->I673 == 0) {
            struct dummyq_struct * pQ;
            U  I1458;
            I1458 = 0;
            pQ = (struct dummyq_struct *)ref_vcs_clocks;
            EBLK  * I1669 = (EBLK  *)pvcsGetLastEventEblk(I1458);
            I1455->I673 = pQ->I1388;
            pQ->I1388 = I1455;
            {
                (pQ->semilerOptQueuesFlag |= (0x1 << 2));
            }
            if (0 && rmaProfEvtProp) {
                vcs_simpSetEBlkEvtID(I1455);
            }
            I1455 = I1669;
            if (!(I1455->I673)) {
                if ((semilerOpt != 0) && (I1669 == I1455)) {
                }
                else {
                    pQ->I1377->I673 = I1455;
                    pQ->I1377 = I1455;
                }
                I1455->I673 = ((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 48);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 12) {
            (*(FP  *)(pcode + 56))(*(void **)(pcode + 64), I235);
        }
        if (I1654 & 8704) {
            (*(FP  *)(pcode + 72))(*(void **)(pcode + 80), I235);
        }
        if (I1654 & 192) {
            (*(FP  *)(pcode + 88))(*(void **)(pcode + 96), I235);
        }
        if (I1654 & 4352) {
            (*(FP  *)(pcode + 104))(*(void **)(pcode + 112), I235);
        }
        if (I1654 & 18432) {
            (*(FP  *)(pcode + 120))(*(void **)(pcode + 128), I235);
        }
        if (I1654 & 2) {
            (*(FP  *)(pcode + 136))(*(void **)(pcode + 144), I235);
        }
        if (I1654 & 16) {
            (*(FP  *)(pcode + 152))(*(void **)(pcode + 160), I235);
        }
        *(pcode + 48U) = I1184;
    }
    {
        scalar  I1880 = X4val[val];
        scalar  I1881 = *(scalar  *)(pcode + 168 + 2U);
        *(scalar  *)(pcode + 168 + 2U) = I1880;
        UB  * I1025 = *(UB  **)(pcode + 168 + 8U);
        if (I1025) {
            U  I1882 = I1880 * 2;
            U  I1883 = 1 << ((I1881 << 2) + I1880);
            *(pcode + 168 + 0U) = 1;
            while (I1025){
                UB  * I1885 = *(UB  **)(I1025 + 16U);
                if ((*(US  *)(I1025 + 0U)) & I1883) {
                    *(*(UB  **)(I1025 + 48U)) = 1;
                    (*(FP  *)(I1025 + 32U))((void *)(*(RP  *)(I1025 + 40U)), (((*(scalar  *)(I1025 + 2U)) >> I1882) & 3));
                }
                I1025 = I1885;
            };
            *(pcode + 168 + 0U) = 0;
            rmaRemoveNonEdgeLoads(pcode + 168);
        }
    }
    pcode += 208;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate8_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate8(pcode, val);
}
void  rmaPropagate10 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    scalar  I1606;
    scalar  I1607;
    scalar  I1184;
    scalar  I1608;
    scalar  * I1609;
    UB  * I1610;
    U  I1611 = 0;
    U  I1612;
    U  I1613 = 0;
    scalar  I1614;
    US  * I1615;
    US  I1616 = 0;
    UB  * I1129;
    UB  * I1617;
    RP  I1618 = 0;
    I1612 = (U )*(pcode + 24 + 3);
    *(pcode + 24 + 3) = 0;
    I1617 = pcode + 24;
    if (I1612) {
        *I1617 = val;
    }
    else {
        I1607 = *(pcode + 24 + 2);
        I1606 = val;
        if (I1606 != I1607) {
            I1611 = 1;
        }
        if (I1607 == 0xff) {
            I1607 = 0;
            I1613 = 1;
        }
        I1129 = pcode + 24 + 1U;
        *I1129 = I1606;
        if (!I1611) {
            return  ;
        }
        *(pcode + 24 + 2) = I1606;
    }
    if (!I1612) {
        I1609 = *(scalar  **)((*(RP  **)(pcode + 32)));
        I1184 = *(I1609 + I1606);
        *I1617 = I1184;
        val = I1184;
        I1608 = *(I1609 + I1607);
        I1614 = *(I1609 + (28));
        I1610 = (UB  *)(*((*(RP  **)(pcode + 32)) + 1));
        I1615 = edgeActionT + (9 * ((I1607 << 7U) + (I1606 << 2U) + I1614));
        I1616 = I1615[0];
    }
    if (I1611) {
        rmaScheduleGatedClockEdgeLoadNew(pcode + 40, I1615, 1U, I1610, I1610, I1606, I1607);
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 104);
        {
            RP  I1569 = 1;
            if (I1569 && I1611) {
                startBit = *(U  *)(pcode + 96);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(31U << startBit);
                state |= I1606 << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode += 112;
        pcode1 = *(UB  **)(pcode + 8);
        {
            RP  I1569 = 1;
            if (I1569 && I1611) {
                startBit = *(U  *)(pcode + 0);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(31U << startBit);
                state |= I1606 << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    if (!I1612 && !(I1616 & ~33825) && !I1613) {
        return  ;
    }
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 16);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 24);
        pcode += 32;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate10_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 24 + 1U);
    *(pcode + 24 + 1U) = 24;
    rmaPropagate10(pcode, val);
}
void  rmaPropagate12 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        unsigned long long * I1878 = derivedClk + (4U * X4val[val]);
        memcpy(pcode + 2 + 4, I1878, 25U);
    }
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 32);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        I1184 = X4val[val];
        I1627 = *(pcode + 40);
        *(pcode + 40) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 8718) {
            *(RmaTimeStamp  *)(pcode + 48) = (RmaTimeStamp )vcs_clocks;
        }
    }
    pcode += 56;
    {
        EBLK  * I1455;
        *((*(UB  **)(pcode + 8)) + 1) = X4val[val];
        I1455 = (EBLK  *)(pcode + 0);
        if (I1455->I673 == 0) {
            struct dummyq_struct * pQ;
            U  I1458;
            I1458 = 0;
            pQ = (struct dummyq_struct *)ref_vcs_clocks;
            EBLK  * I1669 = (EBLK  *)pvcsGetLastEventEblk(I1458);
            I1455->I673 = pQ->I1388;
            pQ->I1388 = I1455;
            {
                (pQ->semilerOptQueuesFlag |= (0x1 << 2));
            }
            if (0 && rmaProfEvtProp) {
                vcs_simpSetEBlkEvtID(I1455);
            }
            I1455 = I1669;
            if (!(I1455->I673)) {
                if ((semilerOpt != 0) && (I1669 == I1455)) {
                }
                else {
                    pQ->I1377->I673 = I1455;
                    pQ->I1377 = I1455;
                }
                I1455->I673 = ((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 48);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 12) {
            (*(FP  *)(pcode + 56))(*(void **)(pcode + 64), I235);
        }
        if (I1654 & 8704) {
            (*(FP  *)(pcode + 72))(*(void **)(pcode + 80), I235);
        }
        if (I1654 & 192) {
            (*(FP  *)(pcode + 88))(*(void **)(pcode + 96), I235);
        }
        if (I1654 & 4352) {
            (*(FP  *)(pcode + 104))(*(void **)(pcode + 112), I235);
        }
        if (I1654 & 18432) {
            (*(FP  *)(pcode + 120))(*(void **)(pcode + 128), I235);
        }
        if (I1654 & 2) {
            (*(FP  *)(pcode + 136))(*(void **)(pcode + 144), I235);
        }
        if (I1654 & 16) {
            (*(FP  *)(pcode + 152))(*(void **)(pcode + 160), I235);
        }
        *(pcode + 48U) = I1184;
    }
    {
        scalar  I1880 = X4val[val];
        scalar  I1881 = *(scalar  *)(pcode + 168 + 2U);
        *(scalar  *)(pcode + 168 + 2U) = I1880;
        UB  * I1025 = *(UB  **)(pcode + 168 + 8U);
        if (I1025) {
            U  I1882 = I1880 * 2;
            U  I1883 = 1 << ((I1881 << 2) + I1880);
            *(pcode + 168 + 0U) = 1;
            while (I1025){
                UB  * I1885 = *(UB  **)(I1025 + 16U);
                if ((*(US  *)(I1025 + 0U)) & I1883) {
                    *(*(UB  **)(I1025 + 48U)) = 1;
                    (*(FP  *)(I1025 + 32U))((void *)(*(RP  *)(I1025 + 40U)), (((*(scalar  *)(I1025 + 2U)) >> I1882) & 3));
                }
                I1025 = I1885;
            };
            *(pcode + 168 + 0U) = 0;
            rmaRemoveNonEdgeLoads(pcode + 168);
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 208);
        pcode += 216;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate12_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate12(pcode, val);
}
void  rmaPropagate16 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        unsigned long long * I1878 = derivedClk + (4U * X4val[val]);
        memcpy(pcode + 2 + 4, I1878, 25U);
    }
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 32);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        I1184 = X4val[val];
        I1627 = *(pcode + 40);
        *(pcode + 40) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 4560) {
            *(RmaTimeStamp  *)(pcode + 48) = (RmaTimeStamp )vcs_clocks;
        }
    }
    pcode += 56;
    {
        EBLK  * I1455;
        *((*(UB  **)(pcode + 8)) + 1) = X4val[val];
        I1455 = (EBLK  *)(pcode + 0);
        if (I1455->I673 == 0) {
            struct dummyq_struct * pQ;
            U  I1458;
            I1458 = 0;
            pQ = (struct dummyq_struct *)ref_vcs_clocks;
            EBLK  * I1669 = (EBLK  *)pvcsGetLastEventEblk(I1458);
            I1455->I673 = pQ->I1388;
            pQ->I1388 = I1455;
            {
                (pQ->semilerOptQueuesFlag |= (0x1 << 2));
            }
            if (0 && rmaProfEvtProp) {
                vcs_simpSetEBlkEvtID(I1455);
            }
            I1455 = I1669;
            if (!(I1455->I673)) {
                if ((semilerOpt != 0) && (I1669 == I1455)) {
                }
                else {
                    pQ->I1377->I673 = I1455;
                    pQ->I1377 = I1455;
                }
                I1455->I673 = ((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 48);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 12) {
            (*(FP  *)(pcode + 56))(*(void **)(pcode + 64), I235);
        }
        if (I1654 & 8704) {
            (*(FP  *)(pcode + 72))(*(void **)(pcode + 80), I235);
        }
        if (I1654 & 192) {
            (*(FP  *)(pcode + 88))(*(void **)(pcode + 96), I235);
        }
        if (I1654 & 4352) {
            (*(FP  *)(pcode + 104))(*(void **)(pcode + 112), I235);
        }
        if (I1654 & 18432) {
            (*(FP  *)(pcode + 120))(*(void **)(pcode + 128), I235);
        }
        if (I1654 & 2) {
            (*(FP  *)(pcode + 136))(*(void **)(pcode + 144), I235);
        }
        if (I1654 & 16) {
            (*(FP  *)(pcode + 152))(*(void **)(pcode + 160), I235);
        }
        *(pcode + 48U) = I1184;
    }
    {
        scalar  I1880 = X4val[val];
        scalar  I1881 = *(scalar  *)(pcode + 168 + 2U);
        *(scalar  *)(pcode + 168 + 2U) = I1880;
        UB  * I1025 = *(UB  **)(pcode + 168 + 8U);
        if (I1025) {
            U  I1882 = I1880 * 2;
            U  I1883 = 1 << ((I1881 << 2) + I1880);
            *(pcode + 168 + 0U) = 1;
            while (I1025){
                UB  * I1885 = *(UB  **)(I1025 + 16U);
                if ((*(US  *)(I1025 + 0U)) & I1883) {
                    *(*(UB  **)(I1025 + 48U)) = 1;
                    (*(FP  *)(I1025 + 32U))((void *)(*(RP  *)(I1025 + 40U)), (((*(scalar  *)(I1025 + 2U)) >> I1882) & 3));
                }
                I1025 = I1885;
            };
            *(pcode + 168 + 0U) = 0;
            rmaRemoveNonEdgeLoads(pcode + 168);
        }
    }
    pcode += 208;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate16_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate16(pcode, val);
}
void  rmaPropagate18 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        unsigned long long * I1878 = derivedClk + (4U * X4val[val]);
        memcpy(pcode + 2 + 4, I1878, 25U);
    }
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 32);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        I1184 = X4val[val];
        I1627 = *(pcode + 40);
        *(pcode + 40) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 4560) {
            *(RmaTimeStamp  *)(pcode + 48) = (RmaTimeStamp )vcs_clocks;
        }
    }
    pcode += 56;
    {
        EBLK  * I1455;
        *((*(UB  **)(pcode + 8)) + 1) = X4val[val];
        I1455 = (EBLK  *)(pcode + 0);
        if (I1455->I673 == 0) {
            struct dummyq_struct * pQ;
            U  I1458;
            I1458 = 0;
            pQ = (struct dummyq_struct *)ref_vcs_clocks;
            EBLK  * I1669 = (EBLK  *)pvcsGetLastEventEblk(I1458);
            I1455->I673 = pQ->I1388;
            pQ->I1388 = I1455;
            {
                (pQ->semilerOptQueuesFlag |= (0x1 << 2));
            }
            if (0 && rmaProfEvtProp) {
                vcs_simpSetEBlkEvtID(I1455);
            }
            I1455 = I1669;
            if (!(I1455->I673)) {
                if ((semilerOpt != 0) && (I1669 == I1455)) {
                }
                else {
                    pQ->I1377->I673 = I1455;
                    pQ->I1377 = I1455;
                }
                I1455->I673 = ((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 48);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 12) {
            (*(FP  *)(pcode + 56))(*(void **)(pcode + 64), I235);
        }
        if (I1654 & 8704) {
            (*(FP  *)(pcode + 72))(*(void **)(pcode + 80), I235);
        }
        if (I1654 & 192) {
            (*(FP  *)(pcode + 88))(*(void **)(pcode + 96), I235);
        }
        if (I1654 & 4352) {
            (*(FP  *)(pcode + 104))(*(void **)(pcode + 112), I235);
        }
        if (I1654 & 18432) {
            (*(FP  *)(pcode + 120))(*(void **)(pcode + 128), I235);
        }
        if (I1654 & 2) {
            (*(FP  *)(pcode + 136))(*(void **)(pcode + 144), I235);
        }
        if (I1654 & 16) {
            (*(FP  *)(pcode + 152))(*(void **)(pcode + 160), I235);
        }
        *(pcode + 48U) = I1184;
    }
    {
        scalar  I1880 = X4val[val];
        scalar  I1881 = *(scalar  *)(pcode + 168 + 2U);
        *(scalar  *)(pcode + 168 + 2U) = I1880;
        UB  * I1025 = *(UB  **)(pcode + 168 + 8U);
        if (I1025) {
            U  I1882 = I1880 * 2;
            U  I1883 = 1 << ((I1881 << 2) + I1880);
            *(pcode + 168 + 0U) = 1;
            while (I1025){
                UB  * I1885 = *(UB  **)(I1025 + 16U);
                if ((*(US  *)(I1025 + 0U)) & I1883) {
                    *(*(UB  **)(I1025 + 48U)) = 1;
                    (*(FP  *)(I1025 + 32U))((void *)(*(RP  *)(I1025 + 40U)), (((*(scalar  *)(I1025 + 2U)) >> I1882) & 3));
                }
                I1025 = I1885;
            };
            *(pcode + 168 + 0U) = 0;
            rmaRemoveNonEdgeLoads(pcode + 168);
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 208);
        pcode += 216;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate18_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate18(pcode, val);
}
void  rmaPropagate23 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    scalar  I1606;
    scalar  I1607;
    scalar  I1184;
    scalar  I1608;
    scalar  * I1609;
    UB  * I1610;
    U  I1611 = 0;
    U  I1612;
    U  I1613 = 0;
    scalar  I1614;
    US  * I1615;
    US  I1616 = 0;
    UB  * I1129;
    UB  * I1617;
    RP  I1618 = 0;
    I1612 = (U )*(pcode + 24 + 3);
    *(pcode + 24 + 3) = 0;
    I1617 = pcode + 24;
    if (I1612) {
        *I1617 = val;
    }
    else {
        I1607 = *(pcode + 24 + 2);
        I1606 = val;
        if (I1606 != I1607) {
            I1611 = 1;
        }
        if (I1607 == 0xff) {
            I1607 = 0;
            I1613 = 1;
        }
        I1129 = pcode + 24 + 1U;
        *I1129 = I1606;
        if (!I1611) {
            return  ;
        }
        *(pcode + 24 + 2) = I1606;
    }
    if (!I1612) {
        I1609 = *(scalar  **)((*(RP  **)(pcode + 32)));
        I1184 = *(I1609 + I1606);
        *I1617 = I1184;
        val = I1184;
        I1608 = *(I1609 + I1607);
        I1614 = *(I1609 + (28));
        I1610 = (UB  *)(*((*(RP  **)(pcode + 32)) + 1));
        I1615 = edgeActionT + (9 * ((I1607 << 7U) + (I1606 << 2U) + I1614));
        I1616 = I1615[0];
    }
    if (I1611) {
        rmaScheduleGatedClockEdgeLoadNew(pcode + 40, I1615, 1U, I1610, I1610, I1606, I1607);
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 104);
        {
            RP  I1569 = 1;
            if (I1569 && I1611) {
                startBit = *(U  *)(pcode + 96);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(31U << startBit);
                state |= I1606 << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode += 112;
        pcode1 = *(UB  **)(pcode + 8);
        {
            RP  I1569 = 1;
            if (I1569 && I1611) {
                startBit = *(U  *)(pcode + 0);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(31U << startBit);
                state |= I1606 << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    if (!I1612 && !(I1616 & ~33825) && !I1613) {
        return  ;
    }
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 16);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 24);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 32;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate23_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 24 + 1U);
    *(pcode + 24 + 1U) = 24;
    rmaPropagate23(pcode, val);
}
void  rmaPropagate25 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        unsigned long long * I1878 = derivedClk + (4U * X4val[val]);
        memcpy(pcode + 1 + 4, I1878, 25U);
    }
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 32);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        I1184 = X4val[val];
        I1627 = *(pcode + 40);
        *(pcode + 40) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 8718) {
            *(RmaTimeStamp  *)(pcode + 48) = (RmaTimeStamp )vcs_clocks;
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 56);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 12) {
            (*(FP  *)(pcode + 64))(*(void **)(pcode + 72), I235);
        }
        if (I1654 & 8704) {
            (*(FP  *)(pcode + 80))(*(void **)(pcode + 88), I235);
        }
        if (I1654 & 192) {
            (*(FP  *)(pcode + 96))(*(void **)(pcode + 104), I235);
        }
        if (I1654 & 4352) {
            (*(FP  *)(pcode + 112))(*(void **)(pcode + 120), I235);
        }
        if (I1654 & 18432) {
            (*(FP  *)(pcode + 128))(*(void **)(pcode + 136), I235);
        }
        if (I1654 & 2) {
            (*(FP  *)(pcode + 144))(*(void **)(pcode + 152), I235);
        }
        if (I1654 & 16) {
            (*(FP  *)(pcode + 160))(*(void **)(pcode + 168), I235);
        }
        *(pcode + 56U) = I1184;
    }
    {
        scalar  I1880 = X4val[val];
        scalar  I1881 = *(scalar  *)(pcode + 176 + 2U);
        *(scalar  *)(pcode + 176 + 2U) = I1880;
        UB  * I1025 = *(UB  **)(pcode + 176 + 8U);
        if (I1025) {
            U  I1882 = I1880 * 2;
            U  I1883 = 1 << ((I1881 << 2) + I1880);
            *(pcode + 176 + 0U) = 1;
            while (I1025){
                UB  * I1885 = *(UB  **)(I1025 + 16U);
                if ((*(US  *)(I1025 + 0U)) & I1883) {
                    *(*(UB  **)(I1025 + 48U)) = 1;
                    (*(FP  *)(I1025 + 32U))((void *)(*(RP  *)(I1025 + 40U)), (((*(scalar  *)(I1025 + 2U)) >> I1882) & 3));
                }
                I1025 = I1885;
            };
            *(pcode + 176 + 0U) = 0;
            rmaRemoveNonEdgeLoads(pcode + 176);
        }
    }
    pcode += 216;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate25_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate25(pcode, val);
}
void  rmaPropagate27 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        unsigned long long * I1878 = derivedClk + (4U * X4val[val]);
        memcpy(pcode + 1 + 4, I1878, 25U);
    }
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 32);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        I1184 = X4val[val];
        I1627 = *(pcode + 40);
        *(pcode + 40) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 8718) {
            *(RmaTimeStamp  *)(pcode + 48) = (RmaTimeStamp )vcs_clocks;
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 56);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 12) {
            (*(FP  *)(pcode + 64))(*(void **)(pcode + 72), I235);
        }
        if (I1654 & 8704) {
            (*(FP  *)(pcode + 80))(*(void **)(pcode + 88), I235);
        }
        if (I1654 & 192) {
            (*(FP  *)(pcode + 96))(*(void **)(pcode + 104), I235);
        }
        if (I1654 & 4352) {
            (*(FP  *)(pcode + 112))(*(void **)(pcode + 120), I235);
        }
        if (I1654 & 18432) {
            (*(FP  *)(pcode + 128))(*(void **)(pcode + 136), I235);
        }
        if (I1654 & 2) {
            (*(FP  *)(pcode + 144))(*(void **)(pcode + 152), I235);
        }
        if (I1654 & 16) {
            (*(FP  *)(pcode + 160))(*(void **)(pcode + 168), I235);
        }
        *(pcode + 56U) = I1184;
    }
    {
        scalar  I1880 = X4val[val];
        scalar  I1881 = *(scalar  *)(pcode + 176 + 2U);
        *(scalar  *)(pcode + 176 + 2U) = I1880;
        UB  * I1025 = *(UB  **)(pcode + 176 + 8U);
        if (I1025) {
            U  I1882 = I1880 * 2;
            U  I1883 = 1 << ((I1881 << 2) + I1880);
            *(pcode + 176 + 0U) = 1;
            while (I1025){
                UB  * I1885 = *(UB  **)(I1025 + 16U);
                if ((*(US  *)(I1025 + 0U)) & I1883) {
                    *(*(UB  **)(I1025 + 48U)) = 1;
                    (*(FP  *)(I1025 + 32U))((void *)(*(RP  *)(I1025 + 40U)), (((*(scalar  *)(I1025 + 2U)) >> I1882) & 3));
                }
                I1025 = I1885;
            };
            *(pcode + 176 + 0U) = 0;
            rmaRemoveNonEdgeLoads(pcode + 176);
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 216);
        pcode += 224;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate27_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate27(pcode, val);
}
void  rmaPropagate28 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    scalar  I1606;
    scalar  I1607;
    scalar  I1184;
    scalar  I1608;
    scalar  * I1609;
    UB  * I1610;
    U  I1611 = 0;
    U  I1612;
    U  I1613 = 0;
    scalar  I1614;
    US  * I1615;
    US  I1616 = 0;
    UB  * I1129;
    UB  * I1617;
    RP  I1618 = 0;
    I1612 = (U )*(pcode + 24 + 3);
    *(pcode + 24 + 3) = 0;
    I1617 = pcode + 24;
    if (I1612) {
        *I1617 = val;
    }
    else {
        I1607 = *(pcode + 24 + 2);
        I1606 = val;
        if (I1606 != I1607) {
            I1611 = 1;
        }
        if (I1607 == 0xff) {
            I1607 = 0;
            I1613 = 1;
        }
        I1129 = pcode + 24 + 1U;
        *I1129 = I1606;
        if (!I1611) {
            return  ;
        }
        *(pcode + 24 + 2) = I1606;
    }
    if (!I1612) {
        I1609 = *(scalar  **)((*(RP  **)(pcode + 32)));
        I1184 = *(I1609 + I1606);
        *I1617 = I1184;
        val = I1184;
        I1608 = *(I1609 + I1607);
        I1614 = *(I1609 + (28));
        I1610 = (UB  *)(*((*(RP  **)(pcode + 32)) + 1));
        I1615 = edgeActionT + (9 * ((I1607 << 7U) + (I1606 << 2U) + I1614));
        I1616 = I1615[0];
    }
    if (I1611) {
        rmaScheduleGatedClockEdgeLoadNew(pcode + 40, I1615, 1U, I1610, I1610, I1606, I1607);
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 104);
        {
            RP  I1569 = 1;
            if (I1569 && I1611) {
                startBit = *(U  *)(pcode + 96);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(31U << startBit);
                state |= I1606 << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode += 112;
        pcode1 = *(UB  **)(pcode + 8);
        {
            RP  I1569 = 1;
            if (I1569 && I1611) {
                startBit = *(U  *)(pcode + 0);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(31U << startBit);
                state |= I1606 << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    if (!I1612 && !(I1616 & ~33825) && !I1613) {
        return  ;
    }
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 16);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 24);
        pcode += 32;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate28_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 24 + 1U);
    *(pcode + 24 + 1U) = 24;
    rmaPropagate28(pcode, val);
}
void  rmaPropagate29 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    scalar  I1606;
    scalar  I1607;
    scalar  I1184;
    scalar  I1608;
    scalar  * I1609;
    UB  * I1610;
    U  I1611 = 0;
    U  I1612;
    U  I1613 = 0;
    scalar  I1614;
    US  * I1615;
    US  I1616 = 0;
    UB  * I1129;
    UB  * I1617;
    RP  I1618 = 0;
    I1612 = (U )*(pcode + 24 + 3);
    *(pcode + 24 + 3) = 0;
    I1617 = pcode + 24;
    if (I1612) {
        *I1617 = val;
    }
    else {
        I1607 = *(pcode + 24 + 2);
        I1606 = val;
        if (I1606 != I1607) {
            I1611 = 1;
        }
        if (I1607 == 0xff) {
            I1607 = 0;
            I1613 = 1;
        }
        I1129 = pcode + 24 + 1U;
        *I1129 = I1606;
        if (!I1611) {
            return  ;
        }
        *(pcode + 24 + 2) = I1606;
    }
    if (!I1612) {
        I1609 = *(scalar  **)((*(RP  **)(pcode + 32)));
        I1184 = *(I1609 + I1606);
        *I1617 = I1184;
        val = I1184;
        I1608 = *(I1609 + I1607);
        I1614 = *(I1609 + (28));
        I1610 = (UB  *)(*((*(RP  **)(pcode + 32)) + 1));
        I1615 = edgeActionT + (9 * ((I1607 << 7U) + (I1606 << 2U) + I1614));
        I1616 = I1615[0];
    }
    if (I1611) {
        rmaScheduleGatedClockEdgeLoadNew(pcode + 40, I1615, 1U, I1610, I1610, I1606, I1607);
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 104);
        {
            RP  I1569 = 1;
            if (I1569 && I1611) {
                startBit = *(U  *)(pcode + 96);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(31U << startBit);
                state |= I1606 << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode += 112;
        pcode1 = *(UB  **)(pcode + 8);
        {
            RP  I1569 = 1;
            if (I1569 && I1611) {
                startBit = *(U  *)(pcode + 0);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(31U << startBit);
                state |= I1606 << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    if (!I1612 && !(I1616 & ~33825) && !I1613) {
        return  ;
    }
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 16);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 24);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 32);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 40);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 48;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate29_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 24 + 1U);
    *(pcode + 24 + 1U) = 24;
    rmaPropagate29(pcode, val);
}
void  rmaPropagate85 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 8718) {
            *(RmaTimeStamp  *)(pcode + 24) = (RmaTimeStamp )vcs_clocks;
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 32);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 18) {
            if (I1654 & 2) {
                (*(FP  *)(pcode + 40))(*(void **)(pcode + 48), I235);
            }
        }
        else {
            U  I1552;
            U  I657;
            U  I1733;
            U  * I1735;
            UB  * pcode1;
            pcode1 = (UB  *)(*(UP  *)(pcode + 48) & ~3);
            I657 = *(U  *)pcode1;
            I1735 = (U  *)(pcode1 + sizeof(U ));
            I1733 = (I657 + 31) >> 5;
            pcode1 += sizeof(U ) * (1 + I1733);
            for (I1552 = 0; I1552 < I1733; I1552++) {
                if (I1552 == I1733 - 1 && (I657 % 32)) {
                    I1735[I1552] = (1 << (I657 % 32)) - 1;
                }
                else {
                    I1735[I1552] = (U )-1;
                }
            }
            pcode1 = (UB  *)((((RP )pcode1) + 7) & (~7));
            for (; I657 > 0; I657--) {
                (*(FP  *)(pcode1))(*(void **)(pcode1 + 8LU), I235);
                pcode1 += 16;
            }
        }
        *(pcode + 32U) = I1184;
    }
    pcode += 56;
    {
        EBLK  * I1455;
        *((*(UB  **)(pcode + 8)) + 1) = X4val[val];
        I1455 = (EBLK  *)(pcode + 0);
        if (I1455->I673 == 0) {
            struct dummyq_struct * pQ;
            U  I1458;
            I1458 = 0;
            pQ = (struct dummyq_struct *)ref_vcs_clocks;
            EBLK  * I1669 = (EBLK  *)pvcsGetLastEventEblk(I1458);
            I1455->I673 = pQ->I1388;
            pQ->I1388 = I1455;
            {
                (pQ->semilerOptQueuesFlag |= (0x1 << 2));
            }
            if (0 && rmaProfEvtProp) {
                vcs_simpSetEBlkEvtID(I1455);
            }
            I1455 = I1669;
            if (!(I1455->I673)) {
                if ((semilerOpt != 0) && (I1669 == I1455)) {
                }
                else {
                    pQ->I1377->I673 = I1455;
                    pQ->I1377 = I1455;
                }
                I1455->I673 = ((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
    pcode += 48;
    *((*(UB  **)(pcode + 8U)) + 1) = X4val[val];
    {
        EBLK  * I1455;
        I1455 = (EBLK  *)(pcode + 0);
        EBLK  * I1669;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1669 = (EBLK  *)pvcsGetLastEventEblk(I1458);
        if (I1455->I673 == 0) {
            I1455->I673 = pQ->I1387;
            pQ->I1387 = I1455;
            {
                (pQ->semilerOptQueuesFlag |= (0x1 << 2));
            }
            I1455 = I1669;
            if (!(I1455->I673)) {
                if ((semilerOpt != 0) && (I1669 == I1455)) {
                }
                else {
                    pQ->I1377->I673 = I1455;
                    pQ->I1377 = I1455;
                }
                I1455->I673 = ((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
    {
        (*(FP  *)(pcode + 56))(*(UB  **)(pcode + 64), globalTable1Input[(*(U  *)(pcode + 48) >> 8) + val]);
    }
    pcode += 72;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate85_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate85(pcode, val);
}
void  rmaPropagate87 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        U  I1705;
        U  I1706;
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 4560) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 24), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 24));
            }
        }
        if (I1654 & 8718) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 72), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 72));
            }
        }
    }
    pcode += 120;
    {
        EBLK  * I1455;
        *((*(UB  **)(pcode + 8)) + 1) = X4val[val];
        I1455 = (EBLK  *)(pcode + 0);
        if (I1455->I673 == 0) {
            struct dummyq_struct * pQ;
            U  I1458;
            I1458 = 0;
            pQ = (struct dummyq_struct *)ref_vcs_clocks;
            EBLK  * I1669 = (EBLK  *)pvcsGetLastEventEblk(I1458);
            I1455->I673 = pQ->I1388;
            pQ->I1388 = I1455;
            {
                (pQ->semilerOptQueuesFlag |= (0x1 << 2));
            }
            if (0 && rmaProfEvtProp) {
                vcs_simpSetEBlkEvtID(I1455);
            }
            I1455 = I1669;
            if (!(I1455->I673)) {
                if ((semilerOpt != 0) && (I1669 == I1455)) {
                }
                else {
                    pQ->I1377->I673 = I1455;
                    pQ->I1377 = I1455;
                }
                I1455->I673 = ((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 48);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 56);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 64))(*(UB  **)(pcode + 72), I1473);
    }
    pcode += 80;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate87_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate87(pcode, val);
}
void  rmaPropagate88 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    if (*(pcode + 0) == val) {
        return  ;
    }
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 16);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 24);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 32);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 40))(*(UB  **)(pcode + 48), I1473);
    }
    pcode += 56;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate89 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 24U))(*(UB  **)(pcode + 32U), *((*(UB  **)(pcode + 16U)) + X4val[val]));
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 40);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 48);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 56);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 64))(*(UB  **)(pcode + 72), I1473);
    }
    pcode += 80;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate89_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate89(pcode, val);
}
void  rmaPropagate94 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 8718) {
            *(RmaTimeStamp  *)(pcode + 24) = (RmaTimeStamp )vcs_clocks;
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 32);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 18) {
            if (I1654 & 2) {
                (*(FP  *)(pcode + 40))(*(void **)(pcode + 48), I235);
            }
        }
        else {
            U  I1552;
            U  I657;
            U  I1733;
            U  * I1735;
            UB  * pcode1;
            pcode1 = (UB  *)(*(UP  *)(pcode + 48) & ~3);
            I657 = *(U  *)pcode1;
            I1735 = (U  *)(pcode1 + sizeof(U ));
            I1733 = (I657 + 31) >> 5;
            pcode1 += sizeof(U ) * (1 + I1733);
            for (I1552 = 0; I1552 < I1733; I1552++) {
                if (I1552 == I1733 - 1 && (I657 % 32)) {
                    I1735[I1552] = (1 << (I657 % 32)) - 1;
                }
                else {
                    I1735[I1552] = (U )-1;
                }
            }
            pcode1 = (UB  *)((((RP )pcode1) + 7) & (~7));
            for (; I657 > 0; I657--) {
                (*(FP  *)(pcode1))(*(void **)(pcode1 + 8LU), I235);
                pcode1 += 16;
            }
        }
        *(pcode + 32U) = I1184;
    }
    pcode += 56;
    {
        EBLK  * I1455;
        *((*(UB  **)(pcode + 8)) + 1) = X4val[val];
        I1455 = (EBLK  *)(pcode + 0);
        if (I1455->I673 == 0) {
            struct dummyq_struct * pQ;
            U  I1458;
            I1458 = 0;
            pQ = (struct dummyq_struct *)ref_vcs_clocks;
            EBLK  * I1669 = (EBLK  *)pvcsGetLastEventEblk(I1458);
            I1455->I673 = pQ->I1388;
            pQ->I1388 = I1455;
            {
                (pQ->semilerOptQueuesFlag |= (0x1 << 2));
            }
            if (0 && rmaProfEvtProp) {
                vcs_simpSetEBlkEvtID(I1455);
            }
            I1455 = I1669;
            if (!(I1455->I673)) {
                if ((semilerOpt != 0) && (I1669 == I1455)) {
                }
                else {
                    pQ->I1377->I673 = I1455;
                    pQ->I1377 = I1455;
                }
                I1455->I673 = ((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
    {
        (*(FP  *)(pcode + 56))(*(UB  **)(pcode + 64), globalTable1Input[(*(U  *)(pcode + 48) >> 8) + val]);
    }
    pcode += 72;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate94_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate94(pcode, val);
}
void  rmaPropagate95 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    if (*(pcode + 0) == val) {
        return  ;
    }
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 16);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 24))(*(UB  **)(pcode + 32), I1473);
    }
    pcode += 40;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate96 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 24U))(*(UB  **)(pcode + 32U), *((*(UB  **)(pcode + 16U)) + X4val[val]));
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 40);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 48))(*(UB  **)(pcode + 56), I1473);
    }
    pcode += 64;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate96_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate96(pcode, val);
}
void  rmaPropagate102 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 8718) {
            *(RmaTimeStamp  *)(pcode + 24) = (RmaTimeStamp )vcs_clocks;
        }
    }
    {
        (*(FP  *)(pcode + 40))(*(UB  **)(pcode + 48), globalTable1Input[(*(U  *)(pcode + 32) >> 8) + val]);
    }
    {
        (*(FP  *)(pcode + 64))(*(UB  **)(pcode + 72), globalTable1Input[(*(U  *)(pcode + 56) >> 8) + val]);
    }
    pcode += 80;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate102_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate102(pcode, val);
}
void  rmaPropagate104 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 16);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 18) {
            if (I1654 & 16) {
                (*(FP  *)(pcode + 24))(*(void **)(pcode + 32), I235);
            }
        }
        else {
            U  I1552;
            U  I657;
            U  I1733;
            U  * I1735;
            UB  * pcode1;
            pcode1 = (UB  *)(*(UP  *)(pcode + 32) & ~3);
            I657 = *(U  *)pcode1;
            I1735 = (U  *)(pcode1 + sizeof(U ));
            I1733 = (I657 + 31) >> 5;
            pcode1 += sizeof(U ) * (1 + I1733);
            for (I1552 = 0; I1552 < I1733; I1552++) {
                if (I1552 == I1733 - 1 && (I657 % 32)) {
                    I1735[I1552] = (1 << (I657 % 32)) - 1;
                }
                else {
                    I1735[I1552] = (U )-1;
                }
            }
            pcode1 = (UB  *)((((RP )pcode1) + 7) & (~7));
            for (; I657 > 0; I657--) {
                (*(FP  *)(pcode1))(*(void **)(pcode1 + 8LU), I235);
                pcode1 += 16;
            }
        }
        *(pcode + 16U) = I1184;
    }
    {
        (*(FP  *)(pcode + 48))(*(UB  **)(pcode + 56), globalTable1Input[(*(U  *)(pcode + 40) >> 8) + val]);
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 64);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 72);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 80;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate104_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate104(pcode, val);
}
void  rmaPropagate110 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 24U))(*(UB  **)(pcode + 32U), *((*(UB  **)(pcode + 16U)) + X4val[val]));
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 40);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 48);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 56))(*(UB  **)(pcode + 64), I1473);
    }
    pcode += 72;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate110_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate110(pcode, val);
}
void  rmaPropagate113 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    if (*(pcode + 0) == val) {
        return  ;
    }
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 16);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 24);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 32;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate116 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 16);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 18) {
            if (I1654 & 16) {
                (*(FP  *)(pcode + 24))(*(void **)(pcode + 32), I235);
            }
        }
        else {
            U  I1552;
            U  I657;
            U  I1733;
            U  * I1735;
            UB  * pcode1;
            pcode1 = (UB  *)(*(UP  *)(pcode + 32) & ~3);
            I657 = *(U  *)pcode1;
            I1735 = (U  *)(pcode1 + sizeof(U ));
            I1733 = (I657 + 31) >> 5;
            pcode1 += sizeof(U ) * (1 + I1733);
            for (I1552 = 0; I1552 < I1733; I1552++) {
                if (I1552 == I1733 - 1 && (I657 % 32)) {
                    I1735[I1552] = (1 << (I657 % 32)) - 1;
                }
                else {
                    I1735[I1552] = (U )-1;
                }
            }
            pcode1 = (UB  *)((((RP )pcode1) + 7) & (~7));
            for (; I657 > 0; I657--) {
                (*(FP  *)(pcode1))(*(void **)(pcode1 + 8LU), I235);
                pcode1 += 16;
            }
        }
        *(pcode + 16U) = I1184;
    }
    {
        (*(FP  *)(pcode + 48))(*(UB  **)(pcode + 56), globalTable1Input[(*(U  *)(pcode + 40) >> 8) + val]);
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 64);
        pcode += 72;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate116_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate116(pcode, val);
}
void  rmaPropagate118 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 24U))(*(UB  **)(pcode + 32U), *((*(UB  **)(pcode + 16U)) + X4val[val]));
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 40);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 48);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 56))(*(UB  **)(pcode + 64), I1473);
    }
    pcode += 72;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate118_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate118(pcode, val);
}
void  rmaPropagate119 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    if (*(pcode + 0) == val) {
        return  ;
    }
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 16);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 24);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 32;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate121 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 4560) {
            *(RmaTimeStamp  *)(pcode + 24) = (RmaTimeStamp )vcs_clocks;
        }
    }
    {
        (*(FP  *)(pcode + 40))(*(UB  **)(pcode + 48), globalTable1Input[(*(U  *)(pcode + 32) >> 8) + val]);
    }
    {
        (*(FP  *)(pcode + 64))(*(UB  **)(pcode + 72), globalTable1Input[(*(U  *)(pcode + 56) >> 8) + val]);
    }
    pcode += 80;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate121_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate121(pcode, val);
}
void  rmaPropagate123 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 16);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 18) {
            if (I1654 & 16) {
                (*(FP  *)(pcode + 24))(*(void **)(pcode + 32), I235);
            }
        }
        else {
            U  I1552;
            U  I657;
            U  I1733;
            U  * I1735;
            UB  * pcode1;
            pcode1 = (UB  *)(*(UP  *)(pcode + 32) & ~3);
            I657 = *(U  *)pcode1;
            I1735 = (U  *)(pcode1 + sizeof(U ));
            I1733 = (I657 + 31) >> 5;
            pcode1 += sizeof(U ) * (1 + I1733);
            for (I1552 = 0; I1552 < I1733; I1552++) {
                if (I1552 == I1733 - 1 && (I657 % 32)) {
                    I1735[I1552] = (1 << (I657 % 32)) - 1;
                }
                else {
                    I1735[I1552] = (U )-1;
                }
            }
            pcode1 = (UB  *)((((RP )pcode1) + 7) & (~7));
            for (; I657 > 0; I657--) {
                (*(FP  *)(pcode1))(*(void **)(pcode1 + 8LU), I235);
                pcode1 += 16;
            }
        }
        *(pcode + 16U) = I1184;
    }
    {
        (*(FP  *)(pcode + 48))(*(UB  **)(pcode + 56), globalTable1Input[(*(U  *)(pcode + 40) >> 8) + val]);
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 64);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 72);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 80);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 88;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate123_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate123(pcode, val);
}
void  rmaPropagate124 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    if (*(pcode + 0) == val) {
        return  ;
    }
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 16);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 24);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 32))(*(UB  **)(pcode + 40), I1473);
    }
    pcode += 48;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate125 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 24U))(*(UB  **)(pcode + 32U), *((*(UB  **)(pcode + 16U)) + X4val[val]));
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 40);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 48))(*(UB  **)(pcode + 56), I1473);
    }
    pcode += 64;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate125_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate125(pcode, val);
}
void  rmaPropagate129 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        (*(FP  *)(pcode + 24))(*(UB  **)(pcode + 32), globalTable1Input[(*(U  *)(pcode + 16) >> 8) + val]);
    }
    {
        (*(FP  *)(pcode + 48))(*(UB  **)(pcode + 56), globalTable1Input[(*(U  *)(pcode + 40) >> 8) + val]);
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 64))(*(UB  **)(pcode + 72), I1473);
    }
    pcode += 80;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate129_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate129(pcode, val);
}
void  rmaPropagate131 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 16);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 18) {
            if (I1654 & 16) {
                (*(FP  *)(pcode + 24))(*(void **)(pcode + 32), I235);
            }
        }
        else {
            U  I1552;
            U  I657;
            U  I1733;
            U  * I1735;
            UB  * pcode1;
            pcode1 = (UB  *)(*(UP  *)(pcode + 32) & ~3);
            I657 = *(U  *)pcode1;
            I1735 = (U  *)(pcode1 + sizeof(U ));
            I1733 = (I657 + 31) >> 5;
            pcode1 += sizeof(U ) * (1 + I1733);
            for (I1552 = 0; I1552 < I1733; I1552++) {
                if (I1552 == I1733 - 1 && (I657 % 32)) {
                    I1735[I1552] = (1 << (I657 % 32)) - 1;
                }
                else {
                    I1735[I1552] = (U )-1;
                }
            }
            pcode1 = (UB  *)((((RP )pcode1) + 7) & (~7));
            for (; I657 > 0; I657--) {
                (*(FP  *)(pcode1))(*(void **)(pcode1 + 8LU), I235);
                pcode1 += 16;
            }
        }
        *(pcode + 16U) = I1184;
    }
    {
        (*(FP  *)(pcode + 48))(*(UB  **)(pcode + 56), globalTable1Input[(*(U  *)(pcode + 40) >> 8) + val]);
    }
    {
        (*(FP  *)(pcode + 72))(*(UB  **)(pcode + 80), globalTable1Input[(*(U  *)(pcode + 64) >> 8) + val]);
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 88);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 96);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 104))(*(UB  **)(pcode + 112), I1473);
    }
    pcode += 120;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate131_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate131(pcode, val);
}
void  rmaPropagate133 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    if (*(pcode + 0) == val) {
        return  ;
    }
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 16);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 24;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate137 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    pcode += 16;
    {
        EBLK  * I1455;
        *((*(UB  **)(pcode + 8)) + 1) = X4val[val];
        I1455 = (EBLK  *)(pcode + 0);
        if (I1455->I673 == 0) {
            struct dummyq_struct * pQ;
            U  I1458;
            I1458 = 0;
            pQ = (struct dummyq_struct *)ref_vcs_clocks;
            EBLK  * I1669 = (EBLK  *)pvcsGetLastEventEblk(I1458);
            I1455->I673 = pQ->I1388;
            pQ->I1388 = I1455;
            {
                (pQ->semilerOptQueuesFlag |= (0x1 << 2));
            }
            if (0 && rmaProfEvtProp) {
                vcs_simpSetEBlkEvtID(I1455);
            }
            I1455 = I1669;
            if (!(I1455->I673)) {
                if ((semilerOpt != 0) && (I1669 == I1455)) {
                }
                else {
                    pQ->I1377->I673 = I1455;
                    pQ->I1377 = I1455;
                }
                I1455->I673 = ((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
    {
        (*(FP  *)(pcode + 56))(*(UB  **)(pcode + 64), globalTable1Input[(*(U  *)(pcode + 48) >> 8) + val]);
    }
    {
        (*(FP  *)(pcode + 80))(*(UB  **)(pcode + 88), globalTable1Input[(*(U  *)(pcode + 72) >> 8) + val]);
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 96))(*(UB  **)(pcode + 104), I1473);
    }
    pcode += 112;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate137_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate137(pcode, val);
}
void  rmaPropagate139 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    pcode += 16;
    {
        EBLK  * I1455;
        *((*(UB  **)(pcode + 8)) + 1) = X4val[val];
        I1455 = (EBLK  *)(pcode + 0);
        if (I1455->I673 == 0) {
            struct dummyq_struct * pQ;
            U  I1458;
            I1458 = 0;
            pQ = (struct dummyq_struct *)ref_vcs_clocks;
            EBLK  * I1669 = (EBLK  *)pvcsGetLastEventEblk(I1458);
            I1455->I673 = pQ->I1388;
            pQ->I1388 = I1455;
            {
                (pQ->semilerOptQueuesFlag |= (0x1 << 2));
            }
            if (0 && rmaProfEvtProp) {
                vcs_simpSetEBlkEvtID(I1455);
            }
            I1455 = I1669;
            if (!(I1455->I673)) {
                if ((semilerOpt != 0) && (I1669 == I1455)) {
                }
                else {
                    pQ->I1377->I673 = I1455;
                    pQ->I1377 = I1455;
                }
                I1455->I673 = ((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
    {
        (*(FP  *)(pcode + 56))(*(UB  **)(pcode + 64), globalTable1Input[(*(U  *)(pcode + 48) >> 8) + val]);
    }
    {
        (*(FP  *)(pcode + 80))(*(UB  **)(pcode + 88), globalTable1Input[(*(U  *)(pcode + 72) >> 8) + val]);
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 96))(*(UB  **)(pcode + 104), I1473);
    }
    pcode += 112;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate139_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate139(pcode, val);
}
void  rmaPropagate141 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 16);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 18) {
            if (I1654 & 16) {
                (*(FP  *)(pcode + 24))(*(void **)(pcode + 32), I235);
            }
        }
        else {
            U  I1552;
            U  I657;
            U  I1733;
            U  * I1735;
            UB  * pcode1;
            pcode1 = (UB  *)(*(UP  *)(pcode + 32) & ~3);
            I657 = *(U  *)pcode1;
            I1735 = (U  *)(pcode1 + sizeof(U ));
            I1733 = (I657 + 31) >> 5;
            pcode1 += sizeof(U ) * (1 + I1733);
            for (I1552 = 0; I1552 < I1733; I1552++) {
                if (I1552 == I1733 - 1 && (I657 % 32)) {
                    I1735[I1552] = (1 << (I657 % 32)) - 1;
                }
                else {
                    I1735[I1552] = (U )-1;
                }
            }
            pcode1 = (UB  *)((((RP )pcode1) + 7) & (~7));
            for (; I657 > 0; I657--) {
                (*(FP  *)(pcode1))(*(void **)(pcode1 + 8LU), I235);
                pcode1 += 16;
            }
        }
        *(pcode + 16U) = I1184;
    }
    {
        (*(FP  *)(pcode + 48))(*(UB  **)(pcode + 56), globalTable1Input[(*(U  *)(pcode + 40) >> 8) + val]);
    }
    {
        (*(FP  *)(pcode + 72))(*(UB  **)(pcode + 80), globalTable1Input[(*(U  *)(pcode + 64) >> 8) + val]);
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 88);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 96);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 104);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        pcode += 112;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 0);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 8))(*(UB  **)(pcode + 16), I1473);
    }
    pcode += 24;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate141_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate141(pcode, val);
}
void  rmaPropagate144 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        U  I1705;
        U  I1706;
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 4560) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 24), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 24));
            }
        }
        if (I1654 & 8718) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 72), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 72));
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        pcode += 120;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 0);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 8);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 16))(*(UB  **)(pcode + 24), I1473);
    }
    pcode += 32;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate144_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate144(pcode, val);
}
void  rmaPropagate146 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        U  I1705;
        U  I1706;
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 4560) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 24), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 24));
            }
        }
        if (I1654 & 8718) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 72), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 72));
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        pcode += 120;
        (*(FP  *)(pcode + 0))(*(UB  **)(pcode + 8), I1473);
    }
    pcode += 16;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate146_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate146(pcode, val);
}
void  rmaPropagate147 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    if (*(pcode + 0) == val) {
        return  ;
    }
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 16);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 24))(*(UB  **)(pcode + 32), I1473);
    }
    pcode += 40;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate152 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 16))(*(UB  **)(pcode + 24), I1473);
    }
    pcode += 32;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate152_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate152(pcode, val);
}
void  rmaPropagate154 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        U  I1705;
        U  I1706;
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 4560) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 24), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 24));
            }
        }
        if (I1654 & 8718) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 72), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 72));
            }
        }
    }
    pcode += 120;
    {
        EBLK  * I1455;
        *((*(UB  **)(pcode + 8)) + 1) = X4val[val];
        I1455 = (EBLK  *)(pcode + 0);
        if (I1455->I673 == 0) {
            struct dummyq_struct * pQ;
            U  I1458;
            I1458 = 0;
            pQ = (struct dummyq_struct *)ref_vcs_clocks;
            EBLK  * I1669 = (EBLK  *)pvcsGetLastEventEblk(I1458);
            I1455->I673 = pQ->I1388;
            pQ->I1388 = I1455;
            {
                (pQ->semilerOptQueuesFlag |= (0x1 << 2));
            }
            if (0 && rmaProfEvtProp) {
                vcs_simpSetEBlkEvtID(I1455);
            }
            I1455 = I1669;
            if (!(I1455->I673)) {
                if ((semilerOpt != 0) && (I1669 == I1455)) {
                }
                else {
                    pQ->I1377->I673 = I1455;
                    pQ->I1377 = I1455;
                }
                I1455->I673 = ((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 48);
        pcode += 56;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 0))(*(UB  **)(pcode + 8), I1473);
    }
    pcode += 16;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate154_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate154(pcode, val);
}
void  rmaPropagate155 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    {
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        if (*(scalar  *)((pcode + 0) + 24U) != val) {
            RmaEblk  * I1455 = (RmaEblk  *)(pcode + 0);
            *(scalar  *)((pcode + 0) + 24U) = val;
            if (!(I1455->I673)) {
                pQ->I1355->I673 = (EBLK  *)I1455;
                pQ->I1355 = (EBLK  *)I1455;
                I1455->I673 = (RP )((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
}
void  rmaPropagate155_s0 (UB  * pcode, scalar  val)
{
    val = *(scalar  *)((pcode + 0) + 24U);
    if (*(pcode + 48) == val) {
        return  ;
    }
    *(pcode + 48) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 56);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 64);
        pcode += 72;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 8);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 0);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode1 = *(UB  **)(pcode + 24);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 16);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 32))(*(UB  **)(pcode + 40), I1473);
    }
    pcode += 48;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate156 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    if (*(pcode + 0) == val) {
        return  ;
    }
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 16))(*(UB  **)(pcode + 24), I1473);
    }
    pcode += 32;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate157 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 16))(*(UB  **)(pcode + 24), I1473);
    }
    pcode += 32;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate158 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 24U))(*(UB  **)(pcode + 32U), *((*(UB  **)(pcode + 16U)) + X4val[val]));
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 40);
        pcode += 48;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 8);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 0);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode1 = *(UB  **)(pcode + 24);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 16);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 32))(*(UB  **)(pcode + 40), I1473);
    }
    pcode += 48;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate158_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate158(pcode, val);
}
void  rmaPropagate159 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 24U))(*(UB  **)(pcode + 32U), *((*(UB  **)(pcode + 16U)) + X4val[val]));
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 40))(*(UB  **)(pcode + 48), I1473);
    }
    pcode += 56;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate159_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate159(pcode, val);
}
void  rmaPropagate164 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 4560) {
            *(RmaTimeStamp  *)(pcode + 24) = (RmaTimeStamp )vcs_clocks;
        }
    }
    pcode += 32;
    {
        EBLK  * I1455;
        *((*(UB  **)(pcode + 8)) + 1) = X4val[val];
        I1455 = (EBLK  *)(pcode + 0);
        if (I1455->I673 == 0) {
            struct dummyq_struct * pQ;
            U  I1458;
            I1458 = 0;
            pQ = (struct dummyq_struct *)ref_vcs_clocks;
            EBLK  * I1669 = (EBLK  *)pvcsGetLastEventEblk(I1458);
            I1455->I673 = pQ->I1388;
            pQ->I1388 = I1455;
            {
                (pQ->semilerOptQueuesFlag |= (0x1 << 2));
            }
            if (0 && rmaProfEvtProp) {
                vcs_simpSetEBlkEvtID(I1455);
            }
            I1455 = I1669;
            if (!(I1455->I673)) {
                if ((semilerOpt != 0) && (I1669 == I1455)) {
                }
                else {
                    pQ->I1377->I673 = I1455;
                    pQ->I1377 = I1455;
                }
                I1455->I673 = ((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
    {
        (*(FP  *)(pcode + 56))(*(UB  **)(pcode + 64), globalTable1Input[(*(U  *)(pcode + 48) >> 8) + val]);
    }
    pcode += 72;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate164_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate164(pcode, val);
}
void  rmaPropagate169 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 8718) {
            *(RmaTimeStamp  *)(pcode + 24) = (RmaTimeStamp )vcs_clocks;
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 32);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 18) {
            if (I1654 & 2) {
                (*(FP  *)(pcode + 40))(*(void **)(pcode + 48), I235);
            }
        }
        else {
            U  I1552;
            U  I657;
            U  I1733;
            U  * I1735;
            UB  * pcode1;
            pcode1 = (UB  *)(*(UP  *)(pcode + 48) & ~3);
            I657 = *(U  *)pcode1;
            I1735 = (U  *)(pcode1 + sizeof(U ));
            I1733 = (I657 + 31) >> 5;
            pcode1 += sizeof(U ) * (1 + I1733);
            for (I1552 = 0; I1552 < I1733; I1552++) {
                if (I1552 == I1733 - 1 && (I657 % 32)) {
                    I1735[I1552] = (1 << (I657 % 32)) - 1;
                }
                else {
                    I1735[I1552] = (U )-1;
                }
            }
            pcode1 = (UB  *)((((RP )pcode1) + 7) & (~7));
            for (; I657 > 0; I657--) {
                (*(FP  *)(pcode1))(*(void **)(pcode1 + 8LU), I235);
                pcode1 += 16;
            }
        }
        *(pcode + 32U) = I1184;
    }
    pcode += 56;
    {
        EBLK  * I1455;
        *((*(UB  **)(pcode + 8)) + 1) = X4val[val];
        I1455 = (EBLK  *)(pcode + 0);
        if (I1455->I673 == 0) {
            struct dummyq_struct * pQ;
            U  I1458;
            I1458 = 0;
            pQ = (struct dummyq_struct *)ref_vcs_clocks;
            EBLK  * I1669 = (EBLK  *)pvcsGetLastEventEblk(I1458);
            I1455->I673 = pQ->I1388;
            pQ->I1388 = I1455;
            {
                (pQ->semilerOptQueuesFlag |= (0x1 << 2));
            }
            if (0 && rmaProfEvtProp) {
                vcs_simpSetEBlkEvtID(I1455);
            }
            I1455 = I1669;
            if (!(I1455->I673)) {
                if ((semilerOpt != 0) && (I1669 == I1455)) {
                }
                else {
                    pQ->I1377->I673 = I1455;
                    pQ->I1377 = I1455;
                }
                I1455->I673 = ((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
    {
        (*(FP  *)(pcode + 56))(*(UB  **)(pcode + 64), globalTable1Input[(*(U  *)(pcode + 48) >> 8) + val]);
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 72);
        pcode += 80;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 0);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 8);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 16;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate169_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate169(pcode, val);
}
void  rmaPropagate171 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        U  I1705;
        U  I1706;
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 4560) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 24), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 24));
            }
        }
        if (I1654 & 8718) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 72), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 72));
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 120);
        pcode += 128;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 0))(*(UB  **)(pcode + 8), I1473);
    }
    pcode += 16;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate171_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate171(pcode, val);
}
void  rmaPropagate172 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    if (*(pcode + 0) == val) {
        return  ;
    }
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 16);
        pcode += 24;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 0);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 8);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 16;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate173 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    if (*(pcode + 0) == val) {
        return  ;
    }
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 16);
        pcode += 24;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 0);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 8);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 16))(*(UB  **)(pcode + 24), I1473);
    }
    pcode += 32;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate174 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 24U))(*(UB  **)(pcode + 32U), *((*(UB  **)(pcode + 16U)) + X4val[val]));
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 40);
        pcode += 48;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 0);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 8);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 16))(*(UB  **)(pcode + 24), I1473);
    }
    pcode += 32;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate174_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate174(pcode, val);
}
void  rmaPropagate176 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 8718) {
            *(RmaTimeStamp  *)(pcode + 24) = (RmaTimeStamp )vcs_clocks;
        }
    }
    pcode += 32;
    {
        EBLK  * I1455;
        *((*(UB  **)(pcode + 8)) + 1) = X4val[val];
        I1455 = (EBLK  *)(pcode + 0);
        if (I1455->I673 == 0) {
            struct dummyq_struct * pQ;
            U  I1458;
            I1458 = 0;
            pQ = (struct dummyq_struct *)ref_vcs_clocks;
            EBLK  * I1669 = (EBLK  *)pvcsGetLastEventEblk(I1458);
            I1455->I673 = pQ->I1388;
            pQ->I1388 = I1455;
            {
                (pQ->semilerOptQueuesFlag |= (0x1 << 2));
            }
            if (0 && rmaProfEvtProp) {
                vcs_simpSetEBlkEvtID(I1455);
            }
            I1455 = I1669;
            if (!(I1455->I673)) {
                if ((semilerOpt != 0) && (I1669 == I1455)) {
                }
                else {
                    pQ->I1377->I673 = I1455;
                    pQ->I1377 = I1455;
                }
                I1455->I673 = ((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
    {
        (*(FP  *)(pcode + 56))(*(UB  **)(pcode + 64), globalTable1Input[(*(U  *)(pcode + 48) >> 8) + val]);
    }
    pcode += 72;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate176_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate176(pcode, val);
}
void  rmaPropagate182 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        U  I1705;
        U  I1706;
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 4560) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 24), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 24));
            }
        }
        if (I1654 & 8718) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 72), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 72));
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        pcode += 120;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 0);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 8))(*(UB  **)(pcode + 16), I1473);
    }
    pcode += 24;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate182_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate182(pcode, val);
}
void  rmaPropagate184 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 16);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 18) {
            if (I1654 & 2) {
                (*(FP  *)(pcode + 24))(*(void **)(pcode + 32), I235);
            }
        }
        else {
            U  I1552;
            U  I657;
            U  I1733;
            U  * I1735;
            UB  * pcode1;
            pcode1 = (UB  *)(*(UP  *)(pcode + 32) & ~3);
            I657 = *(U  *)pcode1;
            I1735 = (U  *)(pcode1 + sizeof(U ));
            I1733 = (I657 + 31) >> 5;
            pcode1 += sizeof(U ) * (1 + I1733);
            for (I1552 = 0; I1552 < I1733; I1552++) {
                if (I1552 == I1733 - 1 && (I657 % 32)) {
                    I1735[I1552] = (1 << (I657 % 32)) - 1;
                }
                else {
                    I1735[I1552] = (U )-1;
                }
            }
            pcode1 = (UB  *)((((RP )pcode1) + 7) & (~7));
            for (; I657 > 0; I657--) {
                (*(FP  *)(pcode1))(*(void **)(pcode1 + 8LU), I235);
                pcode1 += 16;
            }
        }
        *(pcode + 16U) = I1184;
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 40);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 48);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 56);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 64;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate184_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate184(pcode, val);
}
void  rmaPropagate185 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    {
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        if (*(scalar  *)((pcode + 0) + 24U) != val) {
            RmaEblk  * I1455 = (RmaEblk  *)(pcode + 0);
            *(scalar  *)((pcode + 0) + 24U) = val;
            if (!(I1455->I673)) {
                pQ->I1355->I673 = (EBLK  *)I1455;
                pQ->I1355 = (EBLK  *)I1455;
                I1455->I673 = (RP )((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
}
void  rmaPropagate185_s0 (UB  * pcode, scalar  val)
{
    val = *(scalar  *)((pcode + 0) + 24U);
    if (*(pcode + 48) == val) {
        return  ;
    }
    *(pcode + 48) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 56);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 72);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 64);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode1 = *(UB  **)(pcode + 88);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 80);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 96))(*(UB  **)(pcode + 104), I1473);
    }
    pcode += 112;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate186 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        (*(FP  *)(pcode + 24))(*(UB  **)(pcode + 32), globalTable1Input[(*(U  *)(pcode + 16) >> 8) + val]);
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 48U))(*(UB  **)(pcode + 56U), *((*(UB  **)(pcode + 40U)) + X4val[val]));
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 64);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 80);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 72);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode1 = *(UB  **)(pcode + 96);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 88);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 104);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 112))(*(UB  **)(pcode + 120), I1473);
    }
    pcode += 128;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate186_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate186(pcode, val);
}
void  rmaPropagate187 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 16);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 24);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 32))(*(UB  **)(pcode + 40), I1473);
    }
    pcode += 48;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate187_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate187(pcode, val);
}
void  rmaPropagate188 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    {
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        if (*(scalar  *)((pcode + 0) + 24U) != val) {
            RmaEblk  * I1455 = (RmaEblk  *)(pcode + 0);
            *(scalar  *)((pcode + 0) + 24U) = val;
            if (!(I1455->I673)) {
                pQ->I1355->I673 = (EBLK  *)I1455;
                pQ->I1355 = (EBLK  *)I1455;
                I1455->I673 = (RP )((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
}
void  rmaPropagate188_s0 (UB  * pcode, scalar  val)
{
    val = *(scalar  *)((pcode + 0) + 24U);
    if (*(pcode + 48) == val) {
        return  ;
    }
    *(pcode + 48) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 56);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 64);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 80);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 72);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode1 = *(UB  **)(pcode + 96);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 88);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 104))(*(UB  **)(pcode + 112), I1473);
    }
    pcode += 120;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate189 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        (*(FP  *)(pcode + 24))(*(UB  **)(pcode + 32), globalTable1Input[(*(U  *)(pcode + 16) >> 8) + val]);
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 48U))(*(UB  **)(pcode + 56U), *((*(UB  **)(pcode + 40U)) + X4val[val]));
            }
        }
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 72);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 64);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode1 = *(UB  **)(pcode + 88);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 80);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 96);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 104))(*(UB  **)(pcode + 112), I1473);
    }
    pcode += 120;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate189_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate189(pcode, val);
}
void  rmaPropagate191 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 16);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 18) {
            if (I1654 & 2) {
                (*(FP  *)(pcode + 24))(*(void **)(pcode + 32), I235);
            }
        }
        else {
            U  I1552;
            U  I657;
            U  I1733;
            U  * I1735;
            UB  * pcode1;
            pcode1 = (UB  *)(*(UP  *)(pcode + 32) & ~3);
            I657 = *(U  *)pcode1;
            I1735 = (U  *)(pcode1 + sizeof(U ));
            I1733 = (I657 + 31) >> 5;
            pcode1 += sizeof(U ) * (1 + I1733);
            for (I1552 = 0; I1552 < I1733; I1552++) {
                if (I1552 == I1733 - 1 && (I657 % 32)) {
                    I1735[I1552] = (1 << (I657 % 32)) - 1;
                }
                else {
                    I1735[I1552] = (U )-1;
                }
            }
            pcode1 = (UB  *)((((RP )pcode1) + 7) & (~7));
            for (; I657 > 0; I657--) {
                (*(FP  *)(pcode1))(*(void **)(pcode1 + 8LU), I235);
                pcode1 += 16;
            }
        }
        *(pcode + 16U) = I1184;
    }
    pcode += 40;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate191_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate191(pcode, val);
}
void  rmaPropagate192 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        (*(FP  *)(pcode + 24))(*(UB  **)(pcode + 32), globalTable1Input[(*(U  *)(pcode + 16) >> 8) + val]);
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 48U))(*(UB  **)(pcode + 56U), *((*(UB  **)(pcode + 40U)) + X4val[val]));
            }
        }
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 72);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 64);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode1 = *(UB  **)(pcode + 88);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 80);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 96);
        pcode += 104;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 0))(*(UB  **)(pcode + 8), I1473);
    }
    pcode += 16;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate192_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate192(pcode, val);
}
void  rmaPropagate195 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    {
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        if (*(scalar  *)((pcode + 0) + 24U) != val) {
            RmaEblk  * I1455 = (RmaEblk  *)(pcode + 0);
            *(scalar  *)((pcode + 0) + 24U) = val;
            if (!(I1455->I673)) {
                pQ->I1355->I673 = (EBLK  *)I1455;
                pQ->I1355 = (EBLK  *)I1455;
                I1455->I673 = (RP )((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
}
void  rmaPropagate195_s0 (UB  * pcode, scalar  val)
{
    val = *(scalar  *)((pcode + 0) + 24U);
    if (*(pcode + 48) == val) {
        return  ;
    }
    *(pcode + 48) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 56);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 72);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 64);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode1 = *(UB  **)(pcode + 88);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 80);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 96);
        pcode += 104;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 0))(*(UB  **)(pcode + 8), I1473);
    }
    pcode += 16;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate196 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        (*(FP  *)(pcode + 24))(*(UB  **)(pcode + 32), globalTable1Input[(*(U  *)(pcode + 16) >> 8) + val]);
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 48U))(*(UB  **)(pcode + 56U), *((*(UB  **)(pcode + 40U)) + X4val[val]));
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 64);
        pcode += 72;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 8);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 0);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode1 = *(UB  **)(pcode + 24);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 16);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 32))(*(UB  **)(pcode + 40), I1473);
    }
    pcode += 48;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate196_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate196(pcode, val);
}
void  rmaPropagate199 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 24U))(*(UB  **)(pcode + 32U), *((*(UB  **)(pcode + 16U)) + X4val[val]));
            }
        }
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 48);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 40);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode1 = *(UB  **)(pcode + 64);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 56);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 72);
        pcode += 80;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 0))(*(UB  **)(pcode + 8), I1473);
    }
    pcode += 16;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate199_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate199(pcode, val);
}
void  rmaPropagate201 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 24U))(*(UB  **)(pcode + 32U), *((*(UB  **)(pcode + 16U)) + X4val[val]));
            }
        }
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 48);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 40);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode1 = *(UB  **)(pcode + 64);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 56);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 72);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 80))(*(UB  **)(pcode + 88), I1473);
    }
    pcode += 96;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate201_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate201(pcode, val);
}
void  rmaPropagate203 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        U  I1705;
        U  I1706;
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 4560) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 24), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 24));
            }
        }
        if (I1654 & 8718) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 72), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 72));
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        pcode += 120;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 0);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 8);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 16);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 24))(*(UB  **)(pcode + 32), I1473);
    }
    pcode += 40;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate203_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate203(pcode, val);
}
void  rmaPropagate205 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 16);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 18) {
            if (I1654 & 2) {
                (*(FP  *)(pcode + 24))(*(void **)(pcode + 32), I235);
            }
        }
        else {
            U  I1552;
            U  I657;
            U  I1733;
            U  * I1735;
            UB  * pcode1;
            pcode1 = (UB  *)(*(UP  *)(pcode + 32) & ~3);
            I657 = *(U  *)pcode1;
            I1735 = (U  *)(pcode1 + sizeof(U ));
            I1733 = (I657 + 31) >> 5;
            pcode1 += sizeof(U ) * (1 + I1733);
            for (I1552 = 0; I1552 < I1733; I1552++) {
                if (I1552 == I1733 - 1 && (I657 % 32)) {
                    I1735[I1552] = (1 << (I657 % 32)) - 1;
                }
                else {
                    I1735[I1552] = (U )-1;
                }
            }
            pcode1 = (UB  *)((((RP )pcode1) + 7) & (~7));
            for (; I657 > 0; I657--) {
                (*(FP  *)(pcode1))(*(void **)(pcode1 + 8LU), I235);
                pcode1 += 16;
            }
        }
        *(pcode + 16U) = I1184;
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        GateCount  I655;
        I655 = *(U  *)(pcode + 40);
        pcode += 48;
        for (; I655 > 0; I655--) {
            {
                typedef
                US
                 stateType;
                typedef
                US
                 * stateTypePtr;
                pcode1 = *(UB  **)(pcode + 0);
                iinput = (U )(((RP )pcode1) & 7);
                pcode1 = (UB  *)(((RP )pcode1) & ~7);
                {
                    RP  I1569 = 1;
                    if (I1569) {
                        state = *(stateTypePtr )(pcode1 + 16U);
                        state &= ~(3 << (iinput * 2));
                        state |= X4val[val] << (iinput * 2);
                        *(stateTypePtr )(pcode1 + 16U) = state;
                        newval = *((*(UB  **)(pcode1 + 8U)) + state);
                        if (newval != *(pcode1 + 18U)) {
                            *(pcode1 + 18U) = newval;
                            (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                        }
                    }
                }
            }
            pcode += 8;
        }
    }
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate205_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate205(pcode, val);
}
void  rmaPropagate206 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    {
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        if (*(scalar  *)((pcode + 0) + 24U) != val) {
            RmaEblk  * I1455 = (RmaEblk  *)(pcode + 0);
            *(scalar  *)((pcode + 0) + 24U) = val;
            if (!(I1455->I673)) {
                pQ->I1355->I673 = (EBLK  *)I1455;
                pQ->I1355 = (EBLK  *)I1455;
                I1455->I673 = (RP )((EBLK  *)-1);
                if (0 && rmaProfEvtProp) {
                    vcs_simpSetEBlkEvtID(I1455);
                }
            }
        }
    }
}
void  rmaPropagate206_s0 (UB  * pcode, scalar  val)
{
    val = *(scalar  *)((pcode + 0) + 24U);
    if (*(pcode + 48) == val) {
        return  ;
    }
    *(pcode + 48) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 56);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 64);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 72);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 80);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 96);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 88);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode += 104;
        pcode1 = *(UB  **)(pcode + 8);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 0);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 16))(*(UB  **)(pcode + 24), I1473);
    }
    pcode += 32;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate208 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 8718) {
            *(RmaTimeStamp  *)(pcode + 24) = (RmaTimeStamp )vcs_clocks;
        }
    }
    {
        (*(FP  *)(pcode + 40))(*(UB  **)(pcode + 48), globalTable1Input[(*(U  *)(pcode + 32) >> 8) + val]);
    }
    {
        (*(FP  *)(pcode + 64))(*(UB  **)(pcode + 72), globalTable1Input[(*(U  *)(pcode + 56) >> 8) + val]);
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 80);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 88;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate208_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate208(pcode, val);
}
void  rmaPropagate210 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        U  I1705;
        U  I1706;
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 8718) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 24), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 24));
            }
        }
        if (I1654 & 4560) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 72), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 72));
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        pcode += 120;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 0);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 8);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 16);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 24))(*(UB  **)(pcode + 32), I1473);
    }
    pcode += 40;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate210_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate210(pcode, val);
}
void  rmaPropagate212 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 16);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 18) {
            if (I1654 & 2) {
                (*(FP  *)(pcode + 24))(*(void **)(pcode + 32), I235);
            }
        }
        else {
            U  I1552;
            U  I657;
            U  I1733;
            U  * I1735;
            UB  * pcode1;
            pcode1 = (UB  *)(*(UP  *)(pcode + 32) & ~3);
            I657 = *(U  *)pcode1;
            I1735 = (U  *)(pcode1 + sizeof(U ));
            I1733 = (I657 + 31) >> 5;
            pcode1 += sizeof(U ) * (1 + I1733);
            for (I1552 = 0; I1552 < I1733; I1552++) {
                if (I1552 == I1733 - 1 && (I657 % 32)) {
                    I1735[I1552] = (1 << (I657 % 32)) - 1;
                }
                else {
                    I1735[I1552] = (U )-1;
                }
            }
            pcode1 = (UB  *)((((RP )pcode1) + 7) & (~7));
            for (; I657 > 0; I657--) {
                (*(FP  *)(pcode1))(*(void **)(pcode1 + 8LU), I235);
                pcode1 += 16;
            }
        }
        *(pcode + 16U) = I1184;
    }
    {
        (*(FP  *)(pcode + 48))(*(UB  **)(pcode + 56), globalTable1Input[(*(U  *)(pcode + 40) >> 8) + val]);
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 64);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 72);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 80);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 88;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate212_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate212(pcode, val);
}
void  rmaPropagate213 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    if (*(pcode + 0) == val) {
        return  ;
    }
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 16);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 24);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 32;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate214 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    if (*(pcode + 0) == val) {
        return  ;
    }
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 16);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 24);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 32);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 40))(*(UB  **)(pcode + 48), I1473);
    }
    pcode += 56;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate215 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 24U))(*(UB  **)(pcode + 32U), *((*(UB  **)(pcode + 16U)) + X4val[val]));
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 40);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 48);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 56))(*(UB  **)(pcode + 64), I1473);
    }
    pcode += 72;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate215_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate215(pcode, val);
}
void  rmaPropagate217 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        U  I1705;
        U  I1706;
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 8718) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 24), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 24));
            }
        }
        if (I1654 & 4560) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 72), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 72));
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        pcode += 120;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 0);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 8))(*(UB  **)(pcode + 16), I1473);
    }
    pcode += 24;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate217_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate217(pcode, val);
}
void  rmaPropagate219 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    *(pcode + 1) = X4val[val];
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        US  I235;
        I1184 = X3val[val];
        I1627 = *(pcode + 16);
        I235 = (I1627 << 2) + I1184;
        I1654 = 1 << I235;
        if (I1654 & 18) {
            if (I1654 & 2) {
                (*(FP  *)(pcode + 24))(*(void **)(pcode + 32), I235);
            }
        }
        else {
            U  I1552;
            U  I657;
            U  I1733;
            U  * I1735;
            UB  * pcode1;
            pcode1 = (UB  *)(*(UP  *)(pcode + 32) & ~3);
            I657 = *(U  *)pcode1;
            I1735 = (U  *)(pcode1 + sizeof(U ));
            I1733 = (I657 + 31) >> 5;
            pcode1 += sizeof(U ) * (1 + I1733);
            for (I1552 = 0; I1552 < I1733; I1552++) {
                if (I1552 == I1733 - 1 && (I657 % 32)) {
                    I1735[I1552] = (1 << (I657 % 32)) - 1;
                }
                else {
                    I1735[I1552] = (U )-1;
                }
            }
            pcode1 = (UB  *)((((RP )pcode1) + 7) & (~7));
            for (; I657 > 0; I657--) {
                (*(FP  *)(pcode1))(*(void **)(pcode1 + 8LU), I235);
                pcode1 += 16;
            }
        }
        *(pcode + 16U) = I1184;
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 40);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 48);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 56);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 64;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate219_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate219(pcode, val);
}
void  rmaPropagate220 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 16);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 24))(*(UB  **)(pcode + 32), I1473);
    }
    pcode += 40;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate220_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate220(pcode, val);
}
void  rmaPropagate221 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 24U))(*(UB  **)(pcode + 32U), *((*(UB  **)(pcode + 16U)) + X4val[val]));
            }
        }
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 48);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 40);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode1 = *(UB  **)(pcode + 64);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 56);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 72);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 80);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 88))(*(UB  **)(pcode + 96), I1473);
    }
    pcode += 104;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate221_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate221(pcode, val);
}
void  rmaPropagate222 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 16);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 24);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 32))(*(UB  **)(pcode + 40), I1473);
    }
    pcode += 48;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate222_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate222(pcode, val);
}
void  rmaPropagate225 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        U  I1705;
        U  I1706;
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 4560) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 24), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 24));
            }
        }
        if (I1654 & 8718) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 72), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 72));
            }
        }
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 128U))(*(UB  **)(pcode + 136U), *((*(UB  **)(pcode + 120U)) + X4val[val]));
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        pcode += 144;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 0);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 8))(*(UB  **)(pcode + 16), I1473);
    }
    pcode += 24;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate225_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate225(pcode, val);
}
void  rmaPropagate227 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        U  I1705;
        U  I1706;
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 4560) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 24), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 24));
            }
        }
        if (I1654 & 8718) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 72), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 72));
            }
        }
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 128U))(*(UB  **)(pcode + 136U), *((*(UB  **)(pcode + 120U)) + X4val[val]));
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        pcode += 144;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 0);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 8);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 16))(*(UB  **)(pcode + 24), I1473);
    }
    pcode += 32;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate227_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate227(pcode, val);
}
void  rmaPropagate229 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 8718) {
            *(RmaTimeStamp  *)(pcode + 24) = (RmaTimeStamp )vcs_clocks;
        }
    }
    {
        (*(FP  *)(pcode + 40))(*(UB  **)(pcode + 48), globalTable1Input[(*(U  *)(pcode + 32) >> 8) + val]);
    }
    {
        (*(FP  *)(pcode + 64))(*(UB  **)(pcode + 72), globalTable1Input[(*(U  *)(pcode + 56) >> 8) + val]);
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 80);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 88);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 96);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 104;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate229_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate229(pcode, val);
}
void  rmaPropagate230 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    if (*(pcode + 0) == val) {
        return  ;
    }
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 16);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 24);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 32;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate232 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        U  I1705;
        U  I1706;
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 8718) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 24), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 24));
            }
        }
        if (I1654 & 4560) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 72), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 72));
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        pcode += 120;
        (*(FP  *)(pcode + 0))(*(UB  **)(pcode + 8), I1473);
    }
    pcode += 16;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate232_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate232(pcode, val);
}
void  rmaPropagate233 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        {
            RP  I1569 = 1;
            if (I1569) {
                (*(FP  *)(pcode + 24U))(*(UB  **)(pcode + 32U), *((*(UB  **)(pcode + 16U)) + X4val[val]));
            }
        }
    }
    {
        typedef
        US
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            US
             stateType;
            typedef
            US
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 40);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 16U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 16U) = state;
                    newval = *((*(UB  **)(pcode1 + 8U)) + state);
                    if (newval != *(pcode1 + 18U)) {
                        *(pcode1 + 18U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  newval;
        U  state;
        U  startBit;
        UB  * pcode1;
        pcode1 = *(UB  **)(pcode + 56);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 48);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
        pcode1 = *(UB  **)(pcode + 72);
        {
            RP  I1569 = 1;
            if (I1569) {
                startBit = *(U  *)(pcode + 64);
                state = *(U  *)(pcode1 + 16U);
                state &= ~(0x3 << startBit);
                state |= X4val[val] << startBit;
                *(U  *)(pcode1 + 16U) = state;
                newval = *((*(UB  **)(pcode1 + 8U)) + state);
                if (newval != *(pcode1 + 20U)) {
                    *(pcode1 + 20U) = newval;
                    (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                }
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 80);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 88))(*(UB  **)(pcode + 96), I1473);
    }
    pcode += 104;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate233_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate233(pcode, val);
}
void  rmaPropagate235 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        U  I1705;
        U  I1706;
        EBLK  * I1455;
        struct dummyq_struct * pQ;
        U  I1458;
        I1458 = 0;
        pQ = (struct dummyq_struct *)ref_vcs_clocks;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 4560) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 24), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 24));
            }
        }
        if (I1654 & 8718) {
            if (getCurSchedRegion()) {
                SchedSemiLerTBReactiveRegion_th((struct eblk *)(pcode + 72), I1458);
            }
            else {
                sched0_th(pQ, (EBLK  *)(pcode + 72));
            }
        }
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        pcode += 120;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 0);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    {
        scalar  I1473;
        I1473 = val;
        (*(FP  *)(pcode + 8))(*(UB  **)(pcode + 16), I1473);
    }
    pcode += 24;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate235_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate235(pcode, val);
}
void  rmaPropagate237 (UB  * pcode, scalar  val)
{
    UB  * I1812;
    *(pcode + 0) = val;
    {
        {
            RP  * I664 = ((void *)0);
            I664 = (RP  *)(pcode + 8);
            if (I664) {
                RP  I1666 = *I664;
                if (I1666) {
                    hsimDispatchNoDynElabS(I664, val, 0U);
                }
            }
        }
    }
    {
        scalar  I1627;
        scalar  I1184;
        U  I1654;
        I1184 = X4val[val];
        I1627 = *(pcode + 16);
        *(pcode + 16) = I1184;
        I1654 = (I1627 << 2) + I1184;
        I1654 = 1 << I1654;
        if (I1654 & 8718) {
            *(RmaTimeStamp  *)(pcode + 24) = (RmaTimeStamp )vcs_clocks;
        }
    }
    {
        (*(FP  *)(pcode + 40))(*(UB  **)(pcode + 48), globalTable1Input[(*(U  *)(pcode + 32) >> 8) + val]);
    }
    {
        (*(FP  *)(pcode + 64))(*(UB  **)(pcode + 72), globalTable1Input[(*(U  *)(pcode + 56) >> 8) + val]);
    }
    {
        typedef
        UB
         stateType;
        scalar  newval;
        stateType  state;
        U  iinput;
        UB  * pcode1;
        UB  * I1461;
        UB  * I1575;
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 80);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
        {
            typedef
            UB
             stateType;
            typedef
            UB
             * stateTypePtr;
            pcode1 = *(UB  **)(pcode + 88);
            iinput = (U )(((RP )pcode1) & 7);
            pcode1 = (UB  *)(((RP )pcode1) & ~7);
            {
                RP  I1569 = 1;
                if (I1569) {
                    state = *(stateTypePtr )(pcode1 + 12U);
                    state &= ~(3 << (iinput * 2));
                    state |= X4val[val] << (iinput * 2);
                    *(stateTypePtr )(pcode1 + 12U) = state;
                    newval = (*(U  *)(pcode1 + 8U) >> (state << 1)) & 3;
                    if (newval != *(pcode1 + 13U)) {
                        *(pcode1 + 13U) = newval;
                        (*(FP  *)(pcode1 + 0U))(pcode1, newval);
                    }
                }
            }
        }
    }
    pcode += 96;
    UB  * I751 = *(UB  **)(pcode + 0);
    if (I751 != (UB  *)(pcode + 0)) {
        RmaSwitchGate  * I1840 = (RmaSwitchGate  *)I751;
        RmaSwitchGate  * I994 = 0;
        do {
            RmaIbfPcode  * I1115 = (RmaIbfPcode  *)(((UB  *)I1840) + 24U);
            ((FP )(I1115->I1115))((void *)I1115->pcode, val);
            RmaDoublyLinkedListElem  I1841;
            I1841.I994 = 0;
            RmaSwitchGateInCbkListInfo  I1842;
            I1842.I1305 = 0;
            I994 = (RmaSwitchGate  *)I1840->I642.I1843.I994;
        } while ((UB  *)(I1840 = I994) != (UB  *)I751);
    }
}
void  rmaPropagate237_t0 (UB  * pcode, UB  val)
{
    val = *(pcode + 0);
    *(pcode + 0) = 0xff;
    rmaPropagate237(pcode, val);
}
#ifdef __cplusplus
extern "C" {
#endif
void SinitHsimPats(void);
#ifdef __cplusplus
}
#endif
