import type { components as _components, external as _external, operations as _operations, paths as _paths } from "../reference/wakanim_api";

declare namespace wakanim_api {
  export type external = _external;
  export type operations = _operations;
  export type paths = _paths;

  export type Show = _components["schemas"]["Show"];
  export type Season = _components["schemas"]["Season"];
  export type Episode = _components["schemas"]["Episode"];
  export type Tag = _components["schemas"]["Tag"];
  export type Genre = _components["schemas"]["Genre"];
  export type Classification = _components["schemas"]["Classification"];
}

export type { wakanim_api };
