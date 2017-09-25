class DesplazadorTexto
!!!136827.cpp!!!	DesplazadorTexto(in nTexto : Texto, inout nSonido : Sonido, in nVelocidad : long)
  texto = nTexto;
  sonido = nSonido;
  velocidad = nVelocidad;
  posicionX = 0;
  posicionY = 0;
!!!136955.cpp!!!	getTexto() : Texto
  return texto;
!!!137083.cpp!!!	getSonido() : Sonido
  return sonido;
!!!137211.cpp!!!	getVelocidad() : long
  return velocidad;
!!!137339.cpp!!!	isActivo() : bool
  return activo;
!!!137595.cpp!!!	isMuted() : bool
  return mute;
!!!137723.cpp!!!	setTexto(in nTexto : Texto) : void
  texto = nTexto;
!!!137851.cpp!!!	setSonido(inout nSonido : Sonido) : void
  sonido = nSonido;
!!!137979.cpp!!!	setVelocidad(in nVelocidad : long) : void
  velocidad = nVelocidad;
!!!138363.cpp!!!	iniciar() : void
  activo = true;
  thread desplazador (&DesplazadorTexto::desplazar, this);
  desplazador.detach();
!!!138491.cpp!!!	desplazar() : void
  Texto tempTexto = texto;
  string textoActual;

  for (int i = 0; i < tempTexto.getTexto().length(); i++) {
    textoActual = "";

    for (int j = 0; j < i; j++) {
      textoActual += tempTexto.getTexto()[j];
    }

    texto.setTexto(textoActual);
    texto.refrescar();

    if (tempTexto.getTexto()[i] != ' ' && mute == false) {
      sonido->reproducir();
    }

    this_thread::sleep_for(chrono::milliseconds(velocidad));
  }

  texto = tempTexto;
  activo = false;
!!!138619.cpp!!!	toSuperficie() : SDL_Surface
  if (visible) {
    return texto.toSuperficie();
  }else{
    return NULL;
  }
!!!138747.cpp!!!	refrescar() : bool
  texto.refrescar();
!!!137467.cpp!!!	isVisible() : bool
  return visible;
!!!138107.cpp!!!	setVisible(in nVisible : bool) : void
  visible = nVisible;
!!!138235.cpp!!!	setMute(in nMute : bool) : void
  mute = nMute;
