#include "nitc__abstract_compiler.sep.0.h"
/* method abstract_compiler#AMethPropdef#compile_intern_to_c for (self: AMethPropdef, AbstractCompilerVisitor, MMethodDef, Array[RuntimeVariable]): Bool */
short int nitc__abstract_compiler___AMethPropdef___compile_intern_to_c(val* self, val* p0, val* p1, val* p2) {
short int var /* : Bool */;
val* var_v /* var v: AbstractCompilerVisitor */;
val* var_mpropdef /* var mpropdef: MMethodDef */;
val* var_arguments /* var arguments: Array[RuntimeVariable] */;
val* var1 /* : MProperty */;
val* var3 /* : MProperty */;
val* var4 /* : String */;
val* var6 /* : String */;
val* var_pname /* var pname: String */;
val* var7 /* : MClassDef */;
val* var9 /* : MClassDef */;
val* var10 /* : MClass */;
val* var12 /* : MClass */;
val* var13 /* : String */;
val* var15 /* : String */;
val* var_cname /* var cname: String */;
val* var16 /* : nullable MSignature */;
val* var18 /* : nullable MSignature */;
val* var19 /* : nullable MType */;
val* var21 /* : nullable MType */;
val* var_ret /* var ret: nullable MType */;
short int var22 /* : Bool */;
short int var23 /* : Bool */;
val* var_other /* var other: nullable Object */;
short int var25 /* : Bool */;
short int var26 /* : Bool */;
val* var27 /* : nullable Object */;
val* var28 /* : MType */;
short int var29 /* : Bool */;
static val* varonce;
val* var30 /* : String */;
char* var31 /* : NativeString */;
val* var32 /* : String */;
short int var33 /* : Bool */;
short int var35 /* : Bool */;
short int var36 /* : Bool */;
short int var_ /* var : Bool */;
static val* varonce37;
val* var38 /* : String */;
char* var39 /* : NativeString */;
val* var40 /* : String */;
short int var41 /* : Bool */;
short int var43 /* : Bool */;
short int var44 /* : Bool */;
static val* varonce45;
val* var46 /* : String */;
char* var47 /* : NativeString */;
val* var48 /* : String */;
short int var49 /* : Bool */;
static val* varonce50;
val* var51 /* : String */;
char* var52 /* : NativeString */;
val* var53 /* : String */;
short int var54 /* : Bool */;
val* var56 /* : NativeArray[String] */;
static val* varonce55;
static val* varonce57;
val* var58 /* : String */;
char* var59 /* : NativeString */;
val* var60 /* : String */;
static val* varonce61;
val* var62 /* : String */;
char* var63 /* : NativeString */;
val* var64 /* : String */;
val* var65 /* : nullable Object */;
val* var66 /* : String */;
val* var67 /* : String */;
static val* varonce68;
val* var69 /* : String */;
char* var70 /* : NativeString */;
val* var71 /* : String */;
short int var72 /* : Bool */;
val* var73 /* : nullable Object */;
static val* varonce74;
val* var75 /* : String */;
char* var76 /* : NativeString */;
val* var77 /* : String */;
short int var78 /* : Bool */;
val* var80 /* : NativeArray[String] */;
static val* varonce79;
static val* varonce81;
val* var82 /* : String */;
char* var83 /* : NativeString */;
val* var84 /* : String */;
val* var85 /* : nullable Object */;
val* var86 /* : String */;
val* var87 /* : nullable Object */;
val* var88 /* : String */;
val* var89 /* : String */;
val* var90 /* : RuntimeVariable */;
static val* varonce91;
val* var92 /* : String */;
char* var93 /* : NativeString */;
val* var94 /* : String */;
short int var95 /* : Bool */;
val* var97 /* : NativeArray[String] */;
static val* varonce96;
static val* varonce98;
val* var99 /* : String */;
char* var100 /* : NativeString */;
val* var101 /* : String */;
val* var102 /* : nullable Object */;
val* var103 /* : String */;
val* var104 /* : nullable Object */;
val* var105 /* : String */;
val* var106 /* : String */;
val* var107 /* : RuntimeVariable */;
static val* varonce108;
val* var109 /* : String */;
char* var110 /* : NativeString */;
val* var111 /* : String */;
short int var112 /* : Bool */;
val* var114 /* : NativeArray[String] */;
static val* varonce113;
static val* varonce115;
val* var116 /* : String */;
char* var117 /* : NativeString */;
val* var118 /* : String */;
val* var119 /* : nullable Object */;
val* var120 /* : String */;
val* var121 /* : String */;
val* var122 /* : RuntimeVariable */;
static val* varonce123;
val* var124 /* : String */;
char* var125 /* : NativeString */;
val* var126 /* : String */;
short int var127 /* : Bool */;
val* var128 /* : nullable Object */;
static val* varonce129;
val* var130 /* : String */;
char* var131 /* : NativeString */;
val* var132 /* : String */;
short int var133 /* : Bool */;
val* var135 /* : NativeArray[String] */;
static val* varonce134;
static val* varonce136;
val* var137 /* : String */;
char* var138 /* : NativeString */;
val* var139 /* : String */;
val* var140 /* : nullable Object */;
val* var141 /* : String */;
val* var142 /* : nullable Object */;
val* var143 /* : String */;
val* var144 /* : String */;
val* var145 /* : RuntimeVariable */;
static val* varonce146;
val* var147 /* : String */;
char* var148 /* : NativeString */;
val* var149 /* : String */;
short int var150 /* : Bool */;
val* var152 /* : NativeArray[String] */;
static val* varonce151;
static val* varonce153;
val* var154 /* : String */;
char* var155 /* : NativeString */;
val* var156 /* : String */;
val* var157 /* : nullable Object */;
val* var158 /* : String */;
val* var159 /* : nullable Object */;
val* var160 /* : String */;
val* var161 /* : String */;
val* var162 /* : RuntimeVariable */;
static val* varonce163;
val* var164 /* : String */;
char* var165 /* : NativeString */;
val* var166 /* : String */;
short int var167 /* : Bool */;
val* var169 /* : NativeArray[String] */;
static val* varonce168;
static val* varonce170;
val* var171 /* : String */;
char* var172 /* : NativeString */;
val* var173 /* : String */;
val* var174 /* : nullable Object */;
val* var175 /* : String */;
val* var176 /* : nullable Object */;
val* var177 /* : String */;
val* var178 /* : String */;
val* var179 /* : RuntimeVariable */;
static val* varonce180;
val* var181 /* : String */;
char* var182 /* : NativeString */;
val* var183 /* : String */;
short int var184 /* : Bool */;
val* var185 /* : nullable Object */;
val* var186 /* : nullable Object */;
val* var187 /* : RuntimeVariable */;
static val* varonce188;
val* var189 /* : String */;
char* var190 /* : NativeString */;
val* var191 /* : String */;
short int var192 /* : Bool */;
val* var193 /* : nullable Object */;
val* var194 /* : nullable Object */;
val* var195 /* : RuntimeVariable */;
val* var_res /* var res: RuntimeVariable */;
val* var197 /* : NativeArray[String] */;
static val* varonce196;
static val* varonce198;
val* var199 /* : String */;
char* var200 /* : NativeString */;
val* var201 /* : String */;
val* var202 /* : String */;
val* var203 /* : String */;
val* var204 /* : RuntimeVariable */;
static val* varonce205;
val* var206 /* : String */;
char* var207 /* : NativeString */;
val* var208 /* : String */;
short int var209 /* : Bool */;
val* var211 /* : NativeArray[String] */;
static val* varonce210;
static val* varonce212;
val* var213 /* : String */;
char* var214 /* : NativeString */;
val* var215 /* : String */;
val* var216 /* : nullable Object */;
val* var217 /* : String */;
val* var218 /* : nullable Object */;
val* var219 /* : String */;
val* var220 /* : String */;
val* var221 /* : RuntimeVariable */;
static val* varonce222;
val* var223 /* : String */;
char* var224 /* : NativeString */;
val* var225 /* : String */;
short int var226 /* : Bool */;
val* var228 /* : NativeArray[String] */;
static val* varonce227;
static val* varonce229;
val* var230 /* : String */;
char* var231 /* : NativeString */;
val* var232 /* : String */;
val* var233 /* : nullable Object */;
val* var234 /* : String */;
val* var235 /* : nullable Object */;
val* var236 /* : String */;
val* var237 /* : String */;
val* var238 /* : RuntimeVariable */;
static val* varonce239;
val* var240 /* : String */;
char* var241 /* : NativeString */;
val* var242 /* : String */;
short int var243 /* : Bool */;
val* var245 /* : NativeArray[String] */;
static val* varonce244;
static val* varonce246;
val* var247 /* : String */;
char* var248 /* : NativeString */;
val* var249 /* : String */;
val* var250 /* : nullable Object */;
val* var251 /* : String */;
val* var252 /* : nullable Object */;
val* var253 /* : String */;
val* var254 /* : String */;
val* var255 /* : RuntimeVariable */;
static val* varonce256;
val* var257 /* : String */;
char* var258 /* : NativeString */;
val* var259 /* : String */;
short int var260 /* : Bool */;
val* var262 /* : NativeArray[String] */;
static val* varonce261;
static val* varonce263;
val* var264 /* : String */;
char* var265 /* : NativeString */;
val* var266 /* : String */;
val* var267 /* : nullable Object */;
val* var268 /* : String */;
val* var269 /* : nullable Object */;
val* var270 /* : String */;
val* var271 /* : String */;
val* var272 /* : RuntimeVariable */;
static val* varonce273;
val* var274 /* : String */;
char* var275 /* : NativeString */;
val* var276 /* : String */;
short int var277 /* : Bool */;
val* var279 /* : NativeArray[String] */;
static val* varonce278;
static val* varonce280;
val* var281 /* : String */;
char* var282 /* : NativeString */;
val* var283 /* : String */;
val* var284 /* : nullable Object */;
val* var285 /* : String */;
val* var286 /* : String */;
val* var287 /* : RuntimeVariable */;
static val* varonce288;
val* var289 /* : String */;
char* var290 /* : NativeString */;
val* var291 /* : String */;
short int var292 /* : Bool */;
val* var294 /* : NativeArray[String] */;
static val* varonce293;
static val* varonce295;
val* var296 /* : String */;
char* var297 /* : NativeString */;
val* var298 /* : String */;
val* var299 /* : nullable Object */;
val* var300 /* : String */;
val* var301 /* : String */;
val* var302 /* : RuntimeVariable */;
static val* varonce303;
val* var304 /* : String */;
char* var305 /* : NativeString */;
val* var306 /* : String */;
short int var307 /* : Bool */;
val* var309 /* : NativeArray[String] */;
static val* varonce308;
static val* varonce310;
val* var311 /* : String */;
char* var312 /* : NativeString */;
val* var313 /* : String */;
val* var314 /* : nullable Object */;
val* var315 /* : String */;
val* var316 /* : String */;
val* var317 /* : RuntimeVariable */;
static val* varonce318;
val* var319 /* : String */;
char* var320 /* : NativeString */;
val* var321 /* : String */;
short int var322 /* : Bool */;
val* var324 /* : NativeArray[String] */;
static val* varonce323;
static val* varonce325;
val* var326 /* : String */;
char* var327 /* : NativeString */;
val* var328 /* : String */;
val* var329 /* : nullable Object */;
val* var330 /* : String */;
val* var331 /* : String */;
val* var332 /* : RuntimeVariable */;
static val* varonce333;
val* var334 /* : String */;
char* var335 /* : NativeString */;
val* var336 /* : String */;
short int var337 /* : Bool */;
val* var339 /* : NativeArray[String] */;
static val* varonce338;
static val* varonce340;
val* var341 /* : String */;
char* var342 /* : NativeString */;
val* var343 /* : String */;
val* var344 /* : nullable Object */;
val* var345 /* : String */;
val* var346 /* : String */;
val* var347 /* : RuntimeVariable */;
static val* varonce348;
val* var349 /* : String */;
char* var350 /* : NativeString */;
val* var351 /* : String */;
short int var352 /* : Bool */;
val* var354 /* : NativeArray[String] */;
static val* varonce353;
static val* varonce355;
val* var356 /* : String */;
char* var357 /* : NativeString */;
val* var358 /* : String */;
val* var359 /* : nullable Object */;
val* var360 /* : String */;
val* var361 /* : String */;
val* var362 /* : RuntimeVariable */;
static val* varonce363;
val* var364 /* : String */;
char* var365 /* : NativeString */;
val* var366 /* : String */;
short int var367 /* : Bool */;
val* var369 /* : NativeArray[String] */;
static val* varonce368;
static val* varonce370;
val* var371 /* : String */;
char* var372 /* : NativeString */;
val* var373 /* : String */;
val* var374 /* : nullable Object */;
val* var375 /* : String */;
val* var376 /* : String */;
val* var377 /* : RuntimeVariable */;
static val* varonce378;
val* var379 /* : String */;
char* var380 /* : NativeString */;
val* var381 /* : String */;
short int var382 /* : Bool */;
val* var384 /* : NativeArray[String] */;
static val* varonce383;
static val* varonce385;
val* var386 /* : String */;
char* var387 /* : NativeString */;
val* var388 /* : String */;
val* var389 /* : nullable Object */;
val* var390 /* : String */;
val* var391 /* : String */;
val* var392 /* : RuntimeVariable */;
static val* varonce393;
val* var394 /* : String */;
char* var395 /* : NativeString */;
val* var396 /* : String */;
short int var397 /* : Bool */;
val* var399 /* : NativeArray[String] */;
static val* varonce398;
static val* varonce400;
val* var401 /* : String */;
char* var402 /* : NativeString */;
val* var403 /* : String */;
val* var404 /* : nullable Object */;
val* var405 /* : String */;
val* var406 /* : nullable Object */;
val* var407 /* : String */;
val* var408 /* : String */;
val* var409 /* : RuntimeVariable */;
static val* varonce410;
val* var411 /* : String */;
char* var412 /* : NativeString */;
val* var413 /* : String */;
short int var414 /* : Bool */;
val* var416 /* : NativeArray[String] */;
static val* varonce415;
static val* varonce417;
val* var418 /* : String */;
char* var419 /* : NativeString */;
val* var420 /* : String */;
val* var421 /* : nullable Object */;
val* var422 /* : String */;
val* var423 /* : nullable Object */;
val* var424 /* : String */;
val* var425 /* : String */;
val* var426 /* : RuntimeVariable */;
static val* varonce427;
val* var428 /* : String */;
char* var429 /* : NativeString */;
val* var430 /* : String */;
short int var431 /* : Bool */;
val* var433 /* : NativeArray[String] */;
static val* varonce432;
static val* varonce434;
val* var435 /* : String */;
char* var436 /* : NativeString */;
val* var437 /* : String */;
val* var438 /* : nullable Object */;
val* var439 /* : String */;
val* var440 /* : nullable Object */;
val* var441 /* : String */;
val* var442 /* : String */;
val* var443 /* : RuntimeVariable */;
static val* varonce444;
val* var445 /* : String */;
char* var446 /* : NativeString */;
val* var447 /* : String */;
short int var448 /* : Bool */;
val* var450 /* : NativeArray[String] */;
static val* varonce449;
static val* varonce451;
val* var452 /* : String */;
char* var453 /* : NativeString */;
val* var454 /* : String */;
val* var455 /* : nullable Object */;
val* var456 /* : String */;
val* var457 /* : nullable Object */;
val* var458 /* : String */;
val* var459 /* : String */;
val* var460 /* : RuntimeVariable */;
static val* varonce461;
val* var462 /* : String */;
char* var463 /* : NativeString */;
val* var464 /* : String */;
short int var465 /* : Bool */;
static val* varonce466;
val* var467 /* : String */;
char* var468 /* : NativeString */;
val* var469 /* : String */;
short int var470 /* : Bool */;
val* var472 /* : NativeArray[String] */;
static val* varonce471;
static val* varonce473;
val* var474 /* : String */;
char* var475 /* : NativeString */;
val* var476 /* : String */;
val* var477 /* : nullable Object */;
val* var478 /* : String */;
val* var479 /* : String */;
val* var480 /* : RuntimeVariable */;
static val* varonce481;
val* var482 /* : String */;
char* var483 /* : NativeString */;
val* var484 /* : String */;
short int var485 /* : Bool */;
val* var487 /* : NativeArray[String] */;
static val* varonce486;
static val* varonce488;
val* var489 /* : String */;
char* var490 /* : NativeString */;
val* var491 /* : String */;
val* var492 /* : nullable Object */;
val* var493 /* : String */;
val* var494 /* : nullable Object */;
val* var495 /* : String */;
val* var496 /* : String */;
val* var497 /* : RuntimeVariable */;
static val* varonce498;
val* var499 /* : String */;
char* var500 /* : NativeString */;
val* var501 /* : String */;
short int var502 /* : Bool */;
val* var504 /* : NativeArray[String] */;
static val* varonce503;
static val* varonce505;
val* var506 /* : String */;
char* var507 /* : NativeString */;
val* var508 /* : String */;
val* var509 /* : nullable Object */;
val* var510 /* : String */;
val* var511 /* : nullable Object */;
val* var512 /* : String */;
val* var513 /* : String */;
val* var514 /* : RuntimeVariable */;
static val* varonce515;
val* var516 /* : String */;
char* var517 /* : NativeString */;
val* var518 /* : String */;
short int var519 /* : Bool */;
val* var520 /* : nullable Object */;
val* var521 /* : nullable Object */;
val* var522 /* : RuntimeVariable */;
static val* varonce523;
val* var524 /* : String */;
char* var525 /* : NativeString */;
val* var526 /* : String */;
short int var527 /* : Bool */;
val* var528 /* : nullable Object */;
val* var529 /* : nullable Object */;
val* var530 /* : RuntimeVariable */;
val* var_res531 /* var res: RuntimeVariable */;
val* var533 /* : NativeArray[String] */;
static val* varonce532;
static val* varonce534;
val* var535 /* : String */;
char* var536 /* : NativeString */;
val* var537 /* : String */;
val* var538 /* : String */;
val* var539 /* : String */;
val* var540 /* : RuntimeVariable */;
static val* varonce541;
val* var542 /* : String */;
char* var543 /* : NativeString */;
val* var544 /* : String */;
short int var545 /* : Bool */;
val* var547 /* : NativeArray[String] */;
static val* varonce546;
static val* varonce548;
val* var549 /* : String */;
char* var550 /* : NativeString */;
val* var551 /* : String */;
val* var552 /* : nullable Object */;
val* var553 /* : String */;
val* var554 /* : nullable Object */;
val* var555 /* : String */;
val* var556 /* : String */;
val* var557 /* : RuntimeVariable */;
static val* varonce558;
val* var559 /* : String */;
char* var560 /* : NativeString */;
val* var561 /* : String */;
short int var562 /* : Bool */;
val* var564 /* : NativeArray[String] */;
static val* varonce563;
static val* varonce565;
val* var566 /* : String */;
char* var567 /* : NativeString */;
val* var568 /* : String */;
val* var569 /* : nullable Object */;
val* var570 /* : String */;
val* var571 /* : nullable Object */;
val* var572 /* : String */;
val* var573 /* : String */;
val* var574 /* : RuntimeVariable */;
static val* varonce575;
val* var576 /* : String */;
char* var577 /* : NativeString */;
val* var578 /* : String */;
short int var579 /* : Bool */;
val* var581 /* : NativeArray[String] */;
static val* varonce580;
static val* varonce582;
val* var583 /* : String */;
char* var584 /* : NativeString */;
val* var585 /* : String */;
val* var586 /* : nullable Object */;
val* var587 /* : String */;
val* var588 /* : nullable Object */;
val* var589 /* : String */;
val* var590 /* : String */;
val* var591 /* : RuntimeVariable */;
static val* varonce592;
val* var593 /* : String */;
char* var594 /* : NativeString */;
val* var595 /* : String */;
short int var596 /* : Bool */;
val* var598 /* : NativeArray[String] */;
static val* varonce597;
static val* varonce599;
val* var600 /* : String */;
char* var601 /* : NativeString */;
val* var602 /* : String */;
val* var603 /* : nullable Object */;
val* var604 /* : String */;
val* var605 /* : nullable Object */;
val* var606 /* : String */;
val* var607 /* : String */;
val* var608 /* : RuntimeVariable */;
static val* varonce609;
val* var610 /* : String */;
char* var611 /* : NativeString */;
val* var612 /* : String */;
short int var613 /* : Bool */;
val* var615 /* : NativeArray[String] */;
static val* varonce614;
static val* varonce616;
val* var617 /* : String */;
char* var618 /* : NativeString */;
val* var619 /* : String */;
val* var620 /* : nullable Object */;
val* var621 /* : String */;
val* var622 /* : String */;
val* var623 /* : RuntimeVariable */;
static val* varonce624;
val* var625 /* : String */;
char* var626 /* : NativeString */;
val* var627 /* : String */;
short int var628 /* : Bool */;
val* var630 /* : NativeArray[String] */;
static val* varonce629;
static val* varonce631;
val* var632 /* : String */;
char* var633 /* : NativeString */;
val* var634 /* : String */;
val* var635 /* : nullable Object */;
val* var636 /* : String */;
val* var637 /* : String */;
val* var638 /* : RuntimeVariable */;
static val* varonce639;
val* var640 /* : String */;
char* var641 /* : NativeString */;
val* var642 /* : String */;
short int var643 /* : Bool */;
static val* varonce644;
val* var645 /* : String */;
char* var646 /* : NativeString */;
val* var647 /* : String */;
short int var648 /* : Bool */;
val* var650 /* : NativeArray[String] */;
static val* varonce649;
static val* varonce651;
val* var652 /* : String */;
char* var653 /* : NativeString */;
val* var654 /* : String */;
static val* varonce655;
val* var656 /* : String */;
char* var657 /* : NativeString */;
val* var658 /* : String */;
val* var659 /* : nullable Object */;
val* var660 /* : String */;
val* var661 /* : String */;
static val* varonce662;
val* var663 /* : String */;
char* var664 /* : NativeString */;
val* var665 /* : String */;
short int var666 /* : Bool */;
val* var668 /* : NativeArray[String] */;
static val* varonce667;
static val* varonce669;
val* var670 /* : String */;
char* var671 /* : NativeString */;
val* var672 /* : String */;
val* var673 /* : nullable Object */;
val* var674 /* : String */;
val* var675 /* : String */;
val* var676 /* : RuntimeVariable */;
static val* varonce677;
val* var678 /* : String */;
char* var679 /* : NativeString */;
val* var680 /* : String */;
short int var681 /* : Bool */;
val* var683 /* : NativeArray[String] */;
static val* varonce682;
static val* varonce684;
val* var685 /* : String */;
char* var686 /* : NativeString */;
val* var687 /* : String */;
val* var688 /* : nullable Object */;
val* var689 /* : String */;
val* var690 /* : nullable Object */;
val* var691 /* : String */;
val* var692 /* : String */;
val* var693 /* : RuntimeVariable */;
static val* varonce694;
val* var695 /* : String */;
char* var696 /* : NativeString */;
val* var697 /* : String */;
short int var698 /* : Bool */;
val* var700 /* : NativeArray[String] */;
static val* varonce699;
static val* varonce701;
val* var702 /* : String */;
char* var703 /* : NativeString */;
val* var704 /* : String */;
val* var705 /* : nullable Object */;
val* var706 /* : String */;
val* var707 /* : nullable Object */;
val* var708 /* : String */;
val* var709 /* : String */;
val* var710 /* : RuntimeVariable */;
static val* varonce711;
val* var712 /* : String */;
char* var713 /* : NativeString */;
val* var714 /* : String */;
short int var715 /* : Bool */;
val* var717 /* : NativeArray[String] */;
static val* varonce716;
static val* varonce718;
val* var719 /* : String */;
char* var720 /* : NativeString */;
val* var721 /* : String */;
val* var722 /* : nullable Object */;
val* var723 /* : String */;
val* var724 /* : String */;
val* var725 /* : RuntimeVariable */;
static val* varonce726;
val* var727 /* : String */;
char* var728 /* : NativeString */;
val* var729 /* : String */;
short int var730 /* : Bool */;
val* var731 /* : nullable Object */;
static val* varonce732;
val* var733 /* : String */;
char* var734 /* : NativeString */;
val* var735 /* : String */;
short int var736 /* : Bool */;
val* var738 /* : NativeArray[String] */;
static val* varonce737;
static val* varonce739;
val* var740 /* : String */;
char* var741 /* : NativeString */;
val* var742 /* : String */;
val* var743 /* : nullable Object */;
val* var744 /* : String */;
val* var745 /* : nullable Object */;
val* var746 /* : String */;
val* var747 /* : String */;
val* var748 /* : RuntimeVariable */;
static val* varonce749;
val* var750 /* : String */;
char* var751 /* : NativeString */;
val* var752 /* : String */;
short int var753 /* : Bool */;
val* var755 /* : NativeArray[String] */;
static val* varonce754;
static val* varonce756;
val* var757 /* : String */;
char* var758 /* : NativeString */;
val* var759 /* : String */;
val* var760 /* : nullable Object */;
val* var761 /* : String */;
val* var762 /* : nullable Object */;
val* var763 /* : String */;
val* var764 /* : String */;
val* var765 /* : RuntimeVariable */;
static val* varonce766;
val* var767 /* : String */;
char* var768 /* : NativeString */;
val* var769 /* : String */;
short int var770 /* : Bool */;
val* var772 /* : NativeArray[String] */;
static val* varonce771;
static val* varonce773;
val* var774 /* : String */;
char* var775 /* : NativeString */;
val* var776 /* : String */;
val* var777 /* : nullable Object */;
val* var778 /* : String */;
val* var779 /* : nullable Object */;
val* var780 /* : String */;
val* var781 /* : String */;
val* var782 /* : RuntimeVariable */;
static val* varonce783;
val* var784 /* : String */;
char* var785 /* : NativeString */;
val* var786 /* : String */;
short int var787 /* : Bool */;
val* var788 /* : nullable Object */;
val* var789 /* : nullable Object */;
val* var790 /* : RuntimeVariable */;
static val* varonce791;
val* var792 /* : String */;
char* var793 /* : NativeString */;
val* var794 /* : String */;
short int var795 /* : Bool */;
val* var796 /* : nullable Object */;
val* var797 /* : nullable Object */;
val* var798 /* : RuntimeVariable */;
val* var_res799 /* var res: RuntimeVariable */;
val* var801 /* : NativeArray[String] */;
static val* varonce800;
static val* varonce802;
val* var803 /* : String */;
char* var804 /* : NativeString */;
val* var805 /* : String */;
val* var806 /* : String */;
val* var807 /* : String */;
val* var808 /* : RuntimeVariable */;
static val* varonce809;
val* var810 /* : String */;
char* var811 /* : NativeString */;
val* var812 /* : String */;
short int var813 /* : Bool */;
val* var815 /* : NativeArray[String] */;
static val* varonce814;
static val* varonce816;
val* var817 /* : String */;
char* var818 /* : NativeString */;
val* var819 /* : String */;
val* var820 /* : nullable Object */;
val* var821 /* : String */;
val* var822 /* : nullable Object */;
val* var823 /* : String */;
val* var824 /* : String */;
val* var825 /* : RuntimeVariable */;
static val* varonce826;
val* var827 /* : String */;
char* var828 /* : NativeString */;
val* var829 /* : String */;
short int var830 /* : Bool */;
val* var832 /* : NativeArray[String] */;
static val* varonce831;
static val* varonce833;
val* var834 /* : String */;
char* var835 /* : NativeString */;
val* var836 /* : String */;
val* var837 /* : nullable Object */;
val* var838 /* : String */;
val* var839 /* : nullable Object */;
val* var840 /* : String */;
val* var841 /* : String */;
val* var842 /* : RuntimeVariable */;
static val* varonce843;
val* var844 /* : String */;
char* var845 /* : NativeString */;
val* var846 /* : String */;
short int var847 /* : Bool */;
val* var849 /* : NativeArray[String] */;
static val* varonce848;
static val* varonce850;
val* var851 /* : String */;
char* var852 /* : NativeString */;
val* var853 /* : String */;
val* var854 /* : nullable Object */;
val* var855 /* : String */;
val* var856 /* : nullable Object */;
val* var857 /* : String */;
val* var858 /* : String */;
val* var859 /* : RuntimeVariable */;
static val* varonce860;
val* var861 /* : String */;
char* var862 /* : NativeString */;
val* var863 /* : String */;
short int var864 /* : Bool */;
val* var866 /* : NativeArray[String] */;
static val* varonce865;
static val* varonce867;
val* var868 /* : String */;
char* var869 /* : NativeString */;
val* var870 /* : String */;
val* var871 /* : nullable Object */;
val* var872 /* : String */;
val* var873 /* : nullable Object */;
val* var874 /* : String */;
val* var875 /* : String */;
val* var876 /* : RuntimeVariable */;
static val* varonce877;
val* var878 /* : String */;
char* var879 /* : NativeString */;
val* var880 /* : String */;
short int var881 /* : Bool */;
val* var883 /* : NativeArray[String] */;
static val* varonce882;
static val* varonce884;
val* var885 /* : String */;
char* var886 /* : NativeString */;
val* var887 /* : String */;
val* var888 /* : nullable Object */;
val* var889 /* : String */;
val* var890 /* : nullable Object */;
val* var891 /* : String */;
val* var892 /* : String */;
val* var893 /* : RuntimeVariable */;
static val* varonce894;
val* var895 /* : String */;
char* var896 /* : NativeString */;
val* var897 /* : String */;
short int var898 /* : Bool */;
val* var900 /* : NativeArray[String] */;
static val* varonce899;
static val* varonce901;
val* var902 /* : String */;
char* var903 /* : NativeString */;
val* var904 /* : String */;
val* var905 /* : nullable Object */;
val* var906 /* : String */;
val* var907 /* : nullable Object */;
val* var908 /* : String */;
val* var909 /* : String */;
val* var910 /* : RuntimeVariable */;
static val* varonce911;
val* var912 /* : String */;
char* var913 /* : NativeString */;
val* var914 /* : String */;
short int var915 /* : Bool */;
val* var917 /* : NativeArray[String] */;
static val* varonce916;
static val* varonce918;
val* var919 /* : String */;
char* var920 /* : NativeString */;
val* var921 /* : String */;
val* var922 /* : nullable Object */;
val* var923 /* : String */;
val* var924 /* : nullable Object */;
val* var925 /* : String */;
val* var926 /* : String */;
val* var927 /* : RuntimeVariable */;
static val* varonce928;
val* var929 /* : String */;
char* var930 /* : NativeString */;
val* var931 /* : String */;
short int var932 /* : Bool */;
val* var934 /* : NativeArray[String] */;
static val* varonce933;
static val* varonce935;
val* var936 /* : String */;
char* var937 /* : NativeString */;
val* var938 /* : String */;
val* var939 /* : nullable Object */;
val* var940 /* : String */;
val* var941 /* : String */;
val* var942 /* : RuntimeVariable */;
static val* varonce943;
val* var944 /* : String */;
char* var945 /* : NativeString */;
val* var946 /* : String */;
short int var947 /* : Bool */;
val* var949 /* : NativeArray[String] */;
static val* varonce948;
static val* varonce950;
val* var951 /* : String */;
char* var952 /* : NativeString */;
val* var953 /* : String */;
val* var954 /* : nullable Object */;
val* var955 /* : String */;
val* var956 /* : String */;
val* var957 /* : RuntimeVariable */;
static val* varonce958;
val* var959 /* : String */;
char* var960 /* : NativeString */;
val* var961 /* : String */;
short int var962 /* : Bool */;
val* var964 /* : NativeArray[String] */;
static val* varonce963;
static val* varonce965;
val* var966 /* : String */;
char* var967 /* : NativeString */;
val* var968 /* : String */;
val* var969 /* : nullable Object */;
val* var970 /* : String */;
val* var971 /* : String */;
val* var972 /* : RuntimeVariable */;
static val* varonce973;
val* var974 /* : String */;
char* var975 /* : NativeString */;
val* var976 /* : String */;
short int var977 /* : Bool */;
val* var979 /* : NativeArray[String] */;
static val* varonce978;
static val* varonce980;
val* var981 /* : String */;
char* var982 /* : NativeString */;
val* var983 /* : String */;
val* var984 /* : nullable Object */;
val* var985 /* : String */;
val* var986 /* : String */;
val* var987 /* : RuntimeVariable */;
static val* varonce988;
val* var989 /* : String */;
char* var990 /* : NativeString */;
val* var991 /* : String */;
short int var992 /* : Bool */;
val* var994 /* : NativeArray[String] */;
static val* varonce993;
static val* varonce995;
val* var996 /* : String */;
char* var997 /* : NativeString */;
val* var998 /* : String */;
val* var999 /* : nullable Object */;
val* var1000 /* : String */;
val* var1001 /* : String */;
val* var1002 /* : RuntimeVariable */;
static val* varonce1003;
val* var1004 /* : String */;
char* var1005 /* : NativeString */;
val* var1006 /* : String */;
short int var1007 /* : Bool */;
val* var1009 /* : NativeArray[String] */;
static val* varonce1008;
static val* varonce1010;
val* var1011 /* : String */;
char* var1012 /* : NativeString */;
val* var1013 /* : String */;
val* var1014 /* : nullable Object */;
val* var1015 /* : String */;
val* var1016 /* : String */;
val* var1017 /* : RuntimeVariable */;
static val* varonce1018;
val* var1019 /* : String */;
char* var1020 /* : NativeString */;
val* var1021 /* : String */;
short int var1022 /* : Bool */;
val* var1024 /* : NativeArray[String] */;
static val* varonce1023;
static val* varonce1025;
val* var1026 /* : String */;
char* var1027 /* : NativeString */;
val* var1028 /* : String */;
val* var1029 /* : nullable Object */;
val* var1030 /* : String */;
val* var1031 /* : String */;
val* var1032 /* : RuntimeVariable */;
static val* varonce1033;
val* var1034 /* : String */;
char* var1035 /* : NativeString */;
val* var1036 /* : String */;
short int var1037 /* : Bool */;
val* var1039 /* : NativeArray[String] */;
static val* varonce1038;
static val* varonce1040;
val* var1041 /* : String */;
char* var1042 /* : NativeString */;
val* var1043 /* : String */;
val* var1044 /* : nullable Object */;
val* var1045 /* : String */;
val* var1046 /* : String */;
val* var1047 /* : RuntimeVariable */;
static val* varonce1048;
val* var1049 /* : String */;
char* var1050 /* : NativeString */;
val* var1051 /* : String */;
short int var1052 /* : Bool */;
static val* varonce1053;
val* var1054 /* : String */;
char* var1055 /* : NativeString */;
val* var1056 /* : String */;
short int var1057 /* : Bool */;
val* var1059 /* : NativeArray[String] */;
static val* varonce1058;
static val* varonce1060;
val* var1061 /* : String */;
char* var1062 /* : NativeString */;
val* var1063 /* : String */;
static val* varonce1064;
val* var1065 /* : String */;
char* var1066 /* : NativeString */;
val* var1067 /* : String */;
val* var1068 /* : nullable Object */;
val* var1069 /* : String */;
val* var1070 /* : String */;
static val* varonce1071;
val* var1072 /* : String */;
char* var1073 /* : NativeString */;
val* var1074 /* : String */;
short int var1075 /* : Bool */;
val* var1077 /* : NativeArray[String] */;
static val* varonce1076;
static val* varonce1078;
val* var1079 /* : String */;
char* var1080 /* : NativeString */;
val* var1081 /* : String */;
val* var1082 /* : nullable Object */;
val* var1083 /* : String */;
val* var1084 /* : String */;
val* var1085 /* : RuntimeVariable */;
static val* varonce1086;
val* var1087 /* : String */;
char* var1088 /* : NativeString */;
val* var1089 /* : String */;
short int var1090 /* : Bool */;
val* var1091 /* : nullable Object */;
val* var1092 /* : nullable Object */;
val* var1093 /* : RuntimeVariable */;
static val* varonce1094;
val* var1095 /* : String */;
char* var1096 /* : NativeString */;
val* var1097 /* : String */;
short int var1098 /* : Bool */;
val* var1099 /* : nullable Object */;
val* var1100 /* : nullable Object */;
val* var1101 /* : RuntimeVariable */;
val* var_res1102 /* var res: RuntimeVariable */;
val* var1104 /* : NativeArray[String] */;
static val* varonce1103;
static val* varonce1105;
val* var1106 /* : String */;
char* var1107 /* : NativeString */;
val* var1108 /* : String */;
val* var1109 /* : String */;
val* var1110 /* : String */;
val* var1111 /* : RuntimeVariable */;
static val* varonce1112;
val* var1113 /* : String */;
char* var1114 /* : NativeString */;
val* var1115 /* : String */;
short int var1116 /* : Bool */;
static val* varonce1117;
val* var1118 /* : String */;
char* var1119 /* : NativeString */;
val* var1120 /* : String */;
short int var1121 /* : Bool */;
val* var1123 /* : NativeArray[String] */;
static val* varonce1122;
static val* varonce1124;
val* var1125 /* : String */;
char* var1126 /* : NativeString */;
val* var1127 /* : String */;
static val* varonce1128;
val* var1129 /* : String */;
char* var1130 /* : NativeString */;
val* var1131 /* : String */;
val* var1132 /* : nullable Object */;
val* var1133 /* : String */;
val* var1134 /* : String */;
static val* varonce1135;
val* var1136 /* : String */;
char* var1137 /* : NativeString */;
val* var1138 /* : String */;
short int var1139 /* : Bool */;
val* var1141 /* : NativeArray[String] */;
static val* varonce1140;
static val* varonce1142;
val* var1143 /* : String */;
char* var1144 /* : NativeString */;
val* var1145 /* : String */;
val* var1146 /* : nullable Object */;
val* var1147 /* : String */;
val* var1148 /* : String */;
val* var1149 /* : RuntimeVariable */;
static val* varonce1150;
val* var1151 /* : String */;
char* var1152 /* : NativeString */;
val* var1153 /* : String */;
short int var1154 /* : Bool */;
val* var1156 /* : NativeArray[String] */;
static val* varonce1155;
static val* varonce1157;
val* var1158 /* : String */;
char* var1159 /* : NativeString */;
val* var1160 /* : String */;
val* var1161 /* : nullable Object */;
val* var1162 /* : String */;
val* var1163 /* : nullable Object */;
val* var1164 /* : String */;
val* var1165 /* : String */;
val* var1166 /* : RuntimeVariable */;
static val* varonce1167;
val* var1168 /* : String */;
char* var1169 /* : NativeString */;
val* var1170 /* : String */;
short int var1171 /* : Bool */;
val* var1173 /* : NativeArray[String] */;
static val* varonce1172;
static val* varonce1174;
val* var1175 /* : String */;
char* var1176 /* : NativeString */;
val* var1177 /* : String */;
val* var1178 /* : nullable Object */;
val* var1179 /* : String */;
val* var1180 /* : nullable Object */;
val* var1181 /* : String */;
val* var1182 /* : String */;
val* var1183 /* : RuntimeVariable */;
static val* varonce1184;
val* var1185 /* : String */;
char* var1186 /* : NativeString */;
val* var1187 /* : String */;
short int var1188 /* : Bool */;
val* var1190 /* : NativeArray[String] */;
static val* varonce1189;
static val* varonce1191;
val* var1192 /* : String */;
char* var1193 /* : NativeString */;
val* var1194 /* : String */;
val* var1195 /* : nullable Object */;
val* var1196 /* : String */;
val* var1197 /* : String */;
val* var1198 /* : RuntimeVariable */;
static val* varonce1199;
val* var1200 /* : String */;
char* var1201 /* : NativeString */;
val* var1202 /* : String */;
short int var1203 /* : Bool */;
val* var1204 /* : nullable Object */;
static val* varonce1205;
val* var1206 /* : String */;
char* var1207 /* : NativeString */;
val* var1208 /* : String */;
short int var1209 /* : Bool */;
val* var1211 /* : NativeArray[String] */;
static val* varonce1210;
static val* varonce1212;
val* var1213 /* : String */;
char* var1214 /* : NativeString */;
val* var1215 /* : String */;
val* var1216 /* : nullable Object */;
val* var1217 /* : String */;
val* var1218 /* : String */;
val* var1219 /* : RuntimeVariable */;
static val* varonce1220;
val* var1221 /* : String */;
char* var1222 /* : NativeString */;
val* var1223 /* : String */;
short int var1224 /* : Bool */;
val* var1226 /* : NativeArray[String] */;
static val* varonce1225;
static val* varonce1227;
val* var1228 /* : String */;
char* var1229 /* : NativeString */;
val* var1230 /* : String */;
val* var1231 /* : nullable Object */;
val* var1232 /* : String */;
val* var1233 /* : String */;
val* var1234 /* : RuntimeVariable */;
static val* varonce1235;
val* var1236 /* : String */;
char* var1237 /* : NativeString */;
val* var1238 /* : String */;
short int var1239 /* : Bool */;
val* var1241 /* : NativeArray[String] */;
static val* varonce1240;
static val* varonce1242;
val* var1243 /* : String */;
char* var1244 /* : NativeString */;
val* var1245 /* : String */;
val* var1246 /* : nullable Object */;
val* var1247 /* : String */;
val* var1248 /* : nullable Object */;
val* var1249 /* : String */;
val* var1250 /* : String */;
val* var1251 /* : RuntimeVariable */;
static val* varonce1252;
val* var1253 /* : String */;
char* var1254 /* : NativeString */;
val* var1255 /* : String */;
short int var1256 /* : Bool */;
val* var1258 /* : NativeArray[String] */;
static val* varonce1257;
static val* varonce1259;
val* var1260 /* : String */;
char* var1261 /* : NativeString */;
val* var1262 /* : String */;
val* var1263 /* : nullable Object */;
val* var1264 /* : String */;
val* var1265 /* : nullable Object */;
val* var1266 /* : String */;
val* var1267 /* : String */;
val* var1268 /* : RuntimeVariable */;
static val* varonce1269;
val* var1270 /* : String */;
char* var1271 /* : NativeString */;
val* var1272 /* : String */;
short int var1273 /* : Bool */;
val* var1274 /* : nullable Object */;
val* var1275 /* : nullable Object */;
val* var1276 /* : RuntimeVariable */;
static val* varonce1277;
val* var1278 /* : String */;
char* var1279 /* : NativeString */;
val* var1280 /* : String */;
short int var1281 /* : Bool */;
val* var1282 /* : nullable Object */;
val* var1283 /* : nullable Object */;
val* var1284 /* : RuntimeVariable */;
val* var_res1285 /* var res: RuntimeVariable */;
val* var1287 /* : NativeArray[String] */;
static val* varonce1286;
static val* varonce1288;
val* var1289 /* : String */;
char* var1290 /* : NativeString */;
val* var1291 /* : String */;
val* var1292 /* : String */;
val* var1293 /* : String */;
val* var1294 /* : RuntimeVariable */;
static val* varonce1295;
val* var1296 /* : String */;
char* var1297 /* : NativeString */;
val* var1298 /* : String */;
short int var1299 /* : Bool */;
val* var1301 /* : NativeArray[String] */;
static val* varonce1300;
static val* varonce1302;
val* var1303 /* : String */;
char* var1304 /* : NativeString */;
val* var1305 /* : String */;
val* var1306 /* : nullable Object */;
val* var1307 /* : String */;
val* var1308 /* : nullable Object */;
val* var1309 /* : String */;
val* var1310 /* : String */;
val* var1311 /* : RuntimeVariable */;
static val* varonce1312;
val* var1313 /* : String */;
char* var1314 /* : NativeString */;
val* var1315 /* : String */;
short int var1316 /* : Bool */;
val* var1318 /* : NativeArray[String] */;
static val* varonce1317;
static val* varonce1319;
val* var1320 /* : String */;
char* var1321 /* : NativeString */;
val* var1322 /* : String */;
val* var1323 /* : nullable Object */;
val* var1324 /* : String */;
val* var1325 /* : nullable Object */;
val* var1326 /* : String */;
val* var1327 /* : String */;
val* var1328 /* : RuntimeVariable */;
static val* varonce1329;
val* var1330 /* : String */;
char* var1331 /* : NativeString */;
val* var1332 /* : String */;
short int var1333 /* : Bool */;
val* var1335 /* : NativeArray[String] */;
static val* varonce1334;
static val* varonce1336;
val* var1337 /* : String */;
char* var1338 /* : NativeString */;
val* var1339 /* : String */;
val* var1340 /* : nullable Object */;
val* var1341 /* : String */;
val* var1342 /* : nullable Object */;
val* var1343 /* : String */;
val* var1344 /* : String */;
val* var1345 /* : RuntimeVariable */;
static val* varonce1346;
val* var1347 /* : String */;
char* var1348 /* : NativeString */;
val* var1349 /* : String */;
short int var1350 /* : Bool */;
val* var1352 /* : NativeArray[String] */;
static val* varonce1351;
static val* varonce1353;
val* var1354 /* : String */;
char* var1355 /* : NativeString */;
val* var1356 /* : String */;
val* var1357 /* : nullable Object */;
val* var1358 /* : String */;
val* var1359 /* : nullable Object */;
val* var1360 /* : String */;
val* var1361 /* : String */;
val* var1362 /* : RuntimeVariable */;
static val* varonce1363;
val* var1364 /* : String */;
char* var1365 /* : NativeString */;
val* var1366 /* : String */;
short int var1367 /* : Bool */;
val* var1369 /* : NativeArray[String] */;
static val* varonce1368;
static val* varonce1370;
val* var1371 /* : String */;
char* var1372 /* : NativeString */;
val* var1373 /* : String */;
val* var1374 /* : nullable Object */;
val* var1375 /* : String */;
val* var1376 /* : String */;
val* var1377 /* : RuntimeVariable */;
static val* varonce1378;
val* var1379 /* : String */;
char* var1380 /* : NativeString */;
val* var1381 /* : String */;
short int var1382 /* : Bool */;
val* var1384 /* : NativeArray[String] */;
static val* varonce1383;
static val* varonce1385;
val* var1386 /* : String */;
char* var1387 /* : NativeString */;
val* var1388 /* : String */;
val* var1389 /* : nullable Object */;
val* var1390 /* : String */;
val* var1391 /* : String */;
val* var1392 /* : RuntimeVariable */;
static val* varonce1393;
val* var1394 /* : String */;
char* var1395 /* : NativeString */;
val* var1396 /* : String */;
short int var1397 /* : Bool */;
val* var1399 /* : NativeArray[String] */;
static val* varonce1398;
static val* varonce1400;
val* var1401 /* : String */;
char* var1402 /* : NativeString */;
val* var1403 /* : String */;
val* var1404 /* : nullable Object */;
val* var1405 /* : String */;
val* var1406 /* : String */;
val* var1407 /* : RuntimeVariable */;
static val* varonce1408;
val* var1409 /* : String */;
char* var1410 /* : NativeString */;
val* var1411 /* : String */;
short int var1412 /* : Bool */;
val* var1414 /* : NativeArray[String] */;
static val* varonce1413;
static val* varonce1415;
val* var1416 /* : String */;
char* var1417 /* : NativeString */;
val* var1418 /* : String */;
val* var1419 /* : nullable Object */;
val* var1420 /* : String */;
val* var1421 /* : String */;
val* var1422 /* : RuntimeVariable */;
static val* varonce1423;
val* var1424 /* : String */;
char* var1425 /* : NativeString */;
val* var1426 /* : String */;
short int var1427 /* : Bool */;
val* var1429 /* : NativeArray[String] */;
static val* varonce1428;
static val* varonce1430;
val* var1431 /* : String */;
char* var1432 /* : NativeString */;
val* var1433 /* : String */;
val* var1434 /* : nullable Object */;
val* var1435 /* : String */;
val* var1436 /* : String */;
val* var1437 /* : RuntimeVariable */;
static val* varonce1438;
val* var1439 /* : String */;
char* var1440 /* : NativeString */;
val* var1441 /* : String */;
short int var1442 /* : Bool */;
val* var1444 /* : NativeArray[String] */;
static val* varonce1443;
static val* varonce1445;
val* var1446 /* : String */;
char* var1447 /* : NativeString */;
val* var1448 /* : String */;
val* var1449 /* : nullable Object */;
val* var1450 /* : String */;
val* var1451 /* : String */;
val* var1452 /* : RuntimeVariable */;
static val* varonce1453;
val* var1454 /* : String */;
char* var1455 /* : NativeString */;
val* var1456 /* : String */;
short int var1457 /* : Bool */;
val* var1459 /* : NativeArray[String] */;
static val* varonce1458;
static val* varonce1460;
val* var1461 /* : String */;
char* var1462 /* : NativeString */;
val* var1463 /* : String */;
val* var1464 /* : nullable Object */;
val* var1465 /* : String */;
val* var1466 /* : String */;
val* var1467 /* : RuntimeVariable */;
static val* varonce1468;
val* var1469 /* : String */;
char* var1470 /* : NativeString */;
val* var1471 /* : String */;
short int var1472 /* : Bool */;
static val* varonce1473;
val* var1474 /* : String */;
char* var1475 /* : NativeString */;
val* var1476 /* : String */;
short int var1477 /* : Bool */;
val* var1479 /* : NativeArray[String] */;
static val* varonce1478;
static val* varonce1480;
val* var1481 /* : String */;
char* var1482 /* : NativeString */;
val* var1483 /* : String */;
static val* varonce1484;
val* var1485 /* : String */;
char* var1486 /* : NativeString */;
val* var1487 /* : String */;
val* var1488 /* : nullable Object */;
val* var1489 /* : String */;
val* var1490 /* : String */;
val* var1491 /* : RuntimeVariable */;
static val* varonce1492;
val* var1493 /* : String */;
char* var1494 /* : NativeString */;
val* var1495 /* : String */;
short int var1496 /* : Bool */;
static val* varonce1497;
val* var1498 /* : String */;
char* var1499 /* : NativeString */;
val* var1500 /* : String */;
short int var1501 /* : Bool */;
val* var1503 /* : NativeArray[String] */;
static val* varonce1502;
static val* varonce1504;
val* var1505 /* : String */;
char* var1506 /* : NativeString */;
val* var1507 /* : String */;
static val* varonce1508;
val* var1509 /* : String */;
char* var1510 /* : NativeString */;
val* var1511 /* : String */;
static val* varonce1512;
val* var1513 /* : String */;
char* var1514 /* : NativeString */;
val* var1515 /* : String */;
val* var1516 /* : nullable Object */;
val* var1517 /* : String */;
val* var1518 /* : nullable Object */;
val* var1519 /* : String */;
val* var1520 /* : String */;
val* var1521 /* : RuntimeVariable */;
static val* varonce1522;
val* var1523 /* : String */;
char* var1524 /* : NativeString */;
val* var1525 /* : String */;
short int var1526 /* : Bool */;
val* var1528 /* : NativeArray[String] */;
static val* varonce1527;
static val* varonce1529;
val* var1530 /* : String */;
char* var1531 /* : NativeString */;
val* var1532 /* : String */;
static val* varonce1533;
val* var1534 /* : String */;
char* var1535 /* : NativeString */;
val* var1536 /* : String */;
static val* varonce1537;
val* var1538 /* : String */;
char* var1539 /* : NativeString */;
val* var1540 /* : String */;
val* var1541 /* : nullable Object */;
val* var1542 /* : String */;
val* var1543 /* : nullable Object */;
val* var1544 /* : String */;
val* var1545 /* : nullable Object */;
val* var1546 /* : String */;
val* var1547 /* : String */;
static val* varonce1548;
val* var1549 /* : String */;
char* var1550 /* : NativeString */;
val* var1551 /* : String */;
short int var1552 /* : Bool */;
val* var1554 /* : NativeArray[String] */;
static val* varonce1553;
static val* varonce1555;
val* var1556 /* : String */;
char* var1557 /* : NativeString */;
val* var1558 /* : String */;
static val* varonce1559;
val* var1560 /* : String */;
char* var1561 /* : NativeString */;
val* var1562 /* : String */;
static val* varonce1563;
val* var1564 /* : String */;
char* var1565 /* : NativeString */;
val* var1566 /* : String */;
static val* varonce1567;
val* var1568 /* : String */;
char* var1569 /* : NativeString */;
val* var1570 /* : String */;
static val* varonce1571;
val* var1572 /* : String */;
char* var1573 /* : NativeString */;
val* var1574 /* : String */;
static val* varonce1575;
val* var1576 /* : String */;
char* var1577 /* : NativeString */;
val* var1578 /* : String */;
val* var1579 /* : nullable Object */;
val* var1580 /* : String */;
val* var1581 /* : nullable Object */;
val* var1582 /* : String */;
val* var1583 /* : nullable Object */;
val* var1584 /* : String */;
val* var1585 /* : nullable Object */;
val* var1586 /* : String */;
val* var1587 /* : nullable Object */;
val* var1588 /* : String */;
val* var1589 /* : String */;
static val* varonce1590;
val* var1591 /* : String */;
char* var1592 /* : NativeString */;
val* var1593 /* : String */;
short int var1594 /* : Bool */;
val* var1596 /* : NativeArray[String] */;
static val* varonce1595;
static val* varonce1597;
val* var1598 /* : String */;
char* var1599 /* : NativeString */;
val* var1600 /* : String */;
static val* varonce1601;
val* var1602 /* : String */;
char* var1603 /* : NativeString */;
val* var1604 /* : String */;
val* var1605 /* : nullable Object */;
val* var1606 /* : String */;
val* var1607 /* : String */;
val* var1608 /* : RuntimeVariable */;
static val* varonce1609;
val* var1610 /* : String */;
char* var1611 /* : NativeString */;
val* var1612 /* : String */;
short int var1613 /* : Bool */;
val* var1615 /* : NativeArray[String] */;
static val* varonce1614;
static val* varonce1616;
val* var1617 /* : String */;
char* var1618 /* : NativeString */;
val* var1619 /* : String */;
val* var1620 /* : nullable Object */;
val* var1621 /* : String */;
val* var1622 /* : nullable Object */;
val* var1623 /* : String */;
val* var1624 /* : String */;
val* var1625 /* : RuntimeVariable */;
static val* varonce1626;
val* var1627 /* : String */;
char* var1628 /* : NativeString */;
val* var1629 /* : String */;
short int var1630 /* : Bool */;
val* var1631 /* : nullable Object */;
val* var1632 /* : nullable Object */;
val* var1633 /* : RuntimeVariable */;
static val* varonce1634;
val* var1635 /* : String */;
char* var1636 /* : NativeString */;
val* var1637 /* : String */;
short int var1638 /* : Bool */;
val* var1639 /* : nullable Object */;
val* var1640 /* : nullable Object */;
val* var1641 /* : RuntimeVariable */;
val* var_res1642 /* var res: RuntimeVariable */;
val* var1644 /* : NativeArray[String] */;
static val* varonce1643;
static val* varonce1645;
val* var1646 /* : String */;
char* var1647 /* : NativeString */;
val* var1648 /* : String */;
val* var1649 /* : String */;
val* var1650 /* : String */;
val* var1651 /* : RuntimeVariable */;
static val* varonce1652;
val* var1653 /* : String */;
char* var1654 /* : NativeString */;
val* var1655 /* : String */;
short int var1656 /* : Bool */;
val* var1658 /* : NativeArray[String] */;
static val* varonce1657;
static val* varonce1659;
val* var1660 /* : String */;
char* var1661 /* : NativeString */;
val* var1662 /* : String */;
static val* varonce1663;
val* var1664 /* : String */;
char* var1665 /* : NativeString */;
val* var1666 /* : String */;
val* var1667 /* : nullable Object */;
val* var1668 /* : String */;
val* var1669 /* : String */;
val* var1670 /* : RuntimeVariable */;
static val* varonce1671;
val* var1672 /* : String */;
char* var1673 /* : NativeString */;
val* var1674 /* : String */;
short int var1675 /* : Bool */;
val* var1677 /* : NativeArray[String] */;
static val* varonce1676;
static val* varonce1678;
val* var1679 /* : String */;
char* var1680 /* : NativeString */;
val* var1681 /* : String */;
static val* varonce1682;
val* var1683 /* : String */;
char* var1684 /* : NativeString */;
val* var1685 /* : String */;
static val* varonce1686;
val* var1687 /* : String */;
char* var1688 /* : NativeString */;
val* var1689 /* : String */;
val* var1690 /* : nullable Object */;
val* var1691 /* : String */;
val* var1692 /* : nullable Object */;
val* var1693 /* : String */;
val* var1694 /* : String */;
val* var1695 /* : RuntimeVariable */;
static val* varonce1696;
val* var1697 /* : String */;
char* var1698 /* : NativeString */;
val* var1699 /* : String */;
short int var1700 /* : Bool */;
val* var1702 /* : NativeArray[String] */;
static val* varonce1701;
static val* varonce1703;
val* var1704 /* : String */;
char* var1705 /* : NativeString */;
val* var1706 /* : String */;
static val* varonce1707;
val* var1708 /* : String */;
char* var1709 /* : NativeString */;
val* var1710 /* : String */;
static val* varonce1711;
val* var1712 /* : String */;
char* var1713 /* : NativeString */;
val* var1714 /* : String */;
val* var1715 /* : nullable Object */;
val* var1716 /* : String */;
val* var1717 /* : nullable Object */;
val* var1718 /* : String */;
val* var1719 /* : String */;
val* var1720 /* : RuntimeVariable */;
static val* varonce1721;
val* var1722 /* : String */;
char* var1723 /* : NativeString */;
val* var1724 /* : String */;
short int var1725 /* : Bool */;
short int var1726 /* : Bool */;
static val* varonce1727;
val* var1728 /* : String */;
char* var1729 /* : NativeString */;
val* var1730 /* : String */;
short int var1731 /* : Bool */;
static val* varonce1732;
val* var1733 /* : String */;
char* var1734 /* : NativeString */;
val* var1735 /* : String */;
short int var1736 /* : Bool */;
val* var1738 /* : NativeArray[String] */;
static val* varonce1737;
static val* varonce1739;
val* var1740 /* : String */;
char* var1741 /* : NativeString */;
val* var1742 /* : String */;
static val* varonce1743;
val* var1744 /* : String */;
char* var1745 /* : NativeString */;
val* var1746 /* : String */;
val* var1747 /* : nullable Object */;
val* var1748 /* : String */;
val* var1749 /* : String */;
static val* varonce1750;
val* var1751 /* : String */;
char* var1752 /* : NativeString */;
val* var1753 /* : String */;
short int var1754 /* : Bool */;
val* var1756 /* : NativeArray[String] */;
static val* varonce1755;
static val* varonce1757;
val* var1758 /* : String */;
char* var1759 /* : NativeString */;
val* var1760 /* : String */;
val* var1761 /* : nullable Object */;
val* var1762 /* : String */;
val* var1763 /* : String */;
val* var1764 /* : RuntimeVariable */;
static val* varonce1765;
val* var1766 /* : String */;
char* var1767 /* : NativeString */;
val* var1768 /* : String */;
short int var1769 /* : Bool */;
val* var1771 /* : NativeArray[String] */;
static val* varonce1770;
static val* varonce1772;
val* var1773 /* : String */;
char* var1774 /* : NativeString */;
val* var1775 /* : String */;
val* var1776 /* : nullable Object */;
val* var1777 /* : String */;
val* var1778 /* : nullable Object */;
val* var1779 /* : String */;
val* var1780 /* : String */;
val* var1781 /* : RuntimeVariable */;
static val* varonce1782;
val* var1783 /* : String */;
char* var1784 /* : NativeString */;
val* var1785 /* : String */;
short int var1786 /* : Bool */;
val* var1788 /* : NativeArray[String] */;
static val* varonce1787;
static val* varonce1789;
val* var1790 /* : String */;
char* var1791 /* : NativeString */;
val* var1792 /* : String */;
val* var1793 /* : nullable Object */;
val* var1794 /* : String */;
val* var1795 /* : nullable Object */;
val* var1796 /* : String */;
val* var1797 /* : String */;
val* var1798 /* : RuntimeVariable */;
static val* varonce1799;
val* var1800 /* : String */;
char* var1801 /* : NativeString */;
val* var1802 /* : String */;
short int var1803 /* : Bool */;
val* var1805 /* : NativeArray[String] */;
static val* varonce1804;
static val* varonce1806;
val* var1807 /* : String */;
char* var1808 /* : NativeString */;
val* var1809 /* : String */;
val* var1810 /* : nullable Object */;
val* var1811 /* : String */;
val* var1812 /* : String */;
val* var1813 /* : RuntimeVariable */;
static val* varonce1814;
val* var1815 /* : String */;
char* var1816 /* : NativeString */;
val* var1817 /* : String */;
short int var1818 /* : Bool */;
val* var1819 /* : nullable Object */;
static val* varonce1820;
val* var1821 /* : String */;
char* var1822 /* : NativeString */;
val* var1823 /* : String */;
short int var1824 /* : Bool */;
val* var1826 /* : NativeArray[String] */;
static val* varonce1825;
static val* varonce1827;
val* var1828 /* : String */;
char* var1829 /* : NativeString */;
val* var1830 /* : String */;
val* var1831 /* : nullable Object */;
val* var1832 /* : String */;
val* var1833 /* : nullable Object */;
val* var1834 /* : String */;
val* var1835 /* : String */;
val* var1836 /* : RuntimeVariable */;
static val* varonce1837;
val* var1838 /* : String */;
char* var1839 /* : NativeString */;
val* var1840 /* : String */;
short int var1841 /* : Bool */;
val* var1843 /* : NativeArray[String] */;
static val* varonce1842;
static val* varonce1844;
val* var1845 /* : String */;
char* var1846 /* : NativeString */;
val* var1847 /* : String */;
val* var1848 /* : nullable Object */;
val* var1849 /* : String */;
val* var1850 /* : nullable Object */;
val* var1851 /* : String */;
val* var1852 /* : String */;
val* var1853 /* : RuntimeVariable */;
static val* varonce1854;
val* var1855 /* : String */;
char* var1856 /* : NativeString */;
val* var1857 /* : String */;
short int var1858 /* : Bool */;
val* var1860 /* : NativeArray[String] */;
static val* varonce1859;
static val* varonce1861;
val* var1862 /* : String */;
char* var1863 /* : NativeString */;
val* var1864 /* : String */;
val* var1865 /* : nullable Object */;
val* var1866 /* : String */;
val* var1867 /* : nullable Object */;
val* var1868 /* : String */;
val* var1869 /* : String */;
val* var1870 /* : RuntimeVariable */;
static val* varonce1871;
val* var1872 /* : String */;
char* var1873 /* : NativeString */;
val* var1874 /* : String */;
short int var1875 /* : Bool */;
val* var1877 /* : NativeArray[String] */;
static val* varonce1876;
static val* varonce1878;
val* var1879 /* : String */;
char* var1880 /* : NativeString */;
val* var1881 /* : String */;
val* var1882 /* : nullable Object */;
val* var1883 /* : String */;
val* var1884 /* : nullable Object */;
val* var1885 /* : String */;
val* var1886 /* : String */;
val* var1887 /* : RuntimeVariable */;
static val* varonce1888;
val* var1889 /* : String */;
char* var1890 /* : NativeString */;
val* var1891 /* : String */;
short int var1892 /* : Bool */;
val* var1894 /* : NativeArray[String] */;
static val* varonce1893;
static val* varonce1895;
val* var1896 /* : String */;
char* var1897 /* : NativeString */;
val* var1898 /* : String */;
val* var1899 /* : nullable Object */;
val* var1900 /* : String */;
val* var1901 /* : nullable Object */;
val* var1902 /* : String */;
val* var1903 /* : String */;
val* var1904 /* : RuntimeVariable */;
static val* varonce1905;
val* var1906 /* : String */;
char* var1907 /* : NativeString */;
val* var1908 /* : String */;
short int var1909 /* : Bool */;
val* var1910 /* : nullable Object */;
val* var1911 /* : nullable Object */;
val* var1912 /* : RuntimeVariable */;
static val* varonce1913;
val* var1914 /* : String */;
char* var1915 /* : NativeString */;
val* var1916 /* : String */;
short int var1917 /* : Bool */;
val* var1918 /* : nullable Object */;
val* var1919 /* : nullable Object */;
val* var1920 /* : RuntimeVariable */;
val* var_res1921 /* var res: RuntimeVariable */;
val* var1923 /* : NativeArray[String] */;
static val* varonce1922;
static val* varonce1924;
val* var1925 /* : String */;
char* var1926 /* : NativeString */;
val* var1927 /* : String */;
val* var1928 /* : String */;
val* var1929 /* : String */;
val* var1930 /* : RuntimeVariable */;
static val* varonce1931;
val* var1932 /* : String */;
char* var1933 /* : NativeString */;
val* var1934 /* : String */;
short int var1935 /* : Bool */;
val* var1937 /* : NativeArray[String] */;
static val* varonce1936;
static val* varonce1938;
val* var1939 /* : String */;
char* var1940 /* : NativeString */;
val* var1941 /* : String */;
val* var1942 /* : nullable Object */;
val* var1943 /* : String */;
val* var1944 /* : nullable Object */;
val* var1945 /* : String */;
val* var1946 /* : String */;
val* var1947 /* : RuntimeVariable */;
static val* varonce1948;
val* var1949 /* : String */;
char* var1950 /* : NativeString */;
val* var1951 /* : String */;
short int var1952 /* : Bool */;
val* var1954 /* : NativeArray[String] */;
static val* varonce1953;
static val* varonce1955;
val* var1956 /* : String */;
char* var1957 /* : NativeString */;
val* var1958 /* : String */;
val* var1959 /* : nullable Object */;
val* var1960 /* : String */;
val* var1961 /* : nullable Object */;
val* var1962 /* : String */;
val* var1963 /* : String */;
val* var1964 /* : RuntimeVariable */;
static val* varonce1965;
val* var1966 /* : String */;
char* var1967 /* : NativeString */;
val* var1968 /* : String */;
short int var1969 /* : Bool */;
val* var1971 /* : NativeArray[String] */;
static val* varonce1970;
static val* varonce1972;
val* var1973 /* : String */;
char* var1974 /* : NativeString */;
val* var1975 /* : String */;
val* var1976 /* : nullable Object */;
val* var1977 /* : String */;
val* var1978 /* : nullable Object */;
val* var1979 /* : String */;
val* var1980 /* : String */;
val* var1981 /* : RuntimeVariable */;
static val* varonce1982;
val* var1983 /* : String */;
char* var1984 /* : NativeString */;
val* var1985 /* : String */;
short int var1986 /* : Bool */;
val* var1988 /* : NativeArray[String] */;
static val* varonce1987;
static val* varonce1989;
val* var1990 /* : String */;
char* var1991 /* : NativeString */;
val* var1992 /* : String */;
val* var1993 /* : nullable Object */;
val* var1994 /* : String */;
val* var1995 /* : nullable Object */;
val* var1996 /* : String */;
val* var1997 /* : String */;
val* var1998 /* : RuntimeVariable */;
static val* varonce1999;
val* var2000 /* : String */;
char* var2001 /* : NativeString */;
val* var2002 /* : String */;
short int var2003 /* : Bool */;
val* var2005 /* : NativeArray[String] */;
static val* varonce2004;
static val* varonce2006;
val* var2007 /* : String */;
char* var2008 /* : NativeString */;
val* var2009 /* : String */;
val* var2010 /* : nullable Object */;
val* var2011 /* : String */;
val* var2012 /* : String */;
val* var2013 /* : RuntimeVariable */;
static val* varonce2014;
val* var2015 /* : String */;
char* var2016 /* : NativeString */;
val* var2017 /* : String */;
short int var2018 /* : Bool */;
val* var2020 /* : NativeArray[String] */;
static val* varonce2019;
static val* varonce2021;
val* var2022 /* : String */;
char* var2023 /* : NativeString */;
val* var2024 /* : String */;
val* var2025 /* : nullable Object */;
val* var2026 /* : String */;
val* var2027 /* : String */;
val* var2028 /* : RuntimeVariable */;
static val* varonce2029;
val* var2030 /* : String */;
char* var2031 /* : NativeString */;
val* var2032 /* : String */;
short int var2033 /* : Bool */;
val* var2035 /* : NativeArray[String] */;
static val* varonce2034;
static val* varonce2036;
val* var2037 /* : String */;
char* var2038 /* : NativeString */;
val* var2039 /* : String */;
val* var2040 /* : nullable Object */;
val* var2041 /* : String */;
val* var2042 /* : String */;
val* var2043 /* : RuntimeVariable */;
static val* varonce2044;
val* var2045 /* : String */;
char* var2046 /* : NativeString */;
val* var2047 /* : String */;
short int var2048 /* : Bool */;
val* var2050 /* : NativeArray[String] */;
static val* varonce2049;
static val* varonce2051;
val* var2052 /* : String */;
char* var2053 /* : NativeString */;
val* var2054 /* : String */;
val* var2055 /* : nullable Object */;
val* var2056 /* : String */;
val* var2057 /* : String */;
val* var2058 /* : RuntimeVariable */;
static val* varonce2059;
val* var2060 /* : String */;
char* var2061 /* : NativeString */;
val* var2062 /* : String */;
short int var2063 /* : Bool */;
val* var2065 /* : NativeArray[String] */;
static val* varonce2064;
static val* varonce2066;
val* var2067 /* : String */;
char* var2068 /* : NativeString */;
val* var2069 /* : String */;
val* var2070 /* : nullable Object */;
val* var2071 /* : String */;
val* var2072 /* : String */;
val* var2073 /* : RuntimeVariable */;
static val* varonce2074;
val* var2075 /* : String */;
char* var2076 /* : NativeString */;
val* var2077 /* : String */;
short int var2078 /* : Bool */;
val* var2080 /* : NativeArray[String] */;
static val* varonce2079;
static val* varonce2081;
val* var2082 /* : String */;
char* var2083 /* : NativeString */;
val* var2084 /* : String */;
val* var2085 /* : nullable Object */;
val* var2086 /* : String */;
val* var2087 /* : String */;
val* var2088 /* : RuntimeVariable */;
static val* varonce2089;
val* var2090 /* : String */;
char* var2091 /* : NativeString */;
val* var2092 /* : String */;
short int var2093 /* : Bool */;
val* var2095 /* : NativeArray[String] */;
static val* varonce2094;
static val* varonce2096;
val* var2097 /* : String */;
char* var2098 /* : NativeString */;
val* var2099 /* : String */;
val* var2100 /* : nullable Object */;
val* var2101 /* : String */;
val* var2102 /* : String */;
val* var2103 /* : RuntimeVariable */;
static val* varonce2104;
val* var2105 /* : String */;
char* var2106 /* : NativeString */;
val* var2107 /* : String */;
short int var2108 /* : Bool */;
val* var2110 /* : NativeArray[String] */;
static val* varonce2109;
static val* varonce2111;
val* var2112 /* : String */;
char* var2113 /* : NativeString */;
val* var2114 /* : String */;
val* var2115 /* : nullable Object */;
val* var2116 /* : String */;
val* var2117 /* : nullable Object */;
val* var2118 /* : String */;
val* var2119 /* : String */;
val* var2120 /* : RuntimeVariable */;
static val* varonce2121;
val* var2122 /* : String */;
char* var2123 /* : NativeString */;
val* var2124 /* : String */;
short int var2125 /* : Bool */;
val* var2127 /* : NativeArray[String] */;
static val* varonce2126;
static val* varonce2128;
val* var2129 /* : String */;
char* var2130 /* : NativeString */;
val* var2131 /* : String */;
val* var2132 /* : nullable Object */;
val* var2133 /* : String */;
val* var2134 /* : nullable Object */;
val* var2135 /* : String */;
val* var2136 /* : String */;
val* var2137 /* : RuntimeVariable */;
static val* varonce2138;
val* var2139 /* : String */;
char* var2140 /* : NativeString */;
val* var2141 /* : String */;
short int var2142 /* : Bool */;
val* var2144 /* : NativeArray[String] */;
static val* varonce2143;
static val* varonce2145;
val* var2146 /* : String */;
char* var2147 /* : NativeString */;
val* var2148 /* : String */;
val* var2149 /* : nullable Object */;
val* var2150 /* : String */;
val* var2151 /* : nullable Object */;
val* var2152 /* : String */;
val* var2153 /* : String */;
val* var2154 /* : RuntimeVariable */;
static val* varonce2155;
val* var2156 /* : String */;
char* var2157 /* : NativeString */;
val* var2158 /* : String */;
short int var2159 /* : Bool */;
val* var2161 /* : NativeArray[String] */;
static val* varonce2160;
static val* varonce2162;
val* var2163 /* : String */;
char* var2164 /* : NativeString */;
val* var2165 /* : String */;
val* var2166 /* : nullable Object */;
val* var2167 /* : String */;
val* var2168 /* : String */;
val* var2169 /* : RuntimeVariable */;
static val* varonce2170;
val* var2171 /* : String */;
char* var2172 /* : NativeString */;
val* var2173 /* : String */;
short int var2174 /* : Bool */;
static val* varonce2175;
val* var2176 /* : String */;
char* var2177 /* : NativeString */;
val* var2178 /* : String */;
short int var2179 /* : Bool */;
val* var2181 /* : NativeArray[String] */;
static val* varonce2180;
static val* varonce2182;
val* var2183 /* : String */;
char* var2184 /* : NativeString */;
val* var2185 /* : String */;
static val* varonce2186;
val* var2187 /* : String */;
char* var2188 /* : NativeString */;
val* var2189 /* : String */;
val* var2190 /* : nullable Object */;
val* var2191 /* : String */;
val* var2192 /* : String */;
static val* varonce2193;
val* var2194 /* : String */;
char* var2195 /* : NativeString */;
val* var2196 /* : String */;
short int var2197 /* : Bool */;
val* var2199 /* : NativeArray[String] */;
static val* varonce2198;
static val* varonce2200;
val* var2201 /* : String */;
char* var2202 /* : NativeString */;
val* var2203 /* : String */;
val* var2204 /* : nullable Object */;
val* var2205 /* : String */;
val* var2206 /* : String */;
val* var2207 /* : RuntimeVariable */;
static val* varonce2208;
val* var2209 /* : String */;
char* var2210 /* : NativeString */;
val* var2211 /* : String */;
short int var2212 /* : Bool */;
val* var2214 /* : NativeArray[String] */;
static val* varonce2213;
static val* varonce2215;
val* var2216 /* : String */;
char* var2217 /* : NativeString */;
val* var2218 /* : String */;
val* var2219 /* : nullable Object */;
val* var2220 /* : String */;
val* var2221 /* : nullable Object */;
val* var2222 /* : String */;
val* var2223 /* : String */;
val* var2224 /* : RuntimeVariable */;
static val* varonce2225;
val* var2226 /* : String */;
char* var2227 /* : NativeString */;
val* var2228 /* : String */;
short int var2229 /* : Bool */;
val* var2231 /* : NativeArray[String] */;
static val* varonce2230;
static val* varonce2232;
val* var2233 /* : String */;
char* var2234 /* : NativeString */;
val* var2235 /* : String */;
val* var2236 /* : nullable Object */;
val* var2237 /* : String */;
val* var2238 /* : nullable Object */;
val* var2239 /* : String */;
val* var2240 /* : String */;
val* var2241 /* : RuntimeVariable */;
static val* varonce2242;
val* var2243 /* : String */;
char* var2244 /* : NativeString */;
val* var2245 /* : String */;
short int var2246 /* : Bool */;
val* var2248 /* : NativeArray[String] */;
static val* varonce2247;
static val* varonce2249;
val* var2250 /* : String */;
char* var2251 /* : NativeString */;
val* var2252 /* : String */;
val* var2253 /* : nullable Object */;
val* var2254 /* : String */;
val* var2255 /* : String */;
val* var2256 /* : RuntimeVariable */;
static val* varonce2257;
val* var2258 /* : String */;
char* var2259 /* : NativeString */;
val* var2260 /* : String */;
short int var2261 /* : Bool */;
val* var2262 /* : nullable Object */;
static val* varonce2263;
val* var2264 /* : String */;
char* var2265 /* : NativeString */;
val* var2266 /* : String */;
short int var2267 /* : Bool */;
val* var2269 /* : NativeArray[String] */;
static val* varonce2268;
static val* varonce2270;
val* var2271 /* : String */;
char* var2272 /* : NativeString */;
val* var2273 /* : String */;
val* var2274 /* : nullable Object */;
val* var2275 /* : String */;
val* var2276 /* : nullable Object */;
val* var2277 /* : String */;
val* var2278 /* : String */;
val* var2279 /* : RuntimeVariable */;
static val* varonce2280;
val* var2281 /* : String */;
char* var2282 /* : NativeString */;
val* var2283 /* : String */;
short int var2284 /* : Bool */;
val* var2286 /* : NativeArray[String] */;
static val* varonce2285;
static val* varonce2287;
val* var2288 /* : String */;
char* var2289 /* : NativeString */;
val* var2290 /* : String */;
val* var2291 /* : nullable Object */;
val* var2292 /* : String */;
val* var2293 /* : nullable Object */;
val* var2294 /* : String */;
val* var2295 /* : String */;
val* var2296 /* : RuntimeVariable */;
static val* varonce2297;
val* var2298 /* : String */;
char* var2299 /* : NativeString */;
val* var2300 /* : String */;
short int var2301 /* : Bool */;
val* var2303 /* : NativeArray[String] */;
static val* varonce2302;
static val* varonce2304;
val* var2305 /* : String */;
char* var2306 /* : NativeString */;
val* var2307 /* : String */;
val* var2308 /* : nullable Object */;
val* var2309 /* : String */;
val* var2310 /* : nullable Object */;
val* var2311 /* : String */;
val* var2312 /* : String */;
val* var2313 /* : RuntimeVariable */;
static val* varonce2314;
val* var2315 /* : String */;
char* var2316 /* : NativeString */;
val* var2317 /* : String */;
short int var2318 /* : Bool */;
val* var2320 /* : NativeArray[String] */;
static val* varonce2319;
static val* varonce2321;
val* var2322 /* : String */;
char* var2323 /* : NativeString */;
val* var2324 /* : String */;
val* var2325 /* : nullable Object */;
val* var2326 /* : String */;
val* var2327 /* : nullable Object */;
val* var2328 /* : String */;
val* var2329 /* : String */;
val* var2330 /* : RuntimeVariable */;
static val* varonce2331;
val* var2332 /* : String */;
char* var2333 /* : NativeString */;
val* var2334 /* : String */;
short int var2335 /* : Bool */;
val* var2337 /* : NativeArray[String] */;
static val* varonce2336;
static val* varonce2338;
val* var2339 /* : String */;
char* var2340 /* : NativeString */;
val* var2341 /* : String */;
val* var2342 /* : nullable Object */;
val* var2343 /* : String */;
val* var2344 /* : nullable Object */;
val* var2345 /* : String */;
val* var2346 /* : String */;
val* var2347 /* : RuntimeVariable */;
static val* varonce2348;
val* var2349 /* : String */;
char* var2350 /* : NativeString */;
val* var2351 /* : String */;
short int var2352 /* : Bool */;
val* var2353 /* : nullable Object */;
val* var2354 /* : nullable Object */;
val* var2355 /* : RuntimeVariable */;
static val* varonce2356;
val* var2357 /* : String */;
char* var2358 /* : NativeString */;
val* var2359 /* : String */;
short int var2360 /* : Bool */;
val* var2361 /* : nullable Object */;
val* var2362 /* : nullable Object */;
val* var2363 /* : RuntimeVariable */;
val* var_res2364 /* var res: RuntimeVariable */;
val* var2366 /* : NativeArray[String] */;
static val* varonce2365;
static val* varonce2367;
val* var2368 /* : String */;
char* var2369 /* : NativeString */;
val* var2370 /* : String */;
val* var2371 /* : String */;
val* var2372 /* : String */;
val* var2373 /* : RuntimeVariable */;
static val* varonce2374;
val* var2375 /* : String */;
char* var2376 /* : NativeString */;
val* var2377 /* : String */;
short int var2378 /* : Bool */;
val* var2380 /* : NativeArray[String] */;
static val* varonce2379;
static val* varonce2381;
val* var2382 /* : String */;
char* var2383 /* : NativeString */;
val* var2384 /* : String */;
val* var2385 /* : nullable Object */;
val* var2386 /* : String */;
val* var2387 /* : nullable Object */;
val* var2388 /* : String */;
val* var2389 /* : String */;
val* var2390 /* : RuntimeVariable */;
static val* varonce2391;
val* var2392 /* : String */;
char* var2393 /* : NativeString */;
val* var2394 /* : String */;
short int var2395 /* : Bool */;
val* var2397 /* : NativeArray[String] */;
static val* varonce2396;
static val* varonce2398;
val* var2399 /* : String */;
char* var2400 /* : NativeString */;
val* var2401 /* : String */;
val* var2402 /* : nullable Object */;
val* var2403 /* : String */;
val* var2404 /* : nullable Object */;
val* var2405 /* : String */;
val* var2406 /* : String */;
val* var2407 /* : RuntimeVariable */;
static val* varonce2408;
val* var2409 /* : String */;
char* var2410 /* : NativeString */;
val* var2411 /* : String */;
short int var2412 /* : Bool */;
val* var2414 /* : NativeArray[String] */;
static val* varonce2413;
static val* varonce2415;
val* var2416 /* : String */;
char* var2417 /* : NativeString */;
val* var2418 /* : String */;
val* var2419 /* : nullable Object */;
val* var2420 /* : String */;
val* var2421 /* : nullable Object */;
val* var2422 /* : String */;
val* var2423 /* : String */;
val* var2424 /* : RuntimeVariable */;
static val* varonce2425;
val* var2426 /* : String */;
char* var2427 /* : NativeString */;
val* var2428 /* : String */;
short int var2429 /* : Bool */;
val* var2431 /* : NativeArray[String] */;
static val* varonce2430;
static val* varonce2432;
val* var2433 /* : String */;
char* var2434 /* : NativeString */;
val* var2435 /* : String */;
val* var2436 /* : nullable Object */;
val* var2437 /* : String */;
val* var2438 /* : nullable Object */;
val* var2439 /* : String */;
val* var2440 /* : String */;
val* var2441 /* : RuntimeVariable */;
static val* varonce2442;
val* var2443 /* : String */;
char* var2444 /* : NativeString */;
val* var2445 /* : String */;
short int var2446 /* : Bool */;
val* var2448 /* : NativeArray[String] */;
static val* varonce2447;
static val* varonce2449;
val* var2450 /* : String */;
char* var2451 /* : NativeString */;
val* var2452 /* : String */;
val* var2453 /* : nullable Object */;
val* var2454 /* : String */;
val* var2455 /* : String */;
val* var2456 /* : RuntimeVariable */;
static val* varonce2457;
val* var2458 /* : String */;
char* var2459 /* : NativeString */;
val* var2460 /* : String */;
short int var2461 /* : Bool */;
val* var2463 /* : NativeArray[String] */;
static val* varonce2462;
static val* varonce2464;
val* var2465 /* : String */;
char* var2466 /* : NativeString */;
val* var2467 /* : String */;
val* var2468 /* : nullable Object */;
val* var2469 /* : String */;
val* var2470 /* : String */;
val* var2471 /* : RuntimeVariable */;
static val* varonce2472;
val* var2473 /* : String */;
char* var2474 /* : NativeString */;
val* var2475 /* : String */;
short int var2476 /* : Bool */;
val* var2478 /* : NativeArray[String] */;
static val* varonce2477;
static val* varonce2479;
val* var2480 /* : String */;
char* var2481 /* : NativeString */;
val* var2482 /* : String */;
val* var2483 /* : nullable Object */;
val* var2484 /* : String */;
val* var2485 /* : String */;
val* var2486 /* : RuntimeVariable */;
static val* varonce2487;
val* var2488 /* : String */;
char* var2489 /* : NativeString */;
val* var2490 /* : String */;
short int var2491 /* : Bool */;
val* var2493 /* : NativeArray[String] */;
static val* varonce2492;
static val* varonce2494;
val* var2495 /* : String */;
char* var2496 /* : NativeString */;
val* var2497 /* : String */;
val* var2498 /* : nullable Object */;
val* var2499 /* : String */;
val* var2500 /* : String */;
val* var2501 /* : RuntimeVariable */;
static val* varonce2502;
val* var2503 /* : String */;
char* var2504 /* : NativeString */;
val* var2505 /* : String */;
short int var2506 /* : Bool */;
val* var2508 /* : NativeArray[String] */;
static val* varonce2507;
static val* varonce2509;
val* var2510 /* : String */;
char* var2511 /* : NativeString */;
val* var2512 /* : String */;
val* var2513 /* : nullable Object */;
val* var2514 /* : String */;
val* var2515 /* : String */;
val* var2516 /* : RuntimeVariable */;
static val* varonce2517;
val* var2518 /* : String */;
char* var2519 /* : NativeString */;
val* var2520 /* : String */;
short int var2521 /* : Bool */;
val* var2523 /* : NativeArray[String] */;
static val* varonce2522;
static val* varonce2524;
val* var2525 /* : String */;
char* var2526 /* : NativeString */;
val* var2527 /* : String */;
val* var2528 /* : nullable Object */;
val* var2529 /* : String */;
val* var2530 /* : String */;
val* var2531 /* : RuntimeVariable */;
static val* varonce2532;
val* var2533 /* : String */;
char* var2534 /* : NativeString */;
val* var2535 /* : String */;
short int var2536 /* : Bool */;
val* var2538 /* : NativeArray[String] */;
static val* varonce2537;
static val* varonce2539;
val* var2540 /* : String */;
char* var2541 /* : NativeString */;
val* var2542 /* : String */;
val* var2543 /* : nullable Object */;
val* var2544 /* : String */;
val* var2545 /* : String */;
val* var2546 /* : RuntimeVariable */;
static val* varonce2547;
val* var2548 /* : String */;
char* var2549 /* : NativeString */;
val* var2550 /* : String */;
short int var2551 /* : Bool */;
val* var2553 /* : NativeArray[String] */;
static val* varonce2552;
static val* varonce2554;
val* var2555 /* : String */;
char* var2556 /* : NativeString */;
val* var2557 /* : String */;
val* var2558 /* : nullable Object */;
val* var2559 /* : String */;
val* var2560 /* : nullable Object */;
val* var2561 /* : String */;
val* var2562 /* : String */;
val* var2563 /* : RuntimeVariable */;
static val* varonce2564;
val* var2565 /* : String */;
char* var2566 /* : NativeString */;
val* var2567 /* : String */;
short int var2568 /* : Bool */;
val* var2570 /* : NativeArray[String] */;
static val* varonce2569;
static val* varonce2571;
val* var2572 /* : String */;
char* var2573 /* : NativeString */;
val* var2574 /* : String */;
val* var2575 /* : nullable Object */;
val* var2576 /* : String */;
val* var2577 /* : nullable Object */;
val* var2578 /* : String */;
val* var2579 /* : String */;
val* var2580 /* : RuntimeVariable */;
static val* varonce2581;
val* var2582 /* : String */;
char* var2583 /* : NativeString */;
val* var2584 /* : String */;
short int var2585 /* : Bool */;
val* var2587 /* : NativeArray[String] */;
static val* varonce2586;
static val* varonce2588;
val* var2589 /* : String */;
char* var2590 /* : NativeString */;
val* var2591 /* : String */;
val* var2592 /* : nullable Object */;
val* var2593 /* : String */;
val* var2594 /* : nullable Object */;
val* var2595 /* : String */;
val* var2596 /* : String */;
val* var2597 /* : RuntimeVariable */;
static val* varonce2598;
val* var2599 /* : String */;
char* var2600 /* : NativeString */;
val* var2601 /* : String */;
short int var2602 /* : Bool */;
val* var2604 /* : NativeArray[String] */;
static val* varonce2603;
static val* varonce2605;
val* var2606 /* : String */;
char* var2607 /* : NativeString */;
val* var2608 /* : String */;
val* var2609 /* : nullable Object */;
val* var2610 /* : String */;
val* var2611 /* : String */;
val* var2612 /* : RuntimeVariable */;
static val* varonce2613;
val* var2614 /* : String */;
char* var2615 /* : NativeString */;
val* var2616 /* : String */;
short int var2617 /* : Bool */;
static val* varonce2618;
val* var2619 /* : String */;
char* var2620 /* : NativeString */;
val* var2621 /* : String */;
short int var2622 /* : Bool */;
val* var2624 /* : NativeArray[String] */;
static val* varonce2623;
static val* varonce2625;
val* var2626 /* : String */;
char* var2627 /* : NativeString */;
val* var2628 /* : String */;
static val* varonce2629;
val* var2630 /* : String */;
char* var2631 /* : NativeString */;
val* var2632 /* : String */;
val* var2633 /* : nullable Object */;
val* var2634 /* : String */;
val* var2635 /* : String */;
static val* varonce2636;
val* var2637 /* : String */;
char* var2638 /* : NativeString */;
val* var2639 /* : String */;
short int var2640 /* : Bool */;
val* var2642 /* : NativeArray[String] */;
static val* varonce2641;
static val* varonce2643;
val* var2644 /* : String */;
char* var2645 /* : NativeString */;
val* var2646 /* : String */;
val* var2647 /* : nullable Object */;
val* var2648 /* : String */;
val* var2649 /* : String */;
val* var2650 /* : RuntimeVariable */;
static val* varonce2651;
val* var2652 /* : String */;
char* var2653 /* : NativeString */;
val* var2654 /* : String */;
short int var2655 /* : Bool */;
val* var2657 /* : NativeArray[String] */;
static val* varonce2656;
static val* varonce2658;
val* var2659 /* : String */;
char* var2660 /* : NativeString */;
val* var2661 /* : String */;
val* var2662 /* : nullable Object */;
val* var2663 /* : String */;
val* var2664 /* : nullable Object */;
val* var2665 /* : String */;
val* var2666 /* : String */;
val* var2667 /* : RuntimeVariable */;
static val* varonce2668;
val* var2669 /* : String */;
char* var2670 /* : NativeString */;
val* var2671 /* : String */;
short int var2672 /* : Bool */;
val* var2674 /* : NativeArray[String] */;
static val* varonce2673;
static val* varonce2675;
val* var2676 /* : String */;
char* var2677 /* : NativeString */;
val* var2678 /* : String */;
val* var2679 /* : nullable Object */;
val* var2680 /* : String */;
val* var2681 /* : nullable Object */;
val* var2682 /* : String */;
val* var2683 /* : String */;
val* var2684 /* : RuntimeVariable */;
static val* varonce2685;
val* var2686 /* : String */;
char* var2687 /* : NativeString */;
val* var2688 /* : String */;
short int var2689 /* : Bool */;
val* var2691 /* : NativeArray[String] */;
static val* varonce2690;
static val* varonce2692;
val* var2693 /* : String */;
char* var2694 /* : NativeString */;
val* var2695 /* : String */;
val* var2696 /* : nullable Object */;
val* var2697 /* : String */;
val* var2698 /* : String */;
val* var2699 /* : RuntimeVariable */;
static val* varonce2700;
val* var2701 /* : String */;
char* var2702 /* : NativeString */;
val* var2703 /* : String */;
short int var2704 /* : Bool */;
val* var2705 /* : nullable Object */;
static val* varonce2706;
val* var2707 /* : String */;
char* var2708 /* : NativeString */;
val* var2709 /* : String */;
short int var2710 /* : Bool */;
val* var2712 /* : NativeArray[String] */;
static val* varonce2711;
static val* varonce2713;
val* var2714 /* : String */;
char* var2715 /* : NativeString */;
val* var2716 /* : String */;
val* var2717 /* : nullable Object */;
val* var2718 /* : String */;
val* var2719 /* : nullable Object */;
val* var2720 /* : String */;
val* var2721 /* : String */;
val* var2722 /* : RuntimeVariable */;
static val* varonce2723;
val* var2724 /* : String */;
char* var2725 /* : NativeString */;
val* var2726 /* : String */;
short int var2727 /* : Bool */;
val* var2729 /* : NativeArray[String] */;
static val* varonce2728;
static val* varonce2730;
val* var2731 /* : String */;
char* var2732 /* : NativeString */;
val* var2733 /* : String */;
val* var2734 /* : nullable Object */;
val* var2735 /* : String */;
val* var2736 /* : nullable Object */;
val* var2737 /* : String */;
val* var2738 /* : String */;
val* var2739 /* : RuntimeVariable */;
static val* varonce2740;
val* var2741 /* : String */;
char* var2742 /* : NativeString */;
val* var2743 /* : String */;
short int var2744 /* : Bool */;
val* var2746 /* : NativeArray[String] */;
static val* varonce2745;
static val* varonce2747;
val* var2748 /* : String */;
char* var2749 /* : NativeString */;
val* var2750 /* : String */;
val* var2751 /* : nullable Object */;
val* var2752 /* : String */;
val* var2753 /* : nullable Object */;
val* var2754 /* : String */;
val* var2755 /* : String */;
val* var2756 /* : RuntimeVariable */;
static val* varonce2757;
val* var2758 /* : String */;
char* var2759 /* : NativeString */;
val* var2760 /* : String */;
short int var2761 /* : Bool */;
val* var2763 /* : NativeArray[String] */;
static val* varonce2762;
static val* varonce2764;
val* var2765 /* : String */;
char* var2766 /* : NativeString */;
val* var2767 /* : String */;
val* var2768 /* : nullable Object */;
val* var2769 /* : String */;
val* var2770 /* : nullable Object */;
val* var2771 /* : String */;
val* var2772 /* : String */;
val* var2773 /* : RuntimeVariable */;
static val* varonce2774;
val* var2775 /* : String */;
char* var2776 /* : NativeString */;
val* var2777 /* : String */;
short int var2778 /* : Bool */;
val* var2780 /* : NativeArray[String] */;
static val* varonce2779;
static val* varonce2781;
val* var2782 /* : String */;
char* var2783 /* : NativeString */;
val* var2784 /* : String */;
val* var2785 /* : nullable Object */;
val* var2786 /* : String */;
val* var2787 /* : nullable Object */;
val* var2788 /* : String */;
val* var2789 /* : String */;
val* var2790 /* : RuntimeVariable */;
static val* varonce2791;
val* var2792 /* : String */;
char* var2793 /* : NativeString */;
val* var2794 /* : String */;
short int var2795 /* : Bool */;
val* var2796 /* : nullable Object */;
val* var2797 /* : nullable Object */;
val* var2798 /* : RuntimeVariable */;
static val* varonce2799;
val* var2800 /* : String */;
char* var2801 /* : NativeString */;
val* var2802 /* : String */;
short int var2803 /* : Bool */;
val* var2804 /* : nullable Object */;
val* var2805 /* : nullable Object */;
val* var2806 /* : RuntimeVariable */;
val* var_res2807 /* var res: RuntimeVariable */;
val* var2809 /* : NativeArray[String] */;
static val* varonce2808;
static val* varonce2810;
val* var2811 /* : String */;
char* var2812 /* : NativeString */;
val* var2813 /* : String */;
val* var2814 /* : String */;
val* var2815 /* : String */;
val* var2816 /* : RuntimeVariable */;
static val* varonce2817;
val* var2818 /* : String */;
char* var2819 /* : NativeString */;
val* var2820 /* : String */;
short int var2821 /* : Bool */;
val* var2823 /* : NativeArray[String] */;
static val* varonce2822;
static val* varonce2824;
val* var2825 /* : String */;
char* var2826 /* : NativeString */;
val* var2827 /* : String */;
val* var2828 /* : nullable Object */;
val* var2829 /* : String */;
val* var2830 /* : nullable Object */;
val* var2831 /* : String */;
val* var2832 /* : String */;
val* var2833 /* : RuntimeVariable */;
static val* varonce2834;
val* var2835 /* : String */;
char* var2836 /* : NativeString */;
val* var2837 /* : String */;
short int var2838 /* : Bool */;
val* var2840 /* : NativeArray[String] */;
static val* varonce2839;
static val* varonce2841;
val* var2842 /* : String */;
char* var2843 /* : NativeString */;
val* var2844 /* : String */;
val* var2845 /* : nullable Object */;
val* var2846 /* : String */;
val* var2847 /* : nullable Object */;
val* var2848 /* : String */;
val* var2849 /* : String */;
val* var2850 /* : RuntimeVariable */;
static val* varonce2851;
val* var2852 /* : String */;
char* var2853 /* : NativeString */;
val* var2854 /* : String */;
short int var2855 /* : Bool */;
val* var2857 /* : NativeArray[String] */;
static val* varonce2856;
static val* varonce2858;
val* var2859 /* : String */;
char* var2860 /* : NativeString */;
val* var2861 /* : String */;
val* var2862 /* : nullable Object */;
val* var2863 /* : String */;
val* var2864 /* : nullable Object */;
val* var2865 /* : String */;
val* var2866 /* : String */;
val* var2867 /* : RuntimeVariable */;
static val* varonce2868;
val* var2869 /* : String */;
char* var2870 /* : NativeString */;
val* var2871 /* : String */;
short int var2872 /* : Bool */;
val* var2874 /* : NativeArray[String] */;
static val* varonce2873;
static val* varonce2875;
val* var2876 /* : String */;
char* var2877 /* : NativeString */;
val* var2878 /* : String */;
val* var2879 /* : nullable Object */;
val* var2880 /* : String */;
val* var2881 /* : nullable Object */;
val* var2882 /* : String */;
val* var2883 /* : String */;
val* var2884 /* : RuntimeVariable */;
static val* varonce2885;
val* var2886 /* : String */;
char* var2887 /* : NativeString */;
val* var2888 /* : String */;
short int var2889 /* : Bool */;
val* var2891 /* : NativeArray[String] */;
static val* varonce2890;
static val* varonce2892;
val* var2893 /* : String */;
char* var2894 /* : NativeString */;
val* var2895 /* : String */;
val* var2896 /* : nullable Object */;
val* var2897 /* : String */;
val* var2898 /* : String */;
val* var2899 /* : RuntimeVariable */;
static val* varonce2900;
val* var2901 /* : String */;
char* var2902 /* : NativeString */;
val* var2903 /* : String */;
short int var2904 /* : Bool */;
val* var2906 /* : NativeArray[String] */;
static val* varonce2905;
static val* varonce2907;
val* var2908 /* : String */;
char* var2909 /* : NativeString */;
val* var2910 /* : String */;
val* var2911 /* : nullable Object */;
val* var2912 /* : String */;
val* var2913 /* : String */;
val* var2914 /* : RuntimeVariable */;
static val* varonce2915;
val* var2916 /* : String */;
char* var2917 /* : NativeString */;
val* var2918 /* : String */;
short int var2919 /* : Bool */;
val* var2921 /* : NativeArray[String] */;
static val* varonce2920;
static val* varonce2922;
val* var2923 /* : String */;
char* var2924 /* : NativeString */;
val* var2925 /* : String */;
val* var2926 /* : nullable Object */;
val* var2927 /* : String */;
val* var2928 /* : String */;
val* var2929 /* : RuntimeVariable */;
static val* varonce2930;
val* var2931 /* : String */;
char* var2932 /* : NativeString */;
val* var2933 /* : String */;
short int var2934 /* : Bool */;
val* var2936 /* : NativeArray[String] */;
static val* varonce2935;
static val* varonce2937;
val* var2938 /* : String */;
char* var2939 /* : NativeString */;
val* var2940 /* : String */;
val* var2941 /* : nullable Object */;
val* var2942 /* : String */;
val* var2943 /* : String */;
val* var2944 /* : RuntimeVariable */;
static val* varonce2945;
val* var2946 /* : String */;
char* var2947 /* : NativeString */;
val* var2948 /* : String */;
short int var2949 /* : Bool */;
val* var2951 /* : NativeArray[String] */;
static val* varonce2950;
static val* varonce2952;
val* var2953 /* : String */;
char* var2954 /* : NativeString */;
val* var2955 /* : String */;
val* var2956 /* : nullable Object */;
val* var2957 /* : String */;
val* var2958 /* : String */;
val* var2959 /* : RuntimeVariable */;
static val* varonce2960;
val* var2961 /* : String */;
char* var2962 /* : NativeString */;
val* var2963 /* : String */;
short int var2964 /* : Bool */;
val* var2966 /* : NativeArray[String] */;
static val* varonce2965;
static val* varonce2967;
val* var2968 /* : String */;
char* var2969 /* : NativeString */;
val* var2970 /* : String */;
val* var2971 /* : nullable Object */;
val* var2972 /* : String */;
val* var2973 /* : String */;
val* var2974 /* : RuntimeVariable */;
static val* varonce2975;
val* var2976 /* : String */;
char* var2977 /* : NativeString */;
val* var2978 /* : String */;
short int var2979 /* : Bool */;
val* var2981 /* : NativeArray[String] */;
static val* varonce2980;
static val* varonce2982;
val* var2983 /* : String */;
char* var2984 /* : NativeString */;
val* var2985 /* : String */;
val* var2986 /* : nullable Object */;
val* var2987 /* : String */;
val* var2988 /* : String */;
val* var2989 /* : RuntimeVariable */;
static val* varonce2990;
val* var2991 /* : String */;
char* var2992 /* : NativeString */;
val* var2993 /* : String */;
short int var2994 /* : Bool */;
val* var2996 /* : NativeArray[String] */;
static val* varonce2995;
static val* varonce2997;
val* var2998 /* : String */;
char* var2999 /* : NativeString */;
val* var3000 /* : String */;
val* var3001 /* : nullable Object */;
val* var3002 /* : String */;
val* var3003 /* : nullable Object */;
val* var3004 /* : String */;
val* var3005 /* : String */;
val* var3006 /* : RuntimeVariable */;
static val* varonce3007;
val* var3008 /* : String */;
char* var3009 /* : NativeString */;
val* var3010 /* : String */;
short int var3011 /* : Bool */;
val* var3013 /* : NativeArray[String] */;
static val* varonce3012;
static val* varonce3014;
val* var3015 /* : String */;
char* var3016 /* : NativeString */;
val* var3017 /* : String */;
val* var3018 /* : nullable Object */;
val* var3019 /* : String */;
val* var3020 /* : nullable Object */;
val* var3021 /* : String */;
val* var3022 /* : String */;
val* var3023 /* : RuntimeVariable */;
static val* varonce3024;
val* var3025 /* : String */;
char* var3026 /* : NativeString */;
val* var3027 /* : String */;
short int var3028 /* : Bool */;
val* var3030 /* : NativeArray[String] */;
static val* varonce3029;
static val* varonce3031;
val* var3032 /* : String */;
char* var3033 /* : NativeString */;
val* var3034 /* : String */;
val* var3035 /* : nullable Object */;
val* var3036 /* : String */;
val* var3037 /* : nullable Object */;
val* var3038 /* : String */;
val* var3039 /* : String */;
val* var3040 /* : RuntimeVariable */;
static val* varonce3041;
val* var3042 /* : String */;
char* var3043 /* : NativeString */;
val* var3044 /* : String */;
short int var3045 /* : Bool */;
val* var3047 /* : NativeArray[String] */;
static val* varonce3046;
static val* varonce3048;
val* var3049 /* : String */;
char* var3050 /* : NativeString */;
val* var3051 /* : String */;
val* var3052 /* : nullable Object */;
val* var3053 /* : String */;
val* var3054 /* : String */;
val* var3055 /* : RuntimeVariable */;
static val* varonce3056;
val* var3057 /* : String */;
char* var3058 /* : NativeString */;
val* var3059 /* : String */;
short int var3060 /* : Bool */;
static val* varonce3061;
val* var3062 /* : String */;
char* var3063 /* : NativeString */;
val* var3064 /* : String */;
short int var3065 /* : Bool */;
val* var3067 /* : NativeArray[String] */;
static val* varonce3066;
static val* varonce3068;
val* var3069 /* : String */;
char* var3070 /* : NativeString */;
val* var3071 /* : String */;
static val* varonce3072;
val* var3073 /* : String */;
char* var3074 /* : NativeString */;
val* var3075 /* : String */;
val* var3076 /* : nullable Object */;
val* var3077 /* : String */;
val* var3078 /* : String */;
static val* varonce3079;
val* var3080 /* : String */;
char* var3081 /* : NativeString */;
val* var3082 /* : String */;
short int var3083 /* : Bool */;
val* var3085 /* : NativeArray[String] */;
static val* varonce3084;
static val* varonce3086;
val* var3087 /* : String */;
char* var3088 /* : NativeString */;
val* var3089 /* : String */;
val* var3090 /* : nullable Object */;
val* var3091 /* : String */;
val* var3092 /* : String */;
val* var3093 /* : RuntimeVariable */;
static val* varonce3094;
val* var3095 /* : String */;
char* var3096 /* : NativeString */;
val* var3097 /* : String */;
short int var3098 /* : Bool */;
val* var3100 /* : NativeArray[String] */;
static val* varonce3099;
static val* varonce3101;
val* var3102 /* : String */;
char* var3103 /* : NativeString */;
val* var3104 /* : String */;
val* var3105 /* : nullable Object */;
val* var3106 /* : String */;
val* var3107 /* : nullable Object */;
val* var3108 /* : String */;
val* var3109 /* : String */;
val* var3110 /* : RuntimeVariable */;
static val* varonce3111;
val* var3112 /* : String */;
char* var3113 /* : NativeString */;
val* var3114 /* : String */;
short int var3115 /* : Bool */;
val* var3117 /* : NativeArray[String] */;
static val* varonce3116;
static val* varonce3118;
val* var3119 /* : String */;
char* var3120 /* : NativeString */;
val* var3121 /* : String */;
val* var3122 /* : nullable Object */;
val* var3123 /* : String */;
val* var3124 /* : nullable Object */;
val* var3125 /* : String */;
val* var3126 /* : String */;
val* var3127 /* : RuntimeVariable */;
static val* varonce3128;
val* var3129 /* : String */;
char* var3130 /* : NativeString */;
val* var3131 /* : String */;
short int var3132 /* : Bool */;
val* var3134 /* : NativeArray[String] */;
static val* varonce3133;
static val* varonce3135;
val* var3136 /* : String */;
char* var3137 /* : NativeString */;
val* var3138 /* : String */;
val* var3139 /* : nullable Object */;
val* var3140 /* : String */;
val* var3141 /* : String */;
val* var3142 /* : RuntimeVariable */;
static val* varonce3143;
val* var3144 /* : String */;
char* var3145 /* : NativeString */;
val* var3146 /* : String */;
short int var3147 /* : Bool */;
val* var3148 /* : nullable Object */;
static val* varonce3149;
val* var3150 /* : String */;
char* var3151 /* : NativeString */;
val* var3152 /* : String */;
short int var3153 /* : Bool */;
val* var3155 /* : NativeArray[String] */;
static val* varonce3154;
static val* varonce3156;
val* var3157 /* : String */;
char* var3158 /* : NativeString */;
val* var3159 /* : String */;
val* var3160 /* : nullable Object */;
val* var3161 /* : String */;
val* var3162 /* : nullable Object */;
val* var3163 /* : String */;
val* var3164 /* : String */;
val* var3165 /* : RuntimeVariable */;
static val* varonce3166;
val* var3167 /* : String */;
char* var3168 /* : NativeString */;
val* var3169 /* : String */;
short int var3170 /* : Bool */;
val* var3172 /* : NativeArray[String] */;
static val* varonce3171;
static val* varonce3173;
val* var3174 /* : String */;
char* var3175 /* : NativeString */;
val* var3176 /* : String */;
val* var3177 /* : nullable Object */;
val* var3178 /* : String */;
val* var3179 /* : nullable Object */;
val* var3180 /* : String */;
val* var3181 /* : String */;
val* var3182 /* : RuntimeVariable */;
static val* varonce3183;
val* var3184 /* : String */;
char* var3185 /* : NativeString */;
val* var3186 /* : String */;
short int var3187 /* : Bool */;
val* var3189 /* : NativeArray[String] */;
static val* varonce3188;
static val* varonce3190;
val* var3191 /* : String */;
char* var3192 /* : NativeString */;
val* var3193 /* : String */;
val* var3194 /* : nullable Object */;
val* var3195 /* : String */;
val* var3196 /* : nullable Object */;
val* var3197 /* : String */;
val* var3198 /* : String */;
val* var3199 /* : RuntimeVariable */;
static val* varonce3200;
val* var3201 /* : String */;
char* var3202 /* : NativeString */;
val* var3203 /* : String */;
short int var3204 /* : Bool */;
val* var3206 /* : NativeArray[String] */;
static val* varonce3205;
static val* varonce3207;
val* var3208 /* : String */;
char* var3209 /* : NativeString */;
val* var3210 /* : String */;
val* var3211 /* : nullable Object */;
val* var3212 /* : String */;
val* var3213 /* : nullable Object */;
val* var3214 /* : String */;
val* var3215 /* : String */;
val* var3216 /* : RuntimeVariable */;
static val* varonce3217;
val* var3218 /* : String */;
char* var3219 /* : NativeString */;
val* var3220 /* : String */;
short int var3221 /* : Bool */;
val* var3223 /* : NativeArray[String] */;
static val* varonce3222;
static val* varonce3224;
val* var3225 /* : String */;
char* var3226 /* : NativeString */;
val* var3227 /* : String */;
val* var3228 /* : nullable Object */;
val* var3229 /* : String */;
val* var3230 /* : nullable Object */;
val* var3231 /* : String */;
val* var3232 /* : String */;
val* var3233 /* : RuntimeVariable */;
static val* varonce3234;
val* var3235 /* : String */;
char* var3236 /* : NativeString */;
val* var3237 /* : String */;
short int var3238 /* : Bool */;
val* var3239 /* : nullable Object */;
val* var3240 /* : nullable Object */;
val* var3241 /* : RuntimeVariable */;
static val* varonce3242;
val* var3243 /* : String */;
char* var3244 /* : NativeString */;
val* var3245 /* : String */;
short int var3246 /* : Bool */;
val* var3247 /* : nullable Object */;
val* var3248 /* : nullable Object */;
val* var3249 /* : RuntimeVariable */;
val* var_res3250 /* var res: RuntimeVariable */;
val* var3252 /* : NativeArray[String] */;
static val* varonce3251;
static val* varonce3253;
val* var3254 /* : String */;
char* var3255 /* : NativeString */;
val* var3256 /* : String */;
val* var3257 /* : String */;
val* var3258 /* : String */;
val* var3259 /* : RuntimeVariable */;
static val* varonce3260;
val* var3261 /* : String */;
char* var3262 /* : NativeString */;
val* var3263 /* : String */;
short int var3264 /* : Bool */;
val* var3266 /* : NativeArray[String] */;
static val* varonce3265;
static val* varonce3267;
val* var3268 /* : String */;
char* var3269 /* : NativeString */;
val* var3270 /* : String */;
val* var3271 /* : nullable Object */;
val* var3272 /* : String */;
val* var3273 /* : nullable Object */;
val* var3274 /* : String */;
val* var3275 /* : String */;
val* var3276 /* : RuntimeVariable */;
static val* varonce3277;
val* var3278 /* : String */;
char* var3279 /* : NativeString */;
val* var3280 /* : String */;
short int var3281 /* : Bool */;
val* var3283 /* : NativeArray[String] */;
static val* varonce3282;
static val* varonce3284;
val* var3285 /* : String */;
char* var3286 /* : NativeString */;
val* var3287 /* : String */;
val* var3288 /* : nullable Object */;
val* var3289 /* : String */;
val* var3290 /* : nullable Object */;
val* var3291 /* : String */;
val* var3292 /* : String */;
val* var3293 /* : RuntimeVariable */;
static val* varonce3294;
val* var3295 /* : String */;
char* var3296 /* : NativeString */;
val* var3297 /* : String */;
short int var3298 /* : Bool */;
val* var3300 /* : NativeArray[String] */;
static val* varonce3299;
static val* varonce3301;
val* var3302 /* : String */;
char* var3303 /* : NativeString */;
val* var3304 /* : String */;
val* var3305 /* : nullable Object */;
val* var3306 /* : String */;
val* var3307 /* : nullable Object */;
val* var3308 /* : String */;
val* var3309 /* : String */;
val* var3310 /* : RuntimeVariable */;
static val* varonce3311;
val* var3312 /* : String */;
char* var3313 /* : NativeString */;
val* var3314 /* : String */;
short int var3315 /* : Bool */;
val* var3317 /* : NativeArray[String] */;
static val* varonce3316;
static val* varonce3318;
val* var3319 /* : String */;
char* var3320 /* : NativeString */;
val* var3321 /* : String */;
val* var3322 /* : nullable Object */;
val* var3323 /* : String */;
val* var3324 /* : nullable Object */;
val* var3325 /* : String */;
val* var3326 /* : String */;
val* var3327 /* : RuntimeVariable */;
static val* varonce3328;
val* var3329 /* : String */;
char* var3330 /* : NativeString */;
val* var3331 /* : String */;
short int var3332 /* : Bool */;
val* var3334 /* : NativeArray[String] */;
static val* varonce3333;
static val* varonce3335;
val* var3336 /* : String */;
char* var3337 /* : NativeString */;
val* var3338 /* : String */;
val* var3339 /* : nullable Object */;
val* var3340 /* : String */;
val* var3341 /* : String */;
val* var3342 /* : RuntimeVariable */;
static val* varonce3343;
val* var3344 /* : String */;
char* var3345 /* : NativeString */;
val* var3346 /* : String */;
short int var3347 /* : Bool */;
val* var3349 /* : NativeArray[String] */;
static val* varonce3348;
static val* varonce3350;
val* var3351 /* : String */;
char* var3352 /* : NativeString */;
val* var3353 /* : String */;
val* var3354 /* : nullable Object */;
val* var3355 /* : String */;
val* var3356 /* : String */;
val* var3357 /* : RuntimeVariable */;
static val* varonce3358;
val* var3359 /* : String */;
char* var3360 /* : NativeString */;
val* var3361 /* : String */;
short int var3362 /* : Bool */;
val* var3364 /* : NativeArray[String] */;
static val* varonce3363;
static val* varonce3365;
val* var3366 /* : String */;
char* var3367 /* : NativeString */;
val* var3368 /* : String */;
val* var3369 /* : nullable Object */;
val* var3370 /* : String */;
val* var3371 /* : String */;
val* var3372 /* : RuntimeVariable */;
static val* varonce3373;
val* var3374 /* : String */;
char* var3375 /* : NativeString */;
val* var3376 /* : String */;
short int var3377 /* : Bool */;
val* var3379 /* : NativeArray[String] */;
static val* varonce3378;
static val* varonce3380;
val* var3381 /* : String */;
char* var3382 /* : NativeString */;
val* var3383 /* : String */;
val* var3384 /* : nullable Object */;
val* var3385 /* : String */;
val* var3386 /* : String */;
val* var3387 /* : RuntimeVariable */;
static val* varonce3388;
val* var3389 /* : String */;
char* var3390 /* : NativeString */;
val* var3391 /* : String */;
short int var3392 /* : Bool */;
val* var3394 /* : NativeArray[String] */;
static val* varonce3393;
static val* varonce3395;
val* var3396 /* : String */;
char* var3397 /* : NativeString */;
val* var3398 /* : String */;
val* var3399 /* : nullable Object */;
val* var3400 /* : String */;
val* var3401 /* : String */;
val* var3402 /* : RuntimeVariable */;
static val* varonce3403;
val* var3404 /* : String */;
char* var3405 /* : NativeString */;
val* var3406 /* : String */;
short int var3407 /* : Bool */;
val* var3409 /* : NativeArray[String] */;
static val* varonce3408;
static val* varonce3410;
val* var3411 /* : String */;
char* var3412 /* : NativeString */;
val* var3413 /* : String */;
val* var3414 /* : nullable Object */;
val* var3415 /* : String */;
val* var3416 /* : String */;
val* var3417 /* : RuntimeVariable */;
static val* varonce3418;
val* var3419 /* : String */;
char* var3420 /* : NativeString */;
val* var3421 /* : String */;
short int var3422 /* : Bool */;
val* var3424 /* : NativeArray[String] */;
static val* varonce3423;
static val* varonce3425;
val* var3426 /* : String */;
char* var3427 /* : NativeString */;
val* var3428 /* : String */;
val* var3429 /* : nullable Object */;
val* var3430 /* : String */;
val* var3431 /* : String */;
val* var3432 /* : RuntimeVariable */;
static val* varonce3433;
val* var3434 /* : String */;
char* var3435 /* : NativeString */;
val* var3436 /* : String */;
short int var3437 /* : Bool */;
val* var3439 /* : NativeArray[String] */;
static val* varonce3438;
static val* varonce3440;
val* var3441 /* : String */;
char* var3442 /* : NativeString */;
val* var3443 /* : String */;
val* var3444 /* : nullable Object */;
val* var3445 /* : String */;
val* var3446 /* : nullable Object */;
val* var3447 /* : String */;
val* var3448 /* : String */;
val* var3449 /* : RuntimeVariable */;
static val* varonce3450;
val* var3451 /* : String */;
char* var3452 /* : NativeString */;
val* var3453 /* : String */;
short int var3454 /* : Bool */;
val* var3456 /* : NativeArray[String] */;
static val* varonce3455;
static val* varonce3457;
val* var3458 /* : String */;
char* var3459 /* : NativeString */;
val* var3460 /* : String */;
val* var3461 /* : nullable Object */;
val* var3462 /* : String */;
val* var3463 /* : nullable Object */;
val* var3464 /* : String */;
val* var3465 /* : String */;
val* var3466 /* : RuntimeVariable */;
static val* varonce3467;
val* var3468 /* : String */;
char* var3469 /* : NativeString */;
val* var3470 /* : String */;
short int var3471 /* : Bool */;
val* var3473 /* : NativeArray[String] */;
static val* varonce3472;
static val* varonce3474;
val* var3475 /* : String */;
char* var3476 /* : NativeString */;
val* var3477 /* : String */;
val* var3478 /* : nullable Object */;
val* var3479 /* : String */;
val* var3480 /* : nullable Object */;
val* var3481 /* : String */;
val* var3482 /* : String */;
val* var3483 /* : RuntimeVariable */;
static val* varonce3484;
val* var3485 /* : String */;
char* var3486 /* : NativeString */;
val* var3487 /* : String */;
short int var3488 /* : Bool */;
val* var3490 /* : NativeArray[String] */;
static val* varonce3489;
static val* varonce3491;
val* var3492 /* : String */;
char* var3493 /* : NativeString */;
val* var3494 /* : String */;
val* var3495 /* : nullable Object */;
val* var3496 /* : String */;
val* var3497 /* : String */;
val* var3498 /* : RuntimeVariable */;
static val* varonce3499;
val* var3500 /* : String */;
char* var3501 /* : NativeString */;
val* var3502 /* : String */;
short int var3503 /* : Bool */;
static val* varonce3504;
val* var3505 /* : String */;
char* var3506 /* : NativeString */;
val* var3507 /* : String */;
short int var3508 /* : Bool */;
val* var3510 /* : NativeArray[String] */;
static val* varonce3509;
static val* varonce3511;
val* var3512 /* : String */;
char* var3513 /* : NativeString */;
val* var3514 /* : String */;
static val* varonce3515;
val* var3516 /* : String */;
char* var3517 /* : NativeString */;
val* var3518 /* : String */;
val* var3519 /* : nullable Object */;
val* var3520 /* : String */;
val* var3521 /* : String */;
static val* varonce3522;
val* var3523 /* : String */;
char* var3524 /* : NativeString */;
val* var3525 /* : String */;
short int var3526 /* : Bool */;
val* var3528 /* : NativeArray[String] */;
static val* varonce3527;
static val* varonce3529;
val* var3530 /* : String */;
char* var3531 /* : NativeString */;
val* var3532 /* : String */;
val* var3533 /* : nullable Object */;
val* var3534 /* : String */;
val* var3535 /* : String */;
val* var3536 /* : RuntimeVariable */;
static val* varonce3537;
val* var3538 /* : String */;
char* var3539 /* : NativeString */;
val* var3540 /* : String */;
short int var3541 /* : Bool */;
val* var3543 /* : NativeArray[String] */;
static val* varonce3542;
static val* varonce3544;
val* var3545 /* : String */;
char* var3546 /* : NativeString */;
val* var3547 /* : String */;
val* var3548 /* : nullable Object */;
val* var3549 /* : String */;
val* var3550 /* : nullable Object */;
val* var3551 /* : String */;
val* var3552 /* : String */;
val* var3553 /* : RuntimeVariable */;
static val* varonce3554;
val* var3555 /* : String */;
char* var3556 /* : NativeString */;
val* var3557 /* : String */;
short int var3558 /* : Bool */;
val* var3560 /* : NativeArray[String] */;
static val* varonce3559;
static val* varonce3561;
val* var3562 /* : String */;
char* var3563 /* : NativeString */;
val* var3564 /* : String */;
val* var3565 /* : nullable Object */;
val* var3566 /* : String */;
val* var3567 /* : nullable Object */;
val* var3568 /* : String */;
val* var3569 /* : String */;
val* var3570 /* : RuntimeVariable */;
static val* varonce3571;
val* var3572 /* : String */;
char* var3573 /* : NativeString */;
val* var3574 /* : String */;
short int var3575 /* : Bool */;
val* var3577 /* : NativeArray[String] */;
static val* varonce3576;
static val* varonce3578;
val* var3579 /* : String */;
char* var3580 /* : NativeString */;
val* var3581 /* : String */;
val* var3582 /* : nullable Object */;
val* var3583 /* : String */;
val* var3584 /* : String */;
val* var3585 /* : RuntimeVariable */;
static val* varonce3586;
val* var3587 /* : String */;
char* var3588 /* : NativeString */;
val* var3589 /* : String */;
short int var3590 /* : Bool */;
val* var3591 /* : nullable Object */;
static val* varonce3592;
val* var3593 /* : String */;
char* var3594 /* : NativeString */;
val* var3595 /* : String */;
short int var3596 /* : Bool */;
val* var3598 /* : NativeArray[String] */;
static val* varonce3597;
static val* varonce3599;
val* var3600 /* : String */;
char* var3601 /* : NativeString */;
val* var3602 /* : String */;
val* var3603 /* : nullable Object */;
val* var3604 /* : String */;
val* var3605 /* : nullable Object */;
val* var3606 /* : String */;
val* var3607 /* : String */;
val* var3608 /* : RuntimeVariable */;
static val* varonce3609;
val* var3610 /* : String */;
char* var3611 /* : NativeString */;
val* var3612 /* : String */;
short int var3613 /* : Bool */;
val* var3615 /* : NativeArray[String] */;
static val* varonce3614;
static val* varonce3616;
val* var3617 /* : String */;
char* var3618 /* : NativeString */;
val* var3619 /* : String */;
val* var3620 /* : nullable Object */;
val* var3621 /* : String */;
val* var3622 /* : nullable Object */;
val* var3623 /* : String */;
val* var3624 /* : String */;
val* var3625 /* : RuntimeVariable */;
static val* varonce3626;
val* var3627 /* : String */;
char* var3628 /* : NativeString */;
val* var3629 /* : String */;
short int var3630 /* : Bool */;
val* var3632 /* : NativeArray[String] */;
static val* varonce3631;
static val* varonce3633;
val* var3634 /* : String */;
char* var3635 /* : NativeString */;
val* var3636 /* : String */;
val* var3637 /* : nullable Object */;
val* var3638 /* : String */;
val* var3639 /* : nullable Object */;
val* var3640 /* : String */;
val* var3641 /* : String */;
val* var3642 /* : RuntimeVariable */;
static val* varonce3643;
val* var3644 /* : String */;
char* var3645 /* : NativeString */;
val* var3646 /* : String */;
short int var3647 /* : Bool */;
val* var3649 /* : NativeArray[String] */;
static val* varonce3648;
static val* varonce3650;
val* var3651 /* : String */;
char* var3652 /* : NativeString */;
val* var3653 /* : String */;
val* var3654 /* : nullable Object */;
val* var3655 /* : String */;
val* var3656 /* : nullable Object */;
val* var3657 /* : String */;
val* var3658 /* : String */;
val* var3659 /* : RuntimeVariable */;
static val* varonce3660;
val* var3661 /* : String */;
char* var3662 /* : NativeString */;
val* var3663 /* : String */;
short int var3664 /* : Bool */;
val* var3666 /* : NativeArray[String] */;
static val* varonce3665;
static val* varonce3667;
val* var3668 /* : String */;
char* var3669 /* : NativeString */;
val* var3670 /* : String */;
val* var3671 /* : nullable Object */;
val* var3672 /* : String */;
val* var3673 /* : nullable Object */;
val* var3674 /* : String */;
val* var3675 /* : String */;
val* var3676 /* : RuntimeVariable */;
static val* varonce3677;
val* var3678 /* : String */;
char* var3679 /* : NativeString */;
val* var3680 /* : String */;
short int var3681 /* : Bool */;
val* var3682 /* : nullable Object */;
val* var3683 /* : nullable Object */;
val* var3684 /* : RuntimeVariable */;
static val* varonce3685;
val* var3686 /* : String */;
char* var3687 /* : NativeString */;
val* var3688 /* : String */;
short int var3689 /* : Bool */;
val* var3690 /* : nullable Object */;
val* var3691 /* : nullable Object */;
val* var3692 /* : RuntimeVariable */;
val* var_res3693 /* var res: RuntimeVariable */;
val* var3695 /* : NativeArray[String] */;
static val* varonce3694;
static val* varonce3696;
val* var3697 /* : String */;
char* var3698 /* : NativeString */;
val* var3699 /* : String */;
val* var3700 /* : String */;
val* var3701 /* : String */;
val* var3702 /* : RuntimeVariable */;
static val* varonce3703;
val* var3704 /* : String */;
char* var3705 /* : NativeString */;
val* var3706 /* : String */;
short int var3707 /* : Bool */;
val* var3709 /* : NativeArray[String] */;
static val* varonce3708;
static val* varonce3710;
val* var3711 /* : String */;
char* var3712 /* : NativeString */;
val* var3713 /* : String */;
val* var3714 /* : nullable Object */;
val* var3715 /* : String */;
val* var3716 /* : nullable Object */;
val* var3717 /* : String */;
val* var3718 /* : String */;
val* var3719 /* : RuntimeVariable */;
static val* varonce3720;
val* var3721 /* : String */;
char* var3722 /* : NativeString */;
val* var3723 /* : String */;
short int var3724 /* : Bool */;
val* var3726 /* : NativeArray[String] */;
static val* varonce3725;
static val* varonce3727;
val* var3728 /* : String */;
char* var3729 /* : NativeString */;
val* var3730 /* : String */;
val* var3731 /* : nullable Object */;
val* var3732 /* : String */;
val* var3733 /* : nullable Object */;
val* var3734 /* : String */;
val* var3735 /* : String */;
val* var3736 /* : RuntimeVariable */;
static val* varonce3737;
val* var3738 /* : String */;
char* var3739 /* : NativeString */;
val* var3740 /* : String */;
short int var3741 /* : Bool */;
val* var3743 /* : NativeArray[String] */;
static val* varonce3742;
static val* varonce3744;
val* var3745 /* : String */;
char* var3746 /* : NativeString */;
val* var3747 /* : String */;
val* var3748 /* : nullable Object */;
val* var3749 /* : String */;
val* var3750 /* : nullable Object */;
val* var3751 /* : String */;
val* var3752 /* : String */;
val* var3753 /* : RuntimeVariable */;
static val* varonce3754;
val* var3755 /* : String */;
char* var3756 /* : NativeString */;
val* var3757 /* : String */;
short int var3758 /* : Bool */;
val* var3760 /* : NativeArray[String] */;
static val* varonce3759;
static val* varonce3761;
val* var3762 /* : String */;
char* var3763 /* : NativeString */;
val* var3764 /* : String */;
val* var3765 /* : nullable Object */;
val* var3766 /* : String */;
val* var3767 /* : nullable Object */;
val* var3768 /* : String */;
val* var3769 /* : String */;
val* var3770 /* : RuntimeVariable */;
static val* varonce3771;
val* var3772 /* : String */;
char* var3773 /* : NativeString */;
val* var3774 /* : String */;
short int var3775 /* : Bool */;
val* var3777 /* : NativeArray[String] */;
static val* varonce3776;
static val* varonce3778;
val* var3779 /* : String */;
char* var3780 /* : NativeString */;
val* var3781 /* : String */;
val* var3782 /* : nullable Object */;
val* var3783 /* : String */;
val* var3784 /* : String */;
val* var3785 /* : RuntimeVariable */;
static val* varonce3786;
val* var3787 /* : String */;
char* var3788 /* : NativeString */;
val* var3789 /* : String */;
short int var3790 /* : Bool */;
val* var3792 /* : NativeArray[String] */;
static val* varonce3791;
static val* varonce3793;
val* var3794 /* : String */;
char* var3795 /* : NativeString */;
val* var3796 /* : String */;
val* var3797 /* : nullable Object */;
val* var3798 /* : String */;
val* var3799 /* : String */;
val* var3800 /* : RuntimeVariable */;
static val* varonce3801;
val* var3802 /* : String */;
char* var3803 /* : NativeString */;
val* var3804 /* : String */;
short int var3805 /* : Bool */;
val* var3807 /* : NativeArray[String] */;
static val* varonce3806;
static val* varonce3808;
val* var3809 /* : String */;
char* var3810 /* : NativeString */;
val* var3811 /* : String */;
val* var3812 /* : nullable Object */;
val* var3813 /* : String */;
val* var3814 /* : String */;
val* var3815 /* : RuntimeVariable */;
static val* varonce3816;
val* var3817 /* : String */;
char* var3818 /* : NativeString */;
val* var3819 /* : String */;
short int var3820 /* : Bool */;
val* var3822 /* : NativeArray[String] */;
static val* varonce3821;
static val* varonce3823;
val* var3824 /* : String */;
char* var3825 /* : NativeString */;
val* var3826 /* : String */;
val* var3827 /* : nullable Object */;
val* var3828 /* : String */;
val* var3829 /* : String */;
val* var3830 /* : RuntimeVariable */;
static val* varonce3831;
val* var3832 /* : String */;
char* var3833 /* : NativeString */;
val* var3834 /* : String */;
short int var3835 /* : Bool */;
val* var3837 /* : NativeArray[String] */;
static val* varonce3836;
static val* varonce3838;
val* var3839 /* : String */;
char* var3840 /* : NativeString */;
val* var3841 /* : String */;
val* var3842 /* : nullable Object */;
val* var3843 /* : String */;
val* var3844 /* : String */;
val* var3845 /* : RuntimeVariable */;
static val* varonce3846;
val* var3847 /* : String */;
char* var3848 /* : NativeString */;
val* var3849 /* : String */;
short int var3850 /* : Bool */;
val* var3852 /* : NativeArray[String] */;
static val* varonce3851;
static val* varonce3853;
val* var3854 /* : String */;
char* var3855 /* : NativeString */;
val* var3856 /* : String */;
val* var3857 /* : nullable Object */;
val* var3858 /* : String */;
val* var3859 /* : String */;
val* var3860 /* : RuntimeVariable */;
static val* varonce3861;
val* var3862 /* : String */;
char* var3863 /* : NativeString */;
val* var3864 /* : String */;
short int var3865 /* : Bool */;
val* var3867 /* : NativeArray[String] */;
static val* varonce3866;
static val* varonce3868;
val* var3869 /* : String */;
char* var3870 /* : NativeString */;
val* var3871 /* : String */;
val* var3872 /* : nullable Object */;
val* var3873 /* : String */;
val* var3874 /* : String */;
val* var3875 /* : RuntimeVariable */;
static val* varonce3876;
val* var3877 /* : String */;
char* var3878 /* : NativeString */;
val* var3879 /* : String */;
short int var3880 /* : Bool */;
val* var3882 /* : NativeArray[String] */;
static val* varonce3881;
static val* varonce3883;
val* var3884 /* : String */;
char* var3885 /* : NativeString */;
val* var3886 /* : String */;
val* var3887 /* : nullable Object */;
val* var3888 /* : String */;
val* var3889 /* : nullable Object */;
val* var3890 /* : String */;
val* var3891 /* : String */;
val* var3892 /* : RuntimeVariable */;
static val* varonce3893;
val* var3894 /* : String */;
char* var3895 /* : NativeString */;
val* var3896 /* : String */;
short int var3897 /* : Bool */;
val* var3899 /* : NativeArray[String] */;
static val* varonce3898;
static val* varonce3900;
val* var3901 /* : String */;
char* var3902 /* : NativeString */;
val* var3903 /* : String */;
val* var3904 /* : nullable Object */;
val* var3905 /* : String */;
val* var3906 /* : nullable Object */;
val* var3907 /* : String */;
val* var3908 /* : String */;
val* var3909 /* : RuntimeVariable */;
static val* varonce3910;
val* var3911 /* : String */;
char* var3912 /* : NativeString */;
val* var3913 /* : String */;
short int var3914 /* : Bool */;
val* var3916 /* : NativeArray[String] */;
static val* varonce3915;
static val* varonce3917;
val* var3918 /* : String */;
char* var3919 /* : NativeString */;
val* var3920 /* : String */;
val* var3921 /* : nullable Object */;
val* var3922 /* : String */;
val* var3923 /* : nullable Object */;
val* var3924 /* : String */;
val* var3925 /* : String */;
val* var3926 /* : RuntimeVariable */;
static val* varonce3927;
val* var3928 /* : String */;
char* var3929 /* : NativeString */;
val* var3930 /* : String */;
short int var3931 /* : Bool */;
val* var3933 /* : NativeArray[String] */;
static val* varonce3932;
static val* varonce3934;
val* var3935 /* : String */;
char* var3936 /* : NativeString */;
val* var3937 /* : String */;
val* var3938 /* : nullable Object */;
val* var3939 /* : String */;
val* var3940 /* : String */;
val* var3941 /* : RuntimeVariable */;
static val* varonce3942;
val* var3943 /* : String */;
char* var3944 /* : NativeString */;
val* var3945 /* : String */;
short int var3946 /* : Bool */;
val* var3948 /* : NativeArray[String] */;
static val* varonce3947;
static val* varonce3949;
val* var3950 /* : String */;
char* var3951 /* : NativeString */;
val* var3952 /* : String */;
static val* varonce3953;
val* var3954 /* : String */;
char* var3955 /* : NativeString */;
val* var3956 /* : String */;
val* var3957 /* : nullable Object */;
val* var3958 /* : String */;
val* var3959 /* : String */;
static val* varonce3960;
val* var3961 /* : String */;
char* var3962 /* : NativeString */;
val* var3963 /* : String */;
short int var3964 /* : Bool */;
static val* varonce3965;
val* var3966 /* : String */;
char* var3967 /* : NativeString */;
val* var3968 /* : String */;
val* var3969 /* : RuntimeVariable */;
static val* varonce3970;
val* var3971 /* : String */;
char* var3972 /* : NativeString */;
val* var3973 /* : String */;
short int var3974 /* : Bool */;
val* var3976 /* : NativeArray[String] */;
static val* varonce3975;
static val* varonce3977;
val* var3978 /* : String */;
char* var3979 /* : NativeString */;
val* var3980 /* : String */;
static val* varonce3981;
val* var3982 /* : String */;
char* var3983 /* : NativeString */;
val* var3984 /* : String */;
val* var3985 /* : nullable Object */;
val* var3986 /* : String */;
val* var3987 /* : String */;
val* var3988 /* : RuntimeVariable */;
static val* varonce3989;
val* var3990 /* : String */;
char* var3991 /* : NativeString */;
val* var3992 /* : String */;
short int var3993 /* : Bool */;
static val* varonce3994;
val* var3995 /* : String */;
char* var3996 /* : NativeString */;
val* var3997 /* : String */;
short int var3998 /* : Bool */;
val* var4000 /* : NativeArray[String] */;
static val* varonce3999;
static val* varonce4001;
val* var4002 /* : String */;
char* var4003 /* : NativeString */;
val* var4004 /* : String */;
val* var4005 /* : nullable Object */;
val* var4006 /* : String */;
val* var4007 /* : String */;
val* var4008 /* : RuntimeVariable */;
static val* varonce4009;
val* var4010 /* : String */;
char* var4011 /* : NativeString */;
val* var4012 /* : String */;
short int var4013 /* : Bool */;
val* var4014 /* : nullable Object */;
val* var4015 /* : nullable Object */;
val* var4016 /* : RuntimeVariable */;
static val* varonce4017;
val* var4018 /* : String */;
char* var4019 /* : NativeString */;
val* var4020 /* : String */;
short int var4021 /* : Bool */;
val* var4022 /* : nullable Object */;
val* var4023 /* : nullable Object */;
val* var4024 /* : RuntimeVariable */;
static val* varonce4025;
val* var4026 /* : String */;
char* var4027 /* : NativeString */;
val* var4028 /* : String */;
short int var4029 /* : Bool */;
val* var4030 /* : nullable Object */;
val* var4031 /* : String */;
val* var_nat /* var nat: String */;
val* var4033 /* : NativeArray[String] */;
static val* varonce4032;
static val* varonce4034;
val* var4035 /* : String */;
char* var4036 /* : NativeString */;
val* var4037 /* : String */;
static val* varonce4038;
val* var4039 /* : String */;
char* var4040 /* : NativeString */;
val* var4041 /* : String */;
val* var4042 /* : String */;
static val* varonce4043;
val* var4044 /* : String */;
char* var4045 /* : NativeString */;
val* var4046 /* : String */;
short int var4047 /* : Bool */;
val* var4048 /* : nullable Object */;
val* var4049 /* : String */;
val* var_nat4050 /* var nat: String */;
val* var4052 /* : NativeArray[String] */;
static val* varonce4051;
static val* varonce4053;
val* var4054 /* : String */;
char* var4055 /* : NativeString */;
val* var4056 /* : String */;
val* var4057 /* : String */;
val* var4058 /* : RuntimeVariable */;
static val* varonce4059;
val* var4060 /* : String */;
char* var4061 /* : NativeString */;
val* var4062 /* : String */;
short int var4063 /* : Bool */;
static val* varonce4064;
val* var4065 /* : String */;
char* var4066 /* : NativeString */;
val* var4067 /* : String */;
static val* varonce4068;
val* var4069 /* : String */;
char* var4070 /* : NativeString */;
val* var4071 /* : String */;
short int var4072 /* : Bool */;
static val* varonce4073;
val* var4074 /* : String */;
char* var4075 /* : NativeString */;
val* var4076 /* : String */;
val* var4077 /* : RuntimeVariable */;
static val* varonce4078;
val* var4079 /* : String */;
char* var4080 /* : NativeString */;
val* var4081 /* : String */;
short int var4082 /* : Bool */;
val* var4084 /* : NativeArray[String] */;
static val* varonce4083;
static val* varonce4085;
val* var4086 /* : String */;
char* var4087 /* : NativeString */;
val* var4088 /* : String */;
static val* varonce4089;
val* var4090 /* : String */;
char* var4091 /* : NativeString */;
val* var4092 /* : String */;
val* var4093 /* : nullable Object */;
val* var4094 /* : String */;
val* var4095 /* : String */;
val* var4096 /* : RuntimeVariable */;
var_v = p0;
var_mpropdef = p1;
var_arguments = p2;
{
{ /* Inline model#MPropDef#mproperty (var_mpropdef) on <var_mpropdef:MMethodDef> */
var3 = var_mpropdef->attrs[COLOR_nitc__model__MPropDef___mproperty].val; /* _mproperty on <var_mpropdef:MMethodDef> */
if (unlikely(var3 == NULL)) {
PRINT_ERROR("Runtime error: %s", "Uninitialized attribute _mproperty");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__model, 2233);
fatal_exit(1);
}
var1 = var3;
RET_LABEL2:(void)0;
}
}
{
{ /* Inline model#MProperty#name (var1) on <var1:MProperty(MMethod)> */
var6 = var1->attrs[COLOR_nitc__model__MProperty___name].val; /* _name on <var1:MProperty(MMethod)> */
if (unlikely(var6 == NULL)) {
PRINT_ERROR("Runtime error: %s", "Uninitialized attribute _name");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__model, 1954);
fatal_exit(1);
}
var4 = var6;
RET_LABEL5:(void)0;
}
}
var_pname = var4;
{
{ /* Inline model#MPropDef#mclassdef (var_mpropdef) on <var_mpropdef:MMethodDef> */
var9 = var_mpropdef->attrs[COLOR_nitc__model__MPropDef___mclassdef].val; /* _mclassdef on <var_mpropdef:MMethodDef> */
if (unlikely(var9 == NULL)) {
PRINT_ERROR("Runtime error: %s", "Uninitialized attribute _mclassdef");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__model, 2230);
fatal_exit(1);
}
var7 = var9;
RET_LABEL8:(void)0;
}
}
{
{ /* Inline model#MClassDef#mclass (var7) on <var7:MClassDef> */
var12 = var7->attrs[COLOR_nitc__model__MClassDef___mclass].val; /* _mclass on <var7:MClassDef> */
if (unlikely(var12 == NULL)) {
PRINT_ERROR("Runtime error: %s", "Uninitialized attribute _mclass");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__model, 579);
fatal_exit(1);
}
var10 = var12;
RET_LABEL11:(void)0;
}
}
{
{ /* Inline model#MClass#name (var10) on <var10:MClass> */
var15 = var10->attrs[COLOR_nitc__model__MClass___name].val; /* _name on <var10:MClass> */
if (unlikely(var15 == NULL)) {
PRINT_ERROR("Runtime error: %s", "Uninitialized attribute _name");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__model, 388);
fatal_exit(1);
}
var13 = var15;
RET_LABEL14:(void)0;
}
}
var_cname = var13;
{
{ /* Inline model#MMethodDef#msignature (var_mpropdef) on <var_mpropdef:MMethodDef> */
var18 = var_mpropdef->attrs[COLOR_nitc__model__MMethodDef___msignature].val; /* _msignature on <var_mpropdef:MMethodDef> */
var16 = var18;
RET_LABEL17:(void)0;
}
}
if (var16 == NULL) {
PRINT_ERROR("Runtime error: %s", "Receiver is null");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2204);
fatal_exit(1);
} else {
{ /* Inline model#MSignature#return_mtype (var16) on <var16:nullable MSignature> */
if (unlikely(var16 == NULL)) {
PRINT_ERROR("Runtime error: %s", "Receiver is null");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__model, 1798);
fatal_exit(1);
}
var21 = var16->attrs[COLOR_nitc__model__MSignature___return_mtype].val; /* _return_mtype on <var16:nullable MSignature> */
var19 = var21;
RET_LABEL20:(void)0;
}
}
var_ret = var19;
if (var_ret == NULL) {
var22 = 0; /* is null */
} else {
var22 = 1; /* arg is null and recv is not */
}
if (0) {
{ /* Inline kernel#Object#!= (var_ret,((val*)NULL)) on <var_ret:nullable MType> */
var_other = ((val*)NULL);
{
var25 = ((short int(*)(val* self, val* p0))(var_ret->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_ret, var_other); /* == on <var_ret:nullable MType(MType)>*/
}
var26 = !var25;
var23 = var26;
goto RET_LABEL24;
RET_LABEL24:(void)0;
}
var22 = var23;
}
if (var22){
{
var27 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var28 = nitc___nitc__AbstractCompilerVisitor___resolve_for(var_v, var_ret, var27);
}
var_ret = var28;
} else {
}
if (likely(varonce!=NULL)) {
var30 = varonce;
} else {
var31 = "==";
var32 = core__flat___NativeString___to_s_full(var31, 2l, 2l);
var30 = var32;
varonce = var30;
}
{
{ /* Inline kernel#Object#!= (var_pname,var30) on <var_pname:String> */
var_other = var30;
{
var35 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var_other); /* == on <var_pname:String>*/
}
var36 = !var35;
var33 = var36;
goto RET_LABEL34;
RET_LABEL34:(void)0;
}
}
var_ = var33;
if (var33){
if (likely(varonce37!=NULL)) {
var38 = varonce37;
} else {
var39 = "!=";
var40 = core__flat___NativeString___to_s_full(var39, 2l, 2l);
var38 = var40;
varonce37 = var38;
}
{
{ /* Inline kernel#Object#!= (var_pname,var38) on <var_pname:String> */
var_other = var38;
{
var43 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var_other); /* == on <var_pname:String>*/
}
var44 = !var43;
var41 = var44;
goto RET_LABEL42;
RET_LABEL42:(void)0;
}
}
var29 = var41;
} else {
var29 = var_;
}
if (var29){
{
nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__adapt_signature(var_v, var_mpropdef, var_arguments); /* Direct call separate_compiler#SeparateCompilerVisitor#adapt_signature on <var_v:AbstractCompilerVisitor>*/
}
{
nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__unbox_signature_extern(var_v, var_mpropdef, var_arguments); /* Direct call separate_compiler#SeparateCompilerVisitor#unbox_signature_extern on <var_v:AbstractCompilerVisitor>*/
}
} else {
}
if (likely(varonce45!=NULL)) {
var46 = varonce45;
} else {
var47 = "Int";
var48 = core__flat___NativeString___to_s_full(var47, 3l, 3l);
var46 = var48;
varonce45 = var46;
}
{
var49 = ((short int(*)(val* self, val* p0))(var_cname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_cname, var46); /* == on <var_cname:String>*/
}
if (var49){
if (likely(varonce50!=NULL)) {
var51 = varonce50;
} else {
var52 = "output";
var53 = core__flat___NativeString___to_s_full(var52, 6l, 6l);
var51 = var53;
varonce50 = var51;
}
{
var54 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var51); /* == on <var_pname:String>*/
}
if (var54){
if (unlikely(varonce55==NULL)) {
var56 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce57!=NULL)) {
var58 = varonce57;
} else {
var59 = "printf(\"%ld\\n\", ";
var60 = core__flat___NativeString___to_s_full(var59, 16l, 16l);
var58 = var60;
varonce57 = var58;
}
((struct instance_core__NativeArray*)var56)->values[0]=var58;
if (likely(varonce61!=NULL)) {
var62 = varonce61;
} else {
var63 = ");";
var64 = core__flat___NativeString___to_s_full(var63, 2l, 2l);
var62 = var64;
varonce61 = var62;
}
((struct instance_core__NativeArray*)var56)->values[2]=var62;
} else {
var56 = varonce55;
varonce55 = NULL;
}
{
var65 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var66 = ((val*(*)(val* self))(var65->class->vft[COLOR_core__abstract_text__Object__to_s]))(var65); /* to_s on <var65:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var56)->values[1]=var66;
{
var67 = ((val*(*)(val* self))(var56->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var56); /* native_to_s on <var56:NativeArray[String]>*/
}
varonce55 = var56;
{
nitc___nitc__AbstractCompilerVisitor___add(var_v, var67); /* Direct call abstract_compiler#AbstractCompilerVisitor#add on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce68!=NULL)) {
var69 = varonce68;
} else {
var70 = "object_id";
var71 = core__flat___NativeString___to_s_full(var70, 9l, 9l);
var69 = var71;
varonce68 = var69;
}
{
var72 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var69); /* == on <var_pname:String>*/
}
if (var72){
{
var73 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var73); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce74!=NULL)) {
var75 = varonce74;
} else {
var76 = "+";
var77 = core__flat___NativeString___to_s_full(var76, 1l, 1l);
var75 = var77;
varonce74 = var75;
}
{
var78 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var75); /* == on <var_pname:String>*/
}
if (var78){
if (unlikely(varonce79==NULL)) {
var80 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce81!=NULL)) {
var82 = varonce81;
} else {
var83 = " + ";
var84 = core__flat___NativeString___to_s_full(var83, 3l, 3l);
var82 = var84;
varonce81 = var82;
}
((struct instance_core__NativeArray*)var80)->values[1]=var82;
} else {
var80 = varonce79;
varonce79 = NULL;
}
{
var85 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var86 = ((val*(*)(val* self))(var85->class->vft[COLOR_core__abstract_text__Object__to_s]))(var85); /* to_s on <var85:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var80)->values[0]=var86;
{
var87 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var88 = ((val*(*)(val* self))(var87->class->vft[COLOR_core__abstract_text__Object__to_s]))(var87); /* to_s on <var87:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var80)->values[2]=var88;
{
var89 = ((val*(*)(val* self))(var80->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var80); /* native_to_s on <var80:NativeArray[String]>*/
}
varonce79 = var80;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2220);
fatal_exit(1);
}
{
var90 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var89, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var90); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce91!=NULL)) {
var92 = varonce91;
} else {
var93 = "-";
var94 = core__flat___NativeString___to_s_full(var93, 1l, 1l);
var92 = var94;
varonce91 = var92;
}
{
var95 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var92); /* == on <var_pname:String>*/
}
if (var95){
if (unlikely(varonce96==NULL)) {
var97 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce98!=NULL)) {
var99 = varonce98;
} else {
var100 = " - ";
var101 = core__flat___NativeString___to_s_full(var100, 3l, 3l);
var99 = var101;
varonce98 = var99;
}
((struct instance_core__NativeArray*)var97)->values[1]=var99;
} else {
var97 = varonce96;
varonce96 = NULL;
}
{
var102 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var103 = ((val*(*)(val* self))(var102->class->vft[COLOR_core__abstract_text__Object__to_s]))(var102); /* to_s on <var102:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var97)->values[0]=var103;
{
var104 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var105 = ((val*(*)(val* self))(var104->class->vft[COLOR_core__abstract_text__Object__to_s]))(var104); /* to_s on <var104:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var97)->values[2]=var105;
{
var106 = ((val*(*)(val* self))(var97->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var97); /* native_to_s on <var97:NativeArray[String]>*/
}
varonce96 = var97;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2223);
fatal_exit(1);
}
{
var107 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var106, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var107); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce108!=NULL)) {
var109 = varonce108;
} else {
var110 = "unary -";
var111 = core__flat___NativeString___to_s_full(var110, 7l, 7l);
var109 = var111;
varonce108 = var109;
}
{
var112 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var109); /* == on <var_pname:String>*/
}
if (var112){
if (unlikely(varonce113==NULL)) {
var114 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce115!=NULL)) {
var116 = varonce115;
} else {
var117 = "-";
var118 = core__flat___NativeString___to_s_full(var117, 1l, 1l);
var116 = var118;
varonce115 = var116;
}
((struct instance_core__NativeArray*)var114)->values[0]=var116;
} else {
var114 = varonce113;
varonce113 = NULL;
}
{
var119 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var120 = ((val*(*)(val* self))(var119->class->vft[COLOR_core__abstract_text__Object__to_s]))(var119); /* to_s on <var119:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var114)->values[1]=var120;
{
var121 = ((val*(*)(val* self))(var114->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var114); /* native_to_s on <var114:NativeArray[String]>*/
}
varonce113 = var114;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2226);
fatal_exit(1);
}
{
var122 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var121, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var122); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce123!=NULL)) {
var124 = varonce123;
} else {
var125 = "unary +";
var126 = core__flat___NativeString___to_s_full(var125, 7l, 7l);
var124 = var126;
varonce123 = var124;
}
{
var127 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var124); /* == on <var_pname:String>*/
}
if (var127){
{
var128 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var128); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce129!=NULL)) {
var130 = varonce129;
} else {
var131 = "*";
var132 = core__flat___NativeString___to_s_full(var131, 1l, 1l);
var130 = var132;
varonce129 = var130;
}
{
var133 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var130); /* == on <var_pname:String>*/
}
if (var133){
if (unlikely(varonce134==NULL)) {
var135 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce136!=NULL)) {
var137 = varonce136;
} else {
var138 = " * ";
var139 = core__flat___NativeString___to_s_full(var138, 3l, 3l);
var137 = var139;
varonce136 = var137;
}
((struct instance_core__NativeArray*)var135)->values[1]=var137;
} else {
var135 = varonce134;
varonce134 = NULL;
}
{
var140 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var141 = ((val*(*)(val* self))(var140->class->vft[COLOR_core__abstract_text__Object__to_s]))(var140); /* to_s on <var140:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var135)->values[0]=var141;
{
var142 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var143 = ((val*(*)(val* self))(var142->class->vft[COLOR_core__abstract_text__Object__to_s]))(var142); /* to_s on <var142:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var135)->values[2]=var143;
{
var144 = ((val*(*)(val* self))(var135->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var135); /* native_to_s on <var135:NativeArray[String]>*/
}
varonce134 = var135;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2232);
fatal_exit(1);
}
{
var145 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var144, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var145); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce146!=NULL)) {
var147 = varonce146;
} else {
var148 = "/";
var149 = core__flat___NativeString___to_s_full(var148, 1l, 1l);
var147 = var149;
varonce146 = var147;
}
{
var150 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var147); /* == on <var_pname:String>*/
}
if (var150){
if (unlikely(varonce151==NULL)) {
var152 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce153!=NULL)) {
var154 = varonce153;
} else {
var155 = " / ";
var156 = core__flat___NativeString___to_s_full(var155, 3l, 3l);
var154 = var156;
varonce153 = var154;
}
((struct instance_core__NativeArray*)var152)->values[1]=var154;
} else {
var152 = varonce151;
varonce151 = NULL;
}
{
var157 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var158 = ((val*(*)(val* self))(var157->class->vft[COLOR_core__abstract_text__Object__to_s]))(var157); /* to_s on <var157:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var152)->values[0]=var158;
{
var159 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var160 = ((val*(*)(val* self))(var159->class->vft[COLOR_core__abstract_text__Object__to_s]))(var159); /* to_s on <var159:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var152)->values[2]=var160;
{
var161 = ((val*(*)(val* self))(var152->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var152); /* native_to_s on <var152:NativeArray[String]>*/
}
varonce151 = var152;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2235);
fatal_exit(1);
}
{
var162 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var161, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var162); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce163!=NULL)) {
var164 = varonce163;
} else {
var165 = "%";
var166 = core__flat___NativeString___to_s_full(var165, 1l, 1l);
var164 = var166;
varonce163 = var164;
}
{
var167 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var164); /* == on <var_pname:String>*/
}
if (var167){
if (unlikely(varonce168==NULL)) {
var169 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce170!=NULL)) {
var171 = varonce170;
} else {
var172 = " % ";
var173 = core__flat___NativeString___to_s_full(var172, 3l, 3l);
var171 = var173;
varonce170 = var171;
}
((struct instance_core__NativeArray*)var169)->values[1]=var171;
} else {
var169 = varonce168;
varonce168 = NULL;
}
{
var174 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var175 = ((val*(*)(val* self))(var174->class->vft[COLOR_core__abstract_text__Object__to_s]))(var174); /* to_s on <var174:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var169)->values[0]=var175;
{
var176 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var177 = ((val*(*)(val* self))(var176->class->vft[COLOR_core__abstract_text__Object__to_s]))(var176); /* to_s on <var176:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var169)->values[2]=var177;
{
var178 = ((val*(*)(val* self))(var169->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var169); /* native_to_s on <var169:NativeArray[String]>*/
}
varonce168 = var169;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2238);
fatal_exit(1);
}
{
var179 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var178, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var179); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce180!=NULL)) {
var181 = varonce180;
} else {
var182 = "==";
var183 = core__flat___NativeString___to_s_full(var182, 2l, 2l);
var181 = var183;
varonce180 = var181;
}
{
var184 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var181); /* == on <var_pname:String>*/
}
if (var184){
{
var185 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var186 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var187 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var185, var186);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var187); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce188!=NULL)) {
var189 = varonce188;
} else {
var190 = "!=";
var191 = core__flat___NativeString___to_s_full(var190, 2l, 2l);
var189 = var191;
varonce188 = var189;
}
{
var192 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var189); /* == on <var_pname:String>*/
}
if (var192){
{
var193 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var194 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var195 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var193, var194);
}
var_res = var195;
if (unlikely(varonce196==NULL)) {
var197 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce198!=NULL)) {
var199 = varonce198;
} else {
var200 = "!";
var201 = core__flat___NativeString___to_s_full(var200, 1l, 1l);
var199 = var201;
varonce198 = var199;
}
((struct instance_core__NativeArray*)var197)->values[0]=var199;
} else {
var197 = varonce196;
varonce196 = NULL;
}
{
var202 = ((val*(*)(val* self))(var_res->class->vft[COLOR_core__abstract_text__Object__to_s]))(var_res); /* to_s on <var_res:RuntimeVariable>*/
}
((struct instance_core__NativeArray*)var197)->values[1]=var202;
{
var203 = ((val*(*)(val* self))(var197->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var197); /* native_to_s on <var197:NativeArray[String]>*/
}
varonce196 = var197;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2245);
fatal_exit(1);
}
{
var204 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var203, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var204); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce205!=NULL)) {
var206 = varonce205;
} else {
var207 = "<";
var208 = core__flat___NativeString___to_s_full(var207, 1l, 1l);
var206 = var208;
varonce205 = var206;
}
{
var209 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var206); /* == on <var_pname:String>*/
}
if (var209){
if (unlikely(varonce210==NULL)) {
var211 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce212!=NULL)) {
var213 = varonce212;
} else {
var214 = " < ";
var215 = core__flat___NativeString___to_s_full(var214, 3l, 3l);
var213 = var215;
varonce212 = var213;
}
((struct instance_core__NativeArray*)var211)->values[1]=var213;
} else {
var211 = varonce210;
varonce210 = NULL;
}
{
var216 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var217 = ((val*(*)(val* self))(var216->class->vft[COLOR_core__abstract_text__Object__to_s]))(var216); /* to_s on <var216:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var211)->values[0]=var217;
{
var218 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var219 = ((val*(*)(val* self))(var218->class->vft[COLOR_core__abstract_text__Object__to_s]))(var218); /* to_s on <var218:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var211)->values[2]=var219;
{
var220 = ((val*(*)(val* self))(var211->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var211); /* native_to_s on <var211:NativeArray[String]>*/
}
varonce210 = var211;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2248);
fatal_exit(1);
}
{
var221 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var220, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var221); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce222!=NULL)) {
var223 = varonce222;
} else {
var224 = ">";
var225 = core__flat___NativeString___to_s_full(var224, 1l, 1l);
var223 = var225;
varonce222 = var223;
}
{
var226 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var223); /* == on <var_pname:String>*/
}
if (var226){
if (unlikely(varonce227==NULL)) {
var228 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce229!=NULL)) {
var230 = varonce229;
} else {
var231 = " > ";
var232 = core__flat___NativeString___to_s_full(var231, 3l, 3l);
var230 = var232;
varonce229 = var230;
}
((struct instance_core__NativeArray*)var228)->values[1]=var230;
} else {
var228 = varonce227;
varonce227 = NULL;
}
{
var233 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var234 = ((val*(*)(val* self))(var233->class->vft[COLOR_core__abstract_text__Object__to_s]))(var233); /* to_s on <var233:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var228)->values[0]=var234;
{
var235 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var236 = ((val*(*)(val* self))(var235->class->vft[COLOR_core__abstract_text__Object__to_s]))(var235); /* to_s on <var235:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var228)->values[2]=var236;
{
var237 = ((val*(*)(val* self))(var228->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var228); /* native_to_s on <var228:NativeArray[String]>*/
}
varonce227 = var228;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2251);
fatal_exit(1);
}
{
var238 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var237, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var238); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce239!=NULL)) {
var240 = varonce239;
} else {
var241 = "<=";
var242 = core__flat___NativeString___to_s_full(var241, 2l, 2l);
var240 = var242;
varonce239 = var240;
}
{
var243 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var240); /* == on <var_pname:String>*/
}
if (var243){
if (unlikely(varonce244==NULL)) {
var245 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce246!=NULL)) {
var247 = varonce246;
} else {
var248 = " <= ";
var249 = core__flat___NativeString___to_s_full(var248, 4l, 4l);
var247 = var249;
varonce246 = var247;
}
((struct instance_core__NativeArray*)var245)->values[1]=var247;
} else {
var245 = varonce244;
varonce244 = NULL;
}
{
var250 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var251 = ((val*(*)(val* self))(var250->class->vft[COLOR_core__abstract_text__Object__to_s]))(var250); /* to_s on <var250:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var245)->values[0]=var251;
{
var252 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var253 = ((val*(*)(val* self))(var252->class->vft[COLOR_core__abstract_text__Object__to_s]))(var252); /* to_s on <var252:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var245)->values[2]=var253;
{
var254 = ((val*(*)(val* self))(var245->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var245); /* native_to_s on <var245:NativeArray[String]>*/
}
varonce244 = var245;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2254);
fatal_exit(1);
}
{
var255 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var254, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var255); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce256!=NULL)) {
var257 = varonce256;
} else {
var258 = ">=";
var259 = core__flat___NativeString___to_s_full(var258, 2l, 2l);
var257 = var259;
varonce256 = var257;
}
{
var260 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var257); /* == on <var_pname:String>*/
}
if (var260){
if (unlikely(varonce261==NULL)) {
var262 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce263!=NULL)) {
var264 = varonce263;
} else {
var265 = " >= ";
var266 = core__flat___NativeString___to_s_full(var265, 4l, 4l);
var264 = var266;
varonce263 = var264;
}
((struct instance_core__NativeArray*)var262)->values[1]=var264;
} else {
var262 = varonce261;
varonce261 = NULL;
}
{
var267 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var268 = ((val*(*)(val* self))(var267->class->vft[COLOR_core__abstract_text__Object__to_s]))(var267); /* to_s on <var267:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var262)->values[0]=var268;
{
var269 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var270 = ((val*(*)(val* self))(var269->class->vft[COLOR_core__abstract_text__Object__to_s]))(var269); /* to_s on <var269:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var262)->values[2]=var270;
{
var271 = ((val*(*)(val* self))(var262->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var262); /* native_to_s on <var262:NativeArray[String]>*/
}
varonce261 = var262;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2257);
fatal_exit(1);
}
{
var272 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var271, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var272); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce273!=NULL)) {
var274 = varonce273;
} else {
var275 = "to_i8";
var276 = core__flat___NativeString___to_s_full(var275, 5l, 5l);
var274 = var276;
varonce273 = var274;
}
{
var277 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var274); /* == on <var_pname:String>*/
}
if (var277){
if (unlikely(varonce278==NULL)) {
var279 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce280!=NULL)) {
var281 = varonce280;
} else {
var282 = "(int8_t)";
var283 = core__flat___NativeString___to_s_full(var282, 8l, 8l);
var281 = var283;
varonce280 = var281;
}
((struct instance_core__NativeArray*)var279)->values[0]=var281;
} else {
var279 = varonce278;
varonce278 = NULL;
}
{
var284 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var285 = ((val*(*)(val* self))(var284->class->vft[COLOR_core__abstract_text__Object__to_s]))(var284); /* to_s on <var284:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var279)->values[1]=var285;
{
var286 = ((val*(*)(val* self))(var279->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var279); /* native_to_s on <var279:NativeArray[String]>*/
}
varonce278 = var279;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2260);
fatal_exit(1);
}
{
var287 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var286, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var287); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce288!=NULL)) {
var289 = varonce288;
} else {
var290 = "to_i16";
var291 = core__flat___NativeString___to_s_full(var290, 6l, 6l);
var289 = var291;
varonce288 = var289;
}
{
var292 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var289); /* == on <var_pname:String>*/
}
if (var292){
if (unlikely(varonce293==NULL)) {
var294 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce295!=NULL)) {
var296 = varonce295;
} else {
var297 = "(int16_t)";
var298 = core__flat___NativeString___to_s_full(var297, 9l, 9l);
var296 = var298;
varonce295 = var296;
}
((struct instance_core__NativeArray*)var294)->values[0]=var296;
} else {
var294 = varonce293;
varonce293 = NULL;
}
{
var299 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var300 = ((val*(*)(val* self))(var299->class->vft[COLOR_core__abstract_text__Object__to_s]))(var299); /* to_s on <var299:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var294)->values[1]=var300;
{
var301 = ((val*(*)(val* self))(var294->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var294); /* native_to_s on <var294:NativeArray[String]>*/
}
varonce293 = var294;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2263);
fatal_exit(1);
}
{
var302 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var301, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var302); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce303!=NULL)) {
var304 = varonce303;
} else {
var305 = "to_u16";
var306 = core__flat___NativeString___to_s_full(var305, 6l, 6l);
var304 = var306;
varonce303 = var304;
}
{
var307 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var304); /* == on <var_pname:String>*/
}
if (var307){
if (unlikely(varonce308==NULL)) {
var309 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce310!=NULL)) {
var311 = varonce310;
} else {
var312 = "(uint16_t)";
var313 = core__flat___NativeString___to_s_full(var312, 10l, 10l);
var311 = var313;
varonce310 = var311;
}
((struct instance_core__NativeArray*)var309)->values[0]=var311;
} else {
var309 = varonce308;
varonce308 = NULL;
}
{
var314 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var315 = ((val*(*)(val* self))(var314->class->vft[COLOR_core__abstract_text__Object__to_s]))(var314); /* to_s on <var314:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var309)->values[1]=var315;
{
var316 = ((val*(*)(val* self))(var309->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var309); /* native_to_s on <var309:NativeArray[String]>*/
}
varonce308 = var309;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2266);
fatal_exit(1);
}
{
var317 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var316, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var317); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce318!=NULL)) {
var319 = varonce318;
} else {
var320 = "to_i32";
var321 = core__flat___NativeString___to_s_full(var320, 6l, 6l);
var319 = var321;
varonce318 = var319;
}
{
var322 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var319); /* == on <var_pname:String>*/
}
if (var322){
if (unlikely(varonce323==NULL)) {
var324 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce325!=NULL)) {
var326 = varonce325;
} else {
var327 = "(int32_t)";
var328 = core__flat___NativeString___to_s_full(var327, 9l, 9l);
var326 = var328;
varonce325 = var326;
}
((struct instance_core__NativeArray*)var324)->values[0]=var326;
} else {
var324 = varonce323;
varonce323 = NULL;
}
{
var329 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var330 = ((val*(*)(val* self))(var329->class->vft[COLOR_core__abstract_text__Object__to_s]))(var329); /* to_s on <var329:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var324)->values[1]=var330;
{
var331 = ((val*(*)(val* self))(var324->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var324); /* native_to_s on <var324:NativeArray[String]>*/
}
varonce323 = var324;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2269);
fatal_exit(1);
}
{
var332 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var331, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var332); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce333!=NULL)) {
var334 = varonce333;
} else {
var335 = "to_u32";
var336 = core__flat___NativeString___to_s_full(var335, 6l, 6l);
var334 = var336;
varonce333 = var334;
}
{
var337 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var334); /* == on <var_pname:String>*/
}
if (var337){
if (unlikely(varonce338==NULL)) {
var339 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce340!=NULL)) {
var341 = varonce340;
} else {
var342 = "(uint32_t)";
var343 = core__flat___NativeString___to_s_full(var342, 10l, 10l);
var341 = var343;
varonce340 = var341;
}
((struct instance_core__NativeArray*)var339)->values[0]=var341;
} else {
var339 = varonce338;
varonce338 = NULL;
}
{
var344 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var345 = ((val*(*)(val* self))(var344->class->vft[COLOR_core__abstract_text__Object__to_s]))(var344); /* to_s on <var344:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var339)->values[1]=var345;
{
var346 = ((val*(*)(val* self))(var339->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var339); /* native_to_s on <var339:NativeArray[String]>*/
}
varonce338 = var339;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2272);
fatal_exit(1);
}
{
var347 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var346, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var347); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce348!=NULL)) {
var349 = varonce348;
} else {
var350 = "to_f";
var351 = core__flat___NativeString___to_s_full(var350, 4l, 4l);
var349 = var351;
varonce348 = var349;
}
{
var352 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var349); /* == on <var_pname:String>*/
}
if (var352){
if (unlikely(varonce353==NULL)) {
var354 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce355!=NULL)) {
var356 = varonce355;
} else {
var357 = "(double)";
var358 = core__flat___NativeString___to_s_full(var357, 8l, 8l);
var356 = var358;
varonce355 = var356;
}
((struct instance_core__NativeArray*)var354)->values[0]=var356;
} else {
var354 = varonce353;
varonce353 = NULL;
}
{
var359 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var360 = ((val*(*)(val* self))(var359->class->vft[COLOR_core__abstract_text__Object__to_s]))(var359); /* to_s on <var359:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var354)->values[1]=var360;
{
var361 = ((val*(*)(val* self))(var354->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var354); /* native_to_s on <var354:NativeArray[String]>*/
}
varonce353 = var354;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2275);
fatal_exit(1);
}
{
var362 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var361, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var362); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce363!=NULL)) {
var364 = varonce363;
} else {
var365 = "to_b";
var366 = core__flat___NativeString___to_s_full(var365, 4l, 4l);
var364 = var366;
varonce363 = var364;
}
{
var367 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var364); /* == on <var_pname:String>*/
}
if (var367){
if (unlikely(varonce368==NULL)) {
var369 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce370!=NULL)) {
var371 = varonce370;
} else {
var372 = "(unsigned char)";
var373 = core__flat___NativeString___to_s_full(var372, 15l, 15l);
var371 = var373;
varonce370 = var371;
}
((struct instance_core__NativeArray*)var369)->values[0]=var371;
} else {
var369 = varonce368;
varonce368 = NULL;
}
{
var374 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var375 = ((val*(*)(val* self))(var374->class->vft[COLOR_core__abstract_text__Object__to_s]))(var374); /* to_s on <var374:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var369)->values[1]=var375;
{
var376 = ((val*(*)(val* self))(var369->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var369); /* native_to_s on <var369:NativeArray[String]>*/
}
varonce368 = var369;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2278);
fatal_exit(1);
}
{
var377 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var376, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var377); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce378!=NULL)) {
var379 = varonce378;
} else {
var380 = "code_point";
var381 = core__flat___NativeString___to_s_full(var380, 10l, 10l);
var379 = var381;
varonce378 = var379;
}
{
var382 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var379); /* == on <var_pname:String>*/
}
if (var382){
if (unlikely(varonce383==NULL)) {
var384 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce385!=NULL)) {
var386 = varonce385;
} else {
var387 = "(uint32_t)";
var388 = core__flat___NativeString___to_s_full(var387, 10l, 10l);
var386 = var388;
varonce385 = var386;
}
((struct instance_core__NativeArray*)var384)->values[0]=var386;
} else {
var384 = varonce383;
varonce383 = NULL;
}
{
var389 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var390 = ((val*(*)(val* self))(var389->class->vft[COLOR_core__abstract_text__Object__to_s]))(var389); /* to_s on <var389:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var384)->values[1]=var390;
{
var391 = ((val*(*)(val* self))(var384->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var384); /* native_to_s on <var384:NativeArray[String]>*/
}
varonce383 = var384;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2281);
fatal_exit(1);
}
{
var392 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var391, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var392); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce393!=NULL)) {
var394 = varonce393;
} else {
var395 = "&";
var396 = core__flat___NativeString___to_s_full(var395, 1l, 1l);
var394 = var396;
varonce393 = var394;
}
{
var397 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var394); /* == on <var_pname:String>*/
}
if (var397){
if (unlikely(varonce398==NULL)) {
var399 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce400!=NULL)) {
var401 = varonce400;
} else {
var402 = " & ";
var403 = core__flat___NativeString___to_s_full(var402, 3l, 3l);
var401 = var403;
varonce400 = var401;
}
((struct instance_core__NativeArray*)var399)->values[1]=var401;
} else {
var399 = varonce398;
varonce398 = NULL;
}
{
var404 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var405 = ((val*(*)(val* self))(var404->class->vft[COLOR_core__abstract_text__Object__to_s]))(var404); /* to_s on <var404:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var399)->values[0]=var405;
{
var406 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var407 = ((val*(*)(val* self))(var406->class->vft[COLOR_core__abstract_text__Object__to_s]))(var406); /* to_s on <var406:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var399)->values[2]=var407;
{
var408 = ((val*(*)(val* self))(var399->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var399); /* native_to_s on <var399:NativeArray[String]>*/
}
varonce398 = var399;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2284);
fatal_exit(1);
}
{
var409 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var408, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var409); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce410!=NULL)) {
var411 = varonce410;
} else {
var412 = "|";
var413 = core__flat___NativeString___to_s_full(var412, 1l, 1l);
var411 = var413;
varonce410 = var411;
}
{
var414 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var411); /* == on <var_pname:String>*/
}
if (var414){
if (unlikely(varonce415==NULL)) {
var416 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce417!=NULL)) {
var418 = varonce417;
} else {
var419 = " | ";
var420 = core__flat___NativeString___to_s_full(var419, 3l, 3l);
var418 = var420;
varonce417 = var418;
}
((struct instance_core__NativeArray*)var416)->values[1]=var418;
} else {
var416 = varonce415;
varonce415 = NULL;
}
{
var421 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var422 = ((val*(*)(val* self))(var421->class->vft[COLOR_core__abstract_text__Object__to_s]))(var421); /* to_s on <var421:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var416)->values[0]=var422;
{
var423 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var424 = ((val*(*)(val* self))(var423->class->vft[COLOR_core__abstract_text__Object__to_s]))(var423); /* to_s on <var423:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var416)->values[2]=var424;
{
var425 = ((val*(*)(val* self))(var416->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var416); /* native_to_s on <var416:NativeArray[String]>*/
}
varonce415 = var416;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2287);
fatal_exit(1);
}
{
var426 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var425, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var426); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce427!=NULL)) {
var428 = varonce427;
} else {
var429 = ">>";
var430 = core__flat___NativeString___to_s_full(var429, 2l, 2l);
var428 = var430;
varonce427 = var428;
}
{
var431 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var428); /* == on <var_pname:String>*/
}
if (var431){
if (unlikely(varonce432==NULL)) {
var433 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce434!=NULL)) {
var435 = varonce434;
} else {
var436 = " >> ";
var437 = core__flat___NativeString___to_s_full(var436, 4l, 4l);
var435 = var437;
varonce434 = var435;
}
((struct instance_core__NativeArray*)var433)->values[1]=var435;
} else {
var433 = varonce432;
varonce432 = NULL;
}
{
var438 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var439 = ((val*(*)(val* self))(var438->class->vft[COLOR_core__abstract_text__Object__to_s]))(var438); /* to_s on <var438:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var433)->values[0]=var439;
{
var440 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var441 = ((val*(*)(val* self))(var440->class->vft[COLOR_core__abstract_text__Object__to_s]))(var440); /* to_s on <var440:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var433)->values[2]=var441;
{
var442 = ((val*(*)(val* self))(var433->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var433); /* native_to_s on <var433:NativeArray[String]>*/
}
varonce432 = var433;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2290);
fatal_exit(1);
}
{
var443 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var442, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var443); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce444!=NULL)) {
var445 = varonce444;
} else {
var446 = "<<";
var447 = core__flat___NativeString___to_s_full(var446, 2l, 2l);
var445 = var447;
varonce444 = var445;
}
{
var448 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var445); /* == on <var_pname:String>*/
}
if (var448){
if (unlikely(varonce449==NULL)) {
var450 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce451!=NULL)) {
var452 = varonce451;
} else {
var453 = " << ";
var454 = core__flat___NativeString___to_s_full(var453, 4l, 4l);
var452 = var454;
varonce451 = var452;
}
((struct instance_core__NativeArray*)var450)->values[1]=var452;
} else {
var450 = varonce449;
varonce449 = NULL;
}
{
var455 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var456 = ((val*(*)(val* self))(var455->class->vft[COLOR_core__abstract_text__Object__to_s]))(var455); /* to_s on <var455:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var450)->values[0]=var456;
{
var457 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var458 = ((val*(*)(val* self))(var457->class->vft[COLOR_core__abstract_text__Object__to_s]))(var457); /* to_s on <var457:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var450)->values[2]=var458;
{
var459 = ((val*(*)(val* self))(var450->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var450); /* native_to_s on <var450:NativeArray[String]>*/
}
varonce449 = var450;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2293);
fatal_exit(1);
}
{
var460 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var459, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var460); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
} else {
if (likely(varonce461!=NULL)) {
var462 = varonce461;
} else {
var463 = "Char";
var464 = core__flat___NativeString___to_s_full(var463, 4l, 4l);
var462 = var464;
varonce461 = var462;
}
{
var465 = ((short int(*)(val* self, val* p0))(var_cname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_cname, var462); /* == on <var_cname:String>*/
}
if (var465){
if (likely(varonce466!=NULL)) {
var467 = varonce466;
} else {
var468 = "object_id";
var469 = core__flat___NativeString___to_s_full(var468, 9l, 9l);
var467 = var469;
varonce466 = var467;
}
{
var470 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var467); /* == on <var_pname:String>*/
}
if (var470){
if (unlikely(varonce471==NULL)) {
var472 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce473!=NULL)) {
var474 = varonce473;
} else {
var475 = "(long)";
var476 = core__flat___NativeString___to_s_full(var475, 6l, 6l);
var474 = var476;
varonce473 = var474;
}
((struct instance_core__NativeArray*)var472)->values[0]=var474;
} else {
var472 = varonce471;
varonce471 = NULL;
}
{
var477 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var478 = ((val*(*)(val* self))(var477->class->vft[COLOR_core__abstract_text__Object__to_s]))(var477); /* to_s on <var477:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var472)->values[1]=var478;
{
var479 = ((val*(*)(val* self))(var472->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var472); /* native_to_s on <var472:NativeArray[String]>*/
}
varonce471 = var472;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2298);
fatal_exit(1);
}
{
var480 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var479, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var480); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce481!=NULL)) {
var482 = varonce481;
} else {
var483 = "successor";
var484 = core__flat___NativeString___to_s_full(var483, 9l, 9l);
var482 = var484;
varonce481 = var482;
}
{
var485 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var482); /* == on <var_pname:String>*/
}
if (var485){
if (unlikely(varonce486==NULL)) {
var487 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce488!=NULL)) {
var489 = varonce488;
} else {
var490 = " + ";
var491 = core__flat___NativeString___to_s_full(var490, 3l, 3l);
var489 = var491;
varonce488 = var489;
}
((struct instance_core__NativeArray*)var487)->values[1]=var489;
} else {
var487 = varonce486;
varonce486 = NULL;
}
{
var492 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var493 = ((val*(*)(val* self))(var492->class->vft[COLOR_core__abstract_text__Object__to_s]))(var492); /* to_s on <var492:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var487)->values[0]=var493;
{
var494 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var495 = ((val*(*)(val* self))(var494->class->vft[COLOR_core__abstract_text__Object__to_s]))(var494); /* to_s on <var494:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var487)->values[2]=var495;
{
var496 = ((val*(*)(val* self))(var487->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var487); /* native_to_s on <var487:NativeArray[String]>*/
}
varonce486 = var487;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2301);
fatal_exit(1);
}
{
var497 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var496, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var497); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce498!=NULL)) {
var499 = varonce498;
} else {
var500 = "predecessor";
var501 = core__flat___NativeString___to_s_full(var500, 11l, 11l);
var499 = var501;
varonce498 = var499;
}
{
var502 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var499); /* == on <var_pname:String>*/
}
if (var502){
if (unlikely(varonce503==NULL)) {
var504 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce505!=NULL)) {
var506 = varonce505;
} else {
var507 = " - ";
var508 = core__flat___NativeString___to_s_full(var507, 3l, 3l);
var506 = var508;
varonce505 = var506;
}
((struct instance_core__NativeArray*)var504)->values[1]=var506;
} else {
var504 = varonce503;
varonce503 = NULL;
}
{
var509 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var510 = ((val*(*)(val* self))(var509->class->vft[COLOR_core__abstract_text__Object__to_s]))(var509); /* to_s on <var509:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var504)->values[0]=var510;
{
var511 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var512 = ((val*(*)(val* self))(var511->class->vft[COLOR_core__abstract_text__Object__to_s]))(var511); /* to_s on <var511:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var504)->values[2]=var512;
{
var513 = ((val*(*)(val* self))(var504->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var504); /* native_to_s on <var504:NativeArray[String]>*/
}
varonce503 = var504;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2304);
fatal_exit(1);
}
{
var514 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var513, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var514); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce515!=NULL)) {
var516 = varonce515;
} else {
var517 = "==";
var518 = core__flat___NativeString___to_s_full(var517, 2l, 2l);
var516 = var518;
varonce515 = var516;
}
{
var519 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var516); /* == on <var_pname:String>*/
}
if (var519){
{
var520 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var521 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var522 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var520, var521);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var522); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce523!=NULL)) {
var524 = varonce523;
} else {
var525 = "!=";
var526 = core__flat___NativeString___to_s_full(var525, 2l, 2l);
var524 = var526;
varonce523 = var524;
}
{
var527 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var524); /* == on <var_pname:String>*/
}
if (var527){
{
var528 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var529 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var530 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var528, var529);
}
var_res531 = var530;
if (unlikely(varonce532==NULL)) {
var533 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce534!=NULL)) {
var535 = varonce534;
} else {
var536 = "!";
var537 = core__flat___NativeString___to_s_full(var536, 1l, 1l);
var535 = var537;
varonce534 = var535;
}
((struct instance_core__NativeArray*)var533)->values[0]=var535;
} else {
var533 = varonce532;
varonce532 = NULL;
}
{
var538 = ((val*(*)(val* self))(var_res531->class->vft[COLOR_core__abstract_text__Object__to_s]))(var_res531); /* to_s on <var_res531:RuntimeVariable>*/
}
((struct instance_core__NativeArray*)var533)->values[1]=var538;
{
var539 = ((val*(*)(val* self))(var533->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var533); /* native_to_s on <var533:NativeArray[String]>*/
}
varonce532 = var533;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2311);
fatal_exit(1);
}
{
var540 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var539, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var540); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce541!=NULL)) {
var542 = varonce541;
} else {
var543 = "<";
var544 = core__flat___NativeString___to_s_full(var543, 1l, 1l);
var542 = var544;
varonce541 = var542;
}
{
var545 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var542); /* == on <var_pname:String>*/
}
if (var545){
if (unlikely(varonce546==NULL)) {
var547 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce548!=NULL)) {
var549 = varonce548;
} else {
var550 = " < ";
var551 = core__flat___NativeString___to_s_full(var550, 3l, 3l);
var549 = var551;
varonce548 = var549;
}
((struct instance_core__NativeArray*)var547)->values[1]=var549;
} else {
var547 = varonce546;
varonce546 = NULL;
}
{
var552 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var553 = ((val*(*)(val* self))(var552->class->vft[COLOR_core__abstract_text__Object__to_s]))(var552); /* to_s on <var552:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var547)->values[0]=var553;
{
var554 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var555 = ((val*(*)(val* self))(var554->class->vft[COLOR_core__abstract_text__Object__to_s]))(var554); /* to_s on <var554:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var547)->values[2]=var555;
{
var556 = ((val*(*)(val* self))(var547->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var547); /* native_to_s on <var547:NativeArray[String]>*/
}
varonce546 = var547;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2314);
fatal_exit(1);
}
{
var557 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var556, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var557); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce558!=NULL)) {
var559 = varonce558;
} else {
var560 = ">";
var561 = core__flat___NativeString___to_s_full(var560, 1l, 1l);
var559 = var561;
varonce558 = var559;
}
{
var562 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var559); /* == on <var_pname:String>*/
}
if (var562){
if (unlikely(varonce563==NULL)) {
var564 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce565!=NULL)) {
var566 = varonce565;
} else {
var567 = " > ";
var568 = core__flat___NativeString___to_s_full(var567, 3l, 3l);
var566 = var568;
varonce565 = var566;
}
((struct instance_core__NativeArray*)var564)->values[1]=var566;
} else {
var564 = varonce563;
varonce563 = NULL;
}
{
var569 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var570 = ((val*(*)(val* self))(var569->class->vft[COLOR_core__abstract_text__Object__to_s]))(var569); /* to_s on <var569:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var564)->values[0]=var570;
{
var571 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var572 = ((val*(*)(val* self))(var571->class->vft[COLOR_core__abstract_text__Object__to_s]))(var571); /* to_s on <var571:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var564)->values[2]=var572;
{
var573 = ((val*(*)(val* self))(var564->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var564); /* native_to_s on <var564:NativeArray[String]>*/
}
varonce563 = var564;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2317);
fatal_exit(1);
}
{
var574 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var573, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var574); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce575!=NULL)) {
var576 = varonce575;
} else {
var577 = "<=";
var578 = core__flat___NativeString___to_s_full(var577, 2l, 2l);
var576 = var578;
varonce575 = var576;
}
{
var579 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var576); /* == on <var_pname:String>*/
}
if (var579){
if (unlikely(varonce580==NULL)) {
var581 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce582!=NULL)) {
var583 = varonce582;
} else {
var584 = " <= ";
var585 = core__flat___NativeString___to_s_full(var584, 4l, 4l);
var583 = var585;
varonce582 = var583;
}
((struct instance_core__NativeArray*)var581)->values[1]=var583;
} else {
var581 = varonce580;
varonce580 = NULL;
}
{
var586 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var587 = ((val*(*)(val* self))(var586->class->vft[COLOR_core__abstract_text__Object__to_s]))(var586); /* to_s on <var586:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var581)->values[0]=var587;
{
var588 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var589 = ((val*(*)(val* self))(var588->class->vft[COLOR_core__abstract_text__Object__to_s]))(var588); /* to_s on <var588:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var581)->values[2]=var589;
{
var590 = ((val*(*)(val* self))(var581->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var581); /* native_to_s on <var581:NativeArray[String]>*/
}
varonce580 = var581;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2320);
fatal_exit(1);
}
{
var591 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var590, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var591); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce592!=NULL)) {
var593 = varonce592;
} else {
var594 = ">=";
var595 = core__flat___NativeString___to_s_full(var594, 2l, 2l);
var593 = var595;
varonce592 = var593;
}
{
var596 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var593); /* == on <var_pname:String>*/
}
if (var596){
if (unlikely(varonce597==NULL)) {
var598 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce599!=NULL)) {
var600 = varonce599;
} else {
var601 = " >= ";
var602 = core__flat___NativeString___to_s_full(var601, 4l, 4l);
var600 = var602;
varonce599 = var600;
}
((struct instance_core__NativeArray*)var598)->values[1]=var600;
} else {
var598 = varonce597;
varonce597 = NULL;
}
{
var603 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var604 = ((val*(*)(val* self))(var603->class->vft[COLOR_core__abstract_text__Object__to_s]))(var603); /* to_s on <var603:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var598)->values[0]=var604;
{
var605 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var606 = ((val*(*)(val* self))(var605->class->vft[COLOR_core__abstract_text__Object__to_s]))(var605); /* to_s on <var605:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var598)->values[2]=var606;
{
var607 = ((val*(*)(val* self))(var598->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var598); /* native_to_s on <var598:NativeArray[String]>*/
}
varonce597 = var598;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2323);
fatal_exit(1);
}
{
var608 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var607, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var608); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce609!=NULL)) {
var610 = varonce609;
} else {
var611 = "to_i";
var612 = core__flat___NativeString___to_s_full(var611, 4l, 4l);
var610 = var612;
varonce609 = var610;
}
{
var613 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var610); /* == on <var_pname:String>*/
}
if (var613){
if (unlikely(varonce614==NULL)) {
var615 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce616!=NULL)) {
var617 = varonce616;
} else {
var618 = "-\'0\'";
var619 = core__flat___NativeString___to_s_full(var618, 4l, 4l);
var617 = var619;
varonce616 = var617;
}
((struct instance_core__NativeArray*)var615)->values[1]=var617;
} else {
var615 = varonce614;
varonce614 = NULL;
}
{
var620 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var621 = ((val*(*)(val* self))(var620->class->vft[COLOR_core__abstract_text__Object__to_s]))(var620); /* to_s on <var620:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var615)->values[0]=var621;
{
var622 = ((val*(*)(val* self))(var615->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var615); /* native_to_s on <var615:NativeArray[String]>*/
}
varonce614 = var615;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2326);
fatal_exit(1);
}
{
var623 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var622, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var623); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce624!=NULL)) {
var625 = varonce624;
} else {
var626 = "code_point";
var627 = core__flat___NativeString___to_s_full(var626, 10l, 10l);
var625 = var627;
varonce624 = var625;
}
{
var628 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var625); /* == on <var_pname:String>*/
}
if (var628){
if (unlikely(varonce629==NULL)) {
var630 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce631!=NULL)) {
var632 = varonce631;
} else {
var633 = "(long)";
var634 = core__flat___NativeString___to_s_full(var633, 6l, 6l);
var632 = var634;
varonce631 = var632;
}
((struct instance_core__NativeArray*)var630)->values[0]=var632;
} else {
var630 = varonce629;
varonce629 = NULL;
}
{
var635 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var636 = ((val*(*)(val* self))(var635->class->vft[COLOR_core__abstract_text__Object__to_s]))(var635); /* to_s on <var635:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var630)->values[1]=var636;
{
var637 = ((val*(*)(val* self))(var630->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var630); /* native_to_s on <var630:NativeArray[String]>*/
}
varonce629 = var630;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2329);
fatal_exit(1);
}
{
var638 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var637, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var638); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
}
}
}
}
}
}
}
}
}
}
}
} else {
if (likely(varonce639!=NULL)) {
var640 = varonce639;
} else {
var641 = "Byte";
var642 = core__flat___NativeString___to_s_full(var641, 4l, 4l);
var640 = var642;
varonce639 = var640;
}
{
var643 = ((short int(*)(val* self, val* p0))(var_cname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_cname, var640); /* == on <var_cname:String>*/
}
if (var643){
if (likely(varonce644!=NULL)) {
var645 = varonce644;
} else {
var646 = "output";
var647 = core__flat___NativeString___to_s_full(var646, 6l, 6l);
var645 = var647;
varonce644 = var645;
}
{
var648 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var645); /* == on <var_pname:String>*/
}
if (var648){
if (unlikely(varonce649==NULL)) {
var650 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce651!=NULL)) {
var652 = varonce651;
} else {
var653 = "printf(\"%x\\n\", ";
var654 = core__flat___NativeString___to_s_full(var653, 15l, 15l);
var652 = var654;
varonce651 = var652;
}
((struct instance_core__NativeArray*)var650)->values[0]=var652;
if (likely(varonce655!=NULL)) {
var656 = varonce655;
} else {
var657 = ");";
var658 = core__flat___NativeString___to_s_full(var657, 2l, 2l);
var656 = var658;
varonce655 = var656;
}
((struct instance_core__NativeArray*)var650)->values[2]=var656;
} else {
var650 = varonce649;
varonce649 = NULL;
}
{
var659 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var660 = ((val*(*)(val* self))(var659->class->vft[COLOR_core__abstract_text__Object__to_s]))(var659); /* to_s on <var659:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var650)->values[1]=var660;
{
var661 = ((val*(*)(val* self))(var650->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var650); /* native_to_s on <var650:NativeArray[String]>*/
}
varonce649 = var650;
{
nitc___nitc__AbstractCompilerVisitor___add(var_v, var661); /* Direct call abstract_compiler#AbstractCompilerVisitor#add on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce662!=NULL)) {
var663 = varonce662;
} else {
var664 = "object_id";
var665 = core__flat___NativeString___to_s_full(var664, 9l, 9l);
var663 = var665;
varonce662 = var663;
}
{
var666 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var663); /* == on <var_pname:String>*/
}
if (var666){
if (unlikely(varonce667==NULL)) {
var668 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce669!=NULL)) {
var670 = varonce669;
} else {
var671 = "(long)";
var672 = core__flat___NativeString___to_s_full(var671, 6l, 6l);
var670 = var672;
varonce669 = var670;
}
((struct instance_core__NativeArray*)var668)->values[0]=var670;
} else {
var668 = varonce667;
varonce667 = NULL;
}
{
var673 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var674 = ((val*(*)(val* self))(var673->class->vft[COLOR_core__abstract_text__Object__to_s]))(var673); /* to_s on <var673:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var668)->values[1]=var674;
{
var675 = ((val*(*)(val* self))(var668->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var668); /* native_to_s on <var668:NativeArray[String]>*/
}
varonce667 = var668;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2337);
fatal_exit(1);
}
{
var676 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var675, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var676); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce677!=NULL)) {
var678 = varonce677;
} else {
var679 = "+";
var680 = core__flat___NativeString___to_s_full(var679, 1l, 1l);
var678 = var680;
varonce677 = var678;
}
{
var681 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var678); /* == on <var_pname:String>*/
}
if (var681){
if (unlikely(varonce682==NULL)) {
var683 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce684!=NULL)) {
var685 = varonce684;
} else {
var686 = " + ";
var687 = core__flat___NativeString___to_s_full(var686, 3l, 3l);
var685 = var687;
varonce684 = var685;
}
((struct instance_core__NativeArray*)var683)->values[1]=var685;
} else {
var683 = varonce682;
varonce682 = NULL;
}
{
var688 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var689 = ((val*(*)(val* self))(var688->class->vft[COLOR_core__abstract_text__Object__to_s]))(var688); /* to_s on <var688:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var683)->values[0]=var689;
{
var690 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var691 = ((val*(*)(val* self))(var690->class->vft[COLOR_core__abstract_text__Object__to_s]))(var690); /* to_s on <var690:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var683)->values[2]=var691;
{
var692 = ((val*(*)(val* self))(var683->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var683); /* native_to_s on <var683:NativeArray[String]>*/
}
varonce682 = var683;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2340);
fatal_exit(1);
}
{
var693 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var692, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var693); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce694!=NULL)) {
var695 = varonce694;
} else {
var696 = "-";
var697 = core__flat___NativeString___to_s_full(var696, 1l, 1l);
var695 = var697;
varonce694 = var695;
}
{
var698 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var695); /* == on <var_pname:String>*/
}
if (var698){
if (unlikely(varonce699==NULL)) {
var700 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce701!=NULL)) {
var702 = varonce701;
} else {
var703 = " - ";
var704 = core__flat___NativeString___to_s_full(var703, 3l, 3l);
var702 = var704;
varonce701 = var702;
}
((struct instance_core__NativeArray*)var700)->values[1]=var702;
} else {
var700 = varonce699;
varonce699 = NULL;
}
{
var705 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var706 = ((val*(*)(val* self))(var705->class->vft[COLOR_core__abstract_text__Object__to_s]))(var705); /* to_s on <var705:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var700)->values[0]=var706;
{
var707 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var708 = ((val*(*)(val* self))(var707->class->vft[COLOR_core__abstract_text__Object__to_s]))(var707); /* to_s on <var707:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var700)->values[2]=var708;
{
var709 = ((val*(*)(val* self))(var700->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var700); /* native_to_s on <var700:NativeArray[String]>*/
}
varonce699 = var700;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2343);
fatal_exit(1);
}
{
var710 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var709, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var710); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce711!=NULL)) {
var712 = varonce711;
} else {
var713 = "unary -";
var714 = core__flat___NativeString___to_s_full(var713, 7l, 7l);
var712 = var714;
varonce711 = var712;
}
{
var715 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var712); /* == on <var_pname:String>*/
}
if (var715){
if (unlikely(varonce716==NULL)) {
var717 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce718!=NULL)) {
var719 = varonce718;
} else {
var720 = "-";
var721 = core__flat___NativeString___to_s_full(var720, 1l, 1l);
var719 = var721;
varonce718 = var719;
}
((struct instance_core__NativeArray*)var717)->values[0]=var719;
} else {
var717 = varonce716;
varonce716 = NULL;
}
{
var722 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var723 = ((val*(*)(val* self))(var722->class->vft[COLOR_core__abstract_text__Object__to_s]))(var722); /* to_s on <var722:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var717)->values[1]=var723;
{
var724 = ((val*(*)(val* self))(var717->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var717); /* native_to_s on <var717:NativeArray[String]>*/
}
varonce716 = var717;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2346);
fatal_exit(1);
}
{
var725 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var724, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var725); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce726!=NULL)) {
var727 = varonce726;
} else {
var728 = "unary +";
var729 = core__flat___NativeString___to_s_full(var728, 7l, 7l);
var727 = var729;
varonce726 = var727;
}
{
var730 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var727); /* == on <var_pname:String>*/
}
if (var730){
{
var731 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var731); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce732!=NULL)) {
var733 = varonce732;
} else {
var734 = "*";
var735 = core__flat___NativeString___to_s_full(var734, 1l, 1l);
var733 = var735;
varonce732 = var733;
}
{
var736 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var733); /* == on <var_pname:String>*/
}
if (var736){
if (unlikely(varonce737==NULL)) {
var738 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce739!=NULL)) {
var740 = varonce739;
} else {
var741 = " * ";
var742 = core__flat___NativeString___to_s_full(var741, 3l, 3l);
var740 = var742;
varonce739 = var740;
}
((struct instance_core__NativeArray*)var738)->values[1]=var740;
} else {
var738 = varonce737;
varonce737 = NULL;
}
{
var743 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var744 = ((val*(*)(val* self))(var743->class->vft[COLOR_core__abstract_text__Object__to_s]))(var743); /* to_s on <var743:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var738)->values[0]=var744;
{
var745 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var746 = ((val*(*)(val* self))(var745->class->vft[COLOR_core__abstract_text__Object__to_s]))(var745); /* to_s on <var745:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var738)->values[2]=var746;
{
var747 = ((val*(*)(val* self))(var738->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var738); /* native_to_s on <var738:NativeArray[String]>*/
}
varonce737 = var738;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2352);
fatal_exit(1);
}
{
var748 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var747, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var748); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce749!=NULL)) {
var750 = varonce749;
} else {
var751 = "/";
var752 = core__flat___NativeString___to_s_full(var751, 1l, 1l);
var750 = var752;
varonce749 = var750;
}
{
var753 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var750); /* == on <var_pname:String>*/
}
if (var753){
if (unlikely(varonce754==NULL)) {
var755 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce756!=NULL)) {
var757 = varonce756;
} else {
var758 = " / ";
var759 = core__flat___NativeString___to_s_full(var758, 3l, 3l);
var757 = var759;
varonce756 = var757;
}
((struct instance_core__NativeArray*)var755)->values[1]=var757;
} else {
var755 = varonce754;
varonce754 = NULL;
}
{
var760 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var761 = ((val*(*)(val* self))(var760->class->vft[COLOR_core__abstract_text__Object__to_s]))(var760); /* to_s on <var760:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var755)->values[0]=var761;
{
var762 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var763 = ((val*(*)(val* self))(var762->class->vft[COLOR_core__abstract_text__Object__to_s]))(var762); /* to_s on <var762:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var755)->values[2]=var763;
{
var764 = ((val*(*)(val* self))(var755->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var755); /* native_to_s on <var755:NativeArray[String]>*/
}
varonce754 = var755;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2355);
fatal_exit(1);
}
{
var765 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var764, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var765); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce766!=NULL)) {
var767 = varonce766;
} else {
var768 = "%";
var769 = core__flat___NativeString___to_s_full(var768, 1l, 1l);
var767 = var769;
varonce766 = var767;
}
{
var770 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var767); /* == on <var_pname:String>*/
}
if (var770){
if (unlikely(varonce771==NULL)) {
var772 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce773!=NULL)) {
var774 = varonce773;
} else {
var775 = " % ";
var776 = core__flat___NativeString___to_s_full(var775, 3l, 3l);
var774 = var776;
varonce773 = var774;
}
((struct instance_core__NativeArray*)var772)->values[1]=var774;
} else {
var772 = varonce771;
varonce771 = NULL;
}
{
var777 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var778 = ((val*(*)(val* self))(var777->class->vft[COLOR_core__abstract_text__Object__to_s]))(var777); /* to_s on <var777:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var772)->values[0]=var778;
{
var779 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var780 = ((val*(*)(val* self))(var779->class->vft[COLOR_core__abstract_text__Object__to_s]))(var779); /* to_s on <var779:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var772)->values[2]=var780;
{
var781 = ((val*(*)(val* self))(var772->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var772); /* native_to_s on <var772:NativeArray[String]>*/
}
varonce771 = var772;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2358);
fatal_exit(1);
}
{
var782 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var781, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var782); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce783!=NULL)) {
var784 = varonce783;
} else {
var785 = "==";
var786 = core__flat___NativeString___to_s_full(var785, 2l, 2l);
var784 = var786;
varonce783 = var784;
}
{
var787 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var784); /* == on <var_pname:String>*/
}
if (var787){
{
var788 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var789 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var790 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var788, var789);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var790); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce791!=NULL)) {
var792 = varonce791;
} else {
var793 = "!=";
var794 = core__flat___NativeString___to_s_full(var793, 2l, 2l);
var792 = var794;
varonce791 = var792;
}
{
var795 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var792); /* == on <var_pname:String>*/
}
if (var795){
{
var796 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var797 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var798 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var796, var797);
}
var_res799 = var798;
if (unlikely(varonce800==NULL)) {
var801 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce802!=NULL)) {
var803 = varonce802;
} else {
var804 = "!";
var805 = core__flat___NativeString___to_s_full(var804, 1l, 1l);
var803 = var805;
varonce802 = var803;
}
((struct instance_core__NativeArray*)var801)->values[0]=var803;
} else {
var801 = varonce800;
varonce800 = NULL;
}
{
var806 = ((val*(*)(val* self))(var_res799->class->vft[COLOR_core__abstract_text__Object__to_s]))(var_res799); /* to_s on <var_res799:RuntimeVariable>*/
}
((struct instance_core__NativeArray*)var801)->values[1]=var806;
{
var807 = ((val*(*)(val* self))(var801->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var801); /* native_to_s on <var801:NativeArray[String]>*/
}
varonce800 = var801;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2365);
fatal_exit(1);
}
{
var808 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var807, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var808); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce809!=NULL)) {
var810 = varonce809;
} else {
var811 = "<";
var812 = core__flat___NativeString___to_s_full(var811, 1l, 1l);
var810 = var812;
varonce809 = var810;
}
{
var813 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var810); /* == on <var_pname:String>*/
}
if (var813){
if (unlikely(varonce814==NULL)) {
var815 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce816!=NULL)) {
var817 = varonce816;
} else {
var818 = " < ";
var819 = core__flat___NativeString___to_s_full(var818, 3l, 3l);
var817 = var819;
varonce816 = var817;
}
((struct instance_core__NativeArray*)var815)->values[1]=var817;
} else {
var815 = varonce814;
varonce814 = NULL;
}
{
var820 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var821 = ((val*(*)(val* self))(var820->class->vft[COLOR_core__abstract_text__Object__to_s]))(var820); /* to_s on <var820:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var815)->values[0]=var821;
{
var822 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var823 = ((val*(*)(val* self))(var822->class->vft[COLOR_core__abstract_text__Object__to_s]))(var822); /* to_s on <var822:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var815)->values[2]=var823;
{
var824 = ((val*(*)(val* self))(var815->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var815); /* native_to_s on <var815:NativeArray[String]>*/
}
varonce814 = var815;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2368);
fatal_exit(1);
}
{
var825 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var824, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var825); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce826!=NULL)) {
var827 = varonce826;
} else {
var828 = ">";
var829 = core__flat___NativeString___to_s_full(var828, 1l, 1l);
var827 = var829;
varonce826 = var827;
}
{
var830 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var827); /* == on <var_pname:String>*/
}
if (var830){
if (unlikely(varonce831==NULL)) {
var832 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce833!=NULL)) {
var834 = varonce833;
} else {
var835 = " > ";
var836 = core__flat___NativeString___to_s_full(var835, 3l, 3l);
var834 = var836;
varonce833 = var834;
}
((struct instance_core__NativeArray*)var832)->values[1]=var834;
} else {
var832 = varonce831;
varonce831 = NULL;
}
{
var837 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var838 = ((val*(*)(val* self))(var837->class->vft[COLOR_core__abstract_text__Object__to_s]))(var837); /* to_s on <var837:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var832)->values[0]=var838;
{
var839 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var840 = ((val*(*)(val* self))(var839->class->vft[COLOR_core__abstract_text__Object__to_s]))(var839); /* to_s on <var839:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var832)->values[2]=var840;
{
var841 = ((val*(*)(val* self))(var832->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var832); /* native_to_s on <var832:NativeArray[String]>*/
}
varonce831 = var832;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2371);
fatal_exit(1);
}
{
var842 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var841, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var842); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce843!=NULL)) {
var844 = varonce843;
} else {
var845 = "<=";
var846 = core__flat___NativeString___to_s_full(var845, 2l, 2l);
var844 = var846;
varonce843 = var844;
}
{
var847 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var844); /* == on <var_pname:String>*/
}
if (var847){
if (unlikely(varonce848==NULL)) {
var849 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce850!=NULL)) {
var851 = varonce850;
} else {
var852 = " <= ";
var853 = core__flat___NativeString___to_s_full(var852, 4l, 4l);
var851 = var853;
varonce850 = var851;
}
((struct instance_core__NativeArray*)var849)->values[1]=var851;
} else {
var849 = varonce848;
varonce848 = NULL;
}
{
var854 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var855 = ((val*(*)(val* self))(var854->class->vft[COLOR_core__abstract_text__Object__to_s]))(var854); /* to_s on <var854:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var849)->values[0]=var855;
{
var856 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var857 = ((val*(*)(val* self))(var856->class->vft[COLOR_core__abstract_text__Object__to_s]))(var856); /* to_s on <var856:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var849)->values[2]=var857;
{
var858 = ((val*(*)(val* self))(var849->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var849); /* native_to_s on <var849:NativeArray[String]>*/
}
varonce848 = var849;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2374);
fatal_exit(1);
}
{
var859 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var858, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var859); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce860!=NULL)) {
var861 = varonce860;
} else {
var862 = ">=";
var863 = core__flat___NativeString___to_s_full(var862, 2l, 2l);
var861 = var863;
varonce860 = var861;
}
{
var864 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var861); /* == on <var_pname:String>*/
}
if (var864){
if (unlikely(varonce865==NULL)) {
var866 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce867!=NULL)) {
var868 = varonce867;
} else {
var869 = " >= ";
var870 = core__flat___NativeString___to_s_full(var869, 4l, 4l);
var868 = var870;
varonce867 = var868;
}
((struct instance_core__NativeArray*)var866)->values[1]=var868;
} else {
var866 = varonce865;
varonce865 = NULL;
}
{
var871 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var872 = ((val*(*)(val* self))(var871->class->vft[COLOR_core__abstract_text__Object__to_s]))(var871); /* to_s on <var871:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var866)->values[0]=var872;
{
var873 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var874 = ((val*(*)(val* self))(var873->class->vft[COLOR_core__abstract_text__Object__to_s]))(var873); /* to_s on <var873:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var866)->values[2]=var874;
{
var875 = ((val*(*)(val* self))(var866->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var866); /* native_to_s on <var866:NativeArray[String]>*/
}
varonce865 = var866;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2377);
fatal_exit(1);
}
{
var876 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var875, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var876); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce877!=NULL)) {
var878 = varonce877;
} else {
var879 = ">>";
var880 = core__flat___NativeString___to_s_full(var879, 2l, 2l);
var878 = var880;
varonce877 = var878;
}
{
var881 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var878); /* == on <var_pname:String>*/
}
if (var881){
if (unlikely(varonce882==NULL)) {
var883 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce884!=NULL)) {
var885 = varonce884;
} else {
var886 = " >> ";
var887 = core__flat___NativeString___to_s_full(var886, 4l, 4l);
var885 = var887;
varonce884 = var885;
}
((struct instance_core__NativeArray*)var883)->values[1]=var885;
} else {
var883 = varonce882;
varonce882 = NULL;
}
{
var888 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var889 = ((val*(*)(val* self))(var888->class->vft[COLOR_core__abstract_text__Object__to_s]))(var888); /* to_s on <var888:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var883)->values[0]=var889;
{
var890 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var891 = ((val*(*)(val* self))(var890->class->vft[COLOR_core__abstract_text__Object__to_s]))(var890); /* to_s on <var890:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var883)->values[2]=var891;
{
var892 = ((val*(*)(val* self))(var883->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var883); /* native_to_s on <var883:NativeArray[String]>*/
}
varonce882 = var883;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2380);
fatal_exit(1);
}
{
var893 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var892, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var893); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce894!=NULL)) {
var895 = varonce894;
} else {
var896 = "<<";
var897 = core__flat___NativeString___to_s_full(var896, 2l, 2l);
var895 = var897;
varonce894 = var895;
}
{
var898 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var895); /* == on <var_pname:String>*/
}
if (var898){
if (unlikely(varonce899==NULL)) {
var900 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce901!=NULL)) {
var902 = varonce901;
} else {
var903 = " << ";
var904 = core__flat___NativeString___to_s_full(var903, 4l, 4l);
var902 = var904;
varonce901 = var902;
}
((struct instance_core__NativeArray*)var900)->values[1]=var902;
} else {
var900 = varonce899;
varonce899 = NULL;
}
{
var905 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var906 = ((val*(*)(val* self))(var905->class->vft[COLOR_core__abstract_text__Object__to_s]))(var905); /* to_s on <var905:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var900)->values[0]=var906;
{
var907 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var908 = ((val*(*)(val* self))(var907->class->vft[COLOR_core__abstract_text__Object__to_s]))(var907); /* to_s on <var907:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var900)->values[2]=var908;
{
var909 = ((val*(*)(val* self))(var900->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var900); /* native_to_s on <var900:NativeArray[String]>*/
}
varonce899 = var900;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2383);
fatal_exit(1);
}
{
var910 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var909, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var910); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce911!=NULL)) {
var912 = varonce911;
} else {
var913 = "&";
var914 = core__flat___NativeString___to_s_full(var913, 1l, 1l);
var912 = var914;
varonce911 = var912;
}
{
var915 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var912); /* == on <var_pname:String>*/
}
if (var915){
if (unlikely(varonce916==NULL)) {
var917 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce918!=NULL)) {
var919 = varonce918;
} else {
var920 = " & ";
var921 = core__flat___NativeString___to_s_full(var920, 3l, 3l);
var919 = var921;
varonce918 = var919;
}
((struct instance_core__NativeArray*)var917)->values[1]=var919;
} else {
var917 = varonce916;
varonce916 = NULL;
}
{
var922 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var923 = ((val*(*)(val* self))(var922->class->vft[COLOR_core__abstract_text__Object__to_s]))(var922); /* to_s on <var922:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var917)->values[0]=var923;
{
var924 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var925 = ((val*(*)(val* self))(var924->class->vft[COLOR_core__abstract_text__Object__to_s]))(var924); /* to_s on <var924:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var917)->values[2]=var925;
{
var926 = ((val*(*)(val* self))(var917->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var917); /* native_to_s on <var917:NativeArray[String]>*/
}
varonce916 = var917;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2386);
fatal_exit(1);
}
{
var927 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var926, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var927); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce928!=NULL)) {
var929 = varonce928;
} else {
var930 = "to_i";
var931 = core__flat___NativeString___to_s_full(var930, 4l, 4l);
var929 = var931;
varonce928 = var929;
}
{
var932 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var929); /* == on <var_pname:String>*/
}
if (var932){
if (unlikely(varonce933==NULL)) {
var934 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce935!=NULL)) {
var936 = varonce935;
} else {
var937 = "(long)";
var938 = core__flat___NativeString___to_s_full(var937, 6l, 6l);
var936 = var938;
varonce935 = var936;
}
((struct instance_core__NativeArray*)var934)->values[0]=var936;
} else {
var934 = varonce933;
varonce933 = NULL;
}
{
var939 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var940 = ((val*(*)(val* self))(var939->class->vft[COLOR_core__abstract_text__Object__to_s]))(var939); /* to_s on <var939:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var934)->values[1]=var940;
{
var941 = ((val*(*)(val* self))(var934->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var934); /* native_to_s on <var934:NativeArray[String]>*/
}
varonce933 = var934;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2389);
fatal_exit(1);
}
{
var942 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var941, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var942); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce943!=NULL)) {
var944 = varonce943;
} else {
var945 = "to_f";
var946 = core__flat___NativeString___to_s_full(var945, 4l, 4l);
var944 = var946;
varonce943 = var944;
}
{
var947 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var944); /* == on <var_pname:String>*/
}
if (var947){
if (unlikely(varonce948==NULL)) {
var949 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce950!=NULL)) {
var951 = varonce950;
} else {
var952 = "(double)";
var953 = core__flat___NativeString___to_s_full(var952, 8l, 8l);
var951 = var953;
varonce950 = var951;
}
((struct instance_core__NativeArray*)var949)->values[0]=var951;
} else {
var949 = varonce948;
varonce948 = NULL;
}
{
var954 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var955 = ((val*(*)(val* self))(var954->class->vft[COLOR_core__abstract_text__Object__to_s]))(var954); /* to_s on <var954:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var949)->values[1]=var955;
{
var956 = ((val*(*)(val* self))(var949->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var949); /* native_to_s on <var949:NativeArray[String]>*/
}
varonce948 = var949;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2392);
fatal_exit(1);
}
{
var957 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var956, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var957); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce958!=NULL)) {
var959 = varonce958;
} else {
var960 = "to_i8";
var961 = core__flat___NativeString___to_s_full(var960, 5l, 5l);
var959 = var961;
varonce958 = var959;
}
{
var962 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var959); /* == on <var_pname:String>*/
}
if (var962){
if (unlikely(varonce963==NULL)) {
var964 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce965!=NULL)) {
var966 = varonce965;
} else {
var967 = "(int8_t)";
var968 = core__flat___NativeString___to_s_full(var967, 8l, 8l);
var966 = var968;
varonce965 = var966;
}
((struct instance_core__NativeArray*)var964)->values[0]=var966;
} else {
var964 = varonce963;
varonce963 = NULL;
}
{
var969 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var970 = ((val*(*)(val* self))(var969->class->vft[COLOR_core__abstract_text__Object__to_s]))(var969); /* to_s on <var969:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var964)->values[1]=var970;
{
var971 = ((val*(*)(val* self))(var964->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var964); /* native_to_s on <var964:NativeArray[String]>*/
}
varonce963 = var964;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2395);
fatal_exit(1);
}
{
var972 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var971, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var972); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce973!=NULL)) {
var974 = varonce973;
} else {
var975 = "to_i16";
var976 = core__flat___NativeString___to_s_full(var975, 6l, 6l);
var974 = var976;
varonce973 = var974;
}
{
var977 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var974); /* == on <var_pname:String>*/
}
if (var977){
if (unlikely(varonce978==NULL)) {
var979 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce980!=NULL)) {
var981 = varonce980;
} else {
var982 = "(int16_t)";
var983 = core__flat___NativeString___to_s_full(var982, 9l, 9l);
var981 = var983;
varonce980 = var981;
}
((struct instance_core__NativeArray*)var979)->values[0]=var981;
} else {
var979 = varonce978;
varonce978 = NULL;
}
{
var984 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var985 = ((val*(*)(val* self))(var984->class->vft[COLOR_core__abstract_text__Object__to_s]))(var984); /* to_s on <var984:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var979)->values[1]=var985;
{
var986 = ((val*(*)(val* self))(var979->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var979); /* native_to_s on <var979:NativeArray[String]>*/
}
varonce978 = var979;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2398);
fatal_exit(1);
}
{
var987 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var986, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var987); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce988!=NULL)) {
var989 = varonce988;
} else {
var990 = "to_u16";
var991 = core__flat___NativeString___to_s_full(var990, 6l, 6l);
var989 = var991;
varonce988 = var989;
}
{
var992 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var989); /* == on <var_pname:String>*/
}
if (var992){
if (unlikely(varonce993==NULL)) {
var994 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce995!=NULL)) {
var996 = varonce995;
} else {
var997 = "(uint16_t)";
var998 = core__flat___NativeString___to_s_full(var997, 10l, 10l);
var996 = var998;
varonce995 = var996;
}
((struct instance_core__NativeArray*)var994)->values[0]=var996;
} else {
var994 = varonce993;
varonce993 = NULL;
}
{
var999 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1000 = ((val*(*)(val* self))(var999->class->vft[COLOR_core__abstract_text__Object__to_s]))(var999); /* to_s on <var999:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var994)->values[1]=var1000;
{
var1001 = ((val*(*)(val* self))(var994->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var994); /* native_to_s on <var994:NativeArray[String]>*/
}
varonce993 = var994;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2401);
fatal_exit(1);
}
{
var1002 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1001, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1002); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1003!=NULL)) {
var1004 = varonce1003;
} else {
var1005 = "to_i32";
var1006 = core__flat___NativeString___to_s_full(var1005, 6l, 6l);
var1004 = var1006;
varonce1003 = var1004;
}
{
var1007 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1004); /* == on <var_pname:String>*/
}
if (var1007){
if (unlikely(varonce1008==NULL)) {
var1009 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1010!=NULL)) {
var1011 = varonce1010;
} else {
var1012 = "(int32_t)";
var1013 = core__flat___NativeString___to_s_full(var1012, 9l, 9l);
var1011 = var1013;
varonce1010 = var1011;
}
((struct instance_core__NativeArray*)var1009)->values[0]=var1011;
} else {
var1009 = varonce1008;
varonce1008 = NULL;
}
{
var1014 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1015 = ((val*(*)(val* self))(var1014->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1014); /* to_s on <var1014:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1009)->values[1]=var1015;
{
var1016 = ((val*(*)(val* self))(var1009->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1009); /* native_to_s on <var1009:NativeArray[String]>*/
}
varonce1008 = var1009;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2404);
fatal_exit(1);
}
{
var1017 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1016, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1017); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1018!=NULL)) {
var1019 = varonce1018;
} else {
var1020 = "to_u32";
var1021 = core__flat___NativeString___to_s_full(var1020, 6l, 6l);
var1019 = var1021;
varonce1018 = var1019;
}
{
var1022 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1019); /* == on <var_pname:String>*/
}
if (var1022){
if (unlikely(varonce1023==NULL)) {
var1024 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1025!=NULL)) {
var1026 = varonce1025;
} else {
var1027 = "(uint32_t)";
var1028 = core__flat___NativeString___to_s_full(var1027, 10l, 10l);
var1026 = var1028;
varonce1025 = var1026;
}
((struct instance_core__NativeArray*)var1024)->values[0]=var1026;
} else {
var1024 = varonce1023;
varonce1023 = NULL;
}
{
var1029 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1030 = ((val*(*)(val* self))(var1029->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1029); /* to_s on <var1029:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1024)->values[1]=var1030;
{
var1031 = ((val*(*)(val* self))(var1024->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1024); /* native_to_s on <var1024:NativeArray[String]>*/
}
varonce1023 = var1024;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2407);
fatal_exit(1);
}
{
var1032 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1031, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1032); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1033!=NULL)) {
var1034 = varonce1033;
} else {
var1035 = "ascii";
var1036 = core__flat___NativeString___to_s_full(var1035, 5l, 5l);
var1034 = var1036;
varonce1033 = var1034;
}
{
var1037 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1034); /* == on <var_pname:String>*/
}
if (var1037){
if (unlikely(varonce1038==NULL)) {
var1039 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1040!=NULL)) {
var1041 = varonce1040;
} else {
var1042 = "(uint32_t)";
var1043 = core__flat___NativeString___to_s_full(var1042, 10l, 10l);
var1041 = var1043;
varonce1040 = var1041;
}
((struct instance_core__NativeArray*)var1039)->values[0]=var1041;
} else {
var1039 = varonce1038;
varonce1038 = NULL;
}
{
var1044 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1045 = ((val*(*)(val* self))(var1044->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1044); /* to_s on <var1044:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1039)->values[1]=var1045;
{
var1046 = ((val*(*)(val* self))(var1039->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1039); /* native_to_s on <var1039:NativeArray[String]>*/
}
varonce1038 = var1039;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2410);
fatal_exit(1);
}
{
var1047 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1046, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1047); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
} else {
if (likely(varonce1048!=NULL)) {
var1049 = varonce1048;
} else {
var1050 = "Bool";
var1051 = core__flat___NativeString___to_s_full(var1050, 4l, 4l);
var1049 = var1051;
varonce1048 = var1049;
}
{
var1052 = ((short int(*)(val* self, val* p0))(var_cname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_cname, var1049); /* == on <var_cname:String>*/
}
if (var1052){
if (likely(varonce1053!=NULL)) {
var1054 = varonce1053;
} else {
var1055 = "output";
var1056 = core__flat___NativeString___to_s_full(var1055, 6l, 6l);
var1054 = var1056;
varonce1053 = var1054;
}
{
var1057 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1054); /* == on <var_pname:String>*/
}
if (var1057){
if (unlikely(varonce1058==NULL)) {
var1059 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1060!=NULL)) {
var1061 = varonce1060;
} else {
var1062 = "printf(";
var1063 = core__flat___NativeString___to_s_full(var1062, 7l, 7l);
var1061 = var1063;
varonce1060 = var1061;
}
((struct instance_core__NativeArray*)var1059)->values[0]=var1061;
if (likely(varonce1064!=NULL)) {
var1065 = varonce1064;
} else {
var1066 = "?\"true\\n\":\"false\\n\");";
var1067 = core__flat___NativeString___to_s_full(var1066, 21l, 21l);
var1065 = var1067;
varonce1064 = var1065;
}
((struct instance_core__NativeArray*)var1059)->values[2]=var1065;
} else {
var1059 = varonce1058;
varonce1058 = NULL;
}
{
var1068 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var1069 = ((val*(*)(val* self))(var1068->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1068); /* to_s on <var1068:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1059)->values[1]=var1069;
{
var1070 = ((val*(*)(val* self))(var1059->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1059); /* native_to_s on <var1059:NativeArray[String]>*/
}
varonce1058 = var1059;
{
nitc___nitc__AbstractCompilerVisitor___add(var_v, var1070); /* Direct call abstract_compiler#AbstractCompilerVisitor#add on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1071!=NULL)) {
var1072 = varonce1071;
} else {
var1073 = "object_id";
var1074 = core__flat___NativeString___to_s_full(var1073, 9l, 9l);
var1072 = var1074;
varonce1071 = var1072;
}
{
var1075 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1072); /* == on <var_pname:String>*/
}
if (var1075){
if (unlikely(varonce1076==NULL)) {
var1077 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1078!=NULL)) {
var1079 = varonce1078;
} else {
var1080 = "(long)";
var1081 = core__flat___NativeString___to_s_full(var1080, 6l, 6l);
var1079 = var1081;
varonce1078 = var1079;
}
((struct instance_core__NativeArray*)var1077)->values[0]=var1079;
} else {
var1077 = varonce1076;
varonce1076 = NULL;
}
{
var1082 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var1083 = ((val*(*)(val* self))(var1082->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1082); /* to_s on <var1082:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1077)->values[1]=var1083;
{
var1084 = ((val*(*)(val* self))(var1077->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1077); /* native_to_s on <var1077:NativeArray[String]>*/
}
varonce1076 = var1077;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2418);
fatal_exit(1);
}
{
var1085 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1084, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1085); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1086!=NULL)) {
var1087 = varonce1086;
} else {
var1088 = "==";
var1089 = core__flat___NativeString___to_s_full(var1088, 2l, 2l);
var1087 = var1089;
varonce1086 = var1087;
}
{
var1090 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1087); /* == on <var_pname:String>*/
}
if (var1090){
{
var1091 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1092 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1093 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var1091, var1092);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1093); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1094!=NULL)) {
var1095 = varonce1094;
} else {
var1096 = "!=";
var1097 = core__flat___NativeString___to_s_full(var1096, 2l, 2l);
var1095 = var1097;
varonce1094 = var1095;
}
{
var1098 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1095); /* == on <var_pname:String>*/
}
if (var1098){
{
var1099 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1100 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1101 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var1099, var1100);
}
var_res1102 = var1101;
if (unlikely(varonce1103==NULL)) {
var1104 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1105!=NULL)) {
var1106 = varonce1105;
} else {
var1107 = "!";
var1108 = core__flat___NativeString___to_s_full(var1107, 1l, 1l);
var1106 = var1108;
varonce1105 = var1106;
}
((struct instance_core__NativeArray*)var1104)->values[0]=var1106;
} else {
var1104 = varonce1103;
varonce1103 = NULL;
}
{
var1109 = ((val*(*)(val* self))(var_res1102->class->vft[COLOR_core__abstract_text__Object__to_s]))(var_res1102); /* to_s on <var_res1102:RuntimeVariable>*/
}
((struct instance_core__NativeArray*)var1104)->values[1]=var1109;
{
var1110 = ((val*(*)(val* self))(var1104->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1104); /* native_to_s on <var1104:NativeArray[String]>*/
}
varonce1103 = var1104;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2425);
fatal_exit(1);
}
{
var1111 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1110, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1111); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
}
}
}
}
} else {
if (likely(varonce1112!=NULL)) {
var1113 = varonce1112;
} else {
var1114 = "Float";
var1115 = core__flat___NativeString___to_s_full(var1114, 5l, 5l);
var1113 = var1115;
varonce1112 = var1113;
}
{
var1116 = ((short int(*)(val* self, val* p0))(var_cname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_cname, var1113); /* == on <var_cname:String>*/
}
if (var1116){
if (likely(varonce1117!=NULL)) {
var1118 = varonce1117;
} else {
var1119 = "output";
var1120 = core__flat___NativeString___to_s_full(var1119, 6l, 6l);
var1118 = var1120;
varonce1117 = var1118;
}
{
var1121 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1118); /* == on <var_pname:String>*/
}
if (var1121){
if (unlikely(varonce1122==NULL)) {
var1123 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1124!=NULL)) {
var1125 = varonce1124;
} else {
var1126 = "printf(\"%f\\n\", ";
var1127 = core__flat___NativeString___to_s_full(var1126, 15l, 15l);
var1125 = var1127;
varonce1124 = var1125;
}
((struct instance_core__NativeArray*)var1123)->values[0]=var1125;
if (likely(varonce1128!=NULL)) {
var1129 = varonce1128;
} else {
var1130 = ");";
var1131 = core__flat___NativeString___to_s_full(var1130, 2l, 2l);
var1129 = var1131;
varonce1128 = var1129;
}
((struct instance_core__NativeArray*)var1123)->values[2]=var1129;
} else {
var1123 = varonce1122;
varonce1122 = NULL;
}
{
var1132 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var1133 = ((val*(*)(val* self))(var1132->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1132); /* to_s on <var1132:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1123)->values[1]=var1133;
{
var1134 = ((val*(*)(val* self))(var1123->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1123); /* native_to_s on <var1123:NativeArray[String]>*/
}
varonce1122 = var1123;
{
nitc___nitc__AbstractCompilerVisitor___add(var_v, var1134); /* Direct call abstract_compiler#AbstractCompilerVisitor#add on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1135!=NULL)) {
var1136 = varonce1135;
} else {
var1137 = "object_id";
var1138 = core__flat___NativeString___to_s_full(var1137, 9l, 9l);
var1136 = var1138;
varonce1135 = var1136;
}
{
var1139 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1136); /* == on <var_pname:String>*/
}
if (var1139){
if (unlikely(varonce1140==NULL)) {
var1141 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1142!=NULL)) {
var1143 = varonce1142;
} else {
var1144 = "(double)";
var1145 = core__flat___NativeString___to_s_full(var1144, 8l, 8l);
var1143 = var1145;
varonce1142 = var1143;
}
((struct instance_core__NativeArray*)var1141)->values[0]=var1143;
} else {
var1141 = varonce1140;
varonce1140 = NULL;
}
{
var1146 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var1147 = ((val*(*)(val* self))(var1146->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1146); /* to_s on <var1146:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1141)->values[1]=var1147;
{
var1148 = ((val*(*)(val* self))(var1141->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1141); /* native_to_s on <var1141:NativeArray[String]>*/
}
varonce1140 = var1141;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2433);
fatal_exit(1);
}
{
var1149 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1148, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1149); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1150!=NULL)) {
var1151 = varonce1150;
} else {
var1152 = "+";
var1153 = core__flat___NativeString___to_s_full(var1152, 1l, 1l);
var1151 = var1153;
varonce1150 = var1151;
}
{
var1154 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1151); /* == on <var_pname:String>*/
}
if (var1154){
if (unlikely(varonce1155==NULL)) {
var1156 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1157!=NULL)) {
var1158 = varonce1157;
} else {
var1159 = " + ";
var1160 = core__flat___NativeString___to_s_full(var1159, 3l, 3l);
var1158 = var1160;
varonce1157 = var1158;
}
((struct instance_core__NativeArray*)var1156)->values[1]=var1158;
} else {
var1156 = varonce1155;
varonce1155 = NULL;
}
{
var1161 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1162 = ((val*(*)(val* self))(var1161->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1161); /* to_s on <var1161:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1156)->values[0]=var1162;
{
var1163 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1164 = ((val*(*)(val* self))(var1163->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1163); /* to_s on <var1163:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1156)->values[2]=var1164;
{
var1165 = ((val*(*)(val* self))(var1156->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1156); /* native_to_s on <var1156:NativeArray[String]>*/
}
varonce1155 = var1156;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2436);
fatal_exit(1);
}
{
var1166 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1165, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1166); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1167!=NULL)) {
var1168 = varonce1167;
} else {
var1169 = "-";
var1170 = core__flat___NativeString___to_s_full(var1169, 1l, 1l);
var1168 = var1170;
varonce1167 = var1168;
}
{
var1171 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1168); /* == on <var_pname:String>*/
}
if (var1171){
if (unlikely(varonce1172==NULL)) {
var1173 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1174!=NULL)) {
var1175 = varonce1174;
} else {
var1176 = " - ";
var1177 = core__flat___NativeString___to_s_full(var1176, 3l, 3l);
var1175 = var1177;
varonce1174 = var1175;
}
((struct instance_core__NativeArray*)var1173)->values[1]=var1175;
} else {
var1173 = varonce1172;
varonce1172 = NULL;
}
{
var1178 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1179 = ((val*(*)(val* self))(var1178->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1178); /* to_s on <var1178:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1173)->values[0]=var1179;
{
var1180 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1181 = ((val*(*)(val* self))(var1180->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1180); /* to_s on <var1180:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1173)->values[2]=var1181;
{
var1182 = ((val*(*)(val* self))(var1173->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1173); /* native_to_s on <var1173:NativeArray[String]>*/
}
varonce1172 = var1173;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2439);
fatal_exit(1);
}
{
var1183 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1182, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1183); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1184!=NULL)) {
var1185 = varonce1184;
} else {
var1186 = "unary -";
var1187 = core__flat___NativeString___to_s_full(var1186, 7l, 7l);
var1185 = var1187;
varonce1184 = var1185;
}
{
var1188 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1185); /* == on <var_pname:String>*/
}
if (var1188){
if (unlikely(varonce1189==NULL)) {
var1190 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1191!=NULL)) {
var1192 = varonce1191;
} else {
var1193 = "-";
var1194 = core__flat___NativeString___to_s_full(var1193, 1l, 1l);
var1192 = var1194;
varonce1191 = var1192;
}
((struct instance_core__NativeArray*)var1190)->values[0]=var1192;
} else {
var1190 = varonce1189;
varonce1189 = NULL;
}
{
var1195 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1196 = ((val*(*)(val* self))(var1195->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1195); /* to_s on <var1195:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1190)->values[1]=var1196;
{
var1197 = ((val*(*)(val* self))(var1190->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1190); /* native_to_s on <var1190:NativeArray[String]>*/
}
varonce1189 = var1190;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2442);
fatal_exit(1);
}
{
var1198 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1197, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1198); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1199!=NULL)) {
var1200 = varonce1199;
} else {
var1201 = "unary +";
var1202 = core__flat___NativeString___to_s_full(var1201, 7l, 7l);
var1200 = var1202;
varonce1199 = var1200;
}
{
var1203 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1200); /* == on <var_pname:String>*/
}
if (var1203){
{
var1204 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1204); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1205!=NULL)) {
var1206 = varonce1205;
} else {
var1207 = "succ";
var1208 = core__flat___NativeString___to_s_full(var1207, 4l, 4l);
var1206 = var1208;
varonce1205 = var1206;
}
{
var1209 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1206); /* == on <var_pname:String>*/
}
if (var1209){
if (unlikely(varonce1210==NULL)) {
var1211 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1212!=NULL)) {
var1213 = varonce1212;
} else {
var1214 = "+1";
var1215 = core__flat___NativeString___to_s_full(var1214, 2l, 2l);
var1213 = var1215;
varonce1212 = var1213;
}
((struct instance_core__NativeArray*)var1211)->values[1]=var1213;
} else {
var1211 = varonce1210;
varonce1210 = NULL;
}
{
var1216 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1217 = ((val*(*)(val* self))(var1216->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1216); /* to_s on <var1216:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1211)->values[0]=var1217;
{
var1218 = ((val*(*)(val* self))(var1211->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1211); /* native_to_s on <var1211:NativeArray[String]>*/
}
varonce1210 = var1211;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2448);
fatal_exit(1);
}
{
var1219 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1218, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1219); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1220!=NULL)) {
var1221 = varonce1220;
} else {
var1222 = "prec";
var1223 = core__flat___NativeString___to_s_full(var1222, 4l, 4l);
var1221 = var1223;
varonce1220 = var1221;
}
{
var1224 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1221); /* == on <var_pname:String>*/
}
if (var1224){
if (unlikely(varonce1225==NULL)) {
var1226 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1227!=NULL)) {
var1228 = varonce1227;
} else {
var1229 = "-1";
var1230 = core__flat___NativeString___to_s_full(var1229, 2l, 2l);
var1228 = var1230;
varonce1227 = var1228;
}
((struct instance_core__NativeArray*)var1226)->values[1]=var1228;
} else {
var1226 = varonce1225;
varonce1225 = NULL;
}
{
var1231 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1232 = ((val*(*)(val* self))(var1231->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1231); /* to_s on <var1231:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1226)->values[0]=var1232;
{
var1233 = ((val*(*)(val* self))(var1226->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1226); /* native_to_s on <var1226:NativeArray[String]>*/
}
varonce1225 = var1226;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2451);
fatal_exit(1);
}
{
var1234 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1233, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1234); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1235!=NULL)) {
var1236 = varonce1235;
} else {
var1237 = "*";
var1238 = core__flat___NativeString___to_s_full(var1237, 1l, 1l);
var1236 = var1238;
varonce1235 = var1236;
}
{
var1239 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1236); /* == on <var_pname:String>*/
}
if (var1239){
if (unlikely(varonce1240==NULL)) {
var1241 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1242!=NULL)) {
var1243 = varonce1242;
} else {
var1244 = " * ";
var1245 = core__flat___NativeString___to_s_full(var1244, 3l, 3l);
var1243 = var1245;
varonce1242 = var1243;
}
((struct instance_core__NativeArray*)var1241)->values[1]=var1243;
} else {
var1241 = varonce1240;
varonce1240 = NULL;
}
{
var1246 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1247 = ((val*(*)(val* self))(var1246->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1246); /* to_s on <var1246:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1241)->values[0]=var1247;
{
var1248 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1249 = ((val*(*)(val* self))(var1248->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1248); /* to_s on <var1248:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1241)->values[2]=var1249;
{
var1250 = ((val*(*)(val* self))(var1241->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1241); /* native_to_s on <var1241:NativeArray[String]>*/
}
varonce1240 = var1241;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2454);
fatal_exit(1);
}
{
var1251 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1250, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1251); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1252!=NULL)) {
var1253 = varonce1252;
} else {
var1254 = "/";
var1255 = core__flat___NativeString___to_s_full(var1254, 1l, 1l);
var1253 = var1255;
varonce1252 = var1253;
}
{
var1256 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1253); /* == on <var_pname:String>*/
}
if (var1256){
if (unlikely(varonce1257==NULL)) {
var1258 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1259!=NULL)) {
var1260 = varonce1259;
} else {
var1261 = " / ";
var1262 = core__flat___NativeString___to_s_full(var1261, 3l, 3l);
var1260 = var1262;
varonce1259 = var1260;
}
((struct instance_core__NativeArray*)var1258)->values[1]=var1260;
} else {
var1258 = varonce1257;
varonce1257 = NULL;
}
{
var1263 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1264 = ((val*(*)(val* self))(var1263->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1263); /* to_s on <var1263:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1258)->values[0]=var1264;
{
var1265 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1266 = ((val*(*)(val* self))(var1265->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1265); /* to_s on <var1265:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1258)->values[2]=var1266;
{
var1267 = ((val*(*)(val* self))(var1258->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1258); /* native_to_s on <var1258:NativeArray[String]>*/
}
varonce1257 = var1258;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2457);
fatal_exit(1);
}
{
var1268 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1267, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1268); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1269!=NULL)) {
var1270 = varonce1269;
} else {
var1271 = "==";
var1272 = core__flat___NativeString___to_s_full(var1271, 2l, 2l);
var1270 = var1272;
varonce1269 = var1270;
}
{
var1273 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1270); /* == on <var_pname:String>*/
}
if (var1273){
{
var1274 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1275 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1276 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var1274, var1275);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1276); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1277!=NULL)) {
var1278 = varonce1277;
} else {
var1279 = "!=";
var1280 = core__flat___NativeString___to_s_full(var1279, 2l, 2l);
var1278 = var1280;
varonce1277 = var1278;
}
{
var1281 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1278); /* == on <var_pname:String>*/
}
if (var1281){
{
var1282 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1283 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1284 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var1282, var1283);
}
var_res1285 = var1284;
if (unlikely(varonce1286==NULL)) {
var1287 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1288!=NULL)) {
var1289 = varonce1288;
} else {
var1290 = "!";
var1291 = core__flat___NativeString___to_s_full(var1290, 1l, 1l);
var1289 = var1291;
varonce1288 = var1289;
}
((struct instance_core__NativeArray*)var1287)->values[0]=var1289;
} else {
var1287 = varonce1286;
varonce1286 = NULL;
}
{
var1292 = ((val*(*)(val* self))(var_res1285->class->vft[COLOR_core__abstract_text__Object__to_s]))(var_res1285); /* to_s on <var_res1285:RuntimeVariable>*/
}
((struct instance_core__NativeArray*)var1287)->values[1]=var1292;
{
var1293 = ((val*(*)(val* self))(var1287->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1287); /* native_to_s on <var1287:NativeArray[String]>*/
}
varonce1286 = var1287;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2464);
fatal_exit(1);
}
{
var1294 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1293, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1294); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1295!=NULL)) {
var1296 = varonce1295;
} else {
var1297 = "<";
var1298 = core__flat___NativeString___to_s_full(var1297, 1l, 1l);
var1296 = var1298;
varonce1295 = var1296;
}
{
var1299 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1296); /* == on <var_pname:String>*/
}
if (var1299){
if (unlikely(varonce1300==NULL)) {
var1301 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1302!=NULL)) {
var1303 = varonce1302;
} else {
var1304 = " < ";
var1305 = core__flat___NativeString___to_s_full(var1304, 3l, 3l);
var1303 = var1305;
varonce1302 = var1303;
}
((struct instance_core__NativeArray*)var1301)->values[1]=var1303;
} else {
var1301 = varonce1300;
varonce1300 = NULL;
}
{
var1306 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1307 = ((val*(*)(val* self))(var1306->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1306); /* to_s on <var1306:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1301)->values[0]=var1307;
{
var1308 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1309 = ((val*(*)(val* self))(var1308->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1308); /* to_s on <var1308:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1301)->values[2]=var1309;
{
var1310 = ((val*(*)(val* self))(var1301->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1301); /* native_to_s on <var1301:NativeArray[String]>*/
}
varonce1300 = var1301;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2467);
fatal_exit(1);
}
{
var1311 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1310, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1311); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1312!=NULL)) {
var1313 = varonce1312;
} else {
var1314 = ">";
var1315 = core__flat___NativeString___to_s_full(var1314, 1l, 1l);
var1313 = var1315;
varonce1312 = var1313;
}
{
var1316 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1313); /* == on <var_pname:String>*/
}
if (var1316){
if (unlikely(varonce1317==NULL)) {
var1318 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1319!=NULL)) {
var1320 = varonce1319;
} else {
var1321 = " > ";
var1322 = core__flat___NativeString___to_s_full(var1321, 3l, 3l);
var1320 = var1322;
varonce1319 = var1320;
}
((struct instance_core__NativeArray*)var1318)->values[1]=var1320;
} else {
var1318 = varonce1317;
varonce1317 = NULL;
}
{
var1323 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1324 = ((val*(*)(val* self))(var1323->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1323); /* to_s on <var1323:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1318)->values[0]=var1324;
{
var1325 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1326 = ((val*(*)(val* self))(var1325->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1325); /* to_s on <var1325:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1318)->values[2]=var1326;
{
var1327 = ((val*(*)(val* self))(var1318->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1318); /* native_to_s on <var1318:NativeArray[String]>*/
}
varonce1317 = var1318;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2470);
fatal_exit(1);
}
{
var1328 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1327, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1328); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1329!=NULL)) {
var1330 = varonce1329;
} else {
var1331 = "<=";
var1332 = core__flat___NativeString___to_s_full(var1331, 2l, 2l);
var1330 = var1332;
varonce1329 = var1330;
}
{
var1333 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1330); /* == on <var_pname:String>*/
}
if (var1333){
if (unlikely(varonce1334==NULL)) {
var1335 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1336!=NULL)) {
var1337 = varonce1336;
} else {
var1338 = " <= ";
var1339 = core__flat___NativeString___to_s_full(var1338, 4l, 4l);
var1337 = var1339;
varonce1336 = var1337;
}
((struct instance_core__NativeArray*)var1335)->values[1]=var1337;
} else {
var1335 = varonce1334;
varonce1334 = NULL;
}
{
var1340 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1341 = ((val*(*)(val* self))(var1340->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1340); /* to_s on <var1340:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1335)->values[0]=var1341;
{
var1342 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1343 = ((val*(*)(val* self))(var1342->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1342); /* to_s on <var1342:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1335)->values[2]=var1343;
{
var1344 = ((val*(*)(val* self))(var1335->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1335); /* native_to_s on <var1335:NativeArray[String]>*/
}
varonce1334 = var1335;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2473);
fatal_exit(1);
}
{
var1345 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1344, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1345); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1346!=NULL)) {
var1347 = varonce1346;
} else {
var1348 = ">=";
var1349 = core__flat___NativeString___to_s_full(var1348, 2l, 2l);
var1347 = var1349;
varonce1346 = var1347;
}
{
var1350 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1347); /* == on <var_pname:String>*/
}
if (var1350){
if (unlikely(varonce1351==NULL)) {
var1352 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1353!=NULL)) {
var1354 = varonce1353;
} else {
var1355 = " >= ";
var1356 = core__flat___NativeString___to_s_full(var1355, 4l, 4l);
var1354 = var1356;
varonce1353 = var1354;
}
((struct instance_core__NativeArray*)var1352)->values[1]=var1354;
} else {
var1352 = varonce1351;
varonce1351 = NULL;
}
{
var1357 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1358 = ((val*(*)(val* self))(var1357->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1357); /* to_s on <var1357:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1352)->values[0]=var1358;
{
var1359 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1360 = ((val*(*)(val* self))(var1359->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1359); /* to_s on <var1359:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1352)->values[2]=var1360;
{
var1361 = ((val*(*)(val* self))(var1352->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1352); /* native_to_s on <var1352:NativeArray[String]>*/
}
varonce1351 = var1352;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2476);
fatal_exit(1);
}
{
var1362 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1361, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1362); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1363!=NULL)) {
var1364 = varonce1363;
} else {
var1365 = "to_i";
var1366 = core__flat___NativeString___to_s_full(var1365, 4l, 4l);
var1364 = var1366;
varonce1363 = var1364;
}
{
var1367 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1364); /* == on <var_pname:String>*/
}
if (var1367){
if (unlikely(varonce1368==NULL)) {
var1369 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1370!=NULL)) {
var1371 = varonce1370;
} else {
var1372 = "(long)";
var1373 = core__flat___NativeString___to_s_full(var1372, 6l, 6l);
var1371 = var1373;
varonce1370 = var1371;
}
((struct instance_core__NativeArray*)var1369)->values[0]=var1371;
} else {
var1369 = varonce1368;
varonce1368 = NULL;
}
{
var1374 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1375 = ((val*(*)(val* self))(var1374->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1374); /* to_s on <var1374:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1369)->values[1]=var1375;
{
var1376 = ((val*(*)(val* self))(var1369->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1369); /* native_to_s on <var1369:NativeArray[String]>*/
}
varonce1368 = var1369;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2479);
fatal_exit(1);
}
{
var1377 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1376, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1377); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1378!=NULL)) {
var1379 = varonce1378;
} else {
var1380 = "to_b";
var1381 = core__flat___NativeString___to_s_full(var1380, 4l, 4l);
var1379 = var1381;
varonce1378 = var1379;
}
{
var1382 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1379); /* == on <var_pname:String>*/
}
if (var1382){
if (unlikely(varonce1383==NULL)) {
var1384 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1385!=NULL)) {
var1386 = varonce1385;
} else {
var1387 = "(unsigned char)";
var1388 = core__flat___NativeString___to_s_full(var1387, 15l, 15l);
var1386 = var1388;
varonce1385 = var1386;
}
((struct instance_core__NativeArray*)var1384)->values[0]=var1386;
} else {
var1384 = varonce1383;
varonce1383 = NULL;
}
{
var1389 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1390 = ((val*(*)(val* self))(var1389->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1389); /* to_s on <var1389:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1384)->values[1]=var1390;
{
var1391 = ((val*(*)(val* self))(var1384->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1384); /* native_to_s on <var1384:NativeArray[String]>*/
}
varonce1383 = var1384;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2482);
fatal_exit(1);
}
{
var1392 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1391, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1392); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1393!=NULL)) {
var1394 = varonce1393;
} else {
var1395 = "to_i8";
var1396 = core__flat___NativeString___to_s_full(var1395, 5l, 5l);
var1394 = var1396;
varonce1393 = var1394;
}
{
var1397 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1394); /* == on <var_pname:String>*/
}
if (var1397){
if (unlikely(varonce1398==NULL)) {
var1399 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1400!=NULL)) {
var1401 = varonce1400;
} else {
var1402 = "(int8_t)";
var1403 = core__flat___NativeString___to_s_full(var1402, 8l, 8l);
var1401 = var1403;
varonce1400 = var1401;
}
((struct instance_core__NativeArray*)var1399)->values[0]=var1401;
} else {
var1399 = varonce1398;
varonce1398 = NULL;
}
{
var1404 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1405 = ((val*(*)(val* self))(var1404->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1404); /* to_s on <var1404:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1399)->values[1]=var1405;
{
var1406 = ((val*(*)(val* self))(var1399->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1399); /* native_to_s on <var1399:NativeArray[String]>*/
}
varonce1398 = var1399;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2485);
fatal_exit(1);
}
{
var1407 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1406, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1407); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1408!=NULL)) {
var1409 = varonce1408;
} else {
var1410 = "to_i16";
var1411 = core__flat___NativeString___to_s_full(var1410, 6l, 6l);
var1409 = var1411;
varonce1408 = var1409;
}
{
var1412 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1409); /* == on <var_pname:String>*/
}
if (var1412){
if (unlikely(varonce1413==NULL)) {
var1414 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1415!=NULL)) {
var1416 = varonce1415;
} else {
var1417 = "(int16_t)";
var1418 = core__flat___NativeString___to_s_full(var1417, 9l, 9l);
var1416 = var1418;
varonce1415 = var1416;
}
((struct instance_core__NativeArray*)var1414)->values[0]=var1416;
} else {
var1414 = varonce1413;
varonce1413 = NULL;
}
{
var1419 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1420 = ((val*(*)(val* self))(var1419->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1419); /* to_s on <var1419:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1414)->values[1]=var1420;
{
var1421 = ((val*(*)(val* self))(var1414->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1414); /* native_to_s on <var1414:NativeArray[String]>*/
}
varonce1413 = var1414;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2488);
fatal_exit(1);
}
{
var1422 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1421, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1422); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1423!=NULL)) {
var1424 = varonce1423;
} else {
var1425 = "to_u16";
var1426 = core__flat___NativeString___to_s_full(var1425, 6l, 6l);
var1424 = var1426;
varonce1423 = var1424;
}
{
var1427 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1424); /* == on <var_pname:String>*/
}
if (var1427){
if (unlikely(varonce1428==NULL)) {
var1429 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1430!=NULL)) {
var1431 = varonce1430;
} else {
var1432 = "(uint16_t)";
var1433 = core__flat___NativeString___to_s_full(var1432, 10l, 10l);
var1431 = var1433;
varonce1430 = var1431;
}
((struct instance_core__NativeArray*)var1429)->values[0]=var1431;
} else {
var1429 = varonce1428;
varonce1428 = NULL;
}
{
var1434 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1435 = ((val*(*)(val* self))(var1434->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1434); /* to_s on <var1434:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1429)->values[1]=var1435;
{
var1436 = ((val*(*)(val* self))(var1429->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1429); /* native_to_s on <var1429:NativeArray[String]>*/
}
varonce1428 = var1429;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2491);
fatal_exit(1);
}
{
var1437 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1436, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1437); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1438!=NULL)) {
var1439 = varonce1438;
} else {
var1440 = "to_i32";
var1441 = core__flat___NativeString___to_s_full(var1440, 6l, 6l);
var1439 = var1441;
varonce1438 = var1439;
}
{
var1442 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1439); /* == on <var_pname:String>*/
}
if (var1442){
if (unlikely(varonce1443==NULL)) {
var1444 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1445!=NULL)) {
var1446 = varonce1445;
} else {
var1447 = "(int32_t)";
var1448 = core__flat___NativeString___to_s_full(var1447, 9l, 9l);
var1446 = var1448;
varonce1445 = var1446;
}
((struct instance_core__NativeArray*)var1444)->values[0]=var1446;
} else {
var1444 = varonce1443;
varonce1443 = NULL;
}
{
var1449 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1450 = ((val*(*)(val* self))(var1449->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1449); /* to_s on <var1449:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1444)->values[1]=var1450;
{
var1451 = ((val*(*)(val* self))(var1444->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1444); /* native_to_s on <var1444:NativeArray[String]>*/
}
varonce1443 = var1444;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2494);
fatal_exit(1);
}
{
var1452 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1451, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1452); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1453!=NULL)) {
var1454 = varonce1453;
} else {
var1455 = "to_u32";
var1456 = core__flat___NativeString___to_s_full(var1455, 6l, 6l);
var1454 = var1456;
varonce1453 = var1454;
}
{
var1457 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1454); /* == on <var_pname:String>*/
}
if (var1457){
if (unlikely(varonce1458==NULL)) {
var1459 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1460!=NULL)) {
var1461 = varonce1460;
} else {
var1462 = "(uint32_t)";
var1463 = core__flat___NativeString___to_s_full(var1462, 10l, 10l);
var1461 = var1463;
varonce1460 = var1461;
}
((struct instance_core__NativeArray*)var1459)->values[0]=var1461;
} else {
var1459 = varonce1458;
varonce1458 = NULL;
}
{
var1464 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1465 = ((val*(*)(val* self))(var1464->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1464); /* to_s on <var1464:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1459)->values[1]=var1465;
{
var1466 = ((val*(*)(val* self))(var1459->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1459); /* native_to_s on <var1459:NativeArray[String]>*/
}
varonce1458 = var1459;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2497);
fatal_exit(1);
}
{
var1467 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1466, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1467); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
} else {
if (likely(varonce1468!=NULL)) {
var1469 = varonce1468;
} else {
var1470 = "BufferedNativeString";
var1471 = core__flat___NativeString___to_s_full(var1470, 20l, 20l);
var1469 = var1471;
varonce1468 = var1469;
}
{
var1472 = ((short int(*)(val* self, val* p0))(var_cname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_cname, var1469); /* == on <var_cname:String>*/
}
if (var1472){
if (likely(varonce1473!=NULL)) {
var1474 = varonce1473;
} else {
var1475 = "new";
var1476 = core__flat___NativeString___to_s_full(var1475, 3l, 3l);
var1474 = var1476;
varonce1473 = var1474;
}
{
var1477 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1474); /* == on <var_pname:String>*/
}
if (var1477){
if (unlikely(varonce1478==NULL)) {
var1479 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1480!=NULL)) {
var1481 = varonce1480;
} else {
var1482 = "(nit_string*) nit_alloc(2 * sizeof(long) + ";
var1483 = core__flat___NativeString___to_s_full(var1482, 43l, 43l);
var1481 = var1483;
varonce1480 = var1481;
}
((struct instance_core__NativeArray*)var1479)->values[0]=var1481;
if (likely(varonce1484!=NULL)) {
var1485 = varonce1484;
} else {
var1486 = ")";
var1487 = core__flat___NativeString___to_s_full(var1486, 1l, 1l);
var1485 = var1487;
varonce1484 = var1485;
}
((struct instance_core__NativeArray*)var1479)->values[2]=var1485;
} else {
var1479 = varonce1478;
varonce1478 = NULL;
}
{
var1488 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1489 = ((val*(*)(val* self))(var1488->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1488); /* to_s on <var1488:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1479)->values[1]=var1489;
{
var1490 = ((val*(*)(val* self))(var1479->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1479); /* native_to_s on <var1479:NativeArray[String]>*/
}
varonce1478 = var1479;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2502);
fatal_exit(1);
}
{
var1491 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1490, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1491); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
} else {
}
} else {
if (likely(varonce1492!=NULL)) {
var1493 = varonce1492;
} else {
var1494 = "NativeString";
var1495 = core__flat___NativeString___to_s_full(var1494, 12l, 12l);
var1493 = var1495;
varonce1492 = var1493;
}
{
var1496 = ((short int(*)(val* self, val* p0))(var_cname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_cname, var1493); /* == on <var_cname:String>*/
}
if (var1496){
if (likely(varonce1497!=NULL)) {
var1498 = varonce1497;
} else {
var1499 = "[]";
var1500 = core__flat___NativeString___to_s_full(var1499, 2l, 2l);
var1498 = var1500;
varonce1497 = var1498;
}
{
var1501 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1498); /* == on <var_pname:String>*/
}
if (var1501){
if (unlikely(varonce1502==NULL)) {
var1503 = NEW_core__NativeArray(5l, &type_core__NativeArray__core__String);
if (likely(varonce1504!=NULL)) {
var1505 = varonce1504;
} else {
var1506 = "(unsigned char)((int)";
var1507 = core__flat___NativeString___to_s_full(var1506, 21l, 21l);
var1505 = var1507;
varonce1504 = var1505;
}
((struct instance_core__NativeArray*)var1503)->values[0]=var1505;
if (likely(varonce1508!=NULL)) {
var1509 = varonce1508;
} else {
var1510 = "[";
var1511 = core__flat___NativeString___to_s_full(var1510, 1l, 1l);
var1509 = var1511;
varonce1508 = var1509;
}
((struct instance_core__NativeArray*)var1503)->values[2]=var1509;
if (likely(varonce1512!=NULL)) {
var1513 = varonce1512;
} else {
var1514 = "])";
var1515 = core__flat___NativeString___to_s_full(var1514, 2l, 2l);
var1513 = var1515;
varonce1512 = var1513;
}
((struct instance_core__NativeArray*)var1503)->values[4]=var1513;
} else {
var1503 = varonce1502;
varonce1502 = NULL;
}
{
var1516 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1517 = ((val*(*)(val* self))(var1516->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1516); /* to_s on <var1516:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1503)->values[1]=var1517;
{
var1518 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1519 = ((val*(*)(val* self))(var1518->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1518); /* to_s on <var1518:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1503)->values[3]=var1519;
{
var1520 = ((val*(*)(val* self))(var1503->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1503); /* native_to_s on <var1503:NativeArray[String]>*/
}
varonce1502 = var1503;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2506);
fatal_exit(1);
}
{
var1521 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1520, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1521); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1522!=NULL)) {
var1523 = varonce1522;
} else {
var1524 = "[]=";
var1525 = core__flat___NativeString___to_s_full(var1524, 3l, 3l);
var1523 = var1525;
varonce1522 = var1523;
}
{
var1526 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1523); /* == on <var_pname:String>*/
}
if (var1526){
if (unlikely(varonce1527==NULL)) {
var1528 = NEW_core__NativeArray(6l, &type_core__NativeArray__core__String);
if (likely(varonce1529!=NULL)) {
var1530 = varonce1529;
} else {
var1531 = "[";
var1532 = core__flat___NativeString___to_s_full(var1531, 1l, 1l);
var1530 = var1532;
varonce1529 = var1530;
}
((struct instance_core__NativeArray*)var1528)->values[1]=var1530;
if (likely(varonce1533!=NULL)) {
var1534 = varonce1533;
} else {
var1535 = "]=(unsigned char)";
var1536 = core__flat___NativeString___to_s_full(var1535, 17l, 17l);
var1534 = var1536;
varonce1533 = var1534;
}
((struct instance_core__NativeArray*)var1528)->values[3]=var1534;
if (likely(varonce1537!=NULL)) {
var1538 = varonce1537;
} else {
var1539 = ";";
var1540 = core__flat___NativeString___to_s_full(var1539, 1l, 1l);
var1538 = var1540;
varonce1537 = var1538;
}
((struct instance_core__NativeArray*)var1528)->values[5]=var1538;
} else {
var1528 = varonce1527;
varonce1527 = NULL;
}
{
var1541 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1542 = ((val*(*)(val* self))(var1541->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1541); /* to_s on <var1541:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1528)->values[0]=var1542;
{
var1543 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1544 = ((val*(*)(val* self))(var1543->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1543); /* to_s on <var1543:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1528)->values[2]=var1544;
{
var1545 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 2l);
}
{
var1546 = ((val*(*)(val* self))(var1545->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1545); /* to_s on <var1545:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1528)->values[4]=var1546;
{
var1547 = ((val*(*)(val* self))(var1528->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1528); /* native_to_s on <var1528:NativeArray[String]>*/
}
varonce1527 = var1528;
{
nitc___nitc__AbstractCompilerVisitor___add(var_v, var1547); /* Direct call abstract_compiler#AbstractCompilerVisitor#add on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1548!=NULL)) {
var1549 = varonce1548;
} else {
var1550 = "copy_to";
var1551 = core__flat___NativeString___to_s_full(var1550, 7l, 7l);
var1549 = var1551;
varonce1548 = var1549;
}
{
var1552 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1549); /* == on <var_pname:String>*/
}
if (var1552){
if (unlikely(varonce1553==NULL)) {
var1554 = NEW_core__NativeArray(11l, &type_core__NativeArray__core__String);
if (likely(varonce1555!=NULL)) {
var1556 = varonce1555;
} else {
var1557 = "memmove(";
var1558 = core__flat___NativeString___to_s_full(var1557, 8l, 8l);
var1556 = var1558;
varonce1555 = var1556;
}
((struct instance_core__NativeArray*)var1554)->values[0]=var1556;
if (likely(varonce1559!=NULL)) {
var1560 = varonce1559;
} else {
var1561 = "+";
var1562 = core__flat___NativeString___to_s_full(var1561, 1l, 1l);
var1560 = var1562;
varonce1559 = var1560;
}
((struct instance_core__NativeArray*)var1554)->values[2]=var1560;
if (likely(varonce1563!=NULL)) {
var1564 = varonce1563;
} else {
var1565 = ",";
var1566 = core__flat___NativeString___to_s_full(var1565, 1l, 1l);
var1564 = var1566;
varonce1563 = var1564;
}
((struct instance_core__NativeArray*)var1554)->values[4]=var1564;
if (likely(varonce1567!=NULL)) {
var1568 = varonce1567;
} else {
var1569 = "+";
var1570 = core__flat___NativeString___to_s_full(var1569, 1l, 1l);
var1568 = var1570;
varonce1567 = var1568;
}
((struct instance_core__NativeArray*)var1554)->values[6]=var1568;
if (likely(varonce1571!=NULL)) {
var1572 = varonce1571;
} else {
var1573 = ",";
var1574 = core__flat___NativeString___to_s_full(var1573, 1l, 1l);
var1572 = var1574;
varonce1571 = var1572;
}
((struct instance_core__NativeArray*)var1554)->values[8]=var1572;
if (likely(varonce1575!=NULL)) {
var1576 = varonce1575;
} else {
var1577 = ");";
var1578 = core__flat___NativeString___to_s_full(var1577, 2l, 2l);
var1576 = var1578;
varonce1575 = var1576;
}
((struct instance_core__NativeArray*)var1554)->values[10]=var1576;
} else {
var1554 = varonce1553;
varonce1553 = NULL;
}
{
var1579 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1580 = ((val*(*)(val* self))(var1579->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1579); /* to_s on <var1579:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1554)->values[1]=var1580;
{
var1581 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 4l);
}
{
var1582 = ((val*(*)(val* self))(var1581->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1581); /* to_s on <var1581:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1554)->values[3]=var1582;
{
var1583 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1584 = ((val*(*)(val* self))(var1583->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1583); /* to_s on <var1583:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1554)->values[5]=var1584;
{
var1585 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 3l);
}
{
var1586 = ((val*(*)(val* self))(var1585->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1585); /* to_s on <var1585:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1554)->values[7]=var1586;
{
var1587 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 2l);
}
{
var1588 = ((val*(*)(val* self))(var1587->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1587); /* to_s on <var1587:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1554)->values[9]=var1588;
{
var1589 = ((val*(*)(val* self))(var1554->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1554); /* native_to_s on <var1554:NativeArray[String]>*/
}
varonce1553 = var1554;
{
nitc___nitc__AbstractCompilerVisitor___add(var_v, var1589); /* Direct call abstract_compiler#AbstractCompilerVisitor#add on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1590!=NULL)) {
var1591 = varonce1590;
} else {
var1592 = "atoi";
var1593 = core__flat___NativeString___to_s_full(var1592, 4l, 4l);
var1591 = var1593;
varonce1590 = var1591;
}
{
var1594 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1591); /* == on <var_pname:String>*/
}
if (var1594){
if (unlikely(varonce1595==NULL)) {
var1596 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1597!=NULL)) {
var1598 = varonce1597;
} else {
var1599 = "atoi(";
var1600 = core__flat___NativeString___to_s_full(var1599, 5l, 5l);
var1598 = var1600;
varonce1597 = var1598;
}
((struct instance_core__NativeArray*)var1596)->values[0]=var1598;
if (likely(varonce1601!=NULL)) {
var1602 = varonce1601;
} else {
var1603 = ");";
var1604 = core__flat___NativeString___to_s_full(var1603, 2l, 2l);
var1602 = var1604;
varonce1601 = var1602;
}
((struct instance_core__NativeArray*)var1596)->values[2]=var1602;
} else {
var1596 = varonce1595;
varonce1595 = NULL;
}
{
var1605 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1606 = ((val*(*)(val* self))(var1605->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1605); /* to_s on <var1605:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1596)->values[1]=var1606;
{
var1607 = ((val*(*)(val* self))(var1596->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1596); /* native_to_s on <var1596:NativeArray[String]>*/
}
varonce1595 = var1596;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2515);
fatal_exit(1);
}
{
var1608 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1607, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1608); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1609!=NULL)) {
var1610 = varonce1609;
} else {
var1611 = "fast_cstring";
var1612 = core__flat___NativeString___to_s_full(var1611, 12l, 12l);
var1610 = var1612;
varonce1609 = var1610;
}
{
var1613 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1610); /* == on <var_pname:String>*/
}
if (var1613){
if (unlikely(varonce1614==NULL)) {
var1615 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1616!=NULL)) {
var1617 = varonce1616;
} else {
var1618 = " + ";
var1619 = core__flat___NativeString___to_s_full(var1618, 3l, 3l);
var1617 = var1619;
varonce1616 = var1617;
}
((struct instance_core__NativeArray*)var1615)->values[1]=var1617;
} else {
var1615 = varonce1614;
varonce1614 = NULL;
}
{
var1620 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1621 = ((val*(*)(val* self))(var1620->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1620); /* to_s on <var1620:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1615)->values[0]=var1621;
{
var1622 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1623 = ((val*(*)(val* self))(var1622->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1622); /* to_s on <var1622:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1615)->values[2]=var1623;
{
var1624 = ((val*(*)(val* self))(var1615->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1615); /* native_to_s on <var1615:NativeArray[String]>*/
}
varonce1614 = var1615;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2518);
fatal_exit(1);
}
{
var1625 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1624, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1625); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1626!=NULL)) {
var1627 = varonce1626;
} else {
var1628 = "==";
var1629 = core__flat___NativeString___to_s_full(var1628, 2l, 2l);
var1627 = var1629;
varonce1626 = var1627;
}
{
var1630 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1627); /* == on <var_pname:String>*/
}
if (var1630){
{
var1631 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1632 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1633 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var1631, var1632);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1633); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1634!=NULL)) {
var1635 = varonce1634;
} else {
var1636 = "!=";
var1637 = core__flat___NativeString___to_s_full(var1636, 2l, 2l);
var1635 = var1637;
varonce1634 = var1635;
}
{
var1638 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1635); /* == on <var_pname:String>*/
}
if (var1638){
{
var1639 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1640 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1641 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var1639, var1640);
}
var_res1642 = var1641;
if (unlikely(varonce1643==NULL)) {
var1644 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1645!=NULL)) {
var1646 = varonce1645;
} else {
var1647 = "!";
var1648 = core__flat___NativeString___to_s_full(var1647, 1l, 1l);
var1646 = var1648;
varonce1645 = var1646;
}
((struct instance_core__NativeArray*)var1644)->values[0]=var1646;
} else {
var1644 = varonce1643;
varonce1643 = NULL;
}
{
var1649 = ((val*(*)(val* self))(var_res1642->class->vft[COLOR_core__abstract_text__Object__to_s]))(var_res1642); /* to_s on <var_res1642:RuntimeVariable>*/
}
((struct instance_core__NativeArray*)var1644)->values[1]=var1649;
{
var1650 = ((val*(*)(val* self))(var1644->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1644); /* native_to_s on <var1644:NativeArray[String]>*/
}
varonce1643 = var1644;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2525);
fatal_exit(1);
}
{
var1651 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1650, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1651); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1652!=NULL)) {
var1653 = varonce1652;
} else {
var1654 = "new";
var1655 = core__flat___NativeString___to_s_full(var1654, 3l, 3l);
var1653 = var1655;
varonce1652 = var1653;
}
{
var1656 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1653); /* == on <var_pname:String>*/
}
if (var1656){
if (unlikely(varonce1657==NULL)) {
var1658 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1659!=NULL)) {
var1660 = varonce1659;
} else {
var1661 = "(char*)nit_alloc(";
var1662 = core__flat___NativeString___to_s_full(var1661, 17l, 17l);
var1660 = var1662;
varonce1659 = var1660;
}
((struct instance_core__NativeArray*)var1658)->values[0]=var1660;
if (likely(varonce1663!=NULL)) {
var1664 = varonce1663;
} else {
var1665 = ")";
var1666 = core__flat___NativeString___to_s_full(var1665, 1l, 1l);
var1664 = var1666;
varonce1663 = var1664;
}
((struct instance_core__NativeArray*)var1658)->values[2]=var1664;
} else {
var1658 = varonce1657;
varonce1657 = NULL;
}
{
var1667 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1668 = ((val*(*)(val* self))(var1667->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1667); /* to_s on <var1667:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1658)->values[1]=var1668;
{
var1669 = ((val*(*)(val* self))(var1658->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1658); /* native_to_s on <var1658:NativeArray[String]>*/
}
varonce1657 = var1658;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2528);
fatal_exit(1);
}
{
var1670 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1669, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1670); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1671!=NULL)) {
var1672 = varonce1671;
} else {
var1673 = "fetch_4_chars";
var1674 = core__flat___NativeString___to_s_full(var1673, 13l, 13l);
var1672 = var1674;
varonce1671 = var1672;
}
{
var1675 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1672); /* == on <var_pname:String>*/
}
if (var1675){
if (unlikely(varonce1676==NULL)) {
var1677 = NEW_core__NativeArray(5l, &type_core__NativeArray__core__String);
if (likely(varonce1678!=NULL)) {
var1679 = varonce1678;
} else {
var1680 = "(long)*((uint32_t*)(";
var1681 = core__flat___NativeString___to_s_full(var1680, 20l, 20l);
var1679 = var1681;
varonce1678 = var1679;
}
((struct instance_core__NativeArray*)var1677)->values[0]=var1679;
if (likely(varonce1682!=NULL)) {
var1683 = varonce1682;
} else {
var1684 = " + ";
var1685 = core__flat___NativeString___to_s_full(var1684, 3l, 3l);
var1683 = var1685;
varonce1682 = var1683;
}
((struct instance_core__NativeArray*)var1677)->values[2]=var1683;
if (likely(varonce1686!=NULL)) {
var1687 = varonce1686;
} else {
var1688 = "))";
var1689 = core__flat___NativeString___to_s_full(var1688, 2l, 2l);
var1687 = var1689;
varonce1686 = var1687;
}
((struct instance_core__NativeArray*)var1677)->values[4]=var1687;
} else {
var1677 = varonce1676;
varonce1676 = NULL;
}
{
var1690 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1691 = ((val*(*)(val* self))(var1690->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1690); /* to_s on <var1690:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1677)->values[1]=var1691;
{
var1692 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1693 = ((val*(*)(val* self))(var1692->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1692); /* to_s on <var1692:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1677)->values[3]=var1693;
{
var1694 = ((val*(*)(val* self))(var1677->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1677); /* native_to_s on <var1677:NativeArray[String]>*/
}
varonce1676 = var1677;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2531);
fatal_exit(1);
}
{
var1695 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1694, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1695); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1696!=NULL)) {
var1697 = varonce1696;
} else {
var1698 = "fetch_4_hchars";
var1699 = core__flat___NativeString___to_s_full(var1698, 14l, 14l);
var1697 = var1699;
varonce1696 = var1697;
}
{
var1700 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1697); /* == on <var_pname:String>*/
}
if (var1700){
if (unlikely(varonce1701==NULL)) {
var1702 = NEW_core__NativeArray(5l, &type_core__NativeArray__core__String);
if (likely(varonce1703!=NULL)) {
var1704 = varonce1703;
} else {
var1705 = "(long)be32toh(*((uint32_t*)(";
var1706 = core__flat___NativeString___to_s_full(var1705, 28l, 28l);
var1704 = var1706;
varonce1703 = var1704;
}
((struct instance_core__NativeArray*)var1702)->values[0]=var1704;
if (likely(varonce1707!=NULL)) {
var1708 = varonce1707;
} else {
var1709 = " + ";
var1710 = core__flat___NativeString___to_s_full(var1709, 3l, 3l);
var1708 = var1710;
varonce1707 = var1708;
}
((struct instance_core__NativeArray*)var1702)->values[2]=var1708;
if (likely(varonce1711!=NULL)) {
var1712 = varonce1711;
} else {
var1713 = ")))";
var1714 = core__flat___NativeString___to_s_full(var1713, 3l, 3l);
var1712 = var1714;
varonce1711 = var1712;
}
((struct instance_core__NativeArray*)var1702)->values[4]=var1712;
} else {
var1702 = varonce1701;
varonce1701 = NULL;
}
{
var1715 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1716 = ((val*(*)(val* self))(var1715->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1715); /* to_s on <var1715:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1702)->values[1]=var1716;
{
var1717 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1718 = ((val*(*)(val* self))(var1717->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1717); /* to_s on <var1717:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1702)->values[3]=var1718;
{
var1719 = ((val*(*)(val* self))(var1702->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1702); /* native_to_s on <var1702:NativeArray[String]>*/
}
varonce1701 = var1702;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2534);
fatal_exit(1);
}
{
var1720 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1719, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1720); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
}
}
}
}
}
}
}
}
}
}
} else {
if (likely(varonce1721!=NULL)) {
var1722 = varonce1721;
} else {
var1723 = "NativeArray";
var1724 = core__flat___NativeString___to_s_full(var1723, 11l, 11l);
var1722 = var1724;
varonce1721 = var1722;
}
{
var1725 = ((short int(*)(val* self, val* p0))(var_cname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_cname, var1722); /* == on <var_cname:String>*/
}
if (var1725){
{
var1726 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__native_array_def(var_v, var_pname, var_ret, var_arguments);
}
var = var1726;
goto RET_LABEL;
} else {
if (likely(varonce1727!=NULL)) {
var1728 = varonce1727;
} else {
var1729 = "Int8";
var1730 = core__flat___NativeString___to_s_full(var1729, 4l, 4l);
var1728 = var1730;
varonce1727 = var1728;
}
{
var1731 = ((short int(*)(val* self, val* p0))(var_cname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_cname, var1728); /* == on <var_cname:String>*/
}
if (var1731){
if (likely(varonce1732!=NULL)) {
var1733 = varonce1732;
} else {
var1734 = "output";
var1735 = core__flat___NativeString___to_s_full(var1734, 6l, 6l);
var1733 = var1735;
varonce1732 = var1733;
}
{
var1736 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1733); /* == on <var_pname:String>*/
}
if (var1736){
if (unlikely(varonce1737==NULL)) {
var1738 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1739!=NULL)) {
var1740 = varonce1739;
} else {
var1741 = "printf(\"%\"PRIi8 \"\\n\", ";
var1742 = core__flat___NativeString___to_s_full(var1741, 22l, 22l);
var1740 = var1742;
varonce1739 = var1740;
}
((struct instance_core__NativeArray*)var1738)->values[0]=var1740;
if (likely(varonce1743!=NULL)) {
var1744 = varonce1743;
} else {
var1745 = ");";
var1746 = core__flat___NativeString___to_s_full(var1745, 2l, 2l);
var1744 = var1746;
varonce1743 = var1744;
}
((struct instance_core__NativeArray*)var1738)->values[2]=var1744;
} else {
var1738 = varonce1737;
varonce1737 = NULL;
}
{
var1747 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var1748 = ((val*(*)(val* self))(var1747->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1747); /* to_s on <var1747:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1738)->values[1]=var1748;
{
var1749 = ((val*(*)(val* self))(var1738->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1738); /* native_to_s on <var1738:NativeArray[String]>*/
}
varonce1737 = var1738;
{
nitc___nitc__AbstractCompilerVisitor___add(var_v, var1749); /* Direct call abstract_compiler#AbstractCompilerVisitor#add on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1750!=NULL)) {
var1751 = varonce1750;
} else {
var1752 = "object_id";
var1753 = core__flat___NativeString___to_s_full(var1752, 9l, 9l);
var1751 = var1753;
varonce1750 = var1751;
}
{
var1754 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1751); /* == on <var_pname:String>*/
}
if (var1754){
if (unlikely(varonce1755==NULL)) {
var1756 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1757!=NULL)) {
var1758 = varonce1757;
} else {
var1759 = "(long)";
var1760 = core__flat___NativeString___to_s_full(var1759, 6l, 6l);
var1758 = var1760;
varonce1757 = var1758;
}
((struct instance_core__NativeArray*)var1756)->values[0]=var1758;
} else {
var1756 = varonce1755;
varonce1755 = NULL;
}
{
var1761 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var1762 = ((val*(*)(val* self))(var1761->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1761); /* to_s on <var1761:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1756)->values[1]=var1762;
{
var1763 = ((val*(*)(val* self))(var1756->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1756); /* native_to_s on <var1756:NativeArray[String]>*/
}
varonce1755 = var1756;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2544);
fatal_exit(1);
}
{
var1764 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1763, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1764); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1765!=NULL)) {
var1766 = varonce1765;
} else {
var1767 = "+";
var1768 = core__flat___NativeString___to_s_full(var1767, 1l, 1l);
var1766 = var1768;
varonce1765 = var1766;
}
{
var1769 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1766); /* == on <var_pname:String>*/
}
if (var1769){
if (unlikely(varonce1770==NULL)) {
var1771 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1772!=NULL)) {
var1773 = varonce1772;
} else {
var1774 = " + ";
var1775 = core__flat___NativeString___to_s_full(var1774, 3l, 3l);
var1773 = var1775;
varonce1772 = var1773;
}
((struct instance_core__NativeArray*)var1771)->values[1]=var1773;
} else {
var1771 = varonce1770;
varonce1770 = NULL;
}
{
var1776 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1777 = ((val*(*)(val* self))(var1776->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1776); /* to_s on <var1776:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1771)->values[0]=var1777;
{
var1778 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1779 = ((val*(*)(val* self))(var1778->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1778); /* to_s on <var1778:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1771)->values[2]=var1779;
{
var1780 = ((val*(*)(val* self))(var1771->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1771); /* native_to_s on <var1771:NativeArray[String]>*/
}
varonce1770 = var1771;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2547);
fatal_exit(1);
}
{
var1781 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1780, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1781); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1782!=NULL)) {
var1783 = varonce1782;
} else {
var1784 = "-";
var1785 = core__flat___NativeString___to_s_full(var1784, 1l, 1l);
var1783 = var1785;
varonce1782 = var1783;
}
{
var1786 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1783); /* == on <var_pname:String>*/
}
if (var1786){
if (unlikely(varonce1787==NULL)) {
var1788 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1789!=NULL)) {
var1790 = varonce1789;
} else {
var1791 = " - ";
var1792 = core__flat___NativeString___to_s_full(var1791, 3l, 3l);
var1790 = var1792;
varonce1789 = var1790;
}
((struct instance_core__NativeArray*)var1788)->values[1]=var1790;
} else {
var1788 = varonce1787;
varonce1787 = NULL;
}
{
var1793 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1794 = ((val*(*)(val* self))(var1793->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1793); /* to_s on <var1793:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1788)->values[0]=var1794;
{
var1795 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1796 = ((val*(*)(val* self))(var1795->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1795); /* to_s on <var1795:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1788)->values[2]=var1796;
{
var1797 = ((val*(*)(val* self))(var1788->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1788); /* native_to_s on <var1788:NativeArray[String]>*/
}
varonce1787 = var1788;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2550);
fatal_exit(1);
}
{
var1798 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1797, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1798); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1799!=NULL)) {
var1800 = varonce1799;
} else {
var1801 = "unary -";
var1802 = core__flat___NativeString___to_s_full(var1801, 7l, 7l);
var1800 = var1802;
varonce1799 = var1800;
}
{
var1803 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1800); /* == on <var_pname:String>*/
}
if (var1803){
if (unlikely(varonce1804==NULL)) {
var1805 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1806!=NULL)) {
var1807 = varonce1806;
} else {
var1808 = "-";
var1809 = core__flat___NativeString___to_s_full(var1808, 1l, 1l);
var1807 = var1809;
varonce1806 = var1807;
}
((struct instance_core__NativeArray*)var1805)->values[0]=var1807;
} else {
var1805 = varonce1804;
varonce1804 = NULL;
}
{
var1810 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1811 = ((val*(*)(val* self))(var1810->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1810); /* to_s on <var1810:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1805)->values[1]=var1811;
{
var1812 = ((val*(*)(val* self))(var1805->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1805); /* native_to_s on <var1805:NativeArray[String]>*/
}
varonce1804 = var1805;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2553);
fatal_exit(1);
}
{
var1813 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1812, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1813); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1814!=NULL)) {
var1815 = varonce1814;
} else {
var1816 = "unary +";
var1817 = core__flat___NativeString___to_s_full(var1816, 7l, 7l);
var1815 = var1817;
varonce1814 = var1815;
}
{
var1818 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1815); /* == on <var_pname:String>*/
}
if (var1818){
{
var1819 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1819); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1820!=NULL)) {
var1821 = varonce1820;
} else {
var1822 = "*";
var1823 = core__flat___NativeString___to_s_full(var1822, 1l, 1l);
var1821 = var1823;
varonce1820 = var1821;
}
{
var1824 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1821); /* == on <var_pname:String>*/
}
if (var1824){
if (unlikely(varonce1825==NULL)) {
var1826 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1827!=NULL)) {
var1828 = varonce1827;
} else {
var1829 = " * ";
var1830 = core__flat___NativeString___to_s_full(var1829, 3l, 3l);
var1828 = var1830;
varonce1827 = var1828;
}
((struct instance_core__NativeArray*)var1826)->values[1]=var1828;
} else {
var1826 = varonce1825;
varonce1825 = NULL;
}
{
var1831 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1832 = ((val*(*)(val* self))(var1831->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1831); /* to_s on <var1831:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1826)->values[0]=var1832;
{
var1833 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1834 = ((val*(*)(val* self))(var1833->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1833); /* to_s on <var1833:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1826)->values[2]=var1834;
{
var1835 = ((val*(*)(val* self))(var1826->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1826); /* native_to_s on <var1826:NativeArray[String]>*/
}
varonce1825 = var1826;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2559);
fatal_exit(1);
}
{
var1836 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1835, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1836); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1837!=NULL)) {
var1838 = varonce1837;
} else {
var1839 = "/";
var1840 = core__flat___NativeString___to_s_full(var1839, 1l, 1l);
var1838 = var1840;
varonce1837 = var1838;
}
{
var1841 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1838); /* == on <var_pname:String>*/
}
if (var1841){
if (unlikely(varonce1842==NULL)) {
var1843 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1844!=NULL)) {
var1845 = varonce1844;
} else {
var1846 = " / ";
var1847 = core__flat___NativeString___to_s_full(var1846, 3l, 3l);
var1845 = var1847;
varonce1844 = var1845;
}
((struct instance_core__NativeArray*)var1843)->values[1]=var1845;
} else {
var1843 = varonce1842;
varonce1842 = NULL;
}
{
var1848 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1849 = ((val*(*)(val* self))(var1848->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1848); /* to_s on <var1848:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1843)->values[0]=var1849;
{
var1850 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1851 = ((val*(*)(val* self))(var1850->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1850); /* to_s on <var1850:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1843)->values[2]=var1851;
{
var1852 = ((val*(*)(val* self))(var1843->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1843); /* native_to_s on <var1843:NativeArray[String]>*/
}
varonce1842 = var1843;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2562);
fatal_exit(1);
}
{
var1853 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1852, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1853); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1854!=NULL)) {
var1855 = varonce1854;
} else {
var1856 = "%";
var1857 = core__flat___NativeString___to_s_full(var1856, 1l, 1l);
var1855 = var1857;
varonce1854 = var1855;
}
{
var1858 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1855); /* == on <var_pname:String>*/
}
if (var1858){
if (unlikely(varonce1859==NULL)) {
var1860 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1861!=NULL)) {
var1862 = varonce1861;
} else {
var1863 = " % ";
var1864 = core__flat___NativeString___to_s_full(var1863, 3l, 3l);
var1862 = var1864;
varonce1861 = var1862;
}
((struct instance_core__NativeArray*)var1860)->values[1]=var1862;
} else {
var1860 = varonce1859;
varonce1859 = NULL;
}
{
var1865 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1866 = ((val*(*)(val* self))(var1865->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1865); /* to_s on <var1865:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1860)->values[0]=var1866;
{
var1867 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1868 = ((val*(*)(val* self))(var1867->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1867); /* to_s on <var1867:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1860)->values[2]=var1868;
{
var1869 = ((val*(*)(val* self))(var1860->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1860); /* native_to_s on <var1860:NativeArray[String]>*/
}
varonce1859 = var1860;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2565);
fatal_exit(1);
}
{
var1870 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1869, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1870); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1871!=NULL)) {
var1872 = varonce1871;
} else {
var1873 = "<<";
var1874 = core__flat___NativeString___to_s_full(var1873, 2l, 2l);
var1872 = var1874;
varonce1871 = var1872;
}
{
var1875 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1872); /* == on <var_pname:String>*/
}
if (var1875){
if (unlikely(varonce1876==NULL)) {
var1877 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1878!=NULL)) {
var1879 = varonce1878;
} else {
var1880 = " << ";
var1881 = core__flat___NativeString___to_s_full(var1880, 4l, 4l);
var1879 = var1881;
varonce1878 = var1879;
}
((struct instance_core__NativeArray*)var1877)->values[1]=var1879;
} else {
var1877 = varonce1876;
varonce1876 = NULL;
}
{
var1882 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1883 = ((val*(*)(val* self))(var1882->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1882); /* to_s on <var1882:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1877)->values[0]=var1883;
{
var1884 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1885 = ((val*(*)(val* self))(var1884->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1884); /* to_s on <var1884:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1877)->values[2]=var1885;
{
var1886 = ((val*(*)(val* self))(var1877->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1877); /* native_to_s on <var1877:NativeArray[String]>*/
}
varonce1876 = var1877;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2568);
fatal_exit(1);
}
{
var1887 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1886, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1887); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1888!=NULL)) {
var1889 = varonce1888;
} else {
var1890 = ">>";
var1891 = core__flat___NativeString___to_s_full(var1890, 2l, 2l);
var1889 = var1891;
varonce1888 = var1889;
}
{
var1892 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1889); /* == on <var_pname:String>*/
}
if (var1892){
if (unlikely(varonce1893==NULL)) {
var1894 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1895!=NULL)) {
var1896 = varonce1895;
} else {
var1897 = " >> ";
var1898 = core__flat___NativeString___to_s_full(var1897, 4l, 4l);
var1896 = var1898;
varonce1895 = var1896;
}
((struct instance_core__NativeArray*)var1894)->values[1]=var1896;
} else {
var1894 = varonce1893;
varonce1893 = NULL;
}
{
var1899 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1900 = ((val*(*)(val* self))(var1899->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1899); /* to_s on <var1899:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1894)->values[0]=var1900;
{
var1901 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1902 = ((val*(*)(val* self))(var1901->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1901); /* to_s on <var1901:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1894)->values[2]=var1902;
{
var1903 = ((val*(*)(val* self))(var1894->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1894); /* native_to_s on <var1894:NativeArray[String]>*/
}
varonce1893 = var1894;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2571);
fatal_exit(1);
}
{
var1904 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1903, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1904); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1905!=NULL)) {
var1906 = varonce1905;
} else {
var1907 = "==";
var1908 = core__flat___NativeString___to_s_full(var1907, 2l, 2l);
var1906 = var1908;
varonce1905 = var1906;
}
{
var1909 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1906); /* == on <var_pname:String>*/
}
if (var1909){
{
var1910 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1911 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1912 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var1910, var1911);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1912); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1913!=NULL)) {
var1914 = varonce1913;
} else {
var1915 = "!=";
var1916 = core__flat___NativeString___to_s_full(var1915, 2l, 2l);
var1914 = var1916;
varonce1913 = var1914;
}
{
var1917 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1914); /* == on <var_pname:String>*/
}
if (var1917){
{
var1918 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1919 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1920 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var1918, var1919);
}
var_res1921 = var1920;
if (unlikely(varonce1922==NULL)) {
var1923 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce1924!=NULL)) {
var1925 = varonce1924;
} else {
var1926 = "!";
var1927 = core__flat___NativeString___to_s_full(var1926, 1l, 1l);
var1925 = var1927;
varonce1924 = var1925;
}
((struct instance_core__NativeArray*)var1923)->values[0]=var1925;
} else {
var1923 = varonce1922;
varonce1922 = NULL;
}
{
var1928 = ((val*(*)(val* self))(var_res1921->class->vft[COLOR_core__abstract_text__Object__to_s]))(var_res1921); /* to_s on <var_res1921:RuntimeVariable>*/
}
((struct instance_core__NativeArray*)var1923)->values[1]=var1928;
{
var1929 = ((val*(*)(val* self))(var1923->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1923); /* native_to_s on <var1923:NativeArray[String]>*/
}
varonce1922 = var1923;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2578);
fatal_exit(1);
}
{
var1930 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1929, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1930); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1931!=NULL)) {
var1932 = varonce1931;
} else {
var1933 = "<";
var1934 = core__flat___NativeString___to_s_full(var1933, 1l, 1l);
var1932 = var1934;
varonce1931 = var1932;
}
{
var1935 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1932); /* == on <var_pname:String>*/
}
if (var1935){
if (unlikely(varonce1936==NULL)) {
var1937 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1938!=NULL)) {
var1939 = varonce1938;
} else {
var1940 = " < ";
var1941 = core__flat___NativeString___to_s_full(var1940, 3l, 3l);
var1939 = var1941;
varonce1938 = var1939;
}
((struct instance_core__NativeArray*)var1937)->values[1]=var1939;
} else {
var1937 = varonce1936;
varonce1936 = NULL;
}
{
var1942 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1943 = ((val*(*)(val* self))(var1942->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1942); /* to_s on <var1942:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1937)->values[0]=var1943;
{
var1944 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1945 = ((val*(*)(val* self))(var1944->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1944); /* to_s on <var1944:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1937)->values[2]=var1945;
{
var1946 = ((val*(*)(val* self))(var1937->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1937); /* native_to_s on <var1937:NativeArray[String]>*/
}
varonce1936 = var1937;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2581);
fatal_exit(1);
}
{
var1947 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1946, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1947); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1948!=NULL)) {
var1949 = varonce1948;
} else {
var1950 = ">";
var1951 = core__flat___NativeString___to_s_full(var1950, 1l, 1l);
var1949 = var1951;
varonce1948 = var1949;
}
{
var1952 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1949); /* == on <var_pname:String>*/
}
if (var1952){
if (unlikely(varonce1953==NULL)) {
var1954 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1955!=NULL)) {
var1956 = varonce1955;
} else {
var1957 = " > ";
var1958 = core__flat___NativeString___to_s_full(var1957, 3l, 3l);
var1956 = var1958;
varonce1955 = var1956;
}
((struct instance_core__NativeArray*)var1954)->values[1]=var1956;
} else {
var1954 = varonce1953;
varonce1953 = NULL;
}
{
var1959 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1960 = ((val*(*)(val* self))(var1959->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1959); /* to_s on <var1959:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1954)->values[0]=var1960;
{
var1961 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1962 = ((val*(*)(val* self))(var1961->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1961); /* to_s on <var1961:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1954)->values[2]=var1962;
{
var1963 = ((val*(*)(val* self))(var1954->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1954); /* native_to_s on <var1954:NativeArray[String]>*/
}
varonce1953 = var1954;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2584);
fatal_exit(1);
}
{
var1964 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1963, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1964); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1965!=NULL)) {
var1966 = varonce1965;
} else {
var1967 = "<=";
var1968 = core__flat___NativeString___to_s_full(var1967, 2l, 2l);
var1966 = var1968;
varonce1965 = var1966;
}
{
var1969 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1966); /* == on <var_pname:String>*/
}
if (var1969){
if (unlikely(varonce1970==NULL)) {
var1971 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1972!=NULL)) {
var1973 = varonce1972;
} else {
var1974 = " <= ";
var1975 = core__flat___NativeString___to_s_full(var1974, 4l, 4l);
var1973 = var1975;
varonce1972 = var1973;
}
((struct instance_core__NativeArray*)var1971)->values[1]=var1973;
} else {
var1971 = varonce1970;
varonce1970 = NULL;
}
{
var1976 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1977 = ((val*(*)(val* self))(var1976->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1976); /* to_s on <var1976:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1971)->values[0]=var1977;
{
var1978 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1979 = ((val*(*)(val* self))(var1978->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1978); /* to_s on <var1978:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1971)->values[2]=var1979;
{
var1980 = ((val*(*)(val* self))(var1971->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1971); /* native_to_s on <var1971:NativeArray[String]>*/
}
varonce1970 = var1971;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2587);
fatal_exit(1);
}
{
var1981 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1980, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1981); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1982!=NULL)) {
var1983 = varonce1982;
} else {
var1984 = ">=";
var1985 = core__flat___NativeString___to_s_full(var1984, 2l, 2l);
var1983 = var1985;
varonce1982 = var1983;
}
{
var1986 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var1983); /* == on <var_pname:String>*/
}
if (var1986){
if (unlikely(varonce1987==NULL)) {
var1988 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce1989!=NULL)) {
var1990 = varonce1989;
} else {
var1991 = " >= ";
var1992 = core__flat___NativeString___to_s_full(var1991, 4l, 4l);
var1990 = var1992;
varonce1989 = var1990;
}
((struct instance_core__NativeArray*)var1988)->values[1]=var1990;
} else {
var1988 = varonce1987;
varonce1987 = NULL;
}
{
var1993 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var1994 = ((val*(*)(val* self))(var1993->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1993); /* to_s on <var1993:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1988)->values[0]=var1994;
{
var1995 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var1996 = ((val*(*)(val* self))(var1995->class->vft[COLOR_core__abstract_text__Object__to_s]))(var1995); /* to_s on <var1995:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var1988)->values[2]=var1996;
{
var1997 = ((val*(*)(val* self))(var1988->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var1988); /* native_to_s on <var1988:NativeArray[String]>*/
}
varonce1987 = var1988;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2590);
fatal_exit(1);
}
{
var1998 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var1997, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var1998); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce1999!=NULL)) {
var2000 = varonce1999;
} else {
var2001 = "to_i";
var2002 = core__flat___NativeString___to_s_full(var2001, 4l, 4l);
var2000 = var2002;
varonce1999 = var2000;
}
{
var2003 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2000); /* == on <var_pname:String>*/
}
if (var2003){
if (unlikely(varonce2004==NULL)) {
var2005 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2006!=NULL)) {
var2007 = varonce2006;
} else {
var2008 = "(long)";
var2009 = core__flat___NativeString___to_s_full(var2008, 6l, 6l);
var2007 = var2009;
varonce2006 = var2007;
}
((struct instance_core__NativeArray*)var2005)->values[0]=var2007;
} else {
var2005 = varonce2004;
varonce2004 = NULL;
}
{
var2010 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2011 = ((val*(*)(val* self))(var2010->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2010); /* to_s on <var2010:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2005)->values[1]=var2011;
{
var2012 = ((val*(*)(val* self))(var2005->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2005); /* native_to_s on <var2005:NativeArray[String]>*/
}
varonce2004 = var2005;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2593);
fatal_exit(1);
}
{
var2013 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2012, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2013); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2014!=NULL)) {
var2015 = varonce2014;
} else {
var2016 = "to_b";
var2017 = core__flat___NativeString___to_s_full(var2016, 4l, 4l);
var2015 = var2017;
varonce2014 = var2015;
}
{
var2018 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2015); /* == on <var_pname:String>*/
}
if (var2018){
if (unlikely(varonce2019==NULL)) {
var2020 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2021!=NULL)) {
var2022 = varonce2021;
} else {
var2023 = "(unsigned char)";
var2024 = core__flat___NativeString___to_s_full(var2023, 15l, 15l);
var2022 = var2024;
varonce2021 = var2022;
}
((struct instance_core__NativeArray*)var2020)->values[0]=var2022;
} else {
var2020 = varonce2019;
varonce2019 = NULL;
}
{
var2025 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2026 = ((val*(*)(val* self))(var2025->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2025); /* to_s on <var2025:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2020)->values[1]=var2026;
{
var2027 = ((val*(*)(val* self))(var2020->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2020); /* native_to_s on <var2020:NativeArray[String]>*/
}
varonce2019 = var2020;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2596);
fatal_exit(1);
}
{
var2028 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2027, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2028); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2029!=NULL)) {
var2030 = varonce2029;
} else {
var2031 = "to_i16";
var2032 = core__flat___NativeString___to_s_full(var2031, 6l, 6l);
var2030 = var2032;
varonce2029 = var2030;
}
{
var2033 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2030); /* == on <var_pname:String>*/
}
if (var2033){
if (unlikely(varonce2034==NULL)) {
var2035 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2036!=NULL)) {
var2037 = varonce2036;
} else {
var2038 = "(int16_t)";
var2039 = core__flat___NativeString___to_s_full(var2038, 9l, 9l);
var2037 = var2039;
varonce2036 = var2037;
}
((struct instance_core__NativeArray*)var2035)->values[0]=var2037;
} else {
var2035 = varonce2034;
varonce2034 = NULL;
}
{
var2040 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2041 = ((val*(*)(val* self))(var2040->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2040); /* to_s on <var2040:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2035)->values[1]=var2041;
{
var2042 = ((val*(*)(val* self))(var2035->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2035); /* native_to_s on <var2035:NativeArray[String]>*/
}
varonce2034 = var2035;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2599);
fatal_exit(1);
}
{
var2043 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2042, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2043); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2044!=NULL)) {
var2045 = varonce2044;
} else {
var2046 = "to_u16";
var2047 = core__flat___NativeString___to_s_full(var2046, 6l, 6l);
var2045 = var2047;
varonce2044 = var2045;
}
{
var2048 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2045); /* == on <var_pname:String>*/
}
if (var2048){
if (unlikely(varonce2049==NULL)) {
var2050 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2051!=NULL)) {
var2052 = varonce2051;
} else {
var2053 = "(uint16_t)";
var2054 = core__flat___NativeString___to_s_full(var2053, 10l, 10l);
var2052 = var2054;
varonce2051 = var2052;
}
((struct instance_core__NativeArray*)var2050)->values[0]=var2052;
} else {
var2050 = varonce2049;
varonce2049 = NULL;
}
{
var2055 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2056 = ((val*(*)(val* self))(var2055->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2055); /* to_s on <var2055:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2050)->values[1]=var2056;
{
var2057 = ((val*(*)(val* self))(var2050->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2050); /* native_to_s on <var2050:NativeArray[String]>*/
}
varonce2049 = var2050;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2602);
fatal_exit(1);
}
{
var2058 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2057, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2058); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2059!=NULL)) {
var2060 = varonce2059;
} else {
var2061 = "to_i32";
var2062 = core__flat___NativeString___to_s_full(var2061, 6l, 6l);
var2060 = var2062;
varonce2059 = var2060;
}
{
var2063 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2060); /* == on <var_pname:String>*/
}
if (var2063){
if (unlikely(varonce2064==NULL)) {
var2065 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2066!=NULL)) {
var2067 = varonce2066;
} else {
var2068 = "(int32_t)";
var2069 = core__flat___NativeString___to_s_full(var2068, 9l, 9l);
var2067 = var2069;
varonce2066 = var2067;
}
((struct instance_core__NativeArray*)var2065)->values[0]=var2067;
} else {
var2065 = varonce2064;
varonce2064 = NULL;
}
{
var2070 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2071 = ((val*(*)(val* self))(var2070->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2070); /* to_s on <var2070:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2065)->values[1]=var2071;
{
var2072 = ((val*(*)(val* self))(var2065->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2065); /* native_to_s on <var2065:NativeArray[String]>*/
}
varonce2064 = var2065;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2605);
fatal_exit(1);
}
{
var2073 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2072, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2073); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2074!=NULL)) {
var2075 = varonce2074;
} else {
var2076 = "to_u32";
var2077 = core__flat___NativeString___to_s_full(var2076, 6l, 6l);
var2075 = var2077;
varonce2074 = var2075;
}
{
var2078 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2075); /* == on <var_pname:String>*/
}
if (var2078){
if (unlikely(varonce2079==NULL)) {
var2080 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2081!=NULL)) {
var2082 = varonce2081;
} else {
var2083 = "(uint32_t)";
var2084 = core__flat___NativeString___to_s_full(var2083, 10l, 10l);
var2082 = var2084;
varonce2081 = var2082;
}
((struct instance_core__NativeArray*)var2080)->values[0]=var2082;
} else {
var2080 = varonce2079;
varonce2079 = NULL;
}
{
var2085 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2086 = ((val*(*)(val* self))(var2085->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2085); /* to_s on <var2085:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2080)->values[1]=var2086;
{
var2087 = ((val*(*)(val* self))(var2080->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2080); /* native_to_s on <var2080:NativeArray[String]>*/
}
varonce2079 = var2080;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2608);
fatal_exit(1);
}
{
var2088 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2087, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2088); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2089!=NULL)) {
var2090 = varonce2089;
} else {
var2091 = "to_f";
var2092 = core__flat___NativeString___to_s_full(var2091, 4l, 4l);
var2090 = var2092;
varonce2089 = var2090;
}
{
var2093 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2090); /* == on <var_pname:String>*/
}
if (var2093){
if (unlikely(varonce2094==NULL)) {
var2095 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2096!=NULL)) {
var2097 = varonce2096;
} else {
var2098 = "(double)";
var2099 = core__flat___NativeString___to_s_full(var2098, 8l, 8l);
var2097 = var2099;
varonce2096 = var2097;
}
((struct instance_core__NativeArray*)var2095)->values[0]=var2097;
} else {
var2095 = varonce2094;
varonce2094 = NULL;
}
{
var2100 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2101 = ((val*(*)(val* self))(var2100->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2100); /* to_s on <var2100:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2095)->values[1]=var2101;
{
var2102 = ((val*(*)(val* self))(var2095->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2095); /* native_to_s on <var2095:NativeArray[String]>*/
}
varonce2094 = var2095;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2611);
fatal_exit(1);
}
{
var2103 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2102, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2103); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2104!=NULL)) {
var2105 = varonce2104;
} else {
var2106 = "&";
var2107 = core__flat___NativeString___to_s_full(var2106, 1l, 1l);
var2105 = var2107;
varonce2104 = var2105;
}
{
var2108 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2105); /* == on <var_pname:String>*/
}
if (var2108){
if (unlikely(varonce2109==NULL)) {
var2110 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2111!=NULL)) {
var2112 = varonce2111;
} else {
var2113 = " & ";
var2114 = core__flat___NativeString___to_s_full(var2113, 3l, 3l);
var2112 = var2114;
varonce2111 = var2112;
}
((struct instance_core__NativeArray*)var2110)->values[1]=var2112;
} else {
var2110 = varonce2109;
varonce2109 = NULL;
}
{
var2115 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2116 = ((val*(*)(val* self))(var2115->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2115); /* to_s on <var2115:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2110)->values[0]=var2116;
{
var2117 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2118 = ((val*(*)(val* self))(var2117->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2117); /* to_s on <var2117:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2110)->values[2]=var2118;
{
var2119 = ((val*(*)(val* self))(var2110->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2110); /* native_to_s on <var2110:NativeArray[String]>*/
}
varonce2109 = var2110;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2614);
fatal_exit(1);
}
{
var2120 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2119, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2120); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2121!=NULL)) {
var2122 = varonce2121;
} else {
var2123 = "|";
var2124 = core__flat___NativeString___to_s_full(var2123, 1l, 1l);
var2122 = var2124;
varonce2121 = var2122;
}
{
var2125 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2122); /* == on <var_pname:String>*/
}
if (var2125){
if (unlikely(varonce2126==NULL)) {
var2127 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2128!=NULL)) {
var2129 = varonce2128;
} else {
var2130 = " | ";
var2131 = core__flat___NativeString___to_s_full(var2130, 3l, 3l);
var2129 = var2131;
varonce2128 = var2129;
}
((struct instance_core__NativeArray*)var2127)->values[1]=var2129;
} else {
var2127 = varonce2126;
varonce2126 = NULL;
}
{
var2132 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2133 = ((val*(*)(val* self))(var2132->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2132); /* to_s on <var2132:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2127)->values[0]=var2133;
{
var2134 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2135 = ((val*(*)(val* self))(var2134->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2134); /* to_s on <var2134:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2127)->values[2]=var2135;
{
var2136 = ((val*(*)(val* self))(var2127->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2127); /* native_to_s on <var2127:NativeArray[String]>*/
}
varonce2126 = var2127;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2617);
fatal_exit(1);
}
{
var2137 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2136, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2137); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2138!=NULL)) {
var2139 = varonce2138;
} else {
var2140 = "^";
var2141 = core__flat___NativeString___to_s_full(var2140, 1l, 1l);
var2139 = var2141;
varonce2138 = var2139;
}
{
var2142 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2139); /* == on <var_pname:String>*/
}
if (var2142){
if (unlikely(varonce2143==NULL)) {
var2144 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2145!=NULL)) {
var2146 = varonce2145;
} else {
var2147 = " ^ ";
var2148 = core__flat___NativeString___to_s_full(var2147, 3l, 3l);
var2146 = var2148;
varonce2145 = var2146;
}
((struct instance_core__NativeArray*)var2144)->values[1]=var2146;
} else {
var2144 = varonce2143;
varonce2143 = NULL;
}
{
var2149 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2150 = ((val*(*)(val* self))(var2149->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2149); /* to_s on <var2149:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2144)->values[0]=var2150;
{
var2151 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2152 = ((val*(*)(val* self))(var2151->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2151); /* to_s on <var2151:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2144)->values[2]=var2152;
{
var2153 = ((val*(*)(val* self))(var2144->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2144); /* native_to_s on <var2144:NativeArray[String]>*/
}
varonce2143 = var2144;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2620);
fatal_exit(1);
}
{
var2154 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2153, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2154); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2155!=NULL)) {
var2156 = varonce2155;
} else {
var2157 = "unary ~";
var2158 = core__flat___NativeString___to_s_full(var2157, 7l, 7l);
var2156 = var2158;
varonce2155 = var2156;
}
{
var2159 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2156); /* == on <var_pname:String>*/
}
if (var2159){
if (unlikely(varonce2160==NULL)) {
var2161 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2162!=NULL)) {
var2163 = varonce2162;
} else {
var2164 = "~";
var2165 = core__flat___NativeString___to_s_full(var2164, 1l, 1l);
var2163 = var2165;
varonce2162 = var2163;
}
((struct instance_core__NativeArray*)var2161)->values[0]=var2163;
} else {
var2161 = varonce2160;
varonce2160 = NULL;
}
{
var2166 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2167 = ((val*(*)(val* self))(var2166->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2166); /* to_s on <var2166:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2161)->values[1]=var2167;
{
var2168 = ((val*(*)(val* self))(var2161->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2161); /* native_to_s on <var2161:NativeArray[String]>*/
}
varonce2160 = var2161;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2623);
fatal_exit(1);
}
{
var2169 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2168, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2169); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
} else {
if (likely(varonce2170!=NULL)) {
var2171 = varonce2170;
} else {
var2172 = "Int16";
var2173 = core__flat___NativeString___to_s_full(var2172, 5l, 5l);
var2171 = var2173;
varonce2170 = var2171;
}
{
var2174 = ((short int(*)(val* self, val* p0))(var_cname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_cname, var2171); /* == on <var_cname:String>*/
}
if (var2174){
if (likely(varonce2175!=NULL)) {
var2176 = varonce2175;
} else {
var2177 = "output";
var2178 = core__flat___NativeString___to_s_full(var2177, 6l, 6l);
var2176 = var2178;
varonce2175 = var2176;
}
{
var2179 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2176); /* == on <var_pname:String>*/
}
if (var2179){
if (unlikely(varonce2180==NULL)) {
var2181 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2182!=NULL)) {
var2183 = varonce2182;
} else {
var2184 = "printf(\"%\"PRIi16 \"\\n\", ";
var2185 = core__flat___NativeString___to_s_full(var2184, 23l, 23l);
var2183 = var2185;
varonce2182 = var2183;
}
((struct instance_core__NativeArray*)var2181)->values[0]=var2183;
if (likely(varonce2186!=NULL)) {
var2187 = varonce2186;
} else {
var2188 = ");";
var2189 = core__flat___NativeString___to_s_full(var2188, 2l, 2l);
var2187 = var2189;
varonce2186 = var2187;
}
((struct instance_core__NativeArray*)var2181)->values[2]=var2187;
} else {
var2181 = varonce2180;
varonce2180 = NULL;
}
{
var2190 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var2191 = ((val*(*)(val* self))(var2190->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2190); /* to_s on <var2190:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2181)->values[1]=var2191;
{
var2192 = ((val*(*)(val* self))(var2181->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2181); /* native_to_s on <var2181:NativeArray[String]>*/
}
varonce2180 = var2181;
{
nitc___nitc__AbstractCompilerVisitor___add(var_v, var2192); /* Direct call abstract_compiler#AbstractCompilerVisitor#add on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2193!=NULL)) {
var2194 = varonce2193;
} else {
var2195 = "object_id";
var2196 = core__flat___NativeString___to_s_full(var2195, 9l, 9l);
var2194 = var2196;
varonce2193 = var2194;
}
{
var2197 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2194); /* == on <var_pname:String>*/
}
if (var2197){
if (unlikely(varonce2198==NULL)) {
var2199 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2200!=NULL)) {
var2201 = varonce2200;
} else {
var2202 = "(long)";
var2203 = core__flat___NativeString___to_s_full(var2202, 6l, 6l);
var2201 = var2203;
varonce2200 = var2201;
}
((struct instance_core__NativeArray*)var2199)->values[0]=var2201;
} else {
var2199 = varonce2198;
varonce2198 = NULL;
}
{
var2204 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var2205 = ((val*(*)(val* self))(var2204->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2204); /* to_s on <var2204:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2199)->values[1]=var2205;
{
var2206 = ((val*(*)(val* self))(var2199->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2199); /* native_to_s on <var2199:NativeArray[String]>*/
}
varonce2198 = var2199;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2631);
fatal_exit(1);
}
{
var2207 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2206, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2207); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2208!=NULL)) {
var2209 = varonce2208;
} else {
var2210 = "+";
var2211 = core__flat___NativeString___to_s_full(var2210, 1l, 1l);
var2209 = var2211;
varonce2208 = var2209;
}
{
var2212 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2209); /* == on <var_pname:String>*/
}
if (var2212){
if (unlikely(varonce2213==NULL)) {
var2214 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2215!=NULL)) {
var2216 = varonce2215;
} else {
var2217 = " + ";
var2218 = core__flat___NativeString___to_s_full(var2217, 3l, 3l);
var2216 = var2218;
varonce2215 = var2216;
}
((struct instance_core__NativeArray*)var2214)->values[1]=var2216;
} else {
var2214 = varonce2213;
varonce2213 = NULL;
}
{
var2219 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2220 = ((val*(*)(val* self))(var2219->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2219); /* to_s on <var2219:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2214)->values[0]=var2220;
{
var2221 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2222 = ((val*(*)(val* self))(var2221->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2221); /* to_s on <var2221:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2214)->values[2]=var2222;
{
var2223 = ((val*(*)(val* self))(var2214->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2214); /* native_to_s on <var2214:NativeArray[String]>*/
}
varonce2213 = var2214;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2634);
fatal_exit(1);
}
{
var2224 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2223, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2224); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2225!=NULL)) {
var2226 = varonce2225;
} else {
var2227 = "-";
var2228 = core__flat___NativeString___to_s_full(var2227, 1l, 1l);
var2226 = var2228;
varonce2225 = var2226;
}
{
var2229 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2226); /* == on <var_pname:String>*/
}
if (var2229){
if (unlikely(varonce2230==NULL)) {
var2231 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2232!=NULL)) {
var2233 = varonce2232;
} else {
var2234 = " - ";
var2235 = core__flat___NativeString___to_s_full(var2234, 3l, 3l);
var2233 = var2235;
varonce2232 = var2233;
}
((struct instance_core__NativeArray*)var2231)->values[1]=var2233;
} else {
var2231 = varonce2230;
varonce2230 = NULL;
}
{
var2236 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2237 = ((val*(*)(val* self))(var2236->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2236); /* to_s on <var2236:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2231)->values[0]=var2237;
{
var2238 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2239 = ((val*(*)(val* self))(var2238->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2238); /* to_s on <var2238:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2231)->values[2]=var2239;
{
var2240 = ((val*(*)(val* self))(var2231->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2231); /* native_to_s on <var2231:NativeArray[String]>*/
}
varonce2230 = var2231;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2637);
fatal_exit(1);
}
{
var2241 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2240, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2241); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2242!=NULL)) {
var2243 = varonce2242;
} else {
var2244 = "unary -";
var2245 = core__flat___NativeString___to_s_full(var2244, 7l, 7l);
var2243 = var2245;
varonce2242 = var2243;
}
{
var2246 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2243); /* == on <var_pname:String>*/
}
if (var2246){
if (unlikely(varonce2247==NULL)) {
var2248 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2249!=NULL)) {
var2250 = varonce2249;
} else {
var2251 = "-";
var2252 = core__flat___NativeString___to_s_full(var2251, 1l, 1l);
var2250 = var2252;
varonce2249 = var2250;
}
((struct instance_core__NativeArray*)var2248)->values[0]=var2250;
} else {
var2248 = varonce2247;
varonce2247 = NULL;
}
{
var2253 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2254 = ((val*(*)(val* self))(var2253->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2253); /* to_s on <var2253:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2248)->values[1]=var2254;
{
var2255 = ((val*(*)(val* self))(var2248->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2248); /* native_to_s on <var2248:NativeArray[String]>*/
}
varonce2247 = var2248;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2640);
fatal_exit(1);
}
{
var2256 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2255, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2256); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2257!=NULL)) {
var2258 = varonce2257;
} else {
var2259 = "unary +";
var2260 = core__flat___NativeString___to_s_full(var2259, 7l, 7l);
var2258 = var2260;
varonce2257 = var2258;
}
{
var2261 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2258); /* == on <var_pname:String>*/
}
if (var2261){
{
var2262 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2262); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2263!=NULL)) {
var2264 = varonce2263;
} else {
var2265 = "*";
var2266 = core__flat___NativeString___to_s_full(var2265, 1l, 1l);
var2264 = var2266;
varonce2263 = var2264;
}
{
var2267 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2264); /* == on <var_pname:String>*/
}
if (var2267){
if (unlikely(varonce2268==NULL)) {
var2269 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2270!=NULL)) {
var2271 = varonce2270;
} else {
var2272 = " * ";
var2273 = core__flat___NativeString___to_s_full(var2272, 3l, 3l);
var2271 = var2273;
varonce2270 = var2271;
}
((struct instance_core__NativeArray*)var2269)->values[1]=var2271;
} else {
var2269 = varonce2268;
varonce2268 = NULL;
}
{
var2274 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2275 = ((val*(*)(val* self))(var2274->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2274); /* to_s on <var2274:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2269)->values[0]=var2275;
{
var2276 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2277 = ((val*(*)(val* self))(var2276->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2276); /* to_s on <var2276:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2269)->values[2]=var2277;
{
var2278 = ((val*(*)(val* self))(var2269->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2269); /* native_to_s on <var2269:NativeArray[String]>*/
}
varonce2268 = var2269;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2646);
fatal_exit(1);
}
{
var2279 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2278, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2279); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2280!=NULL)) {
var2281 = varonce2280;
} else {
var2282 = "/";
var2283 = core__flat___NativeString___to_s_full(var2282, 1l, 1l);
var2281 = var2283;
varonce2280 = var2281;
}
{
var2284 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2281); /* == on <var_pname:String>*/
}
if (var2284){
if (unlikely(varonce2285==NULL)) {
var2286 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2287!=NULL)) {
var2288 = varonce2287;
} else {
var2289 = " / ";
var2290 = core__flat___NativeString___to_s_full(var2289, 3l, 3l);
var2288 = var2290;
varonce2287 = var2288;
}
((struct instance_core__NativeArray*)var2286)->values[1]=var2288;
} else {
var2286 = varonce2285;
varonce2285 = NULL;
}
{
var2291 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2292 = ((val*(*)(val* self))(var2291->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2291); /* to_s on <var2291:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2286)->values[0]=var2292;
{
var2293 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2294 = ((val*(*)(val* self))(var2293->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2293); /* to_s on <var2293:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2286)->values[2]=var2294;
{
var2295 = ((val*(*)(val* self))(var2286->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2286); /* native_to_s on <var2286:NativeArray[String]>*/
}
varonce2285 = var2286;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2649);
fatal_exit(1);
}
{
var2296 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2295, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2296); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2297!=NULL)) {
var2298 = varonce2297;
} else {
var2299 = "%";
var2300 = core__flat___NativeString___to_s_full(var2299, 1l, 1l);
var2298 = var2300;
varonce2297 = var2298;
}
{
var2301 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2298); /* == on <var_pname:String>*/
}
if (var2301){
if (unlikely(varonce2302==NULL)) {
var2303 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2304!=NULL)) {
var2305 = varonce2304;
} else {
var2306 = " % ";
var2307 = core__flat___NativeString___to_s_full(var2306, 3l, 3l);
var2305 = var2307;
varonce2304 = var2305;
}
((struct instance_core__NativeArray*)var2303)->values[1]=var2305;
} else {
var2303 = varonce2302;
varonce2302 = NULL;
}
{
var2308 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2309 = ((val*(*)(val* self))(var2308->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2308); /* to_s on <var2308:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2303)->values[0]=var2309;
{
var2310 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2311 = ((val*(*)(val* self))(var2310->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2310); /* to_s on <var2310:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2303)->values[2]=var2311;
{
var2312 = ((val*(*)(val* self))(var2303->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2303); /* native_to_s on <var2303:NativeArray[String]>*/
}
varonce2302 = var2303;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2652);
fatal_exit(1);
}
{
var2313 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2312, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2313); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2314!=NULL)) {
var2315 = varonce2314;
} else {
var2316 = "<<";
var2317 = core__flat___NativeString___to_s_full(var2316, 2l, 2l);
var2315 = var2317;
varonce2314 = var2315;
}
{
var2318 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2315); /* == on <var_pname:String>*/
}
if (var2318){
if (unlikely(varonce2319==NULL)) {
var2320 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2321!=NULL)) {
var2322 = varonce2321;
} else {
var2323 = " << ";
var2324 = core__flat___NativeString___to_s_full(var2323, 4l, 4l);
var2322 = var2324;
varonce2321 = var2322;
}
((struct instance_core__NativeArray*)var2320)->values[1]=var2322;
} else {
var2320 = varonce2319;
varonce2319 = NULL;
}
{
var2325 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2326 = ((val*(*)(val* self))(var2325->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2325); /* to_s on <var2325:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2320)->values[0]=var2326;
{
var2327 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2328 = ((val*(*)(val* self))(var2327->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2327); /* to_s on <var2327:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2320)->values[2]=var2328;
{
var2329 = ((val*(*)(val* self))(var2320->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2320); /* native_to_s on <var2320:NativeArray[String]>*/
}
varonce2319 = var2320;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2655);
fatal_exit(1);
}
{
var2330 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2329, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2330); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2331!=NULL)) {
var2332 = varonce2331;
} else {
var2333 = ">>";
var2334 = core__flat___NativeString___to_s_full(var2333, 2l, 2l);
var2332 = var2334;
varonce2331 = var2332;
}
{
var2335 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2332); /* == on <var_pname:String>*/
}
if (var2335){
if (unlikely(varonce2336==NULL)) {
var2337 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2338!=NULL)) {
var2339 = varonce2338;
} else {
var2340 = " >> ";
var2341 = core__flat___NativeString___to_s_full(var2340, 4l, 4l);
var2339 = var2341;
varonce2338 = var2339;
}
((struct instance_core__NativeArray*)var2337)->values[1]=var2339;
} else {
var2337 = varonce2336;
varonce2336 = NULL;
}
{
var2342 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2343 = ((val*(*)(val* self))(var2342->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2342); /* to_s on <var2342:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2337)->values[0]=var2343;
{
var2344 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2345 = ((val*(*)(val* self))(var2344->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2344); /* to_s on <var2344:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2337)->values[2]=var2345;
{
var2346 = ((val*(*)(val* self))(var2337->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2337); /* native_to_s on <var2337:NativeArray[String]>*/
}
varonce2336 = var2337;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2658);
fatal_exit(1);
}
{
var2347 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2346, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2347); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2348!=NULL)) {
var2349 = varonce2348;
} else {
var2350 = "==";
var2351 = core__flat___NativeString___to_s_full(var2350, 2l, 2l);
var2349 = var2351;
varonce2348 = var2349;
}
{
var2352 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2349); /* == on <var_pname:String>*/
}
if (var2352){
{
var2353 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2354 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2355 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var2353, var2354);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2355); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2356!=NULL)) {
var2357 = varonce2356;
} else {
var2358 = "!=";
var2359 = core__flat___NativeString___to_s_full(var2358, 2l, 2l);
var2357 = var2359;
varonce2356 = var2357;
}
{
var2360 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2357); /* == on <var_pname:String>*/
}
if (var2360){
{
var2361 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2362 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2363 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var2361, var2362);
}
var_res2364 = var2363;
if (unlikely(varonce2365==NULL)) {
var2366 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2367!=NULL)) {
var2368 = varonce2367;
} else {
var2369 = "!";
var2370 = core__flat___NativeString___to_s_full(var2369, 1l, 1l);
var2368 = var2370;
varonce2367 = var2368;
}
((struct instance_core__NativeArray*)var2366)->values[0]=var2368;
} else {
var2366 = varonce2365;
varonce2365 = NULL;
}
{
var2371 = ((val*(*)(val* self))(var_res2364->class->vft[COLOR_core__abstract_text__Object__to_s]))(var_res2364); /* to_s on <var_res2364:RuntimeVariable>*/
}
((struct instance_core__NativeArray*)var2366)->values[1]=var2371;
{
var2372 = ((val*(*)(val* self))(var2366->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2366); /* native_to_s on <var2366:NativeArray[String]>*/
}
varonce2365 = var2366;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2665);
fatal_exit(1);
}
{
var2373 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2372, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2373); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2374!=NULL)) {
var2375 = varonce2374;
} else {
var2376 = "<";
var2377 = core__flat___NativeString___to_s_full(var2376, 1l, 1l);
var2375 = var2377;
varonce2374 = var2375;
}
{
var2378 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2375); /* == on <var_pname:String>*/
}
if (var2378){
if (unlikely(varonce2379==NULL)) {
var2380 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2381!=NULL)) {
var2382 = varonce2381;
} else {
var2383 = " < ";
var2384 = core__flat___NativeString___to_s_full(var2383, 3l, 3l);
var2382 = var2384;
varonce2381 = var2382;
}
((struct instance_core__NativeArray*)var2380)->values[1]=var2382;
} else {
var2380 = varonce2379;
varonce2379 = NULL;
}
{
var2385 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2386 = ((val*(*)(val* self))(var2385->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2385); /* to_s on <var2385:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2380)->values[0]=var2386;
{
var2387 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2388 = ((val*(*)(val* self))(var2387->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2387); /* to_s on <var2387:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2380)->values[2]=var2388;
{
var2389 = ((val*(*)(val* self))(var2380->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2380); /* native_to_s on <var2380:NativeArray[String]>*/
}
varonce2379 = var2380;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2668);
fatal_exit(1);
}
{
var2390 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2389, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2390); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2391!=NULL)) {
var2392 = varonce2391;
} else {
var2393 = ">";
var2394 = core__flat___NativeString___to_s_full(var2393, 1l, 1l);
var2392 = var2394;
varonce2391 = var2392;
}
{
var2395 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2392); /* == on <var_pname:String>*/
}
if (var2395){
if (unlikely(varonce2396==NULL)) {
var2397 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2398!=NULL)) {
var2399 = varonce2398;
} else {
var2400 = " > ";
var2401 = core__flat___NativeString___to_s_full(var2400, 3l, 3l);
var2399 = var2401;
varonce2398 = var2399;
}
((struct instance_core__NativeArray*)var2397)->values[1]=var2399;
} else {
var2397 = varonce2396;
varonce2396 = NULL;
}
{
var2402 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2403 = ((val*(*)(val* self))(var2402->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2402); /* to_s on <var2402:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2397)->values[0]=var2403;
{
var2404 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2405 = ((val*(*)(val* self))(var2404->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2404); /* to_s on <var2404:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2397)->values[2]=var2405;
{
var2406 = ((val*(*)(val* self))(var2397->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2397); /* native_to_s on <var2397:NativeArray[String]>*/
}
varonce2396 = var2397;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2671);
fatal_exit(1);
}
{
var2407 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2406, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2407); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2408!=NULL)) {
var2409 = varonce2408;
} else {
var2410 = "<=";
var2411 = core__flat___NativeString___to_s_full(var2410, 2l, 2l);
var2409 = var2411;
varonce2408 = var2409;
}
{
var2412 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2409); /* == on <var_pname:String>*/
}
if (var2412){
if (unlikely(varonce2413==NULL)) {
var2414 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2415!=NULL)) {
var2416 = varonce2415;
} else {
var2417 = " <= ";
var2418 = core__flat___NativeString___to_s_full(var2417, 4l, 4l);
var2416 = var2418;
varonce2415 = var2416;
}
((struct instance_core__NativeArray*)var2414)->values[1]=var2416;
} else {
var2414 = varonce2413;
varonce2413 = NULL;
}
{
var2419 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2420 = ((val*(*)(val* self))(var2419->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2419); /* to_s on <var2419:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2414)->values[0]=var2420;
{
var2421 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2422 = ((val*(*)(val* self))(var2421->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2421); /* to_s on <var2421:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2414)->values[2]=var2422;
{
var2423 = ((val*(*)(val* self))(var2414->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2414); /* native_to_s on <var2414:NativeArray[String]>*/
}
varonce2413 = var2414;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2674);
fatal_exit(1);
}
{
var2424 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2423, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2424); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2425!=NULL)) {
var2426 = varonce2425;
} else {
var2427 = ">=";
var2428 = core__flat___NativeString___to_s_full(var2427, 2l, 2l);
var2426 = var2428;
varonce2425 = var2426;
}
{
var2429 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2426); /* == on <var_pname:String>*/
}
if (var2429){
if (unlikely(varonce2430==NULL)) {
var2431 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2432!=NULL)) {
var2433 = varonce2432;
} else {
var2434 = " >= ";
var2435 = core__flat___NativeString___to_s_full(var2434, 4l, 4l);
var2433 = var2435;
varonce2432 = var2433;
}
((struct instance_core__NativeArray*)var2431)->values[1]=var2433;
} else {
var2431 = varonce2430;
varonce2430 = NULL;
}
{
var2436 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2437 = ((val*(*)(val* self))(var2436->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2436); /* to_s on <var2436:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2431)->values[0]=var2437;
{
var2438 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2439 = ((val*(*)(val* self))(var2438->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2438); /* to_s on <var2438:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2431)->values[2]=var2439;
{
var2440 = ((val*(*)(val* self))(var2431->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2431); /* native_to_s on <var2431:NativeArray[String]>*/
}
varonce2430 = var2431;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2677);
fatal_exit(1);
}
{
var2441 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2440, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2441); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2442!=NULL)) {
var2443 = varonce2442;
} else {
var2444 = "to_i";
var2445 = core__flat___NativeString___to_s_full(var2444, 4l, 4l);
var2443 = var2445;
varonce2442 = var2443;
}
{
var2446 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2443); /* == on <var_pname:String>*/
}
if (var2446){
if (unlikely(varonce2447==NULL)) {
var2448 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2449!=NULL)) {
var2450 = varonce2449;
} else {
var2451 = "(long)";
var2452 = core__flat___NativeString___to_s_full(var2451, 6l, 6l);
var2450 = var2452;
varonce2449 = var2450;
}
((struct instance_core__NativeArray*)var2448)->values[0]=var2450;
} else {
var2448 = varonce2447;
varonce2447 = NULL;
}
{
var2453 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2454 = ((val*(*)(val* self))(var2453->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2453); /* to_s on <var2453:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2448)->values[1]=var2454;
{
var2455 = ((val*(*)(val* self))(var2448->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2448); /* native_to_s on <var2448:NativeArray[String]>*/
}
varonce2447 = var2448;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2680);
fatal_exit(1);
}
{
var2456 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2455, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2456); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2457!=NULL)) {
var2458 = varonce2457;
} else {
var2459 = "to_b";
var2460 = core__flat___NativeString___to_s_full(var2459, 4l, 4l);
var2458 = var2460;
varonce2457 = var2458;
}
{
var2461 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2458); /* == on <var_pname:String>*/
}
if (var2461){
if (unlikely(varonce2462==NULL)) {
var2463 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2464!=NULL)) {
var2465 = varonce2464;
} else {
var2466 = "(unsigned char)";
var2467 = core__flat___NativeString___to_s_full(var2466, 15l, 15l);
var2465 = var2467;
varonce2464 = var2465;
}
((struct instance_core__NativeArray*)var2463)->values[0]=var2465;
} else {
var2463 = varonce2462;
varonce2462 = NULL;
}
{
var2468 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2469 = ((val*(*)(val* self))(var2468->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2468); /* to_s on <var2468:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2463)->values[1]=var2469;
{
var2470 = ((val*(*)(val* self))(var2463->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2463); /* native_to_s on <var2463:NativeArray[String]>*/
}
varonce2462 = var2463;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2683);
fatal_exit(1);
}
{
var2471 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2470, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2471); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2472!=NULL)) {
var2473 = varonce2472;
} else {
var2474 = "to_i8";
var2475 = core__flat___NativeString___to_s_full(var2474, 5l, 5l);
var2473 = var2475;
varonce2472 = var2473;
}
{
var2476 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2473); /* == on <var_pname:String>*/
}
if (var2476){
if (unlikely(varonce2477==NULL)) {
var2478 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2479!=NULL)) {
var2480 = varonce2479;
} else {
var2481 = "(int8_t)";
var2482 = core__flat___NativeString___to_s_full(var2481, 8l, 8l);
var2480 = var2482;
varonce2479 = var2480;
}
((struct instance_core__NativeArray*)var2478)->values[0]=var2480;
} else {
var2478 = varonce2477;
varonce2477 = NULL;
}
{
var2483 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2484 = ((val*(*)(val* self))(var2483->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2483); /* to_s on <var2483:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2478)->values[1]=var2484;
{
var2485 = ((val*(*)(val* self))(var2478->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2478); /* native_to_s on <var2478:NativeArray[String]>*/
}
varonce2477 = var2478;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2686);
fatal_exit(1);
}
{
var2486 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2485, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2486); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2487!=NULL)) {
var2488 = varonce2487;
} else {
var2489 = "to_u16";
var2490 = core__flat___NativeString___to_s_full(var2489, 6l, 6l);
var2488 = var2490;
varonce2487 = var2488;
}
{
var2491 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2488); /* == on <var_pname:String>*/
}
if (var2491){
if (unlikely(varonce2492==NULL)) {
var2493 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2494!=NULL)) {
var2495 = varonce2494;
} else {
var2496 = "(uint16_t)";
var2497 = core__flat___NativeString___to_s_full(var2496, 10l, 10l);
var2495 = var2497;
varonce2494 = var2495;
}
((struct instance_core__NativeArray*)var2493)->values[0]=var2495;
} else {
var2493 = varonce2492;
varonce2492 = NULL;
}
{
var2498 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2499 = ((val*(*)(val* self))(var2498->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2498); /* to_s on <var2498:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2493)->values[1]=var2499;
{
var2500 = ((val*(*)(val* self))(var2493->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2493); /* native_to_s on <var2493:NativeArray[String]>*/
}
varonce2492 = var2493;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2689);
fatal_exit(1);
}
{
var2501 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2500, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2501); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2502!=NULL)) {
var2503 = varonce2502;
} else {
var2504 = "to_i32";
var2505 = core__flat___NativeString___to_s_full(var2504, 6l, 6l);
var2503 = var2505;
varonce2502 = var2503;
}
{
var2506 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2503); /* == on <var_pname:String>*/
}
if (var2506){
if (unlikely(varonce2507==NULL)) {
var2508 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2509!=NULL)) {
var2510 = varonce2509;
} else {
var2511 = "(int32_t)";
var2512 = core__flat___NativeString___to_s_full(var2511, 9l, 9l);
var2510 = var2512;
varonce2509 = var2510;
}
((struct instance_core__NativeArray*)var2508)->values[0]=var2510;
} else {
var2508 = varonce2507;
varonce2507 = NULL;
}
{
var2513 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2514 = ((val*(*)(val* self))(var2513->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2513); /* to_s on <var2513:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2508)->values[1]=var2514;
{
var2515 = ((val*(*)(val* self))(var2508->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2508); /* native_to_s on <var2508:NativeArray[String]>*/
}
varonce2507 = var2508;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2692);
fatal_exit(1);
}
{
var2516 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2515, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2516); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2517!=NULL)) {
var2518 = varonce2517;
} else {
var2519 = "to_u32";
var2520 = core__flat___NativeString___to_s_full(var2519, 6l, 6l);
var2518 = var2520;
varonce2517 = var2518;
}
{
var2521 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2518); /* == on <var_pname:String>*/
}
if (var2521){
if (unlikely(varonce2522==NULL)) {
var2523 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2524!=NULL)) {
var2525 = varonce2524;
} else {
var2526 = "(uint32_t)";
var2527 = core__flat___NativeString___to_s_full(var2526, 10l, 10l);
var2525 = var2527;
varonce2524 = var2525;
}
((struct instance_core__NativeArray*)var2523)->values[0]=var2525;
} else {
var2523 = varonce2522;
varonce2522 = NULL;
}
{
var2528 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2529 = ((val*(*)(val* self))(var2528->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2528); /* to_s on <var2528:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2523)->values[1]=var2529;
{
var2530 = ((val*(*)(val* self))(var2523->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2523); /* native_to_s on <var2523:NativeArray[String]>*/
}
varonce2522 = var2523;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2695);
fatal_exit(1);
}
{
var2531 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2530, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2531); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2532!=NULL)) {
var2533 = varonce2532;
} else {
var2534 = "to_f";
var2535 = core__flat___NativeString___to_s_full(var2534, 4l, 4l);
var2533 = var2535;
varonce2532 = var2533;
}
{
var2536 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2533); /* == on <var_pname:String>*/
}
if (var2536){
if (unlikely(varonce2537==NULL)) {
var2538 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2539!=NULL)) {
var2540 = varonce2539;
} else {
var2541 = "(double)";
var2542 = core__flat___NativeString___to_s_full(var2541, 8l, 8l);
var2540 = var2542;
varonce2539 = var2540;
}
((struct instance_core__NativeArray*)var2538)->values[0]=var2540;
} else {
var2538 = varonce2537;
varonce2537 = NULL;
}
{
var2543 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2544 = ((val*(*)(val* self))(var2543->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2543); /* to_s on <var2543:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2538)->values[1]=var2544;
{
var2545 = ((val*(*)(val* self))(var2538->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2538); /* native_to_s on <var2538:NativeArray[String]>*/
}
varonce2537 = var2538;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2698);
fatal_exit(1);
}
{
var2546 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2545, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2546); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2547!=NULL)) {
var2548 = varonce2547;
} else {
var2549 = "&";
var2550 = core__flat___NativeString___to_s_full(var2549, 1l, 1l);
var2548 = var2550;
varonce2547 = var2548;
}
{
var2551 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2548); /* == on <var_pname:String>*/
}
if (var2551){
if (unlikely(varonce2552==NULL)) {
var2553 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2554!=NULL)) {
var2555 = varonce2554;
} else {
var2556 = " & ";
var2557 = core__flat___NativeString___to_s_full(var2556, 3l, 3l);
var2555 = var2557;
varonce2554 = var2555;
}
((struct instance_core__NativeArray*)var2553)->values[1]=var2555;
} else {
var2553 = varonce2552;
varonce2552 = NULL;
}
{
var2558 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2559 = ((val*(*)(val* self))(var2558->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2558); /* to_s on <var2558:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2553)->values[0]=var2559;
{
var2560 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2561 = ((val*(*)(val* self))(var2560->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2560); /* to_s on <var2560:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2553)->values[2]=var2561;
{
var2562 = ((val*(*)(val* self))(var2553->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2553); /* native_to_s on <var2553:NativeArray[String]>*/
}
varonce2552 = var2553;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2701);
fatal_exit(1);
}
{
var2563 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2562, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2563); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2564!=NULL)) {
var2565 = varonce2564;
} else {
var2566 = "|";
var2567 = core__flat___NativeString___to_s_full(var2566, 1l, 1l);
var2565 = var2567;
varonce2564 = var2565;
}
{
var2568 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2565); /* == on <var_pname:String>*/
}
if (var2568){
if (unlikely(varonce2569==NULL)) {
var2570 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2571!=NULL)) {
var2572 = varonce2571;
} else {
var2573 = " | ";
var2574 = core__flat___NativeString___to_s_full(var2573, 3l, 3l);
var2572 = var2574;
varonce2571 = var2572;
}
((struct instance_core__NativeArray*)var2570)->values[1]=var2572;
} else {
var2570 = varonce2569;
varonce2569 = NULL;
}
{
var2575 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2576 = ((val*(*)(val* self))(var2575->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2575); /* to_s on <var2575:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2570)->values[0]=var2576;
{
var2577 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2578 = ((val*(*)(val* self))(var2577->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2577); /* to_s on <var2577:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2570)->values[2]=var2578;
{
var2579 = ((val*(*)(val* self))(var2570->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2570); /* native_to_s on <var2570:NativeArray[String]>*/
}
varonce2569 = var2570;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2704);
fatal_exit(1);
}
{
var2580 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2579, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2580); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2581!=NULL)) {
var2582 = varonce2581;
} else {
var2583 = "^";
var2584 = core__flat___NativeString___to_s_full(var2583, 1l, 1l);
var2582 = var2584;
varonce2581 = var2582;
}
{
var2585 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2582); /* == on <var_pname:String>*/
}
if (var2585){
if (unlikely(varonce2586==NULL)) {
var2587 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2588!=NULL)) {
var2589 = varonce2588;
} else {
var2590 = " ^ ";
var2591 = core__flat___NativeString___to_s_full(var2590, 3l, 3l);
var2589 = var2591;
varonce2588 = var2589;
}
((struct instance_core__NativeArray*)var2587)->values[1]=var2589;
} else {
var2587 = varonce2586;
varonce2586 = NULL;
}
{
var2592 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2593 = ((val*(*)(val* self))(var2592->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2592); /* to_s on <var2592:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2587)->values[0]=var2593;
{
var2594 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2595 = ((val*(*)(val* self))(var2594->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2594); /* to_s on <var2594:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2587)->values[2]=var2595;
{
var2596 = ((val*(*)(val* self))(var2587->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2587); /* native_to_s on <var2587:NativeArray[String]>*/
}
varonce2586 = var2587;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2707);
fatal_exit(1);
}
{
var2597 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2596, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2597); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2598!=NULL)) {
var2599 = varonce2598;
} else {
var2600 = "unary ~";
var2601 = core__flat___NativeString___to_s_full(var2600, 7l, 7l);
var2599 = var2601;
varonce2598 = var2599;
}
{
var2602 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2599); /* == on <var_pname:String>*/
}
if (var2602){
if (unlikely(varonce2603==NULL)) {
var2604 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2605!=NULL)) {
var2606 = varonce2605;
} else {
var2607 = "~";
var2608 = core__flat___NativeString___to_s_full(var2607, 1l, 1l);
var2606 = var2608;
varonce2605 = var2606;
}
((struct instance_core__NativeArray*)var2604)->values[0]=var2606;
} else {
var2604 = varonce2603;
varonce2603 = NULL;
}
{
var2609 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2610 = ((val*(*)(val* self))(var2609->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2609); /* to_s on <var2609:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2604)->values[1]=var2610;
{
var2611 = ((val*(*)(val* self))(var2604->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2604); /* native_to_s on <var2604:NativeArray[String]>*/
}
varonce2603 = var2604;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2710);
fatal_exit(1);
}
{
var2612 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2611, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2612); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
} else {
if (likely(varonce2613!=NULL)) {
var2614 = varonce2613;
} else {
var2615 = "UInt16";
var2616 = core__flat___NativeString___to_s_full(var2615, 6l, 6l);
var2614 = var2616;
varonce2613 = var2614;
}
{
var2617 = ((short int(*)(val* self, val* p0))(var_cname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_cname, var2614); /* == on <var_cname:String>*/
}
if (var2617){
if (likely(varonce2618!=NULL)) {
var2619 = varonce2618;
} else {
var2620 = "output";
var2621 = core__flat___NativeString___to_s_full(var2620, 6l, 6l);
var2619 = var2621;
varonce2618 = var2619;
}
{
var2622 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2619); /* == on <var_pname:String>*/
}
if (var2622){
if (unlikely(varonce2623==NULL)) {
var2624 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2625!=NULL)) {
var2626 = varonce2625;
} else {
var2627 = "printf(\"%\"PRIu16 \"\\n\", ";
var2628 = core__flat___NativeString___to_s_full(var2627, 23l, 23l);
var2626 = var2628;
varonce2625 = var2626;
}
((struct instance_core__NativeArray*)var2624)->values[0]=var2626;
if (likely(varonce2629!=NULL)) {
var2630 = varonce2629;
} else {
var2631 = ");";
var2632 = core__flat___NativeString___to_s_full(var2631, 2l, 2l);
var2630 = var2632;
varonce2629 = var2630;
}
((struct instance_core__NativeArray*)var2624)->values[2]=var2630;
} else {
var2624 = varonce2623;
varonce2623 = NULL;
}
{
var2633 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var2634 = ((val*(*)(val* self))(var2633->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2633); /* to_s on <var2633:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2624)->values[1]=var2634;
{
var2635 = ((val*(*)(val* self))(var2624->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2624); /* native_to_s on <var2624:NativeArray[String]>*/
}
varonce2623 = var2624;
{
nitc___nitc__AbstractCompilerVisitor___add(var_v, var2635); /* Direct call abstract_compiler#AbstractCompilerVisitor#add on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2636!=NULL)) {
var2637 = varonce2636;
} else {
var2638 = "object_id";
var2639 = core__flat___NativeString___to_s_full(var2638, 9l, 9l);
var2637 = var2639;
varonce2636 = var2637;
}
{
var2640 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2637); /* == on <var_pname:String>*/
}
if (var2640){
if (unlikely(varonce2641==NULL)) {
var2642 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2643!=NULL)) {
var2644 = varonce2643;
} else {
var2645 = "(long)";
var2646 = core__flat___NativeString___to_s_full(var2645, 6l, 6l);
var2644 = var2646;
varonce2643 = var2644;
}
((struct instance_core__NativeArray*)var2642)->values[0]=var2644;
} else {
var2642 = varonce2641;
varonce2641 = NULL;
}
{
var2647 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var2648 = ((val*(*)(val* self))(var2647->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2647); /* to_s on <var2647:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2642)->values[1]=var2648;
{
var2649 = ((val*(*)(val* self))(var2642->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2642); /* native_to_s on <var2642:NativeArray[String]>*/
}
varonce2641 = var2642;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2718);
fatal_exit(1);
}
{
var2650 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2649, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2650); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2651!=NULL)) {
var2652 = varonce2651;
} else {
var2653 = "+";
var2654 = core__flat___NativeString___to_s_full(var2653, 1l, 1l);
var2652 = var2654;
varonce2651 = var2652;
}
{
var2655 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2652); /* == on <var_pname:String>*/
}
if (var2655){
if (unlikely(varonce2656==NULL)) {
var2657 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2658!=NULL)) {
var2659 = varonce2658;
} else {
var2660 = " + ";
var2661 = core__flat___NativeString___to_s_full(var2660, 3l, 3l);
var2659 = var2661;
varonce2658 = var2659;
}
((struct instance_core__NativeArray*)var2657)->values[1]=var2659;
} else {
var2657 = varonce2656;
varonce2656 = NULL;
}
{
var2662 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2663 = ((val*(*)(val* self))(var2662->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2662); /* to_s on <var2662:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2657)->values[0]=var2663;
{
var2664 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2665 = ((val*(*)(val* self))(var2664->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2664); /* to_s on <var2664:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2657)->values[2]=var2665;
{
var2666 = ((val*(*)(val* self))(var2657->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2657); /* native_to_s on <var2657:NativeArray[String]>*/
}
varonce2656 = var2657;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2721);
fatal_exit(1);
}
{
var2667 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2666, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2667); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2668!=NULL)) {
var2669 = varonce2668;
} else {
var2670 = "-";
var2671 = core__flat___NativeString___to_s_full(var2670, 1l, 1l);
var2669 = var2671;
varonce2668 = var2669;
}
{
var2672 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2669); /* == on <var_pname:String>*/
}
if (var2672){
if (unlikely(varonce2673==NULL)) {
var2674 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2675!=NULL)) {
var2676 = varonce2675;
} else {
var2677 = " - ";
var2678 = core__flat___NativeString___to_s_full(var2677, 3l, 3l);
var2676 = var2678;
varonce2675 = var2676;
}
((struct instance_core__NativeArray*)var2674)->values[1]=var2676;
} else {
var2674 = varonce2673;
varonce2673 = NULL;
}
{
var2679 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2680 = ((val*(*)(val* self))(var2679->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2679); /* to_s on <var2679:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2674)->values[0]=var2680;
{
var2681 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2682 = ((val*(*)(val* self))(var2681->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2681); /* to_s on <var2681:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2674)->values[2]=var2682;
{
var2683 = ((val*(*)(val* self))(var2674->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2674); /* native_to_s on <var2674:NativeArray[String]>*/
}
varonce2673 = var2674;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2724);
fatal_exit(1);
}
{
var2684 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2683, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2684); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2685!=NULL)) {
var2686 = varonce2685;
} else {
var2687 = "unary -";
var2688 = core__flat___NativeString___to_s_full(var2687, 7l, 7l);
var2686 = var2688;
varonce2685 = var2686;
}
{
var2689 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2686); /* == on <var_pname:String>*/
}
if (var2689){
if (unlikely(varonce2690==NULL)) {
var2691 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2692!=NULL)) {
var2693 = varonce2692;
} else {
var2694 = "-";
var2695 = core__flat___NativeString___to_s_full(var2694, 1l, 1l);
var2693 = var2695;
varonce2692 = var2693;
}
((struct instance_core__NativeArray*)var2691)->values[0]=var2693;
} else {
var2691 = varonce2690;
varonce2690 = NULL;
}
{
var2696 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2697 = ((val*(*)(val* self))(var2696->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2696); /* to_s on <var2696:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2691)->values[1]=var2697;
{
var2698 = ((val*(*)(val* self))(var2691->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2691); /* native_to_s on <var2691:NativeArray[String]>*/
}
varonce2690 = var2691;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2727);
fatal_exit(1);
}
{
var2699 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2698, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2699); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2700!=NULL)) {
var2701 = varonce2700;
} else {
var2702 = "unary +";
var2703 = core__flat___NativeString___to_s_full(var2702, 7l, 7l);
var2701 = var2703;
varonce2700 = var2701;
}
{
var2704 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2701); /* == on <var_pname:String>*/
}
if (var2704){
{
var2705 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2705); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2706!=NULL)) {
var2707 = varonce2706;
} else {
var2708 = "*";
var2709 = core__flat___NativeString___to_s_full(var2708, 1l, 1l);
var2707 = var2709;
varonce2706 = var2707;
}
{
var2710 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2707); /* == on <var_pname:String>*/
}
if (var2710){
if (unlikely(varonce2711==NULL)) {
var2712 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2713!=NULL)) {
var2714 = varonce2713;
} else {
var2715 = " * ";
var2716 = core__flat___NativeString___to_s_full(var2715, 3l, 3l);
var2714 = var2716;
varonce2713 = var2714;
}
((struct instance_core__NativeArray*)var2712)->values[1]=var2714;
} else {
var2712 = varonce2711;
varonce2711 = NULL;
}
{
var2717 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2718 = ((val*(*)(val* self))(var2717->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2717); /* to_s on <var2717:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2712)->values[0]=var2718;
{
var2719 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2720 = ((val*(*)(val* self))(var2719->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2719); /* to_s on <var2719:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2712)->values[2]=var2720;
{
var2721 = ((val*(*)(val* self))(var2712->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2712); /* native_to_s on <var2712:NativeArray[String]>*/
}
varonce2711 = var2712;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2733);
fatal_exit(1);
}
{
var2722 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2721, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2722); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2723!=NULL)) {
var2724 = varonce2723;
} else {
var2725 = "/";
var2726 = core__flat___NativeString___to_s_full(var2725, 1l, 1l);
var2724 = var2726;
varonce2723 = var2724;
}
{
var2727 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2724); /* == on <var_pname:String>*/
}
if (var2727){
if (unlikely(varonce2728==NULL)) {
var2729 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2730!=NULL)) {
var2731 = varonce2730;
} else {
var2732 = " / ";
var2733 = core__flat___NativeString___to_s_full(var2732, 3l, 3l);
var2731 = var2733;
varonce2730 = var2731;
}
((struct instance_core__NativeArray*)var2729)->values[1]=var2731;
} else {
var2729 = varonce2728;
varonce2728 = NULL;
}
{
var2734 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2735 = ((val*(*)(val* self))(var2734->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2734); /* to_s on <var2734:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2729)->values[0]=var2735;
{
var2736 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2737 = ((val*(*)(val* self))(var2736->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2736); /* to_s on <var2736:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2729)->values[2]=var2737;
{
var2738 = ((val*(*)(val* self))(var2729->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2729); /* native_to_s on <var2729:NativeArray[String]>*/
}
varonce2728 = var2729;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2736);
fatal_exit(1);
}
{
var2739 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2738, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2739); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2740!=NULL)) {
var2741 = varonce2740;
} else {
var2742 = "%";
var2743 = core__flat___NativeString___to_s_full(var2742, 1l, 1l);
var2741 = var2743;
varonce2740 = var2741;
}
{
var2744 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2741); /* == on <var_pname:String>*/
}
if (var2744){
if (unlikely(varonce2745==NULL)) {
var2746 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2747!=NULL)) {
var2748 = varonce2747;
} else {
var2749 = " % ";
var2750 = core__flat___NativeString___to_s_full(var2749, 3l, 3l);
var2748 = var2750;
varonce2747 = var2748;
}
((struct instance_core__NativeArray*)var2746)->values[1]=var2748;
} else {
var2746 = varonce2745;
varonce2745 = NULL;
}
{
var2751 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2752 = ((val*(*)(val* self))(var2751->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2751); /* to_s on <var2751:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2746)->values[0]=var2752;
{
var2753 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2754 = ((val*(*)(val* self))(var2753->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2753); /* to_s on <var2753:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2746)->values[2]=var2754;
{
var2755 = ((val*(*)(val* self))(var2746->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2746); /* native_to_s on <var2746:NativeArray[String]>*/
}
varonce2745 = var2746;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2739);
fatal_exit(1);
}
{
var2756 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2755, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2756); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2757!=NULL)) {
var2758 = varonce2757;
} else {
var2759 = "<<";
var2760 = core__flat___NativeString___to_s_full(var2759, 2l, 2l);
var2758 = var2760;
varonce2757 = var2758;
}
{
var2761 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2758); /* == on <var_pname:String>*/
}
if (var2761){
if (unlikely(varonce2762==NULL)) {
var2763 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2764!=NULL)) {
var2765 = varonce2764;
} else {
var2766 = " << ";
var2767 = core__flat___NativeString___to_s_full(var2766, 4l, 4l);
var2765 = var2767;
varonce2764 = var2765;
}
((struct instance_core__NativeArray*)var2763)->values[1]=var2765;
} else {
var2763 = varonce2762;
varonce2762 = NULL;
}
{
var2768 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2769 = ((val*(*)(val* self))(var2768->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2768); /* to_s on <var2768:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2763)->values[0]=var2769;
{
var2770 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2771 = ((val*(*)(val* self))(var2770->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2770); /* to_s on <var2770:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2763)->values[2]=var2771;
{
var2772 = ((val*(*)(val* self))(var2763->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2763); /* native_to_s on <var2763:NativeArray[String]>*/
}
varonce2762 = var2763;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2742);
fatal_exit(1);
}
{
var2773 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2772, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2773); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2774!=NULL)) {
var2775 = varonce2774;
} else {
var2776 = ">>";
var2777 = core__flat___NativeString___to_s_full(var2776, 2l, 2l);
var2775 = var2777;
varonce2774 = var2775;
}
{
var2778 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2775); /* == on <var_pname:String>*/
}
if (var2778){
if (unlikely(varonce2779==NULL)) {
var2780 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2781!=NULL)) {
var2782 = varonce2781;
} else {
var2783 = " >> ";
var2784 = core__flat___NativeString___to_s_full(var2783, 4l, 4l);
var2782 = var2784;
varonce2781 = var2782;
}
((struct instance_core__NativeArray*)var2780)->values[1]=var2782;
} else {
var2780 = varonce2779;
varonce2779 = NULL;
}
{
var2785 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2786 = ((val*(*)(val* self))(var2785->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2785); /* to_s on <var2785:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2780)->values[0]=var2786;
{
var2787 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2788 = ((val*(*)(val* self))(var2787->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2787); /* to_s on <var2787:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2780)->values[2]=var2788;
{
var2789 = ((val*(*)(val* self))(var2780->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2780); /* native_to_s on <var2780:NativeArray[String]>*/
}
varonce2779 = var2780;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2745);
fatal_exit(1);
}
{
var2790 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2789, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2790); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2791!=NULL)) {
var2792 = varonce2791;
} else {
var2793 = "==";
var2794 = core__flat___NativeString___to_s_full(var2793, 2l, 2l);
var2792 = var2794;
varonce2791 = var2792;
}
{
var2795 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2792); /* == on <var_pname:String>*/
}
if (var2795){
{
var2796 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2797 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2798 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var2796, var2797);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2798); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2799!=NULL)) {
var2800 = varonce2799;
} else {
var2801 = "!=";
var2802 = core__flat___NativeString___to_s_full(var2801, 2l, 2l);
var2800 = var2802;
varonce2799 = var2800;
}
{
var2803 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2800); /* == on <var_pname:String>*/
}
if (var2803){
{
var2804 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2805 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2806 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var2804, var2805);
}
var_res2807 = var2806;
if (unlikely(varonce2808==NULL)) {
var2809 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2810!=NULL)) {
var2811 = varonce2810;
} else {
var2812 = "!";
var2813 = core__flat___NativeString___to_s_full(var2812, 1l, 1l);
var2811 = var2813;
varonce2810 = var2811;
}
((struct instance_core__NativeArray*)var2809)->values[0]=var2811;
} else {
var2809 = varonce2808;
varonce2808 = NULL;
}
{
var2814 = ((val*(*)(val* self))(var_res2807->class->vft[COLOR_core__abstract_text__Object__to_s]))(var_res2807); /* to_s on <var_res2807:RuntimeVariable>*/
}
((struct instance_core__NativeArray*)var2809)->values[1]=var2814;
{
var2815 = ((val*(*)(val* self))(var2809->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2809); /* native_to_s on <var2809:NativeArray[String]>*/
}
varonce2808 = var2809;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2752);
fatal_exit(1);
}
{
var2816 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2815, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2816); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2817!=NULL)) {
var2818 = varonce2817;
} else {
var2819 = "<";
var2820 = core__flat___NativeString___to_s_full(var2819, 1l, 1l);
var2818 = var2820;
varonce2817 = var2818;
}
{
var2821 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2818); /* == on <var_pname:String>*/
}
if (var2821){
if (unlikely(varonce2822==NULL)) {
var2823 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2824!=NULL)) {
var2825 = varonce2824;
} else {
var2826 = " < ";
var2827 = core__flat___NativeString___to_s_full(var2826, 3l, 3l);
var2825 = var2827;
varonce2824 = var2825;
}
((struct instance_core__NativeArray*)var2823)->values[1]=var2825;
} else {
var2823 = varonce2822;
varonce2822 = NULL;
}
{
var2828 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2829 = ((val*(*)(val* self))(var2828->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2828); /* to_s on <var2828:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2823)->values[0]=var2829;
{
var2830 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2831 = ((val*(*)(val* self))(var2830->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2830); /* to_s on <var2830:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2823)->values[2]=var2831;
{
var2832 = ((val*(*)(val* self))(var2823->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2823); /* native_to_s on <var2823:NativeArray[String]>*/
}
varonce2822 = var2823;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2755);
fatal_exit(1);
}
{
var2833 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2832, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2833); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2834!=NULL)) {
var2835 = varonce2834;
} else {
var2836 = ">";
var2837 = core__flat___NativeString___to_s_full(var2836, 1l, 1l);
var2835 = var2837;
varonce2834 = var2835;
}
{
var2838 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2835); /* == on <var_pname:String>*/
}
if (var2838){
if (unlikely(varonce2839==NULL)) {
var2840 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2841!=NULL)) {
var2842 = varonce2841;
} else {
var2843 = " > ";
var2844 = core__flat___NativeString___to_s_full(var2843, 3l, 3l);
var2842 = var2844;
varonce2841 = var2842;
}
((struct instance_core__NativeArray*)var2840)->values[1]=var2842;
} else {
var2840 = varonce2839;
varonce2839 = NULL;
}
{
var2845 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2846 = ((val*(*)(val* self))(var2845->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2845); /* to_s on <var2845:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2840)->values[0]=var2846;
{
var2847 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2848 = ((val*(*)(val* self))(var2847->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2847); /* to_s on <var2847:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2840)->values[2]=var2848;
{
var2849 = ((val*(*)(val* self))(var2840->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2840); /* native_to_s on <var2840:NativeArray[String]>*/
}
varonce2839 = var2840;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2758);
fatal_exit(1);
}
{
var2850 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2849, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2850); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2851!=NULL)) {
var2852 = varonce2851;
} else {
var2853 = "<=";
var2854 = core__flat___NativeString___to_s_full(var2853, 2l, 2l);
var2852 = var2854;
varonce2851 = var2852;
}
{
var2855 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2852); /* == on <var_pname:String>*/
}
if (var2855){
if (unlikely(varonce2856==NULL)) {
var2857 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2858!=NULL)) {
var2859 = varonce2858;
} else {
var2860 = " <= ";
var2861 = core__flat___NativeString___to_s_full(var2860, 4l, 4l);
var2859 = var2861;
varonce2858 = var2859;
}
((struct instance_core__NativeArray*)var2857)->values[1]=var2859;
} else {
var2857 = varonce2856;
varonce2856 = NULL;
}
{
var2862 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2863 = ((val*(*)(val* self))(var2862->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2862); /* to_s on <var2862:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2857)->values[0]=var2863;
{
var2864 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2865 = ((val*(*)(val* self))(var2864->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2864); /* to_s on <var2864:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2857)->values[2]=var2865;
{
var2866 = ((val*(*)(val* self))(var2857->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2857); /* native_to_s on <var2857:NativeArray[String]>*/
}
varonce2856 = var2857;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2761);
fatal_exit(1);
}
{
var2867 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2866, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2867); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2868!=NULL)) {
var2869 = varonce2868;
} else {
var2870 = ">=";
var2871 = core__flat___NativeString___to_s_full(var2870, 2l, 2l);
var2869 = var2871;
varonce2868 = var2869;
}
{
var2872 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2869); /* == on <var_pname:String>*/
}
if (var2872){
if (unlikely(varonce2873==NULL)) {
var2874 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2875!=NULL)) {
var2876 = varonce2875;
} else {
var2877 = " >= ";
var2878 = core__flat___NativeString___to_s_full(var2877, 4l, 4l);
var2876 = var2878;
varonce2875 = var2876;
}
((struct instance_core__NativeArray*)var2874)->values[1]=var2876;
} else {
var2874 = varonce2873;
varonce2873 = NULL;
}
{
var2879 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2880 = ((val*(*)(val* self))(var2879->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2879); /* to_s on <var2879:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2874)->values[0]=var2880;
{
var2881 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var2882 = ((val*(*)(val* self))(var2881->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2881); /* to_s on <var2881:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2874)->values[2]=var2882;
{
var2883 = ((val*(*)(val* self))(var2874->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2874); /* native_to_s on <var2874:NativeArray[String]>*/
}
varonce2873 = var2874;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2764);
fatal_exit(1);
}
{
var2884 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2883, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2884); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2885!=NULL)) {
var2886 = varonce2885;
} else {
var2887 = "to_i";
var2888 = core__flat___NativeString___to_s_full(var2887, 4l, 4l);
var2886 = var2888;
varonce2885 = var2886;
}
{
var2889 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2886); /* == on <var_pname:String>*/
}
if (var2889){
if (unlikely(varonce2890==NULL)) {
var2891 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2892!=NULL)) {
var2893 = varonce2892;
} else {
var2894 = "(long)";
var2895 = core__flat___NativeString___to_s_full(var2894, 6l, 6l);
var2893 = var2895;
varonce2892 = var2893;
}
((struct instance_core__NativeArray*)var2891)->values[0]=var2893;
} else {
var2891 = varonce2890;
varonce2890 = NULL;
}
{
var2896 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2897 = ((val*(*)(val* self))(var2896->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2896); /* to_s on <var2896:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2891)->values[1]=var2897;
{
var2898 = ((val*(*)(val* self))(var2891->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2891); /* native_to_s on <var2891:NativeArray[String]>*/
}
varonce2890 = var2891;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2767);
fatal_exit(1);
}
{
var2899 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2898, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2899); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2900!=NULL)) {
var2901 = varonce2900;
} else {
var2902 = "to_b";
var2903 = core__flat___NativeString___to_s_full(var2902, 4l, 4l);
var2901 = var2903;
varonce2900 = var2901;
}
{
var2904 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2901); /* == on <var_pname:String>*/
}
if (var2904){
if (unlikely(varonce2905==NULL)) {
var2906 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2907!=NULL)) {
var2908 = varonce2907;
} else {
var2909 = "(unsigned char)";
var2910 = core__flat___NativeString___to_s_full(var2909, 15l, 15l);
var2908 = var2910;
varonce2907 = var2908;
}
((struct instance_core__NativeArray*)var2906)->values[0]=var2908;
} else {
var2906 = varonce2905;
varonce2905 = NULL;
}
{
var2911 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2912 = ((val*(*)(val* self))(var2911->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2911); /* to_s on <var2911:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2906)->values[1]=var2912;
{
var2913 = ((val*(*)(val* self))(var2906->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2906); /* native_to_s on <var2906:NativeArray[String]>*/
}
varonce2905 = var2906;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2770);
fatal_exit(1);
}
{
var2914 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2913, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2914); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2915!=NULL)) {
var2916 = varonce2915;
} else {
var2917 = "to_i8";
var2918 = core__flat___NativeString___to_s_full(var2917, 5l, 5l);
var2916 = var2918;
varonce2915 = var2916;
}
{
var2919 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2916); /* == on <var_pname:String>*/
}
if (var2919){
if (unlikely(varonce2920==NULL)) {
var2921 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2922!=NULL)) {
var2923 = varonce2922;
} else {
var2924 = "(int8_t)";
var2925 = core__flat___NativeString___to_s_full(var2924, 8l, 8l);
var2923 = var2925;
varonce2922 = var2923;
}
((struct instance_core__NativeArray*)var2921)->values[0]=var2923;
} else {
var2921 = varonce2920;
varonce2920 = NULL;
}
{
var2926 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2927 = ((val*(*)(val* self))(var2926->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2926); /* to_s on <var2926:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2921)->values[1]=var2927;
{
var2928 = ((val*(*)(val* self))(var2921->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2921); /* native_to_s on <var2921:NativeArray[String]>*/
}
varonce2920 = var2921;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2773);
fatal_exit(1);
}
{
var2929 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2928, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2929); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2930!=NULL)) {
var2931 = varonce2930;
} else {
var2932 = "to_i16";
var2933 = core__flat___NativeString___to_s_full(var2932, 6l, 6l);
var2931 = var2933;
varonce2930 = var2931;
}
{
var2934 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2931); /* == on <var_pname:String>*/
}
if (var2934){
if (unlikely(varonce2935==NULL)) {
var2936 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2937!=NULL)) {
var2938 = varonce2937;
} else {
var2939 = "(int16_t)";
var2940 = core__flat___NativeString___to_s_full(var2939, 9l, 9l);
var2938 = var2940;
varonce2937 = var2938;
}
((struct instance_core__NativeArray*)var2936)->values[0]=var2938;
} else {
var2936 = varonce2935;
varonce2935 = NULL;
}
{
var2941 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2942 = ((val*(*)(val* self))(var2941->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2941); /* to_s on <var2941:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2936)->values[1]=var2942;
{
var2943 = ((val*(*)(val* self))(var2936->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2936); /* native_to_s on <var2936:NativeArray[String]>*/
}
varonce2935 = var2936;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2776);
fatal_exit(1);
}
{
var2944 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2943, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2944); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2945!=NULL)) {
var2946 = varonce2945;
} else {
var2947 = "to_i32";
var2948 = core__flat___NativeString___to_s_full(var2947, 6l, 6l);
var2946 = var2948;
varonce2945 = var2946;
}
{
var2949 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2946); /* == on <var_pname:String>*/
}
if (var2949){
if (unlikely(varonce2950==NULL)) {
var2951 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2952!=NULL)) {
var2953 = varonce2952;
} else {
var2954 = "(int32_t)";
var2955 = core__flat___NativeString___to_s_full(var2954, 9l, 9l);
var2953 = var2955;
varonce2952 = var2953;
}
((struct instance_core__NativeArray*)var2951)->values[0]=var2953;
} else {
var2951 = varonce2950;
varonce2950 = NULL;
}
{
var2956 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2957 = ((val*(*)(val* self))(var2956->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2956); /* to_s on <var2956:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2951)->values[1]=var2957;
{
var2958 = ((val*(*)(val* self))(var2951->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2951); /* native_to_s on <var2951:NativeArray[String]>*/
}
varonce2950 = var2951;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2779);
fatal_exit(1);
}
{
var2959 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2958, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2959); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2960!=NULL)) {
var2961 = varonce2960;
} else {
var2962 = "to_u32";
var2963 = core__flat___NativeString___to_s_full(var2962, 6l, 6l);
var2961 = var2963;
varonce2960 = var2961;
}
{
var2964 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2961); /* == on <var_pname:String>*/
}
if (var2964){
if (unlikely(varonce2965==NULL)) {
var2966 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2967!=NULL)) {
var2968 = varonce2967;
} else {
var2969 = "(uint32_t)";
var2970 = core__flat___NativeString___to_s_full(var2969, 10l, 10l);
var2968 = var2970;
varonce2967 = var2968;
}
((struct instance_core__NativeArray*)var2966)->values[0]=var2968;
} else {
var2966 = varonce2965;
varonce2965 = NULL;
}
{
var2971 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2972 = ((val*(*)(val* self))(var2971->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2971); /* to_s on <var2971:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2966)->values[1]=var2972;
{
var2973 = ((val*(*)(val* self))(var2966->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2966); /* native_to_s on <var2966:NativeArray[String]>*/
}
varonce2965 = var2966;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2782);
fatal_exit(1);
}
{
var2974 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2973, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2974); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2975!=NULL)) {
var2976 = varonce2975;
} else {
var2977 = "to_f";
var2978 = core__flat___NativeString___to_s_full(var2977, 4l, 4l);
var2976 = var2978;
varonce2975 = var2976;
}
{
var2979 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2976); /* == on <var_pname:String>*/
}
if (var2979){
if (unlikely(varonce2980==NULL)) {
var2981 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce2982!=NULL)) {
var2983 = varonce2982;
} else {
var2984 = "(double)";
var2985 = core__flat___NativeString___to_s_full(var2984, 8l, 8l);
var2983 = var2985;
varonce2982 = var2983;
}
((struct instance_core__NativeArray*)var2981)->values[0]=var2983;
} else {
var2981 = varonce2980;
varonce2980 = NULL;
}
{
var2986 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var2987 = ((val*(*)(val* self))(var2986->class->vft[COLOR_core__abstract_text__Object__to_s]))(var2986); /* to_s on <var2986:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2981)->values[1]=var2987;
{
var2988 = ((val*(*)(val* self))(var2981->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2981); /* native_to_s on <var2981:NativeArray[String]>*/
}
varonce2980 = var2981;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2785);
fatal_exit(1);
}
{
var2989 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var2988, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var2989); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce2990!=NULL)) {
var2991 = varonce2990;
} else {
var2992 = "&";
var2993 = core__flat___NativeString___to_s_full(var2992, 1l, 1l);
var2991 = var2993;
varonce2990 = var2991;
}
{
var2994 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var2991); /* == on <var_pname:String>*/
}
if (var2994){
if (unlikely(varonce2995==NULL)) {
var2996 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce2997!=NULL)) {
var2998 = varonce2997;
} else {
var2999 = " & ";
var3000 = core__flat___NativeString___to_s_full(var2999, 3l, 3l);
var2998 = var3000;
varonce2997 = var2998;
}
((struct instance_core__NativeArray*)var2996)->values[1]=var2998;
} else {
var2996 = varonce2995;
varonce2995 = NULL;
}
{
var3001 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3002 = ((val*(*)(val* self))(var3001->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3001); /* to_s on <var3001:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2996)->values[0]=var3002;
{
var3003 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3004 = ((val*(*)(val* self))(var3003->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3003); /* to_s on <var3003:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var2996)->values[2]=var3004;
{
var3005 = ((val*(*)(val* self))(var2996->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var2996); /* native_to_s on <var2996:NativeArray[String]>*/
}
varonce2995 = var2996;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2788);
fatal_exit(1);
}
{
var3006 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3005, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3006); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3007!=NULL)) {
var3008 = varonce3007;
} else {
var3009 = "|";
var3010 = core__flat___NativeString___to_s_full(var3009, 1l, 1l);
var3008 = var3010;
varonce3007 = var3008;
}
{
var3011 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3008); /* == on <var_pname:String>*/
}
if (var3011){
if (unlikely(varonce3012==NULL)) {
var3013 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3014!=NULL)) {
var3015 = varonce3014;
} else {
var3016 = " | ";
var3017 = core__flat___NativeString___to_s_full(var3016, 3l, 3l);
var3015 = var3017;
varonce3014 = var3015;
}
((struct instance_core__NativeArray*)var3013)->values[1]=var3015;
} else {
var3013 = varonce3012;
varonce3012 = NULL;
}
{
var3018 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3019 = ((val*(*)(val* self))(var3018->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3018); /* to_s on <var3018:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3013)->values[0]=var3019;
{
var3020 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3021 = ((val*(*)(val* self))(var3020->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3020); /* to_s on <var3020:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3013)->values[2]=var3021;
{
var3022 = ((val*(*)(val* self))(var3013->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3013); /* native_to_s on <var3013:NativeArray[String]>*/
}
varonce3012 = var3013;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2791);
fatal_exit(1);
}
{
var3023 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3022, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3023); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3024!=NULL)) {
var3025 = varonce3024;
} else {
var3026 = "^";
var3027 = core__flat___NativeString___to_s_full(var3026, 1l, 1l);
var3025 = var3027;
varonce3024 = var3025;
}
{
var3028 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3025); /* == on <var_pname:String>*/
}
if (var3028){
if (unlikely(varonce3029==NULL)) {
var3030 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3031!=NULL)) {
var3032 = varonce3031;
} else {
var3033 = " ^ ";
var3034 = core__flat___NativeString___to_s_full(var3033, 3l, 3l);
var3032 = var3034;
varonce3031 = var3032;
}
((struct instance_core__NativeArray*)var3030)->values[1]=var3032;
} else {
var3030 = varonce3029;
varonce3029 = NULL;
}
{
var3035 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3036 = ((val*(*)(val* self))(var3035->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3035); /* to_s on <var3035:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3030)->values[0]=var3036;
{
var3037 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3038 = ((val*(*)(val* self))(var3037->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3037); /* to_s on <var3037:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3030)->values[2]=var3038;
{
var3039 = ((val*(*)(val* self))(var3030->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3030); /* native_to_s on <var3030:NativeArray[String]>*/
}
varonce3029 = var3030;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2794);
fatal_exit(1);
}
{
var3040 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3039, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3040); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3041!=NULL)) {
var3042 = varonce3041;
} else {
var3043 = "unary ~";
var3044 = core__flat___NativeString___to_s_full(var3043, 7l, 7l);
var3042 = var3044;
varonce3041 = var3042;
}
{
var3045 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3042); /* == on <var_pname:String>*/
}
if (var3045){
if (unlikely(varonce3046==NULL)) {
var3047 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3048!=NULL)) {
var3049 = varonce3048;
} else {
var3050 = "~";
var3051 = core__flat___NativeString___to_s_full(var3050, 1l, 1l);
var3049 = var3051;
varonce3048 = var3049;
}
((struct instance_core__NativeArray*)var3047)->values[0]=var3049;
} else {
var3047 = varonce3046;
varonce3046 = NULL;
}
{
var3052 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3053 = ((val*(*)(val* self))(var3052->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3052); /* to_s on <var3052:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3047)->values[1]=var3053;
{
var3054 = ((val*(*)(val* self))(var3047->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3047); /* native_to_s on <var3047:NativeArray[String]>*/
}
varonce3046 = var3047;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2797);
fatal_exit(1);
}
{
var3055 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3054, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3055); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
} else {
if (likely(varonce3056!=NULL)) {
var3057 = varonce3056;
} else {
var3058 = "Int32";
var3059 = core__flat___NativeString___to_s_full(var3058, 5l, 5l);
var3057 = var3059;
varonce3056 = var3057;
}
{
var3060 = ((short int(*)(val* self, val* p0))(var_cname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_cname, var3057); /* == on <var_cname:String>*/
}
if (var3060){
if (likely(varonce3061!=NULL)) {
var3062 = varonce3061;
} else {
var3063 = "output";
var3064 = core__flat___NativeString___to_s_full(var3063, 6l, 6l);
var3062 = var3064;
varonce3061 = var3062;
}
{
var3065 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3062); /* == on <var_pname:String>*/
}
if (var3065){
if (unlikely(varonce3066==NULL)) {
var3067 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3068!=NULL)) {
var3069 = varonce3068;
} else {
var3070 = "printf(\"%\"PRIi32 \"\\n\", ";
var3071 = core__flat___NativeString___to_s_full(var3070, 23l, 23l);
var3069 = var3071;
varonce3068 = var3069;
}
((struct instance_core__NativeArray*)var3067)->values[0]=var3069;
if (likely(varonce3072!=NULL)) {
var3073 = varonce3072;
} else {
var3074 = ");";
var3075 = core__flat___NativeString___to_s_full(var3074, 2l, 2l);
var3073 = var3075;
varonce3072 = var3073;
}
((struct instance_core__NativeArray*)var3067)->values[2]=var3073;
} else {
var3067 = varonce3066;
varonce3066 = NULL;
}
{
var3076 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var3077 = ((val*(*)(val* self))(var3076->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3076); /* to_s on <var3076:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3067)->values[1]=var3077;
{
var3078 = ((val*(*)(val* self))(var3067->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3067); /* native_to_s on <var3067:NativeArray[String]>*/
}
varonce3066 = var3067;
{
nitc___nitc__AbstractCompilerVisitor___add(var_v, var3078); /* Direct call abstract_compiler#AbstractCompilerVisitor#add on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3079!=NULL)) {
var3080 = varonce3079;
} else {
var3081 = "object_id";
var3082 = core__flat___NativeString___to_s_full(var3081, 9l, 9l);
var3080 = var3082;
varonce3079 = var3080;
}
{
var3083 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3080); /* == on <var_pname:String>*/
}
if (var3083){
if (unlikely(varonce3084==NULL)) {
var3085 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3086!=NULL)) {
var3087 = varonce3086;
} else {
var3088 = "(long)";
var3089 = core__flat___NativeString___to_s_full(var3088, 6l, 6l);
var3087 = var3089;
varonce3086 = var3087;
}
((struct instance_core__NativeArray*)var3085)->values[0]=var3087;
} else {
var3085 = varonce3084;
varonce3084 = NULL;
}
{
var3090 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var3091 = ((val*(*)(val* self))(var3090->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3090); /* to_s on <var3090:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3085)->values[1]=var3091;
{
var3092 = ((val*(*)(val* self))(var3085->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3085); /* native_to_s on <var3085:NativeArray[String]>*/
}
varonce3084 = var3085;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2805);
fatal_exit(1);
}
{
var3093 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3092, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3093); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3094!=NULL)) {
var3095 = varonce3094;
} else {
var3096 = "+";
var3097 = core__flat___NativeString___to_s_full(var3096, 1l, 1l);
var3095 = var3097;
varonce3094 = var3095;
}
{
var3098 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3095); /* == on <var_pname:String>*/
}
if (var3098){
if (unlikely(varonce3099==NULL)) {
var3100 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3101!=NULL)) {
var3102 = varonce3101;
} else {
var3103 = " + ";
var3104 = core__flat___NativeString___to_s_full(var3103, 3l, 3l);
var3102 = var3104;
varonce3101 = var3102;
}
((struct instance_core__NativeArray*)var3100)->values[1]=var3102;
} else {
var3100 = varonce3099;
varonce3099 = NULL;
}
{
var3105 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3106 = ((val*(*)(val* self))(var3105->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3105); /* to_s on <var3105:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3100)->values[0]=var3106;
{
var3107 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3108 = ((val*(*)(val* self))(var3107->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3107); /* to_s on <var3107:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3100)->values[2]=var3108;
{
var3109 = ((val*(*)(val* self))(var3100->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3100); /* native_to_s on <var3100:NativeArray[String]>*/
}
varonce3099 = var3100;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2808);
fatal_exit(1);
}
{
var3110 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3109, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3110); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3111!=NULL)) {
var3112 = varonce3111;
} else {
var3113 = "-";
var3114 = core__flat___NativeString___to_s_full(var3113, 1l, 1l);
var3112 = var3114;
varonce3111 = var3112;
}
{
var3115 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3112); /* == on <var_pname:String>*/
}
if (var3115){
if (unlikely(varonce3116==NULL)) {
var3117 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3118!=NULL)) {
var3119 = varonce3118;
} else {
var3120 = " - ";
var3121 = core__flat___NativeString___to_s_full(var3120, 3l, 3l);
var3119 = var3121;
varonce3118 = var3119;
}
((struct instance_core__NativeArray*)var3117)->values[1]=var3119;
} else {
var3117 = varonce3116;
varonce3116 = NULL;
}
{
var3122 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3123 = ((val*(*)(val* self))(var3122->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3122); /* to_s on <var3122:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3117)->values[0]=var3123;
{
var3124 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3125 = ((val*(*)(val* self))(var3124->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3124); /* to_s on <var3124:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3117)->values[2]=var3125;
{
var3126 = ((val*(*)(val* self))(var3117->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3117); /* native_to_s on <var3117:NativeArray[String]>*/
}
varonce3116 = var3117;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2811);
fatal_exit(1);
}
{
var3127 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3126, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3127); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3128!=NULL)) {
var3129 = varonce3128;
} else {
var3130 = "unary -";
var3131 = core__flat___NativeString___to_s_full(var3130, 7l, 7l);
var3129 = var3131;
varonce3128 = var3129;
}
{
var3132 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3129); /* == on <var_pname:String>*/
}
if (var3132){
if (unlikely(varonce3133==NULL)) {
var3134 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3135!=NULL)) {
var3136 = varonce3135;
} else {
var3137 = "-";
var3138 = core__flat___NativeString___to_s_full(var3137, 1l, 1l);
var3136 = var3138;
varonce3135 = var3136;
}
((struct instance_core__NativeArray*)var3134)->values[0]=var3136;
} else {
var3134 = varonce3133;
varonce3133 = NULL;
}
{
var3139 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3140 = ((val*(*)(val* self))(var3139->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3139); /* to_s on <var3139:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3134)->values[1]=var3140;
{
var3141 = ((val*(*)(val* self))(var3134->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3134); /* native_to_s on <var3134:NativeArray[String]>*/
}
varonce3133 = var3134;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2814);
fatal_exit(1);
}
{
var3142 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3141, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3142); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3143!=NULL)) {
var3144 = varonce3143;
} else {
var3145 = "unary +";
var3146 = core__flat___NativeString___to_s_full(var3145, 7l, 7l);
var3144 = var3146;
varonce3143 = var3144;
}
{
var3147 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3144); /* == on <var_pname:String>*/
}
if (var3147){
{
var3148 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3148); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3149!=NULL)) {
var3150 = varonce3149;
} else {
var3151 = "*";
var3152 = core__flat___NativeString___to_s_full(var3151, 1l, 1l);
var3150 = var3152;
varonce3149 = var3150;
}
{
var3153 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3150); /* == on <var_pname:String>*/
}
if (var3153){
if (unlikely(varonce3154==NULL)) {
var3155 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3156!=NULL)) {
var3157 = varonce3156;
} else {
var3158 = " * ";
var3159 = core__flat___NativeString___to_s_full(var3158, 3l, 3l);
var3157 = var3159;
varonce3156 = var3157;
}
((struct instance_core__NativeArray*)var3155)->values[1]=var3157;
} else {
var3155 = varonce3154;
varonce3154 = NULL;
}
{
var3160 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3161 = ((val*(*)(val* self))(var3160->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3160); /* to_s on <var3160:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3155)->values[0]=var3161;
{
var3162 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3163 = ((val*(*)(val* self))(var3162->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3162); /* to_s on <var3162:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3155)->values[2]=var3163;
{
var3164 = ((val*(*)(val* self))(var3155->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3155); /* native_to_s on <var3155:NativeArray[String]>*/
}
varonce3154 = var3155;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2820);
fatal_exit(1);
}
{
var3165 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3164, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3165); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3166!=NULL)) {
var3167 = varonce3166;
} else {
var3168 = "/";
var3169 = core__flat___NativeString___to_s_full(var3168, 1l, 1l);
var3167 = var3169;
varonce3166 = var3167;
}
{
var3170 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3167); /* == on <var_pname:String>*/
}
if (var3170){
if (unlikely(varonce3171==NULL)) {
var3172 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3173!=NULL)) {
var3174 = varonce3173;
} else {
var3175 = " / ";
var3176 = core__flat___NativeString___to_s_full(var3175, 3l, 3l);
var3174 = var3176;
varonce3173 = var3174;
}
((struct instance_core__NativeArray*)var3172)->values[1]=var3174;
} else {
var3172 = varonce3171;
varonce3171 = NULL;
}
{
var3177 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3178 = ((val*(*)(val* self))(var3177->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3177); /* to_s on <var3177:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3172)->values[0]=var3178;
{
var3179 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3180 = ((val*(*)(val* self))(var3179->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3179); /* to_s on <var3179:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3172)->values[2]=var3180;
{
var3181 = ((val*(*)(val* self))(var3172->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3172); /* native_to_s on <var3172:NativeArray[String]>*/
}
varonce3171 = var3172;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2823);
fatal_exit(1);
}
{
var3182 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3181, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3182); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3183!=NULL)) {
var3184 = varonce3183;
} else {
var3185 = "%";
var3186 = core__flat___NativeString___to_s_full(var3185, 1l, 1l);
var3184 = var3186;
varonce3183 = var3184;
}
{
var3187 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3184); /* == on <var_pname:String>*/
}
if (var3187){
if (unlikely(varonce3188==NULL)) {
var3189 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3190!=NULL)) {
var3191 = varonce3190;
} else {
var3192 = " % ";
var3193 = core__flat___NativeString___to_s_full(var3192, 3l, 3l);
var3191 = var3193;
varonce3190 = var3191;
}
((struct instance_core__NativeArray*)var3189)->values[1]=var3191;
} else {
var3189 = varonce3188;
varonce3188 = NULL;
}
{
var3194 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3195 = ((val*(*)(val* self))(var3194->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3194); /* to_s on <var3194:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3189)->values[0]=var3195;
{
var3196 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3197 = ((val*(*)(val* self))(var3196->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3196); /* to_s on <var3196:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3189)->values[2]=var3197;
{
var3198 = ((val*(*)(val* self))(var3189->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3189); /* native_to_s on <var3189:NativeArray[String]>*/
}
varonce3188 = var3189;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2826);
fatal_exit(1);
}
{
var3199 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3198, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3199); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3200!=NULL)) {
var3201 = varonce3200;
} else {
var3202 = "<<";
var3203 = core__flat___NativeString___to_s_full(var3202, 2l, 2l);
var3201 = var3203;
varonce3200 = var3201;
}
{
var3204 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3201); /* == on <var_pname:String>*/
}
if (var3204){
if (unlikely(varonce3205==NULL)) {
var3206 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3207!=NULL)) {
var3208 = varonce3207;
} else {
var3209 = " << ";
var3210 = core__flat___NativeString___to_s_full(var3209, 4l, 4l);
var3208 = var3210;
varonce3207 = var3208;
}
((struct instance_core__NativeArray*)var3206)->values[1]=var3208;
} else {
var3206 = varonce3205;
varonce3205 = NULL;
}
{
var3211 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3212 = ((val*(*)(val* self))(var3211->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3211); /* to_s on <var3211:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3206)->values[0]=var3212;
{
var3213 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3214 = ((val*(*)(val* self))(var3213->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3213); /* to_s on <var3213:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3206)->values[2]=var3214;
{
var3215 = ((val*(*)(val* self))(var3206->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3206); /* native_to_s on <var3206:NativeArray[String]>*/
}
varonce3205 = var3206;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2829);
fatal_exit(1);
}
{
var3216 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3215, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3216); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3217!=NULL)) {
var3218 = varonce3217;
} else {
var3219 = ">>";
var3220 = core__flat___NativeString___to_s_full(var3219, 2l, 2l);
var3218 = var3220;
varonce3217 = var3218;
}
{
var3221 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3218); /* == on <var_pname:String>*/
}
if (var3221){
if (unlikely(varonce3222==NULL)) {
var3223 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3224!=NULL)) {
var3225 = varonce3224;
} else {
var3226 = " >> ";
var3227 = core__flat___NativeString___to_s_full(var3226, 4l, 4l);
var3225 = var3227;
varonce3224 = var3225;
}
((struct instance_core__NativeArray*)var3223)->values[1]=var3225;
} else {
var3223 = varonce3222;
varonce3222 = NULL;
}
{
var3228 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3229 = ((val*(*)(val* self))(var3228->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3228); /* to_s on <var3228:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3223)->values[0]=var3229;
{
var3230 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3231 = ((val*(*)(val* self))(var3230->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3230); /* to_s on <var3230:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3223)->values[2]=var3231;
{
var3232 = ((val*(*)(val* self))(var3223->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3223); /* native_to_s on <var3223:NativeArray[String]>*/
}
varonce3222 = var3223;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2832);
fatal_exit(1);
}
{
var3233 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3232, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3233); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3234!=NULL)) {
var3235 = varonce3234;
} else {
var3236 = "==";
var3237 = core__flat___NativeString___to_s_full(var3236, 2l, 2l);
var3235 = var3237;
varonce3234 = var3235;
}
{
var3238 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3235); /* == on <var_pname:String>*/
}
if (var3238){
{
var3239 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3240 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3241 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var3239, var3240);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3241); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3242!=NULL)) {
var3243 = varonce3242;
} else {
var3244 = "!=";
var3245 = core__flat___NativeString___to_s_full(var3244, 2l, 2l);
var3243 = var3245;
varonce3242 = var3243;
}
{
var3246 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3243); /* == on <var_pname:String>*/
}
if (var3246){
{
var3247 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3248 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3249 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var3247, var3248);
}
var_res3250 = var3249;
if (unlikely(varonce3251==NULL)) {
var3252 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3253!=NULL)) {
var3254 = varonce3253;
} else {
var3255 = "!";
var3256 = core__flat___NativeString___to_s_full(var3255, 1l, 1l);
var3254 = var3256;
varonce3253 = var3254;
}
((struct instance_core__NativeArray*)var3252)->values[0]=var3254;
} else {
var3252 = varonce3251;
varonce3251 = NULL;
}
{
var3257 = ((val*(*)(val* self))(var_res3250->class->vft[COLOR_core__abstract_text__Object__to_s]))(var_res3250); /* to_s on <var_res3250:RuntimeVariable>*/
}
((struct instance_core__NativeArray*)var3252)->values[1]=var3257;
{
var3258 = ((val*(*)(val* self))(var3252->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3252); /* native_to_s on <var3252:NativeArray[String]>*/
}
varonce3251 = var3252;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2839);
fatal_exit(1);
}
{
var3259 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3258, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3259); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3260!=NULL)) {
var3261 = varonce3260;
} else {
var3262 = "<";
var3263 = core__flat___NativeString___to_s_full(var3262, 1l, 1l);
var3261 = var3263;
varonce3260 = var3261;
}
{
var3264 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3261); /* == on <var_pname:String>*/
}
if (var3264){
if (unlikely(varonce3265==NULL)) {
var3266 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3267!=NULL)) {
var3268 = varonce3267;
} else {
var3269 = " < ";
var3270 = core__flat___NativeString___to_s_full(var3269, 3l, 3l);
var3268 = var3270;
varonce3267 = var3268;
}
((struct instance_core__NativeArray*)var3266)->values[1]=var3268;
} else {
var3266 = varonce3265;
varonce3265 = NULL;
}
{
var3271 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3272 = ((val*(*)(val* self))(var3271->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3271); /* to_s on <var3271:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3266)->values[0]=var3272;
{
var3273 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3274 = ((val*(*)(val* self))(var3273->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3273); /* to_s on <var3273:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3266)->values[2]=var3274;
{
var3275 = ((val*(*)(val* self))(var3266->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3266); /* native_to_s on <var3266:NativeArray[String]>*/
}
varonce3265 = var3266;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2842);
fatal_exit(1);
}
{
var3276 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3275, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3276); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3277!=NULL)) {
var3278 = varonce3277;
} else {
var3279 = ">";
var3280 = core__flat___NativeString___to_s_full(var3279, 1l, 1l);
var3278 = var3280;
varonce3277 = var3278;
}
{
var3281 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3278); /* == on <var_pname:String>*/
}
if (var3281){
if (unlikely(varonce3282==NULL)) {
var3283 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3284!=NULL)) {
var3285 = varonce3284;
} else {
var3286 = " > ";
var3287 = core__flat___NativeString___to_s_full(var3286, 3l, 3l);
var3285 = var3287;
varonce3284 = var3285;
}
((struct instance_core__NativeArray*)var3283)->values[1]=var3285;
} else {
var3283 = varonce3282;
varonce3282 = NULL;
}
{
var3288 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3289 = ((val*(*)(val* self))(var3288->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3288); /* to_s on <var3288:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3283)->values[0]=var3289;
{
var3290 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3291 = ((val*(*)(val* self))(var3290->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3290); /* to_s on <var3290:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3283)->values[2]=var3291;
{
var3292 = ((val*(*)(val* self))(var3283->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3283); /* native_to_s on <var3283:NativeArray[String]>*/
}
varonce3282 = var3283;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2845);
fatal_exit(1);
}
{
var3293 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3292, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3293); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3294!=NULL)) {
var3295 = varonce3294;
} else {
var3296 = "<=";
var3297 = core__flat___NativeString___to_s_full(var3296, 2l, 2l);
var3295 = var3297;
varonce3294 = var3295;
}
{
var3298 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3295); /* == on <var_pname:String>*/
}
if (var3298){
if (unlikely(varonce3299==NULL)) {
var3300 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3301!=NULL)) {
var3302 = varonce3301;
} else {
var3303 = " <= ";
var3304 = core__flat___NativeString___to_s_full(var3303, 4l, 4l);
var3302 = var3304;
varonce3301 = var3302;
}
((struct instance_core__NativeArray*)var3300)->values[1]=var3302;
} else {
var3300 = varonce3299;
varonce3299 = NULL;
}
{
var3305 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3306 = ((val*(*)(val* self))(var3305->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3305); /* to_s on <var3305:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3300)->values[0]=var3306;
{
var3307 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3308 = ((val*(*)(val* self))(var3307->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3307); /* to_s on <var3307:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3300)->values[2]=var3308;
{
var3309 = ((val*(*)(val* self))(var3300->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3300); /* native_to_s on <var3300:NativeArray[String]>*/
}
varonce3299 = var3300;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2848);
fatal_exit(1);
}
{
var3310 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3309, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3310); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3311!=NULL)) {
var3312 = varonce3311;
} else {
var3313 = ">=";
var3314 = core__flat___NativeString___to_s_full(var3313, 2l, 2l);
var3312 = var3314;
varonce3311 = var3312;
}
{
var3315 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3312); /* == on <var_pname:String>*/
}
if (var3315){
if (unlikely(varonce3316==NULL)) {
var3317 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3318!=NULL)) {
var3319 = varonce3318;
} else {
var3320 = " >= ";
var3321 = core__flat___NativeString___to_s_full(var3320, 4l, 4l);
var3319 = var3321;
varonce3318 = var3319;
}
((struct instance_core__NativeArray*)var3317)->values[1]=var3319;
} else {
var3317 = varonce3316;
varonce3316 = NULL;
}
{
var3322 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3323 = ((val*(*)(val* self))(var3322->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3322); /* to_s on <var3322:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3317)->values[0]=var3323;
{
var3324 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3325 = ((val*(*)(val* self))(var3324->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3324); /* to_s on <var3324:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3317)->values[2]=var3325;
{
var3326 = ((val*(*)(val* self))(var3317->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3317); /* native_to_s on <var3317:NativeArray[String]>*/
}
varonce3316 = var3317;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2851);
fatal_exit(1);
}
{
var3327 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3326, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3327); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3328!=NULL)) {
var3329 = varonce3328;
} else {
var3330 = "to_i";
var3331 = core__flat___NativeString___to_s_full(var3330, 4l, 4l);
var3329 = var3331;
varonce3328 = var3329;
}
{
var3332 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3329); /* == on <var_pname:String>*/
}
if (var3332){
if (unlikely(varonce3333==NULL)) {
var3334 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3335!=NULL)) {
var3336 = varonce3335;
} else {
var3337 = "(long)";
var3338 = core__flat___NativeString___to_s_full(var3337, 6l, 6l);
var3336 = var3338;
varonce3335 = var3336;
}
((struct instance_core__NativeArray*)var3334)->values[0]=var3336;
} else {
var3334 = varonce3333;
varonce3333 = NULL;
}
{
var3339 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3340 = ((val*(*)(val* self))(var3339->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3339); /* to_s on <var3339:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3334)->values[1]=var3340;
{
var3341 = ((val*(*)(val* self))(var3334->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3334); /* native_to_s on <var3334:NativeArray[String]>*/
}
varonce3333 = var3334;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2854);
fatal_exit(1);
}
{
var3342 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3341, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3342); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3343!=NULL)) {
var3344 = varonce3343;
} else {
var3345 = "to_b";
var3346 = core__flat___NativeString___to_s_full(var3345, 4l, 4l);
var3344 = var3346;
varonce3343 = var3344;
}
{
var3347 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3344); /* == on <var_pname:String>*/
}
if (var3347){
if (unlikely(varonce3348==NULL)) {
var3349 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3350!=NULL)) {
var3351 = varonce3350;
} else {
var3352 = "(unsigned char)";
var3353 = core__flat___NativeString___to_s_full(var3352, 15l, 15l);
var3351 = var3353;
varonce3350 = var3351;
}
((struct instance_core__NativeArray*)var3349)->values[0]=var3351;
} else {
var3349 = varonce3348;
varonce3348 = NULL;
}
{
var3354 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3355 = ((val*(*)(val* self))(var3354->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3354); /* to_s on <var3354:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3349)->values[1]=var3355;
{
var3356 = ((val*(*)(val* self))(var3349->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3349); /* native_to_s on <var3349:NativeArray[String]>*/
}
varonce3348 = var3349;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2857);
fatal_exit(1);
}
{
var3357 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3356, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3357); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3358!=NULL)) {
var3359 = varonce3358;
} else {
var3360 = "to_i8";
var3361 = core__flat___NativeString___to_s_full(var3360, 5l, 5l);
var3359 = var3361;
varonce3358 = var3359;
}
{
var3362 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3359); /* == on <var_pname:String>*/
}
if (var3362){
if (unlikely(varonce3363==NULL)) {
var3364 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3365!=NULL)) {
var3366 = varonce3365;
} else {
var3367 = "(int8_t)";
var3368 = core__flat___NativeString___to_s_full(var3367, 8l, 8l);
var3366 = var3368;
varonce3365 = var3366;
}
((struct instance_core__NativeArray*)var3364)->values[0]=var3366;
} else {
var3364 = varonce3363;
varonce3363 = NULL;
}
{
var3369 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3370 = ((val*(*)(val* self))(var3369->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3369); /* to_s on <var3369:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3364)->values[1]=var3370;
{
var3371 = ((val*(*)(val* self))(var3364->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3364); /* native_to_s on <var3364:NativeArray[String]>*/
}
varonce3363 = var3364;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2860);
fatal_exit(1);
}
{
var3372 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3371, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3372); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3373!=NULL)) {
var3374 = varonce3373;
} else {
var3375 = "to_i16";
var3376 = core__flat___NativeString___to_s_full(var3375, 6l, 6l);
var3374 = var3376;
varonce3373 = var3374;
}
{
var3377 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3374); /* == on <var_pname:String>*/
}
if (var3377){
if (unlikely(varonce3378==NULL)) {
var3379 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3380!=NULL)) {
var3381 = varonce3380;
} else {
var3382 = "(int16_t)";
var3383 = core__flat___NativeString___to_s_full(var3382, 9l, 9l);
var3381 = var3383;
varonce3380 = var3381;
}
((struct instance_core__NativeArray*)var3379)->values[0]=var3381;
} else {
var3379 = varonce3378;
varonce3378 = NULL;
}
{
var3384 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3385 = ((val*(*)(val* self))(var3384->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3384); /* to_s on <var3384:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3379)->values[1]=var3385;
{
var3386 = ((val*(*)(val* self))(var3379->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3379); /* native_to_s on <var3379:NativeArray[String]>*/
}
varonce3378 = var3379;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2863);
fatal_exit(1);
}
{
var3387 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3386, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3387); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3388!=NULL)) {
var3389 = varonce3388;
} else {
var3390 = "to_u16";
var3391 = core__flat___NativeString___to_s_full(var3390, 6l, 6l);
var3389 = var3391;
varonce3388 = var3389;
}
{
var3392 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3389); /* == on <var_pname:String>*/
}
if (var3392){
if (unlikely(varonce3393==NULL)) {
var3394 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3395!=NULL)) {
var3396 = varonce3395;
} else {
var3397 = "(uint16_t)";
var3398 = core__flat___NativeString___to_s_full(var3397, 10l, 10l);
var3396 = var3398;
varonce3395 = var3396;
}
((struct instance_core__NativeArray*)var3394)->values[0]=var3396;
} else {
var3394 = varonce3393;
varonce3393 = NULL;
}
{
var3399 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3400 = ((val*(*)(val* self))(var3399->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3399); /* to_s on <var3399:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3394)->values[1]=var3400;
{
var3401 = ((val*(*)(val* self))(var3394->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3394); /* native_to_s on <var3394:NativeArray[String]>*/
}
varonce3393 = var3394;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2866);
fatal_exit(1);
}
{
var3402 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3401, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3402); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3403!=NULL)) {
var3404 = varonce3403;
} else {
var3405 = "to_u32";
var3406 = core__flat___NativeString___to_s_full(var3405, 6l, 6l);
var3404 = var3406;
varonce3403 = var3404;
}
{
var3407 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3404); /* == on <var_pname:String>*/
}
if (var3407){
if (unlikely(varonce3408==NULL)) {
var3409 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3410!=NULL)) {
var3411 = varonce3410;
} else {
var3412 = "(uint32_t)";
var3413 = core__flat___NativeString___to_s_full(var3412, 10l, 10l);
var3411 = var3413;
varonce3410 = var3411;
}
((struct instance_core__NativeArray*)var3409)->values[0]=var3411;
} else {
var3409 = varonce3408;
varonce3408 = NULL;
}
{
var3414 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3415 = ((val*(*)(val* self))(var3414->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3414); /* to_s on <var3414:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3409)->values[1]=var3415;
{
var3416 = ((val*(*)(val* self))(var3409->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3409); /* native_to_s on <var3409:NativeArray[String]>*/
}
varonce3408 = var3409;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2869);
fatal_exit(1);
}
{
var3417 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3416, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3417); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3418!=NULL)) {
var3419 = varonce3418;
} else {
var3420 = "to_f";
var3421 = core__flat___NativeString___to_s_full(var3420, 4l, 4l);
var3419 = var3421;
varonce3418 = var3419;
}
{
var3422 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3419); /* == on <var_pname:String>*/
}
if (var3422){
if (unlikely(varonce3423==NULL)) {
var3424 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3425!=NULL)) {
var3426 = varonce3425;
} else {
var3427 = "(double)";
var3428 = core__flat___NativeString___to_s_full(var3427, 8l, 8l);
var3426 = var3428;
varonce3425 = var3426;
}
((struct instance_core__NativeArray*)var3424)->values[0]=var3426;
} else {
var3424 = varonce3423;
varonce3423 = NULL;
}
{
var3429 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3430 = ((val*(*)(val* self))(var3429->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3429); /* to_s on <var3429:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3424)->values[1]=var3430;
{
var3431 = ((val*(*)(val* self))(var3424->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3424); /* native_to_s on <var3424:NativeArray[String]>*/
}
varonce3423 = var3424;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2872);
fatal_exit(1);
}
{
var3432 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3431, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3432); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3433!=NULL)) {
var3434 = varonce3433;
} else {
var3435 = "&";
var3436 = core__flat___NativeString___to_s_full(var3435, 1l, 1l);
var3434 = var3436;
varonce3433 = var3434;
}
{
var3437 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3434); /* == on <var_pname:String>*/
}
if (var3437){
if (unlikely(varonce3438==NULL)) {
var3439 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3440!=NULL)) {
var3441 = varonce3440;
} else {
var3442 = " & ";
var3443 = core__flat___NativeString___to_s_full(var3442, 3l, 3l);
var3441 = var3443;
varonce3440 = var3441;
}
((struct instance_core__NativeArray*)var3439)->values[1]=var3441;
} else {
var3439 = varonce3438;
varonce3438 = NULL;
}
{
var3444 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3445 = ((val*(*)(val* self))(var3444->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3444); /* to_s on <var3444:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3439)->values[0]=var3445;
{
var3446 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3447 = ((val*(*)(val* self))(var3446->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3446); /* to_s on <var3446:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3439)->values[2]=var3447;
{
var3448 = ((val*(*)(val* self))(var3439->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3439); /* native_to_s on <var3439:NativeArray[String]>*/
}
varonce3438 = var3439;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2875);
fatal_exit(1);
}
{
var3449 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3448, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3449); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3450!=NULL)) {
var3451 = varonce3450;
} else {
var3452 = "|";
var3453 = core__flat___NativeString___to_s_full(var3452, 1l, 1l);
var3451 = var3453;
varonce3450 = var3451;
}
{
var3454 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3451); /* == on <var_pname:String>*/
}
if (var3454){
if (unlikely(varonce3455==NULL)) {
var3456 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3457!=NULL)) {
var3458 = varonce3457;
} else {
var3459 = " | ";
var3460 = core__flat___NativeString___to_s_full(var3459, 3l, 3l);
var3458 = var3460;
varonce3457 = var3458;
}
((struct instance_core__NativeArray*)var3456)->values[1]=var3458;
} else {
var3456 = varonce3455;
varonce3455 = NULL;
}
{
var3461 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3462 = ((val*(*)(val* self))(var3461->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3461); /* to_s on <var3461:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3456)->values[0]=var3462;
{
var3463 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3464 = ((val*(*)(val* self))(var3463->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3463); /* to_s on <var3463:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3456)->values[2]=var3464;
{
var3465 = ((val*(*)(val* self))(var3456->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3456); /* native_to_s on <var3456:NativeArray[String]>*/
}
varonce3455 = var3456;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2878);
fatal_exit(1);
}
{
var3466 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3465, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3466); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3467!=NULL)) {
var3468 = varonce3467;
} else {
var3469 = "^";
var3470 = core__flat___NativeString___to_s_full(var3469, 1l, 1l);
var3468 = var3470;
varonce3467 = var3468;
}
{
var3471 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3468); /* == on <var_pname:String>*/
}
if (var3471){
if (unlikely(varonce3472==NULL)) {
var3473 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3474!=NULL)) {
var3475 = varonce3474;
} else {
var3476 = " ^ ";
var3477 = core__flat___NativeString___to_s_full(var3476, 3l, 3l);
var3475 = var3477;
varonce3474 = var3475;
}
((struct instance_core__NativeArray*)var3473)->values[1]=var3475;
} else {
var3473 = varonce3472;
varonce3472 = NULL;
}
{
var3478 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3479 = ((val*(*)(val* self))(var3478->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3478); /* to_s on <var3478:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3473)->values[0]=var3479;
{
var3480 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3481 = ((val*(*)(val* self))(var3480->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3480); /* to_s on <var3480:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3473)->values[2]=var3481;
{
var3482 = ((val*(*)(val* self))(var3473->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3473); /* native_to_s on <var3473:NativeArray[String]>*/
}
varonce3472 = var3473;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2881);
fatal_exit(1);
}
{
var3483 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3482, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3483); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3484!=NULL)) {
var3485 = varonce3484;
} else {
var3486 = "unary ~";
var3487 = core__flat___NativeString___to_s_full(var3486, 7l, 7l);
var3485 = var3487;
varonce3484 = var3485;
}
{
var3488 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3485); /* == on <var_pname:String>*/
}
if (var3488){
if (unlikely(varonce3489==NULL)) {
var3490 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3491!=NULL)) {
var3492 = varonce3491;
} else {
var3493 = "~";
var3494 = core__flat___NativeString___to_s_full(var3493, 1l, 1l);
var3492 = var3494;
varonce3491 = var3492;
}
((struct instance_core__NativeArray*)var3490)->values[0]=var3492;
} else {
var3490 = varonce3489;
varonce3489 = NULL;
}
{
var3495 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3496 = ((val*(*)(val* self))(var3495->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3495); /* to_s on <var3495:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3490)->values[1]=var3496;
{
var3497 = ((val*(*)(val* self))(var3490->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3490); /* native_to_s on <var3490:NativeArray[String]>*/
}
varonce3489 = var3490;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2884);
fatal_exit(1);
}
{
var3498 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3497, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3498); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
} else {
if (likely(varonce3499!=NULL)) {
var3500 = varonce3499;
} else {
var3501 = "UInt32";
var3502 = core__flat___NativeString___to_s_full(var3501, 6l, 6l);
var3500 = var3502;
varonce3499 = var3500;
}
{
var3503 = ((short int(*)(val* self, val* p0))(var_cname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_cname, var3500); /* == on <var_cname:String>*/
}
if (var3503){
if (likely(varonce3504!=NULL)) {
var3505 = varonce3504;
} else {
var3506 = "output";
var3507 = core__flat___NativeString___to_s_full(var3506, 6l, 6l);
var3505 = var3507;
varonce3504 = var3505;
}
{
var3508 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3505); /* == on <var_pname:String>*/
}
if (var3508){
if (unlikely(varonce3509==NULL)) {
var3510 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3511!=NULL)) {
var3512 = varonce3511;
} else {
var3513 = "printf(\"%\"PRIu32 \"\\n\", ";
var3514 = core__flat___NativeString___to_s_full(var3513, 23l, 23l);
var3512 = var3514;
varonce3511 = var3512;
}
((struct instance_core__NativeArray*)var3510)->values[0]=var3512;
if (likely(varonce3515!=NULL)) {
var3516 = varonce3515;
} else {
var3517 = ");";
var3518 = core__flat___NativeString___to_s_full(var3517, 2l, 2l);
var3516 = var3518;
varonce3515 = var3516;
}
((struct instance_core__NativeArray*)var3510)->values[2]=var3516;
} else {
var3510 = varonce3509;
varonce3509 = NULL;
}
{
var3519 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var3520 = ((val*(*)(val* self))(var3519->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3519); /* to_s on <var3519:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3510)->values[1]=var3520;
{
var3521 = ((val*(*)(val* self))(var3510->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3510); /* native_to_s on <var3510:NativeArray[String]>*/
}
varonce3509 = var3510;
{
nitc___nitc__AbstractCompilerVisitor___add(var_v, var3521); /* Direct call abstract_compiler#AbstractCompilerVisitor#add on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3522!=NULL)) {
var3523 = varonce3522;
} else {
var3524 = "object_id";
var3525 = core__flat___NativeString___to_s_full(var3524, 9l, 9l);
var3523 = var3525;
varonce3522 = var3523;
}
{
var3526 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3523); /* == on <var_pname:String>*/
}
if (var3526){
if (unlikely(varonce3527==NULL)) {
var3528 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3529!=NULL)) {
var3530 = varonce3529;
} else {
var3531 = "(long)";
var3532 = core__flat___NativeString___to_s_full(var3531, 6l, 6l);
var3530 = var3532;
varonce3529 = var3530;
}
((struct instance_core__NativeArray*)var3528)->values[0]=var3530;
} else {
var3528 = varonce3527;
varonce3527 = NULL;
}
{
var3533 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var3534 = ((val*(*)(val* self))(var3533->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3533); /* to_s on <var3533:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3528)->values[1]=var3534;
{
var3535 = ((val*(*)(val* self))(var3528->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3528); /* native_to_s on <var3528:NativeArray[String]>*/
}
varonce3527 = var3528;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2892);
fatal_exit(1);
}
{
var3536 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3535, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3536); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3537!=NULL)) {
var3538 = varonce3537;
} else {
var3539 = "+";
var3540 = core__flat___NativeString___to_s_full(var3539, 1l, 1l);
var3538 = var3540;
varonce3537 = var3538;
}
{
var3541 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3538); /* == on <var_pname:String>*/
}
if (var3541){
if (unlikely(varonce3542==NULL)) {
var3543 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3544!=NULL)) {
var3545 = varonce3544;
} else {
var3546 = " + ";
var3547 = core__flat___NativeString___to_s_full(var3546, 3l, 3l);
var3545 = var3547;
varonce3544 = var3545;
}
((struct instance_core__NativeArray*)var3543)->values[1]=var3545;
} else {
var3543 = varonce3542;
varonce3542 = NULL;
}
{
var3548 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3549 = ((val*(*)(val* self))(var3548->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3548); /* to_s on <var3548:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3543)->values[0]=var3549;
{
var3550 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3551 = ((val*(*)(val* self))(var3550->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3550); /* to_s on <var3550:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3543)->values[2]=var3551;
{
var3552 = ((val*(*)(val* self))(var3543->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3543); /* native_to_s on <var3543:NativeArray[String]>*/
}
varonce3542 = var3543;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2895);
fatal_exit(1);
}
{
var3553 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3552, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3553); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3554!=NULL)) {
var3555 = varonce3554;
} else {
var3556 = "-";
var3557 = core__flat___NativeString___to_s_full(var3556, 1l, 1l);
var3555 = var3557;
varonce3554 = var3555;
}
{
var3558 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3555); /* == on <var_pname:String>*/
}
if (var3558){
if (unlikely(varonce3559==NULL)) {
var3560 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3561!=NULL)) {
var3562 = varonce3561;
} else {
var3563 = " - ";
var3564 = core__flat___NativeString___to_s_full(var3563, 3l, 3l);
var3562 = var3564;
varonce3561 = var3562;
}
((struct instance_core__NativeArray*)var3560)->values[1]=var3562;
} else {
var3560 = varonce3559;
varonce3559 = NULL;
}
{
var3565 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3566 = ((val*(*)(val* self))(var3565->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3565); /* to_s on <var3565:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3560)->values[0]=var3566;
{
var3567 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3568 = ((val*(*)(val* self))(var3567->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3567); /* to_s on <var3567:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3560)->values[2]=var3568;
{
var3569 = ((val*(*)(val* self))(var3560->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3560); /* native_to_s on <var3560:NativeArray[String]>*/
}
varonce3559 = var3560;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2898);
fatal_exit(1);
}
{
var3570 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3569, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3570); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3571!=NULL)) {
var3572 = varonce3571;
} else {
var3573 = "unary -";
var3574 = core__flat___NativeString___to_s_full(var3573, 7l, 7l);
var3572 = var3574;
varonce3571 = var3572;
}
{
var3575 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3572); /* == on <var_pname:String>*/
}
if (var3575){
if (unlikely(varonce3576==NULL)) {
var3577 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3578!=NULL)) {
var3579 = varonce3578;
} else {
var3580 = "-";
var3581 = core__flat___NativeString___to_s_full(var3580, 1l, 1l);
var3579 = var3581;
varonce3578 = var3579;
}
((struct instance_core__NativeArray*)var3577)->values[0]=var3579;
} else {
var3577 = varonce3576;
varonce3576 = NULL;
}
{
var3582 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3583 = ((val*(*)(val* self))(var3582->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3582); /* to_s on <var3582:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3577)->values[1]=var3583;
{
var3584 = ((val*(*)(val* self))(var3577->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3577); /* native_to_s on <var3577:NativeArray[String]>*/
}
varonce3576 = var3577;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2901);
fatal_exit(1);
}
{
var3585 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3584, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3585); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3586!=NULL)) {
var3587 = varonce3586;
} else {
var3588 = "unary +";
var3589 = core__flat___NativeString___to_s_full(var3588, 7l, 7l);
var3587 = var3589;
varonce3586 = var3587;
}
{
var3590 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3587); /* == on <var_pname:String>*/
}
if (var3590){
{
var3591 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3591); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3592!=NULL)) {
var3593 = varonce3592;
} else {
var3594 = "*";
var3595 = core__flat___NativeString___to_s_full(var3594, 1l, 1l);
var3593 = var3595;
varonce3592 = var3593;
}
{
var3596 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3593); /* == on <var_pname:String>*/
}
if (var3596){
if (unlikely(varonce3597==NULL)) {
var3598 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3599!=NULL)) {
var3600 = varonce3599;
} else {
var3601 = " * ";
var3602 = core__flat___NativeString___to_s_full(var3601, 3l, 3l);
var3600 = var3602;
varonce3599 = var3600;
}
((struct instance_core__NativeArray*)var3598)->values[1]=var3600;
} else {
var3598 = varonce3597;
varonce3597 = NULL;
}
{
var3603 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3604 = ((val*(*)(val* self))(var3603->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3603); /* to_s on <var3603:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3598)->values[0]=var3604;
{
var3605 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3606 = ((val*(*)(val* self))(var3605->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3605); /* to_s on <var3605:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3598)->values[2]=var3606;
{
var3607 = ((val*(*)(val* self))(var3598->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3598); /* native_to_s on <var3598:NativeArray[String]>*/
}
varonce3597 = var3598;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2907);
fatal_exit(1);
}
{
var3608 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3607, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3608); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3609!=NULL)) {
var3610 = varonce3609;
} else {
var3611 = "/";
var3612 = core__flat___NativeString___to_s_full(var3611, 1l, 1l);
var3610 = var3612;
varonce3609 = var3610;
}
{
var3613 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3610); /* == on <var_pname:String>*/
}
if (var3613){
if (unlikely(varonce3614==NULL)) {
var3615 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3616!=NULL)) {
var3617 = varonce3616;
} else {
var3618 = " / ";
var3619 = core__flat___NativeString___to_s_full(var3618, 3l, 3l);
var3617 = var3619;
varonce3616 = var3617;
}
((struct instance_core__NativeArray*)var3615)->values[1]=var3617;
} else {
var3615 = varonce3614;
varonce3614 = NULL;
}
{
var3620 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3621 = ((val*(*)(val* self))(var3620->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3620); /* to_s on <var3620:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3615)->values[0]=var3621;
{
var3622 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3623 = ((val*(*)(val* self))(var3622->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3622); /* to_s on <var3622:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3615)->values[2]=var3623;
{
var3624 = ((val*(*)(val* self))(var3615->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3615); /* native_to_s on <var3615:NativeArray[String]>*/
}
varonce3614 = var3615;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2910);
fatal_exit(1);
}
{
var3625 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3624, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3625); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3626!=NULL)) {
var3627 = varonce3626;
} else {
var3628 = "%";
var3629 = core__flat___NativeString___to_s_full(var3628, 1l, 1l);
var3627 = var3629;
varonce3626 = var3627;
}
{
var3630 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3627); /* == on <var_pname:String>*/
}
if (var3630){
if (unlikely(varonce3631==NULL)) {
var3632 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3633!=NULL)) {
var3634 = varonce3633;
} else {
var3635 = " % ";
var3636 = core__flat___NativeString___to_s_full(var3635, 3l, 3l);
var3634 = var3636;
varonce3633 = var3634;
}
((struct instance_core__NativeArray*)var3632)->values[1]=var3634;
} else {
var3632 = varonce3631;
varonce3631 = NULL;
}
{
var3637 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3638 = ((val*(*)(val* self))(var3637->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3637); /* to_s on <var3637:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3632)->values[0]=var3638;
{
var3639 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3640 = ((val*(*)(val* self))(var3639->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3639); /* to_s on <var3639:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3632)->values[2]=var3640;
{
var3641 = ((val*(*)(val* self))(var3632->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3632); /* native_to_s on <var3632:NativeArray[String]>*/
}
varonce3631 = var3632;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2913);
fatal_exit(1);
}
{
var3642 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3641, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3642); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3643!=NULL)) {
var3644 = varonce3643;
} else {
var3645 = "<<";
var3646 = core__flat___NativeString___to_s_full(var3645, 2l, 2l);
var3644 = var3646;
varonce3643 = var3644;
}
{
var3647 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3644); /* == on <var_pname:String>*/
}
if (var3647){
if (unlikely(varonce3648==NULL)) {
var3649 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3650!=NULL)) {
var3651 = varonce3650;
} else {
var3652 = " << ";
var3653 = core__flat___NativeString___to_s_full(var3652, 4l, 4l);
var3651 = var3653;
varonce3650 = var3651;
}
((struct instance_core__NativeArray*)var3649)->values[1]=var3651;
} else {
var3649 = varonce3648;
varonce3648 = NULL;
}
{
var3654 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3655 = ((val*(*)(val* self))(var3654->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3654); /* to_s on <var3654:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3649)->values[0]=var3655;
{
var3656 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3657 = ((val*(*)(val* self))(var3656->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3656); /* to_s on <var3656:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3649)->values[2]=var3657;
{
var3658 = ((val*(*)(val* self))(var3649->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3649); /* native_to_s on <var3649:NativeArray[String]>*/
}
varonce3648 = var3649;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2916);
fatal_exit(1);
}
{
var3659 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3658, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3659); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3660!=NULL)) {
var3661 = varonce3660;
} else {
var3662 = ">>";
var3663 = core__flat___NativeString___to_s_full(var3662, 2l, 2l);
var3661 = var3663;
varonce3660 = var3661;
}
{
var3664 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3661); /* == on <var_pname:String>*/
}
if (var3664){
if (unlikely(varonce3665==NULL)) {
var3666 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3667!=NULL)) {
var3668 = varonce3667;
} else {
var3669 = " >> ";
var3670 = core__flat___NativeString___to_s_full(var3669, 4l, 4l);
var3668 = var3670;
varonce3667 = var3668;
}
((struct instance_core__NativeArray*)var3666)->values[1]=var3668;
} else {
var3666 = varonce3665;
varonce3665 = NULL;
}
{
var3671 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3672 = ((val*(*)(val* self))(var3671->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3671); /* to_s on <var3671:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3666)->values[0]=var3672;
{
var3673 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3674 = ((val*(*)(val* self))(var3673->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3673); /* to_s on <var3673:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3666)->values[2]=var3674;
{
var3675 = ((val*(*)(val* self))(var3666->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3666); /* native_to_s on <var3666:NativeArray[String]>*/
}
varonce3665 = var3666;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2919);
fatal_exit(1);
}
{
var3676 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3675, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3676); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3677!=NULL)) {
var3678 = varonce3677;
} else {
var3679 = "==";
var3680 = core__flat___NativeString___to_s_full(var3679, 2l, 2l);
var3678 = var3680;
varonce3677 = var3678;
}
{
var3681 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3678); /* == on <var_pname:String>*/
}
if (var3681){
{
var3682 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3683 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3684 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var3682, var3683);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3684); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3685!=NULL)) {
var3686 = varonce3685;
} else {
var3687 = "!=";
var3688 = core__flat___NativeString___to_s_full(var3687, 2l, 2l);
var3686 = var3688;
varonce3685 = var3686;
}
{
var3689 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3686); /* == on <var_pname:String>*/
}
if (var3689){
{
var3690 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3691 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3692 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var3690, var3691);
}
var_res3693 = var3692;
if (unlikely(varonce3694==NULL)) {
var3695 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3696!=NULL)) {
var3697 = varonce3696;
} else {
var3698 = "!";
var3699 = core__flat___NativeString___to_s_full(var3698, 1l, 1l);
var3697 = var3699;
varonce3696 = var3697;
}
((struct instance_core__NativeArray*)var3695)->values[0]=var3697;
} else {
var3695 = varonce3694;
varonce3694 = NULL;
}
{
var3700 = ((val*(*)(val* self))(var_res3693->class->vft[COLOR_core__abstract_text__Object__to_s]))(var_res3693); /* to_s on <var_res3693:RuntimeVariable>*/
}
((struct instance_core__NativeArray*)var3695)->values[1]=var3700;
{
var3701 = ((val*(*)(val* self))(var3695->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3695); /* native_to_s on <var3695:NativeArray[String]>*/
}
varonce3694 = var3695;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2926);
fatal_exit(1);
}
{
var3702 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3701, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3702); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3703!=NULL)) {
var3704 = varonce3703;
} else {
var3705 = "<";
var3706 = core__flat___NativeString___to_s_full(var3705, 1l, 1l);
var3704 = var3706;
varonce3703 = var3704;
}
{
var3707 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3704); /* == on <var_pname:String>*/
}
if (var3707){
if (unlikely(varonce3708==NULL)) {
var3709 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3710!=NULL)) {
var3711 = varonce3710;
} else {
var3712 = " < ";
var3713 = core__flat___NativeString___to_s_full(var3712, 3l, 3l);
var3711 = var3713;
varonce3710 = var3711;
}
((struct instance_core__NativeArray*)var3709)->values[1]=var3711;
} else {
var3709 = varonce3708;
varonce3708 = NULL;
}
{
var3714 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3715 = ((val*(*)(val* self))(var3714->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3714); /* to_s on <var3714:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3709)->values[0]=var3715;
{
var3716 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3717 = ((val*(*)(val* self))(var3716->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3716); /* to_s on <var3716:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3709)->values[2]=var3717;
{
var3718 = ((val*(*)(val* self))(var3709->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3709); /* native_to_s on <var3709:NativeArray[String]>*/
}
varonce3708 = var3709;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2929);
fatal_exit(1);
}
{
var3719 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3718, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3719); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3720!=NULL)) {
var3721 = varonce3720;
} else {
var3722 = ">";
var3723 = core__flat___NativeString___to_s_full(var3722, 1l, 1l);
var3721 = var3723;
varonce3720 = var3721;
}
{
var3724 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3721); /* == on <var_pname:String>*/
}
if (var3724){
if (unlikely(varonce3725==NULL)) {
var3726 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3727!=NULL)) {
var3728 = varonce3727;
} else {
var3729 = " > ";
var3730 = core__flat___NativeString___to_s_full(var3729, 3l, 3l);
var3728 = var3730;
varonce3727 = var3728;
}
((struct instance_core__NativeArray*)var3726)->values[1]=var3728;
} else {
var3726 = varonce3725;
varonce3725 = NULL;
}
{
var3731 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3732 = ((val*(*)(val* self))(var3731->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3731); /* to_s on <var3731:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3726)->values[0]=var3732;
{
var3733 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3734 = ((val*(*)(val* self))(var3733->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3733); /* to_s on <var3733:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3726)->values[2]=var3734;
{
var3735 = ((val*(*)(val* self))(var3726->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3726); /* native_to_s on <var3726:NativeArray[String]>*/
}
varonce3725 = var3726;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2932);
fatal_exit(1);
}
{
var3736 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3735, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3736); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3737!=NULL)) {
var3738 = varonce3737;
} else {
var3739 = "<=";
var3740 = core__flat___NativeString___to_s_full(var3739, 2l, 2l);
var3738 = var3740;
varonce3737 = var3738;
}
{
var3741 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3738); /* == on <var_pname:String>*/
}
if (var3741){
if (unlikely(varonce3742==NULL)) {
var3743 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3744!=NULL)) {
var3745 = varonce3744;
} else {
var3746 = " <= ";
var3747 = core__flat___NativeString___to_s_full(var3746, 4l, 4l);
var3745 = var3747;
varonce3744 = var3745;
}
((struct instance_core__NativeArray*)var3743)->values[1]=var3745;
} else {
var3743 = varonce3742;
varonce3742 = NULL;
}
{
var3748 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3749 = ((val*(*)(val* self))(var3748->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3748); /* to_s on <var3748:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3743)->values[0]=var3749;
{
var3750 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3751 = ((val*(*)(val* self))(var3750->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3750); /* to_s on <var3750:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3743)->values[2]=var3751;
{
var3752 = ((val*(*)(val* self))(var3743->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3743); /* native_to_s on <var3743:NativeArray[String]>*/
}
varonce3742 = var3743;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2935);
fatal_exit(1);
}
{
var3753 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3752, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3753); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3754!=NULL)) {
var3755 = varonce3754;
} else {
var3756 = ">=";
var3757 = core__flat___NativeString___to_s_full(var3756, 2l, 2l);
var3755 = var3757;
varonce3754 = var3755;
}
{
var3758 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3755); /* == on <var_pname:String>*/
}
if (var3758){
if (unlikely(varonce3759==NULL)) {
var3760 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3761!=NULL)) {
var3762 = varonce3761;
} else {
var3763 = " >= ";
var3764 = core__flat___NativeString___to_s_full(var3763, 4l, 4l);
var3762 = var3764;
varonce3761 = var3762;
}
((struct instance_core__NativeArray*)var3760)->values[1]=var3762;
} else {
var3760 = varonce3759;
varonce3759 = NULL;
}
{
var3765 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3766 = ((val*(*)(val* self))(var3765->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3765); /* to_s on <var3765:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3760)->values[0]=var3766;
{
var3767 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3768 = ((val*(*)(val* self))(var3767->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3767); /* to_s on <var3767:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3760)->values[2]=var3768;
{
var3769 = ((val*(*)(val* self))(var3760->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3760); /* native_to_s on <var3760:NativeArray[String]>*/
}
varonce3759 = var3760;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2938);
fatal_exit(1);
}
{
var3770 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3769, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3770); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3771!=NULL)) {
var3772 = varonce3771;
} else {
var3773 = "to_i";
var3774 = core__flat___NativeString___to_s_full(var3773, 4l, 4l);
var3772 = var3774;
varonce3771 = var3772;
}
{
var3775 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3772); /* == on <var_pname:String>*/
}
if (var3775){
if (unlikely(varonce3776==NULL)) {
var3777 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3778!=NULL)) {
var3779 = varonce3778;
} else {
var3780 = "(long)";
var3781 = core__flat___NativeString___to_s_full(var3780, 6l, 6l);
var3779 = var3781;
varonce3778 = var3779;
}
((struct instance_core__NativeArray*)var3777)->values[0]=var3779;
} else {
var3777 = varonce3776;
varonce3776 = NULL;
}
{
var3782 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3783 = ((val*(*)(val* self))(var3782->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3782); /* to_s on <var3782:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3777)->values[1]=var3783;
{
var3784 = ((val*(*)(val* self))(var3777->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3777); /* native_to_s on <var3777:NativeArray[String]>*/
}
varonce3776 = var3777;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2941);
fatal_exit(1);
}
{
var3785 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3784, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3785); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3786!=NULL)) {
var3787 = varonce3786;
} else {
var3788 = "to_b";
var3789 = core__flat___NativeString___to_s_full(var3788, 4l, 4l);
var3787 = var3789;
varonce3786 = var3787;
}
{
var3790 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3787); /* == on <var_pname:String>*/
}
if (var3790){
if (unlikely(varonce3791==NULL)) {
var3792 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3793!=NULL)) {
var3794 = varonce3793;
} else {
var3795 = "(unsigned char)";
var3796 = core__flat___NativeString___to_s_full(var3795, 15l, 15l);
var3794 = var3796;
varonce3793 = var3794;
}
((struct instance_core__NativeArray*)var3792)->values[0]=var3794;
} else {
var3792 = varonce3791;
varonce3791 = NULL;
}
{
var3797 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3798 = ((val*(*)(val* self))(var3797->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3797); /* to_s on <var3797:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3792)->values[1]=var3798;
{
var3799 = ((val*(*)(val* self))(var3792->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3792); /* native_to_s on <var3792:NativeArray[String]>*/
}
varonce3791 = var3792;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2944);
fatal_exit(1);
}
{
var3800 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3799, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3800); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3801!=NULL)) {
var3802 = varonce3801;
} else {
var3803 = "to_i8";
var3804 = core__flat___NativeString___to_s_full(var3803, 5l, 5l);
var3802 = var3804;
varonce3801 = var3802;
}
{
var3805 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3802); /* == on <var_pname:String>*/
}
if (var3805){
if (unlikely(varonce3806==NULL)) {
var3807 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3808!=NULL)) {
var3809 = varonce3808;
} else {
var3810 = "(int8_t)";
var3811 = core__flat___NativeString___to_s_full(var3810, 8l, 8l);
var3809 = var3811;
varonce3808 = var3809;
}
((struct instance_core__NativeArray*)var3807)->values[0]=var3809;
} else {
var3807 = varonce3806;
varonce3806 = NULL;
}
{
var3812 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3813 = ((val*(*)(val* self))(var3812->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3812); /* to_s on <var3812:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3807)->values[1]=var3813;
{
var3814 = ((val*(*)(val* self))(var3807->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3807); /* native_to_s on <var3807:NativeArray[String]>*/
}
varonce3806 = var3807;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2947);
fatal_exit(1);
}
{
var3815 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3814, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3815); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3816!=NULL)) {
var3817 = varonce3816;
} else {
var3818 = "to_i16";
var3819 = core__flat___NativeString___to_s_full(var3818, 6l, 6l);
var3817 = var3819;
varonce3816 = var3817;
}
{
var3820 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3817); /* == on <var_pname:String>*/
}
if (var3820){
if (unlikely(varonce3821==NULL)) {
var3822 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3823!=NULL)) {
var3824 = varonce3823;
} else {
var3825 = "(int16_t)";
var3826 = core__flat___NativeString___to_s_full(var3825, 9l, 9l);
var3824 = var3826;
varonce3823 = var3824;
}
((struct instance_core__NativeArray*)var3822)->values[0]=var3824;
} else {
var3822 = varonce3821;
varonce3821 = NULL;
}
{
var3827 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3828 = ((val*(*)(val* self))(var3827->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3827); /* to_s on <var3827:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3822)->values[1]=var3828;
{
var3829 = ((val*(*)(val* self))(var3822->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3822); /* native_to_s on <var3822:NativeArray[String]>*/
}
varonce3821 = var3822;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2950);
fatal_exit(1);
}
{
var3830 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3829, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3830); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3831!=NULL)) {
var3832 = varonce3831;
} else {
var3833 = "to_u16";
var3834 = core__flat___NativeString___to_s_full(var3833, 6l, 6l);
var3832 = var3834;
varonce3831 = var3832;
}
{
var3835 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3832); /* == on <var_pname:String>*/
}
if (var3835){
if (unlikely(varonce3836==NULL)) {
var3837 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3838!=NULL)) {
var3839 = varonce3838;
} else {
var3840 = "(uint16_t)";
var3841 = core__flat___NativeString___to_s_full(var3840, 10l, 10l);
var3839 = var3841;
varonce3838 = var3839;
}
((struct instance_core__NativeArray*)var3837)->values[0]=var3839;
} else {
var3837 = varonce3836;
varonce3836 = NULL;
}
{
var3842 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3843 = ((val*(*)(val* self))(var3842->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3842); /* to_s on <var3842:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3837)->values[1]=var3843;
{
var3844 = ((val*(*)(val* self))(var3837->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3837); /* native_to_s on <var3837:NativeArray[String]>*/
}
varonce3836 = var3837;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2953);
fatal_exit(1);
}
{
var3845 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3844, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3845); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3846!=NULL)) {
var3847 = varonce3846;
} else {
var3848 = "to_i32";
var3849 = core__flat___NativeString___to_s_full(var3848, 6l, 6l);
var3847 = var3849;
varonce3846 = var3847;
}
{
var3850 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3847); /* == on <var_pname:String>*/
}
if (var3850){
if (unlikely(varonce3851==NULL)) {
var3852 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3853!=NULL)) {
var3854 = varonce3853;
} else {
var3855 = "(int32_t)";
var3856 = core__flat___NativeString___to_s_full(var3855, 9l, 9l);
var3854 = var3856;
varonce3853 = var3854;
}
((struct instance_core__NativeArray*)var3852)->values[0]=var3854;
} else {
var3852 = varonce3851;
varonce3851 = NULL;
}
{
var3857 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3858 = ((val*(*)(val* self))(var3857->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3857); /* to_s on <var3857:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3852)->values[1]=var3858;
{
var3859 = ((val*(*)(val* self))(var3852->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3852); /* native_to_s on <var3852:NativeArray[String]>*/
}
varonce3851 = var3852;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2956);
fatal_exit(1);
}
{
var3860 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3859, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3860); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3861!=NULL)) {
var3862 = varonce3861;
} else {
var3863 = "to_f";
var3864 = core__flat___NativeString___to_s_full(var3863, 4l, 4l);
var3862 = var3864;
varonce3861 = var3862;
}
{
var3865 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3862); /* == on <var_pname:String>*/
}
if (var3865){
if (unlikely(varonce3866==NULL)) {
var3867 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3868!=NULL)) {
var3869 = varonce3868;
} else {
var3870 = "(double)";
var3871 = core__flat___NativeString___to_s_full(var3870, 8l, 8l);
var3869 = var3871;
varonce3868 = var3869;
}
((struct instance_core__NativeArray*)var3867)->values[0]=var3869;
} else {
var3867 = varonce3866;
varonce3866 = NULL;
}
{
var3872 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3873 = ((val*(*)(val* self))(var3872->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3872); /* to_s on <var3872:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3867)->values[1]=var3873;
{
var3874 = ((val*(*)(val* self))(var3867->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3867); /* native_to_s on <var3867:NativeArray[String]>*/
}
varonce3866 = var3867;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2959);
fatal_exit(1);
}
{
var3875 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3874, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3875); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3876!=NULL)) {
var3877 = varonce3876;
} else {
var3878 = "&";
var3879 = core__flat___NativeString___to_s_full(var3878, 1l, 1l);
var3877 = var3879;
varonce3876 = var3877;
}
{
var3880 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3877); /* == on <var_pname:String>*/
}
if (var3880){
if (unlikely(varonce3881==NULL)) {
var3882 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3883!=NULL)) {
var3884 = varonce3883;
} else {
var3885 = " & ";
var3886 = core__flat___NativeString___to_s_full(var3885, 3l, 3l);
var3884 = var3886;
varonce3883 = var3884;
}
((struct instance_core__NativeArray*)var3882)->values[1]=var3884;
} else {
var3882 = varonce3881;
varonce3881 = NULL;
}
{
var3887 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3888 = ((val*(*)(val* self))(var3887->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3887); /* to_s on <var3887:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3882)->values[0]=var3888;
{
var3889 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3890 = ((val*(*)(val* self))(var3889->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3889); /* to_s on <var3889:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3882)->values[2]=var3890;
{
var3891 = ((val*(*)(val* self))(var3882->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3882); /* native_to_s on <var3882:NativeArray[String]>*/
}
varonce3881 = var3882;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2962);
fatal_exit(1);
}
{
var3892 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3891, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3892); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3893!=NULL)) {
var3894 = varonce3893;
} else {
var3895 = "|";
var3896 = core__flat___NativeString___to_s_full(var3895, 1l, 1l);
var3894 = var3896;
varonce3893 = var3894;
}
{
var3897 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3894); /* == on <var_pname:String>*/
}
if (var3897){
if (unlikely(varonce3898==NULL)) {
var3899 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3900!=NULL)) {
var3901 = varonce3900;
} else {
var3902 = " | ";
var3903 = core__flat___NativeString___to_s_full(var3902, 3l, 3l);
var3901 = var3903;
varonce3900 = var3901;
}
((struct instance_core__NativeArray*)var3899)->values[1]=var3901;
} else {
var3899 = varonce3898;
varonce3898 = NULL;
}
{
var3904 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3905 = ((val*(*)(val* self))(var3904->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3904); /* to_s on <var3904:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3899)->values[0]=var3905;
{
var3906 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3907 = ((val*(*)(val* self))(var3906->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3906); /* to_s on <var3906:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3899)->values[2]=var3907;
{
var3908 = ((val*(*)(val* self))(var3899->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3899); /* native_to_s on <var3899:NativeArray[String]>*/
}
varonce3898 = var3899;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2965);
fatal_exit(1);
}
{
var3909 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3908, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3909); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3910!=NULL)) {
var3911 = varonce3910;
} else {
var3912 = "^";
var3913 = core__flat___NativeString___to_s_full(var3912, 1l, 1l);
var3911 = var3913;
varonce3910 = var3911;
}
{
var3914 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3911); /* == on <var_pname:String>*/
}
if (var3914){
if (unlikely(varonce3915==NULL)) {
var3916 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3917!=NULL)) {
var3918 = varonce3917;
} else {
var3919 = " ^ ";
var3920 = core__flat___NativeString___to_s_full(var3919, 3l, 3l);
var3918 = var3920;
varonce3917 = var3918;
}
((struct instance_core__NativeArray*)var3916)->values[1]=var3918;
} else {
var3916 = varonce3915;
varonce3915 = NULL;
}
{
var3921 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3922 = ((val*(*)(val* self))(var3921->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3921); /* to_s on <var3921:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3916)->values[0]=var3922;
{
var3923 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3924 = ((val*(*)(val* self))(var3923->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3923); /* to_s on <var3923:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3916)->values[2]=var3924;
{
var3925 = ((val*(*)(val* self))(var3916->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3916); /* native_to_s on <var3916:NativeArray[String]>*/
}
varonce3915 = var3916;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2968);
fatal_exit(1);
}
{
var3926 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3925, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3926); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3927!=NULL)) {
var3928 = varonce3927;
} else {
var3929 = "unary ~";
var3930 = core__flat___NativeString___to_s_full(var3929, 7l, 7l);
var3928 = var3930;
varonce3927 = var3928;
}
{
var3931 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3928); /* == on <var_pname:String>*/
}
if (var3931){
if (unlikely(varonce3932==NULL)) {
var3933 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce3934!=NULL)) {
var3935 = varonce3934;
} else {
var3936 = "~";
var3937 = core__flat___NativeString___to_s_full(var3936, 1l, 1l);
var3935 = var3937;
varonce3934 = var3935;
}
((struct instance_core__NativeArray*)var3933)->values[0]=var3935;
} else {
var3933 = varonce3932;
varonce3932 = NULL;
}
{
var3938 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var3939 = ((val*(*)(val* self))(var3938->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3938); /* to_s on <var3938:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3933)->values[1]=var3939;
{
var3940 = ((val*(*)(val* self))(var3933->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3933); /* native_to_s on <var3933:NativeArray[String]>*/
}
varonce3932 = var3933;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2971);
fatal_exit(1);
}
{
var3941 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3940, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3941); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
}
} else {
}
}
}
}
}
}
}
}
}
}
}
}
}
if (likely(varonce3942!=NULL)) {
var3943 = varonce3942;
} else {
var3944 = "exit";
var3945 = core__flat___NativeString___to_s_full(var3944, 4l, 4l);
var3943 = var3945;
varonce3942 = var3943;
}
{
var3946 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3943); /* == on <var_pname:String>*/
}
if (var3946){
if (unlikely(varonce3947==NULL)) {
var3948 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3949!=NULL)) {
var3950 = varonce3949;
} else {
var3951 = "exit(";
var3952 = core__flat___NativeString___to_s_full(var3951, 5l, 5l);
var3950 = var3952;
varonce3949 = var3950;
}
((struct instance_core__NativeArray*)var3948)->values[0]=var3950;
if (likely(varonce3953!=NULL)) {
var3954 = varonce3953;
} else {
var3955 = ");";
var3956 = core__flat___NativeString___to_s_full(var3955, 2l, 2l);
var3954 = var3956;
varonce3953 = var3954;
}
((struct instance_core__NativeArray*)var3948)->values[2]=var3954;
} else {
var3948 = varonce3947;
varonce3947 = NULL;
}
{
var3957 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3958 = ((val*(*)(val* self))(var3957->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3957); /* to_s on <var3957:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3948)->values[1]=var3958;
{
var3959 = ((val*(*)(val* self))(var3948->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3948); /* native_to_s on <var3948:NativeArray[String]>*/
}
varonce3947 = var3948;
{
nitc___nitc__AbstractCompilerVisitor___add(var_v, var3959); /* Direct call abstract_compiler#AbstractCompilerVisitor#add on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3960!=NULL)) {
var3961 = varonce3960;
} else {
var3962 = "sys";
var3963 = core__flat___NativeString___to_s_full(var3962, 3l, 3l);
var3961 = var3963;
varonce3960 = var3961;
}
{
var3964 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3961); /* == on <var_pname:String>*/
}
if (var3964){
if (likely(varonce3965!=NULL)) {
var3966 = varonce3965;
} else {
var3967 = "glob_sys";
var3968 = core__flat___NativeString___to_s_full(var3967, 8l, 8l);
var3966 = var3968;
varonce3965 = var3966;
}
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2979);
fatal_exit(1);
}
{
var3969 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3966, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3969); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3970!=NULL)) {
var3971 = varonce3970;
} else {
var3972 = "calloc_string";
var3973 = core__flat___NativeString___to_s_full(var3972, 13l, 13l);
var3971 = var3973;
varonce3970 = var3971;
}
{
var3974 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3971); /* == on <var_pname:String>*/
}
if (var3974){
if (unlikely(varonce3975==NULL)) {
var3976 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce3977!=NULL)) {
var3978 = varonce3977;
} else {
var3979 = "(char*)nit_alloc(";
var3980 = core__flat___NativeString___to_s_full(var3979, 17l, 17l);
var3978 = var3980;
varonce3977 = var3978;
}
((struct instance_core__NativeArray*)var3976)->values[0]=var3978;
if (likely(varonce3981!=NULL)) {
var3982 = varonce3981;
} else {
var3983 = ")";
var3984 = core__flat___NativeString___to_s_full(var3983, 1l, 1l);
var3982 = var3984;
varonce3981 = var3982;
}
((struct instance_core__NativeArray*)var3976)->values[2]=var3982;
} else {
var3976 = varonce3975;
varonce3975 = NULL;
}
{
var3985 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var3986 = ((val*(*)(val* self))(var3985->class->vft[COLOR_core__abstract_text__Object__to_s]))(var3985); /* to_s on <var3985:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var3976)->values[1]=var3986;
{
var3987 = ((val*(*)(val* self))(var3976->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var3976); /* native_to_s on <var3976:NativeArray[String]>*/
}
varonce3975 = var3976;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2982);
fatal_exit(1);
}
{
var3988 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var3987, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var3988); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3989!=NULL)) {
var3990 = varonce3989;
} else {
var3991 = "calloc_array";
var3992 = core__flat___NativeString___to_s_full(var3991, 12l, 12l);
var3990 = var3992;
varonce3989 = var3990;
}
{
var3993 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3990); /* == on <var_pname:String>*/
}
if (var3993){
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2985);
fatal_exit(1);
}
{
((void(*)(val* self, val* p0, val* p1))(var_v->class->vft[COLOR_nitc__abstract_compiler__AbstractCompilerVisitor__calloc_array]))(var_v, var_ret, var_arguments); /* calloc_array on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce3994!=NULL)) {
var3995 = varonce3994;
} else {
var3996 = "object_id";
var3997 = core__flat___NativeString___to_s_full(var3996, 9l, 9l);
var3995 = var3997;
varonce3994 = var3995;
}
{
var3998 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var3995); /* == on <var_pname:String>*/
}
if (var3998){
if (unlikely(varonce3999==NULL)) {
var4000 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce4001!=NULL)) {
var4002 = varonce4001;
} else {
var4003 = "(long)";
var4004 = core__flat___NativeString___to_s_full(var4003, 6l, 6l);
var4002 = var4004;
varonce4001 = var4002;
}
((struct instance_core__NativeArray*)var4000)->values[0]=var4002;
} else {
var4000 = varonce3999;
varonce3999 = NULL;
}
{
var4005 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var4006 = ((val*(*)(val* self))(var4005->class->vft[COLOR_core__abstract_text__Object__to_s]))(var4005); /* to_s on <var4005:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var4000)->values[1]=var4006;
{
var4007 = ((val*(*)(val* self))(var4000->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var4000); /* native_to_s on <var4000:NativeArray[String]>*/
}
varonce3999 = var4000;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 2988);
fatal_exit(1);
}
{
var4008 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var4007, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var4008); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce4009!=NULL)) {
var4010 = varonce4009;
} else {
var4011 = "is_same_type";
var4012 = core__flat___NativeString___to_s_full(var4011, 12l, 12l);
var4010 = var4012;
varonce4009 = var4010;
}
{
var4013 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var4010); /* == on <var_pname:String>*/
}
if (var4013){
{
var4014 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var4015 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var4016 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__is_same_type_test(var_v, var4014, var4015);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var4016); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce4017!=NULL)) {
var4018 = varonce4017;
} else {
var4019 = "is_same_instance";
var4020 = core__flat___NativeString___to_s_full(var4019, 16l, 16l);
var4018 = var4020;
varonce4017 = var4018;
}
{
var4021 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var4018); /* == on <var_pname:String>*/
}
if (var4021){
{
var4022 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 0l);
}
{
var4023 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var4024 = nitc___nitc__SeparateCompilerVisitor___nitc__abstract_compiler__AbstractCompilerVisitor__equal_test(var_v, var4022, var4023);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var4024); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce4025!=NULL)) {
var4026 = varonce4025;
} else {
var4027 = "output_class_name";
var4028 = core__flat___NativeString___to_s_full(var4027, 17l, 17l);
var4026 = var4028;
varonce4025 = var4026;
}
{
var4029 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var4026); /* == on <var_pname:String>*/
}
if (var4029){
{
var4030 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var4031 = ((val*(*)(val* self, val* p0))(var_v->class->vft[COLOR_nitc__abstract_compiler__AbstractCompilerVisitor__class_name_string]))(var_v, var4030); /* class_name_string on <var_v:AbstractCompilerVisitor>*/
}
var_nat = var4031;
if (unlikely(varonce4032==NULL)) {
var4033 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce4034!=NULL)) {
var4035 = varonce4034;
} else {
var4036 = "printf(\"%s\\n\", ";
var4037 = core__flat___NativeString___to_s_full(var4036, 15l, 15l);
var4035 = var4037;
varonce4034 = var4035;
}
((struct instance_core__NativeArray*)var4033)->values[0]=var4035;
if (likely(varonce4038!=NULL)) {
var4039 = varonce4038;
} else {
var4040 = ");";
var4041 = core__flat___NativeString___to_s_full(var4040, 2l, 2l);
var4039 = var4041;
varonce4038 = var4039;
}
((struct instance_core__NativeArray*)var4033)->values[2]=var4039;
} else {
var4033 = varonce4032;
varonce4032 = NULL;
}
((struct instance_core__NativeArray*)var4033)->values[1]=var_nat;
{
var4042 = ((val*(*)(val* self))(var4033->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var4033); /* native_to_s on <var4033:NativeArray[String]>*/
}
varonce4032 = var4033;
{
nitc___nitc__AbstractCompilerVisitor___add(var_v, var4042); /* Direct call abstract_compiler#AbstractCompilerVisitor#add on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce4043!=NULL)) {
var4044 = varonce4043;
} else {
var4045 = "native_class_name";
var4046 = core__flat___NativeString___to_s_full(var4045, 17l, 17l);
var4044 = var4046;
varonce4043 = var4044;
}
{
var4047 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var4044); /* == on <var_pname:String>*/
}
if (var4047){
{
var4048 = core___core__SequenceRead___Collection__first(var_arguments);
}
{
var4049 = ((val*(*)(val* self, val* p0))(var_v->class->vft[COLOR_nitc__abstract_compiler__AbstractCompilerVisitor__class_name_string]))(var_v, var4048); /* class_name_string on <var_v:AbstractCompilerVisitor>*/
}
var_nat4050 = var4049;
if (unlikely(varonce4051==NULL)) {
var4052 = NEW_core__NativeArray(2l, &type_core__NativeArray__core__String);
if (likely(varonce4053!=NULL)) {
var4054 = varonce4053;
} else {
var4055 = "(char*)";
var4056 = core__flat___NativeString___to_s_full(var4055, 7l, 7l);
var4054 = var4056;
varonce4053 = var4054;
}
((struct instance_core__NativeArray*)var4052)->values[0]=var4054;
} else {
var4052 = varonce4051;
varonce4051 = NULL;
}
((struct instance_core__NativeArray*)var4052)->values[1]=var_nat4050;
{
var4057 = ((val*(*)(val* self))(var4052->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var4052); /* native_to_s on <var4052:NativeArray[String]>*/
}
varonce4051 = var4052;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 3002);
fatal_exit(1);
}
{
var4058 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var4057, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var4058); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce4059!=NULL)) {
var4060 = varonce4059;
} else {
var4061 = "force_garbage_collection";
var4062 = core__flat___NativeString___to_s_full(var4061, 24l, 24l);
var4060 = var4062;
varonce4059 = var4060;
}
{
var4063 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var4060); /* == on <var_pname:String>*/
}
if (var4063){
if (likely(varonce4064!=NULL)) {
var4065 = varonce4064;
} else {
var4066 = "nit_gcollect();";
var4067 = core__flat___NativeString___to_s_full(var4066, 15l, 15l);
var4065 = var4067;
varonce4064 = var4065;
}
{
nitc___nitc__AbstractCompilerVisitor___add(var_v, var4065); /* Direct call abstract_compiler#AbstractCompilerVisitor#add on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce4068!=NULL)) {
var4069 = varonce4068;
} else {
var4070 = "native_argc";
var4071 = core__flat___NativeString___to_s_full(var4070, 11l, 11l);
var4069 = var4071;
varonce4068 = var4069;
}
{
var4072 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var4069); /* == on <var_pname:String>*/
}
if (var4072){
if (likely(varonce4073!=NULL)) {
var4074 = varonce4073;
} else {
var4075 = "glob_argc";
var4076 = core__flat___NativeString___to_s_full(var4075, 9l, 9l);
var4074 = var4076;
varonce4073 = var4074;
}
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 3008);
fatal_exit(1);
}
{
var4077 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var4074, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var4077); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
if (likely(varonce4078!=NULL)) {
var4079 = varonce4078;
} else {
var4080 = "native_argv";
var4081 = core__flat___NativeString___to_s_full(var4080, 11l, 11l);
var4079 = var4081;
varonce4078 = var4079;
}
{
var4082 = ((short int(*)(val* self, val* p0))(var_pname->class->vft[COLOR_core__kernel__Object___61d_61d]))(var_pname, var4079); /* == on <var_pname:String>*/
}
if (var4082){
if (unlikely(varonce4083==NULL)) {
var4084 = NEW_core__NativeArray(3l, &type_core__NativeArray__core__String);
if (likely(varonce4085!=NULL)) {
var4086 = varonce4085;
} else {
var4087 = "glob_argv[";
var4088 = core__flat___NativeString___to_s_full(var4087, 10l, 10l);
var4086 = var4088;
varonce4085 = var4086;
}
((struct instance_core__NativeArray*)var4084)->values[0]=var4086;
if (likely(varonce4089!=NULL)) {
var4090 = varonce4089;
} else {
var4091 = "]";
var4092 = core__flat___NativeString___to_s_full(var4091, 1l, 1l);
var4090 = var4092;
varonce4089 = var4090;
}
((struct instance_core__NativeArray*)var4084)->values[2]=var4090;
} else {
var4084 = varonce4083;
varonce4083 = NULL;
}
{
var4093 = core___core__Array___core__abstract_collection__SequenceRead___91d_93d(var_arguments, 1l);
}
{
var4094 = ((val*(*)(val* self))(var4093->class->vft[COLOR_core__abstract_text__Object__to_s]))(var4093); /* to_s on <var4093:nullable Object(RuntimeVariable)>*/
}
((struct instance_core__NativeArray*)var4084)->values[1]=var4094;
{
var4095 = ((val*(*)(val* self))(var4084->class->vft[COLOR_core__abstract_text__NativeArray__native_to_s]))(var4084); /* native_to_s on <var4084:NativeArray[String]>*/
}
varonce4083 = var4084;
if (unlikely(var_ret == NULL)) {
PRINT_ERROR("Runtime error: %s", "Cast failed");
PRINT_ERROR(" (%s:%d)\n", FILE_nitc__abstract_compiler, 3011);
fatal_exit(1);
}
{
var4096 = nitc___nitc__AbstractCompilerVisitor___new_expr(var_v, var4095, var_ret);
}
{
nitc___nitc__AbstractCompilerVisitor___ret(var_v, var4096); /* Direct call abstract_compiler#AbstractCompilerVisitor#ret on <var_v:AbstractCompilerVisitor>*/
}
var = 1;
goto RET_LABEL;
} else {
}
}
}
}
}
}
}
}
}
}
}
}
var = 0;
goto RET_LABEL;
RET_LABEL:;
return var;
}
