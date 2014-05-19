/**
* Created using Unreal Script Wizard by RyanJon2040
* Visit: www.dynamiceffects.net
* Meet me on Facebook: www.facebook.com/satheeshpv
*/

class Scimitar_Weapon extends UTWeapon;

var array<Actor> hitArray;

var name StartSocket, EndSocket;

simulated state WeaponFiring{
    simulated event BeginState(name PreviousState){
        if (!HasAmmo(CurrentFireMode)){
            WeaponEmpty();
            return;
        }
        `LogInv("PreviousStateName:" @ PreviousState);
        
        PlayFireEffects(CurrentFireMode);
        SetTimer(GetFireInterval(CurrentFireMode), false, 'RefireCheckTimer');
    }
    // simulated simulated?
    simulated event EndState(name NextState){
        hitArray.Length = 0;
        `LogInv("NextStateName" @NextState);
        ClearTimer('RefireCheckTimer');
        NotifyWeaponFinishedFiring(CurrentFireMode);
        return;
    }
    
    simulated function RefireCheckTimer() {
        if (bWeaponPutDown) {
            `LogInv("Weapon put down");
            PutDownWeapon();
            return;
        }
        if (ShouldRefire()) {
            hitArray.Length = 0;
            PlayFireEffects(CurrentFireMode);
            SetTimer(GetFireInterval(CurrentFireMode), false, 'RefireCheckTimer');
        }
        HandleFinishedFiring();
        return;
    }
    
    function Tick(float delta) {
        local Vector Startv, Endv;
        
        SkeletalMeshComponent(Mesh).GetSocketWorldLocationAndRotation(StartSocket, Startv);
        SkeletalMeshComponent(Mesh).GetSocketWorldLocationAndRotation(EndSocket, Endv);
        
        // bad command or expression
        WeaponTrace(Endv, Startv);
    }
    
    simulated event WeaponTrace(vector End, vector Start)
    {
        local vector HitLocation, HitNormal;
        local Actor HitActor;
        
        HitActor = Trace(HitLocation, HitNormal, End, Start, true);
        
        if (HitActor != none) {
            if (hitArray.Find(HitActor) == INDEX_NONE && HitActor.bCanBeDamaged) {
                HitActor.TakeDamage(InstantHitDamage[CurrentFireMode], Pawn(Owner).Controller, HitLocation, Velocity*100.f, class'Scimitar_Damage');
                AmmoCount -= ShotCost[CurrentFireMode];
                hitArray.AddItem(HitActor);
                return;
            }
        }
    }
    
    //begin;
    //FinishAnim(AnimNodeSequence(SkeletalMeshComponent(Mesh).FindAnimNode(WeaponFireAnim[CurrentFireMode])));
}


DefaultProperties
{
    
    ShotCost(0)=0;
    ShotCost(1)=0;
    
    WeaponFireTypes(0)=EWFT_Custom;
    WeaponFireTypes(1)=EWFT_Custom;
    
    StartSocket = StartSocket;
    EndSocket = EndSocket;

    PlayerViewOffset=(X=20.000000,Y=6.00000,Z=-8.000000);

    Begin Object class=AnimNodeSequence Name=MeshSequenceA
        bCauseActorAnimEnd=true
    End Object

    Begin Object Name=FirstPersonMesh
        SkeletalMesh=SkeletalMesh'CS164.RainbowWizards.Scimitar'
        FOV=60
        Animations=MeshSequenceA
        AnimSets(0)=AnimSet'CS164.RainbowWizards.polySurface1'
        bForceUpdateAttachmentsInTick=True
        Scale=0.9000000
    End Object

    Begin Object Name=PickupMesh
        SkeletalMesh=SkeletalMesh'CS164.RainbowWizards.Scimitar'
        Scale=0.9000000
    End Object

    WeaponEquipSnd=SoundCue'A_Weapon_Link.Cue.A_Weapon_Link_RaiseCue'
    WeaponPutDownSnd=SoundCue'A_Weapon_Link.Cue.A_Weapon_Link_LowerCue'
    WeaponFireSnd(0)=SoundCue'A_Weapon_RocketLauncher.Cue.A_Weapon_RL_GrenadeFire_Cue'
    WeaponFireSnd(1)=SoundCue'A_Weapon_RocketLauncher.Cue.A_Weapon_RL_GrenadeFire_Cue'

    PickupSound=SoundCue'A_Pickups.Weapons.Cue.A_Pickup_Weapons_Shock_Cue'

    PivotTranslation=(Y=0.0)

    MaxAmmoCount=0
    AmmoCount=0

    InventoryGroup=4

    bInstantHit=True
    InstantHitDamage(0)=50
    InstantHitDamage(1)=15
    InstantHitMomentum(0)=300
    InstantHitMomentum(1)=55
    InstantHitDamageTypes(0)=Class'Scimitar_Damage'
    InstantHitDamageTypes(1)=Class'Scimitar_Damage'

    //CrosshairImage=Copy texture from Content Browser
    CrossHairCoordinates=(U=384,V=0,UL=64,VL=64)

    FireInterval(0)=1
    FireInterval(1)=1

    //<DO NOT MODIFY>
    ArmsAnimSet=AnimSet'CS164.RainbowWizards.polySurface1'
    Mesh=FirstPersonMesh
    DroppedPickupMesh=PickupMesh
    PickupFactoryMesh=PickupMesh
    AttachmentClass=Class'Scimitar_Attach'

}
