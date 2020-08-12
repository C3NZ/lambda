/**
 * @file Layer.h
 * @brief The Layer implementation that allows application to specify layers to
 * be attached to the game.
 */
#ifndef LAMBDA_SRC_CORE_LAYERS_LAYER_H_
#define LAMBDA_SRC_CORE_LAYERS_LAYER_H_

#include "core/Core.h"
#include "core/events/Event.h"
#include "core/memory/Pointers.h"
#include "core/util/Time.h"

namespace lambda {
namespace core {
namespace layers {

class Layer {
 public:
  explicit Layer(const std::string& name = "Layer");
  virtual ~Layer();

  virtual void OnAttach() {}
  virtual void OnDetach() {}
  virtual void OnUpdate(util::TimeStep time_step) {}
  virtual void OnEvent(memory::Shared<events::Event> event) {}
  virtual void OnImGuiRender() {}

  inline const std::string& GetName() const { return debug_name_; }

 protected:
  std::string debug_name_;
};


}  // namespace layers
}  // namespace core
}  // namespace lambda

#endif  // LAMBDA_SRC_CORE_LAYERS_LAYER_H_

/**
 * @class lambda::layers::Layer
 * @brief An abstract data structure that represents a "layer" within the
 * engine.
 *
 * Layers are the primary hook for applications to specify logic that they want
 * to be apart of the engines event loop.
 */

/**
 * @fn lambda::layers::Layer::OnAttach
 * @brief What to do when a layer is attached to the game engine.
 *
 * Primarily for initializing anything in the layer when it's attached to the
 * engine.
 */

/**
 * @fn lambda::layers::Layer::OnDetach
 * @brief Handles what to do when a layer is attached to the game engine.
 *
 * Primarily for cleaning up anything in the layer when it's no longer
 * attached to the engine.
 */

/**
 * @fn lambda::layers::Layer::OnUpdate
 * @brief Handles what to do when the game engine requests to update the
 * layer.
 *
 * This can only be accessed if the layer is attached to the engine.
 */

/**
 * @fn lambda::layers::Layer::OnEvent
 * @param event - The event received by the engine.
 * @brief Handles what to do when the game engine passes an event.
 *
 * This can only be accessed if the layer is attached to the engine.
 */

/**
 * @fn lambda::layers::Layer::OnImGuiRender
 * @brief Handles what to do when the game engine requests the layer to
 * render ImGui components.
 *
 * This can only be accessed if the layer is attached to the engine.
 */