LDVERSION= $(shell $(PIC_LD) -v | grep -q 2.30 ;echo $$?)
ifeq ($(LDVERSION), 0)
     LD_NORELAX_FLAG= --no-relax
endif

ARCHIVE_OBJS=
ARCHIVE_OBJS += _150454_archive_1.so
_150454_archive_1.so : archive.26/_150454_archive_1.a
	@$(AR) -s $<
	@$(PIC_LD) -shared  -Bsymbolic $(LD_NORELAX_FLAG)  -o .//../simv.daidir//_150454_archive_1.so --whole-archive $< --no-whole-archive
	@rm -f $@
	@ln -sf .//../simv.daidir//_150454_archive_1.so $@


ARCHIVE_OBJS += _prev_archive_1.so
_prev_archive_1.so : archive.26/_prev_archive_1.a
	@$(AR) -s $<
	@$(PIC_LD) -shared  -Bsymbolic $(LD_NORELAX_FLAG)  -o .//../simv.daidir//_prev_archive_1.so --whole-archive $< --no-whole-archive
	@rm -f $@
	@ln -sf .//../simv.daidir//_prev_archive_1.so $@




VCS_CU_ARC_OBJS = 


O0_OBJS =

$(O0_OBJS) : %.o: %.c
	$(CC_CG) $(CFLAGS_O0) -c -o $@ $<


%.o: %.c
	$(CC_CG) $(CFLAGS_CG) -c -o $@ $<

CU_UDP_OBJS = \
objs/udps/Y9h1d.o objs/udps/qUKec.o objs/udps/WJG2Y.o objs/udps/hFH2J.o objs/udps/GuLzc.o  \
objs/udps/F8h38.o objs/udps/TUgSV.o objs/udps/qTbGp.o objs/udps/eZijI.o objs/udps/v17TT.o  \
objs/udps/JIUcK.o objs/udps/PhkAb.o objs/udps/qIhZj.o objs/udps/ajvLe.o objs/udps/uQ6gx.o  \
objs/udps/t6H9V.o objs/udps/W7e2i.o objs/udps/eAW1F.o objs/udps/aBrjq.o objs/udps/kBv7Y.o  \
objs/udps/Gjg4Z.o objs/udps/hg6Rm.o objs/udps/Z0GwU.o objs/udps/JgPNT.o objs/udps/pNeY8.o  \
objs/udps/y4a7N.o 

CU_UDP_OBJS += 
CU_LVL_OBJS = \
SIM_l.o 

MAIN_OBJS = \
objs/a/amcQw_d.o 

CU_OBJS = $(MAIN_OBJS) $(ARCHIVE_OBJS) $(CU_UDP_OBJS) $(CU_LVL_OBJS)

