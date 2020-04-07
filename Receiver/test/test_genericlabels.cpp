#include <string>
#include <memory>

#include "gtest/gtest.h"
#include "labels.hpp"

class LabelsGeneric : public ::testing::Test {
  protected:
  const std::string label_path = { "../build_debug/test/resources/labels.txt" };
  std::unique_ptr<LabelDetection> label_{nullptr};

  void SetUp() {
    label_ = std::make_unique<LabelDetection>(label_path);
    label_->read();
  }

  void TearDown() {
    // code here will be called just after the TEST_F completes
    // ok to through exceptions from here if need be
  }

  const std::string getLabel(std::unordered_map<int, std::string> label, int i) {
    std::unordered_map<int, std::string>::iterator it = label.find(i);
    return it->second;
  }

  const int getIndexLabel(std::unordered_map<int, std::string> label, int i) {
    std::unordered_map<int, std::string>::iterator it = label.find(i);
    return it->first;
  }
};

TEST_F(LabelsGeneric, background) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 0), 0);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 0), "background");
}

TEST_F(LabelsGeneric, tench_Tinca_tinca) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 1), 1);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 1), "tench, Tinca tinca");
}

TEST_F(LabelsGeneric, goldfish_Carassius_auratus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 2), 2);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 2), "goldfish, Carassius auratus");
}

TEST_F(LabelsGeneric, great_white_shark_white_shark_man_eater_man_eating_shark_Carcharodon_carcharias) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 3), 3);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 3), "great white shark, white shark, man-eater, man-eating shark, Carcharodon carcharias");
}

TEST_F(LabelsGeneric, tiger_shark_Galeocerdo_cuvieri) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 4), 4);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 4), "tiger shark, Galeocerdo cuvieri");
}

TEST_F(LabelsGeneric, hammerhead_hammerhead_shark) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 5), 5);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 5), "hammerhead, hammerhead shark");
}

TEST_F(LabelsGeneric, electric_ray_crampfish_numbfish_torpedo) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 6), 6);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 6), "electric ray, crampfish, numbfish, torpedo");
}

TEST_F(LabelsGeneric, stingray) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 7), 7);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 7), "stingray");
}

TEST_F(LabelsGeneric, cock) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 8), 8);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 8), "cock");
}

TEST_F(LabelsGeneric, hen) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 9), 9);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 9), "hen");
}

TEST_F(LabelsGeneric, ostrich_Struthio_camelus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 10), 10);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 10), "ostrich, Struthio camelus");
}

TEST_F(LabelsGeneric, brambling_Fringilla_montifringilla) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 11), 11);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 11), "brambling, Fringilla montifringilla");
}

TEST_F(LabelsGeneric, goldfinch_Carduelis_carduelis) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 12), 12);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 12), "goldfinch, Carduelis carduelis");
}

TEST_F(LabelsGeneric, house_finch_linnet_Carpodacus_mexicanus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 13), 13);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 13), "house finch, linnet, Carpodacus mexicanus");
}

TEST_F(LabelsGeneric, junco_snowbird) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 14), 14);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 14), "junco, snowbird");
}

TEST_F(LabelsGeneric, indigo_bunting_indigo_finch_indigo_bird_Passerina_cyanea) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 15), 15);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 15), "indigo bunting, indigo finch, indigo bird, Passerina cyanea");
}

TEST_F(LabelsGeneric, robin_American_robin_Turdus_migratorius) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 16), 16);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 16), "robin, American robin, Turdus migratorius");
}

TEST_F(LabelsGeneric, bulbul) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 17), 17);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 17), "bulbul");
}

TEST_F(LabelsGeneric, jay) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 18), 18);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 18), "jay");
}

TEST_F(LabelsGeneric, magpie) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 19), 19);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 19), "magpie");
}

TEST_F(LabelsGeneric, chickadee) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 20), 20);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 20), "chickadee");
}

TEST_F(LabelsGeneric, water_ouzel_dipper) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 21), 21);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 21), "water ouzel, dipper");
}

TEST_F(LabelsGeneric, kite) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 22), 22);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 22), "kite");
}

TEST_F(LabelsGeneric, bald_eagle_American_eagle_Haliaeetus_leucocephalus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 23), 23);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 23), "bald eagle, American eagle, Haliaeetus leucocephalus");
}

TEST_F(LabelsGeneric, vulture) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 24), 24);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 24), "vulture");
}

TEST_F(LabelsGeneric, great_grey_owl_great_gray_owl_Strix_nebulosa) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 25), 25);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 25), "great grey owl, great gray owl, Strix nebulosa");
}

TEST_F(LabelsGeneric, European_fire_salamander_Salamandra_salamandra) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 26), 26);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 26), "European fire salamander, Salamandra salamandra");
}

TEST_F(LabelsGeneric, common_newt_Triturus_vulgaris) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 27), 27);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 27), "common newt, Triturus vulgaris");
}

TEST_F(LabelsGeneric, eft) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 28), 28);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 28), "eft");
}

TEST_F(LabelsGeneric, spotted_salamander_Ambystoma_maculatum) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 29), 29);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 29), "spotted salamander, Ambystoma maculatum");
}

TEST_F(LabelsGeneric, axolotl_mud_puppy_Ambystoma_mexicanum) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 30), 30);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 30), "axolotl, mud puppy, Ambystoma mexicanum");
}

TEST_F(LabelsGeneric, bullfrog_Rana_catesbeiana) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 31), 31);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 31), "bullfrog, Rana catesbeiana");
}

TEST_F(LabelsGeneric, tree_frog_tree_frog) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 32), 32);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 32), "tree frog, tree-frog");
}

TEST_F(LabelsGeneric, tailed_frog_bell_toad_ribbed_toad_tailed_toad_Ascaphus_trui) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 33), 33);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 33), "tailed frog, bell toad, ribbed toad, tailed toad, Ascaphus trui");
}

TEST_F(LabelsGeneric, loggerhead_loggerhead_turtle_Caretta_caretta) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 34), 34);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 34), "loggerhead, loggerhead turtle, Caretta caretta");
}

TEST_F(LabelsGeneric, leatherback_turtle_leatherback_leathery_turtle_Dermochelys_coriacea) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 35), 35);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 35), "leatherback turtle, leatherback, leathery turtle, Dermochelys coriacea");
}

TEST_F(LabelsGeneric, mud_turtle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 36), 36);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 36), "mud turtle");
}

TEST_F(LabelsGeneric, terrapin) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 37), 37);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 37), "terrapin");
}

TEST_F(LabelsGeneric, box_turtle_box_tortoise) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 38), 38);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 38), "box turtle, box tortoise");
}

TEST_F(LabelsGeneric, banded_gecko) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 39), 39);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 39), "banded gecko");
}

TEST_F(LabelsGeneric, common_iguana_iguana_Iguana_iguana) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 40), 40);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 40), "common iguana, iguana, Iguana iguana");
}

TEST_F(LabelsGeneric, American_chameleon_anole_Anolis_carolinensis) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 41), 41);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 41), "American chameleon, anole, Anolis carolinensis");
}

TEST_F(LabelsGeneric, whiptail_whiptail_lizard) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 42), 42);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 42), "whiptail, whiptail lizard");
}

TEST_F(LabelsGeneric, agama) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 43), 43);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 43), "agama");
}

TEST_F(LabelsGeneric, frilled_lizard_Chlamydosaurus_kingi) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 44), 44);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 44), "frilled lizard, Chlamydosaurus kingi");
}

TEST_F(LabelsGeneric, alligator_lizard) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 45), 45);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 45), "alligator lizard");
}

TEST_F(LabelsGeneric, Gila_monster_Heloderma_suspectum) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 46), 46);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 46), "Gila monster, Heloderma suspectum");
}

TEST_F(LabelsGeneric, green_lizard_Lacerta_viridis) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 47), 47);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 47), "green lizard, Lacerta viridis");
}

TEST_F(LabelsGeneric, African_chameleon_Chamaeleo_chamaeleon) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 48), 48);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 48), "African chameleon, Chamaeleo chamaeleon");
}

TEST_F(LabelsGeneric, Komodo_dragon_Komodo_lizard_dragon_lizard_giant_lizard_Varanus_komodoensis) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 49), 49);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 49), "Komodo dragon, Komodo lizard, dragon lizard, giant lizard, Varanus komodoensis");
}

TEST_F(LabelsGeneric, African_crocodile_Nile_crocodile_Crocodylus_niloticus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 50), 50);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 50), "African crocodile, Nile crocodile, Crocodylus niloticus");
}

TEST_F(LabelsGeneric, American_alligator_Alligator_mississipiensis) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 51), 51);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 51), "American alligator, Alligator mississipiensis");
}

TEST_F(LabelsGeneric, triceratops) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 52), 52);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 52), "triceratops");
}

TEST_F(LabelsGeneric, thunder_snake_worm_snake_Carphophis_amoenus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 53), 53);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 53), "thunder snake, worm snake, Carphophis amoenus");
}

TEST_F(LabelsGeneric, ringneck_snake_ring_necked_snake_ring_snake) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 54), 54);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 54), "ringneck snake, ring-necked snake, ring snake");
}

TEST_F(LabelsGeneric, hognose_snake_puff_adder_sand_viper) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 55), 55);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 55), "hognose snake, puff adder, sand viper");
}

TEST_F(LabelsGeneric, green_snake_grass_snake) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 56), 56);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 56), "green snake, grass snake");
}

TEST_F(LabelsGeneric, king_snake_kingsnake) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 57), 57);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 57), "king snake, kingsnake");
}

TEST_F(LabelsGeneric, garter_snake_grass_snake) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 58), 58);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 58), "garter snake, grass snake");
}

TEST_F(LabelsGeneric, water_snake) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 59), 59);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 59), "water snake");
}

TEST_F(LabelsGeneric, vine_snake) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 60), 60);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 60), "vine snake");
}

TEST_F(LabelsGeneric, night_snake_Hypsiglena_torquata) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 61), 61);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 61), "night snake, Hypsiglena torquata");
}

TEST_F(LabelsGeneric, boa_constrictor_Constrictor_constrictor) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 62), 62);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 62), "boa constrictor, Constrictor constrictor");
}

TEST_F(LabelsGeneric, rock_python_rock_snake_Python_sebae) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 63), 63);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 63), "rock python, rock snake, Python sebae");
}

TEST_F(LabelsGeneric, Indian_cobra_Naja_naja) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 64), 64);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 64), "Indian cobra, Naja naja");
}

TEST_F(LabelsGeneric, green_mamba) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 65), 65);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 65), "green mamba");
}

TEST_F(LabelsGeneric, sea_snake) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 66), 66);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 66), "sea snake");
}

TEST_F(LabelsGeneric, horned_viper_cerastes_sand_viper_horned_asp_Cerastes_cornutus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 67), 67);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 67), "horned viper, cerastes, sand viper, horned asp, Cerastes cornutus");
}

TEST_F(LabelsGeneric, diamondback_diamondback_rattlesnake_Crotalus_adamanteus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 68), 68);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 68), "diamondback, diamondback rattlesnake, Crotalus adamanteus");
}

TEST_F(LabelsGeneric, sidewinder_horned_rattlesnake_Crotalus_cerastes) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 69), 69);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 69), "sidewinder, horned rattlesnake, Crotalus cerastes");
}

TEST_F(LabelsGeneric, trilobite) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 70), 70);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 70), "trilobite");
}

TEST_F(LabelsGeneric, harvestman_daddy_longlegs_Phalangium_opilio) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 71), 71);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 71), "harvestman, daddy longlegs, Phalangium opilio");
}

TEST_F(LabelsGeneric, scorpion) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 72), 72);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 72), "scorpion");
}

TEST_F(LabelsGeneric, black_and_gold_garden_spider_Argiope_aurantia) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 73), 73);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 73), "black and gold garden spider, Argiope aurantia");
}

TEST_F(LabelsGeneric, barn_spider_Araneus_cavaticus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 74), 74);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 74), "barn spider, Araneus cavaticus");
}

TEST_F(LabelsGeneric, garden_spider_Aranea_diademata) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 75), 75);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 75), "garden spider, Aranea diademata");
}

TEST_F(LabelsGeneric, black_widow_Latrodectus_mactans) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 76), 76);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 76), "black widow, Latrodectus mactans");
}

TEST_F(LabelsGeneric, tarantula) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 77), 77);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 77), "tarantula");
}

TEST_F(LabelsGeneric, wolf_spider_hunting_spider) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 78), 78);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 78), "wolf spider, hunting spider");
}

TEST_F(LabelsGeneric, tick) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 79), 79);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 79), "tick");
}

TEST_F(LabelsGeneric, centipede) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 80), 80);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 80), "centipede");
}

TEST_F(LabelsGeneric, black_grouse) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 81), 81);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 81), "black grouse");
}

TEST_F(LabelsGeneric, ptarmigan) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 82), 82);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 82), "ptarmigan");
}

TEST_F(LabelsGeneric, ruffed_grouse_partridge_Bonasa_umbellus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 83), 83);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 83), "ruffed grouse, partridge, Bonasa umbellus");
}

TEST_F(LabelsGeneric, prairie_chicken_prairie_grouse_prairie_fowl) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 84), 84);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 84), "prairie chicken, prairie grouse, prairie fowl");
}

TEST_F(LabelsGeneric, peacock) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 85), 85);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 85), "peacock");
}

TEST_F(LabelsGeneric, quail) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 86), 86);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 86), "quail");
}

TEST_F(LabelsGeneric, partridge) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 87), 87);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 87), "partridge");
}

TEST_F(LabelsGeneric, African_grey_African_gray_Psittacus_erithacus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 88), 88);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 88), "African grey, African gray, Psittacus erithacus");
}

TEST_F(LabelsGeneric, macaw) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 89), 89);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 89), "macaw");
}

TEST_F(LabelsGeneric, sulphur_crested_cockatoo_Kakatoe_galerita_Cacatua_galerita) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 90), 90);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 90), "sulphur-crested cockatoo, Kakatoe galerita, Cacatua galerita");
}

TEST_F(LabelsGeneric, lorikeet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 91), 91);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 91), "lorikeet");
}

TEST_F(LabelsGeneric, coucal) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 92), 92);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 92), "coucal");
}

TEST_F(LabelsGeneric, bee_eater) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 93), 93);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 93), "bee eater");
}

TEST_F(LabelsGeneric, hornbill) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 94), 94);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 94), "hornbill");
}

TEST_F(LabelsGeneric, hummingbird) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 95), 95);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 95), "hummingbird");
}

TEST_F(LabelsGeneric, jacamar) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 96), 96);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 96), "jacamar");
}

TEST_F(LabelsGeneric, toucan) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 97), 97);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 97), "toucan");
}

TEST_F(LabelsGeneric, drake) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 98), 98);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 98), "drake");
}

TEST_F(LabelsGeneric, red_breasted_merganser_Mergus_serrator) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 99), 99);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 99), "red-breasted merganser, Mergus serrator");
}

TEST_F(LabelsGeneric, goose) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 100), 100);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 100), "goose");
}

TEST_F(LabelsGeneric, black_swan_Cygnus_atratus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 101), 101);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 101), "black swan, Cygnus atratus");
}

TEST_F(LabelsGeneric, tusker) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 102), 102);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 102), "tusker");
}

TEST_F(LabelsGeneric, echidna_spiny_anteater_anteater) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 103), 103);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 103), "echidna, spiny anteater, anteater");
}

TEST_F(LabelsGeneric, platypus_duckbill_duckbilled_platypus_duck_billed_platypus_Ornithorhynchus_anatinus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 104), 104);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 104), "platypus, duckbill, duckbilled platypus, duck-billed platypus, Ornithorhynchus anatinus");
}

TEST_F(LabelsGeneric, wallaby_brush_kangaroo) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 105), 105);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 105), "wallaby, brush kangaroo");
}

TEST_F(LabelsGeneric, koala_koala_bear_kangaroo_bear_native_bear_Phascolarctos_cinereus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 106), 106);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 106), "koala, koala bear, kangaroo bear, native bear, Phascolarctos cinereus");
}

TEST_F(LabelsGeneric, wombat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 107), 107);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 107), "wombat");
}

TEST_F(LabelsGeneric, jellyfish) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 108), 108);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 108), "jellyfish");
}

TEST_F(LabelsGeneric, sea_anemone_anemone) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 109), 109);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 109), "sea anemone, anemone");
}

TEST_F(LabelsGeneric, brain_coral) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 110), 110);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 110), "brain coral");
}

TEST_F(LabelsGeneric, flatworm_platyhelminth) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 111), 111);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 111), "flatworm, platyhelminth");
}

TEST_F(LabelsGeneric, nematode_nematode_worm_roundworm) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 112), 112);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 112), "nematode, nematode worm, roundworm");
}

TEST_F(LabelsGeneric, conch) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 113), 113);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 113), "conch");
}

TEST_F(LabelsGeneric, snail) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 114), 114);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 114), "snail");
}

TEST_F(LabelsGeneric, slug) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 115), 115);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 115), "slug");
}

TEST_F(LabelsGeneric, sea_slug_nudibranch) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 116), 116);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 116), "sea slug, nudibranch");
}

TEST_F(LabelsGeneric, chiton_coat_of_mail_shell_sea_cradle_polyplacophore) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 117), 117);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 117), "chiton, coat-of-mail shell, sea cradle, polyplacophore");
}

TEST_F(LabelsGeneric, chambered_nautilus_pearly_nautilus_nautilus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 118), 118);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 118), "chambered nautilus, pearly nautilus, nautilus");
}

TEST_F(LabelsGeneric, Dungeness_crab_Cancer_magister) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 119), 119);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 119), "Dungeness crab, Cancer magister");
}

TEST_F(LabelsGeneric, rock_crab_Cancer_irroratus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 120), 120);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 120), "rock crab, Cancer irroratus");
}

TEST_F(LabelsGeneric, fiddler_crab) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 121), 121);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 121), "fiddler crab");
}

TEST_F(LabelsGeneric, king_crab_Alaska_crab_Alaskan_king_crab_Alaska_king_crab_Paralithodes_camtschatica) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 122), 122);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 122), "king crab, Alaska crab, Alaskan king crab, Alaska king crab, Paralithodes camtschatica");
}

TEST_F(LabelsGeneric, American_lobster_Northern_lobster_Maine_lobster_Homarus_americanus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 123), 123);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 123), "American lobster, Northern lobster, Maine lobster, Homarus americanus");
}

TEST_F(LabelsGeneric, spiny_lobster_langouste_rock_lobster_crawfish_crayfish_sea_crawfish) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 124), 124);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 124), "spiny lobster, langouste, rock lobster, crawfish, crayfish, sea crawfish");
}

TEST_F(LabelsGeneric, crayfish_crawfish_crawdad_crawdaddy) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 125), 125);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 125), "crayfish, crawfish, crawdad, crawdaddy");
}

TEST_F(LabelsGeneric, hermit_crab) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 126), 126);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 126), "hermit crab");
}

TEST_F(LabelsGeneric, isopod) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 127), 127);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 127), "isopod");
}

TEST_F(LabelsGeneric, white_stork_Ciconia_ciconia) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 128), 128);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 128), "white stork, Ciconia ciconia");
}

TEST_F(LabelsGeneric, black_stork_Ciconia_nigra) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 129), 129);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 129), "black stork, Ciconia nigra");
}

TEST_F(LabelsGeneric, spoonbill) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 130), 130);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 130), "spoonbill");
}

TEST_F(LabelsGeneric, flamingo) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 131), 131);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 131), "flamingo");
}

TEST_F(LabelsGeneric, little_blue_heron_Egretta_caerulea) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 132), 132);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 132), "little blue heron, Egretta caerulea");
}

TEST_F(LabelsGeneric, American_egret_great_white_heron_Egretta_albus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 133), 133);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 133), "American egret, great white heron, Egretta albus");
}

TEST_F(LabelsGeneric, bittern) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 134), 134);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 134), "bittern");
}

TEST_F(LabelsGeneric, crane) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 135), 135);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 135), "crane");
}

TEST_F(LabelsGeneric, limpkin_Aramus_pictus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 136), 136);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 136), "limpkin, Aramus pictus");
}

TEST_F(LabelsGeneric, European_gallinule_Porphyrio_porphyrio) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 137), 137);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 137), "European gallinule, Porphyrio porphyrio");
}

TEST_F(LabelsGeneric, American_coot_marsh_hen_mud_hen_water_hen_Fulica_americana) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 138), 138);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 138), "American coot, marsh hen, mud hen, water hen, Fulica americana");
}

TEST_F(LabelsGeneric, bustard) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 139), 139);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 139), "bustard");
}

TEST_F(LabelsGeneric, ruddy_turnstone_Arenaria_interpres) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 140), 140);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 140), "ruddy turnstone, Arenaria interpres");
}

TEST_F(LabelsGeneric, red_backed_sandpiper_dunlin_Erolia_alpina) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 141), 141);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 141), "red-backed sandpiper, dunlin, Erolia alpina");
}

TEST_F(LabelsGeneric, redshank_Tringa_totanus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 142), 142);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 142), "redshank, Tringa totanus");
}

TEST_F(LabelsGeneric, dowitcher) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 143), 143);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 143), "dowitcher");
}

TEST_F(LabelsGeneric, oystercatcher_oyster_catcher) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 144), 144);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 144), "oystercatcher, oyster catcher");
}

TEST_F(LabelsGeneric, pelican) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 145), 145);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 145), "pelican");
}

TEST_F(LabelsGeneric, king_penguin_Aptenodytes_patagonica) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 146), 146);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 146), "king penguin, Aptenodytes patagonica");
}

TEST_F(LabelsGeneric, albatross_mollymawk) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 147), 147);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 147), "albatross, mollymawk");
}

TEST_F(LabelsGeneric, grey_whale_gray_whale_devilfish_Eschrichtius_gibbosus_Eschrichtius_robustus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 148), 148);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 148), "grey whale, gray whale, devilfish, Eschrichtius gibbosus, Eschrichtius robustus");
}

TEST_F(LabelsGeneric, killer_whale_killer_orca_grampus_sea_wolf_Orcinus_orca) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 149), 149);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 149), "killer whale, killer, orca, grampus, sea wolf, Orcinus orca");
}

TEST_F(LabelsGeneric, dugong_Dugong_dugon) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 150), 150);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 150), "dugong, Dugong dugon");
}

TEST_F(LabelsGeneric, sea_lion) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 151), 151);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 151), "sea lion");
}

TEST_F(LabelsGeneric, Chihuahua) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 152), 152);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 152), "Chihuahua");
}

TEST_F(LabelsGeneric, Japanese_spaniel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 153), 153);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 153), "Japanese spaniel");
}

TEST_F(LabelsGeneric, Maltese_dog_Maltese_terrier_Maltese) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 154), 154);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 154), "Maltese dog, Maltese terrier, Maltese");
}

TEST_F(LabelsGeneric, Pekinese_Pekingese_Peke) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 155), 155);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 155), "Pekinese, Pekingese, Peke");
}

TEST_F(LabelsGeneric, Shih_Tzu) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 156), 156);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 156), "Shih-Tzu");
}

TEST_F(LabelsGeneric, Blenheim_spaniel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 157), 157);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 157), "Blenheim spaniel");
}

TEST_F(LabelsGeneric, papillon) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 158), 158);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 158), "papillon");
}

TEST_F(LabelsGeneric, toy_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 159), 159);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 159), "toy terrier");
}

TEST_F(LabelsGeneric, Rhodesian_ridgeback) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 160), 160);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 160), "Rhodesian ridgeback");
}

TEST_F(LabelsGeneric, Afghan_hound_Afghan) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 161), 161);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 161), "Afghan hound, Afghan");
}

TEST_F(LabelsGeneric, basset_basset_hound) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 162), 162);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 162), "basset, basset hound");
}

TEST_F(LabelsGeneric, beagle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 163), 163);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 163), "beagle");
}

TEST_F(LabelsGeneric, bloodhound_sleuthhound) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 164), 164);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 164), "bloodhound, sleuthhound");
}

TEST_F(LabelsGeneric, bluetick) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 165), 165);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 165), "bluetick");
}

TEST_F(LabelsGeneric, black_and_tan_coonhound) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 166), 166);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 166), "black-and-tan coonhound");
}

TEST_F(LabelsGeneric, Walker_hound_Walker_foxhound) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 167), 167);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 167), "Walker hound, Walker foxhound");
}

TEST_F(LabelsGeneric, English_foxhound) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 168), 168);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 168), "English foxhound");
}

TEST_F(LabelsGeneric, redbone) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 169), 169);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 169), "redbone");
}

TEST_F(LabelsGeneric, borzoi_Russian_wolfhound) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 170), 170);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 170), "borzoi, Russian wolfhound");
}

TEST_F(LabelsGeneric, Irish_wolfhound) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 171), 171);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 171), "Irish wolfhound");
}

TEST_F(LabelsGeneric, Italian_greyhound) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 172), 172);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 172), "Italian greyhound");
}

TEST_F(LabelsGeneric, whippet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 173), 173);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 173), "whippet");
}

TEST_F(LabelsGeneric, Ibizan_hound_Ibizan_Podenco) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 174), 174);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 174), "Ibizan hound, Ibizan Podenco");
}

TEST_F(LabelsGeneric, Norwegian_elkhound_elkhound) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 175), 175);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 175), "Norwegian elkhound, elkhound");
}

TEST_F(LabelsGeneric, otterhound_otter_hound) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 176), 176);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 176), "otterhound, otter hound");
}

TEST_F(LabelsGeneric, Saluki_gazelle_hound) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 177), 177);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 177), "Saluki, gazelle hound");
}

TEST_F(LabelsGeneric, Scottish_deerhound_deerhound) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 178), 178);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 178), "Scottish deerhound, deerhound");
}

TEST_F(LabelsGeneric, Weimaraner) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 179), 179);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 179), "Weimaraner");
}

TEST_F(LabelsGeneric, Staffordshire_bullterrier_Staffordshire_bull_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 180), 180);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 180), "Staffordshire bullterrier, Staffordshire bull terrier");
}

TEST_F(LabelsGeneric, American_Staffordshire_terrier_Staffordshire_terrier_American_pit_bull_terrier_pit_bull_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 181), 181);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 181), "American Staffordshire terrier, Staffordshire terrier, American pit bull terrier, pit bull terrier");
}

TEST_F(LabelsGeneric, Bedlington_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 182), 182);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 182), "Bedlington terrier");
}

TEST_F(LabelsGeneric, Border_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 183), 183);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 183), "Border terrier");
}

TEST_F(LabelsGeneric, Kerry_blue_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 184), 184);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 184), "Kerry blue terrier");
}

TEST_F(LabelsGeneric, Irish_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 185), 185);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 185), "Irish terrier");
}

TEST_F(LabelsGeneric, Norfolk_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 186), 186);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 186), "Norfolk terrier");
}

TEST_F(LabelsGeneric, Norwich_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 187), 187);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 187), "Norwich terrier");
}

TEST_F(LabelsGeneric, Yorkshire_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 188), 188);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 188), "Yorkshire terrier");
}

TEST_F(LabelsGeneric, wire_haired_fox_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 189), 189);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 189), "wire-haired fox terrier");
}

TEST_F(LabelsGeneric, Lakeland_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 190), 190);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 190), "Lakeland terrier");
}

TEST_F(LabelsGeneric, Sealyham_terrier_Sealyham) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 191), 191);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 191), "Sealyham terrier, Sealyham");
}

TEST_F(LabelsGeneric, Airedale_Airedale_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 192), 192);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 192), "Airedale, Airedale terrier");
}

TEST_F(LabelsGeneric, cairn_cairn_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 193), 193);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 193), "cairn, cairn terrier");
}

TEST_F(LabelsGeneric, Australian_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 194), 194);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 194), "Australian terrier");
}

TEST_F(LabelsGeneric, Dandie_Dinmont_Dandie_Dinmont_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 195), 195);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 195), "Dandie Dinmont, Dandie Dinmont terrier");
}

TEST_F(LabelsGeneric, Boston_bull_Boston_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 196), 196);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 196), "Boston bull, Boston terrier");
}

TEST_F(LabelsGeneric, miniature_schnauzer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 197), 197);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 197), "miniature schnauzer");
}

TEST_F(LabelsGeneric, giant_schnauzer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 198), 198);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 198), "giant schnauzer");
}

TEST_F(LabelsGeneric, standard_schnauzer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 199), 199);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 199), "standard schnauzer");
}

TEST_F(LabelsGeneric, Scotch_terrier_Scottish_terrier_Scottie) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 200), 200);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 200), "Scotch terrier, Scottish terrier, Scottie");
}

TEST_F(LabelsGeneric, Tibetan_terrier_chrysanthemum_dog) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 201), 201);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 201), "Tibetan terrier, chrysanthemum dog");
}

TEST_F(LabelsGeneric, silky_terrier_Sydney_silky) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 202), 202);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 202), "silky terrier, Sydney silky");
}

TEST_F(LabelsGeneric, soft_coated_wheaten_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 203), 203);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 203), "soft-coated wheaten terrier");
}

TEST_F(LabelsGeneric, West_Highland_white_terrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 204), 204);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 204), "West Highland white terrier");
}

TEST_F(LabelsGeneric, Lhasa_Lhasa_apso) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 205), 205);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 205), "Lhasa, Lhasa apso");
}

TEST_F(LabelsGeneric, flat_coated_retriever) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 206), 206);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 206), "flat-coated retriever");
}

TEST_F(LabelsGeneric, curly_coated_retriever) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 207), 207);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 207), "curly-coated retriever");
}

TEST_F(LabelsGeneric, golden_retriever) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 208), 208);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 208), "golden retriever");
}

TEST_F(LabelsGeneric, Labrador_retriever) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 209), 209);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 209), "Labrador retriever");
}

TEST_F(LabelsGeneric, Chesapeake_Bay_retriever) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 210), 210);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 210), "Chesapeake Bay retriever");
}

TEST_F(LabelsGeneric, German_short_haired_pointer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 211), 211);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 211), "German short-haired pointer");
}

TEST_F(LabelsGeneric, vizsla_Hungarian_pointer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 212), 212);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 212), "vizsla, Hungarian pointer");
}

TEST_F(LabelsGeneric, English_setter) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 213), 213);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 213), "English setter");
}

TEST_F(LabelsGeneric, Irish_setter_red_setter) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 214), 214);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 214), "Irish setter, red setter");
}

TEST_F(LabelsGeneric, Gordon_setter) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 215), 215);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 215), "Gordon setter");
}

TEST_F(LabelsGeneric, Brittany_spaniel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 216), 216);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 216), "Brittany spaniel");
}

TEST_F(LabelsGeneric, clumber_clumber_spaniel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 217), 217);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 217), "clumber, clumber spaniel");
}

TEST_F(LabelsGeneric, English_springer_English_springer_spaniel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 218), 218);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 218), "English springer, English springer spaniel");
}

TEST_F(LabelsGeneric, Welsh_springer_spaniel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 219), 219);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 219), "Welsh springer spaniel");
}

TEST_F(LabelsGeneric, cocker_spaniel_English_cocker_spaniel_cocker) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 220), 220);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 220), "cocker spaniel, English cocker spaniel, cocker");
}

TEST_F(LabelsGeneric, Sussex_spaniel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 221), 221);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 221), "Sussex spaniel");
}

TEST_F(LabelsGeneric, Irish_water_spaniel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 222), 222);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 222), "Irish water spaniel");
}

TEST_F(LabelsGeneric, kuvasz) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 223), 223);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 223), "kuvasz");
}

TEST_F(LabelsGeneric, schipperke) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 224), 224);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 224), "schipperke");
}

TEST_F(LabelsGeneric, groenendael) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 225), 225);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 225), "groenendael");
}

TEST_F(LabelsGeneric, malinois) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 226), 226);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 226), "malinois");
}

TEST_F(LabelsGeneric, briard) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 227), 227);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 227), "briard");
}

TEST_F(LabelsGeneric, kelpie) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 228), 228);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 228), "kelpie");
}

TEST_F(LabelsGeneric, komondor) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 229), 229);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 229), "komondor");
}

TEST_F(LabelsGeneric, Old_English_sheepdog_bobtail) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 230), 230);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 230), "Old English sheepdog, bobtail");
}

TEST_F(LabelsGeneric, Shetland_sheepdog_Shetland_sheep_dog_Shetland) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 231), 231);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 231), "Shetland sheepdog, Shetland sheep dog, Shetland");
}

TEST_F(LabelsGeneric, collie) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 232), 232);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 232), "collie");
}

TEST_F(LabelsGeneric, Border_collie) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 233), 233);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 233), "Border collie");
}

TEST_F(LabelsGeneric, Bouvier_des_Flandres_Bouviers_des_Flandres) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 234), 234);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 234), "Bouvier des Flandres, Bouviers des Flandres");
}

TEST_F(LabelsGeneric, Rottweiler) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 235), 235);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 235), "Rottweiler");
}

TEST_F(LabelsGeneric, German_shepherd_German_shepherd_dog_German_police_dog_alsatian) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 236), 236);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 236), "German shepherd, German shepherd dog, German police dog, alsatian");
}

TEST_F(LabelsGeneric, Doberman_Doberman_pinscher) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 237), 237);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 237), "Doberman, Doberman pinscher");
}

TEST_F(LabelsGeneric, miniature_pinscher) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 238), 238);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 238), "miniature pinscher");
}

TEST_F(LabelsGeneric, Greater_Swiss_Mountain_dog) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 239), 239);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 239), "Greater Swiss Mountain dog");
}

TEST_F(LabelsGeneric, Bernese_mountain_dog) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 240), 240);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 240), "Bernese mountain dog");
}

TEST_F(LabelsGeneric, Appenzeller) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 241), 241);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 241), "Appenzeller");
}

TEST_F(LabelsGeneric, EntleBucher) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 242), 242);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 242), "EntleBucher");
}

TEST_F(LabelsGeneric, boxer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 243), 243);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 243), "boxer");
}

TEST_F(LabelsGeneric, bull_mastiff) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 244), 244);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 244), "bull mastiff");
}

TEST_F(LabelsGeneric, Tibetan_mastiff) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 245), 245);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 245), "Tibetan mastiff");
}

TEST_F(LabelsGeneric, French_bulldog) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 246), 246);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 246), "French bulldog");
}

TEST_F(LabelsGeneric, Great_Dane) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 247), 247);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 247), "Great Dane");
}

TEST_F(LabelsGeneric, Saint_Bernard_St_Bernard) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 248), 248);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 248), "Saint Bernard, St Bernard");
}

TEST_F(LabelsGeneric, Eskimo_dog_husky) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 249), 249);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 249), "Eskimo dog, husky");
}

TEST_F(LabelsGeneric, malamute_malemute_Alaskan_malamute) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 250), 250);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 250), "malamute, malemute, Alaskan malamute");
}

TEST_F(LabelsGeneric, Siberian_husky) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 251), 251);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 251), "Siberian husky");
}

TEST_F(LabelsGeneric, dalmatian_coach_dog_carriage_dog) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 252), 252);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 252), "dalmatian, coach dog, carriage dog");
}

TEST_F(LabelsGeneric, affenpinscher_monkey_pinscher_monkey_dog) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 253), 253);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 253), "affenpinscher, monkey pinscher, monkey dog");
}

TEST_F(LabelsGeneric, basenji) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 254), 254);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 254), "basenji");
}

TEST_F(LabelsGeneric, pug_pug_dog) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 255), 255);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 255), "pug, pug-dog");
}

TEST_F(LabelsGeneric, Leonberg) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 256), 256);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 256), "Leonberg");
}

TEST_F(LabelsGeneric, Newfoundland_Newfoundland_dog) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 257), 257);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 257), "Newfoundland, Newfoundland dog");
}

TEST_F(LabelsGeneric, Great_Pyrenees) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 258), 258);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 258), "Great Pyrenees");
}

TEST_F(LabelsGeneric, Samoyed_Samoyede) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 259), 259);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 259), "Samoyed, Samoyede");
}

TEST_F(LabelsGeneric, Pomeranian) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 260), 260);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 260), "Pomeranian");
}

TEST_F(LabelsGeneric, chow_chow_chow) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 261), 261);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 261), "chow, chow chow");
}

TEST_F(LabelsGeneric, keeshond) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 262), 262);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 262), "keeshond");
}

TEST_F(LabelsGeneric, Brabancon_griffon) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 263), 263);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 263), "Brabancon griffon");
}

TEST_F(LabelsGeneric, Pembroke_Pembroke_Welsh_corgi) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 264), 264);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 264), "Pembroke, Pembroke Welsh corgi");
}

TEST_F(LabelsGeneric, Cardigan_Cardigan_Welsh_corgi) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 265), 265);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 265), "Cardigan, Cardigan Welsh corgi");
}

TEST_F(LabelsGeneric, toy_poodle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 266), 266);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 266), "toy poodle");
}

TEST_F(LabelsGeneric, miniature_poodle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 267), 267);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 267), "miniature poodle");
}

TEST_F(LabelsGeneric, standard_poodle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 268), 268);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 268), "standard poodle");
}

TEST_F(LabelsGeneric, Mexican_hairless) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 269), 269);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 269), "Mexican hairless");
}

TEST_F(LabelsGeneric, timber_wolf_grey_wolf_gray_wolf_Canis_lupus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 270), 270);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 270), "timber wolf, grey wolf, gray wolf, Canis lupus");
}

TEST_F(LabelsGeneric, white_wolf_Arctic_wolf_Canis_lupus_tundrarum) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 271), 271);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 271), "white wolf, Arctic wolf, Canis lupus tundrarum");
}

TEST_F(LabelsGeneric, red_wolf_maned_wolf_Canis_rufus_Canis_niger) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 272), 272);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 272), "red wolf, maned wolf, Canis rufus, Canis niger");
}

TEST_F(LabelsGeneric, coyote_prairie_wolf_brush_wolf_Canis_latrans) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 273), 273);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 273), "coyote, prairie wolf, brush wolf, Canis latrans");
}

TEST_F(LabelsGeneric, dingo_warrigal_warragal_Canis_dingo) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 274), 274);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 274), "dingo, warrigal, warragal, Canis dingo");
}

TEST_F(LabelsGeneric, dhole_Cuon_alpinus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 275), 275);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 275), "dhole, Cuon alpinus");
}

TEST_F(LabelsGeneric, African_hunting_dog_hyena_dog_Cape_hunting_dog_Lycaon_pictus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 276), 276);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 276), "African hunting dog, hyena dog, Cape hunting dog, Lycaon pictus");
}

TEST_F(LabelsGeneric, hyena_hyaena) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 277), 277);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 277), "hyena, hyaena");
}

TEST_F(LabelsGeneric, red_fox_Vulpes_vulpes) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 278), 278);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 278), "red fox, Vulpes vulpes");
}

TEST_F(LabelsGeneric, kit_fox_Vulpes_macrotis) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 279), 279);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 279), "kit fox, Vulpes macrotis");
}

TEST_F(LabelsGeneric, Arctic_fox_white_fox_Alopex_lagopus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 280), 280);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 280), "Arctic fox, white fox, Alopex lagopus");
}

TEST_F(LabelsGeneric, grey_fox_gray_fox_Urocyon_cinereoargenteus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 281), 281);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 281), "grey fox, gray fox, Urocyon cinereoargenteus");
}

TEST_F(LabelsGeneric, tabby_tabby_cat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 282), 282);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 282), "tabby, tabby cat");
}

TEST_F(LabelsGeneric, tiger_cat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 283), 283);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 283), "tiger cat");
}

TEST_F(LabelsGeneric, Persian_cat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 284), 284);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 284), "Persian cat");
}

TEST_F(LabelsGeneric, Siamese_cat_Siamese) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 285), 285);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 285), "Siamese cat, Siamese");
}

TEST_F(LabelsGeneric, Egyptian_cat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 286), 286);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 286), "Egyptian cat");
}

TEST_F(LabelsGeneric, cougar_puma_catamount_mountain_lion_painter_panther_Felis_concolor) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 287), 287);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 287), "cougar, puma, catamount, mountain lion, painter, panther, Felis concolor");
}

TEST_F(LabelsGeneric, lynx_catamount) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 288), 288);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 288), "lynx, catamount");
}

TEST_F(LabelsGeneric, leopard_Panthera_pardus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 289), 289);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 289), "leopard, Panthera pardus");
}

TEST_F(LabelsGeneric, snow_leopard_ounce_Panthera_uncia) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 290), 290);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 290), "snow leopard, ounce, Panthera uncia");
}

TEST_F(LabelsGeneric, jaguar_panther_Panthera_onca_Felis_onca) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 291), 291);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 291), "jaguar, panther, Panthera onca, Felis onca");
}

TEST_F(LabelsGeneric, lion_king_of_beasts_Panthera_leo) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 292), 292);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 292), "lion, king of beasts, Panthera leo");
}

TEST_F(LabelsGeneric, tiger_Panthera_tigris) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 293), 293);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 293), "tiger, Panthera tigris");
}

TEST_F(LabelsGeneric, cheetah_chetah_Acinonyx_jubatus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 294), 294);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 294), "cheetah, chetah, Acinonyx jubatus");
}

TEST_F(LabelsGeneric, brown_bear_bruin_Ursus_arctos) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 295), 295);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 295), "brown bear, bruin, Ursus arctos");
}

TEST_F(LabelsGeneric, American_black_bear_black_bear_Ursus_americanus_Euarctos_americanus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 296), 296);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 296), "American black bear, black bear, Ursus americanus, Euarctos americanus");
}

TEST_F(LabelsGeneric, ice_bear_polar_bear_Ursus_Maritimus_Thalarctos_maritimus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 297), 297);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 297), "ice bear, polar bear, Ursus Maritimus, Thalarctos maritimus");
}

TEST_F(LabelsGeneric, sloth_bear_Melursus_ursinus_Ursus_ursinus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 298), 298);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 298), "sloth bear, Melursus ursinus, Ursus ursinus");
}

TEST_F(LabelsGeneric, mongoose) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 299), 299);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 299), "mongoose");
}

TEST_F(LabelsGeneric, meerkat_mierkat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 300), 300);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 300), "meerkat, mierkat");
}

TEST_F(LabelsGeneric, tiger_beetle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 301), 301);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 301), "tiger beetle");
}

TEST_F(LabelsGeneric, ladybug_ladybeetle_lady_beetle_ladybird_ladybird_beetle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 302), 302);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 302), "ladybug, ladybeetle, lady beetle, ladybird, ladybird beetle");
}

TEST_F(LabelsGeneric, ground_beetle_carabid_beetle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 303), 303);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 303), "ground beetle, carabid beetle");
}

TEST_F(LabelsGeneric, long_horned_beetle_longicorn_longicorn_beetle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 304), 304);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 304), "long-horned beetle, longicorn, longicorn beetle");
}

TEST_F(LabelsGeneric, leaf_beetle_chrysomelid) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 305), 305);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 305), "leaf beetle, chrysomelid");
}

TEST_F(LabelsGeneric, dung_beetle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 306), 306);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 306), "dung beetle");
}

TEST_F(LabelsGeneric, rhinoceros_beetle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 307), 307);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 307), "rhinoceros beetle");
}

TEST_F(LabelsGeneric, weevil) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 308), 308);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 308), "weevil");
}

TEST_F(LabelsGeneric, fly) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 309), 309);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 309), "fly");
}

TEST_F(LabelsGeneric, bee) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 310), 310);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 310), "bee");
}

TEST_F(LabelsGeneric, ant_emmet_pismire) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 311), 311);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 311), "ant, emmet, pismire");
}

TEST_F(LabelsGeneric, grasshopper_hopper) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 312), 312);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 312), "grasshopper, hopper");
}

TEST_F(LabelsGeneric, cricket) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 313), 313);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 313), "cricket");
}

TEST_F(LabelsGeneric, walking_stick_walkingstick_stick_insect) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 314), 314);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 314), "walking stick, walkingstick, stick insect");
}

TEST_F(LabelsGeneric, cockroach_roach) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 315), 315);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 315), "cockroach, roach");
}

TEST_F(LabelsGeneric, mantis_mantid) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 316), 316);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 316), "mantis, mantid");
}

TEST_F(LabelsGeneric, cicada_cicala) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 317), 317);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 317), "cicada, cicala");
}

TEST_F(LabelsGeneric, leafhopper) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 318), 318);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 318), "leafhopper");
}

TEST_F(LabelsGeneric, lacewing_lacewing_fly) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 319), 319);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 319), "lacewing, lacewing fly");
}

TEST_F(LabelsGeneric, dragonfly_darning_needle_devil_s_darning_needle_sewing_needle_snake_feeder_snake_doctor_mosquito_hawk_skeeter_hawk) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 320), 320);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 320), "dragonfly, darning needle, devil's darning needle, sewing needle, snake feeder, snake doctor, mosquito hawk, skeeter hawk");
}

TEST_F(LabelsGeneric, damselfly) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 321), 321);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 321), "damselfly");
}

TEST_F(LabelsGeneric, admiral) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 322), 322);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 322), "admiral");
}

TEST_F(LabelsGeneric, ringlet_ringlet_butterfly) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 323), 323);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 323), "ringlet, ringlet butterfly");
}

TEST_F(LabelsGeneric, monarch_monarch_butterfly_milkweed_butterfly_Danaus_plexippus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 324), 324);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 324), "monarch, monarch butterfly, milkweed butterfly, Danaus plexippus");
}

TEST_F(LabelsGeneric, cabbage_butterfly) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 325), 325);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 325), "cabbage butterfly");
}

TEST_F(LabelsGeneric, sulphur_butterfly_sulfur_butterfly) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 326), 326);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 326), "sulphur butterfly, sulfur butterfly");
}

TEST_F(LabelsGeneric, lycaenid_lycaenid_butterfly) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 327), 327);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 327), "lycaenid, lycaenid butterfly");
}

TEST_F(LabelsGeneric, starfish_sea_star) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 328), 328);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 328), "starfish, sea star");
}

TEST_F(LabelsGeneric, sea_urchin) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 329), 329);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 329), "sea urchin");
}

TEST_F(LabelsGeneric, sea_cucumber_holothurian) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 330), 330);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 330), "sea cucumber, holothurian");
}

TEST_F(LabelsGeneric, wood_rabbit_cottontail_cottontail_rabbit) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 331), 331);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 331), "wood rabbit, cottontail, cottontail rabbit");
}

TEST_F(LabelsGeneric, hare) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 332), 332);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 332), "hare");
}

TEST_F(LabelsGeneric, Angora_Angora_rabbit) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 333), 333);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 333), "Angora, Angora rabbit");
}

TEST_F(LabelsGeneric, hamster) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 334), 334);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 334), "hamster");
}

TEST_F(LabelsGeneric, porcupine_hedgehog) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 335), 335);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 335), "porcupine, hedgehog");
}

TEST_F(LabelsGeneric, fox_squirrel_eastern_fox_squirrel_Sciurus_niger) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 336), 336);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 336), "fox squirrel, eastern fox squirrel, Sciurus niger");
}

TEST_F(LabelsGeneric, marmot) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 337), 337);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 337), "marmot");
}

TEST_F(LabelsGeneric, beaver) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 338), 338);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 338), "beaver");
}

TEST_F(LabelsGeneric, guinea_pig_Cavia_cobaya) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 339), 339);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 339), "guinea pig, Cavia cobaya");
}

TEST_F(LabelsGeneric, sorrel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 340), 340);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 340), "sorrel");
}

TEST_F(LabelsGeneric, zebra) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 341), 341);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 341), "zebra");
}

TEST_F(LabelsGeneric, hog_pig_grunter_squealer_Sus_scrofa) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 342), 342);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 342), "hog, pig, grunter, squealer, Sus scrofa");
}

TEST_F(LabelsGeneric, wild_boar_boar_Sus_scrofa) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 343), 343);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 343), "wild boar, boar, Sus scrofa");
}

TEST_F(LabelsGeneric, warthog) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 344), 344);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 344), "warthog");
}

TEST_F(LabelsGeneric, hippopotamus_hippo_river_horse_Hippopotamus_amphibius) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 345), 345);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 345), "hippopotamus, hippo, river horse, Hippopotamus amphibius");
}

TEST_F(LabelsGeneric, ox) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 346), 346);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 346), "ox");
}

TEST_F(LabelsGeneric, water_buffalo_water_ox_Asiatic_buffalo_Bubalus_bubalis) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 347), 347);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 347), "water buffalo, water ox, Asiatic buffalo, Bubalus bubalis");
}

TEST_F(LabelsGeneric, bison) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 348), 348);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 348), "bison");
}

TEST_F(LabelsGeneric, ram_tup) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 349), 349);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 349), "ram, tup");
}

TEST_F(LabelsGeneric, bighorn_bighorn_sheep_cimarron_Rocky_Mountain_bighorn_Rocky_Mountain_sheep_Ovis_canadensis) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 350), 350);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 350), "bighorn, bighorn sheep, cimarron, Rocky Mountain bighorn, Rocky Mountain sheep, Ovis canadensis");
}

TEST_F(LabelsGeneric, ibex_Capra_ibex) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 351), 351);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 351), "ibex, Capra ibex");
}

TEST_F(LabelsGeneric, hartebeest) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 352), 352);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 352), "hartebeest");
}

TEST_F(LabelsGeneric, impala_Aepyceros_melampus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 353), 353);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 353), "impala, Aepyceros melampus");
}

TEST_F(LabelsGeneric, gazelle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 354), 354);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 354), "gazelle");
}

TEST_F(LabelsGeneric, Arabian_camel_dromedary_Camelus_dromedarius) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 355), 355);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 355), "Arabian camel, dromedary, Camelus dromedarius");
}

TEST_F(LabelsGeneric, llama) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 356), 356);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 356), "llama");
}

TEST_F(LabelsGeneric, weasel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 357), 357);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 357), "weasel");
}

TEST_F(LabelsGeneric, mink) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 358), 358);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 358), "mink");
}

TEST_F(LabelsGeneric, polecat_fitch_foulmart_foumart_Mustela_putorius) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 359), 359);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 359), "polecat, fitch, foulmart, foumart, Mustela putorius");
}

TEST_F(LabelsGeneric, black_footed_ferret_ferret_Mustela_nigripes) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 360), 360);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 360), "black-footed ferret, ferret, Mustela nigripes");
}

TEST_F(LabelsGeneric, otter) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 361), 361);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 361), "otter");
}

TEST_F(LabelsGeneric, skunk_polecat_wood_pussy) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 362), 362);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 362), "skunk, polecat, wood pussy");
}

TEST_F(LabelsGeneric, badger) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 363), 363);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 363), "badger");
}

TEST_F(LabelsGeneric, armadillo) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 364), 364);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 364), "armadillo");
}

TEST_F(LabelsGeneric, three_toed_sloth_ai_Bradypus_tridactylus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 365), 365);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 365), "three-toed sloth, ai, Bradypus tridactylus");
}

TEST_F(LabelsGeneric, orangutan_orang_orangutang_Pongo_pygmaeus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 366), 366);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 366), "orangutan, orang, orangutang, Pongo pygmaeus");
}

TEST_F(LabelsGeneric, gorilla_Gorilla_gorilla) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 367), 367);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 367), "gorilla, Gorilla gorilla");
}

TEST_F(LabelsGeneric, chimpanzee_chimp_Pan_troglodytes) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 368), 368);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 368), "chimpanzee, chimp, Pan troglodytes");
}

TEST_F(LabelsGeneric, gibbon_Hylobates_lar) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 369), 369);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 369), "gibbon, Hylobates lar");
}

TEST_F(LabelsGeneric, siamang_Hylobates_syndactylus_Symphalangus_syndactylus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 370), 370);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 370), "siamang, Hylobates syndactylus, Symphalangus syndactylus");
}

TEST_F(LabelsGeneric, guenon_guenon_monkey) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 371), 371);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 371), "guenon, guenon monkey");
}

TEST_F(LabelsGeneric, patas_hussar_monkey_Erythrocebus_patas) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 372), 372);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 372), "patas, hussar monkey, Erythrocebus patas");
}

TEST_F(LabelsGeneric, baboon) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 373), 373);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 373), "baboon");
}

TEST_F(LabelsGeneric, macaque) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 374), 374);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 374), "macaque");
}

TEST_F(LabelsGeneric, langur) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 375), 375);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 375), "langur");
}

TEST_F(LabelsGeneric, colobus_colobus_monkey) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 376), 376);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 376), "colobus, colobus monkey");
}

TEST_F(LabelsGeneric, proboscis_monkey_Nasalis_larvatus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 377), 377);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 377), "proboscis monkey, Nasalis larvatus");
}

TEST_F(LabelsGeneric, marmoset) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 378), 378);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 378), "marmoset");
}

TEST_F(LabelsGeneric, capuchin_ringtail_Cebus_capucinus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 379), 379);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 379), "capuchin, ringtail, Cebus capucinus");
}

TEST_F(LabelsGeneric, howler_monkey_howler) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 380), 380);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 380), "howler monkey, howler");
}

TEST_F(LabelsGeneric, titi_titi_monkey) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 381), 381);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 381), "titi, titi monkey");
}

TEST_F(LabelsGeneric, spider_monkey_Ateles_geoffroyi) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 382), 382);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 382), "spider monkey, Ateles geoffroyi");
}

TEST_F(LabelsGeneric, squirrel_monkey_Saimiri_sciureus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 383), 383);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 383), "squirrel monkey, Saimiri sciureus");
}

TEST_F(LabelsGeneric, Madagascar_cat_ring_tailed_lemur_Lemur_catta) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 384), 384);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 384), "Madagascar cat, ring-tailed lemur, Lemur catta");
}

TEST_F(LabelsGeneric, indri_indris_Indri_indri_Indri_brevicaudatus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 385), 385);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 385), "indri, indris, Indri indri, Indri brevicaudatus");
}

TEST_F(LabelsGeneric, Indian_elephant_Elephas_maximus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 386), 386);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 386), "Indian elephant, Elephas maximus");
}

TEST_F(LabelsGeneric, African_elephant_Loxodonta_africana) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 387), 387);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 387), "African elephant, Loxodonta africana");
}

TEST_F(LabelsGeneric, lesser_panda_red_panda_panda_bear_cat_cat_bear_Ailurus_fulgens) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 388), 388);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 388), "lesser panda, red panda, panda, bear cat, cat bear, Ailurus fulgens");
}

TEST_F(LabelsGeneric, giant_panda_panda_panda_bear_coon_bear_Ailuropoda_melanoleuca) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 389), 389);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 389), "giant panda, panda, panda bear, coon bear, Ailuropoda melanoleuca");
}

TEST_F(LabelsGeneric, barracouta_snoek) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 390), 390);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 390), "barracouta, snoek");
}

TEST_F(LabelsGeneric, eel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 391), 391);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 391), "eel");
}

TEST_F(LabelsGeneric, coho_cohoe_coho_salmon_blue_jack_silver_salmon_Oncorhynchus_kisutch) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 392), 392);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 392), "coho, cohoe, coho salmon, blue jack, silver salmon, Oncorhynchus kisutch");
}

TEST_F(LabelsGeneric, rock_beauty_Holocanthus_tricolor) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 393), 393);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 393), "rock beauty, Holocanthus tricolor");
}

TEST_F(LabelsGeneric, anemone_fish) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 394), 394);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 394), "anemone fish");
}

TEST_F(LabelsGeneric, sturgeon) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 395), 395);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 395), "sturgeon");
}

TEST_F(LabelsGeneric, gar_garfish_garpike_billfish_Lepisosteus_osseus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 396), 396);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 396), "gar, garfish, garpike, billfish, Lepisosteus osseus");
}

TEST_F(LabelsGeneric, lionfish) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 397), 397);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 397), "lionfish");
}

TEST_F(LabelsGeneric, puffer_pufferfish_blowfish_globefish) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 398), 398);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 398), "puffer, pufferfish, blowfish, globefish");
}

TEST_F(LabelsGeneric, abacus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 399), 399);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 399), "abacus");
}

TEST_F(LabelsGeneric, abaya) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 400), 400);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 400), "abaya");
}

TEST_F(LabelsGeneric, academic_gown_academic_robe_judge_s_robe) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 401), 401);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 401), "academic gown, academic robe, judge's robe");
}

TEST_F(LabelsGeneric, accordion_piano_accordion_squeeze_box) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 402), 402);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 402), "accordion, piano accordion, squeeze box");
}

TEST_F(LabelsGeneric, acoustic_guitar) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 403), 403);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 403), "acoustic guitar");
}

TEST_F(LabelsGeneric, aircraft_carrier_carrier_flattop_attack_aircraft_carrier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 404), 404);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 404), "aircraft carrier, carrier, flattop, attack aircraft carrier");
}

TEST_F(LabelsGeneric, airliner) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 405), 405);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 405), "airliner");
}

TEST_F(LabelsGeneric, airship_dirigible) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 406), 406);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 406), "airship, dirigible");
}

TEST_F(LabelsGeneric, altar) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 407), 407);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 407), "altar");
}

TEST_F(LabelsGeneric, ambulance) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 408), 408);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 408), "ambulance");
}

TEST_F(LabelsGeneric, amphibian_amphibious_vehicle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 409), 409);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 409), "amphibian, amphibious vehicle");
}

TEST_F(LabelsGeneric, analog_clock) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 410), 410);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 410), "analog clock");
}

TEST_F(LabelsGeneric, apiary_bee_house) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 411), 411);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 411), "apiary, bee house");
}

TEST_F(LabelsGeneric, apron) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 412), 412);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 412), "apron");
}

TEST_F(LabelsGeneric, ashcan_trash_can_garbage_can_wastebin_ash_bin_ash_bin_ashbin_dustbin_trash_barrel_trash_bin) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 413), 413);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 413), "ashcan, trash can, garbage can, wastebin, ash bin, ash-bin, ashbin, dustbin, trash barrel, trash bin");
}

TEST_F(LabelsGeneric, assault_rifle_assault_gun) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 414), 414);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 414), "assault rifle, assault gun");
}

TEST_F(LabelsGeneric, backpack_back_pack_knapsack_packsack_rucksack_haversack) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 415), 415);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 415), "backpack, back pack, knapsack, packsack, rucksack, haversack");
}

TEST_F(LabelsGeneric, bakery_bakeshop_bakehouse) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 416), 416);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 416), "bakery, bakeshop, bakehouse");
}

TEST_F(LabelsGeneric, balance_beam_beam) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 417), 417);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 417), "balance beam, beam");
}

TEST_F(LabelsGeneric, balloon) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 418), 418);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 418), "balloon");
}

TEST_F(LabelsGeneric, ballpoint_ballpoint_pen_ballpen_Biro) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 419), 419);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 419), "ballpoint, ballpoint pen, ballpen, Biro");
}

TEST_F(LabelsGeneric, Band_Aid) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 420), 420);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 420), "Band Aid");
}

TEST_F(LabelsGeneric, banjo) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 421), 421);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 421), "banjo");
}

TEST_F(LabelsGeneric, bannister_banister_balustrade_balusters_handrail) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 422), 422);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 422), "bannister, banister, balustrade, balusters, handrail");
}

TEST_F(LabelsGeneric, barbell) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 423), 423);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 423), "barbell");
}

TEST_F(LabelsGeneric, barber_chair) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 424), 424);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 424), "barber chair");
}

TEST_F(LabelsGeneric, barbershop) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 425), 425);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 425), "barbershop");
}

TEST_F(LabelsGeneric, barn) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 426), 426);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 426), "barn");
}

TEST_F(LabelsGeneric, barometer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 427), 427);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 427), "barometer");
}

TEST_F(LabelsGeneric, barrel_cask) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 428), 428);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 428), "barrel, cask");
}

TEST_F(LabelsGeneric, barrow_garden_cart_lawn_cart_wheelbarrow) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 429), 429);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 429), "barrow, garden cart, lawn cart, wheelbarrow");
}

TEST_F(LabelsGeneric, baseball) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 430), 430);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 430), "baseball");
}

TEST_F(LabelsGeneric, basketball) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 431), 431);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 431), "basketball");
}

TEST_F(LabelsGeneric, bassinet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 432), 432);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 432), "bassinet");
}

TEST_F(LabelsGeneric, bassoon) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 433), 433);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 433), "bassoon");
}

TEST_F(LabelsGeneric, bathing_cap_swimming_cap) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 434), 434);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 434), "bathing cap, swimming cap");
}

TEST_F(LabelsGeneric, bath_towel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 435), 435);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 435), "bath towel");
}

TEST_F(LabelsGeneric, bathtub_bathing_tub_bath_tub) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 436), 436);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 436), "bathtub, bathing tub, bath, tub");
}

TEST_F(LabelsGeneric, beach_wagon_station_wagon_wagon_estate_car_beach_waggon_station_waggon_waggon) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 437), 437);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 437), "beach wagon, station wagon, wagon, estate car, beach waggon, station waggon, waggon");
}

TEST_F(LabelsGeneric, beacon_lighthouse_beacon_light_pharos) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 438), 438);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 438), "beacon, lighthouse, beacon light, pharos");
}

TEST_F(LabelsGeneric, beaker) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 439), 439);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 439), "beaker");
}

TEST_F(LabelsGeneric, bearskin_busby_shako) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 440), 440);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 440), "bearskin, busby, shako");
}

TEST_F(LabelsGeneric, beer_bottle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 441), 441);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 441), "beer bottle");
}

TEST_F(LabelsGeneric, beer_glass) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 442), 442);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 442), "beer glass");
}

TEST_F(LabelsGeneric, bell_cote_bell_cot) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 443), 443);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 443), "bell cote, bell cot");
}

TEST_F(LabelsGeneric, bib) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 444), 444);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 444), "bib");
}

TEST_F(LabelsGeneric, bicycle_built_for_two_tandem_bicycle_tandem) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 445), 445);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 445), "bicycle-built-for-two, tandem bicycle, tandem");
}

TEST_F(LabelsGeneric, bikini_two_piece) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 446), 446);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 446), "bikini, two-piece");
}

TEST_F(LabelsGeneric, binder_ring_binder) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 447), 447);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 447), "binder, ring-binder");
}

TEST_F(LabelsGeneric, binoculars_field_glasses_opera_glasses) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 448), 448);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 448), "binoculars, field glasses, opera glasses");
}

TEST_F(LabelsGeneric, birdhouse) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 449), 449);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 449), "birdhouse");
}

TEST_F(LabelsGeneric, boathouse) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 450), 450);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 450), "boathouse");
}

TEST_F(LabelsGeneric, bobsled_bobsleigh_bob) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 451), 451);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 451), "bobsled, bobsleigh, bob");
}

TEST_F(LabelsGeneric, bolo_tie_bolo_bola_tie_bola) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 452), 452);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 452), "bolo tie, bolo, bola tie, bola");
}

TEST_F(LabelsGeneric, bonnet_poke_bonnet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 453), 453);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 453), "bonnet, poke bonnet");
}

TEST_F(LabelsGeneric, bookcase) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 454), 454);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 454), "bookcase");
}

TEST_F(LabelsGeneric, bookshop_bookstore_bookstall) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 455), 455);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 455), "bookshop, bookstore, bookstall");
}

TEST_F(LabelsGeneric, bottlecap) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 456), 456);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 456), "bottlecap");
}

TEST_F(LabelsGeneric, bow) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 457), 457);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 457), "bow");
}

TEST_F(LabelsGeneric, bow_tie_bow_tie_bowtie) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 458), 458);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 458), "bow tie, bow-tie, bowtie");
}

TEST_F(LabelsGeneric, brass_memorial_tablet_plaque) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 459), 459);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 459), "brass, memorial tablet, plaque");
}

TEST_F(LabelsGeneric, brassiere_bra_bandeau) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 460), 460);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 460), "brassiere, bra, bandeau");
}

TEST_F(LabelsGeneric, breakwater_groin_groyne_mole_bulwark_seawall_jetty) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 461), 461);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 461), "breakwater, groin, groyne, mole, bulwark, seawall, jetty");
}

TEST_F(LabelsGeneric, breastplate_aegis_egis) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 462), 462);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 462), "breastplate, aegis, egis");
}

TEST_F(LabelsGeneric, broom) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 463), 463);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 463), "broom");
}

TEST_F(LabelsGeneric, bucket_pail) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 464), 464);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 464), "bucket, pail");
}

TEST_F(LabelsGeneric, buckle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 465), 465);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 465), "buckle");
}

TEST_F(LabelsGeneric, bulletproof_vest) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 466), 466);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 466), "bulletproof vest");
}

TEST_F(LabelsGeneric, bullet_train_bullet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 467), 467);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 467), "bullet train, bullet");
}

TEST_F(LabelsGeneric, butcher_shop_meat_market) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 468), 468);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 468), "butcher shop, meat market");
}

TEST_F(LabelsGeneric, cab_hack_taxi_taxicab) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 469), 469);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 469), "cab, hack, taxi, taxicab");
}

TEST_F(LabelsGeneric, caldron_cauldron) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 470), 470);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 470), "caldron, cauldron");
}

TEST_F(LabelsGeneric, candle_taper_wax_light) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 471), 471);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 471), "candle, taper, wax light");
}

TEST_F(LabelsGeneric, cannon) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 472), 472);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 472), "cannon");
}

TEST_F(LabelsGeneric, canoe) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 473), 473);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 473), "canoe");
}

TEST_F(LabelsGeneric, can_opener_tin_opener) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 474), 474);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 474), "can opener, tin opener");
}

TEST_F(LabelsGeneric, cardigan) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 475), 475);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 475), "cardigan");
}

TEST_F(LabelsGeneric, car_mirror) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 476), 476);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 476), "car mirror");
}

TEST_F(LabelsGeneric, carousel_carrousel_merry_go_round_roundabout_whirligig) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 477), 477);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 477), "carousel, carrousel, merry-go-round, roundabout, whirligig");
}

TEST_F(LabelsGeneric, carpenter_s_kit_tool_kit) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 478), 478);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 478), "carpenter's kit, tool kit");
}

TEST_F(LabelsGeneric, carton) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 479), 479);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 479), "carton");
}

TEST_F(LabelsGeneric, car_wheel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 480), 480);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 480), "car wheel");
}

TEST_F(LabelsGeneric, cash_machine_cash_dispenser_automated_teller_machine_automatic_teller_machine_automated_teller_automatic_teller_ATM) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 481), 481);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 481), "cash machine, cash dispenser, automated teller machine, automatic teller machine, automated teller, automatic teller, ATM");
}

TEST_F(LabelsGeneric, cassette) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 482), 482);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 482), "cassette");
}

TEST_F(LabelsGeneric, cassette_player) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 483), 483);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 483), "cassette player");
}

TEST_F(LabelsGeneric, castle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 484), 484);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 484), "castle");
}

TEST_F(LabelsGeneric, catamaran) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 485), 485);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 485), "catamaran");
}

TEST_F(LabelsGeneric, CD_player) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 486), 486);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 486), "CD player");
}

TEST_F(LabelsGeneric, cello_violoncello) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 487), 487);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 487), "cello, violoncello");
}

TEST_F(LabelsGeneric, cellular_telephone_cellular_phone_cellphone_cell_mobile_phone) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 488), 488);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 488), "cellular telephone, cellular phone, cellphone, cell, mobile phone");
}

TEST_F(LabelsGeneric, chain) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 489), 489);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 489), "chain");
}

TEST_F(LabelsGeneric, chainlink_fence) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 490), 490);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 490), "chainlink fence");
}

TEST_F(LabelsGeneric, chain_mail_ring_mail_mail_chain_armor_chain_armour_ring_armor_ring_armour) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 491), 491);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 491), "chain mail, ring mail, mail, chain armor, chain armour, ring armor, ring armour");
}

TEST_F(LabelsGeneric, chain_saw_chainsaw) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 492), 492);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 492), "chain saw, chainsaw");
}

TEST_F(LabelsGeneric, chest) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 493), 493);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 493), "chest");
}

TEST_F(LabelsGeneric, chiffonier_commode) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 494), 494);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 494), "chiffonier, commode");
}

TEST_F(LabelsGeneric, chime_bell_gong) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 495), 495);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 495), "chime, bell, gong");
}

TEST_F(LabelsGeneric, china_cabinet_china_closet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 496), 496);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 496), "china cabinet, china closet");
}

TEST_F(LabelsGeneric, Christmas_stocking) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 497), 497);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 497), "Christmas stocking");
}

TEST_F(LabelsGeneric, church_church_building) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 498), 498);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 498), "church, church building");
}

TEST_F(LabelsGeneric, cinema_movie_theater_movie_theatre_movie_house_picture_palace) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 499), 499);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 499), "cinema, movie theater, movie theatre, movie house, picture palace");
}

TEST_F(LabelsGeneric, cleaver_meat_cleaver_chopper) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 500), 500);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 500), "cleaver, meat cleaver, chopper");
}

TEST_F(LabelsGeneric, cliff_dwelling) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 501), 501);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 501), "cliff dwelling");
}

TEST_F(LabelsGeneric, cloak) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 502), 502);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 502), "cloak");
}

TEST_F(LabelsGeneric, clog_geta_patten_sabot) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 503), 503);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 503), "clog, geta, patten, sabot");
}

TEST_F(LabelsGeneric, cocktail_shaker) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 504), 504);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 504), "cocktail shaker");
}

TEST_F(LabelsGeneric, coffee_mug) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 505), 505);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 505), "coffee mug");
}

TEST_F(LabelsGeneric, coffeepot) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 506), 506);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 506), "coffeepot");
}

TEST_F(LabelsGeneric, coil_spiral_volute_whorl_helix) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 507), 507);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 507), "coil, spiral, volute, whorl, helix");
}

TEST_F(LabelsGeneric, combination_lock) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 508), 508);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 508), "combination lock");
}

TEST_F(LabelsGeneric, computer_keyboard_keypad) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 509), 509);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 509), "computer keyboard, keypad");
}

TEST_F(LabelsGeneric, confectionery_confectionary_candy_store) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 510), 510);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 510), "confectionery, confectionary, candy store");
}

TEST_F(LabelsGeneric, container_ship_containership_container_vessel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 511), 511);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 511), "container ship, containership, container vessel");
}

TEST_F(LabelsGeneric, convertible) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 512), 512);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 512), "convertible");
}

TEST_F(LabelsGeneric, corkscrew_bottle_screw) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 513), 513);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 513), "corkscrew, bottle screw");
}

TEST_F(LabelsGeneric, cornet_horn_trumpet_trump) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 514), 514);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 514), "cornet, horn, trumpet, trump");
}

TEST_F(LabelsGeneric, cowboy_boot) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 515), 515);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 515), "cowboy boot");
}

TEST_F(LabelsGeneric, cowboy_hat_ten_gallon_hat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 516), 516);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 516), "cowboy hat, ten-gallon hat");
}

TEST_F(LabelsGeneric, cradle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 517), 517);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 517), "cradle");
}

TEST_F(LabelsGeneric, crane2) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 518), 518);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 518), "crane");
}

TEST_F(LabelsGeneric, crash_helmet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 519), 519);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 519), "crash helmet");
}

TEST_F(LabelsGeneric, crate) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 520), 520);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 520), "crate");
}

TEST_F(LabelsGeneric, crib_cot) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 521), 521);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 521), "crib, cot");
}

TEST_F(LabelsGeneric, Crock_Pot) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 522), 522);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 522), "Crock Pot");
}

TEST_F(LabelsGeneric, croquet_ball) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 523), 523);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 523), "croquet ball");
}

TEST_F(LabelsGeneric, crutch) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 524), 524);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 524), "crutch");
}

TEST_F(LabelsGeneric, cuirass) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 525), 525);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 525), "cuirass");
}

TEST_F(LabelsGeneric, dam_dike_dyke) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 526), 526);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 526), "dam, dike, dyke");
}

TEST_F(LabelsGeneric, desk) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 527), 527);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 527), "desk");
}

TEST_F(LabelsGeneric, desktop_computer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 528), 528);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 528), "desktop computer");
}

TEST_F(LabelsGeneric, dial_telephone_dial_phone) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 529), 529);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 529), "dial telephone, dial phone");
}

TEST_F(LabelsGeneric, diaper_nappy_napkin) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 530), 530);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 530), "diaper, nappy, napkin");
}

TEST_F(LabelsGeneric, digital_clock) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 531), 531);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 531), "digital clock");
}

TEST_F(LabelsGeneric, digital_watch) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 532), 532);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 532), "digital watch");
}

TEST_F(LabelsGeneric, dining_table_board) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 533), 533);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 533), "dining table, board");
}

TEST_F(LabelsGeneric, dishrag_dishcloth) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 534), 534);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 534), "dishrag, dishcloth");
}

TEST_F(LabelsGeneric, dishwasher_dish_washer_dishwashing_machine) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 535), 535);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 535), "dishwasher, dish washer, dishwashing machine");
}

TEST_F(LabelsGeneric, disk_brake_disc_brake) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 536), 536);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 536), "disk brake, disc brake");
}

TEST_F(LabelsGeneric, dock_dockage_docking_facility) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 537), 537);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 537), "dock, dockage, docking facility");
}

TEST_F(LabelsGeneric, dogsled_dog_sled_dog_sleigh) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 538), 538);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 538), "dogsled, dog sled, dog sleigh");
}

TEST_F(LabelsGeneric, dome) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 539), 539);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 539), "dome");
}

TEST_F(LabelsGeneric, doormat_welcome_mat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 540), 540);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 540), "doormat, welcome mat");
}

TEST_F(LabelsGeneric, drilling_platform_offshore_rig) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 541), 541);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 541), "drilling platform, offshore rig");
}

TEST_F(LabelsGeneric, drum_membranophone_tympan) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 542), 542);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 542), "drum, membranophone, tympan");
}

TEST_F(LabelsGeneric, drumstick) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 543), 543);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 543), "drumstick");
}

TEST_F(LabelsGeneric, dumbbell) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 544), 544);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 544), "dumbbell");
}

TEST_F(LabelsGeneric, Dutch_oven) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 545), 545);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 545), "Dutch oven");
}

TEST_F(LabelsGeneric, electric_fan_blower) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 546), 546);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 546), "electric fan, blower");
}

TEST_F(LabelsGeneric, electric_guitar) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 547), 547);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 547), "electric guitar");
}

TEST_F(LabelsGeneric, electric_locomotive) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 548), 548);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 548), "electric locomotive");
}

TEST_F(LabelsGeneric, entertainment_center) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 549), 549);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 549), "entertainment center");
}

TEST_F(LabelsGeneric, envelope) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 550), 550);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 550), "envelope");
}

TEST_F(LabelsGeneric, espresso_maker) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 551), 551);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 551), "espresso maker");
}

TEST_F(LabelsGeneric, face_powder) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 552), 552);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 552), "face powder");
}

TEST_F(LabelsGeneric, feather_boa_boa) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 553), 553);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 553), "feather boa, boa");
}

TEST_F(LabelsGeneric, file_file_cabinet_filing_cabinet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 554), 554);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 554), "file, file cabinet, filing cabinet");
}

TEST_F(LabelsGeneric, fireboat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 555), 555);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 555), "fireboat");
}

TEST_F(LabelsGeneric, fire_engine_fire_truck) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 556), 556);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 556), "fire engine, fire truck");
}

TEST_F(LabelsGeneric, fire_screen_fireguard) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 557), 557);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 557), "fire screen, fireguard");
}

TEST_F(LabelsGeneric, flagpole_flagstaff) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 558), 558);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 558), "flagpole, flagstaff");
}

TEST_F(LabelsGeneric, flute_transverse_flute) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 559), 559);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 559), "flute, transverse flute");
}

TEST_F(LabelsGeneric, folding_chair) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 560), 560);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 560), "folding chair");
}

TEST_F(LabelsGeneric, football_helmet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 561), 561);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 561), "football helmet");
}

TEST_F(LabelsGeneric, forklift) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 562), 562);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 562), "forklift");
}

TEST_F(LabelsGeneric, fountain) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 563), 563);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 563), "fountain");
}

TEST_F(LabelsGeneric, fountain_pen) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 564), 564);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 564), "fountain pen");
}

TEST_F(LabelsGeneric, four_poster) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 565), 565);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 565), "four-poster");
}

TEST_F(LabelsGeneric, freight_car) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 566), 566);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 566), "freight car");
}

TEST_F(LabelsGeneric, French_horn_horn) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 567), 567);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 567), "French horn, horn");
}

TEST_F(LabelsGeneric, frying_pan_frypan_skillet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 568), 568);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 568), "frying pan, frypan, skillet");
}

TEST_F(LabelsGeneric, fur_coat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 569), 569);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 569), "fur coat");
}

TEST_F(LabelsGeneric, garbage_truck_dustcart) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 570), 570);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 570), "garbage truck, dustcart");
}

TEST_F(LabelsGeneric, gasmask_respirator_gas_helmet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 571), 571);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 571), "gasmask, respirator, gas helmet");
}

TEST_F(LabelsGeneric, gas_pump_gasoline_pump_petrol_pump_island_dispenser) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 572), 572);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 572), "gas pump, gasoline pump, petrol pump, island dispenser");
}

TEST_F(LabelsGeneric, goblet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 573), 573);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 573), "goblet");
}

TEST_F(LabelsGeneric, go_kart) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 574), 574);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 574), "go-kart");
}

TEST_F(LabelsGeneric, golf_ball) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 575), 575);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 575), "golf ball");
}

TEST_F(LabelsGeneric, golfcart_golf_cart) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 576), 576);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 576), "golfcart, golf cart");
}

TEST_F(LabelsGeneric, gondola) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 577), 577);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 577), "gondola");
}

TEST_F(LabelsGeneric, gong_tam_tam) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 578), 578);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 578), "gong, tam-tam");
}

TEST_F(LabelsGeneric, gown) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 579), 579);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 579), "gown");
}

TEST_F(LabelsGeneric, grand_piano_grand) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 580), 580);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 580), "grand piano, grand");
}

TEST_F(LabelsGeneric, greenhouse_nursery_glasshouse) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 581), 581);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 581), "greenhouse, nursery, glasshouse");
}

TEST_F(LabelsGeneric, grille_radiator_grille) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 582), 582);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 582), "grille, radiator grille");
}

TEST_F(LabelsGeneric, grocery_store_grocery_food_market_market) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 583), 583);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 583), "grocery store, grocery, food market, market");
}

TEST_F(LabelsGeneric, guillotine) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 584), 584);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 584), "guillotine");
}

TEST_F(LabelsGeneric, hair_slide) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 585), 585);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 585), "hair slide");
}

TEST_F(LabelsGeneric, hair_spray) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 586), 586);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 586), "hair spray");
}

TEST_F(LabelsGeneric, half_track) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 587), 587);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 587), "half track");
}

TEST_F(LabelsGeneric, hammer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 588), 588);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 588), "hammer");
}

TEST_F(LabelsGeneric, hamper) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 589), 589);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 589), "hamper");
}

TEST_F(LabelsGeneric, hand_blower_blow_dryer_blow_drier_hair_dryer_hair_drier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 590), 590);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 590), "hand blower, blow dryer, blow drier, hair dryer, hair drier");
}

TEST_F(LabelsGeneric, hand_held_computer_hand_held_microcomputer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 591), 591);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 591), "hand-held computer, hand-held microcomputer");
}

TEST_F(LabelsGeneric, handkerchief_hankie_hanky_hankey) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 592), 592);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 592), "handkerchief, hankie, hanky, hankey");
}

TEST_F(LabelsGeneric, hard_disc_hard_disk_fixed_disk) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 593), 593);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 593), "hard disc, hard disk, fixed disk");
}

TEST_F(LabelsGeneric, harmonica_mouth_organ_harp_mouth_harp) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 594), 594);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 594), "harmonica, mouth organ, harp, mouth harp");
}

TEST_F(LabelsGeneric, harp) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 595), 595);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 595), "harp");
}

TEST_F(LabelsGeneric, harvester_reaper) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 596), 596);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 596), "harvester, reaper");
}

TEST_F(LabelsGeneric, hatchet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 597), 597);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 597), "hatchet");
}

TEST_F(LabelsGeneric, holster) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 598), 598);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 598), "holster");
}

TEST_F(LabelsGeneric, home_theater_home_theatre) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 599), 599);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 599), "home theater, home theatre");
}

TEST_F(LabelsGeneric, honeycomb) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 600), 600);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 600), "honeycomb");
}

TEST_F(LabelsGeneric, hook_claw) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 601), 601);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 601), "hook, claw");
}

TEST_F(LabelsGeneric, hoopskirt_crinoline) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 602), 602);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 602), "hoopskirt, crinoline");
}

TEST_F(LabelsGeneric, horizontal_bar_high_bar) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 603), 603);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 603), "horizontal bar, high bar");
}

TEST_F(LabelsGeneric, horse_cart_horse_cart) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 604), 604);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 604), "horse cart, horse-cart");
}

TEST_F(LabelsGeneric, hourglass) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 605), 605);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 605), "hourglass");
}

TEST_F(LabelsGeneric, iPod) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 606), 606);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 606), "iPod");
}

TEST_F(LabelsGeneric, iron_smoothing_iron) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 607), 607);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 607), "iron, smoothing iron");
}

TEST_F(LabelsGeneric, jack_o_lantern) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 608), 608);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 608), "jack-o'-lantern");
}

TEST_F(LabelsGeneric, jean_blue_jean_denim) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 609), 609);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 609), "jean, blue jean, denim");
}

TEST_F(LabelsGeneric, jeep_landrover) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 610), 610);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 610), "jeep, landrover");
}

TEST_F(LabelsGeneric, jersey_T_shirt_tee_shirt) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 611), 611);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 611), "jersey, T-shirt, tee shirt");
}

TEST_F(LabelsGeneric, jigsaw_puzzle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 612), 612);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 612), "jigsaw puzzle");
}

TEST_F(LabelsGeneric, jinrikisha_ricksha_rickshaw) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 613), 613);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 613), "jinrikisha, ricksha, rickshaw");
}

TEST_F(LabelsGeneric, joystick) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 614), 614);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 614), "joystick");
}

TEST_F(LabelsGeneric, kimono) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 615), 615);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 615), "kimono");
}

TEST_F(LabelsGeneric, knee_pad) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 616), 616);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 616), "knee pad");
}

TEST_F(LabelsGeneric, knot) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 617), 617);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 617), "knot");
}

TEST_F(LabelsGeneric, lab_coat_laboratory_coat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 618), 618);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 618), "lab coat, laboratory coat");
}

TEST_F(LabelsGeneric, ladle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 619), 619);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 619), "ladle");
}

TEST_F(LabelsGeneric, lampshade_lamp_shade) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 620), 620);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 620), "lampshade, lamp shade");
}

TEST_F(LabelsGeneric, laptop_laptop_computer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 621), 621);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 621), "laptop, laptop computer");
}

TEST_F(LabelsGeneric, lawn_mower_mower) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 622), 622);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 622), "lawn mower, mower");
}

TEST_F(LabelsGeneric, lens_cap_lens_cover) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 623), 623);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 623), "lens cap, lens cover");
}

TEST_F(LabelsGeneric, letter_opener_paper_knife_paperknife) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 624), 624);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 624), "letter opener, paper knife, paperknife");
}

TEST_F(LabelsGeneric, library) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 625), 625);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 625), "library");
}

TEST_F(LabelsGeneric, lifeboat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 626), 626);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 626), "lifeboat");
}

TEST_F(LabelsGeneric, lighter_light_igniter_ignitor) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 627), 627);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 627), "lighter, light, igniter, ignitor");
}

TEST_F(LabelsGeneric, limousine_limo) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 628), 628);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 628), "limousine, limo");
}

TEST_F(LabelsGeneric, liner_ocean_liner) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 629), 629);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 629), "liner, ocean liner");
}

TEST_F(LabelsGeneric, lipstick_lip_rouge) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 630), 630);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 630), "lipstick, lip rouge");
}

TEST_F(LabelsGeneric, Loafer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 631), 631);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 631), "Loafer");
}

TEST_F(LabelsGeneric, lotion) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 632), 632);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 632), "lotion");
}

TEST_F(LabelsGeneric, loudspeaker_speaker_speaker_unit_loudspeaker_system_speaker_system) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 633), 633);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 633), "loudspeaker, speaker, speaker unit, loudspeaker system, speaker system");
}

TEST_F(LabelsGeneric, loupe_jeweler_s_loupe) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 634), 634);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 634), "loupe, jeweler's loupe");
}

TEST_F(LabelsGeneric, lumbermill_sawmill) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 635), 635);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 635), "lumbermill, sawmill");
}

TEST_F(LabelsGeneric, magnetic_compass) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 636), 636);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 636), "magnetic compass");
}

TEST_F(LabelsGeneric, mailbag_postbag) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 637), 637);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 637), "mailbag, postbag");
}

TEST_F(LabelsGeneric, mailbox_letter_box) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 638), 638);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 638), "mailbox, letter box");
}

TEST_F(LabelsGeneric, maillot) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 639), 639);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 639), "maillot");
}

TEST_F(LabelsGeneric, maillot_tank_suit) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 640), 640);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 640), "maillot, tank suit");
}

TEST_F(LabelsGeneric, manhole_cover) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 641), 641);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 641), "manhole cover");
}

TEST_F(LabelsGeneric, maraca) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 642), 642);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 642), "maraca");
}

TEST_F(LabelsGeneric, marimba_xylophone) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 643), 643);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 643), "marimba, xylophone");
}

TEST_F(LabelsGeneric, mask) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 644), 644);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 644), "mask");
}

TEST_F(LabelsGeneric, matchstick) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 645), 645);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 645), "matchstick");
}

TEST_F(LabelsGeneric, maypole) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 646), 646);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 646), "maypole");
}

TEST_F(LabelsGeneric, maze_labyrinth) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 647), 647);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 647), "maze, labyrinth");
}

TEST_F(LabelsGeneric, measuring_cup) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 648), 648);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 648), "measuring cup");
}

TEST_F(LabelsGeneric, medicine_chest_medicine_cabinet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 649), 649);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 649), "medicine chest, medicine cabinet");
}

TEST_F(LabelsGeneric, megalith_megalithic_structure) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 650), 650);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 650), "megalith, megalithic structure");
}

TEST_F(LabelsGeneric, microphone_mike) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 651), 651);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 651), "microphone, mike");
}

TEST_F(LabelsGeneric, microwave_microwave_oven) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 652), 652);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 652), "microwave, microwave oven");
}

TEST_F(LabelsGeneric, military_uniform) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 653), 653);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 653), "military uniform");
}

TEST_F(LabelsGeneric, milk_can) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 654), 654);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 654), "milk can");
}

TEST_F(LabelsGeneric, minibus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 655), 655);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 655), "minibus");
}

TEST_F(LabelsGeneric, miniskirt_mini) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 656), 656);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 656), "miniskirt, mini");
}

TEST_F(LabelsGeneric, minivan) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 657), 657);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 657), "minivan");
}

TEST_F(LabelsGeneric, missile) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 658), 658);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 658), "missile");
}

TEST_F(LabelsGeneric, mitten) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 659), 659);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 659), "mitten");
}

TEST_F(LabelsGeneric, mixing_bowl) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 660), 660);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 660), "mixing bowl");
}

TEST_F(LabelsGeneric, mobile_home_manufactured_home) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 661), 661);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 661), "mobile home, manufactured home");
}

TEST_F(LabelsGeneric, Model_T) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 662), 662);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 662), "Model T");
}

TEST_F(LabelsGeneric, modem) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 663), 663);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 663), "modem");
}

TEST_F(LabelsGeneric, monastery) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 664), 664);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 664), "monastery");
}

TEST_F(LabelsGeneric, monitor) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 665), 665);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 665), "monitor");
}

TEST_F(LabelsGeneric, moped) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 666), 666);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 666), "moped");
}

TEST_F(LabelsGeneric, mortar) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 667), 667);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 667), "mortar");
}

TEST_F(LabelsGeneric, mortarboard) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 668), 668);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 668), "mortarboard");
}

TEST_F(LabelsGeneric, mosque) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 669), 669);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 669), "mosque");
}

TEST_F(LabelsGeneric, mosquito_net) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 670), 670);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 670), "mosquito net");
}

TEST_F(LabelsGeneric, motor_scooter_scooter) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 671), 671);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 671), "motor scooter, scooter");
}

TEST_F(LabelsGeneric, mountain_bike_all_terrain_bike_off_roader) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 672), 672);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 672), "mountain bike, all-terrain bike, off-roader");
}

TEST_F(LabelsGeneric, mountain_tent) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 673), 673);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 673), "mountain tent");
}

TEST_F(LabelsGeneric, mouse_computer_mouse) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 674), 674);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 674), "mouse, computer mouse");
}

TEST_F(LabelsGeneric, mousetrap) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 675), 675);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 675), "mousetrap");
}

TEST_F(LabelsGeneric, moving_van) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 676), 676);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 676), "moving van");
}

TEST_F(LabelsGeneric, muzzle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 677), 677);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 677), "muzzle");
}

TEST_F(LabelsGeneric, nail) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 678), 678);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 678), "nail");
}

TEST_F(LabelsGeneric, neck_brace) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 679), 679);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 679), "neck brace");
}

TEST_F(LabelsGeneric, necklace) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 680), 680);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 680), "necklace");
}

TEST_F(LabelsGeneric, nipple) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 681), 681);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 681), "nipple");
}

TEST_F(LabelsGeneric, notebook_notebook_computer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 682), 682);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 682), "notebook, notebook computer");
}

TEST_F(LabelsGeneric, obelisk) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 683), 683);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 683), "obelisk");
}

TEST_F(LabelsGeneric, oboe_hautboy_hautbois) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 684), 684);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 684), "oboe, hautboy, hautbois");
}

TEST_F(LabelsGeneric, ocarina_sweet_potato) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 685), 685);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 685), "ocarina, sweet potato");
}

TEST_F(LabelsGeneric, odometer_hodometer_mileometer_milometer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 686), 686);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 686), "odometer, hodometer, mileometer, milometer");
}

TEST_F(LabelsGeneric, oil_filter) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 687), 687);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 687), "oil filter");
}

TEST_F(LabelsGeneric, organ_pipe_organ) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 688), 688);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 688), "organ, pipe organ");
}

TEST_F(LabelsGeneric, oscilloscope_scope_cathode_ray_oscilloscope_CRO) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 689), 689);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 689), "oscilloscope, scope, cathode-ray oscilloscope, CRO");
}

TEST_F(LabelsGeneric, overskirt) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 690), 690);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 690), "overskirt");
}

TEST_F(LabelsGeneric, oxcart) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 691), 691);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 691), "oxcart");
}

TEST_F(LabelsGeneric, oxygen_mask) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 692), 692);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 692), "oxygen mask");
}

TEST_F(LabelsGeneric, packet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 693), 693);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 693), "packet");
}

TEST_F(LabelsGeneric, paddle_boat_paddle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 694), 694);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 694), "paddle, boat paddle");
}

TEST_F(LabelsGeneric, paddlewheel_paddle_wheel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 695), 695);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 695), "paddlewheel, paddle wheel");
}

TEST_F(LabelsGeneric, padlock) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 696), 696);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 696), "padlock");
}

TEST_F(LabelsGeneric, paintbrush) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 697), 697);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 697), "paintbrush");
}

TEST_F(LabelsGeneric, pajama_pyjama_pj_s_jammies) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 698), 698);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 698), "pajama, pyjama, pj's, jammies");
}

TEST_F(LabelsGeneric, palace) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 699), 699);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 699), "palace");
}

TEST_F(LabelsGeneric, panpipe_pandean_pipe_syrinx) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 700), 700);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 700), "panpipe, pandean pipe, syrinx");
}

TEST_F(LabelsGeneric, paper_towel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 701), 701);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 701), "paper towel");
}

TEST_F(LabelsGeneric, parachute_chute) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 702), 702);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 702), "parachute, chute");
}

TEST_F(LabelsGeneric, parallel_bars_bars) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 703), 703);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 703), "parallel bars, bars");
}

TEST_F(LabelsGeneric, park_bench) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 704), 704);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 704), "park bench");
}

TEST_F(LabelsGeneric, parking_meter) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 705), 705);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 705), "parking meter");
}

TEST_F(LabelsGeneric, passenger_car_coach_carriage) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 706), 706);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 706), "passenger car, coach, carriage");
}

TEST_F(LabelsGeneric, patio_terrace) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 707), 707);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 707), "patio, terrace");
}

TEST_F(LabelsGeneric, pay_phone_pay_station) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 708), 708);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 708), "pay-phone, pay-station");
}

TEST_F(LabelsGeneric, pedestal_plinth_footstall) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 709), 709);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 709), "pedestal, plinth, footstall");
}

TEST_F(LabelsGeneric, pencil_box_pencil_case) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 710), 710);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 710), "pencil box, pencil case");
}

TEST_F(LabelsGeneric, pencil_sharpener) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 711), 711);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 711), "pencil sharpener");
}

TEST_F(LabelsGeneric, perfume_essence) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 712), 712);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 712), "perfume, essence");
}

TEST_F(LabelsGeneric, Petri_dish) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 713), 713);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 713), "Petri dish");
}

TEST_F(LabelsGeneric, photocopier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 714), 714);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 714), "photocopier");
}

TEST_F(LabelsGeneric, pick_plectrum_plectron) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 715), 715);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 715), "pick, plectrum, plectron");
}

TEST_F(LabelsGeneric, pickelhaube) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 716), 716);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 716), "pickelhaube");
}

TEST_F(LabelsGeneric, picket_fence_paling) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 717), 717);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 717), "picket fence, paling");
}

TEST_F(LabelsGeneric, pickup_pickup_truck) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 718), 718);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 718), "pickup, pickup truck");
}

TEST_F(LabelsGeneric, pier) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 719), 719);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 719), "pier");
}

TEST_F(LabelsGeneric, piggy_bank_penny_bank) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 720), 720);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 720), "piggy bank, penny bank");
}

TEST_F(LabelsGeneric, pill_bottle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 721), 721);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 721), "pill bottle");
}

TEST_F(LabelsGeneric, pillow) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 722), 722);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 722), "pillow");
}

TEST_F(LabelsGeneric, ping_pong_ball) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 723), 723);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 723), "ping-pong ball");
}

TEST_F(LabelsGeneric, pinwheel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 724), 724);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 724), "pinwheel");
}

TEST_F(LabelsGeneric, pirate_pirate_ship) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 725), 725);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 725), "pirate, pirate ship");
}

TEST_F(LabelsGeneric, pitcher_ewer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 726), 726);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 726), "pitcher, ewer");
}

TEST_F(LabelsGeneric, plane_carpenter_s_plane_woodworking_plane) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 727), 727);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 727), "plane, carpenter's plane, woodworking plane");
}

TEST_F(LabelsGeneric, planetarium) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 728), 728);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 728), "planetarium");
}

TEST_F(LabelsGeneric, plastic_bag) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 729), 729);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 729), "plastic bag");
}

TEST_F(LabelsGeneric, plate_rack) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 730), 730);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 730), "plate rack");
}

TEST_F(LabelsGeneric, plow_plough) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 731), 731);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 731), "plow, plough");
}

TEST_F(LabelsGeneric, plunger_plumber_s_helper) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 732), 732);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 732), "plunger, plumber's helper");
}

TEST_F(LabelsGeneric, Polaroid_camera_Polaroid_Land_camera) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 733), 733);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 733), "Polaroid camera, Polaroid Land camera");
}

TEST_F(LabelsGeneric, pole) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 734), 734);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 734), "pole");
}

TEST_F(LabelsGeneric, police_van_police_wagon_paddy_wagon_patrol_wagon_wagon_black_Maria) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 735), 735);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 735), "police van, police wagon, paddy wagon, patrol wagon, wagon, black Maria");
}

TEST_F(LabelsGeneric, poncho) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 736), 736);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 736), "poncho");
}

TEST_F(LabelsGeneric, pool_table_billiard_table_snooker_table) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 737), 737);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 737), "pool table, billiard table, snooker table");
}

TEST_F(LabelsGeneric, pop_bottle_soda_bottle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 738), 738);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 738), "pop bottle, soda bottle");
}

TEST_F(LabelsGeneric, pot_flowerpot) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 739), 739);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 739), "pot, flowerpot");
}

TEST_F(LabelsGeneric, potter_s_wheel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 740), 740);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 740), "potter's wheel");
}

TEST_F(LabelsGeneric, power_drill) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 741), 741);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 741), "power drill");
}

TEST_F(LabelsGeneric, prayer_rug_prayer_mat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 742), 742);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 742), "prayer rug, prayer mat");
}

TEST_F(LabelsGeneric, printer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 743), 743);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 743), "printer");
}

TEST_F(LabelsGeneric, prison_prison_house) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 744), 744);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 744), "prison, prison house");
}

TEST_F(LabelsGeneric, projectile_missile) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 745), 745);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 745), "projectile, missile");
}

TEST_F(LabelsGeneric, projector) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 746), 746);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 746), "projector");
}

TEST_F(LabelsGeneric, puck_hockey_puck) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 747), 747);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 747), "puck, hockey puck");
}

TEST_F(LabelsGeneric, punching_bag_punch_bag_punching_ball_punchball) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 748), 748);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 748), "punching bag, punch bag, punching ball, punchball");
}

TEST_F(LabelsGeneric, purse) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 749), 749);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 749), "purse");
}

TEST_F(LabelsGeneric, quill_quill_pen) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 750), 750);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 750), "quill, quill pen");
}

TEST_F(LabelsGeneric, quilt_comforter_comfort_puff) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 751), 751);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 751), "quilt, comforter, comfort, puff");
}

TEST_F(LabelsGeneric, racer_race_car_racing_car) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 752), 752);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 752), "racer, race car, racing car");
}

TEST_F(LabelsGeneric, racket_racquet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 753), 753);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 753), "racket, racquet");
}

TEST_F(LabelsGeneric, radiator) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 754), 754);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 754), "radiator");
}

TEST_F(LabelsGeneric, radio_wireless) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 755), 755);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 755), "radio, wireless");
}

TEST_F(LabelsGeneric, radio_telescope_radio_reflector) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 756), 756);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 756), "radio telescope, radio reflector");
}

TEST_F(LabelsGeneric, rain_barrel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 757), 757);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 757), "rain barrel");
}

TEST_F(LabelsGeneric, recreational_vehicle_RV_R_V_) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 758), 758);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 758), "recreational vehicle, RV, R.V.");
}

TEST_F(LabelsGeneric, reel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 759), 759);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 759), "reel");
}

TEST_F(LabelsGeneric, reflex_camera) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 760), 760);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 760), "reflex camera");
}

TEST_F(LabelsGeneric, refrigerator_icebox) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 761), 761);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 761), "refrigerator, icebox");
}

TEST_F(LabelsGeneric, remote_control_remote) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 762), 762);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 762), "remote control, remote");
}

TEST_F(LabelsGeneric, restaurant_eating_house_eating_place_eatery) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 763), 763);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 763), "restaurant, eating house, eating place, eatery");
}

TEST_F(LabelsGeneric, revolver_six_gun_six_shooter) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 764), 764);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 764), "revolver, six-gun, six-shooter");
}

TEST_F(LabelsGeneric, rifle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 765), 765);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 765), "rifle");
}

TEST_F(LabelsGeneric, rocking_chair_rocker) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 766), 766);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 766), "rocking chair, rocker");
}

TEST_F(LabelsGeneric, rotisserie) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 767), 767);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 767), "rotisserie");
}

TEST_F(LabelsGeneric, rubber_eraser_rubber_pencil_eraser) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 768), 768);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 768), "rubber eraser, rubber, pencil eraser");
}

TEST_F(LabelsGeneric, rugby_ball) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 769), 769);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 769), "rugby ball");
}

TEST_F(LabelsGeneric, rule_ruler) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 770), 770);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 770), "rule, ruler");
}

TEST_F(LabelsGeneric, running_shoe) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 771), 771);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 771), "running shoe");
}

TEST_F(LabelsGeneric, safe) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 772), 772);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 772), "safe");
}

TEST_F(LabelsGeneric, safety_pin) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 773), 773);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 773), "safety pin");
}

TEST_F(LabelsGeneric, saltshaker_salt_shaker) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 774), 774);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 774), "saltshaker, salt shaker");
}

TEST_F(LabelsGeneric, sandal) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 775), 775);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 775), "sandal");
}

TEST_F(LabelsGeneric, sarong) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 776), 776);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 776), "sarong");
}

TEST_F(LabelsGeneric, sax_saxophone) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 777), 777);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 777), "sax, saxophone");
}

TEST_F(LabelsGeneric, scabbard) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 778), 778);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 778), "scabbard");
}

TEST_F(LabelsGeneric, scale_weighing_machine) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 779), 779);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 779), "scale, weighing machine");
}

TEST_F(LabelsGeneric, school_bus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 780), 780);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 780), "school bus");
}

TEST_F(LabelsGeneric, schooner) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 781), 781);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 781), "schooner");
}

TEST_F(LabelsGeneric, scoreboard) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 782), 782);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 782), "scoreboard");
}

TEST_F(LabelsGeneric, screen_CRT_screen) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 783), 783);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 783), "screen, CRT screen");
}

TEST_F(LabelsGeneric, screw) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 784), 784);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 784), "screw");
}

TEST_F(LabelsGeneric, screwdriver) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 785), 785);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 785), "screwdriver");
}

TEST_F(LabelsGeneric, seat_belt_seatbelt) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 786), 786);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 786), "seat belt, seatbelt");
}

TEST_F(LabelsGeneric, sewing_machine) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 787), 787);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 787), "sewing machine");
}

TEST_F(LabelsGeneric, shield_buckler) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 788), 788);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 788), "shield, buckler");
}

TEST_F(LabelsGeneric, shoe_shop_shoe_shop_shoe_store) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 789), 789);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 789), "shoe shop, shoe-shop, shoe store");
}

TEST_F(LabelsGeneric, shoji) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 790), 790);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 790), "shoji");
}

TEST_F(LabelsGeneric, shopping_basket) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 791), 791);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 791), "shopping basket");
}

TEST_F(LabelsGeneric, shopping_cart) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 792), 792);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 792), "shopping cart");
}

TEST_F(LabelsGeneric, shovel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 793), 793);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 793), "shovel");
}

TEST_F(LabelsGeneric, shower_cap) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 794), 794);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 794), "shower cap");
}

TEST_F(LabelsGeneric, shower_curtain) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 795), 795);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 795), "shower curtain");
}

TEST_F(LabelsGeneric, ski) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 796), 796);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 796), "ski");
}

TEST_F(LabelsGeneric, ski_mask) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 797), 797);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 797), "ski mask");
}

TEST_F(LabelsGeneric, sleeping_bag) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 798), 798);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 798), "sleeping bag");
}

TEST_F(LabelsGeneric, slide_rule_slipstick) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 799), 799);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 799), "slide rule, slipstick");
}

TEST_F(LabelsGeneric, sliding_door) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 800), 800);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 800), "sliding door");
}

TEST_F(LabelsGeneric, slot_one_armed_bandit) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 801), 801);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 801), "slot, one-armed bandit");
}

TEST_F(LabelsGeneric, snorkel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 802), 802);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 802), "snorkel");
}

TEST_F(LabelsGeneric, snowmobile) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 803), 803);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 803), "snowmobile");
}

TEST_F(LabelsGeneric, snowplow_snowplough) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 804), 804);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 804), "snowplow, snowplough");
}

TEST_F(LabelsGeneric, soap_dispenser) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 805), 805);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 805), "soap dispenser");
}

TEST_F(LabelsGeneric, soccer_ball) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 806), 806);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 806), "soccer ball");
}

TEST_F(LabelsGeneric, sock) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 807), 807);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 807), "sock");
}

TEST_F(LabelsGeneric, solar_dish_solar_collector_solar_furnace) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 808), 808);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 808), "solar dish, solar collector, solar furnace");
}

TEST_F(LabelsGeneric, sombrero) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 809), 809);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 809), "sombrero");
}

TEST_F(LabelsGeneric, soup_bowl) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 810), 810);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 810), "soup bowl");
}

TEST_F(LabelsGeneric, space_bar) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 811), 811);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 811), "space bar");
}

TEST_F(LabelsGeneric, space_heater) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 812), 812);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 812), "space heater");
}

TEST_F(LabelsGeneric, space_shuttle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 813), 813);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 813), "space shuttle");
}

TEST_F(LabelsGeneric, spatula) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 814), 814);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 814), "spatula");
}

TEST_F(LabelsGeneric, speedboat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 815), 815);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 815), "speedboat");
}

TEST_F(LabelsGeneric, spider_web_spider_s_web) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 816), 816);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 816), "spider web, spider's web");
}

TEST_F(LabelsGeneric, spindle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 817), 817);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 817), "spindle");
}

TEST_F(LabelsGeneric, sports_car_sport_car) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 818), 818);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 818), "sports car, sport car");
}

TEST_F(LabelsGeneric, spotlight_spot) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 819), 819);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 819), "spotlight, spot");
}

TEST_F(LabelsGeneric, stage) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 820), 820);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 820), "stage");
}

TEST_F(LabelsGeneric, steam_locomotive) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 821), 821);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 821), "steam locomotive");
}

TEST_F(LabelsGeneric, steel_arch_bridge) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 822), 822);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 822), "steel arch bridge");
}

TEST_F(LabelsGeneric, steel_drum) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 823), 823);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 823), "steel drum");
}

TEST_F(LabelsGeneric, stethoscope) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 824), 824);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 824), "stethoscope");
}

TEST_F(LabelsGeneric, stole) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 825), 825);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 825), "stole");
}

TEST_F(LabelsGeneric, stone_wall) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 826), 826);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 826), "stone wall");
}

TEST_F(LabelsGeneric, stopwatch_stop_watch) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 827), 827);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 827), "stopwatch, stop watch");
}

TEST_F(LabelsGeneric, stove) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 828), 828);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 828), "stove");
}

TEST_F(LabelsGeneric, strainer) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 829), 829);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 829), "strainer");
}

TEST_F(LabelsGeneric, streetcar_tram_tramcar_trolley_trolley_car) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 830), 830);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 830), "streetcar, tram, tramcar, trolley, trolley car");
}

TEST_F(LabelsGeneric, stretcher) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 831), 831);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 831), "stretcher");
}

TEST_F(LabelsGeneric, studio_couch_day_bed) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 832), 832);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 832), "studio couch, day bed");
}

TEST_F(LabelsGeneric, stupa_tope) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 833), 833);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 833), "stupa, tope");
}

TEST_F(LabelsGeneric, submarine_pigboat_sub_U_boat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 834), 834);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 834), "submarine, pigboat, sub, U-boat");
}

TEST_F(LabelsGeneric, suit_suit_of_clothes) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 835), 835);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 835), "suit, suit of clothes");
}

TEST_F(LabelsGeneric, sundial) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 836), 836);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 836), "sundial");
}

TEST_F(LabelsGeneric, sunglass) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 837), 837);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 837), "sunglass");
}

TEST_F(LabelsGeneric, sunglasses_dark_glasses_shades) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 838), 838);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 838), "sunglasses, dark glasses, shades");
}

TEST_F(LabelsGeneric, sunscreen_sunblock_sun_blocker) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 839), 839);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 839), "sunscreen, sunblock, sun blocker");
}

TEST_F(LabelsGeneric, suspension_bridge) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 840), 840);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 840), "suspension bridge");
}

TEST_F(LabelsGeneric, swab_swob_mop) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 841), 841);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 841), "swab, swob, mop");
}

TEST_F(LabelsGeneric, sweatshirt) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 842), 842);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 842), "sweatshirt");
}

TEST_F(LabelsGeneric, swimming_trunks_bathing_trunks) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 843), 843);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 843), "swimming trunks, bathing trunks");
}

TEST_F(LabelsGeneric, swing) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 844), 844);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 844), "swing");
}

TEST_F(LabelsGeneric, switch_electric_switch_electrical_switch) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 845), 845);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 845), "switch, electric switch, electrical switch");
}

TEST_F(LabelsGeneric, syringe) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 846), 846);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 846), "syringe");
}

TEST_F(LabelsGeneric, table_lamp) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 847), 847);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 847), "table lamp");
}

TEST_F(LabelsGeneric, tank_army_tank_armored_combat_vehicle_armoured_combat_vehicle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 848), 848);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 848), "tank, army tank, armored combat vehicle, armoured combat vehicle");
}

TEST_F(LabelsGeneric, tape_player) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 849), 849);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 849), "tape player");
}

TEST_F(LabelsGeneric, teapot) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 850), 850);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 850), "teapot");
}

TEST_F(LabelsGeneric, teddy_teddy_bear) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 851), 851);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 851), "teddy, teddy bear");
}

TEST_F(LabelsGeneric, television_television_system) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 852), 852);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 852), "television, television system");
}

TEST_F(LabelsGeneric, tennis_ball) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 853), 853);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 853), "tennis ball");
}

TEST_F(LabelsGeneric, thatch_thatched_roof) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 854), 854);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 854), "thatch, thatched roof");
}

TEST_F(LabelsGeneric, theater_curtain_theatre_curtain) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 855), 855);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 855), "theater curtain, theatre curtain");
}

TEST_F(LabelsGeneric, thimble) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 856), 856);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 856), "thimble");
}

TEST_F(LabelsGeneric, thresher_thrasher_threshing_machine) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 857), 857);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 857), "thresher, thrasher, threshing machine");
}

TEST_F(LabelsGeneric, throne) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 858), 858);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 858), "throne");
}

TEST_F(LabelsGeneric, tile_roof) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 859), 859);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 859), "tile roof");
}

TEST_F(LabelsGeneric, toaster) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 860), 860);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 860), "toaster");
}

TEST_F(LabelsGeneric, tobacco_shop_tobacconist_shop_tobacconist) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 861), 861);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 861), "tobacco shop, tobacconist shop, tobacconist");
}

TEST_F(LabelsGeneric, toilet_seat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 862), 862);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 862), "toilet seat");
}

TEST_F(LabelsGeneric, torch) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 863), 863);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 863), "torch");
}

TEST_F(LabelsGeneric, totem_pole) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 864), 864);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 864), "totem pole");
}

TEST_F(LabelsGeneric, tow_truck_tow_car_wrecker) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 865), 865);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 865), "tow truck, tow car, wrecker");
}

TEST_F(LabelsGeneric, toyshop) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 866), 866);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 866), "toyshop");
}

TEST_F(LabelsGeneric, tractor) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 867), 867);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 867), "tractor");
}

TEST_F(LabelsGeneric, trailer_truck_tractor_trailer_trucking_rig_rig_articulated_lorry_semi) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 868), 868);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 868), "trailer truck, tractor trailer, trucking rig, rig, articulated lorry, semi");
}

TEST_F(LabelsGeneric, tray) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 869), 869);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 869), "tray");
}

TEST_F(LabelsGeneric, trench_coat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 870), 870);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 870), "trench coat");
}

TEST_F(LabelsGeneric, tricycle_trike_velocipede) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 871), 871);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 871), "tricycle, trike, velocipede");
}

TEST_F(LabelsGeneric, trimaran) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 872), 872);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 872), "trimaran");
}

TEST_F(LabelsGeneric, tripod) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 873), 873);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 873), "tripod");
}

TEST_F(LabelsGeneric, triumphal_arch) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 874), 874);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 874), "triumphal arch");
}

TEST_F(LabelsGeneric, trolleybus_trolley_coach_trackless_trolley) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 875), 875);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 875), "trolleybus, trolley coach, trackless trolley");
}

TEST_F(LabelsGeneric, trombone) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 876), 876);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 876), "trombone");
}

TEST_F(LabelsGeneric, tub_vat) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 877), 877);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 877), "tub, vat");
}

TEST_F(LabelsGeneric, turnstile) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 878), 878);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 878), "turnstile");
}

TEST_F(LabelsGeneric, typewriter_keyboard) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 879), 879);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 879), "typewriter keyboard");
}

TEST_F(LabelsGeneric, umbrella) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 880), 880);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 880), "umbrella");
}

TEST_F(LabelsGeneric, unicycle_monocycle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 881), 881);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 881), "unicycle, monocycle");
}

TEST_F(LabelsGeneric, upright_upright_piano) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 882), 882);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 882), "upright, upright piano");
}

TEST_F(LabelsGeneric, vacuum_vacuum_cleaner) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 883), 883);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 883), "vacuum, vacuum cleaner");
}

TEST_F(LabelsGeneric, vase) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 884), 884);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 884), "vase");
}

TEST_F(LabelsGeneric, vault) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 885), 885);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 885), "vault");
}

TEST_F(LabelsGeneric, velvet) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 886), 886);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 886), "velvet");
}

TEST_F(LabelsGeneric, vending_machine) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 887), 887);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 887), "vending machine");
}

TEST_F(LabelsGeneric, vestment) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 888), 888);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 888), "vestment");
}

TEST_F(LabelsGeneric, viaduct) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 889), 889);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 889), "viaduct");
}

TEST_F(LabelsGeneric, violin_fiddle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 890), 890);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 890), "violin, fiddle");
}

TEST_F(LabelsGeneric, volleyball) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 891), 891);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 891), "volleyball");
}

TEST_F(LabelsGeneric, waffle_iron) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 892), 892);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 892), "waffle iron");
}

TEST_F(LabelsGeneric, wall_clock) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 893), 893);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 893), "wall clock");
}

TEST_F(LabelsGeneric, wallet_billfold_notecase_pocketbook) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 894), 894);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 894), "wallet, billfold, notecase, pocketbook");
}

TEST_F(LabelsGeneric, wardrobe_closet_press) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 895), 895);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 895), "wardrobe, closet, press");
}

TEST_F(LabelsGeneric, warplane_military_plane) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 896), 896);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 896), "warplane, military plane");
}

TEST_F(LabelsGeneric, washbasin_handbasin_washbowl_lavabo_wash_hand_basin) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 897), 897);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 897), "washbasin, handbasin, washbowl, lavabo, wash-hand basin");
}

TEST_F(LabelsGeneric, washer_automatic_washer_washing_machine) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 898), 898);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 898), "washer, automatic washer, washing machine");
}

TEST_F(LabelsGeneric, water_bottle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 899), 899);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 899), "water bottle");
}

TEST_F(LabelsGeneric, water_jug) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 900), 900);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 900), "water jug");
}

TEST_F(LabelsGeneric, water_tower) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 901), 901);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 901), "water tower");
}

TEST_F(LabelsGeneric, whiskey_jug) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 902), 902);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 902), "whiskey jug");
}

TEST_F(LabelsGeneric, whistle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 903), 903);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 903), "whistle");
}

TEST_F(LabelsGeneric, wig) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 904), 904);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 904), "wig");
}

TEST_F(LabelsGeneric, window_screen) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 905), 905);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 905), "window screen");
}

TEST_F(LabelsGeneric, window_shade) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 906), 906);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 906), "window shade");
}

TEST_F(LabelsGeneric, Windsor_tie) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 907), 907);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 907), "Windsor tie");
}

TEST_F(LabelsGeneric, wine_bottle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 908), 908);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 908), "wine bottle");
}

TEST_F(LabelsGeneric, wing) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 909), 909);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 909), "wing");
}

TEST_F(LabelsGeneric, wok) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 910), 910);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 910), "wok");
}

TEST_F(LabelsGeneric, wooden_spoon) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 911), 911);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 911), "wooden spoon");
}

TEST_F(LabelsGeneric, wool_woolen_woollen) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 912), 912);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 912), "wool, woolen, woollen");
}

TEST_F(LabelsGeneric, worm_fence_snake_fence_snake_rail_fence_Virginia_fence) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 913), 913);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 913), "worm fence, snake fence, snake-rail fence, Virginia fence");
}

TEST_F(LabelsGeneric, wreck) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 914), 914);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 914), "wreck");
}

TEST_F(LabelsGeneric, yawl) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 915), 915);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 915), "yawl");
}

TEST_F(LabelsGeneric, yurt) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 916), 916);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 916), "yurt");
}

TEST_F(LabelsGeneric, web_site_website_internet_site_site) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 917), 917);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 917), "web site, website, internet site, site");
}

TEST_F(LabelsGeneric, comic_book) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 918), 918);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 918), "comic book");
}

TEST_F(LabelsGeneric, crossword_puzzle_crossword) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 919), 919);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 919), "crossword puzzle, crossword");
}

TEST_F(LabelsGeneric, street_sign) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 920), 920);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 920), "street sign");
}

TEST_F(LabelsGeneric, traffic_light_traffic_signal_stoplight) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 921), 921);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 921), "traffic light, traffic signal, stoplight");
}

TEST_F(LabelsGeneric, book_jacket_dust_cover_dust_jacket_dust_wrapper) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 922), 922);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 922), "book jacket, dust cover, dust jacket, dust wrapper");
}

TEST_F(LabelsGeneric, menu) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 923), 923);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 923), "menu");
}

TEST_F(LabelsGeneric, plate) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 924), 924);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 924), "plate");
}

TEST_F(LabelsGeneric, guacamole) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 925), 925);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 925), "guacamole");
}

TEST_F(LabelsGeneric, consomme) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 926), 926);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 926), "consomme");
}

TEST_F(LabelsGeneric, hot_pot_hotpot) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 927), 927);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 927), "hot pot, hotpot");
}

TEST_F(LabelsGeneric, trifle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 928), 928);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 928), "trifle");
}

TEST_F(LabelsGeneric, ice_cream_icecream) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 929), 929);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 929), "ice cream, icecream");
}

TEST_F(LabelsGeneric, ice_lolly_lolly_lollipop_popsicle) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 930), 930);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 930), "ice lolly, lolly, lollipop, popsicle");
}

TEST_F(LabelsGeneric, French_loaf) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 931), 931);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 931), "French loaf");
}

TEST_F(LabelsGeneric, bagel_beigel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 932), 932);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 932), "bagel, beigel");
}

TEST_F(LabelsGeneric, pretzel) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 933), 933);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 933), "pretzel");
}

TEST_F(LabelsGeneric, cheeseburger) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 934), 934);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 934), "cheeseburger");
}

TEST_F(LabelsGeneric, hotdog_hot_dog_red_hot) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 935), 935);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 935), "hotdog, hot dog, red hot");
}

TEST_F(LabelsGeneric, mashed_potato) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 936), 936);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 936), "mashed potato");
}

TEST_F(LabelsGeneric, head_cabbage) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 937), 937);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 937), "head cabbage");
}

TEST_F(LabelsGeneric, broccoli) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 938), 938);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 938), "broccoli");
}

TEST_F(LabelsGeneric, cauliflower) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 939), 939);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 939), "cauliflower");
}

TEST_F(LabelsGeneric, zucchini_courgette) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 940), 940);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 940), "zucchini, courgette");
}

TEST_F(LabelsGeneric, spaghetti_squash) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 941), 941);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 941), "spaghetti squash");
}

TEST_F(LabelsGeneric, acorn_squash) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 942), 942);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 942), "acorn squash");
}

TEST_F(LabelsGeneric, butternut_squash) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 943), 943);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 943), "butternut squash");
}

TEST_F(LabelsGeneric, cucumber_cuke) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 944), 944);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 944), "cucumber, cuke");
}

TEST_F(LabelsGeneric, artichoke_globe_artichoke) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 945), 945);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 945), "artichoke, globe artichoke");
}

TEST_F(LabelsGeneric, bell_pepper) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 946), 946);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 946), "bell pepper");
}

TEST_F(LabelsGeneric, cardoon) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 947), 947);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 947), "cardoon");
}

TEST_F(LabelsGeneric, mushroom) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 948), 948);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 948), "mushroom");
}

TEST_F(LabelsGeneric, Granny_Smith) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 949), 949);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 949), "Granny Smith");
}

TEST_F(LabelsGeneric, strawberry) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 950), 950);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 950), "strawberry");
}

TEST_F(LabelsGeneric, orange) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 951), 951);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 951), "orange");
}

TEST_F(LabelsGeneric, lemon) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 952), 952);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 952), "lemon");
}

TEST_F(LabelsGeneric, fig) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 953), 953);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 953), "fig");
}

TEST_F(LabelsGeneric, pineapple_ananas) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 954), 954);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 954), "pineapple, ananas");
}

TEST_F(LabelsGeneric, banana) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 955), 955);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 955), "banana");
}

TEST_F(LabelsGeneric, jackfruit_jak_jack) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 956), 956);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 956), "jackfruit, jak, jack");
}

TEST_F(LabelsGeneric, custard_apple) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 957), 957);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 957), "custard apple");
}

TEST_F(LabelsGeneric, pomegranate) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 958), 958);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 958), "pomegranate");
}

TEST_F(LabelsGeneric, hay) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 959), 959);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 959), "hay");
}

TEST_F(LabelsGeneric, carbonara) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 960), 960);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 960), "carbonara");
}

TEST_F(LabelsGeneric, chocolate_sauce_chocolate_syrup) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 961), 961);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 961), "chocolate sauce, chocolate syrup");
}

TEST_F(LabelsGeneric, dough) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 962), 962);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 962), "dough");
}

TEST_F(LabelsGeneric, meat_loaf_meatloaf) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 963), 963);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 963), "meat loaf, meatloaf");
}

TEST_F(LabelsGeneric, pizza_pizza_pie) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 964), 964);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 964), "pizza, pizza pie");
}

TEST_F(LabelsGeneric, potpie) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 965), 965);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 965), "potpie");
}

TEST_F(LabelsGeneric, burrito) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 966), 966);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 966), "burrito");
}

TEST_F(LabelsGeneric, red_wine) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 967), 967);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 967), "red wine");
}

TEST_F(LabelsGeneric, espresso) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 968), 968);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 968), "espresso");
}

TEST_F(LabelsGeneric, cup) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 969), 969);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 969), "cup");
}

TEST_F(LabelsGeneric, eggnog) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 970), 970);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 970), "eggnog");
}

TEST_F(LabelsGeneric, alp) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 971), 971);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 971), "alp");
}

TEST_F(LabelsGeneric, bubble) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 972), 972);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 972), "bubble");
}

TEST_F(LabelsGeneric, cliff_drop_drop_off) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 973), 973);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 973), "cliff, drop, drop-off");
}

TEST_F(LabelsGeneric, coral_reef) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 974), 974);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 974), "coral reef");
}

TEST_F(LabelsGeneric, geyser) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 975), 975);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 975), "geyser");
}

TEST_F(LabelsGeneric, lakeside_lakeshore) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 976), 976);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 976), "lakeside, lakeshore");
}

TEST_F(LabelsGeneric, promontory_headland_head_foreland) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 977), 977);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 977), "promontory, headland, head, foreland");
}

TEST_F(LabelsGeneric, sandbar_sand_bar) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 978), 978);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 978), "sandbar, sand bar");
}

TEST_F(LabelsGeneric, seashore_coast_seacoast_sea_coast) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 979), 979);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 979), "seashore, coast, seacoast, sea-coast");
}

TEST_F(LabelsGeneric, valley_vale) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 980), 980);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 980), "valley, vale");
}

TEST_F(LabelsGeneric, volcano) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 981), 981);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 981), "volcano");
}

TEST_F(LabelsGeneric, ballplayer_baseball_player) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 982), 982);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 982), "ballplayer, baseball player");
}

TEST_F(LabelsGeneric, groom_bridegroom) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 983), 983);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 983), "groom, bridegroom");
}

TEST_F(LabelsGeneric, scuba_diver) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 984), 984);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 984), "scuba diver");
}

TEST_F(LabelsGeneric, rapeseed) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 985), 985);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 985), "rapeseed");
}

TEST_F(LabelsGeneric, daisy) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 986), 986);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 986), "daisy");
}

TEST_F(LabelsGeneric, yellow_lady_s_slipper_yellow_lady_slipper_Cypripedium_calceolus_Cypripedium_parviflorum) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 987), 987);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 987), "yellow lady's slipper, yellow lady-slipper, Cypripedium calceolus, Cypripedium parviflorum");
}

TEST_F(LabelsGeneric, corn) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 988), 988);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 988), "corn");
}

TEST_F(LabelsGeneric, acorn) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 989), 989);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 989), "acorn");
}

TEST_F(LabelsGeneric, hip_rose_hip_rosehip) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 990), 990);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 990), "hip, rose hip, rosehip");
}

TEST_F(LabelsGeneric, buckeye_horse_chestnut_conker) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 991), 991);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 991), "buckeye, horse chestnut, conker");
}

TEST_F(LabelsGeneric, coral_fungus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 992), 992);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 992), "coral fungus");
}

TEST_F(LabelsGeneric, agaric) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 993), 993);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 993), "agaric");
}

TEST_F(LabelsGeneric, gyromitra) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 994), 994);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 994), "gyromitra");
}

TEST_F(LabelsGeneric, stinkhorn_carrion_fungus) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 995), 995);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 995), "stinkhorn, carrion fungus");
}

TEST_F(LabelsGeneric, earthstar) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 996), 996);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 996), "earthstar");
}

TEST_F(LabelsGeneric, hen_of_the_woods_hen_of_the_woods_Polyporus_frondosus_Grifola_frondosa) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 997), 997);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 997), "hen-of-the-woods, hen of the woods, Polyporus frondosus, Grifola frondosa");
}

TEST_F(LabelsGeneric, bolete) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 998), 998);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 998), "bolete");
}

TEST_F(LabelsGeneric, ear_spike_capitulum) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 999), 999);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 999), "ear, spike, capitulum");
}

TEST_F(LabelsGeneric, toilet_tissue_toilet_paper_bathroom_tissue) {
  EXPECT_EQ(getIndexLabel(label_ -> getLabels(), 1000), 1000);
  EXPECT_EQ(getLabel(label_ -> getLabels(), 1000), "toilet tissue, toilet paper, bathroom tissue");
}

