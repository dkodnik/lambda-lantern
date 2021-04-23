#include "Panda3d/Panda3d.h"
#include "Data_Boolean/Data_Boolean.h"
#include "Data_Functor/Data_Functor.h"
#include "Effect/Effect.h"
#include "Control_Applicative/Control_Applicative.h"
#include "FRP_Event/FRP_Event.h"
#include "FRP_Event_Time/FRP_Event_Time.h"
#include "Control_Apply/Control_Apply.h"
#include "Data_Unit/Data_Unit.h"
#include "Data_Show/Data_Show.h"
#include "Math/Math.h"
#include "FRP_Event_Class/FRP_Event_Class.h"
#include "Effect_Timer/Effect_Timer.h"

#include "Main/Main.h"



namespace Main {

auto MainMenuStateAnimating() -> const boxed& {
    static const boxed _ = dict_t{
        { "MainMenuStateAnimating", true }
    };
    return _;
};
auto MainMenuStateWaiting() -> const boxed& {
    static const boxed _ = dict_t{
        { "MainMenuStateWaiting", true }
    };
    return _;
};
auto MainMenuStateCleanUp() -> const boxed& {
    static const boxed _ = dict_t{
        { "MainMenuStateCleanUp", true }
    };
    return _;
};
auto MainMenuStateDone() -> const boxed& {
    static const boxed _ = dict_t{
        { "MainMenuStateDone", true }
    };
    return _;
};
auto LevelStateIntro() -> const boxed& {
    static const boxed _ = dict_t{
        { "LevelStateIntro", true }
    };
    return _;
};
auto LevelStatePlaying() -> const boxed& {
    static const boxed _ = dict_t{
        { "LevelStatePlaying", true }
    };
    return _;
};
auto LevelStateFailure() -> const boxed& {
    static const boxed _ = dict_t{
        { "LevelStateFailure", true }
    };
    return _;
};
auto LevelStateSuccess() -> const boxed& {
    static const boxed _ = dict_t{
        { "LevelStateSuccess", true }
    };
    return _;
};
auto LevelStateCleanUp() -> const boxed& {
    static const boxed _ = dict_t{
        { "LevelStateCleanUp", true }
    };
    return _;
};
auto LevelStateDone() -> const boxed& {
    static const boxed _ = dict_t{
        { "LevelStateDone", true }
    };
    return _;
};
auto MainMenu() -> const boxed& {
    static const boxed _ = dict_t{
        { "MainMenu", true }
    };
    return _;
};
auto Level() -> const boxed& {
    static const boxed _ = dict_t{
        { "Level", true }
    };
    return _;
};
auto Ending() -> const boxed& {
    static const boxed _ = dict_t{
        { "Ending", true }
    };
    return _;
};
auto getAssetsPath() -> boxed {
    boxed ifEmpty = [=](const boxed& s) -> boxed {
        if (unbox<int>(Panda3d::getStringLength()(s)) == 0) {
            return "./assets";
        };
        if (unbox<bool>(Data_Boolean::otherwise())) {
            return s;
        };
        THROW_("Failed pattern match at Main (line 696, column 5 - line 696, column 32)");
    };
    return [=]() -> boxed {
        boxed v = Data_Functor::map()(Effect::functorEffect())(ifEmpty)(Panda3d::getEnv()("LAMBDA_LANTERN_ASSETS_PATH"))();
        return Control_Applicative::pure()(Effect::applicativeEffect())(Panda3d::toOsGenericFilename()(v))();
    };
};
auto main() -> boxed {
    return Panda3d::withFramework()([=](const boxed& framework) -> boxed {
        return [=]() -> boxed {
            Panda3d::setWindowTitle()(framework)("Lambda Lantern by David Lettier")();
            return Panda3d::withWindow()(framework)([=](const boxed& window) -> boxed {
                return [=]() -> boxed {
                    boxed v = getAssetsPath()();
                    boxed v1 = Panda3d::getDisplayRegion()(window)();
                    Panda3d::setClearColor()(v1)(0.125)(0.122)(0.184)();
                    boxed v2 = Panda3d::getCamera()(window)();
                    boxed v3 = Panda3d::getRender()(window)();
                    boxed v4 = Panda3d::getModels()(framework)();
                    boxed v5 = Panda3d::getLens()(v2)();
                    boxed v6 = Panda3d::loadFont()(unbox<string>(v) + "/fonts/gloria-hallelujah.ttf")();
                    boxed v7 = Panda3d::findButton()("w")();
                    boxed v8 = Panda3d::findButton()("a")();
                    boxed v9 = Panda3d::findButton()("s")();
                    boxed v10 = Panda3d::findButton()("d")();
                    boxed v11 = Panda3d::findButton()("1")();
                    boxed v12 = Panda3d::findButton()("2")();
                    boxed v13 = Panda3d::findButton()("3")();
                    boxed v14 = Panda3d::findButton()("space")();
                    boxed v15 = Panda3d::getSound()(unbox<string>(v) + "/music/big-eyes.ogg")();
                    boxed v16 = Panda3d::getSound()(unbox<string>(v) + "/music/night-in-the-castle.ogg")();
                    boxed v17 = Panda3d::getSound()(unbox<string>(v) + "/music/magic-in-the-garden.ogg")();
                    boxed v18 = Panda3d::getSound()(unbox<string>(v) + "/sounds/evil-laugh.ogg")();
                    boxed v19 = Panda3d::getSound()(unbox<string>(v) + "/sounds/level-complete.ogg")();
                    boxed v20 = Panda3d::getSound()(unbox<string>(v) + "/sounds/chicken.ogg")();
                    boxed v21 = Panda3d::getSound()(unbox<string>(v) + "/sounds/twinkle.ogg")();
                    boxed v22 = Panda3d::getSound()(unbox<string>(v) + "/sounds/stone-dragging.ogg")();
                    boxed v23 = Panda3d::getSound()(unbox<string>(v) + "/sounds/door-open.ogg")();
                    boxed v24 = FRP_Event::create()();
                    Data_Functor::void_()(Effect::functorEffect())(FRP_Event::subscribe()(v24["event"])([=](const boxed& gameState) -> boxed {
                        if (unbox<dict_t>(gameState).contains("MainMenu")) {
                            return [=]() -> boxed {
                                boxed v25 = Panda3d::createEmptyNodePath()("scene-root")();
                                Panda3d::reparentTo()(v3)(v25)();
                                Panda3d::setFov()(v5)(35.0)();
                                Panda3d::setPosition()(v2)(-1.0)(-20.0)(-5.0)();
                                boxed v26 = Panda3d::addScreenText()(window)("press-s-text")("Press S...")();
                                Panda3d::setScale()(v26)(0.15)(0.15)(0.15)();
                                Panda3d::setPosition()(v26)(-0.3)(0.0)(-0.5)();
                                Panda3d::setFont()(v26)(v6)();
                                Panda3d::setTextAlignment()(v26)(Panda3d::textAlignCenter())();
                                Panda3d::showNodePath()(v26)(false)();
                                boxed v27 = Panda3d::createAmbientLight()("ambientLight")(0.203)(0.198)(0.301)();
                                boxed v28 = Panda3d::attachNewNode()(v25)(v27)();
                                Panda3d::setLight()(v25)(v28)();
                                boxed v29 = Panda3d::createPointLight()("light")(false)();
                                boxed v30 = Panda3d::attachNewNode()(v25)(v29)();
                                Panda3d::setPosition()(v30)(-6.6)(-3.5)(-2.9)();
                                Panda3d::setColor()(v30)(0.2)(0.2)(0.2)();
                                Panda3d::setLight()(v25)(v30)();
                                boxed v31 = Panda3d::createPointLight()("light1")(true)();
                                boxed v32 = Panda3d::attachNewNode()(v25)(v31)();
                                Panda3d::setPosition()(v32)(2.72)(-0.668)(1.41)();
                                Panda3d::setColor()(v32)(0.1)(0.38)(0.51)();
                                Panda3d::setAttenutation()(v32)(0.0)(0.0)(0.1)();
                                Panda3d::setLight()(v25)(v32)();
                                boxed v33 = Panda3d::loadModel()(window)(v4)(unbox<string>(v) + "/eggs/logo/logo")();
                                Panda3d::reparentTo()(v25)(v33)();
                                boxed v34 = Panda3d::createPointLight()("light2")(false)();
                                boxed v35 = Panda3d::attachNewNode()(v25)(v34)();
                                Panda3d::setColor()(v35)(1.0)(0.15)(0.29)();
                                Panda3d::setAttenutation()(v35)(0.0)(0.0)(1.0e-2)();
                                Panda3d::setLight()(v25)(v35)();
                                boxed v36 = Panda3d::loadAnimations()(v33)();
                                Panda3d::loopAnimation()(v36)("swing")(true)();
                                boxed v37 = Panda3d::exposeCharacterJoint()(v33)("bone")();
                                Panda3d::reparentTo()(v37)(v35)();
                                Panda3d::setPosition()(v35)(0.0)(3.0)(0.0)();
                                boxed v38 = FRP_Event::subscribe()(FRP_Event_Time::interval()(100))([=](const boxed& v38) -> boxed {
                                    return [=]() -> boxed {
                                        boxed v39 = Panda3d::getRandomNumber()(0.1)();
                                        return Panda3d::setColor()(v32)(0.1 - unbox<double>(v39))(0.38 - unbox<double>(v39))(0.51 - unbox<double>(v39))();
                                    };
                                })();
                                Panda3d::setSoundVolume()(v15)(0.1)();
                                Panda3d::setSoundLoop()(v15)(true)();
                                Panda3d::playSound()(v15)();
                                boxed v39 = FRP_Event::create()();
                                FRP_Event::subscribe()(Control_Apply::applySecond()(FRP_Event::applyEvent())(FRP_Event_Time::interval()(16))(v39["event"]))([=](const boxed& mainMenuState) -> boxed {
                                    if (unbox<dict_t>(mainMenuState).contains("MainMenuStateAnimating")) {
                                        return [=]() -> boxed {
                                            boxed v40 = Panda3d::getPosition()(v2)();
                                            boxed _var51_ = unbox<double>(v40["z"]) < -2.0;
                                            if (unbox<bool>(_var51_)) {
                                                return Panda3d::setPosition()(v2)(v40["x"])(v40["y"])(unbox<double>(v40["z"]) + 1.0e-2)();
                                            };
                                            return v39["push"](MainMenuStateWaiting())();
                                        };
                                    };
                                    if (unbox<dict_t>(mainMenuState).contains("MainMenuStateWaiting")) {
                                        return [=]() -> boxed {
                                            Panda3d::showNodePath()(v26)(true)();
                                            boxed v40 = Panda3d::isButtonDown()(window)(v9)();
                                            return Control_Applicative::when()(Effect::applicativeEffect())(v40)(v39["push"](MainMenuStateCleanUp()))();
                                        };
                                    };
                                    if (unbox<dict_t>(mainMenuState).contains("MainMenuStateCleanUp")) {
                                        return [=]() -> boxed {
                                            v38();
                                            Panda3d::removeNodePath()(v25)();
                                            Panda3d::removeNodePath()(v26)();
                                            Panda3d::stopSound()(v15)();
                                            v39["push"](MainMenuStateDone())();
                                            return v24["push"](Level())();
                                        };
                                    };
                                    if (unbox<dict_t>(mainMenuState).contains("MainMenuStateDone")) {
                                        return Control_Applicative::pure()(Effect::applicativeEffect())(Data_Unit::unit());
                                    };
                                    THROW_("Failed pattern match at Main (line 157, column 27 - line 188, column 59)");
                                })();
                                return v39["push"](MainMenuStateAnimating())();
                            };
                        };
                        if (unbox<dict_t>(gameState).contains("Level")) {
                            return [=]() -> boxed {
                                boxed v25 = Panda3d::createEmptyNodePath()("scene-root")();
                                Panda3d::reparentTo()(v3)(v25)();
                                Panda3d::setFov()(v5)(55.0)();
                                Panda3d::setPosition()(v2)(168.0)(-165.0)(108.0)();
                                boxed v26 = Panda3d::loadModel()(window)(v4)(unbox<string>(v) + "/eggs/room-0/room-0")();
                                Panda3d::reparentTo()(v25)(v26)();
                                boxed v27 = Panda3d::createAmbientLight()("ambientLight")(0.125)(0.122)(0.184)();
                                boxed v28 = Panda3d::attachNewNode()(v25)(v27)();
                                Panda3d::setLight()(v25)(v28)();
                                boxed v29 = Panda3d::createPointLight()("light")(false)();
                                boxed v30 = Panda3d::attachNewNode()(v25)(v29)();
                                Panda3d::setPosition()(v30)(44.0)(-64.0)(10.0)();
                                Panda3d::setColor()(v30)(0.2)(0.2)(0.2)();
                                Panda3d::setLight()(v25)(v30)();
                                boxed v31 = Panda3d::createPointLight()("light1")(true)();
                                boxed v32 = Panda3d::attachNewNode()(v25)(v31)();
                                Panda3d::setPosition()(v32)(43.0)(27.0)(10.0)();
                                Panda3d::setColor()(v32)(1.0)(0.737)(0.498)();
                                Panda3d::setLight()(v25)(v32)();
                                boxed v33 = Panda3d::createPointLight()("light2")(true)();
                                boxed v34 = Panda3d::attachNewNode()(v25)(v33)();
                                Panda3d::setPosition()(v34)(-33.0)(-38.0)(10.0)();
                                Panda3d::setColor()(v34)(0.38)(0.737)(0.663)();
                                Panda3d::setLight()(v25)(v34)();
                                boxed v35 = Panda3d::loadModel()(window)(v25)(unbox<string>(v) + "/eggs/main-character/main-character")();
                                Panda3d::setPosition()(v35)(0.0)(0.0)(25.0)();
                                Panda3d::lookAt()(v35)(v2)();
                                boxed v36 = Panda3d::addCollisionSphere()(v35)("main-character-collision-sphere")(0.0)(0.0)(0.0)(15.0)(false)();
                                boxed v37 = Panda3d::findNodePath()(v26)("crate")();
                                Panda3d::reparentTo()(v25)(v37)();
                                Panda3d::addCollisionBox()(v37)("crate-collision-box")(0.0)(0.0)(0.0)(8.0)(8.0)(8.0)(false)();
                                boxed v39 = Panda3d::findNodePath()(v26)("door")();
                                Panda3d::reparentTo()(v25)(v39)();
                                Panda3d::setHpr()(v39)(0.0)(0.0)(0.0)();
                                Panda3d::addCollisionBox()(v39)("door-collision-box")(17.0)(0.0)(0.0)(17.0)(6.0)(25.0)(false)();
                                Panda3d::addColliderToTraverserAndPusher()(v35)(v36)();
                                Panda3d::addCollisionBox()(v25)("east-wall-collision-box")(-55.0)(-5.0)(34.0)(5.0)(70.0)(30.0)(false)();
                                Panda3d::addCollisionBox()(v25)("south-wall-collision-box")(0.0)(-75.0)(34.0)(70.0)(5.0)(30.0)(false)();
                                Panda3d::addCollisionBox()(v25)("west-wall-collision-box")(60.0)(-5.0)(34.0)(5.0)(70.0)(30.0)(false)();
                                Panda3d::addCollisionBox()(v25)("north-left-wall-collision-box")(-34.0)(50.0)(34.0)(15.0)(5.0)(30.0)(false)();
                                Panda3d::addCollisionBox()(v25)("north-right-wall-collision-box")(34.0)(50.0)(34.0)(15.0)(5.0)(30.0)(false)();
                                boxed v46 = Panda3d::loadAnimations()(v35)();
                                Panda3d::loopAnimation()(v46)("hover")(true)();
                                Panda3d::setSoundVolume()(v16)(0.1)();
                                Panda3d::setSoundLoop()(v16)(true)();
                                Panda3d::playSound()(v16)();
                                boxed v47 = Panda3d::addScreenText()(window)("timer-text")(Data_Show::show()(Data_Show::showInt())(60))();
                                Panda3d::setFont()(v47)(v6)();
                                Panda3d::setScale()(v47)(0.5)(0.5)(0.5)();
                                Panda3d::setPosition()(v47)(-0.2)(0.0)(0.5)();
                                Panda3d::showNodePath()(v47)(false)();
                                boxed v48 = Panda3d::addScreenText()(window)("you-lost-text")("You lost! :(")();
                                Panda3d::setScale()(v48)(0.16)(0.15)(0.15)();
                                Panda3d::setPosition()(v48)(-0.4)(0.0)(-0.5)();
                                Panda3d::setFont()(v48)(v6)();
                                Panda3d::setTextAlignment()(v48)(Panda3d::textAlignCenter())();
                                Panda3d::showNodePath()(v48)(false)();
                                boxed v49 = Panda3d::addScreenText()(window)("you-won-text")("You won! :)")();
                                Panda3d::setScale()(v49)(0.16)(0.15)(0.15)();
                                Panda3d::setPosition()(v49)(-0.4)(0.0)(-0.5)();
                                Panda3d::setFont()(v49)(v6)();
                                Panda3d::setTextAlignment()(v49)(Panda3d::textAlignCenter())();
                                Panda3d::showNodePath()(v49)(false)();
                                boxed puzzleTextPrime_ = "You examine the crate and there appears to be a chicken inside?!\n" + ("As you try to get the chicken out, you notice the stone underneath\n" + ("springs up and down a bit.\n" + ("Curiously, every time you push, the door also jiggles behind you.\n" + ("If you can make the crate heavy enough, I bet the door will pop open!" + ("\n\n" + ("Crate(Boulder) = ___ Crate(Chicken)" + ("\n\n" + ("Which incantation fills out the blank? Press 1, 2, or 3." + ("\n\n" + ("1) fmap ((Feathers -> Boulder) . (Chicken -> Feathers))\n" + (string("2) foldl (Feathers -> Chicken -> Feathers) Feathers\n") + "3) flip (>>=) (Boulder -> Crate(Chicken))\n")))))))))));
                                boxed v50 = Panda3d::addScreenText()(window)("intro-text")(puzzleTextPrime_)();
                                Panda3d::setFont()(v50)(v6)();
                                Panda3d::setScale()(v50)(6.0e-2)(6.0e-2)(6.0e-2)();
                                Panda3d::setPosition()(v50)(-1.0)(0.0)(0.7)();
                                Panda3d::setTextCardColor()(v50)(0.1)(0.1)(0.1)(0.8)();
                                Panda3d::setTextCardMargin()(v50)(0.8)(0.8)(0.8)(0.8)();
                                Panda3d::setTextCardDecal()(v50)(true)();
                                Panda3d::showNodePath()(v50)(false)();
                                boxed v51 = FRP_Event::create()();
                                boxed v52 = FRP_Event::create()();
                                boxed v53 = FRP_Event::subscribe()(FRP_Event_Time::interval()(100))([=](const boxed& v53) -> boxed {
                                    return [=]() -> boxed {
                                        boxed v54 = Panda3d::getRandomNumber()(0.1)();
                                        boxed v55 = Panda3d::getRandomNumber()(0.1)();
                                        Panda3d::setColor()(v32)(1.0 - unbox<double>(v54))(0.504 - unbox<double>(v54))(0.213 - unbox<double>(v54))();
                                        return Panda3d::setColor()(v34)(0.12 - unbox<double>(v55))(0.505 - unbox<double>(v55))(0.395 - unbox<double>(v55))();
                                    };
                                })();
                                boxed v54 = FRP_Event::create()();
                                boxed v55 = FRP_Event::create()();
                                boxed v56 = FRP_Event::subscribe()(Control_Apply::applySecond()(FRP_Event::applyEvent())(FRP_Event_Time::interval()(16))(v52["event"]))([=](const boxed& levelState) -> boxed {
                                    if (unbox<dict_t>(levelState).contains("LevelStatePlaying")) {
                                        return [=]() -> boxed {
                                            boxed v56 = Panda3d::isButtonDown()(window)(v7)();
                                            boxed v57 = Panda3d::isButtonDown()(window)(v9)();
                                            boxed v58 = Panda3d::isButtonDown()(window)(v8)();
                                            boxed v59 = Panda3d::isButtonDown()(window)(v10)();
                                            boxed v60 = Panda3d::isButtonDown()(window)(v14)();
                                            boxed v61 = Panda3d::getHpr()(v35)();
                                            Panda3d::setHpr()(v35)(v61["h"])(0.0)(0.0)();
                                            Control_Applicative::when()(Effect::applicativeEffect())(v56)([=]() -> boxed {
                                                Panda3d::setHpr()(v35)(0.0)(0.0)(0.0)();
                                                Panda3d::setHpr()(v35)(180.0)(10.0)(0.0)();
                                                boxed v62 = Panda3d::getPosition()(v35)();
                                                return Panda3d::setPosition()(v35)(v62["x"])(unbox<double>(v62["y"]) + 1.0)(v62["z"])();
                                            })();
                                            Control_Applicative::when()(Effect::applicativeEffect())(v58)([=]() -> boxed {
                                                Panda3d::setHpr()(v35)(0.0)(0.0)(0.0)();
                                                Panda3d::setHpr()(v35)(-90.0)(10.0)(0.0)();
                                                boxed v62 = Panda3d::getPosition()(v35)();
                                                return Panda3d::setPosition()(v35)(unbox<double>(v62["x"]) - 1.0)(v62["y"])(v62["z"])();
                                            })();
                                            Control_Applicative::when()(Effect::applicativeEffect())(v57)([=]() -> boxed {
                                                Panda3d::setHpr()(v35)(0.0)(10.0)(0.0)();
                                                boxed v62 = Panda3d::getPosition()(v35)();
                                                return Panda3d::setPosition()(v35)(v62["x"])(unbox<double>(v62["y"]) - 1.0)(v62["z"])();
                                            })();
                                            Control_Applicative::when()(Effect::applicativeEffect())(v59)([=]() -> boxed {
                                                Panda3d::setHpr()(v35)(0.0)(0.0)(0.0)();
                                                Panda3d::setHpr()(v35)(90.0)(10.0)(0.0)();
                                                boxed v62 = Panda3d::getPosition()(v35)();
                                                return Panda3d::setPosition()(v35)(unbox<double>(v62["x"]) + 1.0)(v62["y"])(v62["z"])();
                                            })();
                                            boxed v62 = Panda3d::getPosition()(v35)();
                                            boxed v63 = Panda3d::getPosition()(v37)();
                                            boxed distance = Math::pow()(unbox<double>(Math::pow()(unbox<double>(v62["x"]) - unbox<double>(v63["x"]))(2.0)) + unbox<double>(Math::pow()(unbox<double>(v62["y"]) - unbox<double>(v63["y"]))(2.0)))(0.5);
                                            boxed v64 = Panda3d::getPosition()(v37)();
                                            Control_Applicative::when()(Effect::applicativeEffect())(unbox<double>(distance) <= 25.0)(Control_Applicative::when()(Effect::applicativeEffect())(unbox<bool>(v60) && unbox<double>(v64["z"]) >= 1.0)([=]() -> boxed {
                                                Panda3d::showNodePath()(v50)(true)();
                                                Panda3d::setSoundVolume()(v20)(0.1)();
                                                Panda3d::playSound()(v20)();
                                                return v51["push"](true)();
                                            }))();
                                            return Control_Applicative::when()(Effect::applicativeEffect())(unbox<double>(v62["y"]) >= 56.0)(v52["push"](LevelStateSuccess()))();
                                        };
                                    };
                                    return Control_Applicative::pure()(Effect::applicativeEffect())(Data_Unit::unit());
                                })();
                                boxed v57 = FRP_Event::subscribe()(Control_Apply::applySecond()(FRP_Event::applyEvent())(FRP_Event_Time::interval()(16))(v51["event"]))([=](const boxed& puzzleTextShown) -> boxed {
                                    return Control_Applicative::when()(Effect::applicativeEffect())(puzzleTextShown)([=]() -> boxed {
                                        boxed v57 = Panda3d::isButtonDown()(window)(v11)();
                                        boxed v58 = Panda3d::isButtonDown()(window)(v12)();
                                        boxed v59 = Panda3d::isButtonDown()(window)(v13)();
                                        Control_Applicative::when()(Effect::applicativeEffect())(v57)([=]() -> boxed {
                                            Panda3d::setSoundVolume()(v21)(0.1)();
                                            Panda3d::playSound()(v21)();
                                            Panda3d::showNodePath()(v50)(false)();
                                            v54["push"](true)();
                                            Panda3d::setSoundVolume()(v22)(0.2)();
                                            return Panda3d::playSound()(v22)();
                                        })();
                                        Control_Applicative::when()(Effect::applicativeEffect())(v58)(v52["push"](LevelStateFailure()))();
                                        return Control_Applicative::when()(Effect::applicativeEffect())(v59)(v52["push"](LevelStateFailure()))();
                                    });
                                })();
                                boxed v58 = FRP_Event::subscribe()(Control_Apply::applySecond()(FRP_Event::applyEvent())(FRP_Event_Time::interval()(16))(v54["event"]))([=](const boxed& crateAnimation) -> boxed {
                                    return Control_Applicative::when()(Effect::applicativeEffect())(crateAnimation)([=]() -> boxed {
                                        boxed v58 = Panda3d::getPosition()(v37)();
                                        return Control_Applicative::when()(Effect::applicativeEffect())(unbox<double>(v58["z"]) >= 1.0)([=]() -> boxed {
                                            Panda3d::setPosition()(v37)(v58["x"])(v58["y"])(unbox<double>(v58["z"]) - 7.0e-2)();
                                            return Control_Applicative::when()(Effect::applicativeEffect())(unbox<double>(v58["z"]) - 7.0e-2 < 1.0)([=]() -> boxed {
                                                Panda3d::setSoundVolume()(v23)(0.1)();
                                                Panda3d::playSound()(v23)();
                                                return v55["push"](true)();
                                            })();
                                        })();
                                    });
                                })();
                                boxed v59 = FRP_Event::subscribe()(Control_Apply::applySecond()(FRP_Event::applyEvent())(FRP_Event_Time::interval()(16))(v55["event"]))([=](const boxed& doorAnimation) -> boxed {
                                    return Control_Applicative::when()(Effect::applicativeEffect())(doorAnimation)([=]() -> boxed {
                                        boxed v59 = Panda3d::getHpr()(v39)();
                                        return Control_Applicative::when()(Effect::applicativeEffect())(unbox<double>(v59["h"]) <= 120.0)(Panda3d::setHpr()(v39)(unbox<double>(v59["h"]) + 1.0)(v59["p"])(v59["r"]))();
                                    });
                                })();
                                boxed v60 = FRP_Event::create()();
                                boxed v61 = FRP_Event::subscribe()(FRP_Event_Class::sampleOn_()(FRP_Event::eventIsEvent())(v60["event"])(FRP_Event_Time::interval()(1000)))([=](const boxed& secondsPassed) -> boxed {
                                    return Control_Applicative::when()(Effect::applicativeEffect())(unbox<int>(secondsPassed) <= 60 + 1)([=]() -> boxed {
                                        boxed secondsLeft = 60 - unbox<int>(secondsPassed);
                                        return [=]() -> boxed {
                                            [=]() -> boxed {
                                                boxed _var104_ = unbox<int>(secondsLeft) < 0;
                                                if (unbox<bool>(_var104_)) {
                                                    return v52["push"](LevelStateFailure())();
                                                };
                                                return Panda3d::setText()(v47)(Data_Show::show()(Data_Show::showInt())(secondsLeft))();
                                            }();
                                            return v60["push"](unbox<int>(secondsPassed) + 1)();
                                        };
                                    }());
                                })();
                                FRP_Event::subscribe()(v52["event"])([=](const boxed& levelState) -> boxed {
                                    if (unbox<dict_t>(levelState).contains("LevelStateIntro")) {
                                        boxed introTextPrime_ = "The evil sorcerer State has trapped you in their dungeon of complexity.\n" + ("Good thing you have the Lambda Lantern!\n" + (u8"Assemble the right incantation and escape State's dungeon but hurry\U00002014\n" + ("Lambda Lantern's light is about to run out!" + ("\n\n" + ("Press W, A, S, and/or D to move around.\n" + ("If something is context sensitive, press the space bar\n" + ("to interact with it." + (string("\n\n") + "Okay press space to start! :D"))))))));
                                        return [=]() -> boxed {
                                            boxed v62 = Panda3d::addScreenText()(window)("intro-text")(introTextPrime_)();
                                            Panda3d::setFont()(v62)(v6)();
                                            Panda3d::setScale()(v62)(6.0e-2)(6.0e-2)(6.0e-2)();
                                            Panda3d::setPosition()(v62)(-1.07)(0.0)(0.5)();
                                            Panda3d::setTextCardColor()(v62)(0.1)(0.1)(0.1)(0.8)();
                                            Panda3d::setTextCardMargin()(v62)(0.8)(0.8)(0.8)(0.8)();
                                            Panda3d::setTextCardDecal()(v62)(true)();
                                            Panda3d::setSoundVolume()(v18)(0.1)();
                                            Panda3d::playSound()(v18)();
                                            boxed v63 = FRP_Event::create()();
                                            boxed v64 = FRP_Event::subscribe()(FRP_Event_Class::sampleOn_()(FRP_Event::eventIsEvent())(v63["event"])(FRP_Event_Time::interval()(16)))([=](const boxed& leavingIntro) -> boxed {
                                                return Control_Applicative::unless()(Effect::applicativeEffect())(leavingIntro)([=]() -> boxed {
                                                    boxed v64 = Panda3d::isButtonDown()(window)(v14)();
                                                    return Control_Applicative::when()(Effect::applicativeEffect())(v64)([=]() -> boxed {
                                                        Panda3d::removeNodePath()(v62)();
                                                        v63["push"](true)();
                                                        return v52["push"](LevelStatePlaying())();
                                                    })();
                                                });
                                            })();
                                            v63["push"](false)();
                                            return Data_Functor::void_()(Effect::functorEffect())(FRP_Event::subscribe()(v63["event"])([=](const boxed& leavingIntro) -> boxed {
                                                return Control_Applicative::when()(Effect::applicativeEffect())(leavingIntro)([=]() -> boxed {
                                                    v64();
                                                    return Data_Unit::unit();
                                                });
                                            }))();
                                        };
                                    };
                                    if (unbox<dict_t>(levelState).contains("LevelStatePlaying")) {
                                        return [=]() -> boxed {
                                            Panda3d::showNodePath()(v47)(true)();
                                            return v60["push"](0)();
                                        };
                                    };
                                    if (unbox<dict_t>(levelState).contains("LevelStateFailure")) {
                                        return [=]() -> boxed {
                                            Panda3d::showNodePath()(v47)(false)();
                                            Panda3d::showNodePath()(v50)(false)();
                                            Panda3d::showNodePath()(v48)(true)();
                                            Panda3d::setColor()(v30)(0.0)(0.0)(0.0)();
                                            Panda3d::setColor()(v32)(0.0)(0.0)(0.0)();
                                            Panda3d::setColor()(v34)(0.0)(0.0)(0.0)();
                                            Panda3d::setSoundVolume()(v18)(0.1)();
                                            Panda3d::playSound()(v18)();
                                            v53();
                                            Panda3d::stopSound()(v16)();
                                            return Data_Functor::void_()(Effect::functorEffect())(Effect_Timer::setTimeout()(2000)(v52["push"](LevelStateCleanUp())))();
                                        };
                                    };
                                    if (unbox<dict_t>(levelState).contains("LevelStateSuccess")) {
                                        return [=]() -> boxed {
                                            Panda3d::showNodePath()(v47)(false)();
                                            Panda3d::showNodePath()(v50)(false)();
                                            Panda3d::showNodePath()(v49)(true)();
                                            Panda3d::stopSound()(v16)();
                                            Panda3d::setSoundVolume()(v19)(0.1)();
                                            Panda3d::playSound()(v19)();
                                            return Data_Functor::void_()(Effect::functorEffect())(Effect_Timer::setTimeout()(2000)(v52["push"](LevelStateCleanUp())))();
                                        };
                                    };
                                    if (unbox<dict_t>(levelState).contains("LevelStateCleanUp")) {
                                        return [=]() -> boxed {
                                            v61();
                                            v56();
                                            v58();
                                            v59();
                                            v57();
                                            Panda3d::removeNodePath()(v25)();
                                            Panda3d::removeNodePath()(v47)();
                                            Panda3d::removeNodePath()(v50)();
                                            Panda3d::removeNodePath()(v48)();
                                            Panda3d::removeNodePath()(v49)();
                                            v52["push"](LevelStateDone())();
                                            return v24["push"](Ending())();
                                        };
                                    };
                                    if (unbox<dict_t>(levelState).contains("LevelStateDone")) {
                                        return Control_Applicative::pure()(Effect::applicativeEffect())(Data_Unit::unit());
                                    };
                                    THROW_("Failed pattern match at Main (line 539, column 25 - line 648, column 54)");
                                })();
                                v52["push"](LevelStateIntro())();
                                return Data_Unit::unit();
                            };
                        };
                        if (unbox<dict_t>(gameState).contains("Ending")) {
                            return [=]() -> boxed {
                                Panda3d::setSoundVolume()(v17)(0.1)();
                                Panda3d::playSound()(v17)();
                                boxed endingTextPrime_ = "Lambda Lantern was created by me, David Lettier. Visit lettier.com and\n" + ("follow @lettier on Twitter if you'd like." + ("\n\n" + ("Keep an eye on Lambda Lantern. New releases will be bigger and better\n" + ("with more levels and more interesting puzzles!" + ("\n\n" + ("Special thanks to freepd.com for the music, freesound.com for the\n" + ("sounds, and Kimberly Geswein for the font." + (string("\n\n") + "Thanks for playing! :D"))))))));
                                boxed v25 = Panda3d::addScreenText()(window)("intro-text")(endingTextPrime_)();
                                Panda3d::setFont()(v25)(v6)();
                                Panda3d::setScale()(v25)(6.0e-2)(6.0e-2)(6.0e-2)();
                                return Panda3d::setPosition()(v25)(-1.1)(0.0)(0.6)();
                            };
                        };
                        THROW_("Failed pattern match at Main (line 90, column 17 - line 674, column 62)");
                    }))();
                    FRP_Event::subscribe()(FRP_Event_Time::interval()(16))([=](const boxed& v25) -> boxed {
                        return [=]() -> boxed {
                            Panda3d::updateAudioManager()();
                            return Panda3d::traverseCollisionTraverser()(v3)();
                        };
                    })();
                    v24["push"](MainMenu())();
                    return Panda3d::setShaderAuto()(v3)();
                };
            })();
        };
    });
};


} // end namespace Main

int main(int argc, const char * argv[]) {
    Main::main()();
    return 0;
}

