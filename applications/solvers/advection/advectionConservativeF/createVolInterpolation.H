IStringStream volInterpolationType("fvcReconstructCP");
tmp<volInterpolationScheme<scalar> > tcellCentreReconstruction = volInterpolationScheme<scalar>::New(mesh, volInterpolationType);
const volInterpolationScheme<scalar>& cellCentreReconstruction = tcellCentreReconstruction();

