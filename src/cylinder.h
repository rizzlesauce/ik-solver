#ifndef cylinder_h
#define cylinder_h

#include "gltypes.h"


static const VERTEX_DATA_3D cylinderVertexData[] = {
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{0.707107, 0.707107, -1.000000}, /*n:*/{0.498764, 0.498764, -0.708792} },
	{/*v:*/{0.831470, 0.555570, -1.000000}, /*n:*/{0.675375, 0.484054, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{0.831471, 0.555569, 1.000000}, /*n:*/{0.705679, 0.438704, 0.556322} },
	{/*v:*/{0.707108, 0.707105, 1.000000}, /*n:*/{0.631825, 0.631825, 0.448927} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{0.831470, 0.555570, -1.000000}, /*n:*/{0.675375, 0.484054, -0.556322} },
	{/*v:*/{0.923880, 0.382683, -1.000000}, /*n:*/{0.756828, 0.342998, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{0.923880, 0.382682, 1.000000}, /*n:*/{0.777703, 0.292611, 0.556322} },
	{/*v:*/{0.831471, 0.555569, 1.000000}, /*n:*/{0.705679, 0.438704, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{0.923880, 0.382683, -1.000000}, /*n:*/{0.756828, 0.342998, -0.556322} },
	{/*v:*/{0.980785, 0.195090, -1.000000}, /*n:*/{0.809198, 0.188757, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{0.980786, 0.195088, 1.000000}, /*n:*/{0.819849, 0.135258, 0.556322} },
	{/*v:*/{0.923880, 0.382682, 1.000000}, /*n:*/{0.777703, 0.292611, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{0.980785, 0.195090, -1.000000}, /*n:*/{0.809198, 0.188757, -0.556322} },
	{/*v:*/{1.000000, 0.000000, -1.000000}, /*n:*/{0.830500, 0.027253, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{1.000000, -0.000002, 1.000000}, /*n:*/{0.830500, -0.027253, 0.556322} },
	{/*v:*/{0.980786, 0.195088, 1.000000}, /*n:*/{0.819849, 0.135258, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{1.000000, 0.000000, -1.000000}, /*n:*/{0.830500, 0.027253, -0.556322} },
	{/*v:*/{0.980785, -0.195090, -1.000000}, /*n:*/{0.819849, -0.135258, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{0.980785, -0.195092, 1.000000}, /*n:*/{0.809198, -0.188757, 0.556322} },
	{/*v:*/{1.000000, -0.000002, 1.000000}, /*n:*/{0.830500, -0.027253, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{0.980785, -0.195090, -1.000000}, /*n:*/{0.819849, -0.135258, -0.556322} },
	{/*v:*/{0.923880, -0.382683, -1.000000}, /*n:*/{0.777703, -0.292611, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{0.923879, -0.382685, 1.000000}, /*n:*/{0.756828, -0.342998, 0.556322} },
	{/*v:*/{0.980785, -0.195092, 1.000000}, /*n:*/{0.809198, -0.188757, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{0.923880, -0.382683, -1.000000}, /*n:*/{0.777703, -0.292611, -0.556322} },
	{/*v:*/{0.831470, -0.555570, -1.000000}, /*n:*/{0.705679, -0.438704, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{0.831469, -0.555571, 1.000000}, /*n:*/{0.675375, -0.484054, 0.556322} },
	{/*v:*/{0.923879, -0.382685, 1.000000}, /*n:*/{0.756828, -0.342998, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{0.831470, -0.555570, -1.000000}, /*n:*/{0.705679, -0.438704, -0.556322} },
	{/*v:*/{0.707107, -0.707107, -1.000000}, /*n:*/{0.631825, -0.631825, -0.448927} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{0.707106, -0.707107, 1.000000}, /*n:*/{0.498764, -0.498764, 0.708792} },
	{/*v:*/{0.831469, -0.555571, 1.000000}, /*n:*/{0.675375, -0.484054, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{0.707107, -0.707107, -1.000000}, /*n:*/{0.631825, -0.631825, -0.448927} },
	{/*v:*/{0.555570, -0.831470, -1.000000}, /*n:*/{0.438704, -0.705679, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{0.555570, -0.831470, 1.000000}, /*n:*/{0.484054, -0.675375, 0.556322} },
	{/*v:*/{0.707106, -0.707107, 1.000000}, /*n:*/{0.498764, -0.498764, 0.708792} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{0.555570, -0.831470, -1.000000}, /*n:*/{0.438704, -0.705679, -0.556322} },
	{/*v:*/{0.382683, -0.923880, -1.000000}, /*n:*/{0.292611, -0.777703, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{0.382684, -0.923880, 1.000000}, /*n:*/{0.342998, -0.756828, 0.556322} },
	{/*v:*/{0.555570, -0.831470, 1.000000}, /*n:*/{0.484054, -0.675375, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{0.382683, -0.923880, -1.000000}, /*n:*/{0.292611, -0.777703, -0.556322} },
	{/*v:*/{0.195090, -0.980785, -1.000000}, /*n:*/{0.135258, -0.819849, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{0.195091, -0.980785, 1.000000}, /*n:*/{0.188757, -0.809198, 0.556322} },
	{/*v:*/{0.382684, -0.923880, 1.000000}, /*n:*/{0.342998, -0.756828, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{0.195090, -0.980785, -1.000000}, /*n:*/{0.135258, -0.819849, -0.556322} },
	{/*v:*/{-0.000000, -1.000000, -1.000000}, /*n:*/{-0.027253, -0.830500, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{0.000001, -1.000000, 1.000000}, /*n:*/{0.027253, -0.830500, 0.556322} },
	{/*v:*/{0.195091, -0.980785, 1.000000}, /*n:*/{0.188757, -0.809198, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{-0.000000, -1.000000, -1.000000}, /*n:*/{-0.027253, -0.830500, -0.556322} },
	{/*v:*/{-0.195091, -0.980785, -1.000000}, /*n:*/{-0.188757, -0.809198, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{-0.195089, -0.980786, 1.000000}, /*n:*/{-0.135258, -0.819849, 0.556322} },
	{/*v:*/{0.000001, -1.000000, 1.000000}, /*n:*/{0.027253, -0.830500, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{-0.195091, -0.980785, -1.000000}, /*n:*/{-0.188757, -0.809198, -0.556322} },
	{/*v:*/{-0.382684, -0.923879, -1.000000}, /*n:*/{-0.342998, -0.756828, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{-0.382682, -0.923880, 1.000000}, /*n:*/{-0.292611, -0.777703, 0.556322} },
	{/*v:*/{-0.195089, -0.980786, 1.000000}, /*n:*/{-0.135258, -0.819849, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{-0.382684, -0.923879, -1.000000}, /*n:*/{-0.342998, -0.756828, -0.556322} },
	{/*v:*/{-0.555571, -0.831469, -1.000000}, /*n:*/{-0.484054, -0.675375, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{-0.555568, -0.831471, 1.000000}, /*n:*/{-0.438704, -0.705679, 0.556322} },
	{/*v:*/{-0.382682, -0.923880, 1.000000}, /*n:*/{-0.292611, -0.777703, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{-0.555571, -0.831469, -1.000000}, /*n:*/{-0.484054, -0.675375, -0.556322} },
	{/*v:*/{-0.707107, -0.707106, -1.000000}, /*n:*/{-0.606525, -0.567949, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{-0.707105, -0.707109, 1.000000}, /*n:*/{-0.567949, -0.606525, 0.556322} },
	{/*v:*/{-0.555568, -0.831471, 1.000000}, /*n:*/{-0.438704, -0.705679, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{-0.707107, -0.707106, -1.000000}, /*n:*/{-0.606525, -0.567949, -0.556322} },
	{/*v:*/{-0.831470, -0.555570, -1.000000}, /*n:*/{-0.705679, -0.438704, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{-0.831468, -0.555573, 1.000000}, /*n:*/{-0.675375, -0.484054, 0.556322} },
	{/*v:*/{-0.707105, -0.707109, 1.000000}, /*n:*/{-0.567949, -0.606525, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{-0.831470, -0.555570, -1.000000}, /*n:*/{-0.705679, -0.438704, -0.556322} },
	{/*v:*/{-0.923880, -0.382683, -1.000000}, /*n:*/{-0.777703, -0.292611, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{-0.923878, -0.382686, 1.000000}, /*n:*/{-0.756828, -0.342998, 0.556322} },
	{/*v:*/{-0.831468, -0.555573, 1.000000}, /*n:*/{-0.675375, -0.484054, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{-0.923880, -0.382683, -1.000000}, /*n:*/{-0.777703, -0.292611, -0.556322} },
	{/*v:*/{-0.980785, -0.195089, -1.000000}, /*n:*/{-0.819849, -0.135258, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{-0.980785, -0.195094, 1.000000}, /*n:*/{-0.809198, -0.188757, 0.556322} },
	{/*v:*/{-0.923878, -0.382686, 1.000000}, /*n:*/{-0.756828, -0.342998, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{-0.980785, -0.195089, -1.000000}, /*n:*/{-0.819849, -0.135258, -0.556322} },
	{/*v:*/{-1.000000, 0.000001, -1.000000}, /*n:*/{-0.830500, 0.027253, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{-1.000000, -0.000004, 1.000000}, /*n:*/{-0.830500, -0.027253, 0.556322} },
	{/*v:*/{-0.980785, -0.195094, 1.000000}, /*n:*/{-0.809198, -0.188757, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{-1.000000, 0.000001, -1.000000}, /*n:*/{-0.830500, 0.027253, -0.556322} },
	{/*v:*/{-0.980785, 0.195091, -1.000000}, /*n:*/{-0.809198, 0.188757, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{-0.980786, 0.195086, 1.000000}, /*n:*/{-0.819849, 0.135258, 0.556322} },
	{/*v:*/{-1.000000, -0.000004, 1.000000}, /*n:*/{-0.830500, -0.027253, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{-0.980785, 0.195091, -1.000000}, /*n:*/{-0.809198, 0.188757, -0.556322} },
	{/*v:*/{-0.923879, 0.382684, -1.000000}, /*n:*/{-0.756828, 0.342998, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{-0.923881, 0.382679, 1.000000}, /*n:*/{-0.777703, 0.292611, 0.556322} },
	{/*v:*/{-0.980786, 0.195086, 1.000000}, /*n:*/{-0.819849, 0.135258, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{-0.923879, 0.382684, -1.000000}, /*n:*/{-0.756828, 0.342998, -0.556322} },
	{/*v:*/{-0.831469, 0.555571, -1.000000}, /*n:*/{-0.675375, 0.484054, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{-0.831473, 0.555566, 1.000000}, /*n:*/{-0.705679, 0.438704, 0.556322} },
	{/*v:*/{-0.923881, 0.382679, 1.000000}, /*n:*/{-0.777703, 0.292611, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{-0.831469, 0.555571, -1.000000}, /*n:*/{-0.675375, 0.484054, -0.556322} },
	{/*v:*/{-0.707106, 0.707108, -1.000000}, /*n:*/{-0.567949, 0.606525, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{-0.707111, 0.707103, 1.000000}, /*n:*/{-0.606525, 0.567949, 0.556322} },
	{/*v:*/{-0.831473, 0.555566, 1.000000}, /*n:*/{-0.705679, 0.438704, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{-0.707106, 0.707108, -1.000000}, /*n:*/{-0.567949, 0.606525, -0.556322} },
	{/*v:*/{-0.555569, 0.831470, -1.000000}, /*n:*/{-0.438704, 0.705679, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{-0.555575, 0.831466, 1.000000}, /*n:*/{-0.484054, 0.675375, 0.556322} },
	{/*v:*/{-0.707111, 0.707103, 1.000000}, /*n:*/{-0.606525, 0.567949, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{-0.555569, 0.831470, -1.000000}, /*n:*/{-0.438704, 0.705679, -0.556322} },
	{/*v:*/{-0.382682, 0.923880, -1.000000}, /*n:*/{-0.292611, 0.777703, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{-0.382689, 0.923877, 1.000000}, /*n:*/{-0.342998, 0.756828, 0.556322} },
	{/*v:*/{-0.555575, 0.831466, 1.000000}, /*n:*/{-0.484054, 0.675375, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{-0.382682, 0.923880, -1.000000}, /*n:*/{-0.292611, 0.777703, -0.556322} },
	{/*v:*/{-0.195089, 0.980786, -1.000000}, /*n:*/{-0.135258, 0.819849, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{-0.195097, 0.980784, 1.000000}, /*n:*/{-0.188757, 0.809198, 0.556322} },
	{/*v:*/{-0.382689, 0.923877, 1.000000}, /*n:*/{-0.342998, 0.756828, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{-0.195089, 0.980786, -1.000000}, /*n:*/{-0.135258, 0.819849, -0.556322} },
	{/*v:*/{0.000002, 1.000000, -1.000000}, /*n:*/{0.027253, 0.830500, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{-0.000007, 1.000000, 1.000000}, /*n:*/{-0.027253, 0.830500, 0.556322} },
	{/*v:*/{-0.195097, 0.980784, 1.000000}, /*n:*/{-0.188757, 0.809198, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{0.000002, 1.000000, -1.000000}, /*n:*/{0.027253, 0.830500, -0.556322} },
	{/*v:*/{0.195092, 0.980785, -1.000000}, /*n:*/{0.188757, 0.809198, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{0.195083, 0.980787, 1.000000}, /*n:*/{0.135258, 0.819849, 0.556322} },
	{/*v:*/{-0.000007, 1.000000, 1.000000}, /*n:*/{-0.027253, 0.830500, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{0.195092, 0.980785, -1.000000}, /*n:*/{0.188757, 0.809198, -0.556322} },
	{/*v:*/{0.382685, 0.923879, -1.000000}, /*n:*/{0.342998, 0.756828, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{0.382676, 0.923883, 1.000000}, /*n:*/{0.292611, 0.777703, 0.556322} },
	{/*v:*/{0.195083, 0.980787, 1.000000}, /*n:*/{0.135258, 0.819849, 0.556322} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{0.382685, 0.923879, -1.000000}, /*n:*/{0.342998, 0.756828, -0.556322} },
	{/*v:*/{0.555572, 0.831469, -1.000000}, /*n:*/{0.484054, 0.675375, -0.556322} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{0.555563, 0.831474, 1.000000}, /*n:*/{0.438704, 0.705679, 0.556322} },
	{/*v:*/{0.382676, 0.923883, 1.000000}, /*n:*/{0.292611, 0.777703, 0.556322} },
	{/*v:*/{0.555572, 0.831469, -1.000000}, /*n:*/{0.484054, 0.675375, -0.556322} },
	{/*v:*/{0.707107, 0.707107, -1.000000}, /*n:*/{0.498764, 0.498764, -0.708792} },
	{/*v:*/{0.000000, 0.000000, -1.000000}, /*n:*/{0.000000, 0.000000, -1.000000} },
	{/*v:*/{0.000000, 0.000000, 1.000000}, /*n:*/{0.000000, 0.000000, 1.000000} },
	{/*v:*/{0.707108, 0.707105, 1.000000}, /*n:*/{0.631825, 0.631825, 0.448927} },
	{/*v:*/{0.555563, 0.831474, 1.000000}, /*n:*/{0.438704, 0.705679, 0.556322} },
	{/*v:*/{0.707108, 0.707105, 1.000000}, /*n:*/{0.631825, 0.631825, 0.448927} },
	{/*v:*/{0.707107, 0.707107, -1.000000}, /*n:*/{0.498764, 0.498764, -0.708792} },
	{/*v:*/{0.555572, 0.831469, -1.000000}, /*n:*/{0.484054, 0.675375, -0.556322} },
	{/*v:*/{0.707108, 0.707105, 1.000000}, /*n:*/{0.631825, 0.631825, 0.448927} },
	{/*v:*/{0.555572, 0.831469, -1.000000}, /*n:*/{0.484054, 0.675375, -0.556322} },
	{/*v:*/{0.555563, 0.831474, 1.000000}, /*n:*/{0.438704, 0.705679, 0.556322} },
	{/*v:*/{0.382685, 0.923879, -1.000000}, /*n:*/{0.342998, 0.756828, -0.556322} },
	{/*v:*/{0.382676, 0.923883, 1.000000}, /*n:*/{0.292611, 0.777703, 0.556322} },
	{/*v:*/{0.555563, 0.831474, 1.000000}, /*n:*/{0.438704, 0.705679, 0.556322} },
	{/*v:*/{0.382685, 0.923879, -1.000000}, /*n:*/{0.342998, 0.756828, -0.556322} },
	{/*v:*/{0.555563, 0.831474, 1.000000}, /*n:*/{0.438704, 0.705679, 0.556322} },
	{/*v:*/{0.555572, 0.831469, -1.000000}, /*n:*/{0.484054, 0.675375, -0.556322} },
	{/*v:*/{0.195092, 0.980785, -1.000000}, /*n:*/{0.188757, 0.809198, -0.556322} },
	{/*v:*/{0.195083, 0.980787, 1.000000}, /*n:*/{0.135258, 0.819849, 0.556322} },
	{/*v:*/{0.382676, 0.923883, 1.000000}, /*n:*/{0.292611, 0.777703, 0.556322} },
	{/*v:*/{0.195092, 0.980785, -1.000000}, /*n:*/{0.188757, 0.809198, -0.556322} },
	{/*v:*/{0.382676, 0.923883, 1.000000}, /*n:*/{0.292611, 0.777703, 0.556322} },
	{/*v:*/{0.382685, 0.923879, -1.000000}, /*n:*/{0.342998, 0.756828, -0.556322} },
	{/*v:*/{0.000002, 1.000000, -1.000000}, /*n:*/{0.027253, 0.830500, -0.556322} },
	{/*v:*/{-0.000007, 1.000000, 1.000000}, /*n:*/{-0.027253, 0.830500, 0.556322} },
	{/*v:*/{0.195083, 0.980787, 1.000000}, /*n:*/{0.135258, 0.819849, 0.556322} },
	{/*v:*/{0.000002, 1.000000, -1.000000}, /*n:*/{0.027253, 0.830500, -0.556322} },
	{/*v:*/{0.195083, 0.980787, 1.000000}, /*n:*/{0.135258, 0.819849, 0.556322} },
	{/*v:*/{0.195092, 0.980785, -1.000000}, /*n:*/{0.188757, 0.809198, -0.556322} },
	{/*v:*/{-0.195089, 0.980786, -1.000000}, /*n:*/{-0.135258, 0.819849, -0.556322} },
	{/*v:*/{-0.195097, 0.980784, 1.000000}, /*n:*/{-0.188757, 0.809198, 0.556322} },
	{/*v:*/{-0.000007, 1.000000, 1.000000}, /*n:*/{-0.027253, 0.830500, 0.556322} },
	{/*v:*/{-0.195089, 0.980786, -1.000000}, /*n:*/{-0.135258, 0.819849, -0.556322} },
	{/*v:*/{-0.000007, 1.000000, 1.000000}, /*n:*/{-0.027253, 0.830500, 0.556322} },
	{/*v:*/{0.000002, 1.000000, -1.000000}, /*n:*/{0.027253, 0.830500, -0.556322} },
	{/*v:*/{-0.382682, 0.923880, -1.000000}, /*n:*/{-0.292611, 0.777703, -0.556322} },
	{/*v:*/{-0.382689, 0.923877, 1.000000}, /*n:*/{-0.342998, 0.756828, 0.556322} },
	{/*v:*/{-0.195097, 0.980784, 1.000000}, /*n:*/{-0.188757, 0.809198, 0.556322} },
	{/*v:*/{-0.382682, 0.923880, -1.000000}, /*n:*/{-0.292611, 0.777703, -0.556322} },
	{/*v:*/{-0.195097, 0.980784, 1.000000}, /*n:*/{-0.188757, 0.809198, 0.556322} },
	{/*v:*/{-0.195089, 0.980786, -1.000000}, /*n:*/{-0.135258, 0.819849, -0.556322} },
	{/*v:*/{-0.555569, 0.831470, -1.000000}, /*n:*/{-0.438704, 0.705679, -0.556322} },
	{/*v:*/{-0.555575, 0.831466, 1.000000}, /*n:*/{-0.484054, 0.675375, 0.556322} },
	{/*v:*/{-0.382689, 0.923877, 1.000000}, /*n:*/{-0.342998, 0.756828, 0.556322} },
	{/*v:*/{-0.555569, 0.831470, -1.000000}, /*n:*/{-0.438704, 0.705679, -0.556322} },
	{/*v:*/{-0.382689, 0.923877, 1.000000}, /*n:*/{-0.342998, 0.756828, 0.556322} },
	{/*v:*/{-0.382682, 0.923880, -1.000000}, /*n:*/{-0.292611, 0.777703, -0.556322} },
	{/*v:*/{-0.707106, 0.707108, -1.000000}, /*n:*/{-0.567949, 0.606525, -0.556322} },
	{/*v:*/{-0.707111, 0.707103, 1.000000}, /*n:*/{-0.606525, 0.567949, 0.556322} },
	{/*v:*/{-0.555575, 0.831466, 1.000000}, /*n:*/{-0.484054, 0.675375, 0.556322} },
	{/*v:*/{-0.707106, 0.707108, -1.000000}, /*n:*/{-0.567949, 0.606525, -0.556322} },
	{/*v:*/{-0.555575, 0.831466, 1.000000}, /*n:*/{-0.484054, 0.675375, 0.556322} },
	{/*v:*/{-0.555569, 0.831470, -1.000000}, /*n:*/{-0.438704, 0.705679, -0.556322} },
	{/*v:*/{-0.831469, 0.555571, -1.000000}, /*n:*/{-0.675375, 0.484054, -0.556322} },
	{/*v:*/{-0.831473, 0.555566, 1.000000}, /*n:*/{-0.705679, 0.438704, 0.556322} },
	{/*v:*/{-0.707111, 0.707103, 1.000000}, /*n:*/{-0.606525, 0.567949, 0.556322} },
	{/*v:*/{-0.831469, 0.555571, -1.000000}, /*n:*/{-0.675375, 0.484054, -0.556322} },
	{/*v:*/{-0.707111, 0.707103, 1.000000}, /*n:*/{-0.606525, 0.567949, 0.556322} },
	{/*v:*/{-0.707106, 0.707108, -1.000000}, /*n:*/{-0.567949, 0.606525, -0.556322} },
	{/*v:*/{-0.923879, 0.382684, -1.000000}, /*n:*/{-0.756828, 0.342998, -0.556322} },
	{/*v:*/{-0.923881, 0.382679, 1.000000}, /*n:*/{-0.777703, 0.292611, 0.556322} },
	{/*v:*/{-0.831473, 0.555566, 1.000000}, /*n:*/{-0.705679, 0.438704, 0.556322} },
	{/*v:*/{-0.923879, 0.382684, -1.000000}, /*n:*/{-0.756828, 0.342998, -0.556322} },
	{/*v:*/{-0.831473, 0.555566, 1.000000}, /*n:*/{-0.705679, 0.438704, 0.556322} },
	{/*v:*/{-0.831469, 0.555571, -1.000000}, /*n:*/{-0.675375, 0.484054, -0.556322} },
	{/*v:*/{-0.980785, 0.195091, -1.000000}, /*n:*/{-0.809198, 0.188757, -0.556322} },
	{/*v:*/{-0.980786, 0.195086, 1.000000}, /*n:*/{-0.819849, 0.135258, 0.556322} },
	{/*v:*/{-0.923881, 0.382679, 1.000000}, /*n:*/{-0.777703, 0.292611, 0.556322} },
	{/*v:*/{-0.980785, 0.195091, -1.000000}, /*n:*/{-0.809198, 0.188757, -0.556322} },
	{/*v:*/{-0.923881, 0.382679, 1.000000}, /*n:*/{-0.777703, 0.292611, 0.556322} },
	{/*v:*/{-0.923879, 0.382684, -1.000000}, /*n:*/{-0.756828, 0.342998, -0.556322} },
	{/*v:*/{-1.000000, 0.000001, -1.000000}, /*n:*/{-0.830500, 0.027253, -0.556322} },
	{/*v:*/{-1.000000, -0.000004, 1.000000}, /*n:*/{-0.830500, -0.027253, 0.556322} },
	{/*v:*/{-0.980786, 0.195086, 1.000000}, /*n:*/{-0.819849, 0.135258, 0.556322} },
	{/*v:*/{-1.000000, 0.000001, -1.000000}, /*n:*/{-0.830500, 0.027253, -0.556322} },
	{/*v:*/{-0.980786, 0.195086, 1.000000}, /*n:*/{-0.819849, 0.135258, 0.556322} },
	{/*v:*/{-0.980785, 0.195091, -1.000000}, /*n:*/{-0.809198, 0.188757, -0.556322} },
	{/*v:*/{-0.980785, -0.195089, -1.000000}, /*n:*/{-0.819849, -0.135258, -0.556322} },
	{/*v:*/{-0.980785, -0.195094, 1.000000}, /*n:*/{-0.809198, -0.188757, 0.556322} },
	{/*v:*/{-1.000000, -0.000004, 1.000000}, /*n:*/{-0.830500, -0.027253, 0.556322} },
	{/*v:*/{-0.980785, -0.195089, -1.000000}, /*n:*/{-0.819849, -0.135258, -0.556322} },
	{/*v:*/{-1.000000, -0.000004, 1.000000}, /*n:*/{-0.830500, -0.027253, 0.556322} },
	{/*v:*/{-1.000000, 0.000001, -1.000000}, /*n:*/{-0.830500, 0.027253, -0.556322} },
	{/*v:*/{-0.923880, -0.382683, -1.000000}, /*n:*/{-0.777703, -0.292611, -0.556322} },
	{/*v:*/{-0.923878, -0.382686, 1.000000}, /*n:*/{-0.756828, -0.342998, 0.556322} },
	{/*v:*/{-0.980785, -0.195094, 1.000000}, /*n:*/{-0.809198, -0.188757, 0.556322} },
	{/*v:*/{-0.923880, -0.382683, -1.000000}, /*n:*/{-0.777703, -0.292611, -0.556322} },
	{/*v:*/{-0.980785, -0.195094, 1.000000}, /*n:*/{-0.809198, -0.188757, 0.556322} },
	{/*v:*/{-0.980785, -0.195089, -1.000000}, /*n:*/{-0.819849, -0.135258, -0.556322} },
	{/*v:*/{-0.831470, -0.555570, -1.000000}, /*n:*/{-0.705679, -0.438704, -0.556322} },
	{/*v:*/{-0.831468, -0.555573, 1.000000}, /*n:*/{-0.675375, -0.484054, 0.556322} },
	{/*v:*/{-0.923878, -0.382686, 1.000000}, /*n:*/{-0.756828, -0.342998, 0.556322} },
	{/*v:*/{-0.831470, -0.555570, -1.000000}, /*n:*/{-0.705679, -0.438704, -0.556322} },
	{/*v:*/{-0.923878, -0.382686, 1.000000}, /*n:*/{-0.756828, -0.342998, 0.556322} },
	{/*v:*/{-0.923880, -0.382683, -1.000000}, /*n:*/{-0.777703, -0.292611, -0.556322} },
	{/*v:*/{-0.707107, -0.707106, -1.000000}, /*n:*/{-0.606525, -0.567949, -0.556322} },
	{/*v:*/{-0.707105, -0.707109, 1.000000}, /*n:*/{-0.567949, -0.606525, 0.556322} },
	{/*v:*/{-0.831468, -0.555573, 1.000000}, /*n:*/{-0.675375, -0.484054, 0.556322} },
	{/*v:*/{-0.707107, -0.707106, -1.000000}, /*n:*/{-0.606525, -0.567949, -0.556322} },
	{/*v:*/{-0.831468, -0.555573, 1.000000}, /*n:*/{-0.675375, -0.484054, 0.556322} },
	{/*v:*/{-0.831470, -0.555570, -1.000000}, /*n:*/{-0.705679, -0.438704, -0.556322} },
	{/*v:*/{-0.555571, -0.831469, -1.000000}, /*n:*/{-0.484054, -0.675375, -0.556322} },
	{/*v:*/{-0.555568, -0.831471, 1.000000}, /*n:*/{-0.438704, -0.705679, 0.556322} },
	{/*v:*/{-0.707105, -0.707109, 1.000000}, /*n:*/{-0.567949, -0.606525, 0.556322} },
	{/*v:*/{-0.555571, -0.831469, -1.000000}, /*n:*/{-0.484054, -0.675375, -0.556322} },
	{/*v:*/{-0.707105, -0.707109, 1.000000}, /*n:*/{-0.567949, -0.606525, 0.556322} },
	{/*v:*/{-0.707107, -0.707106, -1.000000}, /*n:*/{-0.606525, -0.567949, -0.556322} },
	{/*v:*/{-0.382684, -0.923879, -1.000000}, /*n:*/{-0.342998, -0.756828, -0.556322} },
	{/*v:*/{-0.382682, -0.923880, 1.000000}, /*n:*/{-0.292611, -0.777703, 0.556322} },
	{/*v:*/{-0.555568, -0.831471, 1.000000}, /*n:*/{-0.438704, -0.705679, 0.556322} },
	{/*v:*/{-0.382684, -0.923879, -1.000000}, /*n:*/{-0.342998, -0.756828, -0.556322} },
	{/*v:*/{-0.555568, -0.831471, 1.000000}, /*n:*/{-0.438704, -0.705679, 0.556322} },
	{/*v:*/{-0.555571, -0.831469, -1.000000}, /*n:*/{-0.484054, -0.675375, -0.556322} },
	{/*v:*/{-0.195091, -0.980785, -1.000000}, /*n:*/{-0.188757, -0.809198, -0.556322} },
	{/*v:*/{-0.195089, -0.980786, 1.000000}, /*n:*/{-0.135258, -0.819849, 0.556322} },
	{/*v:*/{-0.382682, -0.923880, 1.000000}, /*n:*/{-0.292611, -0.777703, 0.556322} },
	{/*v:*/{-0.195091, -0.980785, -1.000000}, /*n:*/{-0.188757, -0.809198, -0.556322} },
	{/*v:*/{-0.382682, -0.923880, 1.000000}, /*n:*/{-0.292611, -0.777703, 0.556322} },
	{/*v:*/{-0.382684, -0.923879, -1.000000}, /*n:*/{-0.342998, -0.756828, -0.556322} },
	{/*v:*/{-0.000000, -1.000000, -1.000000}, /*n:*/{-0.027253, -0.830500, -0.556322} },
	{/*v:*/{0.000001, -1.000000, 1.000000}, /*n:*/{0.027253, -0.830500, 0.556322} },
	{/*v:*/{-0.195089, -0.980786, 1.000000}, /*n:*/{-0.135258, -0.819849, 0.556322} },
	{/*v:*/{-0.000000, -1.000000, -1.000000}, /*n:*/{-0.027253, -0.830500, -0.556322} },
	{/*v:*/{-0.195089, -0.980786, 1.000000}, /*n:*/{-0.135258, -0.819849, 0.556322} },
	{/*v:*/{-0.195091, -0.980785, -1.000000}, /*n:*/{-0.188757, -0.809198, -0.556322} },
	{/*v:*/{0.195090, -0.980785, -1.000000}, /*n:*/{0.135258, -0.819849, -0.556322} },
	{/*v:*/{0.195091, -0.980785, 1.000000}, /*n:*/{0.188757, -0.809198, 0.556322} },
	{/*v:*/{0.000001, -1.000000, 1.000000}, /*n:*/{0.027253, -0.830500, 0.556322} },
	{/*v:*/{0.195090, -0.980785, -1.000000}, /*n:*/{0.135258, -0.819849, -0.556322} },
	{/*v:*/{0.000001, -1.000000, 1.000000}, /*n:*/{0.027253, -0.830500, 0.556322} },
	{/*v:*/{-0.000000, -1.000000, -1.000000}, /*n:*/{-0.027253, -0.830500, -0.556322} },
	{/*v:*/{0.382683, -0.923880, -1.000000}, /*n:*/{0.292611, -0.777703, -0.556322} },
	{/*v:*/{0.382684, -0.923880, 1.000000}, /*n:*/{0.342998, -0.756828, 0.556322} },
	{/*v:*/{0.195091, -0.980785, 1.000000}, /*n:*/{0.188757, -0.809198, 0.556322} },
	{/*v:*/{0.382683, -0.923880, -1.000000}, /*n:*/{0.292611, -0.777703, -0.556322} },
	{/*v:*/{0.195091, -0.980785, 1.000000}, /*n:*/{0.188757, -0.809198, 0.556322} },
	{/*v:*/{0.195090, -0.980785, -1.000000}, /*n:*/{0.135258, -0.819849, -0.556322} },
	{/*v:*/{0.555570, -0.831470, -1.000000}, /*n:*/{0.438704, -0.705679, -0.556322} },
	{/*v:*/{0.555570, -0.831470, 1.000000}, /*n:*/{0.484054, -0.675375, 0.556322} },
	{/*v:*/{0.382684, -0.923880, 1.000000}, /*n:*/{0.342998, -0.756828, 0.556322} },
	{/*v:*/{0.555570, -0.831470, -1.000000}, /*n:*/{0.438704, -0.705679, -0.556322} },
	{/*v:*/{0.382684, -0.923880, 1.000000}, /*n:*/{0.342998, -0.756828, 0.556322} },
	{/*v:*/{0.382683, -0.923880, -1.000000}, /*n:*/{0.292611, -0.777703, -0.556322} },
	{/*v:*/{0.707107, -0.707107, -1.000000}, /*n:*/{0.631825, -0.631825, -0.448927} },
	{/*v:*/{0.707106, -0.707107, 1.000000}, /*n:*/{0.498764, -0.498764, 0.708792} },
	{/*v:*/{0.555570, -0.831470, 1.000000}, /*n:*/{0.484054, -0.675375, 0.556322} },
	{/*v:*/{0.707107, -0.707107, -1.000000}, /*n:*/{0.631825, -0.631825, -0.448927} },
	{/*v:*/{0.555570, -0.831470, 1.000000}, /*n:*/{0.484054, -0.675375, 0.556322} },
	{/*v:*/{0.555570, -0.831470, -1.000000}, /*n:*/{0.438704, -0.705679, -0.556322} },
	{/*v:*/{0.831470, -0.555570, -1.000000}, /*n:*/{0.705679, -0.438704, -0.556322} },
	{/*v:*/{0.831469, -0.555571, 1.000000}, /*n:*/{0.675375, -0.484054, 0.556322} },
	{/*v:*/{0.707107, -0.707107, -1.000000}, /*n:*/{0.631825, -0.631825, -0.448927} },
	{/*v:*/{0.831469, -0.555571, 1.000000}, /*n:*/{0.675375, -0.484054, 0.556322} },
	{/*v:*/{0.707106, -0.707107, 1.000000}, /*n:*/{0.498764, -0.498764, 0.708792} },
	{/*v:*/{0.707107, -0.707107, -1.000000}, /*n:*/{0.631825, -0.631825, -0.448927} },
	{/*v:*/{0.923880, -0.382683, -1.000000}, /*n:*/{0.777703, -0.292611, -0.556322} },
	{/*v:*/{0.923879, -0.382685, 1.000000}, /*n:*/{0.756828, -0.342998, 0.556322} },
	{/*v:*/{0.831470, -0.555570, -1.000000}, /*n:*/{0.705679, -0.438704, -0.556322} },
	{/*v:*/{0.923879, -0.382685, 1.000000}, /*n:*/{0.756828, -0.342998, 0.556322} },
	{/*v:*/{0.831469, -0.555571, 1.000000}, /*n:*/{0.675375, -0.484054, 0.556322} },
	{/*v:*/{0.831470, -0.555570, -1.000000}, /*n:*/{0.705679, -0.438704, -0.556322} },
	{/*v:*/{0.980785, -0.195090, -1.000000}, /*n:*/{0.819849, -0.135258, -0.556322} },
	{/*v:*/{0.980785, -0.195092, 1.000000}, /*n:*/{0.809198, -0.188757, 0.556322} },
	{/*v:*/{0.923880, -0.382683, -1.000000}, /*n:*/{0.777703, -0.292611, -0.556322} },
	{/*v:*/{0.980785, -0.195092, 1.000000}, /*n:*/{0.809198, -0.188757, 0.556322} },
	{/*v:*/{0.923879, -0.382685, 1.000000}, /*n:*/{0.756828, -0.342998, 0.556322} },
	{/*v:*/{0.923880, -0.382683, -1.000000}, /*n:*/{0.777703, -0.292611, -0.556322} },
	{/*v:*/{1.000000, 0.000000, -1.000000}, /*n:*/{0.830500, 0.027253, -0.556322} },
	{/*v:*/{1.000000, -0.000002, 1.000000}, /*n:*/{0.830500, -0.027253, 0.556322} },
	{/*v:*/{0.980785, -0.195090, -1.000000}, /*n:*/{0.819849, -0.135258, -0.556322} },
	{/*v:*/{1.000000, -0.000002, 1.000000}, /*n:*/{0.830500, -0.027253, 0.556322} },
	{/*v:*/{0.980785, -0.195092, 1.000000}, /*n:*/{0.809198, -0.188757, 0.556322} },
	{/*v:*/{0.980785, -0.195090, -1.000000}, /*n:*/{0.819849, -0.135258, -0.556322} },
	{/*v:*/{0.980785, 0.195090, -1.000000}, /*n:*/{0.809198, 0.188757, -0.556322} },
	{/*v:*/{0.980786, 0.195088, 1.000000}, /*n:*/{0.819849, 0.135258, 0.556322} },
	{/*v:*/{1.000000, 0.000000, -1.000000}, /*n:*/{0.830500, 0.027253, -0.556322} },
	{/*v:*/{0.980786, 0.195088, 1.000000}, /*n:*/{0.819849, 0.135258, 0.556322} },
	{/*v:*/{1.000000, -0.000002, 1.000000}, /*n:*/{0.830500, -0.027253, 0.556322} },
	{/*v:*/{1.000000, 0.000000, -1.000000}, /*n:*/{0.830500, 0.027253, -0.556322} },
	{/*v:*/{0.923880, 0.382683, -1.000000}, /*n:*/{0.756828, 0.342998, -0.556322} },
	{/*v:*/{0.923880, 0.382682, 1.000000}, /*n:*/{0.777703, 0.292611, 0.556322} },
	{/*v:*/{0.980785, 0.195090, -1.000000}, /*n:*/{0.809198, 0.188757, -0.556322} },
	{/*v:*/{0.923880, 0.382682, 1.000000}, /*n:*/{0.777703, 0.292611, 0.556322} },
	{/*v:*/{0.980786, 0.195088, 1.000000}, /*n:*/{0.819849, 0.135258, 0.556322} },
	{/*v:*/{0.980785, 0.195090, -1.000000}, /*n:*/{0.809198, 0.188757, -0.556322} },
	{/*v:*/{0.831470, 0.555570, -1.000000}, /*n:*/{0.675375, 0.484054, -0.556322} },
	{/*v:*/{0.831471, 0.555569, 1.000000}, /*n:*/{0.705679, 0.438704, 0.556322} },
	{/*v:*/{0.923880, 0.382683, -1.000000}, /*n:*/{0.756828, 0.342998, -0.556322} },
	{/*v:*/{0.831471, 0.555569, 1.000000}, /*n:*/{0.705679, 0.438704, 0.556322} },
	{/*v:*/{0.923880, 0.382682, 1.000000}, /*n:*/{0.777703, 0.292611, 0.556322} },
	{/*v:*/{0.923880, 0.382683, -1.000000}, /*n:*/{0.756828, 0.342998, -0.556322} },
	{/*v:*/{0.707107, 0.707107, -1.000000}, /*n:*/{0.498764, 0.498764, -0.708792} },
	{/*v:*/{0.707108, 0.707105, 1.000000}, /*n:*/{0.631825, 0.631825, 0.448927} },
	{/*v:*/{0.831470, 0.555570, -1.000000}, /*n:*/{0.675375, 0.484054, -0.556322} },
	{/*v:*/{0.707108, 0.707105, 1.000000}, /*n:*/{0.631825, 0.631825, 0.448927} },
	{/*v:*/{0.831471, 0.555569, 1.000000}, /*n:*/{0.705679, 0.438704, 0.556322} },
	{/*v:*/{0.831470, 0.555570, -1.000000}, /*n:*/{0.675375, 0.484054, -0.556322} },
};

#define cylinderNumberOfVertices	384
// Drawing Code:
// glEnableClientState(GL_VERTEX_ARRAY);
// glEnableClientState(GL_NORMAL_ARRAY);
// glVertexPointer(3, GL_FLOAT, sizeof(VERTEX_DATA_3D), &cylinderVertexData[0].vertex);
// glNormalPointer(GL_FLOAT, sizeof(VERTEX_DATA_3D), &cylinderVertexData[0].normal);
// glDrawArrays(GL_TRIANGLES, 0, cylinderNumberOfVertices);
// glDisableClientState(GL_VERTEX_ARRAY);
// glDisableClientState(GL_NORMAL_ARRAY);


#endif
