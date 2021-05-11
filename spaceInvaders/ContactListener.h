#pragma once
#include<box2d/box2d.h>
#include"Player.h"
class ContactListener : public b2ContactListener
{
    void BeginContact(b2Contact* contact) {

        //check if fixture A was a ball
        b2BodyUserData bodyUserData = contact->GetFixtureA()->GetBody()->GetUserData();
        if (bodyUserData.data == "player")
            reinterpret_cast<gameObject*>(bodyUserData.point)->Collide(contact->GetFixtureB()->GetBody()->GetLinearVelocity());

        //check if fixture B was a ball
        bodyUserData = contact->GetFixtureB()->GetBody()->GetUserData();
        if (bodyUserData.data == "player")
            reinterpret_cast<gameObject*>(bodyUserData.point)->Collide(contact->GetFixtureA()->GetBody()->GetLinearVelocity());
        
         

    }

    void EndContact(b2Contact* contact) {

        //check if fixture A was a ball
        void* bodyUserData = &contact->GetFixtureA()->GetBody()->GetUserData();
        if (bodyUserData)
            static_cast<player*>(bodyUserData)->endContact();

        //check if fixture B was a ball
        bodyUserData = &contact->GetFixtureB()->GetBody()->GetUserData();
        if (bodyUserData)
            static_cast<player*>(bodyUserData)->endContact();

    }
};

