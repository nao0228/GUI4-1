#include "Particle.h"

Particle::Particle(void) : x(0), y(0), vx(0), vy(0), ax(0), ay(0), omega(0), phi(0), radius(0), mx(0), my(0), lastupdate(0), life(0), color(0), hdc(0)
{
}

Particle::~Particle(void)
{
}

void Particle::init(void)
{
	// TODO : �p�[�e�B�N���̒��S���W���}�E�X�J�[�\���̍��W�ɂ���B
	x = mx;
	y = my;
	// TODO : �p�[�e�B�N���̑��x�i�����x�j��-30�`30 �̗����Őݒ肷��B
	vx = (rand() * 2 - 1) * 30;
	vy = (rand() * 2 - 1) * 30;
	// TODO : �p�[�e�B�N���̉����x�� 0 �ɂ���B
	ax = 0;
	ay = 0;
	// TODO : �p�[�e�B�N���̔��a�� 10 �ɂ���B
	radius = 10;
	// TODO : �p�[�e�B�N���̎����� 1�`3 �b�̗����Őݒ肷��B
	life = rand() * 2 + 1;
	// TODO : �p�[�e�B�N���̐F��ɂ���B
	color = 0x0000FF;
	// TODO : �^�C�}�[�����Z�b�g����B
	timer.reset();
		// TODO : �ŏI�X�V������ 0 �ɂ���B
	lastupdate = 0;
}

void Particle::clean(void)
{
}

// �p�[�e�B�N���̋����v�Z
void Particle::update(void)
{
	double t; // ���݂̎���
	// TODO : t �Ɍ��݂̎����i�^�C�}�[�l�j���Z�b�g����B
	double t = timer.get();
	// TODO : �������݂̎��� t ������ life �ȉ��Ȃ�A
	if (t <= life) {
		double dt; // �ŏI�X�V���� lastupdate ����o�ߎ���
		 // TODO : dt �ɍŏI�X�V��������̌o�ߎ��Ԃ��Z�b�g����B
		dt = t - lastupdate;
		 // TODO : ax,ay,dt ��p���Č��݂̑��x vx,vy ���v�Z����B
		vx += ax * dt;
		vy += ay * dt;
		 // TODO : vx,vy,dt ��p���Č��݂̈ʒu x,y ���v�Z����B
		x = vx * dt;
		y = vy * dt;
		 // TODO : t ��p���Č��݂̔��a radius ���v�Z����B
		radius = (-10 / life) * t + 10;
		 // TODO : t ��p���Č��݂̐F color ���v�Z����B
		double RG = (255 / life) * t;
		color = RGB(RG, RG, 255);
		 // TODO : �ŏI�X�V���������݂̎������Z�b�g����B
		lastupdate = t;
	}
	 // TODO : �����łȂ���΁A
	else {
		// TODO : �I������������B(clean()���ĂԁB)
		clean();
		// TODO : ��������������B(init()���ĂԁB)
		init();
	}
}

// �p�[�e�B�N���̕`��
void Particle::draw(void)
{
	// TODO : ���S���W(x, y), ���a radius, �F color �̉~��h��Ԃ��`�悷��B
	SelectObject(hdc, GetStockObject(DC_PEN)); // PEN�i�֊s���j���g��
	SelectObject(hdc, GetStockObject(DC_BRUSH)); // BRUSH�i�h��j���g��
	SetDCPenColor(hdc,color); // PEN �̐F
	SetDCBrushColor(hdc, color); // BRUSH �̐F
	Ellipse(hdc, x-10, y-10, x+10, y+10); // �ȉ~�`��
}


void Particle::setCursorPos(int mx, int my)
{
	// TODO : �������� mx, my �������o�ϐ��� mx, my �փZ�b�g����B
	this->mx = mx;
	this->my = my;
}

void Particle::setHDC(HDC hdc)
{
	// TODO : �������� hdc �������o�ϐ��� hdc �ɃZ�b�g����B
	this->hdc = hdc;
}

double Particle::rand(void)
{
	return static_cast<double>(::rand()) / RAND_MAX;
}
