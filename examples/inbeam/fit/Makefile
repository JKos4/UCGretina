all: s44_1329_histos.root \
     s44_2150_histos.root \
     s44_2457_histos.root
	$(MAKE) -C makeData
	echo "Geant4 simulations done."

# Pattern rules for running Geant4 simulations and sorting the output
# into Root histograms
%.dat : %.mac
	UCGretina $*.mac 2>&1 | tee $*.log

%_histos.root : %.dat
	grutinizer gvalues.val -qH $*.dat -o /dev/null \
	${GRUTSYS}/lib/libMakeHistosInBeam.so \
	--hist-output $*_histos.root 2>&1 | tee $*_grut.log
	rm $*.dat

clean:
	$(MAKE) -C makeData clean
	rm *.log *.root

