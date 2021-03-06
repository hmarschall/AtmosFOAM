#!/bin/bash
set -e
rm -rf [0-9]* processor*
blockMesh
terrainFollowingMesh

setTheta

setExnerBalancedH

cp init_0/Uf 0/Uf
createSpongeLayer

decomposePar -force -constant
$ATMOSTESTS_DIR/bin/correctMPIinitialUf.sh .
set +e
mpirun --hostfile machines -np 2 exnerFoamH -parallel
./diff.sh
