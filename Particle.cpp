#include "Particle.h"

Particle::Particle(void) : x(0), y(0), vx(0), vy(0), ax(0), ay(0), omega(0), phi(0), radius(0), mx(0), my(0), lastupdate(0), life(0), color(0), hdc(0)
{
}

Particle::~Particle(void)
{
}

void Particle::init(void)
{
	// TODO : パーティクルの中心座標をマウスカーソルの座標にする。
	x = mx;
	y = my;
	// TODO : パーティクルの速度（初速度）を-30～30 の乱数で設定する。
	vx = (rand() * 2 - 1) * 30;
	vy = (rand() * 2 - 1) * 30;
	// TODO : パーティクルの加速度を 0 にする。
	ax = 0;
	ay = 0;
	// TODO : パーティクルの半径を 10 にする。
	radius = 10;
	// TODO : パーティクルの寿命を 1～3 秒の乱数で設定する。
	life = rand() * 2 + 1;
	// TODO : パーティクルの色を青にする。
	color = 0x0000FF;
	// TODO : タイマーをリセットする。
	timer.reset();
		// TODO : 最終更新時刻を 0 にする。
	lastupdate = 0;
}

void Particle::clean(void)
{
}

// パーティクルの挙動計算
void Particle::update(void)
{
	double t; // 現在の時刻
	// TODO : t に現在の時刻（タイマー値）をセットする。
	double t = timer.get();
	// TODO : もし現在の時刻 t が寿命 life 以下なら、
	if (t <= life) {
		double dt; // 最終更新時刻 lastupdate から経過時間
		 // TODO : dt に最終更新時刻からの経過時間をセットする。
		dt = t - lastupdate;
		 // TODO : ax,ay,dt を用いて現在の速度 vx,vy を計算する。
		vx += ax * dt;
		vy += ay * dt;
		 // TODO : vx,vy,dt を用いて現在の位置 x,y を計算する。
		x = vx * dt;
		y = vy * dt;
		 // TODO : t を用いて現在の半径 radius を計算する。
		radius = (-10 / life) * t + 10;
		 // TODO : t を用いて現在の色 color を計算する。
		double RG = (255 / life) * t;
		color = RGB(RG, RG, 255);
		 // TODO : 最終更新時刻を現在の時刻をセットする。
		lastupdate = t;
	}
	 // TODO : そうでなければ、
	else {
		// TODO : 終了処理をする。(clean()を呼ぶ。)
		clean();
		// TODO : 初期処理をする。(init()を呼ぶ。)
		init();
	}
}

// パーティクルの描画
void Particle::draw(void)
{
	// TODO : 中心座標(x, y), 半径 radius, 色 color の円を塗りつぶし描画する。
	SelectObject(hdc, GetStockObject(DC_PEN)); // PEN（輪郭線）を使う
	SelectObject(hdc, GetStockObject(DC_BRUSH)); // BRUSH（塗り）を使う
	SetDCPenColor(hdc,color); // PEN の色
	SetDCBrushColor(hdc, color); // BRUSH の色
	Ellipse(hdc, x-10, y-10, x+10, y+10); // 楕円描画
}


void Particle::setCursorPos(int mx, int my)
{
	// TODO : 仮引数の mx, my をメンバ変数の mx, my へセットする。
	this->mx = mx;
	this->my = my;
}

void Particle::setHDC(HDC hdc)
{
	// TODO : 仮引数の hdc をメンバ変数の hdc にセットする。
	this->hdc = hdc;
}

double Particle::rand(void)
{
	return static_cast<double>(::rand()) / RAND_MAX;
}
