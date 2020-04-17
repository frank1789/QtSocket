#include <memory>

#include "gtest/gtest.h"
#include "labels.hpp"
#include "test_label_function.hpp"

TEST(Labels, IndexNumber) {
  const std::string label_path = {
      "../build_debug/test/resources/labels.txt"};
  auto label_ = std::make_unique<LabelDetection>(label_path);
  label_->read();
  auto num_lab = label_->getLabels().size();
  EXPECT_EQ(num_lab, 1001);
}

TEST(Labels, Generic) {
  const std::string label_path = {"../build_debug/test/resources/labels.txt"};
  auto label_ = std::make_unique<LabelDetection>(label_path);
  label_->read();
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 0), 0);
  EXPECT_EQ(getLabel(label_->getLabels(), 0), "background");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 1), 1);
  EXPECT_EQ(getLabel(label_->getLabels(), 1), "tench, Tinca tinca");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 2), 2);
  EXPECT_EQ(getLabel(label_->getLabels(), 2), "goldfish, Carassius auratus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 3), 3);
  EXPECT_EQ(getLabel(label_->getLabels(), 3),
            "great white shark, white shark, man-eater, man-eating shark, "
            "Carcharodon carcharias");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 4), 4);
  EXPECT_EQ(getLabel(label_->getLabels(), 4),
            "tiger shark, Galeocerdo cuvieri");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 5), 5);
  EXPECT_EQ(getLabel(label_->getLabels(), 5), "hammerhead, hammerhead shark");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 6), 6);
  EXPECT_EQ(getLabel(label_->getLabels(), 6),
            "electric ray, crampfish, numbfish, torpedo");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 7), 7);
  EXPECT_EQ(getLabel(label_->getLabels(), 7), "stingray");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 8), 8);
  EXPECT_EQ(getLabel(label_->getLabels(), 8), "cock");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 9), 9);
  EXPECT_EQ(getLabel(label_->getLabels(), 9), "hen");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 10), 10);
  EXPECT_EQ(getLabel(label_->getLabels(), 10), "ostrich, Struthio camelus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 11), 11);
  EXPECT_EQ(getLabel(label_->getLabels(), 11),
            "brambling, Fringilla montifringilla");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 12), 12);
  EXPECT_EQ(getLabel(label_->getLabels(), 12),
            "goldfinch, Carduelis carduelis");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 13), 13);
  EXPECT_EQ(getLabel(label_->getLabels(), 13),
            "house finch, linnet, Carpodacus mexicanus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 14), 14);
  EXPECT_EQ(getLabel(label_->getLabels(), 14), "junco, snowbird");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 15), 15);
  EXPECT_EQ(getLabel(label_->getLabels(), 15),
            "indigo bunting, indigo finch, indigo bird, Passerina cyanea");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 16), 16);
  EXPECT_EQ(getLabel(label_->getLabels(), 16),
            "robin, American robin, Turdus migratorius");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 17), 17);
  EXPECT_EQ(getLabel(label_->getLabels(), 17), "bulbul");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 18), 18);
  EXPECT_EQ(getLabel(label_->getLabels(), 18), "jay");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 19), 19);
  EXPECT_EQ(getLabel(label_->getLabels(), 19), "magpie");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 20), 20);
  EXPECT_EQ(getLabel(label_->getLabels(), 20), "chickadee");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 21), 21);
  EXPECT_EQ(getLabel(label_->getLabels(), 21), "water ouzel, dipper");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 22), 22);
  EXPECT_EQ(getLabel(label_->getLabels(), 22), "kite");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 23), 23);
  EXPECT_EQ(getLabel(label_->getLabels(), 23),
            "bald eagle, American eagle, Haliaeetus leucocephalus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 24), 24);
  EXPECT_EQ(getLabel(label_->getLabels(), 24), "vulture");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 25), 25);
  EXPECT_EQ(getLabel(label_->getLabels(), 25),
            "great grey owl, great gray owl, Strix nebulosa");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 26), 26);
  EXPECT_EQ(getLabel(label_->getLabels(), 26),
            "European fire salamander, Salamandra salamandra");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 27), 27);
  EXPECT_EQ(getLabel(label_->getLabels(), 27),
            "common newt, Triturus vulgaris");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 28), 28);
  EXPECT_EQ(getLabel(label_->getLabels(), 28), "eft");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 29), 29);
  EXPECT_EQ(getLabel(label_->getLabels(), 29),
            "spotted salamander, Ambystoma maculatum");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 30), 30);
  EXPECT_EQ(getLabel(label_->getLabels(), 30),
            "axolotl, mud puppy, Ambystoma mexicanum");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 31), 31);
  EXPECT_EQ(getLabel(label_->getLabels(), 31), "bullfrog, Rana catesbeiana");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 32), 32);
  EXPECT_EQ(getLabel(label_->getLabels(), 32), "tree frog, tree-frog");

  EXPECT_EQ(getIndexLabel(label_->getLabels(), 33), 33);
  EXPECT_EQ(getLabel(label_->getLabels(), 33),
            "tailed frog, bell toad, ribbed toad, tailed toad, Ascaphus trui");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 34), 34);
  EXPECT_EQ(getLabel(label_->getLabels(), 34),
            "loggerhead, loggerhead turtle, Caretta caretta");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 35), 35);
  EXPECT_EQ(getLabel(label_->getLabels(), 35),
            "leatherback turtle, leatherback, leathery turtle, Dermochelys "
            "coriacea");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 36), 36);
  EXPECT_EQ(getLabel(label_->getLabels(), 36), "mud turtle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 37), 37);
  EXPECT_EQ(getLabel(label_->getLabels(), 37), "terrapin");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 38), 38);
  EXPECT_EQ(getLabel(label_->getLabels(), 38), "box turtle, box tortoise");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 39), 39);
  EXPECT_EQ(getLabel(label_->getLabels(), 39), "banded gecko");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 40), 40);
  EXPECT_EQ(getLabel(label_->getLabels(), 40),
            "common iguana, iguana, Iguana iguana");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 41), 41);
  EXPECT_EQ(getLabel(label_->getLabels(), 41),
            "American chameleon, anole, Anolis carolinensis");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 42), 42);
  EXPECT_EQ(getLabel(label_->getLabels(), 42), "whiptail, whiptail lizard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 43), 43);
  EXPECT_EQ(getLabel(label_->getLabels(), 43), "agama");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 44), 44);
  EXPECT_EQ(getLabel(label_->getLabels(), 44),
            "frilled lizard, Chlamydosaurus kingi");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 45), 45);
  EXPECT_EQ(getLabel(label_->getLabels(), 45), "alligator lizard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 46), 46);
  EXPECT_EQ(getLabel(label_->getLabels(), 46),
            "Gila monster, Heloderma suspectum");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 47), 47);
  EXPECT_EQ(getLabel(label_->getLabels(), 47), "green lizard, Lacerta viridis");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 48), 48);
  EXPECT_EQ(getLabel(label_->getLabels(), 48),
            "African chameleon, Chamaeleo chamaeleon");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 49), 49);
  EXPECT_EQ(getLabel(label_->getLabels(), 49),
            "Komodo dragon, Komodo lizard, dragon lizard, giant lizard, "
            "Varanus komodoensis");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 50), 50);
  EXPECT_EQ(getLabel(label_->getLabels(), 50),
            "African crocodile, Nile crocodile, Crocodylus niloticus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 51), 51);
  EXPECT_EQ(getLabel(label_->getLabels(), 51),
            "American alligator, Alligator mississipiensis");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 52), 52);
  EXPECT_EQ(getLabel(label_->getLabels(), 52), "triceratops");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 53), 53);
  EXPECT_EQ(getLabel(label_->getLabels(), 53),
            "thunder snake, worm snake, Carphophis amoenus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 54), 54);
  EXPECT_EQ(getLabel(label_->getLabels(), 54),
            "ringneck snake, ring-necked snake, ring snake");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 55), 55);
  EXPECT_EQ(getLabel(label_->getLabels(), 55),
            "hognose snake, puff adder, sand viper");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 56), 56);
  EXPECT_EQ(getLabel(label_->getLabels(), 56), "green snake, grass snake");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 57), 57);
  EXPECT_EQ(getLabel(label_->getLabels(), 57), "king snake, kingsnake");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 58), 58);
  EXPECT_EQ(getLabel(label_->getLabels(), 58), "garter snake, grass snake");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 59), 59);
  EXPECT_EQ(getLabel(label_->getLabels(), 59), "water snake");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 60), 60);
  EXPECT_EQ(getLabel(label_->getLabels(), 60), "vine snake");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 61), 61);
  EXPECT_EQ(getLabel(label_->getLabels(), 61),
            "night snake, Hypsiglena torquata");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 62), 62);
  EXPECT_EQ(getLabel(label_->getLabels(), 62),
            "boa constrictor, Constrictor constrictor");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 63), 63);
  EXPECT_EQ(getLabel(label_->getLabels(), 63),
            "rock python, rock snake, Python sebae");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 64), 64);
  EXPECT_EQ(getLabel(label_->getLabels(), 64), "Indian cobra, Naja naja");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 65), 65);
  EXPECT_EQ(getLabel(label_->getLabels(), 65), "green mamba");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 66), 66);
  EXPECT_EQ(getLabel(label_->getLabels(), 66), "sea snake");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 67), 67);
  EXPECT_EQ(
      getLabel(label_->getLabels(), 67),
      "horned viper, cerastes, sand viper, horned asp, Cerastes cornutus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 68), 68);
  EXPECT_EQ(getLabel(label_->getLabels(), 68),
            "diamondback, diamondback rattlesnake, Crotalus adamanteus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 69), 69);
  EXPECT_EQ(getLabel(label_->getLabels(), 69),
            "sidewinder, horned rattlesnake, Crotalus cerastes");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 70), 70);
  EXPECT_EQ(getLabel(label_->getLabels(), 70), "trilobite");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 71), 71);
  EXPECT_EQ(getLabel(label_->getLabels(), 71),
            "harvestman, daddy longlegs, Phalangium opilio");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 72), 72);
  EXPECT_EQ(getLabel(label_->getLabels(), 72), "scorpion");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 73), 73);
  EXPECT_EQ(getLabel(label_->getLabels(), 73),
            "black and gold garden spider, Argiope aurantia");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 74), 74);
  EXPECT_EQ(getLabel(label_->getLabels(), 74),
            "barn spider, Araneus cavaticus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 75), 75);
  EXPECT_EQ(getLabel(label_->getLabels(), 75),
            "garden spider, Aranea diademata");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 76), 76);
  EXPECT_EQ(getLabel(label_->getLabels(), 76),
            "black widow, Latrodectus mactans");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 77), 77);
  EXPECT_EQ(getLabel(label_->getLabels(), 77), "tarantula");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 78), 78);
  EXPECT_EQ(getLabel(label_->getLabels(), 78), "wolf spider, hunting spider");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 79), 79);
  EXPECT_EQ(getLabel(label_->getLabels(), 79), "tick");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 80), 80);
  EXPECT_EQ(getLabel(label_->getLabels(), 80), "centipede");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 81), 81);
  EXPECT_EQ(getLabel(label_->getLabels(), 81), "black grouse");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 82), 82);
  EXPECT_EQ(getLabel(label_->getLabels(), 82), "ptarmigan");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 83), 83);
  EXPECT_EQ(getLabel(label_->getLabels(), 83),
            "ruffed grouse, partridge, Bonasa umbellus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 84), 84);
  EXPECT_EQ(getLabel(label_->getLabels(), 84),
            "prairie chicken, prairie grouse, prairie fowl");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 85), 85);
  EXPECT_EQ(getLabel(label_->getLabels(), 85), "peacock");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 86), 86);
  EXPECT_EQ(getLabel(label_->getLabels(), 86), "quail");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 87), 87);
  EXPECT_EQ(getLabel(label_->getLabels(), 87), "partridge");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 88), 88);
  EXPECT_EQ(getLabel(label_->getLabels(), 88),
            "African grey, African gray, Psittacus erithacus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 89), 89);
  EXPECT_EQ(getLabel(label_->getLabels(), 89), "macaw");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 90), 90);
  EXPECT_EQ(getLabel(label_->getLabels(), 90),
            "sulphur-crested cockatoo, Kakatoe galerita, Cacatua galerita");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 91), 91);
  EXPECT_EQ(getLabel(label_->getLabels(), 91), "lorikeet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 92), 92);
  EXPECT_EQ(getLabel(label_->getLabels(), 92), "coucal");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 93), 93);
  EXPECT_EQ(getLabel(label_->getLabels(), 93), "bee eater");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 94), 94);
  EXPECT_EQ(getLabel(label_->getLabels(), 94), "hornbill");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 95), 95);
  EXPECT_EQ(getLabel(label_->getLabels(), 95), "hummingbird");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 96), 96);
  EXPECT_EQ(getLabel(label_->getLabels(), 96), "jacamar");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 97), 97);
  EXPECT_EQ(getLabel(label_->getLabels(), 97), "toucan");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 98), 98);
  EXPECT_EQ(getLabel(label_->getLabels(), 98), "drake");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 99), 99);
  EXPECT_EQ(getLabel(label_->getLabels(), 99),
            "red-breasted merganser, Mergus serrator");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 100), 100);
  EXPECT_EQ(getLabel(label_->getLabels(), 100), "goose");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 101), 101);
  EXPECT_EQ(getLabel(label_->getLabels(), 101), "black swan, Cygnus atratus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 102), 102);
  EXPECT_EQ(getLabel(label_->getLabels(), 102), "tusker");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 103), 103);
  EXPECT_EQ(getLabel(label_->getLabels(), 103),
            "echidna, spiny anteater, anteater");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 104), 104);
  EXPECT_EQ(getLabel(label_->getLabels(), 104),
            "platypus, duckbill, duckbilled platypus, duck-billed platypus, "
            "Ornithorhynchus anatinus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 105), 105);
  EXPECT_EQ(getLabel(label_->getLabels(), 105), "wallaby, brush kangaroo");

  EXPECT_EQ(getIndexLabel(label_->getLabels(), 106), 106);
  EXPECT_EQ(getLabel(label_->getLabels(), 106),
            "koala, koala bear, kangaroo bear, native bear, Phascolarctos "
            "cinereus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 107), 107);
  EXPECT_EQ(getLabel(label_->getLabels(), 107), "wombat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 108), 108);
  EXPECT_EQ(getLabel(label_->getLabels(), 108), "jellyfish");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 109), 109);
  EXPECT_EQ(getLabel(label_->getLabels(), 109), "sea anemone, anemone");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 110), 110);
  EXPECT_EQ(getLabel(label_->getLabels(), 110), "brain coral");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 111), 111);
  EXPECT_EQ(getLabel(label_->getLabels(), 111), "flatworm, platyhelminth");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 112), 112);
  EXPECT_EQ(getLabel(label_->getLabels(), 112),
            "nematode, nematode worm, roundworm");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 113), 113);
  EXPECT_EQ(getLabel(label_->getLabels(), 113), "conch");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 114), 114);
  EXPECT_EQ(getLabel(label_->getLabels(), 114), "snail");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 115), 115);
  EXPECT_EQ(getLabel(label_->getLabels(), 115), "slug");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 116), 116);
  EXPECT_EQ(getLabel(label_->getLabels(), 116), "sea slug, nudibranch");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 117), 117);
  EXPECT_EQ(getLabel(label_->getLabels(), 117),
            "chiton, coat-of-mail shell, sea cradle, polyplacophore");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 118), 118);
  EXPECT_EQ(getLabel(label_->getLabels(), 118),
            "chambered nautilus, pearly nautilus, nautilus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 119), 119);
  EXPECT_EQ(getLabel(label_->getLabels(), 119),
            "Dungeness crab, Cancer magister");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 120), 120);
  EXPECT_EQ(getLabel(label_->getLabels(), 120), "rock crab, Cancer irroratus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 121), 121);
  EXPECT_EQ(getLabel(label_->getLabels(), 121), "fiddler crab");

  EXPECT_EQ(getIndexLabel(label_->getLabels(), 122), 122);
  EXPECT_EQ(getLabel(label_->getLabels(), 122),
            "king crab, Alaska crab, Alaskan king crab, Alaska king crab, "
            "Paralithodes camtschatica");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 123), 123);
  EXPECT_EQ(getLabel(label_->getLabels(), 123),
            "American lobster, Northern lobster, Maine lobster, Homarus "
            "americanus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 124), 124);
  EXPECT_EQ(getLabel(label_->getLabels(), 124),
            "spiny lobster, langouste, rock lobster, crawfish, crayfish, sea "
            "crawfish");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 125), 125);
  EXPECT_EQ(getLabel(label_->getLabels(), 125),
            "crayfish, crawfish, crawdad, crawdaddy");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 126), 126);
  EXPECT_EQ(getLabel(label_->getLabels(), 126), "hermit crab");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 127), 127);
  EXPECT_EQ(getLabel(label_->getLabels(), 127), "isopod");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 128), 128);
  EXPECT_EQ(getLabel(label_->getLabels(), 128), "white stork, Ciconia ciconia");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 129), 129);
  EXPECT_EQ(getLabel(label_->getLabels(), 129), "black stork, Ciconia nigra");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 130), 130);
  EXPECT_EQ(getLabel(label_->getLabels(), 130), "spoonbill");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 131), 131);
  EXPECT_EQ(getLabel(label_->getLabels(), 131), "flamingo");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 132), 132);
  EXPECT_EQ(getLabel(label_->getLabels(), 132),
            "little blue heron, Egretta caerulea");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 133), 133);
  EXPECT_EQ(getLabel(label_->getLabels(), 133),
            "American egret, great white heron, Egretta albus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 134), 134);
  EXPECT_EQ(getLabel(label_->getLabels(), 134), "bittern");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 135), 135);
  EXPECT_EQ(getLabel(label_->getLabels(), 135), "crane");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 136), 136);
  EXPECT_EQ(getLabel(label_->getLabels(), 136), "limpkin, Aramus pictus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 137), 137);
  EXPECT_EQ(getLabel(label_->getLabels(), 137),
            "European gallinule, Porphyrio porphyrio");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 138), 138);
  EXPECT_EQ(getLabel(label_->getLabels(), 138),
            "American coot, marsh hen, mud hen, water hen, Fulica americana");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 139), 139);
  EXPECT_EQ(getLabel(label_->getLabels(), 139), "bustard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 140), 140);
  EXPECT_EQ(getLabel(label_->getLabels(), 140),
            "ruddy turnstone, Arenaria interpres");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 141), 141);
  EXPECT_EQ(getLabel(label_->getLabels(), 141),
            "red-backed sandpiper, dunlin, Erolia alpina");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 142), 142);
  EXPECT_EQ(getLabel(label_->getLabels(), 142), "redshank, Tringa totanus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 143), 143);
  EXPECT_EQ(getLabel(label_->getLabels(), 143), "dowitcher");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 144), 144);
  EXPECT_EQ(getLabel(label_->getLabels(), 144),
            "oystercatcher, oyster catcher");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 145), 145);
  EXPECT_EQ(getLabel(label_->getLabels(), 145), "pelican");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 146), 146);
  EXPECT_EQ(getLabel(label_->getLabels(), 146),
            "king penguin, Aptenodytes patagonica");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 147), 147);
  EXPECT_EQ(getLabel(label_->getLabels(), 147), "albatross, mollymawk");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 148), 148);
  EXPECT_EQ(getLabel(label_->getLabels(), 148),
            "grey whale, gray whale, devilfish, Eschrichtius gibbosus, "
            "Eschrichtius robustus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 149), 149);
  EXPECT_EQ(getLabel(label_->getLabels(), 149),
            "killer whale, killer, orca, grampus, sea wolf, Orcinus orca");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 150), 150);
  EXPECT_EQ(getLabel(label_->getLabels(), 150), "dugong, Dugong dugon");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 151), 151);
  EXPECT_EQ(getLabel(label_->getLabels(), 151), "sea lion");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 152), 152);
  EXPECT_EQ(getLabel(label_->getLabels(), 152), "Chihuahua");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 153), 153);
  EXPECT_EQ(getLabel(label_->getLabels(), 153), "Japanese spaniel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 154), 154);
  EXPECT_EQ(getLabel(label_->getLabels(), 154),
            "Maltese dog, Maltese terrier, Maltese");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 155), 155);
  EXPECT_EQ(getLabel(label_->getLabels(), 155), "Pekinese, Pekingese, Peke");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 156), 156);
  EXPECT_EQ(getLabel(label_->getLabels(), 156), "Shih-Tzu");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 157), 157);
  EXPECT_EQ(getLabel(label_->getLabels(), 157), "Blenheim spaniel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 158), 158);
  EXPECT_EQ(getLabel(label_->getLabels(), 158), "papillon");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 159), 159);
  EXPECT_EQ(getLabel(label_->getLabels(), 159), "toy terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 160), 160);
  EXPECT_EQ(getLabel(label_->getLabels(), 160), "Rhodesian ridgeback");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 161), 161);
  EXPECT_EQ(getLabel(label_->getLabels(), 161), "Afghan hound, Afghan");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 162), 162);
  EXPECT_EQ(getLabel(label_->getLabels(), 162), "basset, basset hound");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 163), 163);
  EXPECT_EQ(getLabel(label_->getLabels(), 163), "beagle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 164), 164);
  EXPECT_EQ(getLabel(label_->getLabels(), 164), "bloodhound, sleuthhound");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 165), 165);
  EXPECT_EQ(getLabel(label_->getLabels(), 165), "bluetick");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 166), 166);
  EXPECT_EQ(getLabel(label_->getLabels(), 166), "black-and-tan coonhound");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 167), 167);
  EXPECT_EQ(getLabel(label_->getLabels(), 167),
            "Walker hound, Walker foxhound");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 168), 168);
  EXPECT_EQ(getLabel(label_->getLabels(), 168), "English foxhound");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 169), 169);
  EXPECT_EQ(getLabel(label_->getLabels(), 169), "redbone");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 170), 170);
  EXPECT_EQ(getLabel(label_->getLabels(), 170), "borzoi, Russian wolfhound");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 171), 171);
  EXPECT_EQ(getLabel(label_->getLabels(), 171), "Irish wolfhound");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 172), 172);
  EXPECT_EQ(getLabel(label_->getLabels(), 172), "Italian greyhound");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 173), 173);
  EXPECT_EQ(getLabel(label_->getLabels(), 173), "whippet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 174), 174);
  EXPECT_EQ(getLabel(label_->getLabels(), 174), "Ibizan hound, Ibizan Podenco");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 175), 175);
  EXPECT_EQ(getLabel(label_->getLabels(), 175), "Norwegian elkhound, elkhound");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 176), 176);
  EXPECT_EQ(getLabel(label_->getLabels(), 176), "otterhound, otter hound");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 177), 177);
  EXPECT_EQ(getLabel(label_->getLabels(), 177), "Saluki, gazelle hound");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 178), 178);
  EXPECT_EQ(getLabel(label_->getLabels(), 178),
            "Scottish deerhound, deerhound");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 179), 179);
  EXPECT_EQ(getLabel(label_->getLabels(), 179), "Weimaraner");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 180), 180);
  EXPECT_EQ(getLabel(label_->getLabels(), 180),
            "Staffordshire bullterrier, Staffordshire bull terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 181), 181);
  EXPECT_EQ(getLabel(label_->getLabels(), 181),
            "American Staffordshire terrier, Staffordshire terrier, American "
            "pit bull terrier, pit bull terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 182), 182);
  EXPECT_EQ(getLabel(label_->getLabels(), 182), "Bedlington terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 183), 183);
  EXPECT_EQ(getLabel(label_->getLabels(), 183), "Border terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 184), 184);
  EXPECT_EQ(getLabel(label_->getLabels(), 184), "Kerry blue terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 185), 185);
  EXPECT_EQ(getLabel(label_->getLabels(), 185), "Irish terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 186), 186);
  EXPECT_EQ(getLabel(label_->getLabels(), 186), "Norfolk terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 187), 187);
  EXPECT_EQ(getLabel(label_->getLabels(), 187), "Norwich terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 188), 188);
  EXPECT_EQ(getLabel(label_->getLabels(), 188), "Yorkshire terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 189), 189);
  EXPECT_EQ(getLabel(label_->getLabels(), 189), "wire-haired fox terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 190), 190);
  EXPECT_EQ(getLabel(label_->getLabels(), 190), "Lakeland terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 191), 191);
  EXPECT_EQ(getLabel(label_->getLabels(), 191), "Sealyham terrier, Sealyham");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 192), 192);
  EXPECT_EQ(getLabel(label_->getLabels(), 192), "Airedale, Airedale terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 193), 193);
  EXPECT_EQ(getLabel(label_->getLabels(), 193), "cairn, cairn terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 194), 194);
  EXPECT_EQ(getLabel(label_->getLabels(), 194), "Australian terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 195), 195);
  EXPECT_EQ(getLabel(label_->getLabels(), 195),
            "Dandie Dinmont, Dandie Dinmont terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 196), 196);
  EXPECT_EQ(getLabel(label_->getLabels(), 196), "Boston bull, Boston terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 197), 197);
  EXPECT_EQ(getLabel(label_->getLabels(), 197), "miniature schnauzer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 198), 198);
  EXPECT_EQ(getLabel(label_->getLabels(), 198), "giant schnauzer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 199), 199);
  EXPECT_EQ(getLabel(label_->getLabels(), 199), "standard schnauzer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 200), 200);
  EXPECT_EQ(getLabel(label_->getLabels(), 200),
            "Scotch terrier, Scottish terrier, Scottie");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 201), 201);
  EXPECT_EQ(getLabel(label_->getLabels(), 201),
            "Tibetan terrier, chrysanthemum dog");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 202), 202);
  EXPECT_EQ(getLabel(label_->getLabels(), 202), "silky terrier, Sydney silky");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 203), 203);
  EXPECT_EQ(getLabel(label_->getLabels(), 203), "soft-coated wheaten terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 204), 204);
  EXPECT_EQ(getLabel(label_->getLabels(), 204), "West Highland white terrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 205), 205);
  EXPECT_EQ(getLabel(label_->getLabels(), 205), "Lhasa, Lhasa apso");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 206), 206);
  EXPECT_EQ(getLabel(label_->getLabels(), 206), "flat-coated retriever");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 207), 207);
  EXPECT_EQ(getLabel(label_->getLabels(), 207), "curly-coated retriever");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 208), 208);
  EXPECT_EQ(getLabel(label_->getLabels(), 208), "golden retriever");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 209), 209);
  EXPECT_EQ(getLabel(label_->getLabels(), 209), "Labrador retriever");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 210), 210);
  EXPECT_EQ(getLabel(label_->getLabels(), 210), "Chesapeake Bay retriever");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 211), 211);
  EXPECT_EQ(getLabel(label_->getLabels(), 211), "German short-haired pointer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 212), 212);
  EXPECT_EQ(getLabel(label_->getLabels(), 212), "vizsla, Hungarian pointer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 213), 213);
  EXPECT_EQ(getLabel(label_->getLabels(), 213), "English setter");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 214), 214);
  EXPECT_EQ(getLabel(label_->getLabels(), 214), "Irish setter, red setter");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 215), 215);
  EXPECT_EQ(getLabel(label_->getLabels(), 215), "Gordon setter");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 216), 216);
  EXPECT_EQ(getLabel(label_->getLabels(), 216), "Brittany spaniel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 217), 217);
  EXPECT_EQ(getLabel(label_->getLabels(), 217), "clumber, clumber spaniel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 218), 218);
  EXPECT_EQ(getLabel(label_->getLabels(), 218),
            "English springer, English springer spaniel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 219), 219);
  EXPECT_EQ(getLabel(label_->getLabels(), 219), "Welsh springer spaniel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 220), 220);
  EXPECT_EQ(getLabel(label_->getLabels(), 220),
            "cocker spaniel, English cocker spaniel, cocker");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 221), 221);
  EXPECT_EQ(getLabel(label_->getLabels(), 221), "Sussex spaniel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 222), 222);
  EXPECT_EQ(getLabel(label_->getLabels(), 222), "Irish water spaniel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 223), 223);
  EXPECT_EQ(getLabel(label_->getLabels(), 223), "kuvasz");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 224), 224);
  EXPECT_EQ(getLabel(label_->getLabels(), 224), "schipperke");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 225), 225);
  EXPECT_EQ(getLabel(label_->getLabels(), 225), "groenendael");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 226), 226);
  EXPECT_EQ(getLabel(label_->getLabels(), 226), "malinois");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 227), 227);
  EXPECT_EQ(getLabel(label_->getLabels(), 227), "briard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 228), 228);
  EXPECT_EQ(getLabel(label_->getLabels(), 228), "kelpie");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 229), 229);
  EXPECT_EQ(getLabel(label_->getLabels(), 229), "komondor");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 230), 230);
  EXPECT_EQ(getLabel(label_->getLabels(), 230),
            "Old English sheepdog, bobtail");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 231), 231);
  EXPECT_EQ(getLabel(label_->getLabels(), 231),
            "Shetland sheepdog, Shetland sheep dog, Shetland");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 232), 232);
  EXPECT_EQ(getLabel(label_->getLabels(), 232), "collie");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 233), 233);
  EXPECT_EQ(getLabel(label_->getLabels(), 233), "Border collie");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 234), 234);
  EXPECT_EQ(getLabel(label_->getLabels(), 234),
            "Bouvier des Flandres, Bouviers des Flandres");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 235), 235);
  EXPECT_EQ(getLabel(label_->getLabels(), 235), "Rottweiler");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 236), 236);
  EXPECT_EQ(getLabel(label_->getLabels(), 236),
            "German shepherd, German shepherd dog, German police dog, "
            "alsatian");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 237), 237);
  EXPECT_EQ(getLabel(label_->getLabels(), 237), "Doberman, Doberman pinscher");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 238), 238);
  EXPECT_EQ(getLabel(label_->getLabels(), 238), "miniature pinscher");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 239), 239);
  EXPECT_EQ(getLabel(label_->getLabels(), 239), "Greater Swiss Mountain dog");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 240), 240);
  EXPECT_EQ(getLabel(label_->getLabels(), 240), "Bernese mountain dog");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 241), 241);
  EXPECT_EQ(getLabel(label_->getLabels(), 241), "Appenzeller");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 242), 242);
  EXPECT_EQ(getLabel(label_->getLabels(), 242), "EntleBucher");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 243), 243);
  EXPECT_EQ(getLabel(label_->getLabels(), 243), "boxer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 244), 244);
  EXPECT_EQ(getLabel(label_->getLabels(), 244), "bull mastiff");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 245), 245);
  EXPECT_EQ(getLabel(label_->getLabels(), 245), "Tibetan mastiff");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 246), 246);
  EXPECT_EQ(getLabel(label_->getLabels(), 246), "French bulldog");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 247), 247);
  EXPECT_EQ(getLabel(label_->getLabels(), 247), "Great Dane");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 248), 248);
  EXPECT_EQ(getLabel(label_->getLabels(), 248), "Saint Bernard, St Bernard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 249), 249);
  EXPECT_EQ(getLabel(label_->getLabels(), 249), "Eskimo dog, husky");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 250), 250);
  EXPECT_EQ(getLabel(label_->getLabels(), 250),
            "malamute, malemute, Alaskan malamute");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 251), 251);
  EXPECT_EQ(getLabel(label_->getLabels(), 251), "Siberian husky");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 252), 252);
  EXPECT_EQ(getLabel(label_->getLabels(), 252),
            "dalmatian, coach dog, carriage dog");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 253), 253);
  EXPECT_EQ(getLabel(label_->getLabels(), 253),
            "affenpinscher, monkey pinscher, monkey dog");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 254), 254);
  EXPECT_EQ(getLabel(label_->getLabels(), 254), "basenji");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 255), 255);
  EXPECT_EQ(getLabel(label_->getLabels(), 255), "pug, pug-dog");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 256), 256);
  EXPECT_EQ(getLabel(label_->getLabels(), 256), "Leonberg");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 257), 257);
  EXPECT_EQ(getLabel(label_->getLabels(), 257),
            "Newfoundland, Newfoundland dog");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 258), 258);
  EXPECT_EQ(getLabel(label_->getLabels(), 258), "Great Pyrenees");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 259), 259);
  EXPECT_EQ(getLabel(label_->getLabels(), 259), "Samoyed, Samoyede");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 260), 260);
  EXPECT_EQ(getLabel(label_->getLabels(), 260), "Pomeranian");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 261), 261);
  EXPECT_EQ(getLabel(label_->getLabels(), 261), "chow, chow chow");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 262), 262);
  EXPECT_EQ(getLabel(label_->getLabels(), 262), "keeshond");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 263), 263);
  EXPECT_EQ(getLabel(label_->getLabels(), 263), "Brabancon griffon");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 264), 264);
  EXPECT_EQ(getLabel(label_->getLabels(), 264),
            "Pembroke, Pembroke Welsh corgi");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 265), 265);
  EXPECT_EQ(getLabel(label_->getLabels(), 265),
            "Cardigan, Cardigan Welsh corgi");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 266), 266);
  EXPECT_EQ(getLabel(label_->getLabels(), 266), "toy poodle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 267), 267);
  EXPECT_EQ(getLabel(label_->getLabels(), 267), "miniature poodle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 268), 268);
  EXPECT_EQ(getLabel(label_->getLabels(), 268), "standard poodle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 269), 269);
  EXPECT_EQ(getLabel(label_->getLabels(), 269), "Mexican hairless");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 270), 270);
  EXPECT_EQ(getLabel(label_->getLabels(), 270),
            "timber wolf, grey wolf, gray wolf, Canis lupus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 271), 271);
  EXPECT_EQ(getLabel(label_->getLabels(), 271),
            "white wolf, Arctic wolf, Canis lupus tundrarum");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 272), 272);
  EXPECT_EQ(getLabel(label_->getLabels(), 272),
            "red wolf, maned wolf, Canis rufus, Canis niger");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 273), 273);
  EXPECT_EQ(getLabel(label_->getLabels(), 273),
            "coyote, prairie wolf, brush wolf, Canis latrans");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 274), 274);
  EXPECT_EQ(getLabel(label_->getLabels(), 274),
            "dingo, warrigal, warragal, Canis dingo");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 275), 275);
  EXPECT_EQ(getLabel(label_->getLabels(), 275), "dhole, Cuon alpinus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 276), 276);
  EXPECT_EQ(getLabel(label_->getLabels(), 276),
            "African hunting dog, hyena dog, Cape hunting dog, Lycaon pictus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 277), 277);
  EXPECT_EQ(getLabel(label_->getLabels(), 277), "hyena, hyaena");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 278), 278);
  EXPECT_EQ(getLabel(label_->getLabels(), 278), "red fox, Vulpes vulpes");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 279), 279);
  EXPECT_EQ(getLabel(label_->getLabels(), 279), "kit fox, Vulpes macrotis");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 280), 280);
  EXPECT_EQ(getLabel(label_->getLabels(), 280),
            "Arctic fox, white fox, Alopex lagopus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 281), 281);
  EXPECT_EQ(getLabel(label_->getLabels(), 281),
            "grey fox, gray fox, Urocyon cinereoargenteus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 282), 282);
  EXPECT_EQ(getLabel(label_->getLabels(), 282), "tabby, tabby cat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 283), 283);
  EXPECT_EQ(getLabel(label_->getLabels(), 283), "tiger cat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 284), 284);
  EXPECT_EQ(getLabel(label_->getLabels(), 284), "Persian cat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 285), 285);
  EXPECT_EQ(getLabel(label_->getLabels(), 285), "Siamese cat, Siamese");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 286), 286);
  EXPECT_EQ(getLabel(label_->getLabels(), 286), "Egyptian cat");

  EXPECT_EQ(getIndexLabel(label_->getLabels(), 287), 287);
  EXPECT_EQ(getLabel(label_->getLabels(), 287),
            "cougar, puma, catamount, mountain lion, painter, panther, Felis "
            "concolor");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 288), 288);
  EXPECT_EQ(getLabel(label_->getLabels(), 288), "lynx, catamount");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 289), 289);
  EXPECT_EQ(getLabel(label_->getLabels(), 289), "leopard, Panthera pardus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 290), 290);
  EXPECT_EQ(getLabel(label_->getLabels(), 290),
            "snow leopard, ounce, Panthera uncia");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 291), 291);
  EXPECT_EQ(getLabel(label_->getLabels(), 291),
            "jaguar, panther, Panthera onca, Felis onca");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 292), 292);
  EXPECT_EQ(getLabel(label_->getLabels(), 292),
            "lion, king of beasts, Panthera leo");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 293), 293);
  EXPECT_EQ(getLabel(label_->getLabels(), 293), "tiger, Panthera tigris");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 294), 294);
  EXPECT_EQ(getLabel(label_->getLabels(), 294),
            "cheetah, chetah, Acinonyx jubatus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 295), 295);
  EXPECT_EQ(getLabel(label_->getLabels(), 295),
            "brown bear, bruin, Ursus arctos");

  EXPECT_EQ(getIndexLabel(label_->getLabels(), 296), 296);
  EXPECT_EQ(getLabel(label_->getLabels(), 296),
            "American black bear, black bear, Ursus americanus, "
            "Euarctos americanus");

  EXPECT_EQ(getIndexLabel(label_->getLabels(), 297), 297);
  EXPECT_EQ(getLabel(label_->getLabels(), 297),
            "ice bear, polar bear, Ursus Maritimus, Thalarctos "
            "maritimus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 298), 298);
  EXPECT_EQ(getLabel(label_->getLabels(), 298),
            "sloth bear, Melursus ursinus, Ursus ursinus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 299), 299);
  EXPECT_EQ(getLabel(label_->getLabels(), 299), "mongoose");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 300), 300);
  EXPECT_EQ(getLabel(label_->getLabels(), 300), "meerkat, mierkat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 301), 301);
  EXPECT_EQ(getLabel(label_->getLabels(), 301), "tiger beetle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 302), 302);
  EXPECT_EQ(getLabel(label_->getLabels(), 302),
            "ladybug, ladybeetle, lady beetle, ladybird, ladybird "
            "beetle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 303), 303);
  EXPECT_EQ(getLabel(label_->getLabels(), 303),
            "ground beetle, carabid beetle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 304), 304);
  EXPECT_EQ(getLabel(label_->getLabels(), 304),
            "long-horned beetle, longicorn, longicorn beetle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 305), 305);
  EXPECT_EQ(getLabel(label_->getLabels(), 305), "leaf beetle, chrysomelid");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 306), 306);
  EXPECT_EQ(getLabel(label_->getLabels(), 306), "dung beetle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 307), 307);
  EXPECT_EQ(getLabel(label_->getLabels(), 307), "rhinoceros beetle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 308), 308);
  EXPECT_EQ(getLabel(label_->getLabels(), 308), "weevil");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 309), 309);
  EXPECT_EQ(getLabel(label_->getLabels(), 309), "fly");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 310), 310);
  EXPECT_EQ(getLabel(label_->getLabels(), 310), "bee");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 311), 311);
  EXPECT_EQ(getLabel(label_->getLabels(), 311), "ant, emmet, pismire");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 312), 312);
  EXPECT_EQ(getLabel(label_->getLabels(), 312), "grasshopper, hopper");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 313), 313);
  EXPECT_EQ(getLabel(label_->getLabels(), 313), "cricket");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 314), 314);
  EXPECT_EQ(getLabel(label_->getLabels(), 314),
            "walking stick, walkingstick, stick insect");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 315), 315);
  EXPECT_EQ(getLabel(label_->getLabels(), 315), "cockroach, roach");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 316), 316);
  EXPECT_EQ(getLabel(label_->getLabels(), 316), "mantis, mantid");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 317), 317);
  EXPECT_EQ(getLabel(label_->getLabels(), 317), "cicada, cicala");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 318), 318);
  EXPECT_EQ(getLabel(label_->getLabels(), 318), "leafhopper");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 319), 319);
  EXPECT_EQ(getLabel(label_->getLabels(), 319), "lacewing, lacewing fly");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 320), 320);
  EXPECT_EQ(getLabel(label_->getLabels(), 320),
            "dragonfly, darning needle, devil's darning needle, sewing "
            "needle, "
            "snake feeder, snake doctor, mosquito hawk, skeeter hawk");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 321), 321);
  EXPECT_EQ(getLabel(label_->getLabels(), 321), "damselfly");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 322), 322);
  EXPECT_EQ(getLabel(label_->getLabels(), 322), "admiral");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 323), 323);
  EXPECT_EQ(getLabel(label_->getLabels(), 323), "ringlet, ringlet butterfly");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 324), 324);
  EXPECT_EQ(getLabel(label_->getLabels(), 324),
            "monarch, monarch butterfly, milkweed butterfly, "
            "Danaus plexippus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 325), 325);
  EXPECT_EQ(getLabel(label_->getLabels(), 325), "cabbage butterfly");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 326), 326);
  EXPECT_EQ(getLabel(label_->getLabels(), 326),
            "sulphur butterfly, sulfur butterfly");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 327), 327);
  EXPECT_EQ(getLabel(label_->getLabels(), 327), "lycaenid, lycaenid butterfly");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 328), 328);
  EXPECT_EQ(getLabel(label_->getLabels(), 328), "starfish, sea star");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 329), 329);
  EXPECT_EQ(getLabel(label_->getLabels(), 329), "sea urchin");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 330), 330);
  EXPECT_EQ(getLabel(label_->getLabels(), 330), "sea cucumber, holothurian");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 331), 331);
  EXPECT_EQ(getLabel(label_->getLabels(), 331),
            "wood rabbit, cottontail, cottontail rabbit");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 332), 332);
  EXPECT_EQ(getLabel(label_->getLabels(), 332), "hare");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 333), 333);
  EXPECT_EQ(getLabel(label_->getLabels(), 333), "Angora, Angora rabbit");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 334), 334);
  EXPECT_EQ(getLabel(label_->getLabels(), 334), "hamster");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 335), 335);
  EXPECT_EQ(getLabel(label_->getLabels(), 335), "porcupine, hedgehog");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 336), 336);
  EXPECT_EQ(getLabel(label_->getLabels(), 336),
            "fox squirrel, eastern fox squirrel, Sciurus niger");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 337), 337);
  EXPECT_EQ(getLabel(label_->getLabels(), 337), "marmot");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 338), 338);
  EXPECT_EQ(getLabel(label_->getLabels(), 338), "beaver");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 339), 339);
  EXPECT_EQ(getLabel(label_->getLabels(), 339), "guinea pig, Cavia cobaya");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 340), 340);
  EXPECT_EQ(getLabel(label_->getLabels(), 340), "sorrel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 341), 341);
  EXPECT_EQ(getLabel(label_->getLabels(), 341), "zebra");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 342), 342);
  EXPECT_EQ(getLabel(label_->getLabels(), 342),
            "hog, pig, grunter, squealer, Sus scrofa");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 343), 343);
  EXPECT_EQ(getLabel(label_->getLabels(), 343), "wild boar, boar, Sus scrofa");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 344), 344);
  EXPECT_EQ(getLabel(label_->getLabels(), 344), "warthog");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 345), 345);
  EXPECT_EQ(getLabel(label_->getLabels(), 345),
            "hippopotamus, hippo, river horse, Hippopotamus amphibius");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 346), 346);
  EXPECT_EQ(getLabel(label_->getLabels(), 346), "ox");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 347), 347);
  EXPECT_EQ(getLabel(label_->getLabels(), 347),
            "water buffalo, water ox, Asiatic buffalo, Bubalus bubalis");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 348), 348);
  EXPECT_EQ(getLabel(label_->getLabels(), 348), "bison");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 349), 349);
  EXPECT_EQ(getLabel(label_->getLabels(), 349), "ram, tup");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 350), 350);
  EXPECT_EQ(getLabel(label_->getLabels(), 350),
            "bighorn, bighorn sheep, cimarron, Rocky Mountain "
            "bighorn, Rocky "
            "Mountain sheep, Ovis canadensis");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 351), 351);
  EXPECT_EQ(getLabel(label_->getLabels(), 351), "ibex, Capra ibex");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 352), 352);
  EXPECT_EQ(getLabel(label_->getLabels(), 352), "hartebeest");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 353), 353);
  EXPECT_EQ(getLabel(label_->getLabels(), 353), "impala, Aepyceros melampus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 354), 354);
  EXPECT_EQ(getLabel(label_->getLabels(), 354), "gazelle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 355), 355);
  EXPECT_EQ(getLabel(label_->getLabels(), 355),
            "Arabian camel, dromedary, Camelus dromedarius");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 356), 356);
  EXPECT_EQ(getLabel(label_->getLabels(), 356), "llama");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 357), 357);
  EXPECT_EQ(getLabel(label_->getLabels(), 357), "weasel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 358), 358);
  EXPECT_EQ(getLabel(label_->getLabels(), 358), "mink");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 359), 359);
  EXPECT_EQ(getLabel(label_->getLabels(), 359),
            "polecat, fitch, foulmart, foumart, Mustela putorius");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 360), 360);
  EXPECT_EQ(getLabel(label_->getLabels(), 360),
            "black-footed ferret, ferret, Mustela nigripes");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 361), 361);
  EXPECT_EQ(getLabel(label_->getLabels(), 361), "otter");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 362), 362);
  EXPECT_EQ(getLabel(label_->getLabels(), 362), "skunk, polecat, wood pussy");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 363), 363);
  EXPECT_EQ(getLabel(label_->getLabels(), 363), "badger");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 364), 364);
  EXPECT_EQ(getLabel(label_->getLabels(), 364), "armadillo");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 365), 365);
  EXPECT_EQ(getLabel(label_->getLabels(), 365),
            "three-toed sloth, ai, Bradypus tridactylus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 366), 366);
  EXPECT_EQ(getLabel(label_->getLabels(), 366),
            "orangutan, orang, orangutang, Pongo pygmaeus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 367), 367);
  EXPECT_EQ(getLabel(label_->getLabels(), 367), "gorilla, Gorilla gorilla");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 368), 368);
  EXPECT_EQ(getLabel(label_->getLabels(), 368),
            "chimpanzee, chimp, Pan troglodytes");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 369), 369);
  EXPECT_EQ(getLabel(label_->getLabels(), 369), "gibbon, Hylobates lar");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 370), 370);
  EXPECT_EQ(getLabel(label_->getLabels(), 370),
            "siamang, Hylobates syndactylus, Symphalangus syndactylus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 371), 371);
  EXPECT_EQ(getLabel(label_->getLabels(), 371), "guenon, guenon monkey");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 372), 372);
  EXPECT_EQ(getLabel(label_->getLabels(), 372),
            "patas, hussar monkey, Erythrocebus patas");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 373), 373);
  EXPECT_EQ(getLabel(label_->getLabels(), 373), "baboon");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 374), 374);
  EXPECT_EQ(getLabel(label_->getLabels(), 374), "macaque");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 375), 375);
  EXPECT_EQ(getLabel(label_->getLabels(), 375), "langur");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 376), 376);
  EXPECT_EQ(getLabel(label_->getLabels(), 376), "colobus, colobus monkey");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 377), 377);
  EXPECT_EQ(getLabel(label_->getLabels(), 377),
            "proboscis monkey, Nasalis larvatus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 378), 378);
  EXPECT_EQ(getLabel(label_->getLabels(), 378), "marmoset");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 379), 379);
  EXPECT_EQ(getLabel(label_->getLabels(), 379),
            "capuchin, ringtail, Cebus capucinus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 380), 380);
  EXPECT_EQ(getLabel(label_->getLabels(), 380), "howler monkey, howler");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 381), 381);
  EXPECT_EQ(getLabel(label_->getLabels(), 381), "titi, titi monkey");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 382), 382);
  EXPECT_EQ(getLabel(label_->getLabels(), 382),
            "spider monkey, Ateles geoffroyi");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 383), 383);
  EXPECT_EQ(getLabel(label_->getLabels(), 383),
            "squirrel monkey, Saimiri sciureus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 384), 384);
  EXPECT_EQ(getLabel(label_->getLabels(), 384),
            "Madagascar cat, ring-tailed lemur, Lemur catta");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 385), 385);
  EXPECT_EQ(getLabel(label_->getLabels(), 385),
            "indri, indris, Indri indri, Indri brevicaudatus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 386), 386);
  EXPECT_EQ(getLabel(label_->getLabels(), 386),
            "Indian elephant, Elephas maximus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 387), 387);
  EXPECT_EQ(getLabel(label_->getLabels(), 387),
            "African elephant, Loxodonta africana");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 388), 388);
  EXPECT_EQ(getLabel(label_->getLabels(), 388),
            "lesser panda, red panda, panda, bear cat, cat bear, "
            "Ailurus fulgens");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 389), 389);
  EXPECT_EQ(getLabel(label_->getLabels(), 389),
            "giant panda, panda, panda bear, coon bear, Ailuropoda "
            "melanoleuca");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 390), 390);
  EXPECT_EQ(getLabel(label_->getLabels(), 390), "barracouta, snoek");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 391), 391);
  EXPECT_EQ(getLabel(label_->getLabels(), 391), "eel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 392), 392);
  EXPECT_EQ(getLabel(label_->getLabels(), 392),
            "coho, cohoe, coho salmon, blue jack, silver salmon, "
            "Oncorhynchus "
            "kisutch");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 393), 393);
  EXPECT_EQ(getLabel(label_->getLabels(), 393),
            "rock beauty, Holocanthus tricolor");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 394), 394);
  EXPECT_EQ(getLabel(label_->getLabels(), 394), "anemone fish");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 395), 395);
  EXPECT_EQ(getLabel(label_->getLabels(), 395), "sturgeon");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 396), 396);
  EXPECT_EQ(getLabel(label_->getLabels(), 396),
            "gar, garfish, garpike, billfish, Lepisosteus osseus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 397), 397);
  EXPECT_EQ(getLabel(label_->getLabels(), 397), "lionfish");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 398), 398);
  EXPECT_EQ(getLabel(label_->getLabels(), 398),
            "puffer, pufferfish, blowfish, globefish");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 399), 399);
  EXPECT_EQ(getLabel(label_->getLabels(), 399), "abacus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 400), 400);
  EXPECT_EQ(getLabel(label_->getLabels(), 400), "abaya");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 401), 401);
  EXPECT_EQ(getLabel(label_->getLabels(), 401),
            "academic gown, academic robe, judge's robe");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 402), 402);
  EXPECT_EQ(getLabel(label_->getLabels(), 402),
            "accordion, piano accordion, squeeze box");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 403), 403);
  EXPECT_EQ(getLabel(label_->getLabels(), 403), "acoustic guitar");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 404), 404);
  EXPECT_EQ(getLabel(label_->getLabels(), 404),
            "aircraft carrier, carrier, flattop, attack aircraft "
            "carrier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 405), 405);
  EXPECT_EQ(getLabel(label_->getLabels(), 405), "airliner");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 406), 406);
  EXPECT_EQ(getLabel(label_->getLabels(), 406), "airship, dirigible");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 407), 407);
  EXPECT_EQ(getLabel(label_->getLabels(), 407), "altar");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 408), 408);
  EXPECT_EQ(getLabel(label_->getLabels(), 408), "ambulance");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 409), 409);
  EXPECT_EQ(getLabel(label_->getLabels(), 409),
            "amphibian, amphibious vehicle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 410), 410);
  EXPECT_EQ(getLabel(label_->getLabels(), 410), "analog clock");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 411), 411);
  EXPECT_EQ(getLabel(label_->getLabels(), 411), "apiary, bee house");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 412), 412);
  EXPECT_EQ(getLabel(label_->getLabels(), 412), "apron");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 413), 413);
  EXPECT_EQ(getLabel(label_->getLabels(), 413),
            "ashcan, trash can, garbage can, wastebin, ash bin, ash-bin, "
            "ashbin, dustbin, trash barrel, trash bin");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 414), 414);
  EXPECT_EQ(getLabel(label_->getLabels(), 414), "assault rifle, assault gun");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 415), 415);
  EXPECT_EQ(getLabel(label_->getLabels(), 415),
            "backpack, back pack, knapsack, packsack, rucksack, "
            "haversack");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 416), 416);
  EXPECT_EQ(getLabel(label_->getLabels(), 416), "bakery, bakeshop, bakehouse");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 417), 417);
  EXPECT_EQ(getLabel(label_->getLabels(), 417), "balance beam, beam");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 418), 418);
  EXPECT_EQ(getLabel(label_->getLabels(), 418), "balloon");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 419), 419);
  EXPECT_EQ(getLabel(label_->getLabels(), 419),
            "ballpoint, ballpoint pen, ballpen, Biro");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 420), 420);
  EXPECT_EQ(getLabel(label_->getLabels(), 420), "Band Aid");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 421), 421);
  EXPECT_EQ(getLabel(label_->getLabels(), 421), "banjo");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 422), 422);
  EXPECT_EQ(getLabel(label_->getLabels(), 422),
            "bannister, banister, balustrade, balusters, handrail");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 423), 423);
  EXPECT_EQ(getLabel(label_->getLabels(), 423), "barbell");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 424), 424);
  EXPECT_EQ(getLabel(label_->getLabels(), 424), "barber chair");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 425), 425);
  EXPECT_EQ(getLabel(label_->getLabels(), 425), "barbershop");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 426), 426);
  EXPECT_EQ(getLabel(label_->getLabels(), 426), "barn");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 427), 427);
  EXPECT_EQ(getLabel(label_->getLabels(), 427), "barometer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 428), 428);
  EXPECT_EQ(getLabel(label_->getLabels(), 428), "barrel, cask");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 429), 429);
  EXPECT_EQ(getLabel(label_->getLabels(), 429),
            "barrow, garden cart, lawn cart, wheelbarrow");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 430), 430);
  EXPECT_EQ(getLabel(label_->getLabels(), 430), "baseball");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 431), 431);
  EXPECT_EQ(getLabel(label_->getLabels(), 431), "basketball");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 432), 432);
  EXPECT_EQ(getLabel(label_->getLabels(), 432), "bassinet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 433), 433);
  EXPECT_EQ(getLabel(label_->getLabels(), 433), "bassoon");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 434), 434);
  EXPECT_EQ(getLabel(label_->getLabels(), 434), "bathing cap, swimming cap");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 435), 435);
  EXPECT_EQ(getLabel(label_->getLabels(), 435), "bath towel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 436), 436);
  EXPECT_EQ(getLabel(label_->getLabels(), 436),
            "bathtub, bathing tub, bath, tub");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 437), 437);
  EXPECT_EQ(getLabel(label_->getLabels(), 437),
            "beach wagon, station wagon, wagon, estate car, beach "
            "waggon, "
            "station waggon, waggon");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 438), 438);
  EXPECT_EQ(getLabel(label_->getLabels(), 438),
            "beacon, lighthouse, beacon light, pharos");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 439), 439);
  EXPECT_EQ(getLabel(label_->getLabels(), 439), "beaker");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 440), 440);
  EXPECT_EQ(getLabel(label_->getLabels(), 440), "bearskin, busby, shako");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 441), 441);
  EXPECT_EQ(getLabel(label_->getLabels(), 441), "beer bottle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 442), 442);
  EXPECT_EQ(getLabel(label_->getLabels(), 442), "beer glass");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 443), 443);
  EXPECT_EQ(getLabel(label_->getLabels(), 443), "bell cote, bell cot");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 444), 444);
  EXPECT_EQ(getLabel(label_->getLabels(), 444), "bib");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 445), 445);
  EXPECT_EQ(getLabel(label_->getLabels(), 445),
            "bicycle-built-for-two, tandem bicycle, tandem");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 446), 446);
  EXPECT_EQ(getLabel(label_->getLabels(), 446), "bikini, two-piece");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 447), 447);
  EXPECT_EQ(getLabel(label_->getLabels(), 447), "binder, ring-binder");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 448), 448);
  EXPECT_EQ(getLabel(label_->getLabels(), 448),
            "binoculars, field glasses, opera glasses");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 449), 449);
  EXPECT_EQ(getLabel(label_->getLabels(), 449), "birdhouse");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 450), 450);
  EXPECT_EQ(getLabel(label_->getLabels(), 450), "boathouse");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 451), 451);
  EXPECT_EQ(getLabel(label_->getLabels(), 451), "bobsled, bobsleigh, bob");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 452), 452);
  EXPECT_EQ(getLabel(label_->getLabels(), 452),
            "bolo tie, bolo, bola tie, bola");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 453), 453);
  EXPECT_EQ(getLabel(label_->getLabels(), 453), "bonnet, poke bonnet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 454), 454);
  EXPECT_EQ(getLabel(label_->getLabels(), 454), "bookcase");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 455), 455);
  EXPECT_EQ(getLabel(label_->getLabels(), 455),
            "bookshop, bookstore, bookstall");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 456), 456);
  EXPECT_EQ(getLabel(label_->getLabels(), 456), "bottlecap");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 457), 457);
  EXPECT_EQ(getLabel(label_->getLabels(), 457), "bow");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 458), 458);
  EXPECT_EQ(getLabel(label_->getLabels(), 458), "bow tie, bow-tie, bowtie");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 459), 459);
  EXPECT_EQ(getLabel(label_->getLabels(), 459),
            "brass, memorial tablet, plaque");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 460), 460);
  EXPECT_EQ(getLabel(label_->getLabels(), 460), "brassiere, bra, bandeau");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 461), 461);
  EXPECT_EQ(getLabel(label_->getLabels(), 461),
            "breakwater, groin, groyne, mole, bulwark, seawall, jetty");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 462), 462);
  EXPECT_EQ(getLabel(label_->getLabels(), 462), "breastplate, aegis, egis");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 463), 463);
  EXPECT_EQ(getLabel(label_->getLabels(), 463), "broom");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 464), 464);
  EXPECT_EQ(getLabel(label_->getLabels(), 464), "bucket, pail");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 465), 465);
  EXPECT_EQ(getLabel(label_->getLabels(), 465), "buckle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 466), 466);
  EXPECT_EQ(getLabel(label_->getLabels(), 466), "bulletproof vest");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 467), 467);
  EXPECT_EQ(getLabel(label_->getLabels(), 467), "bullet train, bullet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 468), 468);
  EXPECT_EQ(getLabel(label_->getLabels(), 468), "butcher shop, meat market");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 469), 469);
  EXPECT_EQ(getLabel(label_->getLabels(), 469), "cab, hack, taxi, taxicab");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 470), 470);
  EXPECT_EQ(getLabel(label_->getLabels(), 470), "caldron, cauldron");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 471), 471);
  EXPECT_EQ(getLabel(label_->getLabels(), 471), "candle, taper, wax light");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 472), 472);
  EXPECT_EQ(getLabel(label_->getLabels(), 472), "cannon");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 473), 473);
  EXPECT_EQ(getLabel(label_->getLabels(), 473), "canoe");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 474), 474);
  EXPECT_EQ(getLabel(label_->getLabels(), 474), "can opener, tin opener");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 475), 475);
  EXPECT_EQ(getLabel(label_->getLabels(), 475), "cardigan");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 476), 476);
  EXPECT_EQ(getLabel(label_->getLabels(), 476), "car mirror");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 477), 477);
  EXPECT_EQ(getLabel(label_->getLabels(), 477),
            "carousel, carrousel, merry-go-round, roundabout, whirligig");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 478), 478);
  EXPECT_EQ(getLabel(label_->getLabels(), 478), "carpenter's kit, tool kit");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 479), 479);
  EXPECT_EQ(getLabel(label_->getLabels(), 479), "carton");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 480), 480);
  EXPECT_EQ(getLabel(label_->getLabels(), 480), "car wheel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 481), 481);
  EXPECT_EQ(getLabel(label_->getLabels(), 481),
            "cash machine, cash dispenser, automated teller machine, "
            "automatic "
            "teller machine, automated teller, automatic teller, ATM");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 482), 482);
  EXPECT_EQ(getLabel(label_->getLabels(), 482), "cassette");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 483), 483);
  EXPECT_EQ(getLabel(label_->getLabels(), 483), "cassette player");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 484), 484);
  EXPECT_EQ(getLabel(label_->getLabels(), 484), "castle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 485), 485);
  EXPECT_EQ(getLabel(label_->getLabels(), 485), "catamaran");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 486), 486);
  EXPECT_EQ(getLabel(label_->getLabels(), 486), "CD player");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 487), 487);
  EXPECT_EQ(getLabel(label_->getLabels(), 487), "cello, violoncello");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 488), 488);
  EXPECT_EQ(getLabel(label_->getLabels(), 488),
            "cellular telephone, cellular phone, cellphone, "
            "cell, mobile phone");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 489), 489);
  EXPECT_EQ(getLabel(label_->getLabels(), 489), "chain");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 490), 490);
  EXPECT_EQ(getLabel(label_->getLabels(), 490), "chainlink fence");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 491), 491);
  EXPECT_EQ(getLabel(label_->getLabels(), 491),
            "chain mail, ring mail, mail, chain armor, chain "
            "armour, ring "
            "armor, ring armour");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 492), 492);
  EXPECT_EQ(getLabel(label_->getLabels(), 492), "chain saw, chainsaw");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 493), 493);
  EXPECT_EQ(getLabel(label_->getLabels(), 493), "chest");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 494), 494);
  EXPECT_EQ(getLabel(label_->getLabels(), 494), "chiffonier, commode");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 495), 495);
  EXPECT_EQ(getLabel(label_->getLabels(), 495), "chime, bell, gong");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 496), 496);
  EXPECT_EQ(getLabel(label_->getLabels(), 496), "china cabinet, china closet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 497), 497);
  EXPECT_EQ(getLabel(label_->getLabels(), 497), "Christmas stocking");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 498), 498);
  EXPECT_EQ(getLabel(label_->getLabels(), 498), "church, church building");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 499), 499);
  EXPECT_EQ(getLabel(label_->getLabels(), 499),
            "cinema, movie theater, movie theatre, movie house, "
            "picture palace");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 500), 500);
  EXPECT_EQ(getLabel(label_->getLabels(), 500),
            "cleaver, meat cleaver, chopper");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 501), 501);
  EXPECT_EQ(getLabel(label_->getLabels(), 501), "cliff dwelling");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 502), 502);
  EXPECT_EQ(getLabel(label_->getLabels(), 502), "cloak");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 503), 503);
  EXPECT_EQ(getLabel(label_->getLabels(), 503), "clog, geta, patten, sabot");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 504), 504);
  EXPECT_EQ(getLabel(label_->getLabels(), 504), "cocktail shaker");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 505), 505);
  EXPECT_EQ(getLabel(label_->getLabels(), 505), "coffee mug");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 506), 506);
  EXPECT_EQ(getLabel(label_->getLabels(), 506), "coffeepot");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 507), 507);
  EXPECT_EQ(getLabel(label_->getLabels(), 507),
            "coil, spiral, volute, whorl, helix");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 508), 508);
  EXPECT_EQ(getLabel(label_->getLabels(), 508), "combination lock");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 509), 509);
  EXPECT_EQ(getLabel(label_->getLabels(), 509), "computer keyboard, keypad");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 510), 510);
  EXPECT_EQ(getLabel(label_->getLabels(), 510),
            "confectionery, confectionary, candy store");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 511), 511);
  EXPECT_EQ(getLabel(label_->getLabels(), 511),
            "container ship, containership, container vessel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 512), 512);
  EXPECT_EQ(getLabel(label_->getLabels(), 512), "convertible");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 513), 513);
  EXPECT_EQ(getLabel(label_->getLabels(), 513), "corkscrew, bottle screw");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 514), 514);
  EXPECT_EQ(getLabel(label_->getLabels(), 514), "cornet, horn, trumpet, trump");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 515), 515);
  EXPECT_EQ(getLabel(label_->getLabels(), 515), "cowboy boot");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 516), 516);
  EXPECT_EQ(getLabel(label_->getLabels(), 516), "cowboy hat, ten-gallon hat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 517), 517);
  EXPECT_EQ(getLabel(label_->getLabels(), 517), "cradle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 518), 518);
  EXPECT_EQ(getLabel(label_->getLabels(), 518), "crane");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 519), 519);
  EXPECT_EQ(getLabel(label_->getLabels(), 519), "crash helmet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 520), 520);
  EXPECT_EQ(getLabel(label_->getLabels(), 520), "crate");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 521), 521);
  EXPECT_EQ(getLabel(label_->getLabels(), 521), "crib, cot");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 522), 522);
  EXPECT_EQ(getLabel(label_->getLabels(), 522), "Crock Pot");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 523), 523);
  EXPECT_EQ(getLabel(label_->getLabels(), 523), "croquet ball");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 524), 524);
  EXPECT_EQ(getLabel(label_->getLabels(), 524), "crutch");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 525), 525);
  EXPECT_EQ(getLabel(label_->getLabels(), 525), "cuirass");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 526), 526);
  EXPECT_EQ(getLabel(label_->getLabels(), 526), "dam, dike, dyke");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 527), 527);
  EXPECT_EQ(getLabel(label_->getLabels(), 527), "desk");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 528), 528);
  EXPECT_EQ(getLabel(label_->getLabels(), 528), "desktop computer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 529), 529);
  EXPECT_EQ(getLabel(label_->getLabels(), 529), "dial telephone, dial phone");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 530), 530);
  EXPECT_EQ(getLabel(label_->getLabels(), 530), "diaper, nappy, napkin");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 531), 531);
  EXPECT_EQ(getLabel(label_->getLabels(), 531), "digital clock");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 532), 532);
  EXPECT_EQ(getLabel(label_->getLabels(), 532), "digital watch");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 533), 533);
  EXPECT_EQ(getLabel(label_->getLabels(), 533), "dining table, board");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 534), 534);
  EXPECT_EQ(getLabel(label_->getLabels(), 534), "dishrag, dishcloth");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 535), 535);
  EXPECT_EQ(getLabel(label_->getLabels(), 535),
            "dishwasher, dish washer, dishwashing machine");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 536), 536);
  EXPECT_EQ(getLabel(label_->getLabels(), 536), "disk brake, disc brake");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 537), 537);
  EXPECT_EQ(getLabel(label_->getLabels(), 537),
            "dock, dockage, docking facility");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 538), 538);
  EXPECT_EQ(getLabel(label_->getLabels(), 538),
            "dogsled, dog sled, dog sleigh");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 539), 539);
  EXPECT_EQ(getLabel(label_->getLabels(), 539), "dome");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 540), 540);
  EXPECT_EQ(getLabel(label_->getLabels(), 540), "doormat, welcome mat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 541), 541);
  EXPECT_EQ(getLabel(label_->getLabels(), 541),
            "drilling platform, offshore rig");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 542), 542);
  EXPECT_EQ(getLabel(label_->getLabels(), 542), "drum, membranophone, tympan");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 543), 543);
  EXPECT_EQ(getLabel(label_->getLabels(), 543), "drumstick");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 544), 544);
  EXPECT_EQ(getLabel(label_->getLabels(), 544), "dumbbell");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 545), 545);
  EXPECT_EQ(getLabel(label_->getLabels(), 545), "Dutch oven");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 546), 546);
  EXPECT_EQ(getLabel(label_->getLabels(), 546), "electric fan, blower");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 547), 547);
  EXPECT_EQ(getLabel(label_->getLabels(), 547), "electric guitar");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 548), 548);
  EXPECT_EQ(getLabel(label_->getLabels(), 548), "electric locomotive");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 549), 549);
  EXPECT_EQ(getLabel(label_->getLabels(), 549), "entertainment center");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 550), 550);
  EXPECT_EQ(getLabel(label_->getLabels(), 550), "envelope");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 551), 551);
  EXPECT_EQ(getLabel(label_->getLabels(), 551), "espresso maker");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 552), 552);
  EXPECT_EQ(getLabel(label_->getLabels(), 552), "face powder");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 553), 553);
  EXPECT_EQ(getLabel(label_->getLabels(), 553), "feather boa, boa");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 554), 554);
  EXPECT_EQ(getLabel(label_->getLabels(), 554),
            "file, file cabinet, filing cabinet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 555), 555);
  EXPECT_EQ(getLabel(label_->getLabels(), 555), "fireboat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 556), 556);
  EXPECT_EQ(getLabel(label_->getLabels(), 556), "fire engine, fire truck");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 557), 557);
  EXPECT_EQ(getLabel(label_->getLabels(), 557), "fire screen, fireguard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 558), 558);
  EXPECT_EQ(getLabel(label_->getLabels(), 558), "flagpole, flagstaff");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 559), 559);
  EXPECT_EQ(getLabel(label_->getLabels(), 559), "flute, transverse flute");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 560), 560);
  EXPECT_EQ(getLabel(label_->getLabels(), 560), "folding chair");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 561), 561);
  EXPECT_EQ(getLabel(label_->getLabels(), 561), "football helmet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 562), 562);
  EXPECT_EQ(getLabel(label_->getLabels(), 562), "forklift");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 563), 563);
  EXPECT_EQ(getLabel(label_->getLabels(), 563), "fountain");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 564), 564);
  EXPECT_EQ(getLabel(label_->getLabels(), 564), "fountain pen");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 565), 565);
  EXPECT_EQ(getLabel(label_->getLabels(), 565), "four-poster");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 566), 566);
  EXPECT_EQ(getLabel(label_->getLabels(), 566), "freight car");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 567), 567);
  EXPECT_EQ(getLabel(label_->getLabels(), 567), "French horn, horn");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 568), 568);
  EXPECT_EQ(getLabel(label_->getLabels(), 568), "frying pan, frypan, skillet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 569), 569);
  EXPECT_EQ(getLabel(label_->getLabels(), 569), "fur coat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 570), 570);
  EXPECT_EQ(getLabel(label_->getLabels(), 570), "garbage truck, dustcart");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 571), 571);
  EXPECT_EQ(getLabel(label_->getLabels(), 571),
            "gasmask, respirator, gas helmet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 572), 572);
  EXPECT_EQ(getLabel(label_->getLabels(), 572),
            "gas pump, gasoline pump, petrol pump, island dispenser");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 573), 573);
  EXPECT_EQ(getLabel(label_->getLabels(), 573), "goblet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 574), 574);
  EXPECT_EQ(getLabel(label_->getLabels(), 574), "go-kart");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 575), 575);
  EXPECT_EQ(getLabel(label_->getLabels(), 575), "golf ball");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 576), 576);
  EXPECT_EQ(getLabel(label_->getLabels(), 576), "golfcart, golf cart");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 577), 577);
  EXPECT_EQ(getLabel(label_->getLabels(), 577), "gondola");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 578), 578);
  EXPECT_EQ(getLabel(label_->getLabels(), 578), "gong, tam-tam");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 579), 579);
  EXPECT_EQ(getLabel(label_->getLabels(), 579), "gown");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 580), 580);
  EXPECT_EQ(getLabel(label_->getLabels(), 580), "grand piano, grand");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 581), 581);
  EXPECT_EQ(getLabel(label_->getLabels(), 581),
            "greenhouse, nursery, glasshouse");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 582), 582);
  EXPECT_EQ(getLabel(label_->getLabels(), 582), "grille, radiator grille");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 583), 583);
  EXPECT_EQ(getLabel(label_->getLabels(), 583),
            "grocery store, grocery, food market, market");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 584), 584);
  EXPECT_EQ(getLabel(label_->getLabels(), 584), "guillotine");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 585), 585);
  EXPECT_EQ(getLabel(label_->getLabels(), 585), "hair slide");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 586), 586);
  EXPECT_EQ(getLabel(label_->getLabels(), 586), "hair spray");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 587), 587);
  EXPECT_EQ(getLabel(label_->getLabels(), 587), "half track");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 588), 588);
  EXPECT_EQ(getLabel(label_->getLabels(), 588), "hammer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 589), 589);
  EXPECT_EQ(getLabel(label_->getLabels(), 589), "hamper");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 590), 590);
  EXPECT_EQ(getLabel(label_->getLabels(), 590),
            "hand blower, blow dryer, blow drier, hair dryer, "
            "hair drier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 591), 591);
  EXPECT_EQ(getLabel(label_->getLabels(), 591),
            "hand-held computer, hand-held microcomputer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 592), 592);
  EXPECT_EQ(getLabel(label_->getLabels(), 592),
            "handkerchief, hankie, hanky, hankey");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 593), 593);
  EXPECT_EQ(getLabel(label_->getLabels(), 593),
            "hard disc, hard disk, fixed disk");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 594), 594);
  EXPECT_EQ(getLabel(label_->getLabels(), 594),
            "harmonica, mouth organ, harp, mouth harp");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 595), 595);
  EXPECT_EQ(getLabel(label_->getLabels(), 595), "harp");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 596), 596);
  EXPECT_EQ(getLabel(label_->getLabels(), 596), "harvester, reaper");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 597), 597);
  EXPECT_EQ(getLabel(label_->getLabels(), 597), "hatchet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 598), 598);
  EXPECT_EQ(getLabel(label_->getLabels(), 598), "holster");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 599), 599);
  EXPECT_EQ(getLabel(label_->getLabels(), 599), "home theater, home theatre");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 600), 600);
  EXPECT_EQ(getLabel(label_->getLabels(), 600), "honeycomb");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 601), 601);
  EXPECT_EQ(getLabel(label_->getLabels(), 601), "hook, claw");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 602), 602);
  EXPECT_EQ(getLabel(label_->getLabels(), 602), "hoopskirt, crinoline");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 603), 603);
  EXPECT_EQ(getLabel(label_->getLabels(), 603), "horizontal bar, high bar");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 604), 604);
  EXPECT_EQ(getLabel(label_->getLabels(), 604), "horse cart, horse-cart");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 605), 605);
  EXPECT_EQ(getLabel(label_->getLabels(), 605), "hourglass");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 606), 606);
  EXPECT_EQ(getLabel(label_->getLabels(), 606), "iPod");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 607), 607);
  EXPECT_EQ(getLabel(label_->getLabels(), 607), "iron, smoothing iron");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 608), 608);
  EXPECT_EQ(getLabel(label_->getLabels(), 608), "jack-o'-lantern");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 609), 609);
  EXPECT_EQ(getLabel(label_->getLabels(), 609), "jean, blue jean, denim");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 610), 610);
  EXPECT_EQ(getLabel(label_->getLabels(), 610), "jeep, landrover");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 611), 611);
  EXPECT_EQ(getLabel(label_->getLabels(), 611), "jersey, T-shirt, tee shirt");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 612), 612);
  EXPECT_EQ(getLabel(label_->getLabels(), 612), "jigsaw puzzle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 613), 613);
  EXPECT_EQ(getLabel(label_->getLabels(), 613),
            "jinrikisha, ricksha, rickshaw");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 614), 614);
  EXPECT_EQ(getLabel(label_->getLabels(), 614), "joystick");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 615), 615);
  EXPECT_EQ(getLabel(label_->getLabels(), 615), "kimono");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 616), 616);
  EXPECT_EQ(getLabel(label_->getLabels(), 616), "knee pad");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 617), 617);
  EXPECT_EQ(getLabel(label_->getLabels(), 617), "knot");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 618), 618);
  EXPECT_EQ(getLabel(label_->getLabels(), 618), "lab coat, laboratory coat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 619), 619);
  EXPECT_EQ(getLabel(label_->getLabels(), 619), "ladle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 620), 620);
  EXPECT_EQ(getLabel(label_->getLabels(), 620), "lampshade, lamp shade");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 621), 621);
  EXPECT_EQ(getLabel(label_->getLabels(), 621), "laptop, laptop computer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 622), 622);
  EXPECT_EQ(getLabel(label_->getLabels(), 622), "lawn mower, mower");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 623), 623);
  EXPECT_EQ(getLabel(label_->getLabels(), 623), "lens cap, lens cover");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 624), 624);
  EXPECT_EQ(getLabel(label_->getLabels(), 624),
            "letter opener, paper knife, paperknife");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 625), 625);
  EXPECT_EQ(getLabel(label_->getLabels(), 625), "library");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 626), 626);
  EXPECT_EQ(getLabel(label_->getLabels(), 626), "lifeboat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 627), 627);
  EXPECT_EQ(getLabel(label_->getLabels(), 627),
            "lighter, light, igniter, ignitor");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 628), 628);
  EXPECT_EQ(getLabel(label_->getLabels(), 628), "limousine, limo");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 629), 629);
  EXPECT_EQ(getLabel(label_->getLabels(), 629), "liner, ocean liner");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 630), 630);
  EXPECT_EQ(getLabel(label_->getLabels(), 630), "lipstick, lip rouge");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 631), 631);
  EXPECT_EQ(getLabel(label_->getLabels(), 631), "Loafer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 632), 632);
  EXPECT_EQ(getLabel(label_->getLabels(), 632), "lotion");

  EXPECT_EQ(getIndexLabel(label_->getLabels(), 633), 633);
  EXPECT_EQ(getLabel(label_->getLabels(), 633),
            "loudspeaker, speaker, speaker unit, loudspeaker "
            "system, speaker system");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 634), 634);
  EXPECT_EQ(getLabel(label_->getLabels(), 634), "loupe, jeweler's loupe");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 635), 635);
  EXPECT_EQ(getLabel(label_->getLabels(), 635), "lumbermill, sawmill");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 636), 636);
  EXPECT_EQ(getLabel(label_->getLabels(), 636), "magnetic compass");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 637), 637);
  EXPECT_EQ(getLabel(label_->getLabels(), 637), "mailbag, postbag");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 638), 638);
  EXPECT_EQ(getLabel(label_->getLabels(), 638), "mailbox, letter box");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 639), 639);
  EXPECT_EQ(getLabel(label_->getLabels(), 639), "maillot");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 640), 640);
  EXPECT_EQ(getLabel(label_->getLabels(), 640), "maillot, tank suit");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 641), 641);
  EXPECT_EQ(getLabel(label_->getLabels(), 641), "manhole cover");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 642), 642);
  EXPECT_EQ(getLabel(label_->getLabels(), 642), "maraca");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 643), 643);
  EXPECT_EQ(getLabel(label_->getLabels(), 643), "marimba, xylophone");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 644), 644);
  EXPECT_EQ(getLabel(label_->getLabels(), 644), "mask");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 645), 645);
  EXPECT_EQ(getLabel(label_->getLabels(), 645), "matchstick");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 646), 646);
  EXPECT_EQ(getLabel(label_->getLabels(), 646), "maypole");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 647), 647);
  EXPECT_EQ(getLabel(label_->getLabels(), 647), "maze, labyrinth");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 648), 648);
  EXPECT_EQ(getLabel(label_->getLabels(), 648), "measuring cup");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 649), 649);
  EXPECT_EQ(getLabel(label_->getLabels(), 649),
            "medicine chest, medicine cabinet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 650), 650);
  EXPECT_EQ(getLabel(label_->getLabels(), 650),
            "megalith, megalithic structure");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 651), 651);
  EXPECT_EQ(getLabel(label_->getLabels(), 651), "microphone, mike");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 652), 652);
  EXPECT_EQ(getLabel(label_->getLabels(), 652), "microwave, microwave oven");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 653), 653);
  EXPECT_EQ(getLabel(label_->getLabels(), 653), "military uniform");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 654), 654);
  EXPECT_EQ(getLabel(label_->getLabels(), 654), "milk can");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 655), 655);
  EXPECT_EQ(getLabel(label_->getLabels(), 655), "minibus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 656), 656);
  EXPECT_EQ(getLabel(label_->getLabels(), 656), "miniskirt, mini");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 657), 657);
  EXPECT_EQ(getLabel(label_->getLabels(), 657), "minivan");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 658), 658);
  EXPECT_EQ(getLabel(label_->getLabels(), 658), "missile");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 659), 659);
  EXPECT_EQ(getLabel(label_->getLabels(), 659), "mitten");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 660), 660);
  EXPECT_EQ(getLabel(label_->getLabels(), 660), "mixing bowl");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 661), 661);
  EXPECT_EQ(getLabel(label_->getLabels(), 661),
            "mobile home, manufactured home");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 662), 662);
  EXPECT_EQ(getLabel(label_->getLabels(), 662), "Model T");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 663), 663);
  EXPECT_EQ(getLabel(label_->getLabels(), 663), "modem");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 664), 664);
  EXPECT_EQ(getLabel(label_->getLabels(), 664), "monastery");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 665), 665);
  EXPECT_EQ(getLabel(label_->getLabels(), 665), "monitor");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 666), 666);
  EXPECT_EQ(getLabel(label_->getLabels(), 666), "moped");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 667), 667);
  EXPECT_EQ(getLabel(label_->getLabels(), 667), "mortar");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 668), 668);
  EXPECT_EQ(getLabel(label_->getLabels(), 668), "mortarboard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 669), 669);
  EXPECT_EQ(getLabel(label_->getLabels(), 669), "mosque");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 670), 670);
  EXPECT_EQ(getLabel(label_->getLabels(), 670), "mosquito net");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 671), 671);
  EXPECT_EQ(getLabel(label_->getLabels(), 671), "motor scooter, scooter");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 672), 672);
  EXPECT_EQ(getLabel(label_->getLabels(), 672),
            "mountain bike, all-terrain bike, off-roader");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 673), 673);
  EXPECT_EQ(getLabel(label_->getLabels(), 673), "mountain tent");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 674), 674);
  EXPECT_EQ(getLabel(label_->getLabels(), 674), "mouse, computer mouse");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 675), 675);
  EXPECT_EQ(getLabel(label_->getLabels(), 675), "mousetrap");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 676), 676);
  EXPECT_EQ(getLabel(label_->getLabels(), 676), "moving van");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 677), 677);
  EXPECT_EQ(getLabel(label_->getLabels(), 677), "muzzle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 678), 678);
  EXPECT_EQ(getLabel(label_->getLabels(), 678), "nail");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 679), 679);
  EXPECT_EQ(getLabel(label_->getLabels(), 679), "neck brace");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 680), 680);
  EXPECT_EQ(getLabel(label_->getLabels(), 680), "necklace");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 681), 681);
  EXPECT_EQ(getLabel(label_->getLabels(), 681), "nipple");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 682), 682);
  EXPECT_EQ(getLabel(label_->getLabels(), 682), "notebook, notebook computer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 683), 683);
  EXPECT_EQ(getLabel(label_->getLabels(), 683), "obelisk");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 684), 684);
  EXPECT_EQ(getLabel(label_->getLabels(), 684), "oboe, hautboy, hautbois");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 685), 685);
  EXPECT_EQ(getLabel(label_->getLabels(), 685), "ocarina, sweet potato");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 686), 686);
  EXPECT_EQ(getLabel(label_->getLabels(), 686),
            "odometer, hodometer, mileometer, milometer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 687), 687);
  EXPECT_EQ(getLabel(label_->getLabels(), 687), "oil filter");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 688), 688);
  EXPECT_EQ(getLabel(label_->getLabels(), 688), "organ, pipe organ");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 689), 689);
  EXPECT_EQ(getLabel(label_->getLabels(), 689),
            "oscilloscope, scope, cathode-ray oscilloscope, CRO");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 690), 690);
  EXPECT_EQ(getLabel(label_->getLabels(), 690), "overskirt");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 691), 691);
  EXPECT_EQ(getLabel(label_->getLabels(), 691), "oxcart");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 692), 692);
  EXPECT_EQ(getLabel(label_->getLabels(), 692), "oxygen mask");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 693), 693);
  EXPECT_EQ(getLabel(label_->getLabels(), 693), "packet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 694), 694);
  EXPECT_EQ(getLabel(label_->getLabels(), 694), "paddle, boat paddle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 695), 695);
  EXPECT_EQ(getLabel(label_->getLabels(), 695), "paddlewheel, paddle wheel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 696), 696);
  EXPECT_EQ(getLabel(label_->getLabels(), 696), "padlock");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 697), 697);
  EXPECT_EQ(getLabel(label_->getLabels(), 697), "paintbrush");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 698), 698);
  EXPECT_EQ(getLabel(label_->getLabels(), 698),
            "pajama, pyjama, pj's, jammies");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 699), 699);
  EXPECT_EQ(getLabel(label_->getLabels(), 699), "palace");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 700), 700);
  EXPECT_EQ(getLabel(label_->getLabels(), 700),
            "panpipe, pandean pipe, syrinx");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 701), 701);
  EXPECT_EQ(getLabel(label_->getLabels(), 701), "paper towel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 702), 702);
  EXPECT_EQ(getLabel(label_->getLabels(), 702), "parachute, chute");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 703), 703);
  EXPECT_EQ(getLabel(label_->getLabels(), 703), "parallel bars, bars");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 704), 704);
  EXPECT_EQ(getLabel(label_->getLabels(), 704), "park bench");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 705), 705);
  EXPECT_EQ(getLabel(label_->getLabels(), 705), "parking meter");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 706), 706);
  EXPECT_EQ(getLabel(label_->getLabels(), 706),
            "passenger car, coach, carriage");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 707), 707);
  EXPECT_EQ(getLabel(label_->getLabels(), 707), "patio, terrace");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 708), 708);
  EXPECT_EQ(getLabel(label_->getLabels(), 708), "pay-phone, pay-station");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 709), 709);
  EXPECT_EQ(getLabel(label_->getLabels(), 709), "pedestal, plinth, footstall");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 710), 710);
  EXPECT_EQ(getLabel(label_->getLabels(), 710), "pencil box, pencil case");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 711), 711);
  EXPECT_EQ(getLabel(label_->getLabels(), 711), "pencil sharpener");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 712), 712);
  EXPECT_EQ(getLabel(label_->getLabels(), 712), "perfume, essence");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 713), 713);
  EXPECT_EQ(getLabel(label_->getLabels(), 713), "Petri dish");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 714), 714);
  EXPECT_EQ(getLabel(label_->getLabels(), 714), "photocopier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 715), 715);
  EXPECT_EQ(getLabel(label_->getLabels(), 715), "pick, plectrum, plectron");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 716), 716);
  EXPECT_EQ(getLabel(label_->getLabels(), 716), "pickelhaube");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 717), 717);
  EXPECT_EQ(getLabel(label_->getLabels(), 717), "picket fence, paling");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 718), 718);
  EXPECT_EQ(getLabel(label_->getLabels(), 718), "pickup, pickup truck");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 719), 719);
  EXPECT_EQ(getLabel(label_->getLabels(), 719), "pier");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 720), 720);
  EXPECT_EQ(getLabel(label_->getLabels(), 720), "piggy bank, penny bank");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 721), 721);
  EXPECT_EQ(getLabel(label_->getLabels(), 721), "pill bottle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 722), 722);
  EXPECT_EQ(getLabel(label_->getLabels(), 722), "pillow");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 723), 723);
  EXPECT_EQ(getLabel(label_->getLabels(), 723), "ping-pong ball");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 724), 724);
  EXPECT_EQ(getLabel(label_->getLabels(), 724), "pinwheel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 725), 725);
  EXPECT_EQ(getLabel(label_->getLabels(), 725), "pirate, pirate ship");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 726), 726);
  EXPECT_EQ(getLabel(label_->getLabels(), 726), "pitcher, ewer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 727), 727);
  EXPECT_EQ(getLabel(label_->getLabels(), 727),
            "plane, carpenter's plane, woodworking plane");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 728), 728);
  EXPECT_EQ(getLabel(label_->getLabels(), 728), "planetarium");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 729), 729);
  EXPECT_EQ(getLabel(label_->getLabels(), 729), "plastic bag");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 730), 730);
  EXPECT_EQ(getLabel(label_->getLabels(), 730), "plate rack");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 731), 731);
  EXPECT_EQ(getLabel(label_->getLabels(), 731), "plow, plough");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 732), 732);
  EXPECT_EQ(getLabel(label_->getLabels(), 732), "plunger, plumber's helper");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 733), 733);
  EXPECT_EQ(getLabel(label_->getLabels(), 733),
            "Polaroid camera, Polaroid Land camera");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 734), 734);
  EXPECT_EQ(getLabel(label_->getLabels(), 734), "pole");

  EXPECT_EQ(getIndexLabel(label_->getLabels(), 735), 735);
  EXPECT_EQ(getLabel(label_->getLabels(), 735),
            "police van, police wagon, paddy wagon, patrol "
            "wagon, wagon, black "
            "Maria");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 736), 736);
  EXPECT_EQ(getLabel(label_->getLabels(), 736), "poncho");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 737), 737);
  EXPECT_EQ(getLabel(label_->getLabels(), 737),
            "pool table, billiard table, snooker table");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 738), 738);
  EXPECT_EQ(getLabel(label_->getLabels(), 738), "pop bottle, soda bottle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 739), 739);
  EXPECT_EQ(getLabel(label_->getLabels(), 739), "pot, flowerpot");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 740), 740);
  EXPECT_EQ(getLabel(label_->getLabels(), 740), "potter's wheel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 741), 741);
  EXPECT_EQ(getLabel(label_->getLabels(), 741), "power drill");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 742), 742);
  EXPECT_EQ(getLabel(label_->getLabels(), 742), "prayer rug, prayer mat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 743), 743);
  EXPECT_EQ(getLabel(label_->getLabels(), 743), "printer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 744), 744);
  EXPECT_EQ(getLabel(label_->getLabels(), 744), "prison, prison house");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 745), 745);
  EXPECT_EQ(getLabel(label_->getLabels(), 745), "projectile, missile");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 746), 746);
  EXPECT_EQ(getLabel(label_->getLabels(), 746), "projector");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 747), 747);
  EXPECT_EQ(getLabel(label_->getLabels(), 747), "puck, hockey puck");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 748), 748);
  EXPECT_EQ(getLabel(label_->getLabels(), 748),
            "punching bag, punch bag, punching ball, punchball");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 749), 749);
  EXPECT_EQ(getLabel(label_->getLabels(), 749), "purse");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 750), 750);
  EXPECT_EQ(getLabel(label_->getLabels(), 750), "quill, quill pen");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 751), 751);
  EXPECT_EQ(getLabel(label_->getLabels(), 751),
            "quilt, comforter, comfort, puff");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 752), 752);
  EXPECT_EQ(getLabel(label_->getLabels(), 752), "racer, race car, racing car");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 753), 753);
  EXPECT_EQ(getLabel(label_->getLabels(), 753), "racket, racquet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 754), 754);
  EXPECT_EQ(getLabel(label_->getLabels(), 754), "radiator");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 755), 755);
  EXPECT_EQ(getLabel(label_->getLabels(), 755), "radio, wireless");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 756), 756);
  EXPECT_EQ(getLabel(label_->getLabels(), 756),
            "radio telescope, radio reflector");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 757), 757);
  EXPECT_EQ(getLabel(label_->getLabels(), 757), "rain barrel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 758), 758);
  EXPECT_EQ(getLabel(label_->getLabels(), 758),
            "recreational vehicle, RV, R.V.");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 759), 759);
  EXPECT_EQ(getLabel(label_->getLabels(), 759), "reel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 760), 760);
  EXPECT_EQ(getLabel(label_->getLabels(), 760), "reflex camera");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 761), 761);
  EXPECT_EQ(getLabel(label_->getLabels(), 761), "refrigerator, icebox");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 762), 762);
  EXPECT_EQ(getLabel(label_->getLabels(), 762), "remote control, remote");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 763), 763);
  EXPECT_EQ(getLabel(label_->getLabels(), 763),
            "restaurant, eating house, eating place, eatery");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 764), 764);
  EXPECT_EQ(getLabel(label_->getLabels(), 764),
            "revolver, six-gun, six-shooter");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 765), 765);
  EXPECT_EQ(getLabel(label_->getLabels(), 765), "rifle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 766), 766);
  EXPECT_EQ(getLabel(label_->getLabels(), 766), "rocking chair, rocker");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 767), 767);
  EXPECT_EQ(getLabel(label_->getLabels(), 767), "rotisserie");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 768), 768);
  EXPECT_EQ(getLabel(label_->getLabels(), 768),
            "rubber eraser, rubber, pencil eraser");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 769), 769);
  EXPECT_EQ(getLabel(label_->getLabels(), 769), "rugby ball");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 770), 770);
  EXPECT_EQ(getLabel(label_->getLabels(), 770), "rule, ruler");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 771), 771);
  EXPECT_EQ(getLabel(label_->getLabels(), 771), "running shoe");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 772), 772);
  EXPECT_EQ(getLabel(label_->getLabels(), 772), "safe");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 773), 773);
  EXPECT_EQ(getLabel(label_->getLabels(), 773), "safety pin");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 774), 774);
  EXPECT_EQ(getLabel(label_->getLabels(), 774), "saltshaker, salt shaker");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 775), 775);
  EXPECT_EQ(getLabel(label_->getLabels(), 775), "sandal");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 776), 776);
  EXPECT_EQ(getLabel(label_->getLabels(), 776), "sarong");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 777), 777);
  EXPECT_EQ(getLabel(label_->getLabels(), 777), "sax, saxophone");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 778), 778);
  EXPECT_EQ(getLabel(label_->getLabels(), 778), "scabbard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 779), 779);
  EXPECT_EQ(getLabel(label_->getLabels(), 779), "scale, weighing machine");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 780), 780);
  EXPECT_EQ(getLabel(label_->getLabels(), 780), "school bus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 781), 781);
  EXPECT_EQ(getLabel(label_->getLabels(), 781), "schooner");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 782), 782);
  EXPECT_EQ(getLabel(label_->getLabels(), 782), "scoreboard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 783), 783);
  EXPECT_EQ(getLabel(label_->getLabels(), 783), "screen, CRT screen");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 784), 784);
  EXPECT_EQ(getLabel(label_->getLabels(), 784), "screw");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 785), 785);
  EXPECT_EQ(getLabel(label_->getLabels(), 785), "screwdriver");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 786), 786);
  EXPECT_EQ(getLabel(label_->getLabels(), 786), "seat belt, seatbelt");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 787), 787);
  EXPECT_EQ(getLabel(label_->getLabels(), 787), "sewing machine");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 788), 788);
  EXPECT_EQ(getLabel(label_->getLabels(), 788), "shield, buckler");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 789), 789);
  EXPECT_EQ(getLabel(label_->getLabels(), 789),
            "shoe shop, shoe-shop, shoe store");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 790), 790);
  EXPECT_EQ(getLabel(label_->getLabels(), 790), "shoji");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 791), 791);
  EXPECT_EQ(getLabel(label_->getLabels(), 791), "shopping basket");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 792), 792);
  EXPECT_EQ(getLabel(label_->getLabels(), 792), "shopping cart");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 793), 793);
  EXPECT_EQ(getLabel(label_->getLabels(), 793), "shovel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 794), 794);
  EXPECT_EQ(getLabel(label_->getLabels(), 794), "shower cap");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 795), 795);
  EXPECT_EQ(getLabel(label_->getLabels(), 795), "shower curtain");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 796), 796);
  EXPECT_EQ(getLabel(label_->getLabels(), 796), "ski");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 797), 797);
  EXPECT_EQ(getLabel(label_->getLabels(), 797), "ski mask");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 798), 798);
  EXPECT_EQ(getLabel(label_->getLabels(), 798), "sleeping bag");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 799), 799);
  EXPECT_EQ(getLabel(label_->getLabels(), 799), "slide rule, slipstick");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 800), 800);
  EXPECT_EQ(getLabel(label_->getLabels(), 800), "sliding door");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 801), 801);
  EXPECT_EQ(getLabel(label_->getLabels(), 801), "slot, one-armed bandit");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 802), 802);
  EXPECT_EQ(getLabel(label_->getLabels(), 802), "snorkel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 803), 803);
  EXPECT_EQ(getLabel(label_->getLabels(), 803), "snowmobile");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 804), 804);
  EXPECT_EQ(getLabel(label_->getLabels(), 804), "snowplow, snowplough");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 805), 805);
  EXPECT_EQ(getLabel(label_->getLabels(), 805), "soap dispenser");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 806), 806);
  EXPECT_EQ(getLabel(label_->getLabels(), 806), "soccer ball");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 807), 807);
  EXPECT_EQ(getLabel(label_->getLabels(), 807), "sock");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 808), 808);
  EXPECT_EQ(getLabel(label_->getLabels(), 808),
            "solar dish, solar collector, solar furnace");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 809), 809);
  EXPECT_EQ(getLabel(label_->getLabels(), 809), "sombrero");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 810), 810);
  EXPECT_EQ(getLabel(label_->getLabels(), 810), "soup bowl");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 811), 811);
  EXPECT_EQ(getLabel(label_->getLabels(), 811), "space bar");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 812), 812);
  EXPECT_EQ(getLabel(label_->getLabels(), 812), "space heater");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 813), 813);
  EXPECT_EQ(getLabel(label_->getLabels(), 813), "space shuttle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 814), 814);
  EXPECT_EQ(getLabel(label_->getLabels(), 814), "spatula");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 815), 815);
  EXPECT_EQ(getLabel(label_->getLabels(), 815), "speedboat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 816), 816);
  EXPECT_EQ(getLabel(label_->getLabels(), 816), "spider web, spider's web");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 817), 817);
  EXPECT_EQ(getLabel(label_->getLabels(), 817), "spindle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 818), 818);
  EXPECT_EQ(getLabel(label_->getLabels(), 818), "sports car, sport car");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 819), 819);
  EXPECT_EQ(getLabel(label_->getLabels(), 819), "spotlight, spot");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 820), 820);
  EXPECT_EQ(getLabel(label_->getLabels(), 820), "stage");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 821), 821);
  EXPECT_EQ(getLabel(label_->getLabels(), 821), "steam locomotive");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 822), 822);
  EXPECT_EQ(getLabel(label_->getLabels(), 822), "steel arch bridge");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 823), 823);
  EXPECT_EQ(getLabel(label_->getLabels(), 823), "steel drum");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 824), 824);
  EXPECT_EQ(getLabel(label_->getLabels(), 824), "stethoscope");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 825), 825);
  EXPECT_EQ(getLabel(label_->getLabels(), 825), "stole");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 826), 826);
  EXPECT_EQ(getLabel(label_->getLabels(), 826), "stone wall");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 827), 827);
  EXPECT_EQ(getLabel(label_->getLabels(), 827), "stopwatch, stop watch");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 828), 828);
  EXPECT_EQ(getLabel(label_->getLabels(), 828), "stove");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 829), 829);
  EXPECT_EQ(getLabel(label_->getLabels(), 829), "strainer");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 830), 830);
  EXPECT_EQ(getLabel(label_->getLabels(), 830),
            "streetcar, tram, tramcar, trolley, trolley car");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 831), 831);
  EXPECT_EQ(getLabel(label_->getLabels(), 831), "stretcher");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 832), 832);
  EXPECT_EQ(getLabel(label_->getLabels(), 832), "studio couch, day bed");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 833), 833);
  EXPECT_EQ(getLabel(label_->getLabels(), 833), "stupa, tope");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 834), 834);
  EXPECT_EQ(getLabel(label_->getLabels(), 834),
            "submarine, pigboat, sub, U-boat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 835), 835);
  EXPECT_EQ(getLabel(label_->getLabels(), 835), "suit, suit of clothes");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 836), 836);
  EXPECT_EQ(getLabel(label_->getLabels(), 836), "sundial");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 837), 837);
  EXPECT_EQ(getLabel(label_->getLabels(), 837), "sunglass");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 838), 838);
  EXPECT_EQ(getLabel(label_->getLabels(), 838),
            "sunglasses, dark glasses, shades");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 839), 839);
  EXPECT_EQ(getLabel(label_->getLabels(), 839),
            "sunscreen, sunblock, sun blocker");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 840), 840);
  EXPECT_EQ(getLabel(label_->getLabels(), 840), "suspension bridge");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 841), 841);
  EXPECT_EQ(getLabel(label_->getLabels(), 841), "swab, swob, mop");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 842), 842);
  EXPECT_EQ(getLabel(label_->getLabels(), 842), "sweatshirt");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 843), 843);
  EXPECT_EQ(getLabel(label_->getLabels(), 843),
            "swimming trunks, bathing trunks");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 844), 844);
  EXPECT_EQ(getLabel(label_->getLabels(), 844), "swing");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 845), 845);
  EXPECT_EQ(getLabel(label_->getLabels(), 845),
            "switch, electric switch, electrical switch");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 846), 846);
  EXPECT_EQ(getLabel(label_->getLabels(), 846), "syringe");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 847), 847);
  EXPECT_EQ(getLabel(label_->getLabels(), 847), "table lamp");

  EXPECT_EQ(getIndexLabel(label_->getLabels(), 848), 848);
  EXPECT_EQ(getLabel(label_->getLabels(), 848),
            "tank, army tank, armored combat vehicle, "
            "armoured combat vehicle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 849), 849);
  EXPECT_EQ(getLabel(label_->getLabels(), 849), "tape player");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 850), 850);
  EXPECT_EQ(getLabel(label_->getLabels(), 850), "teapot");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 851), 851);
  EXPECT_EQ(getLabel(label_->getLabels(), 851), "teddy, teddy bear");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 852), 852);
  EXPECT_EQ(getLabel(label_->getLabels(), 852),
            "television, television system");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 853), 853);
  EXPECT_EQ(getLabel(label_->getLabels(), 853), "tennis ball");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 854), 854);
  EXPECT_EQ(getLabel(label_->getLabels(), 854), "thatch, thatched roof");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 855), 855);
  EXPECT_EQ(getLabel(label_->getLabels(), 855),
            "theater curtain, theatre curtain");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 856), 856);
  EXPECT_EQ(getLabel(label_->getLabels(), 856), "thimble");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 857), 857);
  EXPECT_EQ(getLabel(label_->getLabels(), 857),
            "thresher, thrasher, threshing machine");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 858), 858);
  EXPECT_EQ(getLabel(label_->getLabels(), 858), "throne");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 859), 859);
  EXPECT_EQ(getLabel(label_->getLabels(), 859), "tile roof");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 860), 860);
  EXPECT_EQ(getLabel(label_->getLabels(), 860), "toaster");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 861), 861);
  EXPECT_EQ(getLabel(label_->getLabels(), 861),
            "tobacco shop, tobacconist shop, tobacconist");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 862), 862);
  EXPECT_EQ(getLabel(label_->getLabels(), 862), "toilet seat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 863), 863);
  EXPECT_EQ(getLabel(label_->getLabels(), 863), "torch");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 864), 864);
  EXPECT_EQ(getLabel(label_->getLabels(), 864), "totem pole");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 865), 865);
  EXPECT_EQ(getLabel(label_->getLabels(), 865), "tow truck, tow car, wrecker");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 866), 866);
  EXPECT_EQ(getLabel(label_->getLabels(), 866), "toyshop");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 867), 867);
  EXPECT_EQ(getLabel(label_->getLabels(), 867), "tractor");

  EXPECT_EQ(getIndexLabel(label_->getLabels(), 868), 868);
  EXPECT_EQ(getLabel(label_->getLabels(), 868),
            "trailer truck, tractor trailer, trucking "
            "rig, rig, articulated "
            "lorry, semi");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 869), 869);
  EXPECT_EQ(getLabel(label_->getLabels(), 869), "tray");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 870), 870);
  EXPECT_EQ(getLabel(label_->getLabels(), 870), "trench coat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 871), 871);
  EXPECT_EQ(getLabel(label_->getLabels(), 871), "tricycle, trike, velocipede");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 872), 872);
  EXPECT_EQ(getLabel(label_->getLabels(), 872), "trimaran");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 873), 873);
  EXPECT_EQ(getLabel(label_->getLabels(), 873), "tripod");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 874), 874);
  EXPECT_EQ(getLabel(label_->getLabels(), 874), "triumphal arch");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 875), 875);
  EXPECT_EQ(getLabel(label_->getLabels(), 875),
            "trolleybus, trolley coach, trackless trolley");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 876), 876);
  EXPECT_EQ(getLabel(label_->getLabels(), 876), "trombone");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 877), 877);
  EXPECT_EQ(getLabel(label_->getLabels(), 877), "tub, vat");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 878), 878);
  EXPECT_EQ(getLabel(label_->getLabels(), 878), "turnstile");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 879), 879);
  EXPECT_EQ(getLabel(label_->getLabels(), 879), "typewriter keyboard");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 880), 880);
  EXPECT_EQ(getLabel(label_->getLabels(), 880), "umbrella");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 881), 881);
  EXPECT_EQ(getLabel(label_->getLabels(), 881), "unicycle, monocycle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 882), 882);
  EXPECT_EQ(getLabel(label_->getLabels(), 882), "upright, upright piano");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 883), 883);
  EXPECT_EQ(getLabel(label_->getLabels(), 883), "vacuum, vacuum cleaner");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 884), 884);
  EXPECT_EQ(getLabel(label_->getLabels(), 884), "vase");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 885), 885);
  EXPECT_EQ(getLabel(label_->getLabels(), 885), "vault");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 886), 886);
  EXPECT_EQ(getLabel(label_->getLabels(), 886), "velvet");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 887), 887);
  EXPECT_EQ(getLabel(label_->getLabels(), 887), "vending machine");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 888), 888);
  EXPECT_EQ(getLabel(label_->getLabels(), 888), "vestment");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 889), 889);
  EXPECT_EQ(getLabel(label_->getLabels(), 889), "viaduct");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 890), 890);
  EXPECT_EQ(getLabel(label_->getLabels(), 890), "violin, fiddle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 891), 891);
  EXPECT_EQ(getLabel(label_->getLabels(), 891), "volleyball");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 892), 892);
  EXPECT_EQ(getLabel(label_->getLabels(), 892), "waffle iron");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 893), 893);
  EXPECT_EQ(getLabel(label_->getLabels(), 893), "wall clock");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 894), 894);
  EXPECT_EQ(getLabel(label_->getLabels(), 894),
            "wallet, billfold, notecase, pocketbook");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 895), 895);
  EXPECT_EQ(getLabel(label_->getLabels(), 895), "wardrobe, closet, press");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 896), 896);
  EXPECT_EQ(getLabel(label_->getLabels(), 896), "warplane, military plane");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 897), 897);
  EXPECT_EQ(getLabel(label_->getLabels(), 897),
            "washbasin, handbasin, washbowl, lavabo, "
            "wash-hand basin");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 898), 898);
  EXPECT_EQ(getLabel(label_->getLabels(), 898),
            "washer, automatic washer, washing machine");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 899), 899);
  EXPECT_EQ(getLabel(label_->getLabels(), 899), "water bottle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 900), 900);
  EXPECT_EQ(getLabel(label_->getLabels(), 900), "water jug");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 901), 901);
  EXPECT_EQ(getLabel(label_->getLabels(), 901), "water tower");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 902), 902);
  EXPECT_EQ(getLabel(label_->getLabels(), 902), "whiskey jug");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 903), 903);
  EXPECT_EQ(getLabel(label_->getLabels(), 903), "whistle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 904), 904);
  EXPECT_EQ(getLabel(label_->getLabels(), 904), "wig");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 905), 905);
  EXPECT_EQ(getLabel(label_->getLabels(), 905), "window screen");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 906), 906);
  EXPECT_EQ(getLabel(label_->getLabels(), 906), "window shade");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 907), 907);
  EXPECT_EQ(getLabel(label_->getLabels(), 907), "Windsor tie");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 908), 908);
  EXPECT_EQ(getLabel(label_->getLabels(), 908), "wine bottle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 909), 909);
  EXPECT_EQ(getLabel(label_->getLabels(), 909), "wing");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 910), 910);
  EXPECT_EQ(getLabel(label_->getLabels(), 910), "wok");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 911), 911);
  EXPECT_EQ(getLabel(label_->getLabels(), 911), "wooden spoon");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 912), 912);
  EXPECT_EQ(getLabel(label_->getLabels(), 912), "wool, woolen, woollen");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 913), 913);
  EXPECT_EQ(getLabel(label_->getLabels(), 913),
            "worm fence, snake fence, snake-rail fence, "
            "Virginia fence");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 914), 914);
  EXPECT_EQ(getLabel(label_->getLabels(), 914), "wreck");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 915), 915);
  EXPECT_EQ(getLabel(label_->getLabels(), 915), "yawl");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 916), 916);
  EXPECT_EQ(getLabel(label_->getLabels(), 916), "yurt");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 917), 917);
  EXPECT_EQ(getLabel(label_->getLabels(), 917),
            "web site, website, internet site, site");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 918), 918);
  EXPECT_EQ(getLabel(label_->getLabels(), 918), "comic book");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 919), 919);
  EXPECT_EQ(getLabel(label_->getLabels(), 919), "crossword puzzle, crossword");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 920), 920);
  EXPECT_EQ(getLabel(label_->getLabels(), 920), "street sign");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 921), 921);
  EXPECT_EQ(getLabel(label_->getLabels(), 921),
            "traffic light, traffic signal, stoplight");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 922), 922);
  EXPECT_EQ(getLabel(label_->getLabels(), 922),
            "book jacket, dust cover, dust jacket, dust "
            "wrapper");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 923), 923);
  EXPECT_EQ(getLabel(label_->getLabels(), 923), "menu");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 924), 924);
  EXPECT_EQ(getLabel(label_->getLabels(), 924), "plate");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 925), 925);
  EXPECT_EQ(getLabel(label_->getLabels(), 925), "guacamole");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 926), 926);
  EXPECT_EQ(getLabel(label_->getLabels(), 926), "consomme");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 927), 927);
  EXPECT_EQ(getLabel(label_->getLabels(), 927), "hot pot, hotpot");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 928), 928);
  EXPECT_EQ(getLabel(label_->getLabels(), 928), "trifle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 929), 929);
  EXPECT_EQ(getLabel(label_->getLabels(), 929), "ice cream, icecream");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 930), 930);
  EXPECT_EQ(getLabel(label_->getLabels(), 930),
            "ice lolly, lolly, lollipop, popsicle");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 931), 931);
  EXPECT_EQ(getLabel(label_->getLabels(), 931), "French loaf");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 932), 932);
  EXPECT_EQ(getLabel(label_->getLabels(), 932), "bagel, beigel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 933), 933);
  EXPECT_EQ(getLabel(label_->getLabels(), 933), "pretzel");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 934), 934);
  EXPECT_EQ(getLabel(label_->getLabels(), 934), "cheeseburger");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 935), 935);
  EXPECT_EQ(getLabel(label_->getLabels(), 935), "hotdog, hot dog, red hot");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 936), 936);
  EXPECT_EQ(getLabel(label_->getLabels(), 936), "mashed potato");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 937), 937);
  EXPECT_EQ(getLabel(label_->getLabels(), 937), "head cabbage");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 938), 938);
  EXPECT_EQ(getLabel(label_->getLabels(), 938), "broccoli");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 939), 939);
  EXPECT_EQ(getLabel(label_->getLabels(), 939), "cauliflower");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 940), 940);
  EXPECT_EQ(getLabel(label_->getLabels(), 940), "zucchini, courgette");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 941), 941);
  EXPECT_EQ(getLabel(label_->getLabels(), 941), "spaghetti squash");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 942), 942);
  EXPECT_EQ(getLabel(label_->getLabels(), 942), "acorn squash");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 943), 943);
  EXPECT_EQ(getLabel(label_->getLabels(), 943), "butternut squash");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 944), 944);
  EXPECT_EQ(getLabel(label_->getLabels(), 944), "cucumber, cuke");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 945), 945);
  EXPECT_EQ(getLabel(label_->getLabels(), 945), "artichoke, globe artichoke");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 946), 946);
  EXPECT_EQ(getLabel(label_->getLabels(), 946), "bell pepper");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 947), 947);
  EXPECT_EQ(getLabel(label_->getLabels(), 947), "cardoon");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 948), 948);
  EXPECT_EQ(getLabel(label_->getLabels(), 948), "mushroom");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 949), 949);
  EXPECT_EQ(getLabel(label_->getLabels(), 949), "Granny Smith");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 950), 950);
  EXPECT_EQ(getLabel(label_->getLabels(), 950), "strawberry");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 951), 951);
  EXPECT_EQ(getLabel(label_->getLabels(), 951), "orange");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 952), 952);
  EXPECT_EQ(getLabel(label_->getLabels(), 952), "lemon");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 953), 953);
  EXPECT_EQ(getLabel(label_->getLabels(), 953), "fig");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 954), 954);
  EXPECT_EQ(getLabel(label_->getLabels(), 954), "pineapple, ananas");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 955), 955);
  EXPECT_EQ(getLabel(label_->getLabels(), 955), "banana");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 956), 956);
  EXPECT_EQ(getLabel(label_->getLabels(), 956), "jackfruit, jak, jack");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 957), 957);
  EXPECT_EQ(getLabel(label_->getLabels(), 957), "custard apple");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 958), 958);
  EXPECT_EQ(getLabel(label_->getLabels(), 958), "pomegranate");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 959), 959);
  EXPECT_EQ(getLabel(label_->getLabels(), 959), "hay");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 960), 960);
  EXPECT_EQ(getLabel(label_->getLabels(), 960), "carbonara");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 961), 961);
  EXPECT_EQ(getLabel(label_->getLabels(), 961),
            "chocolate sauce, chocolate syrup");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 962), 962);
  EXPECT_EQ(getLabel(label_->getLabels(), 962), "dough");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 963), 963);
  EXPECT_EQ(getLabel(label_->getLabels(), 963), "meat loaf, meatloaf");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 964), 964);
  EXPECT_EQ(getLabel(label_->getLabels(), 964), "pizza, pizza pie");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 965), 965);
  EXPECT_EQ(getLabel(label_->getLabels(), 965), "potpie");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 966), 966);
  EXPECT_EQ(getLabel(label_->getLabels(), 966), "burrito");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 967), 967);
  EXPECT_EQ(getLabel(label_->getLabels(), 967), "red wine");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 968), 968);
  EXPECT_EQ(getLabel(label_->getLabels(), 968), "espresso");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 969), 969);
  EXPECT_EQ(getLabel(label_->getLabels(), 969), "cup");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 970), 970);
  EXPECT_EQ(getLabel(label_->getLabels(), 970), "eggnog");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 971), 971);
  EXPECT_EQ(getLabel(label_->getLabels(), 971), "alp");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 972), 972);
  EXPECT_EQ(getLabel(label_->getLabels(), 972), "bubble");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 973), 973);
  EXPECT_EQ(getLabel(label_->getLabels(), 973), "cliff, drop, drop-off");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 974), 974);
  EXPECT_EQ(getLabel(label_->getLabels(), 974), "coral reef");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 975), 975);
  EXPECT_EQ(getLabel(label_->getLabels(), 975), "geyser");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 976), 976);
  EXPECT_EQ(getLabel(label_->getLabels(), 976), "lakeside, lakeshore");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 977), 977);
  EXPECT_EQ(getLabel(label_->getLabels(), 977),
            "promontory, headland, head, foreland");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 978), 978);
  EXPECT_EQ(getLabel(label_->getLabels(), 978), "sandbar, sand bar");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 979), 979);
  EXPECT_EQ(getLabel(label_->getLabels(), 979),
            "seashore, coast, seacoast, sea-coast");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 980), 980);
  EXPECT_EQ(getLabel(label_->getLabels(), 980), "valley, vale");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 981), 981);
  EXPECT_EQ(getLabel(label_->getLabels(), 981), "volcano");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 982), 982);
  EXPECT_EQ(getLabel(label_->getLabels(), 982), "ballplayer, baseball player");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 983), 983);
  EXPECT_EQ(getLabel(label_->getLabels(), 983), "groom, bridegroom");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 984), 984);
  EXPECT_EQ(getLabel(label_->getLabels(), 984), "scuba diver");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 985), 985);
  EXPECT_EQ(getLabel(label_->getLabels(), 985), "rapeseed");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 986), 986);
  EXPECT_EQ(getLabel(label_->getLabels(), 986), "daisy");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 987), 987);
  EXPECT_EQ(getLabel(label_->getLabels(), 987),
            "yellow lady's slipper, yellow lady-slipper, "
            "Cypripedium "
            "calceolus, Cypripedium parviflorum");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 988), 988);
  EXPECT_EQ(getLabel(label_->getLabels(), 988), "corn");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 989), 989);
  EXPECT_EQ(getLabel(label_->getLabels(), 989), "acorn");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 990), 990);
  EXPECT_EQ(getLabel(label_->getLabels(), 990), "hip, rose hip, rosehip");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 991), 991);
  EXPECT_EQ(getLabel(label_->getLabels(), 991),
            "buckeye, horse chestnut, conker");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 992), 992);
  EXPECT_EQ(getLabel(label_->getLabels(), 992), "coral fungus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 993), 993);
  EXPECT_EQ(getLabel(label_->getLabels(), 993), "agaric");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 994), 994);
  EXPECT_EQ(getLabel(label_->getLabels(), 994), "gyromitra");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 995), 995);
  EXPECT_EQ(getLabel(label_->getLabels(), 995), "stinkhorn, carrion fungus");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 996), 996);
  EXPECT_EQ(getLabel(label_->getLabels(), 996), "earthstar");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 997), 997);
  EXPECT_EQ(getLabel(label_->getLabels(), 997),
            "hen-of-the-woods, hen of the woods, "
            "Polyporus frondosus, Grifola "
            "frondosa");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 998), 998);
  EXPECT_EQ(getLabel(label_->getLabels(), 998), "bolete");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 999), 999);
  EXPECT_EQ(getLabel(label_->getLabels(), 999), "ear, spike, capitulum");
  EXPECT_EQ(getIndexLabel(label_->getLabels(), 1000), 1000);
  EXPECT_EQ(getLabel(label_->getLabels(), 1000),
            "toilet tissue, toilet paper, bathroom tissue");
}
