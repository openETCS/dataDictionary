#!/bin/bash

echo "Starting SEFEV"
/home/railsite/ITE/bin/run.sh -load /home/railsite/ITE/config/scenario-tsd-rca.xml -mdb /media/sf_D_DRIVE/OpenETCS_git/testmodel/AU_TS_AU_Testspec_150730_v290_01.mdb -lof /home/railsite/Sefev.log -autoload -autorun -autoexit
