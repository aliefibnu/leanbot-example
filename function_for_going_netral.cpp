//bot1 yg ada di kanan
//bot2 yg ada di kiri
//ini derajat dan jarak lari nya blom di setela karena perhitungan pasti nya blom di hitung
#include <Leanbot.h>


void netral_kiri_bot1() {
    LbMotion.waitRotationDeg(90);
    LbMotion.waitDistanceMm(4.2 * 10);
    LbGripper.close();
}


void netral_kiri_bot2() {
    LbMotion.waitDistanceMm(4.2 * 10);
    LbMotion.waitRotationDeg(4.2);
    LbMotion.waitDistanceMm(4.2 * 10);
    LbGripper.close();
}

void netral_kanan_bawah_bot1() {
    LbMotion.waitDistanceMm((-20) * 10); //mundur
    LbMotion.waitRotationDeg(-100);
    LbMotion.waitDistanceMm(4.2 * 10);
    LbGripper.close();
}


void netral_kanan_bawah_bot2() {
    LbMotion.waitRotationDeg(-100); //mundur
    LbMotion.waitDistanceMm(4.2 * 10);
    LbGripper.close();
}
