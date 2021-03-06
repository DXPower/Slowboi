#pragma once

#include "Fastboi.h"
#include "Spritesheet.h"

using namespace Fastboi;
using namespace Fastboi::Components;

namespace Slowboi {
    namespace Components {
        struct Player final {
            private:
            Rigidbody* rigidbody = nullptr;
            Spritesheet<int>* spritesheet = nullptr;

            Input::KeyListener spacebarListener;
            Input::ClickListener clickListener;

            Input::KeyListener enableListener;
            
            Vecf lastDirection;
            Vecf facingDirection;

            public:
            GORef gameobject;
            float_t speed = 200.0f;

            Player(GORef&& go);
            ~Player();

            void EnablePressed(const KeyEvent& e);
            void Spacebar(const KeyEvent& e);
            void VelocityChanged(const Velocity& velocity) const;
            void Fire(const ClickEvent& event);
            void Start();
            void Update();
            void Collision(const CollisionEvent& e) const;
        };
    };
};