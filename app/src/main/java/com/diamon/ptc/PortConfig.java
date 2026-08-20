package com.diamon.ptc;

/**
 * Configuración de un puerto/arquitectura SDCC.
 * Define todos los parámetros necesarios para compilar y editar código
 * para una familia de microcontroladores específica.
 */
public class PortConfig {

    /** Nombre visible en el spinner de arquitectura */
    public final String familyName;

    /** Flag -m<arch> principal para SDCC (ej: "pic14", "mcs51", "z80") */
    public final String sdccArch;

    /** Sub-arquitecturas dentro de la misma familia (ej: z80 tiene z80, z180, z80n, ez80_z80, r800) */
    public final String[] subArchitectures;

    /** Labels visibles para las sub-arquitecturas (misma longitud que subArchitectures) */
    public final String[] subArchLabels;

    /** true si esta familia soporta modo ASM con GPUTILS (solo PIC) */
    public final boolean hasAsmMode;

    /** true si se debe usar flag -p<processor> (PIC y MCS-51 con headers específicos) */
    public final boolean hasProcessorFlag;

    /** Subdirectorio dentro de include/ donde buscar headers .h para poblar spinner de dispositivos (null = sin spinner) */
    public final String headerIncludeDir;

    /** Extensión de los headers para detectar dispositivos (.h, .inc) */
    public final String headerExtension;

    /** Prefijo a eliminar de los nombres de archivo para obtener el nombre del dispositivo (ej: "p" para PIC) */
    public final String headerPrefix;

    /** true si se deben convertir nombres de dispositivo a mayúsculas */
    public final boolean headerUpperCase;

    /** true si se debe usar --use-non-free (solo para PIC) */
    public final boolean useNonFree;

    /** Código C de ejemplo por defecto */
    public final String defaultCCode;

    /** Código ASM de ejemplo por defecto (null si no aplica) */
    public final String defaultAsmCode;

    /** Hint para el editor en modo C */
    public final String editorHintC;

    /** Hint para el editor en modo ASM (null si no aplica) */
    public final String editorHintAsm;

    /** Nombre por defecto para dispositivo si no se detecta ninguno */
    public final String defaultDevice;

    /** Formato de salida para el linker (--out-fmt-ihx, etc.) */
    public final String outputFormat;

    /** Nombre del binario simulador ucSim/s51 correspondiente (ej: "s51", "ucsim_z80", "ucsim_stm8") */
    public final String simulatorBinary;

    private PortConfig(Builder builder) {
        this.familyName = builder.familyName;
        this.sdccArch = builder.sdccArch;
        this.subArchitectures = builder.subArchitectures;
        this.subArchLabels = builder.subArchLabels;
        this.hasAsmMode = builder.hasAsmMode;
        this.hasProcessorFlag = builder.hasProcessorFlag;
        this.headerIncludeDir = builder.headerIncludeDir;
        this.headerExtension = builder.headerExtension;
        this.headerPrefix = builder.headerPrefix;
        this.headerUpperCase = builder.headerUpperCase;
        this.useNonFree = builder.useNonFree;
        this.defaultCCode = builder.defaultCCode;
        this.defaultAsmCode = builder.defaultAsmCode;
        this.editorHintC = builder.editorHintC;
        this.editorHintAsm = builder.editorHintAsm;
        this.defaultDevice = builder.defaultDevice;
        this.outputFormat = builder.outputFormat;
        this.simulatorBinary = builder.simulatorBinary;
    }

    /** Resuelve la arquitectura SDCC real para un sub-índice del spinner */
    public String resolveArch(int subIndex) {
        if (subArchitectures != null && subIndex >= 0 && subIndex < subArchitectures.length) {
            return subArchitectures[subIndex];
        }
        return sdccArch;
    }

    /** Devuelve true si esta familia tiene sub-arquitecturas seleccionables */
    public boolean hasSubArchitectures() {
        return subArchitectures != null && subArchitectures.length > 1;
    }

    /** Devuelve true si tiene un spinner de dispositivos (headers) */
    public boolean hasDeviceSelector() {
        return headerIncludeDir != null;
    }

    public static class Builder {
        String familyName;
        String sdccArch;
        String[] subArchitectures;
        String[] subArchLabels;
        boolean hasAsmMode = false;
        boolean hasProcessorFlag = false;
        String headerIncludeDir;
        String headerExtension = ".h";
        String headerPrefix = "";
        boolean headerUpperCase = false;
        boolean useNonFree = false;
        String defaultCCode = "";
        String defaultAsmCode;
        String editorHintC = "// Write your C code here…";
        String editorHintAsm;
        String defaultDevice;
        String outputFormat = "--out-fmt-ihx";
        String simulatorBinary = "s51";

        public Builder(String familyName, String sdccArch) {
            this.familyName = familyName;
            this.sdccArch = sdccArch;
        }

        public Builder subArchitectures(String[] archs, String[] labels) {
            this.subArchitectures = archs;
            this.subArchLabels = labels;
            return this;
        }

        public Builder hasAsmMode(boolean val) { this.hasAsmMode = val; return this; }
        public Builder hasProcessorFlag(boolean val) { this.hasProcessorFlag = val; return this; }
        public Builder headerIncludeDir(String dir) { this.headerIncludeDir = dir; return this; }
        public Builder headerExtension(String ext) { this.headerExtension = ext; return this; }
        public Builder headerPrefix(String prefix) { this.headerPrefix = prefix; return this; }
        public Builder headerUpperCase(boolean val) { this.headerUpperCase = val; return this; }
        public Builder useNonFree(boolean val) { this.useNonFree = val; return this; }
        public Builder defaultCCode(String code) { this.defaultCCode = code; return this; }
        public Builder defaultAsmCode(String code) { this.defaultAsmCode = code; return this; }
        public Builder editorHintC(String hint) { this.editorHintC = hint; return this; }
        public Builder editorHintAsm(String hint) { this.editorHintAsm = hint; return this; }
        public Builder defaultDevice(String device) { this.defaultDevice = device; return this; }
        public Builder outputFormat(String fmt) { this.outputFormat = fmt; return this; }
        public Builder simulatorBinary(String sim) { this.simulatorBinary = sim; return this; }

        public PortConfig build() {
            return new PortConfig(this);
        }
    }
}
