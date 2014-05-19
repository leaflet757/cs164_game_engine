/**
* Created using Unreal Script Wizard by RyanJon2040
* Visit: www.dynamiceffects.net
* Meet me on Facebook: www.facebook.com/satheeshpv
*/

class Scimitar_Attach extends UTWeaponAttachment;

DefaultProperties
{

    Begin Object Name=SkeletalMeshComponent0
        SkeletalMesh=SkeletalMesh'CS164.RainbowWizards.Scimitar'
        CullDistance=5000.000000
        Scale=1
    End Object

    bMakeSplash=False

    //<DO NOT MODIFY>
    Mesh=SkeletalMeshComponent0
    WeaponClass=Class'Scimitar_Weapon'
}
