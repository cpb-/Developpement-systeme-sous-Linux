SUBDIRS	=            \
	chapitre-01  \
	chapitre-02  \
	chapitre-03  \
	chapitre-04  \
	chapitre-05  \
	chapitre-06  \
	chapitre-07  \
	chapitre-08  \
	chapitre-09  \
	chapitre-10  \
	chapitre-11  \
	chapitre-12  \
	chapitre-13  \
	chapitre-14  \
	chapitre-15  \
	chapitre-16  \
	chapitre-17  \
	chapitre-18  \
	chapitre-19  \
	chapitre-20  \
	chapitre-21  \
	chapitre-22  \
	chapitre-23  \
	chapitre-24  \
	chapitre-25  \
	chapitre-26  \
	chapitre-27  \
	chapitre-28  \
	chapitre-29  \
	chapitre-30  \
	chapitre-31  \
	chapitre-32  \

all: 
	@set -e;     \
	for i in $(SUBDIRS); do \
		cd $$i; \
		make all ; \
		cd ..; \
	done

clean: 
	@set -e; \
	for i in $(SUBDIRS); do \
		cd $$i; \
		make clean; \
		cd ..; \
	done

