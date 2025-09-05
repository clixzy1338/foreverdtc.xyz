#pragma once
#include "thread"
#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <array>
#include <algorithm>

namespace O
{
    uintptr_t dwMainCamera = 0xd1bc5f8; // MainCamera  // update
    uintptr_t dwBaseNetworkable = 0xd1d5af8;// BaseNetworkable // update
    uintptr_t ghandle = 0xd52ac50; // Il2CppGetHandle // UPDATED

    uintptr_t Graphics = 0xBD0F020;  // ConvarGraphics 

    uintptr_t entitycount = 0x18; // PlayerList // UPDATED
	uintptr_t entityarray = 0x10; // EntitySize // UPDATED

    namespace BN // Basenetworkable all updated
    {
        inline uintptr_t List1 = 0x40; // BaseNetworkable1 // UPDATED
        inline uintptr_t List2 = 0x10; // BaseNetworkable2// UPDATED
        inline uintptr_t List3 = 0x18; // BaseNetworkable3 // UPDATED
    }

    namespace Graphic
    {
        constexpr uint64_t fov = 0x2A0; // updated
    }

    namespace BasePlayer
    {
        constexpr uint64_t playerFlags = 0x588; // updated
        constexpr uint64_t playerTeam = 0x460;// CurrentTeam
        constexpr uint64_t Mounted = 0x4C0; // unknown
        constexpr uint64_t _displayName = 0x5B8; // updated //0x18
        constexpr uint64_t _Model = 0xC8; // THIS IS NOT PLAYERMODEL
        constexpr uint64_t input = 0x328; // PlayerInput
        constexpr uint64_t PlayerModel = 0x268; // updated//CHANGES OFTEN
        constexpr uint64_t PlayerEyes = 0x5e0;// updated //not sure
        constexpr uint64_t PlayerInventory = 0x350; // updated
        constexpr uint64_t PlayerMovement = 0x2f8; // BaseMovement
        constexpr uint64_t ModelState = 0x2A8;

    }

    namespace BaseProjectile {
        inline int recoil = 0x348; // recoilproperties
        inline int automatic = 0x2D8; // upd
        inline int isBurstWeapon = 0x37A; // upd
        inline int internalBurstFireRateScale = 0x384; //upd

        inline int viewModel = 0x218; // updated 
        inline int is_reloading = 0x3B8;
        inline int reloadDuration = 0x310; // updated
        inline int primaryMagazine = 0x318; // updated
        inline int sightAimConeScale = 0x358; // aimcone pentalty
        inline int hipAimConeScale = 0x354; // updated

        namespace viewModels {
            inline int baseviewModel = 0x28;
            namespace baseViewModel {
                inline int Animator = 0xD0;

                inline int ViewmodelBob = 0xC0;
                inline int viewmodelSway = 0x334;
                inline int viewmodelLower = 0xD8;
                inline int irongsights = 0x90;

                namespace ViewmodelLower {
                    inline int lowerOnSprint = 0x20;
                    inline int lowerWhenCantAttack = 0x21;
                    inline int shouldLower = 0x28;
                }
                namespace ViewmodelSway {
                    inline int positionalSwaySpeed = 0x338;
                    inline int rotationSwayAmount = 0x2C;
                }
                namespace viewmodelBob {
                    inline int bobAmountRun = 0x28;
                    inline int bobAmountWalk = 0x28;
                    inline int bobSpeedRun = 0x24;
                    inline int bobSpeedWalk = 0x20;
                }
            }
        }
    }

    namespace BaseProjectileExploits
    {
        constexpr uintptr_t automatic = 0x2D8; // updated
        constexpr uintptr_t FlintStrikeWeapon = 0x3F0; // successFraction
        constexpr uintptr_t DidShitTick = 0x400; // encrypted value 
    }


    namespace RecoilProperties {
        constexpr uintptr_t new_recoil = 0x80;
        constexpr uintptr_t recoilYawMin = 0x20;
        constexpr uintptr_t recoilYawMax = 0x1C;
        constexpr uintptr_t recoilPitchMin = 0x20;
        constexpr uintptr_t recoilPitchMax = 0x24;
    }

    namespace PlayerInventory
    {
        constexpr uint64_t ClActiveItem = 0x490; // updated
        constexpr uint64_t Belt = 0x58; // updated
        constexpr uint64_t Wear = 0x30; // updated
        constexpr uint64_t ItemDisplayName = 0x20; // updated
        constexpr uint64_t ShortName = 0x28; // updated
        constexpr uint64_t ItemDisplayEnglish = 0x38;
        constexpr uint64_t ItemId = 0xB0; // updated
        constexpr uint64_t ItemList = 0x18; // updated

        constexpr uint64_t ItemDefinition = 0x90; // updated / iteminfo
    }

    namespace PlayerModel
    {
        constexpr uintptr_t MaterialList = 0x148; // not updated
        constexpr uintptr_t SkinnedMultiMesh = 0x2E0; // updated
        constexpr uintptr_t RendererList = 0x40; // updated
        constexpr uint64_t new_velocity = 0x2D4; // updated
    }

    namespace CameraManager
    {
        inline uintptr_t CameraObject = 0xb8; //MainCamera1 OR MainCamera = 0xBDA4E48; // --> THIS IS THE OFFSET 0x48
    }

    namespace Recoil
    {
        constexpr uintptr_t RecoilProperties = 0x340;
        constexpr uintptr_t NewRecoilOverride = 0x80; // updated
    }
    namespace Eyes
    {
        constexpr uintptr_t eye_offset = 0x400;
        constexpr uintptr_t eye_rotation = 0x6C;
        constexpr uintptr_t body_rotation = 0x50;
        constexpr uintptr_t view_offset = 0x40;
    }

    namespace Sky
    {
        inline uintptr_t TOD_Sky = 0xBD23DD8; // updated
    }

    namespace Model
    {
        inline uintptr_t boneTransforms = 0x50;
    }
    namespace Projectile
    {
        inline uintptr_t HeldItem = 0x10; // updated
        inline uintptr_t PrimaryMagazine = 0x318; // updated
    }
}
