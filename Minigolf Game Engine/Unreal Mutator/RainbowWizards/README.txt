CS164 Game Engines
5.20.14
Leif Myer
Jonah Nobelza

Install Instructions:
- First you must import the Scimitar.fbx into UDK Editor
- Make sure that import type is set to Static Mesh
- Make sure that import animations and import rigid animation under skeletal Mesh
- Name the package CS164 and keep the name the same

- Next double click the Scimitar skeletal mesh in the CS164 Package
- Click the Anim tab and set the animset to PolySet1
- then make sure that Rot Origin is set to 0,0,0 at the bottom left
- Then find the Polyset1 in the Content browser
- click the anim tab and rename one of the sequences WeaponFire and remove the others if there are any

- navigate to UDKGame Folder, then to config, open the DefaultEngine.ini file
- underneath:
[UnrealEd.EditorEngine]
+EditPackages=UTGame
+EditPackages=UTGameContent

- add the line:
+EditPackages=RainbowWizards

- Lastly make sure that Game Type is set to UTDeathmatch