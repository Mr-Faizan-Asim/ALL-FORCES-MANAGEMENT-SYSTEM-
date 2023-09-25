#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <fstream>
#include <string>
using namespace std;

int screen_size();
int rows_of_screen, columns_of_screen;
int rows_to_fit, columns_to_fit;
// LOGIN PHASE
int user_id();
string take_password();
string take_username();
bool ams_user_password_login(string user, string password);
bool nms_user_password_login(string user, string password);
bool afms_user_password_login(string user, string password);
bool air_force_officer_user_password_login(string user, string password);
bool navy_officer_user_password_login(string user, string password);
bool army_officer_user_password_login(string user, string password);
bool army_soldier_user_password_login(string user, string password);

// Validations
bool numeric_validation(string word);
bool soldiers_batch_id_validations(string word);
bool validation_in_adding_soldiers_persons(int arr_index,string word);
bool password_validation(string word);
bool character_type_validation(string word);
bool validation_in_adding_officers_persons(int arr_index,string word);
bool officer_batch_id_validations(string word);
// DESIGN PHASE DECISION PHASE
void title(string content_inside_title);
void to_print_in_title(string content_inside_title);
void print_start_box(int rows, int columns);
char getCharAtxy(short int x, short int y);
void gotoxy(int x, int y);
void home_page();
void print_line(int start_point, int row, int end_point);
void first_page_title();
int selecting_function(int x, int y, int n);
void slecter_horizantel_line(int x, int y);
void erase_slecter_horizantel_line(int x, int y);
void invalid_function();
void to_show_note(string text);

// USERS
int army_management_team_system(int checker_of_user_domain);
int navy_management_team_system(int checker_of_user_domain);
int air_force_management_team_system(int checker_of_user_domain);
int army_officer_management_system(int checker_of_user_domain);
int air_force_officer_management_system(int checker_of_user_domain);
int navy_officer_management_system(int checker_of_user_domain);
int soldiers_management_system(int checker_of_user_domain);
// SECURITY PHASE
string batch_id_security;
int batch_id_index_security;
// VARIABLES FOR COUNT THINGS
int army_soldier_count = 0;
int navy_soldier_count = 0;
int air_force_soldier_count = 0;
int army_officer_count = 0;
int navy_officer_count = 0;
int air_force_officer_count = 0;
// Variable for retired 
int retired_army_soldier_count = 0;
int retired_navy_soldier_count = 0;
int retired_air_force_soldier_count = 0;
int retired_army_officer_count = 0;
int retired_navy_officer_count = 0;
int retired_air_force_officer_count = 0;
// ARRAYS
string army_soldier_array[8][1000];
string navy_soldier_array[8][1000];
string air_force_soldier_array[8][1000];
string army_officer_array[8][1000];
string navy_officer_array[8][1000];
string air_force_officer_array[8][1000];
// ARRAYS FOR RETIRED SOLDIERS
string retired_army_soldier_array[8][1000];
string retired_navy_soldier_array[8][1000];
string retired_air_force_soldier_array[8][1000];
string retired_army_officer_array[8][1000];
string retired_navy_officer_array[8][1000];
string retired_air_force_officer_array[8][1000];
// SOLDIERS UNDER THE OFFICER
string soldiers_under_the_officer_ams[2][1000];
string soldiers_under_the_officer_nms[2][1000];
string soldiers_under_the_officer_afms[2][1000];
// INSTRUMENTS AMS
int count_ams_weapons = 0;
int count_ams_carriers = 0;
int count_ams_missilies = 0;
int count_ams_tank = 0;
int count_ams_atomic_bombs = 0;
string ams_weapons[30][5];
string ams_carriers[30][5];
string ams_missilies[30][5];
string ams_tank[30][5];
string ams_atomic_bombs[30][5];
int count_nms_weapons = 0;
int count_nms_air_craft = 0;
int count_nms_missilies = 0;
int count_nms_subarine = 0;
int count_nms_surface_ships = 0;
string nms_weapons[30][5];
string nms_air_craft[30][5];
string nms_missilies[30][5];
string nms_subarine[30][5];
string nms_surface_ships[30][5];
int count_afms_weapons = 0;
int count_afms_air_craft = 0;
int count_afms_missilies = 0;
int count_afms_planes = 0;
int count_afms_trackers = 0;
string afms_weapons[30][5];
string afms_air_craft[30][5];
string afms_missilies[30][5];
string afms_planes[30][5];
string afms_trackers[30][5];
// fetch Instruments
int fetch_ams_carriers();
int fetch_ams_weapons();
int fetch_ams_tank();
int fetch_ams_missilies();
int fetch_ams_bombs();
int fetch_nms_weapons();
int fetch_nms_air_craft();
int fetch_nms_missilies();
int fetch_nms_subarine();
int fetch_nms_surface_ships();
int fetch_afms_air_craft();
int fetch_afms_weapons();
int fetch_afms_missilies();
int fetch_afms_planes();
int fetch_afms_trackers();
// SELECTION FUNCTIONS
int yes_or_no(int perior_option);
void feedback();
int to_calculate_salary_asms();
// fetching functions
void fetch_all_data_at_start();
int fetch_ams_soldier_data_from_txt_to_array();
int fetch_ams_officers_data_from_txt_to_array();
int fetch_nms_soldier_data_from_txt_to_array();
int fetch_nms_officers_data_from_txt_to_array();
int fetch_afms_soldier_data_from_txt_to_array();
int fetch_afms_officers_data_from_txt_to_array();
int fetch_ams_retired_soldiers_data_from_txt_to_array();
int fetch_ams_retired_officers_data_from_txt_to_array();
int fetch_nms_retired_soldiers_data_from_txt_to_array();
int fetch_nms_retired_officers_data_from_txt_to_array();
int fetch_afms_retired_soldiers_data_from_txt_to_array();
int fetch_afms_retired_officers_data_from_txt_to_array();

// AMS TEAM USER 1 THINGS
string main_menu_names_ams[5] = {"1. ARMY SOLDIERS", "2. ARMY OFFICERS", "3. INSTRUMENTS", "4. CROPS", "5. REPORT OF ARMY WORK"};
string sub_menu_army_soldiers_ams[5] = {"1. PERSONAL DETAILS", "2. ADD NEW SOLDIER", "3. EDIT SOLDIER DETAIL", "4. RETIRED GENERIALS", "5. MARTYRED"};
string sub_menu_instruments_ams[5] = {"1. DETAILS OF INSTRUMENT", "2. ADD NEW INSTRUMENTS", "3. EDIT INSTRUMENT DETAIL", "4. GRAPH OF INSTRUMENTS(RESULT OF BUDGET)", "5. BUDGET OF INSTRUMENT"};
string personal_details_options_ams_soldiers[8] = {"SOLDIER BATCH ID      : ", "SOLDIER NAME    : ", "SOLDIER FATHER NAME  : ", "SOLDIER PROVIENCE : ", "SOLDIER SALARY : ", "SOLDIER AGE : ", "SOLDIER RANK : ", "SOLDIER ID PASSWORD"};
string retired_options_ams[2] = {"1. VIEW RETIRED ", "2. ADD NEW RETIRED MEN"};
string personal_details_options_ams_officers[8] = {"OFFICER BATCH ID      : ", "OFFICER NAME    : ", "OFFICER FATHER NAME  : ", "OFFICER PROVIENCE : ", "OFFICER SALARY : ", "OFFICER AGE : ", "OFFICER RANK : ", "OFFICER ID PASSWORD"};
string sub_menu_army_officers_ams[7] = {"1. PERSONAL DETAILS", "2. ADD NEW OFFICERS", "3. EDIT OFFICER DETAILS", "4. RETIRED OFFICER", "5. MARTYRED", "6. OFFICERS IN PROVIENCE", "7. SOLDIERS UNDER OFFICERS"};
string sub_of_sub_menu_instruments_ams[5] = {"1. CARRIERS", "2. WEAPONS", "3. MISSILES", "4. TANKS", "5. ATOMIC BOMBS"};
string readable_instruments_ams[5] = {"NAME: ", "RANGE: ", "PRICE: ", "STOCK: ", "USING: "};
string ams_crops[2] = {"1. XXX-KHOR", "2. SOC-KHOR"};
string matryed_option[2] = {"1. VIEW HEROES OF NATION", "2. ADD NEW MATRYED"};
int to_show_main_menu_ams(int no_of_index);
int to_show_sub_menu_army_soldier_ams(int no_of_index);
int id_take_to_fetch_and_id_check_soldiers_ams();
int to_show_personal_details_from_soldiers_array(int batch_id_index);
void to_show_personal_details_options_soldiers_ams();
void to_add_data_in_soldiers_array_ams();
void to_add_data_in_soldier_txt_ams();
void to_edit_data_in_soldiers_array_ams(int batch_id_index);
void to_add_whole_data_in_soldier_txt_ams();
int to_show_retired_menu_ams(int no_of_index);
void to_view_retired_soldier_data_ams();
void to_add_removed_soldier_in_retired_ams(int batch_index);
void to_remove_retired_soldier_from_array_ams(int batch_index);
void to_add_whole_data_in_retired_soldier_txt_ams();
int to_show_matryed_menu_ams(int no_of_index);
int to_view_matryed(string address);
int to_add_matryed(string address);
    // sub menu 2
int to_show_sub_menu_army_officer_ams(int no_of_index);
int id_take_to_fetch_and_id_check_officer_ams();
int to_show_personal_details_from_officer_array(int batch_id_index);
void to_show_personal_details_options_officer_ams();
void to_show_personal_details_options_officer_ams();
void to_add_data_in_officer_array_ams();
void to_add_data_in_officer_txt_ams();
void to_edit_data_in_officer_array_ams(int batch_id_index);
void to_add_whole_data_in_officer_txt_ams();
void to_view_retired_officer_data_ams();
void to_add_removed_officer_in_retired_ams(int batch_index);
void to_remove_retired_officer_from_array_ams(int batch_index);
void to_add_whole_data_in_retired_officer_txt_ams();
int to_see_data_from_ams_officer_arrray(int row,string provience);
string to_take_provience();
void soldier_under_officers_ams();
void soldier_under_officer_view_ams(int batch_id);
void soldier_under_officers_ams();
// sub op 3
int to_show_sub_menu_army_instruments_ams(int no_of_index);
int to_show_sub_detail_view_army_instruments_ams(int no_of_index);
void to_show_carriers_details();
void to_show_weapons_details();
void to_show_missilies_details();
void to_show_tank_details();
void to_show_atomic_bombs_details();
void to_add_data_in_array_carrier();
void to_add_data_in_array_weapons();
void to_add_data_in_array_missilies();
void to_add_data_in_array_tank();
void to_add_data_in_array_bomb();
bool validation_check_instruments(int n, string word);
void to_add_data_of_carrier_in_txt();
void to_add_data_of_weapons_in_txt();
void to_add_data_of_bomb_in_txt();
void to_add_data_of_missilies_in_txt();
void to_add_data_of_tank_in_txt();
void to_edit_instrument_record_carriers();
void to_edit_instrument_record_weapons();
void to_edit_instrument_record_tank();
void to_edit_instrument_record_missilies();
void to_edit_instrument_record_bombs();
void to_add_whole_data_in_txt_carriers();
void to_add_whole_data_in_txt_tank();
void to_add_whole_data_in_txt_weapons();
void to_add_whole_data_in_txt_missilies();
void to_add_whole_data_in_txt_bombs();
void graph_ams();
void total_ams_budget();
// SUB OP 4
int to_show_sub_menu_army_crops_ams(int no_of_index);
void to_show_soc_khor();
void to_show_xxx_khor();
// sub op 5
void to_fetch_feedback();
//                               NMS USER
string main_menu_names_nms[5] = {"1. NAVY SOLDIERS", "2. NAVY OFFICERS", "3. INSTRUMENTS", "4. CROPS", "5. REPORT OF NAVY WORK"};
string sub_menu_navy_soldiers_nms[5] = {"1. PERSONAL DETAILS", "2. ADD NEW SOLDIER", "3. EDIT SOLDIER DETAIL", "4. RETIRED SOLDIERS", "5. MARTYRED"};
string sub_menu_instruments_nms[5] = {"1. DETAILS OF INSTRUMENT", "2. ADD NEW INSTRUMENTS", "3. EDIT INSTRUMENT DETAIL", "4. GRAPH OF INSTRUMENTS(RESULT OF BUDGET)", "5. BUDGET OF INSTRUMENT"};
string personal_details_options_nms_soldiers[8] = {"SOLDIER BATCH ID      : ", "SOLDIER NAME    : ", "SOLDIER FATHER NAME  : ", "SOLDIER PROVIENCE : ", "SOLDIER SALARY : ", "SOLDIER AGE : ", "SOLDIER RANK : ", "SOLDIER ID PASSWORD"};
string retired_options_nms[2] = {"1. VIEW RETIRED ", "2. ADD NEW RETIRED PERSON"};
string personal_details_options_nms_officers[8] = {"OFFICER BATCH ID      : ", "OFFICER NAME    : ", "OFFICER FATHER NAME  : ", "OFFICER PROVIENCE : ", "OFFICER SALARY : ", "OFFICER AGE : ", "OFFICER RANK : ", "OFFICER ID PASSWORD"};
string sub_menu_navy_officers_nms[7] = {"1. PERSONAL DETAILS", "2. ADD NEW OFFICERS", "3. EDIT OFFICER DETAILS", "4. RETIRED OFFICER", "5. MARTYRED", "6. OFFICERS IN PROVIENCE", "7. SOLDIERS UNDER OFFICERS"};
string sub_of_sub_menu_instruments_nms[5] = {"1. AIR CRAFT", "2. WEAPONS", "3. MISSILES", "4. SUBARINE", "5. SURFACE SHIP"};
string readable_instruments_nms[5] = {"NAME: ", "RANGE: ", "PRICE: ", "STOCK: ", "USING: "};
string nms_crops[2] = {"1. NAVAL-KHOR", "2. NAIZI-KHOR"};
int to_show_main_menu_nms(int no_of_index);
int to_show_sub_menu_navy_soldier_nms(int no_of_index);
int id_take_to_fetch_and_id_check_soldiers_nms();
int to_show_personal_details_from_navy_soldiers_array(int batch_id_index);
void to_show_personal_details_options_soldiers_nms();
void to_add_data_in_soldiers_array_nms();
void to_add_data_in_soldier_txt_nms();
void to_edit_data_in_soldiers_array_nms(int batch_id_index);
void to_add_whole_data_in_soldier_txt_nms();
int to_show_retired_menu_nms(int no_of_index);
void to_view_retired_soldier_data_nms();
void to_add_removed_soldier_in_retired_nms(int batch_index);
void to_remove_retired_soldier_from_array_nms(int batch_index);
void to_add_whole_data_in_retired_soldier_txt_nms();
int to_show_matryed_menu_nms(int no_of_index);
int to_view_matryed(string address);
int to_add_matryed(string address);
    // sub menu 2
int to_show_sub_menu_navy_officer_nms(int no_of_index);
int id_take_to_fetch_and_id_check_officer_nms();
int to_show_personal_details_from_navy_officer_array(int batch_id_index);
void to_show_personal_details_options_officer_nms();
void to_show_personal_details_options_officer_nms();
void to_add_data_in_officer_array_nms();
void to_add_data_in_officer_txt_nms();
void to_edit_data_in_officer_array_nms(int batch_id_index);
void to_add_whole_data_in_officer_txt_nms();
void to_view_retired_officer_data_nms();
void to_add_removed_officer_in_retired_nms(int batch_index);
void to_remove_retired_officer_from_array_nms(int batch_index);
void to_add_whole_data_in_retired_officer_txt_nms();
int to_see_data_from_nms_officer_arrray(int row,string provience);
string to_take_provience();
void soldier_under_officers_nms();
void soldier_under_officer_view_nms(int batch_id);
void soldier_under_officers_nms();
// sub op 3
int to_show_sub_menu_navy_instruments_nms(int no_of_index);
int to_show_sub_detail_view_navy_instruments_nms(int no_of_index);
void to_show_air_craft_details();
void to_show_weapons_details_navy();
void to_show_missilies_details_navy();
void to_show_subarine_details();
void to_show_surface_ships_details();
void to_add_data_in_array_air_craft();
void to_add_data_in_array_weapons_navy();
void to_add_data_in_array_missilies_navy();
void to_add_data_in_array_subarine();
void to_add_data_in_array_surface_ship();
void to_add_data_of_air_craft_in_txt();
void to_add_data_of_weapons_in_txt_navy();
void to_add_data_of_surface_ship_in_txt();
void to_add_data_of_missilies_in_txt_navy();
void to_add_data_of_subarine_in_txt();
void to_edit_instrument_record_air_craft();
void to_edit_instrument_record_weapons_navy();
void to_edit_instrument_record_subarine();
void to_edit_instrument_record_missilies_navy();
void to_edit_instrument_record_surface_ships();
void to_add_whole_data_in_txt_air_craft();
void to_add_whole_data_in_txt_subarine();
void to_add_whole_data_in_txt_weapons_navy();
void to_add_whole_data_in_txt_missilies_navy();
void to_add_whole_data_in_txt_surface_ships();
void graph_nms();
void total_nms_budget();
// SUB OP 4
int to_show_sub_menu_navy_crops_nms(int no_of_index);
void to_show_naizi_khor();
void to_show_naval_khor();
//                          AFMS
//                               AFMS USER
string main_menu_names_afms[5] = {"1. AIR FORCE SOLDIERS", "2. AIR FORCE OFFICERS", "3. INSTRUMENTS", "4. CROPS", "5. REPORT OF AIR FORCE WORK"};
string sub_menu_air_force_soldiers_afms[5] = {"1. PERSONAL DETAILS", "2. ADD NEW SOLDIER", "3. EDIT SOLDIER DETAIL", "4. RETIRED SOLDIERS", "5. MARTYRED"};
string sub_menu_instruments_afms[5] = {"1. DETAILS OF INSTRUMENT", "2. ADD NEW INSTRUMENTS", "3. EDIT INSTRUMENT DETAIL", "4. GRAPH OF INSTRUMENTS(RESULT OF BUDGET)", "5. BUDGET OF INSTRUMENT"};
string personal_details_options_afms_soldiers[8] = {"SOLDIER BATCH ID      : ", "SOLDIER NAME    : ", "SOLDIER FATHER NAME  : ", "SOLDIER PROVIENCE : ", "SOLDIER SALARY : ", "SOLDIER AGE : ", "SOLDIER RANK : ", "SOLDIER ID PASSWORD"};
string retired_options_afms[2] = {"1. VIEW RETIRED ", "2. ADD NEW RETIRED PERSON"};
string personal_details_options_afms_officers[8] = {"OFFICER BATCH ID      : ", "OFFICER NAME    : ", "OFFICER FATHER NAME  : ", "OFFICER PROVIENCE : ", "OFFICER SALARY : ", "OFFICER AGE : ", "OFFICER RANK : ", "OFFICER ID PASSWORD"};
string sub_menu_air_force_officers_afms[7] = {"1. PERSONAL DETAILS", "2. ADD NEW OFFICERS", "3. EDIT OFFICER DETAILS", "4. RETIRED OFFICER", "5. MARTYRED", "6. OFFICERS IN PROVIENCE", "7. SOLDIERS UNDER OFFICERS"};
string sub_of_sub_menu_instruments_afms[5] = {"1. AIR CRAFT", "2. WEAPONS", "3. MISSILES", "4. planes", "5. SURFACE SHIP"};
string readable_instruments_afms[5] = {"NAME: ", "RANGE: ", "PRICE: ", "STOCK: ", "USING: "};
string afms_crops[2] = {"1. NAVAL-KHOR", "2. NAIZI-KHOR"};
string soldiers_main_menu_asms[3] = {"1. VIEW PERSONAL DETAILS", "2. CALCULATE SALARY", "3. FEEDBACK"};
string personal_details_options_asms[8] = {"SOLDIER BATCH ID      : ", "SOLDIER NAME    : ", "SOLDIER FATHER NAME  : ", "SOLDIER PROVIENCE : ", "SOLDIER SALARY : ", "SOLDIER AGE : ", "SOLDIER RANK : ", "SOLDIER ID PASSWORD"};
int to_show_main_menu_afms(int no_of_index);
int to_show_sub_menu_air_force_soldier_afms(int no_of_index);
int id_take_to_fetch_and_id_check_soldiers_afms();
int to_show_personal_details_from_air_force_soldiers_array(int batch_id_index);
void to_show_personal_details_options_soldiers_afms();
void to_add_data_in_soldiers_array_afms();
void to_add_data_in_soldier_txt_afms();
void to_edit_data_in_soldiers_array_afms(int batch_id_index);
void to_add_whole_data_in_soldier_txt_afms();
int to_show_retired_menu_afms(int no_of_index);
void to_view_retired_soldier_data_afms();
void to_add_removed_soldier_in_retired_afms(int batch_index);
void to_remove_retired_soldier_from_array_afms(int batch_index);
void to_add_whole_data_in_retired_soldier_txt_afms();
int to_show_matryed_menu_afms(int no_of_index);
int to_view_matryed(string address);
int to_add_matryed(string address);
    // sub menu 2
int to_show_sub_menu_air_force_officer_afms(int no_of_index);
int id_take_to_fetch_and_id_check_officer_afms();
int to_show_personal_details_from_air_force_officer_array(int batch_id_index);
void to_show_personal_details_options_officer_afms();
void to_show_personal_details_options_officer_afms();
void to_add_data_in_officer_array_afms();
void to_add_data_in_officer_txt_afms();
void to_edit_data_in_officer_array_afms(int batch_id_index);
void to_add_whole_data_in_officer_txt_afms();
void to_view_retired_officer_data_afms();
void to_add_removed_officer_in_retired_afms(int batch_index);
void to_remove_retired_officer_from_array_afms(int batch_index);
void to_add_whole_data_in_retired_officer_txt_afms();
int to_see_data_from_afms_officer_arrray(int row,string provience);
string to_take_provience();
void soldier_under_officers_afms();
void soldier_under_officer_view_afms(int batch_id);
void soldier_under_officers_afms();
// sub op 3
int to_show_sub_menu_air_force_instruments_afms(int no_of_index);
int to_show_sub_detail_view_air_force_instruments_afms(int no_of_index);
void to_show_air_craft_details_air_force();
void to_show_weapons_details_air_force();
void to_show_missilies_details_air_force();
void to_show_planes_details();
void to_show_trackers_details();
void to_add_data_in_array_air_craft_air_force();
void to_add_data_in_array_weapons_air_force();
void to_add_data_in_array_missilies_air_force();
void to_add_data_in_array_planes();
void to_add_data_in_array_trackers();
void to_add_data_of_air_craft_in_txt_air_force();
void to_add_data_of_weapons_in_txt_air_force();
void to_add_data_of_trackers_in_txt();
void to_add_data_of_missilies_in_txt_air_force();
void to_add_data_of_planes_in_txt();
void to_edit_instrument_record_air_craft_air_force();
void to_edit_instrument_record_weapons_air_force();
void to_edit_instrument_record_planes();
void to_edit_instrument_record_missilies_air_force();
void to_edit_instrument_record_trackers();
void to_add_whole_data_in_txt_air_craft_air_force();
void to_add_whole_data_in_txt_planes();
void to_add_whole_data_in_txt_weapons_air_force();
void to_add_whole_data_in_txt_missilies_air_force();
void to_add_whole_data_in_txt_trackers();
void graph_afms();
void total_afms_budget();
// SUB OP 4
int to_show_sub_menu_air_force_crops_afms(int no_of_index);
void to_show_him_khor();
void to_show_nav_khor();
//                                  user 4
string gto_tasks_marks[5][6];
string psychologist_tasks_marks[5][6];
string candidate_batch_id[5];
int total_candidatr_marks_gto[5];
int total_candidatr_marks_psychologist[5];
string aoms_main_menus[5] = {"1. PERSONAL DETAILS", "2. VIEW SOLDIERS", "3. CANDIDATES SELECTOR", "4. WAR IDEA", "5. CODE BY CROPS"};
string aoms_issb_selector_option[2] = {"1. GTO", "2. PSYCHOLOGYIST"};
string gto_tasks[6] = {"MILTARY PLANING", "GROUP DISCUSSION", "OUTDOOR TASK", "OBSTACLES", "LECTURE", "TEAM WORK"};
string psychologist_tasks[6] = {"WORDS TESTS", "ALGORITHM TEST", "INTERVIEW", "ATITUDE", "SCREEN TEST", "NON VERBAL TEST"};
int to_show_main_menu_aoms(int no_of_index);
int to_show_personal_details_from_aoms();
void to_show_personal_details_options_aoms();
int to_show_gto_tasks(int no_of_index);
int to_show_psychologist_tasks(int no_of_index);
int to_get_candidate_marks_gto();
int to_get_candidate_marks_psychologist();
int to_show_personal_selector_details_options_aoms(int no_of_index);
int to_input_war_ideas();
int to_show_main_war_ideas();
int code_by_corp();
void to_add_data_in_txt_feedback_psychologist();
void to_add_data_in_txt_feedback_gto();
void to_get_candidates_batch_id();
// 5 and 6th user
int to_show_personal_details_from_noms();
int to_show_personal_details_from_afoms();
//                              ASMS THINGS USER 7
int to_show_main_menu_asms(int no_of_index);
void to_show_personal_details_options_asms();
int to_show_personal_details_from_asms();
main()
{
    fetch_all_data_at_start();
    int checker_of_user_domain;
user_login:
    screen_size();
    checker_of_user_domain = user_id();

    if (checker_of_user_domain == 1)
    {
        army_management_team_system(checker_of_user_domain);
        goto user_login;
    }
    if (checker_of_user_domain == 2)
    {
        navy_management_team_system(checker_of_user_domain);
        goto user_login;
    }
    if (checker_of_user_domain == 3)
    {
        air_force_management_team_system(checker_of_user_domain);
        goto user_login;
    }
    if (checker_of_user_domain == 4)
    {
        army_officer_management_system(checker_of_user_domain);
        goto user_login;
    }
    
    if (checker_of_user_domain == 5)
    {
        navy_officer_management_system(checker_of_user_domain);
        goto user_login;
    }
    
    if (checker_of_user_domain == 6)
    {
        air_force_officer_management_system(checker_of_user_domain);
        goto user_login;
    }
    if (checker_of_user_domain == 7)
    {
        soldiers_management_system(checker_of_user_domain);
        goto user_login;
    }
}
// 1. ARMY MANAGEMENT SYSTEM
int army_management_team_system(int checker_of_user_domain)
{
    
    int sub_selected_instruments;
    int main_selected_option_of_ams;
    int sub_select_of_army_instruments_ams, sub_select_of_army_soldier_ams, sub_select_of_army_officer_ams;
    int item_quantity[5];
// Main Menu of ARMY TEAM MANAGEMENT SYSTEM
    ams_top_menu:
    title("ARMY TEAM MANAGEMENT SYSTEM");
    to_show_main_menu_ams(5);
    main_selected_option_of_ams = selecting_function(columns_of_screen / 3 + 10,12,5);
    // army soldiers in ams // COMPLETE
    while (main_selected_option_of_ams == 1)
    {
        army_soldiers_menu:
        title("ARMY TEAM MANAGEMENT SYSTEM");
        to_show_sub_menu_army_soldier_ams(5);
        sub_select_of_army_soldier_ams = selecting_function(columns_of_screen / 3 + 10,12,5);
        // View Personal details of Soldiers 1
        while (sub_select_of_army_soldier_ams == 1)
        {
            int check_batch_id;
            int batch_id_idx;
            title("PERSONAL DETAILS OF ARMY SOLDIER");
            batch_id_idx = id_take_to_fetch_and_id_check_soldiers_ams();
            check_batch_id = to_show_personal_details_from_soldiers_array(batch_id_idx);
            if (check_batch_id == 1)
            {
                sub_select_of_army_soldier_ams = yes_or_no(sub_select_of_army_soldier_ams);
                if (sub_select_of_army_soldier_ams == 0 )
                {
                    goto army_soldiers_menu;
                }
            }
        }
        // ADD NEW RECORD 2
        while (sub_select_of_army_soldier_ams == 2)
        {
            title("ADD DETAILS OF ARMY SOLDIER");
            to_show_note("120-");
            to_add_data_in_soldiers_array_ams();
            to_add_data_in_soldier_txt_ams();
            sub_select_of_army_soldier_ams = yes_or_no(sub_select_of_army_soldier_ams);
            if (sub_select_of_army_soldier_ams == 0 )
            {   

                goto army_soldiers_menu;
            }
        }
        // EDIT RECORD 3
        while (sub_select_of_army_soldier_ams == 3)
        {
            int check_batch_idx;
            int batch_id_index;
            title("EDIT DETAILS OF ARMY SOLDIER");
            batch_id_index = id_take_to_fetch_and_id_check_soldiers_ams();
            to_edit_data_in_soldiers_array_ams(batch_id_index);
            to_add_whole_data_in_soldier_txt_ams();
            sub_select_of_army_soldier_ams = yes_or_no(sub_select_of_army_soldier_ams);
            if (sub_select_of_army_soldier_ams == 0)
            {
                goto army_soldiers_menu;
            }
        }
        // RETIRED OFFICERS 4
        while (sub_select_of_army_soldier_ams == 4)
        {   retired_main_menu:
            int sub_option_of_retired_soldiers;
            title("RETIRED SOLDIERS MANAGEMENT");
            to_show_retired_menu_ams(2);
            sub_option_of_retired_soldiers = selecting_function(columns_of_screen / 3 + 10, 17,2);
            // to view retired soldiers
            while(sub_option_of_retired_soldiers == 1)
            {
                to_view_retired_soldier_data_ams();
                sub_option_of_retired_soldiers = yes_or_no(sub_option_of_retired_soldiers);
                if(sub_option_of_retired_soldiers == 0)
                {
                    goto retired_main_menu;
                }
            }
            // to add new retired soldiers
            while(sub_option_of_retired_soldiers == 2)
            {
                int batch_id_index;
                batch_id_index = id_take_to_fetch_and_id_check_soldiers_ams();
                to_add_removed_soldier_in_retired_ams(batch_id_index);
                to_remove_retired_soldier_from_array_ams(batch_id_index);
                to_add_whole_data_in_soldier_txt_ams();
                to_add_whole_data_in_retired_soldier_txt_ams();
                sub_option_of_retired_soldiers = yes_or_no(sub_option_of_retired_soldiers);
                if(sub_option_of_retired_soldiers == 0)
                {
                    goto retired_main_menu;
                }
            }

            if(sub_option_of_retired_soldiers == 3)
            {
                goto army_soldiers_menu;
            }
            
        }
        // MATRYED 5
        while (sub_select_of_army_soldier_ams == 5)
        {
            matryed:
            int sub_option_of_matryed_officers;
            title("HEROES OF OUR NATION");
            to_show_matryed_menu_ams(2);
            sub_option_of_matryed_officers = selecting_function(columns_of_screen / 3 + 10, 17,2);
            if (sub_option_of_matryed_officers == 1)
            {
                system("cls");
                title("HEROES OF OUR NATION");
                to_view_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed;
                }
            }
            else if (sub_option_of_matryed_officers == 2)
            {
                title("HEROES OF OUR NATION");
                to_add_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed;
                }
            }
            else if (sub_option_of_matryed_officers == 3)
            {
                goto army_soldiers_menu;
            }
        }
        // GO TO AMS TOP MENU IN 6
        if (sub_select_of_army_soldier_ams == 6)
        {
            goto ams_top_menu;
        }
        
    }
    // ARMY OFFICERS IN AMS // complete
    while (main_selected_option_of_ams == 2)
    {
        army_officers_menu:
        title("ARMY TEAM MANAGEMENT SYSTEM");
        to_show_sub_menu_army_officer_ams(7);
        sub_select_of_army_officer_ams = selecting_function(columns_of_screen / 3 + 10, 12,7);
        // View Personal details of Officers 1
        while (sub_select_of_army_officer_ams == 1)
        {
            int check_batch_id;
            int batch_id_idx;
            title("PERSONAL DETAILS OF ARMY OFFICER");
            batch_id_idx = id_take_to_fetch_and_id_check_officer_ams();
            check_batch_id = to_show_personal_details_from_officer_array(batch_id_idx);
            if (check_batch_id == 1)
            {
                sub_select_of_army_officer_ams = yes_or_no(sub_select_of_army_officer_ams);
                if (sub_select_of_army_officer_ams == 0 )
                {
                    goto army_officers_menu;
                }
            }
        }
         // ADD NEW RECORD 2
        while (sub_select_of_army_officer_ams == 2)
        {
            title("ADD DETAILS OF ARMY OFFICER");
            to_show_note("PMI-");
            to_add_data_in_officer_array_ams();
            to_add_data_in_officer_txt_ams();
            sub_select_of_army_officer_ams = yes_or_no(sub_select_of_army_officer_ams);
            if (sub_select_of_army_officer_ams == 0 )
            {
                goto army_officers_menu;
            }
        }
        // EDIT RECORD 3
        while (sub_select_of_army_officer_ams == 3)
        {
            int check_batch_idx;
            int batch_id_index;
            title("EDIT DETAILS OF ARMY SOLDIER");
            batch_id_index = id_take_to_fetch_and_id_check_officer_ams();
            to_edit_data_in_officer_array_ams(batch_id_index);
            to_add_whole_data_in_officer_txt_ams();
            sub_select_of_army_officer_ams = yes_or_no(sub_select_of_army_officer_ams);
            if (sub_select_of_army_officer_ams == 0)
            {
                goto army_officers_menu;
            }
        }
        // RETIRED OFFICERS 4
        while (sub_select_of_army_officer_ams == 4)
        {   retired_main_menu_officer:
            int sub_option_of_retired_officer;
            title("RETIRED OFFICERS MANAGEMENT");
            to_show_retired_menu_ams(2);
            sub_option_of_retired_officer = selecting_function(columns_of_screen / 3 + 10, 17,2);
            // to view retired soldiers
            while(sub_option_of_retired_officer == 1)
            {
                to_view_retired_officer_data_ams();
                sub_option_of_retired_officer = yes_or_no(sub_option_of_retired_officer);
                if(sub_option_of_retired_officer == 0)
                {
                    goto retired_main_menu_officer;
                }
            }
            // to add new retired soldiers
            while(sub_option_of_retired_officer == 2)
            {
                int batch_id_index;
                batch_id_index = id_take_to_fetch_and_id_check_officer_ams();
                to_add_removed_officer_in_retired_ams(batch_id_index);
                to_remove_retired_officer_from_array_ams(batch_id_index);
                to_add_whole_data_in_officer_txt_ams();
                to_add_whole_data_in_retired_officer_txt_ams();
                sub_option_of_retired_officer = yes_or_no(sub_option_of_retired_officer);
                if(sub_option_of_retired_officer == 0)
                {
                    goto retired_main_menu_officer;
                }
            }
            if(sub_option_of_retired_officer == 3)
            {
                goto army_officers_menu;
            }
            
        }
        // MATRYED 5
        while (sub_select_of_army_officer_ams == 5)
        {
            matryed_officer:
            int sub_option_of_matryed_officers;
            title("HEROES OF OUR NATION");
            to_show_matryed_menu_ams(2);
            sub_option_of_matryed_officers = selecting_function(columns_of_screen / 3 + 10, 17,2);
            if (sub_option_of_matryed_officers == 1)
            {
                system("cls");
                title("HEROES OF OUR NATION");
                to_view_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed_officer;
                }
            }
            else if (sub_option_of_matryed_officers == 2)
            {
                title("HEROES OF OUR NATION");
                to_add_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed_officer;
                }
            }
            else if (sub_option_of_matryed_officers == 3)
            {
                goto army_officers_menu;
            }
        }  
        // Officers in Provience 6
        while (sub_select_of_army_officer_ams == 6)
        {
            string prov; // provience
            int count_officers = 0;
            prov = to_take_provience();
            count_officers = to_see_data_from_ams_officer_arrray(3,prov);
            sub_select_of_army_officer_ams = yes_or_no(sub_select_of_army_officer_ams);
            if(sub_select_of_army_officer_ams == 0)
                {
                    goto army_officers_menu;
                }
        }
        // Soldiers under Officers 7
        while (sub_select_of_army_officer_ams == 7)
        {   
            int batch_id_index;
            string check_batch_id;
            title("SOLDIERS UNDER THE OFFICER");
            soldier_under_officers_ams();
            batch_id_index = id_take_to_fetch_and_id_check_officer_ams();
            soldier_under_officer_view_ams(batch_id_index);
            sub_select_of_army_officer_ams = yes_or_no(sub_select_of_army_officer_ams);
            if(sub_select_of_army_officer_ams == 0)
            {
                goto army_officers_menu;
            }

        }
        // GO TO AGAIN LOG IN 8
        while (sub_select_of_army_officer_ams == 8)
        {
            goto ams_top_menu;
        }
    }
    // ARMY INSTRUMENTS // COMPLETE
    while (main_selected_option_of_ams == 3)
    {
        sub_menu_instruments:
        int sub_of_sub_selected_instruments;
        title("ARMY TEAM MANAGEMENT SYSTEM");
        to_show_sub_menu_army_instruments_ams(5);
        sub_select_of_army_instruments_ams = selecting_function(columns_of_screen / 3 + 10, 12,5);
        // VIEW INSTRUMENTS 1
        while (sub_select_of_army_instruments_ams == 1)
        {   
            instrument_stayer:
            int sub_of_sub_selected_instruments;
            title("INSTRUMENTS MANAGEMENT SYSTEM");
            to_show_sub_detail_view_army_instruments_ams(5);
            sub_of_sub_selected_instruments = selecting_function(columns_of_screen / 3 + 10, 12,5);
            // Carriers
            while (sub_of_sub_selected_instruments == 1)
            {
                to_show_carriers_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // Weapons
            while (sub_of_sub_selected_instruments == 2)
            {
                
                to_show_weapons_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // missiles
            while (sub_of_sub_selected_instruments == 3)
            {
                to_show_missilies_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // tanks
            while (sub_of_sub_selected_instruments == 4)
            {
                to_show_tank_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // atomic Bomb
            while (sub_of_sub_selected_instruments == 5)
            {
                to_show_atomic_bombs_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // back
            while (sub_of_sub_selected_instruments == 6)
            {
                goto sub_menu_instruments;
            }
        }
        // Add INSTRUMENTS
        while (sub_select_of_army_instruments_ams == 2)
        {
            INS_PLACE_2:
            int sub_of_sub_selected_instruments;
            title("INSTRUMENTS MANAGEMENT SYSTEM");
            to_show_sub_detail_view_army_instruments_ams(5);
            sub_of_sub_selected_instruments = selecting_function(columns_of_screen / 3 + 10, 12,5);
            while (sub_of_sub_selected_instruments == 1)
            {
                to_show_carriers_details();
                to_add_data_in_array_carrier();
                to_add_data_of_carrier_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // Weapons
            while (sub_of_sub_selected_instruments == 2)
            {
                
                to_show_weapons_details();
                to_add_data_in_array_weapons();
                to_add_data_of_weapons_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // missiles
            while (sub_of_sub_selected_instruments == 3)
            {
                to_add_data_in_array_missilies();
                to_show_missilies_details();
                to_add_data_of_missilies_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // tanks
            while (sub_of_sub_selected_instruments == 4)
            {
                to_show_tank_details();
                to_add_data_in_array_tank();
                to_add_data_of_tank_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // atomic Bomb
            while (sub_of_sub_selected_instruments == 5)
            {
                to_show_atomic_bombs_details();
                to_add_data_in_array_bomb();
                to_add_data_of_bomb_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // back
            while (sub_of_sub_selected_instruments == 6)
            {
                goto sub_menu_instruments;
            }
            
        }
        // edit instruments
        while(sub_select_of_army_instruments_ams == 3)
        {
            instrument_stayer_edit:
            int sub_of_sub_selected_instruments;
            title("INSTRUMENTS MANAGEMENT SYSTEM");
            to_show_sub_detail_view_army_instruments_ams(5);
            sub_of_sub_selected_instruments = selecting_function(columns_of_screen / 3 + 10, 12,5);
               while (sub_of_sub_selected_instruments == 1)
            {
                to_edit_instrument_record_carriers();
                to_add_whole_data_in_txt_carriers();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 2)
            {
                to_edit_instrument_record_weapons();
                to_add_whole_data_in_txt_weapons();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 3)
            {
                to_edit_instrument_record_missilies();
                to_add_whole_data_in_txt_missilies();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 4)
            {
                to_edit_instrument_record_tank();
                to_add_whole_data_in_txt_tank();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 5)
            {
                to_edit_instrument_record_bombs();
                to_add_whole_data_in_txt_bombs();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while(sub_of_sub_selected_instruments == 6)
            {
                goto sub_menu_instruments;
            }
            
        }
         // graph
        while (sub_select_of_army_instruments_ams == 4)
        {
            system("cls");
            title("GRAPH OF BUDGET");
            graph_ams();
            Sleep(5000);
            sub_select_of_army_instruments_ams = yes_or_no(sub_select_of_army_instruments_ams);
            if(sub_select_of_army_instruments_ams == 0)
            {
                goto sub_menu_instruments;
            }
        }
        // Budget Calculate
        while (sub_select_of_army_instruments_ams == 5)
        {
            float total;
            title("THE ARMY BUDGET");
            total_ams_budget();
            sub_select_of_army_instruments_ams = yes_or_no(sub_select_of_army_instruments_ams);
            if(sub_select_of_army_instruments_ams == 0)
            {
                goto sub_menu_instruments;
            }
        }
        //Back
        while (sub_selected_instruments == 6 || sub_select_of_army_instruments_ams == 6)
        {
            goto ams_top_menu;
        }
    }
    // CROPS
    while (main_selected_option_of_ams == 4)
    {
        int sub_select_of_crops_ams;
        menu_crops:
        title("CROPS MANAGEMENT SYSTEM");
        to_show_sub_menu_army_crops_ams(2);
        sub_select_of_crops_ams = selecting_function(columns_of_screen / 3 + 10,12,2);
        while(sub_select_of_crops_ams == 1)
        {
            to_show_xxx_khor();
            sub_select_of_crops_ams = yes_or_no(sub_select_of_crops_ams);
            if(sub_select_of_crops_ams == 0)
            {
                goto menu_crops;
            }
        }
        while(sub_select_of_crops_ams == 2)
        {
            to_show_soc_khor();
            sub_select_of_crops_ams = yes_or_no(sub_select_of_crops_ams);
            if(sub_select_of_crops_ams == 0)
            {
                goto menu_crops;
            }
        }
        if (sub_select_of_crops_ams ==  3)
        {
            goto ams_top_menu;
        }
    }
    // Report of work
    while (main_selected_option_of_ams == 5)
    {
        
        to_fetch_feedback();
        main_selected_option_of_ams = yes_or_no(main_selected_option_of_ams);
        if (main_selected_option_of_ams == 0)
        {
            goto ams_top_menu;
        }
    }
}
// 1. ARMY MANAGEMENT SYSTEM ENDED
// 2. NAVY MANAGEMENT SYSTEM
int navy_management_team_system(int checker_of_user_domain)
{
    
    int sub_selected_instruments;
    int main_selected_option_of_nms;
    int sub_select_of_navy_instruments_nms, sub_select_of_navy_soldier_nms, sub_select_of_navy_officer_nms;
    int item_quantity[5];
// Main Menu of NAVY TEAM MANAGEMENT SYSTEM
nms_top_menu:
    title("NAVY TEAM MANAGEMENT SYSTEM");
    to_show_main_menu_nms(5);
    
    main_selected_option_of_nms = selecting_function(columns_of_screen / 3 + 10,12,5);
    // NAVY soldiers in nms // COMPLETE
    while (main_selected_option_of_nms == 1)
    {
    navy_soldiers_menu:
        title("NAVY TEAM MANAGEMENT SYSTEM");
        to_show_sub_menu_navy_soldier_nms(5);
        sub_select_of_navy_soldier_nms = selecting_function(columns_of_screen / 3 + 10,12,5);
        // View Personal details of Soldiers 1
        while (sub_select_of_navy_soldier_nms == 1)
        {
            int check_batch_id;
            int batch_id_idx;
            title("PERSONAL DETAILS OF NAVY SOLDIER");
            batch_id_idx = id_take_to_fetch_and_id_check_soldiers_nms();
            check_batch_id = to_show_personal_details_from_navy_soldiers_array(batch_id_idx);
            if (check_batch_id == 1)
            {
                sub_select_of_navy_soldier_nms = yes_or_no(sub_select_of_navy_soldier_nms);
                if (sub_select_of_navy_soldier_nms == 0 )
                {
                    goto navy_soldiers_menu;
                }
            }
        }
        // ADD NEW RECORD 2
        while (sub_select_of_navy_soldier_nms == 2)
        {
            title("ADD DETAILS OF NAVY SOLDIER");
            to_show_note("121-");
            to_add_data_in_soldiers_array_nms();
            to_add_data_in_soldier_txt_nms();
            sub_select_of_navy_soldier_nms = yes_or_no(sub_select_of_navy_soldier_nms);
            if (sub_select_of_navy_soldier_nms == 0 )
            {
                goto navy_soldiers_menu;
            }
        }
        // EDIT RECORD 3
        while (sub_select_of_navy_soldier_nms == 3)
        {
            int check_batch_idx;
            int batch_id_index;
            title("EDIT DETAILS OF NAVY SOLDIER");
            batch_id_index = id_take_to_fetch_and_id_check_soldiers_nms();
            to_edit_data_in_soldiers_array_nms(batch_id_index);
            to_add_whole_data_in_soldier_txt_nms();
            sub_select_of_navy_soldier_nms = yes_or_no(sub_select_of_navy_soldier_nms);
            if (sub_select_of_navy_soldier_nms == 0)
            {
                goto navy_soldiers_menu;
            }
        }
        // RETIRED OFFICERS 4
        while (sub_select_of_navy_soldier_nms == 4)
        {   retired_main_menu:
            int sub_option_of_retired_soldiers;
            title("RETIRED SOLDIERS MANAGEMENT");
            to_show_retired_menu_nms(2);
            sub_option_of_retired_soldiers = selecting_function(columns_of_screen / 3 + 10, 17,2);
            // to view retired soldiers
            while(sub_option_of_retired_soldiers == 1)
            {
                to_view_retired_soldier_data_nms();
                sub_option_of_retired_soldiers = yes_or_no(sub_option_of_retired_soldiers);
                if(sub_option_of_retired_soldiers == 0)
                {
                    goto retired_main_menu;
                }
            }
            // to add new retired soldiers
            while(sub_option_of_retired_soldiers == 2)
            {
                int batch_id_index;
                batch_id_index = id_take_to_fetch_and_id_check_soldiers_nms();
                to_add_removed_soldier_in_retired_nms(batch_id_index);
                to_remove_retired_soldier_from_array_nms(batch_id_index);
                to_add_whole_data_in_soldier_txt_nms();
                to_add_whole_data_in_retired_soldier_txt_nms();
                sub_option_of_retired_soldiers = yes_or_no(sub_option_of_retired_soldiers);
                if(sub_option_of_retired_soldiers == 0)
                {
                    goto retired_main_menu;
                }
            }

            if(sub_option_of_retired_soldiers == 3)
            {
                goto navy_soldiers_menu;
            }
            
        }
        // MATRYED 5
        while (sub_select_of_navy_soldier_nms == 5)
        {
            matryed:
            int sub_option_of_matryed_officers;
            title("HEROES OF OUR NATION");
            to_show_matryed_menu_nms(2);
            sub_option_of_matryed_officers = selecting_function(columns_of_screen / 3 + 10, 17,2);
            if (sub_option_of_matryed_officers == 1)
            {
                system("cls");
                title("HEROES OF OUR NATION");
                to_view_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed;
                }
            }
            else if (sub_option_of_matryed_officers == 2)
            {
                title("HEROES OF OUR NATION");
                to_add_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed;
                }
            }
            else if (sub_option_of_matryed_officers == 3)
            {
                goto navy_soldiers_menu;
            }
        }
        // GO TO nms TOP MENU IN 6
        if (sub_select_of_navy_soldier_nms == 6)
        {
            goto nms_top_menu;
        }
        
    }
    // NAVY OFFICERS IN nms // complete
    while (main_selected_option_of_nms == 2)
    {
        navy_officers_menu:
        title("NAVY TEAM MANAGEMENT SYSTEM");
        to_show_sub_menu_navy_officer_nms(7);
        sub_select_of_navy_officer_nms = selecting_function(columns_of_screen / 3 + 10, 12,7);
        // View Personal details of Officers 1
        while (sub_select_of_navy_officer_nms == 1)
        {
            int check_batch_id;
            int batch_id_idx;
            title("PERSONAL DETAILS OF NAVY OFFICER");
            batch_id_idx = id_take_to_fetch_and_id_check_officer_nms();
            check_batch_id = to_show_personal_details_from_navy_officer_array(batch_id_idx);
            if (check_batch_id == 1)
            {
                sub_select_of_navy_officer_nms = yes_or_no(sub_select_of_navy_officer_nms);
                if (sub_select_of_navy_officer_nms == 0 )
                {
                    goto navy_officers_menu;
                }
            }
        }
         // ADD NEW RECORD 2
        while (sub_select_of_navy_officer_nms == 2)
        {
            title("ADD DETAILS OF NAVY OFFICER");
            to_show_note("NAV-");
            to_add_data_in_officer_array_nms();
            to_add_data_in_officer_txt_nms();
            sub_select_of_navy_officer_nms = yes_or_no(sub_select_of_navy_officer_nms);
            if (sub_select_of_navy_officer_nms == 0 )
            {
                goto navy_officers_menu;
            }
        }
        // EDIT RECORD 3
        while (sub_select_of_navy_officer_nms == 3)
        {
            int check_batch_idx;
            int batch_id_index;
            title("EDIT DETAILS OF NAVY SOLDIER");
            batch_id_index = id_take_to_fetch_and_id_check_officer_nms();
            to_edit_data_in_officer_array_nms(batch_id_index);
            to_add_whole_data_in_officer_txt_nms();
            sub_select_of_navy_officer_nms = yes_or_no(sub_select_of_navy_officer_nms);
            if (sub_select_of_navy_officer_nms == 0)
            {
                goto navy_officers_menu;
            }
        }
        // RETIRED OFFICERS 4
        while (sub_select_of_navy_officer_nms == 4)
        {   retired_main_menu_officer:
            int sub_option_of_retired_officer;
            title("RETIRED OFFICERS MANAGEMENT");
            to_show_retired_menu_nms(2);
            sub_option_of_retired_officer = selecting_function(columns_of_screen / 3 + 10, 17,2);
            // to view retired soldiers
            while(sub_option_of_retired_officer == 1)
            {
                to_view_retired_officer_data_nms();
                sub_option_of_retired_officer = yes_or_no(sub_option_of_retired_officer);
                if(sub_option_of_retired_officer == 0)
                {
                    goto retired_main_menu_officer;
                }
            }
            // to add new retired soldiers
            while(sub_option_of_retired_officer == 2)
            {
                int batch_id_index;
                batch_id_index = id_take_to_fetch_and_id_check_officer_nms();
                to_add_removed_officer_in_retired_nms(batch_id_index);
                to_remove_retired_officer_from_array_nms(batch_id_index);
                to_add_whole_data_in_officer_txt_nms();
                to_add_whole_data_in_retired_officer_txt_nms();
                sub_option_of_retired_officer = yes_or_no(sub_option_of_retired_officer);
                if(sub_option_of_retired_officer == 0)
                {
                    goto retired_main_menu_officer;
                }
            }
            if(sub_option_of_retired_officer == 3)
            {
                goto navy_officers_menu;
            }
            
        }
        // MATRYED 5
        while (sub_select_of_navy_officer_nms == 5)
        {
            matryed_officer:
            int sub_option_of_matryed_officers;
            title("HEROES OF OUR NATION");
            to_show_matryed_menu_nms(2);
            sub_option_of_matryed_officers = selecting_function(columns_of_screen / 3 + 10, 17,2);
            if (sub_option_of_matryed_officers == 1)
            {
                system("cls");
                title("HEROES OF OUR NATION");
                to_view_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed_officer;
                }
            }
            else if (sub_option_of_matryed_officers == 2)
            {
                title("HEROES OF OUR NATION");
                to_add_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed_officer;
                }
            }
            else if (sub_option_of_matryed_officers == 3)
            {
                goto navy_officers_menu;
            }
        }  
        // Officers in Provience 6
        while (sub_select_of_navy_officer_nms == 6)
        {
            string prov; // provience
            int count_officers = 0;
            prov = to_take_provience();
            count_officers = to_see_data_from_nms_officer_arrray(3,prov);
            sub_select_of_navy_officer_nms = yes_or_no(sub_select_of_navy_officer_nms);
            if(sub_select_of_navy_officer_nms == 0)
                {
                    goto navy_officers_menu;
                }
        }
        // Soldiers under Officers 7
        while (sub_select_of_navy_officer_nms == 7)
        {   
            int batch_id_index;
            string check_batch_id;
            title("SOLDIERS UNDER THE OFFICER");
            soldier_under_officers_nms();
            batch_id_index = id_take_to_fetch_and_id_check_officer_nms();
            soldier_under_officer_view_nms(batch_id_index);
            sub_select_of_navy_officer_nms = yes_or_no(sub_select_of_navy_officer_nms);
            if(sub_select_of_navy_officer_nms == 0)
            {
                goto navy_officers_menu;
            }

        }
        // GO TO AGAIN LOG IN 8
        while (sub_select_of_navy_officer_nms == 8)
        {
            goto nms_top_menu;
        }
    }
    // NAVY INSTRUMENTS // COMPLETE
    while (main_selected_option_of_nms == 3)
    {
        sub_menu_instruments:
        int sub_of_sub_selected_instruments;
        title("NAVY TEAM MANAGEMENT SYSTEM");
        to_show_sub_menu_navy_instruments_nms(5);
        sub_select_of_navy_instruments_nms = selecting_function(columns_of_screen / 3 + 10, 12,5);
        // VIEW INSTRUMENTS 1
        while (sub_select_of_navy_instruments_nms == 1)
        {   
            instrument_stayer:
            int sub_of_sub_selected_instruments;
            title("INSTRUMENTS MANAGEMENT SYSTEM");
            to_show_sub_detail_view_navy_instruments_nms(5);
            sub_of_sub_selected_instruments = selecting_function(columns_of_screen / 3 + 10, 12,5);
            // air_craft
            while (sub_of_sub_selected_instruments == 1)
            {
                to_show_air_craft_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // Weapons
            while (sub_of_sub_selected_instruments == 2)
            {
                
                to_show_weapons_details_navy();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // missiles
            while (sub_of_sub_selected_instruments == 3)
            {
                to_show_missilies_details_navy();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // subarines
            while (sub_of_sub_selected_instruments == 4)
            {
                to_show_subarine_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // atomic surface_ship
            while (sub_of_sub_selected_instruments == 5)
            {
                to_show_surface_ships_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // back
            while (sub_of_sub_selected_instruments == 6)
            {
                goto sub_menu_instruments;
            }
        }
        // Add INSTRUMENTS
        while (sub_select_of_navy_instruments_nms == 2)
        {
            INS_PLACE_2:
            int sub_of_sub_selected_instruments;
            title("INSTRUMENTS MANAGEMENT SYSTEM");
            to_show_sub_detail_view_navy_instruments_nms(5);
            sub_of_sub_selected_instruments = selecting_function(columns_of_screen / 3 + 10, 12,5);
            while (sub_of_sub_selected_instruments == 1)
            {
                to_show_air_craft_details();
                to_add_data_in_array_air_craft();
                to_add_data_of_air_craft_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // Weapons
            while (sub_of_sub_selected_instruments == 2)
            {
                
                to_show_weapons_details_navy();
                to_add_data_in_array_weapons_navy();
                to_add_data_of_weapons_in_txt_navy();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // missiles
            while (sub_of_sub_selected_instruments == 3)
            {
                to_show_missilies_details_navy();
                to_add_data_in_array_missilies_navy();
                to_add_data_of_missilies_in_txt_navy();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // subarines
            while (sub_of_sub_selected_instruments == 4)
            {
                to_show_subarine_details();
                to_add_data_in_array_subarine();
                to_add_data_of_subarine_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // atomic surface_ship
            while (sub_of_sub_selected_instruments == 5)
            {
                to_show_surface_ships_details();
                to_add_data_in_array_surface_ship();
                to_add_data_of_surface_ship_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // back
            while (sub_of_sub_selected_instruments == 6)
            {
                goto sub_menu_instruments;
            }
            
        }
        // edit instruments
        while(sub_select_of_navy_instruments_nms == 3)
        {
            instrument_stayer_edit:
            int sub_of_sub_selected_instruments;
            title("INSTRUMENTS MANAGEMENT SYSTEM");
            to_show_sub_detail_view_navy_instruments_nms(5);
            sub_of_sub_selected_instruments = selecting_function(columns_of_screen / 3 + 10, 12,5);
               while (sub_of_sub_selected_instruments == 1)
            {
                to_edit_instrument_record_air_craft();
                to_add_whole_data_in_txt_air_craft();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 2)
            {
                to_edit_instrument_record_weapons_navy();
                to_add_whole_data_in_txt_weapons_navy();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 3)
            {
                to_edit_instrument_record_missilies_navy();
                to_add_whole_data_in_txt_missilies_navy();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 4)
            {
                to_edit_instrument_record_subarine();
                to_add_whole_data_in_txt_subarine();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 5)
            {
                to_edit_instrument_record_surface_ships();
                to_add_whole_data_in_txt_surface_ships();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while(sub_of_sub_selected_instruments == 6)
            {
                goto sub_menu_instruments;
            }
            
        }
         // graph
        while (sub_select_of_navy_instruments_nms == 4)
        {
            system("cls");
            title("GRAPH OF BUDGET");
            graph_nms();
            Sleep(5000);
            sub_select_of_navy_instruments_nms = yes_or_no(sub_select_of_navy_instruments_nms);
            if(sub_select_of_navy_instruments_nms == 0)
            {
                goto sub_menu_instruments;
            }
        }
        // Budget Calculate
        while (sub_select_of_navy_instruments_nms == 5)
        {
            float total;
            title("THE NAVY BUDGET");
            total_nms_budget();
            sub_select_of_navy_instruments_nms = yes_or_no(sub_select_of_navy_instruments_nms);
            if(sub_select_of_navy_instruments_nms == 0)
            {
                goto sub_menu_instruments;
            }
        }
        //Back
        while (sub_selected_instruments == 6 || sub_select_of_navy_instruments_nms == 6)
        {
            goto nms_top_menu;
        }
    }
    
    // CROPS
    while (main_selected_option_of_nms == 4)
    {
        int sub_select_of_crops_nms;
        menu_crops:
        title("CROPS MANAGEMENT SYSTEM");
        to_show_sub_menu_navy_crops_nms(2);
        sub_select_of_crops_nms = selecting_function(columns_of_screen / 3 + 10,12,2);
        while(sub_select_of_crops_nms == 1)
        {
            to_show_naval_khor();
            sub_select_of_crops_nms = yes_or_no(sub_select_of_crops_nms);
            if(sub_select_of_crops_nms == 0)
            {
                goto menu_crops;
            }
        }
        while(sub_select_of_crops_nms == 2)
        {
            to_show_naizi_khor();
            sub_select_of_crops_nms = yes_or_no(sub_select_of_crops_nms);
            if(sub_select_of_crops_nms == 0)
            {
                goto menu_crops;
            }
        }
        if (sub_select_of_crops_nms ==  3)
        {
            goto nms_top_menu;
        }
    }
    // Report of work
    while (main_selected_option_of_nms == 5)
    {
        
        to_fetch_feedback();
        main_selected_option_of_nms = yes_or_no(main_selected_option_of_nms);
        if (main_selected_option_of_nms == 0)
        {
            goto nms_top_menu;
        }
    }
}
// 2. NAVY MANAGEMENT SYSTEM ENDED
// 3. AIR FORCE MANAGEMENT SYSTEM
int air_force_management_team_system(int checker_of_user_domain)
{
    
    int sub_selected_instruments;
    int main_selected_option_of_afms;
    int sub_select_of_air_force_instruments_afms, sub_select_of_air_force_soldier_afms, sub_select_of_air_force_officer_afms;
    int item_quantity[5];
// Main Menu of AIR FORCE TEAM MANAGEMENT SYSTEM
afms_top_menu:
    title("AIR FORCE TEAM MANAGEMENT SYSTEM");
    to_show_main_menu_afms(5);
    
    main_selected_option_of_afms = selecting_function(columns_of_screen / 3 + 10,12,5);
    // AIR FORCE soldiers in afms // COMPLETE
    while (main_selected_option_of_afms == 1)
    {
    air_force_soldiers_menu:
        title("AIR FORCE TEAM MANAGEMENT SYSTEM");
        to_show_sub_menu_air_force_soldier_afms(5);
        sub_select_of_air_force_soldier_afms = selecting_function(columns_of_screen / 3 + 10,12,5);
        // View Personal details of Soldiers 1
        while (sub_select_of_air_force_soldier_afms == 1)
        {
            int check_batch_id;
            int batch_id_idx;
            title("PERSONAL DETAILS OF AIR FORCE SOLDIER");
            batch_id_idx = id_take_to_fetch_and_id_check_soldiers_afms();
            check_batch_id = to_show_personal_details_from_air_force_soldiers_array(batch_id_idx);
            if (check_batch_id == 1)
            {
                sub_select_of_air_force_soldier_afms = yes_or_no(sub_select_of_air_force_soldier_afms);
                if (sub_select_of_air_force_soldier_afms == 0 )
                {
                    goto air_force_soldiers_menu;
                }
            }
        }
        // ADD NEW RECORD 2
        while (sub_select_of_air_force_soldier_afms == 2)
        {
            title("ADD DETAILS OF AIR FORCE SOLDIER");
            to_show_note("122-");
            to_add_data_in_soldiers_array_afms();
            to_add_data_in_soldier_txt_afms();
            sub_select_of_air_force_soldier_afms = yes_or_no(sub_select_of_air_force_soldier_afms);
            if (sub_select_of_air_force_soldier_afms == 0 )
            {
                goto air_force_soldiers_menu;
            }
        }
        // EDIT RECORD 3
        while (sub_select_of_air_force_soldier_afms == 3)
        {
            int check_batch_idx;
            int batch_id_index;
            title("EDIT DETAILS OF AIR FORCE SOLDIER");
            batch_id_index = id_take_to_fetch_and_id_check_soldiers_afms();
            to_edit_data_in_soldiers_array_afms(batch_id_index);
            to_add_whole_data_in_soldier_txt_afms();
            sub_select_of_air_force_soldier_afms = yes_or_no(sub_select_of_air_force_soldier_afms);
            if (sub_select_of_air_force_soldier_afms == 0)
            {
                goto air_force_soldiers_menu;
            }
        }
        // RETIRED OFFICERS 4
        while (sub_select_of_air_force_soldier_afms == 4)
        {   retired_main_menu:
            int sub_option_of_retired_soldiers;
            title("RETIRED SOLDIERS MANAGEMENT");
            to_show_retired_menu_afms(2);
            sub_option_of_retired_soldiers = selecting_function(columns_of_screen / 3 + 10, 17,2);
            // to view retired soldiers
            while(sub_option_of_retired_soldiers == 1)
            {
                to_view_retired_soldier_data_afms();
                sub_option_of_retired_soldiers = yes_or_no(sub_option_of_retired_soldiers);
                if(sub_option_of_retired_soldiers == 0)
                {
                    goto retired_main_menu;
                }
            }
            // to add new retired soldiers
            while(sub_option_of_retired_soldiers == 2)
            {
                int batch_id_index;
                batch_id_index = id_take_to_fetch_and_id_check_soldiers_afms();
                to_add_removed_soldier_in_retired_afms(batch_id_index);
                to_remove_retired_soldier_from_array_afms(batch_id_index);
                to_add_whole_data_in_soldier_txt_afms();
                to_add_whole_data_in_retired_soldier_txt_afms();
                sub_option_of_retired_soldiers = yes_or_no(sub_option_of_retired_soldiers);
                if(sub_option_of_retired_soldiers == 0)
                {
                    goto retired_main_menu;
                }
            }

            if(sub_option_of_retired_soldiers == 3)
            {
                goto air_force_soldiers_menu;
            }
            
        }
        // MATRYED 5
        while (sub_select_of_air_force_soldier_afms == 5)
        {
            matryed:
            int sub_option_of_matryed_officers;
            title("HEROES OF OUR NATION");
            to_show_matryed_menu_afms(2);
            sub_option_of_matryed_officers = selecting_function(columns_of_screen / 3 + 10, 17,2);
            if (sub_option_of_matryed_officers == 1)
            {
                system("cls");
                title("HEROES OF OUR NATION");
                to_view_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed;
                }
            }
            else if (sub_option_of_matryed_officers == 2)
            {
                title("HEROES OF OUR NATION");
                to_add_matryed("matryed/ams_army_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed;
                }
            }
            else if (sub_option_of_matryed_officers == 3)
            {
                goto air_force_soldiers_menu;
            }
        }
        // GO TO afms TOP MENU IN 6
        if (sub_select_of_air_force_soldier_afms == 6)
        {
            goto afms_top_menu;
        }
        
    }
    // AIR FORCE OFFICERS IN afms // complete
    while (main_selected_option_of_afms == 2)
    {
        air_force_officers_menu:
        title("AIR FORCE TEAM MANAGEMENT SYSTEM");
        to_show_sub_menu_air_force_officer_afms(7);
        sub_select_of_air_force_officer_afms = selecting_function(columns_of_screen / 3 + 10, 12,7);
        // View Personal details of Officers 1
        while (sub_select_of_air_force_officer_afms == 1)
        {
            int check_batch_id;
            int batch_id_idx;
            title("PERSONAL DETAILS OF AIR FORCE OFFICER");
            batch_id_idx = id_take_to_fetch_and_id_check_officer_afms();
            check_batch_id = to_show_personal_details_from_air_force_officer_array(batch_id_idx);
            if (check_batch_id == 1)
            {
                sub_select_of_air_force_officer_afms = yes_or_no(sub_select_of_air_force_officer_afms);
                if (sub_select_of_air_force_officer_afms == 0 )
                {
                    goto air_force_officers_menu;
                }
            }
        }
         // ADD NEW RECORD 2
        while (sub_select_of_air_force_officer_afms == 2)
        {
            title("ADD DETAILS OF AIR FORCE OFFICER");
            to_show_note("EAG-");
            to_add_data_in_officer_array_afms();
            to_add_data_in_officer_txt_afms();
            sub_select_of_air_force_officer_afms = yes_or_no(sub_select_of_air_force_officer_afms);
            if (sub_select_of_air_force_officer_afms == 0 )
            {
                goto air_force_officers_menu;
            }
        }
        // EDIT RECORD 3
        while (sub_select_of_air_force_officer_afms == 3)
        {
            int check_batch_idx;
            int batch_id_index;
            title("EDIT DETAILS OF AIR FORCE SOLDIER");
            batch_id_index = id_take_to_fetch_and_id_check_officer_afms();
            to_edit_data_in_officer_array_afms(batch_id_index);
            to_add_whole_data_in_officer_txt_afms();
            sub_select_of_air_force_officer_afms = yes_or_no(sub_select_of_air_force_officer_afms);
            if (sub_select_of_air_force_officer_afms == 0)
            {
                goto air_force_officers_menu;
            }
        }
        // RETIRED OFFICERS 4
        while (sub_select_of_air_force_officer_afms == 4)
        {   retired_main_menu_officer:
            int sub_option_of_retired_officer;
            title("RETIRED OFFICERS MANAGEMENT");
            to_show_retired_menu_afms(2);
            sub_option_of_retired_officer = selecting_function(columns_of_screen / 3 + 10, 17,2);
            // to view retired soldiers
            while(sub_option_of_retired_officer == 1)
            {
                to_view_retired_officer_data_afms();
                sub_option_of_retired_officer = yes_or_no(sub_option_of_retired_officer);
                if(sub_option_of_retired_officer == 0)
                {
                    goto retired_main_menu_officer;
                }
            }
            // to add new retired soldiers
            while(sub_option_of_retired_officer == 2)
            {
                int batch_id_index;
                batch_id_index = id_take_to_fetch_and_id_check_officer_afms();
                to_add_removed_officer_in_retired_afms(batch_id_index);
                to_remove_retired_officer_from_array_afms(batch_id_index);
                to_add_whole_data_in_officer_txt_afms();
                to_add_whole_data_in_retired_officer_txt_afms();
                sub_option_of_retired_officer = yes_or_no(sub_option_of_retired_officer);
                if(sub_option_of_retired_officer == 0)
                {
                    goto retired_main_menu_officer;
                }
            }
            if(sub_option_of_retired_officer == 3)
            {
                goto air_force_officers_menu;
            }
            
        }
        // MATRYED 5
        while (sub_select_of_air_force_officer_afms == 5)
        {
            matryed_officer:
            int sub_option_of_matryed_officers;
            title("HEROES OF OUR NATION");
            to_show_matryed_menu_afms(2);
            sub_option_of_matryed_officers = selecting_function(columns_of_screen / 3 + 10, 17,2);
            if (sub_option_of_matryed_officers == 1)
            {
                system("cls");
                title("HEROES OF OUR NATION");
                to_view_matryed("matryed/afms_air_force_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed_officer;
                }
            }
            else if (sub_option_of_matryed_officers == 2)
            {
                title("HEROES OF OUR NATION");
                to_add_matryed("matryed/afms_air_force_soldiers_matryed.txt");
                sub_option_of_matryed_officers = yes_or_no(sub_option_of_matryed_officers);
                if(sub_option_of_matryed_officers == 0)
                {
                    goto matryed_officer;
                }
            }
            else if (sub_option_of_matryed_officers == 3)
            {
                goto air_force_officers_menu;
            }
        }  
        // Officers in Provience 6
        while (sub_select_of_air_force_officer_afms == 6)
        {
            string prov; // provience
            int count_officers = 0;
            prov = to_take_provience();
            count_officers = to_see_data_from_afms_officer_arrray(3,prov);
            sub_select_of_air_force_officer_afms = yes_or_no(sub_select_of_air_force_officer_afms);
            if(sub_select_of_air_force_officer_afms == 0)
                {
                    goto air_force_officers_menu;
                }
        }
        // Soldiers under Officers 7
        while (sub_select_of_air_force_officer_afms == 7)
        {   
            int batch_id_index;
            string check_batch_id;
            title("SOLDIERS UNDER THE OFFICER");
            soldier_under_officers_afms();
            batch_id_index = id_take_to_fetch_and_id_check_officer_afms();
            soldier_under_officer_view_afms(batch_id_index);
            sub_select_of_air_force_officer_afms = yes_or_no(sub_select_of_air_force_officer_afms);
            if(sub_select_of_air_force_officer_afms == 0)
            {
                goto air_force_officers_menu;
            }

        }
        // GO TO AGAIN LOG IN 8
        while (sub_select_of_air_force_officer_afms == 8)
        {
            goto afms_top_menu;
        }
    }
    // AIR FORCE INSTRUMENTS // COMPLETE
    while (main_selected_option_of_afms == 3)
    {
        sub_menu_instruments:
        int sub_of_sub_selected_instruments;
        title("AIR FORCE TEAM MANAGEMENT SYSTEM");
        to_show_sub_menu_air_force_instruments_afms(5);
        sub_select_of_air_force_instruments_afms = selecting_function(columns_of_screen / 3 + 10, 12,5);
        // VIEW INSTRUMENTS 1
        while (sub_select_of_air_force_instruments_afms == 1)
        {   
            instrument_stayer:
            int sub_of_sub_selected_instruments;
            title("INSTRUMENTS MANAGEMENT SYSTEM");
            to_show_sub_detail_view_air_force_instruments_afms(5);
            sub_of_sub_selected_instruments = selecting_function(columns_of_screen / 3 + 10, 12,5);
            // air_craft
            while (sub_of_sub_selected_instruments == 1)
            {
                to_show_air_craft_details_air_force();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // Weapons
            while (sub_of_sub_selected_instruments == 2)
            {
                
                to_show_weapons_details_air_force();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // missiles
            while (sub_of_sub_selected_instruments == 3)
            {
                to_show_missilies_details_air_force();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // planess
            while (sub_of_sub_selected_instruments == 4)
            {
                to_show_planes_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // atomic trackers
            while (sub_of_sub_selected_instruments == 5)
            {
                to_show_trackers_details();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer;
                }
            }
            // back
            while (sub_of_sub_selected_instruments == 6)
            {
                goto sub_menu_instruments;
            }
        }
        // Add INSTRUMENTS
        while (sub_select_of_air_force_instruments_afms == 2)
        {
            INS_PLACE_2:
            int sub_of_sub_selected_instruments;
            title("INSTRUMENTS MANAGEMENT SYSTEM");
            to_show_sub_detail_view_air_force_instruments_afms(5);
            sub_of_sub_selected_instruments = selecting_function(columns_of_screen / 3 + 10, 12,5);
            while (sub_of_sub_selected_instruments == 1)
            {
                to_show_air_craft_details_air_force();
                to_add_data_in_array_air_craft_air_force();
                to_add_data_of_air_craft_in_txt_air_force();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // Weapons
            while (sub_of_sub_selected_instruments == 2)
            {
                
                to_show_weapons_details_air_force();
                to_add_data_in_array_weapons_air_force();
                to_add_data_of_weapons_in_txt_air_force();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // missiles
            while (sub_of_sub_selected_instruments == 3)
            {
                to_show_missilies_details_air_force();
                to_add_data_in_array_missilies_air_force();
                to_add_data_of_missilies_in_txt_air_force();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // planess
            while (sub_of_sub_selected_instruments == 4)
            {
                to_show_planes_details();
                to_add_data_in_array_planes();
                to_add_data_of_planes_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // atomic trackers
            while (sub_of_sub_selected_instruments == 5)
            {
                to_show_trackers_details();
                to_add_data_in_array_trackers();
                to_add_data_of_trackers_in_txt();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto INS_PLACE_2;
                }
            }
            // back
            while (sub_of_sub_selected_instruments == 6)
            {
                goto sub_menu_instruments;
            }
            
        }
        // edit instruments
        while(sub_select_of_air_force_instruments_afms == 3)
        {
            instrument_stayer_edit:
            int sub_of_sub_selected_instruments;
            title("INSTRUMENTS MANAGEMENT SYSTEM");
            to_show_sub_detail_view_air_force_instruments_afms(5);
            sub_of_sub_selected_instruments = selecting_function(columns_of_screen / 3 + 10, 12,5);
               while (sub_of_sub_selected_instruments == 1)
            {
                to_edit_instrument_record_air_craft();
                to_add_whole_data_in_txt_air_craft();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 2)
            {
                to_edit_instrument_record_weapons_air_force();
                to_add_whole_data_in_txt_weapons_air_force();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 3)
            {
                to_edit_instrument_record_missilies_air_force();
                to_add_whole_data_in_txt_missilies_air_force();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 4)
            {
                to_edit_instrument_record_planes();
                to_add_whole_data_in_txt_planes();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while (sub_of_sub_selected_instruments == 5)
            {
                to_edit_instrument_record_trackers();
                to_add_whole_data_in_txt_trackers();
                sub_of_sub_selected_instruments = yes_or_no(sub_of_sub_selected_instruments);
                if(sub_of_sub_selected_instruments == 0)
                {
                    goto instrument_stayer_edit;
                }
            }
            while(sub_of_sub_selected_instruments == 6)
            {
                goto sub_menu_instruments;
            }
            
        }
         // graph
        while (sub_select_of_air_force_instruments_afms == 4)
        {
            system("cls");
            title("GRAPH OF BUDGET");
            graph_afms();
            Sleep(5000);
            sub_select_of_air_force_instruments_afms = yes_or_no(sub_select_of_air_force_instruments_afms);
            if(sub_select_of_air_force_instruments_afms == 0)
            {
                goto sub_menu_instruments;
            }
        }
        // Budget Calculate
        while (sub_select_of_air_force_instruments_afms == 5)
        {
            float total;
            title("THE AIR FORCE BUDGET");
            total_afms_budget();
            sub_select_of_air_force_instruments_afms = yes_or_no(sub_select_of_air_force_instruments_afms);
            if(sub_select_of_air_force_instruments_afms == 0)
            {
                goto sub_menu_instruments;
            }
        }
        //Back
        while (sub_selected_instruments == 6 || sub_select_of_air_force_instruments_afms == 6)
        {
            goto afms_top_menu;
        }
    }
    // CROPS
    while (main_selected_option_of_afms == 4)
    {
        int sub_select_of_crops_afms;
        menu_crops:
        title("CROPS MANAGEMENT SYSTEM");
        to_show_sub_menu_air_force_crops_afms(2);
        sub_select_of_crops_afms = selecting_function(columns_of_screen / 3 + 10,12,2);
        while(sub_select_of_crops_afms == 1)
        {
            to_show_nav_khor();
            sub_select_of_crops_afms = yes_or_no(sub_select_of_crops_afms);
            if(sub_select_of_crops_afms == 0)
            {
                goto menu_crops;
            }
        }
        while(sub_select_of_crops_afms == 2)
        {
            to_show_him_khor();
            sub_select_of_crops_afms = yes_or_no(sub_select_of_crops_afms);
            if(sub_select_of_crops_afms == 0)
            {
                goto menu_crops;
            }
        }
        if (sub_select_of_crops_afms ==  3)
        {
            goto afms_top_menu;
        }
    }
    // Report of work
    while (main_selected_option_of_afms == 5)
    {
        
        to_fetch_feedback();
        main_selected_option_of_afms = yes_or_no(main_selected_option_of_afms);
        if (main_selected_option_of_afms == 0)
        {
            goto afms_top_menu;
        }
    }
}
// 3. AIR FORCE MANAGEMENT SYSTEM ENDED
// 4. ARMY OFFICERS MANAGEMENT SYSTEM
int army_officer_management_system(int checker_of_user_domain)
{
	int main_selector, sub_select_of_army_officer_aoms;
aoms_main_menu:
	title("ARMY OFFICER MANAGEMENT");
	to_show_main_menu_aoms(5);
	main_selector = selecting_function(columns_of_screen / 3 + 10,12,5);
		// PERSONAL DETAILS
		while (main_selector == 1)
		{
			int check_batch_id;
			string batch_id;
			title("PERSONAL DETAILS OF ARMY OFFICER");
			to_show_personal_details_from_aoms();
            main_selector = yes_or_no(main_selector);
            if(main_selector == 0)
            {
                goto aoms_main_menu;
            }
		}
		// SOLDIERS DETAILS
		while (main_selector == 2)
		{
           int check_batch_id;
            int batch_id_idx;
            title("PERSONAL DETAILS OF ARMY SOLDIER");
            batch_id_idx = id_take_to_fetch_and_id_check_soldiers_ams();
            check_batch_id = to_show_personal_details_from_soldiers_array(batch_id_idx);
            if (check_batch_id == 1)
            {
                main_selector = yes_or_no(main_selector);
                if (main_selector == 0 )
                {
                    goto aoms_main_menu;
                }
            } 
		}
		// Candidates Select
		while (main_selector == 3)
		{
			title("ISSB SELECTOR");
			to_show_personal_selector_details_options_aoms(2);
            sub_select_of_army_officer_aoms = selecting_function(columns_of_screen / 3 ,12,2);
			while (sub_select_of_army_officer_aoms == 1)
			{
					title("GTO GROUP TAKS");
                    to_get_candidates_batch_id();
                    to_get_candidate_marks_gto();
                    to_add_data_in_txt_feedback_gto();
                sub_select_of_army_officer_aoms = yes_or_no(sub_select_of_army_officer_aoms);
			    if (sub_select_of_army_officer_aoms == 0)
			    {
				goto aoms_main_menu;
			    }
			}
            // psychologist_tasks
			while (sub_select_of_army_officer_aoms == 2)
			{
				
					title("PSYCOLOGYIST TASKS OF GROUP");
                    to_get_candidates_batch_id();
					to_get_candidate_marks_psychologist();
                    to_add_data_in_txt_feedback_psychologist();
                    sub_select_of_army_officer_aoms = yes_or_no(sub_select_of_army_officer_aoms);
			    if (sub_select_of_army_officer_aoms == 0)
			    {
				goto aoms_main_menu;
			    }
			}
			if (sub_select_of_army_officer_aoms == 3)
			{
				goto aoms_main_menu;
			}
		}
		// WAR IDEA
		while (main_selector == 4)
		{
			title("WAR IDEA SYSTEM");
			to_input_war_ideas();
            main_selector = yes_or_no(main_selector);
			if (main_selector == 0)
			{
				goto aoms_main_menu;
			}
		}
		// CODE BY CROPS
		while (main_selector == 5)
		{
			main_selector = code_by_corp();
			if (main_selector == 0)
			{
				goto aoms_main_menu;
			}
		}
        if(main_selector == 6)
        {
            return 0;
        }

	
}
// 4. ARMY OFFICERS MANAGEMENT SYSTEM END
// 5. NAVY OFFICERS MANAGEMENT SYSTEM
int navy_officer_management_system(int checker_of_user_domain)
{
	int main_selector, sub_select_of_army_officer_aoms;
	noms_main_menu:
	title("NAVY OFFICER MANAGEMENT");
	to_show_main_menu_aoms(5);
	main_selector = selecting_function(columns_of_screen / 3 + 10,12,5);
		// PERSONAL DETAILS
		while (main_selector == 1)
		{
			int check_batch_id;
			string batch_id;
			title("PERSONAL DETAILS OF NAVY OFFICER");
			to_show_personal_details_from_noms();
            main_selector = yes_or_no(main_selector);
            if(main_selector == 0)
            {
                goto noms_main_menu;
            }
		}
		// SOLDIERS DETAILS
		while (main_selector == 2)
		{
           int check_batch_id;
            int batch_id_idx;
            title("PERSONAL DETAILS OF NAVY SOLDIER");
            batch_id_idx = id_take_to_fetch_and_id_check_soldiers_nms();
            check_batch_id = to_show_personal_details_from_navy_soldiers_array(batch_id_idx);
            if (check_batch_id == 1)
            {
                main_selector = yes_or_no(main_selector);
                if (main_selector == 0 )
                {
                    goto noms_main_menu;
                }
            }
		}
		// Candidates Select
		while (main_selector == 3)
		{
			title("ISSB SELECTOR");
			to_show_personal_selector_details_options_aoms(2);
            sub_select_of_army_officer_aoms = selecting_function(columns_of_screen / 3 ,12,2);
			while (sub_select_of_army_officer_aoms == 1)
			{
					title("GTO GROUP TAKS");
                    to_get_candidates_batch_id();
                    to_get_candidate_marks_gto();
                    to_add_data_in_txt_feedback_gto();
                sub_select_of_army_officer_aoms = yes_or_no(sub_select_of_army_officer_aoms);
			    if (sub_select_of_army_officer_aoms == 0)
			    {
				goto noms_main_menu;
			    }
			}
            // psychologist_tasks
			while (sub_select_of_army_officer_aoms == 2)
			{
				
					title("PSYCOLOGYIST TASKS OF GROUP");
                    to_get_candidates_batch_id();
					to_get_candidate_marks_psychologist();
                    to_add_data_in_txt_feedback_psychologist();
                    sub_select_of_army_officer_aoms = yes_or_no(sub_select_of_army_officer_aoms);
			    if (sub_select_of_army_officer_aoms == 0)
			    {
				goto noms_main_menu;
			    }
			}
			if (sub_select_of_army_officer_aoms == 3)
			{
				goto noms_main_menu;
			}
		}
		// WAR IDEA
		while (main_selector == 4)
		{
			title("WAR IDEA SYSTEM");
			to_input_war_ideas();
            main_selector = yes_or_no(main_selector);
			if (main_selector == 0)
			{
				goto noms_main_menu;
			}
		}
		// CODE BY CROPS
		while (main_selector == 5)
		{
			main_selector = code_by_corp();
			if (main_selector == 0)
			{
				goto noms_main_menu;
			}
		}
        if(main_selector == 6)
        {
            return 0;
        }

	
}
// 5. NAVY OFFICERS MANAGEMENT SYSTEM END
// 6. AIR FORCE OFFICERS MANAGEMENT SYSTEM
int air_force_officer_management_system(int checker_of_user_domain)
{
	int main_selector, sub_select_of_army_officer_aoms;
	afms_main_menu:
	title("AIR FORCE OFFICER MANAGEMENT");
	to_show_main_menu_aoms(5);
	main_selector = selecting_function(columns_of_screen / 3 + 10,12,5);
		// PERSONAL DETAILS
		while (main_selector == 1)
		{
			int check_batch_id;
			string batch_id;
			title("PERSONAL DETAILS OF AIR FORCE OFFICER");
			to_show_personal_details_from_afoms();
            main_selector = yes_or_no(main_selector);
            if(main_selector == 0)
            {
                goto afms_main_menu;
            }
		}
		// SOLDIERS DETAILS
		while (main_selector == 2)
		{
           int check_batch_id;
            int batch_id_idx;
            title("PERSONAL DETAILS OF AIR FORCE SOLDIER");
            batch_id_idx = id_take_to_fetch_and_id_check_soldiers_afms();
            check_batch_id = to_show_personal_details_from_air_force_soldiers_array(batch_id_idx);
            if (check_batch_id == 1)
            {
                main_selector = yes_or_no(main_selector);
                if (main_selector == 0 )
                {
                    goto afms_main_menu;
                }
            }
		}
		// Candidates Select
		while (main_selector == 3)
		{
			title("ISSB SELECTOR");
			to_show_personal_selector_details_options_aoms(2);
            sub_select_of_army_officer_aoms = selecting_function(columns_of_screen / 3 ,12,2);
			while (sub_select_of_army_officer_aoms == 1)
			{
					title("GTO GROUP TAKS");
                    to_get_candidates_batch_id();
                    to_get_candidate_marks_gto();
                    to_add_data_in_txt_feedback_gto();
                sub_select_of_army_officer_aoms = yes_or_no(sub_select_of_army_officer_aoms);
			    if (sub_select_of_army_officer_aoms == 0)
			    {
				goto afms_main_menu;
			    }
			}
            // psychologist_tasks
			while (sub_select_of_army_officer_aoms == 2)
			{
				
					title("PSYCOLOGYIST TASKS OF GROUP");
                    to_get_candidates_batch_id();
					to_get_candidate_marks_psychologist();
                    to_add_data_in_txt_feedback_psychologist();
                    sub_select_of_army_officer_aoms = yes_or_no(sub_select_of_army_officer_aoms);
			    if (sub_select_of_army_officer_aoms == 0)
			    {
				goto afms_main_menu;
			    }
			}
			if (sub_select_of_army_officer_aoms == 3)
			{
				goto afms_main_menu;
			}
		}
		// WAR IDEA
		while (main_selector == 4)
		{
			title("WAR IDEA SYSTEM");
			to_input_war_ideas();
            main_selector = yes_or_no(main_selector);
			if (main_selector == 0)
			{
				goto afms_main_menu;
			}
		}
		// CODE BY CROPS
		while (main_selector == 5)
		{
			main_selector = code_by_corp();
			if (main_selector == 0)
			{
				goto afms_main_menu;
			}
		}
        if(main_selector == 6)
        {
            return 0;
        }

	
}
// 6. air OFFICERS MANAGEMENT SYSTEM END
// 7. SOLDIERS MANAGEMENT SYSTEM COMPLETED
int soldiers_management_system(int checker_of_user_domain)
{

army_soldiers_menu:
    int main_menu_taker;
    title("SOLDIERS MANAGEMENT SYSTEM");
    to_show_main_menu_asms(3);
    main_menu_taker = selecting_function(columns_of_screen / 3 + 10, 12, 3);
    while (main_menu_taker == 1)
    {

        int check_batch_id;
        string batch_id;
        title("PERSONAL DETAILS OF ARMY SOLDIER");
        check_batch_id = to_show_personal_details_from_asms();
        if (check_batch_id == 1)
        {
            main_menu_taker = yes_or_no(main_menu_taker);
            if (main_menu_taker == 0)
            {
                goto army_soldiers_menu;
            }
        }
        else
        {
            gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 10);
            cout << "INVALID !";
            Sleep(2000);
        }
    }
    if (main_menu_taker == 2)
    {
        to_calculate_salary_asms();
        goto army_soldiers_menu;
    }
    if (main_menu_taker == 3)
    {
        feedback();
        goto army_soldiers_menu;
    }
    if (main_menu_taker == 4)
    {
        return 0;
    }
}

// 7 . SMS

//                                        FETCH PHASE
void fetch_all_data_at_start()
{   // ams
    fetch_ams_soldier_data_from_txt_to_array();
    fetch_ams_officers_data_from_txt_to_array();
    // nms
    fetch_nms_soldier_data_from_txt_to_array();
    fetch_nms_officers_data_from_txt_to_array();
    // AFMS
    fetch_afms_soldier_data_from_txt_to_array();
    fetch_afms_officers_data_from_txt_to_array();
    fetch_ams_retired_soldiers_data_from_txt_to_array();
    fetch_ams_retired_officers_data_from_txt_to_array();
    fetch_nms_retired_soldiers_data_from_txt_to_array();
    fetch_nms_retired_officers_data_from_txt_to_array();
    fetch_afms_retired_soldiers_data_from_txt_to_array();
    fetch_afms_retired_officers_data_from_txt_to_array();
    fetch_ams_carriers();
    fetch_ams_weapons();
    fetch_ams_tank();
    fetch_ams_missilies();
    fetch_ams_bombs();
    fetch_nms_weapons();
    fetch_nms_air_craft();
    fetch_nms_missilies();
    fetch_nms_subarine();
    fetch_nms_surface_ships();

}
// fetch sms
int fetch_ams_soldier_data_from_txt_to_array()
{
    int index_col_of_array = army_soldier_count;
    int i = 0;
    string file_path = "ams_folder/ams_army_soldiers.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') // get batch_ id
        {
            army_soldier_array[0][index_col_of_array] = army_soldier_array[0][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // name
        {
            army_soldier_array[1][index_col_of_array] = army_soldier_array[1][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // f name
        {
            army_soldier_array[2][index_col_of_array] = army_soldier_array[2][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // provience
        {
            army_soldier_array[3][index_col_of_array] = army_soldier_array[3][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // salary
        {
            army_soldier_array[4][index_col_of_array] = army_soldier_array[4][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // age
        {
            army_soldier_array[5][index_col_of_array] = army_soldier_array[5][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // rank
        {
            army_soldier_array[6][index_col_of_array] = army_soldier_array[6][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // password
        {
            army_soldier_array[7][index_col_of_array] = army_soldier_array[7][index_col_of_array] + line[i];
            i++;
        }
        i++;
        index_col_of_array++;
    }
    file.close();
    army_soldier_count = index_col_of_array;
    return 1;
}
// fetch nsms
int fetch_nms_soldier_data_from_txt_to_array()
{
    int index_col_of_array = navy_soldier_count;
    int i = 0;
    string file_path = "ams_folder/nms_navy_soldiers.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') // get batch_ id
        {
            navy_soldier_array[0][index_col_of_array] = navy_soldier_array[0][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // name
        {
            navy_soldier_array[1][index_col_of_array] = navy_soldier_array[1][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // f name
        {
            navy_soldier_array[2][index_col_of_array] = navy_soldier_array[2][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // provience
        {
            navy_soldier_array[3][index_col_of_array] = navy_soldier_array[3][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // salary
        {
            navy_soldier_array[4][index_col_of_array] = navy_soldier_array[4][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // age
        {
            navy_soldier_array[5][index_col_of_array] = navy_soldier_array[5][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // rank
        {
            navy_soldier_array[6][index_col_of_array] = navy_soldier_array[6][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // password
        {
            navy_soldier_array[7][index_col_of_array] = navy_soldier_array[7][index_col_of_array] + line[i];
            i++;
        }
        i++;
        index_col_of_array++;
    }
    file.close();
    navy_soldier_count = index_col_of_array;
    return 1;
}
// fetch afsms
int fetch_afms_soldier_data_from_txt_to_array()
{
    int index_col_of_array = air_force_soldier_count;
    int i = 0;
    string file_path = "ams_folder/afms_air_force_soldiers.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') // get batch_ id
        {
            air_force_soldier_array[0][index_col_of_array] = air_force_soldier_array[0][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // name
        {
            air_force_soldier_array[1][index_col_of_array] = air_force_soldier_array[1][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // f name
        {
            air_force_soldier_array[2][index_col_of_array] = air_force_soldier_array[2][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // provience
        {
            air_force_soldier_array[3][index_col_of_array] = air_force_soldier_array[3][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // salary
        {
            air_force_soldier_array[4][index_col_of_array] = air_force_soldier_array[4][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // age
        {
            air_force_soldier_array[5][index_col_of_array] = air_force_soldier_array[5][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // rank
        {
            air_force_soldier_array[6][index_col_of_array] = air_force_soldier_array[6][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // password
        {
            air_force_soldier_array[7][index_col_of_array] = air_force_soldier_array[7][index_col_of_array] + line[i];
            i++;
        }
        i++;
        index_col_of_array++;
    }
    file.close();
    air_force_soldier_count = index_col_of_array;
    return 1;
}
// fetch army officers
int fetch_ams_officers_data_from_txt_to_array()
{
    int index_col_of_array = army_officer_count;
    int i = 0;
    string file_path = "ams_folder/ams_army_officer.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') // get batch_ id
        {
            army_officer_array[0][index_col_of_array] = army_officer_array[0][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // name
        {
            army_officer_array[1][index_col_of_array] = army_officer_array[1][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // f name
        {
            army_officer_array[2][index_col_of_array] = army_officer_array[2][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // provience
        {
            army_officer_array[3][index_col_of_array] = army_officer_array[3][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // salary
        {
            army_officer_array[4][index_col_of_array] = army_officer_array[4][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // age
        {
            army_officer_array[5][index_col_of_array] = army_officer_array[5][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // rank
        {
            army_officer_array[6][index_col_of_array] = army_officer_array[6][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // password
        {
            army_officer_array[7][index_col_of_array] = army_officer_array[7][index_col_of_array] + line[i];
            i++;
        }
        i++;
        index_col_of_array++;
    }
    file.close();
    army_officer_count = index_col_of_array;
    return 1;
}
// fetch navy officers
int fetch_nms_officers_data_from_txt_to_array()
{
    int index_col_of_array = navy_officer_count;
    int i = 0;
    string file_path = "ams_folder/nms_navy_officer.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') // get batch_ id
        {
            navy_officer_array[0][index_col_of_array] = navy_officer_array[0][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // name
        {
            navy_officer_array[1][index_col_of_array] = navy_officer_array[1][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // f name
        {
            navy_officer_array[2][index_col_of_array] = navy_officer_array[2][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // provience
        {
            navy_officer_array[3][index_col_of_array] = navy_officer_array[3][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // salary
        {
            navy_officer_array[4][index_col_of_array] = navy_officer_array[4][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // age
        {
            navy_officer_array[5][index_col_of_array] = navy_officer_array[5][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // rank
        {
            navy_officer_array[6][index_col_of_array] = navy_officer_array[6][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // password
        {
            navy_officer_array[7][index_col_of_array] = navy_officer_array[7][index_col_of_array] + line[i];
            i++;
        }
        i++;
        index_col_of_array++;
    }
    file.close();
    navy_officer_count = index_col_of_array;
    return 1;
}
// fetch afms officers
int fetch_afms_officers_data_from_txt_to_array()
{
    int index_col_of_array = air_force_officer_count;
    int i = 0;
    string file_path = "ams_folder/afms_air_force_officer.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') // get batch_ id
        {
            air_force_officer_array[0][index_col_of_array] = air_force_officer_array[0][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // name
        {
            air_force_officer_array[1][index_col_of_array] = air_force_officer_array[1][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // f name
        {
            air_force_officer_array[2][index_col_of_array] = air_force_officer_array[2][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // provience
        {
            air_force_officer_array[3][index_col_of_array] = air_force_officer_array[3][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // salary
        {
            air_force_officer_array[4][index_col_of_array] = air_force_officer_array[4][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // age
        {
            air_force_officer_array[5][index_col_of_array] = air_force_officer_array[5][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // rank
        {
            air_force_officer_array[6][index_col_of_array] = air_force_officer_array[6][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // password
        {
            air_force_officer_array[7][index_col_of_array] = air_force_officer_array[7][index_col_of_array] + line[i];
            i++;
        }
        i++;
        index_col_of_array++;
    }
    file.close();
    air_force_officer_count = index_col_of_array;
    return 1;
}
//                  RETIRED OFFICERS
// to fetch retired soldier data from txt to array ams
int fetch_ams_retired_soldiers_data_from_txt_to_array()
{
    int index_col_of_array = retired_army_soldier_count;
    int i = 0;
    string file_path = "retired/ams_retired_soldiers.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') // get batch_ id
        {
            retired_army_soldier_array[0][index_col_of_array] = retired_army_soldier_array[0][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // name
        {
            retired_army_soldier_array[1][index_col_of_array] = retired_army_soldier_array[1][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // f name
        {
            retired_army_soldier_array[2][index_col_of_array] = retired_army_soldier_array[2][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // provience
        {
            retired_army_soldier_array[3][index_col_of_array] = retired_army_soldier_array[3][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // salary
        {
            retired_army_soldier_array[4][index_col_of_array] = retired_army_soldier_array[4][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // age
        {
            retired_army_soldier_array[5][index_col_of_array] = retired_army_soldier_array[5][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // rank
        {
            retired_army_soldier_array[6][index_col_of_array] = retired_army_soldier_array[6][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // password
        {
            retired_army_soldier_array[7][index_col_of_array] = retired_army_soldier_array[7][index_col_of_array] + line[i];
            i++;
        }
        i++;
        index_col_of_array++;
    }
    file.close();
    retired_army_soldier_count = index_col_of_array;
    return 1;
}
// to fetch retired soldier data from txt to array nms
int fetch_nms_retired_soldiers_data_from_txt_to_array()
{
    int index_col_of_array = retired_navy_soldier_count;
    int i = 0;
    string file_path = "retired/nms_retired_soldiers.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') // get batch_ id
        {
            retired_navy_soldier_array[0][index_col_of_array] = retired_navy_soldier_array[0][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // name
        {
            retired_navy_soldier_array[1][index_col_of_array] = retired_navy_soldier_array[1][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // f name
        {
            retired_navy_soldier_array[2][index_col_of_array] = retired_navy_soldier_array[2][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // provience
        {
            retired_navy_soldier_array[3][index_col_of_array] = retired_navy_soldier_array[3][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // salary
        {
            retired_navy_soldier_array[4][index_col_of_array] = retired_navy_soldier_array[4][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // age
        {
            retired_navy_soldier_array[5][index_col_of_array] = retired_navy_soldier_array[5][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // rank
        {
            retired_navy_soldier_array[6][index_col_of_array] = retired_navy_soldier_array[6][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // password
        {
            retired_navy_soldier_array[7][index_col_of_array] = retired_navy_soldier_array[7][index_col_of_array] + line[i];
            i++;
        }
        i++;
        index_col_of_array++;
    }
    file.close();
    retired_navy_soldier_count = index_col_of_array;
    return 1;
}
// to fetch retired officer data from txt to array
int fetch_afms_retired_soldiers_data_from_txt_to_array()
{
    int index_col_of_array = retired_air_force_soldier_count;
    int i = 0;
    string file_path = "retired/afms_retired_soldiers.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') // get batch_ id
        {
            retired_air_force_soldier_array[0][index_col_of_array] = retired_air_force_soldier_array[0][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // name
        {
            retired_air_force_soldier_array[1][index_col_of_array] = retired_air_force_soldier_array[1][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // f name
        {
            retired_air_force_soldier_array[2][index_col_of_array] = retired_air_force_soldier_array[2][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // provience
        {
            retired_air_force_soldier_array[3][index_col_of_array] = retired_air_force_soldier_array[3][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // salary
        {
            retired_air_force_soldier_array[4][index_col_of_array] = retired_air_force_soldier_array[4][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // age
        {
            retired_air_force_soldier_array[5][index_col_of_array] = retired_air_force_soldier_array[5][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // rank
        {
            retired_air_force_soldier_array[6][index_col_of_array] = retired_air_force_soldier_array[6][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // password
        {
            retired_air_force_soldier_array[7][index_col_of_array] = retired_air_force_soldier_array[7][index_col_of_array] + line[i];
            i++;
        }
        i++;
        index_col_of_array++;
    }
    file.close();
    retired_air_force_soldier_count = index_col_of_array;
    return 1;
}
// to fetch retired soldier data from txt to array ams
int fetch_ams_retired_officers_data_from_txt_to_array()
{
    int index_col_of_array = retired_army_officer_count;
    int i = 0;
    string file_path = "retired/ams_retired_officers.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') // get batch_ id
        {
            retired_army_officer_array[0][index_col_of_array] = retired_army_officer_array[0][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // name
        {
            retired_army_officer_array[1][index_col_of_array] = retired_army_officer_array[1][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // f name
        {
            retired_army_officer_array[2][index_col_of_array] = retired_army_officer_array[2][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // provience
        {
            retired_army_officer_array[3][index_col_of_array] = retired_army_officer_array[3][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // salary
        {
            retired_army_officer_array[4][index_col_of_array] = retired_army_officer_array[4][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // age
        {
            retired_army_officer_array[5][index_col_of_array] = retired_army_officer_array[5][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // rank
        {
            retired_army_officer_array[6][index_col_of_array] = retired_army_officer_array[6][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // password
        {
            retired_army_officer_array[7][index_col_of_array] = retired_army_officer_array[7][index_col_of_array] + line[i];
            i++;
        }
        i++;
        index_col_of_array++;
    }
    file.close();
    retired_army_officer_count = index_col_of_array;
    return 1;
}
// to fetch retired soldier data from txt to array nms
int fetch_nms_retired_officers_data_from_txt_to_array()
{
    int index_col_of_array = retired_navy_officer_count;
    int i = 0;
    string file_path = "retired/nms_retired_officers.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') // get batch_ id
        {
            retired_navy_officer_array[0][index_col_of_array] = retired_navy_officer_array[0][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // name
        {
            retired_navy_officer_array[1][index_col_of_array] = retired_navy_officer_array[1][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // f name
        {
            retired_navy_officer_array[2][index_col_of_array] = retired_navy_officer_array[2][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // provience
        {
            retired_navy_officer_array[3][index_col_of_array] = retired_navy_officer_array[3][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // salary
        {
            retired_navy_officer_array[4][index_col_of_array] = retired_navy_officer_array[4][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // age
        {
            retired_navy_officer_array[5][index_col_of_array] = retired_navy_officer_array[5][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // rank
        {
            retired_navy_officer_array[6][index_col_of_array] = retired_navy_officer_array[6][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // password
        {
            retired_navy_officer_array[7][index_col_of_array] = retired_navy_officer_array[7][index_col_of_array] + line[i];
            i++;
        }
        i++;
        index_col_of_array++;
    }
    file.close();
    retired_navy_officer_count = index_col_of_array;
    return 1;
}
// to fetch retired soldier data from txt to array afms
int fetch_afms_retired_officers_data_from_txt_to_array()
{
    int index_col_of_array = retired_air_force_officer_count;
    int i = 0;
    string file_path = "retired/afms_retired_officers.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') // get batch_ id
        {
            retired_air_force_officer_array[0][index_col_of_array] = retired_air_force_officer_array[0][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // name
        {
            retired_air_force_officer_array[1][index_col_of_array] = retired_air_force_officer_array[1][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // f name
        {
            retired_air_force_officer_array[2][index_col_of_array] = retired_air_force_officer_array[2][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // provience
        {
            retired_air_force_officer_array[3][index_col_of_array] = retired_air_force_officer_array[3][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // salary
        {
            retired_air_force_officer_array[4][index_col_of_array] = retired_air_force_officer_array[4][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // age
        {
            retired_air_force_officer_array[5][index_col_of_array] = retired_air_force_officer_array[5][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // rank
        {
            retired_air_force_officer_array[6][index_col_of_array] = retired_air_force_officer_array[6][index_col_of_array] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // password
        {
            retired_air_force_officer_array[7][index_col_of_array] = retired_air_force_officer_array[7][index_col_of_array] + line[i];
            i++;
        }
        i++;
        index_col_of_array++;
    }
    file.close();
    retired_air_force_officer_count = index_col_of_array;
    return 1;
}
// to fetch ams carriers
int fetch_ams_carriers()
{
    int index_row_of_array = count_ams_carriers;
    int i = 0;
    string file_path = "instruments/ams_carriers.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') //name
        {
            ams_carriers[index_row_of_array][0] = ams_carriers[index_row_of_array][0] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // range
        {
            ams_carriers[index_row_of_array][1] = ams_carriers[index_row_of_array][1] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // price
        {
            ams_carriers[index_row_of_array][2] = ams_carriers[index_row_of_array][2] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // stock
        {
            ams_carriers[index_row_of_array][3] = ams_carriers[index_row_of_array][3] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // used
        {
            ams_carriers[index_row_of_array][4] = ams_carriers[index_row_of_array][4] + line[i];
            i++;
        }
        i++;
        index_row_of_array++;
    }
    count_ams_carriers = index_row_of_array;
    file.close();
    return 1;
}
// to fetch ams weapons
int fetch_ams_weapons()
{
    int index_row_of_array = count_ams_weapons;
    int i = 0;
    string file_path = "instruments/ams_weapons.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') //name
        {
            ams_weapons[index_row_of_array][0] = ams_weapons[index_row_of_array][0] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // range
        {
            ams_weapons[index_row_of_array][1] = ams_weapons[index_row_of_array][1] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // price
        {
            ams_weapons[index_row_of_array][2] = ams_weapons[index_row_of_array][2] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // stock
        {
            ams_weapons[index_row_of_array][3] = ams_weapons[index_row_of_array][3] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // used
        {
            ams_weapons[index_row_of_array][4] = ams_weapons[index_row_of_array][4] + line[i];
            i++;
        }
        i++;
        index_row_of_array++;
    }
    count_ams_weapons = index_row_of_array;
    file.close();
    return 1;
}
// to fetch ams tank
int fetch_ams_tank()
{
    int index_row_of_array = count_ams_tank;
    int i = 0;
    string file_path = "instruments/ams_tank.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') //name
        {
            ams_tank[index_row_of_array][0] = ams_tank[index_row_of_array][0] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // range
        {
            ams_tank[index_row_of_array][1] = ams_tank[index_row_of_array][1] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // price
        {
            ams_tank[index_row_of_array][2] = ams_tank[index_row_of_array][2] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // stock
        {
            ams_tank[index_row_of_array][3] = ams_tank[index_row_of_array][3] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // used
        {
            ams_tank[index_row_of_array][4] = ams_tank[index_row_of_array][4] + line[i];
            i++;
        }
        i++;
        index_row_of_array++;
    }
    count_ams_tank = index_row_of_array;
    file.close();
    return 1;
}
// to fetch ams missilies
int fetch_ams_missilies()
{
    int index_row_of_array = count_ams_missilies;
    int i = 0;
    string file_path = "instruments/ams_missilies.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') //name
        {
            ams_missilies[index_row_of_array][0] = ams_missilies[index_row_of_array][0] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // range
        {
            ams_missilies[index_row_of_array][1] = ams_missilies[index_row_of_array][1] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // price
        {
            ams_missilies[index_row_of_array][2] = ams_missilies[index_row_of_array][2] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // stock
        {
            ams_missilies[index_row_of_array][3] = ams_missilies[index_row_of_array][3] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // used
        {
            ams_missilies[index_row_of_array][4] = ams_missilies[index_row_of_array][4] + line[i];
            i++;
        }
        i++;
        index_row_of_array++;
    }
    count_ams_missilies = index_row_of_array;
    file.close();
    return 1;
}
// to fetch ams missilies
int fetch_ams_bombs()
{
    int index_row_of_array = count_ams_atomic_bombs;
    int i = 0;
    string file_path = "instruments/ams_bombs.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') //name
        {
            ams_atomic_bombs[index_row_of_array][0] = ams_atomic_bombs[index_row_of_array][0] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // range
        {
            ams_atomic_bombs[index_row_of_array][1] = ams_atomic_bombs[index_row_of_array][1] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // price
        {
            ams_atomic_bombs[index_row_of_array][2] = ams_atomic_bombs[index_row_of_array][2] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // stock
        {
            ams_atomic_bombs[index_row_of_array][3] = ams_atomic_bombs[index_row_of_array][3] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // used
        {
            ams_atomic_bombs[index_row_of_array][4] = ams_atomic_bombs[index_row_of_array][4] + line[i];
            i++;
        }
        i++;
        index_row_of_array++;
    }
    count_ams_atomic_bombs = index_row_of_array;
    file.close();
    return 1;
}
// to fetch nms air craft
int fetch_nms_air_craft()
{
    int index_row_of_array = count_nms_air_craft;
    int i = 0;
    string file_path = "instruments/nms_air_craft.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') //name
        {
            nms_air_craft[index_row_of_array][0] = nms_air_craft[index_row_of_array][0] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // range
        {
            nms_air_craft[index_row_of_array][1] = nms_air_craft[index_row_of_array][1] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // price
        {
            nms_air_craft[index_row_of_array][2] = nms_air_craft[index_row_of_array][2] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // stock
        {
            nms_air_craft[index_row_of_array][3] = nms_air_craft[index_row_of_array][3] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // used
        {
            nms_air_craft[index_row_of_array][4] = nms_air_craft[index_row_of_array][4] + line[i];
            i++;
        }
        i++;
        index_row_of_array++;
    }
    count_nms_air_craft = index_row_of_array;
    file.close();
    return 1;
}
// to fetch nms weapons
int fetch_nms_weapons()
{
    int index_row_of_array = count_nms_weapons;
    int i = 0;
    string file_path = "instruments/nms_weapons.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') //name
        {
            nms_weapons[index_row_of_array][0] = nms_weapons[index_row_of_array][0] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // range
        {
            nms_weapons[index_row_of_array][1] = nms_weapons[index_row_of_array][1] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // price
        {
            nms_weapons[index_row_of_array][2] = nms_weapons[index_row_of_array][2] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // stock
        {
            nms_weapons[index_row_of_array][3] = nms_weapons[index_row_of_array][3] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // used
        {
            nms_weapons[index_row_of_array][4] = nms_weapons[index_row_of_array][4] + line[i];
            i++;
        }
        i++;
        index_row_of_array++;
    }
    count_nms_weapons = index_row_of_array;
    file.close();
    return 1;
}
// to fetch nms missilies
int fetch_nms_missilies()
{
    int index_row_of_array = count_nms_missilies;
    int i = 0;
    string file_path = "instruments/nms_missilies.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') //name
        {
            nms_missilies[index_row_of_array][0] = nms_missilies[index_row_of_array][0] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // range
        {
            nms_missilies[index_row_of_array][1] = nms_missilies[index_row_of_array][1] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // price
        {
            nms_missilies[index_row_of_array][2] = nms_missilies[index_row_of_array][2] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // stock
        {
            nms_missilies[index_row_of_array][3] = nms_missilies[index_row_of_array][3] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // used
        {
            nms_missilies[index_row_of_array][4] = nms_missilies[index_row_of_array][4] + line[i];
            i++;
        }
        i++;
        index_row_of_array++;
    }
    count_nms_missilies = index_row_of_array;
    file.close();
    return 1;
}
// to fetch nms missilies
int fetch_nms_subarine()
{
    int index_row_of_array = count_nms_subarine;
    int i = 0;
    string file_path = "instruments/nms_subarine.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') //name
        {
            nms_subarine[index_row_of_array][0] = nms_subarine[index_row_of_array][0] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // range
        {
            nms_subarine[index_row_of_array][1] = nms_subarine[index_row_of_array][1] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // price
        {
            nms_subarine[index_row_of_array][2] = nms_subarine[index_row_of_array][2] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // stock
        {
            nms_subarine[index_row_of_array][3] = nms_subarine[index_row_of_array][3] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // used
        {
            nms_subarine[index_row_of_array][4] = nms_subarine[index_row_of_array][4] + line[i];
            i++;
        }
        i++;
        index_row_of_array++;
    }
    count_nms_subarine = index_row_of_array;
    file.close();
    return 1;
}
// to fetch nms missilies
int fetch_nms_surface_ships()
{
    int index_row_of_array = count_nms_surface_ships;
    int i = 0;
    string file_path = "instruments/nms_surface_ship.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') //name
        {
            nms_surface_ships[index_row_of_array][0] = nms_surface_ships[index_row_of_array][0] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // range
        {
            nms_surface_ships[index_row_of_array][1] = nms_surface_ships[index_row_of_array][1] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // price
        {
            nms_surface_ships[index_row_of_array][2] = nms_surface_ships[index_row_of_array][2] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // stock
        {
            nms_surface_ships[index_row_of_array][3] = nms_surface_ships[index_row_of_array][3] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // used
        {
            nms_surface_ships[index_row_of_array][4] = nms_surface_ships[index_row_of_array][4] + line[i];
            i++;
        }
        i++;
        index_row_of_array++;
    }
    count_nms_surface_ships = index_row_of_array;
    file.close();
    return 1;
}

// to fetch afms air craft
int fetch_afms_air_craft()
{
    int index_row_of_array = count_afms_air_craft;
    int i = 0;
    string file_path = "instruments/afms_air_craft.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') //name
        {
            afms_air_craft[index_row_of_array][0] = afms_air_craft[index_row_of_array][0] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // range
        {
            afms_air_craft[index_row_of_array][1] = afms_air_craft[index_row_of_array][1] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // price
        {
            afms_air_craft[index_row_of_array][2] = afms_air_craft[index_row_of_array][2] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // stock
        {
            afms_air_craft[index_row_of_array][3] = afms_air_craft[index_row_of_array][3] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // used
        {
            afms_air_craft[index_row_of_array][4] = afms_air_craft[index_row_of_array][4] + line[i];
            i++;
        }
        i++;
        index_row_of_array++;
    }
    count_afms_air_craft = index_row_of_array;
    file.close();
    return 1;
}
// to fetch afms weapons
int fetch_afms_weapons()
{
    int index_row_of_array = count_afms_weapons;
    int i = 0;
    string file_path = "instruments/afms_weapons.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') //name
        {
            afms_weapons[index_row_of_array][0] = afms_weapons[index_row_of_array][0] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // range
        {
            afms_weapons[index_row_of_array][1] = afms_weapons[index_row_of_array][1] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // price
        {
            afms_weapons[index_row_of_array][2] = afms_weapons[index_row_of_array][2] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // stock
        {
            afms_weapons[index_row_of_array][3] = afms_weapons[index_row_of_array][3] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // used
        {
            afms_weapons[index_row_of_array][4] = afms_weapons[index_row_of_array][4] + line[i];
            i++;
        }
        i++;
        index_row_of_array++;
    }
    count_afms_weapons = index_row_of_array;
    file.close();
    return 1;
}
// to fetch afms missilies
int fetch_afms_missilies()
{
    int index_row_of_array = count_afms_missilies;
    int i = 0;
    string file_path = "instruments/afms_missilies.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') //name
        {
            afms_missilies[index_row_of_array][0] = afms_missilies[index_row_of_array][0] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // range
        {
            afms_missilies[index_row_of_array][1] = afms_missilies[index_row_of_array][1] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // price
        {
            afms_missilies[index_row_of_array][2] = afms_missilies[index_row_of_array][2] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // stock
        {
            afms_missilies[index_row_of_array][3] = afms_missilies[index_row_of_array][3] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // used
        {
            afms_missilies[index_row_of_array][4] = afms_missilies[index_row_of_array][4] + line[i];
            i++;
        }
        i++;
        index_row_of_array++;
    }
    count_afms_missilies = index_row_of_array;
    file.close();
    return 1;
}
// to fetch afms missilies
int fetch_afms_planes()
{
    int index_row_of_array = count_afms_planes;
    int i = 0;
    string file_path = "instruments/afms_planes.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') //name
        {
            afms_planes[index_row_of_array][0] = afms_planes[index_row_of_array][0] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // range
        {
            afms_planes[index_row_of_array][1] = afms_planes[index_row_of_array][1] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // price
        {
            afms_planes[index_row_of_array][2] = afms_planes[index_row_of_array][2] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // stock
        {
            afms_planes[index_row_of_array][3] = afms_planes[index_row_of_array][3] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // used
        {
            afms_planes[index_row_of_array][4] = afms_planes[index_row_of_array][4] + line[i];
            i++;
        }
        i++;
        index_row_of_array++;
    }
    count_afms_planes = index_row_of_array;
    file.close();
    return 1;
}
// to fetch afms missilies
int fetch_afms_trackers()
{
    int index_row_of_array = count_afms_trackers;
    int i = 0;
    string file_path = "instruments/afms_trackers.txt";
    string line;
    ifstream file;
    file.open(file_path, ios::in);
    while (!file.eof())
    {
        getline(file, line);
        i = 0;
        while (line[i] != ',') //name
        {
            afms_trackers[index_row_of_array][0] = afms_trackers[index_row_of_array][0] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // range
        {
            afms_trackers[index_row_of_array][1] = afms_trackers[index_row_of_array][1] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // price
        {
            afms_trackers[index_row_of_array][2] = afms_trackers[index_row_of_array][2] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // stock
        {
            afms_trackers[index_row_of_array][3] = afms_trackers[index_row_of_array][3] + line[i];
            i++;
        }
        i++;
        while (line[i] != ',') // used
        {
            afms_trackers[index_row_of_array][4] = afms_trackers[index_row_of_array][4] + line[i];
            i++;
        }
        i++;
        index_row_of_array++;
    }
    count_afms_trackers = index_row_of_array;
    file.close();
    return 1;
}





//                              Yes or No option
int yes_or_no(int perior_option)
{
    string select_option;
select:
    gotoxy(columns_to_fit + 15, 10);
    cout << "\33[31m"
         << "IS YOU WANT TO REPEAT THAT TASK "
         << "\33[34m"
         << "(" << perior_option << " / "
         << "\33[34m"
         << "0): ";
    gotoxy(columns_to_fit + 56, 10);
    cout << "                       ";
    gotoxy(columns_to_fit + 56, 10);
    cin >> select_option;
    if (select_option != to_string(perior_option) && select_option != to_string(0))
    {
        goto select;
    }
    return stoi(select_option);
}

//                                      LOGIN AND DESIG PHASE
// TO MANAGE SCREEN SIZE
int screen_size()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns_of_screen = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows_of_screen = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    rows_to_fit = rows_of_screen / 4;
    columns_to_fit = columns_of_screen / 4;
    return 0;
}
// TAKE USER ID FROM DIFFERENT FUNCTINS THEN CHECK IT AND RETURN NUMBER
int user_id()
{
    int to_count_user_word;
    string user, pass;
in_case_wrong:
    system("cls");
    first_page_title();
    home_page();
    user = take_username();
    pass = take_password();
    to_count_user_word = user.length();
    if (ams_user_password_login(user, pass))
    {
        batch_id_security = user;
        return 1;
    }
    if (nms_user_password_login(user, pass))
    {
        batch_id_security = user;
        return 2;
    }
    if (afms_user_password_login(user, pass))
    {
        batch_id_security = user;
        return 3;
    }
    if (army_officer_user_password_login(user, pass))
    {
        batch_id_security = user;
        return 4;
    }
    
    if (navy_officer_user_password_login(user, pass))
    {
        batch_id_security = user;
        return 5;
    }
    if (air_force_officer_user_password_login(user, pass))
    {
        batch_id_security = user;
        return 6;
    }
    if (army_soldier_user_password_login(user, pass))
    {
        batch_id_security = user;
        return 7;
    }
    else
    {
        gotoxy(columns_of_screen / 2, rows_of_screen - 3);
        cout << "INVALID !";
        Sleep(3000);
        goto in_case_wrong;
    }
}
// take user id
// AMS LOGIN
bool ams_user_password_login(string user, string password)
{
    bool checker = false;
    for (int i = 0; i < army_soldier_count; i++)
    {
        if (user == army_officer_array[0][i] && password == "AMS18082")
        {
            checker = true;
            return checker;
        }
    }
    return checker;
}
// NMS LOGIN
bool nms_user_password_login(string user, string password)
{
    bool checker = false;
    for (int i = 0; i < army_soldier_count; i++)
    {
        if (user == navy_officer_array[0][i] && password == "NMS18082")
        {
            checker = true;
            return checker;
        }
    }
    return checker;
}
// AFMS LOGIN
bool afms_user_password_login(string user, string password)
{
    bool checker = false;
    for (int i = 0; i < army_soldier_count; i++)
    {
        if (user == air_force_officer_array[0][i] && password == "AFMS18082")
        {
            checker = true;
            return checker;
        }
    }
    return checker;
}
// asms login
bool army_soldier_user_password_login(string user, string password)
{
    bool checker = false;
    for (int i = 0; i < army_soldier_count; i++)
    {
        if (user == army_soldier_array[0][i] && password == army_soldier_array[7][i])
        {
            batch_id_index_security = i;
            checker = true;
            return checker;
        }
    }
    return checker;
}
// aRMY OFFICERms login
bool army_officer_user_password_login(string user, string password)
{
    bool checker = false;
    for (int i = 0; i < army_officer_count; i++)
    {
        if (user == army_officer_array[0][i] && password == army_officer_array[7][i])
        {

            batch_id_index_security = i;
            checker = true;
            return checker;
        }
    }
    return checker;
}
// NAVY LOGIN
bool navy_officer_user_password_login(string user, string password)
{
    bool checker = false;
    for (int i = 0; i < navy_officer_count; i++)
    {
        if (user == navy_officer_array[0][i] && password == navy_officer_array[7][i])
        {

            batch_id_index_security = i;
            checker = true;
            return checker;
        }
    }
    return checker;
}
// air force
bool air_force_officer_user_password_login(string user, string password)
{
    bool checker = false;
    for (int i = 0; i < air_force_officer_count; i++)
    {
        if (user == air_force_officer_array[0][i] && password == air_force_officer_array[7][i])
        {

            batch_id_index_security = i;
            checker = true;
            return checker;
        }
    }
    return checker;
}

// first page title
void first_page_title()
{
    int columns;
    print_start_box(5, columns_of_screen);
    to_print_in_title("PAKISTAN FORCES MANAGEMENT SYSTEM");
    columns = columns_to_fit / 7;
    gotoxy(columns, 6);
    cout << "\033[32m"
         << "..../\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\")=======||||||D		              DIE IN THE PATH OF SUCCESS                       (|||||=======/\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\")..." << endl;
    gotoxy(columns, 7);
    cout << "\033[32m"
         << "/\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\\                                                                                           /\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\"\\" << endl;
    gotoxy(columns, 8);
    cout << "\033[32m"
         << "\\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/                                                                                           \\@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@/" << endl
         << endl
         << endl;
}
// PRINT START BOX
void print_start_box(int rows, int columns)
{
    for (int i = 1; i <= rows; ++i)
    {
        for (int j = 1; j <= columns; ++j)
        {
            if (i == 1 || i == rows || j == 1 || j == columns)
            {
                cout << "#";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}
// TITLE ON EVERY PAGE AND USE TO PRINT TITLE FUNCTION IN IT
void title(string content_inside_title)
{
    system("cls");
    print_start_box(5, columns_of_screen - 2);
    gotoxy((columns_of_screen / 3) - 5, 6);
    cout << "\033[31m"
         << "And when you judge between people, judge with justice. (Al Quran)"
         << "\033[37m" << endl;
    gotoxy((columns_of_screen / 3) - 5, 7);
    cout << "_________________________________________________________________ " << endl;

    gotoxy((columns_of_screen / 3) - 5, rows_of_screen - 2);
    cout << "_________________________________________________________________" << endl;
    to_print_in_title(content_inside_title);
} // GOTOXY
// GOTOXY
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
// GETCHAR
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufsize;
    coordBufsize.X = 1;
    coordBufsize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufsize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}
// TAKE USERNAME
string take_username()
{
    string user;
    gotoxy(columns_to_fit + 15, 17);
    cin >> user;
    return user;
}
// take password
string take_password()
{
    string pass;
    gotoxy(columns_to_fit + 15, 23);
    cin >> pass;
    return pass;
}
// print content_inside_title
void to_print_in_title(string content_inside_title)
{
    gotoxy(columns_of_screen / 2 - 17, 2);
    cout << content_inside_title;
}
// HOME PAGE THINGS
void home_page()
{
    print_line(columns_to_fit, 14, columns_of_screen - columns_to_fit);
    print_line(columns_to_fit, 20, columns_of_screen - columns_to_fit);
    print_line(columns_to_fit, 26, columns_of_screen - columns_to_fit);
    gotoxy(columns_to_fit, 17);
    cout << "\33[34m"
         << "USERNAME: ";
    gotoxy(columns_to_fit, 23);
    cout << "\33[34m"
         << "PASSWORD: ";
}
// PRINT LINE
void print_line(int start_point, int row, int end_point)
{
    for (int i = start_point; i <= end_point; i++)
    {
        gotoxy(i, row);
        cout << "*";
    }
}
// show note
void to_show_note(string text)
{
	gotoxy(columns_of_screen/3 + 5, rows_of_screen - 3);
	cout<<"NOTE EVERY BACTH ID MUST STARTED WITH "<<text;
}
// SELECTING THINGS
int selecting_function(int x, int y, int n)
{
    int x_axis = x;
    int y_axis = y;
    int option = 1;
    slecter_horizantel_line(x_axis, y_axis);
    while (true)
    {
        if (GetAsyncKeyState(VK_DOWN) && option <= n)
        {
            erase_slecter_horizantel_line(x_axis, y_axis);
            if (option < n)
            {
                y_axis = y_axis + 4;
                option = option + 1;
            }
            slecter_horizantel_line(x_axis, y_axis);
            Sleep(300);
            cout << option;
        }
        if (GetAsyncKeyState(VK_UP) && option > 1)
        {
            erase_slecter_horizantel_line(x_axis, y_axis);
            y_axis = y_axis - 4;
            option = option - 1;
            slecter_horizantel_line(x_axis, y_axis);
            Sleep(300);
            cout << option;
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            Sleep(50);
            return option;
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            Sleep(50);
            return n + 1;
        }
    }
}
// LINE use in selecter;
void slecter_horizantel_line(int x, int y)
{
    for (int i = 0; i < 25; i++)
    {
        gotoxy(x + i, y);
        cout << "\33[32m"
             << "=";
    }
}
// ERase line
void erase_slecter_horizantel_line(int x, int y)
{
    for (int i = 0; i < 25; i++)
    {
        gotoxy(x + i, y);
        cout << "\33[32m"
             << " ";
    }
}
void invalid_function()
{
	gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 5);
	cout << "INVALID INPUT FROM YOU";
	Sleep(1000);
	gotoxy(columns_of_screen / 2 - 10, rows_of_screen - 5);
	cout << "                                 ";
}

//                              MENU SHOWER PHASE
// USER 7
int to_show_main_menu_asms(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << soldiers_main_menu_asms[i];
        rows = rows + 4;
    }
    return 1;
}
// to show personal details option and things
int to_show_personal_details_from_asms()
{
    int arr_index = 0;
    to_show_personal_details_options_asms();
    for (int i = 0; i < 16; i = i + 2)
    {
        gotoxy(columns_of_screen / 3 + 30, 15 + i);
        cout << army_soldier_array[arr_index][batch_id_index_security];
        arr_index++;
    }
    gotoxy(columns_of_screen / 3 + 10, rows_of_screen - 5);
    cout << "PRESS ANY KEY TO GO BACK";
    getch();
    return 1;
}
// to show personal details options by asms
void to_show_personal_details_options_asms()
{
    int details_index = 0;
    for (int i = 0; i < 16; i = i + 2)
    {
        gotoxy(columns_of_screen / 3, 15 + i);
        cout << personal_details_options_asms[details_index];
        details_index++;
    }
}
// feedback taker
void feedback()
{
    string line;
    title("FEEDBACK PAGE");
    fstream file;
    file.open("feedback_file/feedbackfile.txt", ios::app);
    cin.ignore();
    gotoxy(5, 14);
    getline(cin, line);
    file << batch_id_security;
    file << ",";
    file << line;
    file << endl;
    file.close();
}
// to calculate salary
int to_calculate_salary_asms()
{
    while (true)
    {
        int main_menu_taker = 2;
    salary:
        int salary = stoi(army_soldier_array[4][batch_id_index_security]);
        int bonus[3] = {1000, 5000, 4000};
        char catagory;
        float e_day, special_day, total, days_amount;
        system("cls");
        print_start_box(5, columns_of_screen);
        title("SALARY CALCULATOR");
        gotoxy(columns_to_fit + 10, 16);
        cout << "ENTER CATAGORY(1.DRIVER , 2.BOARDER , 3.CHEFF): ";
        gotoxy(columns_to_fit + 60, 16);
        cin >> catagory;
        gotoxy(columns_to_fit + 10, 18);
        cout << "ENTER EXTRA WORKING DAYS: ";
        gotoxy(columns_to_fit + 50, 18);
        cin >> e_day;
        gotoxy(columns_to_fit + 10, 20);
        cout << "ENTER MOVEMENT(EID, NATIONAL etc): ";
        gotoxy(columns_to_fit + 50, 20);
        cin >> special_day;
        if (catagory == '1')
        {
            total = salary + (bonus[0] * special_day) + ((salary / 30) * (e_day));
        }
        else if (catagory == '2')
        {
            total = salary + (bonus[1] * special_day) + ((salary / 30) * (e_day));
        }
        else if (catagory == '3')
        {
            total = salary + (bonus[2] * special_day) + ((salary / 30) * (e_day));
        }
        else
        {
            goto salary;
        }
        gotoxy(columns_of_screen / 2 - columns_to_fit / 2, rows_of_screen - 5);
        cout << "TOTAL SALARY: " << total;
        main_menu_taker = yes_or_no(main_menu_taker);
        if (main_menu_taker == 0)
        {
            return 0;
        }
    }
}
// Validations

// numeric validation
bool numeric_validation(string word)
{
    int count = 0;
    char number[10] = {'0','1','2','3','4','5','6','7','8','9',};
    for(int i = 0 ; i < word.length() ; i++)
    {   
        for(int j = 0 ; j < 10 ; j++)
        {
        if((word[i] == number[j]))
        {
            count++;
        }
        }
    }
    if(count == word.length())
    {
        return false;
    }
    else
    {
    return true;
    }
}
// batch_id validations soldiers
bool soldiers_batch_id_validations(string word)
{
    int count = 0;
    char number[11] = {'0','1','2','3','4','5','6','7','8','9','-'};
    for(int i = 0 ; i < word.length() ; i++)
    {   
        for(int j = 0 ; j < 11 ; j++)
        {
        if((word[i] == number[j]))
        {
            count++;
        }
        }
    }
    if(count == word.length())
    {
        return false;
    }
    else
    {
    return true;
    }
}
// batch_id validations soldiers
bool officer_batch_id_validations(string word)
{
    int count = 0;
    char number[20] = {'0','1','2','3','4','5','6','7','8','9','-','P','M','I','N','A','V','E','A','G'};
    
    for(int i = 0 ; i < word.length() ; i++)
    {   
        for(int j = 0 ; j < 20 ; j++)
        {
        if((word[i] == number[j] ))
        {
            count++;
        }
        
        }
    }
    if(count == word.length())
    {
        return false;
    }
    else
    {
    return true;
    }
}

// Character type validations
bool character_type_validation(string word)
{
    int count = 0;
    for(int i = 0 ; i < word.length() ; i++)
    {
        if((word[i] > 96 && word[i] < 124) || (word[i] > 63 && word[i] < 123) || word[i] == ' ' )
        {
            count++;
        }
    }
    if(count == word.length())
    {
        return false;
    }
    else
    {
    return true;
    }
}
// Password validation
bool password_validation(string word)
{
    int count = 0;
    for(int i = 0 ; i < word.length() ; i++)
    {
        if(word[i] == ' ' )
        {
            return true;
        }
    }
        return false;
    
}

// validion in adding mens
bool validation_in_adding_soldiers_persons(int arr_index,string word)
{   bool check = false;
    if(arr_index == 0)
    {
        check = soldiers_batch_id_validations(word);
        if(check == true)
        {
            return true;
        }
    }
    if(arr_index >=1 && arr_index <= 3)
    {
        check = character_type_validation(word);
        if(check == true)
        {
            return true;
        }
    }
    if(arr_index >= 4 && arr_index <= 6 )
    {
        check = numeric_validation(word);
        if(check == true)
        {
            return true;
        }
    }
    if(arr_index == 7)
    {
        check = password_validation(word);
        if(check == true)
        {
            return true;
        }
    }

    return false;
}
// validion in adding officers
bool validation_in_adding_officers_persons(int arr_index,string word)
{   bool check = false;
    if(arr_index == 0)
    {
        check = officer_batch_id_validations(word);
        if(check == true)
        {
            return true;
        }
    }
    if(arr_index >=1 && arr_index <= 3)
    {
        check = character_type_validation(word);
        if(check == true)
        {
            return true;
        }
    }
    if(arr_index >= 4 && arr_index <= 6 )
    {
        check = numeric_validation(word);
        if(check == true)
        {
            return true;
        }
    }
    if(arr_index == 7)
    {
        check = password_validation(word);
        if(check == true)
        {
            return true;
        }
    }

    return false;
}

//                          USER 1 AMS TEAM FUNCTIONS
//                          USER 1 SUB SELECT SOLDIER
int to_show_main_menu_ams(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << main_menu_names_ams[i];
        rows = rows + 4;
    }
    return 1;
}
int to_show_sub_menu_army_soldier_ams(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << sub_menu_army_soldiers_ams[i];
        rows = rows + 4;
    }
    return 1;
}
// id INDEX IT GIVE US BACK
int id_take_to_fetch_and_id_check_soldiers_ams()
{
	string batch_id;
	int index = army_soldier_count;
	again_take_batch_id:
	gotoxy(columns_of_screen / 2 - 10, 9);
	cout << "                           ";
	gotoxy(columns_of_screen / 2 - 10, 9);
	cout << "BATCH ID: ";
	gotoxy(columns_of_screen / 2, 9);
	cin >> batch_id;
	for(int i = 0 ; i < index ; i++)
	{
		if(batch_id == army_soldier_array[0][i])
		{
		return i;		
		}
	}
	invalid_function();
	goto again_take_batch_id;
}
int to_show_personal_details_from_soldiers_array(int batch_id_index)
{
	title("PERSONAL DETAILS OF SOLDIERS");
	int arr_index = 0;
    to_show_personal_details_options_soldiers_ams();
	for(int i = 0 ; i < 16 ; i = i + 2)
	{
	gotoxy(columns_of_screen/3 + 30,15 + i);
	cout<<army_soldier_array[arr_index][batch_id_index];
	arr_index++;
	}
	gotoxy(columns_of_screen/3 + 10,rows_of_screen - 5);
	cout<<"PRESS ANY KEY TO GO BACK";
	getch();
	return 1;

}
// to show personal details options by soldiers ams
void to_show_personal_details_options_soldiers_ams()
{
    int details_index = 0;
    for (int i = 0; i < 16; i = i + 2)
    {
        gotoxy(columns_of_screen / 3, 15 + i);
        cout << personal_details_options_ams_soldiers[details_index];
        details_index++;
    }
}
// to add data in soldier array AMS
void to_add_data_in_soldiers_array_ams() 
{   string word;
    
	to_show_personal_details_options_soldiers_ams();
    string must = "120-";
	int index = army_soldier_count;
	string batch_id;
	int arr_index = 1;
	function_start:
	gotoxy(columns_of_screen/3 + 30,15);
	cout<<"                          ";
	gotoxy(columns_of_screen/3 + 30,15);
	cin>>batch_id;
	for(int i = 0 ; i < index ; i++)
	{
		if(batch_id == army_soldier_array[0][i])
		{
			invalid_function();
			goto function_start;
		}
		if((batch_id[0] != must[0] || batch_id[1] != must[1] || batch_id[2] != must[2] || batch_id[3] != must[3]))
		{
			invalid_function();
			goto function_start;
		}
	}
    if(validation_in_adding_soldiers_persons(0,batch_id))
    {
        goto function_start;
    }
	army_soldier_array[0][index] = batch_id;
	for(int i = 2 ; i < 16 ; i = i + 2)
	{
	if(arr_index == 1)
	{
		cin.ignore();
	}
	backer:
	gotoxy(columns_of_screen/3 + 30,15 + i);
	getline(cin,word);
    if(validation_in_adding_soldiers_persons(arr_index,word))
    {
        gotoxy(columns_of_screen/3 + 30,15 + i);
        cout<<"                             ";
        goto backer;
    }
    army_soldier_array[arr_index][index] = word;
	arr_index++;
	}
	index++;
    army_soldier_count = index;
}
// to add data in soldier txt
void to_add_data_in_soldier_txt_ams()
{
	int index = army_soldier_count;
	string file_path = "ams_folder/ams_army_soldiers.txt";
    fstream file;
	file.open(file_path,ios::app);
	file << endl;
	for(int i = 0 ; i < 8 ; i++)
	{
		file << army_soldier_array[i][index - 1];
		file << ",";
	}	
    file.close();
}
// to edit data in soldiers array
void to_edit_data_in_soldiers_array_ams(int batch_id_index) 
{
    int arr_index = 0;
    string word;
	to_show_personal_details_options_soldiers_ams();
	for(int i = 0 ; i < 16 ; i = i + 2)
	{
	if(arr_index == 0)
	{
		cin.ignore();
	}
	backer:
	gotoxy(columns_of_screen/3 + 30,15 + i);
	getline(cin,word);
    if(validation_in_adding_soldiers_persons(arr_index,word))
    {
        gotoxy(columns_of_screen/3 + 30,15 + i);
        cout<<"                             ";
        goto backer;
    }
    army_soldier_array[arr_index][batch_id_index] = word;
	arr_index++;
	}
	
}
// to add whole array dats in soldier txt
void to_add_whole_data_in_soldier_txt_ams()
{

	string file_path = "ams_folder/ams_army_soldiers.txt";
    fstream file;
	file.open(file_path,ios::out);
    
    for(int columns = 0 ; columns < army_soldier_count ; columns++)
	{   if(columns != 0)
        {
	    file << endl;
        }
        for(int rows = 0 ; rows < 8 ; rows++)
		{
        file << army_soldier_array[rows][columns];
		file << ",";
        }
	}
    file.close();	
}
// to show menu of retired soldiers
int to_show_retired_menu_ams(int no_of_index)
{
    int rows = 15;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << retired_options_ams[i];
        rows = rows + 4;
    }
    return 1;
}
// view retired soldiers
void to_view_retired_soldier_data_ams()
{   title("RETIRED SOLDIERS SYSTEM");
    for(int i = 0 ; i < retired_army_soldier_count ; i++)
    {
        gotoxy(15,14 + i);
        cout<<"BATCH ID: "<<retired_army_soldier_array[0][i]<<" | "<<"NAME: "<<retired_army_soldier_array[1][i]<<" | "<<"SALARY: "<<retired_army_soldier_array[4][i]<<" | "<<"AGE: "<<retired_army_soldier_array[5][i]<<" | "<<endl;
    }
    gotoxy(columns_of_screen/3,10);
    cout<<"PRESS ANY KEY TO GO BACK";
    getch();
}
// to add removed soldier in retired
void to_add_removed_soldier_in_retired_ams(int batch_index)
{
    int index = retired_army_soldier_count;
    for(int i = 0 ; i < 8; i++)
    {
        retired_army_soldier_array[i][index] = army_soldier_array[i][batch_index]; 
        
    }
    retired_army_soldier_count++;

}
// to remove retired soldier from soldiers array
void to_remove_retired_soldier_from_array_ams(int batch_index)
{
    for(int col = batch_index ; col < army_soldier_count - 1 ; col++)
    {
        for(int row = 0; row < 8 ; row++)
        {
            army_soldier_array[row][col] = army_soldier_array[row][col + 1]; 
        }
    }
    army_soldier_count--;
    cout<<"\33[32m"<<army_soldier_count;
    getch();
} 
// to add whole array dats in retired soldier txt
void to_add_whole_data_in_retired_soldier_txt_ams()
{
    int i = 0;
	string file_path = "retired/ams_retired_soldiers.txt";
    fstream file;
	file.open(file_path,ios::out);
    
    for(int columns = 0 ; columns < retired_army_soldier_count ; columns++)
	{   
        if(columns > 0)
        {
	    file << endl;
        }
        for(int rows = 0 ; rows < 8 ; rows++)
		{
        file << retired_army_soldier_array[rows][columns];
		file << ",";
        }
        i++;
	}
    retired_army_soldier_count = i;
    file.close();	
}

// to show menu of matryed soldiers
int to_show_matryed_menu_ams(int no_of_index)
{
    int rows = 15;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << matryed_option[i];
        rows = rows + 4;
    }
    return 1;
}
// to view matryed
int to_view_matryed(string address)
{
	int i = 14;
	string matryed;
	ifstream view_matryedfile;
	view_matryedfile.open(address);
	while (!view_matryedfile.eof())
	{
		getline(view_matryedfile,matryed);
		cout << "\33[33m";
		gotoxy(columns_of_screen / 3, i);
		cout << matryed;
		i++;
	}
}
// to ADD  Matryed
int to_add_matryed(string address)
{
	string matryed;
	fstream recordfile;
	recordfile.open(address, ios::app);
	gotoxy(columns_of_screen / 3 - 2, 18);
	cout << "ENTER NAME OF OUR HERO";
	gotoxy(columns_to_fit + 10, 20);
    cin.ignore();
	getline(cin,matryed);
	recordfile << endl
			   << matryed;
	recordfile.close();
}
//                      user 2 sub army officer
int to_show_sub_menu_army_officer_ams(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << sub_menu_army_officers_ams[i];
        rows = rows + 4;
    }
    return 1;
}
int id_take_to_fetch_and_id_check_officer_ams()
{
	string batch_id;
	int index = army_officer_count;
	again_take_batch_id:
	gotoxy(columns_of_screen / 2 - 10, 9);
	cout << "                           ";
	gotoxy(columns_of_screen / 2 - 10, 9);
	cout << "BATCH ID: ";
	gotoxy(columns_of_screen / 2, 9);
	cin >> batch_id;
	for(int i = 0 ; i < index ; i++)
	{
		if(batch_id == army_officer_array[0][i])
		{
		return i;		
		}
	}
	invalid_function();
	goto again_take_batch_id;
}
int to_show_personal_details_from_officer_array(int batch_id_index)
{
	title("PERSONAL DETAILS OF OFFICERS");
	int arr_index = 0;
    to_show_personal_details_options_officer_ams();
	for(int i = 0 ; i < 16 ; i = i + 2)
	{
	gotoxy(columns_of_screen/3 + 30,15 + i);
	cout<<army_officer_array[arr_index][batch_id_index];
	arr_index++;
	}
	gotoxy(columns_of_screen/3 + 10,rows_of_screen - 5);
	cout<<"PRESS ANY KEY TO GO BACK";
	getch();
	return 1;

}
// personal details options of officers
void to_show_personal_details_options_officer_ams()
{
    int details_index = 0;
    for (int i = 0; i < 16; i = i + 2)
    {
        gotoxy(columns_of_screen / 3, 15 + i);
        cout << personal_details_options_ams_officers[details_index];
        details_index++;
    }
}
// to add data in soldier array AMS
void to_add_data_in_officer_array_ams() 
{
    string word;
	to_show_personal_details_options_officer_ams();
    string must = "PMI-";
	int index = army_officer_count;
	string batch_id;
	int arr_index = 1;
	function_start:
	gotoxy(columns_of_screen/3 + 30,15);
	cout<<"                          ";
	gotoxy(columns_of_screen/3 + 30,15);
	cin>>batch_id;
	for(int i = 0 ; i < index ; i++)
	{ 
		if(batch_id == army_officer_array[0][i])
		{
			invalid_function();
			goto function_start;
		}
		if((batch_id[0] != must[0] || batch_id[1] != must[1] || batch_id[2] != must[2] || batch_id[3] != must[3]))
		{
			invalid_function();
			goto function_start;
		}
	}
    if(validation_in_adding_officers_persons(0,batch_id))
    {
        goto function_start;
    }
	army_officer_array[0][index] = batch_id;
	for(int i = 2 ; i < 16 ; i = i + 2)
	{
	if(arr_index == 1)
	{
		cin.ignore();
	}
	backer:
	gotoxy(columns_of_screen/3 + 30,15 + i);
    getline(cin,word);
    if(validation_in_adding_officers_persons(arr_index,word))
    {
        gotoxy(columns_of_screen/3 + 30,15 + i);
        cout<<"                             ";
        goto backer;
    }
	army_officer_array[arr_index][index] = word;
	arr_index++;
	}
	index++;
    army_officer_count = index;
}
// to add data in officer txt
void to_add_data_in_officer_txt_ams()
{
	int index = army_officer_count;
	string file_path = "ams_folder/ams_army_officer.txt";
    fstream file;
	file.open(file_path,ios::app);
	file << endl;
	for(int i = 0 ; i < 8 ; i++)
	{
		file << army_officer_array[i][index - 1];
		file << ",";
	}	
    file.close();
}
// to edit data in officer array
void to_edit_data_in_officer_array_ams(int batch_id_index) 
{
    string word;
    int arr_index = 0;
	to_show_personal_details_options_officer_ams();
	for(int i = 0 ; i < 16 ; i = i + 2)
	{
	if(arr_index == 0)
	{
		cin.ignore();
	}
	backer:
	gotoxy(columns_of_screen/3 + 30,15 + i);
	getline(cin,word);
    if(validation_in_adding_officers_persons(arr_index,word))
    {
        gotoxy(columns_of_screen/3 + 30,15 + i);
        cout<<"                             ";
        goto backer;
    }
    army_officer_array[arr_index][batch_id_index] = word ;
	
    arr_index++;
	}
	
}
// to add whole array dats in officer txt
void to_add_whole_data_in_officer_txt_ams()
{
	string file_path = "ams_folder/ams_army_officer.txt";
    fstream file;
	file.open(file_path,ios::out);
    
    for(int columns = 0 ; columns < army_officer_count ; columns++)
	{   if(columns != 0)
        {
	    file << endl;
        }
        for(int rows = 0 ; rows < 8 ; rows++)
		{
        file << army_officer_array[rows][columns];
		file << ",";
        }
	}
    file.close();	
}
// view retired officers
void to_view_retired_officer_data_ams()
{   title("RETIRED OFFICERS SYSTEM");
    for(int i = 0 ; i < retired_army_officer_count ; i++)
    {
        gotoxy(15,14 + i);
        cout<<"BATCH ID: "<<retired_army_officer_array[0][i]<<" | "<<"NAME: "<<retired_army_soldier_array[1][i]<<" | "<<"SALARY: "<<retired_army_soldier_array[4][i]<<" | "<<"AGE: "<<retired_army_soldier_array[5][i]<<" | "<<endl;
    }
    gotoxy(columns_of_screen/3,10);
    cout<<"PRESS ANY KEY TO GO BACK";
    getch();
}
// 
void to_add_removed_officer_in_retired_ams(int batch_index)
{
    int index = retired_army_officer_count;
    for(int i = 0 ; i < 8; i++)
    {
        retired_army_officer_array[i][index] = army_officer_array[i][batch_index]; 
        
    }
    retired_army_officer_count++;

}
// to remove retired soldier from soldiers array
void to_remove_retired_officer_from_array_ams(int batch_index)
{
    for(int col = batch_index ; col < army_officer_count - 1 ; col++)
    {
        for(int row = 0; row < 8 ; row++)
        {
            army_officer_array[row][col] = army_officer_array[row][col + 1]; 
        }
    }
    army_officer_count--;
    cout<<"\33[32m"<<army_officer_count;
    getch();
} 
// to add whole array dats in retired soldier txt
void to_add_whole_data_in_retired_officer_txt_ams()
{
    int i = 0;
	string file_path = "retired/ams_retired_officers.txt";
    fstream file;
	file.open(file_path,ios::out);
    
    for(int columns = 0 ; columns < retired_army_officer_count ; columns++)
	{   
        if(columns > 0)
        {
	    file << endl;
        }
        for(int rows = 0 ; rows < 8 ; rows++)
		{
        file << retired_army_officer_array[rows][columns];
		file << ",";
        }
        i++;
	}
    retired_army_officer_count = i;
    file.close();	
}
// TO TAKE PROVIENCE
string to_take_provience()
{
    string provience;
    back:
    title("OFFICERS IN PROVIENCE");
    gotoxy(columns_of_screen/2 - 15, 12);
    cout<<"ENTER PROVIENCE: ";
    gotoxy(columns_of_screen/2 + 10, 12);
    cin>>provience;
    if(provience == "PUNJAB" || provience == "SINDH" || provience == "KPK" || provience == "BALOCHISTAN" || provience == "KASHMIR" )
    {
        return provience;
        
    }
    goto back;
    
}
// to see data of provience
int to_see_data_from_ams_officer_arrray(int row,string provience)
{   int count = 0;
    for(int i = 0 ; i < army_officer_count ; i++)
    {
        if(army_officer_array[row][i] == provience)
        {
            gotoxy(columns_of_screen/3 ,15 + count);
            cout<<army_officer_array[0][i];
            count++;
        }
    }
    return count;
}
// Soldier under officer
void soldier_under_officers_ams()
{   int j = 0;
    for(int i = 0 ; i < army_officer_count ; i++)
    {   
        soldiers_under_the_officer_ams[0][i] = army_soldier_array[0][j];
        soldiers_under_the_officer_ams[1][i] = army_soldier_array[0][j + 1];
        j = j + 2;
    }
    
}
// SOLDIERS UNDER the officer view
void soldier_under_officer_view_ams(int batch_id)
{
    gotoxy(columns_of_screen/3 + 14, 15);
    cout<<"BATCH ID: "<<soldiers_under_the_officer_ams[0][batch_id];
    gotoxy(columns_of_screen/3 + 14 , 17);
    cout<<"BATCH ID: "<<soldiers_under_the_officer_ams[1][batch_id];
}
//              SUB OPTION 3
int to_show_sub_menu_army_instruments_ams(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << sub_menu_instruments_ams[i];
        rows = rows + 4;
    }
    return 1;
}
//
int to_show_sub_detail_view_army_instruments_ams(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << sub_of_sub_menu_instruments_ams[i];
        rows = rows + 4;
    }
    return 1;
}

// to show carriers details
void to_show_carriers_details()
{
    title("INSTRUMENTS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < count_ams_carriers ; i++)
    {
        gotoxy(columns_of_screen/2 - 20 , 16 + i);
        for(int j = 0 ; j < 5 ; j++)
        {
            cout<<readable_instruments_ams[j];
            cout<<ams_carriers[i][j]<<"   ";
        }
    }
}
// to show weapons details
void to_show_weapons_details()
{
    title("INSTRUMENTS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < count_ams_weapons  ; i++)
    {
        gotoxy(columns_of_screen/2 - 20 , 16 + i);
        for(int j = 0 ; j < 5 ; j++)
        {   cout<<readable_instruments_ams[j];
            cout<<ams_weapons[i][j]<<"  ";
        }
    }

}
// to show missiles details
void to_show_missilies_details()
{
    title("INSTRUMENTS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < count_ams_missilies ; i++)
    {
        gotoxy(columns_of_screen/2 - 20 , 16 + i);
        for(int j = 0 ; j < 5 ; j++)
        {   
            cout<<readable_instruments_ams[j];
            cout<<ams_missilies[i][j]<<"   ";
        }
    }

}
// to show tank details
void to_show_tank_details()
{
    title("INSTRUMENTS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < count_ams_tank  ; i++)
    {
        gotoxy(columns_of_screen/2 - 20 , 16 + i);
        for(int j = 0 ; j < 5 ; j++)
        {   
            cout<<readable_instruments_ams[j];
            cout<<ams_tank[i][j]<<"   ";
        }
    }

}
// to show bombs details
void to_show_atomic_bombs_details()
{
    title("INSTRUMENTS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < count_ams_atomic_bombs  ; i++)
    {
        gotoxy(columns_of_screen/2 - 20 , 16 + i);
        for(int j = 0 ; j < 5 ; j++)
        {   
            cout<<readable_instruments_ams[j];
            cout<<ams_atomic_bombs[i][j]<<"   ";
        }
    }

}
// to_add data in instruments
void to_add_data_in_array_carrier()
{   
    title("EDIT DETAILS OF INSTRUMENTS");
    string word;
    int index = count_ams_carriers;
    for(int i = 0 ; i < 5 ; i++)
    {   back:
        gotoxy(columns_of_screen/3 , 15 + i);
        cout<<readable_instruments_ams[i];
        gotoxy(columns_of_screen/3 + 18 , 15 + i);
        cin>>word;
        if(validation_check_instruments(i,word))
        {
            
            gotoxy(columns_of_screen/3 + 18 , 15 + i);
            cout<<"                               ";
            goto back;
        }
        ams_carriers[index][i] = word; 
    }
    count_ams_carriers++;
}
// to_add data in instruments
void to_add_data_in_array_weapons()
{   
    title("EDIT DETAILS OF INSTRUMENTS");
    string word;
    int index = count_ams_weapons;
    for(int i = 0 ; i < 5 ; i++)
    {   back:
        gotoxy(columns_of_screen/3 , 15 + i);
        cout<<readable_instruments_ams[i];
        gotoxy(columns_of_screen/3 + 18 , 15 + i);
        cin>>word;
        if(validation_check_instruments(i,word))
        {
            
            gotoxy(columns_of_screen/3 + 18 , 15 + i);
            cout<<"                               ";
            goto back;
        }
        ams_weapons[index][i] = word; 
    }
    count_ams_weapons++;
}
// to_add data in instruments
void to_add_data_in_array_missilies()
{   
    title("EDIT DETAILS OF INSTRUMENTS");
    string word;
    int index = count_ams_missilies;
    for(int i = 0 ; i < 5 ; i++)
    {   
        back:
        gotoxy(columns_of_screen/3 , 15 + i);
        cout<<readable_instruments_ams[i];
        gotoxy(columns_of_screen/3 + 18 , 15 + i);
        cin>>word;
        if(validation_check_instruments(i,word))
        {
            gotoxy(columns_of_screen/3 + 18 , 15 + i);
            cout<<"                               ";
            goto back;
        }
        ams_missilies[index][i] = word; 
    }
    count_ams_missilies++;
}
void to_add_data_in_array_tank()
{   
    title("EDIT DETAILS OF INSTRUMENTS");
    string word;
    int index = count_ams_tank;
    for(int i = 0 ; i < 5 ; i++)
    {   
        back:
        gotoxy(columns_of_screen/3 , 15 + i);
        cout<<readable_instruments_ams[i];
        
        gotoxy(columns_of_screen/3 + 18 , 15 + i);
        cin>>word;
        if(validation_check_instruments(i,word))
        {
            gotoxy(columns_of_screen/3 + 18 , 15 + i);
            cout<<"                               ";
            goto back;
        }
        ams_tank[index][i] = word; 
    }
    count_ams_tank++;
}
void to_add_data_in_array_bomb()
{   
    title("EDIT DETAILS OF INSTRUMENTS");
    string word;
    int index = count_ams_atomic_bombs;
    for(int i = 0 ; i < 5 ; i++)
    {   
        back:
        gotoxy(columns_of_screen/3 , 15 + i);
        cout<<readable_instruments_ams[i];
        gotoxy(columns_of_screen/3 + 18 , 15 + i);
        cin>>word;
        if(validation_check_instruments(i,word))
        {
            gotoxy(columns_of_screen/3 + 18 , 15 + i);
            cout<<"                               ";
            goto back;
        }
        ams_atomic_bombs[index][i] = word; 
    }
    count_ams_atomic_bombs++;
}
// validation check instruments
bool validation_check_instruments(int n, string word)
{
    bool check = false;
    if(n == 0)
    {
    check = character_type_validation(word);
    if(check == true)
    {
        return true;
    }
    }
    if(n >= 1 && n <= 4)
    {
    check = numeric_validation(word); 
    if(check == true)
    {
        return true;
    }
    }
    return false;
}
// to add data of Weapons
void to_add_data_of_carrier_in_txt()
{
    string file_path = "instruments/ams_carriers.txt";
    string line;
    fstream file;
    file.open(file_path,ios::app);
    file << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        file << ams_carriers[count_ams_carriers - 1][i];
        file << ","; 
    }
    file.close();
} 
void to_add_data_of_weapons_in_txt()
{
    string file_path = "instruments/ams_weapons.txt";
    string line;
    fstream file;
    file.open(file_path,ios::app);
    file << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        file << ams_weapons[count_ams_weapons - 1][i];
        file << ","; 
    }
    file.close();
} 

void to_add_data_of_tank_in_txt()
{
    string file_path = "instruments/ams_tank.txt";
    string line;
    fstream file;
    file.open(file_path,ios::app);
    file << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        file << ams_tank[count_ams_tank - 1][i];
        file << ","; 
    }
    file.close();
} 

void to_add_data_of_missilies_in_txt()
{
    string file_path = "instruments/ams_missilies.txt";
    string line;
    fstream file;
    file.open(file_path,ios::app);
    file << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        file << ams_missilies[count_ams_missilies - 1][i];
        file << ","; 
    }
    file.close();
} 
void to_add_data_of_bomb_in_txt()
{
    string file_path = "instruments/ams_bombs.txt";
    string line;
    fstream file;
    file.open(file_path,ios::app);
    file << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        file << ams_atomic_bombs[count_ams_atomic_bombs - 1][i];
        file << ","; 
    }
    file.close();
} 
// TO EDIT THE INSTRUMENTS RECORD
void to_edit_instrument_record_carriers()
{
    string option;
    string word;
    title("EDIT THE INSTRUMENTS RECORD");
    gotoxy(columns_of_screen/4,15);
    for(int i = 0 ; i < count_ams_carriers ; i++)
    {
        cout<<i<<". "<<ams_carriers[i][0]<<"   ";
    }
    back:
    gotoxy(columns_of_screen/4,17);
    cin>>option;
    if(numeric_validation(option))
    {
        gotoxy(columns_of_screen/4,17);
        cout<<"                      ";
        goto back;
    }
    if(stoi(option) < count_ams_carriers && stoi(option) >= 0)
    {   int row = stoi(option);
        for(int i = 0 ; i < 5 ; i++)
        {
            gotoxy(columns_of_screen/3,19 + i);
            cout<<readable_instruments_ams[i];
            backer:
            gotoxy(columns_of_screen/3 + 20,19 + i);
            cin>>word;
            if(validation_check_instruments(i,word))
            {
                gotoxy(columns_of_screen/3 + 20,19 + i);
                cout<<"                   ";
                goto backer;    
            }    
            ams_carriers[row][i] = word;        
        }
    }
    else 
    {
        goto back;
    }
}
void to_edit_instrument_record_weapons()
{
    string option;
    string word;
    title("EDIT THE INSTRUMENTS RECORD");
    gotoxy(columns_of_screen/4,15);
    for(int i = 0 ; i < count_ams_weapons ; i++)
    {
        cout<<i<<". "<<ams_weapons[i][0]<<"   ";
    }
    back:
    gotoxy(columns_of_screen/4,17);
    cin>>option;
    if(numeric_validation(option))
    {
        gotoxy(columns_of_screen/4,17);
        cout<<"                      ";
        goto back;
    }
    if(stoi(option) < count_ams_weapons && stoi(option) >= 0)
    {   int row = stoi(option);
        for(int i = 0 ; i < 5 ; i++)
        {
            gotoxy(columns_of_screen/3,19 + i);
            cout<<readable_instruments_ams[i];
            backer:
            gotoxy(columns_of_screen/3 + 20,19 + i);
            cin>>word;
            if(validation_check_instruments(i,word))
            {
                gotoxy(columns_of_screen/3 + 20,19 + i);
                cout<<"                   ";
                goto backer;    
            }    
            ams_weapons[row][i] = word;        
        }
    }
    else 
    {
        goto back;
    }
}
void to_edit_instrument_record_tank()
{
    string option;
    string word;
    title("EDIT THE INSTRUMENTS RECORD");
    gotoxy(columns_of_screen/4,15);
    for(int i = 0 ; i < count_ams_tank ; i++)
    {
        cout<<i<<". "<<ams_tank[i][0]<<"   ";
    }
    back:
    gotoxy(columns_of_screen/4,17);
    cin>>option;
    if(numeric_validation(option))
    {
        gotoxy(columns_of_screen/4,17);
        cout<<"                      ";
        goto back;
    }
    if(stoi(option) < count_ams_tank && stoi(option) >= 0)
    {   int row = stoi(option);
        for(int i = 0 ; i < 5 ; i++)
        {
            gotoxy(columns_of_screen/3,19 + i);
            cout<<readable_instruments_ams[i];
            backer:
            gotoxy(columns_of_screen/3 + 20,19 + i);
            cin>>word;
            if(validation_check_instruments(i,word))
            {
                gotoxy(columns_of_screen/3 + 20,19 + i);
                cout<<"                   ";
                goto backer;    
            }    
            ams_tank[row][i] = word;        
        }
    }
    else 
    {
        goto back;
    }
}
void to_edit_instrument_record_missilies()
{
    string option;
    string word;
    title("EDIT THE INSTRUMENTS RECORD");
    gotoxy(columns_of_screen/4,15);
    for(int i = 0 ; i < count_ams_missilies ; i++)
    {
        cout<<i<<". "<<ams_missilies[i][0]<<"   ";
    }
    back:
    gotoxy(columns_of_screen/4,17);
    cin>>option;
    if(numeric_validation(option))
    {
        gotoxy(columns_of_screen/4,17);
        cout<<"                      ";
        goto back;
    }
    if(stoi(option) < count_ams_missilies && stoi(option) >= 0)
    {   int row = stoi(option);
        for(int i = 0 ; i < 5 ; i++)
        {
            gotoxy(columns_of_screen/3,19 + i);
            cout<<readable_instruments_ams[i];
            backer:
            gotoxy(columns_of_screen/3 + 20,19 + i);
            cin>>word;
            if(validation_check_instruments(i,word))
            {
                gotoxy(columns_of_screen/3 + 20,19 + i);
                cout<<"                   ";
                goto backer;    
            }    
            ams_missilies[row][i] = word;        
        }
    }
    else 
    {
        goto back;
    }
}
void to_edit_instrument_record_bombs()
{
    string option;
    string word;
    title("EDIT THE INSTRUMENTS RECORD");
    gotoxy(columns_of_screen/4,15);
    for(int i = 0 ; i < count_ams_atomic_bombs ; i++)
    {
        cout<<i<<". "<<ams_atomic_bombs[i][0]<<"   ";
    }
    back:
    gotoxy(columns_of_screen/4,17);
    cin>>option;
    if(numeric_validation(option))
    {
        gotoxy(columns_of_screen/4,17);
        cout<<"                      ";
        goto back;
    }
    if(stoi(option) < count_ams_atomic_bombs && stoi(option) >= 0)
    {   int row = stoi(option);
        for(int i = 0 ; i < 5 ; i++)
        {
            gotoxy(columns_of_screen/3,19 + i);
            cout<<readable_instruments_ams[i];
            backer:
            gotoxy(columns_of_screen/3 + 20,19 + i);
            cin>>word;
            if(validation_check_instruments(i,word))
            {
                gotoxy(columns_of_screen/3 + 20,19 + i);
                cout<<"                   ";
                goto backer;    
            }    
            ams_atomic_bombs[row][i] = word;        
        }
    }
    else 
    {
        goto back;
    }
}
// ADD WHOLE DATA IN TXT instruments
void to_add_whole_data_in_txt_carriers()
{
    string file_path = "instruments/ams_carriers.txt";
    string line;
    fstream file;
    file.open(file_path,ios::out);

    for(int i = 0 ; i < count_ams_carriers ; i++)
    {   if(i != 0)
        {
            file << endl;
        }
        for(int j = 0 ; j < 5 ; j++)
        {
        file << ams_carriers[i][j];
        file << ","; 
        }
    }
    file.close();
}
// tank
void to_add_whole_data_in_txt_tank()
{
    string file_path = "instruments/ams_tank.txt";
    string line;
    fstream file;
    file.open(file_path,ios::out);

    for(int i = 0 ; i < count_ams_tank ; i++)
    {   if(i != 0)
        {
            file << endl;
        }
        for(int j = 0 ; j < 5 ; j++)
        {
        file << ams_tank[i][j];
        file << ","; 
        }
    }
    file.close();
}
// mweapons
void to_add_whole_data_in_txt_weapons()
{
    string file_path = "instruments/ams_weapons.txt";
    string line;
    fstream file;
    file.open(file_path,ios::out);

    for(int i = 0 ; i < count_ams_weapons ; i++)
    {   if(i != 0)
        {
            file << endl;
        }
        for(int j = 0 ; j < 5 ; j++)
        {
        file << ams_weapons[i][j];
        file << ","; 
        }
    }
    file.close();
}
// missilies
void to_add_whole_data_in_txt_missilies()
{
    string file_path = "instruments/ams_missilies.txt";
    string line;
    fstream file;
    file.open(file_path,ios::out);

    for(int i = 0 ; i < count_ams_missilies ; i++)
    {   if(i != 0)
        {
            file << endl;
        }
        for(int j = 0 ; j < 5 ; j++)
        {
        file << ams_missilies[i][j];
        file << ","; 
        }
    }
    file.close();
}

void to_add_whole_data_in_txt_bombs()
{
    string file_path = "instruments/ams_bombs.txt";
    string line;
    fstream file;
    file.open(file_path,ios::out);

    for(int i = 0 ; i < count_ams_atomic_bombs ; i++)
    {   if(i != 0)
        {
            file << endl;
        }
        for(int j = 0 ; j < 5 ; j++)
        {
        file << ams_atomic_bombs[i][j];
        file << ","; 
        }
    }
    file.close();
}
// sub menu 4
void graph_ams()
{   int item_quantity[5] = {0,0,0,0,0};
    for(int i = 0 ; i < count_ams_carriers ; i++)
    {
        item_quantity[0] = item_quantity[0] + stoi(ams_carriers[i][2]);
    }
    for(int i = 0 ; i < count_ams_weapons ; i++)
    {
        item_quantity[1] = item_quantity[1] + stoi(ams_weapons[i][2]);
    }
    for(int i = 0 ; i < count_ams_missilies ; i++)
    {
        item_quantity[2] = item_quantity[2] + stoi(ams_missilies[i][2]);
    }
    for(int i = 0 ; i < count_ams_tank ; i++)
    {
        item_quantity[3] = item_quantity[3] + stoi(ams_tank[i][2]);
    }
    for(int i = 0 ; i < count_ams_atomic_bombs ; i++)
    {
        item_quantity[4] = item_quantity[4] + stoi(ams_atomic_bombs[i][2]);
    }
	int j = 0;
	for (int i = columns_of_screen / 8; i < columns_of_screen - 1; i++)
	{
		gotoxy(i, rows_of_screen - 4);
		cout << "*";
	}
	for (int i = rows_of_screen - 4; i > 8; i--)
	{
		gotoxy(columns_of_screen / 8, i);
		cout << "*";
	}
	for (int i = 0; i < 20; i = i + 4)
	{

		gotoxy(2, rows_of_screen / 3 + i);
		cout << sub_of_sub_menu_instruments_ams[j];
		j++;
	}
	int x = 0;
	int screen = columns_of_screen / 8 + 1;
	for (int i = 0; i < 20; i = i + 4)
	{
		for (j = 0; j < item_quantity[x] / 50000; j++)
		{
			gotoxy(screen + j, rows_of_screen / 3 + i);
			cout << "#";
		}
		gotoxy(screen + j, rows_of_screen / 3 + i);
		cout << " ";
		x++;
	}
}
// budget ams
void total_ams_budget()
{
    int item_quantity[5] = {0,0,0,0,0};
    for(int i = 0 ; i < count_ams_carriers ; i++)
    {
        item_quantity[0] = item_quantity[0] + stoi(ams_carriers[i][2]);
    }
    for(int i = 0 ; i < count_ams_weapons ; i++)
    {
        item_quantity[1] = item_quantity[1] + stoi(ams_weapons[i][2]);
    }
    for(int i = 0 ; i < count_ams_missilies ; i++)
    {
        item_quantity[2] = item_quantity[2] + stoi(ams_missilies[i][2]);
    }
    for(int i = 0 ; i < count_ams_tank ; i++)
    {
        item_quantity[3] = item_quantity[3] + stoi(ams_tank[i][2]);
    }
    for(int i = 0 ; i < count_ams_atomic_bombs ; i++)
    {
        item_quantity[4] = item_quantity[4] + stoi(ams_atomic_bombs[i][2]);
    }
    int x = 0;
    for(int i = 0 ; i < 5 ; i++)
    {
        gotoxy(columns_of_screen/3 , 16 + x);
        cout<<sub_of_sub_menu_instruments_ams[i];
        gotoxy(columns_of_screen/3 + 20, 16 + x);
        cout<<item_quantity[i];
        x = x + 2;
    }
}
// SUB 4 MENU CROPS
int to_show_sub_menu_army_crops_ams(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << ams_crops[i];
        rows = rows + 4;
    }
    return 1;
}
void to_show_xxx_khor()
{   
    title("CROPS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < army_soldier_count ; i++)
    {
        if(army_soldier_array[3][i] == "PUNJAB" || army_soldier_array[3][i] == "SINDH")
        {
            gotoxy(columns_of_screen/3,14 + i);
            cout<<"BATCH ID: "<<army_soldier_array[0][i]<<endl;
        }

    }
    for(int i = 0 ; i < army_officer_count ; i++)
    {
        if(army_officer_array[3][i] == "PUNJAB" || army_officer_array[3][i] == "SINDH")
        {
            gotoxy(columns_of_screen/3,14 + i);
            cout<<"BATCH ID: "<<army_officer_array[0][i]<<endl;
            gotoxy(columns_of_screen/3,14 + i + 1);
            cout<<"____________________________________";
        }

    }
}
void to_show_soc_khor()
{   
    
    title("CROPS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < army_soldier_count ; i++)
    {
        if(army_soldier_array[3][i] == "KPK" || army_soldier_array[3][i] == "BALOCHISTAN" || army_soldier_array[3][i] == "KASHMIR")
        {
            gotoxy(columns_of_screen/3,14 + i);
            cout<<"BATCH ID: "<<army_soldier_array[0][i]<<endl;
            
        }

    }
    for(int i = 0 ; i < army_officer_count ; i++)
    {   
        if(army_officer_array[3][i] == "KPK" || army_officer_array[3][i] == "BALOCHISTAN" || army_officer_array[3][i] == "KASHMIR")
        { 
            gotoxy(columns_of_screen/3 + 20,14 + i);
            cout<<"BATCH ID: "<<army_officer_array[0][i]<<endl;
            gotoxy(columns_of_screen/3 + 20,14 + i + 1);
            cout<<"____________________________________";

        }

    }
}
// sub module 5
void to_fetch_feedback()
{
    title("TO SHOW FEEDBACK OF FORCES");
    string file_path = "feedback_file/feedbackfile.txt";
    string line;
    fstream file;
    file.open(file_path,ios::in);
    int i = 0;

    while(!file.eof())
    {   
        getline(file,line);
        gotoxy(columns_of_screen/3 - 5, 16 + i);
        cout<<line;
        i = i + 2;
    }
}

//                                  USER 2
//                                   NMS

//                          USER 2 nms TEAM FUNCTIONS
//                          USER 2 SUB SELECT SOLDIER
int to_show_main_menu_nms(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << main_menu_names_nms[i];
        rows = rows + 4;
    }
    return 1;
}
int to_show_sub_menu_navy_soldier_nms(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << sub_menu_navy_soldiers_nms[i];
        rows = rows + 4;
    }
    return 1;
}
// id INDEX IT GIVE US BACK
int id_take_to_fetch_and_id_check_soldiers_nms()
{
	string batch_id;
	int index = navy_soldier_count;
	again_take_batch_id:
	gotoxy(columns_of_screen / 2 - 10, 9);
	cout << "                           ";
	gotoxy(columns_of_screen / 2 - 10, 9);
	cout << "BATCH ID: ";
	gotoxy(columns_of_screen / 2, 9);
	cin >> batch_id;
	for(int i = 0 ; i < index ; i++)
	{
		if(batch_id == navy_soldier_array[0][i])
		{
		return i;		
		}
	}
	invalid_function();
	goto again_take_batch_id;
}
int to_show_personal_details_from_navy_soldiers_array(int batch_id_index)
{
	title("PERSONAL DETAILS OF NAVY SOLDIERS");
	int arr_index = 0;
    to_show_personal_details_options_soldiers_nms();
	for(int i = 0 ; i < 16 ; i = i + 2)
	{
	gotoxy(columns_of_screen/3 + 30,15 + i);
	cout<<navy_soldier_array[arr_index][batch_id_index];
	arr_index++;
	}
	gotoxy(columns_of_screen/3 + 10,rows_of_screen - 5);
	cout<<"PRESS ANY KEY TO GO BACK";
	getch();
	return 1;

}
// to show personal details options by soldiers nms
void to_show_personal_details_options_soldiers_nms()
{
    int details_index = 0;
    for (int i = 0; i < 16; i = i + 2)
    {
        gotoxy(columns_of_screen / 3, 15 + i);
        cout << personal_details_options_nms_soldiers[details_index];
        details_index++;
    }
}
// to add data in soldier array nms
void to_add_data_in_soldiers_array_nms() 
{   string word;
    
	to_show_personal_details_options_soldiers_nms();
    string must = "121-";
	int index = navy_soldier_count;
	string batch_id;
	int arr_index = 1;
	function_start:
	gotoxy(columns_of_screen/3 + 30,15);
	cout<<"                          ";
	gotoxy(columns_of_screen/3 + 30,15);
	cin>>batch_id;
	for(int i = 0 ; i < index ; i++)
	{
		if(batch_id == navy_soldier_array[0][i])
		{
			invalid_function();
			goto function_start;
		}
		if((batch_id[0] != must[0] || batch_id[1] != must[1] || batch_id[2] != must[2] || batch_id[3] != must[3]))
		{
			invalid_function();
			goto function_start;
		}
	}
    if(validation_in_adding_soldiers_persons(0,batch_id))
    {
        goto function_start;
    }
	navy_soldier_array[0][index] = batch_id;
	for(int i = 2 ; i < 16 ; i = i + 2)
	{
	if(arr_index == 1)
	{
		cin.ignore();
	}
	backer:
	gotoxy(columns_of_screen/3 + 30,15 + i);
	getline(cin,word);
    if(validation_in_adding_soldiers_persons(arr_index,word))
    {
        gotoxy(columns_of_screen/3 + 30,15 + i);
        cout<<"                             ";
        goto backer;
    }
    navy_soldier_array[arr_index][index] = word;
	arr_index++;
	}
	index++;
    navy_soldier_count = index;
}
// to add data in soldier txt
void to_add_data_in_soldier_txt_nms()
{
	int index = navy_soldier_count;
	string file_path = "ams_folder/nms_navy_soldiers.txt";
    fstream file;
	file.open(file_path,ios::app);
	file << endl;
	for(int i = 0 ; i < 8 ; i++)
	{
		file << navy_soldier_array[i][index - 1];
		file << ",";
	}	
    file.close();
}
// to edit data in soldiers array
void to_edit_data_in_soldiers_array_nms(int batch_id_index) 
{
    int arr_index = 0;
    string word;
	to_show_personal_details_options_soldiers_nms();
	for(int i = 0 ; i < 16 ; i = i + 2)
	{
	if(arr_index == 0)
	{
		cin.ignore();
	}
	backer:
	gotoxy(columns_of_screen/3 + 30,15 + i);
	getline(cin,word);
    if(validation_in_adding_soldiers_persons(arr_index,word))
    {
        gotoxy(columns_of_screen/3 + 30,15 + i);
        cout<<"                             ";
        goto backer;
    }
    navy_soldier_array[arr_index][batch_id_index] = word;
	arr_index++;
	}
	
}
// to add whole array dats in soldier txt
void to_add_whole_data_in_soldier_txt_nms()
{

	string file_path = "ams_folder/nms_navy_soldiers.txt";
    fstream file;
	file.open(file_path,ios::out);
    
    for(int columns = 0 ; columns < navy_soldier_count ; columns++)
	{   if(columns != 0)
        {
	    file << endl;
        }
        for(int rows = 0 ; rows < 8 ; rows++)
		{
        file << navy_soldier_array[rows][columns];
		file << ",";
        }
	}
    file.close();	
}
// to show menu of retired soldiers
int to_show_retired_menu_nms(int no_of_index)
{
    int rows = 15;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << retired_options_nms[i];
        rows = rows + 4;
    }
    return 1;
}
// view retired soldiers
void to_view_retired_soldier_data_nms()
{   title("RETIRED SOLDIERS SYSTEM");
    for(int i = 0 ; i < retired_navy_soldier_count ; i++)
    {
        gotoxy(15,14 + i);
        cout<<"BATCH ID: "<<retired_navy_soldier_array[0][i]<<" | "<<"NAME: "<<retired_navy_soldier_array[1][i]<<" | "<<"SALARY: "<<retired_navy_soldier_array[4][i]<<" | "<<"AGE: "<<retired_navy_soldier_array[5][i]<<" | "<<endl;
    }
    gotoxy(columns_of_screen/3,10);
    cout<<"PRESS ANY KEY TO GO BACK";
    getch();
}
// to add removed soldier in retired
void to_add_removed_soldier_in_retired_nms(int batch_index)
{
    int index = retired_navy_soldier_count;
    for(int i = 0 ; i < 8; i++)
    {
        retired_navy_soldier_array[i][index] = navy_soldier_array[i][batch_index]; 
        
    }
    retired_navy_soldier_count++;

}
// to remove retired soldier from soldiers array
void to_remove_retired_soldier_from_array_nms(int batch_index)
{
    for(int col = batch_index ; col < navy_soldier_count - 1 ; col++)
    {
        for(int row = 0; row < 8 ; row++)
        {
            navy_soldier_array[row][col] = navy_soldier_array[row][col + 1]; 
        }
    }
    navy_soldier_count--;
    cout<<"\33[32m"<<navy_soldier_count;
    getch();
} 
// to add whole array dats in retired soldier txt
void to_add_whole_data_in_retired_soldier_txt_nms()
{
    int i = 0;
	string file_path = "retired/nms_retired_soldiers.txt";
    fstream file;
	file.open(file_path,ios::out);
    
    for(int columns = 0 ; columns < retired_navy_soldier_count ; columns++)
	{   
        if(columns > 0)
        {
	    file << endl;
        }
        for(int rows = 0 ; rows < 8 ; rows++)
		{
        file << retired_navy_soldier_array[rows][columns];
		file << ",";
        }
        i++;
	}
    retired_navy_soldier_count = i;
    file.close();	
}

// to show menu of matryed soldiers
int to_show_matryed_menu_nms(int no_of_index)
{
    int rows = 15;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << matryed_option[i];
        rows = rows + 4;
    }
    return 1;
}
//                      user 1 sub NAVY officer
int to_show_sub_menu_navy_officer_nms(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << sub_menu_navy_officers_nms[i];
        rows = rows + 4;
    }
    return 1;
}
int id_take_to_fetch_and_id_check_officer_nms()
{
	string batch_id;
	int index = navy_officer_count;
	again_take_batch_id:
	gotoxy(columns_of_screen / 2 - 10, 9);
	cout << "                           ";
	gotoxy(columns_of_screen / 2 - 10, 9);
	cout << "BATCH ID: ";
	gotoxy(columns_of_screen / 2, 9);
	cin >> batch_id;
	for(int i = 0 ; i < index ; i++)
	{
		if(batch_id == navy_officer_array[0][i])
		{
		return i;		
		}
	}
	invalid_function();
	goto again_take_batch_id;
}
int to_show_personal_details_from_navy_officer_array(int batch_id_index)
{
	title("PERSONAL DETAILS OF OFFICERS");
	int arr_index = 0;
    to_show_personal_details_options_officer_nms();
	for(int i = 0 ; i < 16 ; i = i + 2)
	{
	gotoxy(columns_of_screen/3 + 30,15 + i);
	cout<<navy_officer_array[arr_index][batch_id_index];
	arr_index++;
	}
	gotoxy(columns_of_screen/3 + 10,rows_of_screen - 5);
	cout<<"PRESS ANY KEY TO GO BACK";
	getch();
	return 1;

}
// personal details options of officers
void to_show_personal_details_options_officer_nms()
{
    int details_index = 0;
    for (int i = 0; i < 16; i = i + 2)
    {
        gotoxy(columns_of_screen / 3, 15 + i);
        cout << personal_details_options_nms_officers[details_index];
        details_index++;
    }
}
// to add data in soldier array nms
void to_add_data_in_officer_array_nms() 
{
    string word;
	to_show_personal_details_options_officer_nms();
    string must = "NAV-";
	int index = navy_officer_count;
	string batch_id;
	int arr_index = 1;
	function_start:
	gotoxy(columns_of_screen/3 + 30,15);
	cout<<"                          ";
	gotoxy(columns_of_screen/3 + 30,15);
	cin>>batch_id;
	for(int i = 0 ; i < index ; i++)
	{ 
		if(batch_id == navy_officer_array[0][i])
		{
			invalid_function();
			goto function_start;
		}
		if((batch_id[0] != must[0] || batch_id[1] != must[1] || batch_id[2] != must[2] || batch_id[3] != must[3]))
		{
			invalid_function();
			goto function_start;
		}
	}
    if(validation_in_adding_officers_persons(0,batch_id))
    {
        goto function_start;
    }
	navy_officer_array[0][index] = batch_id;
	for(int i = 2 ; i < 16 ; i = i + 2)
	{
	if(arr_index == 1)
	{
		cin.ignore();
	}
	backer:
	gotoxy(columns_of_screen/3 + 30,15 + i);
    getline(cin,word);
    if(validation_in_adding_officers_persons(arr_index,word))
    {
        gotoxy(columns_of_screen/3 + 30,15 + i);
        cout<<"                             ";
        goto backer;
    }
	navy_officer_array[arr_index][index] = word;
	arr_index++;
	}
	index++;
    navy_officer_count = index;
}
// to add data in officer txt
void to_add_data_in_officer_txt_nms()
{
	int index = navy_officer_count;
	string file_path = "ams_folder/nms_navy_officer.txt";
    fstream file;
	file.open(file_path,ios::app);
	file << endl;
	for(int i = 0 ; i < 8 ; i++)
	{
		file << navy_officer_array[i][index - 1];
		file << ",";
	}	
    file.close();
}
// to edit data in officer array
void to_edit_data_in_officer_array_nms(int batch_id_index) 
{
    string word;
    int arr_index = 0;
	to_show_personal_details_options_officer_nms();
	for(int i = 0 ; i < 16 ; i = i + 2)
	{
	if(arr_index == 0)
	{
		cin.ignore();
	}
	backer:
	gotoxy(columns_of_screen/3 + 30,15 + i);
	getline(cin,word);
    if(validation_in_adding_officers_persons(arr_index,word))
    {
        gotoxy(columns_of_screen/3 + 30,15 + i);
        cout<<"                             ";
        goto backer;
    }
    navy_officer_array[arr_index][batch_id_index] = word ;
	
    arr_index++;
	}
	
}
// to add whole array dats in officer txt
void to_add_whole_data_in_officer_txt_nms()
{
	string file_path = "ams_folder/nms_navy_officer.txt";
    fstream file;
	file.open(file_path,ios::out);
    
    for(int columns = 0 ; columns < navy_officer_count ; columns++)
	{   if(columns != 0)
        {
	    file << endl;
        }
        for(int rows = 0 ; rows < 8 ; rows++)
		{
        file << navy_officer_array[rows][columns];
		file << ",";
        }
	}
    file.close();	
}
// view retired officers
void to_view_retired_officer_data_nms()
{   title("RETIRED OFFICERS SYSTEM");
    for(int i = 0 ; i < retired_navy_officer_count ; i++)
    {
        gotoxy(15,14 + i);
        cout<<"BATCH ID: "<<retired_navy_officer_array[0][i]<<" | "<<"NAME: "<<retired_navy_soldier_array[1][i]<<" | "<<"SALARY: "<<retired_navy_soldier_array[4][i]<<" | "<<"AGE: "<<retired_navy_soldier_array[5][i]<<" | "<<endl;
    }
    gotoxy(columns_of_screen/3,10);
    cout<<"PRESS ANY KEY TO GO BACK";
    getch();
}
// 
void to_add_removed_officer_in_retired_nms(int batch_index)
{
    int index = retired_navy_officer_count;
    for(int i = 0 ; i < 8; i++)
    {
        retired_navy_officer_array[i][index] = navy_officer_array[i][batch_index]; 
        
    }
    retired_navy_officer_count++;

}
// to remove retired soldier from soldiers array
void to_remove_retired_officer_from_array_nms(int batch_index)
{
    for(int col = batch_index ; col < navy_officer_count - 1 ; col++)
    {
        for(int row = 0; row < 8 ; row++)
        {
            navy_officer_array[row][col] = navy_officer_array[row][col + 1]; 
        }
    }
    navy_officer_count--;
    cout<<"\33[32m"<<navy_officer_count;
    getch();
} 
// to add whole array dats in retired soldier txt
void to_add_whole_data_in_retired_officer_txt_nms()
{
    int i = 0;
	string file_path = "retired/nms_retired_officers.txt";
    fstream file;
	file.open(file_path,ios::out);
    
    for(int columns = 0 ; columns < retired_navy_officer_count ; columns++)
	{   
        if(columns > 0)
        {
	    file << endl;
        }
        for(int rows = 0 ; rows < 8 ; rows++)
		{
        file << retired_navy_officer_array[rows][columns];
		file << ",";
        }
        i++;
	}
    retired_navy_officer_count = i;
    file.close();	
}
// to see data of provience
int to_see_data_from_nms_officer_arrray(int row,string provience)
{   int count = 0;
    for(int i = 0 ; i < navy_officer_count ; i++)
    {
        if(navy_officer_array[row][i] == provience)
        {
            gotoxy(columns_of_screen/3 ,15 + count);
            cout<<navy_officer_array[0][i];
            count++;
        }
    }
    return count;
}
// Soldier under officer
void soldier_under_officers_nms()
{   int j = 0;
    for(int i = 0 ; i < navy_officer_count ; i++)
    {   
        soldiers_under_the_officer_nms[0][i] = navy_soldier_array[0][j];
        soldiers_under_the_officer_nms[1][i] = navy_soldier_array[0][j + 1];
        j = j + 2;
    }
    
}
// SOLDIERS UNDER the officer view
void soldier_under_officer_view_nms(int batch_id)
{
    gotoxy(columns_of_screen/3 + 14, 15);
    cout<<"BATCH ID: "<<soldiers_under_the_officer_nms[0][batch_id];
    gotoxy(columns_of_screen/3 + 14 , 17);
    cout<<"BATCH ID: "<<soldiers_under_the_officer_nms[1][batch_id];
}
//              SUB OPTION 3
int to_show_sub_menu_navy_instruments_nms(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << sub_menu_instruments_nms[i];
        rows = rows + 4;
    }
    return 1;
}
//
int to_show_sub_detail_view_navy_instruments_nms(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << sub_of_sub_menu_instruments_nms[i];
        rows = rows + 4;
    }
    return 1;
}

// to show air_craft details
void to_show_air_craft_details()
{
    title("INSTRUMENTS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < count_nms_air_craft ; i++)
    {
        gotoxy(columns_of_screen/2 - 20 , 16 + i);
        for(int j = 0 ; j < 5 ; j++)
        {
            cout<<readable_instruments_nms[j];
            cout<<nms_air_craft[i][j]<<"   ";
        }
    }
}
// to show weapons details
void to_show_weapons_details_navy()
{
    title("INSTRUMENTS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < count_nms_weapons  ; i++)
    {
        gotoxy(columns_of_screen/2 - 20 , 16 + i);
        for(int j = 0 ; j < 5 ; j++)
        {   cout<<readable_instruments_nms[j];
            cout<<nms_weapons[i][j]<<"  ";
        }
    }

}
// to show missiles details
void to_show_missilies_details_navy()
{
    title("INSTRUMENTS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < count_nms_missilies ; i++)
    {
        gotoxy(columns_of_screen/2 - 20 , 16 + i);
        for(int j = 0 ; j < 5 ; j++)
        {   
            cout<<readable_instruments_nms[j];
            cout<<nms_missilies[i][j]<<"   ";
        }
    }

}
// to show subarine details
void to_show_subarine_details()
{
    title("INSTRUMENTS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < count_nms_subarine  ; i++)
    {
        gotoxy(columns_of_screen/2 - 20 , 16 + i);
        for(int j = 0 ; j < 5 ; j++)
        {   
            cout<<readable_instruments_nms[j];
            cout<<nms_subarine[i][j]<<"   ";
        }
    }

}
// to show surface_ships details
void to_show_surface_ships_details()
{
    title("INSTRUMENTS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < count_nms_surface_ships  ; i++)
    {
        gotoxy(columns_of_screen/2 - 20 , 16 + i);
        for(int j = 0 ; j < 5 ; j++)
        {   
            cout<<readable_instruments_nms[j];
            cout<<nms_surface_ships[i][j]<<"   ";
        }
    }

}
// to_add data in instruments
void to_add_data_in_array_air_craft()
{   
    title("EDIT DETAILS OF INSTRUMENTS");
    string word;
    int index = count_nms_air_craft;
    for(int i = 0 ; i < 5 ; i++)
    {   back:
        gotoxy(columns_of_screen/3 , 15 + i);
        cout<<readable_instruments_nms[i];
        gotoxy(columns_of_screen/3 + 18 , 15 + i);
        cin>>word;
        if(validation_check_instruments(i,word))
        {
            
            gotoxy(columns_of_screen/3 + 18 , 15 + i);
            cout<<"                               ";
            goto back;
        }
        nms_air_craft[index][i] = word; 
    }
    count_nms_air_craft++;
}
// to_add data in instruments
void to_add_data_in_array_weapons_navy()
{   
    title("EDIT DETAILS OF INSTRUMENTS");
    string word;
    int index = count_nms_weapons;
    for(int i = 0 ; i < 5 ; i++)
    {   back:
        gotoxy(columns_of_screen/3 , 15 + i);
        cout<<readable_instruments_nms[i];
        gotoxy(columns_of_screen/3 + 18 , 15 + i);
        cin>>word;
        if(validation_check_instruments(i,word))
        {
            
            gotoxy(columns_of_screen/3 + 18 , 15 + i);
            cout<<"                               ";
            goto back;
        }
        nms_weapons[index][i] = word; 
    }
    count_nms_weapons++;
}
// to_add data in instruments
void to_add_data_in_array_missilies_navy()
{   
    title("EDIT DETAILS OF INSTRUMENTS");
    string word;
    int index = count_nms_missilies;
    for(int i = 0 ; i < 5 ; i++)
    {   
        back:
        gotoxy(columns_of_screen/3 , 15 + i);
        cout<<readable_instruments_nms[i];
        gotoxy(columns_of_screen/3 + 18 , 15 + i);
        cin>>word;
        if(validation_check_instruments(i,word))
        {
            gotoxy(columns_of_screen/3 + 18 , 15 + i);
            cout<<"                               ";
            goto back;
        }
        nms_missilies[index][i] = word; 
    }
    count_nms_missilies++;
}
void to_add_data_in_array_subarine()
{   
    title("EDIT DETAILS OF INSTRUMENTS");
    string word;
    int index = count_nms_subarine;
    for(int i = 0 ; i < 5 ; i++)
    {   
        back:
        gotoxy(columns_of_screen/3 , 15 + i);
        cout<<readable_instruments_nms[i];
        
        gotoxy(columns_of_screen/3 + 18 , 15 + i);
        cin>>word;
        if(validation_check_instruments(i,word))
        {
            gotoxy(columns_of_screen/3 + 18 , 15 + i);
            cout<<"                               ";
            goto back;
        }
        nms_subarine[index][i] = word; 
    }
    count_nms_subarine++;
}
void to_add_data_in_array_surface_ship()
{   
    title("EDIT DETAILS OF INSTRUMENTS");
    string word;
    int index = count_nms_surface_ships;
    for(int i = 0 ; i < 5 ; i++)
    {   
        back:
        gotoxy(columns_of_screen/3 , 15 + i);
        cout<<readable_instruments_nms[i];
        gotoxy(columns_of_screen/3 + 18 , 15 + i);
        cin>>word;
        if(validation_check_instruments(i,word))
        {
            gotoxy(columns_of_screen/3 + 18 , 15 + i);
            cout<<"                               ";
            goto back;
        }
        nms_surface_ships[index][i] = word; 
    }
    count_nms_surface_ships++;
}
// to add data of Weapons
void to_add_data_of_air_craft_in_txt()
{
    string file_path = "instruments/nms_air_craft.txt";
    string line;
    fstream file;
    file.open(file_path,ios::app);
    file << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        file << nms_air_craft[count_nms_air_craft - 1][i];
        file << ","; 
    }
    file.close();
} 
void to_add_data_of_weapons_in_txt_navy()
{
    string file_path = "instruments/nms_weapons.txt";
    string line;
    fstream file;
    file.open(file_path,ios::app);
    file << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        file << nms_weapons[count_nms_weapons - 1][i];
        file << ","; 
    }
    file.close();
} 

void to_add_data_of_subarine_in_txt()
{
    string file_path = "instruments/nms_subarine.txt";
    string line;
    fstream file;
    file.open(file_path,ios::app);
    file << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        file << nms_subarine[count_nms_subarine - 1][i];
        file << ","; 
    }
    file.close();
} 

void to_add_data_of_missilies_in_txt_navy()
{
    string file_path = "instruments/nms_missilies.txt";
    string line;
    fstream file;
    file.open(file_path,ios::app);
    file << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        file << nms_missilies[count_nms_missilies - 1][i];
        file << ","; 
    }
    file.close();
} 
void to_add_data_of_surface_ship_in_txt()
{
    string file_path = "instruments/nms_surface_ships.txt";
    string line;
    fstream file;
    file.open(file_path,ios::app);
    file << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        file << nms_surface_ships[count_nms_surface_ships - 1][i];
        file << ","; 
    }
    file.close();
} 
// TO EDIT THE INSTRUMENTS RECORD
void to_edit_instrument_record_air_craft()
{
    string option;
    string word;
    title("EDIT THE INSTRUMENTS RECORD");
    gotoxy(columns_of_screen/4,15);
    for(int i = 0 ; i < count_nms_air_craft ; i++)
    {
        cout<<i<<". "<<nms_air_craft[i][0]<<"   ";
    }
    back:
    gotoxy(columns_of_screen/4,17);
    cin>>option;
    if(numeric_validation(option))
    {
        gotoxy(columns_of_screen/4,17);
        cout<<"                      ";
        goto back;
    }
    if(stoi(option) < count_nms_air_craft && stoi(option) >= 0)
    {   int row = stoi(option);
        for(int i = 0 ; i < 5 ; i++)
        {
            gotoxy(columns_of_screen/3,19 + i);
            cout<<readable_instruments_nms[i];
            backer:
            gotoxy(columns_of_screen/3 + 20,19 + i);
            cin>>word;
            if(validation_check_instruments(i,word))
            {
                gotoxy(columns_of_screen/3 + 20,19 + i);
                cout<<"                   ";
                goto backer;    
            }    
            nms_air_craft[row][i] = word;        
        }
    }
    else 
    {
        goto back;
    }
}
void to_edit_instrument_record_weapons_navy()
{
    string option;
    string word;
    title("EDIT THE INSTRUMENTS RECORD");
    gotoxy(columns_of_screen/4,15);
    for(int i = 0 ; i < count_nms_weapons ; i++)
    {
        cout<<i<<". "<<nms_weapons[i][0]<<"   ";
    }
    back:
    gotoxy(columns_of_screen/4,17);
    cin>>option;
    if(numeric_validation(option))
    {
        gotoxy(columns_of_screen/4,17);
        cout<<"                      ";
        goto back;
    }
    if(stoi(option) < count_nms_weapons && stoi(option) >= 0)
    {   int row = stoi(option);
        for(int i = 0 ; i < 5 ; i++)
        {
            gotoxy(columns_of_screen/3,19 + i);
            cout<<readable_instruments_nms[i];
            backer:
            gotoxy(columns_of_screen/3 + 20,19 + i);
            cin>>word;
            if(validation_check_instruments(i,word))
            {
                gotoxy(columns_of_screen/3 + 20,19 + i);
                cout<<"                   ";
                goto backer;    
            }    
            nms_weapons[row][i] = word;        
        }
    }
    else 
    {
        goto back;
    }
}
void to_edit_instrument_record_subarine()
{
    string option;
    string word;
    title("EDIT THE INSTRUMENTS RECORD");
    gotoxy(columns_of_screen/4,15);
    for(int i = 0 ; i < count_nms_subarine ; i++)
    {
        cout<<i<<". "<<nms_subarine[i][0]<<"   ";
    }
    back:
    gotoxy(columns_of_screen/4,17);
    cin>>option;
    if(numeric_validation(option))
    {
        gotoxy(columns_of_screen/4,17);
        cout<<"                      ";
        goto back;
    }
    if(stoi(option) < count_nms_subarine && stoi(option) >= 0)
    {   int row = stoi(option);
        for(int i = 0 ; i < 5 ; i++)
        {
            gotoxy(columns_of_screen/3,19 + i);
            cout<<readable_instruments_nms[i];
            backer:
            gotoxy(columns_of_screen/3 + 20,19 + i);
            cin>>word;
            if(validation_check_instruments(i,word))
            {
                gotoxy(columns_of_screen/3 + 20,19 + i);
                cout<<"                   ";
                goto backer;    
            }    
            nms_subarine[row][i] = word;        
        }
    }
    else 
    {
        goto back;
    }
}
void to_edit_instrument_record_missilies_navy()
{
    string option;
    string word;
    title("EDIT THE INSTRUMENTS RECORD");
    gotoxy(columns_of_screen/4,15);
    for(int i = 0 ; i < count_nms_missilies ; i++)
    {
        cout<<i<<". "<<nms_missilies[i][0]<<"   ";
    }
    back:
    gotoxy(columns_of_screen/4,17);
    cin>>option;
    if(numeric_validation(option))
    {
        gotoxy(columns_of_screen/4,17);
        cout<<"                      ";
        goto back;
    }
    if(stoi(option) < count_nms_missilies && stoi(option) >= 0)
    {   int row = stoi(option);
        for(int i = 0 ; i < 5 ; i++)
        {
            gotoxy(columns_of_screen/3,19 + i);
            cout<<readable_instruments_nms[i];
            backer:
            gotoxy(columns_of_screen/3 + 20,19 + i);
            cin>>word;
            if(validation_check_instruments(i,word))
            {
                gotoxy(columns_of_screen/3 + 20,19 + i);
                cout<<"                   ";
                goto backer;    
            }    
            nms_missilies[row][i] = word;        
        }
    }
    else 
    {
        goto back;
    }
}
void to_edit_instrument_record_surface_ships()
{
    string option;
    string word;
    title("EDIT THE INSTRUMENTS RECORD");
    gotoxy(columns_of_screen/4,15);
    for(int i = 0 ; i < count_nms_surface_ships ; i++)
    {
        cout<<i<<". "<<nms_surface_ships[i][0]<<"   ";
    }
    back:
    gotoxy(columns_of_screen/4,17);
    cin>>option;
    if(numeric_validation(option))
    {
        gotoxy(columns_of_screen/4,17);
        cout<<"                      ";
        goto back;
    }
    if(stoi(option) < count_nms_surface_ships && stoi(option) >= 0)
    {   int row = stoi(option);
        for(int i = 0 ; i < 5 ; i++)
        {
            gotoxy(columns_of_screen/3,19 + i);
            cout<<readable_instruments_nms[i];
            backer:
            gotoxy(columns_of_screen/3 + 20,19 + i);
            cin>>word;
            if(validation_check_instruments(i,word))
            {
                gotoxy(columns_of_screen/3 + 20,19 + i);
                cout<<"                   ";
                goto backer;    
            }    
            nms_surface_ships[row][i] = word;        
        }
    }
    else 
    {
        goto back;
    }
}
// ADD WHOLE DATA IN TXT instruments
void to_add_whole_data_in_txt_air_craft()
{
    string file_path = "instruments/nms_air_craft.txt";
    string line;
    fstream file;
    file.open(file_path,ios::out);

    for(int i = 0 ; i < count_nms_air_craft ; i++)
    {   if(i != 0)
        {
            file << endl;
        }
        for(int j = 0 ; j < 5 ; j++)
        {
        file << nms_air_craft[i][j];
        file << ","; 
        }
    }
    file.close();
}
// subarine
void to_add_whole_data_in_txt_subarine()
{
    string file_path = "instruments/nms_subarine.txt";
    string line;
    fstream file;
    file.open(file_path,ios::out);

    for(int i = 0 ; i < count_nms_subarine ; i++)
    {   if(i != 0)
        {
            file << endl;
        }
        for(int j = 0 ; j < 5 ; j++)
        {
        file << nms_subarine[i][j];
        file << ","; 
        }
    }
    file.close();
}
// mweapons
void to_add_whole_data_in_txt_weapons_navy()
{
    string file_path = "instruments/nms_weapons.txt";
    string line;
    fstream file;
    file.open(file_path,ios::out);

    for(int i = 0 ; i < count_nms_weapons ; i++)
    {   if(i != 0)
        {
            file << endl;
        }
        for(int j = 0 ; j < 5 ; j++)
        {
        file << nms_weapons[i][j];
        file << ","; 
        }
    }
    file.close();
}
// missilies
void to_add_whole_data_in_txt_missilies_navy()
{
    string file_path = "instruments/nms_missilies.txt";
    string line;
    fstream file;
    file.open(file_path,ios::out);

    for(int i = 0 ; i < count_nms_missilies ; i++)
    {   if(i != 0)
        {
            file << endl;
        }
        for(int j = 0 ; j < 5 ; j++)
        {
        file << nms_missilies[i][j];
        file << ","; 
        }
    }
    file.close();
}

void to_add_whole_data_in_txt_surface_ships()
{
    string file_path = "instruments/nms_surface_ships.txt";
    string line;
    fstream file;
    file.open(file_path,ios::out);

    for(int i = 0 ; i < count_nms_surface_ships ; i++)
    {   if(i != 0)
        {
            file << endl;
        }
        for(int j = 0 ; j < 5 ; j++)
        {
        file << nms_surface_ships[i][j];
        file << ","; 
        }
    }
    file.close();
}
// sub menu 4
void graph_nms()
{   int item_quantity[5] = {0,0,0,0,0};
    for(int i = 0 ; i < count_nms_air_craft ; i++)
    {
        item_quantity[0] = item_quantity[0] + stoi(nms_air_craft[i][2]);
    }
    for(int i = 0 ; i < count_nms_weapons ; i++)
    {
        item_quantity[1] = item_quantity[1] + stoi(nms_weapons[i][2]);
    }
    for(int i = 0 ; i < count_nms_missilies ; i++)
    {
        item_quantity[2] = item_quantity[2] + stoi(nms_missilies[i][2]);
    }
    for(int i = 0 ; i < count_nms_subarine ; i++)
    {
        item_quantity[3] = item_quantity[3] + stoi(nms_subarine[i][2]);
    }
    for(int i = 0 ; i < count_nms_surface_ships ; i++)
    {
        item_quantity[4] = item_quantity[4] + stoi(nms_surface_ships[i][2]);
    }
	int j = 0;
	for (int i = columns_of_screen / 8; i < columns_of_screen - 1; i++)
	{
		gotoxy(i, rows_of_screen - 4);
		cout << "*";
	}
	for (int i = rows_of_screen - 4; i > 8; i--)
	{
		gotoxy(columns_of_screen / 8, i);
		cout << "*";
	}
	for (int i = 0; i < 20; i = i + 4)
	{

		gotoxy(2, rows_of_screen / 3 + i);
		cout << sub_of_sub_menu_instruments_nms[j];
		j++;
	}
	int x = 0;
	int screen = columns_of_screen / 8 + 1;
	for (int i = 0; i < 20; i = i + 4)
	{
		for (j = 0; j < item_quantity[x] / 50000; j++)
		{
			gotoxy(screen + j, rows_of_screen / 3 + i);
			cout << "#";
		}
		gotoxy(screen + j, rows_of_screen / 3 + i);
		cout << " ";
		x++;
	}
}
// budget nms
void total_nms_budget()
{
    int item_quantity[5] = {0,0,0,0,0};
    for(int i = 0 ; i < count_nms_air_craft ; i++)
    {
        item_quantity[0] = item_quantity[0] + stoi(nms_air_craft[i][2]);
    }
    for(int i = 0 ; i < count_nms_weapons ; i++)
    {
        item_quantity[1] = item_quantity[1] + stoi(nms_weapons[i][2]);
    }
    for(int i = 0 ; i < count_nms_missilies ; i++)
    {
        item_quantity[2] = item_quantity[2] + stoi(nms_missilies[i][2]);
    }
    for(int i = 0 ; i < count_nms_subarine ; i++)
    {
        item_quantity[3] = item_quantity[3] + stoi(nms_subarine[i][2]);
    }
    for(int i = 0 ; i < count_nms_surface_ships ; i++)
    {
        item_quantity[4] = item_quantity[4] + stoi(nms_surface_ships[i][2]);
    }
    int x = 0;
    for(int i = 0 ; i < 5 ; i++)
    {
        gotoxy(columns_of_screen/3 , 16 + x);
        cout<<sub_of_sub_menu_instruments_nms[i];
        gotoxy(columns_of_screen/3 + 20, 16 + x);
        cout<<item_quantity[i];
        x = x + 2;
    }
}
// SUB 4 MENU CROPS
int to_show_sub_menu_navy_crops_nms(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << nms_crops[i];
        rows = rows + 4;
    }
    return 1;
}
void to_show_naval_khor()
{   
    title("CROPS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < navy_soldier_count ; i++)
    {
        if(navy_soldier_array[3][i] == "PUNJAB" || navy_soldier_array[3][i] == "SINDH")
        {
            gotoxy(columns_of_screen/3,14 + i);
            cout<<"BATCH ID: "<<navy_soldier_array[0][i]<<endl;
        }

    }
    for(int i = 0 ; i < navy_officer_count ; i++)
    {
        if(navy_officer_array[3][i] == "PUNJAB" || navy_officer_array[3][i] == "SINDH")
        {
            gotoxy(columns_of_screen/3,14 + i);
            cout<<"BATCH ID: "<<navy_officer_array[0][i]<<endl;
            gotoxy(columns_of_screen/3,14 + i + 1);
            cout<<"____________________________________";
        }

    }
}
void to_show_naizi_khor()
{   
    
    title("CROPS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < navy_soldier_count ; i++)
    {
        if(navy_soldier_array[3][i] == "KPK" || navy_soldier_array[3][i] == "BALOCHISTAN" || navy_soldier_array[3][i] == "KASHMIR")
        {
            gotoxy(columns_of_screen/3,14 + i);
            cout<<"BATCH ID: "<<navy_soldier_array[0][i]<<endl;
            
        }

    }
    for(int i = 0 ; i < navy_officer_count ; i++)
    {   
        if(navy_officer_array[3][i] == "KPK" || navy_officer_array[3][i] == "BALOCHISTAN" || navy_officer_array[3][i] == "KASHMIR")
        { 
            gotoxy(columns_of_screen/3 + 20,14 + i);
            cout<<"BATCH ID: "<<navy_officer_array[0][i]<<endl;
            gotoxy(columns_of_screen/3 + 20,14 + i + 1);
            cout<<"____________________________________";

        }

    }
}
//                                  USER 3
//                                   afms

//                          USER 3 afms TEAM FUNCTIONS
//                          USER 3 SUB SELECT SOLDIER

int to_show_main_menu_afms(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << main_menu_names_afms[i];
        rows = rows + 4;
    }
    return 1;
}
int to_show_sub_menu_air_force_soldier_afms(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << sub_menu_air_force_soldiers_afms[i];
        rows = rows + 4;
    }
    return 1;
}
// id INDEX IT GIVE US BACK
int id_take_to_fetch_and_id_check_soldiers_afms()
{
	string batch_id;
	int index = air_force_soldier_count;
	again_take_batch_id:
	gotoxy(columns_of_screen / 2 - 10, 9);
	cout << "                           ";
	gotoxy(columns_of_screen / 2 - 10, 9);
	cout << "BATCH ID: ";
	gotoxy(columns_of_screen / 2, 9);
	cin >> batch_id;
	for(int i = 0 ; i < index ; i++)
	{
		if(batch_id == air_force_soldier_array[0][i])
		{
		return i;		
		}
	}
	invalid_function();
	goto again_take_batch_id;
}
int to_show_personal_details_from_air_force_soldiers_array(int batch_id_index)
{
	title("PERSONAL DETAILS OF AIR FORCE SOLDIERS");
	int arr_index = 0;
    to_show_personal_details_options_soldiers_afms();
	for(int i = 0 ; i < 16 ; i = i + 2)
	{
	gotoxy(columns_of_screen/3 + 30,15 + i);
	cout<<air_force_soldier_array[arr_index][batch_id_index];
	arr_index++;
	}
	gotoxy(columns_of_screen/3 + 10,rows_of_screen - 5);
	cout<<"PRESS ANY KEY TO GO BACK";
	getch();
	return 1;

}
// to show personal details options by soldiers afms
void to_show_personal_details_options_soldiers_afms()
{
    int details_index = 0;
    for (int i = 0; i < 16; i = i + 2)
    {
        gotoxy(columns_of_screen / 3, 15 + i);
        cout << personal_details_options_afms_soldiers[details_index];
        details_index++;
    }
}
// to add data in soldier array afms
void to_add_data_in_soldiers_array_afms() 
{   string word;
    
	to_show_personal_details_options_soldiers_afms();
    string must = "122-";
	int index = air_force_soldier_count;
	string batch_id;
	int arr_index = 1;
	function_start:
	gotoxy(columns_of_screen/3 + 30,15);
	cout<<"                          ";
	gotoxy(columns_of_screen/3 + 30,15);
	cin>>batch_id;
	for(int i = 0 ; i < index ; i++)
	{
		if(batch_id == air_force_soldier_array[0][i])
		{
			invalid_function();
			goto function_start;
		}
		if((batch_id[0] != must[0] || batch_id[1] != must[1] || batch_id[2] != must[2] || batch_id[3] != must[3]))
		{
			invalid_function();
			goto function_start;
		}
	}
    if(validation_in_adding_soldiers_persons(0,batch_id))
    {
        goto function_start;
    }
	air_force_soldier_array[0][index] = batch_id;
	for(int i = 2 ; i < 16 ; i = i + 2)
	{
	if(arr_index == 1)
	{
		cin.ignore();
	}
	backer:
	gotoxy(columns_of_screen/3 + 30,15 + i);
	getline(cin,word);
    if(validation_in_adding_soldiers_persons(arr_index,word))
    {
        gotoxy(columns_of_screen/3 + 30,15 + i);
        cout<<"                             ";
        goto backer;
    }
    air_force_soldier_array[arr_index][index] = word;
	arr_index++;
	}
	index++;
    air_force_soldier_count = index;
}
// to add data in soldier txt
void to_add_data_in_soldier_txt_afms()
{
	int index = air_force_soldier_count;
	string file_path = "ams_folder/afms_air_force_soldiers.txt";
    fstream file;
	file.open(file_path,ios::app);
	file << endl;
	for(int i = 0 ; i < 8 ; i++)
	{
		file << air_force_soldier_array[i][index - 1];
		file << ",";
	}	
    file.close();
}
// to edit data in soldiers array
void to_edit_data_in_soldiers_array_afms(int batch_id_index) 
{
    int arr_index = 0;
    string word;
	to_show_personal_details_options_soldiers_afms();
	for(int i = 0 ; i < 16 ; i = i + 2)
	{
	if(arr_index == 0)
	{
		cin.ignore();
	}
	backer:
	gotoxy(columns_of_screen/3 + 30,15 + i);
	getline(cin,word);
    if(validation_in_adding_soldiers_persons(arr_index,word))
    {
        gotoxy(columns_of_screen/3 + 30,15 + i);
        cout<<"                             ";
        goto backer;
    }
    air_force_soldier_array[arr_index][batch_id_index] = word;
	arr_index++;
	}
	
}
// to add whole array dats in soldier txt
void to_add_whole_data_in_soldier_txt_afms()
{

	string file_path = "ams_folder/afms_air_force_soldiers.txt";
    fstream file;
	file.open(file_path,ios::out);
    
    for(int columns = 0 ; columns < air_force_soldier_count ; columns++)
	{   if(columns != 0)
        {
	    file << endl;
        }
        for(int rows = 0 ; rows < 8 ; rows++)
		{
        file << air_force_soldier_array[rows][columns];
		file << ",";
        }
	}
    file.close();	
}
// to show menu of retired soldiers
int to_show_retired_menu_afms(int no_of_index)
{
    int rows = 15;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << retired_options_afms[i];
        rows = rows + 4;
    }
    return 1;
}
// view retired soldiers
void to_view_retired_soldier_data_afms()
{   title("RETIRED SOLDIERS SYSTEM");
    for(int i = 0 ; i < retired_air_force_soldier_count ; i++)
    {
        gotoxy(15,14 + i);
        cout<<"BATCH ID: "<<retired_air_force_soldier_array[0][i]<<" | "<<"NAME: "<<retired_air_force_soldier_array[1][i]<<" | "<<"SALARY: "<<retired_air_force_soldier_array[4][i]<<" | "<<"AGE: "<<retired_air_force_soldier_array[5][i]<<" | "<<endl;
    }
    gotoxy(columns_of_screen/3,10);
    cout<<"PRESS ANY KEY TO GO BACK";
    getch();
}
// to add removed soldier in retired
void to_add_removed_soldier_in_retired_afms(int batch_index)
{
    int index = retired_air_force_soldier_count;
    for(int i = 0 ; i < 8; i++)
    {
        retired_air_force_soldier_array[i][index] = air_force_soldier_array[i][batch_index]; 
        
    }
    retired_air_force_soldier_count++;

}
// to remove retired soldier from soldiers array
void to_remove_retired_soldier_from_array_afms(int batch_index)
{
    for(int col = batch_index ; col < air_force_soldier_count - 1 ; col++)
    {
        for(int row = 0; row < 8 ; row++)
        {
            air_force_soldier_array[row][col] = air_force_soldier_array[row][col + 1]; 
        }
    }
    air_force_soldier_count--;
    cout<<"\33[32m"<<air_force_soldier_count;
    getch();
} 
// to add whole array dats in retired soldier txt
void to_add_whole_data_in_retired_soldier_txt_afms()
{
    int i = 0;
	string file_path = "retired/afms_retired_soldiers.txt";
    fstream file;
	file.open(file_path,ios::out);
    
    for(int columns = 0 ; columns < retired_air_force_soldier_count ; columns++)
	{   
        if(columns > 0)
        {
	    file << endl;
        }
        for(int rows = 0 ; rows < 8 ; rows++)
		{
        file << retired_air_force_soldier_array[rows][columns];
		file << ",";
        }
        i++;
	}
    retired_air_force_soldier_count = i;
    file.close();	
}

// to show menu of matryed soldiers
int to_show_matryed_menu_afms(int no_of_index)
{
    int rows = 15;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << matryed_option[i];
        rows = rows + 4;
    }
    return 1;
}
//                      user 1 sub AIR FORCE officer
int to_show_sub_menu_air_force_officer_afms(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << sub_menu_air_force_officers_afms[i];
        rows = rows + 4;
    }
    return 1;
}
int id_take_to_fetch_and_id_check_officer_afms()
{
	string batch_id;
	int index = air_force_officer_count;
	again_take_batch_id:
	gotoxy(columns_of_screen / 2 - 10, 9);
	cout << "                           ";
	gotoxy(columns_of_screen / 2 - 10, 9);
	cout << "BATCH ID: ";
	gotoxy(columns_of_screen / 2, 9);
	cin >> batch_id;
	for(int i = 0 ; i < index ; i++)
	{
		if(batch_id == air_force_officer_array[0][i])
		{
		return i;		
		}
	}
	invalid_function();
	goto again_take_batch_id;
}
int to_show_personal_details_from_air_force_officer_array(int batch_id_index)
{
	title("PERSONAL DETAILS OF OFFICERS");
	int arr_index = 0;
    to_show_personal_details_options_officer_afms();
	for(int i = 0 ; i < 16 ; i = i + 2)
	{
	gotoxy(columns_of_screen/3 + 30,15 + i);
	cout<<air_force_officer_array[arr_index][batch_id_index];
	arr_index++;
	}
	gotoxy(columns_of_screen/3 + 10,rows_of_screen - 5);
	cout<<"PRESS ANY KEY TO GO BACK";
	getch();
	return 1;

}
// personal details options of officers
void to_show_personal_details_options_officer_afms()
{
    int details_index = 0;
    for (int i = 0; i < 16; i = i + 2)
    {
        gotoxy(columns_of_screen / 3, 15 + i);
        cout << personal_details_options_afms_officers[details_index];
        details_index++;
    }
}
// to add data in soldier array afms
void to_add_data_in_officer_array_afms() 
{
    string word;
	to_show_personal_details_options_officer_afms();
    string must = "EAG-";
	int index = air_force_officer_count;
	string batch_id;
	int arr_index = 1;
	function_start:
	gotoxy(columns_of_screen/3 + 30,15);
	cout<<"                          ";
	gotoxy(columns_of_screen/3 + 30,15);
	cin>>batch_id;
	for(int i = 0 ; i < index ; i++)
	{ 
		if(batch_id == air_force_officer_array[0][i])
		{
			invalid_function();
			goto function_start;
		}
		if((batch_id[0] != must[0] || batch_id[1] != must[1] || batch_id[2] != must[2] || batch_id[3] != must[3]))
		{
			invalid_function();
			goto function_start;
		}
	}
    if(validation_in_adding_officers_persons(0,batch_id))
    {
        goto function_start;
    }
	air_force_officer_array[0][index] = batch_id;
	for(int i = 2 ; i < 16 ; i = i + 2)
	{
	if(arr_index == 1)
	{
		cin.ignore();
	}
	backer:
	gotoxy(columns_of_screen/3 + 30,15 + i);
    getline(cin,word);
    if(validation_in_adding_officers_persons(arr_index,word))
    {
        gotoxy(columns_of_screen/3 + 30,15 + i);
        cout<<"                             ";
        goto backer;
    }
	air_force_officer_array[arr_index][index] = word;
	arr_index++;
	}
	index++;
    air_force_officer_count = index;
}
// to add data in officer txt
void to_add_data_in_officer_txt_afms()
{
	int index = air_force_officer_count;
	string file_path = "ams_folder/afms_air_force_officer.txt";
    fstream file;
	file.open(file_path,ios::app);
	file << endl;
	for(int i = 0 ; i < 8 ; i++)
	{
		file << air_force_officer_array[i][index - 1];
		file << ",";
	}	
    file.close();
}
// to edit data in officer array
void to_edit_data_in_officer_array_afms(int batch_id_index) 
{
    string word;
    int arr_index = 0;
	to_show_personal_details_options_officer_afms();
	for(int i = 0 ; i < 16 ; i = i + 2)
	{
	if(arr_index == 0)
	{
		cin.ignore();
	}
	backer:
	gotoxy(columns_of_screen/3 + 30,15 + i);
	getline(cin,word);
    if(validation_in_adding_officers_persons(arr_index,word))
    {
        gotoxy(columns_of_screen/3 + 30,15 + i);
        cout<<"                             ";
        goto backer;
    }
    air_force_officer_array[arr_index][batch_id_index] = word ;
	
    arr_index++;
	}
	
}
// to add whole array dats in officer txt
void to_add_whole_data_in_officer_txt_afms()
{
	string file_path = "ams_folder/afms_air_force_officer.txt";
    fstream file;
	file.open(file_path,ios::out);
    
    for(int columns = 0 ; columns < air_force_officer_count ; columns++)
	{   if(columns != 0)
        {
	    file << endl;
        }
        for(int rows = 0 ; rows < 8 ; rows++)
		{
        file << air_force_officer_array[rows][columns];
		file << ",";
        }
	}
    file.close();	
}
// view retired officers
void to_view_retired_officer_data_afms()
{   title("RETIRED OFFICERS SYSTEM");
    for(int i = 0 ; i < retired_air_force_officer_count ; i++)
    {
        gotoxy(15,14 + i);
        cout<<"BATCH ID: "<<retired_air_force_officer_array[0][i]<<" | "<<"NAME: "<<retired_air_force_soldier_array[1][i]<<" | "<<"SALARY: "<<retired_air_force_soldier_array[4][i]<<" | "<<"AGE: "<<retired_air_force_soldier_array[5][i]<<" | "<<endl;
    }
    gotoxy(columns_of_screen/3,10);
    cout<<"PRESS ANY KEY TO GO BACK";
    getch();
}
// 
void to_add_removed_officer_in_retired_afms(int batch_index)
{
    int index = retired_air_force_officer_count;
    for(int i = 0 ; i < 8; i++)
    {
        retired_air_force_officer_array[i][index] = air_force_officer_array[i][batch_index]; 
        
    }
    retired_air_force_officer_count++;

}
// to remove retired soldier from soldiers array
void to_remove_retired_officer_from_array_afms(int batch_index)
{
    for(int col = batch_index ; col < air_force_officer_count - 1 ; col++)
    {
        for(int row = 0; row < 8 ; row++)
        {
            air_force_officer_array[row][col] = air_force_officer_array[row][col + 1]; 
        }
    }
    air_force_officer_count--;
    cout<<"\33[32m"<<air_force_officer_count;
    getch();
} 
// to add whole array dats in retired soldier txt
void to_add_whole_data_in_retired_officer_txt_afms()
{
    int i = 0;
	string file_path = "retired/afms_retired_officers.txt";
    fstream file;
	file.open(file_path,ios::out);
    
    for(int columns = 0 ; columns < retired_air_force_officer_count ; columns++)
	{   
        if(columns > 0)
        {
	    file << endl;
        }
        for(int rows = 0 ; rows < 8 ; rows++)
		{
        file << retired_air_force_officer_array[rows][columns];
		file << ",";
        }
        i++;
	}
    retired_air_force_officer_count = i;
    file.close();	
}
// to see data of provience
int to_see_data_from_afms_officer_arrray(int row,string provience)
{   int count = 0;
    for(int i = 0 ; i < air_force_officer_count ; i++)
    {
        if(air_force_officer_array[row][i] == provience)
        {
            gotoxy(columns_of_screen/3 ,15 + count);
            cout<<air_force_officer_array[0][i];
            count++;
        }
    }
    return count;
}
// Soldier under officer
void soldier_under_officers_afms()
{   int j = 0;
    for(int i = 0 ; i < air_force_officer_count ; i++)
    {   
        soldiers_under_the_officer_afms[0][i] = air_force_soldier_array[0][j];
        soldiers_under_the_officer_afms[1][i] = air_force_soldier_array[0][j + 1];
        j = j + 2;
    }
    
}
// SOLDIERS UNDER the officer view
void soldier_under_officer_view_afms(int batch_id)
{
    gotoxy(columns_of_screen/3 + 14, 15);
    cout<<"BATCH ID: "<<soldiers_under_the_officer_afms[0][batch_id];
    gotoxy(columns_of_screen/3 + 14 , 17);
    cout<<"BATCH ID: "<<soldiers_under_the_officer_afms[1][batch_id];
}
//              SUB OPTION 3
int to_show_sub_menu_air_force_instruments_afms(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << sub_menu_instruments_afms[i];
        rows = rows + 4;
    }
    return 1;
}
//
int to_show_sub_detail_view_air_force_instruments_afms(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << sub_of_sub_menu_instruments_afms[i];
        rows = rows + 4;
    }
    return 1;
}

// to show air_craft details
void to_show_air_craft_details_air_force()
{
    title("INSTRUMENTS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < count_afms_air_craft ; i++)
    {
        gotoxy(columns_of_screen/2 - 20 , 16 + i);
        for(int j = 0 ; j < 5 ; j++)
        {
            cout<<readable_instruments_afms[j];
            cout<<afms_air_craft[i][j]<<"   ";
        }
    }
}
// to show weapons details
void to_show_weapons_details_air_force()
{
    title("INSTRUMENTS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < count_afms_weapons  ; i++)
    {
        gotoxy(columns_of_screen/2 - 20 , 16 + i);
        for(int j = 0 ; j < 5 ; j++)
        {   cout<<readable_instruments_afms[j];
            cout<<afms_weapons[i][j]<<"  ";
        }
    }

}
// to show missiles details
void to_show_missilies_details_air_force()
{
    title("INSTRUMENTS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < count_afms_missilies ; i++)
    {
        gotoxy(columns_of_screen/2 - 20 , 16 + i);
        for(int j = 0 ; j < 5 ; j++)
        {   
            cout<<readable_instruments_afms[j];
            cout<<afms_missilies[i][j]<<"   ";
        }
    }

}
// to show planes details
void to_show_planes_details()
{
    title("INSTRUMENTS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < count_afms_planes  ; i++)
    {
        gotoxy(columns_of_screen/2 - 20 , 16 + i);
        for(int j = 0 ; j < 5 ; j++)
        {   
            cout<<readable_instruments_afms[j];
            cout<<afms_planes[i][j]<<"   ";
        }
    }

}
// to show trackers details
void to_show_trackers_details()
{
    title("INSTRUMENTS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < count_afms_trackers  ; i++)
    {
        gotoxy(columns_of_screen/2 - 20 , 16 + i);
        for(int j = 0 ; j < 5 ; j++)
        {   
            cout<<readable_instruments_afms[j];
            cout<<afms_trackers[i][j]<<"   ";
        }
    }

}
// to_add data in instruments
void to_add_data_in_array_air_craft_air_force()
{   
    title("EDIT DETAILS OF INSTRUMENTS");
    string word;
    int index = count_afms_air_craft;
    for(int i = 0 ; i < 5 ; i++)
    {   back:
        gotoxy(columns_of_screen/3 , 15 + i);
        cout<<readable_instruments_afms[i];
        gotoxy(columns_of_screen/3 + 18 , 15 + i);
        cin>>word;
        if(validation_check_instruments(i,word))
        {
            
            gotoxy(columns_of_screen/3 + 18 , 15 + i);
            cout<<"                               ";
            goto back;
        }
        afms_air_craft[index][i] = word; 
    }
    count_afms_air_craft++;
}
// to_add data in instruments
void to_add_data_in_array_weapons_air_force()
{   
    title("EDIT DETAILS OF INSTRUMENTS");
    string word;
    int index = count_afms_weapons;
    for(int i = 0 ; i < 5 ; i++)
    {   back:
        gotoxy(columns_of_screen/3 , 15 + i);
        cout<<readable_instruments_afms[i];
        gotoxy(columns_of_screen/3 + 18 , 15 + i);
        cin>>word;
        if(validation_check_instruments(i,word))
        {
            
            gotoxy(columns_of_screen/3 + 18 , 15 + i);
            cout<<"                               ";
            goto back;
        }
        afms_weapons[index][i] = word; 
    }
    count_afms_weapons++;
}
// to_add data in instruments
void to_add_data_in_array_missilies_air_force()
{   
    title("EDIT DETAILS OF INSTRUMENTS");
    string word;
    int index = count_afms_missilies;
    for(int i = 0 ; i < 5 ; i++)
    {   
        back:
        gotoxy(columns_of_screen/3 , 15 + i);
        cout<<readable_instruments_afms[i];
        gotoxy(columns_of_screen/3 + 18 , 15 + i);
        cin>>word;
        if(validation_check_instruments(i,word))
        {
            gotoxy(columns_of_screen/3 + 18 , 15 + i);
            cout<<"                               ";
            goto back;
        }
        afms_missilies[index][i] = word; 
    }
    count_afms_missilies++;
}
void to_add_data_in_array_planes()
{   
    title("EDIT DETAILS OF INSTRUMENTS");
    string word;
    int index = count_afms_planes;
    for(int i = 0 ; i < 5 ; i++)
    {   
        back:
        gotoxy(columns_of_screen/3 , 15 + i);
        cout<<readable_instruments_afms[i];
        
        gotoxy(columns_of_screen/3 + 18 , 15 + i);
        cin>>word;
        if(validation_check_instruments(i,word))
        {
            gotoxy(columns_of_screen/3 + 18 , 15 + i);
            cout<<"                               ";
            goto back;
        }
        afms_planes[index][i] = word; 
    }
    count_afms_planes++;
}
void to_add_data_in_array_trackers()
{   
    title("EDIT DETAILS OF INSTRUMENTS");
    string word;
    int index = count_afms_trackers;
    for(int i = 0 ; i < 5 ; i++)
    {   
        back:
        gotoxy(columns_of_screen/3 , 15 + i);
        cout<<readable_instruments_afms[i];
        gotoxy(columns_of_screen/3 + 18 , 15 + i);
        cin>>word;
        if(validation_check_instruments(i,word))
        {
            gotoxy(columns_of_screen/3 + 18 , 15 + i);
            cout<<"                               ";
            goto back;
        }
        afms_trackers[index][i] = word; 
    }
    count_afms_trackers++;
}
// to add data of Weapons
void to_add_data_of_air_craft_in_txt_air_force()
{
    string file_path = "instruments/afms_air_craft.txt";
    string line;
    fstream file;
    file.open(file_path,ios::app);
    file << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        file << afms_air_craft[count_afms_air_craft - 1][i];
        file << ","; 
    }
    file.close();
} 
void to_add_data_of_weapons_in_txt_air_force()
{
    string file_path = "instruments/afms_weapons.txt";
    string line;
    fstream file;
    file.open(file_path,ios::app);
    file << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        file << afms_weapons[count_afms_weapons - 1][i];
        file << ","; 
    }
    file.close();
} 

void to_add_data_of_planes_in_txt()
{
    string file_path = "instruments/afms_planes.txt";
    string line;
    fstream file;
    file.open(file_path,ios::app);
    file << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        file << afms_planes[count_afms_planes - 1][i];
        file << ","; 
    }
    file.close();
} 

void to_add_data_of_missilies_in_txt_air_force()
{
    string file_path = "instruments/afms_missilies.txt";
    string line;
    fstream file;
    file.open(file_path,ios::app);
    file << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        file << afms_missilies[count_afms_missilies - 1][i];
        file << ","; 
    }
    file.close();
} 
void to_add_data_of_trackers_in_txt()
{
    string file_path = "instruments/afms_trackers.txt";
    string line;
    fstream file;
    file.open(file_path,ios::app);
    file << endl;
    for(int i = 0 ; i < 5 ; i++)
    {
        file << afms_trackers[count_afms_trackers - 1][i];
        file << ","; 
    }
    file.close();
} 
// TO EDIT THE INSTRUMENTS RECORD
void to_edit_instrument_record_air_craft_air_force()
{
    string option;
    string word;
    title("EDIT THE INSTRUMENTS RECORD");
    gotoxy(columns_of_screen/4,15);
    for(int i = 0 ; i < count_afms_air_craft ; i++)
    {
        cout<<i<<". "<<afms_air_craft[i][0]<<"   ";
    }
    back:
    gotoxy(columns_of_screen/4,17);
    cin>>option;
    if(numeric_validation(option))
    {
        gotoxy(columns_of_screen/4,17);
        cout<<"                      ";
        goto back;
    }
    if(stoi(option) < count_afms_air_craft && stoi(option) >= 0)
    {   int row = stoi(option);
        for(int i = 0 ; i < 5 ; i++)
        {
            gotoxy(columns_of_screen/3,19 + i);
            cout<<readable_instruments_afms[i];
            backer:
            gotoxy(columns_of_screen/3 + 20,19 + i);
            cin>>word;
            if(validation_check_instruments(i,word))
            {
                gotoxy(columns_of_screen/3 + 20,19 + i);
                cout<<"                   ";
                goto backer;    
            }    
            afms_air_craft[row][i] = word;        
        }
    }
    else 
    {
        goto back;
    }
}
void to_edit_instrument_record_weapons_air_force()
{
    string option;
    string word;
    title("EDIT THE INSTRUMENTS RECORD");
    gotoxy(columns_of_screen/4,15);
    for(int i = 0 ; i < count_afms_weapons ; i++)
    {
        cout<<i<<". "<<afms_weapons[i][0]<<"   ";
    }
    back:
    gotoxy(columns_of_screen/4,17);
    cin>>option;
    if(numeric_validation(option))
    {
        gotoxy(columns_of_screen/4,17);
        cout<<"                      ";
        goto back;
    }
    if(stoi(option) < count_afms_weapons && stoi(option) >= 0)
    {   int row = stoi(option);
        for(int i = 0 ; i < 5 ; i++)
        {
            gotoxy(columns_of_screen/3,19 + i);
            cout<<readable_instruments_afms[i];
            backer:
            gotoxy(columns_of_screen/3 + 20,19 + i);
            cin>>word;
            if(validation_check_instruments(i,word))
            {
                gotoxy(columns_of_screen/3 + 20,19 + i);
                cout<<"                   ";
                goto backer;    
            }    
            afms_weapons[row][i] = word;        
        }
    }
    else 
    {
        goto back;
    }
}
void to_edit_instrument_record_planes()
{
    string option;
    string word;
    title("EDIT THE INSTRUMENTS RECORD");
    gotoxy(columns_of_screen/4,15);
    for(int i = 0 ; i < count_afms_planes ; i++)
    {
        cout<<i<<". "<<afms_planes[i][0]<<"   ";
    }
    back:
    gotoxy(columns_of_screen/4,17);
    cin>>option;
    if(numeric_validation(option))
    {
        gotoxy(columns_of_screen/4,17);
        cout<<"                      ";
        goto back;
    }
    if(stoi(option) < count_afms_planes && stoi(option) >= 0)
    {   int row = stoi(option);
        for(int i = 0 ; i < 5 ; i++)
        {
            gotoxy(columns_of_screen/3,19 + i);
            cout<<readable_instruments_afms[i];
            backer:
            gotoxy(columns_of_screen/3 + 20,19 + i);
            cin>>word;
            if(validation_check_instruments(i,word))
            {
                gotoxy(columns_of_screen/3 + 20,19 + i);
                cout<<"                   ";
                goto backer;    
            }    
            afms_planes[row][i] = word;        
        }
    }
    else 
    {
        goto back;
    }
}
void to_edit_instrument_record_missilies_air_force()
{
    string option;
    string word;
    title("EDIT THE INSTRUMENTS RECORD");
    gotoxy(columns_of_screen/4,15);
    for(int i = 0 ; i < count_afms_missilies ; i++)
    {
        cout<<i<<". "<<afms_missilies[i][0]<<"   ";
    }
    back:
    gotoxy(columns_of_screen/4,17);
    cin>>option;
    if(numeric_validation(option))
    {
        gotoxy(columns_of_screen/4,17);
        cout<<"                      ";
        goto back;
    }
    if(stoi(option) < count_afms_missilies && stoi(option) >= 0)
    {   int row = stoi(option);
        for(int i = 0 ; i < 5 ; i++)
        {
            gotoxy(columns_of_screen/3,19 + i);
            cout<<readable_instruments_afms[i];
            backer:
            gotoxy(columns_of_screen/3 + 20,19 + i);
            cin>>word;
            if(validation_check_instruments(i,word))
            {
                gotoxy(columns_of_screen/3 + 20,19 + i);
                cout<<"                   ";
                goto backer;    
            }    
            afms_missilies[row][i] = word;        
        }
    }
    else 
    {
        goto back;
    }
}
void to_edit_instrument_record_trackers()
{
    string option;
    string word;
    title("EDIT THE INSTRUMENTS RECORD");
    gotoxy(columns_of_screen/4,15);
    for(int i = 0 ; i < count_afms_trackers ; i++)
    {
        cout<<i<<". "<<afms_trackers[i][0]<<"   ";
    }
    back:
    gotoxy(columns_of_screen/4,17);
    cin>>option;
    if(numeric_validation(option))
    {
        gotoxy(columns_of_screen/4,17);
        cout<<"                      ";
        goto back;
    }
    if(stoi(option) < count_afms_trackers && stoi(option) >= 0)
    {   int row = stoi(option);
        for(int i = 0 ; i < 5 ; i++)
        {
            gotoxy(columns_of_screen/3,19 + i);
            cout<<readable_instruments_afms[i];
            backer:
            gotoxy(columns_of_screen/3 + 20,19 + i);
            cin>>word;
            if(validation_check_instruments(i,word))
            {
                gotoxy(columns_of_screen/3 + 20,19 + i);
                cout<<"                   ";
                goto backer;    
            }    
            afms_trackers[row][i] = word;        
        }
    }
    else 
    {
        goto back;
    }
}
// ADD WHOLE DATA IN TXT instruments
void to_add_whole_data_in_txt_air_craft_air_force()
{
    string file_path = "instruments/afms_air_craft.txt";
    string line;
    fstream file;
    file.open(file_path,ios::out);

    for(int i = 0 ; i < count_afms_air_craft ; i++)
    {   if(i != 0)
        {
            file << endl;
        }
        for(int j = 0 ; j < 5 ; j++)
        {
        file << afms_air_craft[i][j];
        file << ","; 
        }
    }
    file.close();
}
// planes
void to_add_whole_data_in_txt_planes()
{
    string file_path = "instruments/afms_planes.txt";
    string line;
    fstream file;
    file.open(file_path,ios::out);

    for(int i = 0 ; i < count_afms_planes ; i++)
    {   if(i != 0)
        {
            file << endl;
        }
        for(int j = 0 ; j < 5 ; j++)
        {
        file << afms_planes[i][j];
        file << ","; 
        }
    }
    file.close();
}
// mweapons
void to_add_whole_data_in_txt_weapons_air_force()
{
    string file_path = "instruments/afms_weapons.txt";
    string line;
    fstream file;
    file.open(file_path,ios::out);

    for(int i = 0 ; i < count_afms_weapons ; i++)
    {   if(i != 0)
        {
            file << endl;
        }
        for(int j = 0 ; j < 5 ; j++)
        {
        file << afms_weapons[i][j];
        file << ","; 
        }
    }
    file.close();
}
// missilies
void to_add_whole_data_in_txt_missilies_air_force()
{
    string file_path = "instruments/afms_missilies.txt";
    string line;
    fstream file;
    file.open(file_path,ios::out);

    for(int i = 0 ; i < count_afms_missilies ; i++)
    {   if(i != 0)
        {
            file << endl;
        }
        for(int j = 0 ; j < 5 ; j++)
        {
        file << afms_missilies[i][j];
        file << ","; 
        }
    }
    file.close();
}

void to_add_whole_data_in_txt_trackers()
{
    string file_path = "instruments/afms_trackers.txt";
    string line;
    fstream file;
    file.open(file_path,ios::out);

    for(int i = 0 ; i < count_afms_trackers ; i++)
    {   if(i != 0)
        {
            file << endl;
        }
        for(int j = 0 ; j < 5 ; j++)
        {
        file << afms_trackers[i][j];
        file << ","; 
        }
    }
    file.close();
}
// sub menu 4
void graph_afms()
{   int item_quantity[5] = {0,0,0,0,0};
    for(int i = 0 ; i < count_afms_air_craft ; i++)
    {
        item_quantity[0] = item_quantity[0] + stoi(afms_air_craft[i][2]);
    }
    for(int i = 0 ; i < count_afms_weapons ; i++)
    {
        item_quantity[1] = item_quantity[1] + stoi(afms_weapons[i][2]);
    }
    for(int i = 0 ; i < count_afms_missilies ; i++)
    {
        item_quantity[2] = item_quantity[2] + stoi(afms_missilies[i][2]);
    }
    for(int i = 0 ; i < count_afms_planes ; i++)
    {
        item_quantity[3] = item_quantity[3] + stoi(afms_planes[i][2]);
    }
    for(int i = 0 ; i < count_afms_trackers ; i++)
    {
        item_quantity[4] = item_quantity[4] + stoi(afms_trackers[i][2]);
    }
	int j = 0;
	for (int i = columns_of_screen / 8; i < columns_of_screen - 1; i++)
	{
		gotoxy(i, rows_of_screen - 4);
		cout << "*";
	}
	for (int i = rows_of_screen - 4; i > 8; i--)
	{
		gotoxy(columns_of_screen / 8, i);
		cout << "*";
	}
	for (int i = 0; i < 20; i = i + 4)
	{

		gotoxy(2, rows_of_screen / 3 + i);
		cout << sub_of_sub_menu_instruments_afms[j];
		j++;
	}
	int x = 0;
	int screen = columns_of_screen / 8 + 1;
	for (int i = 0; i < 20; i = i + 4)
	{
		for (j = 0; j < item_quantity[x] / 50000; j++)
		{
			gotoxy(screen + j, rows_of_screen / 3 + i);
			cout << "#";
		}
		gotoxy(screen + j, rows_of_screen / 3 + i);
		cout << " ";
		x++;
	}
}
// budget afms
void total_afms_budget()
{
    int item_quantity[5] = {0,0,0,0,0};
    for(int i = 0 ; i < count_afms_air_craft ; i++)
    {
        item_quantity[0] = item_quantity[0] + stoi(afms_air_craft[i][2]);
    }
    for(int i = 0 ; i < count_afms_weapons ; i++)
    {
        item_quantity[1] = item_quantity[1] + stoi(afms_weapons[i][2]);
    }
    for(int i = 0 ; i < count_afms_missilies ; i++)
    {
        item_quantity[2] = item_quantity[2] + stoi(afms_missilies[i][2]);
    }
    for(int i = 0 ; i < count_afms_planes ; i++)
    {
        item_quantity[3] = item_quantity[3] + stoi(afms_planes[i][2]);
    }
    for(int i = 0 ; i < count_afms_trackers ; i++)
    {
        item_quantity[4] = item_quantity[4] + stoi(afms_trackers[i][2]);
    }
    int x = 0;
    for(int i = 0 ; i < 5 ; i++)
    {
        gotoxy(columns_of_screen/3 , 16 + x);
        cout<<sub_of_sub_menu_instruments_afms[i];
        gotoxy(columns_of_screen/3 + 20, 16 + x);
        cout<<item_quantity[i];
        x = x + 2;
    }
}
// SUB 4 MENU CROPS
int to_show_sub_menu_air_force_crops_afms(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << afms_crops[i];
        rows = rows + 4;
    }
    return 1;
}
void to_show_nav_khor()
{   
    title("CROPS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < air_force_soldier_count ; i++)
    {
        if(air_force_soldier_array[3][i] == "PUNJAB" || air_force_soldier_array[3][i] == "SINDH")
        {
            gotoxy(columns_of_screen/3,14 + i);
            cout<<"BATCH ID: "<<air_force_soldier_array[0][i]<<endl;
        }

    }
    for(int i = 0 ; i < air_force_officer_count ; i++)
    {
        if(air_force_officer_array[3][i] == "PUNJAB" || air_force_officer_array[3][i] == "SINDH")
        {
            gotoxy(columns_of_screen/3,14 + i);
            cout<<"BATCH ID: "<<air_force_officer_array[0][i]<<endl;
            gotoxy(columns_of_screen/3,14 + i + 1);
            cout<<"____________________________________";
        }

    }
}
void to_show_him_khor()
{   
    
    title("CROPS MANAGEMENT SYSTEM");
    for(int i = 0 ; i < air_force_soldier_count ; i++)
    {
        if(air_force_soldier_array[3][i] == "KPK" || air_force_soldier_array[3][i] == "BALOCHISTAN" || air_force_soldier_array[3][i] == "KASHMIR")
        {
            gotoxy(columns_of_screen/3,14 + i);
            cout<<"BATCH ID: "<<air_force_soldier_array[0][i]<<endl;
            
        }

    }
    for(int i = 0 ; i < air_force_officer_count ; i++)
    {   
        if(air_force_officer_array[3][i] == "KPK" || air_force_officer_array[3][i] == "BALOCHISTAN" || air_force_officer_array[3][i] == "KASHMIR")
        { 
            gotoxy(columns_of_screen/3 + 20,14 + i);
            cout<<"BATCH ID: "<<air_force_officer_array[0][i]<<endl;
            gotoxy(columns_of_screen/3 + 20,14 + i + 1);
            cout<<"____________________________________";

        }

    }
}
//                          USER 4 
//                          AOMS
// TO get batch id
void to_get_candidates_batch_id()
{
    string word;
    for(int i = 0 ; i < 5 ; i++)
    {
        back:
        gotoxy(columns_of_screen/3,10 + i);
        cout<<"CANDIDATE "<<i + 1;
        gotoxy(columns_of_screen/3 + 15,10 + i);
        cin>>word;
        if(numeric_validation(word))
        {
            invalid_function();
            gotoxy(columns_of_screen/3 + 15,10 + i);
            cout<<"                ";
            goto back;
        }
        candidate_batch_id[i] = word;
    }
}
int to_show_main_menu_aoms(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 + 10, rows);
        cout << aoms_main_menus[i];
        rows = rows + 4;
    }
    return 1;
}
// to show personal details option and things
int to_show_personal_details_from_aoms()
{
    int arr_index = 0;
    to_show_personal_details_options_aoms();
    for (int i = 0; i < 16; i = i + 2)
    {
        gotoxy(columns_of_screen / 3 + 30, 15 + i);
        cout << army_officer_array[arr_index][batch_id_index_security];
        arr_index++;
    }
    gotoxy(columns_of_screen / 3 + 10, rows_of_screen - 5);
    cout << "PRESS ANY KEY TO GO BACK";
    getch();
    return 1;
}
// to show personal details options by aoms
void to_show_personal_details_options_aoms()
{
    int details_index = 0;
    for (int i = 0; i < 16; i = i + 2)
    {
        gotoxy(columns_of_screen / 3, 15 + i);
        cout << personal_details_options_ams_officers[details_index];
        details_index++;
    }
}
// to show GTo
int to_show_gto_tasks(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 , rows);
        cout << gto_tasks[i]<<"                                                                 ";
        rows = rows + 4;
    }
    return 1;
}
// to show psychologist
int to_show_psychologist_tasks(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 , rows);
        cout << psychologist_tasks[i]<<"                                                      ";
        rows = rows + 4;
    }
    return 1;
}
// 
int to_get_candidate_marks_gto()
{   
    title("GTO GROUP TAKS");
    int rows = 10;   
    string word;
    for (int i = 0; i < 5; i++)
    {  
        total_candidatr_marks_gto[i] = 0;
        rows = 10;
        to_show_gto_tasks(6);
        for(int j = 0 ; j < 6 ; j++)
        {
        back:
        gotoxy(columns_of_screen / 3 + 30 , rows);
        cin>>word;
        if(numeric_validation(word))
        {
            gotoxy(columns_of_screen / 3 + 30 , rows);
            cout<<"                   ";
            goto back;
        }
        if(!(stoi(word) <= 100))
        {
            gotoxy(columns_of_screen / 3 + 30, rows);
            cout<<"                   ";
            goto back;
        }
        gto_tasks_marks[i][j] = word;
        total_candidatr_marks_gto[i] = total_candidatr_marks_gto[i] + stoi(word);
        rows = rows + 4;
        }
    }
    return 1;
}
int to_get_candidate_marks_psychologist()
{
    title("PSYCOLOGYIST TASKS OF GROUP");
    int rows = 10;
    string word;
    for (int i = 0; i < 5; i++)
    {   
        total_candidatr_marks_psychologist[i] = 0;
        rows = 10;
        to_show_psychologist_tasks(6);
        for(int j = 0 ; j < 6 ; j++)
        {
        back:
        gotoxy(columns_of_screen / 3 + 30 , rows);
        cin>>word;
        if(numeric_validation(word))
        {
            gotoxy(columns_of_screen / 3 + 30, rows);
            cout<<"                   ";
            goto back;
        }
        if(!(stoi(word) <= 100))
        {
            gotoxy(columns_of_screen / 3 + 30, rows);
            cout<<"                   ";
            goto back;
        }
        psychologist_tasks_marks[i][j] = word;
        total_candidatr_marks_psychologist[i] = total_candidatr_marks_psychologist[i] + stoi(word);
        rows = rows + 4;
        }
    }
    return 1;
}
// to add data in txt feedback
void to_add_data_in_txt_feedback_gto()
{
    fstream file;
    file.open("feedback_file/feedbackfile.txt", ios::app);
    for(int i = 0 ; i < 5 ; i++)
    {
        if(total_candidatr_marks_gto[i] >= 460)
        {   file << endl;
            file << candidate_batch_id[i];
            file << ",";
            file << "PASSED GTO";
            file << ",";
        }
    }
    file.close();
}
void to_add_data_in_txt_feedback_psychologist()
{
    fstream file;
    file.open("feedback_file/feedbackfile.txt", ios::app);
    for(int i = 0 ; i < 5 ; i++)
    {
        if(total_candidatr_marks_psychologist[i] >= 460)
        {   file << endl;
            file << candidate_batch_id[i];
            file << ",";
            file << "PASSED GTO";
            file << ",";
        }
    }
    file.close();
}
// CODE BY CROPS
int code_by_corp()
{           
            int n = 5;
            title("CODE BY CROPS");
			string moves[9] = {"ATTACK-ON-POINT-9", "DEFEND-ON-POINT-F", "ATTACK-ON-POINT-C", "ATTACK-ON-POINT-A", "ATTACK-ON-POINT-S", "ATTACK-ON-POINT-J", "ATTACK-ON-POINT-Q", "ATTACK-ON-POINT-R", "ATTACK-ON-POINT-G"};
			int number[4], checker[4], printer;
			int x = 18;
            string word;
			for (int i = 0; i < 4; i++)
			{
				gotoxy(columns_of_screen / 4 + 26, x);
				cout << "Number "<<i + 1<<" :";
                back:
				gotoxy(columns_of_screen / 4 + 46, x);
				cin >> word;
                if(numeric_validation(word))
                {
                    gotoxy(columns_of_screen / 4 + 46, x);
                    cout<<"                ";
                    goto back;
                }
                if(stoi(word) > 9)
                {
                    gotoxy(columns_of_screen / 4 + 46, x);
                    cout<<"                ";
                    goto back;
                    
                }
				number[i] = stoi(word);
                x++;
			}
			for (int i = 0; i < 4; i++)
			{
				checker[i] = number[i] + i;
				if (checker[i] > 9)
				{
					checker[i] = checker[i] - 10;
				}
			}
			title("CODE BY CROPS");
			int y = -10;
			for (int i = 0; i < 4; i++)
			{

				printer = checker[i];
				gotoxy(columns_of_screen / 4 + y, 20);
				cout << moves[printer] << " then ";
				y = y + 30;
			}
			n = yes_or_no(n);
            return n;
}
int to_show_main_war_ideas()
{
    int rows = 10;
    string ideas[6] = {"PLACE 1: ", "PLACE 2: ", "PLACE 3: ", "PLACE 4: ", "PLACE 5: ", "PLACE 6: "};
    for (int i = 0; i < 6; i++)
    {
        gotoxy(columns_of_screen / 3, rows);
        cout << ideas[i] <<"                           ";
        rows = rows + 4;
    }
    return 1;
}
int to_input_war_ideas()
{
    int highest = -1000;
    int index = 0;
    int rows = 10;
    string war_planes[3][6];
    int total[3];
    string word;
    for (int i = 0; i < 3; i++)
    {   to_show_main_war_ideas();
        rows = 10;
        for(int j = 0 ; j < 6 ; j++)
        {
        back:
        gotoxy(columns_of_screen / 3 + 30, rows);
        cin>>word;
        if(word == "1" || word == "0")
        {
            war_planes[i][j] = word;
            total[i] = total[i] + stoi(word); 
        }
        else
        {
            gotoxy(columns_of_screen / 3 + 30, rows);
            cout<<"                  ";
            goto back;
        }
        rows = rows + 4;
        }
        if(total[i] >= highest)
        {
            index = i;
        }
    }
    if(index > 0)
    {
        title("WAR IDEA CONCLUSION");
        gotoxy(columns_of_screen/3,18);
        cout<<index<<" IDEA IS BEST BECAUSE OF ITS CREDENTIALS";
    }
    else if(index < 0)
    {
        title("WAR IDEA CONCLUSION");
        gotoxy(columns_of_screen/3,18);
        cout<<"ALL IDEAS ARE USELESS YOU NEED PUNISHMENT OFFICER";
    }
    return 1;
}
// to show personal details options by aoms
int to_show_personal_selector_details_options_aoms(int no_of_index)
{
    int rows = 10;

    for (int i = 0; i < no_of_index; i++)
    {
        gotoxy(columns_of_screen / 3 , rows);
        cout << aoms_issb_selector_option[i];
        rows = rows + 4;
    }
    return 1;
}
// 5 th user
// to show personal details option and things
int to_show_personal_details_from_noms()
{
    int arr_index = 0;
    to_show_personal_details_options_aoms();
    for (int i = 0; i < 16; i = i + 2)
    {
        gotoxy(columns_of_screen / 3 + 30, 15 + i);
        cout << navy_officer_array[arr_index][batch_id_index_security];
        arr_index++;
    }
    gotoxy(columns_of_screen / 3 + 10, rows_of_screen - 5);
    cout << "PRESS ANY KEY TO GO BACK";
    getch();
    return 1;
}
// 6 th user
// to show personal details option and things
int to_show_personal_details_from_afoms()
{
    int arr_index = 0;
    to_show_personal_details_options_aoms();
    for (int i = 0; i < 16; i = i + 2)
    {
        gotoxy(columns_of_screen / 3 + 30, 15 + i);
        cout << air_force_officer_array[arr_index][batch_id_index_security];
        arr_index++;
    }
    gotoxy(columns_of_screen / 3 + 10, rows_of_screen - 5);
    cout << "PRESS ANY KEY TO GO BACK";
    getch();
    return 1;
}

