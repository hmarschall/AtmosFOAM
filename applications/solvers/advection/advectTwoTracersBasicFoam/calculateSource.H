IOdictionary dict
(
    IOobject
    (
        "advectionDict",
        mesh.time().system(),
        mesh,
        IOobject::READ_IF_PRESENT,
        IOobject::NO_WRITE
    )
);

const int sourcePresent = dict.lookupOrDefault<int>("sourcePresent", int(1));
const dimensionedScalar tempScale(dict.lookup("tempScale"));
const dimensionedScalar velocityScale(dict.lookup("velocityScale"));
const dimensionedScalar timeScale(dict.lookup("timeScale"));
const dimensionedScalar es0(dict.lookup("es0"));
const dimensionedScalar muv(dict.lookup("muv"));
const dimensionedScalar mud(dict.lookup("mud"));
const dimensionedScalar Lv(dict.lookup("Lv"));
const dimensionedScalar cp(dict.lookup("cp"));
const dimensionedScalar Rv(dict.lookup("Rv"));

// The vertical velocity used for calculating the source terms
const volScalarField w = U.component(vector::Z);

volScalarField es
(
    "es",
    es0*Foam::exp( 17.67*(T-273.15*tempScale)/(T-29.65*tempScale) )
);

const volScalarField rvs
(
    "rvs",
    muv/mud * es/(P-es)
);

const volScalarField transferTerm
(
    "transferTerm",
    timeScale/( 1 + Lv*Lv*rvs/(cp*Rv*T*T) )
);

