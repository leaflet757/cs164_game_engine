/**
* Created using Unreal Script Wizard by RyanJon2040
* Visit: www.dynamiceffects.net
* Meet me on Facebook: www.facebook.com/satheeshpv
*/

class Scimitar_Ammo extends UTAmmoPickupFactory;

DefaultProperties
{

    Begin Object Name=AmmoMeshComp
        Translation=(X=0.0,Y=0.0,Z=-16.0)
    End Object

    Begin Object Name=CollisionCylinder
        CollisionHeight=14.4
    End Object

    AmmoAmount=1

    PickupSound=SoundCue'A_Pickups.Ammo.Cue.A_Pickup_Ammo_Link_Cue'

    //<DO NOT MODIFY>
    TargetWeapon=Class'Scimitar_Weapon'
}
